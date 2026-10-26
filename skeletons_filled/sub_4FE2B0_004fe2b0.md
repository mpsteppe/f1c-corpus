## sub_4FE2B0_004fe2b0 — TireTemperatureLookup

**Summary:** Returns tire temperature/pressure value (7.5–32.5) by matching temperature name string against categories. off_5D6FD4 → 32.5, Warm→26.25, Medium→20.0, Cool→13.75, Cold→computed via sub_58850F, unknown→7.5. Used by tire physics system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FE350 (004fe350)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e8ec | flt_59E8EC | R | speed deadzone (not directly referenced) |
| 0059e8f4 | flt_59E8F4 | R | physics threshold (not directly referenced) |
| 005ad328 | flt_5AD328 | R | tire wear float (not directly referenced) |
| 005ad32c | flt_5AD32C | R | unknown float (not directly referenced) |
| 005ad330 | flt_5AD330 | R | clutch engagement rate (not directly referenced) |
| 005c6eb8 | aMedium | R | string "Medium" — tire temp category (returns 20.0) |
| 005d6fbc | aCold | R | string "Cold" — tire temp category (returns computed value) |
| 005d6fc4 | aCool | R | string "Cool" — tire temp category (returns 13.75) |
| 005d6fcc | aWarm | R | string "Warm" — tire temp category (returns 26.25) |
| 005d6fd4 | off_5D6FD4 | R | reference name pointer (likely "Hot"/"Optimal", returns 32.5) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | string equality comparison (returns 0 on match) |
| 0058850f | sub_58850F | computes temperature value for "Cold" category |

**Guard conditions:** none — cascading if-else chain always returns a value. Every path covered.
