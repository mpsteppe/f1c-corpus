## DirectXMeshVertexBufferParsingAndLoading_00547b40 — Mesh vertex buffer parsing and resource loading

**Summary:** Reads mesh data stream via ArithmeticComparison_a5c0 calls (parsing fixed-size chunks: 4, 32, 16-byte blocks), allocates 196-byte resource objects per mesh entry, calls ConstructorInputControlInit/SelfCopyStringToBuffer for each, configures with setters (sub_546F30/sub_546F70/setters based on flag bytes), creates D3D textures, appends to resource linked list via sub_547670, and deduplicates via ArithmeticComparisonBinarySearch. Graphics resource loading.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_54AC70 (0054ac70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f30 | dword_8B8F30 | R | TempFileReadBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00546250 | ConstructorInputControlInit | initialize 196-byte resource object |
| 00546330 | SelfCopyStringToBuffer | copy path string to resource buffer |
| 00546370 | ArrayCleanupWithDualFree | free duplicate resource's array allocations |
| 00546f30 | sub_546F30 | conditional config setter (0x100000 path) |
| 00546f70 | sub_546F70 | conditional multi-setter (suffix path) |
| 005470a0 | GuardedRenderStateSet | guarded render state configuration |
| 005471c0 | SimpleSetter_71c0 | set simple field from parsed data |
| 00547240 | sub_547240 | set two WORD dimensions with validation |
| 00547670 | sub_547670 | append resource to object's linked list |
| 005477f0 | ArithmeticComparisonBinarySearch | search existing resources by name |
| 00548a30 | RandomPasswordKeyGenerator | generate random key for password-tagged textures |
| 0054a5c0 | ArithmeticComparison_a5c0 | stream read/advance by N bytes |
| 0054fb90 | StructInitWithDefaults_fb90 | initialize sub-resource struct |
| 0054fc10 | SelfRelativeCopyNormalize | normalize and copy string path |
| 0054fc70 | sub_54FC70 | setter called for alternate path |
| 0054fc80 | DualFieldSetter | dual-field setter |
| 0054fcb0 | FieldSetterAt0x80 | set field at offset 0x80 |
| 0054fcc0 | sub_54FCC0 | setter with high byte of parsed value |
| 0054fd30 | ShortComputation_fd30 | computation setter with float args |
| 0054fd50 | PlaybackRateConfigSetter | playback rate configuration |
| 0054fda0 | ArrayCopyWithRealloc | array resizing with reallocation |
| 0054fdf0 | SimpleSetter_fdf0 | simple field setter |
| 0054fe00 | InverseScale | inverse scale computation |
| 00552fc0 | FieldSetterAt0x48 | setter at offset 0x48 |
| 00557470 | EmptyStub_7470 | stub cleanup callback |
| 00587bcf | FreeWrapper_7bcf | memory deallocation |
| 00587c03 | OperatorNewNhMallocWrapper | heap memory allocation |

**Guard conditions:** (1) If v24 (parsed entry count) <= 0, BLOCKED: return 0 (no data to process). (2) For each entry: parse stream chunks via ArithmeticComparison_a5c0. (3) If v39[0] (primary path flag) set, use SelfRelativeCopyNormalize + FieldSetterAt0x48 + GuardedRenderStateSet. Else use SelfRelativeCopyNormalize + FieldSetterAt0x48 + sub_546F30. (4) If either setter fails, BLOCKED: return -1. (5) If v37[0] (alternate/suffix path) set, configure second sub-resource slot. (6) After full parse: if ArithmeticComparisonBinarySearch finds existing resource with same name, discard new allocation (ArrayCleanupWithDualFree + FreeWrapper_7bcf). (7) Otherwise: sub_547670 append.
