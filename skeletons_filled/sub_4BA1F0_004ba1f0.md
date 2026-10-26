## sub_4BA1F0_004ba1f0 — Replay File Load State Machine

**Summary:** Implements a state machine for loading replay/vcr files. State 2: opens a replay file via AudioStreamOpen, reads it in 1024-byte chunks using FileWriteWithBackendDispatch/ConditionalDispatch_6bd0, processes via ThunkToFUN004b7300, then sets up player vehicle and menu action. State transitions: on failure sets *this=0; on success keeps *this=2; else sets *this based on ConditionalFlagReturn and session flags (dword_7D0038, dword_7D005C).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0xF3C | RW | — | loaded replay data field at offset 0xF3C within player vehicle struct (written after QueuePeek) |
| this | 0x0 | RW | 0 | state machine state (2=loading replay, 0=done/fail, other=session gate) |
| this | 0x8 | R | — | pointer to player vehicle struct |
| this | 0xF9C | R | — | vehicle struct field at offset 0xF9C (replay-related configuration) |

**Written-by note (persistence):**
- *(this+0x8) 0xF3C: written once during replay load (stores QueuePeek angle result); external poke would NOT survive unless replay reloads
- this 0x0: written every call — state machine drives it; external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0dc | Sleep | R | Win32 Sleep import — used for 250ms delay during replay load |
| 005d24ac | aPreppingReplay | R | PreppingReplayStr [DERIVED] |
| 005d24bc | aLoadingVcrFile | R | LoadingVcrFileString [DERIVED] |
| 005d24dc | aDDevF119992002_22 | R | DDevF119992002String [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea43c | dword_5EA43C | R | SetupDirSuffix [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 005ec6d0 | unk_5EC6D0 | R | session/race configuration data block |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007d0038 | dword_7D0038 | R | ScoringGateFlag [DERIVED] (also: ` — global flag) |
| 007d005c | dword_7D005C | R | SessionCleanupFlag [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f10 | ConditionalFlagReturn | returns a boolean condition based on dword_5EA43C |
| 00423a00 | BinarySearchInStringTable | searches string table for a substring match |
| 0042bbd0 | SetPlayerVehicleIndex | sets the player vehicle index after replay load |
| 0042bc40 | SetPlayerVehicleIndex_bc40 | secondary player vehicle index setter |
| 004a0e70 | SessionTypeGuard | guards against session type transitions |
| 004b86e0 | AngleClampWrap | clamps/wraps angle to valid range |
| 004b87a0 | QueuePeek | peeks at a queue value (angle) from vehicle replay data |
| 004b97d0 | ThunkToFUN004b7300 | processes replay data into vehicle state |
| 004b9810 | SingleCallWrapper_9810 | single-call wrapper for replay initialization |
| 004b9820 | WheelForceAccessor | accesses wheel force data from vehicle |
| 004b9830 | sub_4B9830 | initializes a 128-byte buffer for file path |
| 004b9da0 | MenuActionDispatch | dispatches menu action (action 5 = post-replay) |
| 004d7a50 | StringSplitLoop | string split/parse loop for dev logging |
| 004d7aa0 | DebugLogWrite | writes debug log message |
| 005668b0 | ZeroInitSmallStruct | zero-initializes a small struct (28 bytes) |
| 005668d0 | SubCallWithConditionalFieldFree | conditional field-free sub-call (cleanup) |
| 00566940 | sub_566940 | opens a file for reading (returns success flag) |
| 00566b20 | AudioStreamOpen | opens audio stream (reused for replay file open) |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | conditional file handle close with flag dispatch |
| 00566bd0 | ConditionalDispatch_6bd0 | conditional dispatch after file read chunk |
| 00566c00 | FileWriteWithBackendDispatch | reads from file with backend dispatch (returns bytes read) |
| 00568540 | FileAttributesExistenceCheck | checks if file exists (file attributes check) |
| 00587bcf | FreeWrapper_7bcf | memory free wrapper |
| 00587c03 | OperatorNewNhMallocWrapper | operator new / malloc wrapper (128 bytes) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 2 | state == 2 (loading replay) — PASSES into replay load logic; all other states take else branch |

**Guard interpretation:** The single guard `*this == 2` gates the entire replay load procedure. When state=2: opens file, reads chunks, processes replay, sets player vehicle, dispatches menu action. On failure within state 2, sets *this=0. When state != 2: calls ConditionalFlagReturn and sets *this to session gate flags (dword_7D0038 or dword_7D005C).
