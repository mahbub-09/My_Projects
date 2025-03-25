package com.company.shadow;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service
@Transactional
public class InvoiceService {

	@Autowired
	private InvoiceRepository invoiceRepository;
	
	
	public void save(Invoice invoice) {
		invoiceRepository.save(invoice);
	}
	
	public List<Invoice> view(){
		return invoiceRepository.findAll();
	}
}
