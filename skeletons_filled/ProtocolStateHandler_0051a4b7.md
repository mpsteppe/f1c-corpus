## ProtocolStateHandler_0051a4b7 — ProtocolStateHandler

**Summary:** Selects processing handler (AudioSubbandSynthesisFilterbank or DrawableObjectBatchProcessor) based on render state validation flag, then resets position counter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x184) | 0xC | RW | — | handler function pointer, written with selected handler |
| *(this+0x184) | 0x10 | R | — | enable flag; if nonzero, handler selection proceeds |
| this | 0x49 | R | — | byte flag indicating render state is valid (route to audio handler) |
| this | 0x88 | RW | 0 | position counter, zeroed unconditionally |
| this | 0x184 | R | — | pointer to handler state struct |

**Written-by note (persistence):**
- *(this+0x184) 0xC: once, conditional on enable flag (0x194); set to AudioSubbandSynthesisFilterbank or DrawableObjectBatchProcessor; survives external poke
- this 0x88: once, unconditional (zeroed); survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00519d51 | DrawableObjectBatchProcessor | R | default processing handler function pointer |
| 00519f9a | AudioSubbandSynthesisFilterbank | R | audio processing handler function pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00519eb7 | RenderStateCopyWithValidation | validates render state; nonzero return selects audio handler path |

**Guard conditions:** *(this->0x184 + 16) must be nonzero to enter handler selection. Then this->0x49 byte must be nonzero AND RenderStateCopyWithValidation must return nonzero to PASS as audio path (sets AudioSubbandSynthesisFilterbank). Otherwise BLOCKED to default (DrawableObjectBatchProcessor).
