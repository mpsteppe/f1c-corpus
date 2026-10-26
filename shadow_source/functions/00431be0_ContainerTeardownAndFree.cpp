// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00431BE0
// Canonical corpus name: sub_431BE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_431BE0_00431be0.c

void UnknownObject::ContainerTeardownAndFree()
{
    // Tears down a container object reachable through the global dword_7C73E0. When the global holds a non-null pointer it walks and frees two singly-linked lists (heads at object+48 and object+32, next pointer at node+4) via DoublePointerFree + FreeWrapper_7bcf, zeroes those four-slot field groups, conditionally frees the members at +16, +8 and +0, and finally frees the container itself. On a null global it falls through to return an uninitialized result value.
    // GUARD: Read dword_7C73E0[0] into v0; if nonzero enter the teardown path, otherwise fall through to return the uninitialized result. [global:0x007C73E0, source:raw]
    // LOOP: Walk the linked list starting at *(v0+48); for each node save the next pointer from node+4, then free the node via DoublePointerFree and FreeWrapper_7bcf until the cursor is null. [global:0x007C73E0, source:raw]
    // ASSIGNMENT: Zero the four-slot field group at v0+48, v0+52, v0+56 and v0+60 (list head and associated counters). [global:0x007C73E0, source:raw]
    // LOOP: Walk the linked list starting at *(v0+32); for each node save the next pointer from node+4, then free the node via DoublePointerFree and FreeWrapper_7bcf until the cursor is null. [global:0x007C73E0, source:raw]
    // ASSIGNMENT: Zero the four-slot field group at v0+32, v0+36, v0+40 and v0+44 (list head and associated counters). [global:0x007C73E0, source:raw]
    // CALL: If *(v0+16) is nonzero, free that member pointer with FreeWrapper_7bcf. [global:0x007C73E0, source:raw]
    // CALL: If *(v0+8) is nonzero, free that member pointer with FreeWrapper_7bcf. [global:0x007C73E0, source:raw]
    // CALL: If *(v0) is nonzero, free that member pointer with FreeWrapper_7bcf. [global:0x007C73E0, source:raw]
    // RETURN: Free the container object itself with FreeWrapper_7bcf(v0) and return its result; the null-global path returns the uninitialized local result. [global:0x007C73E0, function:0x00431BE0, source:raw]

    // Conservative worker pseudocode:
    //   v0 = dword_7C73E0[0];
    //   if (v0 == 0) return result; /* result is uninitialized on this path * /
    //   for (v1 = *(v0+48); v1; ) { v2 = v1; v1 = *(v1+4); DoublePointerFree(v2); FreeWrapper_7bcf(v2); }
    //   *(v0+48) = *(v0+52) = *(v0+56) = *(v0+60) = 0;
    //   for (v3 = *(v0+32); v3; ) { v4 = v3; v3 = *(v3+4); DoublePointerFree(v4); FreeWrapper_7bcf(v4); }
    //   *(v0+32) = *(v0+36) = *(v0+40) = *(v0+44) = 0;
    //   if (*(v0+16)) FreeWrapper_7bcf(*(v0+16));
    //   if (*(v0+8)) FreeWrapper_7bcf(*(v0+8));
    //   if (*(v0)) FreeWrapper_7bcf(*(v0));
    //   return FreeWrapper_7bcf(v0);
    // UNRESOLVED: DoublePointerFree and FreeWrapper_7bcf are named in the raw source but have no callee address evidence in the packet; they are described from source text only.
    // UNRESOLVED: The null-global path returns an uninitialized result value; this is the decompiled artifact as-is, not an invented default.
    // UNRESOLVED: Container type and whether dword_7C73E0 is a singleton owner or a general pointer are not established by the packet.
    // UNRESOLVED: The purpose of the second free call per node (DoublePointerFree then FreeWrapper_7bcf) is unknown.
}
