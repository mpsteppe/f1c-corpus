// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00476060
// Canonical corpus name: CarFlagByteSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CarFlagByteSetter_00476060.c

void UnknownObject::CarFlagByteSetter()
{
    // Byte-flag setter (__thiscall) on a car object: unconditionally writes argument a2 into the byte field at offset 0x2C of the this object and returns a2 unchanged. No guards, no calls, no global access. The named fill identifies 0x2C as a car state/flag byte and notes an external poke survives (written unconditionally each call).
    // ASSIGNMENT: Store a2 into the byte field at offset 0x2C of this. [field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Seed result with a2 so the function returns the written value. [source:raw]
    // RETURN: Return a2 (result) unchanged. [function:0x00476060, source:raw]

    // Conservative worker pseudocode:
    //   char CarFlagByteSetter(char *this, char a2) {
    //     char result = a2;
    //     this[44] = a2;
    //     return result;
    //   }
    // UNRESOLVED: Owning object type is unknown; the fill labels 0x2C a car state/flag byte (DERIVED) but that identity is not confirmed from this function alone.
    // UNRESOLVED: Meaning of the stored value (which flag, which states) is not established here.
}
