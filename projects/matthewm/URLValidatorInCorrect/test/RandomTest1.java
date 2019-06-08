

import static org.junit.Assert.*;

import org.junit.Test;

//import java.io.File;
//import java.net.URISyntaxException;

import java.io.IOException;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.Random;

public class RandomTest1 {
	
	

	@Test
	public void testValidateUrl() throws IOException {
		
		final Random RANDOM = new Random();
		UrlValidator validator = new UrlValidator();
		
		
		
		
		String[] schemes = {"http", "https", "ftp", "", "frp"};
		
		String[] seperator = {"://", ":\\", ":", "/", "///", "", "#"};
		
		String[] address = {"www.google.com", "ww.goo#gle.com", "*((#@", ".com", ""};
		
		String[] additionalinfo = {"", "/info", ".html", ".com"};
		
		int scheme_coefficient;
		int seperator_coefficient;
		int address_coefficient;
		int additionalinfo_coefficient;
		
		PrintWriter outputFile = new PrintWriter(new FileWriter("randomtestresults.txt"));
		
		String url;
		
		for (int i=0; i < 300 ; i++)
		{
			scheme_coefficient = Math.abs((RANDOM.nextInt())%5);
			seperator_coefficient = Math.abs(RANDOM.nextInt())%7;
			address_coefficient = Math.abs(RANDOM.nextInt())%5;
			additionalinfo_coefficient = Math.abs(RANDOM.nextInt())%4;
			
			url = schemes[scheme_coefficient] + seperator[seperator_coefficient] + address[address_coefficient] + additionalinfo[additionalinfo_coefficient];
			
			outputFile.printf("Test #: %d\n", i);
			outputFile.printf("Url: %s\n", url);
			outputFile.printf("Test Result: %s\n", validator.isValid(url));
		
		}
		
		outputFile.close();
		
	    //assertTrue(validator.isValid("http://www.google.com"));
	    
	    //assertTrue(validator.isValid("https://www.google.com"));
	    
	    //assertTrue(validator.isValid("ftp://www.google.com"));
	   
	
	
	

	

	
			
			
		

	}
	

}
