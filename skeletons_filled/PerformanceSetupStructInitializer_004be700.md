## PerformanceSetupStructInitializer_004be700 — PerformanceSetupStructInit

**Summary:** Initializes AI performance/setup struct fields with defaults: enables two boolean flags (1,1), sets zero flag, configures float parameters (1.0, 1.0, 600.0, 10.0), zeros accumulators, sets countdown (10) and session type (5). Called by Delegation_e6f0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Delegation_e6f0 (004be6f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x340 | RW | 1 | first boolean/animation flag (enabled) |
| this | 0x341 | RW | 1 | second boolean/animation flag (enabled) |
| this | 0x342 | RW | 0 | third boolean flag (disabled) |
| this | 0x344 | RW | 1065353216 → 1.0f | float parameter 1 (collision threshold multiplier) |
| this | 0x348 | RW | 1065353216 → 1.0f | float parameter 2 (unknown, 1.0 default) |
| this | 0x34C | RW | 1142292480 → 600.0f | float parameter 3 (AI target speed/performance) |
| this | 0x350 | RW | 1092616192 → 10.0f | float parameter 4 (increment/accumulator step) |
| this | 0x354 | RW | 0 | accumulator field (float, zeroed) |
| this | 0x358 | RW | 0 | second accumulator field (float, zeroed) |
| this | 0x35C | RW | 10 | integer countdown or limit |
| this | 0x360 | RW | 5 | session type or mode identifier (default 5) |

**Written-by note (persistence):**
- this 0x340: set once on init; external poke survives but may be overwritten by AnimationStateSetter
- this 0x341: set once on init; external poke survives but may be overwritten
- this 0x342: set once on init; external poke survives
- this 0x344: set once on init; external poke survives
- this 0x348: set once on init; external poke survives
- this 0x34C: set once on init; may be adjusted by sub_4BE760
- this 0x350: set once on init; external poke survives
- this 0x354: set once on init; written later by AIOvertake
- this 0x358: set once on init; written later by AIOvertake
- this 0x35C: set once on init; external poke survives
- this 0x360: set once on init; may be overwritten by AIOvertake

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acdac | dword_5ACDAC | R | DefaultSetupValue [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional initialization of all fields
