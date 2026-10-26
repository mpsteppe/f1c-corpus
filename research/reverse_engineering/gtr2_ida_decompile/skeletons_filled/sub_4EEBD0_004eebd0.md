## sub_4EEBD0_004eebd0 — ProcessExpiredChildTimers

**Summary:** Watchdog over 11 per-child timeout deadlines: when the current time (dbl_FB1D18) has passed an armed deadline (field != FLT_MAX), and none of the up-to-81 child object slots is active, it invokes the paired child's virtual method (vtable slot +4) with fixed arguments and then disarms that deadline by resetting it to FLT_MAX. Part of a UI/child-element update path (called from the parent's update routine).

**Called by:** sub_4EF5B0 (004ef5b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x100)+0x0) | 0x4 | R | — | Child object at this+0x100 (paired with deadline 0x1A0): vtable slot +4 is invoked as the notification/state-change method |
| *(*(this+0x104)+0x0) | 0x4 | R | — | Child object at this+0x104 (deadline 0x19C): vtable slot +4 invoked on timeout |
| *(*(this+0x108)+0x0) | 0x4 | R | — | Child object at this+0x108 (deadline 0x1A4): vtable slot +4 invoked on timeout |
| *(*(this+0x10C)+0x0) | 0x4 | R | — | Child object at this+0x10C (deadline 0x1A8): vtable slot +4 invoked on timeout |
| *(*(this+0x5C)+0x0) | 0x4 | R | — | Child object at this+0x5C (deadline 0x180): vtable slot +4 invoked on timeout |
| *(*(this+0x60)+0x0) | 0x4 | R | — | Child object at this+0x60 (deadline 0x184): vtable slot +4 invoked on timeout |
| *(*(this+0x64)+0x0) | 0x4 | R | — | Child object at this+0x64 (deadline 0x188): vtable slot +4 invoked on timeout |
| *(*(this+0x68)+0x0) | 0x4 | R | — | Child object at this+0x68 (deadline 0x18C): vtable slot +4 invoked on timeout |
| *(*(this+0x6C)+0x0) | 0x4 | R | — | Child object at this+0x6C (deadline 0x190): vtable slot +4 invoked on timeout |
| *(*(this+0x70)+0x0) | 0x4 | R | — | Child object at this+0x70 (deadline 0x194): vtable slot +4 invoked on timeout |
| *(*(this+0xFC)+0x0) | 0x4 | R | — | Child object at this+0xFC (deadline 0x198): vtable slot +4 invoked on timeout |
| *(this+0x100) | 0x0 | R | — | Child object pointer paired with deadline 0x1A0 (also scanned as a slot in the 81-entry child scan) |
| *(this+0x104) | 0x0 | R | — | Child object pointer paired with deadline 0x19C |
| *(this+0x108) | 0x0 | R | — | Child object pointer paired with deadline 0x1A4 |
| *(this+0x10C) | 0x0 | R | — | Child object pointer paired with deadline 0x1A8 |
| *(this+0x5C) | 0x0 | R | — | Child object pointer paired with deadline 0x180 |
| *(this+0x60) | 0x0 | R | — | Child object pointer paired with deadline 0x184 |
| *(this+0x64) | 0x0 | R | — | Child object pointer paired with deadline 0x188 |
| *(this+0x68) | 0x0 | R | — | Child object pointer paired with deadline 0x18C |
| *(this+0x6C) | 0x0 | R | — | Child object pointer paired with deadline 0x190 |
| *(this+0x70) | 0x0 | R | — | Child object pointer paired with deadline 0x194 |
| *(this+0xFC) | 0x0 | R | — | Child object pointer paired with deadline 0x198 |
| this | 0x5C | R | — | Child object pointer (deadline 0x180); nonzero slots are probed with virtual slot +28 |
| this | 0x60 | R | — | Child object pointer (deadline 0x184) |
| this | 0x64 | R | — | Child object pointer (deadline 0x188) |
| this | 0x68 | R | — | Child object pointer (deadline 0x18C) |
| this | 0x6C | R | — | Child object pointer (deadline 0x190) |
| this | 0x70 | R | — | Child object pointer (deadline 0x194) |
| this | 0xFC | R | — | Child object pointer (deadline 0x198) |
| this | 0x100 | R | — | Child object pointer (deadline 0x1A0) |
| this | 0x104 | R | — | Child object pointer (deadline 0x19C) |
| this | 0x108 | R | — | Child object pointer (deadline 0x1A4) |
| this | 0x10C | R | — | Child object pointer (deadline 0x1A8) |
| this | 0x180 | RW | — | Timeout deadline paired with child slot 0x5C; FLT_MAX (disarmed) after firing |
| this | 0x184 | RW | — | Timeout deadline paired with child slot 0x60 |
| this | 0x188 | RW | — | Timeout deadline paired with child slot 0x64 |
| this | 0x18C | RW | — | Timeout deadline paired with child slot 0x68 |
| this | 0x190 | RW | — | Timeout deadline paired with child slot 0x6C |
| this | 0x194 | RW | — | Timeout deadline paired with child slot 0x70 |
| this | 0x198 | RW | — | Timeout deadline paired with child slot 0xFC |
| this | 0x19C | RW | — | Timeout deadline paired with child slot 0x104 |
| this | 0x1A0 | RW | — | Timeout deadline paired with child slot 0x100 |
| this | 0x1A4 | RW | — | Timeout deadline paired with child slot 0x108 |
| this | 0x1A8 | RW | — | Timeout deadline paired with child slot 0x10C; checked first, and its value gates the other ten checks |

**Written-by note (persistence):**
- this 0x180: disarmed (set to FLT_MAX) only on the frame its armed deadline elapses; an external poke survives until dbl_FB1D18 passes it, then it is rewritten.
- this 0x184: same conditional disarm-on-expiry; read and compared on every call.
- this 0x188: same conditional disarm-on-expiry; read and compared on every call.
- this 0x18C: same conditional disarm-on-expiry; read and compared on every call.
- this 0x190: same conditional disarm-on-expiry; read and compared on every call.
- this 0x194: same conditional disarm-on-expiry; read and compared on every call.
- this 0x198: same conditional disarm-on-expiry; read and compared on every call.
- this 0x19C: same conditional disarm-on-expiry; read and compared on every call.
- this 0x1A0: same conditional disarm-on-expiry; read and compared on every call.
- this 0x1A4: same conditional disarm-on-expiry; read and compared on every call.
- this 0x1A8: same conditional disarm-on-expiry; additionally tested (== FLT_MAX) by all later deadline checks, so it is processed first each call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00731ce8 | String2 | R | Global string constant referenced by this routine; its use is not visible in the decompiled body |
| 00b6f118 | byte_B6F118 | R | Global suppression flag: when nonzero, no timeout notification is issued |
| 00b70a44 | flt_B70A44 | R | Global scalar (must be nonzero to fire) forwarded as an argument to the child's virtual method — likely a fade/rate factor |
| 00b72314 | dword_B72314 | R | Pointer to a global state/mode variable; notification is blocked while it equals 7 or 8 |
| 00fb1d18 | dbl_FB1D18 | R | Current time (double) compared against each deadline to decide expiry |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x180 | != | 2139095039 | Deadline armed check (2139095039 = FLT_MAX = disarmed) |
| this | 0x184 | != | 2139095039 | Deadline armed check (FLT_MAX = disarmed) |
| this | 0x188 | != | 2139095039 | Deadline armed check (FLT_MAX = disarmed) |
| this | 0x18C | != | 2139095039 | Deadline armed check (FLT_MAX = disarmed) |
| this | 0x190 | != | 2139095039 | Deadline armed check (FLT_MAX = disarmed) |
| this | 0x194 | != | 2139095039 | Deadline armed check (FLT_MAX = disarmed) |
| this | 0x198 | != | 2139095039 | Deadline armed check (FLT_MAX = disarmed) |
| this | 0x19C | != | 2139095039 | Deadline armed check (FLT_MAX = disarmed) |
| this | 0x1A0 | != | 2139095039 | Deadline armed check (FLT_MAX = disarmed) |
| this | 0x1A4 | != | 2139095039 | Deadline armed check (FLT_MAX = disarmed) |
| this | 0x1A8 | != | 2139095039 | Deadline armed check; processed first in the sequence |
| this | 0x1A8 | == | 2139095039 | Extra gate reused by the ten later checks: they run only while this deadline is disarmed |

**Guard interpretation:** A timeout fires only when its deadline field is not FLT_MAX (armed) AND dbl_FB1D18 (current time) is greater than it. Even then the child notification runs only if byte_B6F118 is zero (not suppressed), flt_B70A44 is nonzero, the global mode at *dword_B72314 is neither 7 nor 8, and — for the ten checks after the first — this+0x1A8 equals FLT_MAX. The notification is additionally skipped when the 81-slot child scan finds any nonzero slot whose virtual slot +28 does not return 2. On expiry the deadline is then rewritten to FLT_MAX (disarmed). Anything failing these gates is left untouched.
