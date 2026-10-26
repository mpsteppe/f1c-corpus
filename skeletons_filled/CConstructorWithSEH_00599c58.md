## CConstructorWithSEH_00599c58 — Istream constructor with SEH and locale vtable init

**Summary:** Registers SEH handler, conditionally applies locale vtable chain (locale vtable + basic_ios), sets up istream vtable on adjusted this pointer, and calls sub_59A8FA to complete istream construction.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LocaleFunctionCallWrapper_987c (0059987c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | boolean guard flag: 0 = skip locale vtable init, non-zero = apply locale vtable chain |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d40a | loc_59D40A | R | address of exception handler code registered by SEHHandlerInit |
| 005b9c40 | ??_7?$basic_istream@GU?$char_traits@G@std@@@std@@6B@ | R | IStreamWVTable [DERIVED] |
| 005b9c50 | ??_7?$basic_ios@GU?$char_traits@G@std@@@std@@6B@ | R | VTable_basic_ios [DERIVED] |
| 005b9c5c | unk_5B9C5C | R | LocaleVTablePtr [DERIVED] (also: ` — locale vtable pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | registers SEH exception handler for frame |
| 0059a8fa | sub_59A8FA | completes istream construction after vtable setup |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC | == | 0 | boolean guard flag for locale vtable chain init |

**Guard interpretation:** If offset 0xC is non-zero, locale vtable chain (unk_5B9C5C → basic_ios) is applied and frame flags are set. If zero, locale init block is skipped. The basic_istream vtable is always applied and sub_59A8FA always called regardless.
