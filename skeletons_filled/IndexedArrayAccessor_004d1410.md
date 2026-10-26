## IndexedArrayAccessor_004d1410 — PitStopOrderIndexedAccessor

**Summary:** Indexed accessor into a pit stop order array. If the array pointer (this[107]) is null, lazily loads pit stop order data via PitStopOrderLoader, then returns pointer at 8-byte stride for given index.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4C6F10 (004c6f10), sub_4D1450 (004d1450)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1A8 | R | — | count/size of the pit stop order array |
| this | 0x1AC | R | — | pointer to pit stop order array elements (null before lazy init) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d12c0 | PitStopOrderLoader | loads/initializes pit stop order data array into this[107] |

**Guard conditions:** If this[107] is null (array not loaded), PitStopOrderLoader is called to init. If a2 < 0 or a2 >= this[106] (index out of bounds), returns 0 (null pointer). If the fetched string pointer is null, returns byte_5EA438 (default directory fallback).
