// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00535620
// Canonical corpus name: ArithmeticComparison_5620
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_5620_00535620.c

void UnknownObject::ResetContextStateWithCallback()
{
    // Per-frame context reset (thiscall). Rejects NULL `this` and a NULL context sub-pointer at this[7], otherwise zeroes three internal counters (this[2], this[5], this[6]), writes 7 or 0 into the first field of the object pointed to by this[7] based on that object's own field at offset 0xC, then calls StateResetWithCallback(0) and returns 0. On either NULL guard it returns -2 before any side effects.
    // GUARD: If `this` is NULL, return -2 immediately. [function:0x00535620, source:raw]
    // GUARD: Load v1 = this[7] (offset 0x1C); if v1 is NULL, return -2 immediately. [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Reset counter this[5] (offset 0x14) to 0. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Reset counter this[2] (offset 0x8) to 0. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Reset counter this[6] (offset 0x18) to 0. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Write through the sub-context pointer: *v1 = (v1[3] != 0) ? 7 : 0, i.e. the pointed object's field at offset 0xC receives 7 or 0. [field:this:0x0000001C, source:raw]
    // CALL: Invoke StateResetWithCallback(0) after the state fields are cleared. [callee:0x00537000, source:raw]
    // RETURN: Return 0 on the successful path. [function:0x00535620, source:raw]
    // CALL: Called by BufferedFileReader (00534f90), sub_5354E0 (005354e0) and sub_5356A0 (005356a0) to reset context state. [caller:0x00534F90, caller:0x005354E0, caller:0x005356A0, source:raw]

    // Conservative worker pseudocode:
    //   if (this == 0) return -2;
    //   v1 = this[7];
    //   if (v1 == 0) return -2;
    //   this[5] = 0; this[2] = 0; this[6] = 0;
    //   *v1 = (v1[3] != 0) ? 7 : 0;
    //   StateResetWithCallback(0);
    //   return 0;
    // UNRESOLVED: Packet guard facts describe a flag at this[10] (offset 0x28) as selecting the 7-versus-0 write value, but the raw source places the ternary on v1[3] (the pointed object's offset 0xC). Raw source is kept as primary; the 0x28 flag's role is unverified here.
    // UNRESOLVED: Semantics of the three zeroed counters and of the 7/0 initialization value depend on the enclosing file-I/O context, which this function does not reveal.
}
