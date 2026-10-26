// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00511457
// Canonical corpus name: StateCounterWithDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateCounterWithDispatch_00511457.c

void UnknownObject::AdvanceJpegRestartMarkerCounter()
{
    // Handles the next JPEG restart marker. Ensures a current marker exists at this+0x178 (reading one via BitstreamTokenReader when it is zero) and compares it against the expected value counter + 208. On a match it reports state 97 through the parameterized dispatcher with the counter value, clears the current marker, and increments the counter modulo 8. On a mismatch it delegates to an alternative handler reached through a vfunc on the stream object, and increments the counter when that handler accepts the marker. Returns 0 when no marker can be read and no handler accepts it.
    // GUARD: If the current marker at this+0x178 is zero, load the next marker by calling BitstreamTokenReader; the function returns 0 when no marker can be produced [field:this:0x00000178, callee:0x005110FC, source:raw]
    // GUARD: Expected-marker match: compare the current marker at this+0x178 against the restart counter stored at (this+0x190 value)+84 plus 208 (0xD0) [field:this:0x00000178, field:this:0x00000190, source:raw]
    // ASSIGNMENT: On a match write state 97 to obj+0x14 and the current counter value to obj+0x18 [field:obj:0x00000014, field:obj:0x00000018, field:this:0x00000000, source:raw]
    // CALL: Parameterized dispatch of the matched restart marker through the second vtable entry (obj+0x4) with argument 3 [field:obj:0x00000004, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Clear the current marker at this+0x178 back to 0 after the match is dispatched [field:this:0x00000178, source:raw]
    // CALL: On a mismatch, delegate to the alternative marker handler reached through vfunc at (this+0x14 stream object)+0x14, passing the current counter value; a true return accepts the marker and falls through to the counter increment [field:this:0x00000014, field:this:0x00000190, source:raw]
    // CALCULATION: Increment the restart counter at (this+0x190 value)+84 modulo 8: ((counter as byte) + 1) & 7 [field:this:0x00000190, source:raw]
    // RETURN: Return 1 when the marker matched, or when the alternative handler accepted it (counter incremented in both cases); return 0 otherwise [function:0x00511457, source:raw]

    // Conservative worker pseudocode:
    //   counter_ptr = (this[0x190/4] + 84);
    //   if (this[0x178/4] == 0 && !BitstreamTokenReader(this)) return 0;
    //   if (this[0x178/4] == (*counter_ptr) + 208) {
    //     obj[0x14/4] = 97;  obj[0x18/4] = *counter_ptr;
    //     dispatch_param(obj, 3);              /* obj[4] vfunc * /
    //     this[0x178/4] = 0;
    //   } else {
    //     if (!alt_handler(this, *counter_ptr)) return 0;  /* vfunc at stream[5] + 0x14 * /
    //   }
    //   *counter_ptr = ((byte)*counter_ptr + 1) & 7;
    //   return 1;
    // UNRESOLVED: The skeleton fill claims this+0x1E4 is the restart counter, but the raw source addresses the counter only through a1[100]+84 (dereferenced this+0x190 plus 0x54). The fill's this+0x1E4 claim cannot be reconciled with the raw source from this packet alone
    // UNRESOLVED: Field this+0x28 (a limit/constant) appears in the packet field list but is never accessed by the raw source of this function
}
