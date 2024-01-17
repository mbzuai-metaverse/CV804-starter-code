#include "assign1.h"


int main(int argc, char* argv[]) {
    Assign1* assign1 = new Assign1();
    assign1->set_instance(assign1);

    assign1->main(argc, argv);
}
