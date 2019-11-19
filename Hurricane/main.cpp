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
	int ID[20];
	int life[20];
	int date[20];
	float avgWindSpeed[20];
	float avgRainfall[20];
	int totalTornadoes[20];
};

int main()
{
	info hurricane1;
	ifstream infile;
	infile.open("storms.txt");
	infile.get(hurricane1.hurricaneName, 10);

	while(!infile.eof())
    {

            float tWind = 0, tRain = 0;
                for(int i=0; i<20;i++)
                {
                    cout << i << endl;
                    infile >> hurricane1.ID[i];
                    infile >> hurricane1.life[i];
                    infile >> hurricane1.date[i];
                        for(int j = 0;j<5;j++)
                        {

                            cout << j << endl;
                            infile >> tWind;
                            tWind += tWind;
                            cout << tWind<< endl;
                        }
                        for(int k = 0; k<2;k++)
                        {
                            cout << k << endl;
                            infile >> tRain;
                            tRain += tRain;
                        }
                    infile >> hurricane1.totalTornadoes[i];

                }
            infile.ignore(256,'\n');
            infile.get(hurricane1.hurricaneName, 10);

    }


	return 0;
}
