## StructInitWithGlobalData_004b4f70 — StructInitWithGlobalData

**Summary:** Initializes a struct by calling ThunkWithStructInitSubCalls on sub-struct at offset 0x90, zeroing 4 byte fields (offsets 0, 1, 0x41, 0x61), and setting 3 sentinel dwords at offsets 0x84/0x88/0x8C to -190986834 (0xF49C952E).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DualCallWrapper_4f50 (004b4f50), DriverNameTeamCopy (004b51e0), sub_4B5E50 (004b5e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Byte field zeroed (enable/flag) |
| this | 0x1 | RW | 0 | Byte field zeroed |
| this | 0x41 | RW | 0 | Byte field zeroed |
| this | 0x61 | RW | 0 | Byte field zeroed |
| this | 0x84 | RW | 18446744073518564782 | Sentinel dword (0xF49C952E) |
| this | 0x88 | RW | 18446744073518564782 | Sentinel dword (0xF49C952E) |
| this | 0x8C | RW | 18446744073518564782 | Sentinel dword (0xF49C952E) |

**Written-by note (persistence):**
- this 0x0: written once — zeroed
- this 0x1: written once — zeroed
- this 0x41: written once — zeroed
- this 0x61: written once — zeroed
- this 0x84: written once — set to sentinel value
- this 0x88: written once — set to sentinel value
- this 0x8C: written once — set to sentinel value

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acd10 | flt_5ACD10 | R | EntityActiveDefault — default active state float constant |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004fffa0 | ThunkWithStructInitSubCalls | Initialize sub-struct at this+0x90 with default parameters |

**Guard conditions:** No guard conditions — always executes fully.
