## sub_4A0CB0_004a0cb0 — RestartMenuModeGuard

**Summary:** Conditionally invokes SessionMenuModeSwitch after session restart. Guards require qualifying DSQ disabled, HUD enabled, session mode identifier at -1 (unset), and player vehicle state field == 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RestartGate (004a0fd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 007ce814 | dword_7CE814 | R | QualifyingDSQEnabled [DERIVED] |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a0c60 | SessionMenuModeSwitch | Switches session to post-race menu mode |

**Guard conditions:** All four conditions must be true: QualifyingDSQEnabled (dword_7CE814) == 0, DisableHUDFlag (byte_7CE254) == 0, SessionModeIdentifier (dword_8AD298) == -1, and player vehicle field at offset 0x4064 == 1. If any fails, returns 0 without calling SessionMenuModeSwitch.
