/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package proiect1;

import junit.framework.TestCase;

/**
 *
 * @author Tudor
 */
public class BigNumberTest extends TestCase {
    
    public BigNumberTest(String testName) {
        super(testName);
    }
/**
    * Test of add method, of class BigNumber.
    */
    public void testAddValues() {
       System.out.println("addValues");

       BigNumber number = new BigNumber("4");
       BigNumber instance = new BigNumber("8");

       BigNumber expResult = new BigNumber("12");
       BigNumber result = instance.addTo(number);
       assertEquals(expResult.toString(), result.toString());
    }

/**
    * Test of getDigit method, of class BigNumber.
    */
    public void testGetDigit() {
        System.out.println("getDigit");
        BigNumber instance = new BigNumber("135648");
        int result = instance.getDigit(2);
        assertEquals(6, result);
    }
  
    public void testCompare() {
  
        System.out.println("compare");
        BigNumber number = new BigNumber("33");
        BigNumber instance = new BigNumber("123456");
        BigNumber instance1 = new BigNumber("-6654");
        assertEquals(1,  instance.compare(number));
        assertEquals(-1, instance1.compare(number));
    }

    public void testToString() {
  
        System.out.println("ToString");
        BigNumber instance = new BigNumber ("444");
        BigNumber instance1 = new BigNumber ("-444");
        assertEquals("444",  instance.toString());
        assertEquals("-444", instance1.toString());
    }

 
  
    public void testSubstractValues()   {
        System.out.println("substractValues");

        BigNumber number = new BigNumber("4");
        BigNumber instance = new BigNumber("-4");
        BigNumber number1 = new BigNumber("-8");
        BigNumber instance1 = new BigNumber("15");
       
       
        BigNumber rezultat = instance.substract(number1);
        BigNumber expResult = new BigNumber("4");
        assertEquals(expResult.toString(), rezultat.toString());
       
        BigNumber rezultat1 = instance1.substract(number1);
        BigNumber expResult1 = new BigNumber("23");
        assertEquals(expResult1.toString(), rezultat1.toString());
       
        BigNumber rezultat2 = instance1.substract(number);
        BigNumber expResult2 = new BigNumber("11");
        assertEquals(expResult2.toString(), rezultat2.toString());
       
        BigNumber rezultat3 = instance.substract(instance1);
        BigNumber expResult3 = new BigNumber("-19");
        assertEquals(expResult3.toString(), rezultat3.toString());
    }  
  
    public void testAddTo() {
        System.out.println("addValues");

        BigNumber number = new BigNumber("4");
        BigNumber instance = new BigNumber("-4");
        BigNumber number1 = new BigNumber("-8");
        BigNumber instance1 = new BigNumber("15");
       
       
        BigNumber rezultat = instance.addTo(number1);
        BigNumber expResult = new BigNumber("-12");
        assertEquals(expResult.toString(), rezultat.toString());

        BigNumber rezultat1 = instance1.addTo(number1);
        BigNumber expResult1 = new BigNumber("7");
        assertEquals(expResult1.toString(), rezultat1.toString());

        BigNumber rezultat2 = instance1.addTo(number);
        BigNumber expResult2 = new BigNumber("19");
        assertEquals(expResult2.toString(), rezultat2.toString());

        BigNumber rezultat3 = instance.addTo(instance1);
        BigNumber expResult3 = new BigNumber("11");
        assertEquals(expResult3.toString(), rezultat3.toString());
    }  
  
  
    public void testInc() {
        System.out.println("inc");

        BigNumber number = new BigNumber("2");
        BigNumber number1 = new BigNumber("-2");

        number.inc();
        assertEquals("3", number.toString());

        number1.inc();
        assertEquals("-1", number1.toString());
        
    }
  
    public void testDec(){
        System.out.println("dec");

        BigNumber number = new BigNumber("2");
        BigNumber number1 = new BigNumber("-2");

        number.dec();
        assertEquals("1", number.toString());

        number1.dec();
        assertEquals("-3", number1.toString());
       
    }
  
    public void testEqual() {
  
        BigNumber one = new BigNumber("45");
        BigNumber two = new BigNumber("450");
        BigNumber three = new BigNumber("45");

        Boolean rezultat = one.equals(two);
        Boolean rezultat1 = one.equals(three);
         
    }
   
  
    public void testMultiply() {
        System.out.println("multiply");

        BigNumber instance = new BigNumber("-4");
        BigNumber instance1 = new BigNumber("-4");
  
        BigNumber result = instance.multiply(instance1);


        BigNumber expResult = new BigNumber("16");
        assertEquals(expResult.toString(), result.toString());
      
  
        
    }
 
  
    public void testDivide() {
        System.out.println("divide");

        BigNumber instance = new BigNumber("51");
        BigNumber instance1 = new BigNumber("3");

        BigNumber result = instance.divide(instance1);
        BigNumber expResult = new BigNumber("17");
        assertEquals( expResult.toString(), result.toString());
    }
  
    public void testPow(){
        System.out.println("pow");
    
        BigNumber instance = new BigNumber("2");
        BigNumber instance1 = new BigNumber("3");
        
        BigNumber result = instance.pow(instance1);
        BigNumber expResult = new BigNumber("8");
        assertEquals(expResult.toString(), result.toString());
    }
    

    public void testFactorial(){
        System.out.println("factorial");
        
        BigNumber instance = new BigNumber("10");
        
        BigNumber result = instance.factorial();
        
        BigNumber expResult = new BigNumber("3628800");
        assertEquals(expResult.toString(),result.toString());
        
    }
        






    






}   

 




