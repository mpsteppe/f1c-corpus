## StateInitWithGlobalConstants_00408290 — StateInitWithScreenDimensions

**Summary:** Initializes struct fields with screen width (dword_5D6D60) and height (dword_5D6D64) as floats and sets a byte flag to 1. Called during camera manager restart to reinitialize display state.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CamMan_Restart (0040c9e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | screen width as float (from dword_5D6D60) |
| this | 0x10 | RW | — | screen height as float (from dword_5D6D64, via double cast) |
| this | 0x14 | RW | 1 | boolean/flag byte set to 1 (active/enabled) |

**Written-by note (persistence):**
- this 0xC: set every call from global dword_5D6D60; external poke survives until next call
- this 0x10: set every call from global dword_5D6D64; external poke survives until next call
- this 0x14: set to 1 every call; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d6d60 | dword_5D6D60 | R | ScreenWidth [DERIVED] |
| 005d6d64 | dword_5D6D64 | R | ScreenWidth [DERIVED] (also: input device parameters) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004083e0 | StructInitWithConditionalNotify | general init function; return value passed through as this function's return value |

**Guard conditions:** None — function always executes unconditionally.
