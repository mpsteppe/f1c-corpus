## ObjectConstructorWithSEHVtableInit_00598b5d — IStreamObjectConstructSimple

**Summary:** Constructs an istream-derived object with SEH handler setup. Conditionally initializes primary and ios vtables based on a flag, always sets istream vtable, then chains to sub_59A8FA for final initialization. Part of C++ standard library stream construction.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_59870C (0059870c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | flag controlling sub-object vtable initialization |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d2aa | loc_59D2AA | R | exception handling type descriptor |
| 005b9ba4 | ??_7?$basic_istream@DU?$char_traits@D@std@@@std@@6B@ | R | IStreamVtablePtr [DERIVED] |
| 005b9bb4 | ??_7?$basic_ios@DU?$char_traits@D@std@@@std@@6B@ | R | IosVtable [DERIVED] |
| 005b9bc0 | unk_5B9BC0 | R | PrimaryVTablePtr [DERIVED] (also: primary vtable pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | initialize SEH handler registration for this constructor |
| 0059a8fa | sub_59A8FA | finalize object initialization after vtable setup |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC | == | 0 | flag controlling sub-object vtable initialization |

**Guard interpretation:** If this+0xC != 0 → initialize primary vtable (unk_5B9BC0), ios vtable, zero field v3[11], set construction flag. If zero → skip sub-object vtable init (BLOCKED). Istram vtable write and sub_59A8FA always execute.
