## StringPointerAccessor_00499e20 — StringPointerAccessor

**Summary:** Returns a string pointer from struct field at offset 0x10, or a default path string (byte_5EA438) if the field is null. Simple accessor for resource path or filename.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ResourceIDLookupByNameString (00407f10), sub_424080 (00424080), StringMatchedLinkedListSearch (0049a210), sub_4C0260 (004c0260), sub_4C02D0 (004c02d0), SessionConfigReader (004c11e0), SeasonRacesSceneSorter (004c5940), SceneOrderSlotFinder (004c5cb0), sub_4FE350 (004fe350), StringKeyedLinkedListSearch (005679c0), sub_568320 (00568320)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | String pointer (non-null returns this, null falls back to default) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Null check at this[4] (offset 0x10): if NULL, return default path byte_5EA438. Otherwise return the stored string pointer.
