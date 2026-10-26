## ConditionalFieldSetterWithState_00452700 — Conditional value capture with one-shot state

**Summary:** Manages a value capture with one-shot activation tracking: if override mode (offset 0x8) is set, always captures the input value; otherwise captures on first activation (0→1 transition) and ignores subsequent activations until deactivated (input 0 resets state). Called per-frame from collision update.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4537B0 (004537b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | Override flag — if non-zero, always write value regardless of state |
| this | 0xC | RW | 0 | Activation state flag — tracks whether first capture has occurred |
| this | 0x10 | RW | 0 | Captured value — set on successful capture, cleared otherwise |

**Written-by note (persistence):**
- this 0xC: state flag updated conditionally; external poke overwrites
- this 0x10: value written conditionally; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** When override (0x8) is non-zero → always captures. Otherwise: value 0→1 transition when state (0xC) is 0 → captures and sets state. Value 0 → resets state, clears captured value. If already activated (state=1) and new non-zero input arrives without intervening zero → captured value cleared to 0.
