// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B5630
// Canonical corpus name: CollisionFilterAABBCull
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionFilterAABBCull_004b5630.c

void UnknownObject::FilterCollisionListNodes()
{
    // Filters a collision node linked list. Reads the active list head from this+0x20 and stores it as the iterator at this+0x28. Walks the active list; a node is kept when FieldCompareConstant and FloatComparisonCheck both pass, or when |node+0x370 float - this+0x30 threshold| <= 2.5. Kept nodes just advance the iterator through the node+4 next link. Culled nodes are unlinked from the active list (fixing head this+0x20, tail this+0x24, iterator this+0x28 and count this+0x2C), their payload freed when the node+8 flag byte is set (EmptyStub_0170 + FreeWrapper_7bcf), the node freed, then a replacement allocated via OperatorNewNhMallocWrapper(12)/ShortComputation_ac20 and inserted into an output list (head this+0x10, anchor pair this+0x14/this+0x18, count this+0x1C). Returns the final iterator value.
    // ASSIGNMENT: result = active list head (this+0x20); store it as the iterator at this+0x28. [field:this:0x00000020, field:this:0x00000028, function:0x004B5630, source:raw]
    // GUARD: If the active list head is non-null, enter the filtering walk. [field:this:0x00000020, function:0x004B5630, source:raw]
    // LOOP: Walk the active list while the iterator (this+0x28) is non-null; the node value i is read from the iterator node's +0 slot (field *(this+0x28):0). [field:*(this+0x28):0x00000000, field:this:0x00000028, function:0x004B5630, source:raw]
    // CALCULATION: Keep test: node is kept when (FieldCompareConstant(i) && FloatComparisonCheck(i)) or |node+0x370 float - this+0x30 threshold| <= 2.5. [callee:0x005001D0, callee:0x005001F0, field:*(*(this+0x20)+0x0):0x00000370, field:this:0x00000030, function:0x004B5630, source:raw]
    // ASSIGNMENT: Keep path: advance the iterator this+0x28 to the current node's next link (node+4, field *(this+0x28):4). [field:*(this+0x28):0x00000004, field:*(this+0x20):0x00000004, field:this:0x00000028, function:0x004B5630, source:raw]
    // STATE_TRANSITION: Cull path: unlink the node (matched by +0 value) from the active list, fixing head this+0x20, tail this+0x24, iterator this+0x28 and the count this+0x2C; free the payload when the node+8 flag byte is set (EmptyStub_0170 then FreeWrapper_7bcf), then free the node itself. [field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:*(this+0x20):0x00000000, field:*(this+0x20):0x00000004, field:*(this+0x20):0x00000008, callee:0x004B0170, callee:0x00587BCF, function:0x004B5630, source:raw]
    // CALL: Allocate a replacement output node: OperatorNewNhMallocWrapper(12); on success ShortComputation_ac20(i, 0), otherwise null. [callee:0x00587C03, callee:0x004BAC20, function:0x004B5630, source:raw]
    // ASSIGNMENT: Insert the new node into the output list: if the output head this+0x10 is non-null, link the new node's +4 to it; otherwise initialize the anchor pair this+0x14 and this+0x18 to the new node; then set this+0x10 = new node and increment the output count this+0x1C. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, function:0x004B5630, source:raw]
    // RETURN: Return the final iterator value (this+0x28), null when the walk exhausted the list. [field:this:0x00000028, function:0x004B5630, source:raw]

    // Conservative worker pseudocode:
    //   result = this->activeHead;         // this+0x20
    //   this->iter = result;               // this+0x28
    //   if (result == 0) return result;
    //   for (n = result; result != 0; n = result[+0]) {
    //     if ((FieldCompareConstant(n) && FloatComparisonCheck(n))
    //         || fabs(n[+0x370] - this->threshold) <= 2.5) {
    //       this->iter = this->iter[+4];   // keep, advance
    //     } else {
    //       unlink n from active list (fix head +0x20, tail +0x24,
    //         iterator +0x28, --count +0x2C);
    //       if (n[+8 byte]) { EmptyStub_0170(); FreeWrapper_7bcf(n[+0]); }
    //       FreeWrapper_7bcf(n);
    //       m = OperatorNewNhMallocWrapper(12) ? ShortComputation_ac20(n, 0) : 0;
    //       if (this->outHead != 0) m[+4] = this->outHead;
    //       else { this[+0x14] = m; this[+0x18] = m; }
    //       this->outHead = m;              // this+0x10
    //       ++this->outCount;               // this+0x1C
    //     }
    //     result = this->iter;
    //   }
    //   return result;
    // UNRESOLVED: Node field at +0xC (field:*(this+0x20):0x0000000C) is listed in the packet but never read by this function.
    // UNRESOLVED: Global dbl_5ACD30 is listed as read but absent from the raw source text; the 2.5 distance bound is a literal.
    // UNRESOLVED: Caller sub_4B9000 provides the surrounding collision context, but the owning object type is unidentified.
}
