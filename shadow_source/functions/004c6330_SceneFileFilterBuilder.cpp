// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C6330
// Canonical corpus name: SceneFileFilterBuilder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneFileFilterBuilder_004c6330.c

void UnknownObject::SceneFileFilterBuilder()
{
    // Builds the filtered, merge-sorted scene-file linked list. Clears the object's existing list, then either copies every non-null entry from the global scene list (dword_8AC490, dword_8AC488 entries, stride 396) when no filter string is given, the filter equals the default byte_5EA438, or a photo/free-camera mode is active; or parses a filter expression with AND:/OR:/NOT: token buckets, materializes include/AND lists and removes NOT tokens, then splits the list at the midpoint and merge-sorts it back together with SceneSortComparator. Returns the accumulated node counter. Called by GameFilterSetup.
    // CALL: Clears the object's existing scene list via ResourceListCleanup_62c0 before rebuilding [callee:0x004C62C0, source:raw]
    // GUARD: Unfiltered path: taken when a2 is null, a2 equals the default path string byte_5EA438, or the mode flags dword_7D0398 is set with dword_7D0410 not equal to 5 [global:0x005EA438, global:0x007D0398, global:0x007D0410, source:raw]
    // CALL: Sets the active filter string to the default byte_5EA438 via StringCopyWithBufferRealloc [global:0x005EA438, callee:0x00566650, source:raw]
    // LOOP: Walks the global scene list: dword_8AC488 entries starting at dword_8AC490 with a stride of 396 bytes, processing each entry whose pointer is non-null [global:0x008AC488, global:0x008AC490, source:raw]
    // CALL: Per entry: clears a 256-byte name buffer, then StringCopyWithValidation copies the scene name from aFilterProperti into it (max 256, source at entry plus 260 bytes) [callee:0x004C58A0, global:0x005D31EC, source:raw]
    // CALL: Allocates and builds the list node: OperatorNewNhMallocWrapper(16) for the scene object initialized by sub_4C5C80 with the copied name, then OperatorNewNhMallocWrapper(12) for the link cell storing the scene pointer, a null next and a flag byte of 1 [callee:0x00587C03, callee:0x004C5C80, source:raw]
    // ASSIGNMENT: Appends the new node: when the head (this+8) exists, the old tail's next pointer (*(this+12)+4) is set to the new node; otherwise head (this+8) and cursor (this+16) both become it; tail (this+12), node count (this+20) and the local counter are then updated [field:this:0x00000008, field:this:0x0000000C, field:*(this+0xC):0x00000004, field:this:0x00000010, field:this:0x00000014, source:raw]
    // CALL: Filtered path: sets the active filter string to a2 via StringCopyWithBufferRealloc and records the OR/alternative marker string stored at dword_5D30C0 [callee:0x00566650, global:0x005D30C0, source:raw]
    // CALL: Copies the filter expression into a 256-byte working buffer with a cap of 255 via sub_587DD0, then zeroes the three token buckets (two 50-dword arrays and a 253-byte buffer) [callee:0x00587DD0, source:raw]
    // LOOP: Tokenizes the filter buffer with strtok-style calls to sub_5897CA using the delimiter set ' ,tab newline'; iteration continues while a token is returned [callee:0x005897CA, source:raw]
    // CALCULATION: Classifies each token with sub_588410 prefix tests against the AND marker, the OR marker (dword_5D30C0) and the NOT marker; the failing branch selects the include (v43), AND (v44) or NOT (v40) bucket and sets the mode counter (0, 1 or 2). Tokens are stored while the chosen bucket holds fewer than 49 entries [callee:0x00588410, global:0x005D30C0, source:raw]
    // CALL: Materializes the filtered list: FilterPropertiesListBuilder adds the include tokens, FilterPropertiesListBuilder_5fd0 the AND tokens, and FilterPropertiesListNodeRemover removes the NOT tokens from the built list [callee:0x004C5E50, callee:0x004C5FD0, callee:0x004C6150, source:raw]
    // CALCULATION: Sort preparation: counts the nodes from the head (this+8); when at least 2 exist, walks to the midpoint, writes 0 to the midpoint node's next pointer (at the tail base (this+12) node plus 4) to split the list into two halves [field:this:0x00000008, field:*(this+0xC):0x00000004, source:raw]
    // CALL: Merge-sorts each half with MergeSortLinkedList and merges the two runs back together using SceneSortComparator to order the nodes [callee:0x004C6810, callee:0x004C5D30, source:raw]
    // ASSIGNMENT: Rebuilds list bookkeeping: head (this+8), tail (this+12) walked to the last node, cursor (this+16), resets the state counter this+24 to 0, and returns the accumulated node counter from the build [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000018, function:0x004C6330, source:raw]
    // CALL: Invoked by GameFilterSetup to produce the filtered scene list for the current filter configuration [caller:0x00477830, source:raw]

    // Conservative worker pseudocode:
    //   cleanup existing list;
    //   if (a2 == null || a2 == byte_5EA438 || (dword_7D0398 && dword_7D0410 != 5)) {
    //     set filter string to byte_5EA438;
    //     for (idx = 0; idx < dword_8AC488; ++idx) {
    //       entry = *(dword_8AC490 + idx*396);
    //       if (entry) {
    //         copy entry name (offset +260) into a 256-byte buffer via StringCopyWithValidation;
    //         new_node = LinkCell(SceneObject(buffer));
    //         append new_node to list tail; ++count;
    //       }
    //     }
    //   } else {
    //     set filter string to a2;
    //     copy a2 into a 256-byte working buffer;
    //     for (token = next_token(buffer); token; token = next_token(null))
    //       classify token as include/AND/NOT and store into the matching bucket;
    //     FilterPropertiesListBuilder(include);
    //     FilterPropertiesListBuilder_5fd0(AND);
    //     FilterPropertiesListNodeRemover(NOT);
    //   }
    //   count nodes; if count >= 2 { split at midpoint; left = MergeSortLinkedList(head); right = MergeSortLinkedList(mid+1); }
    //   head = merge(left, right, SceneSortComparator);
    //   tail = last node; cursor = head; this[6] = 0;
    //   return count;
    // UNRESOLVED: Seven read-only globals (0x005D30C4, 0x005D30C8, 0x005D30CC, 0x005D30D0, 0x005D30D4, 0x005D30D8, 0x008AC368) are flagged by packet facts but appear nowhere in the raw decompiled source; their role (likely adjacent filter-configuration state) is not verifiable from this packet
    // UNRESOLVED: The token bookkeeping uses several overlapping dword-indexed buffers (v32/v33/v34/v30 as both counters and indices); the exact element semantics of the include/AND/NOT buckets are not fully derivable here
    // UNRESOLVED: The branch polarity of sub_588410 (match vs non-match) and the exact AND/OR marker strings (v37, v38 and the dword_5D30C0-backed marker) are inferred from branch order only
}
