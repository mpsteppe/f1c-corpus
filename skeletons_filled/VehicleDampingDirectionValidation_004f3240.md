## VehicleDampingDirectionValidation_004f3240 — damping direction sign validation

**Summary:** Parses 3 damping values per direction index (0-5 corresponding to X+/X-/Y+/Y-/Z+/Z-), validates that damping sign opposes motion, and logs warnings for wrong-signed damping. Suppresses logging on server sessions.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004f3474 | jpt_4F327C | R | jump table for direction cases 0-5 |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 005d536c | aZForceAppliedW_0 | R | ZForceAppliedWField [DERIVED] |
| 005d539c | aZForceAppliedW | R | ZForceAppliedString [DERIVED] |
| 005d53cc | aYForceAppliedW_0 | R | YForceAppliedWString [DERIVED] |
| 005d53fc | aYForceAppliedW | R | YForceAppliedWString [DERIVED] |
| 005d542c | aXForceAppliedW_0 | R | Str_XForceAppliedW [DERIVED] |
| 005d545c | aXForceAppliedW | R | StringXForceAppliedW [DERIVED] |
| 005d548c | aDDevF119992002_7 | R | DefaultScenePath7 [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | splits/initializes debug message buffer for logging |
| 004d7aa0 | DebugLogWrite | writes formatted debug log message |
| 00565aa0 | sub_565AA0 | parses string into 3 output doubles |

**Guard conditions:** sub_565AA0 must succeed (return non-zero) to enter validation switch. Session type must not be 5 (server) for debug logging. Direction case: even indices (0,2,4 = positive axes) warn if value > 0.0; odd indices (1,3,5 = negative axes) warn if value < 0.0.
