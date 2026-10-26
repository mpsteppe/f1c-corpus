# Chain: AudioChannelInit — Audio Channel Initialization

Seed: FUN_0045d530  |  System: docs/21-audio-network-internals.md  |  Depth: 2  |  Functions: 7

---

## Overview

Triggered from Short Computation buffer allocation (`FUN_00461c70`). Initializes an audio channel/voice structure with 104 entries of two types. All callees are thin wrappers or leaf functions — maximum depth is 1 level (seed → callee, callee has no further sub-callees).

## Call Tree

```
FUN_0045d530 — AudioChannelInit  [trigger: buffer allocation init]
  +-- FUN_00461550 — PassThroughWrapper  [1 callee → FUN_00461560]
  +-- FUN_00461470 — ThunkToFUN_00461480  [1 callee → FUN_00461480]
  +-- FUN_004ff670 — PassthroughWrapper  [1 callee → FUN_00500170]
  +-- FUN_0045c750 — WrapperWithConstant  [1 callee → FUN_0045c8b0]
  +-- FUN_0045c0a0 — ShortComputation  [leaf — undocumented]
  +-- FUN_0045cd50 — StructInitializerFlagsFields  [leaf]
  +-- FUN_0045e590 — BufferFillWithFFFF  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_0045d530 — AudioChannelInit

**Trigger:** Called from FUN_00461c70 (Short Computation Large Alloc + Init, docs/20)
**Called by:** FUN_00461c70 — Short Computation (Large Alloc + Init)
**Purpose:** Initializes audio channel/voice structure with default parameters.

**Key actions:**
1. Calls FUN_00461550 (channel allocator), FUN_0045c750, FUN_0045c0a0
2. Creates 0x68 (104) entries of two types via FUN_00461470 and FUN_004ff670
3. Initializes rate as 1.0 / _DAT_0059f098 (sample rate conversion factor)
4. Sets default volume DAT_0059f09c, pitch DAT_0059f0a4
5. Sets function pointer table at +0xfef
6. Initializes 8 slots at +0x6ddb-0x6de3
7. Sets channel type at +0xff6 to 8

**Data passed to callees:** Audio channel struct pointer, allocation parameters.

### Level 1: FUN_00461550 — PassThroughWrapper

**Trigger:** Called from audio channel init for channel allocation
**Purpose:** Pass-through wrapper — calls FUN_00461560.

### Level 1: FUN_00461470 — ThunkToFUN_00461480

**Trigger:** Called from audio channel init
**Purpose:** Thunk — immediately jumps to FUN_00461480.

### Level 1: FUN_004ff670 — PassthroughWrapper

**Trigger:** Called from audio channel init
**Purpose:** Passthrough — calls FUN_00500170 (target function).

### Level 1: FUN_0045c750 — WrapperWithConstant

**Trigger:** Called from audio channel init
**Purpose:** Wrapper with constant parameter — calls FUN_0045c8b0.

### Level 1: FUN_0045c0a0 — ShortComputation

**Trigger:** Called from audio channel init
**Purpose:** Short computation — undocumented (no functions.json entry for this addr).

### Level 1: FUN_0045cd50 — StructInitializerFlagsFields

**Trigger:** Called from audio channel init
**Purpose:** Initializes struct flags and fields.

### Level 1: FUN_0045e590 — BufferFillWithFFFF

**Trigger:** Called from audio channel init
**Purpose:** Fills buffer with 0xFFFFFFFF pattern.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0045d530 | Channel struct, globals | Init sequence | Initialized channel |

## Notes

- All callees are thin wrappers or leaf functions — no chain depth beyond level 1
- Total depth: 2 (seed → wrapper → target function)
- All wrappers (FUN_00461550, FUN_00461470, FUN_004ff670, FUN_0045c750) have call_count=1
- FUN_0045c0a0 has no functions.json entry (undocumented)
- Moddability: hardcoded — channel structure layout is baked

---
