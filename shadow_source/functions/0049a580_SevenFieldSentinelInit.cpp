// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049A580
// Canonical corpus name: F_7FieldSentineInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_7FieldSentineInit_0049a580.c

void UnknownObject::SevenFieldSentinelInit()
{
    // Constructor/initializer on a 7-dword object. Sets all seven fields to literals: offsets 0x0, 0x4, 0xC, 0x14 and 0x18 to 0, and offsets 0x8 and 0x10 to -1 (unsigned packet literal 18446744073709551615), which read as sentinel values. No reads, no globals, no callees; returns the object pointer. Invoked by sub_493480.
    // ASSIGNMENT: Field at offset 0x0 (dword index 0) set to 0 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Field at offset 0x4 (dword index 1) set to 0 [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Field at offset 0x8 (dword index 2) set to -1 (unsigned packet literal 18446744073709551615), a sentinel value [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Field at offset 0xC (dword index 3) set to 0 [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Field at offset 0x10 (dword index 4) set to -1 (unsigned packet literal 18446744073709551615), a sentinel value [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Field at offset 0x14 (dword index 5) set to 0 [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Field at offset 0x18 (dword index 6) set to 0 [field:this:0x00000018, source:raw]
    // RETURN: Returns the this pointer unchanged [function:0x0049A580, source:raw]
    // CALL: Invoked by sub_493480 as an object initializer [caller:0x00493480, source:raw]

    // Conservative worker pseudocode:
    //   result = this;
    //   this[1] = 0;
    //   this[2] = -1;
    //   this[3] = 0;
    //   this[4] = -1;
    //   this[0] = 0;
    //   this[6] = 0;
    //   this[5] = 0;
    //   return result;
    // UNRESOLVED: The role of the object is not named by this function; the -1 sentinels at offsets 0x8 and 0x10 are consistent with invalid/empty markers but their semantics are unverifiable here
    // UNRESOLVED: The write order in the decompiled source (this[1], this[2], this[3], this[4], this[0], this[6], this[5]) differs from ascending offset order; no significance is claimed
}
