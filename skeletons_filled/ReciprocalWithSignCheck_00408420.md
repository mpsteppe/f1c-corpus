## ReciprocalWithSignCheck_00408420 — ReciprocalWithPositiveCheck

**Summary:** Computes 1.0/a2 when a2 is positive, otherwise defaults to 1.0. Always initializes offset 0x04 to 1.0. Simple guarded reciprocal utility used by sound, menu, and loading systems.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalSoundRenderDispatchOnParamCheck (00404970), SessionMenuModeSwitch (004a0c60), LoadingPhase1 (004b87c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 1065353216 → 1.0f | field always set to 1.0f |
| this | 0x8 | RW | 1065353216 → 1.0f | reciprocal result: 1.0/a2 if a2 > 0, else 1.0f |

**Written-by note (persistence):**
- this 0x4: set to 1.0f every call; external poke overwritten
- this 0x8: computed from a2 every call; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If input `a2` is <= 0.0f, the reciprocal computation (1.0 / a2) is skipped and offset 0x08 is set to 1.0f instead. Only positive a2 values produce a meaningful reciprocal.
