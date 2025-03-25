package com.company.shadow;

import org.hibernate.annotations.DynamicUpdate;

import javax.persistence.*;

@Entity
@Table(name="patients", schema="hospital")
@DynamicUpdate
public class Patients {

	@Column(name="name")
	private String name;

	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	@Column(name="email")
	private String email;

	@Column(name="age")
	private Integer age;

	@Column(name="phone")
	private String phone;

	@Column(name="userName")
	private String userName;

	@Column(name="password")
	private String password;

	@Override
	public String toString() {
		return "Patients{" +
						"name='" + name + '\'' +
						", email='" + email + '\'' +
						", age=" + age +
						", appointment_id='" + phone + '\'' +
						", userName='" + userName + '\'' +
						", password='" + password + '\'' +
						'}';
	}

	public Patients() {
	}

	public Patients(String name,
	                String email,
	                Integer age,
	                String appointment_id,
	                String userName,
	                String password) {
		super();
		this.name = name;
		this.email = email;
		this.age = age;
		this.phone = appointment_id;
		this.userName = userName;
		this.password = password;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public Integer getAge() {
		return age;
	}

	public void setAge(Integer age) {
		this.age = age;
	}

	public String getPhone() {
		return phone;
	}

	public void setPhone(String phone) {
		this.phone = phone;
	}

	public String getUserName() {
		return userName;
	}

	public void setUserName(String userName) {
		this.userName = userName;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}
}
