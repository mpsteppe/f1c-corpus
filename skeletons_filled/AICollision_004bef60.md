## AICollision_004bef60 — AICollision

**Summary:** Checks AI collision state: returns 0 (no collision) if not qualifying session; checks wheel contact/brake flags for all 4 wheels (returns 1 if any missing or braking); checks vehicle state for collision severity (returns 2 for state==2); performs probabilistic collision response based on wear flags and random thresholds. Uses two boolean flags (0x340, 0x341) and multiplier (0x344) from behavior config.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** EngineFailureCheck (004bec55)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x340 | R | — | first collision response flag (enables primary probabilistic collision check) |
| this | 0x341 | R | — | second collision response flag (enables secondary probabilistic collision check) |
| this | 0x344 | R | — | float multiplier for secondary collision probability |
| this | 0x35C | R | — | countdown/limit divisor used in probability calculation |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007cea5c | dword_7CEA5C | R | EngineWearMode (0/2/3) [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042aeb0 | DriverSetupParamLookupByID | checks driver setup parameter for collision threshold in engine-wear mode 3 |

**Guard conditions:** PASSES when session type==7 AND all 4 wheels have contact+brake flags set AND state + wear-based checks allow. BLOCKED (return 0) when session type != 7; BLOCKED (return 1) when any wheel missing contact or brake flag; return 2 when vehicle state==2 or engine-wear mode 3 exceeds threshold.
