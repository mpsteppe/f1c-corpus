## SessionCleanupFlagClear_0042adb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AICommandMessageQueueDispatcher (00424cd0), AIMainUpdate (00424e70), CommandQueueResponseHandler (00429ee0), VehicleProximityCollisionDetection (004a5fa0), SessionStateTransition (004ef5a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4410 | R | — | RetiredFlag [FACT] |
| this | 0x4424 | RW | 0 | [LLM] |
| this | 0x45F4 | RW | 1 | ActiveFlag [FACT] |

**Written-by note (persistence):**
- this 0x4424: recalc every frame — external poke does NOT persist
- this 0x45F4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
