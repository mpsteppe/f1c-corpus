## LinkedListNodePeek_00565f20 — advance linked list iterator to next node

**Summary:** Advances enumeration cursor: replaces list head's current node slot (obj+0x8) with next node (offset 4 of current node). Returns true if new node exists and has data. Used for sequential file/directory enumeration.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceListCleanup (00404d50), FileEnumerationByExtension (00421b10), Game_Enter (0042d370), sub_45C0C0 (0045c0c0), PlayerProfileScanner (00468ee0), ProfileBitmapBrowser (00477cb0), sub_47BF30 (0047bf30), TGATextureFileScanner (004c3a00), VehicleFileLoader (004c3d80), SceneFileLoader (004c52c0), sub_4C84A0 (004c84a0), TireBrandLoader (004d7660)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x8) | 0x0 | R | — | current node's data pointer (used for return check) |
| *(obj+0x8) | 0x4 | R | — | current node's next pointer (advance target) |
| obj | 0x8 | RW | — | current node pointer in list head — replaced by next |
| this | 0x0 | R | — | pointer to list head structure |

**Written-by note (persistence):**
- obj 0x8: updated unconditionally when current node exists; external poke survives if it matches next pointer

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If current node (at obj+0x8) is NULL → skip advance (obj+0x8 unchanged). Returns (v3 != NULL && *v3 != 0) — true if new node has data.
