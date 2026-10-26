## ConditionalInitBranch_004f8f10 — FrameRateTimerReinit

**Summary:** Resets high-resolution timer and updates counter parameter. On parameter a2==0, also cleans up frame rate string list entry. Gated on struct being initialized.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VidMan_Restart (004fa640), sub_4FA7E0 (004fa7e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Initialization guard (must be non-null to proceed) |
| this | 0x4 | RW | — | Counter/parameter field set to a2 on reset |
| this | 0xC | RW | 0 | Counter field zeroed on reset |
| this | 0x18 | R | — | Timer object handle passed to HighResolutionTimerReset |

**Written-by note (persistence):**
- this 0x4: Overwritten with a2 each call when guard passes; external poke overwrites
- this 0xC: Zeroed each call when guard passes; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d6d78 | aFtframerate | R | String_FTFrameRate [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00556440 | HighResolutionTimerReset | Resets high-resolution performance counter timer |

**Guard conditions:** `*this` (offset 0) must be non-null to proceed. BLOCKED entirely if struct not yet initialized (offset 0 is null).
