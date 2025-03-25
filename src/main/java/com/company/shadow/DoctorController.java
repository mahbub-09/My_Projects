package com.company.shadow;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;


@Controller
@RequestMapping("/doctors")
public class DoctorController {

	@Autowired
	private AppointmentService service;
	
	@RequestMapping("/doctorAppointments")
	public String showDoctorAppointments(Model model) {
		Authentication authentication = SecurityContextHolder.getContext().getAuthentication();
		String doctorName = authentication.getName();
		List<Appointment> doctorAppointments = service.findByDoctorName(doctorName);
		model.addAttribute("doctorAppointments",doctorAppointments);

		return "doctorAppointments.html";
	}
	
	@RequestMapping("/createPrescription")
	public String createPrescription() {
		return "createPrescription";
	}
}
