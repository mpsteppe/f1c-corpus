// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A1B0
// Canonical corpus name: MemcpyWithAdvancePointer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemcpyWithAdvancePointer_0057a1b0.c

void UnknownObject::MemcpyWithAdvancePointer()
{
    // stdcall helper that copies a3 bytes from the buffer chunk pointed to by *a1 into a2, then advances the stored cursor *a1 by a3 and returns the original descriptor pointer a1. Called by StructFieldSerializerPacker (0x0057A330), so it consumes a serialized field chunk while keeping the read cursor moving.
    // ASSIGNMENT: Save the original descriptor: result = a1. [source:raw]
    // CALL: Copy the chunk: qmemcpy(a2, *a1, a3) reads the cursor stored in the this:0x0 field and writes a3 bytes into a2. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Advance the cursor: *a1 = (char *)*a1 + a3, rewriting the this:0x0 pointer forward by a3 bytes. [field:this:0x00000000, source:raw]
    // RETURN: Return the saved descriptor result (the original a1). [function:0x0057A1B0, source:raw]

    // Conservative worker pseudocode:
    //   const void **MemcpyWithAdvancePointer(const void **a1, void *a2, unsigned int a3) {
    //     const void **result = a1;
    //     qmemcpy(a2, *a1, a3);
    //     *a1 = (const char *)*a1 + a3;
    //     return result;
    //   }
    // UNRESOLVED: The object that owns the this:0x0 read-cursor field is unidentified; owner left UNKNOWN.
    // UNRESOLVED: Caller StructFieldSerializerPacker (0x0057A330) confirms a serialization context, but the descriptor field layout beyond the cursor is not established.
}
