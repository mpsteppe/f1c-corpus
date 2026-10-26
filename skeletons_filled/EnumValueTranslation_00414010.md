## EnumValueTranslation_00414010 — EnumValueToSoundIdMapper

**Summary:** Maps an input enum value (1-22) to a translated literal value (113-134) and stores it with a sub-function result. Used in sound event dispatching.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FontCharacterRenderDispatcher (00411db0), SoundEventDispatcher (00411e90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | Mapped sound/event ID output from switch-case translation |
| this | 0xC | RW | — | Secondary value from sub_414180(0), likely a timing/duration parameter |

**Written-by note (persistence):**
- this 0x8: written conditionally when a2 is 1-22; stores mapped ID value
- this 0xC: written conditionally when a2 is 1-22; stores result of sub_414180(0)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004140e4 | jpt_414021 | R | Switch-case jump table for enum value dispatch (values 1-22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414180 | sub_414180 | Called with argument 0; returns a value stored at this+0xC, likely a sound duration or parameter |

**Guard conditions:** Switch on a2 (1-22): values 1-22 map to result values 113-134 respectively and update struct; default case returns -1 without modifying struct. PASSES: a2 in [1,22]; BLOCKED: a2 outside 1-22 (returns -1).
