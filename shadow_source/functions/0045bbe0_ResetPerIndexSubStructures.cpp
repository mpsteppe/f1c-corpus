// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045BBE0
// Canonical corpus name: DoubleDelegateCall_bbe0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoubleDelegateCall_bbe0_0045bbe0.c

void UnknownObject::ResetPerIndexSubStructures()
{
    // Post-init helper for a UI render object: calls sub_45B950, dereferences the object pointer stored at this+0x0, clears the dword at object offset 0x31C to zero, then loops exactly 8 times resetting the per-index sub-structures. Returns the result of the last per-index reset call. Called by OnScreen_Init during UI render object setup.
    // CALL: Call sub_45B950 (audio collision configuration helper) unconditionally before touching the object. [callee:0x0045B950, source:raw]
    // ASSIGNMENT: Dereference this+0x0 to obtain the object pointer v4 that the remaining operations act on. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Clear the dword at object offset 0x31C (v4[199]) to 0 as part of post-init. [field:obj:0x0000031C, source:raw]
    // LOOP: do-while loop with index v1 starting at 0, running while v1 < 8, i.e. exactly 8 iterations over per-index sub-structures. [source:raw]
    // CALL: Call the per-index struct field resetter on v4 for the current index, capturing its return value as result. [source:raw]
    // RETURN: Return the result of the last per-index resetter call. [source:raw]
    // CALL: Called by OnScreen_Init (0x0049EFA0) as part of UI render object post-initialization. [caller:0x0049EFA0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_45BBE0(void* this) {
    //     sub_45B950();
    //     _DWORD* v4 = *(_DWORD**)this;
    //     v4[199] = 0;
    //     int result;
    //     for (int v1 = 0; v1 < 8; ++v1)
    //       result = PerIndexStructFieldResetter(v4, v1);
    //     return result;
    //   }
    // UNRESOLVED: PerIndexStructFieldResetter appears in the raw source text but has no callee address in the deterministic packet; its target address is unknown.
    // UNRESOLVED: Semantic meaning of the cleared dword at offset 0x31C and of the 8 per-index sub-structures is not established here.
    // UNRESOLVED: The object type owning this method is unknown (owner left UNKNOWN).
}
