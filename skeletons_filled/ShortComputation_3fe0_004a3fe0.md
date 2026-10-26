## ShortComputation_3fe0_004a3fe0 — FieldResetAndFlagUpdate

**Summary:** Zeros two extended DWORD fields (offsets 0x78, 0x84) and conditionally adjusts flag bits via FlagFieldBitManipulation when the sound source handle at 0x64 is non-null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitCrewAnimationMASSetup (004a3910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x64 | R | — | guard: sound source handle, if non-null enables flag manipulation |
| this | 0x78 | RW | 0 | extended DWORD field, zeroed |
| this | 0x84 | RW | 0 | extended DWORD field, zeroed |

**Written-by note (persistence):**
- this 0x78: once unconditional (0)
- this 0x84: once unconditional (0)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054c030 | FlagFieldBitManipulation | sets runtime flags with params (0,0,1,0) when guard passes |

**Guard conditions:** Guard at this[0x64]: if non-null, call FlagFieldBitManipulation(0,0,1,0). If null, skip flag manipulation. Field zeroing (0x78, 0x84) always executes regardless of guard.
