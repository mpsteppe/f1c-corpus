// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059D948
// Canonical corpus name: GlobalFlagSetterViaFunctionCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalFlagSetterViaFunctionCall_0059d948.c

void UnknownObject::GlobalFlagSetterViaFunctionCall()
{
    // Sets a single-byte global flag from a computed value, then forwards the HUD render path. Calls ShortComputation_bad0() to produce a byte, stores it at dword_5C7530 + 128, and returns the result of a HUD-flag renderer (named in source only) called with that byte, literal 0, and the two original arguments a1/a2.
    // CALL: Call ShortComputation_bad0() and capture its byte result in v2. [callee:0x0049BAD0, source:raw]
    // ASSIGNMENT: Write v2 as a single byte at dword_5C7530 + 128, setting the global flag cell. [global:0x005C7530, source:raw]
    // CALL: Invoke HUDFlagRendererSecondary(v2, 0, a1, a2) and return its value; the renderer is named in the raw source but carries no callee address evidence in the packet. [function:0x0059D948, source:raw]

    // Conservative worker pseudocode:
    //   v2 = ShortComputation_bad0();
    //   *(byte*)(dword_5C7530 + 128) = v2;
    //   return HUDFlagRendererSecondary(v2, 0, a1, a2);
    // UNRESOLVED: HUDFlagRendererSecondary has no callee address evidence in the packet; it is described from the raw source name only.
    // UNRESOLVED: The meaning of the byte stored at dword_5C7530 + 128 (flag/id) is not derivable from this packet.
    // UNRESOLVED: Owner object identity is not established by the packet.
}
