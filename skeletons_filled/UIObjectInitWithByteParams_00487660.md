## UIObjectInitWithByteParams_00487660 — UI object init with two byte parameters and vtable set

**Summary:** Initializes a UI list box node: calls ShortComputation_5e30 for setup, stores two byte parameters at offsets 0xE0 and 0xE1, and sets vtable to ListBoxNode vtable (off_5ABA18).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_493FC0 (00493fc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5ABA18 | vtable pointer; set to ListBoxNode vtable |
| this | 0xE0 | RW | a2 | first byte parameter (enable/state flag) |
| this | 0xE1 | RW | a3 | second byte parameter (additional state flag) |

**Written-by note (persistence):**
- this 0x0: written once during construction; persists for object lifetime
- this 0xE0: written once with a2; may be toggled externally
- this 0xE1: written once with a3; may be toggled externally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005aba18 | off_5ABA18 | R | VTable_ListBoxNode — vtable set during initialization |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485e30 | ShortComputation_5e30 | performs initial setup computation before fields are written |

**Guard conditions:** none — unconditional straight-line init
