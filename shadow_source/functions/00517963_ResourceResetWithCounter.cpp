// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00517963
// Canonical corpus name: ResourceResetWithCounter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceResetWithCounter_00517963.c

void UnknownObject::ResourceResetWithCounter()
{
    // Resource-state reset with early-out guards. Returns -2 if the object pointer a1 is null, or if the sub-object pointer stored at this+0x1C is null. Otherwise clears three state fields (this+0x8, this+0x14, this+0x18) to 0, writes the sub-object's first dword to 7 or 0 depending on the sub-object condition field at this+0x28, and calls sub_52765A with the sub-object data pointer read at this+0x30, a1 and 0. Returns 0 on success. Called by sub_5179E0 (005179E0) and sub_519019 (00519019).
    // GUARD: Early-out: if a1 (this) is null the function returns -2; packet records the null-check guard [guard:0, source:raw]
    // GUARD: Early-out: load sub-object pointer from this+0x1C; if it is null the function returns -2 (packet guard offset 0x28 maps to this null-check on the pointer read at this+0x1C) [guard:0, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Reset the state counters to 0: this+0x14, this+0x8 and this+0x18 are cleared (write order per raw source) [field:this:0x00000014, field:this:0x00000008, field:this:0x00000018, source:raw]
    // ASSIGNMENT: Set the sub-object first dword (reached through this+0x1C) to 7 when the sub-object condition field at this+0x28 is non-zero, otherwise to 0 [field:this:0x0000001C, field:this:0x00000028, source:raw]
    // CALL: Call sub_52765A with the sub-object data pointer read at this+0x30, the resource object a1, and literal 0 as arguments [callee:0x0052765A, field:this:0x00000030, source:raw]
    // RETURN: Return 0 on the success path (or -2 from either guard); invoked by sub_5179E0 (005179E0) and sub_519019 (00519019) [function:0x00517963, caller:0x005179E0, caller:0x00519019, source:raw]

    // Conservative worker pseudocode:
    //   if (!a1) return -2;
    //   v1 = *(this + 0x1C);
    //   if (!v1) return -2;
    //   *(this + 0x14) = 0;
    //   *(this + 0x8) = 0;
    //   *(this + 0x18) = 0;
    //   *v1 = (v1[3] != 0) ? 7 : 0;
    //   sub_52765A(*(this + 0x30), a1, 0);
    //   return 0;
    // UNRESOLVED: The packet guard entry is recorded at this+0x28, but the raw source null-check operates on the sub-object pointer stored at this+0x1C; the packet offset appears to reach the sub-object condition field (read at this+0x28 for the 7/0 selection) rather than the guard, so the guard's recorded offset is ambiguous
    // UNRESOLVED: The semantics of sub_52765A's reset behavior and the meaning of the 7/0 counter value are not documented in this packet
    // UNRESOLVED: Field access at this+0x1C is recorded as RW (the write is through the sub-object pointer, not to the pointer slot itself)
}
