## SphereProximityTag_004bdb10 — SphereProximityTagUpdater

**Summary:** Iterates an array of objects (count at this[7], data at this[8]); for each object whose tag doesn't match a2, updates the tag and triggers UI focus change on the associated UI element.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SpriteGridRender (004be4e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | array element count |
| this | 0x20 | R | — | array data pointer to object pointers |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054f7a0 | UIFocusChange | change UI focus state on element |

**Guard conditions:** BLOCKED when object tag v8[1] (offset 4) == a2 (already matches). The `!(v10 | v11)` condition is uninitialized (decompilation artifact of x87 flags).
