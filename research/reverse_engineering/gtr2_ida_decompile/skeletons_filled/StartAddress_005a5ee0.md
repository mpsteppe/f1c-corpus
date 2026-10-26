## StartAddress_005a5ee0 — worker thread main loop (timer-driven tick)

**Summary:** Thread entry routine for the object's asynchronous worker: it polls a shutdown flag at this+0x10 under the mutex at this+0x14, and every time the accumulated timer delta exceeds 1/128 s invokes the object's vtable+0xA8 tick, accumulates clamped (0…10 s) elapsed seconds into the double at this+0xF0, runs the vtable+0x50/0x54 state checks (retried up to 3×), and flushes accumulated time through sub_5A4E50 and vtable+0xC once it exceeds 0.333 s; idles with an alertable SleepEx(5). APC/timer-driven subsystem thread.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC | R | — | Vtable slot 0xC (index 3) — called with the accumulated (>0.333 s) time as float when the flush triggers |
| obj | 0x50 | R | — | Vtable slot 0x50 (index 20) — boolean state check run (retried up to 3×) each frame |
| obj | 0x54 | R | — | Vtable slot 0x54 (index 21) — boolean state check run (retried up to 3×) each frame |
| obj | 0xA8 | R | — | Vtable slot 0xA8 (index 42) — per-frame tick/update called on the object when the frame gate passes |
| this | 0x0 | R | — | Vtable pointer used to resolve slots 0xC/0x50/0x54/0xA8 |
| this | 0x10 | R | — | Shutdown flag byte — read under the mutex; non-zero terminates the thread loop |
| this | 0x14 | R | — | Mutex handle protecting the shutdown flag |
| this | 0x18 | R | — | Wait timeout for the shutdown-flag mutex |
| this | 0xE0 | R | — | Second mutex handle (frame/time state); released unless the wait timed out or failed |
| this | 0xF0 | RW | — | Double accumulator — frame delta added in each tick (running total of processed seconds) |

**Written-by note (persistence):**
- this 0xF0: accumulated every processed frame (`+= clamped delta`); continuously recalculated while the thread runs — an external poke is absorbed/overwritten almost immediately and will not persist.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006ea6b3 | SEH_5A5EE0 | R | SEH scope/handler descriptor covering this thread routine's cleanup path |
| 006f1184 | ReleaseMutex | R | kernel32 import — releases the shutdown-flag mutex (0x14) and the frame mutex (0xE0) after use |
| 006f1188 | WaitForSingleObject | R | kernel32 import — acquires the shutdown-flag mutex and, with 1 ms timeout, the frame mutex at 0xE0; accepts 0/128 for the flag mutex |
| 006f11d4 | SleepEx | R | kernel32 import — alertable 5 ms idle so queued APCs can run |
| 006f1e9c | flt_6F1E9C | R | Float constant participating in the frame-timing comparisons (value inlined in the IDA output) |
| 006f4da8 | dbl_6F4DA8 | R | Double constant participating in the frame-timing comparisons (value inlined in the IDA output) |
| 00726388 | flt_726388 | R | Float constant participating in the frame-timing comparisons (value inlined in the IDA output) |
| 00731ce8 | String2 | R | String global consulted during thread start-up/setup (sub_5A3E40 path) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004eda30 | nullsub_7 | No-op destructor applied to the two timer structs (v15, v16) during SEH cleanup |
| 005a3e40 | sub_5A3E40 | Thread start-up initialization; called twice at entry |
| 005a4e50 | sub_5A4E50 | Time-slice consumer invoked with the object and the accumulated seconds once they exceed 0.333 |
| 00617e70 | sub_617E70 | Resets timer v15 after a frame is processed |
| 00617ed0 | sub_617ed0 | Reads elapsed seconds (double) from timer v16; result is clamped to 0…10 |
| 00617f80 | sub_617f80 | Returns elapsed time for timer v15; summed into v14 against the 0.0078125 frame threshold |

**Guard conditions:** Thread exit: the byte at this+0x10 is read under the mutex at 0x14 — if non-zero the loop breaks and the thread returns 0 (cleanup destructs v15/v16). Frame work is BLOCKED unless `v14 + sub_617F80(v15) > 0.0078125` (1/128 s). Delta clamp: a negative sub_617ED0 result becomes 0.0, values above 10.0 clamp to 10.0. The frame mutex at 0xE0 is released only when the wait result is not 258 (WAIT_TIMEOUT) and not -1 (WAIT_FAILED) and the handle is non-null. The vtable+0x54 and vtable+0x50 checks are each re-invoked up to 3 times while they keep returning true. Time-slice flush (sub_5A4E50 + vtable+0xC) only runs when the accumulated v13 exceeds 0.333, after which v13 is reset.
