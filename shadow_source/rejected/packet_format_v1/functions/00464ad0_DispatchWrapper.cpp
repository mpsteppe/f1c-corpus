// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464AD0
// Canonical corpus name: DispatchWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DispatchWrapper_00464ad0.c

void UnknownObject::DispatchWrapper()
{
    // Trivial dispatch helper: calls BitFlagSetter on the byte element this[a2], requesting bit 1 be set, and returns the result. Used by EntityVisibilityGridManager.
    // CALL: Call BitFlagSetter(&this[a2], 1) to set bit 1 on the byte at index a2 within the caller's byte array. [callee:0x004649F0, source:raw]
    // RETURN: Return the value produced by BitFlagSetter. [source:raw]

    // Conservative worker pseudocode:
    //   return BitFlagSetter(&this[a2], 1);
}
