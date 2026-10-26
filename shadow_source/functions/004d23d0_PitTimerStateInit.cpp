// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D23D0
// Canonical corpus name: PitTimerStateInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PitTimerStateInit_004d23d0.c

void UnknownObject::PitTimerStateInit()
{
    // Initializes a pit-timer struct from a source struct: clears two flag bytes, copies a stored value and a timestamp, computes a second time as timestamp plus a stored offset, dispatches a registration call with a session value of 4, then broadcasts the timestamp to every active vehicle. Returns the vehicle count.
    // ASSIGNMENT: *(_BYTE*)(this + 0xC1) := 0 — clear flag byte at offset 0xC1 [field:this:0x000000C1, source:raw]
    // ASSIGNMENT: *(_DWORD*)(this + 0xD8) := *(_DWORD*)(a2 + 8) — copy stored value from source struct into offset 0xD8 [field:this:0x000000D8, source:raw]
    // ASSIGNMENT: *(float*)(this + 0xB0) := *(float*)(a2 + 12) — copy timestamp float from source struct into offset 0xB0 [field:this:0x000000B0, source:raw]
    // CALCULATION: v4 := *(float*)(a2 + 12) + *(float*)(this + 0xB8) — timestamp plus stored time offset at 0xB8 [field:this:0x000000B8, source:raw]
    // ASSIGNMENT: *(_BYTE*)(this + 0xC2) := 0 — clear flag byte at offset 0xC2 [field:this:0x000000C2, source:raw]
    // ASSIGNMENT: *(float*)(this + 0xB4) := v4 — store computed time into offset 0xB4 [field:this:0x000000B4, source:raw]
    // CALL: sub_42D140(&dword_7C569C, 4) — dispatch registration using the session value stored at 0x7C569C with parameter 4 [callee:0x0042D140, global:0x007C569C, source:raw]
    // LOOP: for i in [0, dword_5C329C): sub_4BC2D0(dword_7C54F0[i] + 16436, this+0xB0) — broadcast the timestamp at offset 0xB0 to each vehicle pointer at 0x7C54F0, receiver at vehicle base plus 16436 [callee:0x004BC2D0, global:0x005C329C, global:0x007C54F0, field:this:0x000000B0, source:raw]
    // RETURN: return result — the vehicle count from dword_5C329C [global:0x005C329C, source:raw]

    // Conservative worker pseudocode:
    //   *(_BYTE*)(this + 0xC1) = 0;
    //   *(_DWORD*)(this + 0xD8) = *(_DWORD*)(a2 + 8);
    //   *(float*)(this + 0xB0) = *(float*)(a2 + 12);
    //   v4 = *(float*)(a2 + 12) + *(float*)(this + 0xB8);
    //   *(_BYTE*)(this + 0xC2) = 0;
    //   *(float*)(this + 0xB4) = v4;
    //   sub_42D140(&dword_7C569C, 4);
    //   for (i = 0; i < dword_5C329C; ++i) {
    //       sub_4BC2D0((_DWORD*)(dword_7C54F0[i] + 16436), *(_DWORD*)(this + 0xB0));
    //   }
    //   return result;
    // UNRESOLVED: Role of the dispatch value 4 passed to sub_42D140 alongside dword_7C569C is unknown.
    // UNRESOLVED: Semantics of the per-vehicle receiver at vehicle base plus 16436 for sub_4BC2D0 are unknown.
    // UNRESOLVED: The owning object type is unidentified; the this pointer is a generic int.
}
