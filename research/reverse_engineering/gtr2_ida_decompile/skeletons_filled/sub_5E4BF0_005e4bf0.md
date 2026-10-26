## sub_5E4BF0_005e4bf0 — texture release (refcounted)

**Summary:** Releases a texture object: walks the global list at dword_FB2D78 to find the entry, decrements the object's reference count at +0x6C, and when it drops to zero destroys the object (cleanup, list removal, vector destructor iteration, free). When the pointer is null or absent from the list it reports "Invalid texture pointer" through the error helper.

**Called by:** sub_41D570 (0041d570), sub_46E940 (0046e940), SeasonRacesSectionWriter [structural] (0046ebb0), sub_4E34F0 (004e34f0), sub_4E3680 (004e3680), sub_561D80 (00561d80), sub_562230 (00562230), sub_562F30 (00562f30), sub_567D00 (00567d00), sub_5F0BF0 (005f0bf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e2b00 | j_j_nullsub_7 | R | no-op element destructor passed to the vector destructor iterator (elements need no individual destruction) |
| 0072be2c | aInvalidTexture | R | "Invalid texture pointer" error-message string used on the failure path |
| 00fb2d78 | dword_FB2D78 | R | head of the singly linked list of live texture entries; each node = {object pointer, next pointer} |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d8c80 | sub_5D8C80 | error/report helper — emits the "Invalid texture pointer" message (id -1); its result becomes the -1 return |
| 005d9a40 | sub_5D9A40 | removes the texture entry from the dword_FB2D78 list (flag 1) |
| 005e6dd0 | sub_5E6DD0 | destruction-time cleanup of the texture object performed before freeing |
| 006308d3 | j__free | CRT free of the allocation header (a2 - 4) |
| 0063093b | ??_M@YGXPAXIHP6EX0@Z@Z | MSVC `eh vector destructor iterator' — iterates the object array (0xD8-byte elements) invoking the element destructor |

**Guard conditions:** Requires `a2` non-null, `dword_FB2D78` non-null, and `a2` present in the list (node whose object pointer equals a2) — any of these failing jumps to LABEL_6, which calls sub_5D8C80(this, -1, "Invalid texture pointer") and returns -1. When found, only the refcount decides destruction: the object is torn down (sub_5E6DD0, a2[140]=0, list removal, destructor iterator, free) solely if the post-decrement refcount reaches 0 (pre-decrement value 1); a still-positive count leaves the object alive and the function returns 0.

**String literals referenced (deterministic):**

- `Invalid texture pointer`
