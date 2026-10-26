// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D1030
// Canonical corpus name: LoopOverTwoParallelArrays
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LoopOverTwoParallelArrays_004d1030.c

void UnknownObject::LoopOverTwoParallelArrays()
{
    // Iterates two per-vehicle data arrays in parallel. First pass walks the AI/path data array (base unk_5F0F80, stride 4656 DWORDS) up to the boundary dword_7C9D80: for each live slot it computes a DistanceComparison into a byte results buffer and resets two sentinel DWORDS to -1. Second pass walks the main vehicle array (base unk_5EC6D8, stride 18624 bytes) up to the boundary byte_7C54D8: for each live slot it runs RenderCallWithGuard and, when the stored distance result is non-zero, AIVehiclePathPositionTracking. Finishes by delegating to sub_4D1670. Called by NetCommPlayerSlotSync (0045FC50).
    // ASSIGNMENT: Initialize iteration counter v1 = 0 and cursor v3 to the AI/path data array base unk_5F0F80. [global:0x005F0F80, source:raw]
    // LOOP: First do-while loop: advance v3 by 4656 DWORDS per iteration until v3 reaches the boundary dword_7C9D80. [global:0x007C9D80, source:raw]
    // GUARD: Slot-live guard on the AI/path array: only process when *(v3 - 1400) != -1. [source:raw]
    // CALL: Compute DistanceComparison(v3 - 4647) and store its result in the results byte buffer at v8[v1 + 12]. [callee:0x004EFFD0, source:raw]
    // ASSIGNMENT: Reset the two sentinel DWORDS behind the live slot: *(v3 - 1) = -1 and *v3 = -1. [source:raw]
    // ASSIGNMENT: Initialize iteration counter v4 = 0 and cursor v5 to the main vehicle array base unk_5EC6D8. [global:0x005EC6D8, source:raw]
    // LOOP: Second do-while loop: advance v5 by 18624 bytes per iteration until v5 reaches the boundary byte_7C54D8. [global:0x007C54D8, source:raw]
    // GUARD: Slot-live guard on the main vehicle array: only process when *((_DWORD *)v5 + 3250) != -1. [source:raw]
    // CALL: Call RenderCallWithGuard(v5, v8, v7), passing the current vehicle plus the results and render buffers. [callee:0x004D1140, source:raw]
    // GUARD: Conditional path tracking: when the stored distance result v8[v4 + 12] is non-zero, call AIVehiclePathPositionTracking(v8, v7). [callee:0x004EF7C0, source:raw]
    // RETURN: Return sub_4D1670(this), the post-loop processing step executed once after both array passes complete. [callee:0x004D1670, source:raw]

    // Conservative worker pseudocode:
    //   v1 = 0;
    //   for (v3 = &unk_5F0F80; v3 < (int*)dword_7C9D80; v3 += 4656, ++v1) {
    //     if (v3[-1400] != -1) {
    //       results[v1 + 12] = DistanceComparison(v3 - 4647);
    //       v3[-1] = -1; v3[0] = -1;
    //     }
    //   }
    //   v4 = 0;
    //   for (v5 = &unk_5EC6D8; v5 < (char*)byte_7C54D8; v5 += 18624, ++v4) {
    //     if (((_DWORD*)v5)[3250] != -1) {
    //       RenderCallWithGuard(v5, results, v7);
    //       if (results[v4 + 12]) AIVehiclePathPositionTracking(results, v7);
    //     }
    //   }
    //   return sub_4D1670(this);
    // UNRESOLVED: The byte buffers v8 (results) and v7 (render/tracking scratch) are stack locals; their exact element layout and stride are not documented by packet evidence.
    // UNRESOLVED: Meaning of the DistanceComparison return value and the exact semantics of the two reset sentinels are only inferred from the guard pattern.
    // UNRESOLVED: abi trust is LEGACY; the legacy name 'Loop_Over_Two_Parallel_Arrays' matches the observed control flow but no higher trust source exists.
}
