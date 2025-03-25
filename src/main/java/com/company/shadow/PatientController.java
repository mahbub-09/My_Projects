package com.company.shadow;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;


@Controller
@RequestMapping("/patients")
public class PatientController {

	@Autowired
	private PatientRepository patientRepository;

	@Autowired
	private PatientService PatientService;

	@Autowired
	private AppointmentService appointmentService;


	@PostMapping("/savePatient")
	public String savePatient(@ModelAttribute("patient") Patients patient, Model model) {
		if (patientRepository.existsByUserName(patient.getUserName())) {
			model.addAttribute("error", "Username already exists!");
			return "signup";
		}

		PatientService.savePatient(patient);

		return "redirect:/savePatient";
	}

	@GetMapping("/myAppointments")
	public String myAppointments(Model model) {
		Authentication authentication = SecurityContextHolder.getContext().getAuthentication();
		String patientName = authentication.getName();
		List<Appointment> listAppointments = appointmentService.findByPatientName(patientName);
		model.addAttribute("listAppointments", listAppointments);

		return "myAppointments";
	}

	@GetMapping("/cancelAppointment")
	public String cancelAppointment(Model model) {
		Appointment cancelAppointment = new Appointment();
		model.addAttribute("appointment", cancelAppointment);

		return "cancelAppointment";
	}
}
