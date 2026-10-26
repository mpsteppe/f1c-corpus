## IDTypePermissionMatrix_004d9290 — Permitted index lookup by mode

**Summary:** Returns 1 (permitted) or 0 (denied) for an index (a1, 0-24) given a race mode (a2, 1-5). Modes 3-5 permit all indices; modes 1-2 permit only specific subsets. Out-of-range modes always return 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D88D0 (004d88d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004d92e4 | jpt_4D929C | R | Jump table for outer switch on a2 (race mode) |
| 004d92f8 | jpt_4D92B6 | R | Jump table for inner switch case a2==2 (index subset) |
| 004d9300 | byte_4D9300 | R | Lookup data for inner switch dispatch |
| 004d9318 | jpt_4D92C6 | R | Jump table for inner switch case a2==1 (index subset) |
| 004d937c | jpt_4D92D6 | R | Jump table for inner switch cases a2==3-5 (all indices) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `a2` outside [1-5] → BLOCKED (returns 0). For a2==1: BLOCKED unless a1 ∈ {1,3,6,7,9,10,11,12,20,21,22,23}. For a2==2: BLOCKED unless a1 ∈ {0,1,6,7,8,9,10,11,12,13,14,15,16,17,18,19,24}. For a2∈{3,4,5}: PASSES for any a1 in [0-24].
