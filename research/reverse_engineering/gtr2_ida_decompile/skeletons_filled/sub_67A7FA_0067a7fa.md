## sub_67A7FA_0067a7fa — PNG output-write dispatch

**Summary:** Dispatches an output write through the user-supplied write callback stored on the PNG struct: errors out if no write function is registered, otherwise forwards the buffer/length arguments to it. It is the writer's low-level "emit bytes" trampoline.

**Called by:** sub_6B743C (006b743c), sub_6B74A7 (006b74a7), sub_6B74D0 (006b74d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4C | R | — | registered write callback pointer; invoked as fn(this, buffer, length) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0073c91c | aCallToNullWrit | R | "Call to NULL write function" error string used when the callback pointer is NULL |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00679f05 | GuardedCallWithLongjmp [structural] | longjmp-guarded error dispatch used when no write function is registered |

**Guard conditions:** Reads the callback pointer at this+0x4C: nonzero → it is called with (this, a2, a3) and its result returned. Zero → the guarded error path is invoked with "Call to NULL write function"; the trailing call is unreachable in practice because that error never returns normally.

**String literals referenced (deterministic):**

- `Call to NULL write function`
