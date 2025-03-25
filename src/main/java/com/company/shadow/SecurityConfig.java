package com.company.shadow;

import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.crypto.factory.PasswordEncoderFactories;
import org.springframework.security.crypto.password.PasswordEncoder;


@Configuration
@EnableWebSecurity
public class SecurityConfig extends WebSecurityConfigurerAdapter{
	@Override
  protected void configure(AuthenticationManagerBuilder auth) throws Exception {
    PasswordEncoder encoder =
      PasswordEncoderFactories.createDelegatingPasswordEncoder();
      auth
		      .inMemoryAuthentication()
		      .withUser("demo")
		      .password(encoder.encode("123"))
		      .roles("USER","PATIENT", "DOCTOR", "RECEPTIONIST")
		      .and()
		      .withUser("mahbub")
		      .password(encoder.encode("123"))
		      .roles("USER", "RECEPTIONIST", "DOCTOR", "PATIENT")
			    .and()
			    .withUser("sadik")
			    .password(encoder.encode("123"))
			    .roles("USER","DOCTOR")
			    .and()
			    .withUser("nafisha")
			    .password(encoder.encode("123"))
			    .roles("USER","RECEPTIONIST")
			    .and()
			    .withUser("ashik")
			    .password(encoder.encode("123"))
			    .roles("USER","PATIENT")
			    .and()
			    .withUser("apon")
			    .password(encoder.encode("123"))
			    .roles("USER","PATIENT")
			    .and()
			    .withUser("abul")
			    .password(encoder.encode("123"))
			    .roles("USER","PATIENT")
			    .and()
			    .withUser("babul")
			    .password(encoder.encode("123"))
			    .roles("USER","PATIENT");
  }

	 @Override
	 protected void configure(HttpSecurity http) throws Exception {
		 http
	       .csrf().disable()
	       .authorizeRequests()
	       .antMatchers("/").permitAll()
	       .antMatchers("/main").permitAll()

	       .antMatchers("/signup").permitAll()
	       .antMatchers("/doctors/**").hasRole("DOCTOR")
	       .antMatchers("/patients/**").hasRole("PATIENT")
	       .antMatchers("/receptionist/**").hasRole("RECEPTIONIST")
	       .antMatchers("/anonymous*").anonymous()
	       .antMatchers("/login*").permitAll()
	       .anyRequest().authenticated()
	       .and()
	       .formLogin()
	       .defaultSuccessUrl("/showPostLogin", false)
	       .permitAll()
	       .and()
	       .logout()
	       .logoutSuccessUrl("/")
	       .permitAll();
	    }
}
