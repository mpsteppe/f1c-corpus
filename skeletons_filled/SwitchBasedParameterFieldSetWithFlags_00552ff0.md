## SwitchBasedParameterFieldSetWithFlags_00552ff0 — AlphaBlendParamSetter

**Summary:** Sets two render state fields. Writes a2 to this[21] (offset 0x54, texture coordinate/scale parameter). Maps a3 (0-4) to an alpha blend value in this[22] (offset 0x58): case 0=191, 1=127, 2=63, 3=0, 4=255. Returns a3. Values out of 0-4 range skip the switch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FontSurfaceLookupDispatch (0053d260)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x54 | RW | — | Texture/scale parameter (a2, passed through) |
| this | 0x58 | RW | 255 | Alpha blend value selected by switch: 191(0), 127(1), 63(2), 0(3), 255(4) |

**Written-by note (persistence):**
- this 0x54: written unconditionally; survives external poke
- this 0x58: written conditionally (only for a3 0-4 with valid switch cases); survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0055303c | jpt_553000 | R | Jump table for switch on a3 (5 blend mode cases) |

**Guard conditions:** Default case (a3 < 0 or > 4): returns early without writing this[22], preserves previous value. Only a3 0-4 match and write this[22].
