## FieldCleanupWithNullCheck_00561940 — SceneGraphFieldFree

**Summary:** Free pointer at this[123] (offset 0x1EC) if non-null, then zero the field. Called during SceneGraph cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneGraph (0054a770)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1EC | RW | 0 | Pointer to allocated resource to free |

**Written-by note (persistence):**
- this 0x1EC: set to 0 after freeing; persists until next assignment

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free allocated memory |

**Guard conditions:** this[123] (offset 0x1EC) — if null, skip free and return null.
