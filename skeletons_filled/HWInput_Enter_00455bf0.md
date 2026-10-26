## HWInput_Enter_00455bf0 — HWInput_Enter

**Summary:** Called on entering the HWInput game state. Logs entry, hides cursor, registers input actions, and optionally acquires dual-source input device when render flag 0x7D13A0 equals 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Enter (0042d370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e2c4 | ShowCursor | R | Win32 ShowCursor API pointer |
| 005c5688 | aEnteredHwinput | R | EnteredHwinputString |
| 005c56a4 | aDDevF119992002_13 | R | SourcePathFormatString |
| 007d13a0 | byte_7D13A0 | R | RenderFlag_7D13A0 (guards dual-source acquisition) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044f4e0 | sub_44F4E0 | unknown — cursor/timing setup |
| 00455290 | InputActionRegistration | registers input action bindings |
| 004d7a50 | StringSplitLoop | checks debug-log enable condition |
| 004d7aa0 | DebugLogWrite | writes entered-hwinput message to debug log |
| 004f8ae0 | DualSourceAcquireWithFallback | acquires dual-input source device |

**Guard conditions:** byte_7D13A0 == 1 enables DualSourceAcquireWithFallback. Otherwise acquisition skipped.
