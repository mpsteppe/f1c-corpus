// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587930
// Canonical corpus name: BufferCopyViaVirtualTypeDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferCopyViaVirtualTypeDispatch_00587930.c

void UnknownObject::BufferCopyViaVirtualTypeDispatch()
{
    // Parses a count-prefixed typed buffer into per-type handler objects. Iterates a3 entries of buffer a2. For each entry it fetches the handler via the vtable slot at offset 0x58 of the sub-struct at this+0x414 (this[261]), compares the entry type byte against the handler's expected type size ((field36>>3)+((field36&7)!=0)), copies the fixed-size entry data into the handler at offset 20 when they match, then reads a trailing length byte and copies that variable-length payload into the handler at offset 8 via MemcpyLikeWithRealloc, stamps the config value a4 at handler offset 4, and dispatches the handler through VTableDispatchWithConditionalBranch. Returns the last dispatch result (initialized to a3).
    // LOOP: Walk a3 entries of buffer a2; the cursor advances by each parsed entry's size and the loop terminates when it reaches a3. [source:raw]
    // CALL: Fetch the per-entry handler object by invoking the vtable slot at offset 0x58 on the sub-struct at this+0x414 (this[261]). [field:*(this+0x414):0x00000058, field:this:0x00000414, source:raw]
    // CALCULATION: Read the entry type byte at buffer position i and compute the handler's expected type size from its field at offset 36: (field36 >> 3) + ((field36 & 7) != 0). [source:raw]
    // GUARD: When the type byte equals the expected type size, copy the fixed-size entry data into the handler buffer at offset 20. [source:raw]
    // CALL: Read the variable-length payload length byte and copy that many bytes into the handler at offset 8 via MemcpyLikeWithRealloc. [callee:0x00587510, source:raw]
    // ASSIGNMENT: Store the configuration value a4 into the handler at offset 4. [source:raw]
    // CALL: Dispatch the built handler through VTableDispatchWithConditionalBranch on the sub-struct at this+0x414; its result is retained across iterations. [callee:0x00585400, field:this:0x00000414, source:raw]
    // CALCULATION: Advance the loop cursor by the parsed entry size (type byte + length byte + data length). [source:raw]
    // RETURN: Return the last dispatch result (initialized to a3); invoked by sub_584230 (00584230). [caller:0x00584230, source:raw]

    // Conservative worker pseudocode:
    //   // __thiscall parse of a count-prefixed typed buffer into per-type handler objects
    //   int result = a3;
    //   for (int i = 0; i < a3; ) {
    //       handler = vtable_call(this[261], slot 0x58)();  // fetch handler for entry type
    //       typeSize = (handler->field36 >> 3) + ((handler->field36 & 7) != 0);
    //       typeByte = a2[i];
    //       next = i + 1;
    //       if (typeByte == typeSize)
    //           memcpy(handler->field20, a2 + next, typeSize);
    //       lenByte = a2[typeByte + next];
    //       pos = typeByte + next + 1;
    //       MemcpyLikeWithRealloc(handler + 8, a2 + pos, lenByte);
    //       handler->field4 = a4;
    //       i = lenByte + pos;
    //       result = VTableDispatchWithConditionalBranch(this[261], handler);
    //   }
    //   return result;
    // UNRESOLVED: The concrete type of this[261] and the handler objects it returns is unknown; only the vtable slot at 0x58 and the per-entry contract are evidenced.
    // UNRESOLVED: The type-size encoding (field36 >> 3) + ((field36 & 7) != 0) and the buffer/field roles at handler offsets 4, 8, 20 and 36 are unverified.
    // UNRESOLVED: The intended semantic of a4 (written into every handler) is unknown.
}
