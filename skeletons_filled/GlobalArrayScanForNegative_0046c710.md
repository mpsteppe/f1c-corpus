## GlobalArrayScanForNegative_0046c710 — CollisionSlotFindFirstNegative

**Summary:** Scans collision/contact array for first negative value. If byte at 0x174 is non-zero, scans dword_7CD2B8→flt_7CD458; else scans dword_7CD470→flt_7CD610. Returns index of first negative entry (empty/invalid slot) or count if none found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x174 | R | — | selects which collision array to scan (0 = first, non-zero = second) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd2b8 | dword_7CD2B8 | R | CollisionGridArrayBase [DERIVED] — first array base |
| 007cd458 | flt_7CD458 | R | ContactStiffnessArray [DERIVED] — first array end bound |
| 007cd470 | dword_7CD470 | R | CollisionGridArrayBase2 [DERIVED] — second array base |
| 007cd610 | flt_7CD610 | R | CollisionParamArray3 [DERIVED] — second array end bound |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** this[372] (offset 0x174) selects array. PASSES for non-zero → scans first array. BLOCKED (zero) → scans second array.
