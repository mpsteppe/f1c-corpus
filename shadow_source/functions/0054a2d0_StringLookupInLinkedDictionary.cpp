// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054A2D0
// Canonical corpus name: StringLookupInLinkedDictionary
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringLookupInLinkedDictionary_0054a2d0.c

void UnknownObject::StringLookupInLinkedDictionary()
{
    // Linear search of a linked dictionary for an input string. Loads the chain head from this+0x100; if null, returns 0. Walks nodes through the next pointer at node+0x104, comparing each node's string at node+8 against the input via strcmp. Returns the matching node pointer, or 0 when the chain ends without a match.
    // ASSIGNMENT: Load the chain head: v2 = *(this+0x100). [field:this:0x00000100, source:raw]
    // GUARD: If v2 is null (empty dictionary), return 0 immediately. [field:this:0x00000100, source:raw]
    // LOOP: While strcmp of the node string at v2+8 against a2 is non-zero, advance to the next node via the next pointer at node+0x104. [field:*(this+0x204):0x00000104, source:raw]
    // GUARD: When the next pointer at node+0x104 is null, return 0 (end of chain without a match). [field:*(this+0x204):0x00000104, source:raw]
    // RETURN: Return the matching node pointer v2 when strcmp reports equality; otherwise 0. [function:0x0054A2D0, source:raw]
    // CALL: Invoked by LinkedListUpdate (00549380) and AudioNodeUpdateWalk (00549440) to resolve a string name to its dictionary node pointer. [caller:0x00549380, caller:0x00549440, source:raw]

    // Conservative worker pseudocode:
    //   v2 = *(this + 0x100);
    //   if (v2 == 0) return 0;
    //   while (strcmp((const char*)(v2 + 8), a2) != 0) {
    //     v2 = *(int*)(v2 + 260);
    //     if (v2 == 0) return 0;
    //   }
    //   return v2;
    // UNRESOLVED: The owning class is unknown; the this+0x100 head and node+0x104 next linkage imply a generic linked dictionary, but the node string field at node+8 and the key layout are unverified.
    // UNRESOLVED: strcmp is not listed as a packet callee; the comparison routine's identity is inferred from the raw source only.
}
