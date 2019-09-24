#include <iostream>
#include <iomanip>
#include <new>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef long long int p[93] ;
#define Max_No 234
int grecordnum = 0 ;
int goutloop = 0 ;
unsigned long long int gtime = 0 ;
unsigned long long int ghalfnum = 0 ;
int getM(int, int) ;
bool openData() ;
void iterativeFib() ;
void iterativeOut() ;
void iterativeDivisors() ;
void recursiveFib(int) ;
void recursiveOut() ;
void recursiveDivisors() ;


//*********************************************************


unsigned long long int setfibs ( int i ) {
    if( i == 1 )
        return 1;
    if( i == 0 )
      return 1;
    if( i == -1 )
      return 0;  
    else 
      return setfibs(i-1)+setfibs(i-2);
	
  	  
}

unsigned long long int findDivisors( unsigned long long int temp,unsigned long long int  innerrecursive, bool & process ) {
  unsigned long long int i = 0 ;
  unsigned long long int j = 0 ;
  if ( innerrecursive == 1 && gtime == 0 ) {
  	ghalfnum = sqrt( temp ) ;
    long long int halfnum2 = 0 ;    
  } 	     
    if (temp % ghalfnum != 0 && innerrecursive < 20000 ) {
      ghalfnum-- ;
      innerrecursive += findDivisors ( temp, innerrecursive+1, process ) ; // ©È¦a¦^Ãz±¼ 
	}
	else {
	  if ( temp % ghalfnum != 0 && innerrecursive >= 20000 ) {
	    gtime += innerrecursive ;
		innerrecursive = 0 ;
		return findDivisors ( temp, innerrecursive+1, process ) ;	    	
	  }	
	  
	  else if( temp % ghalfnum == 0 ){
	    i = ghalfnum ; 
	    process = false ;
	    j = temp / ghalfnum ;
	    cout <<  i << "*" << j ;
	    //innerrecursive = innerrecursive + gtime ;
	    gtime = 0 ;
	    return innerrecursive ;
      } 
      
    } 

}
int recursiveOut(int input,int i, int j) {
	bool process = true ;
	unsigned long long int temp ;
    unsigned long long int fibs[92] ;
    unsigned long long int innerrecursivetemp = 0 ; 
	if ( i<= input ) {
		fibs[j] = setfibs(i) ;
		cout << "[ " << i << "]" << fibs[j] << "= "  ;
		temp = fibs[j] ;
		
		if ( process == true )
		  innerrecursivetemp += findDivisors( temp, innerrecursivetemp+1, process )   ; 
		
	    cout << " (Inner recurision  " << innerrecursivetemp << "times )" << "\n" ;\
	    
	    return recursiveOut(input,i+1, j+1) ;
	     
    }   
	else
	    return 0 ;
}

int main(int argc, char** argv) {
	int input = 0 ;
	int i = 1 ;
	int j = 0 ;
	int minM = 1, maxM = 92 ;
	int command = 0 ;
	p  num ;
	do {
		int M = 1 ;
	    cout << endl << "** Fibonacci Series Generator **" ;
	    cout << endl << "* 0.Quit                       *" ;
	    cout << endl << "* 1.Iterative generation       *" ;
	    cout << endl << "* 2.Recursive generation       *" ;
	    cout << endl << "********************************" ;
	    cout << endl << "Input a command(0, 1, 2):" ;
	
	    cin >> command  ;
	    switch(command) {
	    	
	    	case 0:break ;
	    	
	    	case 1:cout << endl << "Input a Number: " ;
			       iterativeFib() ;
	    	       cout << " <Outer loop:   " << goutloop << " times> " ; 
	    	       break ;
	    	    
	    	case 2:cout << endl << "Input a Number: " ;
	    	       cin >> input ;
			       recursiveOut( input, i, j ) ;
				   break ;
			default: cout << endl << "Command does not exist!" << endl ;		     
		} // end switch
	   
	}while(command != 0) ;
	
	system("pause") ;
	return 0 ;
} // end of main
	
//**********************************************************************

int getM(int minM, int maxM) {
	int temp ;
	string inputS ;
	bool isNum ;
	
	
	do {
		cout << endl << "Input a Number: " ;
		cin >> inputS ;
		isNum = true ;
		for (int i = 0 ; ( i<inputS.length() ) && (isNum) ; i++) {
		    if(( inputS[i] > '9') || (inputS[i] < '0'))
		      isNum = false ; 
	    }      
	    if (!isNum)
	      continue ;
	    
	    temp = strtoul(inputS.c_str(), NULL, 10) ;
	    if ((temp >= minM) && (temp <= maxM))
	      break ;
	} while(true) ; // end do-while
	
	return temp ;
	
} // end getM
	
bool openData() {
	return true ;
} // end openData

void iterativeFib()	{
	
	unsigned long long int fibs[92] ;
	int i = 2, j = 0, num = 0 ; 
	fibs[0] = 1 ;
	fibs[1] = 2 ;
	while ( i < 92 ) {
	  fibs[i] = fibs[i-1] + fibs[i-2] ;
	  i = i + 1 ;
	}
	
	cin >> num ;
	int a = 0 ; 
    unsigned long long int innerloop = 0 ;
    unsigned long long int halfnum2 = 0 ;
    unsigned long long int halfnum = 0 ;
    bool getanswer = false ;
	while ( j < num ) {
	  cout << "[ " << j + 1 << "]" << fibs[j] ;
	  halfnum = sqrt( fibs[j] ) ;
	  halfnum2 = 0 ;
	  innerloop = 0 ;
	  getanswer = false ;
	  while ( getanswer == false ) {
	    if ( fibs[j] % halfnum == 0 ) {
	      halfnum2 = fibs[j] / halfnum ;  
		  getanswer = true ;	
	    }
	    else 
		  halfnum = halfnum - 1 ;
		  
		if ( halfnum == 1 )
		  getanswer = true ;
		  
		innerloop = innerloop + 1 ;  		       
	  }
	  
	  if ( halfnum == 1 )
	    halfnum2 = fibs[j] ;
	  
	  cout << "= " << halfnum << "*" << halfnum2 ;
	  cout << " (Inner Looper:   " << innerloop << "times )" << "\n" ;
	    
	  j = j + 1 ;
	  a = a + 1 ;
	}
	
	goutloop = a ;
}

	
