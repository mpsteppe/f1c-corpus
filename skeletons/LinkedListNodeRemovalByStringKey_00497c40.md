## LinkedListNodeRemovalByStringKey_00497c40 — RemoveSurfaceNodeByName

**Summary:** Removes a node from the loaded-surface linked list (head at this+0x104) by matching name string `a2` against node name at offset 0x4. Unlinks, processes data via ThunkToFUN0053cb90, clears data field, frees name string and node. Returns 1 on successful removal, 0 if not found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ProfileIconBmpLoader (004692b0), CopyProfileIconBMP (0046cd20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x114) | 0x4 | R | — | Name string pointer at node offset 0x4 |
| *(this+0x114) | 0xC | RW | 0 | Data/resolved ID at node offset 0xC (cleared after processing) |
| *(this+0x114) | 0x10 | R | — | Next node pointer at node offset 0x10 |
| this | 0x104 | RW | — | Head pointer of surface linked list |
| this | 0x108 | R | — | Counter of registered surfaces |
| this | 0x114 | RW | — | Pointer to node being examined/manipulated |

**Written-by note (persistence):**
- *(this+0x114) 0xC: Written to 0 unconditionally on removal. External poke does not survive for removed node.
- this 0x104: Written if removing head node. External poke survives if removing non-head.
- this 0x114: Set during traversal to current node. External poke does not survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default name string when node name is null |
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00494fd0 | ThunkToFUN0053cb90 | Processes/cleans up node's data at offset 0xC |
| 00542e50 | sub_542E50 | Secondary cleanup (in unreachable path after data clear) |
| 00557470 | EmptyStub_7470 | Empty stub (in unreachable path) |
| 00587bcf | FreeWrapper_7bcf | Frees node memory and name string |
| 00588410 | sub_588410 | String comparison (returns 0 on match) |

**Guard conditions:** Head at this+0x104 must be non-null — null returns 0. During traversal, next pointer at node+0x10 checked for null — null returns 0 (not found).
