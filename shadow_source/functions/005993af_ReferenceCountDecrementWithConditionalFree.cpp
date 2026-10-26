// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005993AF
// Canonical corpus name: ReferenceCountDecrementWithConditionalFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ReferenceCountDecrementWithConditionalFree_005993af.c

void UnknownObject::ReferenceCountDecrementWithConditionalFree()
{
    // Reference-counted release helper used by exception and locale teardown paths. When the a2 flag is set, it decrements the byte refcount stored just before this[1]; if the count reaches 0 or the -1 sentinel, it frees the block via FreeWrapper_7bcf instead of decrementing. It then clears this[1], this[2] and this[3] to zero unconditionally.
    // GUARD: Release logic only proceeds when the a2 flag is non-zero. [source:raw]
    // ASSIGNMENT: Read the data pointer v3 from this[1]. [field:this:0x00000004]
    // GUARD: Skip the refcount logic entirely when this[1] is null. [source:raw]
    // CALCULATION: Compute the refcount byte address v4 = this[1] - 1 and read v5 = *v4, the byte preceding the data block. [field:this:0x00000004]
    // GUARD: If the refcount byte is 0 or the -1 sentinel, the block must be released. [source:raw]
    // CALL: Free the block at v4 via FreeWrapper_7bcf(v4). [callee:0x00587BCF]
    // CALCULATION: Otherwise write back the decremented count: *v4 = v5 - 1. [source:raw]
    // ASSIGNMENT: Clear this[1] to 0 after release. [field:this:0x00000004]
    // ASSIGNMENT: Clear this[2] to 0 after release. [field:this:0x00000008]
    // ASSIGNMENT: Clear this[3] to 0 after release. [field:this:0x0000000C]

    // Conservative worker pseudocode:
    //   void sub_5993AF(this, char flag) {
    //     if (flag && this[1]) {
    //       byte *p = (byte *)(this[1] - 1);
    //       if (!*p || *p == -1) FreeWrapper_7bcf(p);
    //       else *p = *p - 1;
    //     }
    //     this[1] = 0; this[2] = 0; this[3] = 0;
    //   }
    // UNRESOLVED: Owning class is unknown; the callers are exception/locale destructor and constructor functions in the same module range, suggesting a shared refcounted-buffer wrapper, but no class evidence exists.
    // UNRESOLVED: Whether the refcount header is allocated together with the data block or separately is not visible in this function.
}
