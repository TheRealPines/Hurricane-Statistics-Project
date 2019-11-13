# Hurricane Statistics Project

This all has to be done in C++.

I will have two files. One will contain IDs of storms that are classified as tropical storms and the other file will contain the information of all the storms. 

tropical.txt - contains the IDs for the tropical storms
storms.txt   - containst the informatino of all the storms

Below will be the exact directions:

<strong>
<p>COSC 120</p>
<p>Hurricane Statistics</p>
<p>Program Assignment #4</p>
</strong>
DESCRIPTION: The weather bureau keeps statistics on hurricanes for the past several years. Develop a program that will read a sequence of records with the following fields:
<ul>
  <li>Hurricane Name (Columns 1-10) Name of the hurricane</li>
  <li>ID (Columns 12-14) Integer id of hurricane</li>
  <li>Life (Columns 16-17) Life of hurricane in days</li>
  <li>Date (Columns 19-22) Year of the hurricane</li>
  <li>5 Wind recordings Real Measurement of wind speed</li>
  <li>2 rain fall readings Real 2 measures of rain fall</li>
  <li>Tornadoes spawned Integer Number of tornadoes created</li>
</ul>

<strong>First page</strong>

<p>The program will print on the first page an echo of the Hurricane name, ID, Life, & Date as well as the average wind speed (determined by program) average rain fall (determined by program), and echo print the number of tornadoes spawned with appropriate headings and spacing, as well as the level of the hurricane or indication of tropical storm (determined by the program) and a summary line that indicates the total number of records (both true hurricanes and tropical storms). The total number of true hurricanes and the total number of tropical storms. True hurricanes and tropical storms are explained later.</p>

<strong>Level Pages</strong>
The next pages will contain a different page for each category of hurricanes (tropical storms are not listed) with:

1) The Level of the hurricane centered at the top.

2) The Name, ID, life, average wind speed, average rain fall, number of tornadoes and date of each storm, in alphabetical order by name.

3) A summary line for the number of Hurricanes for that particular level.

4) A summary line for the average life in days for the particular category, average rain, average number of tornadoes spawned and the average wind speed for that level.

The pages will be in level number order. Ex. Category 1 first.

<strong>Summary Page</strong>
A summary page will consist of statistics from the hurricane records which will include

1) The average wind speed of all the hurricane averages

2) The Highest average wind speed

3) The Lowest average wind speed

4) The standard deviation of the wind speed

5) A listing of the number of hurricanes in each category

<strong>Exception Reports</strong>
Each storm is checked with an input file containing the id number of just tropical storms. Any storm found to be a hurricane by the program that appears in this file should generate an exception. (Should be listed in exception report 1).

Also any tropical storm found not to be on the input file of tropical storm should be listed on a separate exception report 2.

<strong>CLARIFICATION:</strong>

1) You must use the C++ user-defined structure data type and a function to sort the records.

2) You must use a function to check the ID of each hurricane (determined by the program) to see if it exists on the tropical storm input list. If it does than it's name must be printed on the exception report.

3) The first input file (infile1) will contain the list of tropical strom ID's that can be read into an array. You can assume that the records in the tropical strom ID file have been ordered (sorted in ascending order) but the actual ID's and the length of the file are variable.

4) The second input file (infile2) will contain an undetermined amount of records (sample data should contain at least 20) given the format above.

5) The sample data should have at least ten records that are not in the tropical storm list.

6) The program should allow for a maximum of 200 hurricanes, a maximum of 150 hurricanes in any one category.

7) All output is sent to output files and not the screen.

Finding the wind speeds: A hurricane wind speed is found by taking the average of the 5 input wind speeds.

The average wind speed of all hurricanes will be found by averaging the individual average wind speeds and then rounding to the nearest integer. Level categories are assigned by using the rounded average wind speeds as follows:

Level Type Wind Speed Destruction

0 Tropical Storm not a hurricane Below 75

1 Weak 75-95 Minimal

2 Moderate 96-110 Moderate

3 Strong 111-130 Extensive

4 Very Strong 131-155 Extreme

5 Devastating > 155 Catastrophic

The standard deviation (sd) is a measure of "dispersion" in a collection of numbers. It is the square root of the variance. The variance is the average of the squared differences between each number and the mean of the collection of numbers. To find the standard deviation do the following:

1. Find the average (mean). avg

2. For each hurricanes average speed, find the difference between that speed and overall avg.

3. Square all of the differences found in step 2.

4. Find the average of the squares found in step 3. (This is the variance)

5. Take the square root of the variance and that is the standard deviation.

After finding the average (step 1 above), step 2 & 3 can be found as shown in the chart below:

Wind Speed Avg Speed-Avg (Speed-Avg)2

125 105 20 400

75 105 -30 900

140 105 35 1225

86 105 -19 361

90 105 -15 225

145 105 40 1600

105 105 0 0

74 105 -31 961

step 4: (400+900+1225+361+225+1600+0+961)/8 = 5672/8= 709

step 5: standard deviation is square root of 709 or 26.627

Sample INPUT: Infile1: A list of tropical storm id numbers

121
122
128
131
135
136
138
151
152
153
160
162
 
 

Sample Input: Infile2: A list of storm names, id, life, date, 5 wind speeds, 2 rain fall readings and tornadoes spawned.

<p>Linda             162 8 1983 120 140 110 123 112 6 8 9</p>
<p>Carla             194 6 1984 70 60 55 62 70 1 2 1</p>
<p>Kathleen        173 4 1998 70 75 81 82 64 3 4 0</p>
<p>Big Bertha     202 9 1990 160 162 155 160 166 9 10 10</p>
<p>Mean Dean   136 7 1964 120 125 130 140 150 4 4 2</p>
<p>Homer          402 5 1984 76 90 85 82 82 5 6 4</p>
<p>Stever          328 7 1986 150 160 161 157 158 8 5 4</p>
<p>Mike            153 4 1991 100 101 95 99 98 7 4 4</p>
<p>Dave            433 4 1997 78 90 94 76 70 6 2 4</p>
<p>Tom             567 5 1996 120 122 119 118 111 7 5 0</p>
<p>Mary Lou     683 8 1902 135 140 150 140 135 7 8 4</p>
<p>Lee              192 7 1911 104 106 109 99 97 5 2 0</p>
<p>Mary Beth    417 5 1952 130 135 150 129 134 5 4 2</p>
<p>Caroline        122 2 1997 76 75 74 77 74 2 1 0</p>
<p>Barbara        420 5 1992 78 79 80 90 80 4 1 0</p>
<p>Bad Bob       501 5 1900 120 122 121 130 125 4 2 2</p>
<p>Chris            555 7 1961 100 99 98 97 95 3 1 1</p>
<p>Phil               641 5 1970 120 125 122 121 111 4 1 2</p>
<p>Mary            701 4 1972 78 79 80 81 75 3 2 0</p>
<p>Mohammad  800 7 1976 97 98 100 110 109 5 2 2</P>

SAMPLE OUTPUT OUTFILE1 (First Page)
 

                            STORM SUMMARY SHEET

<p>Name         ID     Life        Date     Average      Average         Tornadoes         Storm</p>
<p>                   in days             wind speed     rain fall        spawned          level</p>

<p>Linda         162     8         1983      121           7                 9                3</p>
<p>Carla         194     6         1984       63           1.5               1                0</p>
<p>Kathleen      173     4         1998       74           3.5               0                0</p>
<p>Big Bertha    202     9         1990      161           9.5               10               5</p>
<p>Mean Dean     136     7         1964      133           4                 2                4</p>
<p>Homer         402     5         1984       83           5.5               4                1</p>
<p>Stever        328     7         1986      157           6.5               4                5</p>
<p>Mike          153     4         1991       99           5.5               4                2</p>
<p>Dave          433     4         1997       82           4                 4                1</p>
<p>Tom           567     5         1996      118           6                 0                3</p>
<p>Mary Lou      683     8         1902      140           7.5               4                4</p>
<p>Lee           192     7         1911      103           3.5               0                2</p>
<p>Mary Beth     417     5         1952      136           4.5               2                4</p>
<p>Caroline      122     2         1997       75           1.5               0                1</p>
<p>Barbara       420     5         1992       81           2.5               0                1</p>
<p>Bad Bob       501     5         1900      124           3                 2                3</p>
<p>Chris         555     7         1961       98           2                 1                2</p>
<p>Phil          641     5         1970      120           2.5               2                3</p>
<p>Mary          701     4         1972       79           2.5               0                1</p>
<p>Mohammad      800     7         1976      103           3.5               2                2</p>

Total number of records =20
Total number of hurricanes=18
Total number of tropical storms=2

NOTE: The following will be on a separate sheet of paper for each hurricane level (Use \f)
 
 





Hurricane Level 1

<p>Name            Id         Life         Average         Average         Tornadoes         Date</p>
<p>                          in days     wind speed       rain fall           spawned</p>

<p>Barbara          420        5             81                 2.5           0                 1992</p>
<p>Caroline         122        2             75                 1.5           0                 1997</p>
<p>Dave             433        4             82                 4             4                 1997</p>
<p>Homer            402        5             83                 5.5           4                 1984</p>
<p>Mary             701        4             79                 2.5           0                 1972</p>

Total number of Level 1 hurricanes is 5.
Average Life span in days of Level 1 hurricanes is 4.
Average rain fall for Level 1 hurricanes is 3.2.
Average tornadoes spawned for Level 1 hurricanes is 1.6.
Average wind speed for Level 1 hurricanes is 80.
 
 

Hurricane Level 2


 
<p>Name           Id         Life      Average         Average         Tornadoes           Date</p>
<p>                                    in days     wind speed          rain fall         spawned</p>

<p>Chris          555          7       98            2                    1                 1961</p>
<p>Lee            192          7       103           3.5                  0                 1911</p>
<p>Mike           153          4        99           5.5                  4                 1991</p>
<p>Mohammad       800          7       103           3.5                  2                 1976</p>
 
 

Total number of Level 2 hurricanes is 4.
Average Life span in days of Level 2 hurricanes is 6.25.
Average rain fall for Level 2 hurricanes is 3.63.
Average tornadoes spawned for Level 2 hurricanes is 1.75.
Average wind speed for Level 2 hurricanes is 100.75.
 
 

Hurricane Level 3


 
<p>Name                 Id     Life         Average         Average            Tornadoes             Date</p>
<p>                            in days     wind speed       rain fall           spawned</p>

<p>Bad Bob             501     5                 124                 3              2                 1900</p>
<p>Linda               162     8                 121                 7              9                 1983</p>
<p>Phil                641     5                 120                 2.5            2                 1970</p>
<p>Tom                 567     5                 118                 6              0                 1996</p>
 
 

Total number of Level 3 hurricanes is 4.
Average Life span in days of Level 3 hurricanes is 5.75.
Average rain fall for Level 3 hurricanes is 4.63.
Average tornadoes spawned for Level 3 hurricanes is 3.25.
Average wind speed for Level 3 hurricanes is 120.75.
 

Hurricane Level 4


 
 
<p>Name         Id         Life         Average            Average                Tornadoes         Date</p>
<p>                                    in days            wind speed              rain fall           spawned</p>
 

<p>Mary Beth    417         5             136                 4.5                     2                 1952</p>
<p>Mary Lou     683         8             140                 7.5                     4                 1902</p>
<p>Mean Dean    136         7             133                 4                       2                 1964</p>
 
 

Total number of Level 4 hurricanes is 3.
Average Life span in days of Level 4 hurricanes is 6.67.
Average rain fall for Level 4 hurricanes is 4.
Average tornadoes spawned for Level 4 hurricanes is 2.67.
Average wind speed for Level 4 hurricanes is 136.33.
 

Hurricane Level 5


 
 
<p>Name              Id         Life         Average         Average         Tornadoes         Date</p>
<p>                            in days     wind speed       rain fall           spawned</p>
 

<p>Big Bertha       202         9             161                 9.5                 10                 1990</p>
<p>Stever           328         7             157                 6.5                    4                 1986</p>
 
 

Total number of Level 5 hurricanes is 2.
Average Life span in days of Level 5 hurricanes is 8.
Average rain fall for Level 5 hurricanes is 8.
Average tornadoes spawned for Level 5 hurricanes is 7.
Average wind speed for Level 5 hurricanes is 159.
 
 
 
 
 
 
 
 

EXCEPTION REPORT 1

The Following Hurricanes were listed in the Tropical Storm data list.

 NAME             ID

Caroline          122
Linda             162
Mean Dean         136
Mike              153
 
 
 
 
 

EXCEPTION REPORT 2

The Following Tropical Storms were not listed in the Tropical Storm data list.

Name         ID

Carla        194
Kathleen     173
 
 
 
Summary Statistics
 

Wind average of all hurricanes     111.83
Highest wind average                  161
Lowest wind average                     75
Standard deviation                      26.08

Number of Hurricanes in each level

Level 1                 5
Level 2                 4
Level 3                 4
Level 4                 3
Level 5                 2
