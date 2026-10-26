## ArithmeticComparison_3a90_004b3a90 — Size-prefixed data copy

**Summary:** Copies variable-length data from source to destination using a 10-bit size field extracted from bits 8-17 of the source's first dword, plus 8 bytes minimum. Also copies field at offset 0x1AC between structures.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** NetCommSessionMessageDispatcher (0045d890), FloatComputation (00464b40), sub_465300 (00465300), AdvanceRingBuffer (004b3af0), CollisionObjectInsertion (004b48e0), FloatComparisonListIteration (004b5380), sub_4B6360 (004b6360), TimedAudioEventPlayback (004b9510), ZoneThresholdComparisonWithConditionalAction (004fffb0), CollisionStateUpdate (00500010), CollisionTestWithThreshold (00500560)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1AC | RW | — | Copied field from source at matching offset a2[107] |

**Written-by note (persistence):**
- this 0x1AC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Copy only performed when ((*a2 >> 8) & 0x3FF) + 8 > 0 (non-zero size). If size is 0, BLOCKED — only field at 0x1AC is copied.
