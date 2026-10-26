## FontCharacterRenderDispatcher_00411db0 — FontCharRenderDispatch

**Summary:** Dispatches font character rendering based on character code (state block offset +8). Special codes 9875 (with variant 397/426) and 9876 (variants 1-2) handled directly via sub_412490 or EnumValueTranslation plus counter decrement. General case uses GlobalFieldSelectorByIndex to resolve a field index, then copies string path and mapped values (code, field_index, zero flag) to output buffer, returning 1 on success or -1 on failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FontRenderingPrep (00411840)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] — default path string used when a2 string pointer is null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00412490 | sub_412490 | handles rendering for special code 9875 |
| 00414010 | EnumValueTranslation | translates enum value for special code 9876 |
| 00414140 | DecrementCounterWithFloorAtZero | decrements counter at a4, clamped to 0 |
| 00414160 | GlobalFieldSelectorByIndex | resolves field index for general-case character rendering |
| 00566650 | StringCopyWithBufferRealloc | copies file path string |

**Guard conditions:** code 9875 with a5 not in {397,426} → return -1. Code 9876 with a5 not in {1,2} → return -1. General case: if GlobalFieldSelectorByIndex < 0 → return -1.
