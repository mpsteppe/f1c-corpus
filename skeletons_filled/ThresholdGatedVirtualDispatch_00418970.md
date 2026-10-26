## ThresholdGatedVirtualDispatch_00418970 — AudioParamUpdateFromNormalized

**Summary:** Updates audio object with normalized float parameter (0.0-1.0) via vfunc+28. Validates range before dispatch. Passes track condition state or loading percent to audio system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LazyRendererAudioInitCheck (004184f0), UILoadingPercentDisplay (0047c860)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xAF4) | 0x1C | R | — | vfunc+28 — audio param update method |
| this | 0xAF4 | R | — | Audio object pointer (queried via vtable) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** this+0xAF4 (audio object) must be non-null AND float param must be >= 0.0 AND <= 1.0. If either fails, vtable dispatch is blocked — no update sent.
