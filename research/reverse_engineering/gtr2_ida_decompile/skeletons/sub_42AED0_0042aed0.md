## sub_42AED0_0042aed0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_42BC50 (0042bc50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x38 | RW | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0x1B0 | RW | — | [LLM] |
| this | 0x1BC | RW | 0 | [LLM] |
| this | 0x1C0 | RW | 0 | [LLM] |
| this | 0x1CC | RW | 1 | [LLM] |
| this | 0x1D0 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- *(this+0x4) 0x38: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1B0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1BC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1C0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1CC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1D0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e16eb | SEH_42AED0 | R | [LLM] |
| 006f18ec | off_6F18EC | R | [LLM] |
| 006f18f0 | off_6F18F0 | R | [LLM] |
| 006f21d4 | aTime | R | [LLM] |
| 006f35f4 | aDrivingSchoolC | R | [LLM] |
| 006f3624 | aPedals | R | [LLM] |
| 006f362c | aSpeed | R | [LLM] |
| 006f3634 | aGear | R | [LLM] |
| 006f363c | aPerp | R | [LLM] |
| 006f3644 | aTeamname | R | [LLM] |
| 006f3650 | aVehiclename | R | [LLM] |
| 006f3660 | dbl_6F3660 | R | [LLM] |
| 006f3668 | aTiressurfacete | R | [LLM] |
| 006f367c | aTrackname | R | [LLM] |
| 006f3688 | aMaxtrackcollis | R | [LLM] |
| 006f36a4 | aMaxghostcollis | R | [LLM] |
| 006f36c0 | aGhostrelativet | R | [LLM] |
| 006f36d4 | aStartspeed | R | [LLM] |
| 006f36e0 | aLinetimetolera | R | [LLM] |
| 006f36f4 | aGoalyoffset | R | [LLM] |
| 006f3700 | aGoalxoffset | R | [LLM] |
| 006f370c | aGhostline | R | [LLM] |
| 006f3718 | aSuggestedstats | R | [LLM] |
| 00b6cb98 | dword_B6CB98 | R | [LLM] |
| 01020304 | byte_1020304 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ac50 | sub_42AC50 | [LLM] |
| 004730c0 | sub_4730C0 | [LLM] |
| 006133a0 | sub_6133A0 | [LLM] |
| 006134b0 | sub_6134B0 | [LLM] |
| 006136d0 | sub_6136D0 | [LLM] |
| 006137e0 | sub_6137E0 | [LLM] |
| 00613b30 | sub_613B30 | [LLM] |
| 00613c30 | sub_613C30 | [LLM] |
| 00613de0 | sub_613DE0 | [LLM] |
| 00614140 | sub_614140 | [LLM] |
| 00614460 | sub_614460 | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 00631761 | _sprintf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Ori`
- `Pos`
- `Time`
- `Driving school: can't find this file! (%s)`
- `Pedals`
- `Speed`
- `Gear`
- `Perp`
- `TeamName`
- `VehicleName`
- `TrackName`
- `MaxTrackCollisionImpulse`
- `MaxGhostCollisionImpulse`
- `GhostRelativeTime`
- `StartSpeed`
- `LineTimeTolerance`
- `GoalYOffset`
- `GoalXOffset`
- `Ghostline`
- `SuggestedStats`
