// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00540940
// Canonical corpus name: sub_540940
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_540940_00540940.c

void UnknownObject::AllocateAtlasRegion()
{
    // Allocates rectangular regions in a texture atlas from two free-space lists. Allocates a 36-byte horizontal region node and a 28-byte vertical region node via OperatorNewNhMallocWrapper, configures their flags/width/height/bounds from the request object, and links them into sorted doubly-linked free lists keyed by remaining space. When a fit is found the caller-side node state is advanced; on validation failure it reports aErrorCreatingV through sub_53C590 and returns -1.
    // CALL: Allocate a 36-byte horizontal region node via OperatorNewNhMallocWrapper and zero-initialize all nine dwords. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Store the horizontal node pointer into the request object (a2[7], anchored through *(this+0x118C)+0x14) and initialize node fields: flags from a2[14], width default 1234, height default 64. [field:*(*(this+0x118C)+0x14):0x00000000, field:*(*(this+0x118C)+0x14):0x00000004, field:*(*(this+0x118C)+0x14):0x00000008, field:*(this+0x118C):0x00000014, field:this:0x0000118C]
    // CALL: Allocate a 28-byte vertical region node via OperatorNewNhMallocWrapper and zero-initialize all seven dwords. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Store the vertical node pointer into the request object (a2[9]) and initialize it: flags from a2[14] with bit-0x20 normalization (clear bit 0x20, set bit 0x1 when it was set) and bound from a2[4]. The allocator list state at this+0x1154 is zero-initialized. [field:this:0x00001154, source:raw]
    // GUARD: Branch on the allocator-enabled flag at this+0x13DC; when unset the pre-allocated nodes are validated directly without list insertion. [field:this:0x000013DC, source:raw]
    // CALCULATION: Select the horizontal free-list head by dimension flag: this+0x1158 when bit 0x20 of a2[14] is set, otherwise this+0x1150. Compute the effective bound as max(selected head bound, requested a2[2]) and read the secondary dimension from this+0x1160. [field:this:0x00001150, field:this:0x00001158, field:this:0x00001160, source:raw]
    // LOOP: Walk the horizontal free list while the requested width exceeds the node's free space (node bound minus node current offset), advancing through the node next-link field (offset 0x18) and the list-head next-link (offset 0x1C) until a fit is found or the list ends. [field:*(*(this+0x118C)+0x14):0x00000018, field:*(this+0x1154):0x0000001C, field:*(this+0x1154):0x00000074, source:raw]
    // ASSIGNMENT: When no horizontal node fits, allocate a new 36-byte node via OperatorNewNhMallocWrapper, append it at the list tail with back/forward links, and initialize it with the effective bound, flags from a2[14], width 1234 and height 64. [callee:0x00587C03, field:*(this+0x1154):0x00000058, field:*(this+0x1154):0x0000005C, source:raw]
    // CALL: Validate the horizontal placement with sub_540DF0; a non-zero result aborts with -1. [callee:0x00540DF0]
    // CALCULATION: Consume horizontal space: report the node's current offset to the request (a2[11]), advance the node offset by a2[2], and store the node's assigned region id back into the request node. [field:*(this+0x1154):0x00000060, field:*(this+0x1154):0x00000064, source:raw]
    // LOOP: Walk the vertical free list from this+0x1164 while the requested height exceeds the node's free space (node bound minus node offset), advancing through the node next-link fields (offsets 0x28, 0x2C, 0x38) until a fit is found or the list ends. [field:*(this+0x1154):0x00000028, field:*(this+0x1154):0x0000002C, field:*(this+0x1154):0x00000038, source:raw]
    // ASSIGNMENT: When no vertical node fits, allocate a new 28-byte node via OperatorNewNhMallocWrapper, append it at the vertical list tail (head at this+0x1164) with back/forward links, and initialize its flags and bound; the node bound field at offset 0x54 is written. [callee:0x00587C03, field:this:0x00001164, field:*(this+0x1154):0x00000054, source:raw]
    // CALL: Validate the vertical placement with sub_540FC0; a non-zero result aborts with -1. [callee:0x00540FC0]
    // CALCULATION: Consume vertical space: report the node's current offset to the request (a2[12]), advance the node offset by a2[4], and store the node's assigned region id into the request node. [field:*(this+0x1154):0x00000060, field:*(this+0x1154):0x00000064, source:raw]
    // RETURN: Return 0 on successful two-list allocation. [function:0x00540940, source:raw]
    // CALL: Disabled-allocator path: validate the horizontal node (a2[7]) with sub_540DF0 and the vertical node (a2[9]) with sub_540FC0; on any failure log aErrorCreatingV through sub_53C590 and return -1, otherwise clear the reported offsets and return 0. [callee:0x0053C590, callee:0x00540DF0, callee:0x00540FC0, global:0x005DBD40, source:raw]

    // Conservative worker pseudocode:
    //   horiz = alloc_zeroed(36); req->horiz = horiz;
    //   horiz->flags = req->flags; horiz->width = 1234; horiz->height = 64;
    //   vert = alloc_zeroed(28); req->vert = vert;
    //   vert->flags = norm(req->flags); vert->bound = req->height;
    //   if (this->allocator_enabled) {
    //     head = pick_horiz_head(req->flags); bound = max(head_bound, req->width);
    //     node = walk_horiz(head, req->width);
    //     if (!node) { node = alloc_zeroed(36); splice_tail(head, node); init(node, bound, 1234, 64); }
    //     if (sub_540DF0(node)) return -1;
    //     req->horiz_off = node->off; node->off += req->width;
    //     node2 = walk_vert(req->height);
    //     if (!node2) { node2 = alloc_zeroed(28); splice_tail(&this->vert_list, node2); init(node2, bound2); }
    //     if (sub_540FC0(node2)) return -1;
    //     req->vert_off = node2->off; node2->off += req->height;
    //     return 0;
    //   }
    //   if (sub_540DF0(req->horiz) || sub_540FC0(req->vert)) { sub_53C590(-1, aErrorCreatingV); return -1; }
    //   req->horiz_off = 0; req->vert_off = 0; return 0;
    // UNRESOLVED: Read-only fields at this+0x1178, this+0x117C and this+0x1180 are not referenced by the visible decompiled body; their role in the allocator/request object is unknown.
    // UNRESOLVED: Callers sub_54CA00 and sub_557670 invoke this allocator but contribute no field-level evidence to this packet.
    // UNRESOLVED: The exact node layout (which offsets belong to the horizontal versus vertical free-list nodes) is ambiguous from the field bases; the deterministic bases *(*(this+0x118C)+0x14) and *(this+0x1154) were kept as-is.
}
