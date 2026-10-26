// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A180
// Canonical corpus name: DwordAlignedMemoryCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DwordAlignedMemoryCopy_0057a180.c

void UnknownObject::DwordAlignedMemoryCopy()
{
    // Buffer-cursor memory copy: copies a3 bytes from a2 into the buffer whose current cursor is stored at this+0, advances that cursor by a3, and returns the original this pointer. The caller passes a pointer to the cursor, so the function both fills and advances the destination buffer in one call. Used by StructFieldSerialization (0x0057A270).
    // ASSIGNMENT: Save the original this pointer into result before any mutation. [source:raw]
    // CALL: qmemcpy(*a1, a2, a3): copy a3 bytes from source a2 into the destination buffer whose cursor is stored at this+0 (read of this+0). [field:this:0x00000000, source:raw]
    // CALCULATION: Advance the buffer cursor: *a1 = (char *)*a1 + a3, writing the new cursor back to this+0. [field:this:0x00000000, source:raw]
    // RETURN: Return the original this pointer (the saved result), not the advanced cursor. [source:raw, function:0x0057A180]

    // Conservative worker pseudocode:
    //   void **sub_57A180(void **a1, const void *a2, unsigned int a3) {
    //     void **result = a1;
    //     memcpy(*a1, a2, a3);
    //     *a1 = (char *)*a1 + a3;
    //     return result;
    //   }
    // UNRESOLVED: qmemcpy is a compiler builtin; its expansion has no call-target evidence in the packet.
    // UNRESOLVED: The owner object holding the cursor at this+0 is unknown; the function mutates a caller-provided cursor rather than an object field.
    // UNRESOLVED: Byte-count a3 is not validated against the destination buffer size here; overflow safety is the caller's responsibility.
}
