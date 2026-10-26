## SubBufferFree_00541420 — Sub-buffer free with virtual release

**Summary:** Releases two sub-buffers at this[1107] and this[1107]+36 via ObjectResetWithVirtualRelease, frees the base allocation via FreeWrapper_7bcf, and nulls the pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_544740 (00544740), AudioNetworkStreamCleanup (00544af0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x114C | RW | 0 | sub-buffer pointer (this[1107]) — points to allocated descriptor; read for release, set to 0 after |

**Written-by note (persistence):**
- this 0x114C: set to 0 after freeing — becomes null until re-allocated externally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540eb0 | ObjectResetWithVirtualRelease | resets/releases sub-buffer objects (two calls: for base and base+36) |
| 00587bcf | FreeWrapper_7bcf | frees the allocated descriptor memory (at pointer-4) |

**Guard conditions:** If this[1107] (0x114C) is null → skip all release work. Otherwise proceed with ObjectResetWithVirtualRelease twice, then FreeWrapper_7bcf, then set pointer to 0.
