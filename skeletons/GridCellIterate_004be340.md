## GridCellIterate_004be340 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleEffectUpdateDispatch (004eb430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x924 | R | — | [LLM] |
| this | 0x928 | R | — | [LLM] |
| this | 0x92C | R | — | [LLM] |
| this | 0x930 | R | — | [LLM] |
| this | 0x934 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x934: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bda20 | ProximityCheckWithTagUpdate | [LLM] |
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
