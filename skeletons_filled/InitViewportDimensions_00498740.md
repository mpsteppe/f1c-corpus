## InitViewportDimensions_00498740 — Viewport/Dimensions Initializer

**Summary:** Initializes six render-state/viewport fields: computed integer width and height from font-scale factors multiplied by 400/300, screen width, scroll acceleration, a constant, and a contact flag value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CarCrashDamageProcessing (00496030), UILargeRender (00496930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | RW | — | Computed width dimension: CRTFtol(flt_7CB274 * 400.0) |
| this | 0x60 | RW | — | Computed height dimension: CRTFtol(flt_7CB278 * 300.0) |
| this | 0x64 | RW | — | Screen width from global dword_7CB2FC (SCREEN_WIDTH) |
| this | 0x68 | RW | — | Scroll acceleration from global dword_7CB300 |
| this | 0x6C | RW | — | Constant initial value from global dword_7CB304 |
| this | 0x70 | RW | — | Contact/collision flag read and cleared via ContactFlagReadClear |

**Written-by note (persistence):**
- this 0x5C–0x70: All six fields overwritten unconditionally each call; persist until next reinitialization

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e9b0 | dbl_59E9B0 | R | Rad2DegOrTimerMult [DERIVED] (also: ` — conversion multiplier) |
| 005ac9d8 | dbl_5AC9D8 | R | InitFloatValue [DERIVED] |
| 007cb24c | dword_7CB24C | R | Contact/collision state flag to read and clear |
| 007cb274 | flt_7CB274 | R | Font/text scale factor used to compute width (multiplied by 400) |
| 007cb278 | flt_7CB278 | R | Font/text scale factor used to compute height (multiplied by 300) |
| 007cb2fc | dword_7CB2FC | R | Screen width pixel value |
| 007cb300 | dword_7CB300 | R | UI scroll acceleration parameter |
| 007cb304 | dword_7CB304 | R | Constant initialization value |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044f7d0 | ContactFlagReadClear | Reads and clears a contact/collision state flag, returning its value |
| 00587bdc | CRTFtol | Converts float to integer (truncation) for dimension calculation |

**Guard conditions:** (none — always executes fully)
