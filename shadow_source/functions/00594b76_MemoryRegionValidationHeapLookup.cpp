// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00594B76
// Canonical corpus name: MemoryRegionValidationHeapLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemoryRegionValidationHeapLookup_00594b76.c

void UnknownObject::MemoryRegionValidationHeapLookup()
{
    // Walks a doubly-owned linked list of memory regions rooted at the sentinel off_5E7968 to test whether address a1 falls strictly inside a region. If found and a1 is 16-byte aligned with a page offset >= 0x100, stores the owning region node into *a2 and the page-aligned base into *a3, then returns a derived address; otherwise returns 0. On-frame-path allocation/ownership validation helper.
    // LOOP: Walk the region linked list starting at the sentinel off_5E7968; continue while a1 is not strictly inside the current node's bounds (node[4] at +0x10 as start, node[5] at +0x14 as end): while (a1 <= node[4] || a1 >= node[5]). [global:0x005E7968, source:raw]
    // GUARD: If the walk returns to the sentinel off_5E7968, the address is not owned by any region: return 0. [global:0x005E7968, source:raw]
    // GUARD: Accept only 16-byte-aligned addresses with a page offset >= 0x100: (a1 & 0xF) == 0 && (a1 & 0xFFF) >= 0x100. [source:raw]
    // ASSIGNMENT: Store the owning region node into *a2 and the page-aligned base (a1 & 0xFFFFF000) into *a3. [source:raw]
    // RETURN: Compute and return the derived address: ((a1 - pageBase - 256) >> 4) + pageBase + 8. [source:raw]
    // RETURN: Fallback return of 0 when the address is unaligned or below 0x100 within its page. [source:raw]
    // CALL: Called by sub_58AA6F (0x0058AA6F), sub_58B5D4 (0x0058B5D4) and sub_58BB68 (0x0058BB68), consistent with an allocation/ownership validation helper. [caller:0x0058AA6F, caller:0x0058B5D4, caller:0x0058BB68, source:raw]

    // Conservative worker pseudocode:
    //   uint32 sub_594B76(uint32 addr, void** regionNode, uint32* pageBase) {
    //     void** node = &off_5E7968;
    //     while (addr <= (uint32)node[4] || addr >= (uint32)node[5]) {
    //       node = *node;
    //       if (node == &off_5E7968) return 0;
    //     }
    //     if ((addr & 0xF) == 0 && (addr & 0xFFF) >= 0x100) {
    //       *regionNode = node;
    //       *pageBase = addr & 0xFFFFF000;
    //       return ((addr - (addr & 0xFFFFF000) - 256) >> 4) + (addr & 0xFFFFF000) + 8;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Region node layout: v3[4]/v3[5] at byte offsets +0x10/+0x14 interpreted as region start/end bounds is DERIVED from the loop condition, not independently verified.
    // UNRESOLVED: Meaning of the returned derived-address formula is unknown; *a2/*a3 output semantics are inferred from the writes.
    // UNRESOLVED: Caller context for sub_58AA6F, sub_58B5D4 and sub_58BB68 is not available.
}
