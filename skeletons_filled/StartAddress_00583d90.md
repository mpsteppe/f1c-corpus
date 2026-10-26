## StartAddress_00583d90 — FloatAnimationThreadProc

**Summary:** Thread start routine that runs a float-accumulation loop, polling two state conditions (vtable dispatch at offsets 0x50/0x54), and dispatching accumulated values via vtable entry 0xC when a 0.333 threshold is reached. Part of an animation/interpolation subsystem.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC | R | — | vtable dispatch: callback called with accumulated float when threshold exceeded |
| obj | 0x50 | R | — | vtable dispatch at +80: polling function returning status byte (called up to 3x) |
| obj | 0x54 | R | — | vtable dispatch at +84: polling function returning status byte (called up to 3x) |
| this | 0x0 | R | — | vtable pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d063 | SEH_583D90 | R | SEH handler for this thread function |
| 0059e208 | SleepEx | R | kernel32 SleepEx import for 5ms alertable sleep |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e5fc | flt_59E5FC | R | FrameRateCorrectionFactor [DERIVED] (also: ` — global frame-rate correction) |
| 0059ed98 | dbl_59ED98 | R | Dbl_Physics_TimingThreshold [DERIVED] |
| 005b8b58 | flt_5B8B58 | R | AudioBufferThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | no-op function called when accumulation threshold met |
| 005835f0 | TimerInitWithSEH | initialize a timer object (SEH guarded) |
| 00583650 | SingleFunctionCallWrapper_3650 | cleanup/stop single function call |
| 00583660 | FloatSetWithTimingCall | reset a timer to zero |
| 00583680 | FloatAdditionReturnsFUN00568d90Param1 | read current accumulated float from timer |
| 00583690 | SingleFunctionCallWrapper_3690 | call related to second timer (v21) |
| 00583d40 | MutexProtectedDataReadWithTimedWait | check if termination flag is set (non-zero = exit loop) |
| 00583f50 | sub_583F50 | handle accumulated float value |
| 005840d0 | MutexWaitWith1msTimeoutRelease | acquire mutex for protected section |
| 00584110 | sub_584110 | send float value under mutex protection |

**Guard conditions:** Loop condition: `MutexProtectedDataReadWithTimedWait(lpThreadParameter, 0)` returns 0 — BLOCKED (exits loop) when return is non-zero (termination signaled). Inner guard: timer value < 0.0078125 — if false, skips entire update cycle. Accumulation threshold: v19 >= 0.333 — BLOCKED (accumulates only, no dispatch) when false.
