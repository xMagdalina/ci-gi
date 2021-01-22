#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
struct liczby
{
int liczba;
};
struct liczby2
{
int roznica;
};

class ciag{
int stara_roznica;
int dlugosc;
int liczba;
int liczba_poprawnych_ciagow = 0;
vector <struct liczby> r;
vector <struct liczby2> r2;
	public:
		void licz();
};
void ciag::licz(){
	ifstream file;
	ofstream file2;
	file.open("ciag.txt");
	while(file.good()){
 	file >> dlugosc;
	for (int i=0; i<dlugosc; i++)
 	{
  	file >> liczba;
    r.push_back(liczba);
	if (i==1) stara_roznica = r[1]-r[0];
   	if (i>1)
   	{
    int roznica = r[i] - r[i-1];
   	if (roznica != stara_roznica)
   	{
    cout << "zly";
   	}
    	else{
    	liczba_poprawnych_ciagow++;
 		r2.push_back(roznica);
		  }
  	}
 	}
}
	file2<<"Liczba ciagow: "<<liczba_poprawnych_ciagow<<endl;
	file.close();
}
int main(int argc, char** argv) {
	
	ciag do;
	do.licz();
	return 0;
}
