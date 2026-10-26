## VTableDispatchChain_7e00_004d7e00 — VTableDispatchChain

**Summary:** Two-stage vtable dispatch: calls check method (vtable[6] at offset +0x18), conditionally invokes sub_4D7FE0 and PhaseBasedAudioParticleEnvelope, then dispatches to final method (vtable[1] at offset +0x4) and returns result. Called by sub_4D8450.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D8450 (004d8450)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | vtable offset for final dispatch method |
| obj | 0x18 | R | — | vtable offset for check/query method (returning bool) |
| this | 0x0 | R | — | vtable pointer (dispatched through) |
| this | 0x8 | R | — | boolean flag controlling PhaseBasedAudioParticleEnvelope call |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7fe0 | sub_4D7FE0 | called conditionally after vtable check passes |
| 004d7ff0 | PhaseBasedAudioParticleEnvelope | called when this+0x8 is non-zero |

**Guard conditions:** two independent checks: (1) vtable check method at +0x18 returns true — PASSES to sub_4D7FE0; (2) this+0x8 non-zero — PASSES to PhaseBasedAudioParticleEnvelope. Final vtable+0x4 dispatch always executes.
