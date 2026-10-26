## LinkedListIteratorWithStateUpdate_004b5760 — List Walk With Audio State Update

**Summary:** Walks a linked list, testing each node against field/float/audio playback conditions. On match, updates node Z-position (offset 0x370) and decodes scene node via SceneNodeDecoder. Advances via next link.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B9000 (004b9000)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x20)+0x0) | 0x370 | RW | — | Node Z-position/distance field (updated from audio state) |
| *(this+0x20) | 0x0 | R | — | List head node pointer |
| *(this+0x28) | 0x4 | R | — | Next link of current walk node |
| *(this+0x28) | 0x8 | R | — | Second field of walk node (unused in logic) |
| this | 0x20 | R | — | List head pointer |
| this | 0x28 | RW | — | Current walk position |
| this | 0x30 | R | — | Float value (audio playback parameter) |

**Written-by note (persistence):**
- *(*(this+0x20)+0x0) 0x370: Updated with audio-derived float value; per-node conditional.
- this 0x28: Written each iteration with next node; per-call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00410f60 | SceneNodeDecoder | Decode/render scene node using audio state data |
| 005001d0 | FieldCompareConstant | Test node field against constant (gate condition) |
| 005001f0 | FloatComparisonCheck | Test node float against threshold (gate condition) |
| 00500210 | AudioSamplePlaybackWithPitchModulationAndStereoP | Query audio sample playback state with pitch/stereo params |

**Guard conditions:** If this+0x20 (head pointer) is NULL, return immediately. For each node: advance via result[1] (next link) only. Node is processed (update 0x370 + SceneNodeDecoder) only if FieldCompareConstant AND FloatComparisonCheck AND AudioSamplePlaybackWithPitchModulationAndStereoP all return TRUE. Loop terminates when next pointer is NULL.
