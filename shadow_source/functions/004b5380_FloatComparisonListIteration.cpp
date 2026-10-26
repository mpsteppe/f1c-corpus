// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B5380
// Canonical corpus name: FloatComparisonListIteration
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatComparisonListIteration_004b5380.c

void UnknownObject::FloatComparisonListIteration()
{
    // Walks a linked list anchored at this+0x20, storing the threshold a2 at this+0x30 and advancing a cursor at this+0x28. Each node is classified by FieldCompareConstant and FloatComparisonCheck; when a node falls outside the window bounded by node+12 and node+444 versus a2, one of three handlers runs: a lower-bound path calling ArithmeticComparison_3a90((node+440),(node+8)) then sub_5001B0, an upper-bound path calling ArithmeticComparison_3a90((node+8),(node+440)) then VehicleDataBufferClear, or a fallback helper. Called by sub_4B9000.
    // CALL: Invoked by sub_4B9000 for threshold-based processing of a list [caller:0x004B9000, source:raw]
    // ASSIGNMENT: Stores the incoming threshold a2 at this+0x30 (this+48) [field:this:0x00000030, source:raw]
    // ASSIGNMENT: Initializes the cursor at this+0x28 (this+40) from the list head this+0x20 (this+32) [field:this:0x00000020, field:this:0x00000028, source:raw]
    // LOOP: Linked-list walk: reads the head entry at *(this+0x20) and iterates while the current entry pointer is non-null [field:*(this+0x20):0x00000000, source:raw]
    // CALL: Per-node classification: FieldCompareConstant(node) and FloatComparisonCheck(node) produce two independent per-node flags [callee:0x005001D0, callee:0x005001F0, source:raw]
    // GUARD: Processing is entered when either flag is false or the node's float at +444 is above a2 or the node's float at +12 is below a2 (outside the a2 window) [field:*(*(this+0x20)+0x0):0x000001BC, field:*(*(this+0x20)+0x0):0x0000000C, source:raw]
    // CALL: Lower-bound path: when the FloatComparisonCheck flag is set and node+12 is below a2, calls ArithmeticComparison_3a90((node+440),(node+8)) then sub_5001B0(node) [callee:0x004B3A90, callee:0x005001B0, field:*(this+0x28):0x00000008, source:raw]
    // CALL: Upper-bound path: when the FieldCompareConstant flag is set and node+444 is above a2, calls ArithmeticComparison_3a90((node+8),(node+440)) then VehicleDataBufferClear(node) [callee:0x004B3A90, callee:0x00500190, source:raw]
    // CALL: Fallback path: a third helper runs on the node when neither bound path applies; it has no callee evidence ref in the packet [source:raw]
    // LOOP: Cursor advance: re-reads the entry at this+0x28, takes the next pointer at entry+4, writes it back to this+0x28, and dereferences it for the next iteration [field:*(this+0x28):0x00000004, field:this:0x00000028, source:raw]
    // RETURN: Returns the final cursor value, which is null once the list is exhausted [source:raw]

    // Conservative worker pseudocode:
    //   *(this + 0x30) = a2;
    //   cursor = *(this + 0x20);
    //   *(this + 0x28) = cursor;
    //   while (cursor) {
    //     node = *cursor;
    //     if (!node) break;
    //     c1 = FieldCompareConstant(node);
    //     c2 = FloatComparisonCheck(node);
    //     if (!c1 || !c2 || *(node + 444) > a2 || *(node + 12) < a2) {
    //       if (c2 && *(node + 12) < a2) {
    //         ArithmeticComparison_3a90(node + 440, node + 8);
    //         sub_5001B0(node);
    //       }
    //       else if (c1 && *(node + 444) > a2) {
    //         ArithmeticComparison_3a90(node + 8, node + 440);
    //         VehicleDataBufferClear(node);
    //       }
    //       else { unk_500170(node); }
    //     }
    //     cursor = *(this + 0x28);
    //     if (!cursor) break;
    //     cursor = *(cursor + 4);
    //     *(this + 0x28) = cursor;
    //   }
    //   return cursor;
    // UNRESOLVED: The fallback branch calls unk_500170, which has no callee evidence ref in the packet; its semantics are unknown
    // UNRESOLVED: Node field meanings are only directional: +12 behaves as a lower window bound and +444 as an upper window bound against a2; the underlying quantity is unresolved
    // UNRESOLVED: The flag byte at cursor+8 (packet field *(this+0x28)+8) is classified only as a per-node flag; its exact role in the dispatch is unresolved
}
