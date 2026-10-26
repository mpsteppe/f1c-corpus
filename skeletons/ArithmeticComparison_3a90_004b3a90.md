## ArithmeticComparison_3a90_004b3a90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** NetCommSessionMessageDispatcher (0045d890), FloatComputation (00464b40), sub_465300 (00465300), AdvanceRingBuffer (004b3af0), CollisionObjectInsertion (004b48e0), FloatComparisonListIteration (004b5380), sub_4B6360 (004b6360), TimedAudioEventPlayback (004b9510), ZoneThresholdComparisonWithConditionalAction (004fffb0), CollisionStateUpdate (00500010), CollisionTestWithThreshold (00500560)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1AC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x1AC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
