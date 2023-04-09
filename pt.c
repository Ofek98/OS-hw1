#include "os.h"

void page_table_update(uint64_t pt, uint64_t vpn, uint64_t ppn);

uint64_t page_table_query(uint64_t pt, uint64_t vpn){
    int i;
    uint64_t next_node, pt_head;
    uint64_t* pt_head_pointer = (uint64_t*) phys_to_virt(pt);
    for (i = 0; i < 5; i++){
        next_node = vpn << (i*9);
        next_node = next_node >> 36;
        pt_head = pt_head_pointer[next_node];
        if (!(pt_head % 2)){
            return NO_MAPPING;
        }
        pt_head_pointer = (uint64_t*) phys_to_virt(pt_head);
    }
    return *pt_head_pointer;
}
    