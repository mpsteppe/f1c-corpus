## UIElementInitialization_00537e40 — AudioCodecContextInit

**Summary:** Initializes audio codec context object by setting up vtable pointers (off_5DA928, off_5DA93C), internal buffer self-pointers, a D3D shader/state pointer (unk_5DA950), and zeroing the bitstream shift register state. Part of audio codec initialization pipeline.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ConditionalMultiFieldReset (00535e10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB0E | RW | — | internal buffer pointer, set to this+138 (audio data region) |
| this | 0xB16 | RW | — | internal buffer pointer, set to this+2430 |
| this | 0xB1A | RW | — | vtable pointer set to &off_5DA928 |
| this | 0xB22 | RW | — | vtable pointer set to &off_5DA93C |
| this | 0xB26 | RW | — | internal buffer pointer, set to this+2674 |
| this | 0xB2E | RW | — | pointer set to &unk_5DA950 (D3D shader/state) |
| this | 0x16A7 | RW | 8 | buffer capacity/size field, initialized to 8 |
| this | 0x16AB | RW | 0 | bitstream accumulation shift register (low word), cleared |
| this | 0x16AD | RW | 0 | bitstream bit count/index, cleared |

**Written-by note (persistence):**
- this 0xB0E: recalc every frame — external poke does NOT persist
- this 0xB16: recalc every frame — external poke does NOT persist
- this 0xB1A: recalc every frame — external poke does NOT persist
- this 0xB22: recalc every frame — external poke does NOT persist
- this 0xB26: recalc every frame — external poke does NOT persist
- this 0xB2E: recalc every frame — external poke does NOT persist
- this 0x16A7: recalc every frame — external poke does NOT persist
- this 0x16AB: recalc every frame — external poke does NOT persist
- this 0x16AD: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005da928 | off_5DA928 | R | VTable_AudioClass [DERIVED] |
| 005da93c | off_5DA93C | R | PtrTable_5DA93C [DERIVED] |
| 005da950 | unk_5DA950 | R | D3D_Shader_StatePtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00537eb0 | EmptyStub_7eb0 | empty stub function, called for initialization sequencing |

**Guard conditions:** No guard conditions — function always executes fully.
