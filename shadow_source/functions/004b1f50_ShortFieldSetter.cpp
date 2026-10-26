// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B1F50
// Canonical corpus name: ShortFieldSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortFieldSetter_004b1f50.c

void UnknownObject::ShortFieldSetter()
{
    // Short-field setter: copies string a2 into the object, writes three short fields at +0x16/+0x18/+0x1A from a3/a4/a5, conditionally copies string a6 when non-zero, and conditionally copies a3 into the short field at +0x14 when the flag a7 is non-zero. Ends by calling ShortComputation_1b70 on this and returning its result. Called from PlayerOptionsInitializer (004aa270).
    // CALL: Copy the string at a2 into the object's string buffer via StringCopyWithBufferRealloc. [callee:0x00566650]
    // ASSIGNMENT: Write short value a3 into the field at offset +0x16. [field:this:0x00000016]
    // ASSIGNMENT: Write short value a4 into the field at offset +0x18. [field:this:0x00000018]
    // ASSIGNMENT: Write short value a5 into the field at offset +0x1A. [field:this:0x0000001A]
    // GUARD: Guard on a6 being non-zero; only then copy the string at a6 via StringCopyWithBufferRealloc. [source:raw]
    // CALL: Conditional second string copy of a6 into the object's string buffer. [callee:0x00566650]
    // GUARD: Guard on flag a7 being non-zero; only then write the field at offset +0x14. [source:raw]
    // ASSIGNMENT: Conditionally copy short value a3 into the field at offset +0x14. [field:this:0x00000014]
    // CALL: Finalize: call ShortComputation_1b70(this) after all field assignments. [callee:0x004A1B70]
    // RETURN: Return the result of ShortComputation_1b70. [source:raw]

    // Conservative worker pseudocode:
    //   void* ShortFieldSetter(short* this, char* s1, short v1, short v2, short v3, char* s2, char flag) {
    //     StringCopyWithBufferRealloc(s1);
    //     this[11] = v1;  // +0x16
    //     this[12] = v2;  // +0x18
    //     this[13] = v3;  // +0x1A
    //     if (s2) StringCopyWithBufferRealloc(s2);
    //     if (flag) this[10] = v1;  // +0x14
    //     return ShortComputation_1b70(this);
    //   }
    // UNRESOLVED: Semantic identity of the three short fields (+0x16/+0x18/+0x1A) and the conditional +0x14 field is not evidenced in the packet.
    // UNRESOLVED: The packet guard table is empty; the a6/a7 guards are synthesized from the raw source and carry source:raw trust only.
    // UNRESOLVED: a2 and a6 string-copy targets are the same buffer-owning object but the buffer location is not exposed in the packet.
}
