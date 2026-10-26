// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00541340
// Canonical corpus name: TextureSurfaceAllocation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureSurfaceAllocation_00541340.c

void UnknownObject::TextureSurfaceAllocation()
{
    // Texture surface descriptor allocation and creation (canonical name TextureSurfaceAllocation, ABI name Texture_Surface_Allocation). Allocates a 76-byte block with OperatorNewNhMallocWrapper, marks its header as 2, and zeroes two 9-DWORD (36-byte) descriptor blocks. Stores the first descriptor block pointer at this+4428 (this+0x114C), then fills both blocks with the same per-block constants: 34 at the block header, 322 at +4, 24 at +8, and the a2 argument at +12 for the first block; 34 at +36, 322 at +40, 24 at +44, and a2 at +48 for the second. Calls sub_540DF0 (0x00540DF0) once per descriptor block, returning -1 if either call fails and 0 on success. Called by sub_544740 (0x00544740).
    // CALCULATION: Allocate a 76-byte block via OperatorNewNhMallocWrapper (0x00587C03); when the allocation succeeds, set the block header *v3 = 2 and zero the following 18 DWORDs as two 9-DWORD descriptor blocks (v6[0..8] per block with v6 advancing by 9 DWORDs, two iterations). [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Store the first descriptor block pointer (v3 + 1) at this+4428 (this+0x114C). [field:this:0x0000114C, source:raw]
    // ASSIGNMENT: Initialize the first descriptor block: header value 34 at the block base, 322 at +4, 24 at +8, and the a2 argument at +12. [field:*(this+0x114C):0x00000004, field:*(this+0x114C):0x00000008, field:*(this+0x114C):0x0000000C, source:raw]
    // ASSIGNMENT: Initialize the second descriptor block (at *(this+0x114C) + 36): 34 at +36, 322 at +40, 24 at +44, and a2 at +48. [field:*(this+0x114C):0x00000024, field:*(this+0x114C):0x00000028, field:*(this+0x114C):0x0000002C, field:*(this+0x114C):0x00000030, source:raw]
    // CALL: Call sub_540DF0 (0x00540DF0) with this and the first descriptor block pointer (*(this+0x114C)); on a non-zero result return -1. [callee:0x00540DF0, field:this:0x0000114C, source:raw]
    // CALL: Call sub_540DF0 (0x00540DF0) with this and the second descriptor block pointer (*(this+0x114C) + 36); on a non-zero result return -1. [callee:0x00540DF0, field:this:0x0000114C, source:raw]
    // RETURN: Return 0 when both surface creation calls succeed. [source:raw]
    // CALL: Invoked from sub_544740 (0x00544740). [caller:0x00544740, source:raw]

    // Conservative worker pseudocode:
    //   int sub_541340(this, a2) {
    //     block = OperatorNewNhMallocWrapper(76);
    //     desc = block ? block + 1 : 0;
    //     if (block) {
    //       *block = 2;
    //       for (i = 0; i < 2; i++) { d = block + 1 + i * 9; for (j = 0; j < 9; j++) d[j] = 0; }
    //     }
    //     this->descriptor = desc;
    //     desc[0] = 34; desc[1] = 322; desc[2] = 24; desc[3] = a2;
    //     desc[9] = 34; desc[10] = 322; desc[11] = 24; desc[12] = a2;
    //     if (sub_540DF0(this, desc)) return -1;
    //     if (sub_540DF0(this, desc + 9)) return -1;
    //     return 0;
    //   }
    // UNRESOLVED: If the allocation returns null the decompiler output contains no guard: desc stays 0 and the subsequent writes dereference null, which would fault at runtime; the success path is assumed.
    // UNRESOLVED: The constants 34, 322 and 24 are not independently identified as a surface format enum, width or height; the a2 argument is passed through unchanged without a confirmed semantic.
    // UNRESOLVED: sub_540DF0's role of creating a surface from the descriptor block is DERIVED from existing analysis, not independently confirmed.
    // UNRESOLVED: Owning class of this (which holds the descriptor pointer at +0x114C) is unknown.
}
