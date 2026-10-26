## CarPartVisibilityController_004ae490 — UpdateCarPartVisibilityTargets

**Summary:** Updates car-part visibility slider targets across multiple part groups based on a mode selector at offset 0x1AC8. Mode 1 slides targets toward hidden (0 or 0.5f), mode 2 slides toward visible (1 or 0.5f), and any nonzero mode triggers additional visible-target processing for secondary part groups plus arithmetic comparison calls keyed by season-derived indices.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_472930 (00472930), TrackEnvironmentSelect (004ade20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB10 | RW | 1 | Group A first slider target: W = current mode (1 or 0) then clamped |
| this | 0xB18 | R | — | Group A first slider min bound |
| this | 0xB1C | R | — | Group A first slider max bound |
| this | 0xB34 | RW | 1 | Group A second slider target: W = current mode then clamped |
| this | 0xB3C | R | — | Group A second slider min bound |
| this | 0xB40 | R | — | Group A second slider max bound |
| this | 0xB58 | RW | 1 | Group A third slider target: W = current mode then clamped |
| this | 0xB60 | R | — | Group A third slider min bound |
| this | 0xB64 | R | — | Group A third slider max bound |
| this | 0x1AC8 | R | — | visibility mode selector: 0 = idle, 1 = hide/minimize parts, 2 = show/expand parts |
| this | 0x1C30 | RW | 0 | Group B slider target: W = 1 (mode 1) or 0 (mode 2) then clamped |
| this | 0x1C38 | R | — | Group B slider min bound |
| this | 0x1C3C | R | — | Group B slider max bound |
| this | 0x2348 | RW | 1056964608 → 0.5f | Group C first float slider target: W = 0.5f (mode 1) or 0.5f constant then clamped |
| this | 0x2350 | R | — | Group C first float slider min bound |
| this | 0x2354 | R | — | Group C first float slider max bound |
| this | 0x236C | RW | 1056964608 → 0.5f | Group C second float slider target: W = 0.5f then clamped between 0x2374 and 0x2378 |
| this | 0x2374 | R | — | Group C second float slider min bound |
| this | 0x2378 | R | — | Group C second float slider max bound |
| this | 0x26F0 | RW | 1 | Group D first slider target: W = 1 (always when mode nonzero) then clamped |
| this | 0x26F8 | R | — | Group D first slider min bound |
| this | 0x26FC | R | — | Group D first slider max bound |
| this | 0x2714 | RW | 1 | Group D second slider target: W = 1 then clamped |
| this | 0x271C | R | — | Group D second slider min bound |
| this | 0x2720 | R | — | Group D second slider max bound |
| this | 0x2738 | RW | 1 | Group D third slider target: W = 1 then clamped |
| this | 0x2740 | R | — | Group D third slider min bound |
| this | 0x2744 | R | — | Group D third slider max bound |
| this | 0x27EC | RW | 1 | Group E first slider target: W = 1 then clamped |
| this | 0x27F4 | R | — | Group E first slider min bound |
| this | 0x27F8 | R | — | Group E first slider max bound |
| this | 0x2810 | RW | 1 | Group E second slider target: W = 1 then clamped |
| this | 0x2818 | R | — | Group E second slider min bound |
| this | 0x281C | R | — | Group E second slider max bound |
| this | 0x2834 | RW | 1 | Group E third slider target: W = 1 then clamped |
| this | 0x283C | R | — | Group E third slider min bound |
| this | 0x2840 | R | — | Group E third slider max bound |

**Written-by note (persistence):**
- this 0xB10: written every call when mode is 1 or 2 (overwritten unconditionally in that path); external poke does not survive
- this 0xB34: written every call when mode is 1 or 2; external poke does not survive
- this 0xB58: written every call when mode is 1 or 2; external poke does not survive
- this 0x1C30: written every call when mode is 1 or 2; external poke does not survive
- this 0x2348: written every call when mode is 1 or 2; external poke does not survive
- this 0x236C: written every call when mode is 1 or 2; external poke does not survive
- this 0x26F0: written every call when mode is nonzero (post-LABEL_6 path); external poke does not survive
- this 0x2714: written every call when mode is nonzero; external poke does not survive
- this 0x2738: written every call when mode is nonzero; external poke does not survive
- this 0x27EC: written every call when mode is nonzero; external poke does not survive
- this 0x2810: written every call when mode is nonzero; external poke does not survive
- this 0x2834: written every call when mode is nonzero; external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ec3d0 | dword_5EC3D0 | R | SeasonParentPath [DERIVED] — season index used via ShortComputation_3060 to derive comparison operands |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423060 | ShortComputation_3060 | compute a short index from dword_5EC3D0 (season-derived integer, result decremented and passed to ArithmeticComparison_20d0) |
| 004646c0 | FloatClamp | clamp a float value between caller-supplied min and max bounds |
| 0047f1f0 | ClampByRange | clamp an integer value between caller-supplied min and max bounds |
| 004b20d0 | ArithmeticComparison_20d0 | piecewise/slider update step for car-part visibility, called with season-derived indices |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1AC8 | != | 2 | mode not 2 → skip the mode-1/mode-2 block and fall through to LABEL_6 |
| this | 0x1AC8 | == | 1 | mode 1 → hide parts: set Group A/B targets to 0/0, Group C to 0.5f; Group B = 1 |

**Guard interpretation:** The field at 0x1AC8 is the master visibility mode. When == 1, slider targets are pushed toward the hidden/minimized end (0 for integer sliders, 0.5f for float sliders); Group B gets target 1 instead of 0. When == 2, targets are pushed toward the visible/expanded end (1, with Group B set to 0). If mode is 0, the first block is skipped entirely. After LABEL_6, if mode is any nonzero value, Groups D and E are unconditionally set to target 1 (visible) and 7 calls to ArithmeticComparison_20d0 are made using season-derived indices plus a final constant 23, likely driving piecewise animation or visibility transitions for additional car parts.
