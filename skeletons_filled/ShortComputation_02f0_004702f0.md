## ShortComputation_02f0_004702f0 — VTableResetAndSubCall

**Summary:** Sets vtable pointer to off_5A0308 and returns result of VTableSetterSubCall_b4e0. Likely a vtable reassignment (re-init or mode switch) followed by a sub-routine call.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5A0308 |

**Written-by note (persistence):**
- this 0x0: set to vtable off_5A0308; overwrites any previous vtable

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a0308 | off_5A0308 | R | VTablePtr_5A0308 [DERIVED] — vtable pointer assigned to this object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guards — unconditional execution.
