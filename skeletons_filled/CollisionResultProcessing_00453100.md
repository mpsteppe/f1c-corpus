## CollisionResultProcessing_00453100 — Process collision result and set output values

**Summary:** Processes a collision result object based on its type field at offset 0x0: type 0 reads a packed flag from byte_7CA594, type 1 dereferences a pointer at 0x1C, type 2 evaluates an axis value from a pointer at 0x20. Sets output activation state (0x24) and magnitude (0x28) accordingly.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_5bd0 (00455bd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x10 | R | — | Dereferenced collision object field at offset 0x10 (type-1 result source) |
| *(this+0x20) | 0x4 | R | — | Dereferenced collision object field at offset 0x4 (type-2 axis value) |
| this | 0x0 | R | — | Collision result type: 0=flag, 1=object+offset, 2=axis |
| this | 0x4 | R | — | Parameter for flag read (type 0: index/mask) |
| this | 0x1C | R | — | Pointer to collision object for type-1 result |
| this | 0x20 | R | — | Pointer to collision object for type-2 result |
| this | 0x24 | RW | 1 | Output activation state flag |
| this | 0x28 | RW | — | Output magnitude/axis absolute value |

**Written-by note (persistence):**
- this 0x24: output written conditionally by result type; external overwrites
- this 0x28: output written conditionally; external overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 005ea43c | dword_5EA43C | R | SetupDirSuffix [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007ca594 | byte_7CA594 | R | WheelBrakeBiasThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f10 | ConditionalFlagReturn | Checks debug/log session flag to early-exit with zero output |
| 0044f460 | PackedFlagRead | Reads packed bit flag from threshold byte array for type-0 result |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 1 | Collision result type — object pointer dereference path |
| this | 0x0 | == | 2 | Collision result type — axis evaluation path |

**Guard interpretation:** BLOCKED: debug/log session guard (ConditionalFlagReturn + SessionType5) early-returns with zero output. PASSES: branches on type at 0x0 — 0=packed flag read, 1=object pointer dereference, 2=axis absolute value with 0.5 threshold. For type 2, values ≤ 0.5 produce inactive output.
