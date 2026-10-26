// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C7E80
// Canonical corpus name: sub_4C7E80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C7E80_004c7e80.c

void UnknownObject::DestroyLinkedList()
{
    // Destroys a linked list rooted at the object's list-header pointer (this+0xC). The header holds head (0x0), tail (0x4), cursor (0x8) and count (0xC). The walk frees every node with FreeWrapper_7bcf; each node whose alive-flag byte at +8 is non-zero (and whose content pointer at +0 is non-null) has its vtable destructor invoked with argument 1 first. After a defensive second traversal, the header itself is freed, its four fields are zeroed, and this+0xC is set to NULL. Called by Sound_Post (004C8CA0).
    // GUARD: Read the list header v1 = *(this+0xC); if it is NULL the function does nothing. [field:this:0x0000000C, source:raw]
    // GUARD: If the header's head pointer *v1 is non-null, enter the first traversal over the node chain. [field:*(*(this+0xC)+0x0):0x00000000, source:raw]
    // LOOP: First traversal: for each node read its next pointer at +4 and alive-flag byte at +8; when the flag is non-zero (guard v4 false) and the content pointer at +0 is non-null, invoke the content vtable destructor with argument 1; then free the node with FreeWrapper_7bcf and continue while the next pointer is non-null. [field:*(*(*(*(this+0xC)+0x0)+0x0)+0x0):0x00000000, field:*(*(*(this+0xC)+0x0)+0x0):0x00000000, field:*(*(*(this+0xC)+0x0)+0x4):0x00000004, field:*(*(this+0xC)+0x0):0x00000008, guard:0, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Clear the list-header fields: head, tail, cursor and count at header offsets 0x0, 0x4, 0x8 and 0xC are all zeroed. [field:*(this+0xC):0x00000000, field:*(this+0xC):0x00000004, field:*(this+0xC):0x00000008, field:*(this+0xC):0x0000000C, source:raw]
    // LOOP: Defensive second traversal over the re-read header: for each remaining node call the content vtable destructor with argument 1 when the +8 alive flag is non-zero and the +0 content pointer is non-null, free the node with FreeWrapper_7bcf, then zero the header fields again and free the header itself. [field:*(*(*(*(this+0xC)+0x0)+0x0)+0x0):0x00000000, field:*(*(*(this+0xC)+0x0)+0x0):0x00000000, field:*(*(*(this+0xC)+0x0)+0x4):0x00000004, field:*(*(this+0xC)+0x0):0x00000008, guard:0, callee:0x00587BCF, field:*(this+0xC):0x00000000, field:*(this+0xC):0x00000004, field:*(this+0xC):0x00000008, field:*(this+0xC):0x0000000C, source:raw]
    // ASSIGNMENT: Set this+0xC to 0 so the object no longer references the freed header, and return the header-free result. [field:this:0x0000000C, source:raw]
    // RETURN: Return the result of FreeWrapper_7bcf on the freed list header (the second traversal path), which is garbage-initialized on paths that do not reach that call. [function:0x004C7E80, source:raw]
    // CALL: Invoked by Sound_Post (004C8CA0) to tear down the object's node list. [caller:0x004C8CA0, source:raw]

    // Conservative worker pseudocode:
    //   hdr = *(this + 0xC);
    //   if (!hdr) return garbage;
    //   node = *hdr;
    //   while (node) {
    //     n = node;
    //     alive = *(node + 8) != 0;
    //     node = *(node + 4);
    //     if (alive && *n) (*(**n))(*n, 1);
    //     FreeWrapper_7bcf(n);
    //   }
    //   hdr[0] = 0; hdr[1] = 0; hdr[2] = 0; hdr[3] = 0;
    //   hdr = *(this + 0xC);
    //   if (hdr) {
    //     node = *hdr;
    //     while (node) {
    //       n = node;
    //       alive = *(node + 8) != 0;
    //       node = *(node + 4);
    //       if (alive && *n) (*(**n))(*n, 1);
    //       FreeWrapper_7bcf(n);
    //     }
    //     hdr[0] = 0; hdr[1] = 0; hdr[2] = 0; hdr[3] = 0;
    //     result = FreeWrapper_7bcf(hdr);
    //   }
    //   *(this + 0xC) = 0;
    //   return result;
    // UNRESOLVED: The first traversal already frees every node, making the second traversal and header-free appear redundant; this is treated as defensive/residual logic rather than a two-tier list model because no structural difference between the passes is evident
    // UNRESOLVED: The vtable destructor call signature (content object + integer argument 1) and the meaning of the +8 alive flag are inferred from the field layout only; no class contract is documented
    // UNRESOLVED: The return value on the header-NULL early path is an uninitialized register, visible in the decompiler as a garbage read
}
