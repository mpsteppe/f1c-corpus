## RandomOffsetCalculator_004f6850 — randomized offset computation

**Summary:** Computes a2 * scale + bias, optionally randomizing a2 first via sub_5881F0 based on an enable flag. Used for stochastic variation in physics parameters.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_43C250 (0043c250), SuspensionAndWheelPhysics (004e5f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x56C | R | — | enable flag: 0 = randomize input, non-zero = skip randomization |
| this | 0x570 | R | — | bias term added to result (double) |
| this | 0x578 | R | — | scale factor multiplied with (possibly randomized) a2 (double) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005881f0 | sub_5881F0 | randomizes a2 input value (random seed/generator) |

**Guard conditions:** Byte at 0x56C: 0 → randomizes a2 via sub_5881F0 then scales. Non-zero → skips randomization, uses a2 directly.
