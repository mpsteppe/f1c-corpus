## MemoryAllocation_cb20_0053cb20 — AudioEmitterAllocTryRegister

**Summary:** Allocates and creates an audio emitter object. Attempts registration via sub_5429B0; if registration fails leaves object intact (return 0), if registration succeeds frees the freshly-created object (return -1).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_4fb0 (00494fb0), CockpitDashboardLEDGaugeSetup (0049ca00), sub_4F9480 (004f9480), sub_552470 (00552470), sub_55A060 (0055a060)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output pointer storing allocated/created emitter |

**Written-by note (persistence):**
- this 0x0: conditional — written once during allocation; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005426a0 | AudioEmitterCreate | Initializes/creates audio emitter object from allocation |
| 005429b0 | sub_5429B0 | Registration/validation check for audio parameters |
| 00557470 | EmptyStub_7470 | Empty stub (debug/logging hook) |
| 00587bcf | FreeWrapper_7bcf | Heap free wrapper |
| 00587c03 | OperatorNewNhMallocWrapper | Heap allocation wrapper for 60-byte object |

**Guard conditions:** Checks allocation result: if NULL, zero stored to output. If sub_5429B0 returns 0 (registration failure), function returns 0 with object intact. If sub_5429B0 returns non-zero (success), object is freed and function returns -1.
