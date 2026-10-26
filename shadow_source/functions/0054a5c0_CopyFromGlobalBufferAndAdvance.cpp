// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054A5C0
// Canonical corpus name: ArithmeticComparison_a5c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_a5c0_0054a5c0.c

void UnknownObject::CopyFromGlobalBufferAndAdvance()
{
    // Copies a3 bytes from the global byte cursor dword_8B8F3C at offset a2 into the destination buffer a1, then advances the cursor by a3 and returns the copied byte count a3. The four callers are rendering/resource loaders (DirectXMeshVertexBufferParsingAndLoading, D3DTextureResourceCreation, sub_54AC70, MeshVertexIndexBufferLoader), consistent with a shared stream/buffer reader, but that role is not proven by this packet.
    // CALCULATION: Compute the source address as a2 + dword_8B8F3C, treating a2 as a byte offset into the global cursor dword_8B8F3C. [global:0x008B8F3C, source:raw]
    // CALL: Copy a3 bytes from (a2 + dword_8B8F3C) into a1 via an intrinsic memcpy (qmemcpy). [function:0x0054A5C0, global:0x008B8F3C, source:raw]
    // ASSIGNMENT: Advance the global cursor: dword_8B8F3C += a3. [global:0x008B8F3C, source:raw]
    // RETURN: Return a3, the number of bytes copied. [source:raw]

    // Conservative worker pseudocode:
    //   unsigned int result = byte_count;
    //   memcpy(dst, (const void *)(offset + source_cursor), byte_count);
    //   source_cursor += byte_count;
    //   return result;
    // UNRESOLVED: The size, allocation and lifetime of the global buffer behind 0x008B8F3C are unknown; a3 is caller-supplied with no bounds check against the buffer.
    // UNRESOLVED: The meaning of the a2 offset (relative read position vs. sub-stream selector) is not established by this packet.
    // UNRESOLVED: Owner object and invocation context are unknown; the rendering/resource caller names are suggestive only.
    // UNRESOLVED: The ABI lead name is LEGACY trust and not independently verified.
}
