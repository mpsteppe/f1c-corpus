// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055BB20
// Canonical corpus name: F_6FieldStructSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_6FieldStructSetter_0055bb20.c

void UnknownObject::SixFieldStructWrite()
{
    // Generic __thiscall struct setter that copies six DWORD/pointer arguments (a2..a7) into consecutive fields of the `this` object at offsets 0x4 through 0x18, then returns 0. No guards or calls; pure six-field write of caller-supplied values.
    // ASSIGNMENT: Write argument a2 into this[1] (offset 0x4). [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write argument a3 into this[2] (offset 0x8). [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write argument a4 into this[3] (offset 0xC). [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Write argument a5 into this[4] (offset 0x10). [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Write argument a6 into this[5] (offset 0x14). [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Write argument a7 into this[6] (offset 0x18). [field:this:0x00000018, source:raw]
    // RETURN: Return constant 0 always. [function:0x0055BB20, source:raw]
    // CALL: Invoked by sub_55BC00 (0x0055BC00) to populate a six-field record from its arguments. [caller:0x0055BC00, source:raw]

    // Conservative worker pseudocode:
    //   int sub_55BB20(int* this, int a2, int a3, int a4, int a5, int a6, int a7) {
    //     this[1] = a2; this[2] = a3; this[3] = a4;
    //     this[4] = a5; this[5] = a6; this[6] = a7;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic meaning of the six fields and their caller-supplied values depends on the context of sub_55BC00; nothing here establishes the object type.
}
