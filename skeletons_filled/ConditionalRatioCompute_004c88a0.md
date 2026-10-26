## ConditionalRatioCompute_004c88a0 — ConditionalAudioMixerRatioUpdate

**Summary:** Same enable-flag guard pattern as fade update; computes ratio using audio mixer value as numerator divided by a2. Sets state flag to 2. Part of audio/visual synchronization system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4F9480 (004f9480)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | Enable flag for ratio update |
| this | 0x14 | RW | 2 | State flag (set to 2 when guard passes) |
| this | 0x18 | RW | — | Computed ratio value (float) |

**Written-by note (persistence):**
- this 0x14: Set to 2 each time guard passes; persists until next call overwrites
- this 0x18: Set to flt_7CF380 or audio-mixer-value/a2 when guard passes; persists float

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 007cf380 | flt_7CF380 | R | RenderFadeAlpha [DERIVED] (also: ` -- unknown float global) |
| 008ac4c8 | dword_8AC4C8 | R | AudioMixerPtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks byte at this+0x10 != 0, dword_8AC4C8 non-null, *(dword_8AC4C8+4) >= 0.0. ALL must pass to proceed; else function does nothing.
