// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C6150
// Canonical corpus name: FilterPropertiesListNodeRemover
// Owner: FilterPropertiesList [DERIVED]
// Raw source: functions/FilterPropertiesListNodeRemover_004c6150.c

void FilterPropertiesList::FilterPropertiesListNodeRemover()
{
    // Removes nodes from a filter-properties linked list (head at this+0x8, tail at this+0xC, current at this+0x10, count at this+0x14) whose built filter name matches at least one of the criteria strings in a2 (a3 criteria). For each node the scene index at node+0x0 indexes the scene array dword_8AC490 (stride 396); a name is built from aFilterProperti via StringCopyWithValidation and compared against each criterion with sub_566810. A full match unlinks and frees the node (with optional cleanup of its data when the flag byte at node+0x8 is set). Returns the remaining count this+0x14. Called by SceneFileFilterBuilder (004c6330).
    // GUARD: Proceed only when the first criterion *a2 is non-null and the criterion count a3 is greater than 0. [source:raw]
    // ASSIGNMENT: Seed the traversal: current pointer this+0x10 is set from the head pointer this+0x8. [field:this:0x00000008, field:this:0x00000010, source:raw]
    // LOOP: Iterate the node list; each node's scene index is read from node+0x0 (base of the head node at *(this+0x8)). [field:*(this+0x8):0x00000000, source:raw]
    // CALCULATION: Resolve the node's scene entry: v6 = dword_8AC490 + 396 * scene_index (scene array with stride 396). [global:0x008AC490, source:raw]
    // CALL: Build the filter name: seed the buffer from byte_5EA438, zero the remainder, then StringCopyWithValidation(buffer, 256, aFilterProperti, scene_name at v6+260). A missing scene entry or a failed copy skips the node. [global:0x005EA438, global:0x005D31EC, callee:0x004C58A0, source:raw]
    // LOOP: Match the built name against each criterion a2[v7] with sub_566810; if no criterion matches before v7 reaches a3, the node is skipped. [callee:0x00566810, source:raw]
    // STATE_TRANSITION: Unlink a fully matched node: find it from the head (this+0x8), update the current pointer this+0x10 if it pointed at the node, relink predecessor to successor (or update the head when it was first), update the tail this+0xC if the tail was removed, and decrement the count at this+0x14. [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // CALL: Node data cleanup: when the flag byte at node+0x8 is set, release the node data pointer via ShortComputation_4370 and FreeWrapper_7bcf, then free the node itself with FreeWrapper_7bcf. [callee:0x00414370, callee:0x00587BCF, source:raw]
    // RETURN: Return the remaining item count stored at this+0x14 after traversal. [field:this:0x00000014, function:0x004C6150, source:raw]
    // CALL: Called by SceneFileFilterBuilder (004c6330) to prune filter property nodes that no longer match the criteria. [caller:0x004C6330, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 == NULL || *a2 == NULL || a3 <= 0) return this->count_0x14;
    //   cur = this->head_0x8;
    //   this->current_0x10 = cur;
    //   while (cur != NULL) {
    //     node = cur;
    //     scene = dword_8AC490 + 396 * node->scene_index_0x0;
    //     build_name_buffer(buffer, byte_5EA438);
    //     if (scene == NULL || StringCopyWithValidation(buffer, 256, aFilterProperti, scene + 260)) {
    //       advance_current();
    //     } else {
    //       matched = 0;
    //       for (i = 0; i < a3; i++) if (sub_566810(buffer, a2[i]) != 0) { matched = 1; break; }
    //       if (!matched) advance_current();
    //       else {
    //         unlink(node);  /* head +0x8, tail +0xC, current +0x10, count -1 at +0x14 * /
    //         if (node->flag_0x8 != 0) { ShortComputation_4370(node->data + 1); FreeWrapper_7bcf(node->data); }
    //         FreeWrapper_7bcf(node);
    //         this->current_0x10 = this->head_0x8;
    //       }
    //     }
    //     cur = this->current_0x10;
    //   }
    //   return this->count_0x14;
    // UNRESOLVED: global 0x008AC368 (unk_8AC368) is listed by packet facts as read but does not appear in the decompiled body; role unknown
    // UNRESOLVED: StringCopyWithValidation return semantics (nonzero treated as skip here) are inferred from branch placement only
    // UNRESOLVED: node+0x8 is described as a flag byte but its exact meaning is unverified
    // UNRESOLVED: dword_8AC490 scene entry stride of 396 and the name field at +260 come from the raw arithmetic and are not independently named
}
