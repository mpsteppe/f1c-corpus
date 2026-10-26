## ObjectConstructorWithVtableSetup_00599b86 — Object constructor with vtable chain setup

**Summary:** Registers SEH handler, conditionally initializes an object's vtable chain (basic_ostream, basic_ios, unk_5B9C54) when guard at offset 0xC is non-zero, then calls sub_59A8FA on the vtable-adjusted this pointer to complete object construction.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5998C0 (005998c0), DelegationWithFixedArgs_9904 (00599904), SingleFunctionCallWrapper_9933 (00599933)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | boolean guard flag: 0 = skip vtable init block, non-zero = apply vtable chain |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d3c2 | loc_59D3C2 | R | address of exception handler code registered by SEHHandlerInit |
| 005b9c48 | ??_7?$basic_ostream@GU?$char_traits@G@std@@@std@@6B@ | R | VTable_basic_ostream_wchar [DERIVED] |
| 005b9c50 | ??_7?$basic_ios@GU?$char_traits@G@std@@@std@@6B@ | R | VTable_basic_ios [DERIVED] |
| 005b9c54 | unk_5B9C54 | R | CppStreamObject_5B9C54 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | registers SEH exception handler for frame |
| 0059a8fa | sub_59A8FA | completes object construction after vtable setup |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC | == | 0 | boolean guard flag for vtable chain init |

**Guard interpretation:** If offset 0xC is non-zero, the object receives its vtable chain (unk_5B9C54 → basic_ios → basic_ostream) and frame flags are set. If zero, vtable init is skipped, but the basic_ostream vtable is still applied and sub_59A8FA is still called regardless.
