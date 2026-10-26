// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A5E80
// Canonical corpus name: ObjectStateClear
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectStateClear_004a5e80.c

void UnknownObject::ObjectStateClear()
{
    // Clears the dword state at this+0x184 and the byte flag at this+0x180 to 0, then calls a routine on the sub-object pointer at this+0x14 if it is non-null. Returns the sub-object call's result, or 0 when the pointer is null. Inverse of the state-phase setter that writes state 4 and flag 1.
    // ASSIGNMENT: Write 0 to the dword state field at this+0x184. [field:this:0x00000184]
    // ASSIGNMENT: Write 0 to the byte flag at this+0x180. [field:this:0x00000180]
    // GUARD: Read sub-object pointer at this+0x14; if non-null proceed to call on it, otherwise skip the call and return 0. [field:this:0x00000014]
    // CALL: Call the routine on the sub-object pointer at this+0x14 (hex-rays label ShortComputation_3fe0) and return its result. [source:raw, field:this:0x00000014]
    // RETURN: Return result: the sub-object call's return value, or 0 when the pointer at this+0x14 is null. [source:raw]

    // Conservative worker pseudocode:
    //   this->stateDword = 0;
    //   this->flagByte = 0;
    //   if (this->subObject != 0) {
    //     return subObjectRoutine(this->subObject);
    //   }
    //   return 0;
    // UNRESOLVED: The callee invoked on the pointer at this+0x14 is labeled ShortComputation_3fe0 in the raw source but has no callee evidence ref in the packet, so its address is not asserted.
    // UNRESOLVED: The semantic roles of the cleared dword (this+0x184) and byte flag (this+0x180) are not independently confirmed beyond the raw source.
    // UNRESOLVED: The caller relationship from sub_4C6B60 (0x004C6B60) is noted in the packet but not examined here.
}
