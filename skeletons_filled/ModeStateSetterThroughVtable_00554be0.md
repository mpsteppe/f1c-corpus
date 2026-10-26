## ModeStateSetterThroughVtable_00554be0 — ModeStateSetterThroughVtable

**Summary:** Sets mode property 14 on device object via vtable+200. Maps a2 boolean (0/1) to value (0/1) and stores in this[1256]. Updates *this with dispatch result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_53EB70 (0053eb70), sub_5550E0 (005550e0), sub_55CF50 (0055cf50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0xC8 | R | — | Device object vtable+200 (property setter) |
| this | 0x0 | RW | — | Result from property setter dispatch |
| this | 0x1100 | R | — | Pointer to device object (this[1088]) |
| this | 0x13A0 | RW | — | Current mode state (this[1256]), stores a2 for change detection |

**Written-by note (persistence):**
- this 0x0: Updated from dispatch return; external poke survives
- this 0x13A0: Overwritten on change; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Skips if a2 == this[1256] (no change). On change: stores a2, dispatches property 14 with value a2 (non-zero→1, zero→0) via vtable+200.
