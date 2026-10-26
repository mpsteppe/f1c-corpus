## sub_60ABB0_0060abb0 — default-init wrapper (clear refs, set defaults, delegate to configure)

**Summary:** Initializer that clears the managed reference slots (0xCC–0xDC) and 0xE4, sets the defaults this+0xF0 = 1 and this+0xF4 = 4, then delegates to sub_60AA40 with the id a2, float 0.0, the constant 1120403456 (0x42C80000 = 100.0f bit pattern) and the flag byte a3.

**Called by:** sub_604F60 (00604f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xCC | RW | 0 | cleared to 0 here, then overwritten with a2 by the delegated sub_60AA40 |
| this | 0xD0 | RW | 0 | managed reference slot cleared to 0 (detach is done by sub_60AA40) |
| this | 0xD4 | RW | 0 | managed reference slot cleared to 0 |
| this | 0xD8 | RW | 0 | managed reference slot cleared to 0 |
| this | 0xDC | RW | 0 | managed reference slot cleared to 0 |
| this | 0xE4 | RW | 0 | float slot cleared to 0 (sub_60AA40 re-stores 0.0 there) |
| this | 0xF0 | RW | 1 | default state value set to 1 |
| this | 0xF4 | RW | 4 | default parameter set to 4; role not determinable from this snippet |

**Written-by note (persistence):**
- this 0xCC: written unconditionally (0, then a2 via the callee); an external poke survives until the next call.
- this 0xD0: written unconditionally to 0; external poke survives until the next call.
- this 0xD4: written unconditionally to 0; external poke survives until the next call.
- this 0xD8: written unconditionally to 0; external poke survives until the next call.
- this 0xDC: written unconditionally to 0; external poke survives until the next call.
- this 0xE4: written unconditionally (0, then 0.0 via the callee); external poke survives until the next call.
- this 0xF0: written unconditionally to 1; external poke survives until the next call.
- this 0xF4: written unconditionally to 4; external poke survives until the next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0060aa40 | sub_60AA40 | configure/reset routine: stores id a2 at +0xCC and flag a3 at +0xED, detaches refs 0xD0–0xE0 through the manager, stores float a7 at +0xE4; a8 (100.0f bit pattern) is ignored inside it |

**Guard conditions:** none — every store and the call to sub_60AA40 execute unconditionally; no field or argument is tested.
