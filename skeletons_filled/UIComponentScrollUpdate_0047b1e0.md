## UIComponentScrollUpdate_0047b1e0 — UIComponentScrollUpdate

**Summary:** UI scroll/selection update handler: dispatches scroll logic based on state (this+0x104), managing a float accumulator timer, bounded counter updates, and layout recalculation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | Virtual function at vtable offset 44 (index 11) — initial update call |
| obj | 0x54 | R | — | Virtual function at vtable offset 84 (index 21) — final update/refresh call |
| this | 0x0 | R | — | Vtable pointer |
| this | 0x4 | R | — | Lower bound value for scroll range |
| this | 0x8 | R | — | Upper bound value for scroll range |
| this | 0x40 | R | — | Pointer to an object used for DualFieldRead and FloatFieldAccessor |
| this | 0xE4 | RW | — | Result of MenuItemLayoutCalculator (scroll layout position) |
| this | 0xFC | R | — | Offset/adjustment value for scroll boundary calculations |
| this | 0x104 | R | — | Scroll state/mode (1-5, used in switch dispatch) |
| this | 0x108 | RW | — | Float accumulator (scroll timer/debounce, decremented by 0.125 or 0.25) |
| this | 0x110 | RW | 0 | Scroll delta/offset result (set in case 4) |
| this | 0x114 | R | — | Maximum scroll bound (clamp ceiling) |
| this | 0x11C | R | — | Current item position reference |

**Written-by note (persistence):**
- this 0xE4: Written with layout calculation result; persists until next scroll update
- this 0x108: Float accumulator decremented each tick; persists across updates
- this 0x110: Written with bounded scroll delta; persists until next update

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0047b3c0 | jpt_47B22B | R | Jump table for switch-case dispatch on scroll state |
| 0059e4e0 | flt_59E4E0 | R | Scroll auto-repeat threshold (delta time gate) |
| 0059e7f8 | flt_59E7F8 | R | Anti-roll mixing factor |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0047b850 | MenuItemLayoutCalculator | Calculates scroll item layout position based on direction |
| 0047bae0 | BoundedCounterUpdate | Increments/decrements scroll counter within bounds |
| 0047bb40 | sub_47BB40 | Handles scroll jump (case 5 — rapid scroll) |
| 0047be00 | sub_47BE00 | Handles scroll delta clamping and position update (case 4) |
| 00498730 | FloatFieldAccessor | Reads a float value from the scroll object |
| 00498880 | DualFieldRead | Reads current/end indices from the scroll object |

**Guard conditions:** Switch on this+0x104 (scroll state mode 1-5). Each case has additional guards: cases 1-3 check float accumulator threshold (0.125); case 4 checks scroll delta sign; case 5 checks float > 0.25. Default/fallthrough in LABEL_18 always calls vtable+84.
