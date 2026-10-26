## sub_4DA5E0_004da5e0 — LoadAndPlayReplay

**Summary:** Loads a replay (VCR) file and initiates playback. Shows "Loading Replay" status, reads replay data from file, sets up replay state and timing, and transitions to replay mode if conditions are met.

**Called by:** sub_42FE80 (0042fe80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x820 | RW | — | Replay timing/position float at offset 2080 — set from computed value |
| *(this+0x8) | 0x87C | R | — | Replay file path string at offset 2172 |
| this | 0x0 | RW | 0 | Replay state — 2 = in replay mode, 0 = not replaying |
| this | 0x8 | R | — | Pointer to replay context object (this+2 = a1+8) |

**Written-by note (persistence):**
- *(this+0x8) 0x820: written once during replay load; would survive until next replay load
- this 0x0: conditional — set to 2 when replay active, 0 when failed/no replay; would survive until state change

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00601808 | aLoadingReplay | R | "Loading Replay" — status message string |
| 0060fe88 | aDDevNascar2004_15 | R | Source file path for error context |
| 00610080 | aLoadingVcrFile | R | "Loading VCR File for playback" — status message |
| 00629120 | byte_629120 | R | Empty string fallback |
| 00629124 | dword_629124 | R | Unknown state flag passed to sub_405BF0 |
| 0062a170 | dword_62A170 | R | String table handle for status text lookup |
| 0062a17c | Destination | R | Status text buffer — set to "Loading Replay" |
| 0062a37b | byte_62A37B | W | Status text null terminator |
| 0062bf64 | unk_62BF64 | R | Unknown reference data |
| 0076612c | unk_76612C | R | Unknown config/state |
| 007684e0 | dword_7684E0 | R | Replay available flag #1 — non-zero enables replay transition |
| 00768504 | dword_768504 | R | Replay available flag #2 — non-zero enables replay transition |
| 007689cc | dword_7689CC | R | Current game mode — if != 6, replay mode can be entered |
| 007d7920 | dword_7D7920 | R | Error display context |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00405bf0 | sub_405BF0 | Check completion/end state of current session |
| 0041f230 | BinarySearchInStringTable [structural] | Look up "Loading Replay" in string table for localization |
| 0042db60 | sub_42DB60 | Set up replay timing context |
| 0042dc00 | sub_42DC00 | Initialize replay playback state |
| 004ba730 | sub_4BA730 | Display status/loading message with duration |
| 004d82e0 | sub_4D82E0 | Apply replay timing value to replay system |
| 004d8430 | sub_4D8430 | Compute replay timing value into float |
| 004d97e0 | sub_4D97E0 | Parse/load replay data from file |
| 004d9810 | sub_4D9810 | Prepare replay context for loading |
| 004d9820 | sub_4D9820 | Activate/start replay playback |
| 004d9830 | sub_4D9830 | Get replay context handle |
| 004d9840 | sub_4D9840 | Get replay file name from context |
| 004d9ef0 | sub_4D9EF0 | Set replay state/flag (parameter 5) |
| 00500f90 | sub_500F90 | Show status/error dialog |
| 00500fe0 | sub_500FE0 | Display "Loading VCR File for playback" message |
| 0057a080 | ZeroInitSmallStruct [exact] | Zero-initialize file handle struct |
| 0057a0a0 | sub_57A0A0 | Cleanup file handle struct |
| 0057a110 | sub_57A110 | Open replay file for reading |
| 0057a2f0 | AudioStreamOpen [structural] | Open replay data stream |
| 0057a360 | ConditionalFileHandleCloseWithFlagDispatch [structural] | Close replay file handle |
| 0057a3a0 | sub_57A3A0 | Process/buffer replay data chunk |
| 0057a3d0 | sub_57A3D0 | Read next chunk from replay stream |
| 0057af60 | sub_57AF60 | Set/configure replay file |
| 005be8ae | sub_5BE8AE | Free filename buffer memory |
| 005be8e3 | ??2@YAPAXI@Z | operator new — allocate filename buffer (128 bytes) |
| 005beab0 | _strncpy | Copy "Loading Replay" text to status buffer |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 2 | Already in replay mode — proceed with replay loading (PASSES); != 2 → check replay transition conditions |

**Guard interpretation:** 
- *a1 == 2 (already replaying) → load and process replay file
  - sub_57A2F0 (open replay stream) fails → BLOCKED, set *a1=0, cleanup and return 0
  - sub_57A110 (open file) fails → skip to cleanup, set *a1=0
  - sub_4D97E0 (parse replay) fails → BLOCKED, set *a1=0, cleanup
- *a1 != 2 → check if should enter replay mode:
  - dword_7689CC == 6 → BLOCKED (can't replay)
  - sub_405BF0 returns non-zero → BLOCKED (session still active)
  - dword_7684E0 == 0 AND dword_768504 == 0 → BLOCKED (no replay available)
  - All conditions pass → return non-zero (enter replay mode)

**String literals referenced (deterministic):**

- `Loading Replay`
- `Loading Replay`
- `D:\dev\NASCAR_2004\Source\Replay.cpp`
- `Loading VCR File for playback`
