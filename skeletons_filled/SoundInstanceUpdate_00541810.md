## SoundInstanceUpdate_00541810 — Update sound instance list

**Summary:** Replaces the sound instance ID list: clears existing entries via vtable call (flag=0), then sets new entries from source array a3 (each entry 56 bytes) via vtable call (flag=1). Returns the new instance count.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5550E0 (005550e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0xB8 | R | — | vtable offset 184 — sound instance add/remove method |
| this | 0x0 | RW | — | stores result of each vtable call |
| this | 0x1100 | R | — | pointer to vtable-bearing DX/sound object |
| this | 0x13D8 | R | — | guard flag; must be non-zero to proceed |
| this | 0x155C | RW | — | count of active sound instances; written with new count a2 |
| this | 0x1560 | RW | — | start of sound instance ID array |

**Written-by note (persistence):**
- this 0x0: written each vtable call (overwritten each invocation).
- this 0x155C: written with new instance count a2; persists between calls until next update.
- this 0x1560: array entries overwritten with new instance IDs; persists between calls until next update.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x155C | > | 0 | existing instance count used as loop bound for clearing |

**Guard interpretation:** this[0x13D8] (guard flag) must be non‑zero. If zero, function returns existing this[0x13D8] value immediately — entire instance update skipped.
