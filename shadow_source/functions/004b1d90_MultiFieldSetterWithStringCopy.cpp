// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B1D90
// Canonical corpus name: MultiFieldSetterWithStringCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiFieldSetterWithStringCopy_004b1d90.c

void UnknownObject::MultiFieldSetterWithStringCopy()
{
    // Structural twin of MultiFieldSetterWithStrings (packet 004b1ac0) with the same field set but a different write order. Copies the string at a2 via StringCopyWithBufferRealloc, stores integer arguments into fields +0x20 (a5), +0x18 (a3) and +0x1C (a4), optionally copies the string at a6 when a6 is non-zero, and optionally stores a3 into field +0x14 when a7 is non-zero. Ends by returning ShortComputation_1b70(this). Called by PlayerOptionsInitializer (0x004AA270).
    // CALL: Copy the string at argument a2 via StringCopyWithBufferRealloc. [callee:0x00566650, source:raw]
    // ASSIGNMENT: Store integer argument a5 into field +0x20. [field:this:0x00000020]
    // ASSIGNMENT: Store integer argument a3 into field +0x18. [field:this:0x00000018]
    // ASSIGNMENT: Store integer argument a4 into field +0x1C. [field:this:0x0000001C]
    // GUARD: Guard on argument a6: when non-zero, copy the string at a6. [source:raw]
    // CALL: Conditional copy of the string at a6 via StringCopyWithBufferRealloc. [callee:0x00566650]
    // GUARD: Guard on argument a7: when non-zero, reassign field +0x14 from a3. [source:raw]
    // ASSIGNMENT: Conditionally store argument a3 into field +0x14. [field:this:0x00000014]
    // RETURN: Return ShortComputation_1b70(this) as the final step. [callee:0x004A1B70, source:raw]

    // Conservative worker pseudocode:
    //   void *sub_4B1D90(void *this, int a2, int a3, int a4, int a5, int a6, char a7) {
    //     StringCopyWithBufferRealloc(a2);
    //     this[8] = a5;
    //     this[6] = a3;
    //     this[7] = a4;
    //     if (a6) StringCopyWithBufferRealloc(a6);
    //     if (a7) this[5] = a3;
    //     return ShortComputation_1b70(this);
    //   }
    // UNRESOLVED: Identity of the object; called from PlayerOptionsInitializer (0x004AA270).
    // UNRESOLVED: Role of the string copies and of the integer fields +0x14/+0x18/+0x1C/+0x20 is unknown.
    // UNRESOLVED: Field-to-argument correspondence is derived from the decompiled source, which the packet does not map semantically.
    // UNRESOLVED: Cluster-copy note marks this as a structural twin of packet 004b1ac0 (DERIVED); divergence in write order is the only observed difference.
}
