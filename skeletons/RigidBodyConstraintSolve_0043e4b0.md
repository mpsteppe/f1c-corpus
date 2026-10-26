## RigidBodyConstraintSolve_0043e4b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIVehiclePathPositionTracking (004ef7c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB4 | RW | 0 | [LLM] |
| this | 0x3A8 | RW | 18446744073709551615 | [LLM] |
| this | 0x3AC | RW | 18446744073708503039 | [LLM] |
| this | 0x15F0 | R | — | [LLM] |
| this | 0x15FC | R | — | [LLM] |
| this | 0x1604 | R | — | [LLM] |
| this | 0x160C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xB4: recalc every frame — external poke does NOT persist
- this 0x3A8: recalc every frame — external poke does NOT persist
- this 0x3AC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00567740 | FPUControlWordMaskExtract | [LLM] |
| 00567780 | EmptyStub_7780 | [LLM] |
| 0056bd40 | EulerAnglesTo33RotationMatrix | [LLM] |
| 0056f100 | sub_56F100 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
