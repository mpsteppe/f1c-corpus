// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A57F0
// Canonical corpus name: FindZeroResultIndex
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FindZeroResultIndex_004a57f0.c

void UnknownObject::FindZeroResultIndex()
{
    // Iterates i from 0 calling NthValidPartLookup(i); the loop breaks when the lookup returns 0 and i > 0, then stores the terminating index into this[42] (dword index 42 = byte offset 0xA8) and returns the last lookup result. Existing analysis reads this as a count of valid parts (the first index whose lookup returns 0), which is consistent with the raw behavior but not proven by the raw source alone.
    // LOOP: Loop over i = 0, 1, 2, ... calling NthValidPartLookup(i) each iteration, incrementing i; break when the call returns 0 and i > 0. [source:raw, function:0x004A57F0, callee:0x004A5820]
    // GUARD: Loop exit requires NthValidPartLookup(i) == 0 AND i > 0, so at least one valid part (i = 0 returning nonzero) must exist for termination. [source:raw, function:0x004A57F0]
    // ASSIGNMENT: Write i (the first index whose NthValidPartLookup returned 0) to this[42] (dword index 42, byte offset 0xA8). [source:raw, function:0x004A57F0, field:this:0x000000A8]
    // RETURN: Return result, the NthValidPartLookup return value from the final (breaking) call. [source:raw, function:0x004A57F0]

    // Conservative worker pseudocode:
    //   for (i = 0; ; ++i) {
    //       result = NthValidPartLookup(i);
    //       if (result == 0 && i > 0) break;
    //   }
    //   this[42] = i;
    //   return result;
    // UNRESOLVED: Semantics of the value stored at this+0xA8 (per-skeleton analysis calls it a valid-part count) come from existing_analysis, which is DERIVED; the raw source only shows the terminating index being stored.
    // UNRESOLVED: Behavior when NthValidPartLookup never returns 0 is an unbounded loop; no guard in this function bounds it.
}
