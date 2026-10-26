## KeyBindingUIPressKeyOrController_0046b0c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIClickHandlerWithBoundsCheck (0046b070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x1589 | RW | 1 | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x1F4 | RW | — | [LLM] |
| this | 0x1F8 | RW | — | [LLM] |
| this | 0x1FC | RW | 0 | [LLM] |
| this | 0x200 | RW | — | [LLM] |
| this | 0x204 | RW | — | [LLM] |
| this | 0x208 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- *(this+0x40) 0x1589: [LLM: once/conditional? does external poke survive?]
- this 0x1F4: [LLM: once/conditional? does external poke survive?]
- this 0x1F8: [LLM: once/conditional? does external poke survive?]
- this 0x1FC: [LLM: once/conditional? does external poke survive?]
- this 0x200: [LLM: once/conditional? does external poke survive?]
- this 0x204: [LLM: once/conditional? does external poke survive?]
- this 0x208: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c32d8 | word_5C32D8 | R | HotExtension (.HOT) [DERIVED] |
| 005c69b8 | aPressKeyOrCont | R | String_PressKeyOrCont [DERIVED] |
| 005c69e0 | aPopupControlSe | R | PopupControlSetString [DERIVED] |
| 005c69f4 | aReservedKey | R | ReservedKeyString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007d1424 | dword_7D1424 | R | TeamEntryCount [DERIVED] (also: ` — number of teams/entries) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 00454c20 | EnumToIDMappingWithDefaultFallthrough | [LLM] |
| 00454d30 | ParameterLookupWithFallback | [LLM] |
| 00455560 | ArrayIndexedAccessor | [LLM] |
| 0046a9c0 | ControllerShifterMapping | [LLM] |
| 00489940 | FieldGetter | [LLM] |
| 00497940 | LookupDispatch | [LLM] |
| 00497980 | BitmapSpriteAccessor | [LLM] |
| 004988c0 | sub_4988C0 | [LLM] |
| 00498950 | SpriteTextureEnumeration | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1FC | == | 3 | [LLM] |
| this | 0x1FC | == | 2 | [LLM] |
| this | 0x1FC | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
