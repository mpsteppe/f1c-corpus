// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BA6C0
// Canonical corpus name: TwoPathDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoPathDispatch_004ba6c0.c

void UnknownObject::TwoPathDispatch()
{
    // Type-sentinel two-path dispatcher. Reads an integer sentinel at this[0]; path 1 runs the session update path (a ring-buffer/session wrapper gated by an enable flag, followed by a session-state check and an optional scoring/state update), and path 2 runs the weather path (a packed-flag read gated by a second update call). Returns a char status from whichever path ran.
    // ASSIGNMENT: Read the type sentinel from this[0]; dispatch on whether it is 1 or 2. [field:this:0x00000000, source:raw]
    // GUARD: Path 1: if the sentinel equals 1, run the session update path. [guard:0, field:this:0x00000000, source:raw]
    // CALL: Path 1 pre-step: if the enable flag byte_7C56AC is not set, call CallWrapper_9870(this + 2, &dword_83EE60, &unk_5EC6D8, dbl_8AFEA0) passing the ring-buffer counter, vehicle base and session time. [callee:0x004B9870, global:0x007C56AC, global:0x0083EE60, global:0x005EC6D8, global:0x008AFEA0, source:raw]
    // CALL: Path 1 session check: set the status from SessionStateCheckWrapper(dword_7CD25C); if the session is inactive, proceed to the secondary update. [callee:0x00461DB0, global:0x007CD25C, source:raw]
    // GUARD: Path 1 secondary update: if the session check failed and dword_7CC4C8 is nonzero, run sub_4B9890(this + 2, dword_7D0080, this) and take its result as the status. [callee:0x004B9890, global:0x007CC4C8, global:0x007D0080, source:raw]
    // GUARD: Path 2: else if the sentinel equals 2, run the weather path. [field:this:0x00000000, source:raw]
    // CALL: Path 2: read the packed flag at this + 2 via PackedFlagRead_9a00; if it returns zero, run the second path-2 update on dword_8ACEA0 and take its result as the status. [callee:0x004B9A00, global:0x008ACEA0, source:raw]
    // RETURN: Return the char status produced by whichever path executed. [function:0x004BA6C0, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   v2 = this->type;
    //   if (this->type == 1) {
    //     if (!byte_7C56AC)
    //       CallWrapper_9870(this + 2, &dword_83EE60, &unk_5EC6D8, dbl_8AFEA0);
    //     v2 = SessionStateCheckWrapper(dword_7CD25C);
    //     if (!v2 && dword_7CC4C8)
    //       v2 = sub_4B9890((float**)this + 2, (float)dword_7D0080, this);
    //   } else if (v2 == 2) {
    //     v2 = PackedFlagRead_9a00(this + 2);
    //     if (!v2) v2 = WeatherParticleUpdate(&dword_8ACEA0);
    //   }
    //   return (char)v2;
    // UNRESOLVED: The callee address of the second path-2 call (named WeatherParticleUpdate in the existing analysis) is not carried by the packet; the only available evidence reference for it is source:raw.
    // UNRESOLVED: Semantics of the globals (unk_5EC6D8 vehicle base, dword_83EE60 ring-buffer counter, dword_8ACEA0 weather/scoring base, dbl_8AFEA0 session time) are DERIVED from the existing analysis, not packet facts.
    // UNRESOLVED: Sentinel value 2 and its weather meaning are DERIVED; only the value 1 (session path) is a packet guard.
}
