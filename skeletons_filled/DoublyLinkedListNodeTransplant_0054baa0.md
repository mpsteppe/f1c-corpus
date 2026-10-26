## DoublyLinkedListNodeTransplant_0054baa0 — Doubly-linked list node transplant to global list

**Summary:** Unlinks node `a2` from its current container list and inserts it at the tail of a global list (via `dword_8B8F28+264`). Transplants sublist if present.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ConditionalResourceRelease (004e0d70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x44 | RW | — | List head pointer (updated if a2 was the head) |

**Written-by note (persistence):**
- this 0x44: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr [DERIVED] (also: ` — unknown context/state pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00560f40 | DoublyLinkedNodeRemovalGlobalListReInsert | Transplants a node's sublist to the global list |

**Guard conditions:** Null checks on `a2[18]` (prev) and `a2[19]` (next) during unlink. If `dword_8B8F28` is null → skip global list insert entirely. If `a2[140]` (sublist) is null or `a2[16]` (container) or container's sublist is null → skip sublist transplant.
