## TeamIDSetter_004c6960 — Team ID setter across multiple struct fields

**Summary:** Writes the same team ID value (a2) to five different offsets in the vehicle struct: +0x4, +0x10, +0x32D0, +0x4038, +0x4894. Propagates the team identifier to multiple substructures that all need to agree on team identity.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonScoringReset (0042bd60), AIDriverCountSetup (004bfd90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | team ID in primary struct header |
| this | 0x10 | RW | — | team ID in secondary struct region |
| this | 0x32D0 | RW | — | team ID stored in vehicle setup region |
| this | 0x4038 | RW | — | team ID in driver performance region |
| this | 0x4894 | RW | — | team ID in driver info region |

**Written-by note (persistence):**
- this 0x4: written unconditionally with a2; persists until overwritten
- this 0x10: written unconditionally with a2; persists until overwritten
- this 0x32D0: written unconditionally with a2; persists until overwritten
- this 0x4038: written unconditionally with a2; persists until overwritten
- this 0x4894: written unconditionally with a2; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — all five fields written unconditionally
