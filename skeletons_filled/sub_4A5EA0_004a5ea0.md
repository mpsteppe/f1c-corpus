## sub_4A5EA0_004a5ea0 — PitsUnderRedHandler

**Summary:** Handles the "entering pits under red flag" scenario. Fires once (guarded by flag at offset 0x180). Records state change to 2, updates session phase, processes vehicle pit state (offset +0x4034). If race start gate flag is 2 and penalties are enabled, either disqualifies (session type 7) or applies time penalty (sub_4BBA90 with 1000.0).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIStateMachineWithModeDispatch (004a5d10), TrackTemperatureDisplay (004d37b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Pointer to the vehicle object |
| this | 0x180 | RW | 1 | One-shot guard flag: 0 = not yet processed, 1 = already handled |

**Written-by note (persistence):**
- this 0x180: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005cd680 | aEnteringPitsUn | R | EnteringPitsUnString [DERIVED] — "Entering pits under..." message string |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] — when == 7, triggers disqualification instead of penalty |
| 007cef84 | dword_7CEF84 | R | PenaltiesEnabled [DERIVED] |
| 008acfc8 | dword_8ACFC8 | R | RaceStartGateFlag [DERIVED] — when == 2, enables penalty/disqualification logic |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041a2b0 | AISessionPhaseChange | Updates AI session phase in game state |
| 004a5c80 | StateChangeNotify | Records state change to 2 (pits-under-red) into ring buffer |
| 004bba90 | sub_4BBA90 | Applies a time penalty (1000.0 units) with a message string |
| 004bc0e0 | DisqualificationHandler | Disqualifies the vehicle with a reason string |
| 004bc240 | sub_4BC240 | Processes vehicle pit state (at offset +0x4034) |

**Guard conditions:** Checks `this[384]` (offset 0x180) == 0. PASSES when flag is clear (first invocation). BLOCKED on subsequent calls when flag is already 1.