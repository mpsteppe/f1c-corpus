// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00541420
// Canonical corpus name: SubBufferFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SubBufferFree_00541420.c

void UnknownObject::SubBufferFree()
{
    // Frees a sub-buffer descriptor owned by the object: when this[1107] (this+0x114C) is non-null, resets the base allocation and the allocation plus 36 via ObjectResetWithVirtualRelease, frees the descriptor memory itself with FreeWrapper_7bcf at pointer-minus-4, and nulls the field. Returns the last freed or read pointer. Called by sub_544740 (00544740) and AudioNetworkStreamCleanup (00544AF0).
    // ASSIGNMENT: result = this[1107] reads the sub-buffer descriptor pointer at this+0x114C [field:this:0x0000114C, source:raw]
    // GUARD: If the sub-buffer pointer is null, skip all release work and return it [field:this:0x0000114C, source:raw]
    // CALL: ObjectResetWithVirtualRelease(this, this[1107]) resets the base sub-buffer allocation [callee:0x00540EB0, source:raw]
    // CALL: ObjectResetWithVirtualRelease(this, this[1107] + 36) resets the second sub-object at the base allocation plus 36 bytes [callee:0x00540EB0, source:raw]
    // GUARD: If the pointer is still non-null, FreeWrapper_7bcf frees the descriptor at pointer-minus-4 and stores the result [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: this[1107] = 0 nulls the sub-buffer field after the release sequence [field:this:0x0000114C, source:raw]
    // RETURN: Returns result: the original pointer when the field was null, otherwise the FreeWrapper_7bcf result [function:0x00541420, source:raw]
    // CALL: Invoked by sub_544740 (00544740) and AudioNetworkStreamCleanup (00544AF0) as the shared sub-buffer teardown [caller:0x00544740, caller:0x00544AF0, source:raw]

    // Conservative worker pseudocode:
    //   result = this[1107];
    //   if (result) {
    //     ObjectResetWithVirtualRelease(this, this[1107]);
    //     ObjectResetWithVirtualRelease(this, this[1107] + 36);
    //     result = this[1107];
    //     if (result) result = FreeWrapper_7bcf((LPVOID)(result - 4));
    //     this[1107] = 0;
    //   }
    //   return result;
    // UNRESOLVED: The sub-buffer descriptor layout at this+0x114C (including why the free base is pointer-minus-4) is not defined in this packet
    // UNRESOLVED: What the two ObjectResetWithVirtualRelease targets at +0 and +36 represent is inferred only from the sibling call pattern
    // UNRESOLVED: The return value of ObjectResetWithVirtualRelease is ignored; whether its own teardown can invalidate the pointer read back at this[1107] is unverifiable here
}
