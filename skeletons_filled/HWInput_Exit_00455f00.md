## HWInput_Exit_00455f00 — HWInput_Exit

**Summary:** Exits HWInput state: destructs collision objects, cleans up cursor resource and collision culling, releases the DirectInput device, and optionally unloads input module module when render flag indicates.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameExit (0042db20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x8 | R | — | vtable offset 8: Release method |
| obj | 0x0 | R | — | DirectInput device interface pointer |
| this | 0x0 | RW | 0 | DirectInput device pointer (cleared to 0 after Release) |
| this | 0x1B10 | RW | — | module handle/index (set to -1 after ModuleUnload) |

**Written-by note (persistence):**
- this 0x0: set to 0 after releasing DirectInput device. External poke survives.
- this 0x1B10: set to -1 after ModuleUnload. External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c56a4 | aDDevF119992002_13 | R | SourcePathFormatString |
| 005c5734 | aEnteredHwinput_4 | R | debug log entry string |
| 007d13a0 | byte_7D13A0 | R | render flag (1 enables ModuleUnload) |
| 008ad25c | dword_8AD25C | R | debug message buffer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044efe0 | CollisionCullCleanup | cleans up collision culling data |
| 0044f5f0 | CursorResourceCleanup | cleans up cursor resource handles |
| 0044fbe0 | CollisionObjectDestructor | destructs collision objects at offsets +1121 and +866 |
| 004d7a50 | StringSplitLoop | checks debug-log enable condition |
| 004d7aa0 | DebugLogWrite | writes exit-entry message |
| 004f8c90 | ModuleUnload | unloads the input module |

**Guard conditions:** *this (device pointer) checked nonzero before calling virtual Release. byte_7D13A0 == 1 enables ModuleUnload and sets this[1732] = -1.
