// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046B580
// Canonical corpus name: ShortComputation_b580
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_b580_0046b580.c

void UnknownObject::ShortComputation_b580()
{
    // Constructor-style initializer: calls the base/sub-object initializer sub_4893C0, installs the vtable pointer off_59FA98 at offset 0x0, writes parameter a3 into the byte at offset 0xe0 via ByteSetterAt0xe0, then sets field 0x174 to 0, field 0x178 to -1, field 0x17C to parameter a2, and returns this. Called by SeasonDatabaseObjectFactory (0047F440).
    // CALL: Call the base/sub-object initializer sub_4893C0. [callee:0x004893C0, source:raw]
    // ASSIGNMENT: Install the vtable pointer: *this = &off_59FA98 (field 0x0). [field:this:0x00000000, global:0x0059FA98, source:raw]
    // CALL: Write parameter a3 into the byte at offset 0xe0 via ByteSetterAt0xe0. [callee:0x0048A3B0, source:raw]
    // ASSIGNMENT: Set field 0x174 to 0 via this[93] = 0. [field:this:0x00000174, source:raw]
    // ASSIGNMENT: Set field 0x178 to -1 via this[94] = -1 (packet init literal 18446744073709551615 as unsigned max). [field:this:0x00000178, source:raw]
    // ASSIGNMENT: Store parameter a2 into field 0x17C via this[95] = a2. [field:this:0x0000017C, source:raw]
    // RETURN: Return this as the initialized object. [source:raw]
    // CALL: Invoked by SeasonDatabaseObjectFactory (0047F440) to construct a season database variant. [caller:0x0047F440, source:raw]

    // Conservative worker pseudocode:
    //   DWORD* sub_46B580(DWORD* this, int a2, char a3) {
    //     sub_4893C0();
    //     this[0] = (DWORD)&off_59FA98;
    //     ByteSetterAt0xe0(a3);
    //     this[93] = 0;
    //     this[94] = -1;
    //     this[95] = a2;
    //     return this;
    //   }
    // UNRESOLVED: sub_4893C0 and ByteSetterAt0xe0 are unnamed; the base-class identity and the meaning of offset 0xe0 are unknown from this packet
    // UNRESOLVED: Semantics of fields 0x174, 0x178 and 0x17C (the fill labels them season state, season identifier and season parameter) are unverifiable from this packet
    // UNRESOLVED: The object type behind off_59FA98's vtable and parameters a2/a3 meanings are unknown
}
