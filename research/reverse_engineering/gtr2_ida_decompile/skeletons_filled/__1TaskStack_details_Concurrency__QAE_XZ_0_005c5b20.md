## ??1TaskStack@details@Concurrency@@QAE@XZ_0_005c5b20 — TaskStack destructor

**Summary:** Destructor for Concurrency::details::TaskStack; frees the owned heap buffer pointer at this[2] (offset 0x8). Part of the Concurrency runtime (PPL/task scheduler support).

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | heap buffer pointer owned by this TaskStack (freed here) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006308d3 | j__free | frees the owned buffer at this[2] |

**Guard conditions:** `if (this[2])` — frees only when the pointer at offset 0x8 is non-null; a null pointer skips the free (no-op).
