## sub_5FDB10_005fdb10 — Reset record list and invoke global reset callback

**Summary:** Two-step teardown/reset stub: clears the active record list by calling sub_5FCBD0(this, 0) (clear-all mode), then tail-calls the global no-argument function pointer off_16C9744 and returns its result.

**Called by:** sub_5FDBD0 (005fdbd0), sub_60F3B0 (0060f3b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 016c9744 | off_16C9744 | R | Global function pointer invoked with no arguments after the list reset (reset/reinit/notify hook); its return value becomes this function's return value |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005fcbd0 | sub_5FCBD0 | Resets the active record list — called with a2 = 0, i.e. the clear-all mode that unqueues every record and zeroes the count |

**Guard conditions:** None — both steps run unconditionally: sub_5FCBD0(this, 0) always executes, then `off_16C9744()` is always called and its result returned. Nothing passes or is blocked.
