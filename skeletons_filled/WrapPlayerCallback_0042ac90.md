## WrapPlayerCallback_0042ac90 — WrapPlayerCallback

**Summary:** Wraps player session callback by computing callToBox flag = AiOvertakeDistanceThreshold + this[0x4], then writing it via AIStateFlagSetter. Used during phase-3 cleanup in CommandQueueResponseHandler.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CommandQueueResponseHandler (00429ee0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | offset value added to overtake distance threshold for flag calculation |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea2cc | dword_5EA2CC | R | AiOvertakeDistanceThreshold [DERIVED] — base value for callToBox flag calculation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ac70 | AIStateFlagSetter | writes computed flag value to callToBox field |

**Guard conditions:** No guard — always calls AIStateFlagSetter (which internally guards against values > 1).
