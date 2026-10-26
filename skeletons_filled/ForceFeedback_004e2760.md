## ForceFeedback_004e2760 — ForceFeedbackPacketBuild

**Summary:** Builds force feedback output packet. Iterates 4 wheels packing type and force data into bit fields, packs steering/vibration values into output bytes/words. If FFB enable flag at offset 0x98C is set, iterates 17 channels scaling forces to ±32767 range and packs into output structure; otherwise zeros FFB fields. Returns pointer to output packet at this+0x938.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4EF2E0 (004ef2e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x98 | R | — | first wheel force value (float) |
| this | 0xAC | R | — | second wheel force value (float) |
| this | 0xC0 | R | — | third wheel force value (float) |
| this | 0x108 | R | — | wheel type/index per wheel, used for bit encoding |
| this | 0x1E8 | R | — | fourth wheel force value (float) |
| this | 0x938 | RW | — | FFB output packet DWORD (packed force data) |
| this | 0x93C | RW | — | FFB output packet WORD (steering/vibration packed) |
| this | 0x93E | RW | — | FFB output packet BYTE (vibration intensity) |
| this | 0x93F | RW | 0 | FFB output packet BYTE (channel flags pack) |
| this | 0x940 | RW | 0 | FFB output packet DWORD (channel bitmask) |
| this | 0x944 | RW | 0 | FFB output packet WORD (force X channel) |
| this | 0x946 | RW | 0 | FFB output packet WORD (force Y channel) |
| this | 0x948 | RW | 0 | FFB output packet WORD (force Z channel) |
| this | 0x98C | R | — | FFB enable flag byte, gates channel packing |
| this | 0x9A8 | R | — | first FFB channel force data (stride 28 bytes) |

**Written-by note (persistence):**
- this 0x938: written each call (packet built from scratch)
- this 0x93C: written each call
- this 0x93E: written each call
- this 0x93F: written each call (0 in disabled branch, packed in enabled branch)
- this 0x940: written each call (0 in disabled branch, bitmask in enabled)
- this 0x944: written each call (0 in disabled branch, force value in enabled)
- this 0x946: written each call
- this 0x948: written each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e708 | flt_59E708 | R | SoundVolumeLowThreshold [DERIVED] (also: ` — low threshold) |
| 0059e70c | flt_59E70C | R | FFBMinThreshold [DERIVED] (also: ` — FFB minimum threshold) |
| 0059e710 | flt_59E710 | R | FFB_SaturationThreshold [DERIVED] (also: ` — FFB maximum threshold) |
| 0059e864 | flt_59E864 | R | ColorQuantScale [DERIVED] (also: ` — Quantization scale for color channels) |
| 0059e8d8 | flt_59E8D8 | R | BrakingSpeedThreshold3 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | convert float to integer (round to nearest) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x108 | < | 24 | wheelType |

**Guard interpretation:** Wheel type at offset 0x108 (per wheel in loop). When < 24, type>>3 yields valid wheel category (0-2). When >= 24, type caps to 3 (default/invalid). Also FFB enable flag at 0x98C: if non-zero, pack 17 force channels; if zero, zero all FFB output fields.
