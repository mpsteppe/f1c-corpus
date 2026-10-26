## sub_5A3BD0_005a3bd0 — ConsumeTimeStampedSample

**Summary:** One-shot consumer for the sample stored by sub_5A3B50: if the object's "have sample" flag (this+0x10) is set, computes the interpolated time from the caller-supplied current time a5 and the stored times, clears the flag, and outputs the time (a2), the payload pointer or null (a3), and the payload length (a4).

**Called by:** AnimationValueFetchWithTiming [structural] (0059b410)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | 0 | "Have sample" flag; must be nonzero to proceed, then cleared to 0 to consume the sample |
| this | 0x18 | R | — | Stored sample time, subtracted from a5 to compute the elapsed interval |
| this | 0x20 | R | — | Stored interpolated time added to the elapsed interval before writing *a2 |
| this | 0x128 | R | — | Stored payload length; <= 0 selects a null payload pointer output |

**Written-by note (persistence):**
- this 0x10: Conditionally written (cleared to 0) on each successful call — one-shot consume. A poke of 1 would let the next call pass the guard, but that call immediately clears it again.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x128 | <= | 0 | Payload length: when length <= 0, output pointer *a3 = 0 (null); otherwise *a3 = this+40 (start of the stored payload buffer) — selects pointer value only, not the return value |

**Guard interpretation:** Main gate is the byte at this+0x10: if it is 0 (no sample pending) the call is BLOCKED and returns 0 with no outputs and no state change. If nonzero, the sample PASSES: flag is cleared to 0, *a2 = (a5 − this[0x18]) + this[0x20], *a4 = this+0x128, and return 1. The length test at this+0x128 (<= 0) does not block: it only chooses between *a3 = 0 and *a3 = this+0x28.
