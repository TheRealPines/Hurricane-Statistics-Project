#include <iostream>
#include <iomanip> //Allows me to manipulate inputs and outputs
#include <fstream> //Allows me to use files

using namespace std;

//This is the beginning of the structure that will hold the information for the storms.txt file
struct Data
{
    char name[11];
    int ID;
    int life;
    int date;
    float avgWindSpeed;
    float avgRainFall;
    int tornadoes;
    int stormCategory;
};
// This is the end of the Data structure

//This is the beginning for the structure that will hold the information for the tropical.txt file
struct Tropicals
{
    int ID;
};
//This is the end of the Tropicals structure

//These are all function prototypes
void printAllOnFile(ofstream&, Data*, int counter);

//End of all function prototypes

int main()
{
    //I will start to sort everything from the storms.txt to its proper location in the Data structure
    ifstream storms;
    storms.open("storms.txt");
    //This is creating a Results.txt file
    ofstream output;
    output.open("Results.txt");
    output << fixed << setprecision(2);

    //This will count how many lines have information in them or are being used.
    int counter = 0;
    while (storms)
    {
        counter = counter + 1;
        storms.ignore(256,'\n');
    }
    //This is the end of counting block
    counter = counter - 1;

    Data hurricanes[counter];

    //Both pieces of code below will allow me to go back to the beginning of the storms.txt file
    storms.clear();
    storms.seekg(0, ios::beg);


    //Starts the while loop to read in all the storms.txt information
    while (storms)
        {
            storms.get(hurricanes[0].name, 11);
            for(int a = 0; a < counter; a++)
            {
                storms >> hurricanes[a].ID;
                storms >> hurricanes[a].life;
                storms >> hurricanes[a].date;
                float wind = 0.0;
                float sum = 0;
                //This is getting the sum of all wind speed to further get the average
                for (int b = 0; b < 5;b++)
                {
                    storms >> wind;
                    sum = wind + sum;
                }
                hurricanes[a].avgWindSpeed = sum / 5;
                float rain = 0, total = 0;
                //This is getting the sum of both rain reading to further get the average
                for (int c=0; c < 2; c++)
                {
                    storms >> rain;
                    total = rain + total;
                }
                hurricanes[a].avgRainFall = total / 2;
                storms >> hurricanes[a].tornadoes;

                //Making sure that I skip to the next line
                storms.ignore(256, '\n');
                storms.get(hurricanes[a+1].name, 11); //reading in the next number

                //This part will determine the storm category depending on the average wind speed
                if(hurricanes[a].avgWindSpeed < 75)
                    hurricanes[a].stormCategory = 0;
                else if(hurricanes[a].avgWindSpeed >= 75 && hurricanes[a].avgWindSpeed <= 95)
                    hurricanes[a].stormCategory = 1;
                else if(hurricanes[a].avgWindSpeed >= 96 && hurricanes[a].avgWindSpeed <= 110)
                    hurricanes[a].stormCategory = 2;
                else if(hurricanes[a].avgWindSpeed >= 111 && hurricanes[a].avgWindSpeed <= 130)
                    hurricanes[a].stormCategory = 3;
                else if(hurricanes[a].avgWindSpeed >= 131 && hurricanes[a].avgWindSpeed <= 155)
                    hurricanes[a].stormCategory = 4;
                else if(hurricanes[a].avgWindSpeed > 155)
                    hurricanes[a].stormCategory = 5;
            }

        }
    //This will print everything to the Results.txt file
    storms.clear();
    storms.seekg(0, ios::beg);
    printAllOnFile(output, hurricanes, counter);
    return 0;
}

void printAllOnFile(ofstream &outfile, Data *hurricanes, int counter)
{
cout << endl << endl << "This program was created by Guillermo Molina Matus" << endl << endl << endl;
cout << endl << endl << "The program's results can be located in 'Results.txt'" << endl << endl << endl;



//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Top of STORM SUMMARY SHEET
    outfile << setw(70) << "STORM SUMMARY SHEET" << endl;
    outfile << endl;
    outfile << "Name" << setw(10) << "ID" << setw(20) << " Life  " << setw(10) << "Date" << setw(20) << " Average  " << setw(20) << " Average " << setw(20) << "Tornadoes" << setw(19) << "  Storm  " << endl;
    outfile << "    " << setw(10) << "  " << setw(20) << "in days" << setw(10) << "    " << setw(20) << "wind speed" << setw(20) << "rain fall" << setw(20) << " spawned " << setw(20) << " level   " << endl;

    int hurrNum = 0, troNum = 0; //Will hold the number of hurricanes and tropical storms

    //Start adding the data to the STORM SUMMARY SHEET
    outfile << endl;
    for(int i = 0; i < counter; i++)
    {
        outfile << hurricanes[i].name << setw(5) << hurricanes[i].ID << setw(16) << hurricanes[i].life << setw(13) << hurricanes[i].date << setw(18) << hurricanes[i].avgWindSpeed << setw(19) << hurricanes[i].avgRainFall << setw(19) << hurricanes[i].tornadoes << setw(19) << hurricanes[i].stormCategory << endl;
        //Start to count the number of hurricanes vs the number of tropical storms
        if(hurricanes[i].stormCategory == 0)
            troNum++;
        else if(hurricanes[i].stormCategory > 0)
            hurrNum++;
    }
    //This will Start the printing of the extra information for STORM SUMMARY SHEET
    outfile << endl << endl << "Total number of records = " << counter << endl;
    outfile << "Total number of hurricanes = " << hurrNum << endl;
    outfile << "Total number of tropical storms = " << troNum << endl;
    outfile << endl << endl;
//End of the STORM SUMMARY SHEET
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Start of Hurricane Level 1
    int totalLevel1 = 0;    //Will hold the number of storms that are level 1


    //This is just setting the top part of the chart
    outfile << setw(70) << "Hurricane Level 1" << endl << endl;
    outfile << "Name" << setw(10) << "ID" << setw(20) << " Life  " << setw(20) << " Average  " << setw(20) << " Average " << setw(20) << "Tornadoes" << setw(19) << "  Date  " << endl;
    outfile << "    " << setw(10) << "  " << setw(20) << "in days" << setw(20) << "wind speed" << setw(20) << "rain fall" << setw(20) << " spawned " << setw(20) << "    " << endl;
    outfile << endl << endl;
    float avgLifeSpan, avgRainFall, avgTornadoes, avgWindSpeed, life = 0, rain= 0, tornado= 0, wind= 0;
    //Starting to process the information and printing it in its proper location
    for(int i = 0; i < counter; i++)
        if(hurricanes[i].stormCategory == 1)
            {
                totalLevel1++;
                life = life + hurricanes[i].life;
                rain = rain + hurricanes[i].avgRainFall;
                tornado = tornado + hurricanes[i].tornadoes;
                wind = wind + hurricanes[i].avgWindSpeed;
                outfile << hurricanes[i].name << setw(5) << hurricanes[i].ID << setw(15) << hurricanes[i].life << setw(21) << hurricanes[i].avgWindSpeed << setw(20) << hurricanes[i].avgRainFall << setw(19) << hurricanes[i].tornadoes << setw(21) << hurricanes[i].date << endl;
            }
    //Printing the extra information for HURRICANE LEVEL 1
    outfile << endl << endl << "Total number of Level 1 hurricanes is " << totalLevel1 << "." << endl;
    outfile << "Average Life span in days of Level 1 hurricanes is " << life / float(totalLevel1) << "." << endl;
    outfile << "Average rain fall for Level 1 hurricanes is " << rain / float(totalLevel1) << "." << endl;
    outfile << "Average tornadoes spawned for Level 1 hurricanes is " << tornado / float(totalLevel1) << "." << endl;
    outfile << "Average wind speed for Level 1 hurricanes is " << wind / float(totalLevel1) << "." << endl;
    outfile << endl << endl;

//End of the Hurricane Level 1
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Start of Hurricane Level 2
    int totalLevel2 = 0;    //Will hold the number of storms that are level 2


    //This is just setting the top part of the chart
    outfile << setw(70) << "Hurricane Level 2" << endl << endl;
    outfile << "Name" << setw(10) << "ID" << setw(20) << " Life  " << setw(20) << " Average  " << setw(20) << " Average " << setw(20) << "Tornadoes" << setw(19) << "  Date  " << endl;
    outfile << "    " << setw(10) << "  " << setw(20) << "in days" << setw(20) << "wind speed" << setw(20) << "rain fall" << setw(20) << " spawned " << setw(20) << "    " << endl;
    outfile << endl << endl;
    avgLifeSpan = 0, avgRainFall = 0, avgTornadoes = 0, avgWindSpeed = 0, life = 0, rain = 0, tornado = 0, wind = 0;
    //Starting to process the information and printing it in its proper location
    for(int i = 0; i < counter; i++)
        if(hurricanes[i].stormCategory == 2)
            {
                totalLevel2++;
                life = life + hurricanes[i].life;
                rain = rain + hurricanes[i].avgRainFall;
                tornado = tornado + hurricanes[i].tornadoes;
                wind = wind + hurricanes[i].avgWindSpeed;
                outfile << hurricanes[i].name << setw(5) << hurricanes[i].ID << setw(15) << hurricanes[i].life << setw(21) << hurricanes[i].avgWindSpeed << setw(20) << hurricanes[i].avgRainFall << setw(19) << hurricanes[i].tornadoes << setw(21) << hurricanes[i].date << endl;
            }
    //Printing the extra information for HURRICANE LEVEL 2
    outfile << endl << endl << "Total number of Level 2 hurricanes is " << totalLevel2 << "." << endl;
    outfile << "Average Life span in days of Level 2 hurricanes is " << life / float(totalLevel2) << "." << endl;
    outfile << "Average rain fall for Level 2 hurricanes is " << rain / float(totalLevel2) << "." << endl;
    outfile << "Average tornadoes spawned for Level 2 hurricanes is " << tornado / float(totalLevel2) << "." << endl;
    outfile << "Average wind speed for Level 2 hurricanes is " << wind / float(totalLevel2) << "." << endl;
    outfile << endl << endl;
//End of the Hurricane Level 2
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Start of Hurricane Level 3
    int totalLevel3 = 0;    //Will hold the number of storms that are level 3


    //This is just setting the top part of the chart
    outfile << setw(70) << "Hurricane Level 3" << endl << endl;
    outfile << "Name" << setw(10) << "ID" << setw(20) << " Life  " << setw(20) << " Average  " << setw(20) << " Average " << setw(20) << "Tornadoes" << setw(19) << "  Date  " << endl;
    outfile << "    " << setw(10) << "  " << setw(20) << "in days" << setw(20) << "wind speed" << setw(20) << "rain fall" << setw(20) << " spawned " << setw(20) << "    " << endl;
    outfile << endl << endl;
    avgLifeSpan = 0, avgRainFall = 0, avgTornadoes = 0, avgWindSpeed = 0, life = 0, rain = 0, tornado = 0, wind = 0;
    //Starting to process the information and printing it in its proper location
    for(int i = 0; i < counter; i++)
        if(hurricanes[i].stormCategory == 3)
            {
                totalLevel3++;
                life = life + hurricanes[i].life;
                rain = rain + hurricanes[i].avgRainFall;
                tornado = tornado + hurricanes[i].tornadoes;
                wind = wind + hurricanes[i].avgWindSpeed;
                outfile << hurricanes[i].name << setw(5) << hurricanes[i].ID << setw(15) << hurricanes[i].life << setw(21) << hurricanes[i].avgWindSpeed << setw(20) << hurricanes[i].avgRainFall << setw(19) << hurricanes[i].tornadoes << setw(21) << hurricanes[i].date << endl;
            }
    //Printing the extra information for HURRICANE LEVEL 3
    outfile << endl << endl << "Total number of Level 3 hurricanes is " << totalLevel3 << "." << endl;
    outfile << "Average Life span in days of Level 3 hurricanes is " << life / float(totalLevel3) << "." << endl;
    outfile << "Average rain fall for Level 3 hurricanes is " << rain / float(totalLevel3) << "." << endl;
    outfile << "Average tornadoes spawned for Level 3 hurricanes is " << tornado / float(totalLevel3) << "." << endl;
    outfile << "Average wind speed for Level 3 hurricanes is " << wind / float(totalLevel3) << "." << endl;
    outfile << endl << endl;
//End of the Hurricane Level 3
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Start of Hurricane Level 4
    int totalLevel4 = 0;    //Will hold the number of storms that are level 4


    //This is just setting the top part of the chart
    outfile << setw(70) << "Hurricane Level 4" << endl << endl;
    outfile << "Name" << setw(10) << "ID" << setw(20) << " Life  " << setw(20) << " Average  " << setw(20) << " Average " << setw(20) << "Tornadoes" << setw(19) << "  Date  " << endl;
    outfile << "    " << setw(10) << "  " << setw(20) << "in days" << setw(20) << "wind speed" << setw(20) << "rain fall" << setw(20) << " spawned " << setw(20) << "    " << endl;
    outfile << endl << endl;
    avgLifeSpan = 0, avgRainFall = 0, avgTornadoes = 0, avgWindSpeed = 0, life = 0, rain = 0, tornado = 0, wind = 0;
    //Starting to process the information and printing it in its proper location
    for(int i = 0; i < counter; i++)
        if(hurricanes[i].stormCategory == 4)
            {
                totalLevel4++;
                life = life + hurricanes[i].life;
                rain = rain + hurricanes[i].avgRainFall;
                tornado = tornado + hurricanes[i].tornadoes;
                wind = wind + hurricanes[i].avgWindSpeed;
                outfile << hurricanes[i].name << setw(5) << hurricanes[i].ID << setw(15) << hurricanes[i].life << setw(21) << hurricanes[i].avgWindSpeed << setw(20) << hurricanes[i].avgRainFall << setw(19) << hurricanes[i].tornadoes << setw(21) << hurricanes[i].date << endl;
            }
    //Printing the extra information for HURRICANE LEVEL 4
    outfile << endl << endl << "Total number of Level 4 hurricanes is " << totalLevel4 << "." << endl;
    outfile << "Average Life span in days of Level 4 hurricanes is " << life / float(totalLevel4) << "." << endl;
    outfile << "Average rain fall for Level 4 hurricanes is " << rain / float(totalLevel4) << "." << endl;
    outfile << "Average tornadoes spawned for Level 4 hurricanes is " << tornado / float(totalLevel4) << "." << endl;
    outfile << "Average wind speed for Level 4 hurricanes is " << wind / float(totalLevel4) << "." << endl;
    outfile << endl << endl;
//End of the Hurricane Level 4
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Start of Hurricane Level 5
    int totalLevel5 = 0;    //Will hold the number of storms that are level 5


    //This is just setting the top part of the chart
    outfile << setw(70) << "Hurricane Level 5" << endl << endl;
    outfile << "Name" << setw(10) << "ID" << setw(20) << " Life  " << setw(20) << " Average  " << setw(20) << " Average " << setw(20) << "Tornadoes" << setw(19) << "  Date  " << endl;
    outfile << "    " << setw(10) << "  " << setw(20) << "in days" << setw(20) << "wind speed" << setw(20) << "rain fall" << setw(20) << " spawned " << setw(20) << "    " << endl;
    outfile << endl << endl;
    avgLifeSpan = 0, avgRainFall = 0, avgTornadoes = 0, avgWindSpeed = 0, life = 0, rain = 0, tornado = 0, wind = 0;
    //Starting to process the information and printing it in its proper location
    for(int i = 0; i < counter; i++)
        if(hurricanes[i].stormCategory == 5)
            {
                totalLevel5++;
                life = life + hurricanes[i].life;
                rain = rain + hurricanes[i].avgRainFall;
                tornado = tornado + hurricanes[i].tornadoes;
                wind = wind + hurricanes[i].avgWindSpeed;
                outfile << hurricanes[i].name << setw(5) << hurricanes[i].ID << setw(15) << hurricanes[i].life << setw(21) << hurricanes[i].avgWindSpeed << setw(20) << hurricanes[i].avgRainFall << setw(19) << hurricanes[i].tornadoes << setw(21) << hurricanes[i].date << endl;
            }
    //Printing the extra information for HURRICANE LEVEL 5
    outfile << endl << endl << "Total number of Level 5 hurricanes is " << totalLevel5 << "." << endl;
    outfile << "Average Life span in days of Level 5 hurricanes is " << life / float(totalLevel5) << "." << endl;
    outfile << "Average rain fall for Level 5 hurricanes is " << rain / float(totalLevel5) << "." << endl;
    outfile << "Average tornadoes spawned for Level 5 hurricanes is " << tornado / float(totalLevel5) << "." << endl;
    outfile << "Average wind speed for Level 5 hurricanes is " << wind / float(totalLevel5) << "." << endl;
    outfile << endl << endl;
//End of the Hurricane Level 5
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Start of Exceptions 1
    outfile << setw(70) << "EXCEPTION REPORT 1" << endl << endl;
    outfile << setw(90) << "The Following Hurricanes were listed in the Tropical Storm data list." << endl << endl;

    outfile << "NAME" << setw(20) << "ID" << endl;
    outfile << endl << endl;

    ifstream tropical;
    tropical.open("tropical.txt");

     //This will count how many lines have information in them or are being used.
    int count = 0;
    while (tropical)
    {
        count = count + 1;
        tropical.ignore(256,'\n');
    }
    //This is the end of that program
    count = count - 1;
    Tropicals name[count];

    //Both pieces of code below will allow me to go back to the beginning of the tropical.txt file
    tropical.clear();
    tropical.seekg(0, ios::beg);
    tropical >> name[0].ID;
    while(tropical)
    {
        for(int a = 0; a < count ; a++)
        {

            for (int b = 0; b < counter - 1; b++)
            {
                if(name[a].ID == hurricanes[b].ID)
                {
                    outfile << hurricanes[b].name << setw(15) << hurricanes[b].ID << endl;
                }
            }
            tropical >> name[a+1].ID;
        }

    }
    outfile << endl << endl;
//End of Exceptions 1
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Start of Exceptions 2
    outfile << setw(70) << "EXCEPTION REPORT 2" << endl << endl;
    outfile << setw(90) << "The Following Tropical Storms were not listed in the Tropical Storm data list." << endl << endl;

    outfile << "NAME" << setw(20) << "ID" << endl;
    outfile << endl << endl;

    //Both pieces of code below will allow me to go back to the beginning of the tropical.txt file
    tropical.clear();
    tropical.seekg(0, ios::beg);

        for(int i = 0; i < counter; i++)
        {
            if(hurricanes[i].stormCategory == 0)
            {
                for(int j = 0 ; j < count ; j++){
                    if(hurricanes[i].ID != name[j].ID)
                    {
                        outfile << hurricanes[i].name << setw(15) << hurricanes[i].ID << endl;
                        break;
                    }
                }
            }
        }

    outfile << endl << endl;
//End of Exceptions 2
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

}


