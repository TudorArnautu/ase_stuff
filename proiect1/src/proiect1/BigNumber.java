/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package proiect1;

/**
 *
 * @author Tudor
 */
public class BigNumber {
    protected String value;
    protected int length;
    protected boolean isNegative;
    protected final static int IS_SMALLER = -1;
    protected final static int EQUAL = 0;
    protected final static int IS_BIGGER = 1;
    protected static BigNumber ZERO = null;
    protected static BigNumber ONE = null;
    
    
public BigNumber(String value) {
    this.value = value;
    this.length = value.length();                                       
    this.isNegative = false;
    if (this.value.substring(0, 1).equals("-")) {
    this.isNegative = true;
    this.value = this.value.substring(1);
    }  
    if(this.value.equals("0"))
       this.isNegative = false;
    }
    
    
    
    public void setValue(String value) {
        this.value = value;
    }
    
    public String getValue() {
        return this.value;
    }
    
    public String toString() {   
            
        if (this.isNegative == true) {
           return "-" + this.getValue();
        }
        return this.getValue();
    }
    
    
    public BigNumber clone() {
        BigNumber clone =  new BigNumber(this.getValue());
        clone.setIsNegative(this.getIsNegative());
        
        return clone;
  
    }
  
    public BigNumber multiply(int times) {
        BigNumber cloned = this.clone();
        BigNumber result  = this.clone();
int i = -1;
    while(i > times) {
        BigNumber r = result.addTo(cloned);
        result.setValue(r.getValue());
        result  = result.addTo(cloned);
    if(times < 0){
        i--;}
    else{
        i++;}
  
    }
    if (this.getIsNegative() && times > 0 || !this.getIsNegative() && times < 0) {
       result.setIsNegative(true);
    }
    if (this.getIsNegative() && times < 0 || !this.getIsNegative() && times > 0){
        result.setIsNegative(false);
    } 
    
        return result;
    }
    
    public void setLength(int length) {
        this.length=length;
     }
    
    public int getLength() {
        return this.length;
    }
     
    public int compare(BigNumber number) {
        if (this.getIsNegative() == true && number.getIsNegative() == false) {
            return IS_SMALLER;
        }
        if (this.getIsNegative() == false && number.getIsNegative() == true) {
            return IS_BIGGER;
        }
        return BigNumber.compareValue(this.getValue(), number.getValue());
      
    }  
      
    public int getDigit(int position) {
        return BigNumber.getDigitFromValue(this.getValue(), position);
    }

    public void inc() {
        
        BigNumber one = BigNumber.getOne();
        BigNumber inc =  this.addTo(one);
        this.setValue(inc.getValue());
       
    }
       
    public void dec() {
           
        BigNumber one = BigNumber.getOne();
        BigNumber dec = this.substract(one);
        this.setValue(dec.getValue());
        
    }
       
    public static BigNumber getOne() {
           
        if (BigNumber.ONE == null) { 
            BigNumber.ONE = new BigNumber("1");
            
        } 
            
        return BigNumber.ONE;
       
    }
       
       
    public static BigNumber getZero() {
           
        if (BigNumber.ZERO == null) { 
            BigNumber.ZERO = new BigNumber("0");} 
        return BigNumber.ZERO;
       
    }
       
     
    BigNumber substract(BigNumber number) {
        int rezultatComparare = BigNumber.compareValue(this.getValue(), number.getValue());
  
        //ambele numere pozitive
        if (!this.getIsNegative() && !number.getIsNegative()) {
         
            //primul numar > al doilea numar, rezultat pozitiv
            if (rezultatComparare == 1) { 
                String valoare_rezultat = BigNumber.substractValues(this.getValue(), number.getValue());
                BigNumber rezultat = new BigNumber(valoare_rezultat);
                rezultat.setIsNegative(false);
                return rezultat;
            }
            //primul nr<aldoilea nr, rezultat negativ
            if (rezultatComparare == -1) {
                String valoare_rezultat = BigNumber.substractValues(number.getValue(),this.getValue());
                BigNumber rezultat = new BigNumber(valoare_rezultat);
                rezultat.setIsNegative(true);
                return rezultat;
            } 
         
            //daca numerele sunt egale rezultatul scaderii va fi 0
            if (rezultatComparare == 0) {
                return new BigNumber("0");
            }             
        } 
        
         
        // caz 2:primul nr pozitiv, al doilea negativ
        if (this.getIsNegative() && !number.getIsNegative()) {
            String valoare_rezultat = BigNumber.addValues(this.getValue(), number.getValue());
            System.out.println(valoare_rezultat);
            BigNumber rezultat = new BigNumber(valoare_rezultat);
            rezultat.setIsNegative(true);
            return rezultat;
       
        }
            
         
         
        //caz3: inversul cazului 1
        if (this.getIsNegative() && number.getIsNegative()) {
       
            if (rezultatComparare == 1) { 
                String valoare_rezultat = BigNumber.substractValues(this.getValue(), number.getValue());
                 BigNumber rezultat = new BigNumber(valoare_rezultat);
                rezultat.setIsNegative(true);
            return rezultat;
            } 
            if (rezultatComparare == -1) {
                String valoare_rezultat = BigNumber.substractValues(number.getValue(),this.getValue());
                System.out.println(valoare_rezultat);
                System.out.println(number.getValue());
                System.out.println(this.getValue());
                BigNumber rezultat = new BigNumber(valoare_rezultat);
                rezultat.setIsNegative(false);
            return rezultat;
            } 
         
            if (rezultatComparare == 0) {
                return new BigNumber("0");
            }             
        } 
         
          
        //caz4: se aduna valorile cu semnul primului nr "-" si semn "+" celui de-al doilea numar, rezultatul va fi pozitiv
        String valoare_rezultat = BigNumber.addValues(this.getValue(), number.getValue());
            BigNumber rezultat = new BigNumber(valoare_rezultat);
            rezultat.setIsNegative(false);
        return rezultat;
    
    }

                       
   
    
     
    public void setIsNegative(boolean isNegative) {
        this.isNegative = isNegative;
    }
 
    public boolean getIsNegative() {
        return this.isNegative;
    }

    private static int compareValue(String number, String number2) {
        
        int i;  
        int numberLength = number.length();
        int number2Length = number2.length();
       
        if (numberLength > number2Length) {
            return IS_BIGGER;
        }
        else if (numberLength < number2Length) {
            return IS_SMALLER;
        }    
        for (i= 0; i < numberLength; 
            i++){
       
            if (BigNumber.getDigitFromValue(number, i) < BigNumber.getDigitFromValue(number2, i)) {
                return IS_SMALLER;
            }
            else if (BigNumber.getDigitFromValue(number, i) > BigNumber.getDigitFromValue(number2, i)) {
            return IS_BIGGER;
            }
       
        }
            return EQUAL;
 
    }
    
    BigNumber addTo(BigNumber number) {
        int rezultatComparare = BigNumber.compareValue(this.getValue(), number.getValue());   
    
        //caz1
        if (this.getIsNegative() && !number.getIsNegative()) {
            if (rezultatComparare == 1) {
                String valoare_rez = BigNumber.substractValues(this.getValue(), number.getValue());
                BigNumber rezultat = new BigNumber(valoare_rez);
                rezultat.setIsNegative(true);
                return rezultat;
            }
    
            if (rezultatComparare == -1) {
                String valoare_rez = BigNumber.substractValues(number.getValue(),this.getValue());
                BigNumber rezultat = new BigNumber(valoare_rez);
                rezultat.setIsNegative(false);
                return rezultat;
            }
            
            if (rezultatComparare == 0) {
                String valoare_rez = BigNumber.addValues(this.getValue(),number.getValue());
                BigNumber rezultat = new BigNumber(valoare_rez);
                rezultat.setIsNegative(false);
                return rezultat;
            } 
        } 
    
        //caz22.
        if (!this.getIsNegative() && number.getIsNegative()) {
            if (rezultatComparare == 1) {
                String valoare_rez = BigNumber.substractValues(this.getValue(), number.getValue());
                BigNumber rezultat = new BigNumber(valoare_rez);
                rezultat.setIsNegative(false);
                return rezultat;
            }
    
            if (rezultatComparare == -1) {
                String valoare_rez = BigNumber.substractValues(number.getValue(),this.getValue());
                BigNumber rezultat = new BigNumber(valoare_rez);
                rezultat.setIsNegative(true);
                return rezultat;
            }
            
            if (rezultatComparare == 0) {
                String valoare_rez = BigNumber.addValues(this.getValue(),number.getValue());
                BigNumber rezultat = new BigNumber(valoare_rez);
                rezultat.setIsNegative(false);
                return rezultat;
            } 
        } 
    
        //caz3
        if (!this.getIsNegative() && !number.getIsNegative()) {
            String valoare_rez = BigNumber.addValues(this.getValue(),number.getValue());
            BigNumber rezultat = new BigNumber(valoare_rez);
            rezultat.setIsNegative(false);
            return rezultat;
        }
    
        //caz4  
        String valoare_rez = BigNumber.addValues(this.getValue(),number.getValue());
        BigNumber rezultat = new BigNumber(valoare_rez);
        rezultat.setIsNegative(true);
        return rezultat;
         
    } 
 
    private static String addValues(String number, String number1) {
        int firstNoLength = number.length();
        int lastNoLength   = number1.length();
    
        int n = Math.max(firstNoLength, lastNoLength);
        int k = 0;
        int i = 0;
        int j = 0;
        int rest = 0;
        int r = 0;
         String result = "";
        for (k = 0; k < n; k++) {
            int currentResult = rest;
        
            if (i < firstNoLength) {
                currentResult += BigNumber.getDigitFromValue(number, i);
                i++;
            }

            if (j < lastNoLength) {
                currentResult += BigNumber.getDigitFromValue(number1, j);
                j++;
            }
     
            r = currentResult % 10;
            rest = currentResult / 10;

            result = r + result;
    
            }
        if (rest > 0) {
      result = rest + result;}
  
   
        return result;
  
    }

 
    private static int getDigitFromValue(String number, int position) {
        int length = number.length();
    
    return Integer.parseInt(number.substring(length - 1 -position, length - position), 10);
    } 
     

    private static String substractValues(String number, String number1) {
        int firstNoLength = number.length();
        int lastNoLength = number1.length();
    
    
        int pozitie = 0;
        int i = 0;
        int r;
        boolean borrow = false;

        String result = "";
        for (pozitie = 0; pozitie < firstNoLength ; pozitie++) {
            int cifra = getDigitFromValue(number, pozitie);
      
            if (borrow) {
                if (cifra == 0) {
                    cifra = 9;
                }
             else {
                cifra--;
                borrow = false;
            }
            }
     
            if (pozitie < lastNoLength) {
                int cifra2 = getDigitFromValue(number1, pozitie);
                if(cifra < cifra2) {
                    borrow =true;
                    cifra += 10;
                }
    
            r = cifra - cifra2;
  
            }  
            else {
                r = cifra;
     
            }
 
            result = r + result;
        }
        return result.replaceAll("^0", "");
    
    }

 
    public boolean equals(BigNumber number) {
        return this.compare(number) == BigNumber.EQUAL;
   
    }
 

    public BigNumber multiply(BigNumber times) {
        BigNumber index = BigNumber.getOne().clone();
        BigNumber cloned = this.clone();
        BigNumber result  = this.clone();
        
        if (times.getIsNegative() == true) {
            index.setIsNegative(true);}
        
        while (!times.equals(index)) {
            BigNumber r = result.addTo(cloned);
            result.setValue(r.getValue());
            
            if (times.getIsNegative() == true) {
            index.dec();}
            else{
            index.inc();}
        }
        
        if (this.getIsNegative() && !times.getIsNegative() || !this.getIsNegative() && times.getIsNegative()) {
            result.setIsNegative(true);
           
        }
        
        if (this.getIsNegative() && times.getIsNegative() || !this.getIsNegative() && !times.getIsNegative()){
            result.setIsNegative(false);
            
        } 
        
        return result;
    }   


    public BigNumber divide(BigNumber times) {
        BigNumber index = null;
        BigNumber cloned = this.clone();
        BigNumber result  = this.clone();
        

        while (result.compare (BigNumber.getZero()) == 1) {
            BigNumber r = result.substract(times);
            result.setValue(r.getValue());

            if (index == null) {
                index = BigNumber.getOne().clone();
            }
            else {
                index.inc();
            }
        }
        if (this.getIsNegative() && !times.getIsNegative() || !this.getIsNegative() && times.getIsNegative()) {
            index.setIsNegative(true);
           
        }
        
        if (this.getIsNegative() && times.getIsNegative() || !this.getIsNegative() && !times.getIsNegative()){
            index.setIsNegative(false);
            
        } 

    return index;
    }   


    public BigNumber pow(BigNumber times) {
        BigNumber index = BigNumber.getOne().clone();
        BigNumber cloned = this.clone();
        BigNumber result  = this.clone();


        while (!times.equals(index)) {
            BigNumber r = result.multiply(cloned);
            result.setValue(r.getValue());
            index.inc();
        }

    return result;
    }   


    public BigNumber factorial() {
        BigNumber index = BigNumber.getOne().clone();
        BigNumber clone = this.clone();
        BigNumber result = this.clone();
        
        while (!index.equals(clone)){    
            BigNumber r = result.multiply(index);
            result.setValue(r.getValue());
            index.inc();
        }
        return result;
    
    } 
    
    
    
    
    public static void checkValue(String s) throws Exception {
        
        if (s.equals("")) {
            throw new Exception("Not a number");
        }
        int position = 0;
        String firstDigit = s.substring(0,1);
        int length = s.length();
        
        if (firstDigit.equals("-") || firstDigit.equals("+")) {
            
            if (s.equals(firstDigit)) {
                if(s.substring(position,position+1).equals(0))
                throw new Exception("Not a number");
        }
        position++;
        
        }
        
      
            for(; position < length; position++) {
                
                   String currentDigit = s.substring(position, position+1);
            
            try{
                   Integer.parseInt(currentDigit, 10);
               }
            catch (Exception e) {
                throw new Exception("Not a number");  
                }
        
        
            }
    
    
    }

     
    
   
    



}











