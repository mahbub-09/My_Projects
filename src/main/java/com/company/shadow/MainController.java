package com.company.shadow;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
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
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;


@Controller
public class MainController {

	@GetMapping({"/", "/main"})
	public String showMain() {
		return "main";
	}

	@GetMapping("/patients")
	public String showPatient(Model model) {
		Authentication authentication = SecurityContextHolder.getContext().getAuthentication();
		String username= authentication.getName();
		model.addAttribute("username", username);
		String confirmation = "Your Appointment has been successfully booked. ID = ";
		model.addAttribute("confirmation", confirmation);
		String id = (String) model.asMap().get("appointmentId");
		model.addAttribute("appointmentId", id);

		return "patients";
	}
	
	@GetMapping("/doctors")
	public String showDoctors(Model model) {
		Authentication authentication= SecurityContextHolder.getContext().getAuthentication();
		String username = authentication.getName();
		model.addAttribute("username",username);

		return "doctors";
	}

	@GetMapping("/showPostLogin")
	public String showPostLogin() {
		return "postlogin";
	}
	
	@GetMapping("/receptionist")
	public String showReceptionist(Model model) {
		Authentication authentication = SecurityContextHolder.getContext().getAuthentication();
		String username = authentication.getName();
		model.addAttribute("username",username);
	
		return "receptionist";
	}




	@Autowired
	private AppointmentService appointmentService;


	@GetMapping("/add")
	public String newAppointment(Model model) {
		Appointment appointment = new Appointment();
		appointment.setConfirmed("Not yet confirmed");
		model.addAttribute("appointment",appointment);

		return "add.html";
	}

	@GetMapping("/save")
	public String saveProduct(@ModelAttribute("appointment") Appointment appointment,
														BindingResult result, ModelMap model,
														RedirectAttributes redirectAttributes) {
		appointment.setConfirmed("Not yet confirmed");
		appointmentService.save(appointment);

    String appointmentId = appointment.getAppointment_id().toString();
    String message = "Appointment was successfully booked, your id is: " + appointmentId;

    redirectAttributes.addFlashAttribute("message", message);
    redirectAttributes.addFlashAttribute("alertClass", "alert-success");
    redirectAttributes.addFlashAttribute("appointmentId",appointmentId);

    return "redirect:/patients";
	}


	@GetMapping("/cancel")
	public String cancel(@ModelAttribute("appointment") Appointment appointment,
	                     BindingResult result, ModelMap model,
	                     RedirectAttributes redirectAttributes) {

		Integer id = appointment.getAppointment_id();
		appointmentService.delete(id);

	  String message = "Appointment was successfully canceled!";

	  redirectAttributes.addFlashAttribute("message", message);
		redirectAttributes.addFlashAttribute("alertClass", "alert-success");

		return "redirect:/patients";
	}

	@RequestMapping("/confirm")
	public String confirm(@ModelAttribute("appointment") Appointment appointment,
	                      BindingResult result, ModelMap model,
	                      RedirectAttributes redirectAttributes) {
	  String confirmation = "confirmed";
	  Integer id = appointment.getAppointment_id();

	  appointmentService.setConfirmation(confirmation, id);
	  String message = "Appointment was successfully confirmed!";

	  redirectAttributes.addFlashAttribute("message", message);
		redirectAttributes.addFlashAttribute("alertClass", "alert-success");

		return "redirect:/receptionist/receptionistAppointments";
	}

	@GetMapping("/confirmm")
	public String showConfirmm(Model model) {
		Appointment confirmation = new Appointment();
		model.addAttribute("confirmation",confirmation);

		return "confirm";
	}


	@GetMapping("/findbystart")
	public String showBydate(Model model) {
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();

		String doctorName = auth.getName();
		DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyy/MM/dd");
		LocalDateTime now = LocalDateTime.now();

		List<Appointment> Appointments = appointmentService.findByDate(dtf.format(now).toString(),doctorName);
		model.addAttribute("appointments", Appointments);

		return "findbystart";
	}

	@GetMapping("/createPrescription")
	public String createPrescription(Model model) {
		Prescription prescription = new Prescription();
		model.addAttribute("prescription",prescription);

		return "createPrescription";
	}

	@GetMapping("/signup")
	public String signup() {
		return "signup";
	}

	@GetMapping("/signupp")
	public String signupp(RedirectAttributes redirectAttributes) {
		 redirectAttributes.addFlashAttribute("message", "Account created successfully");
		 redirectAttributes.addFlashAttribute("alertClass", "alert-success");
		 redirectAttributes.addFlashAttribute("message", "Please login to continue");
		 redirectAttributes.addFlashAttribute("alertClass", "alert-success");

		 return "redirect:/";
	}




	@Autowired
	public InvoiceService invoiceService;

	@GetMapping("/saveInvoice")
	public String saveInvoice(@ModelAttribute("invoice") Invoice invoice,
														BindingResult result, ModelMap model,
														RedirectAttributes redirectAttributes) {
		invoiceService.save(invoice);
	  String message = "Invoice was successfully created!";

	  redirectAttributes.addFlashAttribute("message", message);
		redirectAttributes.addFlashAttribute("alertClass", "alert-success");

		return "redirect:/patients";
	}
}
