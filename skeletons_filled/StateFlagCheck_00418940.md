## StateFlagCheck_00418940 — OverlayDisplayActiveQuery

**Summary:** Returns bool: true if audio overlay object is busy processing (vfunc+8 returns non-zero) OR there is an active display slot (slot index != -1). Queries whether overlay display is currently active.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateFlagCheck_5240 (00435240)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xAF4) | 0x8 | R | — | vfunc+8 — query method; returns 0=ready, non-zero=busy |
| this | 0x864 | R | — | Active display slot index (-1 = none) |
| this | 0xAF4 | R | — | Pointer to audio/text overlay object |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x864 | != | 18446744073709551615 | Slot index sentinel (-1 = no active slot) |

**Guard interpretation:** When this+0x864 != -1 (active slot exists), returns true immediately — PASSES (activity detected). When slot == -1, falls through to check audio object: returns true only if object non-null AND vfunc+8 returns non-zero (busy). Returns false only when slot==-1 AND (object null OR vfunc returns 0/ready).
