## sub_67CBAE_0067cbae — CallReadCallback

**Summary:** Minimal dispatch wrapper that calls the per-object read callback stored at this+0x50 with (this, a2, a3). If that pointer is NULL it raises "Call to NULL read function" via the guarded-call handler instead of crashing.

**Called by:** sub_67AB08 (0067ab08), sub_67AC9B (0067ac9b), sub_6B9DC1 (006b9dc1), AnimationStateCheck [structural] (006b9dda), sub_6BAE2D (006bae2d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x50 | R | — | function pointer to the object's read callback, invoked as f(this, a2, a3) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0073cc0c | aCallToNullRead | R | error text "Call to NULL read function" passed to the guard handler |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00679f05 | GuardedCallWithLongjmp [structural] | reports the NULL-callback fault (string global) and aborts the call |

**Guard conditions:** this+0x50 == 0 (NULL pointer) → the read is BLOCKED and sub_679F05 is invoked with "Call to NULL read function" (guarded fault/longjmp). Non-NULL pointer → the callback is called with (this, a2, a3) and its return value is returned unchanged.

**String literals referenced (deterministic):**

- `Call to NULL read function`
