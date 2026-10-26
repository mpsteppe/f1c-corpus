## InitKeyboardAxis0_0044d820 — InitializeAudioEngineType14Config

**Summary:** Sets AudioEngine_Type14Config to 25 and zeroes five adjacent configuration fields. Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccc50 | dword_7CCC50 | W | AudioEngine_Type14Config [DERIVED] |
| 007ccc54 | dword_7CCC54 | W | Audio config field slot 2 (zeroed) |
| 007ccc58 | dword_7CCC58 | W | Audio config field slot 3 (zeroed) |
| 007ccc5c | dword_7CCC5C | W | Audio config field slot 4 (zeroed) |
| 007ccc60 | dword_7CCC60 | W | Audio config field slot 5 (zeroed) |
| 007ccc64 | dword_7CCC64 | W | Audio config field slot 6 (zeroed) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
