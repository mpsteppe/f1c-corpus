## IDPairMatchAndClear_0046a980 — ControllerActionIdMatchAndClear

**Summary:** Scans global action-type array (dword_7D1B08 to dword_7D1FD8, stride 7 ints) for matching ID pair (first two ints). Clears matched entry by setting first int to 0 and second to 89. Called from controller/shifter mapping.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ControllerShifterMapping (0046a9c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | first ID to match |
| this | 0x4 | R | — | second ID to match |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007d1b08 | dword_7D1B08 | R | ActionTypeArray [DERIVED] (also: action type array base) |
| 007d1fd8 | dword_7D1FD8 | R | AudioRaceModeFlag [DERIVED] (also: array end bound) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Loop iterates all entries from dword_7D1B08 to dword_7D1FD8. PASSES if `*result == *a1 && result[1] == a1[1]` → clears matched entry. BLOCKED if no match → entry unchanged.
