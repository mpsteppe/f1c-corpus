// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00594AB4
// Canonical corpus name: sub_594AB4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_594AB4_00594ab4.c

void UnknownObject::TrimAllocatorFreePages()
{
    // Walks the allocator-context linked list and decommits free pages (page-table entries holding 240) via VirtualFree(MEM_DECOMMIT), up to a remaining page budget a1. Each successful decommit marks the page-table entry -1, decrements the live page counter dword_8D41B8, and optionally lowers the context's lowest-free pointer v1[3]. If one context's entire page table becomes -1 (all 1024 pages free), the context itself is destroyed via sub_594A5E. Called per frame by CounterThreshold (00594bcd).
    // ASSIGNMENT: v1 = off_5E796C: start the walk at the allocator-context list head. [global:0x005E796C, source:raw]
    // LOOP: Outer do-while walks the context linked list through the next pointer v1[1] until it wraps back to the head off_5E796C or the page budget a1 is exhausted. [global:0x005E796C, source:raw]
    // GUARD: Per-context guard: skip any context whose arena base v1[4] equals -1 (no valid arena). [source:raw]
    // ASSIGNMENT: Reset the per-context freed-page counter v8 = 0 and point v2 at the first page-table entry: v2 = v1 + 2052. [source:raw]
    // LOOP: Per-context page loop: i runs 4190208 down to 0 in 4096-byte steps, visiting each 4KB page of the arena; each page-table entry is two DWORDs wide (v2 -= 2 per iteration). [source:raw]
    // GUARD: Free-page guard: only pages whose entry *v2 equals 240 (free state) are eligible for decommit. [source:raw]
    // CALL: VirtualFree((LPVOID)(v1[4] + i), 0x1000, 0x4000): decommit the 4KB page with MEM_DECOMMIT (0x4000); the page is only freed when the call succeeds. [global:0x0059E0A4, source:raw]
    // ASSIGNMENT: On successful decommit: mark the page-table entry *v2 = -1 and decrement the live page counter dword_8D41B8. [global:0x008D41B8, source:raw]
    // GUARD: Lowest-free pointer update: if v1[3] is unset or still above the newly freed entry, set v1[3] = v2. [source:raw]
    // CALCULATION: Increment the freed-page counter v8 and decrement the remaining page budget a1; break out of the page loop when the budget reaches zero. [source:raw]
    // GUARD: After each context: if at least one page was freed (v8) and the context's page-count entry v5[6] is -1, run the all-free confirmation scan. [source:raw]
    // LOOP: Scan v6 = v5 + 8 across entries 1..1023, stepping v6 += 2, to confirm every remaining page-table entry is -1. [source:raw]
    // CALL: sub_594A5E(v5): destroy the entire allocator context when all 1024 page entries are free. [callee:0x00594A5E, source:raw]
    // RETURN: Void function; nothing is returned. [function:0x00594AB4, source:raw]

    // Conservative worker pseudocode:
    //   void TrimAllocatorFreePages(int budget) {
    //     ctx = off_5E796C;
    //     do {
    //       if (ctx[4] != -1) {
    //         freed = 0;
    //         entry = ctx + 2052;
    //         for (i = 4190208; i >= 0; i -= 4096) {
    //           if (*entry == 240 && VirtualFree((void*)(ctx[4] + i), 0x1000, 0x4000)) {
    //             *entry = -1;
    //             --dword_8D41B8;
    //             if (!ctx[3] || ctx[3] > entry) ctx[3] = entry;
    //             ++freed;
    //             if (!--budget) break;
    //           }
    //           entry -= 2;
    //         }
    //         next = ctx;
    //         ctx = next[1];
    //         if (freed && next[6] == -1) {
    //           scan = next + 8;
    //           for (j = 1; j < 1024; ++j) {
    //             if (*scan != -1) break;
    //             scan += 2;
    //           }
    //           if (j == 1024) sub_594A5E(next);
    //         }
    //       }
    //     } while (ctx != off_5E796C && budget > 0);
    //   }
    // UNRESOLVED: Meaning of the page-table state marker 240 as 'free' is inferred; raw source only compares the entry against 240.
    // UNRESOLVED: Allocator-context layout (arena base v1[4], list-next v1[1], lowest-free v1[3], page-count v1[6], 2-DWORD page entries) is DERIVED from existing analysis and not independently evidenced by this packet.
    // UNRESOLVED: sub_594A5E's destruction semantics beyond 'destroy entire context' are not visible in this packet.
}
