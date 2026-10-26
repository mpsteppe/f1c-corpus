## ShortComputation_6e50_00586e50 — Copy struct fields with buffer and sub-calls

**Summary:** Copies selected fields from input `a2` to `this` struct: two initial DWORDs (offsets 0x0, 0x4), then calls BufferWriteWithParams and sub_59B3B0 on `a2` sub-structs, then copies two trailing DWORDs (offsets 0x4C, 0x50). Acts as a partial struct copy/initializer with side-effect calls.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5853B0 (005853b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Copied from a2[0]; first DWORD of struct |
| this | 0x4 | RW | — | Copied from a2[1]; second DWORD of struct |
| this | 0x4C | RW | — | Copied from a2[19]; 20th DWORD of struct |
| this | 0x50 | RW | — | Copied from a2[20]; 21st DWORD of struct |

**Written-by note (persistence):**
- this 0x0: copied from input a2 every call; external poke overwrites this value
- this 0x4: copied from input a2 every call; external poke overwrites this value
- this 0x4C: copied from input a2 every call; external poke overwrites this value
- this 0x50: copied from input a2 every call; external poke overwrites this value

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587620 | BufferWriteWithParams | Writes buffer data from a2+2 (offset 0x8) |
| 0059b3b0 | sub_59B3B0 | Processes field at a2+5 (offset 0x14) |

**Guard conditions:** No guard conditions — all operations execute unconditionally.
