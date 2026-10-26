## Vec3CopyToStruct_004a2800 — Vec3CopyToStruct

**Summary:** Copies two 3-element DWORD arrays from source pointers into struct fields at offsets 0x4C-0x60 (first source to 0x4C-0x54, second source to 0x58-0x60), then dispatches a conditional transform update via ConditionalDispatch_27d0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Camera (004a3b50), sub_4D0110 (004d0110)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4C | RW | — | first element of first source copy (a2[0]) |
| this | 0x50 | RW | — | second element of first source copy (a2[1]) |
| this | 0x54 | RW | — | third element of first source copy (a2[2]) |
| this | 0x58 | RW | — | first element of second source copy (a3[0]) |
| this | 0x5C | RW | — | second element of second source copy (a3[1]) |
| this | 0x60 | RW | — | third element of second source copy (a3[2]) |

**Written-by note (persistence):**
- this 0x4C: unconditional write from a2[0]
- this 0x50: unconditional write from a2[1]
- this 0x54: unconditional write from a2[2]
- this 0x58: unconditional write from a3[0]
- this 0x5C: unconditional write from a3[1]
- this 0x60: unconditional write from a3[2]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a27d0 | ConditionalDispatch_27d0 | dispatches updated position/transform to 3D subsystem |

**Guard conditions:** No internal guards. Always copies 6 DWORDS and calls ConditionalDispatch_27d0 (which itself is guarded by field 0x64).
