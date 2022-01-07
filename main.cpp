#include "zona1.hpp"
#include "zona2.hpp"
#include "zona3.hpp"
//am folosit https://codebeautify.org/cpp-formatter-beautifier


int main(int argc, char ** argv) {
  ofstream output;
  ifstream input;
  input.open("input.txt");
  output.open("output.txt");
  if (output.is_open() == false) {
    cout << "EROAE output" << endl;
    return -1;
  }
  if (input.is_open() == false) {
    cout << "EROAE input" << endl;
    return -1;
  }
  string text, text1;
  int tip, nr, ani;
  Baza ** zone;
  float da, nu, punctaj_da, punctaj_nu;
  zone = new Baza * [3];

  for (int i = 0; i < 3; i++) { //citire din fisier

    int populatie = 0;
    input >> tip;
    if (tip == 1) {
      input >> populatie;
      //	cout<<" populatie:"<<populatie<<endl;
      int v[5];
      for (int j = 0; j < 5; j++) {
        input >> v[j];
      }
      zone[i] = new zona1(populatie, v);
      //	zone[i]->afisare();
    } else if (tip == 2) {
      input >> populatie;
      int v[10];
      for (int j = 0; j < 10; j++) {
        input >> v[j];
      }
      zone[i] = new zona2(populatie, v);
      // zone[i]->afisare();
    } else if (tip == 3) {
      input >> populatie;
      int v[4];
      for (int j = 0; j < 4; j++) {
        input >> v[j];
      }
      zone[i] = new zona3(populatie, v);
      //   zone[i]->afisare();
    }
  }

  for (int i = 0; i < 3; i++)
    zone[i] -> afisare();

  for (int i = 0; i < 3; i++) { //partea de raspuns la intrebari si scris in fisier
    input >> nr >> tip;
    if (tip == 3)
      input >> ani;
    output << "Zona " << i + 1 << endl;

    for (int j = 0; j < nr; j++) {
      input.ignore();
      getline(input, text);
      output << text << endl;
      input >> text;
      if (tip == 1) {
        int da[5], nu[5];
        for (int k = 0; k < 5; k++)
          input >> da[k];

        input >> text;
        for (int k = 0; k < 5; k++)
          input >> nu[k];

        punctaj_da = zone[i] -> punctaj_da(da, 0);
        punctaj_nu = zone[i] -> punctaj_nu(nu, 0);

        if (punctaj_da > punctaj_nu)
          output << "Acceptat ";
        else if (punctaj_da < punctaj_nu)
          output << "Respins ";
        else output << "Egalitate ";

        output << fixed << setprecision(1) << punctaj_da << "-" << punctaj_nu << endl;
        float aux = zone[i] -> prezenta_vot(da, nu, 0);
        aux = floor(100 * aux) / 100;
        output << "Prezenta vot:" << fixed << setprecision(2) << aux << "%" << endl;
      } else if (tip == 2) {

        int da[5], nu[5];
        for (int k = 0; k < 5; k++)
          input >> da[k];

        input >> text;

        for (int k = 0; k < 5; k++)
          input >> nu[k];

        punctaj_da = zone[i] -> punctaj_da(da, 0);
        punctaj_nu = zone[i] -> punctaj_nu(nu, 0);
       // cout << endl << "punctaj da si nu:" << punctaj_da << "  " << punctaj_nu << endl;
        if (punctaj_da > punctaj_nu)
          output << "Acceptat ";

        else if (punctaj_da < punctaj_nu)
          output << "Respins ";
        else output << "Egalitate ";

        output << fixed << setprecision(0) << punctaj_da << "-" << punctaj_nu << endl;
        float aux = zone[i] -> prezenta_vot(da, nu, 0);
        aux = floor(100 * aux) / 100;
        output << "Prezenta vot:" << fixed << setprecision(2) << aux << "%" << endl;
      } else if (tip == 3) {

        int da[1], nu[1];

        input >> da[0];
        input >> text;
        input >> nu[0];

        punctaj_da = zone[i] -> punctaj_da(da, 0);
        punctaj_nu = zone[i] -> punctaj_nu(nu, 0);
       // cout << endl << "punctaj da si nu:" << punctaj_da << "  " << punctaj_nu << endl;
        if (da[0] > nu[0])
          output << "Acceptat ";

        else if (da[0] < nu[0])
          output << "Respins ";
        else output << "Egalitate ";

        output << fixed << setprecision(1) << da[0] << "-" << nu[0] << endl;
        float aux = zone[i] -> prezenta_vot(da, nu, ani);
        aux = floor(100 * aux) / 100;
        output << "Prezenta vot:" << fixed << setprecision(2) << aux << "%" << endl;
      }

    }
  }

  /* //zona de testare metode 	
  	cout<< "--------zona 1---------"<<endl<<endl;
  	int	pop=150000;
  	int v[5]={70000 ,30000 ,40000 ,9000 ,999};
  	zona1 z(pop,v);
  	z.afisare();
  	int da[5]={ 20000, 10000, 15000 ,100 ,5};
  	int nu[5]={ 14000 ,9000 ,25000, 8900 ,994};
  	cout<< endl<<"punctaj da:  "<< z.punctaj_nu(nu,0);
  	cout<< endl<<"punctaj nu:  "<< z.punctaj_da(da,0);
  	cout<< endl<<"prezenta vot: " <<z.prezenta_vot(da,nu,0)<<"%";
  	
  	cout<<endl<<endl<< "--------zona 2---------"<<endl<<endl;
  	
  	int pop2=230000;
  	int v2[10]={7, 240, 345, 1234 ,6500 ,12000 ,4000, 56000 ,32000, 117673};
  	zona2 z2(pop2,v2);
  	z2.afisare();
  	int da2[5]={ 2, 100, 300 ,1000, 2000};
  	int nu2[5]={4, 50 ,40 ,200 ,4500};
  	cout<<endl<<" prezenta vot: "<<z2.prezenta_vot(da2,nu2,0)<<endl;
  	cout<<" punctaj da : "<<z2.punctaj_da(da2,0)<<endl;
  	cout<<" punctaj nu:  "<<z2.punctaj_nu(nu2,0)<<endl;
  	
  	cout<<endl<<endl<< "--------zona 3---------"<<endl<<endl;
  		
  	int pop3=195000;
  	int v3[4]={55000, 32000 ,39500 ,68499}; 
  	int ani=20;
  	int da3[1]={40000};
  	int nu3[1]={40000};
  	zona3 z3(pop3,v3);
  	z3.afisare();
  	cout<<endl<<" prezsenta vot:"<<z3.prezenta_vot(da3,nu3,ani)<<"%";
  	
  */
  input.close();
  output.close();

  return 0;
}
