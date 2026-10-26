// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00537EC0
// Canonical corpus name: ScorecardZero
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScorecardZero_00537ec0.c

void UnknownObject::ScorecardZero()
{
    // Constructor-style zeroing initializer for a scorecard object. Clears three contiguous _WORD runs of the object: 286 words at this+0x8A, 30 words at this+0x97E, and 19 words at this+0xA72, then zeroes four _DWORD counters at this+0x1693/0x169B/0x169F/0x16A3 and sets the _WORD flag at this+0x48A to 1. Returns a pointer past the end of the cleared 0xA72 run. No reads, no globals, no callees.
    // LOOP: do-while loop zeroing 286 _WORD elements (572 bytes) starting at this+0x8A, stepping by 2 bytes per element. [field:this:0x0000008A, source:raw]
    // LOOP: do-while loop zeroing 30 _WORD elements starting at this+0x97E. [field:this:0x0000097E, source:raw]
    // LOOP: do-while loop zeroing 19 _WORD elements starting at this+0xA72; the final advanced pointer becomes the return value. [field:this:0x00000A72, source:raw]
    // ASSIGNMENT: Zero four _DWORD counters at this+0x1693, this+0x169B, this+0x169F and this+0x16A3. [field:this:0x00001693, field:this:0x0000169B, field:this:0x0000169F, field:this:0x000016A3]
    // ASSIGNMENT: Set the _WORD flag at this+0x48A to 1 (the only non-zero initialization in the function). [field:this:0x0000048A]
    // RETURN: Return the pointer advanced past the last cleared word run (this+0xA72 + 19 words). [source:raw, function:0x00537EC0]

    // Conservative worker pseudocode:
    //   WORD* ScorecardZero(int this) {
    //     for (int n = 286; n; --n) { *(_WORD*)(this + 138) = 0; this_offset += 2; }
    //     for (int n = 30;  n; --n) { *(_WORD*)(this + 2430) = 0; this_offset += 2; }
    //     WORD* result = (_WORD*)(this + 2674);
    //     for (int n = 19;  n; --n) { *result = 0; result += 2; }
    //     *(_DWORD*)(this + 5791) = 0;
    //     *(_DWORD*)(this + 5787) = 0;
    //     *(_DWORD*)(this + 5795) = 0;
    //     *(_DWORD*)(this + 5779) = 0;
    //     *(_WORD*)(this + 1162) = 1;
    //     return result;
    //   }
    // UNRESOLVED: Class owner is unknown (UnknownObject/UNKNOWN); the calling HuffmanBitStreamEncoder at 0x005381F0 does not identify the scorecard type statically here.
    // UNRESOLVED: Field meanings are unknown: the three word runs and four dword counters at 0x1693/0x169B/0x169F/0x16A3 and the flag at 0x48A are unnamed.
    // UNRESOLVED: The runtime prototype name 'ScorecardZero' is LEGACY-trust ABI evidence, not a confirmed source symbol.
}
