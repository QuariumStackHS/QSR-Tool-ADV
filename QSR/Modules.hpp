/*put includes here*/
#include "Modules/Mod_Admin.hpp"
#include "Modules/Mod_Dumper.hpp"
#include "Modules/Generator.hpp"
#include "Modules/math.hpp"
#include "includes/Argser.hpp"
/*put your module in this function to add it*/
void Init_Modules(Argser *I){
    I->add_Module(Admin_main());
    I->add_Module(Mod_Dumper_R());
    I->add_Module(Generator());
    I->add_Module(Math_Module());

}