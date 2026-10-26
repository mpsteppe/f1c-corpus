## LinkedListPopFront_5f50_00565f50 — reset iterator to first node

**Summary:** Sets list cursor (offset 8) to first node address (offset 0) — equivalent to pop front conceptually but repositions cursor rather than removing node. Returns true if list non-empty and first node has data. Used to begin file/directory enumeration.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceListCleanup (00404d50), FileEnumerationByExtension (00421b10), sub_45C0C0 (0045c0c0), sub_47BF30 (0047bf30), TGATextureFileScanner (004c3a00), VehicleFileLoader (004c3d80), SceneFileLoader (004c52c0), TireBrandLoader (004d7660), sub_565F80 (00565f80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x0 | R | — | first node's data pointer |
| obj | 0x0 | R | — | first node pointer |
| obj | 0x8 | RW | — | cursor (overwritten with first node) |
| this | 0x0 | R | — | pointer to list head structure |

**Written-by note (persistence):**
- obj 0x8: unconditionally overwritten with first node pointer; external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x0 | == | 0 | first node pointer — empty list check |

**Guard interpretation:** If obj+0x0 (first node) is NULL → list empty → cursor set to 0 and returns false. If non-NULL → cursor set to first node, returns true only if first node's data pointer is non-zero.
