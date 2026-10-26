## sub_6CE1D0_006ce1d0 — Step subobject processing (single-buffer)

**Summary:** One processing step against the subobject at a1[0x1AC]: when its busy/init flag (+0x30) is clear it first invokes the prepare callback reached through the table at a1[0x1B0] (slot +0xC) with the source pointer array (+0x8), then always invokes the worker callback through the table at a1[0x1B4] (slot +0x4) with (this, source array, cursor +0x34, limit this+0x140, a2, a3, a4); when the cursor reaches the limit both flag and cursor are reset (cycle restart).

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x140 | R | — | limit value passed to the worker callback and compared against the progress counter |
| this | 0x1AC | R | — | pointer to the target subobject (data object with source arrays and state fields) |
| this | 0x1B0 | R | — | callback table base A; slot +0xC holds the prepare/attach function |
| this | 0x1B4 | R | — | callback table base B; slot +0x4 holds the per-step worker function |
| this | 0x1B8 | R | — | worker function pointer loaded from table this+0x1B4 at slot +0x4 (indirect call target) |
| this | 0x1BC | R | — | prepare function pointer loaded from table this+0x1B0 at slot +0xC (indirect call target) |
| this | 0x1DC | RW | 0 | subobject field +0x30: init/busy flag — set to 1 after a successful prepare, cleared when the cursor reaches the limit |
| this | 0x1E0 | RW | 0 | subobject field +0x34: progress counter compared against this+0x140 and reset with the flag |

**Written-by note (persistence):**
- this 0x1DC: conditionally rewritten on every call (0 → prepare → 1 on success; back to 0 when the cursor reaches the limit) — an external poke is overwritten as soon as the state machine runs.
- this 0x1E0: reset to 0 whenever the previous call completed a cycle; otherwise advanced by the worker callback through the pointer `subobject+0x34` — recalculated on every call, so a poke does not survive the next invocation.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** the prepare callback runs only when the flag at subobject+0x30 (this 0x1DC) is 0 — if it returns 0 the function returns 0 immediately (processing blocked; flag stays 0). The flag is set to 1 only after a successful prepare. After the worker call, if the cursor at subobject+0x34 (this 0x1E0) is >= this+0x140, the flag and the cursor are both cleared to 0, restarting the cycle. The worker's return value is returned unchanged.
