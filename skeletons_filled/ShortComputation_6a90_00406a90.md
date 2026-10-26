## ShortComputation_6a90_00406a90 — TrackIndexPairGetter

**Summary:** Reads and returns two integer values from offsets 0x18 and 0x1C through optional output pointer parameters. Simple getter function for a track index pair.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListNodeSearchByIDOperation (00408050)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | R | — | first integer value (returned via a2 if non-null) |
| this | 0x1C | R | — | second integer value (returned via a3 if non-null) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** checks output pointers a2 and a3 for NULL before writing — if a2 is NULL, skips writing first value; if a3 is NULL, skips writing second value
