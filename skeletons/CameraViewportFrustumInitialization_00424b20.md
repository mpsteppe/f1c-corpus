## CameraViewportFrustumInitialization_00424b20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4C6B60 (004c6b60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x413C | RW | 2139095039 | [LLM] |
| this | 0x41B4 | RW | 18446744073709551615 | [LLM] |
| this | 0x42CC | RW | 0 | [LLM] |
| this | 0x43F8 | RW | 0 | [LLM] |
| this | 0x4404 | RW | 18446744072627421184 → -1.0f | [LLM] |
| this | 0x442C | RW | 0 | [LLM] |
| this | 0x4430 | RW | 0 | [LLM] |
| this | 0x443C | RW | 0 | [LLM] |
| this | 0x444C | RW | 0 | [LLM] |
| this | 0x4454 | RW | — | [LLM] |
| this | 0x4458 | RW | 18446744073709551615 | [LLM] |
| this | 0x4460 | RW | 18446744072627421184 → -1.0f | [LLM] |
| this | 0x4464 | RW | 1065353216 → 1.0f | [LLM] |
| this | 0x446C | RW | 0 | [LLM] |
| this | 0x4470 | RW | 0 | [LLM] |
| this | 0x4474 | RW | 1148829696 → 999.0f | [LLM] |
| this | 0x4478 | RW | 0 | [LLM] |
| this | 0x4484 | RW | 1232348144 → 999999.0f | [LLM] |
| this | 0x44B0 | RW | 18446744073709551615 | [LLM] |
| this | 0x4510 | RW | 0 | driverStatus [CONFIRMED] |
| this | 0x4524 | RW | 0 | [LLM] |
| this | 0x4538 | RW | 1232348144 → 999999.0f | maxSpeed [CONFIRMED] |
| this | 0x4540 | RW | 1086324736 → 6.0f | [LLM] |
| this | 0x4544 | RW | 1 | [LLM] |
| this | 0x4548 | RW | 0 | [LLM] |
| this | 0x454C | RW | 0 | callToBox [CONFIRMED] |
| this | 0x4550 | RW | 0 | [LLM] |
| this | 0x4554 | RW | 1065353216 → 1.0f | [LLM] |
| this | 0x4558 | RW | 50 | [LLM] |
| this | 0x4560 | RW | 0 | [LLM] |
| this | 0x4564 | RW | 0 | [LLM] |
| this | 0x4584 | RW | 0 | [LLM] |
| this | 0x45F4 | RW | 0 | ActiveFlag [FACT] |
| this | 0x461C | RW | 1232348144 → 999999.0f | [LLM] |

**Written-by note (persistence):**
- this 0x413C: recalc every frame — external poke does NOT persist
- this 0x41B4: recalc every frame — external poke does NOT persist
- this 0x42CC: recalc every frame — external poke does NOT persist
- this 0x43F8: recalc every frame — external poke does NOT persist
- this 0x4404: recalc every frame — external poke does NOT persist
- this 0x442C: recalc every frame — external poke does NOT persist
- this 0x4430: recalc every frame — external poke does NOT persist
- this 0x443C: recalc every frame — external poke does NOT persist
- this 0x444C: recalc every frame — external poke does NOT persist
- this 0x4454: recalc every frame — external poke does NOT persist
- this 0x4458: recalc every frame — external poke does NOT persist
- this 0x4460: recalc every frame — external poke does NOT persist
- this 0x4464: recalc every frame — external poke does NOT persist
- this 0x446C: recalc every frame — external poke does NOT persist
- this 0x4470: recalc every frame — external poke does NOT persist
- this 0x4474: recalc every frame — external poke does NOT persist
- this 0x4478: recalc every frame — external poke does NOT persist
- this 0x4484: recalc every frame — external poke does NOT persist
- this 0x44B0: recalc every frame — external poke does NOT persist
- this 0x4510: recalc every frame — external poke does NOT persist
- this 0x4524: recalc every frame — external poke does NOT persist
- this 0x4538: recalc every frame — external poke does NOT persist
- this 0x4540: recalc every frame — external poke does NOT persist
- this 0x4544: recalc every frame — external poke does NOT persist
- this 0x4548: recalc every frame — external poke does NOT persist
- this 0x454C: recalc every frame — external poke does NOT persist
- this 0x4550: recalc every frame — external poke does NOT persist
- this 0x4554: recalc every frame — external poke does NOT persist
- this 0x4558: recalc every frame — external poke does NOT persist
- this 0x4560: recalc every frame — external poke does NOT persist
- this 0x4564: recalc every frame — external poke does NOT persist
- this 0x4584: recalc every frame — external poke does NOT persist
- this 0x45F4: recalc every frame — external poke does NOT persist
- this 0x461C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e864 | flt_59E864 | R | ColorQuantScale [DERIVED] (also: ` — Quantization scale for color channels) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00424c80 | AIRingBufferFieldInit | [LLM] |
| 00424cd0 | AICommandMessageQueueDispatcher | [LLM] |
| 00426430 | sub_426430 | [LLM] |
| 0042ae00 | AIClearStateFlags | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
