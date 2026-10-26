## CircularBufferSlotAlloc_004cb540 — ParticleSlotAllocator

**Summary:** Allocate next free slot from a circular particle buffer. Increments write index, wraps at capacity, returns pointer to slot. If slot is free (refcount < 0), bookkeeps it.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleCollisionSpark (004cb620), ParticleTrailEmitter (004cbc50), sub_4CC970 (004cc970), ParticleSpawnFunction (004cce90), WheelContactParticle (004cd6c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | R | — | buffer capacity / max slots |
| this | 0x5C | R | — | buffer base pointer |
| this | 0x60 | RW | 0 | current write index (circular) |
| this | 0x64 | R | — | allocation count (number of active slots) |
| this | 0x68 | R | — | allocation tracking array pointer |

**Written-by note (persistence):**
- this 0x60: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00558a30 | sub_558A30 | unknown (slot init / age reset) |

**Guard conditions:** None — always advances the circular index. Caller must check if slot count > 0 before calling.
