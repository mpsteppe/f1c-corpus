// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00550F70
// Canonical corpus name: sub_550F70
// Owner: MeshDataDualFormat [DERIVED]
// Raw source: functions/sub_550F70_00550f70.c

void MeshDataDualFormat::MeshDataDualFormatDestructor()
{
    // Destructor for loaded mesh data supporting two storage formats selected by flags at this+0x0: bit 0 (0x1) material-block format and bit 1 (0x2) texture/animation-block format. Releases per-block sub-allocations (refcount decrements, 8-byte and 12-byte element destruction) and frees the top-level strided arrays, returning 0 on every path.
    // GUARD: Format flags at this+0x0: when bit 1 (0x2) is clear the material-block path runs; when bit 0 (0x1) is also clear the function returns 0 with no format selected. [field:this:0x00000000, function:0x00550F70, source:raw]
    // LOOP: Material-block path: iterate while the block count at this+0xC is greater than 0 (guard:0). [field:this:0x0000000C, guard:0]
    // CALL: Each material block (sub-allocation pointer read from the array at this+0x10, stride 44, at block+40) has its 32-byte-strided sub-entries released by one RefcountDecrement each. [field:this:0x00000010, callee:0x005507D0]
    // CALL: Free the material block sub-allocation memory via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // CALL: Top-level material array (this+0x10): invoke EmptyStub_7470 on each 44-byte-strided element before the array is freed on the shared tail path. [field:this:0x00000010, callee:0x00557470]
    // LOOP: Texture/animation-block path: iterate while the group count at this+0x14 is greater than 0 (guard:1). [field:this:0x00000014, guard:1]
    // CALL: Each group (array at this+0x18, stride 12): free its 8-byte frame-pair sub-entries via FreeWrapper_7bcf, then destroy and free the group sub-array of 8-byte entries via sub_550810. [field:this:0x00000018, callee:0x00550810, callee:0x00587BCF]
    // CALL: Top-level texture group array (this+0x18): destroy 12-byte (3 dword) structs via ArrayOfStructDestructorWithCountdown, then free the array via FreeWrapper_7bcf on the shared tail path. [callee:0x00550820, callee:0x00587BCF]
    // RETURN: Return 0 on every path (early no-format return, null-array returns, and the final free tail). [function:0x00550F70, source:raw]
    // CALL: Destroyer is invoked by caller 0x00550AC0. [caller:0x00550AC0]

    // Conservative worker pseudocode:
    //   int MeshDataDualFormatDestructor(int *this) {
    //     if ((*this & 2) == 0) {
    //       if ((*this & 1) == 0) return 0;
    //       // Material-block format: release each block's 32-byte sub-entries, then free block memory.
    //       for (int i = 0; i < this[3]; i++) {
    //         int block = *(int*)(this[4] + 44*i + 40);
    //         if (block) {
    //           for (int k = 0; k < *(int*)(block - 4); k++) RefcountDecrement();
    //           FreeWrapper_7bcf(block - 4);
    //         }
    //       }
    //       // Free the 44-byte-strided material block array.
    //       for (int i = 0; i < *(int*)(this[4] - 4); i++) EmptyStub_7470(this[4] + 44*i);
    //     } else {
    //       // Texture/animation-block format.
    //       for (int i = 0; i < this[5]; i++) {
    //         int group = this[6] + 12*i;
    //         for (int k = 0; k < *(int*)(group + 4); k++)
    //           FreeWrapper_7bcf(*(void**)(*(int*)(group + 8) + 8*k + 4));
    //         int frames = *(int*)(group + 8);
    //         if (frames) {
    //           for (int k = 0; k < *(int*)(frames - 4); k++) sub_550810(frames + 8*k);
    //           FreeWrapper_7bcf(frames - 4);
    //         }
    //       }
    //       // Free the 12-byte-strided texture group array, then the array memory.
    //       for (int i = 0; i < *(int*)(this[6] - 4); i++)
    //         ArrayOfStructDestructorWithCountdown(this[6] + 12*i);
    //       FreeWrapper_7bcf(this[6] - 4);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Exact element semantics of sub_550810 (0x00550810) and ArrayOfStructDestructorWithCountdown (0x00550820) are not grounded beyond the fill; inner layouts derive from pointer arithmetic in the raw body.
    // UNRESOLVED: The allocator header convention (element count stored at allocation minus 4) is inferred from the body and is not independently confirmed.
}
