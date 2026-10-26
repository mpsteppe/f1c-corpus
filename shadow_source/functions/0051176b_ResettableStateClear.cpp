// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051176B
// Canonical corpus name: ResettableStateClear
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResettableStateClear_0051176b.c

void UnknownObject::ResettableStateClear()
{
    // Reads obj = *a1 (a1 is a pointer-to-pointer / handle), then unconditionally writes 0 to obj+0x6C and 0 to obj+0x14, and returns the obj pointer. Partial state reset on the pointed-to struct; no branches, no calls.
    // CALCULATION: Dereference a1 to obtain obj, the pointer to the state struct. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write 0 to obj+0x6C. [field:obj:0x0000006C, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write 0 to obj+0x14. [field:obj:0x00000014, field:this:0x00000000, source:raw]
    // RETURN: Return the obj pointer (the original *a1 value). [field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   int* ResettableStateClear(int* a1) {
    //     int* obj = (int*)*a1;
    //     *(int*)((char*)obj + 0x6C) = 0;
    //     *(int*)((char*)obj + 0x14) = 0;
    //     return obj;
    //   }
    // UNRESOLVED: Semantics of the two reset fields (obj+0x14 and obj+0x6C) are unknown; the state struct type and the fields' purposes are not established.
    // UNRESOLVED: a1 is a pointer-to-pointer (handle); the relationship between a1 and the state object owner is unknown.
}
