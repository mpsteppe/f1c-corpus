## PitCrewAnimationStringMapper_004a24d0 — PitCrewAnimationStringMapper

**Summary:** Maps a pit crew animation name string to an integer enum ID (0-24). Called during animation frame loading to identify which pit crew animation type a named entry corresponds to.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A22D0 (004a22d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005cd1c8 | a10secStarterre | R | TenSecStarterStr [DERIVED] |
| 005cd1dc | a10secSman4 | R | SmanString [DERIVED] |
| 005cd1e8 | a10secSman3 | R | TenSecSman3Field [DERIVED] |
| 005cd1f4 | a10secSman2 | R | Pitstop10secSman2 [DERIVED] |
| 005cd200 | a10secSman | R | String_10secSman [DERIVED] |
| 005cd20c | a10secRman2 | R | TimerManString [DERIVED] |
| 005cd218 | a10secRman | R | String10secRman [DERIVED] |
| 005cd224 | a10secNman | R | TenSecPenaltyString [DERIVED] |
| 005cd230 | a10secFmanFleft | R | String_10sec [DERIVED] |
| 005cd244 | a10secLollipopU | R | s_Pit10secLollipop [DERIVED] |
| 005cd258 | a10secLollipopD | R | TenSecLollipopD [DERIVED] |
| 005cd26c | aRearRightWheel_0 | R | RearRightWheelField [DERIVED] |
| 005cd280 | aRearRightWheel | R | RearRightWheelString [DERIVED] |
| 005cd294 | aRearLeftWheel | R | RearLeftWheelString [DERIVED] |
| 005cd2a4 | aFrontRightWhee | R | FrontRightWheeString [DERIVED] |
| 005cd2b8 | aFrontLeftWheel | R | Str_FrontLeftWheel [DERIVED] |
| 005cd2cc | aFuelOut | R | StringFuelOut [DERIVED] |
| 005cd2d8 | aFuelIn | R | FuelInString [DERIVED] |
| 005cd2e0 | aLollipopUp | R | LollipopUpString [DERIVED] |
| 005cd2ec | aLollipopDown | R | LollipopDownString [DERIVED] |
| 005cd2fc | aRearJackDown | R | RearJackDownStr [DERIVED] |
| 005cd30c | aRearJackUp | R | RearJackUpString [DERIVED] |
| 005cd31c | aFrontJackDown | R | FrontJackDownField [DERIVED] |
| 005cd32c | aFrontJackUp | R | FrontJackUp [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00589901 | sub_589901 | string preprocessing/normalization before comparison |

**Guard conditions:** No guard branches. Single if-else chain: each strcmp compares input against a known animation name string. First match returns corresponding ID (0=FrontJackUp, 1=FrontJackDown, ..., 23=10secStarterre). No match returns 24 (last else branch). sub_589901 called unconditionally before comparison chain.
