// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00565EB0
// Canonical corpus name: sub_565EB0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_565EB0_00565eb0.c

void UnknownObject::CleanupListResetCountFlag()
{
    // Resource-list cleanup. Passes the list head (*this) to EnhancedListCleanupWithSubObjectDelete, then unconditionally zeroes the 32-bit field at offset 0x21C of the list-head structure (element index 135) and returns the list-head pointer. No guards; cleanup and flag reset always run.
    // CALL: Call EnhancedListCleanupWithSubObjectDelete(*this) to tear down the linked list contents. [callee:0x00565D50, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Capture the list-head pointer as the return value. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero the list-head element at index 135 (offset 0x21C) unconditionally after cleanup. [field:obj:0x0000021C, source:raw]
    // RETURN: Return the list-head pointer. [function:0x00565EB0, source:raw]

    // Conservative worker pseudocode:
    //   void *CleanupListResetCountFlag(void ***this) {
    //     EnhancedListCleanupWithSubObjectDelete(*this);
    //     void *head = *this;
    //     ((int *)head)[135] = 0;
    //     return head;
    //   }
    // UNRESOLVED: The meaning of the flag/count zeroed at offset 0x21C (element 135) is not established; the existing analysis suggests a state/count flag, which is not independently evidenced.
    // UNRESOLVED: The relationship between the cleanup result and the returned head pointer is caller-context dependent; callers span profile, bitmap, texture, vehicle and scene scanning paths, all unconfirmed.
}
