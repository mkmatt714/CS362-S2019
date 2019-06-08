//package com.journaldev.readfileslinebyline;

import static org.junit.Assert.*;

import org.junit.Test;

//import java.io.File;
//import java.net.URISyntaxException;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class UnitTest1 {
	
	

	@Test
	public void testValidateUrl() {
		
		
		//try {
		//	File file = new File(getClass().getClassLoader().getResource("/testURLs.txt").toURI());
		//}
		//catch (URISyntaxException e) {
			// TODO Auto-generated catch block
		//	e.printStackTrace();
		//}
		
		UrlValidator validator = new UrlValidator();
		
		//try {
		//	List<String> allLines = Files.readAllLines(Paths.get("C:\\Users\\MKM\\eclipse-workspace\\URLValidatorInCorrect\\bin"));
		//	for (String line : allLines) {
		//		System.out.println(line);
		//		assertTrue(validator.isValid(line));
		//	}
		//} catch (IOException e) {
		//	e.printStackTrace();
		
		
		//String[] schemes = {"http", "https", "ftp"};
		
	    assertTrue(validator.isValid("http://www.google.com"));
	    
	    assertTrue(validator.isValid("https://www.google.com"));
	    
	    assertTrue(validator.isValid("ftp://www.google.com"));
	   
	
	
	

	

	
			
			
		

	}
	

}
