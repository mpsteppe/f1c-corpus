// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00545D00
// Canonical corpus name: sub_545D00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_545D00_00545d00.c

void UnknownObject::applyFlagDrivenTraversal()
{
    // Flag-driven scene data traversal and update. Depending on the a2/a3 flag bits: zeroes this+0x1B0 when a2 has bit 0x20, ORs this+0xEC with 0x800 when a3 has bit 0x20, walks the node list at this+0x100 (and the node at this+0x108) invoking RecursiveTraversal, propagates 0x40/0x80/0xC0 flag bits through a chain reached via this+0x110, then processes up to four (count, pointer-array) pairs at this+0x1B4..0x1D0 clearing per-element flag/fields selected by the a3 0x1800 mask. Called by sub_4FA7E0.
    // ASSIGNMENT: When a2 has bit 0x20 set, zero the DWORD at this+0x1B0 (this[108]). [field:this:0x000001B0, source:raw]
    // ASSIGNMENT: Otherwise, when the low byte of a3 has bit 0x20 set, OR the DWORD at this+0xEC (this[59]) with 0x800. [field:this:0x000000EC, source:raw]
    // LOOP: Walk the node list whose head is this+0x100 (this[64]); for each node (next link stored at node+0x104) whose DWORD at node+0xEC is non-zero, call RecursiveTraversal(a2, a3, 0). [field:this:0x00000100, callee:0x0054BCD0, source:raw]
    // GUARD: If the node pointer at this+0x108 (this[66]) is non-null, call RecursiveTraversal(a2, a3, 0) on it. [field:this:0x00000108, callee:0x0054BCD0, source:raw]
    // LOOP: Follow the chain rooted at (*(this+0x110) + 36); while a node is non-null, set or clear flag bits 0x40, 0x80 or 0xC0 at node+0x9C according to the a2 & 0x1800 and a3 & 0x1800 masks (0x40 for 0x800, 0x80 for 0x1000, 0xC0 for 0x1800), advancing via the link stored at node+0xC0. [field:this:0x00000110, source:raw]
    // LOOP: For each of the four (count, pointer-array) pairs at this+0x1B4/0x1B8, this+0x1BC/0x1C0, this+0x1C4/0x1C8 and this+0x1CC/0x1D0 (this[109..116]): when the count is positive, iterate that many elements of the array using a 132-byte stride. [field:this:0x000001B4, field:this:0x000001B8, field:this:0x000001BC, field:this:0x000001C0, field:this:0x000001C4, field:this:0x000001C8, field:this:0x000001CC, field:this:0x000001D0, source:raw]
    // STATE_TRANSITION: Per element, dispatch on the a3 & 0x1800 mask (jump table at global 0x545F24): for 0x800 clear the element's 0x400 flag; for 0x1000 walk 8 sub-slots (stride 16 DWORDs) zeroing slot fields when the first sub-slot DWORD equals 8; for 0x1800 do both. [global:0x00545F24, source:raw]
    // RETURN: Return the last processed element count. [source:raw]

    // Conservative worker pseudocode:
    //   int applyFlagDrivenTraversal(int a2, void* a3) {
    //     if (a2 & 0x20) this[108] = 0;
    //     else if (a3 & 0x20) this[59] |= 0x800;
    //     for (node = this[64]; node; node = node->next)
    //       if (node->flag) RecursiveTraversal(a2, a3, 0);
    //     if (this[66]) RecursiveTraversal(a2, a3, 0);
    //     for (chain = *(this[68] + 36); chain; chain = chain->link) {
    //       set/clear chain->flags (0x40/0x80/0xC0) per a2/a3 mask;
    //     }
    //     for (i = 0; i < 4; ++i) {
    //       (count, arr) = pair(i);
    //       for (e = 0; e < count; ++e) {
    //         switch (a3 & 0x1800) {
    //           case 0x800: arr[e].flags &= ~0x400; break;
    //           case 0x1000: clear 8 sub-slots whose value == 8; break;
    //           case 0x1800: arr[e].flags &= ~0x400; clear 8 sub-slots; break;
    //         }
    //       }
    //     }
    //     return count;
    //   }
    // UNRESOLVED: The deterministic facts attribute the 0x9C/0xC0 flag-chain to base *(this+0x134) (fields *(this+0x134):0x9C and *(*(this+0x134)+0xC0):0xC0, plus this+0x134), while the Hex-Rays rendering roots it at *(this+0x110)+36; the two bases cannot be reconciled from this packet alone.
    // UNRESOLVED: The node-list fields are likewise attributed to base *(this+0x204) (offsets 0xEC and 0x104) by the facts, whereas the source renders them relative to the list node; base mismatch unresolved.
    // UNRESOLVED: Guard on field this+0x1F4 == 8 and the RW fields this+0x1F4, this+0x1F8, this+0x200 are present in the facts but have no visible operation in the raw source text; their role is unproven (possibly an element/version gate for the clearing loop).
    // UNRESOLVED: Owner class and the concrete meaning of the a2/a3 flag masks (0x20, 0x1800) are unconfirmed.
}
