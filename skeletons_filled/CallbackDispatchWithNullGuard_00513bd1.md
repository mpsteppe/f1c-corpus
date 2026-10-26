## CallbackDispatchWithNullGuard_00513bd1 — CallbackDispatchWithNullGuard

**Summary:** Dispatch to callback function pointer at this+0x50 with null guard. If non-null, invoke callback(a1,a2,a3); if null, call GuardedCallWithLongjmp with error string.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5119E9 (005119e9), sub_511B7C (00511b7c), sub_517F58 (00517f58), AnimationStateCheck (00517f72), sub_519019 (00519019)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x50 | R | — | read function callback pointer (null = error) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af4d0 | aCallToNullRead | R | error string "Call to NULL read function" |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00511869 | GuardedCallWithLongjmp | error handler with longjmp recovery |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x50 | != | NULL | callback function pointer — must be non-null for normal dispatch |

**Guard interpretation:** PASSES (normal path) when callback at 0x50 != NULL → invoke it. BLOCKED (error path) when callback == NULL → call GuardedCallWithLongjmp with error message.
