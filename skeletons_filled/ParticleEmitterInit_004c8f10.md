## ParticleEmitterInit_004c8f10 — ParticleEmitterInit

**Summary:** Initializes particle emitter struct: sets vtable pointer, zeroes state fields, configures duration (default 1.0), and computes randomized end offset from trig lookup table.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MemoryAllocation_9a50 (004c9a50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer (set to off_5ACE2C) |
| this | 0x4 | RW | — | Float field, initialized to 0.0 |
| this | 0x8 | RW | — | Float state, initialized to 0.0 |
| this | 0xC | RW | — | Float state, initialized to 0.0 |
| this | 0x10 | RW | — | Float state, initialized to 0.0 |
| this | 0x14 | RW | — | Duration/lifetime (1.0 or a2 parameter) |
| this | 0x18 | RW | — | End offset: trig-lookup random + duration |

**Written-by note (persistence):**
- this 0x0: Set once to vtable; persists for object lifetime
- this 0x4: Set once to 0.0; persists until modified by emitter logic
- this 0x8: Set once to 0.0; persists until modified by emitter logic
- this 0xC: Set once to 0.0; persists until modified by emitter logic
- this 0x10: Set once to 0.0; persists until modified by emitter logic
- this 0x14: Set once per init; persists as lifetime countdown
- this 0x18: Set once per init; persists as end boundary

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` â€” reverse gear throttle multiplier) |
| 005ace2c | off_5ACE2C | R | VTableRef_5ACE2C [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 <= 0 sets duration to 1.0, else uses a2 as duration. No early return guard.
