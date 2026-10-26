## ColorAlphaUpdateFlagSet_004e21d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleStateUpdate_19d0 (004e19d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x14: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005acec4 | flt_5ACEC4 | R | Flt_TrackSegmentFade_SCEC4 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054e100 | PackedArrayTotalSize | [LLM] |
| 0054e120 | PackedArrayIndexLookup | [LLM] |
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
