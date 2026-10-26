## sub_4CDA20_004cda20 — TrackSceneLoader

**Summary:** Loads a track/scene for a race session — verifies file existence, loads audio stream data, initializes AI vehicle count from track config, and sets up the race environment. Returns 0 on success, -1 on file-not-found.

**Called by:** StringCopyFileCheckDispatch [structural] (004cd9c0), sub_4CEA30 (004cea30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x5744)+0x0) | 0x10 | R | — | vtable dispatch (virtual call at offset 0x10 on sub-object) |
| *(this+0x5744) | 0x0 | R | — | pointer to sub-object (track/scene data) |
| this | 0x114 | RW | 1 | file-is-read-only flag (set from file attributes) |
| this | 0x198 | R | — | unknown |
| this | 0x2568 | RW | 1 | flag: some limit/cap enabled |
| this | 0x2570 | R | — | some minimum value |
| this | 0x2574 | R | — | some maximum value |
| this | 0x25EC | R | — | track type / session mode (checked ==5) |
| this | 0x3A14 | R | — | unknown |
| this | 0x3A98 | RW | 41 | clamped value (min 1, max 48, clamped between min and max) |
| this | 0x3AA0 | R | — | clamp minimum bound |
| this | 0x3AA4 | R | — | clamp maximum bound |
| this | 0x5744 | R | — | pointer to sub-object |

**Written-by note (persistence):**
- this 0x114: conditional — set once during load based on file attributes, survives until next load
- this 0x2568: conditional — set once during load, survives until next load
- this 0x3A98: conditional per load — computed and clamped, survives until next track load

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d50d8 | GetFileAttributesA | R | Windows GetFileAttributesA API |
| 005fd340 | NumOfElements | W | active vehicle count — set to computed AI count |
| 00629120 | byte_629120 | R | empty string sentinel |
| 006292d0 | byte_6292D0 | R | unknown (passed to sub_419110) |
| 0062bf64 | unk_62BF64 | R | player state base |
| 0075cba8 | dword_75CBA8 | R | current game state (checked ==1 for skip) |
| 0075e8f0 | dword_75E8F0 | R | AI vehicle list (passed to sub_435C20) |
| 00762f00 | byte_762F00 | R | flag bit 0 — controls sub_4CB410 float argument (1 vs 2) |
| 00764d70 | dword_764D70 | R | unknown |
| 00767898 | flt_767898 | R | float constant (passed to sub_4EFDE0) |
| 007d6a30 | byte_7D6A30 | R | unknown |
| 007d6b78 | byte_7D6B78 | R | unknown |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00419110 | sub_419110 | unknown |
| 0042dba0 | sub_42DBA0 | check if multiplayer mode (adds to AI count) |
| 0042dc40 | BuildActiveVehiclePointerArray [structural] | rebuild active vehicle array |
| 00435c20 | AutoLoadEntryListLoader [structural] | load AI vehicle entries |
| 004634f0 | sub_4634F0 | check session state — if true and game state != 1, skip loading |
| 004bc410 | LinkedListWalker [structural] | walk/process linked list |
| 004cb410 | sub_4CB410 | process track data with float parameter |
| 004cd760 | sub_4CD760 | get track filename/path |
| 004ce0f0 | sub_4CE0F0 | set track/session index |
| 004e58f0 | sub_4E58F0 | load track data |
| 004e8d60 | sub_4E8D60 | process vehicle path |
| 004efde0 | sub_4EFDE0 | initialize something with float |
| 0057a080 | ZeroInitSmallStruct [exact] | zero-initialize small struct |
| 0057a0a0 | sub_57A0A0 | cleanup/teardown struct |
| 0057a2f0 | AudioStreamOpen [structural] | open audio stream from file |
| 0057b040 | sub_57B040 | copy source buffer to destination |
| 0057b340 | sub_57B340 | reset/clear buffer |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x25EC | == | 5 | track type check — if track type == 5, set AI count to 0 |
| this | 0x3A98 | < | 41 | clamp check — if value < 41, force it to 41 (then clamp) |

**Guard interpretation:** When this+0x25EC (track/session type) equals 5, NumOfElements (active vehicles) is set to 0 (no AI opponents). When this+0x3A98 is below 41, it's forced to 41 then clamped between min and max bounds from this+0x3AA0 and this+0x3AA4.
