## WeatherNameWetnessMultiplier_004fe0d0 — WeatherNameWetnessMultiplier

**Summary:** Returns wetness multiplier (0.03–1.0) by comparing weather name string against known categories (Best→0.03, Nice→0.30, Clear→0.60, Overcast→0.65, Drizzle→0.73, Rain→0.85, Monsoon→0.97). Unknown names compute multiplier via sub_58850F * 0.01 clamped to [0.0, 1.0]. Used by physics/wetness system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FE350 (004fe350)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant (not directly referenced) |
| 0059e440 | flt_59E440 | R | zero threshold (not directly referenced) |
| 0059e444 | flt_59E444 | R | frame delta constant (not directly referenced) |
| 0059e4e8 | flt_59E4E8 | R | physics scaling constant (not directly referenced) |
| 0059e8b4 | flt_59E8B4 | R | clamp upper threshold (not directly referenced) |
| 0059e8f8 | flt_59E8F8 | R | physics constant (not directly referenced) |
| 0059e908 | flt_59E908 | R | collision event threshold (not directly referenced) |
| 005ad31c | flt_5AD31C | R | camera FOV scale (not directly referenced) |
| 005ad320 | flt_5AD320 | R | wetness gain float (not directly referenced) |
| 005ad324 | flt_5AD324 | R | camera distance scale (not directly referenced) |
| 005c6e7c | aMonsoon | R | string "Monsoon" — weather category |
| 005c6e8c | aOvercast | R | string "Overcast" — weather category |
| 005d6f84 | aRain_0 | R | string "Rain" — weather category |
| 005d6f8c | aDrizzle | R | string "Drizzle" — weather category |
| 005d6f94 | aClear_0 | R | string "Clear" — weather category |
| 005d6f9c | aNice | R | string "Nice" — weather category |
| 005d6fa4 | aBest | R | string "Best" — weather category |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | string equality comparison (returns 0 on match) |
| 0058850f | sub_58850F | computes wetness value for unrecognized weather name |

**Guard conditions:** none — cascading if-else chain always returns a value. Every path covered.
