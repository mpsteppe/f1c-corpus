## sub_6CD2CE_006cd2ce — reverse dword range in array at 0x3C

**Summary:** In-place reversal of the dword sub-array [a2, a3) inside the array pointed to by this[15] (byte offset 0x3C), swapping element pairs for floor((a3 - a2) / 2) iterations.

**Called by:** sub_6CD4DC (006cd4dc)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3C | R | — | Base pointer of the dword array whose [a2, a3) range is reversed |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Swap loop runs only when (a3 - a2) >> 1 != 0, i.e. at least two indices apart; otherwise the function is a no-op returning a3. No other branches or error paths.
