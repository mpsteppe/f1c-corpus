## CameraTargetUpdateOnPlayerChange_0040c7a0 — CameraTargetUpdateOnPlayerChange

**Summary:** Updates camera target when player changes vehicle. Compares current camera target ID against current player's vehicle field; on mismatch, stops/transitions audio effects and computes new camera mode based on dispatch mode selector and vehicle state. Called by camera director during player vehicle swap.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MainCameraDirectorUpdate (0040ca30), GameStateDispatchChain (0040d240)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x38 | RW | — | Current camera target ID — compared against player's vehicle camera field |
| this | 0x48CC | R | — | Vehicle struct field at offset 18580 (0x4894) — camera target identifier for the vehicle |

**Written-by note (persistence):**
- this 0x38: conditional — updated only when player vehicle ID changes. External poke persists until next vehicle swap.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ecdc8 | unk_5ECDC8 | R | VEH[0].0x6F0 — base of VEH array for iterating sound sources |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex — index into vehicle pointer array |
| 007c54e0 | dword_7C54E0 | R | unknown — not referenced in this function body |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray — array of vehicle object pointers, indexed by player index |
| 007c5bc8 | byte_7C5BC8 | R | ScoringDBEndSentinel — end address for VEH array iteration loop |
| 007cfcc8 | dword_7CFCC8 | R | QueuedModeFlag — queued mode flag for camera mode selection |
| 007cfdc4 | dword_7CFDC4 | R | DispatchModeSelector — selects camera mode (0-3) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c8d0 | StateCheckWithTernaryLogic | Evaluate camera state transition logic for valid current target |
| 004e0ed0 | AudioSoundEffectController | Play/stop audio effects for camera mode transitions |

**Guard conditions:** this[0x38] (current target) == Vehicle[0x4894] (player vehicle camera ID) → skip update. MISMATCH triggers: stop old audio, compute new camera mode, play new audio, store new target.
