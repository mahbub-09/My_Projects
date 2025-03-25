package com.company.shadow;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;


@Service
@Transactional
public class PrescriptionService {
	
	@Autowired
	private PrescriptionRepository prescriptionRepository;
	
	public void save(Prescription prescription) {
		prescriptionRepository.save(prescription);
	}
	
	public List<Prescription> findByPatientName(String patientName){
			return prescriptionRepository.findByPatientName(patientName);
	}
}
