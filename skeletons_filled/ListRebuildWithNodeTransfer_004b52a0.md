## ListRebuildWithNodeTransfer_004b52a0 — ListRebuildWithNodeTransfer

**Summary:** Transfers all nodes from source list (this+0x20) to target list (this+0x10): searches for each source node by data pointer, unlinks it, frees type-1 buffers and node structs, allocates new node with same data pointer, prepends to target list. Sets sentinel at offset 0x30. Called during widget destroy and buffer pool init.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestroyUIWidgetHierarchy (004b5a30), BufferPoolAllocatorInitialization (004b71e0), sub_4B7500 (004b7500)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | — | Target list head pointer (new nodes prepended) |
| this | 0x14 | RW | — | Target list tail pointer (updated if first node) |
| this | 0x18 | RW | — | Target list anchor pointer (updated if first node) |
| this | 0x1C | R | — | Target list count (incremented per node transferred) |
| this | 0x20 | RW | — | Source list head pointer (nodes unlinked from here) |
| this | 0x24 | RW | — | Source list tail pointer (updated if last node removed) |
| this | 0x28 | RW | — | Source list cursor/anchor (traversal pointer) |
| this | 0x2C | R | — | Source list count (decremented per node removed) |
| this | 0x30 | RW | 18446744073658219970 | Sentinel value set to -51331646 (0xFCFCFC42) |

**Written-by note (persistence):**
- this 0x10: updated each iteration (prepend to target)
- this 0x14: set once if target list was empty
- this 0x18: set once if target list was empty
- this 0x20: updated each iteration (unlink from source)
- this 0x24: updated if last node removed
- this 0x28: updated each iteration (cursor = source head)
- this 0x30: written once — sentinel marker

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acd24 | dword_5ACD24 | R | D3DRenderDefaultColor — not directly used in this function |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | No-op stub called before freeing type-1 node buffer |
| 00587bcf | FreeWrapper_7bcf | Free node's data buffer (type-1) and node struct |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate new 12-byte node struct for target list |

**Guard conditions:**
1. If source list head (this[8] at offset 0x20) is null: return immediately (nothing to transfer).
2. If first source node's data pointer (*result at offset 0 of node) is null: return immediately.
3. Loop searches source list for node matching first data pointer. If match not found (v4 becomes null): skip to allocation/new node step (goto LABEL_19), node not unlinked but new node still created and prepended.
4. If new 12-byte node allocation fails (v7 = 0): node not linked into target list.
