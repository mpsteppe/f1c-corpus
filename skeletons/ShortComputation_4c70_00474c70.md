## ShortComputation_4c70_00474c70 — UITextViewFromResourceInit

**Summary:** Initializes a UI text-view object by setting its vtable pointer to off_5A4080 and calling VTableInit for further initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_4c50 (00474c50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer for text-view object |

**Written-by note (persistence):**
- this 0x0: set once; external vtable swap survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a4080 | off_5A4080 | R | Vtable for UI text-view/resource-display object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guards — always executes fully.
