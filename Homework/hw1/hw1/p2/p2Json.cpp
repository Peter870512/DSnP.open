/****************************************************************************
  FileName     [ p2Json.cpp ]
  PackageName  [ p2 ]
  Synopsis     [ Define member functions of class Json and JsonElem ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2018-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "p2Json.h"

using namespace std;

// Implement member functions of class Row and Table here
bool
Json::read(const string& jsonFile)
{  // TODO
   fstream file;
   string buffer;
   file.open(jsonFile);
   if (file.is_open())
   {
      bool find_key = false;
      bool find_value = false;
      string key_string;
      int value;
      while(file >> buffer)
      {
         if (buffer.find("\"") != string::npos)
         {
            find_key = true;
         }
         else if (buffer.find(":") != string::npos)
         {
            find_value = true;
            continue;
         }

         if ((find_key == true) && (find_value == false))
         {
            buffer.pop_back();
            buffer.erase(0, 1);
            key_string = buffer;
         }
         else if ((find_key == true) && (find_value == true))
         {
            value = atoi(buffer.c_str());
            JsonElem element(key_string, value);
            _obj.push_back(element);
            find_value = false;
            find_key = false;
         }
      }
      return true;
   }
   else
   {
      return false;
   }
}

ostream&
operator << (ostream& os, const JsonElem& j)
{
   return (os << "\"" << j._key << "\" : " << j._value);
}

int 
JsonElem::get_value()
{
   return _value;
}

void
Json::print_content()
{
   if (_obj.size() == 0)
   {
      cout << "{" << endl;
      cout << endl;
      cout << "}" << endl;
   }
   else
   {
      cout << "{" << endl;
      for(unsigned int i=0; i<_obj.size(); i++ )
      {
         if (i+1 ==_obj.size())
         {
            cout << "  " << _obj[i] << "\n}" <<endl;
         }
         else
         {
            cout << "  " << _obj[i] << "," << endl;
         }
      }
   }
}

void
Json::print_sum()
{
   if (_obj.size() == 0)
   {
      cout << "Error: No element found!!" << endl;
   }
   else
   {
      int sum = 0;
      for(unsigned int i=0; i<_obj.size(); i++ )
      {
         sum += _obj[i].get_value();
      }
      cout << "The summation of the values is: " << sum << "." << endl;
   }
}

void
Json::print_average()
{
   if (_obj.size() == 0)
   {
      cout << "Error: No element found!!" << endl;
   }
   else
   {
      double sum = 0;
      for(unsigned int i=0; i<_obj.size(); i++ )
      {
         sum += _obj[i].get_value();
      }
      double average = sum / _obj.size();
      cout << "The average of the values is: " << fixed << setprecision(1) << average << "." << endl;
   }
}

void
Json::print_max()
{
   if (_obj.size() == 0)
   {
      cout << "Error: No element found!!" << endl;
   }
   else
   {
      JsonElem max_element = _obj[0];
      for(unsigned int i=0; i<_obj.size(); i++ )
      {
         if (_obj[i].get_value() > max_element.get_value())
         {
            max_element = _obj[i];
         }
      }
      cout << "The maximum element is: {" ;
      cout << max_element << " }."<<endl;
   }
}

void
Json::print_min()
{
   if (_obj.size() == 0)
   {
      cout << "Error: No element found!!" << endl;
   }
   else
   {
      JsonElem min_element = _obj[0];
      for(unsigned int i=0; i<_obj.size(); i++ )
      {
         if (_obj[i].get_value() < min_element.get_value())
         {
            min_element = _obj[i];
         }
      }
      cout << "The minimum element is: {" ;
      cout << min_element << " }."<<endl;
   }
}

void
Json::add_element(JsonElem element)
{
   _obj.push_back(element);
}
