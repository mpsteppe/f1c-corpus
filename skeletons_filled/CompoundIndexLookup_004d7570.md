## CompoundIndexLookup_004d7570 — TireCompoundIndexValidator

**Summary:** Validates tire compound index a2 against range [0, this[4]) and returns pointer to compound data at this[5] + 680*a2. If index out of range, conditionally logs "tire brand doesn't" error and returns 0.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** RandomWeightedTierSelection (00429fd0), VehicleSetupValueFormatter (0042f470), sub_430750 (00430750), BrakeTemperatureFadeModel (00430a50), TireSuspensionForceComputation (00431850), VehiclePhysicsInitializer (00439210), TireCompoundPerWheelPhysicsApplication (0043da10), PitPartStateCopy (004a5330), NthValidPartLookup (004a5820), PitStopOperationTimer (004a6340), SuspensionAndWheelPhysics (004e5f60), TireNameAccessor (004f1630), sub_4F18C0 (004f18c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | compound count (size of array) |
| this | 0x14 | R | — | base pointer to compound array (680 bytes per entry) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d45e4 | aDDevF119992002_4 | R | SourcePath_F1_1999_2002_4 [DERIVED] |
| 005d4950 | aTireBrandDoesn | R | StringTireBrandDoesn [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | validates debug source path before logging |
| 004d7aa0 | DebugLogWrite | writes out-of-range compound error to debug log |

**Guard conditions:** If a2 < 0 or a2 >= this[4] (index out of range), conditionally logs debug error and returns 0 (null/invalid).
