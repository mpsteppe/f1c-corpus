// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491E40
// Canonical corpus name: sub_491E40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_491E40_00491e40.c

void UnknownObject::ConditionalDataFree()
{
    // Flag-gated object free. Reads a flag byte at this+0x8; when it is non-zero and the object pointer at this+0x0 is non-null, forwards that pointer to FreeWrapper_7bcf (00587BCF) to release it. Returns the low byte of the wrapper result (0 when not freed). Structural twin of the ConditionalDestructor_46f0 cluster (004646f0); called by ResourcePoolNodeAllocDealloc (00490940), sub_490D00, sub_57DE30 and sub_57E570.
    // GUARD: Reads the flag byte at this+0x8; when zero the free is skipped entirely [field:this:0x00000008, source:raw]
    // GUARD: When the flag is set, reads the object pointer at this+0x0 and only calls the free wrapper while that pointer is non-null [field:this:0x00000000, source:raw]
    // CALL: Calls FreeWrapper_7bcf (00587BCF) with the object pointer stored at this+0x0 to release the object [callee:0x00587BCF, field:this:0x00000000, source:raw]
    // RETURN: Returns a char: the low byte of the free-wrapper result when freed, otherwise 0 [field:this:0x00000008, source:raw]
    // CALL: Invoked by ResourcePoolNodeAllocDealloc (00490940), sub_490D00, sub_57DE30 and sub_57E570 as a shared conditional teardown helper [caller:0x00490940, caller:0x00490D00, caller:0x0057DE30, caller:0x0057E570, source:raw]

    // Conservative worker pseudocode:
    //   flag = this[0x8/1];
    //   if (flag) {
    //     ptr = this[0x0/4];
    //     if (ptr != NULL)
    //       flag = FreeWrapper_7bcf(ptr);
    //   }
    //   return flag;
    // UNRESOLVED: The return register reuses the flag variable for the wrapper result; whether the caller treats the returned char as a status or ignores it is not determinable from this packet
    // UNRESOLVED: The layout of the containing object around this+0x0 and this+0x8 is unknown; the object type is unnamed
}
