## ShortComputation_9ee0_00489ee0 — Scroll index reset computation

**Summary:** Resets scroll offset (this[0x14C]) to 0 or truncates display size to int. Inverse companion to FloatToIntConversion. Guarded by max scroll value and display size threshold.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_489D00 (00489d00), UIScrollListUpdate (0048a8d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14C | RW | 0 | this[83] — scroll offset, reset to 0 or display size |
| this | 0x154 | R | — | this[85] — display size (truncated to int and stored as scroll offset) |
| this | 0x160 | R | — | this[88] — max scroll value (guard: must be non-zero) |

**Written-by note (persistence):**
- this 0x14C: set to 0 every call; overwritten with display size if max scroll != 0 and display size > 0; survives until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | CRT float-to-long truncation (floor/lrint equivalent) |

**Guard conditions:** If this[0x160] (max scroll) is 0, scroll offset stays 0. If display size (this[0x154] cast to double) is <= 0.0, scroll offset stays 0.
