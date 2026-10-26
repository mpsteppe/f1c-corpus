## PhysicsSubComponentDestroy_00448570 — PhysicsSubComponentDestroy

**Summary:** Destroys and frees 5 physics sub-component pointers: 4 sequential at offsets 0x4C-0x58 (indices 19-22), plus one at 0x5C (index 23). Each non-null pointer is destroyed via PhysicsSubComponentDestroy then freed via FreeWrapper_7bcf. Called from PhysicsBufferFree.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PhysicsBufferFree (00449340)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4C | RW | 0 | physics sub-component pointer 0 (index 19), destroyed & freed if non-null |
| this | 0x5C | RW | 0 | physics sub-component pointer 4 (index 23), destroyed & freed if non-null |

**Written-by note (persistence):**
- this 0x4C: cleared to 0 after free; part of destroy cycle
- this 0x5C: cleared to 0 after free; part of destroy cycle

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00448570 | PhysicsSubComponentDestroy | recursive destroy of sub-component |
| 00587bcf | FreeWrapper_7bcf | frees allocated memory for sub-component |

**Guard conditions:** Each of the 5 pointers (offsets 0x4C, 0x50, 0x54, 0x58, 0x5C) is checked for non-null before destroy/free. Null pointers are skipped.
