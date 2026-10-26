## SetDriverVisibility_004c7aa0 — Set driver visibility (show/hide)

**Summary:** Sets visibility flags (bits 1-2) at offset +0x48BC to show (a2 non-zero) or hide (a2 zero) the driver. When showing and the vehicle matches the current player's team, plays engine sound; when hiding, plays stop sound. Manages 3D audio for the player's own vehicle vs others.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionContactIteration (00460dd0), LoadingPhase2 (004b8940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4894 | R | — | team ID; compared with current player's vehicle team to decide sound type |
| this | 0x48BC | RW | — | visibility/state flags bitset; bits 1-2 control driver visibility |

**Written-by note (persistence):**
- this 0x48BC: updated unconditionally; persists until next write

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c8d0 | StateCheckWithTernaryLogic | check session state to determine if engine sound should play |
| 004e0ed0 | AudioSoundEffectController | play/stop engine audio effect (param 0=play external, 3=stop) |

**Guard conditions:** none — both branches always execute based on a2: non-zero = show (set bits 1+2), zero = hide (clear bits 1+2)
