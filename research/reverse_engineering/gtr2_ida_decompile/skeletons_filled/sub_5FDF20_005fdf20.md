## sub_5FDF20_005fdf20 — Find string in global linked list (second table)

**Summary:** Searches a second global singly-linked string list for an entry equal to a1 via strcmp, returning the stored string pointer on match (0 otherwise) while updating a global cursor to the head and then to each visited node during the walk.

**Called by:** sub_5FE120 (005fe120), sub_5FE2C0 (005fe2c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb285c | dword_FB285C | R | head pointer of the second global string list being searched |
| 00fb2864 | dword_FB2864 | W | traversal cursor — set to the head, then updated to the current node on every step of the walk |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Empty list (head global 0) returns 0 immediately; a null string pointer in the head node also returns 0. Otherwise each node string is strcmp'd against a1; mismatches advance to the next node (updating the cursor global) and continue only while the next node and its string pointer are non-null — otherwise the function returns 0. A strcmp match PASSES and returns that node's string pointer.
