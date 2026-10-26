## WeatherSeverityGripMultiplier_004fe1e0 — WeatherSeverityGripMultiplier

**Summary:** Returns grip/severity multiplier (0.0–1.0) by matching weather severity name against known categories. Cascading comparison via sub_588410 returns discrete values; fallback computes via sub_58850F clamped to [0,1]. Used by physics/grip system.

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
| 0059e450 | flt_59E450 | R | degrees-to-radians (not directly referenced) |
| 0059e7f8 | flt_59E7F8 | R | anti-roll mixing factor (not directly referenced) |
| 0059e7fc | flt_59E7FC | R | bump damping constant (not directly referenced) |
| 005c6e7c | aMonsoon | R | string "Monsoon" — highest severity category (returns 1.0) |
| 005c6e98 | off_5C6E98 | R | base/unknown severity name pointer (returns 0.0) |
| 005c7234 | off_5C7234 | R | intermediate severity name pointer (returns 0.5) |
| 005d6fac | aSoaked | R | string "Soaked" — high severity (returns 0.75) |
| 005d6fb4 | aDamp | R | string "Damp" — light severity (returns 0.25) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | string equality comparison (returns 0 on match) |
| 0058850f | sub_58850F | computes grip multiplier for unrecognized severity name |

**Guard conditions:** none — cascading if-else chain always returns a value. Every path covered.
