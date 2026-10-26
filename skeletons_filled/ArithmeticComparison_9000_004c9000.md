## ArithmeticComparison_9000_004c9000 — SessionStateGuardCheck

**Summary:** Three-stage validation: checks this+4 field non-zero, session manager short computation non-zero, and sub_54C0E0 result non-zero. Returns 1 only if all pass; 0 otherwise.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4C8FC0 (004c8fc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Enable/state flag for session validation |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c910 | ShortComputation_c910 | Computes short value from session manager |
| 0054c0e0 | sub_54C0E0 | Validates/checks session-derived value |

**Guard conditions:** Three sequential guards: (1) this+4 must be non-zero, else return 0. (2) ShortComputation_c910 result must be non-zero, else return 0. (3) sub_54C0E0(v2) must be non-zero, else return 0. Returns 1 only if all pass.
