## VtableDestructorNull_004c9790 — VtableDestructorNull

**Summary:** Releases single sub-object at this+0x20 by calling vtable[0] (Release) with final flag (1), then nulls the pointer. Minimal destructor body.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VTableSwitchDtor (004c9600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x0 | R | — | VTable of sub-object (calls vtable[0]=Release) |
| this | 0x20 | RW | 0 | Pointer to sub-object (nulled after release) |

**Written-by note (persistence):**
- this 0x20: Nulled after release; not persistent after destruction

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Pointer at this+0x20 checked for non-null before vtable[0] dispatch. If null, skipped and returns previous result.
