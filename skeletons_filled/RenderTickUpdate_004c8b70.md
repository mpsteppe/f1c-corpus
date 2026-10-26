## RenderTickUpdate_004c8b70 — RenderTickUpdate

**Summary:** Main render tick handler: performs guarded render calls, iterates vehicles for suspension computation, updates render state flag, and dispatches either global virtual dispatch or sound setup depending on state flags.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0), StateTriggerCheck (004b8ae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e660 | flt_59E660 | R | VehicleBodyDamping [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56ac | byte_7C56AC | R | EnableFlag [DERIVED] (also: ` — enable flag (byte) |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 007cf2b4 | byte_7CF2B4 | R | RenderGateFlag [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |
| 008ac4b0 | flt_8AC4B0 | R | SceneCameraParam [DERIVED] |
| 008ac4c4 | dword_8AC4C4 | R | InitStatus [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004186f0 | TextOverlayDisplayTimer | Displays text overlay timer in HUD |
| 004b9e30 | VehicleDataAccessor | Reads vehicle count/state from scoring data |
| 004c7de0 | sub_4C7DE0 | Clears/zeros SceneCameraParam field |
| 004c8920 | sub_4C8920 | Sound scene DSP config update |
| 004c8a10 | GlobalVirtualDispatchGuarded | Dispatches virtual call with state guard |
| 004d1140 | RenderCallWithGuard | Executes render call with transformation guard |
| 004f8440 | SuspensionForceComputationWithPerCornerVirtualDi | Iterates vehicle suspension corners, computes forces |
| 0054a200 | GlobalFlagSetClear | Sets or clears global flag (32 = set) |

**Guard conditions:** Three-way guard logic: (1) ScoringGate != 2 OR vehicle count == 5 blocks render path (v0=0). (2) DisableHUDFlag AND RenderGateFlag AND InitStatus non-null gates render call + InitStatus method; else skips to suspension loop. (3) EnableFlag OR !RenderGateFlag skips suspension loop to LABEL_18. Final dispatch: v5 OR !DisableHUDFlag → GlobalVirtualDispatchGuarded, else → sub_4C8920 (sound setup).
