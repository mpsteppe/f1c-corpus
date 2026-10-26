// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B33B0
// Canonical corpus name: ProgressBarEventEncode
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ProgressBarEventEncode_004b33b0.c

void UnknownObject::ProgressBarEventEncode()
{
    // Packs multiple event parameters into a single bitfield word and writes it to this+0, stores a secondary payload word in this+4, and resets the flag field at this+0x1AC to -1. The packed value is computed from an indexed global base: result = a5 + ((a4 + ((a3 + ((dword_7C56A4 + 8*(a7 + 4*a2)) << 6)) << 10)) << 8). Returns the packed value. Heavily used by UI/progress-bar and session-event callers to enqueue progress bar UI events.
    // CALCULATION: Compute the packed event word: load dword_7C56A4, index into it with 8*(a7 + 4*a2), then apply three left-shift/accumulate stages (<<6, <<10, <<8) and add a5, a4, a3. The result is returned and stored at this+0. [global:0x007C56A4, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store the computed packed event bitfield word into this+0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store the secondary event data word (a6 parameter) into this+4. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Reset the flag field at this+0x1AC to -1. [field:this:0x000001AC, source:raw]
    // RETURN: Return the packed event word as the function result. [function:0x004B33B0, source:raw]

    // Conservative worker pseudocode:
    //   int packed = a5 + ((a4 + ((a3 + ((dword_7C56A4 + 8 * (a7 + 4 * a2)) << 6)) << 10)) << 8);
    //   this->word = packed;
    //   this->data = a6;
    //   this->flag = -1;
    //   return packed;
    // UNRESOLVED: The exact bit positions of a2/a3/a4/a5/a7 within the packed word and the meaning of the global base dword_7C56A4 index are not derivable from this packet alone.
    // UNRESOLVED: this+0x1AC is set to -1 as a reset; its reader-side semantics are outside this function.
}
