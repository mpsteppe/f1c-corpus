// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F2B50
// Canonical corpus name: PhysicsDefaultsInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsDefaultsInitializer_004f2b50.c

void UnknownObject::PhysicsDefaultsInitializer()
{
    // Zero-initializes a 16-element array at the object base, then writes a block of physics default constants through v1 (DWORD indices 18..65). Returns v1. Called from TireModelDataInit during tire model data setup. The decompiled source never assigns v1, so the literal write target is ambiguous (likely the same object passed to ZeroInit16ElementArray).
    // CALL: ZeroInit16ElementArray(this) zero-fills the 16-element array at the object base. [callee:0x004F2B10, source:raw]
    // ASSIGNMENT: Series of literal default assignments through v1 at DWORD indices 18..65: v1[21] = -1078355559; v1[18] = 0; v1[19] = 0; v1[22] = 0; v1[23] = 0; v1[20] = -1717986918; v1[24] = 0; v1[25] = 0; v1[28] = 0; v1[29] = 0; v1[26] = -1717986918; v1[27] = 1070176665; v1[48] = 0; v1[46] = -1374389534; v1[47] = 1082665287; v1[49] = 1083410432; v1[50] = 108576773; v1[51] = 1062468877; v1[52] = 34359738; v1[53] = 1065781035; v1[54] = -1998362383; v1[55] = 1059387573; v1[56] = 810889825; v1[57] = 1059301674; v1[58] = 1717986918; v1[59] = 1072064102; v1[60] = 1697096197; v1[61] = 1056654162; v1[62] = 1992864825; v1[63] = 1065000894; v1[64] = -755914244; v1[65] = 1061184077. [source:raw]
    // RETURN: Returns v1 (the object receiving the default constants). [source:raw]

    // Conservative worker pseudocode:
    //   ZeroInit16ElementArray(this);
    //   // v1 is never assigned in the decompiled view; the writes below target it.
    //   v1[21] = -1078355559;  v1[18] = 0;  v1[19] = 0;  v1[22] = 0;  v1[23] = 0;
    //   v1[20] = -1717986918;  v1[24] = 0;  v1[25] = 0;  v1[28] = 0;  v1[29] = 0;
    //   v1[26] = -1717986918;  v1[27] = 1070176665;
    //   v1[48] = 0;  v1[46] = -1374389534;  v1[47] = 1082665287;
    //   v1[49] = 1083410432;  v1[50] = 108576773;  v1[51] = 1062468877;
    //   v1[52] = 34359738;  v1[53] = 1065781035;  v1[54] = -1998362383;
    //   v1[55] = 1059387573;  v1[56] = 810889825;  v1[57] = 1059301674;
    //   v1[58] = 1717986918;  v1[59] = 1072064102;  v1[60] = 1697096197;
    //   v1[61] = 1056654162;  v1[62] = 1992864825;  v1[63] = 1065000894;
    //   v1[64] = -755914244;  v1[65] = 1061184077;
    //   return v1;
    // UNRESOLVED: v1 is read before assignment in the decompiled source; the literal writes' target is ambiguous (likely aliases the object passed to ZeroInit16ElementArray, i.e. this).
    // UNRESOLVED: The default block spans DWORD indices 18..65 (~48 dwords / ~192 bytes); element-index-to-byte-offset mapping is not pinned because the packet provides no field evidence refs.
}
