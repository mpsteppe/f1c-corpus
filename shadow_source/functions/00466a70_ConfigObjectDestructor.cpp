// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00466A70
// Canonical corpus name: ConfigObjectDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConfigObjectDestructor_00466a70.c

void UnknownObject::ConfigObjectDestructor()
{
    // Destructor for a config/command-binding object. Copies the stored handle from a global command-binding table, resets a shared string buffer, optionally reports vehicle statistics, frees a linked list of nodes (each node: data pointer, next pointer, flag byte), clears the list head/tail/count fields, and reinserts a sentinel default entry into the custom command list.
    // ASSIGNMENT: Copy the stored command-binding handle: this+0x104 = dword_7C7368[this+0x108], using the field at this+0x108 as an index into the global table dword_7C7368. [field:this:0x00000104, field:this:0x00000108, global:0x007C7368, source:raw]
    // CALL: Reset the shared string buffer via StringCopyWithBufferRealloc on byte_5EA438. [callee:0x00566650, global:0x005EA438, source:raw]
    // GUARD: When the scene-destroyed flag byte_7C7064 is clear, report the vehicle statistics held in byte_7C56C0 during teardown. [global:0x007C7064, global:0x007C56C0, source:raw]
    // CALL: VehicleStatsEstimationDisplay(&byte_7C56C0) displays the estimated vehicle stats. [callee:0x00430F00, global:0x007C56C0, source:raw]
    // LOOP: Walk the node list starting at this+0x44 while the current node pointer is nonzero; each node carries a data pointer at node+0 and the next pointer at node+4. [field:this:0x00000044, field:*(this+0x44):0x00000000, field:*(this+0x48):0x00000004, source:raw]
    // GUARD: Per node, test the flag byte at node+8; when set, free the node's inner data allocation chain. [field:*(this+0x44):0x00000000, source:raw]
    // CALL: Free the node's inner data pointer chain (the data block and the data block pointer) via FreeWrapper_7bcf when non-null. [callee:0x00587BCF, field:*(this+0x44):0x00000000, source:raw]
    // CALL: Free the node block itself via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Clear the list bookkeeping fields this+0x44, this+0x48, this+0x4C and this+0x50 to 0. [field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, source:raw]
    // CALL: Reinsert a sentinel/default entry named aCustom_0 into the custom command list via LinkedListInsertWithNodeAllocation(aCustom_0, -1). [callee:0x00486F30, global:0x005C670C, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int ConfigObjectDestructor() {
    //     this[65] = dword_7C7368[this[66]];
    //     StringCopyWithBufferRealloc(byte_5EA438);
    //     if (!byte_7C7064) VehicleStatsEstimationDisplay(&byte_7C56C0);
    //     node = this[17];
    //     while (node) {
    //       next = node->next;
    //       if (node->flag) {
    //         if (node->data) {
    //           if (*node->data) FreeWrapper_7bcf(*node->data);
    //           FreeWrapper_7bcf(node->data);
    //         }
    //       }
    //       FreeWrapper_7bcf(node);
    //       node = next;
    //     }
    //     this[17] = this[18] = this[19] = this[20] = 0;
    //     LinkedListInsertWithNodeAllocation(aCustom_0, -1);
    //     return 0;
    //   }
    // UNRESOLVED: The purpose of the handle stored from dword_7C7368 into this+0x104 is caller-defined and unknown here.
    // UNRESOLVED: The exact meaning of the node flag byte at node+8 and the data-pointer nesting is inferred from the free pattern only.
    // UNRESOLVED: This object's class and the full layout beyond the accessed offsets are unknown.
}
