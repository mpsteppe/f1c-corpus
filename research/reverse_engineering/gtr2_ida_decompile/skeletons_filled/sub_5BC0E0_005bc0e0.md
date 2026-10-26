## sub_5BC0E0_005bc0e0 — decrement counter and fire virtual callback on expiry

**Summary:** Decrements the object's counter at `this+0x4` and stores it back. When the pre-decrement value was 1 (counter reaches zero) or the new value is negative, it invokes the virtual method in vtable slot +0x14 of the object and returns that result; otherwise it returns the decremented counter. A decrement-and-expire pattern, e.g. a countdown that triggers a virtual "expired" handler.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x14 | R | — | Vtable entry at offset +0x14 — the virtual callback invoked when the counter expires. |
| this | 0x0 | R | — | Object's vtable pointer; dereferenced to load the callback at +0x14. |
| this | 0x4 | RW | — | Integer countdown counter; decremented by 1 and stored back each call. |

**Written-by note (persistence):**
- this 0x4: decremented unconditionally on every call (`this[1] - 1`); an external poke survives only until the next invocation, which subtracts 1 from whatever is there.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | == | 1 | Counter's pre-decrement value; when it held 1 the decrement lands on 0 and the expiry callback fires. |

**Guard interpretation:** After `this[1] -= 1`, the vtable callback (`*this + 20`) is invoked when the new value is negative OR the old value was exactly 1 (counter hitting zero). PASSES (callback runs): old counter 1, or new value < 0 (old ≤ 0). BLOCKED (no callback, returns plain decremented value): old counter ≥ 2.
