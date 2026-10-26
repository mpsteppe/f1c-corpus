// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055BDE0
// Canonical corpus name: sub_55BDE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55BDE0_0055bde0.c

void UnknownObject::LinkedListNodeGetByIndex()
{
    // __thiscall linked-list node accessor: if the requested index a2 is at least the count this[71] it returns 0; otherwise it walks the list from the head this[72] following the next pointer at node + 0x20 (each element a _DWORD) for a2 steps, breaking early when the next pointer is null, and returns the reached node pointer (index a2 or the last reachable node). Existing analysis names it LinkedListNodeGetByIndex.
    // GUARD: Out-of-range guard: when a2 >= this[71] (count read at +0x11C) the function returns 0 immediately. [field:this:0x0000011C, source:raw]
    // RETURN: Return 0 for an out-of-range index. [source:raw]
    // ASSIGNMENT: result = this[72] (head pointer read at +0x120) starts the walk. [field:this:0x00000120, source:raw]
    // LOOP: Walk loop: for i = 0 while i < a2, advance result to the next node via the next pointer at node + 0x20. [field:*(this+0x140):0x00000020, source:raw]
    // GUARD: Early break: if the next pointer at result + 0x20 is null the walk stops at the current node. [field:*(this+0x140):0x00000020, source:raw]
    // RETURN: Returns the node pointer at index a2, or the last reachable node when the chain ends early. [source:raw]
    // CALL: Called by GlobalGuardedFieldReader (0x004F91B0), GuardedFieldAccessor (0x004F9200) and sub_53F3F0 (0x0053F3F0). [caller:0x004F91B0, caller:0x004F9200, caller:0x0053F3F0, source:raw]

    // Conservative worker pseudocode:
    //   int LinkedListNodeGetByIndex(_DWORD* this, int a2) {
    //     if (a2 >= this[71]) return 0;
    //     int result = this[72];
    //     int i = 0;
    //     while (i < a2) {
    //       if (*(_DWORD*)(result + 32) == 0) break;
    //       i++;
    //       result = *(_DWORD*)(result + 32);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The packet identifies the node next pointer with base *(this+0x140) (offset 0x20); the relationship between that base and the returned node pointer is not established.
    // UNRESOLVED: Whether this[71] is an exact count or a max index bound is inferred from the guard only.
    // UNRESOLVED: Returning the last reachable node (rather than null) when the chain is shorter than a2 is evident from the code but its semantic intent is unknown.
}
