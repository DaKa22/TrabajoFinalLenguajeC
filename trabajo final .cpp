//Registro Agenda

#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

using namespace std;

class Datos_Basicos
{
	private:
    	string cedula;
    	string nombre1;
    	string nombre2;
    	string apellido1;
    	string apellido2;
    	string telefono;
    	string email;
    	string genero;
    	string nacionalidad;
    	string estado_civil;
    	string fecha_nacimiento;
    	
    	string fecha_nacimientoA;
    	string fecha_nacimientoM;
    	string fecha_nacimientoD;
    	
    	string rh;
    	string activo;

	public:
    	void ingresar_DB();
    	void retirar_DB();
    	void modificar_DB();
    	void listar_DB();
    	void borrado_logico_DB();
    	void activar_logico_DB();
    	void menu_DB();
};

class Tabla_Estudios
{
	private:
    	string cedula;
    	string titulo;
    	string entidad_educativa;
    	
    	string fecha_terminacionA;
    	string fecha_terminacionM;
    	string fecha_terminacionD;

    	string activo;


	public:
    	void ingresar_TE();
    	void retirar_TE();
    	void modificar_TE();
    	void listar_TE();
    	void borrado_logico_TE();
    	void activar_logico_TE();
    	void menu_TE();
    	
    	
};
class Historial_Laboral
{
	private:
    	string cedula;
    	string empresa;
    	string cargo;
    	//FECHA INICIO
    	string fecha_inicioA;
    	string fecha_inicioM;
    	string fecha_inicioD;
    	
    	//FECHA TERMINACION
    	string fecha_terminacionA;
    	string fecha_terminacionM;
    	string fecha_terminacionD;
    	
    	string activo;
	public:
    	void ingresar_HL();
    	void retirar_HL();
    	void modificar_HL();
    	void listar_HL();
    	void borrado_logico_HL();
    	void activar_logico_HL();
    	void menu_HL();
};
void pausa();
void error();



// Menu general Agenda
void Datos_Basicos::menu_DB()
{
	int opc;
	opc = 9;
	do
	{
		system(CLEAR);
		cout <<"\n REGISTRAR DATOS AGENDA "<<endl<<endl;
		cout <<"1. Ingresar Datos Agenda"<<endl;
		cout <<"2. Retirar Datos Agenda"<<endl;
		cout <<"3. Modificar Datos Agenda"<<endl;
		cout <<"4. Listar Datos Agenda "<<endl;
		cout <<"5. Borrado Logico "<<endl;
		cout <<"6. Acticar Logico "<<endl;
			
		cout <<"0. Salir del Menu"<<endl<<endl;
		cout <<"Digite Opcion :  ";
		cin >> opc;
		fflush(stdin);
		
		switch(opc)
		{
			case 1: ingresar_DB(); break;
			case 2: retirar_DB(); break;
			case 3: modificar_DB(); break;
			case 4: listar_DB(); break;
			case 5: borrado_logico_DB(); break;
		    case 6: activar_logico_DB(); break;
			
			default : cout <<"Ingreso Opcion no valida "; 
		}
	}
	while ( opc != 0 );	
}

// Ingresar datos
void Datos_Basicos::ingresar_DB()
{

	ofstream escribir;
	/* string aux_nombre;
    string aux_codigo;
    string aux_cedula;
    string aux_activo;
	*/
	time_t t = time(NULL);
  	struct tm tiempoLocal = *localtime(&t);
  	int dia_actual=tiempoLocal.tm_mday;
  	int mes_actual=tiempoLocal.tm_mon+1;
  	int year_actual=(tiempoLocal.tm_year-100)+2000;
  
  	
	
	escribir.open("Agenda.txt",ios::app);
	
	if ( escribir.is_open() ) //Validamos que el archivo "escribir no presento error
 	{
		cout<<"\n\n Digite datos basicos ";
		cout<<"\n\n Digite Nombre 1 : ";
		getline(cin,nombre1);
		
		if ( nombre1 == "" ) // validamos que el nombre no este vacio
		{
			do
			{
				cout<<"\n\n Digite Nombre 1: ";
				getline(cin,nombre1);	
			}
			while (nombre1 == "" );
		}
		
		cout<<"\n\n Digite Nombre2 : ";
		getline(cin,nombre2);
		
		if ( nombre2 == "" ) // validamos que el nombre no este vacio
		{
			do
			{
				cout<<"\n\n Digite Nombre2 : ";
				getline(cin,nombre2);	
			}
			while (nombre2 == "" );
		}
		
		cout<<"\n\n Digite Apellido1 : ";
		getline(cin,apellido1);
		
		if ( apellido1 == "" ) // validamos que el apellido no este vacio
		{
			do
			{
				cout<<"\n\n Digite apellido1 : ";
				getline(cin,apellido1);	
			}
			while (apellido1 == "" );
		}
		
		cout<<"\n\n Digite Apellido2 : ";
		getline(cin,apellido2);
		
		if ( apellido2 == "" ) // validamos que el apellido no este vacio
		{
			do
			{
				cout<<"\n\n Digite apellido2 : ";
				getline(cin,apellido2);	
			}
			while (apellido2 == "" );
		}        
		
		
		cout<<"\n\n Digite Cedula : ";
		getline(cin,cedula);
		if ( cedula == "" )
		{
			do
			{
				cout<<"\n\n Digite Cedula : ";
				getline(cin,cedula);	
			}
			while (cedula == "" );
		}
		
			cout<<"\n\n Digite Telefono : ";
		getline(cin,telefono);
		if ( telefono == "" )
		{
			do
			{
				cout<<"\n\n Digite telefono : ";
				getline(cin,telefono);	
			}
			while (telefono == "" );
		}
		
		cout<<"\n\n Digite Email : ";
		getline(cin,email);
		if ( email == "" )
		{
			do
			{
				cout<<"\n\n Digite email : ";
				getline(cin,email);	
			}
			while (email == "" );
		}
		
		
		int opc = 9;
		while(opc!=0 && opc!=1){
			cout<<"\n\n Digite Genero : ";
			cout<<"\n 0: Mujer ";
			cout<<"\n 1: Hombre \n";
			cin >> opc;
			fflush(stdin);
			switch(opc)
			{
				case 0: genero="Mujer";  break;
				case 1: genero="Hombre";  break;
				
				default : cout <<"Ingreso Opcion no valida "; 
			}
		}
		
		opc = 9;
		while(opc!=1 && opc!=2){
			cout<<"\n\n Digite Nacionalidad  : ";
			cout<<"\n 1: Colombia ";
			cout<<"\n 2: Extranjero \n";
			cin >> opc;
			fflush(stdin);
			switch(opc)
			{
				case 1: nacionalidad="Colombiano";  break;
				case 2: nacionalidad="Extranjero";  break;
				
				default : cout <<"Ingreso Opcion no valida "; 
			}
		}
		
		
		
			 opc = 9;
		while(opc!=1 && opc!=2 && opc!=3 && opc!=4){
			cout<<"\n\n Digite Estado civil  : ";
			cout<<"\n 1: Soltero ";
			cout<<"\n 2: Separado";
			cout<<"\n 3: Viudo";
			cout<<"\n 4: Casado \n";
			cin >> opc;
			fflush(stdin);
			switch(opc)
			{
				case 1: estado_civil="Soltero";  break;
				case 2: estado_civil="Separado";  break;
				case 3: estado_civil="Viudo";  break;
				case 4: estado_civil="Casado";  break;
				
				default : cout <<"Ingreso Opcion no valida "; 
			}
		
		

		int con=0;
		  do
			{
					//se valida year que no este vacio
					cout<<"\n\n Digite  year de nacimiento : ";
					getline(cin,fecha_nacimientoA);
					
					if ( fecha_nacimientoA == "" )
					{
						do
						{
							cout<<"\n\n Digite  year de nacimiento : ";
							getline(cin,fecha_nacimientoA);	
						}
						while (fecha_nacimientoA == "" );
					}
					//se valida mes que no este vacio
					cout<<"\n\n Digite  mes de nacimiento : ";
					getline(cin,fecha_nacimientoM);
					if ( fecha_nacimientoM == "" )
					{
						do
						{
							cout<<"\n\n Digite  mes de nacimiento : ";
							getline(cin,fecha_nacimientoM);	
						}
						while (fecha_nacimientoM == "" );
					}
					
					
					//se valida dia que no este vacio
					cout<<"\n\n Digite  DIA de nacimiento : ";
					getline(cin,fecha_nacimientoD);
					if ( fecha_nacimientoD == "" )
					{
						do
						{
							cout<<"\n\n Digite  DIA de nacimiento : ";
							getline(cin,fecha_nacimientoD);	
						}
						while (fecha_nacimientoD == "" );
					}	
					if(year_actual- atoi(fecha_nacimientoA.c_str())>=18){
						if(year_actual- atoi(fecha_nacimientoA.c_str())>18){
							con=1;
							break;
						}
						if(mes_actual>= atoi(fecha_nacimientoM.c_str())){
							if(mes_actual> atoi(fecha_nacimientoM.c_str())){
								con=1;
								break;
							}
						
							if(dia_actual >=atoi(fecha_nacimientoD.c_str())){
						
								con=1;
								break;
							}else{
								cout<<"Es menor de edad";
							}
						}else{
							cout<<"Es menor de edad";
						}
							
					}else{
						cout<<"Es menor de edad";
					}
				
			}
			while (con==0 );
		
		
		cout<<"\n\n Digite RH : ";
		getline(cin,rh);
		if ( rh == "" )
		{
			do
			{
				cout<<"\n\n Digite RH : ";
				getline(cin,rh);	
			}
			while (rh == "" );
		}
	}
	activo = "0";
	escribir<<cedula<<endl<<nombre1<<endl<<nombre2<<endl<<apellido1<<endl<<apellido2<<endl<<telefono<<endl<<email<<endl<<genero<<endl<<nacionalidad<<endl<<estado_civil<<endl<<fecha_nacimientoA<<endl<<fecha_nacimientoM<<endl<<fecha_nacimientoD<<endl<<rh<<endl<<activo<<endl;	

	/*
	escribir<<aux_cedula<<endl<<aux_codigo<<endl<<aux_nombre<<endl<<aux_activo<<endl;	

	
	este forma es igual a la linea anterior 
	escribir<<aux_cedula<<endl;
	escribir<<aux_codigo<<endl;
	escribir<<aux_nombre<<endl;	
	*/
	escribir.close();
	
}}

//Modificar datos
void Datos_Basicos::modificar_DB()
{
	ifstream lectura;
    ofstream auxiliar;
    
    time_t t = time(NULL);
  	struct tm tiempoLocal = *localtime(&t);
  	int dia_actual=tiempoLocal.tm_mday;
  	int mes_actual=tiempoLocal.tm_mon+1;
  	int year_actual=(tiempoLocal.tm_year-100)+2000;
    
    bool encontrado=false;
    
    string auxCedula;
    char respuesta[5];
    
    lectura.open("Agenda.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    
    cout<<"\t\t\t\t*** Dar de baja un Amigo ***\t\t\t\t\n\n";
    if ( lectura.is_open() && auxiliar.is_open() )
    {
        fflush(stdin);
        cout<<"Ingresa el cedula del Amigo que deseas Modificar: ";
        getline(cin,auxCedula);
        
        getline(lectura,cedula);
        while( !lectura.eof() )
        {
			//getline(lectura,cedula);
            getline(lectura,nombre1);
            getline(lectura,nombre2);
            getline(lectura,apellido1);
            getline(lectura,apellido2);
            getline(lectura,telefono);
            getline(lectura,email);
            getline(lectura,genero);
            getline(lectura,nacionalidad);
            getline(lectura,estado_civil);
            getline(lectura,fecha_nacimientoA);   
            getline(lectura,fecha_nacimientoM);
            getline(lectura,fecha_nacimientoD);
            getline(lectura,rh);
            
            getline(lectura,activo);

            if(auxCedula == cedula && activo == "0")
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"Cedula                : "<<cedula<<endl;
                cout<<"Nombre1               : "<<nombre1<<endl;
                cout<<"Nombre2               : "<<nombre2<<endl;
                cout<<"apellido1             : "<<apellido1<<endl;
                cout<<"apellido2             : "<<apellido2<<endl;
                cout<<"telefono              : "<<telefono<<endl;
                cout<<"email                 : "<<email<<endl;
                cout<<"genero                : "<<genero<<endl;
                cout<<"nacionalidad          : "<<nacionalidad<<endl;
                cout<<"estado civil          : "<<estado_civil<<endl;
                cout<<"fecha year nacimiento : "<<fecha_nacimientoA<<endl;
                cout<<"fecha mes nacimiento  : "<<fecha_nacimientoM<<endl;
                cout<<"fecha dia nacimiento  : "<<fecha_nacimientoD<<endl;
                cout<<"rh                    : "<<rh<<endl;
                
                
                cout<<"MODIFICANDO DATOS DEL REGISTRO";
                
                cout<<"\n\n Digite Nombre 1 : ";
				getline(cin,nombre1);
		
				if ( nombre1 == "" ) // validamos que el nombre no este vacio
				{
					do
					{
						cout<<"\n\n Digite Nombre 1 : ";
						getline(cin,nombre1);	
					}
					while (nombre1 == "" );
				}
				
				cout<<"\n\n Digite Nombre 2: ";
				getline(cin,nombre2);

				if ( nombre2 == "" ) // validamos que el nombre no este vacio
				{
					do
					{
						cout<<"\n\n Digite Nombre 2: ";
						getline(cin,nombre2);	
					}
					while (nombre2 == "" );
				}
				
				 cout<<"\n\n Digite Apellido 1: ";
				getline(cin,apellido1);

				if ( apellido1 == "" ) // validamos que el nombre no este vacio
				{
					do
					{
						cout<<"\n\n Digite Apellido 1: ";
						getline(cin,apellido1);	
					}
					while (apellido1 == "" );
				}
				
				 cout<<"\n\n Digite Apellido 2: ";
				getline(cin,apellido2);

				if ( apellido2 == "" ) // validamos que el nombre no este vacio
				{
					do
					{
						cout<<"\n\n Digite Apellido 2: ";
						getline(cin,apellido2);	
					}
					while (apellido2 == "" );
				}
		
				cout<<"\n\n Digite Cedula : ";
				getline(cin,cedula);
				if ( cedula == "" )
				{
					do
					{
						cout<<"\n\n Digite Cedula : ";
						getline(cin,cedula);	
					}
					while (cedula == "" );
            	}
		
		 cout<<"\n\n Digite Telefono: ";
				getline(cin,telefono);

				if ( telefono == "" ) // validamos que el nombre no este vacio
				{
					do
					{
						cout<<"\n\n Digite Telefono: ";
						getline(cin,telefono);	
					}
					while (telefono == "" );
				}
				
				 cout<<"\n\n Digite Email: ";
				getline(cin,email);

				if ( email == "" ) // validamos que el nombre no este vacio
				{
					do
					{
						cout<<"\n\n Digite Email: ";
						getline(cin,email);	
					}
					while (email == "" );
				}
				
			int opc = 9;
			while(opc!=0 && opc!=1){
			cout<<"\n\n Digite Genero : ";
			cout<<"\n 0: Mujer ";
			cout<<"\n 1: Hombre ";
			
			cin >> opc;
			fflush(stdin);
			switch(opc)
			{
				case 0: genero="Mujer";  break;
				case 1: genero="Hombre";  break;
				
				default : cout <<"Ingreso Opcion no valida "; 
			}
		}
						 opc = 9;
			while(opc!=1 && opc!=2){
			cout<<"\n\n Digite Nacionalidad  : ";
			cout<<"\n 1: Colombia ";
			cout<<"\n 2: Extranjero \n";
			cin >> opc;
			fflush(stdin);
			switch(opc)
			{
				case 1: nacionalidad="Colombiano";  break;
				case 2: nacionalidad="Extranjero";  break;
				
				default : cout <<"Ingreso Opcion no valida "; 
			}
		}
				
				
						
			 opc = 9;
			while(opc!=1 && opc!=2 && opc!=3 && opc!=4){
			cout<<"\n\n Digite Estado civil  : ";
			cout<<"\n 1: Soltero ";
			cout<<"\n 2: Separado";
			cout<<"\n 3: Viudo";
			cout<<"\n 4: Casado \n";
			cin >> opc;
			fflush(stdin);
			switch(opc)
			{
				case 1: estado_civil="Soltero";  break;
				case 2: estado_civil="Separado";  break;
				case 3: estado_civil="Viudo";  break;
				case 4: estado_civil="Casado";  break;
				
				default : cout <<"Ingreso Opcion no valida "; 
			}
		}
				
				
		int con=0;
		  do
			{
					//se valida year que no este vacio
					cout<<"\n\n Digite  year de nacimiento : ";
					getline(cin,fecha_nacimientoA);
					
					if ( fecha_nacimientoA == "" )
					{
						do
						{
							cout<<"\n\n Digite  year de nacimiento : ";
							getline(cin,fecha_nacimientoA);	
						}
						while (fecha_nacimientoA == "" );
					}
					//se valida mes que no este vacio
					cout<<"\n\n Digite  mes de nacimiento : ";
					getline(cin,fecha_nacimientoM);
					if ( fecha_nacimientoM == "" )
					{
						do
						{
							cout<<"\n\n Digite  mes de nacimiento : ";
							getline(cin,fecha_nacimientoM);	
						}
						while (fecha_nacimientoM == "" );
					}
					
					
					//se valida dia que no este vacio
					cout<<"\n\n Digite  DIA de nacimiento : ";
					getline(cin,fecha_nacimientoD);
					if ( fecha_nacimientoD == "" )
					{
						do
						{
							cout<<"\n\n Digite  DIA de nacimiento : ";
							getline(cin,fecha_nacimientoD);	
						}
						while (fecha_nacimientoD == "" );
					}	
					if(year_actual- atoi(fecha_nacimientoA.c_str())>=18){
						if(year_actual- atoi(fecha_nacimientoA.c_str())>18){
							con=1;
							break;
						}
						if(mes_actual>= atoi(fecha_nacimientoM.c_str())){
							if(mes_actual> atoi(fecha_nacimientoM.c_str())){
								con=1;
								break;
							}
						
							if(dia_actual >=atoi(fecha_nacimientoD.c_str())){
						
								con=1;
								break;
							}else{
								cout<<"Es menor de edad";
							}
						}else{
							cout<<"Es menor de edad";
						}
							
					}else{
						cout<<"Es menor de edad";
					}
				
			}
			while (con==0 );
					 cout<<"\n\n Digite rh: ";
				getline(cin,rh);

				if ( rh == "" ) // validamos que el nombre no este vacio
				{
					do
					{
						cout<<"\n\n Digite rh: ";
						getline(cin,rh);	
					}
					while (rh == "" );
				}
		
				
		auxiliar<<cedula<<endl<<nombre1<<endl<<nombre2<<endl<<apellido1<<endl<<apellido2<<endl<<telefono<<endl<<email<<endl<<genero<<endl<<nacionalidad<<endl<<estado_civil<<endl<<fecha_nacimientoA<<endl<<fecha_nacimientoM<<endl<<fecha_nacimientoD<<endl<<rh<<endl<<activo<<endl;	
            }
            else
            {
		auxiliar<<cedula<<endl<<nombre1<<endl<<nombre2<<endl<<apellido1<<endl<<apellido2<<endl<<telefono<<endl<<email<<endl<<genero<<endl<<nacionalidad<<endl<<estado_civil<<endl<<fecha_nacimientoA<<endl<<fecha_nacimientoM<<endl<<fecha_nacimientoD<<endl<<rh<<endl<<activo<<endl;	
            }
            
            getline(lectura,cedula);
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontr\242 la cedula: "<<auxCedula<<"\n\n";
        }

    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("Agenda.txt");
    rename("auxiliar.txt","Agenda.txt");
    pausa();		
}

// borrado logico
void Datos_Basicos::borrado_logico_DB()
{
   	ifstream lectura;
    ofstream auxiliar;
    
    bool encontrado=false;
    
    string auxCedula;
    char respuesta[5];
    
    lectura.open("Agenda.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    
    cout<<"\t\t\t\t*** Dar de baja un Amigo ***\t\t\t\t\n\n";
    if ( lectura.is_open() && auxiliar.is_open() )
    {
        fflush(stdin);
        cout<<"Ingresa la cedula del Amigo que deseas dar de baja: ";
        getline(cin,auxCedula);
        
        getline(lectura,cedula);
        while( !lectura.eof() )
        {
		//	getline(lectura,cedula);
            getline(lectura,nombre1);
            getline(lectura,nombre2);
            getline(lectura,apellido1);
            getline(lectura,apellido2);
            getline(lectura,telefono);
            getline(lectura,email);
            getline(lectura,genero);
            getline(lectura,nacionalidad);
            getline(lectura,estado_civil);
            getline(lectura,fecha_nacimientoA);   
            getline(lectura,fecha_nacimientoM);
            getline(lectura,fecha_nacimientoD);
            getline(lectura,rh);
		
            getline(lectura,activo);

            if(auxCedula == cedula && activo == "0")
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                
                 cout<<"Cedula              : "<<cedula<<endl;
                cout<<"Nombre1              : "<<nombre1<<endl;
                cout<<"Nombre2              : "<<nombre2<<endl;
                cout<<"apellido1            : "<<apellido1<<endl;
                cout<<"apellido2            : "<<apellido2<<endl;
                cout<<"telefono             : "<<telefono<<endl;
                cout<<"email                : "<<email<<endl;
                cout<<"genero               : "<<genero<<endl;
                cout<<"nacionalidad         : "<<nacionalidad<<endl;
                cout<<"estado civil         : "<<estado_civil<<endl;
                cout<<"fecha year nacimiento: "<<fecha_nacimientoA<<endl;
                cout<<"fecha mes nacimiento : "<<fecha_nacimientoM<<endl;
                cout<<"fecha dia nacimiento : "<<fecha_nacimientoD<<endl;
                cout<<"rh                   : "<<rh<<endl;
                
                
                cout<<"Realmente deseas dar de Baja-Logico  (s/n)?: ";
                cin.getline(respuesta,5);
                
                if(strcmp(respuesta,"s")==0 || strcmp(respuesta,"S")==0 ||
                   strcmp(respuesta,"si")==0 ||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                        
                  {
                    cout<<"\n\nEl Amigo se ha dado de baja correctamente\n\n";
                    activo = "1";
                    auxiliar<<cedula<<"\n"<<nombre1<<"\n"<<nombre2<<"\n"<<apellido1<<"\n"<<apellido2<<"\n"<<telefono<<"\n"<<email<<"\n"<<genero<<"\n"<<nacionalidad<<"\n"<<estado_civil<<"\n"<<fecha_nacimientoA<<"\n"<<fecha_nacimientoM<<fecha_nacimientoD<<"\n"<<rh<<"\n"<<activo<<"\n";
                  }

                else
                {
                    cout<<"\n\nCliente conservado\n\n";
                    auxiliar<<cedula<<"\n"<<nombre1<<"\n"<<nombre2<<"\n"<<apellido1<<"\n"<<apellido2<<"\n"<<telefono<<"\n"<<email<<"\n"<<genero<<"\n"<<nacionalidad<<"\n"<<estado_civil<<"\n"<<fecha_nacimientoA<<"\n"<<fecha_nacimientoM<<fecha_nacimientoD<<"\n"<<rh<<"\n"<<activo<<"\n";
                }

            }
            else
            {
                    auxiliar<<cedula<<"\n"<<nombre1<<"\n"<<nombre2<<"\n"<<apellido1<<"\n"<<apellido2<<"\n"<<telefono<<"\n"<<email<<"\n"<<genero<<"\n"<<nacionalidad<<"\n"<<estado_civil<<"\n"<<fecha_nacimientoA<<"\n"<<fecha_nacimientoM<<fecha_nacimientoD<<"\n"<<rh<<"\n"<<activo<<"\n";
            }
            
            getline(lectura,cedula);
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontr\242 la cedula: "<<auxCedula<<"\n\n";
        }

    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("Agenda.txt");
    rename("auxiliar.txt","Agenda.txt");
    pausa();
}

// activar logico
void Datos_Basicos::activar_logico_DB()
{
   	ifstream lectura;
    ofstream auxiliar;
    
    bool encontrado=false;
    
    string auxCedua;
    char respuesta[5];//5
    
    lectura.open("Agenda.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    
    cout<<"\t\t\t\t*** Dar de baja un Amigo ***\t\t\t\t\n\n";
    if ( lectura.is_open() && auxiliar.is_open() )
    {
        fflush(stdin);
        cout <<"Activando los Registros Inactivados"<<endl; 
        getline(lectura,cedula);
        while( !lectura.eof() )
        {
		//	getline(lectura,cedula);
            getline(lectura,nombre1);
            getline(lectura,nombre2);
            getline(lectura,apellido1);
            getline(lectura,apellido2);
            getline(lectura,telefono);
            getline(lectura,email);
            getline(lectura,genero);
            getline(lectura,nacionalidad);
            getline(lectura,estado_civil);
            getline(lectura,fecha_nacimientoA);   
            getline(lectura,fecha_nacimientoM);
            getline(lectura,fecha_nacimientoD);
            getline(lectura,rh);
            
            getline(lectura,activo);
 			if(activo=="1"){
 				activo ="0";
                    auxiliar<<cedula<<"\n"<<nombre1<<"\n"<<nombre2<<"\n"<<apellido1<<"\n"<<apellido2<<"\n"<<telefono<<"\n"<<email<<"\n"<<genero<<"\n"<<nacionalidad<<"\n"<<estado_civil<<"\n"<<fecha_nacimientoA<<"\n"<<fecha_nacimientoM<<fecha_nacimientoD<<"\n"<<rh<<"\n"<<activo<<"\n";
			 }else{
			 	auxiliar<<cedula<<"\n"<<nombre1<<"\n"<<nombre2<<"\n"<<apellido1<<"\n"<<apellido2<<"\n"<<telefono<<"\n"<<email<<"\n"<<genero<<"\n"<<nacionalidad<<"\n"<<estado_civil<<"\n"<<fecha_nacimientoA<<"\n"<<fecha_nacimientoM<<fecha_nacimientoD<<"\n"<<rh<<"\n"<<activo<<"\n";
			 }
            
            getline(lectura,cedula);
        }
        cout <<"Fin Proceso de Activando los Registros"<<endl; 
    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("Agenda.txt");
    rename("auxiliar.txt","Agenda.txt");
    pausa();
}


// retirar
void Datos_Basicos::retirar_DB()
{	
	ifstream lectura;
    ofstream auxiliar;
    
    bool encontrado=false;
    
    string auxCedula;
    char respuesta[5];
    
    lectura.open("Agenda.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    
    cout<<"\t\t\t\t*** Dar de baja un Amigo ***\t\t\t\t\n\n";
    if ( lectura.is_open() && auxiliar.is_open() )
    {
        fflush(stdin);
        cout<<"Ingresa la cedula del Amigo que deseas dar de baja: ";
        getline(cin,auxCedula);
        
        getline(lectura,cedula);
        while( !lectura.eof() )
        {
		//	getline(lectura,cedula);
            getline(lectura,nombre1);
            getline(lectura,nombre2);
            getline(lectura,apellido1);
            getline(lectura,apellido2);
            getline(lectura,telefono);
            getline(lectura,email);
            getline(lectura,genero);
            getline(lectura,nacionalidad);
            getline(lectura,estado_civil);
            getline(lectura,fecha_nacimientoA);   
            getline(lectura,fecha_nacimientoM);
            getline(lectura,fecha_nacimientoD);
            getline(lectura,rh);
        
            getline(lectura,activo);

            if(auxCedula== cedula)
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                          
               cout<<"Cedula                 : "<<cedula<<endl;
                cout<<"Nombre1               : "<<nombre1<<endl;
                cout<<"Nombre2               : "<<nombre2<<endl;
                cout<<"apellido1             : "<<apellido1<<endl;
                cout<<"apellido2             : "<<apellido2<<endl;
                cout<<"telefono              : "<<telefono<<endl;
                cout<<"email                 : "<<email<<endl;
                cout<<"genero                : "<<genero<<endl;
                cout<<"nacionalidad          : "<<nacionalidad<<endl;
                cout<<"estado civil          : "<<estado_civil<<endl;
                cout<<"fecha year nacimiento : "<<fecha_nacimientoA<<endl;
                cout<<"fecha mes nacimiento  : "<<fecha_nacimientoM<<endl;
                cout<<"fecha dia nacimiento  : "<<fecha_nacimientoD<<endl;
                cout<<"rh                    : "<<rh<<endl;
                

                cout<<"Realmente deseas dar de baja  (s/n)?: ";
                cin.getline(respuesta,5);
                
                if(strcmp(respuesta,"s")==0 || strcmp(respuesta,"S")==0 ||
                   strcmp(respuesta,"si")==0 ||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                        
                  {
                    cout<<"\n\nEl Amigo se ha dado de baja correctamente\n\n";
                  }

                else
                {
                    cout<<"\n\nCliente conservado\n\n";
				auxiliar<<cedula<<"\n"<<nombre1<<"\n"<<nombre2<<"\n"<<apellido1<<"\n"<<apellido2<<"\n"<<telefono<<"\n"<<email<<"\n"<<genero<<"\n"<<nacionalidad<<"\n"<<estado_civil<<"\n"<<fecha_nacimientoA<<"\n"<<fecha_nacimientoM<<fecha_nacimientoD<<"\n"<<rh<<"\n"<<activo<<"\n";
                }

            }
            else
            {
				auxiliar<<cedula<<"\n"<<nombre1<<"\n"<<nombre2<<"\n"<<apellido1<<"\n"<<apellido2<<"\n"<<telefono<<"\n"<<email<<"\n"<<genero<<"\n"<<nacionalidad<<"\n"<<estado_civil<<"\n"<<fecha_nacimientoA<<"\n"<<fecha_nacimientoM<<fecha_nacimientoD<<"\n"<<rh<<"\n"<<activo<<"\n";            
        }
            getline(lectura,cedula);
            
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontr\242 la cedula : "<<auxCedula<"\n\n";
        }

    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("Agenda.txt");
    rename("auxiliar.txt","Agenda.txt");
    pausa();
}

// Listar

void Datos_Basicos::listar_DB()
{
    int i=0;
    ifstream lectura;
    lectura.open("Agenda.txt",ios::in);
    if(lectura.is_open())  // validamos que no presente error en la apertura del archivo
    {
        cout<<"\t\t\t\t***Listado de todos los clientes***\t\t\t\t\n\n";
        getline(lectura,cedula);
        
		
		while( !lectura.eof() ) // leer mmientras no sea el final del archivo
        {
           // getline(lectura,cedula);
             getline(lectura,nombre1);
            getline(lectura,nombre2);
            getline(lectura,apellido1);
            getline(lectura,apellido2);
            getline(lectura,telefono);
            getline(lectura,email);
            getline(lectura,genero);
            getline(lectura,nacionalidad);
            getline(lectura,estado_civil);
            getline(lectura,fecha_nacimientoA);   
            getline(lectura,fecha_nacimientoM);
            getline(lectura,fecha_nacimientoD);
            getline(lectura,rh);
            
            
            getline(lectura,activo);
            
            if (  activo == "0" )//( strcmp(activo,"0" == 0 )
            {
            	cout<<"Cedula                : "<<cedula<<endl;
                cout<<"Nombre1               : "<<nombre1<<endl;
                cout<<"Nombre2               : "<<nombre2<<endl;
                cout<<"apellido1             : "<<apellido1<<endl;
                cout<<"apellido2             : "<<apellido2<<endl;
                cout<<"telefono              : "<<telefono<<endl;
                cout<<"email                 : "<<email<<endl;
                cout<<"genero                : "<<genero<<endl;
                cout<<"nacionalidad          : "<<nacionalidad<<endl;
                cout<<"estado civil          : "<<estado_civil<<endl;
               	cout<<"fecha year nacimiento : "<<fecha_nacimientoA<<endl;
                cout<<"fecha mes nacimiento  : "<<fecha_nacimientoM<<endl;
                cout<<"fecha dia nacimiento  : "<<fecha_nacimientoD<<endl;
            	cout<<"rh : "<<rh<<endl;
            	
                i++;
            	cout<<"\n";
        	}
            getline(lectura,cedula);
        }
        if(i==1)
			   cout<<"Hay un solo cliente registrado \n\n";
        else
            cout<<"Hay un total de "<<i<<" clientes registrados \n\n";
    }
    else
    {
        error();
    }
    lectura.close();
    pausa();
}
/*  fin procedimiento Agenda */

/* iniciamos procedimientos Estudios */
// Menu general Estudios
 void Tabla_Estudios::menu_TE()
{
	int opc;
	opc = 9;
	do
	{
		system(CLEAR);
		cout <<"\n REGISTRAR DATOS ESTUDIOS "<<endl<<endl;
		cout <<"1. Ingresar Datos Estudios"<<endl;
		cout <<"2. Retirar Datos Estudios"<<endl;
		cout <<"3. Modificar Datos Estudios"<<endl;
		cout <<"4. Listar Datos Estudios "<<endl;
		cout <<"5. Borrado Logico Estudios"<<endl;
		cout <<"6. Acticar Logico Estudios"<<endl;
			
		cout <<"0. Salir del Menu"<<endl<<endl;
		cout <<"Digite Opcion :  ";
		cin >> opc;
		fflush(stdin);
		
		switch(opc)
		{
			case 1: ingresar_TE(); break;
			case 2: retirar_TE(); break;
			case 3: modificar_TE(); break;
			case 4: listar_TE(); break;
			case 5: borrado_logico_TE(); break;
			case 6: activar_logico_TE(); break;
			
			default : cout <<"Ingreso Opcion no valida "; 
		}
	}
	while ( opc != 0 );	
}

void Tabla_Estudios::ingresar_TE()
{
	ofstream escribir;  	// estudios
	ifstream lectura;		// Datos Agenda
	//fecha actual
	time_t t = time(NULL);
  	struct tm tiempoLocal = *localtime(&t);
  	int dia_actual=tiempoLocal.tm_mday;
  	int mes_actual=tiempoLocal.tm_mon+1;
  	int year_actual=(tiempoLocal.tm_year-100)+2000;
	
	//
	
	string bus_cedula;
	
	string aux1_nombre1;
	string aux1_nombre2;
	string aux1_apellido1;
	string aux1_apellido2;
	string aux1_telefono;
	string aux1_email;
	string aux1_genero;
	string aux1_nacionalidad;
	string aux1_estado_civil;
	string aux1_fecha_nacimientoA;
	string aux1_fecha_nacimientoM;
	string aux1_fecha_nacimientoD;

	string aux1_rh;
	string aux1_cedula;
    
    string aux1_activo;
    
	int encontro;
	encontro = 0;

	lectura.open("Agenda.txt",ios::in);
	escribir.open("Estudios.txt",ios::app);
	
	if ( escribir.is_open() )
	{
		cout<<"Estudios";
	}
	else
	{
		escribir.close();
		ofstream escribir_est;
		escribir.open("Estudios.txt",ios::out);	
	}	
	
	if ( escribir.is_open() && lectura.is_open() ) //Validamos que el archivo "escribir no presento error
 	{
		cout<<"\n\n Digite Datos de Estudios ";
		cout<<"\n\n Digite Cedula  : ";
		getline(cin,bus_cedula);
		fflush(stdin);
		
		
		if ( bus_cedula == "" ) // validamos que el nombre no este vacio
		{
			do
			{
				cout<<"\n\n Digite Cedula : ";
				getline(cin,bus_cedula);	
			}
			while (bus_cedula == "" );
		}
		
		getline(lectura,aux1_cedula);
        
		while( !lectura.eof() && encontro == 0)
        {				
			getline(lectura,aux1_nombre1);
            getline(lectura,aux1_nombre2);
            getline(lectura,aux1_apellido1);
            getline(lectura,aux1_apellido2);
            getline(lectura,aux1_telefono);
            getline(lectura,aux1_email);
            getline(lectura,aux1_genero);
            getline(lectura,aux1_nacionalidad);
            getline(lectura,aux1_estado_civil);
            getline(lectura,aux1_fecha_nacimientoA);
            getline(lectura,aux1_fecha_nacimientoM);
            getline(lectura,aux1_fecha_nacimientoD);

            getline(lectura,aux1_rh);
         //   getline(lectura,aux1_cedula);//
            
            
            getline(lectura,aux1_activo);
            
            //cout <<aux1_cedula <<endl<<aux1_nombre<<endl;

            if(aux1_cedula == bus_cedula)
            {
            cout<<aux1_cedula<<endl<<aux1_nombre1<<endl<<aux1_nombre2<<endl<<aux1_apellido1<<endl<<aux1_apellido2<<endl<<aux1_telefono<<endl<<aux1_email<<endl<<aux1_genero<<endl<<aux1_nacionalidad<<endl<<aux1_estado_civil<<endl<<aux1_fecha_nacimientoA<<endl<<aux1_fecha_nacimientoM<<aux1_fecha_nacimientoD<<endl<<aux1_rh<<endl;
            	
		        encontro = 1;
				cout<<"\n\n Digite Entidad educativa : ";
				getline(cin,entidad_educativa);
				if ( entidad_educativa == "" )
				{
					do
					{
						cout<<"\n\n Entidad educativa : ";
						getline(cin,entidad_educativa);	
					}
					while (entidad_educativa == "" );
				}
				
				cout<<"\n\n Digite titulo : ";
				getline(cin,titulo);
				if ( titulo == "" )
				{
					do
					{
						cout<<"\n\n Digite Titulo : ";
						getline(cin,titulo);	
					}
					while (titulo == "" );
				}
		//validar fecha de terminacion
			
					int con=0;
		  do
			{
					//se valida year que no este vacio
					cout<<"\n\n Digite  year de terminacion: ";
					getline(cin,fecha_terminacionA);
					
					if ( fecha_terminacionA == "" )
					{
						do
						{
							cout<<"\n\n Digite  year de terminacion : ";
							getline(cin,fecha_terminacionA);	
						}
						while (fecha_terminacionA == "" );
					}
					//se valida mes que no este vacio
					cout<<"\n\n Digite  mes de terminacion : ";
					getline(cin,fecha_terminacionM);
					if ( fecha_terminacionM == "" )
					{
						do
						{
							cout<<"\n\n Digite  mes de terminacion : ";
							getline(cin,fecha_terminacionM);	
						}
						while (fecha_terminacionM == "" );
					}
					
					
					//se valida dia que no este vacio
					cout<<"\n\n Digite  DIA de terminacion : ";
					getline(cin,fecha_terminacionD);
					if ( fecha_terminacionD == "" )
					{
						do
						{
							cout<<"\n\n Digite  DIA de terminacion : ";
							getline(cin,fecha_terminacionD);	
						}
						while (fecha_terminacionD == "" );
					}
					
					int yearR=(atoi(aux1_fecha_nacimientoA.c_str())+18);
						
					if(yearR<=atoi(fecha_terminacionA.c_str()) && atoi(fecha_terminacionA.c_str())<=year_actual){
						if(yearR<atoi(fecha_terminacionA.c_str()) && atoi(fecha_terminacionA.c_str())<year_actual){
							con=1;
							break;
						}
						if(atoi(aux1_fecha_nacimientoM.c_str())<= atoi(fecha_terminacionM.c_str()) 
						&& atoi(fecha_terminacionM.c_str())<=mes_actual){
							if(atoi(aux1_fecha_nacimientoM.c_str())< atoi(fecha_terminacionM.c_str())
							&& atoi(fecha_terminacionM.c_str())<mes_actual){
								con=1;
								break;
							}
						
							if(atoi(aux1_fecha_nacimientoD.c_str()) <=atoi(fecha_terminacionD.c_str())
							 && atoi(fecha_terminacionM.c_str())<=dia_actual){
						
								con=1;
								break;
							}else{
								cout<<"Es menor de edad o supera la fecha actual, no pudo terminar el estudio";
							}
						}else{
							cout<<"Es menor de edad o supera la fecha actual, no pudo terminar el estudio";
						}
							
					}else{
						cout<<"Es menor de edad o supera la fecha actual, no pudo terminar el estudio";
					}
				
			}
			while (con==0 );
				
				
				
				cedula = bus_cedula;
				escribir<<cedula<<endl<<entidad_educativa<<endl<<titulo<<endl<<fecha_terminacionA<<endl<<fecha_terminacionM<<endl<<fecha_terminacionD<<endl;
			}
			getline(lectura,aux1_cedula);	
		}
		if ( encontro == 0)
		{
			cout <<"\n\n Cedula no existe en el archivo";
			getch();
		}
	}
	escribir.close();
	lectura.close();
}

void Tabla_Estudios::activar_logico_TE()
{
	ifstream lectura;
    ofstream auxiliar;
    
    bool encontrado=false;
    
    string auxCedua;
    char respuesta[5];
    
    lectura.open("Estudios.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    
    cout<<"\t\t\t\t*** Dar de baja un Amigo ***\t\t\t\t\n\n";
    if ( lectura.is_open() && auxiliar.is_open() )
    {
        fflush(stdin);
        cout <<"Activando los Registros Inactivados"<<endl; 
        getline(lectura,cedula);
        while( !lectura.eof() )
        {
		//	getline(lectura,cedula);
            
            getline(lectura,entidad_educativa);
            getline(lectura,titulo);
            getline(lectura,fecha_terminacionA);
            getline(lectura,fecha_terminacionM);
            getline(lectura,fecha_terminacionD);
          
            
            getline(lectura,activo);
 
            activo = "0";
            auxiliar<<cedula<<"\n"<<entidad_educativa<<"\n"<<titulo<<"\n"<<fecha_terminacionA<<"\n"<<fecha_terminacionM<<"\n"<<fecha_terminacionD<<"\n"<<activo<<"\n";
            
            getline(lectura,cedula);
        }
        cout <<"Fin Proceso de Activando los Registros"<<endl; 
    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("Estudios.txt");
    rename("auxiliar.txt","Estudios.txt");
    pausa();
	
}

void Tabla_Estudios::borrado_logico_TE()
{ 
	ifstream lectura;
    ofstream auxiliar;
    
    bool encontrado=false;
    
    string auxCedula;
    char respuesta[5];
    
    lectura.open("Estudios.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    
    cout<<"\t\t\t\t*** Dar de baja un Amigo ***\t\t\t\t\n\n";
    if ( lectura.is_open() && auxiliar.is_open() )
    {
        fflush(stdin);
        cout<<"Ingresa la cedula del Amigo que deseas dar de baja: ";
        getline(cin,auxCedula);
        
        getline(lectura,cedula);
        while( !lectura.eof() )
        {
		//	getline(lectura,cedula);
           
            getline(lectura,entidad_educativa);
             getline(lectura,titulo);
            getline(lectura,fecha_terminacionA);
            getline(lectura,fecha_terminacionM);
            getline(lectura,fecha_terminacionD);
          
		
            getline(lectura,activo);

            if(auxCedula == cedula && activo == "0")
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                
                cout<<"Cedula               : "<<cedula<<endl;
                cout<<"Entidad educativa    : "<<entidad_educativa<<endl;
                cout<<"Titulo               : "<<titulo<<endl;
                cout<<"Year de terminacion  : "<<fecha_terminacionA<<endl;
                cout<<"Mes de terminacion   : "<<fecha_terminacionM<<endl;
                cout<<"Dia de terminacion   : "<<fecha_terminacionD<<endl;

                
                
                cout<<"Realmente deseas dar de Baja-Logico  (s/n)?: ";
                cin.getline(respuesta,5);
                
                if(strcmp(respuesta,"s")==0 || strcmp(respuesta,"S")==0 ||
                   strcmp(respuesta,"si")==0 ||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                        
                  {
                    cout<<"\n\nEl Amigo se ha dado de baja correctamente\n\n";
                    activo = "1";
                    auxiliar<<cedula<<"\n"<<entidad_educativa<<"\n"<<titulo<<"\n"<<fecha_terminacionA<<"\n"<<fecha_terminacionM<<"\n"<<fecha_terminacionD<<"\n"<<activo<<"\n";
                  }

                else
                {
                    cout<<"\n\nCliente conservado\n\n";
				auxiliar<<cedula<<"\n"<<entidad_educativa<<"\n"<<titulo<<"\n"<<fecha_terminacionA<<"\n"<<fecha_terminacionM<<"\n"<<fecha_terminacionD<<"\n"<<activo<<"\n";                }

            }
            else
            {
				auxiliar<<cedula<<"\n"<<entidad_educativa<<"\n"<<titulo<<"\n"<<fecha_terminacionA<<"\n"<<fecha_terminacionM<<"\n"<<fecha_terminacionD<<"\n"<<activo<<"\n";            }
            
            getline(lectura,cedula);
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontr\242 la cedula: "<<auxCedula<<"\n\n";
        }

    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("Estudios.txt");
    rename("auxiliar.txt","Estudios.txt");
    pausa();
	
}

void Tabla_Estudios::listar_TE()
{
	int i=0;
    ifstream lectura;
    ifstream leer_est;
    
    string aux1_cedula;
	string aux1_nombre1;
	string aux1_nombre2;
	string aux1_apellido1;
	string aux1_apellido2;
	string aux1_telefono;
	string aux1_email;
	string aux1_genero;
	string aux1_nacionalidad;
	string aux1_estado_civil;
	string aux1_fecha_nacimientoA;
	string aux1_fecha_nacimientoM;
	string aux1_fecha_nacimientoD;
	string aux1_rh;

    
    
    string aux1_activo;
    
    
    lectura.open("Agenda.txt",ios::in);
    leer_est.open("Estudios.txt",ios::in);
    
    
    if( lectura.is_open() && leer_est.is_open())    // validamos que no presente error en la apertura del archivo
    {
		
		cout<<"\t\t\t\t***Listado de todos los clientes***\t\t\t\t\n\n";
        getline(lectura,aux1_cedula);
        
		while( !lectura.eof() ) // leer mmientras no sea el final del archivo
        {
           getline(lectura,aux1_nombre1);
            getline(lectura,aux1_nombre2);
            getline(lectura,aux1_apellido1);
            getline(lectura,aux1_apellido2);
            getline(lectura,aux1_telefono);
            getline(lectura,aux1_email);
            getline(lectura,aux1_genero);
            getline(lectura,aux1_nacionalidad);
            getline(lectura,aux1_estado_civil);
            getline(lectura,aux1_fecha_nacimientoA);
            getline(lectura,aux1_fecha_nacimientoM);
            getline(lectura,aux1_fecha_nacimientoD);
             getline(lectura,aux1_rh);
            
          //  getline(lectura,aux1_cedula);//
            
            
            getline(lectura,aux1_activo);
            
            
            if (  aux1_activo == "0" )//( strcmp(activo,"0" == 0 )
            {
            		cout<<"\nCedula               : "<<aux1_cedula<<endl;
					cout<<"\nNombre 1             : "<<aux1_nombre1<<endl;
					cout<<"\nNombre 2             : "<<aux1_nombre2<<endl;
					cout<<"\nApellido 1           : "<<aux1_apellido1<<endl;
					cout<<"\nApellido 2           : "<<aux1_apellido2<<endl;
					cout<<"\nTelefono             : "<<aux1_telefono<<endl;
					cout<<"\nEmail                : "<<aux1_email<<endl;
					cout<<"\nGenero               : "<<aux1_genero<<endl;
					cout<<"\nNacionalidad         : "<<aux1_nacionalidad<<endl;
					cout<<"\nEstado civil         : "<<aux1_estado_civil<<endl;
					cout<<"\nyear de nacimiento   : "<<aux1_fecha_nacimientoA<<endl;
					cout<<"\nMes de nacimiento    : "<<aux1_fecha_nacimientoM<<endl;
					cout<<"\nDia de nacimiento    : "<<aux1_fecha_nacimientoD<<endl;
					cout<<"\nrh                   : "<<aux1_rh<<endl;
            	
            	
                i++;
    
            	getline(leer_est,cedula);
        
				while( !leer_est.eof() ) // leer mmientras no sea el final del archivo
        		{
           				getline(leer_est,entidad_educativa);
            			getline(leer_est,titulo);
            			getline(leer_est,fecha_terminacionA);
            			getline(leer_est,fecha_terminacionM);
            			getline(leer_est,fecha_terminacionD);
            		
            		if ( aux1_cedula == cedula )
            		{
            				cout <<"\n\nEntidad educativa   : "<<entidad_educativa<<endl;
            				cout <<"\n Titulo               : "<<titulo<<endl;
            				cout <<"\n year de terminacion  : "<<fecha_terminacionA<<endl;
            				cout <<"\n Mes de terminacion   : "<<fecha_terminacionM<<endl;
            				cout <<"\n Dia de terminacion   : "<<fecha_terminacionD<<endl;
					}
					getline(leer_est,cedula);
            	
            	}
            	cout<<"\n";
            	leer_est.close();
            	leer_est.open("Estudios.txt",ios::in);
        
        	}
            getline(lectura,aux1_cedula);
        }
    }
    else
    {
        error();
    }
    lectura.close();
    leer_est.close();
    pausa();

}

void Tabla_Estudios::modificar_TE()
{
	//lectura agenda datos basicos
//	ifstream lec_DB;
	
	ifstream lectura;
	ifstream lectura_DB;
    ofstream auxiliar;
    
    //variable fecha D B 
	string cedulaDB;
	string nombre1;
    string nombre2;
    string apellido1;
    string apellido2;
    string telefono;
    string email;
    string genero;
    string nacionalidad;
    string estado_civil;
    string aux1_fecha_nacimientoA;  
    string aux1_fecha_nacimientoM;
    string aux1_fecha_nacimientoD;
    string rh;
    string activo;
    
    
    time_t t = time(NULL);
  	struct tm tiempoLocal = *localtime(&t);
  	int dia_actual=tiempoLocal.tm_mday;
  	int mes_actual=tiempoLocal.tm_mon+1;
  	int year_actual=(tiempoLocal.tm_year-100)+2000;
    
    bool encontrado=false;
    
    string auxCedula;
    char respuesta[5];
    
    lectura.open("Estudios.txt",ios::in);
	lectura_DB.open("Agenda.txt",ios::in);
    
    
   // lec_DB.open("Agenda.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    
    cout<<"\t\t\t\t*** Dar de baja un Amigo ***\t\t\t\t\n\n";
    if ( lectura.is_open() && lectura_DB.is_open() && auxiliar.is_open() )
    {
        fflush(stdin);
        cout<<"Ingresa la cedula del Amigo que deseas Modificar: ";
        getline(cin,auxCedula);
        
        getline(lectura,cedula);
        while( !lectura_DB.eof() ){
		//	getline(lectura_DB,cedulaDB);
			getline(lectura_DB,nombre1);
            getline(lectura_DB,nombre2);
            getline(lectura_DB,apellido1);
            getline(lectura_DB,apellido2);
            getline(lectura_DB,telefono);
            getline(lectura_DB,email);
            getline(lectura_DB,genero);
            getline(lectura_DB,nacionalidad);
            getline(lectura_DB,estado_civil);
            getline(lectura_DB,aux1_fecha_nacimientoA);   
            getline(lectura_DB,aux1_fecha_nacimientoM);
            getline(lectura_DB,aux1_fecha_nacimientoD);
            getline(lectura_DB,rh);
            getline(lectura_DB,activo);
            
			if(auxCedula == cedulaDB ){
				break;
			}
		}
        while( !lectura.eof() )
        {
			//getline(lectura,cedula);
            
            getline(lectura,entidad_educativa);
            getline(lectura,titulo);
            getline(lectura,fecha_terminacionA);
            getline(lectura,fecha_terminacionM);
            getline(lectura,fecha_terminacionD);
         
            getline(lectura,activo);

            if(auxCedula == cedula )
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout <<"\n\nEntidad educativa    : "<<entidad_educativa<<endl;
            	cout <<"\n Titulo                : "<<titulo<<endl;
            	cout <<"\n year de terminacion   : "<<fecha_terminacionA<<endl;
            	cout <<"\n Mes de terminacion    : "<<fecha_terminacionM<<endl;
            	cout <<"\n Dia de terminacion    : "<<fecha_terminacionD<<endl;
                
                
                cout<<"MODIFICANDO DATOS DEL REGISTRO";
                
                cout<<"\n\n Digite Entidad educativa : ";
				getline(cin,entidad_educativa);
		
				if ( entidad_educativa == "" ) // validamos que la entidad E no este vacio
				{
					do
					{
						cout<<"\n\n Entidad educativa : ";
						getline(cin,entidad_educativa);	
					}
					while (entidad_educativa == "" );
				}
					
				 cout<<"\n\n Digite Titulo: ";
				getline(cin,titulo);

				if ( titulo == "" ) // validamos que e no este vacio
				{
					do
					{
						cout<<"\n\n Digite Titulo: ";
						getline(cin,titulo);	
					}
					while (titulo == "" );
				}
				
				//validar fecha de terminacion
			
					int con=0;
		  do
			{
					//se valida year que no este vacio
					cout<<"\n\n Digite  year de terminacion: ";
					getline(cin,fecha_terminacionA);
					
					if ( fecha_terminacionA == "" )
					{
						do
						{
							cout<<"\n\n Digite  year de terminacion : ";
							getline(cin,fecha_terminacionA);	
						}
						while (fecha_terminacionA == "" );
					}
					//se valida mes que no este vacio
					cout<<"\n\n Digite  mes de terminacion : ";
					getline(cin,fecha_terminacionM);
					if ( fecha_terminacionM == "" )
					{
						do
						{
							cout<<"\n\n Digite  mes de terminacion : ";
							getline(cin,fecha_terminacionM);	
						}
						while (fecha_terminacionM == "" );
					}
					
					
					//se valida dia que no este vacio
					cout<<"\n\n Digite  DIA de terminacion : ";
					getline(cin,fecha_terminacionD);
					if ( fecha_terminacionD == "" )
					{
						do
						{
							cout<<"\n\n Digite  DIA de terminacion : ";
							getline(cin,fecha_terminacionD);	
						}
						while (fecha_terminacionD == "" );
					}
					
					int yearR=(atoi(aux1_fecha_nacimientoA.c_str())+18);
						
					if(yearR<=atoi(fecha_terminacionA.c_str()) && atoi(fecha_terminacionA.c_str())<=year_actual){
						if(yearR<atoi(fecha_terminacionA.c_str()) && atoi(fecha_terminacionA.c_str())<year_actual){
							con=1;
							break;
						}
						if(atoi(aux1_fecha_nacimientoM.c_str())<= atoi(fecha_terminacionM.c_str()) 
						&& atoi(fecha_terminacionM.c_str())<=mes_actual){
							if(atoi(aux1_fecha_nacimientoM.c_str())< atoi(fecha_terminacionM.c_str())
							&& atoi(fecha_terminacionM.c_str())<mes_actual){
								con=1;
								break;
							}
						
							if(atoi(aux1_fecha_nacimientoD.c_str()) <=atoi(fecha_terminacionD.c_str())
							 && atoi(fecha_terminacionM.c_str())<=dia_actual){
						
								con=1;
								break;
							}else{
								cout<<"Es menor de edad o supera la fecha actual, no pudo terminar el estudio";
							}
						}else{
							cout<<"Es menor de edad o supera la fecha actual, no pudo terminar el estudio";
						}
							
					}else{
						cout<<"Es menor de edad o supera la fecha actual, no pudo terminar el estudio";
					}
				
			}
			while (con==0 );
			
					
		
						 
				
				
		auxiliar<<cedula<<endl<<entidad_educativa<<endl<<titulo<<endl<<fecha_terminacionA<<endl<<fecha_terminacionM<<endl<<fecha_terminacionD<<endl<<activo<<endl;//activo	
            }
            else
            {
		auxiliar<<cedula<<endl<<entidad_educativa<<endl<<titulo<<endl<<fecha_terminacionA<<endl<<fecha_terminacionM<<endl<<fecha_terminacionD<<endl<<activo<<endl;	//activo
            }
            
            getline(lectura,cedula);
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontr\242 la cedula: "<<auxCedula<<"\n\n";
        }

    }
    else
    {
        error();
    }
    lectura.close();
    lectura_DB.close();
    auxiliar.close();
    remove("Estudios.txt");
    rename("auxiliar.txt","Estudios.txt");
    pausa();		

		
}

void Tabla_Estudios::retirar_TE()
{
	int i=0;
	int encontro=0;
    ifstream lectura;
    ifstream leer_est;
    ofstream auxiliar;
    
    string aux1_nombre1;
	string aux1_nombre2;
	string aux1_apellido1;
	string aux1_apellido2;
	string aux1_telefono;
	string aux1_email;
	string aux1_genero;
	string aux1_nacionalidad;
	string aux1_estado_civil;
	string aux1_fecha_nacimientoA;
	string aux1_fecha_nacimientoM;
	string aux1_fecha_nacimientoD;
	string aux1_rh;
	string aux1_cedula;
    
    string auxCedula;
    
    string aux1_activo;
    //string auxCodigo;
    
    
    char respuesta[5];
    
    
    lectura.open("Agenda.txt",ios::in);
    leer_est.open("Estudios.txt",ios::in);
    auxiliar.open("aux_est.txt",ios::out);
    
    if( lectura.is_open() && leer_est.is_open())    // validamos que no presente error en la apertura del archivo
    {
			
		fflush(stdin);
        cout<<"Ingresa la cedula del Amigo que desea Borrar un EStudio: ";
        getline(cin,auxCedula);	
		
		cout<<"\t\t\t\t***Listado de todos los clientes***\t\t\t\t\n\n";
        getline(lectura,aux1_cedula);
        
		while( !lectura.eof()  ) // leer mmientras no sea el final del archivo
        {
           getline(lectura,aux1_nombre1);
            getline(lectura,aux1_nombre2);
            getline(lectura,aux1_apellido1);
            getline(lectura,aux1_apellido2);
            getline(lectura,aux1_telefono);
            getline(lectura,aux1_email);
            getline(lectura,aux1_genero);
            getline(lectura,aux1_nacionalidad);
            getline(lectura,aux1_estado_civil);
            getline(lectura,aux1_fecha_nacimientoA);
            getline(lectura,aux1_fecha_nacimientoM);
            getline(lectura,aux1_fecha_nacimientoD);
             getline(lectura,aux1_rh);
        //    getline(lectura,aux1_cedula);//
            
            
            getline(lectura,aux1_activo);
            
            
            if (  aux1_activo == "0" )//( strcmp(activo,"0" == 0 )
            {
            	
				if ( aux1_cedula == auxCedula )
				{
				    encontro = 1;
				    
					cout<<"\nCedula               : "<<aux1_cedula<<endl;
					cout<<"\nNombre 1             : "<<aux1_nombre1<<endl;
					cout<<"\nNombre 2             : "<<aux1_nombre2<<endl;
					cout<<"\nApellido 1           : "<<aux1_apellido1<<endl;
					cout<<"\nApellido 2           : "<<aux1_apellido2<<endl;
					cout<<"\nTelefono             : "<<aux1_telefono<<endl;
					cout<<"\nEmail                : "<<aux1_email<<endl;
					cout<<"\nGenero               : "<<aux1_genero<<endl;
					cout<<"\nNacionalidad         : "<<aux1_nacionalidad<<endl;
					cout<<"\nEstado civil         : "<<aux1_estado_civil<<endl;
					cout<<"\nyear de nacimiento   : "<<aux1_fecha_nacimientoA<<endl;
					cout<<"\nMes de nacimiento    : "<<aux1_fecha_nacimientoM<<endl;
					cout<<"\nDiade nacimiento     : "<<aux1_fecha_nacimientoD<<endl;
					cout<<"\nrh                   : "<<aux1_rh<<endl;;
            	
					
            		//cout<<"C\242digo : "<<aux1_codigo<<endl;
            		//cout<<"Nombre : "<<aux1_nombre<<endl;
                	
    
            		getline(leer_est,cedula);
        
					while( !leer_est.eof() ) // leer mmientras no sea el final del archivo
        			{
           				getline(leer_est,entidad_educativa);
            			getline(leer_est,titulo);
            			getline(leer_est,fecha_terminacionA);
            			getline(leer_est,fecha_terminacionM);
            			getline(leer_est,fecha_terminacionD);
            			
            		
            			if ( aux1_cedula == cedula )
            			{
            				cout <<"\n\n Entidad educativa   : "<<entidad_educativa<<endl;
            				cout <<"\n Titulo                : "<<titulo<<endl;
            				cout <<"\n Year de terminacion   : "<<fecha_terminacionA<<endl;
            				cout <<"\n Mes de terminacion    : "<<fecha_terminacionM<<endl;
            				cout <<"\n Dia de terminacion    : "<<fecha_terminacionD<<endl;
            				
            				cout<<"\n\nRealmente deseas dar de baja Registro (s/n)?: ";
                			cin.getline(respuesta,5);
                
                			if(strcmp(respuesta,"s")==0 || strcmp(respuesta,"S")==0 ||
                   				strcmp(respuesta,"si")==0 ||strcmp(respuesta,"SI")==0||
                        		strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
            				{
            					i++;
							}
							else
							{
							     auxiliar<<cedula<<endl<<entidad_educativa<<endl<<titulo<<endl<<fecha_terminacionA<<endl<<fecha_terminacionM<<endl<<fecha_terminacionD<<endl<<activo<<endl;
								 // escribimos en el auxiliar 
								 // encontramos los estudios de la persona pero no la borramos	
							}	
						}
						else
						{
							auxiliar<<cedula<<endl<<entidad_educativa<<endl<<titulo<<endl<<fecha_terminacionA<<endl<<fecha_terminacionM<<endl<<fecha_terminacionD<<endl<<activo<<endl;						
								// escribimos en el auxiliar 
							// no encontramos los estudios de la persona este le pertenece a otra persona
						}
						getline(leer_est,cedula);
            		}	
        		}
        	}
            getline(lectura,aux1_cedula);
        }
    }
    else
    {
        error();
    }
    lectura.close();
    leer_est.close();
    auxiliar.close();
    if ( encontro = 0 )
    { 
      cout<<"\n el Amigo buscado en la agenda no Existe ";
	}
	else
	{
		remove("Estudios.txt");
    	rename("aux_est.txt","Estudios.txt");		
	}
    pausa();
}




// Menu historaial laboral  
void Historial_Laboral::menu_HL()
{
	int opc;
	opc = 9;
	do
	{
		system(CLEAR);
		cout <<"\n REGISTRAR DATOS Historial Laboral "<<endl<<endl;
		cout <<"1. Ingresar Datos Historial Laboral"<<endl;
		cout <<"2. Retirar Datos Historial Laboral"<<endl;
		cout <<"3. Modificar Datos Historial Laboral"<<endl;
		cout <<"4. Listar Datos Historial Laboral "<<endl;
		cout <<"5. Borrado Logico Historial Laboral"<<endl;
		cout <<"6. Acticar Logico Historial Laboral"<<endl;
			
		cout <<"0. Salir del Menu"<<endl<<endl;
		cout <<"Digite Opcion :  ";
		cin >> opc;
		fflush(stdin);
		
		switch(opc)
		{
			case 1: ingresar_HL(); break;
			case 2: retirar_HL(); break;
			case 3: modificar_HL(); break;
			case 4: listar_HL(); break;
			case 5: borrado_logico_HL(); break;
		    case 6: activar_logico_HL(); break;
			
			default : cout <<"Ingreso Opcion no valida "; 
		}
	}
	while ( opc != 0 );	
}

void Historial_Laboral::ingresar_HL()
{
	ofstream escribir;  	// historial laboral
	ifstream lectura;		// Datos Agenda
	
	//fecha actual
	time_t t = time(NULL);
  	struct tm tiempoLocal = *localtime(&t);
  	int dia_actual=tiempoLocal.tm_mday;
  	int mes_actual=tiempoLocal.tm_mon+1;
  	int year_actual=(tiempoLocal.tm_year-100)+2000;
  
	//ifstream lectura_TE;//datos TABLA DE ESTUDIOS
	
	string bus_cedula;
	
	
	string aux1_nombre1;
	string aux1_nombre2;
	string aux1_apellido1;
	string aux1_apellido2;
	string aux1_telefono;
	string aux1_email;
	string aux1_genero;
	string aux1_nacionalidad;
	string aux1_estado_civil;
	string aux1_fecha_nacimientoA;
	string aux1_fecha_nacimientoM;
	string aux1_fecha_nacimientoD;
	string aux1_rh;
	string aux1_cedula;
	
	
    
    string aux1_activo;
    
	int encontro;
	encontro = 0;

	lectura.open("Agenda.txt",ios::in);
	
	//lectura_TE.open("Estudios.txt",ios::in);
	
	escribir.open("Historial_laboral.txt",ios::app);
	
	if ( escribir.is_open() )
	{
		cout<<"Historial laboral";
	}
	else
	{
		escribir.close();
		ofstream escribir_est;
		escribir.open("Historial_laboral.txt",ios::out);	
	}	
	
	if ( escribir.is_open() && lectura.is_open() ) //Validamos que el archivo "escribir no presento error
 	{
		cout<<"\n\n Digite Historial Laboral ";
		cout<<"\n\n Digite Cedula  : ";
		getline(cin,bus_cedula);
		fflush(stdin);
		
		
		if ( bus_cedula == "" ) // validamos que el nombre no este vacio
		{
			do
			{
				cout<<"\n\n Digite Cedula : ";
				getline(cin,bus_cedula);	
			}
			while (bus_cedula == "" );
		}
		
		getline(lectura,aux1_cedula);
        
		while( !lectura.eof() && encontro == 0)
        {				
			getline(lectura,aux1_nombre1);
            getline(lectura,aux1_nombre2);
            getline(lectura,aux1_apellido1);
            getline(lectura,aux1_apellido2);
            getline(lectura,aux1_telefono);
            getline(lectura,aux1_email);
            getline(lectura,aux1_genero);
            getline(lectura,aux1_nacionalidad);
            getline(lectura,aux1_estado_civil);
            getline(lectura,aux1_fecha_nacimientoA);
            getline(lectura,aux1_fecha_nacimientoM);
            getline(lectura,aux1_fecha_nacimientoD);
            getline(lectura,aux1_rh);
            
            
         //   getline(lectura,aux1_cedula);//
            
            
            getline(lectura,aux1_activo);
            
            //cout <<aux1_cedula <<endl<<aux1_nombre<<endl;

            if(aux1_cedula == bus_cedula)
            {
            cout <<aux1_cedula <<endl<<aux1_nombre1<<endl<<aux1_nombre2<<endl<<aux1_apellido1<<endl<<aux1_apellido2<<endl<<aux1_telefono<<endl<<aux1_email<<endl<<aux1_genero<<endl<<aux1_nacionalidad<<endl<<aux1_estado_civil<<endl<<aux1_fecha_nacimientoA<<endl<<aux1_fecha_nacimientoM<<endl<<aux1_fecha_nacimientoD<<endl<<aux1_rh<<endl;
            	
		        encontro = 1;
				cout<<"\n\n Digite la Empresa : ";
				getline(cin,empresa);
				if ( empresa == "" )
				{
					do
					{
						cout<<"\n\n Entidad la Empresa : ";
						getline(cin,empresa);	
					}
					while (empresa == "" );
				}
				
				cout<<"\n\n Digite Cargo : ";
				getline(cin,cargo);
				if ( cargo == "" )
				{
					do
					{
						cout<<"\n\n Digite Cargo : ";
						getline(cin,cargo);	
					}
					while (cargo == "" );
				}
		
			
			//validar fecha inicio
			
				int con=0;
		  do
			{
					//se valida year que no este vacio
					cout<<"\n\n Digite  year de inicio: ";
					getline(cin,fecha_inicioA);
					
					if ( fecha_inicioA == "" )
					{
						do
						{
							cout<<"\n\n Digite  year de inicio : ";
							getline(cin,fecha_inicioA);	
						}
						while (fecha_inicioA == "" );
					}
					//se valida mes que no este vacio
					cout<<"\n\n Digite  mes de inicio : ";
					getline(cin,fecha_inicioM);
					if ( fecha_inicioM == "" )
					{
						do
						{
							cout<<"\n\n Digite  mes de inicio : ";
							getline(cin,fecha_inicioM);	
						}
						while (fecha_inicioM == "" );
					}
					
					
					//se valida dia que no este vacio
					cout<<"\n\n Digite  Dia de inicio : ";
					getline(cin,fecha_inicioD);
					if ( fecha_inicioD == "" )
					{
						do
						{
							cout<<"\n\n Digite  Dia de inicio : ";
							getline(cin,fecha_inicioD);	
						}
						while (fecha_inicioD == "" );
					}
					
					int yearR=(atoi(aux1_fecha_nacimientoA.c_str())+18);
						
					if(yearR<=atoi(fecha_inicioA.c_str()) && atoi(fecha_inicioA.c_str())<=year_actual){
						if(yearR<atoi(fecha_inicioA.c_str()) && atoi(fecha_inicioA.c_str())<year_actual){
							con=1;
							break;
						}
						if(atoi(aux1_fecha_nacimientoM.c_str())<= atoi(fecha_inicioM.c_str()) 
						&& atoi(fecha_inicioM.c_str())<=mes_actual){
							if(atoi(aux1_fecha_nacimientoM.c_str())< atoi(fecha_inicioM.c_str())
							&& atoi(fecha_inicioM.c_str())<mes_actual){
								con=1;
								break;
							}
						
							if(atoi(aux1_fecha_nacimientoD.c_str()) <=atoi(fecha_inicioD.c_str())
							 && atoi(fecha_inicioD.c_str())<=dia_actual){
						
								con=1;
								break;
							}else{
								cout<<"Es menor de edad o supera la fecha actual, (fecha iniciar ) ";
							}
						}else{
							cout<<"Es menor de edad o supera la fecha actual, (fecha iniciar ) ";
						}
							
					}else{
						cout<<"Es menor de edad o supera la fecha actual, (fecha iniciar )";
					}
				
			}
			while (con==0 );
		
			
				
				
				//VALIDAD FECHA DE TERMINACION
				
				int c=0;
		  do
			{
					//se valida year que no este vacio
					cout<<"\n\n Digite  year de terminacion: ";
					getline(cin,fecha_terminacionA);
					
					if ( fecha_terminacionA == "" )
					{
						do
						{
							cout<<"\n\n Digite  year de terminacion : ";
							getline(cin,fecha_terminacionA);	
						}
						while (fecha_terminacionA == "" );
					}
					//se valida mes que no este vacio
					cout<<"\n\n Digite  mes de terminacion : ";
					getline(cin,fecha_terminacionM);
					if ( fecha_terminacionM == "" )
					{
						do
						{
							cout<<"\n\n Digite  mes de terminacion : ";
							getline(cin,fecha_terminacionM);	
						}
						while (fecha_terminacionM == "" );
					}
					
					
					//se valida dia que no este vacio
					cout<<"\n\n Digite  DIA de terminacion : ";
					getline(cin,fecha_terminacionD);
					if ( fecha_terminacionD == "" )
					{
						do
						{
							cout<<"\n\n Digite  DIA de terminacion : ";
							getline(cin,fecha_terminacionD);	
						}
						while (fecha_terminacionD == "" );
					}
					
					int yearR=(atoi(aux1_fecha_nacimientoA.c_str())+18);
						
					if(yearR<=atoi(fecha_terminacionA.c_str()) && atoi(fecha_terminacionA.c_str())<=year_actual){
						if(yearR<atoi(fecha_terminacionA.c_str()) && atoi(fecha_terminacionA.c_str())<year_actual){
							c=1;
							break;
						}
						if(atoi(aux1_fecha_nacimientoM.c_str())<= atoi(fecha_terminacionM.c_str()) 
						&& atoi(fecha_terminacionM.c_str())<=mes_actual){
							if(atoi(aux1_fecha_nacimientoM.c_str())< atoi(fecha_terminacionM.c_str())
							&& atoi(fecha_terminacionM.c_str())<mes_actual){
								c=1;
								break;
							}
						
							if(atoi(aux1_fecha_nacimientoD.c_str()) <=atoi(fecha_terminacionD.c_str())
							 && atoi(fecha_terminacionM.c_str())<=dia_actual){
						
								c=1;
								break;
							}else{
								cout<<"Es menor de edad o supera la fecha actual, no pudo terminar ";
							}
						}else{
							cout<<"Es menor de edad o supera la fecha actual, no pudo terminar ";
						}
							
					}else{
						cout<<"Es menor de edad o supera la fecha actual, no pudo terminar ";
					}
				
			}
			while (c==0 );
			
		
				
				cedula = bus_cedula;
				escribir<<cedula<<endl<<empresa<<endl<<cargo<<endl<<fecha_inicioA<<endl<<fecha_inicioM<<endl<<fecha_inicioD<<endl<<fecha_terminacionA<<endl<<fecha_terminacionM<<endl<<fecha_terminacionD<<endl;
			}
			getline(lectura,aux1_cedula);	
		}
		if ( encontro == 0)
		{
			cout <<"\n\n Cedula no existe en el archivo";
			getch();
		}
	}
	escribir.close();
	lectura.close();
	
}

void Historial_Laboral::borrado_logico_HL()
{
	ifstream lectura;
    ofstream auxiliar;
    
    bool encontrado=false;
    
    string auxCedula;
    char respuesta[5];
    
    lectura.open("Historial_laboral.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    
    cout<<"\t\t\t\t*** Dar de baja un Amigo ***\t\t\t\t\n\n";
    if ( lectura.is_open() && auxiliar.is_open() )
    {
        fflush(stdin);
        cout<<"Ingresa la cedula del Amigo que deseas dar de baja: ";
        getline(cin,auxCedula);
        
        getline(lectura,cedula);
        while( !lectura.eof() )
        {
		//	getline(lectura,cedula);
            getline(lectura,empresa);
            getline(lectura,cargo);
            getline(lectura,fecha_inicioA);
            getline(lectura,fecha_inicioM);
            getline(lectura,fecha_inicioD);
            getline(lectura,fecha_terminacionA);
            getline(lectura,fecha_terminacionM);
            getline(lectura,fecha_terminacionD);
		
            getline(lectura,activo);

            if(auxCedula == cedula && activo == "0")
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                
                cout<<"Cedula               : "<<cedula<<endl;
                cout<<"Empresa              : "<<empresa<<endl;
                cout<<"Cargo                : "<<cargo<<endl;
                cout<<"Year de inicio       : "<<fecha_inicioA<<endl;
                cout<<"Mes de inicio        : "<<fecha_inicioM<<endl;
                cout<<"Dia de inicio        : "<<fecha_inicioD<<endl;
                cout<<"Year de terminacion  : "<<fecha_terminacionA<<endl;
                cout<<"Mes de terminacion   : "<<fecha_terminacionM<<endl;
                cout<<"a de terminacion     : "<<fecha_terminacionD<<endl;
                
                
                cout<<"Realmente deseas dar de Baja-Logico  (s/n)?: ";
                cin.getline(respuesta,5);
                
                if(strcmp(respuesta,"s")==0 || strcmp(respuesta,"S")==0 ||
                   strcmp(respuesta,"si")==0 ||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                        
                  {
                    cout<<"\n\nEl Amigo se ha dado de baja correctamente\n\n";
                    activo = "1";
                    auxiliar<<cedula<<"\n"<<empresa<<"\n"<<cargo<<"\n"<<fecha_inicioA<<"\n"<<fecha_inicioM<<"\n"<<fecha_inicioD<<"\n"<<fecha_terminacionA<<"\n"<<fecha_terminacionM<<"\n"<<fecha_terminacionD<<"\n"<<activo<<"\n";
                  }

                else
                {
                    cout<<"\n\nCliente conservado\n\n";
                    auxiliar<<cedula<<"\n"<<empresa<<"\n"<<cargo<<"\n"<<fecha_inicioA<<"\n"<<fecha_inicioM<<"\n"<<fecha_inicioD<<"\n"<<fecha_terminacionA<<"\n"<<fecha_terminacionM<<"\n"<<fecha_terminacionD<<"\n"<<activo<<"\n";
                }

            }
            else
            {
                    auxiliar<<cedula<<"\n"<<empresa<<"\n"<<cargo<<"\n"<<fecha_inicioA<<"\n"<<fecha_inicioM<<"\n"<<fecha_inicioD<<"\n"<<fecha_terminacionA<<"\n"<<fecha_terminacionM<<"\n"<<fecha_terminacionD<<"\n"<<activo<<"\n";
            }
            
            getline(lectura,cedula);
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontr\242 la cedula: "<<auxCedula<<"\n\n";
        }

    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("Historial_laboral.txt");
    rename("auxiliar.txt","Historial_laboral.txt");
    pausa();
	
}

void Historial_Laboral::activar_logico_HL()
{
	ifstream lectura;
    ofstream auxiliar;
    
    bool encontrado=false;
    
    string auxCedua;
    char respuesta[5];
    
    lectura.open("Historial_laboral.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    
    cout<<"\t\t\t\t*** Dar de baja un Amigo ***\t\t\t\t\n\n";
    if ( lectura.is_open() && auxiliar.is_open() )
    {
        fflush(stdin);
        cout <<"Activando los Registros Inactivados"<<endl; 
        getline(lectura,cedula);
        while( !lectura.eof() )
        {
		//	getline(lectura,cedula);
           getline(lectura,empresa);
            getline(lectura,cargo);
            getline(lectura,fecha_inicioA);
            getline(lectura,fecha_inicioM);
            getline(lectura,fecha_inicioD);
            getline(lectura,fecha_terminacionA);
            getline(lectura,fecha_terminacionM);
            getline(lectura,fecha_terminacionD);
          
            
            getline(lectura,activo);
 
            activo = "0";
                    auxiliar<<cedula<<"\n"<<empresa<<"\n"<<cargo<<"\n"<<fecha_inicioA<<"\n"<<fecha_inicioM<<"\n"<<fecha_inicioD<<"\n"<<fecha_terminacionA<<"\n"<<fecha_terminacionM<<"\n"<<fecha_terminacionD<<"\n"<<activo<<"\n";
            
            getline(lectura,cedula);
        }
        cout <<"Fin Proceso de Activando los Registros"<<endl; 
    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("Historial_laboral.txt");
    rename("auxiliar.txt","Historial_laboral.txt");
    pausa();

	
}

void Historial_Laboral::modificar_HL()//validar inicio y termin
{
		//lectura agenda datos basicos

	
	ifstream lectura;
	ifstream lectura_DB;
    ofstream auxiliar;
    
    //variable fecha D B 
	string cedulaDB;
	string nombre1;
    string nombre2;
    string apellido1;
    string apellido2;
    string telefono;
    string email;
    string genero;
    string nacionalidad;
    string estado_civil;
    string aux1_fecha_nacimientoA;  
    string aux1_fecha_nacimientoM;
    string aux1_fecha_nacimientoD;
    string rh;
    string activo;
    
    
    time_t t = time(NULL);
  	struct tm tiempoLocal = *localtime(&t);
  	int dia_actual=tiempoLocal.tm_mday;
  	int mes_actual=tiempoLocal.tm_mon+1;
  	int year_actual=(tiempoLocal.tm_year-100)+2000;
    
    bool encontrado=false;
    
    string auxCedula;
    char respuesta[5];
    
    lectura.open("Historial_laboral.txt",ios::in);
	lectura_DB.open("Agenda.txt",ios::in);
    
    
   // lec_DB.open("Agenda.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    
    cout<<"\t\t\t\t*** Dar de baja un Amigo ***\t\t\t\t\n\n";
    if ( lectura.is_open() && lectura_DB.is_open() && auxiliar.is_open() )
    {
        fflush(stdin);
        cout<<"Ingresa el cedula del Amigo que deseas Modificar: ";
        getline(cin,auxCedula);
        
        getline(lectura,cedula);
        while( !lectura_DB.eof() ){
		//	getline(lectura_DB,cedulaDB);
			getline(lectura_DB,nombre1);
            getline(lectura_DB,nombre2);
            getline(lectura_DB,apellido1);
            getline(lectura_DB,apellido2);
            getline(lectura_DB,telefono);
            getline(lectura_DB,email);
            getline(lectura_DB,genero);
            getline(lectura_DB,nacionalidad);
            getline(lectura_DB,estado_civil);
            getline(lectura_DB,aux1_fecha_nacimientoA);   
            getline(lectura_DB,aux1_fecha_nacimientoM);
            getline(lectura_DB,aux1_fecha_nacimientoD);
            getline(lectura_DB,rh);
            getline(lectura_DB,activo);
            
			if(auxCedula == cedulaDB ){
				break;
			}
		}
        while( !lectura.eof() )
        {
			//getline(lectura,cedula);
            
            getline(lectura,empresa);
            getline(lectura,cargo);
            getline(lectura,fecha_inicioA);
            getline(lectura,fecha_inicioM);
            getline(lectura,fecha_inicioD);
            getline(lectura,fecha_terminacionA);
            getline(lectura,fecha_terminacionM);
            getline(lectura,fecha_terminacionD);
         
            getline(lectura,activo);

            if(auxCedula == cedula )
            {
                encontrado=true;
               				 cout<<"\n\nRegistro Encontrado\n\n";
                			cout <<"\n\n Empresa           : "<<empresa<<endl;
            				cout <<"\n Cargo               : "<<cargo<<endl;
            				cout <<"\n Year de inicio      : "<<fecha_inicioA<<endl;
            				cout <<"\n Mes de inicio       : "<<fecha_inicioM<<endl;
            				cout <<"\n Dia de inicio       : "<<fecha_inicioD<<endl;
            				cout <<"\n Year de terminacion : "<<fecha_terminacionA<<endl;
            				cout <<"\n Mes de terminacion  : "<<fecha_terminacionM<<endl;
            				cout <<"\n Dia de terminacion  : "<<fecha_terminacionD<<endl;
                
                
                cout<<"MODIFICANDO DATOS DEL REGISTRO";
                
                cout<<"\n\n Digite Empresa : ";
				getline(cin,empresa);
		
				if ( empresa == "" ) // validamos que la entidad E no este vacio
				{
					do
					{
						cout<<"\n\n Digite Empresa : ";
						getline(cin,empresa);	
					}
					while (empresa == "" );
				}
					
				 cout<<"\n\n Digite Cargo: ";
				getline(cin,cargo);

				if ( cargo == "" ) // validamos que e no este vacio
				{
					do
					{
						cout<<"\n\n Digite Cargo: ";
						getline(cin,cargo);	
					}
					while (cargo == "" );
				}
				
				//validar fecha de inicion
			int con=0;
		  do
			{
					//se valida year que no este vacio
					cout<<"\n\n Digite  year de inicio: ";
					getline(cin,fecha_inicioA);
					
					if ( fecha_inicioA == "" )
					{
						do
						{
							cout<<"\n\n Digite  year de inicio : ";
							getline(cin,fecha_inicioA);	
						}
						while (fecha_inicioA == "" );
					}
					//se valida mes que no este vacio
					cout<<"\n\n Digite  mes de inicio : ";
					getline(cin,fecha_inicioM);
					if ( fecha_inicioM == "" )
					{
						do
						{
							cout<<"\n\n Digite  mes de inicio : ";
							getline(cin,fecha_inicioM);	
						}
						while (fecha_inicioM == "" );
					}
					
					
					//se valida dia que no este vacio
					cout<<"\n\n Digite  Dia de inicio : ";
					getline(cin,fecha_inicioD);
					if ( fecha_inicioD == "" )
					{
						do
						{
							cout<<"\n\n Digite  Dia de inicio : ";
							getline(cin,fecha_inicioD);	
						}
						while (fecha_inicioD == "" );
					}
					
					int yearR=(atoi(aux1_fecha_nacimientoA.c_str())+18);
						
					if(yearR<=atoi(fecha_inicioA.c_str()) && atoi(fecha_inicioA.c_str())<=year_actual){
						if(yearR<atoi(fecha_inicioA.c_str()) && atoi(fecha_inicioA.c_str())<year_actual){
							con=1;
							break;
						}
						if(atoi(aux1_fecha_nacimientoM.c_str())<= atoi(fecha_inicioM.c_str()) 
						&& atoi(fecha_inicioM.c_str())<=mes_actual){
							if(atoi(aux1_fecha_nacimientoM.c_str())< atoi(fecha_inicioM.c_str())
							&& atoi(fecha_inicioM.c_str())<mes_actual){
								con=1;
								break;
							}
						
							if(atoi(aux1_fecha_nacimientoD.c_str()) <=atoi(fecha_inicioD.c_str())
							 && atoi(fecha_inicioD.c_str())<=dia_actual){
						
								con=1;
								break;
							}else{
								cout<<"Es menor de edad o supera la fecha actual, iniciar ";
							}
						}else{
							cout<<"Es menor de edad o supera la fecha actual, iniciar ";
						}
							
					}else{
						cout<<"Es menor de edad o supera la fecha actual, iniciar";
					}
				
			}
			while (con==0 );
			
				
				//VALIDAD FECHA DE TERMINACION
				
				int c=0;
		  do
			{
					//se valida year que no este vacio
					cout<<"\n\n Digite  year de terminacion: ";
					getline(cin,fecha_terminacionA);
					
					if ( fecha_terminacionA == "" )
					{
						do
						{
							cout<<"\n\n Digite  year de terminacion : ";
							getline(cin,fecha_terminacionA);	
						}
						while (fecha_terminacionA == "" );
					}
					//se valida mes que no este vacio
					cout<<"\n\n Digite  mes de terminacion : ";
					getline(cin,fecha_terminacionM);
					if ( fecha_terminacionM == "" )
					{
						do
						{
							cout<<"\n\n Digite  mes de terminacion : ";
							getline(cin,fecha_terminacionM);	
						}
						while (fecha_terminacionM == "" );
					}
					
					
					//se valida dia que no este vacio
					cout<<"\n\n Digite  DIA de terminacion : ";
					getline(cin,fecha_terminacionD);
					if ( fecha_terminacionD == "" )
					{
						do
						{
							cout<<"\n\n Digite  DIA de terminacion : ";
							getline(cin,fecha_terminacionD);	
						}
						while (fecha_terminacionD == "" );
					}
					
					int yearR=(atoi(aux1_fecha_nacimientoA.c_str())+18);
						
					if(yearR<=atoi(fecha_terminacionA.c_str()) && atoi(fecha_terminacionA.c_str())<=year_actual){
						if(yearR<atoi(fecha_terminacionA.c_str()) && atoi(fecha_terminacionA.c_str())<year_actual){
							c=1;
							break;
						}
						if(atoi(aux1_fecha_nacimientoM.c_str())<= atoi(fecha_terminacionM.c_str()) 
						&& atoi(fecha_terminacionM.c_str())<=mes_actual){
							if(atoi(aux1_fecha_nacimientoM.c_str())< atoi(fecha_terminacionM.c_str())
							&& atoi(fecha_terminacionM.c_str())<mes_actual){
								c=1;
								break;
							}
						
							if(atoi(aux1_fecha_nacimientoD.c_str()) <=atoi(fecha_terminacionD.c_str())
							 && atoi(fecha_terminacionM.c_str())<=dia_actual){
						
								c=1;
								break;
							}else{
								cout<<"Es menor de edad o supera la fecha actual, no pudo terminar ";
							}
						}else{
							cout<<"Es menor de edad o supera la fecha actual, no pudo terminar ";
						}
							
					}else{
						cout<<"Es menor de edad o supera la fecha actual, no pudo terminar";
					}
				
			}
			while (c==0 );
			
			
					
		
						 
				
				
		auxiliar<<cedula<<endl<<empresa<<endl<<cargo<<endl<<fecha_inicioA<<endl<<fecha_inicioM<<endl<<fecha_inicioD<<endl<<fecha_terminacionA<<endl<<fecha_terminacionM<<endl<<fecha_inicioD<<endl<<activo<<endl;//activo	
            }
            else
            {
		auxiliar<<cedula<<endl<<empresa<<endl<<cargo<<endl<<fecha_inicioA<<endl<<fecha_inicioM<<endl<<fecha_inicioD<<endl<<fecha_terminacionA<<endl<<fecha_terminacionM<<endl<<fecha_inicioD<<endl<<activo<<endl;//activo	
            }
            
            getline(lectura,cedula);
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontr\242 la cedula: "<<auxCedula<<"\n\n";
        }

    }
    else
    {
        error();
    }
    lectura.close();
    lectura_DB.close();
    auxiliar.close();
    remove("Historial_laboral.txt");
    rename("auxiliar.txt","Historial_laboral.txt");
    pausa();		
	
	
}

void Historial_Laboral::retirar_HL()
{
	
	int i=0;
	int encontro=0;
    ifstream lectura;
    ifstream leer_est;
    ofstream auxiliar;
    
	
    
    string aux1_nombre1;
	string aux1_nombre2;
	string aux1_apellido1;
	string aux1_apellido2;
	string aux1_telefono;
	string aux1_email;
	string aux1_genero;
	string aux1_nacionalidad;
	string aux1_estado_civil;
	string aux1_fecha_nacimientoA;
	string aux1_fecha_nacimientoM;
	string aux1_fecha_nacimientoD;
	string aux1_rh;
	string aux1_cedula;
    
    string auxCedula;
    
    string aux1_activo;
    //string auxCodigo;
    
    
    char respuesta[5];
    
    
    lectura.open("Agenda.txt",ios::in);
    leer_est.open("Historial_laboral.txt",ios::in);
    auxiliar.open("aux_est.txt",ios::out);
    
    if( lectura.is_open() && leer_est.is_open())    // validamos que no presente error en la apertura del archivo
    {
			
		fflush(stdin);
        cout<<"Ingresa la cedula del Amigo que desea Borrar el historial laboral: ";
        getline(cin,auxCedula);	
		
		cout<<"\t\t\t\t***Listado de todos los clientes***\t\t\t\t\n\n";
        getline(lectura,aux1_cedula);
        
		while( !lectura.eof()  ) // leer mmientras no sea el final del archivo
        {
            getline(lectura,aux1_nombre1);
            getline(lectura,aux1_nombre2);
            getline(lectura,aux1_apellido1);
            getline(lectura,aux1_apellido2);
            getline(lectura,aux1_telefono);
            getline(lectura,aux1_email);
            getline(lectura,aux1_genero);
            getline(lectura,aux1_nacionalidad);
            getline(lectura,aux1_estado_civil);
            getline(lectura,aux1_fecha_nacimientoA);
            getline(lectura,aux1_fecha_nacimientoM);
            getline(lectura,aux1_fecha_nacimientoD);
            
            getline(lectura,aux1_rh);
        //    getline(lectura,aux1_cedula);//
            
            
            getline(lectura,aux1_activo);
            
            
            if (  aux1_activo == "0" )//( strcmp(activo,"0" == 0 )
            {
            	
				if ( aux1_cedula == auxCedula )
				{
				    encontro = 1;
				    
					cout<<"\nCedula               : "<<aux1_cedula<<endl;
					cout<<"\nNombre 1             : "<<aux1_nombre1<<endl;
					cout<<"\nNombre 2             : "<<aux1_nombre2<<endl;
					cout<<"\nApellido 1           : "<<aux1_apellido1<<endl;
					cout<<"\nApellido 2           : "<<aux1_apellido2<<endl;
					cout<<"\nTelefono             : "<<aux1_telefono<<endl;
					cout<<"\nEmail                : "<<aux1_email<<endl;
					cout<<"\nGenero               : "<<aux1_genero<<endl;
					cout<<"\nNacionalidad         : "<<aux1_nacionalidad<<endl;
					cout<<"\nEstado civil         : "<<aux1_estado_civil<<endl;
					cout<<"\nyear de nacimiento   : "<<aux1_fecha_nacimientoA<<endl;
					cout<<"\nMes de nacimiento    : "<<aux1_fecha_nacimientoM<<endl;
					cout<<"\nDia de nacimiento    : "<<aux1_fecha_nacimientoD<<endl;
					cout<<"\nrh                   : "<<aux1_rh<<endl;
					
            		//cout<<"C\242digo : "<<aux1_codigo<<endl;
            		//cout<<"Nombre : "<<aux1_nombre<<endl;
                	
    
            		getline(leer_est,cedula);
        
					while( !leer_est.eof() ) // leer mmientras no sea el final del archivo
        			{
           			 	getline(lectura,empresa);
			            getline(lectura,cargo);
			            getline(lectura,fecha_inicioA);
			            getline(lectura,fecha_inicioM);
			            getline(lectura,fecha_inicioD);
			            getline(lectura,fecha_terminacionA);
			            getline(lectura,fecha_terminacionM);
			            getline(lectura,fecha_terminacionD);

            		
            			if ( aux1_cedula == cedula )
            			{
            				cout <<"\n\n Empresa             : "<<empresa<<endl;
            				cout <<"\n Cargo                 : "<<cargo<<endl;
            				cout <<"\n Year de inicio        : "<<fecha_inicioA<<endl;
            				cout <<"\n Mes de inicio         : "<<fecha_inicioM<<endl;
            				cout <<"\n Dia de inicio         : "<<fecha_inicioD<<endl;
            				cout <<"\n Year de terminacion   : "<<fecha_terminacionA<<endl;
            				cout <<"\n Mes de terminacion    : "<<fecha_terminacionM<<endl;
            				cout <<"\n Dia de terminacion    : "<<fecha_terminacionD<<endl;

            				
            				cout<<"\n\nRealmente deseas dar de baja Registro (s/n)?: ";
                			cin.getline(respuesta,5);
                
                			if(strcmp(respuesta,"s")==0 || strcmp(respuesta,"S")==0 ||
                   				strcmp(respuesta,"si")==0 ||strcmp(respuesta,"SI")==0||
                        		strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
            				{
            					i++;
							}
							else
							{
							     auxiliar<<cedula<<endl<<empresa<<endl<<cargo<<endl<<fecha_inicioA<<endl<<fecha_inicioM<<endl<<fecha_inicioD<<endl<<fecha_terminacionA<<endl<<fecha_terminacionM<<endl<<fecha_terminacionD<<endl<<activo<<endl;
								 // escribimos en el auxiliar 
								 // encontramos los estudios de la persona pero no la borramos	
							}	
						}
						else
						{
							     auxiliar<<cedula<<endl<<empresa<<endl<<cargo<<endl<<fecha_inicioA<<endl<<fecha_inicioM<<endl<<fecha_inicioD<<endl<<fecha_terminacionA<<endl<<fecha_terminacionM<<endl<<fecha_terminacionD<<endl<<activo<<endl;
							// escribimos en el auxiliar 
							// no encontramos los estudios de la persona este le pertenece a otra persona
						}
						getline(leer_est,cedula);
            		}	
        		}
        	}
            getline(lectura,aux1_cedula);
        }
    }
    else
    {
        error();
    }
    lectura.close();
    leer_est.close();
    auxiliar.close();
    if ( encontro = 0 )
    { 
      cout<<"\n el Amigo buscado en la agenda no Existe ";
	}
	else
	{
		remove("Historial_laboral.txt");
    	rename("aux_est.txt","Historial_laboral.txt");		
	}
    pausa();
	
	
}

void Historial_Laboral::listar_HL()
{
	
		int i=0;
    ifstream lectura;
    ifstream leer_est;
    
    string aux1_nombre1;
	string aux1_nombre2;
	string aux1_apellido1;
	string aux1_apellido2;
	string aux1_telefono;
	string aux1_email;
	string aux1_genero;
	string aux1_nacionalidad;
	string aux1_estado_civil;
	string aux1_fecha_nacimientoA;
	string aux1_fecha_nacimientoM;
	string aux1_fecha_nacimientoD;
	string aux1_rh;
	string aux1_cedula;
    
    
    string aux1_activo;
    
    
    lectura.open("Agenda.txt",ios::in);
    leer_est.open("Historial_laboral.txt",ios::in);
    
    
    if( lectura.is_open() && leer_est.is_open())    // validamos que no presente error en la apertura del archivo
    {
		
		cout<<"\t\t\t\t***Listado de todos los clientes***\t\t\t\t\n\n";
        getline(lectura,aux1_cedula);
        
		while( !lectura.eof() ) // leer mmientras no sea el final del archivo
        {
            getline(lectura,aux1_nombre1);
            getline(lectura,aux1_nombre2);
            getline(lectura,aux1_apellido1);
            getline(lectura,aux1_apellido2);
            getline(lectura,aux1_telefono);
            getline(lectura,aux1_email);
            getline(lectura,aux1_genero);
            getline(lectura,aux1_nacionalidad);
            getline(lectura,aux1_estado_civil);
            getline(lectura,aux1_fecha_nacimientoA);
            getline(lectura,aux1_fecha_nacimientoM);
            getline(lectura,aux1_fecha_nacimientoD);
            getline(lectura,aux1_rh);
          //  getline(lectura,aux1_cedula);//
            
            
            getline(lectura,aux1_activo);
            
            
            if (  aux1_activo == "0" )//( strcmp(activo,"0" == 0 )
            {
            		cout<<"\nCedula               : "<<aux1_cedula<<endl;
					cout<<"\nNombre 1             : "<<aux1_nombre1<<endl;
					cout<<"\nNombre 2             : "<<aux1_nombre2<<endl;
					cout<<"\nApellido 1           : "<<aux1_apellido1<<endl;
					cout<<"\nApellido 2           : "<<aux1_apellido2<<endl;
					cout<<"\nTelefono             : "<<aux1_telefono<<endl;
					cout<<"\nEmail                : "<<aux1_email<<endl;
					cout<<"\nGenero               : "<<aux1_genero<<endl;
					cout<<"\nNacionalidad         : "<<aux1_nacionalidad<<endl;
					cout<<"\nEstado civil         : "<<aux1_estado_civil<<endl;
					cout<<"\nyear de nacimiento   : "<<aux1_fecha_nacimientoA<<endl;
					cout<<"\nMes de nacimiento    : "<<aux1_fecha_nacimientoM<<endl;
					cout<<"\nDia de nacimiento    : "<<aux1_fecha_nacimientoD<<endl;
					cout<<"\nrh                   : "<<aux1_rh<<endl;
            	
            	
                i++;
    
            	getline(leer_est,cedula);
        
				while( !leer_est.eof() ) // leer mmientras no sea el final del archivo
        		{
           			getline(lectura,empresa);
            		getline(lectura,cargo);
            		getline(lectura,fecha_inicioA);
            		getline(lectura,fecha_inicioM);
            		getline(lectura,fecha_inicioD);
             		getline(lectura,fecha_terminacionA);
             		getline(lectura,fecha_terminacionM);
             		getline(lectura,fecha_terminacionD);
            		
            		if ( aux1_cedula == cedula )
            		{
            				cout <<"\n\n REGISTRO DE HISTORIAL LABORAL "<<endl;
            				cout<<"\n Empresa              : "<<empresa<<endl;
            				cout <<"\n Cargo               : "<<cargo<<endl;
            				cout <<"\n Year de inicio      : "<<fecha_inicioA<<endl;
            				cout <<"\n Mes de inicio       : "<<fecha_inicioM<<endl;
            				cout <<"\n Dia de inicio       : "<<fecha_inicioD<<endl;
            				cout <<"\n Year de terminacion : "<<fecha_terminacionA<<endl;
            				cout <<"\n Mes de terminacion  : "<<fecha_terminacionM<<endl;
            				cout <<"\n Dia de terminacion  : "<<fecha_terminacionD<<endl;

            				
					}
					getline(leer_est,cedula);
            	
            	}
            	cout<<"\n";
            	leer_est.close();
            	leer_est.open("Historial_laboral.txt",ios::in);
        
        	}
            getline(lectura,aux1_cedula);
        }
    }
    else
    {
        error();
    }
    lectura.close();
    leer_est.close();
    pausa();

	
}

main()
{
    system ("color f0");
    
	int opc;
	opc = 9;
	
	Datos_Basicos DB;
	Tabla_Estudios TE;
	Historial_Laboral HL;
	
	//Agenda inicio;
	//Estudios entrar;
	do
	{
		system(CLEAR);
		cout <<"\n MENU GENERAL "<<endl<<endl;
		cout <<"1. Datos Basicos "<<endl;
		cout <<"2. Datos de Estudios"<<endl;
		cout <<"3. Historial Laboral"<<endl;
		cout <<"0. Salir del Menu"<<endl<<endl;
		cout <<"Digite Opcion :  ";
		cin >> opc;
		fflush(stdin);
		
		switch(opc)
		{
			case 1: 
    			DB.menu_DB();
			    break;
			case 2: 
			    TE.menu_TE();
				break;
			case 3:
				HL.menu_HL();
			
			default : cout <<"Ingreso Opcion no valida "; 
		}
	}
	while ( opc != 0 );	
}

void pausa()
{
    cout<<"Presiona Enter para continuar...";
    getch();
    system(CLEAR);
}

void error()
{
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}



