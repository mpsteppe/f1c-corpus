// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00465460
// Canonical corpus name: EntityVisibilityGridManager
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EntityVisibilityGridManager_00465460.c

void UnknownObject::UpdateEntityVisibilityGrid()
{
    // Grid-based entity visibility manager update. Clears the visibility allocation list at obj+0xE5C0, derives a per-frame work budget from DivisionWithCapComputation and a CRT float product, classifies the rank via ThresholdToRankClassifier (jump table jpt_4655B3) into a per-rank LOD factor, rebuilds a candidate entity list at obj+0xE5B0 from active slots, merge-sorts it, then dispatches visibility/computation work to each entity via DispatchWrapper under a budget cap (v83). Rank-out entities get a 432-byte progress-bar event (ProgressBarEventEncode + VectorToShort3Conversion) appended to obj+0xE5C0; remaining budget headroom is written back into the per-slot word. Entity identity and LOD/threshold bytes are read from per-entity data blocks via the obj+0xE5B8-cursor list chain.
    // CALCULATION: v4 = *this + 14704 -> visibility allocation-list base obj+0xE5C0 (dereference of this); v5 = head pointer at *v4. [field:this:0x00000000, field:obj:0x0000E5C0, source:raw]
    // LOOP: Free-walk of the list at obj+0E5C0: per node, ConditionalFreeByFlagCheck(node) then FreeWrapper_7bcf(node); node linkage follows the +8 next field. [callee:0x00582290, callee:0x00587BCF, field:*(obj+0xE5C0):0x00000008, source:raw]
    // ASSIGNMENT: Zero the 4-slot list header obj+0xE5C0..0xE5CC (head/tail/duplicate-ref/count) after freeing. [field:obj:0x0000E5C0, field:obj:0x0000E5C4, field:obj:0x0000E5C8, field:obj:0x0000E5CC, source:raw]
    // CALL: v7 = DivisionWithCapComputation(*this, a2): per-frame budget base value. [callee:0x00464F50, source:raw]
    // CALCULATION: v90 = 560*a2 (byte stride into obj), v92 = v7; budget v83 = LOWORD(obj[140*a2+173]) + CRTFtol(*(float*)(obj+0x60) * *(float*)(obj+0x64) * v92); the source word obj[140*a2+173] is then zeroed. [callee:0x00587BDC, field:obj:0x00000060, field:obj:0x00000064, source:raw]
    // ASSIGNMENT: Read the entity-list head from obj[27] = obj+0x6C and mirror it into the cursor slot obj+0x74. [field:obj:0x0000006C, field:obj:0x00000074, source:raw]
    // LOOP: Walk entities of the list at obj+0x6C (entity ptr from *(obj+0x6C)); skip those whose +0x1AC dword equals a3; otherwise allocate a 12-byte node via OperatorNewNhMallocWrapper, append it to the obj+0xE5C0 list (head/tail/dup/count update) and debit the budget v83 by -8-((entity type bits>>8)&0x3FF). Advance via cursor obj+0x74 with next entity from *(obj+0x74). [callee:0x00587C03, field:*(obj+0x6C):0x00000000, field:*(obj+0x6C):0x000001AC, field:obj:0x00000074, field:*(obj+0x74):0x00000000, field:obj:0x0000E5C0, source:raw]
    // CALL: ThresholdToRankClassifier(v7) -> rank; a switch over it (jump table jpt_4655B3) selects the per-rank LOD factor v84: 0.125 / 0.083333336 / 0.0625 / 0.015625 / default 0.16666667. [callee:0x00464F90, global:0x00465C18, source:raw]
    // CALCULATION: v82 = dbl_8AFE90: constant read used as an argument to the UtilityFunction_4bb0 threshold test. [global:0x008AFE90, source:raw]
    // GUARD: Proceed into the rebuild/dispatch block only if UtilityFunction_4bb0(slot, v82, v84) is true AND budget v83 > 0. [callee:0x00464BB0, source:raw]
    // CALL: FloatFieldDecrementWithClamp(obj + 560*a2 + 140, v84): decay the per-slot field by the LOD factor. [callee:0x00464BD0, source:raw]
    // CALCULATION: v93 = v83 / 60: convert the budget into 60-unit dispatch steps. [source:raw]
    // LOOP: If v93 > 0, free-walk the obj+0xE5B0 list (ConditionalFreeByFlagCheck + FreeWrapper_7bcf per node; entity ptr from *(obj+0xE5B0)) and zero the 4-slot header obj+0xE5B0..0xE5BC. [callee:0x00582290, callee:0x00587BCF, field:*(obj+0xE5B0):0x00000000, field:obj:0x0000E5B0, field:obj:0x0000E5B4, field:obj:0x0000E5B8, field:obj:0x0000E5BC, source:raw]
    // LOOP: Rescan obj slot table indices 14596..14699: reset each obj[v25] = -1; for active entities (byte at obj+v24+248) with slot counter != a2, allocate a 12-byte node via OperatorNewNhMallocWrapper and append it to the obj+0xE5B0 list (head/tail/dup/count), stepping v24 by 560 per slot. [callee:0x00587C03, field:obj:0x0000E5B0, source:raw]
    // CALCULATION: Select the grid rank/vehicle block: v29 = word_5F0F88[9312*v23]; if dword_5EF9A0[4656*v29] == -1 then v29 = v23; entity data base v32 = unk_5EC6D8 + 18624*v29 (per-rank vehicle array, 0x48C0 stride). [global:0x005F0F88, global:0x005EF9A0, global:0x005EC6D8, source:raw]
    // LOOP: Walk the rebuilt obj+0xE5B0 list; for each entity call ShortComputation_4990(entity, v32); advance via cursor obj+0xE5B8 with the next entity read from *(obj+0xE5B8). [callee:0x00464990, field:*(obj+0xE5B0):0x00000000, field:obj:0x0000E5B8, field:*(obj+0xE5B8):0x00000000, source:raw]
    // CALL: MergeSortOnLinkedList(list at obj+0xE5B0) -> sorted head; write back head into obj+0xE5B0, tail into obj+0xE5B4 and duplicate head ref into obj+0xE5B8. [callee:0x00465C70, field:obj:0x0000E5B0, field:obj:0x0000E5B4, field:obj:0x0000E5B8, source:raw]
    // LOOP: Second pass over the sorted obj+0xE5B0 list: write each obj slot obj[14596..14699] = (unsigned __int8) entity data byte at +0x6D read through the obj+0xE5B0 list. [field:*(obj+0xE5B0):0x00000000, field:*(*(obj+0xE5B0)+0x0):0x0000006D, source:raw]
    // ASSIGNMENT: dword_7CD2AC = *this: publish the object base pointer to the global. [global:0x007CD2AC, source:raw]
    // LOOP: Build the second dispatch chain from the obj+0x7C list (guard: head == 0 skips the whole block): per entity v49 (from *(obj+0x7C)) whose +0x1AC dword != a3, allocate 4-byte and 12-byte nodes via OperatorNewNhMallocWrapper; advance via cursor obj+0x84 with next entity from *(obj+0x84). [guard:1, field:obj:0x0000007C, field:*(obj+0x7C):0x00000000, field:*(*(obj+0x7C)+0x0):0x000001AC, field:obj:0x00000084, field:*(obj+0x84):0x00000000, callee:0x00587C03, source:raw]
    // CALL: v95 = sub_465D70(chain head v94): produces the per-entity (payload pointer, free-flag byte) node list used by the priority dispatch drain. [callee:0x00465D70, source:raw]
    // CALCULATION: v89 = (v93 > 1) ? v93/2 : v83/60: per-frame dispatch-count cap. [source:raw]
    // LOOP: Main dispatch loop while budget v83 > 0: pull the next entity from the obj+0xE5B0 list via cursor obj+0xE5B8; skip entities failing the filter — entity data byte +0x6C cleared or CharacterRangeCheckWithSignFlag(entity, a2, slot flag) false; otherwise dispatch DispatchWrapper(entity, a2). [callee:0x00464AE0, callee:0x00464AD0, field:*(*(*(obj+0xE5B8)+0x0)+0x0):0x0000006C, field:*(obj+0xE5B0):0x00000000, field:obj:0x0000E5B8, source:raw]
    // STATE_TRANSITION: Per dispatched entity (chain rooted at obj+0xE5B8) with +0x219 dword != a3: if dispatch cap v89 is exhausted (<0), allocate a 432-byte block, encode ProgressBarEventEncode(1, 7, 19, entity byte +0x6D, entity float +0x71, 0) and VectorToShort3Conversion, append a wrapper node to the obj+0xE5C0 list and budget v83 -= 8+((block>>8)&0x3FF); otherwise (data block not the -109 sentinel, guard) append a node referencing entity+109 to obj+0xE5C0 and budget v83 -= 60. [callee:0x004B33B0, callee:0x004B2C80, callee:0x00587C03, field:*(*(*(obj+0xE5B8)+0x0)+0x0):0x0000006D, field:*(*(*(obj+0xE5B8)+0x0)+0x0):0x00000071, field:*(*(*(obj+0xE5B8)+0x0)+0x0):0x00000219, field:*(*(obj+0xE5B8)+0x0):0x00000000, guard:0, field:obj:0x0000E5C0, source:raw]
    // LOOP: Drain the v95/v86 node chain into the obj+0xE5C0 list: per remaining node allocate a 12-byte wrapper, append it, and budget v83 -= 8+((payload>>8)&0x3FF); stop when v83 <= 0 or no dispatch source remains. [field:obj:0x0000E5C0, source:raw]
    // LOOP: Free the v95 chain: per node, if its +8 free-flag byte is set call FreeWrapper_7bcf on the payload; then FreeWrapper_7bcf on the node itself. [callee:0x00587BCF, source:raw]
    // RETURN: result = obj+0xE5C0; store the list head into obj+0xE5C8; if budget v83 > 0 write min(CRTFtol(v92*v84), v83) into the per-slot word obj+560*a2+692; return result. [field:obj:0x0000E5C0, field:obj:0x0000E5C8, callee:0x00587BDC, function:0x00465460, source:raw]

    // Conservative worker pseudocode:
    //   // clear visibility allocation list at obj+0xE5C0
    //   v7 = DivisionWithCapComputation(obj, a2);
    //   v83 = LOWORD(obj[140*a2+173]) + CRTFtol(objFloat[0x64] * objFloat[0x60] * v7);
    //   obj[140*a2+173] = 0;
    //   v84 = rank_factor[ThresholdToRankClassifier(v7)];  // 0.125 / 0.0833 / 0.0625 / 0.015625 / 0.1667
    //   if (UtilityFunction_4bb0(&obj[560*a2+35], dbl_8AFE90, v84) && v83 > 0) {
    //       FloatFieldDecrementWithClamp(&obj[560*a2+35], v84);
    //       if (v83/60 > 0) {
    //           // rebuild candidate list at obj+0xE5B0, merge sort it
    //           for each active slot: append 12B node(entity) to list at obj+0xE5B0;
    //           MergeSortOnLinkedList(list at obj+0xE5B0);
    //           // dispatch under budget cap
    //           while (v83 > 0 && sources remain) {
    //               entity = next from obj+0xE5B0 list;
    //               if (!entity.filterOK()) skip;
    //               DispatchWrapper(entity, a2);
    //               if (entity[0x219] != a3) {
    //                   if (--v89 < 0) { progressBarEvent(node at obj+0xE5C0); v83 -= 8+((blk>>8)&0x3FF); }
    //                   else if (entity != -109) { appendNode(obj+0xE5C0); v83 -= 60; }
    //               }
    //           }
    //           free v95 chain;
    //       }
    //   }
    //   obj[0xE5C8] = *(obj+0xE5C0);
    //   if (v83 > 0) *(WORD*)(obj + 560*a2 + 692) = min(CRTFtol(v92*v84), v83);
    //   return obj + 0xE5C0;
    // UNRESOLVED: Fields obj+0x78 and obj+0x88 are read per the packet but are not visible as standalone accesses in the decompiled source text; their role here is unknown.
    // UNRESOLVED: v19 (a register-sourced value) is read uninitialized at the UtilityFunction_4bb0 call site in the raw source; the effective slot base is obj + 560*a2 + 140.
    // UNRESOLVED: The -109 (0xFFFFFF93) sentinel meaning behind guard 0 is unknown; existing analysis labels it the entity data block sentinel.
    // UNRESOLVED: The 0x48C0 stride (18624) and 4656/9312 indexing derive from raw arithmetic only; the entity and rank/vehicle struct definitions are not in the packet.
    // UNRESOLVED: Existing-analysis prose labels these lists by ordinal (e.g. 'fifth allocation list' at obj+0xE5B0); exact list roles (visibility vs dispatch) are DERIVED, not confirmed.
}
