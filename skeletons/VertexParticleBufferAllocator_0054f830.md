## VertexParticleBufferAllocator_0054f830 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CameraViewSetupFromVehiclePosition (0045af50), SuspensionAndWheelPhysics (004e5f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1E0)+0x8) | 0x0 | RW | 0 | [LLM] |
| *(*(this+0x1E0)+0x8) | 0x4 | RW | — | [LLM] |
| *(*(this+0x1E0)+0x8) | 0x8 | RW | — | [LLM] |
| *(*(this+0x1E0)+0x8) | 0xC | RW | — | [LLM] |
| *(*(this+0x1E0)+0x8) | 0x1C | RW | — | [LLM] |
| *(*(this+0x1E0)+0x8) | 0x20 | RW | — | [LLM] |
| *(*(this+0x1E0)+0x8) | 0x24 | RW | — | [LLM] |
| *(this+0x1E0) | 0x0 | RW | — | [LLM] |
| *(this+0x1E0) | 0x8 | RW | — | [LLM] |
| *(this+0x204) | 0xDC | R | — | [LLM] |
| *(this+0x204) | 0xE0 | R | — | [LLM] |
| *(this+0x204) | 0xE4 | R | — | [LLM] |
| this | 0x1E0 | RW | 0 | [LLM] |
| this | 0x204 | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x1E0)+0x8) 0x0: recalc every frame — external poke does NOT persist
- *(*(this+0x1E0)+0x8) 0x4: recalc every frame — external poke does NOT persist
- *(*(this+0x1E0)+0x8) 0x8: recalc every frame — external poke does NOT persist
- *(*(this+0x1E0)+0x8) 0xC: recalc every frame — external poke does NOT persist
- *(*(this+0x1E0)+0x8) 0x1C: recalc every frame — external poke does NOT persist
- *(*(this+0x1E0)+0x8) 0x20: recalc every frame — external poke does NOT persist
- *(*(this+0x1E0)+0x8) 0x24: recalc every frame — external poke does NOT persist
- *(this+0x1E0) 0x0: recalc every frame — external poke does NOT persist
- *(this+0x1E0) 0x8: recalc every frame — external poke does NOT persist
- this 0x1E0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054eaf0 | ShortComputation_eaf0 | [LLM] |
| 0054eb20 | sub_54EB20 | [LLM] |
| 0054fa50 | LinkedNodeDestruction | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
