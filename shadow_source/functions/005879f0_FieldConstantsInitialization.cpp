// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005879F0
// Canonical corpus name: FieldConstantsInitialization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldConstantsInitialization_005879f0.c

void UnknownObject::FieldConstantsInitialization()
{
    // Straight-line initializer that resets the buffer state fields of the caller's object. Writes 0 to the dword fields at offsets 0x400, 0x404 and 0x408, then writes the constant 500 to the field at offset 0x40C. Returns 0 unconditionally. Called by BufferedCharIOInit (0x005876F0) and sub_5878A0 (0x005878A0) as the constant-seeding part of a buffer-state reset.
    // ASSIGNMENT: Resets the dword field at offset 0x400 (this[256]) to 0 [field:this:0x00000400, source:raw]
    // ASSIGNMENT: Resets the dword field at offset 0x404 (this[257]) to 0 [field:this:0x00000404, source:raw]
    // ASSIGNMENT: Resets the dword field at offset 0x408 (this[258]) to 0 [field:this:0x00000408, source:raw]
    // ASSIGNMENT: Sets the dword field at offset 0x40C (this[259]) to the literal constant 500, interpreted as a default capacity/limit [field:this:0x0000040C, source:raw]
    // RETURN: Returns the constant value 0 as the function result [source:raw]
    // CALL: Invoked by BufferedCharIOInit (0x005876F0) and by sub_5878A0 (0x005878A0) as the constant-initialization step of a buffer object reset [caller:0x005876F0, caller:0x005878A0, source:raw]

    // Conservative worker pseudocode:
    //   this[256] = 0;
    //   this[257] = 0;
    //   this[258] = 0;
    //   this[259] = 500;
    //   return 0;
    // UNRESOLVED: The semantic roles of offsets 0x400-0x40C (position/counter/capacity) are inferred from the skeleton fill; the owning object type is unknown
}
