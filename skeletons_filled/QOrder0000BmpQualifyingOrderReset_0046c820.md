## QOrder0000BmpQualifyingOrderReset_0046c820 — QualifyingOrderArrayReset

**Summary:** Resets qualifying order array. If byte at 0x174 is non-zero, copies vehicle field_18580 values into dword_7CD2B8, fills remainder with -1. Otherwise, calls sub_497AD0 with scene object and fills dword_7CD470 with -1. Both branches set this[94] (0x178) to -1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | R | — | scene object pointer passed to sub_497AD0 |
| this | 0x174 | R | — | selector byte: non-zero copies vehicle scores, zero uses scene objects |
| this | 0x178 | RW | 18446744073709551615 | reset to -1 by both branches |

**Written-by note (persistence):**
- this 0x178: set to -1 at end of function; survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount [FACT] — number of vehicles in session |
| 005c6674 | off_5C6674 | R | vtable/function table for scene object |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007cd2b8 | dword_7CD2B8 | W | CollisionGridArrayBase [DERIVED] — first qualifying order array |
| 007cd470 | dword_7CD470 | R | CollisionGridArrayBase2 [DERIVED] — second qualifying order array |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00497ad0 | sub_497AD0 | loads/creates scene object reference |

**Guard conditions:** this[372] (offset 0x174) selects path. PASSES if non-zero → copies vehicle scores into dword_7CD2B8. BLOCKED if zero → uses scene object path and fills dword_7CD470.
