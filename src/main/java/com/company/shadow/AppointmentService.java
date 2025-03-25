package com.company.shadow;

import java.util.List;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;


@Service
@Transactional
public class AppointmentService {
		
		@Autowired
		private AppointmentRepository bookAppointment;

		public List<Appointment> listAll(){
			return bookAppointment.findAll();
		}
		
		public void save(Appointment appointment) {
			bookAppointment.save(appointment);
		}
		
		public void delete(Integer id) {
			bookAppointment.deleteById(id);
		}
		
		public int setConfirmation(String confirmation, Integer id) {
			 return bookAppointment.setConfirmation(confirmation, id);
		}

		public int setPrescription(String confirmation, Integer id) {
			 return bookAppointment.setPrescription(confirmation, id);
		}
		
		public Optional<Appointment> get(Integer id) {
			return bookAppointment.findById(id);
		}
		
		public List<Appointment> findByPatientName(String patientName) {
			return bookAppointment.findByPatientName(patientName);
		}
		
		public List<Appointment> findByDoctorName(String doctorName) {
			return bookAppointment.findByDoctorName(doctorName);
		}
		
		public List<Appointment> findByDate(String date, String doctorName) {
			return bookAppointment.findByDate(date, doctorName);
		}
		
}

