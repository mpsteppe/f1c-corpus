// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054A200
// Canonical corpus name: GlobalFlagSetClear
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalFlagSetClear_0054a200.c

void UnknownObject::GlobalFlagSetClear()
{
    // Set or clear caller-supplied bits in the global flag dword_8B8E34 based on a2 (nonzero sets, zero clears), returning the resulting combined value.
    // GUARD: if a2 is nonzero take the set path, otherwise take the clear path [source:raw]
    // ASSIGNMENT: dword_8B8E34 |= a1 (set path: OR the caller bits into the global flag word) [global:0x008B8E34]
    // CALCULATION: result = a1 | dword_8B8E34 (set path: combined bit mask) [global:0x008B8E34]
    // ASSIGNMENT: dword_8B8E34 &= ~a1 (clear path: AND out the caller bits from the global flag word) [global:0x008B8E34]
    // CALCULATION: result = ~a1 (clear path: complement of the caller mask) [source:raw]
    // RETURN: return result (combined mask on set path, complement on clear path) [source:raw]

    // Conservative worker pseudocode:
    //   if (a2) {
    //     dword_8B8E34 |= a1;
    //     return a1 | dword_8B8E34;
    //   } else {
    //     dword_8B8E34 &= ~a1;
    //     return ~a1;
    //   }
    // UNRESOLVED: the global flag set represented by dword_8B8E34 is unidentified
    // UNRESOLVED: the caller-specific meaning of the flag bits in a1 is not established
}
