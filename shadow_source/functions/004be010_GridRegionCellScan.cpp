// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BE010
// Canonical corpus name: sub_4BE010
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4BE010_004be010.c

void UnknownObject::GridRegionCellScan()
{
    // Computes a clamped rectangular cell region on a grid anchored at this, then visits every cell in that region by calling MemoryAllocation_d900 on each cell address together with a2. Row and column indices are derived from CRTFtol of four expressions built from a2[3], a2[5], a2[6] and the object fields this[585] (0x924), this[587] (0x92C) as origins and this[586] (0x928), this[588] (0x930) as scales; every index is clamped to [0,7]. If any index left the [0,7] range, a flag is set and, at the end, MemoryAllocation_d900 is additionally called once on the region anchor (this + 576 float slots), returning that call's result; otherwise it returns the flag (0). Marked as a structural twin of sub_4BDE20 and called from ShortComputation_e770, ConditionalCleanupChain and StateDependentUpdateDispatch on the per-frame path.
    // CALCULATION: Row start v5 = clamp(CRTFtol((a2[3] - a2[6] - this[585]) * this[586]), 0..7); out-of-range clamp sets the flag. [field:this:0x00000924, field:this:0x00000928, callee:0x00587BDC, source:raw]
    // CALCULATION: Row end v7 = clamp(CRTFtol((a2[6] + a2[3] - this[585]) * this[586]), 0..7); out-of-range clamp sets the flag. [field:this:0x00000924, field:this:0x00000928, callee:0x00587BDC, source:raw]
    // CALCULATION: Column start v9 = clamp(CRTFtol((a2[5] - a2[6] - this[587]) * this[588]), 0..7); out-of-range clamp sets the flag. [field:this:0x0000092C, field:this:0x00000930, callee:0x00587BDC, source:raw]
    // CALCULATION: Column end v11 = clamp(CRTFtol((a2[6] + a2[5] - this[587]) * this[588]), 0..7); out-of-range clamp sets the flag. [field:this:0x0000092C, field:this:0x00000930, callee:0x00587BDC, source:raw]
    // STATE_TRANSITION: Flag v16 is set to 1 whenever any of the four computed indices fell outside [0,7] and had to be clamped (each clamp path re-assigns v16 = 1). [source:raw, function:0x004BE010]
    // LOOP: Nested loop over rows v5..v7 (step 72 float slots) and columns v9..v11 (step 36 float slots) starting from base this[72*v5 + 9*v9]: for each cell call MemoryAllocation_d900(cell_address, a2). [callee:0x004BD900, source:raw, function:0x004BE010]
    // CALL: If the flag is set, call MemoryAllocation_d900(this + 576, a2) once on the region anchor and return its result. [callee:0x004BD900, source:raw, function:0x004BE010]
    // RETURN: When no index was clamped, return the flag (0). [source:raw, function:0x004BE010]

    // Conservative worker pseudocode:
    //   rowStart = clamp(ftol((a2[3]-a2[6]-this[585]) * this[586]), 0, 7); flag |= clamped;
    //   rowEnd   = clamp(ftol((a2[6]+a2[3]-this[585]) * this[586]), 0, 7); flag |= clamped;
    //   colStart = clamp(ftol((a2[5]-a2[6]-this[587]) * this[588]), 0, 7); flag |= clamped;
    //   colEnd   = clamp(ftol((a2[6]+a2[5]-this[587]) * this[588]), 0, 7); flag |= clamped;
    //   for (r = rowStart; r <= rowEnd; ++r)
    //     for (c = colStart; c <= colEnd; ++c)
    //       MemoryAllocation_d900(&this[72*r + 9*c], a2);
    //   return flag ? MemoryAllocation_d900(&this[576], a2) : 0;
    // UNRESOLVED: The purpose of MemoryAllocation_d900 (corpus name; callee 0x004BD900) is not recoverable from this packet; the cell/region semantics (copy, mark, or notify) are unknown.
    // UNRESOLVED: Semantics of fields this[585]..this[588] (origin/scale floats) and the anchor this + 576 are inferred from the arithmetic, not proven; the byte address of this + 576 is not present in the packet.
    // UNRESOLVED: Roles of a2[3], a2[5] and a2[6] as region extents are inferred; the callers (ShortComputation_e770, ConditionalCleanupChain, StateDependentUpdateDispatch) do not establish the data layout.
    // UNRESOLVED: The column loop advances by 36 float slots while the base uses 9*col, an asymmetry whose meaning is unclear from the packet alone.
}
