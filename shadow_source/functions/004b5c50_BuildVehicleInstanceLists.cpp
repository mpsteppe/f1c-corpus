// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B5C50
// Canonical corpus name: VehicleInstanceListBuilder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleInstanceListBuilder_004b5c50.c

void UnknownObject::BuildVehicleInstanceLists()
{
    // Iterates 104 per-slot vehicle entries in a2 (each 18624 bytes apart), building and maintaining per-slot linked lists of tracked vehicle instances anchored at this+0x44. Compares vehicle identity strings, stamps session time onto new instances, and reuses entry nodes from the free list.
    // LOOP: Iterate 104 vehicle-slot entries in a2, each 18624 bytes apart; each slot maintains a list anchored at the this+0x44 head with a tail at 0x48 and a count at 0x4C [field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, function:0x004B5C50]
    // ASSIGNMENT: Copy the slot list head pointer into the tail pointer at 0x48 at the start of the iteration [field:this:0x00000044, field:this:0x00000048]
    // GUARD: Skip the rest of the slot when its list head at this+0x44 is null [guard:0, field:this:0x00000044]
    // CALL: Compare the slot vehicle identity string via VehicleIdentityStringComparison; on a match, move to the next slot without touching the instance [callee:0x004B5120, field:*(this+0x44):0x00000000, source:raw]
    // ASSIGNMENT: If the vehicle instance timestamp at 0x88 equals -1.0e32, stamp it with the session time global dbl_8AFEA0 [field:*(*(this+0x44)+0x0):0x00000088, global:0x008AFEA0]
    // GUARD: Proceed to create an entry only when the slot active marker at a2+13000 differs from -1 [source:raw]
    // CALL: Obtain a reusable entry node: first try LinkedListNodeRemoval_a830 on the free-list head at 0x10; if that yields nothing, allocate a container via OperatorNewNhMallocWrapper and FixedSizeContainerConstructor, initialize it with sub_4BAF10, then pop a node via sub_4BB0C0; store the reused node into the temp pointer at 0x18 [callee:0x004BA830, callee:0x00587C03, callee:0x004BAA50, callee:0x004BAF10, callee:0x004BB0C0, field:this:0x00000010, field:this:0x00000018]
    // CALL: Copy the driver/team identity from a2 into the entry via DriverNameTeamCopy [callee:0x004B51E0]
    // ASSIGNMENT: Set the entry timestamp field at 0x84 to the session time global dbl_8AFEA0 [field:*(this+0x10):0x00000084, global:0x008AFEA0]
    // ASSIGNMENT: Allocate a 12-byte list node via OperatorNewNhMallocWrapper, store the entry pointer in it, and clear its next-link field at 0x4 and its flag byte [callee:0x00587C03, field:*(this+0x44):0x00000004]
    // ASSIGNMENT: Link the node into the slot list: when no node exists yet set both the head at 0x44 and the tail at 0x48 to it, otherwise attach it after the current head; then move the head forward to the new node and increment the count at 0x4C [field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:*(this+0x44):0x00000000]
    // RETURN: Return the final value of the decremented slot counter [source:raw, function:0x004B5C50]

    // Conservative worker pseudocode:
    //   for (slot = 0; slot < 104; slot++, a2 += 18624) {
    //     tail = head;
    //     if (!head) continue;
    //     entry = head->entry;
    //     if (VehicleIdentityStringComparison(entry->identity, a2)) continue;
    //     if (entry->timestamp == -1.0e32) entry->timestamp = dbl_8AFEA0;
    //     if (a2->activeMarker != -1) {
    //       node = reuseOrAllocEntry();
    //       DriverNameTeamCopy(node, a2);
    //       node->timestamp = dbl_8AFEA0;
    //       link = OperatorNewNhMallocWrapper(12);
    //       link->entry = node; link->next = 0;
    //       prepend link to slot list; count++;
    //     }
    //   }
    // UNRESOLVED: flt_5ACD10 is listed as a referenced global but no visible use survives in the decompiled source; its proposed role (EntityActiveDefault) is unconfirmed.
    // UNRESOLVED: The exact type of the vehicle instance and the meaning of the field at 0x84 (driver-name vs timestamp) are DERIVED from prior analysis, not proven here.
    // UNRESOLVED: A concrete owning class is unknown; the single caller PitTimingUpdate only suggests a pit-timing subsystem relationship.
}
