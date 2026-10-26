// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B1C20
// Canonical corpus name: sub_4B1C20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B1C20_004b1c20.c

void UnknownObject::ByteFieldSetterWithStrings()
{
    // Byte-field variant of the multi-field setter. Copies the string at a2 via StringCopyWithBufferRealloc, stores byte arguments into fields +0x15 (a3), +0x16 (a4) and +0x17 (a5), optionally copies the string at a6 when a6 is non-zero, and optionally stores a3 into byte field +0x14 when a7 is non-zero. Ends by returning ShortComputation_1b70(this). Called by PlayerOptionsInitializer (0x004AA270).
    // CALL: Copy the string at argument a2 via StringCopyWithBufferRealloc. [callee:0x00566650, source:raw]
    // ASSIGNMENT: Store byte argument a3 into field +0x15. [field:this:0x00000015]
    // ASSIGNMENT: Store byte argument a4 into field +0x16. [field:this:0x00000016]
    // ASSIGNMENT: Store byte argument a5 into field +0x17. [field:this:0x00000017]
    // GUARD: Guard on argument a6: when non-zero, copy the string at a6. [source:raw]
    // CALL: Conditional copy of the string at a6 via StringCopyWithBufferRealloc. [callee:0x00566650]
    // GUARD: Guard on argument a7: when non-zero, store a3 into field +0x14. [source:raw]
    // ASSIGNMENT: Conditionally store argument a3 into byte field +0x14. [field:this:0x00000014]
    // RETURN: Return ShortComputation_1b70(this) as the final step. [callee:0x004A1B70, source:raw]

    // Conservative worker pseudocode:
    //   void *sub_4B1C20(void *this, int a2, char a3, char a4, char a5, int a6, char a7) {
    //     StringCopyWithBufferRealloc(a2);
    //     this[21] = a3;
    //     this[22] = a4;
    //     this[23] = a5;
    //     if (a6) StringCopyWithBufferRealloc(a6);
    //     if (a7) this[20] = a3;
    //     return ShortComputation_1b70(this);
    //   }
    // UNRESOLVED: Identity of the object; called from PlayerOptionsInitializer (0x004AA270).
    // UNRESOLVED: Role of the string copies and of the byte fields +0x14/+0x15/+0x16/+0x17 is unknown.
    // UNRESOLVED: Field-to-argument correspondence is derived from the decompiled source, which the packet does not map semantically.
}
