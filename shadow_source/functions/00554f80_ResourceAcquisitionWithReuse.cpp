// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00554F80
// Canonical corpus name: sub_554F80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_554F80_00554f80.c

void UnknownObject::ResourceAcquisitionWithReuse()
{
    // Acquires a texture-like resource, reusing an already-existing matching node when possible. Reads the resource descriptor at a3+84; when its setup flag (index 6, bit 0x400) is clear, creates the resource via sub_554E90 and stores the handle at this+0. A result of -1 means the resource already exists, so it searches the node chain reached through ValueGetter(a2)+40 for a matching entry; on a match it reuses the node and clears its prepared bit. When no match exists it falls back to a StructFieldGetter check and D3DResourceListCleanup, then retries creation. Finally, if the descriptor has a target (index 4) it dispatches through the device vtable slot at +116 and marks the descriptor setup bit 0x400. Clears descriptor index 14 and returns 1.
    // ASSIGNMENT: Load the resource descriptor pointer v3 from a3 + 84. [source:raw]
    // GUARD: Skip the entire acquisition path when the descriptor flag at index 6 has bit 0x400 set (already set up). [source:raw]
    // CALL: Create the resource with sub_554E90(this, a3) and store the returned handle at this + 0. [callee:0x00554E90, field:this:0x00000000, source:raw]
    // GUARD: A creation result of -1 signals the resource already exists and triggers the reuse path. [source:raw]
    // CALL: Resolve the node chain via ValueGetter(a2); the reuse path requires a2 non-null and the node pointer at the returned value + 40 non-null. [callee:0x00545F40, source:raw]
    // LOOP: Walk the linked list (next pointer at index 23) searching a node whose flags at +24 have bit 0x80000 clear and bit 0x400 set, whose value at +56 is above 0.0, and whose identity fields (value at +20, node +48, node +28, node +32) match the descriptor and a3 + 80. [source:raw]
    // ASSIGNMENT: On a match, mark the descriptor reuse bit (index 6 |= 8), copy the node data at +20 into descriptor index 5, zero the node field at +20, write the sentinel constant -1082130432 at node +56 and clear the node's prepared bit with mask 0xFFFFFBF7. [source:raw]
    // GUARD: No-match path: return 0 when StructFieldGetter(this) reports a non-null field. [callee:0x0055C9B0, source:raw]
    // CALL: Clean the D3D resource list with D3DResourceListCleanup(this, a2). [callee:0x00554E10, source:raw]
    // CALL: Retry resource creation with sub_554E90, store the handle at this + 0 and return 0 when the retry fails. [callee:0x00554E90, field:this:0x00000000, source:raw]
    // GUARD: Read the descriptor target at index 4; the final vtable dispatch only runs when it is non-zero. [source:raw]
    // CALL: Dispatch the virtual slot at +116 (0x74) of the device object stored at this + 0x1100, passing the device, the descriptor target and the descriptor value. [field:*(*(this+0x1100)+0x0):0x00000074, field:*(this+0x1100):0x00000000, field:this:0x00001100, source:raw]
    // ASSIGNMENT: Store the dispatch result at this + 0, return 0 on failure, otherwise mark the descriptor setup bit (index 6 |= 0x400). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Clear the descriptor field at index 14 and return 1 on success. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_554F80(this, a2, a3) {
    //     desc = *(a3 + 84);
    //     if ((desc[6] & 0x400) == 0) {
    //       handle = sub_554E90(this, a3);
    //       *(this) = handle;
    //       if (handle == -1) {
    //         node = 0;
    //         if (a2 && (node = *(ValueGetter(a2) + 40))) {
    //           while (node) {
    //             if (nodeMatches(node, desc, a3)) break;
    //             node = node[23];
    //           }
    //           if (node) { desc[6] |= 8; desc[5] = *(node + 20);
    //                      *(node + 20) = 0; *(node + 56) = -1082130432;
    //                      *(node + 24) &= 0xFFFFFBF7; }
    //         }
    //         if (!node) {
    //           if (StructFieldGetter(this)) return 0;
    //           D3DResourceListCleanup(this, a2);
    //           handle = sub_554E90(this, a3);
    //           *(this) = handle;
    //           if (handle) return 0;
    //         }
    //       }
    //       if (desc[4]) {
    //         result = device_vtable[116](*(this + 0x1100), desc[4], desc[5]);
    //         *(this) = result;
    //         if (result) return 0;
    //         desc[6] |= 0x400;
    //       }
    //     }
    //     desc[14] = 0;
    //     return 1;
    //   }
    // UNRESOLVED: Identity of the descriptor struct at a3+84 and the meaning of its fields at indices 5, 6 and 14 are not established by this packet.
    // UNRESOLVED: The node identity-match fields (a3+80, node +28/+32/+48, node value at +56) carry no owner-level meaning in this packet.
    // UNRESOLVED: The virtual slot at +116 of the device object (this + 0x1100) performs the final resource setup but its contract is unknown.
    // UNRESOLVED: flt_59E440 is listed as a referenced global but does not appear in this function's raw source; its role here is unclear.
}
