#include "assign3.h"


int main(int argc, char* argv[]) {
    Assign3* assign3 = new Assign3();
    assign3->set_instance(assign3);

    assign3->main(argc, argv);
}
