## LinkedListSearchRemoval_004c4bb0 — Remove list nodes failing filter criteria

**Summary:** Iterates a linked list of vehicle index nodes; removes nodes whose vehicle field at offset 0x1BC does not match ALL specified filter criteria. Returns remaining count.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4C4D50 (004c4d50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x0 | R | — | Data pointer in head node (vehicle index int) |
| *(this+0xC) | 0x0 | R | — | Data pointer in tail node |
| *(this+0xC) | 0x4 | R | — | Next pointer in tail node |
| *(this+0xC) | 0x8 | R | — | Free-flag byte in tail node (if set, free data too) |
| this | 0x8 | RW | — | Head pointer of linked list; updated if first node removed |
| this | 0xC | RW | — | Tail pointer of linked list; updated if tail removed |
| this | 0x10 | RW | — | Current iteration pointer used during traversal |
| this | 0x14 | R | — | Count of items in linked list |

**Written-by note (persistence):**
- this 0x8: updated if head node is removed during filtering
- this 0xC: updated if tail node is removed
- this 0x10: rewritten each iteration as traversal advances; final value is head (line 71)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566810 | sub_566810 | Compare vehicle field at offset 0x1BC against a filter value; returns 0 on match |
| 00587bcf | FreeWrapper_7bcf | Free allocated memory (node data if flag set, then node itself) |

**Guard conditions:** Entry blocked if `*a2` (first filter value) is zero or `a3` (filter count) <= 0. Inner loop: per node, vehicle compared against each filter via `sub_566810` — if all pass (all return 0), node preserved; if any fails (returns nonzero), node is unlinked and freed.
