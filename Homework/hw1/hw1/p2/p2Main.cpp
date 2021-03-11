/****************************************************************************
  FileName     [ p2Main.cpp ]
  PackageName  [ p2 ]
  Synopsis     [ Define main() function ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2016-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include <iostream>
#include <string>
#include <cstring>
#include "p2Json.h"

using namespace std;

int main()
{
   Json json;

   // Read in the csv file. Do NOT change this part of code.
   string jsonFile;
   cout << "Please enter the file name: ";
   cin >> jsonFile;
   if (json.read(jsonFile))
      cout << "File \"" << jsonFile << "\" was read in successfully." << endl;
   else {
      cerr << "Failed to read in file \"" << jsonFile << "\"!" << endl;
      exit(-1); // jsonFile does not exist.
   }
   
   // TODO read and execute commands
   string command; 
   char* command_ptr;
   const char* delim = " ";
   cout << "Enter command: ";
   getchar();
   getline(cin, command);
   while (true) {
      command_ptr = strtok(&command[0], delim);
      string str(command_ptr);
      if (str == "PRINT")
      {
         json.print_content();
      }
      else if (str == "SUM")
      {
         json.print_sum();
      }
      else if (str == "AVE")
      {
         json.print_average();
      }
      else if (str == "MAX")
      {
         json.print_max();
      }
      else if (str == "MIN")
      {
         json.print_min();
      }
      else if (str == "ADD")
      {
         char *content[2];
         int i = 0;
         while(command_ptr != NULL)
         {
            command_ptr = strtok(NULL, delim);
            content[i] = command_ptr;
            i++;
            if(i==2){break;}
         }
         string key(content[0]);
         int value = atoi(content[1]);
         JsonElem element(key, value);
         json.add_element(element);
      }
      else if (str == "EXIT")
      {
         break;
      }
      cout << "Enter command: ";
      getline(cin, command);
   }
}
