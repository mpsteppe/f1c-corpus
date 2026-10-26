## AudioSubsystemInitializer_004c0ab0 — Career standings sub-block initializer

**Summary:** Initializes a large career standings structure containing 103 per-driver sub-blocks and session state fields. Sets default values for season status, race session, and current race index.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerCareerStatsGameOptionsLoader (004c18b0), GameOptionsWriter (004c1e80), NodeAllocListInsert (004c2780)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB144 | RW | 0 | season status value (initialized to 0) |
| this | 0xB148 | RW | 18446744073709551615 | current race index (initialized to -1) |
| this | 0xB14C | RW | 1 | race session identifier (initialized to 1) |
| this | 0xB150 | RW | 0 | race over flag / active flag (initialized to 0) |

**Written-by note (persistence):**
- this 0xB144: written once at init; external poke overwrites season status
- this 0xB148: written once at init; external poke overwrites current race index
- this 0xB14C: written once at init; external poke overwrites race session
- this 0xB150: written once at init; external poke overwrites race over flag

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c0370 | StructInitWithDefaults | initialize default values for a sub-struct |
| 004c03c0 | ArithmeticComparison_03c0 | compare-and-set initialization for per-driver sub-block |

**Guard conditions:** No guard conditions — always fully initializes all 103 sub-blocks and final fields.
