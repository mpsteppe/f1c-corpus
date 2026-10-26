// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005439F0
// Canonical corpus name: ShortFieldAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortFieldAccessor_005439f0.c

void UnknownObject::ShortFieldAccessor()
{
    // Reads three 16-bit fields of the receiver (offsets 0x188, 0x18A, 0x18C) and stores each into a caller-provided output pointer, writing only when that pointer is non-null. Returns the fourth argument pointer regardless of null.
    // GUARD: Write to *a2 is blocked when a2 is NULL [source:raw]
    // ASSIGNMENT: When a2 is non-null, store the 16-bit value at this+0x18C into *a2 [field:this:0x0000018C, source:raw]
    // ASSIGNMENT: When a3 is non-null, store the 16-bit value at this+0x18A into *a3 [field:this:0x0000018A, source:raw]
    // GUARD: Write to *a4 is blocked when a4 is NULL; result is set to a4 before the check [source:raw]
    // ASSIGNMENT: When a4 is non-null, store the 16-bit value at this+0x188 into *a4 [field:this:0x00000188, source:raw]
    // RETURN: Return a4 (the fourth argument) whether or not the write took place [source:raw, function:0x005439F0]
    // CALL: Invoked by sub_4FCAA0 (004FCAA0) [caller:0x004FCAA0]

    // Conservative worker pseudocode:
    //   if (a2) *a2 = (short)this[198];   /* +0x18C * /
    //   if (a3) *a3 = (short)this[197];   /* +0x18A * /
    //   result = a4;
    //   if (a4) *a4 = (short)this[196];   /* +0x188 * /
    //   return result;
    // UNRESOLVED: The semantic meaning of the three 16-bit fields (0x188, 0x18A, 0x18C) as UI position components comes from the existing-analysis fill and is not independently grounded in this packet.
}
