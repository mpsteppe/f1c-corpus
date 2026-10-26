## LinkedListPurgeByThreshold_0045ebd0 — LinkedListPurgeByThreshold

**Summary:** Purges excess entries from a linked list when count exceeds 64. Walks from head, unlinks and frees excess nodes (including data if node flag is set). Keeps list size at or below threshold.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommSessionMessageDispatcher (0045d890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1B770) | 0x0 | R | — | Head node's data pointer (used to free data) |
| *(this+0x1B774) | 0x0 | R | — | Last/iterator node (used for unlinking) |
| this | 0x1B770 | RW | — | Head pointer of linked list (updated after removal) |
| this | 0x1B774 | RW | — | Last/iterator pointer (updated after removal) |
| this | 0x1B778 | RW | 0 | Tail pointer (updated if removing tail) |
| this | 0x1B77C | R | — | Count/size of linked list (compared to threshold 64) |

**Written-by note (persistence):**
- this 0x1B770: conditional — updated if head node is removed; persists until next purge
- this 0x1B774: conditional — updated if iterator node is removed; persists
- this 0x1B778: conditional — set to 0 if tail node removed; persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free heap-allocated memory for nodes and their data |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1B770 | == | 0 | Head pointer null check |

**Guard interpretation:**
- this[0x1B77C/4] (count) <= 64 → skip purge entirely.
- count > 64 → purge (count - 64) nodes from head.
- For each purged node:
  - head pointer null (this[28124] == 0) → skip node.
  - head node's data pointer null → skip data freeing but still unlink.
  - node flag at +0x08 == 0 → skip data freeing; flag != 0 → free data via FreeWrapper_7bcf.
  - Always unlink node and free node allocation.
  - If head node = tail node → update tail pointer.
  - If head node = iterator pointer → update iterator pointer.
