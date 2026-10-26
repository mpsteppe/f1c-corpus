## UtilityFunction_4000_004a4000 — FieldSetOneAndFlagUpdate

**Summary:** Sets DWORD field at offset 0x78 to 1, zeros DWORD at offset 0x84, and conditionally adjusts flag bits via FlagFieldBitManipulation(1,1,1,0) when the sound source handle at offset 0x64 is non-null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A00A0 (004a00a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x64 | R | — | guard: sound source handle, enables flag manipulation |
| this | 0x78 | RW | 1 | extended DWORD field, set to 1 (active/enabled) |
| this | 0x84 | RW | 0 | extended DWORD field, zeroed |

**Written-by note (persistence):**
- this 0x78: once unconditional (1)
- this 0x84: once unconditional (0)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054c030 | FlagFieldBitManipulation | sets runtime flags with params (1,1,1,0) when guard passes |

**Guard conditions:** Guard at this[0x64]: if non-null, call FlagFieldBitManipulation(1,1,1,0). If null, skip flag manipulation. Field writes (0x78=1, 0x84=0) always execute regardless of guard.
