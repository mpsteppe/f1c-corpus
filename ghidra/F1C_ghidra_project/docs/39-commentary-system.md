# Commentary System — Full Decode

FACT-tier documentation of F1C commentary (race engineer / PWS) system.
Every address, offset, and data flow verified against live-game reads, IDA
decompilation, and SDT file analysis. Date: 2026-07-21.

---

## 1. Architecture Overview

```
Game State Change (damage, overtake, off-track, pit, phase change, etc.)
  │
  ▼
42 event-generator functions (FUN_00419120 through FUN_00420490)
  │  Each reads vehicle/race state and decides what event to fire
  │  Calls FUN_004144f0 to build a 32-byte event struct
  │
  ▼
FUN_00418560 — Insert into priority queue
  │  Gate check via FUN_00418B90 (threshold by RaceActiveFlag)
  │  Sorts by priority, enforces cooldown
  │  Queue: 20 slots × 32 bytes at controller+0x864
  │
  ▼
FUN_004186F0 — Tick processor (runs every frame from RenderTickUpdate)
  │  Compacts queue, checks timing/cooldown gates
  │  Calls FUN_00411840 to build audio path from event ID
  │  Calls AudioPlayer->play() via vtable
  │
  ▼
FUN_00411840 — Path builder
  │  FUN_004119D0: event_id → channel (0=PWS, 1=TV)
  │  FUN_00411A00: event_table[event_id].score → PWS/TV lookup table → SDT index
  │  FUN_00411E90: dispatches to Miles Sound System
  │
  ▼
Miles Sound System (Mss32.dll)
  │  AIL_set_sample_file() loads from .SDT container
  │  PC_RE_MAIN.SDT (316 clips), PC_RE_STITCH.SDT (494 clips)
  │  TV: PC_TV_MAIN.SDT, PC_TV_STITCH.SDT
```

---

## 2. Commentary Controller Struct

Global at `0x005EA618`. All offsets relative to this base.

| Offset | Size | Field | Notes |
|--------|------|-------|-------|
| +0x864 | 20×32 bytes | Queue | Priority queue, 20 slots of 32-byte event structs. Head at +0x864. Sentinels at `[0] == -1` for empty. Slot field at +0x08 is spawn_time (checked as deadline by tick). |
| +0xAF8 | float[~300] | PerEventLastPlayTime | `controller + 0xAF8 + event_id*4`. Timestamp when event last played. Used for cooldown. |
| +0xAE4 | byte | IsPlaying | 1=audio currently playing, 0=idle. |
| +0xAE8 | float | PlaybackTimestamp | Game time when last playback started. |
| +0xAEC | int32 | CurrentEventID | Event ID currently playing, or -1 (none). Set by tick processor AFTER play. |
| +0xAF0 | byte | CommentaryEnabled | User setting from Options > Audio > Commentary Detail. |
| +0xAF4 | ptr | AudioPlayerPtr | Heap object. Vtable: +4=play(), +8=isPlaying(), +0x18=update(). |
| +0x135C | int32 | StarterTiming | Countdown gate. Decrements each tick until exhausted. |

---

## 3. Event Table

Base address: `DAT_005bf9a0` (.rdata, read-only). Stride: 0x14 (20 bytes) per entry.
~295 active events (IDs 0x01–0x122 for PWS, 0x125–0x217 for TV).

| Offset | Type | Field |
|--------|------|-------|
| +0x00 | int32 | Priority — used by gate check (FUN_00418B90) |
| +0x04 | float32 | DefaultDelay — seconds delay before play |
| +0x08 | float32 | Field3 — purpose unknown |
| +0x0C | float32 | Cooldown — minimum seconds between plays (FUN_004186F0 check) |
| +0x10 | int32 | Score — key into PWS/TV lookup tables |

### Gate Check (FUN_00418B90)

```c
// At 0x00418B90. Compares event priority against RaceActiveFlag-based threshold.
switch (RaceActiveFlag) {
    case 0: return 0x7ffffffe < priority;  // menu/loading — nearly always blocked
    case 1: return 0x45 < priority;         // pre-race (only priority > 69 passes)
    case 2: return 0x27 < priority;         // formation lap (priority > 39)
    case 3: return 0 < priority;            // on-track (any positive priority)
}
```

### Cooldown Check (in FUN_004186F0)

```c
// At 0x004186F0, IDA-verified
if (dbl_8AFEA8 - last_play_time[event_id] >= event_table[event_id].cooldown) {
    // play event
}
```

Events with `cooldown = FLT_MAX (~3.4e38)` are **permanently blocked from queue playback**.
These events exist in the table for game-systems reference but audio plays through a
different path (likely direct Miles calls from trigger functions or STITCH assembly).

**Blocked events (26 total):** 0x50–0x5D (MECHPROB), 0x6A–0x71 (HIT/RETIRE/STALLED),
0x75–0x77 (PENALTY), 0x95 (DQ).

---

## 4. Event → SDT Clip Mapping Chain

```
event_id
  │
  ▼ read event_table[event_id].score (int32 at +0x10 of event table entry)
  │
  ├─ score == 0x2693 or 0x2694: NO AUDIO (display/message events)
  ├─ score == -1 (0xFFFFFFFF): NO AUDIO (setup events)
  │
  ├─ Channel 0 (PWS, events 0x01–0x122):
  │     sdt_index = DAT_005BEBB0[score]  // uint16 lookup table
  │     Clip from: Audio/Commentary/Pws/PC_RE_MAIN.SDT
  │
  └─ Channel 1 (TV, events 0x125–0x217):
        sdt_index = DAT_005BF2F8[score]  // uint16 lookup table
        Clip from: Audio/Commentary/Tv/PC_TV_MAIN.SDT
```

The PWS/TV lookup tables are **not identity-mapped** — they have gaps and shifts:
- PWS: `lookup[i] = i+1` for i ≥ 32 (with additional gaps at higher indices)
- TV: various gaps above index 100

Channel classifier (FUN_004119D0):
```c
if (0 < event_id && event_id < 0x123)      return 0;  // PWS
if (0x124 < event_id && event_id < 0x218)  return 1;  // TV
return -1;  // invalid
```

---

## 5. SDT File Format

Miles Sound System container. Simple structure:

```
Header:
  [0x00]  uint32  count (number of clips, e.g., 316)
  [0x04]  uint32[count]  offset table (byte offsets into file)

Per clip (at each offset):
  [0x00]  uint32  header_size (typically 40 bytes)
  [0x04]  uint32  audio_data_size (bytes after header)
  [0x08]  char[]  null-terminated identifier string (e.g. "PWS_QUAL32.mp2")
  [hdr_sz]         raw MPEG Layer 2 (.mp2) audio data
```

Files:
| File | Clips | Size | Contents |
|------|-------|------|----------|
| `Audio/Commentary/Pws/PC_RE_MAIN.SDT` | 316 | 4.1 MB | Full RE/PWS lines |
| `Audio/Commentary/Pws/PC_RE_STITCH.SDT` | 494 | 3.3 MB | Stitch fragments |
| `Audio/Commentary/Tv/PC_TV_MAIN.SDT` | TV clips | 10.4 MB | TV commentary |
| `Audio/Commentary/Tv/PC_TV_STITCH.SDT` | TV clips | 4.0 MB | TV stitch fragments |

---

## 6. Trigger Functions

All 32+ functions call `FUN_004144F0(event_id, ...)` then `FUN_00418560(event_struct)`.

| Address | Name | Events Fired | Trigger Condition |
|---------|------|-------------|-------------------|
| 0x00419120 | AI Driver State Transition | 0x78, 0x103, 0xC6 | Position change (player 1st, AI overtake) |
| 0x004193A0 | AI Session Mode Transition | 0x85–0x8A, 0x89 | AI mode changes |
| 0x00419500 | AI Corner Speed Comparison | 0x0D–0x14 | Corner speed vs baseline |
| 0x00419690 | AI Overtake/Defend State | 0x21, 0x106 | Overtake/defend detected |
| 0x004198B0 | AI Position Change Event | 0x07–0x09, 0x11–0x12 | Position swap detected |
| 0x004199E0 | AI Retirement/Vehicle Failure | 0x29, 0x01–0x02, 0x110–0x111 | AI retires, final lap |
| 0x0041A0C0 | AI Out-of-Track Event | 0x108 | Vehicle off track surface |
| 0x0041A170 | AI Vehicle Damage Event | 0x34, 0xC4 | Vehicle damage state |
| 0x0041A200 | AI Pit Strategy State | 0x2A, 0x34 | Pit strategy change |
| 0x0041A2B0 | AI Session Phase Change | 0x15–0x16, 0xB2–0xB3 | Phase change detected |
| 0x0041A3A0 | AI Formation Lap / Race Start | 0xB4–0xB6 | Formation lap phases |
| 0x0041A4A0 | Display Message 0x11C | 0x11C | Display-only message |
| 0x0041A500 | Time-based Message Chain | 0x22–0x23, 0x110–0x117 | Session timer thresholds |
| 0x0041A6B0 | (unanalyzed) | unknown | unknown |
| 0x0041A8C0 | AI Session Event Audio | 0x37 | Session event trigger |
| 0x0041AA10 | AI Session Phase Counter | 0x5F–0x69 | Phase counter tick |
| 0x0041AB30 | Pit State Slot Activation | 0x5E–0x68 | Pit slot state changes |
| 0x0041AC50 | Race Event Sound Dispatch | 0xD0–0xDC | Race events by gear |
| 0x0041AD80 | Overtake / Position Swap | 0x72–0x73, 0xE1–0xE2 | Overtake detected (with cooldown + random) |
| 0x0041AFD0 | Session Event Commentary (Per Car) | 0x6A–0x6F, 0xDD–0xDF | Player/AI retirement by reason code |
| 0x0041B190 | Session End Commentary | 0x4D | Session end detected |
| 0x0041B200 | Display Message 0x4A | 0x4A | Damage/state message |
| 0x0041B250 | Session State / Penalty | 0x75–0x77, 0xEB–0xEE | Penalty by ReasonCode |
| 0x0041B3C0 | Pit Selection State Machine | 0x7E, 0x83, 0x85–0x8A | Pit strategy computed |
| 0x0041BE60 | (unanalyzed) | unknown | unknown |
| 0x0041C090 | (unanalyzed) | unknown | unknown |
| 0x0041C0F0 | Pit Exit / Release Order | 0x204–0x217 | Pit exit track position |
| 0x0041C3E0 | (unanalyzed) | unknown | unknown |
| 0x0041C440 | Championship Mode Commentary | dynamic | Championship context |
| 0x0041C4C0 | Position-based Message | dynamic | Driver position/score |
| 0x0041E320 | (unanalyzed) | unknown | unknown |
| 0x00420490 | (unanalyzed) | unknown | unknown |

---

## 7. Event Tick Processor (FUN_004186F0) — Gate Flow

Called from `RenderTickUpdate`. Full gate chain in order:

```
1. Guard: RaceActiveFlag == 0 → return
2. Guard: TrackConditionState <= 0 → return
3. Guard: CommentaryEnabled == 0 → return
4. Call AudioPlayer->update() (vtable+0x18)
5. If isPlaying()==0 AND IsPlaying flag==1 → reset state (IsPlaying=0, CurrentEventID=-1)
6. Compact queue (FUN_00418AC0) — remove expired slots
7. Guard: Queue head == -1 → check if busy, return
8. Guard: AudioPlayer->isPlaying() → return (busy)
9. Timing gate: if enough time since last play → proceed
   else if StarterTiming <= 0 → return (exhausted)
   else decrement StarterTiming and proceed
10. Guard: now < queue_head_spawn_time (at +0x86C, read as float) → block (injected events set to 0, bypasses)
11. Cooldown check: now - last_play_time >= cooldown → proceed
12. Build audio path (FUN_00411840) from queue head event_id
13. AudioPlayer->play(path, count, 0) via vtable+4
14. Set IsPlaying=1, CurrentEventID=event_id, last_play_time=now
15. Reset queue head (FUN_004144D0) → set to -1 sentinel
16. Compact queue again
```

---

## 8. Injection Method

To trigger a commentary event externally, write to 4 memory locations:

| Write | Address | Value | Purpose |
|-------|---------|-------|---------|
| 32-byte event struct | `0x005EA618 + 0x864` (8× int32) | `[event_id, table_score, 0, -1.0f, -1, -1, -1, table_priority]` | Queue head |
| Per-event timestamp | `0x005EA618 + 0xAF8 + event_id*4` | `0.0f` | Bypass cooldown |
| PlaybackTimestamp | `0x005EA618 + 0xAE8` | `0.0f` | Bypass timing gate |
| StarterTiming | `0x005EA618 + 0x135C` | `1` | Bypass counter exhaustion |

The game picks up the event on the next frame (~16ms). All gates pass because:
- `now - 0.0 >= cooldown` → TRUE for cooldown ≤ now
- `ref_time < now - 0.0` → TRUE for now > ref_time
- `StarterTiming > 0` → bypasses counter exhaustion
- `queue_head.deadline = -1.0` → bypasses compaction
- `queue_head[2] = 0` → `now < 0` is FALSE → session deadline doesn't block

**Implementation:** `tools/commentary_inject.py` — shared module used by both GUI and hotkey player.

---

## 9. Tools

| Tool | Purpose |
|------|---------|
| `tools/commentary_binder.py` | Tkinter GUI: bind events to NUMPAD keys, SDT browser with audio preview (ffplay), built-in hotkey listener, "Test in Game" injection |
| `tools/play_commentary.py` | Standalone NUMPAD hotkey player (reads `event_bindings.json`) |
| `tools/commentary_inject.py` | Shared injection module: `inject_event(eid)` → writes to game memory |
| `tools/sdt_tool.py` | SDT file parser: list/dump/dumpall clips from .SDT containers |
| `tools/event_catalog.py` | 470 real event→clip mappings (from IDA event table × SDT lookup × SDT files) |
| `event_bindings.json` | Saved NUMPAD key binding config |
| `event_clip_map.json` | Full event_id → SDT clip name mapping (generated from IDA) |

`play_commentary.py` overloads the commentary queue when the hotkey is pressed in-game.

---

## 10. Event ID → Clip Mapping

Full mapping in `event_clip_map.json` (470 working events). Generated by:
1. IDA `py_exec_file` → reads `DAT_005bf9a0` event table entries
2. Resolves `score → PWS/TV lookup table → SDT index`
3. Cross-references SDT index with parsed `PC_RE_MAIN.SDT` clip names

Open console log available at `work/full_event_sdt_map.txt`.

---

## 11. Key Addresses

| Address | Symbol | Description |
|---------|--------|-------------|
| `0x005EA618` | Controller | Commentary controller object |
| `0x005EA618 + 0x864` | Queue | Priority queue head (20 slots × 32 bytes) |
| `0x005EA618 + 0xAF8` | Timestamp array | Per-event last-play timestamps (float32) |
| `0x005EA618 + 0xAE8` | PlaybackTimestamp | Global timing gate (float32) |
| `0x005EA618 + 0x135C` | StarterTiming | Countdown gate (int32) |
| `0x005EA618 + 0xAE4` | IsPlaying | Playback status (byte) |
| `0x005EA618 + 0xAEC` | CurrentEventID | Active event (int32, -1=none) |
| `0x005EA618 + 0xAF0` | CommentaryEnabled | User toggle (byte) |
| `0x005BF9A0` | Event table | Event metadata (stride 0x14, 295+ entries) |
| `0x005BEBB0` | PWS lookup | Score→SDT index mapping (uint16 array) |
| `0x005BF2F8` | TV lookup | Score→SDT index mapping (uint16 array) |
| `0x004186F0` | FUN_004186F0 | Tick processor |
| `0x00418560` | FUN_00418560 | Queue insertion |
| `0x004144F0` | FUN_004144F0 | Event struct builder |
| `0x00418B90` | FUN_00418B90 | Gate/threshold check |
| `0x00411840` | FUN_00411840 | Audio path builder |
| `0x004119D0` | FUN_004119D0 | Channel classifier (PWS/TV) |
| `0x007D0308` | RaceActiveFlag | Must be ≠0 for commentary |
| `0x007C56A4` | SessionType | 7=race, 5=qual, 1=practice |
