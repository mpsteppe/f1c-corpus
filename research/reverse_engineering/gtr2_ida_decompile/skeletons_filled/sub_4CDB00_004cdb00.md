## sub_4CDB00_004cdb00 — periodic step with guard-gated secondary call

**Summary:** `__thiscall` update step: always invokes virtual slot +0xA0 on the object, then — only while the guard byte at this+0x110 is set — additionally invokes virtual slot +0x88, and returns 0. Acts as the periodic tick that consults the transaction/guard flag raised by the state-sequencing routine.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x88 | R | — | Vtable slot +0x88; invoked only when the guard byte at this+0x110 is non-zero (secondary step/cancel path — specific effect unknown) |
| obj | 0xA0 | R | — | Vtable slot +0xA0; invoked unconditionally as the main step (specific effect not inferable — unknown) |
| this | 0x0 | R | — | Vtable pointer used to resolve slots +0x88 and +0xA0 |
| this | 0x110 | R | — | Guard byte; non-zero enables the extra virtual +0x88 call, zero skips it |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `this[0x110]` (byte) tested for non-zero. PASS (non-zero) → the +0x88 virtual call is made after the mandatory +0xA0 call. BLOCKED (zero) → only the +0xA0 call runs. Always returns 0.
