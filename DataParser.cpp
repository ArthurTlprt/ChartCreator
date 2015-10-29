/* 
 * File:   DataParser.cpp
 * Author: isen
 * 
 * Created on 26 octobre 2015, 16:31
 */

#include "DataParser.h"

bool DataParser::stringToInt(string str, int &x){
    istringstream ss(str);

    while (!ss.eof())
    {
       if (ss >> x)
           return true;

       ss.clear();
       ss.ignore();
    }
    return false; // There is no integer!
}

bool DataParser::stringToFloat(string str, float& f){
    istringstream ss(str);

    while (!ss.eof())
    {
       if (ss >> f)
           return true;

       ss.clear();
       ss.ignore();
    }
    return false; // There is no float!
}
DataParser::DataParser(string fileName) {
    
    
    
    fstream f(fileName.c_str(), ios::in);  
    // as the standard streams doesn't accept a standard string we need to convert it
 
    if(f)
    {
        string ligne;
        while(getline(f, ligne))  
        {
            Data1* data = new Data1(0.0, Color(0, 0, 0));
            // get name
            int i = 0, j = 0, k = 0;
            string name;
            Color color;
            while(ligne[i] != 34){
                name += ligne[i];
                i++;
            }
            data->SetName(name);
            
            //get prct
            j = i+1;
            string prct;
            while(ligne[j] != 34){
                if(ligne[j] == 44){
                    float num;
                    stringToFloat(prct, num);
                    data->addPrct(num);
                    
                    cout << num << endl;
                    prct = "";
                }else{
                    prct += ligne[j];
                }
                j++;
            }

            float num;
            stringToFloat(prct, num);
            data->addPrct(num);

            cout << num << endl;
                   
            //get color
            j++;        
            int colorInt[3];
            int z=0;
            string str;
                    
            while(ligne[j] != 34){
                if(ligne[j] == 44){
                    stringToInt(str, colorInt[z]);
                    z++;
                    str = "";
                }else{
                    str += ligne[j];
                }
                j++;
            }
            stringToInt(str, colorInt[2]);
            
            
            cout << colorInt[0] << endl;
            cout << colorInt[1] << endl;
            cout << colorInt[2] << endl;
            
            data->SetColor(Color(colorInt[0], colorInt[1], colorInt[2]));
            
            chartData.add(data);
        }
        
    }
    else cout << "unable to open the file" << endl;
}

/*DataParser::DataParser(const DataParser& orig) {
}*/

DataParser::~DataParser() {
}


