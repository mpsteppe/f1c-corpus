## sub_4BF0A0_004bf0a0 — destructor/cleanup helper: frees owned buffer at +0x160

**Summary:** Cleanup routine that releases the heap buffer held at offset 0x160, runs a no-op cleanup on the embedded sub-object at +0x138, then tail-calls sub_491800 (destructor chain). Typical destructor body for an object owning a heap allocation.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x160 | R | — | Owned heap pointer; if non-null it is released with j_j__free |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e2ea8 | SEH_4BF0A0 | R | Exception-handling (SEH) scope record for this function |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00491800 | sub_491800 | Final cleanup/destructor-chain call; return value passed straight back to caller |
| 004eda30 | nullsub_7 | No-op placeholder invoked on sub-object at this+0x138 (empty cleanup/destructor) |
| 006308d8 | j_j__free | CRT free wrapper releasing the buffer stored at this+0x160 |

**Guard conditions:** `if (this[88] != 0)` — if the pointer at this+0x160 is non-null it is freed via j_j__free; if null the free is skipped. Execution always continues to nullsub_7 and the tail call — no early return.
