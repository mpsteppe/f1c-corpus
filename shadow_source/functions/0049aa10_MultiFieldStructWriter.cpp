// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049AA10
// Canonical corpus name: MultiFieldStructWriter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiFieldStructWriter_0049aa10.c

void UnknownObject::MultiFieldStructWriter()
{
    // Writes four caller-supplied integer parameters into four consecutive dword fields of a struct (offsets 0x14, 0x18, 0x1C, 0x20) and returns the fourth parameter (a4) as the function result. No guards or calls; straight-line thiscall writer.
    // ASSIGNMENT: Store a2 into struct dword at offset 0x14 (this[5]). [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Store a3 into struct dword at offset 0x18 (this[6]). [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Store a4 into struct dword at offset 0x1C (this[7]). [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Store a5 into struct dword at offset 0x20 (this[8]). [field:this:0x00000020, source:raw]
    // RETURN: Return a4 as the function result; the same value was also stored at offset 0x1C. [source:raw, function:0x0049AA10]

    // Conservative worker pseudocode:
    //   this[5] = a2;
    //   this[6] = a3;
    //   this[7] = a4;
    //   this[8] = a5;
    //   return a4;
    // UNRESOLVED: Why a4 is both stored at +0x1C and returned is unknown; caller intent at ConditionalMultiParamDispatch (0x004861A0) is outside this packet.
}
