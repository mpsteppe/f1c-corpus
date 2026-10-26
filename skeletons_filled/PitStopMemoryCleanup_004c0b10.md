## PitStopMemoryCleanup_004c0b10 — Career standings memory cleanup

**Summary:** Frees dynamically allocated pointers and runs cleanup on 103 per-driver sub-blocks in the career standings structure. Releases pit stop and driver data allocations before structure destruction.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DoubleListCleanup (004c1700), LinkedListNodeRemovalWithCleanup (004c1820), PlayerCareerStatsGameOptionsLoader (004c18b0), sub_4C1E20 (004c1e20), GameOptionsWriter (004c1e80), DualListDestructionWithDeepCleanup (004c2300)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB120 | R | — | first pointer to free (pit stop / driver data allocation) |
| this | 0xB128 | R | — | second pointer to free (secondary allocation) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049a270 | sub_49A270 | cleanup/release sub-block resources |
| 00587bcf | FreeWrapper_7bcf | free dynamically allocated memory |

**Guard conditions:** Only frees this[11336] (offset 0xB120) if non-null. Only frees this[11338] (offset 0xB128) if non-null.
