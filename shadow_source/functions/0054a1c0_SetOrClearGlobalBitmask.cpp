// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054A1C0
// Canonical corpus name: sub_54A1C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_54A1C0_0054a1c0.c

void UnknownObject::SetOrClearGlobalBitmask()
{
    // __stdcall bitmask mutation of the global dword_8B8EE0 (0x008B8EE0). When a2 is non-zero, the bits of a1 are OR-ed into the global (set); otherwise the inverted bits of a1 are AND-ed in (clear). In both branches the return value is the new logical state: a1 | global on set, ~a1 on clear. Referenced by VidMan_Init (004FA320).
    // GUARD: Branch on a2: non-zero selects the set path, zero selects the clear path. [function:0x0054A1C0, source:raw]
    // ASSIGNMENT: Set path: dword_8B8EE0 |= a1; result = a1 | dword_8B8EE0. [global:0x008B8EE0, function:0x0054A1C0, source:raw]
    // ASSIGNMENT: Clear path: dword_8B8EE0 &= ~a1; result = ~a1. [global:0x008B8EE0, function:0x0054A1C0, source:raw]
    // RETURN: Return result: new combined bitmask state from the executed branch. [function:0x0054A1C0, source:raw]
    // CALL: Invoked by VidMan_Init (004FA320), placing this in video-manager initialization bitmask configuration. [caller:0x004FA320]

    // Conservative worker pseudocode:
    //   if (a2) {
    //     result = a1 | dword_8B8EE0;
    //     dword_8B8EE0 |= a1;
    //   } else {
    //     result = ~a1;
    //     dword_8B8EE0 &= ~a1;
    //   }
    //   return result;
    // UNRESOLVED: Semantic meaning of each bit in dword_8B8EE0 is unknown; only the set/clear transform is evident.
    // UNRESOLVED: The set branch stores the new value into the global but returns the pre-stored computation, so the returned value differs subtly between branches; intent is unconfirmed.
}
