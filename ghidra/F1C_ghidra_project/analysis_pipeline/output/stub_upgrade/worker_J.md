=== TRIAGE LINES ===

=== FULL ENTRIES ===
<!-- target: docs/01-engine-architecture.md -->
### FUN_0042ca70 — DynMan::Exit()

Debug-logging-only stub. Logs "Entered DynMan::Exit()" via FUN_004d7aa0 when debug flag enabled.

**Key logic:**
- Calls FUN_004d7a50(2) to check debug logging enabled at source line 955
- If enabled, writes "Entered DynMan::Exit()" to debug buffer
- No state changes or cleanup

**Calls:** FUN_004d7a50 (debug gate, docs/09), FUN_004d7aa0 (debug log write, docs/09)

<!-- target: docs/01-engine-architecture.md -->
### FUN_0049f000 — OnScreen::Restart()

Resets on-screen display state. Clears display buffers, resets active flag and sub-state.

**Key logic:**
- Calls FUN_0045bdf0 twice (clear display buffers, docs/07)
- Calls FUN_0049f150(0) (reset display layer)
- Sets param_1+4 = 1 (active flag), param_1+8 = 0 (sub-state)
- Calls FUN_004d82a0 (buffer flush)

**Calls:** FUN_0045bdf0 (clear display), FUN_0049f150 (display layer reset), FUN_004d82a0 (buffer flush)

<!-- target: docs/01-engine-architecture.md -->
### FUN_004fa2f0 — VidMan::Setup()

Debug-logging-only stub. Returns 0 (success).

**Key logic:**
- Logs "Entered VidMan::Setup()" via FUN_004d7aa0 when debug enabled
- Returns 0 unconditionally
- No actual video setup

**Calls:** FUN_004d7a50 (debug gate), FUN_004d7aa0 (debug log write)

<!-- target: docs/01-engine-architecture.md -->
### FUN_0040c9e0 — CamMan::Restart()

Resets camera manager state. Calls system state init, clears current camera index and flag.

**Key logic:**
- Calls FUN_00408290 (system state init, docs/19)
- Sets param_1+0x38 = -1 (camera index = none)
- Sets param_1+0x2e = 0 (camera flag reset)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x2e | Flag | Reset to 0 |
| +0x38 | CameraIndex | Set to -1 (none) |

**Calls:** FUN_00408290 (state init, docs/19)

<!-- target: docs/09-track-system.md -->
### FUN_004accfa — Force Feedback Config Initializer

Reads DirectInput force feedback spring coefficient and saturation settings per joystick per axis. 225 string references for 2 joysticks × 8 axes × 4 parameters each.

**Key logic:**
- Iterates 2 joysticks, each with 8 axes
- Per axis: reads Spring Coefficient Neg/Pos and Spring Saturation Neg/Pos via FUN_004b1ac0 (multi-field setter with strings, docs/01)
- Calls FUN_004b1d90 and FUN_004b1c20 (config write operations) in fixed sequence
- Formats parameter names via FUN_0058815f (sprintf formatter, docs/08) with "FFB Joy[%2.2d] Axis[%2.2d] ..." patterns
- Calls FUN_004a1da0 (session catchup), FUN_0047aa60, FUN_004a7010 (repeated 34×), FUN_004a1e20 (triple dispatch wrapper)

**Calls:** FUN_004b1ac0 (multi-field setter), FUN_004b1d90, FUN_004b1c20, FUN_0058815f (format), FUN_004a1e20 (dispatch wrapper), FUN_004a1ec0 (settings path builder), FUN_004a1da0 (session catchup), FUN_0047aa60

**Moddability:** `configurable` — reads FFB spring coefficient/saturation from config via INI-like string patterns

<!-- target: docs/09-track-system.md -->
### FUN_004cfc90 — SpecialFX::Restart()

Debug-logging-only stub. Logs "Entered SpecialFX::Restart()" when debug enabled. No state changes.

**Key logic:**
- Calls FUN_004d7a50(2) to check debug logging at source line 0xcdf
- If enabled, writes "Entered SpecialFX::Restart()" to debug buffer
- No special effects state reset performed

**Calls:** FUN_004d7a50 (debug gate), FUN_004d7aa0 (debug log write)

