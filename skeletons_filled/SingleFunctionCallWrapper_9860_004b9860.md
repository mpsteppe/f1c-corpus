## SingleFunctionCallWrapper_9860_004b9860 — StateTimestepFactorSetter

**Summary:** Writes a2 to obj+0x9AC and sets obj+0xF7C to a float constant corresponding to the timestep/index value (0-4 maps to ~0.04-0.16f). Part of simulation timestep/update rate configuration.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4BA460 (004ba460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x9AC | RW | — | state/timestep index value (written with a2 parameter) |
| obj | 0xF7C | RW | 1026206379 → 0.0417f | timestep factor float (set to one of five constants based on a2) |
| this | 0x0 | R | — | pointer to actual object (dereferenced to get obj) |

**Written-by note (persistence):**
- obj 0x9AC: set once per call; persists as current timestep index
- obj 0xF7C: set once per call; persists as current timestep factor

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If a2 < 0 or a2 > 4, returns early without writing to obj+0xF7C (only writes obj+0x9AC). Values 0-4 each set a specific float constant.
