## AISpeedDeltaSetter_0042aca0 — AISpeedDeltaSetter

**Summary:** Sets AI speed delta flag (this[0x4550]) to a2 (0 or 1). When a2 == 1, additionally triggers AI state transition via sub_4A46F0(this, 1, 0) to enter speed-limited mode. Used by command queue and session state handlers.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CommandQueueResponseHandler (00429ee0), SessionStateTransition (004ef5a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4550 | RW | — | speed delta flag — 0 = normal speed, 1 = apply speed delta limit |

**Written-by note (persistence):**
- this 0x4550: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ce2f0 | unk_7CE2F0 | R | Unknown_AI_Struct_7CE2F0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a46f0 | sub_4A46F0 | triggers AI state transition (to state 1, param 0) when speed delta is activated |

**Guard conditions:** Only writes speed delta flag when a2 <= 1. Only triggers state transition when a2 == 1.
