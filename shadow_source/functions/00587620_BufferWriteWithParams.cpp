// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587620
// Canonical corpus name: BufferWriteWithParams
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferWriteWithParams_00587620.c

void UnknownObject::BufferWriteWithParams()
{
    // Buffer write helper: copies the payload described by parameter object a2 into the destination buffer `this`. a2 carries a pointer to the source data at +0 and the byte count at +8. The copy is performed by MemcpyLikeWithRealloc(this, *(const void**)a2, *(_DWORD*)(a2+8)), which grows/reallocates the destination buffer as needed. The function returns `this` to allow chaining. Callers are NetworkBufferSearch (0x00581600), ShortComputation_6e50 (0x00586E50) and CopyBufferHeaderFieldsCallInit (0x00587370). ABI lead name Buffer_Write_with_Params.
    // CALL: Call MemcpyLikeWithRealloc((int)this, *(const void**)a2, *(_DWORD*)(a2+8)): copy a2's source pointer and byte count into destination buffer this, reallocating it when the capacity is insufficient. [callee:0x00587510, source:raw]
    // RETURN: Return `this`, the destination buffer pointer, enabling call chaining. [function:0x00587620, source:raw]

    // Conservative worker pseudocode:
    //   void *BufferWriteWithParams(void *this, const int *a2) {
    //       MemcpyLikeWithRealloc((int)this, *(const void **)a2, *(_DWORD *)(a2 + 8));
    //       return this;
    //   }
    // UNRESOLVED: The layout of the parameter object a2 (source pointer at +0, byte count at +8) is evident only from the single dereference; it is not declared as a packet field, so no struct-level contract is claimed.
    // UNRESOLVED: The copy semantics of MemcpyLikeWithRealloc (exact realloc trigger, ownership of the source) are not in this packet.
}
