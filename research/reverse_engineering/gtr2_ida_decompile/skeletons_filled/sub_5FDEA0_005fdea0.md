## sub_5FDEA0_005fdea0 — Find string in global linked list

**Summary:** Searches a global singly-linked list of strings for an entry equal to a1 using strcmp, returning the stored string pointer on a match (0 otherwise), and updates a global cursor global to the head and then each visited node as it walks.

**Called by:** SeasonRaceCountCheck [structural] (005fe010), sub_5FE050 (005fe050), sub_5FE2C0 (005fe2c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb288c | dword_FB288C | R | head pointer of the global string list being searched |
| 00fb2894 | dword_FB2894 | W | traversal cursor — set to the head, then updated to the current node on every step of the walk |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If the head global is 0 (empty list) the function returns 0 immediately. If the head node's string pointer is null it also returns 0. Otherwise strcmp runs against each node string; a mismatch advances to the next node (updating the cursor global) and continues only while the next node exists and its string pointer is non-null — otherwise returns 0. A strcmp match (equal strings) PASSES and returns that node's string pointer.
