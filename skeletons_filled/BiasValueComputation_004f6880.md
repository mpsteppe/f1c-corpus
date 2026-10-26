## BiasValueComputation_004f6880 — bias-offset randomized value (variant 2)

**Summary:** Computes a2 * scale + bias with optional randomization of a2, using different parameter offsets than RandomOffsetCalculator. Variant of the same stochastic physics parameter computation.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_43C250 (0043c250), SuspensionAndWheelPhysics (004e5f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x56C | R | — | enable flag: 0 = randomize input, non-zero = skip randomization |
| this | 0x588 | R | — | bias term added to result (double) |
| this | 0x590 | R | — | scale factor multiplied with (possibly randomized) a2 (double) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005881f0 | sub_5881F0 | randomizes a2 input value (random seed/generator) |

**Guard conditions:** Byte at 0x56C: 0 → randomizes a2 via sub_5881F0 then scales. Non-zero → skips randomization, uses a2 directly.
