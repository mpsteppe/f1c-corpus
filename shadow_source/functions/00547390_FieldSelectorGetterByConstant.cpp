// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00547390
// Canonical corpus name: ArithmeticComparison_7390
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_7390_00547390.c

void UnknownObject::FieldSelectorGetterByConstant()
{
    // Selector-style field getter: on selector 4096 writes the value of this[0x8C] through the output pointer *a2 and returns it; on selector 0x2000 writes this[0x90] through *a2 and returns a2; otherwise leaves *a2 untouched and returns the unmodified selector a3. Used per-frame by the collision detection system.
    // ASSIGNMENT: Initialize the result to the selector argument a3. [source:raw]
    // GUARD: Branch on selector a3 == 4096 (the 0x1000-valued constant in the raw source). [source:raw]
    // ASSIGNMENT: When selector is 4096, read this[35] (byte offset 0x8C) and write it through the output pointer *a2. [field:this:0x0000008C, source:raw]
    // GUARD: Else-branch on selector a3 == 0x2000. [source:raw]
    // ASSIGNMENT: When selector is 0x2000, read this[36] (byte offset 0x90) and write it through the output pointer *a2. [field:this:0x00000090, source:raw]
    // RETURN: Return the selected field value for selector 4096, the output pointer a2 for selector 0x2000, or the untouched selector a3 otherwise. [source:raw]

    // Conservative worker pseudocode:
    //   int* FieldSelectorGetterByConstant(int* this, int* a2, int* a3) {
    //     int* result = a3;
    //     if (a3 == (int*)4096) {
    //       result = &this[35];
    //       *a2 = result;
    //     } else if (a3 == (int*)0x2000) {
    //       result = a2;
    //       *a2 = this[36];
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Owner class and the meaning of the selector constants 4096 and 0x2000 are unknown.
    // UNRESOLVED: Semantic roles of the fields at offsets 0x8C and 0x90 are unknown.
    // UNRESOLVED: Caller CollisionDetectionSystem context for the per-frame query is unknown.
}
