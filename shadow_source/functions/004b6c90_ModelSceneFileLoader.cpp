// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B6C90
// Canonical corpus name: ModelSceneFileLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ModelSceneFileLoader_004b6c90.c

void UnknownObject::ModelSceneFileLoader()
{
    // Binary model/scene file deserializer. When BinaryFloatComparison(a2) passes, reads two null-terminated string tables from the stream, reads two 1-byte flags into this+0xF1C and this+0xF20, rebuilds the first scene-object list (this+0x18 block, count this+0x40, pool this+0x38) by reading a node count, allocating or reusing nodes and appending them via 16-byte list blocks indexed at this+0x40, then tears down the second list (this+0x6C0/0x6C4) and rebuilds it from stream nodes read via FileStreamReader, reads three dwords into this+0xF24/0xF28/0xF2C, transfers buffers via LinkedBufferTransfer, builds the third list (this+0x714/0x718/0x71C/0x720) from sub_4B44A0 nodes, consumes per-node format headers, and computes bounding-extent values into this+0xF30/0xF34 from the head node of the third list. Returns 1 on success.
    // GUARD: Result of BinaryFloatComparison(a2) gates the entire body; when it returns nonzero the deserialization runs, otherwise the function returns its (zero) result. [callee:0x004B8090, source:raw]
    // LOOP: Read two string tables from the stream: for each, FileWriteWithBackendDispatch reads a length into v35 and then that many bytes into the local v37 buffer, the buffer is null-terminated and processed by StringCopyWithBufferRealloc. [callee:0x00566C00, callee:0x00566650, source:raw]
    // ASSIGNMENT: Read a 1-byte value from the stream into v31 and store it at this+0xF1C; read a 1-byte value into v32 and store it at this+0xF20. [callee:0x00566C00, field:this:0x00000F1C, field:this:0x00000F20, source:raw]
    // CALL: Call sub_4B5E50(this) to (re)initialize the receiver before node rebuilding. [callee:0x004B5E50, source:raw]
    // LOOP: Read the first-list node count v36 from the stream; loop v36 times rebuilding list A nodes. [callee:0x00566C00, field:this:0x00000040, source:raw]
    // CALL: Per iteration, call ShortComputation_a780 on the list-A management block at this+0x18 and inspect the node at this+0x18 (head at +0x0, byte flag at +0x8 zeroed on reuse); when the node is present, attempt LinkedListNodeRemoval_a830 on its payload; on failure fall back to MemoryAllocation_afc0(this) plus sub_4BB0C0(this+0x18) to obtain a fresh node. The free-pool block at this+0x38 (flag at +0x8) is consulted for pre-existing node eligibility. [callee:0x004BA780, field:this:0x00000018, field:*(this+0x18):0x00000000, field:*(this+0x18):0x00000008, field:this:0x00000038, field:*(this+0x38):0x00000008, callee:0x004BA830, callee:0x004BAFC0, callee:0x004BB0C0, source:raw]
    // CALL: Call sub_4B5040(node, a2) to populate the (possibly reused) node from the stream. [callee:0x004B5040, source:raw]
    // CALCULATION: Select a 16-byte list-management block: index = this + 16 * (node type byte + 4), which addresses the block base at this+0x40 whose head/tail/count live at +0x0/+0x4/+0xC. [field:this:0x00000040, source:raw]
    // ASSIGNMENT: Allocate a 12-byte node via OperatorNewNhMallocWrapper; on success set payload at +0x0, next at +0x4 to zero and byte flag at +0x8 to zero, then append: if head is set link through tail+0x4, otherwise set head at +0x0 and tail at +0x8, update tail at +0x4 and increment the count at +0xC. [callee:0x00587C03, field:*(*(this+0x18)+0x0):0x00000000, source:raw]
    // LOOP: Iterate the second linked list (head pointer at *(this+0x6C0), next at +0x4 of each node, deep-cleanup byte at +0xC): nodes whose cleanup byte is nonzero (guard: cleanup byte == 0 means skip) and which have a payload are passed to DestructorWithConditionalFree_b460, and every node is released via FreeWrapper_7bcf. [field:this:0x000006C0, field:*(this+0x6C0):0x00000000, field:*(*(this+0x6C0)+0x4):0x00000004, field:*(this+0x6C0):0x0000000C, guard:0, callee:0x004BB460, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Clear the second list state: zero this+0x6C0, this+0x6C4, this+0x6C8 and this+0x6CC. [field:this:0x000006C0, field:this:0x000006C4, field:this:0x000006C8, field:this:0x000006CC, source:raw]
    // LOOP: Read a count v30 from the stream and loop that many times: allocate a 12-byte node (next at +0x4 zeroed, index at +0x8 set to -1) and call FileStreamReader on it; when it survives, wrap it in a 16-byte node (payload at +0x0, links at +0x4/+0x8 zeroed, flag byte at +0xC set to 1) and append to the second list via the tail pointer at *(this+0x6C4) (+0x4 next), updating the head pointer at *(this+0x6C0), the tail field this+0x6C8 and count this+0x6CC. [callee:0x00566C00, callee:0x00587C03, callee:0x004B4250, field:this:0x000006C0, field:*(this+0x6C0):0x00000000, field:this:0x000006C4, field:*(this+0x6C4):0x00000004, field:this:0x000006C8, field:this:0x000006CC, source:raw]
    // ASSIGNMENT: Read three stream dwords into this+0xF24, this+0xF28 (unnamed region) and this+0xF2C, then call LinkedBufferTransfer(this) to transfer the linked buffers. [callee:0x00566C00, field:this:0x00000F24, field:this:0x00000F2C, callee:0x004B5F60, source:raw]
    // GUARD: Guard on the count at this+0xF24 being greater than zero; only then does the third-list rebuild loop run. [guard:1, field:this:0x00000F24, source:raw]
    // LOOP: Iterate the third-list rebuild: manage the free-list at this+0x20 via sub_4BB6B0 on the payload (byte flag at +0x8 zeroed) with fallback to MultiLevelAllocation(this+0x20) plus LinkedListNodeRemoval_acf0(v18); call sub_4B44A0 on the node, and on success wrap it in a 16-byte node (payload +0x0, links +0x4/+0x8 zeroed, flag byte +0xC zeroed) appended to the third list via the tail pointer at *(this+0x718) (+0x4 next), updating the head pointer at *(this+0x714), the tail field this+0x71C and count this+0x720. [callee:0x004BB6B0, callee:0x004BB200, callee:0x004BACF0, callee:0x004B44A0, callee:0x00587C03, field:this:0x00000714, field:*(this+0x714):0x00000000, field:this:0x00000718, field:*(this+0x718):0x00000004, field:this:0x0000071C, field:this:0x00000720, source:raw]
    // LOOP: For each rebuilt node, consume the per-node format headers: loop over the count in the word at node+0x8, calling FileFormatHeaderReader(a2) each pass. [callee:0x004B43E0, source:raw]
    // CALCULATION: Compute the bounding extent: zero this+0xF30 and this+0xF34, then from the third-list head at this+0x714 read the payload and its first float; store it into this+0xF30 and store payload_float + this+0xF2C into this+0xF34. [field:this:0x00000F30, field:this:0x00000F34, field:*(*(this+0x714)+0x0):0x00000000, field:this:0x00000714, field:this:0x00000F2C, source:raw]
    // RETURN: Return 1 when the full deserialization path completed successfully. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_4B6C90(this, a2) {
    //     char result = BinaryFloatComparison(a2);
    //     if (result) {
    //       readStringTable(stream); readStringTable(stream); // via FileWriteWithBackendDispatch + StringCopyWithBufferRealloc
    //       this->u8(0xF1C) = stream.readByte();
    //       this->u8(0xF20) = stream.readByte();
    //       sub_4B5E50(this);
    //       n = stream.readDword();
    //       for (i = 0; i < n; ++i) {
    //         node = reuseOrAllocate(listA);  // ShortComputation_a780 / LinkedListNodeRemoval_a830 / MemoryAllocation_afc0 / sub_4BB0C0
    //         sub_4B5040(node, a2);
    //         appendNode(listBlock(this + 16*(type+4)), node);
    //       }
    //       freeList(listB);   // this+0x6C0, DestructorWithConditionalFree_b460 + FreeWrapper_7bcf
    //       zero(this+0x6C0, this+0x6C4, this+0x6C8, this+0x6CC);
    //       for (i = 0; i < stream.readByte(); ++i) {
    //         obj = allocate(); FileStreamReader(obj, a2);
    //         if (obj) appendNode16(listB, wrap(obj, 1));
    //       }
    //       this->u32(0xF24) = stream.readDword(); this->u32(0xF28) = stream.readDword(); this->u32(0xF2C) = stream.readDword();
    //       LinkedBufferTransfer(this);
    //       if (this->u32(0xF24) > 0) {
    //         for (i = 0; i < this->u32(0xF24); ++i) {
    //           node = reuseOrAllocate(listC); // sub_4BB6B0 / MultiLevelAllocation / LinkedListNodeRemoval_acf0
    //           sub_4B44A0(node, a2);
    //           if (node) { wrap16 = allocate(); appendNode16(listC3, wrap16); }
    //           for (j = 0; j < word(node+0x8); ++j) FileFormatHeaderReader(a2);
    //         }
    //       }
    //       this->f(0xF30) = 0; this->f(0xF34) = 0;
    //       first = *(float**)(this+0x714);
    //       if (first && *first) {
    //         this->f(0xF30) = **first;
    //         this->f(0xF34) = **first + this->f(0xF2C);
    //       }
    //       return 1;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The stream dword at this+0xF28 is read by FileWriteWithBackendDispatch in the raw source but has no packet field entry; its role is unknown.
    // UNRESOLVED: The three 16-byte list blocks are indexed by a node type byte (this + 16 * (type + 4)); the exact type enum is unknown.
    // UNRESOLVED: Semantics of the byte flags read into this+0xF1C / this+0xF20 from the stream are unknown.
    // UNRESOLVED: The second-list nodes are wrapped with the flag byte at +0xC set to 1, while third-list nodes are wrapped with it zeroed; the meaning of that flag (e.g. deep-cleanup eligibility) is only inferred.
    // UNRESOLVED: The float extent at this+0xF30/0xF34 combines the head payload's first float with this+0xF2C; the exact bounding semantic is inferred.
    // UNRESOLVED: The free-pool eligibility flag read at *(this+0x38)+0x8 is not visibly accessed in the raw source text (likely inside the allocation helpers); its exact use is inferred.
}
