// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B4F70
// Canonical corpus name: StructInitWithGlobalData
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithGlobalData_004b4f70.c

void UnknownObject::StructInitWithGlobalData()
{
    // Initializes a structure: delegates sub-struct initialization at this+0x90 to ThunkWithStructInitSubCalls, zeroes four byte fields (offsets 0x0, 0x1, 0x41, 0x61), then writes a sentinel dword (-190986834 = 0xF49C952E) into three consecutive dword fields at offsets 0x84, 0x88 and 0x8C. Returns the sentinel value.
    // CALL: Call ThunkWithStructInitSubCalls on the sub-struct at this+0x90 (byte offset 144) to initialize it with default parameters. [callee:0x004FFFA0, source:raw]
    // ASSIGNMENT: Zero the byte field at this+0x0 (this[0]) as an enable/flag field. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero the byte field at this+0x1 (this[1]). [field:this:0x00000001, source:raw]
    // ASSIGNMENT: Zero the byte field at this+0x41 (this[65]). [field:this:0x00000041, source:raw]
    // ASSIGNMENT: Zero the byte field at this+0x61 (this[97]). [field:this:0x00000061, source:raw]
    // ASSIGNMENT: Write sentinel dword -190986834 (0xF49C952E) to this+0x84 (dword index 33); the value corresponds to the default float constant read from flt_5ACD10. [field:this:0x00000084, global:0x005ACD10, source:raw]
    // ASSIGNMENT: Write sentinel dword -190986834 (0xF49C952E) to this+0x88 (dword index 34). [field:this:0x00000088, global:0x005ACD10, source:raw]
    // ASSIGNMENT: Write sentinel dword -190986834 (0xF49C952E) to this+0x8C (dword index 35). [field:this:0x0000008C, global:0x005ACD10, source:raw]
    // RETURN: Return the sentinel value -190986834 stored in result. [source:raw]

    // Conservative worker pseudocode:
    //   int StructInitWithGlobalData(char *this) {
    //     ThunkWithStructInitSubCalls(this + 144);
    //     this[0] = 0; this[1] = 0;
    //     this[0x41] = 0; this[0x61] = 0;
    //     *((_DWORD *)this + 33) = 0xF49C952E;
    //     *((_DWORD *)this + 34) = 0xF49C952E;
    //     *((_DWORD *)this + 35) = 0xF49C952E;
    //     return 0xF49C952E;
    //   }
    // UNRESOLVED: Concrete object type and field semantics are unknown; the four zeroed bytes and the triple sentinel dwords form an unverified initialization contract.
    // UNRESOLVED: flt_5ACD10 is read to supply the sentinel value, but its identity and why the same value is stored in three dwords is not established.
}
