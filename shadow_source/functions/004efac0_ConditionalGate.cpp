// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EFAC0
// Canonical corpus name: ConditionalGate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalGate_004efac0.c

void UnknownObject::ConditionalGate()
{
    // Conditional reset: reads this[3247] (this+0x32BC); if nonzero, sets this[3685] (this+0x3994) to 0; otherwise writes 0 to global byte_7C9081. Returns the read value. On the per-frame AI path and called from AI/state-reset functions.
    // ASSIGNMENT: result = this[3247], reading the field at this+0x32BC. [field:this:0x000032BC, source:raw]
    // GUARD: Branch on result (this+0x32BC value) being nonzero. [field:this:0x000032BC, source:raw]
    // ASSIGNMENT: If nonzero: this[3685] = 0, clearing the field at this+0x3994. [field:this:0x00003994, source:raw]
    // ASSIGNMENT: If zero: write 0 to global byte_7C9081. [source:raw]
    // RETURN: Return result (the this+0x32BC value). [source:raw]

    // Conservative worker pseudocode:
    //   result = this[3247];
    //   if (result)
    //     this[3685] = 0;
    //   else
    //     byte_7C9081 = 0;
    //   return result;
    // UNRESOLVED: Global dbl_7C7428 is listed as read (R) but does not appear in the raw source; its role here is unclear.
    // UNRESOLVED: Global byte_7C9081 (written on the false branch) has no packet field/global entry; it appears only in the raw source text.
    // UNRESOLVED: Interpretation of this+0x32BC as a rigid-body constraint pointer and the reset behavior as vehicle state management is DERIVED from the existing analysis, not proven by the packet.
}
