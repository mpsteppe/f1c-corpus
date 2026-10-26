## CharacterCodeMapper_00411b50 — FontCharCodeToEventIdMapper

**Summary:** Maps a character code (a1) to an event ID using either special-case handling or lookup tables. Special codes 9875 → 45/46 (based on a4=397/426) and 9876 → 42/43 (based on a4=1/2). Otherwise uses unk_5BEE08 (a2=0) or unk_5BF4C0 (a2=1) table for lookup. On success writes (code, mapped_id) to output buffer and returns 0; on failure returns 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FontRenderingPrep (00411840)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005bee08 | unk_5BEE08 | R | SoundBankIndexMap [DERIVED] — character-to-event-ID lookup table for a2=0 |
| 005bf4c0 | unk_5BF4C0 | R | Setup_OptionTable_5BF4C0 [DERIVED] — character-to-event-ID lookup table for a2=1 |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] — path string used with StringCopyWithBufferRealloc |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | copies file path string on successful mapping |

**Guard conditions:** if a1 is special code (9875/9876) and a4 doesn't match expected variants → return 1 (unmapped). If a2 is 0 or 1 and table lookup yields result >= 0 → PASS. If a1 < 0 or v4 < 0 → return 1 (unmapped).
