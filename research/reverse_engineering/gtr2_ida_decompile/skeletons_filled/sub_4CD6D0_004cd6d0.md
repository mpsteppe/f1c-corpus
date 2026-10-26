## sub_4CD6D0_004cd6d0 — conditional delegation helper (returns -1 when disabled)

**Summary:** `__thiscall` gate/helper: when the state field at this[0x30] is non-zero it delegates to `sub_4E1810` with arguments (a2, 0) and returns that result; when the field is zero it returns -1 as a failure/not-ready indicator.

**Called by:** sub_492930 (00492930), sub_493170 (00493170), sub_4942D0 (004942d0), sub_4943E0 (004943e0), sub_494530 (00494530), sub_494ED0 (00494ed0), sub_496840 (00496840), sub_49B9F0 (0049b9f0), sub_49BAC0 (0049bac0), sub_49C5A0 (0049c5a0), sub_4A04E0 (004a04e0), sub_4A66B0 (004a66b0) … +9 more

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x30 | R | — | State/enable flag (this[12]); non-zero allows delegation, zero forces the -1 return |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e1810 | sub_4E1810 | Delegate worker invoked as sub_4E1810(a2, 0); its return value is passed through when the flag is set |

**Guard conditions:** `this[0x30]` tested for non-zero. PASS (non-zero) → calls sub_4E1810(a2, 0) and returns its result. BLOCKED (zero) → returns literal -1 without calling the worker.
