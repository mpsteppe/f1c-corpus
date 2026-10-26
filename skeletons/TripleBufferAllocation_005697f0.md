## TripleBufferAllocation_005697f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsJointSystemLoader (0056d930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x22C | RW | 0 | [LLM] |
| this | 0x230 | RW | — | [LLM] |
| this | 0x234 | RW | 0 | [LLM] |
| this | 0x238 | RW | — | [LLM] |
| this | 0x23C | RW | 0 | [LLM] |
| this | 0x240 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x22C: recalc every frame — external poke does NOT persist
- this 0x230: recalc every frame — external poke does NOT persist
- this 0x234: recalc every frame — external poke does NOT persist
- this 0x238: recalc every frame — external poke does NOT persist
- this 0x23C: recalc every frame — external poke does NOT persist
- this 0x240: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
