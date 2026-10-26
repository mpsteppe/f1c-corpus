// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049A9C0
// Canonical corpus name: ShortComputation_a9c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_a9c0_0049a9c0.c

void UnknownObject::QuadFieldSetter()
{
    // Straight-line setter that stores four arguments into four consecutive fields of the object: a2 to offset 0x4, a3 to offset 0x8, a4 to offset 0xC, and a5 to offset 0x10. Returns the third argument a4, which is also the value stored at offset 0xC.
    // ASSIGNMENT: Store argument a2 into the field at offset 0x4. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Store argument a3 into the field at offset 0x8. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Store argument a4 into the field at offset 0xC. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Store argument a5 into the field at offset 0x10. [field:this:0x00000010, source:raw]
    // RETURN: Return argument a4, the same value stored at offset 0xC. [field:this:0x0000000C, source:raw]

    // Conservative worker pseudocode:
    //   int sub_49A9C0(int* this, int a2, int a3, int a4, int a5) {
    //     this[1] = a2;
    //     this[2] = a3;
    //     this[3] = a4;
    //     this[4] = a5;
    //     return a4;
    //   }
    // UNRESOLVED: Semantic meaning of the four fields (offsets 0x4, 0x8, 0xC, 0x10) is unknown; the function is called from UI render dispatch and tree-node insertion paths.
    // UNRESOLVED: Why the function returns the value stored at offset 0xC is unclear.
}
