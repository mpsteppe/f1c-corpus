// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057ACB0
// Canonical corpus name: sub_57ACB0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57ACB0_0057acb0.c

void UnknownObject::ModuleListFindAndRemoveNode()
{
    // Searches the global module doubly-linked list for the node whose data pointer equals a1, unlinks it, updates head/tail globals, decrements the pool counter, and frees both the node and (if the node flag byte at +12 is set) its owned data object. Also calls a vtable method on the a1 sub-object retrieved via FieldGetter_5cc0 and runs EmptyStub_0170. Returns 0 on successful removal, 1 on empty list or not-found.
    // CALL: Retrieve the sub-object of *a1 via FieldGetter_5cc0 and call its vtable method at offset 4 on the result. [callee:0x00585CC0, field:this:0x00000000, source:raw]
    // CALL: Call the no-op EmptyStub_0170. [callee:0x004B0170, source:raw]
    // ASSIGNMENT: Read the global list head dword_8D3BFC into the walk pointer v2. [global:0x008D3BFC, source:raw]
    // GUARD: Return 1 when the list head dword_8D3BFC is null (empty list). [global:0x008D3BFC, source:raw]
    // LOOP: Walk the list via next pointers v2[1] comparing each node's data pointer *v2 with a1; return 1 if the scan exhausts without a match. [source:raw]
    // ASSIGNMENT: If the matched node equals the tail dword_8D3C04, advance that tail to the node's successor v2[1]. [global:0x008D3C04, source:raw]
    // ASSIGNMENT: Unlink the node from its predecessor: set prev-of-successor v2[1] to the node's predecessor v2[2], or update head dword_8D3BFC when there is no predecessor. [global:0x008D3BFC, source:raw]
    // ASSIGNMENT: Unlink the node from its successor: set next-of-predecessor v2[2] to the node's successor v2[1], or update tail dword_8D3C00 when the node was the tail. [global:0x008D3C00, source:raw]
    // CALCULATION: Decrement the pool allocation counter dword_8D3C08. [global:0x008D3C08, source:raw]
    // GUARD: When the node's flag byte at +12 is set and its data pointer *v2 is non-null, destroy the data object via VTableDestructorThenNullPointer and free it. [callee:0x0057A4C0, source:raw]
    // CALL: Free the node (and its owned data object when owned) via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // RETURN: Return 0 on successful removal, 1 on empty list or not-found. [function:0x0057ACB0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_57ACB0(_DWORD *a1) {
    //     int sub = FieldGetter_5cc0(*a1);
    //     (*(void (__thiscall **)(int))(*(_DWORD*)sub + 4))(sub);
    //     EmptyStub_0170();
    //     _DWORD *v2 = dword_8D3BFC;
    //     if (!dword_8D3BFC) return 1;
    //     while (*v2 != a1) { v2 = v2[1]; if (!v2) return 1; }
    //     if (v2 == dword_8D3C04) dword_8D3C04 = v2[1];
    //     if (v2[2]) *(v2[2]+4) = v2[1]; else dword_8D3BFC = v2[1];
    //     if (v2[1]) *(v2[1]+8) = v2[2];
    //     if (dword_8D3C00 == v2) dword_8D3C00 = v2[2];
    //     --dword_8D3C08;
    //     if (*(byte*)v2 + 12) { if (*v2) { VTableDestructorThenNullPointer(*v2); FreeWrapper_7bcf(*v2); } }
    //     FreeWrapper_7bcf(v2);
    //     return 0;
    //   }
    // UNRESOLVED: Purpose of the vtable method at offset 4 invoked on the FieldGetter_5cc0 result is unknown.
    // UNRESOLVED: Ownership semantics of the node flag byte at +12 (owned data object vs. external) are inferred only from the destructor branch.
    // UNRESOLVED: Relationship to caller PointerCheckWithFallback (0x0057AB20) is not established.
}
