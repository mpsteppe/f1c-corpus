# Chain: Audio File Load & Decode — Miles Sound System Audio Loader

Seed: FUN_00567f40  |  System: docs/21-audio-network-internals.md  |  Depth: 2  |  Functions: 8

---

## Overview

Triggered by audio playback request (engine sound, UI feedback, etc.). Acquires Miles Sound System mutex (FUN_005668b0 — AIL_lock), opens audio file via MSS file I/O (FUN_00566b20), reads file data (FUN_00567e10), decodes audio stream (FUN_00567bb0), closes file (FUN_00566b90), and releases mutex (FUN_005668d0 — AIL_unlock). Returns decode status byte (0 = failure). Pure audio pipeline — no game logic or globals used.

## Call Tree

```
FUN_00567f40 — Audio File Load & Decode  [trigger: audio playback request]
  +-- FUN_005668b0 — MSS Lock  [AIL_lock mutex acquire]
  +-- FUN_00566b20 — MSS File Open  [opens audio file by path (param_1)]
  |     [returns file handle]
  +-- FUN_00567e10 — MSS File Read  [reads audio data from file]
  +-- FUN_00567bb0 — MSS Audio Decode  [decodes audio stream to PCM]
  |     [Miles Sound System decode pipeline]
  +-- FUN_00566b90 — MSS File Close  [closes audio file]
  +-- FUN_005668d0 — MSS Unlock  [AIL_unlock mutex release]
```

## Step-by-Step Trace

### Level 0: FUN_00567f40 — Audio File Load & Decode

**Trigger:** Called when a game subsystem requests audio file playback (engine rev, menu click, etc.).
**Called by:** Audio manager (callers: 2 from callers.json).
**Purpose:** Thread-safe audio file loading and decoding via Miles Sound System.

**Key actions:**
1. Acquires MSS mutex via FUN_005668b0 (AIL_lock)
2. Opens audio file via FUN_00566b20 (param_1 = filename/path)
3. If handle valid: reads data (FUN_00567e10), decodes stream (FUN_00567bb0), closes file (FUN_00566b90)
4. Releases MSS mutex via FUN_005668d0 (AIL_unlock)
5. Returns decode status byte (0 = failure, non-zero = success)

**Data passed to callees:** param_1 (filename/path string), file handle, decoded buffer pointers

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00567f40 | path string | Lock MSS | Mutex acquired |
| FUN_00566b20 | file path | Open file | File handle |
| FUN_00567e10 | file handle | Read data | Raw audio data |
| FUN_00567bb0 | audio data | Decode | PCM audio buffer |
| FUN_00566b90 | file handle | Close file | File closed |
| FUN_005668d0 | mutex | Unlock MSS | Mutex released |

## Globals Written in This Chain

None — operates on MSS handles and audio buffers only.

## Notes

- All callees are Miles Sound System wrappers — no game logic
- Thread-safe via MSS AIL_lock/AIL_unlock mutex
- Pure leaf pipeline: callees have no further sub-calls beyond MSS API (depth 2)
- Return 0 indicates decode failure (corrupt file, unsupported codec, etc.)

---

---
