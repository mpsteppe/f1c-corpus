## ResourceObjectCreationWithConfig_005474d0 — Resource object allocation and initialization

**Summary:** Allocates 196-byte resource object via OperatorNewNhMallocWrapper, initializes with ConstructorInputControlInit, copies string identifier, allocates 148-byte stride sub-resource array (count from this+0xA4+1, plus optional a6 suffix), calls setters (sub_546F30/sub_546F70/ConditionalCheckCall) based on input flags, stores config at sub-resource slot[0]+0x40, sets this+0x9C flags, and returns. Resource manager entry point.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_557CE0 (00557ce0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00546250 | ConstructorInputControlInit | initialize 196-byte object with default values |
| 00546330 | SelfCopyStringToBuffer | copy name string to object buffer |
| 00546f30 | sub_546F30 | conditional setter with 0x100000 (primary path) |
| 00546f70 | sub_546F70 | conditional multi-setter (suffix/alternate path) |
| 00547100 | ConditionalCheckCall | conditional setter with 0x80000000 (fallback when no a5) |
| 00547670 | sub_547670 | append resource node to object's linked list |
| 00548890 | sub_548890 | search existing resources by string name |
| 0054fb90 | StructInitWithDefaults_fb90 | initialize sub-resource struct to defaults |
| 0054fc10 | SelfRelativeCopyNormalize | copy path/name string with self-relative normalization |
| 00587c03 | OperatorNewNhMallocWrapper | heap memory allocation |

**Guard conditions:** (1) sub_548890 lookup: if resource exists by name and a4 bit 8 (0x100) is clear, increment ref count and return 0 (reuse existing). (2) If a6 (suffix string) is non-empty, increments slot count by 1 for second sub-resource. (3) If a5 (primary string) present and non-empty: call sub_546F30 with SelfRelativeCopyNormalize. If absent: call ConditionalCheckCall. (4) If suffix (a6) present: call sub_546F70 with SelfRelativeCopyNormalize into second sub-resource slot.
