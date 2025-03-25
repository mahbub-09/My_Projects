package com.company.shadow;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.ui.ModelMap;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;


@Controller
public class PrescriptionController {

	@Autowired
	private PrescriptionService prescriptionService;
	
	@Autowired
	private AppointmentService appointmentService;
	
	@GetMapping("/viewPrescription")
	public String viewPrescription(Model model) {
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		String patientName = auth.getName();
		List<Prescription> prescriptions = prescriptionService.findByPatientName(patientName);
		model.addAttribute("prescriptions", prescriptions);

		return "viewPrescriptions";
	}
	
	@GetMapping("/savePrescription")
	public String saveProduct(@ModelAttribute("prescription") Prescription prescription,
														BindingResult result, ModelMap model,
														RedirectAttributes redirectAttributes){
		Integer id= prescription.getAppointmentID();
		appointmentService.setPrescription("prescribed", id);

		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		String doctorName = auth.getName();

		prescription.setDoctorName(doctorName);
		prescriptionService.save(prescription);

		String message = "Prescription was successfully saved ";

		redirectAttributes.addFlashAttribute("message", message);
		redirectAttributes.addFlashAttribute("alertClass", "alert-success");

		return "redirect:/doctorAppointments";
	}
}