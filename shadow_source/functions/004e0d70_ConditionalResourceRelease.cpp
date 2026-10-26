// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E0D70
// Canonical corpus name: ConditionalResourceRelease
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalResourceRelease_004e0d70.c

void UnknownObject::ConditionalResourceRelease()
{
    // Conditionally releases a resource element. Reads the element pointer *a1; if it is non-null and the init flag byte at a1+0x40 is set, it transplants the node from its doubly-linked list via DoublyLinkedListNodeTransplant, clears the flag to 0, and returns the result of FlagFieldBitManipulation(1, 1, 1, 0). On any early-out path it returns the element pointer read at entry.
    // ASSIGNMENT: Read result = *a1 (the element pointer) before the guards. [source:raw, field:this:0x00000000]
    // GUARD: Guard: if *a1 is NULL, skip the release body. [source:raw, field:this:0x00000000]
    // GUARD: Guard: if the init flag byte at a1+0x40 is zero, skip the release body. [source:raw, field:this:0x00000040]
    // CALL: Transplant the element node *a1 out of the active doubly-linked list via DoublyLinkedListNodeTransplant(*a1). [source:raw, callee:0x0054BAA0]
    // ASSIGNMENT: Clear the init flag: *((BYTE*)a1 + 64) = 0. [source:raw, field:this:0x00000040]
    // CALL: Return FlagFieldBitManipulation(1, 1, 1, 0) which updates the flag/activation field. [source:raw, callee:0x0054C030]
    // RETURN: Early-out return: result (*a1) when either guard failed and the body was skipped. [source:raw, field:this:0x00000000]

    // Conservative worker pseudocode:
    //   int sub_4E0D70(int *a1) {
    //     int result = *a1;
    //     if (*a1 && *((BYTE*)a1 + 64)) {
    //       DoublyLinkedListNodeTransplant(*a1);
    //       *((BYTE*)a1 + 64) = 0;
    //       return FlagFieldBitManipulation(1, 1, 1, 0);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantics of FlagFieldBitManipulation(1, 1, 1, 0) depend on the flag-field enum, which is not established in this packet.
    // UNRESOLVED: Type/layout of the object behind *a1 beyond the 0x0 element pointer and 0x40 init flag is unknown.
    // UNRESOLVED: a1+0x0 is read as an int but treated as a list node pointer by DoublyLinkedListNodeTransplant; caller contracts (SubslotCleanup 0x004E0E70, SubsystemStateMachine 0x004E17C0, RepairServiceStateDispatcher 0x004ED250) are not detailed here.
}
