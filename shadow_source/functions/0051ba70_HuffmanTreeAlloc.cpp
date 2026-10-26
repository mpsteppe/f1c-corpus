// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051BA70
// Canonical corpus name: HuffmanTreeAlloc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HuffmanTreeAlloc_0051ba70.c

void UnknownObject::HuffmanTreeAlloc()
{
    // Allocation initializer for a Huffman-tree context object a1. Calls the sub-allocator behind the vtable pointer at offset 0x4 to allocate an 80-byte context, stores it at offset 0x194, sets the context's first vtable entry to sub_51B7CD and zeroes vtable slots 14 through 17. Then calls the same sub-allocator for a flat table of slot_count * 256 bytes (slot_count read from offset 0x20, shifted left by 8), stores that pointer at offset 0x8C, and fills each 256-byte slot with 0xFF while slot_count is positive. Returns the table pointer when the fill loop is skipped and -1 after a completed fill loop.
    // CALL: Indirect allocation call through the sub-allocator vtable at *(a1 + 4) with arguments (a1, 1, 80) to allocate an 80-byte Huffman-tree context. [field:*(this+0x4):0x00000000, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Store the allocated context pointer at offset 0x194 (a1 + 404). [field:this:0x00000194, source:raw]
    // ASSIGNMENT: Set the context's vtable entry 0 to sub_51B7CD and zero the vtable slots 14, 15, 16 and 17. [global:0x0051B7CD, source:raw]
    // CALL: Indirect allocation call through the same sub-allocator vtable at *(a1 + 4) with arguments (a1, 1, slot_count << 8) to allocate the flat table of slot_count * 256 bytes. [field:*(this+0x4):0x00000000, field:this:0x00000004, field:this:0x00000020, source:raw]
    // ASSIGNMENT: Store the allocated table pointer at offset 0x8C (a1 + 140). [field:this:0x0000008C, source:raw]
    // GUARD: Guard on the slot count at offset 0x20 being <= 0; when true the 0xFF fill loop is skipped. [guard:0, field:this:0x00000020, source:raw]
    // LOOP: Loop slot_count times over the flat table, memsetting each 256-byte slot to 0xFF. [field:this:0x00000020, source:raw]
    // RETURN: Return result: the table pointer when the fill loop is skipped, otherwise -1 after the loop has run. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_51BA70(int self) {
    //     int (*alloc)(int, int, int) = *(int (**)(int, int, int))(self + 4);
    //     int *ctx = alloc(self, 1, 80);
    //     *(int *)(self + 404) = (int)ctx;
    //     ctx[0] = (int)sub_51B7CD;
    //     ctx[14] = 0; ctx[15] = 0; ctx[16] = 0; ctx[17] = 0;
    //     int slotCount = *(int *)(self + 32);
    //     char *table = alloc(self, 1, slotCount << 8);
    //     *(int *)(self + 140) = (int)table;
    //     int result = (int)table;
    //     int i = 0;
    //     if (slotCount > 0) {
    //       do {
    //         result = -1;
    //         memset(table + i * 256, 0xFF, 256);
    //         ++i;
    //       } while (i < slotCount);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Object type and the exact structure of the Huffman-tree context and table are unknown; the sub-allocator function behind the vtable at offset 0x4 is not resolved here.
    // UNRESOLVED: The allocator call uses the cdecl convention through a vtable slot; its actual signature and allocation semantics are caller-side contracts.
    // UNRESOLVED: Return value differs by path: table pointer when slot_count <= 0, -1 after a fill loop.
}
