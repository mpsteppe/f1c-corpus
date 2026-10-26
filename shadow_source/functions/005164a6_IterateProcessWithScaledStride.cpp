// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005164A6
// Canonical corpus name: sub_5164A6
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5164A6_005164a6.c

void UnknownObject::IterateProcessWithScaledStride()
{
    // Structural twin of a sibling chunked-iteration helper (cluster_copy provenance) with the element stride scaled by 2^7: the effective stride used for byte offsets is *(this+0x8) << 7 instead of *(this+0x8). Walks the element-pointer array in boundary-clamped chunks and dispatches each chunk to one of two cdecl callbacks at this+0x28 (default) or this+0x2C (selected by flag a3). Breaks early when clamping leaves no elements in the chunk.
    // ASSIGNMENT: Initialize the base byte offset v3 = ((*(this+0x8) << 7) * *(this+0x18)) and the scaled stride v8 = *(this+0x8) << 7. [field:this:0x00000008, field:this:0x00000018, source:raw]
    // ASSIGNMENT: Initialize the remaining count result = *(this+0x10) (total element count to process). [field:this:0x00000010, source:raw]
    // LOOP: for (i = 0; i < result; v3 += v9) — iterate over element chunks until the count is exhausted. [field:this:0x00000010, source:raw]
    // CALCULATION: Subtract the current index from the count: result -= i. [source:raw]
    // GUARD: Clamp the chunk count to the chunk-size limit: if *(this+0x14) < result then result = *(this+0x14). [field:this:0x00000014, source:raw]
    // CALCULATION: Compute the boundary offset v6 = i + *(this+0x18). [field:this:0x00000018, source:raw]
    // GUARD: Clamp the chunk count against the upper bound: if result >= *(this+0x1C) - v6 then result = *(this+0x1C) - v6. [field:this:0x0000001C, source:raw]
    // GUARD: Clamp the chunk count against the lower bound: if result >= *(this+0x4) - v6 then result = *(this+0x4) - v6. [field:this:0x00000004, source:raw]
    // GUARD: Break the loop when the clamped chunk count result <= 0. [source:raw]
    // CALCULATION: Compute the chunk byte count v7 = v9 = v8 * result (scaled stride * clamped element count). [field:this:0x00000008, source:raw]
    // GUARD: Flag a3 selects the alternate callback at this+0x2C when non-zero, otherwise the default callback at this+0x28. [field:this:0x00000028, field:this:0x0000002C, source:raw]
    // CALL: Invoke the selected cdecl callback (this+0x28 or this+0x2C) with arguments (a2, state pointer this+0x28, element pointer from *(*(this+0x0) + 4*i), base byte offset v3, chunk byte count v7). [field:this:0x00000028, field:this:0x0000002C, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Advance the index by the chunk size: i += *(this+0x14). [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Reset the remaining count to the total for the next iteration: result = *(this+0x10). [field:this:0x00000010, source:raw]
    // RETURN: Return the final result (total count, or the clamped value on early break). [source:raw]
    // CALL: Called by OffsetValidationWithBufferUpdate (0x0051664F) to dispatch indexed element chunks through the selected callback with a 2^7-scaled stride. [caller:0x0051664F, source:raw]

    // Conservative worker pseudocode:
    //   int sub_5164A6(int this, int dest, int useAltCb) {
    //     int v3 = (*(this+8) << 7) * *(this+24);
    //     int stride = *(this+8) << 7;
    //     int result = *(this+16);
    //     for (int i = 0; i < result; v3 += v9) {
    //       result -= i;
    //       if (*(this+20) < result) result = *(this+20);
    //       int v6 = i + *(this+24);
    //       if (result >= *(this+28) - v6) result = *(this+28) - v6;
    //       if (result >= *(this+4) - v6) result = *(this+4) - v6;
    //       if (result <= 0) break;
    //       int v7 = stride * result; v9 = v7;
    //       void (*cb)(int,int,int,int,int) = useAltCb ? *(this+44) : *(this+40);
    //       cb(dest, this+40, *(*(this+0) + 4*i), v3, v7);
    //       i += *(this+20);
    //       result = *(this+16);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Owner object is unknown; field semantics (array base, bounds, stride) are inferred from usage only.
    // UNRESOLVED: The 2^7 stride scaling distinguishes this twin from its cluster representative; the underlying element size this implies is not confirmed.
    // UNRESOLVED: Exact layout of the element-pointer array at *(this+0x0) and the callback contract (argument meaning of this+0x28 passed as state) are caller-defined.
}
