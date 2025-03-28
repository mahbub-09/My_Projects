package com.company.shadow;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

import org.hibernate.annotations.DynamicUpdate;


@Entity
@Table(name="prescription",schema="hospital")
@DynamicUpdate
public class Prescription {
	
	@Id
	@Column
	@GeneratedValue(strategy=GenerationType.IDENTITY)
	private Integer prescriptionID;

	@Column
	private String patientName;

	@Column 
	private Integer appointmentID;

	@Column
	private String description;

	@Column
	private String doctorName;

	public Prescription() {}

	public Prescription(String patientName,
	                    Integer appointmentID,
	                    String description,
	                    String doctorName){
		super();
		this.patientName = patientName;
		this.appointmentID = appointmentID;
		this.description = description;
		this.doctorName = doctorName;
	}

	public Integer getPrescriptionID() {
		return prescriptionID;
	}

	public void setPrescriptionID(Integer prescriptionID) {
		this.prescriptionID = prescriptionID;
	}

	public String getPatientName() {
		return patientName;
	}

	public void setPatientName(String patientName) {
		this.patientName = patientName;
	}

	public Integer getAppointmentID() {
		return appointmentID;
	}

	public void setAppointmentID(Integer appointmentID) {
		this.appointmentID = appointmentID;
	}

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description;
	}

	public String getDoctorName() {
		return doctorName;
	}

	public void setDoctorName(String doctorName) {
		this.doctorName = doctorName;
	}
}
