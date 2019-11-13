//Guillermo Molina Matus
//Project 4: Hurricane
//November 12, 2019
/*
This project is suppose to receive information from two text files that contain information
about storms and Hurricanes.
*/


#include <iostream>
#include <fstream>

using namespace std;


struct info
{
	char hurricaneName[11];
	int ID;
	int life;
	int date;
	float avgWindSpeed;
	float avgRainfall;
	int totalTornadoes;
};

int main()
{
	int wind1, wind2, wind3, wind4, wind5, rain1, rain2;
	info hurricane1;
	ifstream tropical;	tropical.get(hurricane1.hurricaneName, 10);

	tropical.open("storms.txt");

	tropical.get(hurricane1.hurricaneName, 10);
	cout << hurricane1.hurricaneName;
	tropical >> hurricane1.ID >> hurricane1.life >> hurricane1.date >> wind1 >> wind2 >> wind3 >> wind4 >> wind5 >> rain1 >> rain2 >> hurricane1.totalTornadoes;
	tropical.ignore(256, '\n');
		hurricane1.avgWindSpeed = (wind1 + wind2 + wind3 + wind4 + wind5) / 5;
		hurricane1.avgRainfall = (rain1 + rain2) / 2;

	cout << hurricane1.ID << " ";
	cout << hurricane1.life << " ";
	cout << hurricane1.date << " ";
	cout << hurricane1.avgWindSpeed << " ";
	cout << hurricane1.avgRainfall << " ";
	cout << hurricane1.totalTornadoes << " ";
	cout << endl << endl;




	return 0;
}
