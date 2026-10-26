// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005356A0
// Canonical corpus name: sub_5356A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5356A0_005356a0.c

void UnknownObject::InitializeDecompressionStream()
{
    // Initializes a stream/compression context a1. Validates the version argument a3 (non-null, first byte equal to a113_0[0], a4 == 56), resets the context flag this+0x18, installs default allocator and deallocator callbacks (DelegationWrapper_6fd0 / AllocatorFreeWrapper) when absent, and allocates a 24-byte work block via the allocator callback. Handles a negative block-size exponent a2 by negating it and setting the negation flag, rejects exponents outside 8..15 (GuardedFunctionCallCleanup and -2), stores the exponent in the block, and allocates the 1 << a2 byte multi-block via MultiBlockAllocator (with zero-initializer sub_537D10 when the negation flag is clear). On success calls ArithmeticComparison_5620 and returns 0; on allocation failure cleans up and returns -4.
    // GUARD: Validate the version argument a3: non-null, first byte equal to a113_0[0] (global 0x005DA7A0), and a4 == 56; on failure return -6. [global:0x005DA7A0, function:0x005356A0, source:raw]
    // GUARD: Return -2 when the context pointer a1 is null. [source:raw]
    // ASSIGNMENT: Reset the context flag a1[6] (this+0x18) to 0. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: If the allocator callback a1[8] (this+0x20) is null, install DelegationWrapper_6fd0 (global 0x00536FD0) and clear the allocator context a1[10] (this+0x28). [field:this:0x00000020, field:this:0x00000028, global:0x00536FD0, source:raw]
    // ASSIGNMENT: If the deallocator callback a1[9] (this+0x24) is null, install AllocatorFreeWrapper (global 0x00536FF0). [field:this:0x00000024, global:0x00536FF0, source:raw]
    // CALL: Invoke the allocator callback with (context a1[10], 1, 24) and store the returned work-block pointer in a1[7] (this+0x1C). [field:this:0x0000001C, field:this:0x00000020, source:raw]
    // GUARD: Return -4 when the work-block allocation failed (a1[7] null). [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Initialize the work block: clear the dword at block+20 (flattened as this+0x30) and the dword at block+12 (flattened as this+0x28). [field:this:0x00000030, field:this:0x00000028, source:raw]
    // STATE_TRANSITION: When the block-size exponent a2 is negative, negate it and set the negation flag *(block+12) (flattened as this+0x28) to 1. [field:this:0x00000028, guard:0, source:raw]
    // GUARD: Reject an invalid block-size exponent: if a2 < 8 or a2 > 15, run GuardedFunctionCallCleanup (callee 0x00535660) and return -2. [callee:0x00535660, source:raw]
    // ASSIGNMENT: Store the block-size exponent a2 at *(block+16) (flattened as this+0x2C). [field:this:0x0000002C, source:raw]
    // CALL: Allocate the 1 << a2 byte multi-block via MultiBlockAllocator (callee 0x00537070) with (a1, sub_537D10 (global 0x00537D10) when the negation flag at block+12 is 0 else 0, 1 << a2); store the result at *(block+20) (flattened as this+0x30). [callee:0x00537070, global:0x00537D10, field:this:0x00000030, guard:0, source:raw]
    // GUARD: On successful buffer allocation, call ArithmeticComparison_5620 (callee 0x00535620) and return 0; otherwise run GuardedFunctionCallCleanup (callee 0x00535660) and return -4. [callee:0x00535620, callee:0x00535660, source:raw]

    // Conservative worker pseudocode:
    //   int sub_5356A0(_DWORD *a1, int a2, _BYTE *a3, int a4) {
    //     if (!a3 || *a3 != a113_0[0] || a4 != 56) return -6;
    //     if (!a1) return -2;
    //     a1[6] = 0;
    //     if (!a1[8]) { a1[8] = DelegationWrapper_6fd0; a1[10] = 0; }
    //     if (!a1[9]) a1[9] = AllocatorFreeWrapper;
    //     a1[7] = a1[8](a1[10], 1, 24);
    //     if (!a1[7]) return -4;
    //     *(a1[7]+20) = 0; *(a1[7]+12) = 0;
    //     if (a2 < 0) { a2 = -a2; *(a1[7]+12) = 1; }
    //     if (a2 < 8 || a2 > 15) { GuardedFunctionCallCleanup(a1); return -2; }
    //     *(a1[7]+16) = a2;
    //     *(a1[7]+20) = MultiBlockAllocator(a1, *(a1[7]+12) == 0 ? sub_537D10 : 0, 1 << a2);
    //     if (*(a1[7]+20)) { ArithmeticComparison_5620(a1); return 0; }
    //     GuardedFunctionCallCleanup(a1); return -4;
    //   }
    // UNRESOLVED: The decompression/protocol interpretation (version magic a113_0 '1.13', a4 == 56) is inherited from existing analysis; not proven by this packet.
    // UNRESOLVED: Work-block sub-offsets are flattened by the pipeline as this+0x28/0x2C/0x30; the concrete work-block layout is unknown.
    // UNRESOLVED: The semantic roles of ArithmeticComparison_5620 (reset after allocation) and GuardedFunctionCallCleanup (teardown) are inferred from position in this flow.
    // UNRESOLVED: Callers sub_534B10 and ArgumentReorderWrapper frame this as a stream initializer, but their usage is outside this function.
}
