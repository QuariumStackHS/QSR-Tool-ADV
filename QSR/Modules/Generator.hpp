#ifndef Generator_hpp
#define Generator_hpp 1
#include "../includes/Argser.hpp"
using namespace std;

void *Gen_Help(Argser *IN)
{
    cout << GREEN << "C++ QSRModules: (" << IN->QS.size() << "):" << endl;
    vector<string> VOM;
    ofstream myfile;
    
    myfile.open("scripts/help.QF");
    myfile<<"Begin:\n";
    myfile<<"-help Base\n";
    for (int i = 0; i < IN->QS.size(); i++)
    {
        cout << "\t" << BOLDBLUE << IN->QS[i].Module_Name << endl;
        VOM.push_back(IN->QS[i].Module_Name.c_str());
        myfile <<"-help "<<IN->QS[i].Module_Name.c_str()<<"\n";
    }

    
    myfile<<"end;";
    
    myfile.close();
}

Argser::QSRcModule Generator()
{
    Argser::QSRcModule M;
    M.Set_Name("Generator");
    M.add_Cask("Gen_Help", "Gen helper", &Gen_Help);
    return M;
}

#endif