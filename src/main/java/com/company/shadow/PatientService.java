package com.company.shadow;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import javax.transaction.Transactional;
import java.util.List;


@Service
@Transactional
public class PatientService {

    @Autowired
    private PatientRepository patientRepository;

    public void savePatient(Patients patient) {
			patientRepository.save(patient);
    }

    public List<Patients> findPatientByPhone(String phone) {
        return patientRepository.findByPhone(phone);
    }

    public List<Patients> findPatientByEmail(String email) {
        return patientRepository.findByEmail(email);
    }
}
