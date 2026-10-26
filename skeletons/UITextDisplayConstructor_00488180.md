## UITextDisplayConstructor_00488180 — Text display UI constructor with sub-object init

**Summary:** UI text display object constructor: calls ShortComputation_5e30 for base setup, initializes sub-object at this+0xE0 via sub_499B10, sets vtable to off_5ABB78, and sets enable flag at 0x114 to 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIObjectConstructor_7ea0 (00477ea0), UIObjectConstructor_8e10 (00478e10), ObjectInitWithVTable (0047c0d0), sub_493FC0 (00493fc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5ABB78 | vtable pointer; set to text display vtable |
| this | 0x114 | RW | 1 | enable/visible flag; initialized to 1 (active) |

**Written-by note (persistence):**
- this 0x0: written once during construction; persists for object lifetime
- this 0x114: written once to 1; may be toggled externally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005abb78 | off_5ABB78 | R | PTR_VTable_FUN00488180 — vtable set during text display construction |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485e30 | ShortComputation_5e30 | performs initial setup computation before fields are written |
| 00499b10 | sub_499B10 | initializes sub-object at offset 0xE0 (text string/state) |

**Guard conditions:** none — unconditional straight-line init
