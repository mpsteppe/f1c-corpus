## D3DTextureResourceCreation_00548190 — D3D texture resource creation from stream

**Summary:** Reads texture data stream via ArithmeticComparison_a5c0, allocates 196-byte resource objects per texture entry, configures flags, dimensions (sub_547240), and per-sub-resource settings (sub_546F30/sub_546F70/sub_546FE0/GuardedRenderStateSet/ConditionalRenderStateSetup). For sub-resources, allocates 148-byte stride arrays and reads additional data. Deduplicates via ArithmeticComparisonBinarySearch. Appends via sub_547670. Graphics texture loading.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_548620 (00548620), sub_54AC70 (0054ac70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00800000 | unk_800000 | R | MMXFlag [DERIVED] |
| 008b8f30 | dword_8B8F30 | R | TempFileReadBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00546250 | ConstructorInputControlInit | initialize 196-byte texture resource object |
| 00546370 | ArrayCleanupWithDualFree | free duplicate resource's array allocations |
| 00546f30 | sub_546F30 | conditional setter with 0x100000 |
| 00546f70 | sub_546F70 | conditional multi-setter |
| 00546fe0 | sub_546FE0 | conditional setter with 0x400000 |
| 00547040 | ConditionalRenderStateSetup | conditional render state setup (0x1000000 path) |
| 005470a0 | GuardedRenderStateSet | guarded render state setter (0x8000000 path) |
| 005471c0 | SimpleSetter_71c0 | set simple field from parsed data |
| 00547240 | sub_547240 | set two WORD dimensions with validation |
| 00547670 | sub_547670 | append texture to linked list |
| 005477f0 | ArithmeticComparisonBinarySearch | search existing textures by name |
| 00548a30 | RandomPasswordKeyGenerator | generate random key for password-tagged textures |
| 0054a5c0 | ArithmeticComparison_a5c0 | stream read/advance by N bytes |
| 0054fb90 | StructInitWithDefaults_fb90 | initialize sub-resource struct |
| 0054fc50 | FloatToIntMultiply | float to int conversion with multiply |
| 0054fcb0 | FieldSetterAt0x80 | set field at offset 0x80 |
| 0054fcc0 | sub_54FCC0 | setter with high byte of parsed value |
| 0054fd50 | PlaybackRateConfigSetter | playback rate configuration |
| 00557470 | EmptyStub_7470 | stub cleanup callback |
| 00587bcf | FreeWrapper_7bcf | memory deallocation |
| 00587c03 | OperatorNewNhMallocWrapper | heap memory allocation |
| 00587dd0 | sub_587DD0 | copy random key to name buffer |

**Guard conditions:** (1) If v27 (entry count) <= 0, BLOCKED: return 0. (2) For each texture entry: allocate + init object, parse stream. (3) For each sub-resource (v4[41] count): parse additional data blocks. If v10[18] > 1, allocate dword array. (4) Switch on v15 (v10[24] value) to select configuration path: 0x800000 (MMXFlag) → sub_546F70; 0x100000 → sub_546F30; 0x400000 → sub_546FE0; 0x1000000 → ConditionalRenderStateSetup; 0x8000000 → GuardedRenderStateSet. If setter fails (returns non-zero), BLOCKED: return -1. (5) If ArithmeticComparisonBinarySearch finds existing texture, discard new allocation. (6) Otherwise: sub_547670 append.
