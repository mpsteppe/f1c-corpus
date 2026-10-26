// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041E840
// Canonical corpus name: NestedDataSectionFieldAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NestedDataSectionFieldAccessor_0041e840.c

void UnknownObject::NestedDataSectionFieldAccessor()
{
    // Nested null-guarded accessor over a linked structure rooted at the global dword_7D2DB0: dereferences the list node, extracts a secondary object via FixedOffsetReturn, then dereferences a fresh node and reads the dword at offset +408 of the second FixedOffsetReturn result. Returns 0 at either null guard. Called from AITargetDriverSelection (0x00418EE0).
    // CALL: Call LinkedListDereference(&dword_7D2DB0) to dereference the linked-list root stored in the global dword_7D2DB0. [callee:0x004C2850, global:0x007D2DB0]
    // GUARD: Guard on the dereferenced node: if it is null, return 0 immediately. [source:raw]
    // CALL: Call LinkedListDereference(&dword_7D2DB0) a second time to re-read the node, capturing it as v0. [callee:0x004C2850]
    // CALL: Call FixedOffsetReturn(v0) to derive a target object from the node. [callee:0x004C1390]
    // GUARD: Guard on the FixedOffsetReturn result: if it is null, return 0 immediately. [source:raw]
    // CALL: Call LinkedListDereference(&dword_7D2DB0) a third time, capturing the node as v1. [callee:0x004C2850]
    // CALL: Call FixedOffsetReturn(v1) to derive the object whose field will be read. [callee:0x004C1390]
    // CALCULATION: Form the address of the field: FixedOffsetReturn(v1) + 408. [source:raw]
    // RETURN: Return the dword read at FixedOffsetReturn(v1) + 408. [source:raw]

    // Conservative worker pseudocode:
    //   int NestedDataSectionFieldAccessor() {
    //     if (!LinkedListDereference(&dword_7D2DB0))
    //       return 0;
    //     int v0 = LinkedListDereference(&dword_7D2DB0);
    //     if (!FixedOffsetReturn(v0))
    //       return 0;
    //     int v1 = LinkedListDereference(&dword_7D2DB0);
    //     return *(int *)(FixedOffsetReturn(v1) + 408);
    //   }
    // UNRESOLVED: dword_7D2DB0 is an unnamed linked-list/container head; the node type is unknown.
    // UNRESOLVED: Semantics of FixedOffsetReturn (offset transformation vs. base-class offset resolution) are not evident here.
    // UNRESOLVED: The repeated LinkedListDereference(&dword_7D2DB0) calls may observe a mutating global or reflect decompiler reuse; either way the field at +408 of the final result is what is returned.
    // UNRESOLVED: Semantic meaning of the dword at +408 is unproven; the caller AITargetDriverSelection (0x00418EE0) hints at AI-target data but this is not established.
}
