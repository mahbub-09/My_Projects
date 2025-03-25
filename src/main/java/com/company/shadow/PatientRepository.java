package com.company.shadow;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;
import java.util.List;


@Repository
public interface PatientRepository extends JpaRepository<Patients, String> {

	List<Patients> findByPhone(String phone);

	List<Patients> findByEmail(String email);

	boolean existsByUserName(String userName);
}
