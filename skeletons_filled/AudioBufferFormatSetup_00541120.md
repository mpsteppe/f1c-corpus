## AudioBufferFormatSetup_00541120 — Audio buffer format setup with channel config

**Summary:** Configures audio buffer format: initializes struct, sets channel count at this+0x1170 (2304/256/1280 variants), bit depth, sample rate, and audio mode flags. Dispatches to sub-setters (StructInitWithDefaultValues, PropertyValueSetterWithRefreshOnChange, etc.) for property updates.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_553070 (00553070), sub_553700 (00553700)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0x94 | R | — | vtable[37] (offset 148) on sub-object — set buffer |
| *(this+0x1100) | 0xC8 | R | — | vtable[50] (offset 200) on sub-object — set state |
| *(this+0x1100) | 0x118 | R | — | vtable[70] (offset 280) on sub-object — set format |
| this | 0x0 | RW | — | stores return values from vtable calls |
| this | 0x1100 | R | — | sub-object pointer (index 1088) for all vtable dispatch |
| this | 0x1170 | RW | 2304 | channel/config field (this[1116]) — set to 256/1280/2304 based on flags |
| this | 0x13B8 | R | — | state field (this[1267]) — checked for conditional init |
| this | 0x13CC | RW | 0 | state field (this[1262]) — saved before final vtable call |

**Written-by note (persistence):**
- this 0x0: overwritten by each vtable call — last result persists
- this 0x1170: set based on a7/a8 flags — persists until reconfigured
- this 0x13CC: saved/restored around format calls — survives if not changed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00553db0 | StructInitWithDefaultValues | initializes local struct to defaults |
| 00553fa0 | StateFieldSetWithChainedInit | sets state fields with chained initialization |
| 005546a0 | MultiFieldSetterDispatchingTo7SubSetters | dispatches to 7 sub-setters from struct |
| 00554700 | PropertyValueSetterWithRefreshOnChange | sets property value with refresh-on-change |
| 00554790 | sub_554790 | handles buffer config with mode flags |
| 00554f80 | sub_554F80 | validates audio stream handle |

**Guard conditions:** a3 (audio object) must be non-null and have non-zero field at +32 to proceed. If this[1267] non-zero → calls vtable[37] to set buffer, then clears this[1267]. If a6 (stream handle) non-zero → calls sub_554F80 for stream validation, configures v20/v22/v23 based on a8 flags (0x1400, 0x2800, 0x80, 0x40, 0x20).
