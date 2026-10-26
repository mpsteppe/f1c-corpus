// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498940
// Canonical corpus name: FunctionCallWrapper_8940
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FunctionCallWrapper_8940_00498940.c

void UnknownObject::getFloatFieldC4()
{
    // Double-returning thiscall that reads the float at this+0xC4 (float-array index 49) and returns it (widened to double). Read-only getter with no side effects, matching the prelabel template classification. Invoked by UIScrollListUpdate (0x0048A8D0).
    // RETURN: Read the float field at this+0xC4 (this[49]) and return it as a double. [field:this:0x000000C4, function:0x00498940, source:raw]

    // Conservative worker pseudocode:
    //   double sub_498940(float* this) {
    //     return this[49];
    //   }
    // UNRESOLVED: Semantics of the float field at this+0xC4 are unknown; it is read by a UI scroll-list update path but its meaning is not established.
    // UNRESOLVED: Caller UIScrollListUpdate (0x0048A8D0) context not reconstructed; caller evidence preserved below.
}
