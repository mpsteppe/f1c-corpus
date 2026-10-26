## sub_4BFCD0_004bfcd0 — pre-destructor cleanup: frees +0x1BC buffer, chains dtor

**Summary:** Cleanup routine that releases the owned heap buffer at offset 0x1BC, then chains into the destructor body (sub_4BF9E0) on the same object. Likely the derived-class destructor step preceding the base-class teardown.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1BC | R | — | Owned heap pointer; freed with j_j__free if non-null |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006308d8 | j_j__free | CRT free wrapper; releases the buffer owned at +0x1BC |

**Guard conditions:** `if (*(this+0x1BC) != 0)` — the buffer is freed only when non-null; a null pointer skips the free. Execution always continues into the chained destructor body — no early return.
