// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045B430
// Canonical corpus name: PerIndexStructFieldResetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PerIndexStructFieldResetter_0045b430.c

void UnknownObject::PerIndexStructFieldResetter()
{
    // Resets one indexed entry of an 8-entry circular buffer: clears a flag byte and writes sentinel values (-1, -1082130432, 3). If the reset index equals the buffer write cursor at offset 0x31C, advances the cursor modulo 8. Returns the cursor value.
    // CALCULATION: v2 := (int)&this[23 * a2 + 15] — entry base byte address: 23-dword stride per entry with a 15-dword struct prefix [source:raw]
    // ASSIGNMENT: *(_BYTE*)v2 := 0 — clear the entry flag byte at the entry base [source:raw]
    // ASSIGNMENT: *(_DWORD*)(v2 + 80) := -1 — write sentinel value -1 at entry base plus 80 [source:raw]
    // ASSIGNMENT: *(_DWORD*)(v2 + 84) := -1082130432 — write sentinel value -1082130432 at entry base plus 84 [source:raw]
    // ASSIGNMENT: *(_DWORD*)(v2 + 88) := 3 — write state value 3 at entry base plus 88 [source:raw]
    // GUARD: if (a2 == this[199]) — the reset index matches the circular-buffer write cursor at offset 0x31C [field:this:0x0000031C, source:raw]
    // CALCULATION: this[199] := (this[199] + 1) % 8 — advance the write cursor at offset 0x31C modulo 8 [field:this:0x0000031C, source:raw]
    // RETURN: return result — the cursor value (advanced if the reset index matched, otherwise unchanged) [function:0x0045B430, source:raw]

    // Conservative worker pseudocode:
    //   v2 = (int)&this[23 * a2 + 15];
    //   *(_BYTE*)v2 = 0;
    //   *(_DWORD*)(v2 + 80) = -1;
    //   *(_DWORD*)(v2 + 84) = -1082130432;
    //   *(_DWORD*)(v2 + 88) = 3;
    //   result = this[199];
    //   if (a2 == result) { result = (result + 1) % 8; this[199] = result; }
    //   return result;
    // UNRESOLVED: Semantics of the per-entry sentinel values (-1, -1082130432, 3) and the entry fields written at base plus 80/84/88 are unknown.
    // UNRESOLVED: Purpose of the 8-entry circular buffer and the identity of the owning object are unknown.
    // UNRESOLVED: The entries are addressed via computed pointers from a2, so no fixed per-entry field offsets are evidenced.
}
