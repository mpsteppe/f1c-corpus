## ScoringGateValueSelect_004e2c70 — ScoringGateTimeSelect

**Summary:** Selects timestamp value for scoring field at offset 0x984 based on gate type. If scoring gate type is 2, delegates to Delegation function for gate-specific time and stores result; otherwise stores global session time. Scoring/timing system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x984 | RW | — | scoring timestamp/float field, written each call |

**Written-by note (persistence):**
- this 0x984: overwritten each call; no persistence across calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b9ce0 | Delegation | delegate to gate-specific scoring handler |

**Guard conditions:** If dword_8AB6E4 == 2 (gate type 2), delegate and store result; otherwise store session time.
