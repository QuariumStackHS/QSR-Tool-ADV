#ifndef Mod_Dumper
#define Mod_Dumper 1
#include "../includes/Argser.hpp"
using namespace std;
void* Dump(Argser *IN){
    for(int i=0; i<IN->Functions.size();i++){

    cout<<IN->Functions[i].FuncName<<" Instruction: "<<IN->Functions[i].BeginLine<<":"<<IN->Functions[i].EndLine<<endl;}

}


Argser::QSRcModule Mod_Dumper_R(){
    Argser::QSRcModule M;
    M.Set_Name("Dumper");
    M.add_Cask("Dump","see all functions loaded",&Dump);
    return M;

}
#endif