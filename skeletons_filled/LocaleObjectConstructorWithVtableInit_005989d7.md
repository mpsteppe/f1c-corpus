## LocaleObjectConstructorWithVtableInit_005989d7 — LocaleStreamObjectConstruct

**Summary:** Constructs a locale-related C++ stream object by initializing vtable pointers (streambuf, ios, ostream), checking conditional fields for sub-object construction flags. Part of the C++ standard library locale/stream object initialization chain.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_579FB0 (00579fb0), ThunkToFUN00598815 (0057a940), sub_57ADB0 (0057adb0), sub_57AE30 (0057ae30), SingleFunctionCallWrapper_5e10 (00585e10), ThunkToFUN00598815_6ed0 (00586ed0), CallWrapper_73f0 (005873f0), sub_587680 (00587680), ThunkToFUN00598815_7a50 (00587a50), SingleFunctionCallWrapper_97a1 (005997a1)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | first argument to ObjectInitWithVTableFlagSet |
| this | 0xC | R | — | second argument to ObjectInitWithVTableFlagSet |
| this | 0x10 | R | — | flag indicating whether ObjectInitWithVTableFlagSet should be called |
| this | 0x14 | R | — | flag indicating whether stream sub-object initialization should run |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d23e | loc_59D23E | R | exception handling type descriptor |
| 005b9bac | ??_7?$basic_ostream@DU?$char_traits@D@std@@@std@@6B@ | R | MSVC_ostream_vtable [DERIVED] |
| 005b9bb4 | ??_7?$basic_ios@DU?$char_traits@D@std@@@std@@6B@ | R | IosVtable [DERIVED] |
| 005b9bb8 | unk_5B9BB8 | R | VTable_StreamBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | initialize SEH handler registration for this constructor |
| 005993eb | ObjectInitWithVTableFlagSet | initialize object sub-component with vtable flag |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | == | 0 | flag controlling ObjectInitWithVTableFlagSet call |
| this | 0x14 | == | 0 | flag controlling stream sub-object vtable initialization |

**Guard interpretation:** If this+0x14 != 0 → initialize stream sub-object (set streambuf, ios vtables, zero fields), set construction flag. If this+0x10 != 0 → call ObjectInitWithVTableFlagSet after ostream vtable write. Both guards block their respective initialization when field is zero.
