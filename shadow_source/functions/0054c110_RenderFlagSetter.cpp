// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054C110
// Canonical corpus name: RenderFlagSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RenderFlagSetter_0054c110.c

void UnknownObject::RenderFlagSetter()
{
    // Selects a render flag mode from the a3 flag mask and records the incoming value a2 into one of two render value fields on the object: bit 0x800 stores a2 at +0x234 and ORs 0x800 into the accumulated flags word at +0x3C; bit 0x1000 stores a2 at +0x238 and ORs 0x1000 into the flags word at +0x3C. Returns a3 unchanged when neither flag bit is set.
    // ASSIGNMENT: result is initialized to a3 (the render flag mask). [source:raw]
    // GUARD: When bit 0x800 of a3 is set the 0x800 branch runs; otherwise the 0x1000 branch is tested next. [source:raw]
    // ASSIGNMENT: 0x800 branch: stores the value a2 into the render value field at +0x234 (this[141]). [field:this:0x00000234, source:raw]
    // CALCULATION: 0x800 branch: ORs bit 0x800 into the accumulated render flags word at +0x3C (this[15]) and sets result to a2. [field:this:0x0000003C, source:raw]
    // GUARD: When bit 0x1000 of a3 is set (and 0x800 was not) the 0x1000 branch runs. [source:raw]
    // ASSIGNMENT: 0x1000 branch: stores the value a2 into the render value field at +0x238 (this[142]). [field:this:0x00000238, source:raw]
    // CALCULATION: 0x1000 branch: result becomes the flags word at +0x3C (this[15]) ORed with 0x1000, and that combined value is written back into the flags word. [field:this:0x0000003C, source:raw]
    // RETURN: Returns result: a3 unchanged when neither flag bit is set, a2 in the 0x800 branch, and the ORed flags word in the 0x1000 branch. [source:raw]

    // Conservative worker pseudocode:
    //   result = a3;
    //   if (a3 & 0x800) { this[141] = a2; this[15] |= 0x800; result = a2; }
    //   else if (a3 & 0x1000) { this[142] = a2; result = this[15] | 0x1000; this[15] = result; }
    //   return result;
    // UNRESOLVED: The caller-side meaning of the flag bits 0x800 and 0x1000 and of the two render value fields at +0x234 and +0x238 is not resolved from this function alone.
    // UNRESOLVED: The two branches return differently (a2 vs the ORed flags word), so the return value differs between flag modes; the consumer of that difference is not visible here.
    // UNRESOLVED: The flags word at +0x3C is accumulated by OR only; this function never clears it.
}
