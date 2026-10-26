## VTableSetterSubCall_b4e0_0048b4e0 — VTable set and sub-call

**Summary:** Sets vtable pointer to off_5ABED0 (VTable_EditBox), then calls sub_485EB0 for further initialization. Simple wrapper/override for edit box vtable assignment.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalDestructor_0250 (00470250)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5ABED0 (VTable_EditBox) |

**Written-by note (persistence):**
- this 0x0: written once per call (vtable reassignment); survives until next overwrite

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005abed0 | off_5ABED0 | R | VTable_EditBox [DERIVED] — edit box vtable assigned to this object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — runs unconditionally.
