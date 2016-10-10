#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <fstream>
#include "md5.h"

using namespace std;

int main(int argc, char** argv)
{	
	for( ; ; )
	{
		int x;
		cout << "1. Zapis do bazy" << endl;
		cout << "2. Wczytanie z bazy" << endl;
		cout << "3. Wyjscie" << endl;
		cin  >> x;
		
		if( x == 3 )
		{
			break;
		}
		else if( x == 1 )
		{
			string login = "";
			string haslo1 = "";
			string haslo2 = "";
			
			cout << "Login: ";
			cin  >> login;
			
			do
			{
				haslo1 = "";
				haslo2 = "";
				
				cout << "Haslo: ";
				
				for( ; ; )
			    {
			         char key = getch();
			         
			         if( key == 13 )
			         {
			             break;
			         }
			         
			         cout<<"*";
			         
			         haslo1 += key;
			    }
			    
			    cout << "\nHaslo potwierdz: ";
			    
			    for( ; ; )
			    {
			         char key = getch();
			         
			         if( key == 13 )
			         {
			             break;
			         }
			         
			         cout<<"*";
			         
			         haslo2 += key;
			    }
			    
			    if( strcmp( haslo1.c_str(), haslo2.c_str() ) != 0 )
				{
			    	cout << "\nHasla sie nie zgadzaja!" << endl;	
				}
			}
			while( strcmp( haslo1.c_str(), haslo2.c_str() ) != 0 );
			
			cout << "\nHasla sie zgadzaja" << endl;
		    
		    fstream zapisz;
		    
		    zapisz.open( ( login + ".txt" ).c_str(), ios::out );
		    
		    if( zapisz.good() == true )
		    {
		    	cout << "Plik otwarto poprawnie" << endl;
			}
			else
			{
				cout << "Dostep zabroniony!" << endl;
				
				zapisz.close();
				
				return 1;
			}
		    
		    string zakodowane = md5( haslo1 );
		    
		    zapisz << zakodowane << endl;
		    
		    zakodowane = md5( zakodowane );
		    zapisz << zakodowane << endl;
		    
		    zakodowane = md5( zakodowane );
		    zapisz << zakodowane << endl;
		    
		    zakodowane = md5( zakodowane );
		    zapisz << zakodowane << endl;
		    
		    zapisz.close();
		    
		    cout << "Plik zapisano" << endl;
		}
		else if( x == 2 )
		{
			string login;
			
			cout << "Podaj login: ";
			cin  >> login;
			
			fstream wczytaj;
		    
		    wczytaj.open( ( login + ".txt" ).c_str(), ios::in );
		    
		    if( wczytaj.good() == true )
		    {
		    	cout << "Plik otwarto poprawnie" << endl;
			}
			else
			{
				cout << "Dostep zabroniony!" << endl;
				
				wczytaj.close();
				
				continue;
			}
			
			string haslo_plik;
			
			wczytaj >> haslo_plik;
			
			wczytaj.close();
			
			string haslo = "";
			
			cout << "Haslo: ";
				
			for( ; ; )
		    {
		         char key = getch();
		         
		         if( key == 13 )
		         {
		             break;
		         }
		         
		         cout<<"*";
		         
		         haslo += key;
		    }
		    
		    string haslo_dekodowane = md5( haslo );
		    
		    if( strcmp( haslo_dekodowane.c_str(), haslo_plik.c_str() ) == 0 )
			{
		    	cout << "\nHasla sie zgadzaja" << endl;	
			}
			else
			{
				cout << "\nHasla sie nie zgadzaja!" << endl;
				
				continue;	
			}
			
			/*
			string strMD5 = "Maly czarny napis";
		    string strMD6;
		    
		    cout << strMD5 << endl;
		    
		    strMD6 = md5( strMD5 );
		    
		    cout << strMD6 << endl;
			*/
			
		}
	}

	return 0;
}
