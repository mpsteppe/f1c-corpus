// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A5820
// Canonical corpus name: NthValidPartLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NthValidPartLookup_004a5820.c

void UnknownObject::NthValidPartLookup()
{
    // Finds the Nth (1-indexed) available pit part: iterates the part list at this[0x158] (element count at +16) over indices resolved by CompoundIndexLookup, optionally restricting the search to a compound type via this[0x15C]. A part whose byte at +20 is set (busy/occupied) is only counted when the session filter is bypassed (dword_7C56A4 outside 1..5 or the out-of-session flag dword_8AFED4 set); a free part is counted when no compound filter is active or its resolved part equals the filter compound. Returns the part pointer for the Nth accepted candidate, or 0 when fewer than N candidates exist.
    // GUARD: Return 0 immediately when the requested ordinal a2 is not positive (Nth lookup is 1-indexed). [source:raw, function:0x004A5820]
    // ASSIGNMENT: Initialize the compound filter reference v4 to null; when the filter field this[0x15C] is non-negative, resolve it through CompoundIndexLookup to obtain the reference compound pointer. [callee:0x004D7570, field:this:0x0000015C, guard:0, source:raw]
    // LOOP: Iterate part indices i from 0 up to the element count stored at this[0x158]+16, resolving each index into a part pointer via CompoundIndexLookup(i). [callee:0x004D7570, field:this:0x00000158, source:raw]
    // GUARD: For a part whose byte at +20 is set (busy/occupied), accept it as a candidate only when the session-type global dword_7C56A4 is outside the valid range 1..5 or the out-of-session flag dword_8AFED4 is set; otherwise the busy part is skipped. [global:0x007C56A4, global:0x008AFED4, source:raw]
    // GUARD: For a part whose byte at +20 is clear (free), accept it as a candidate when no compound filter is active or the resolved part equals the filter compound v4. [callee:0x004D7570, source:raw]
    // RETURN: Decrement the remaining-candidates counter v2; when it reaches zero, return the current part pointer as the Nth valid part. [source:raw]
    // RETURN: Return 0 when the loop exhausts all parts before the Nth valid part is found. [source:raw]

    // Conservative worker pseudocode:
    //   if (a2 <= 0) return 0;
    //   v4 = 0;
    //   if ((int)this[87] >= 0) v4 = CompoundIndexLookup(this[87]);
    //   for (i = 0; i < this[86][4]; ++i) {
    //     part = CompoundIndexLookup(i);
    //     if (part[5]) {
    //       if (dword_7C56A4 <= 0 || dword_7C56A4 > 5 || dword_8AFED4) { if (!--a2) return part; }
    //     } else if (!v4 || v4 == part) {
    //       if (!--a2) return part;
    //     }
    //   }
    //   return 0;
    // UNRESOLVED: Field this[0x168] is listed in the packet but is not referenced in the decompiled body; its role is unknown.
    // UNRESOLVED: The part-list object at this[0x158] and the compound-index space served by CompoundIndexLookup are of unknown class; the busy byte at +20 and the count at +16 are interpreted by role only.
    // UNRESOLVED: Callers span pit-session and repair/display paths (PitPartStateCopy, FindZeroResultIndex, PitRepairStatusDisplay, GuardedCallWithCheck, PitStopOperationTimer), but the owning class is not evidenced.
    // UNRESOLVED: The semantics of dword_7C56A4 (session type) and dword_8AFED4 (out-of-session flag) come from the fill's prose and are not proven by this packet alone.
}
