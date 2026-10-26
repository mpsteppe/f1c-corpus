## FloatArrayInitializer_004fc9a0 — InitFourFloatDefaults

**Summary:** Sets four float fields to default values: 0.0, 20.0, 0.3, 0.0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCC30 (004fcc30), sub_4FD8B0 (004fd8b0), sub_4FE350 (004fe350)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | default value 0.0 |
| this | 0x4 | RW | 1101004800 → 20.0f | default value 20.0 |
| this | 0x8 | RW | 1050253722 → 0.3f | default value 0.3 |
| this | 0xC | RW | 0 | default value 0.0 |

**Written-by note (persistence):**
- this 0x0: always — written every call; external poke survives until next call
- this 0x4: always — written every call; external poke survives until next call
- this 0x8: always — written every call; external poke survives until next call
- this 0xC: always — written every call; external poke survives until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional initialization of all 4 fields.
