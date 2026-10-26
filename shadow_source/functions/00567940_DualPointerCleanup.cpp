// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567940
// Canonical corpus name: DualPointerCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualPointerCleanup_00567940.c

void UnknownObject::DualPointerCleanup()
{
    // Frees the two pointer members of a dual-pointer object. Reads and releases the pointer at byte offset 0x18 first (if non-null), then the pointer at byte offset 0x10 (if non-null), returning the result of the last FreeWrapper_7bcf call. Used as a node/tree cleanup helper by RecursiveTreeTraversalFree and sub_567CC0.
    // ASSIGNMENT: Read the pointer at byte offset 0x18 (this + 24) into the result register. [field:this:0x00000018, source:raw]
    // GUARD: If the pointer at byte offset 0x18 is non-null, free it with FreeWrapper_7bcf. [field:this:0x00000018, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Read the pointer at byte offset 0x10 (this + 16) into v3. [field:this:0x00000010, source:raw]
    // GUARD: If the pointer at byte offset 0x10 is non-null, free it with FreeWrapper_7bcf and return its result. [field:this:0x00000010, callee:0x00587BCF, source:raw]
    // RETURN: Otherwise return the earlier free result (previous FreeWrapper_7bcf result, or 0 when offset 0x18 was null). [function:0x00567940, source:raw]

    // Conservative worker pseudocode:
    //   void* result = this->field_0x18;
    //   if (result) result = FreeWrapper_7bcf(this->field_0x18);
    //   void* v3 = this->field_0x10;
    //   if (v3) return FreeWrapper_7bcf(v3);
    //   return result;
    // UNRESOLVED: Owner object and the meaning of the two pointer members (child/sub-object pairs) are not evidenced by this packet.
    // UNRESOLVED: Whether the two freed pointers share allocation ownership or one is borrowed is caller-specific and unresolved.
}
