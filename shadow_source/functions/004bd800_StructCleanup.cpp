// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BD800
// Canonical corpus name: StructCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructCleanup_004bd800.c

void UnknownObject::StructCleanup()
{
    // Struct teardown: frees up to three owned heap pointers (this[2], this[5], this[8]) through FreeWrapper_7bcf, each guarded by a non-null check with the pointer captured before its slot is cleared, then zeroes all nine pointer fields this[0..8]. Returns the last FreeWrapper_7bcf result, or null when nothing was freed.
    // GUARD: Guard on this[2] being non-null before freeing it. [field:this:0x00000008, source:raw]
    // CALL: Free this[2] via FreeWrapper_7bcf when non-null. [callee:0x00587BCF, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Capture this[5] into v2 before its slot is cleared. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Clear this[2], this[0] and this[1] to 0. [field:this:0x00000008, field:this:0x00000000, field:this:0x00000004, source:raw]
    // GUARD: Guard on the captured v2 (former this[5]) being non-null before freeing it. [field:this:0x00000014, source:raw]
    // CALL: Free v2 (former this[5]) via FreeWrapper_7bcf when non-null. [callee:0x00587BCF, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Capture this[8] into result before its slot is cleared. [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Clear this[5], this[3] and this[4] to 0. [field:this:0x00000014, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // GUARD: Guard on the captured result (former this[8]) being non-null before freeing it. [field:this:0x00000020, source:raw]
    // CALL: Free result (former this[8]) via FreeWrapper_7bcf when non-null; the result is stored back as the return value. [callee:0x00587BCF, field:this:0x00000020, source:raw]
    // ASSIGNMENT: Clear this[8], this[6] and this[7] to 0. [field:this:0x00000020, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // RETURN: Return the last FreeWrapper_7bcf result, or null when no pointer was freed. [source:raw]
    // CALL: Called from 0x004BD7D0 and 0x004BDDE0 during their cleanup paths. [caller:0x004BD7D0, caller:0x004BDDE0, source:raw]

    // Conservative worker pseudocode:
    //   void *sub_4BD800(void **this) {
    //     if (this[2]) FreeWrapper_7bcf(this[2]);
    //     void *v2 = this[5];
    //     this[2] = 0; this[0] = 0; this[1] = 0;
    //     if (v2) FreeWrapper_7bcf(v2);
    //     void *result = this[8];
    //     this[5] = 0; this[3] = 0; this[4] = 0;
    //     if (result) result = (void *)FreeWrapper_7bcf(result);
    //     this[8] = 0; this[6] = 0; this[7] = 0;
    //     return result;
    //   }
    // UNRESOLVED: Identity and layout of the owning struct, and the meaning of the nine fields this[0..8], are unknown.
    // UNRESOLVED: The packet prelabel suggests ctor_init but the raw source shows frees and clears, so the raw source governs; the prelabel category is considered unreliable.
    // UNRESOLVED: The caller-side use of the returned free result is unknown.
}
