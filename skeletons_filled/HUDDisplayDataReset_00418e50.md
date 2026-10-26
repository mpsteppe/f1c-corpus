## HUDDisplayDataReset_00418e50 — AIDriverDisplayDataReset

**Summary:** Resets AI driver HUD display data for 104 driver entries conditioned on race active and track condition. Writes sentinel/zero values per driver slot for ID, flags, timers, and display state; calls AITargetDriverSelection for initial target assignment; then zeros three global tracking counters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x350 | RW | 0 | Per-driver slot entry base (array of 104 entries) |
| this | 0x4F0 | RW | 0 | Global tracking counter 1 (zeroed after loop) |
| this | 0x4F4 | RW | 0 | Global tracking counter 2 (zeroed after loop) |
| this | 0x4F8 | RW | 0 | Global tracking counter 3 (zeroed after loop) |
| this | 0x4FC | RW | 18446744072627421184 → -1.0f | First driver's float timer/state field (set to -1.0f sentinel) |
| this | 0x69C | RW | 0 | Per-driver field near offset 0x34C from slot base |
| this | 0x83C | RW | 0 | Per-driver byte flag field (offset 0x4EC from slot base) |

**Written-by note (persistence):**
- this 0x350: zeroed each iteration (starts driver slot array at clean state)
- this 0x4F0/0x4F4/0x4F8: zeroed unconditionally after loop
- this 0x4FC: set to -1.0f sentinel per driver iteration
- this 0x69C: zeroed per driver iteration
- this 0x83C: zeroed per driver iteration

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00418ee0 | AITargetDriverSelection | Selects initial AI target driver after reset |

**Guard conditions:** dword_7D0308 (RaceActiveFlag) must be non-zero AND flt_7CF3C8 (TrackConditionState) != 0.0. If either fails, function skips all reset logic and returns immediately.
