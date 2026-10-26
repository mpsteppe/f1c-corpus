# TASK — Dump & decode the commentary event table (race-engineer PWS quotes)

**Created:** 2026-07-17 · **Scheduled:** 2026-07-18
**Goal:** Extract the event→clip map so we know which PWS (race-engineer) audio line plays
for each race situation (e.g. collision → "you hit someone" yell).

---

## What we already know (verified this session)

### Audio banks (race engineer = PWS channel)
Location: `%USERPROFILE%\Desktop\F1 Challenge V10\Audio\Commentary\Pws\`
- `PC_RE_MAIN.SDT`   = **316** full engineer lines   (PC = Player Car, RE = Race Engineer)
- `PC_RE_STITCH.SDT` = **494** stitch fragments (numbers/gaps/positions/names, spliced into dynamic phrases)
- Per-driver name samples: `Audio\Commentary\pws<Driver>_FB/FE/SB/SE.wav`

**SDT container format (verified — monotonic offsets, first offset == header end, last < filesize):**
```
uint32  count
uint32  offset[count]     // byte offset of each clip blob
...audio blobs...
```
Parse snippet that confirmed counts:
```python
import struct
d=open(path,'rb').read(); n=struct.unpack_from('<I',d,0)[0]
offs=[struct.unpack_from('<I',d,4+4*i)[0] for i in range(n)]   # first==4+4*n
```

### The trigger pipeline (code — fully decompiled)
```
race event → trigger fn → FUN_004144f0(msgID, carA, carB, …) → commentary request
           → msgID indexes event table DAT_005bf9a0 (stride 0x14) → queued → PWS clip plays
```

`FUN_004144f0` @ `0x004144f0` (the dispatcher / Rosetta stone):
```c
param_1[7] = *(int   *)(&DAT_005bf9a0 + msgID*0x14);   // per-event binding (priority / clip?)
param_8    = *(float *)(&DAT_005bf9a4 + msgID*0x14);   // per-event timing / duration
```
- `msgID` = first arg = the selector. `carA`/`carB` = subject vehicle pointer(s).
- Entry size = **0x14 (20 bytes) = 5 dwords** per msgID: fields at +0x00,+0x04,+0x08,+0x0c,+0x10.
- `FUN_004144d0` = no-argument variant (default/continuation).

### Decoded trigger examples
`FUN_004199e0` (per-frame player commentary; caller `FUN_004BC4E0`;
gated by `RaceActiveFlag DAT_007d0308 != 0` AND `RacePhase DAT_007c56a8 != 8`/not-finished):
| msgID | condition | meaning |
|------:|-----------|---------|
| `1`   | car ahead, two-car refs (`+0x489c` name, `+0x4060`), gap via `FUN_0049b6d0` | battle — car in front |
| `2`   | car behind, `+0x4064 != 2` | battle — car catching you |
| `0x29`| player rival | rival/position info |
| `0x110`,`0x111` | race status | race-state lines |

Other msgIDs seen across the ~43 trigger fns in `0x00418000–0x0041E000`:
`0xd, 0xe, 0x13, 0x14, 0x37, 0x108, 0x113, 0x11c`.
`0x11c`/`0x113` = practice/qualifying session announcements (docs/06). It's a **unified
announcement-ID space** shared by HUD text + TV commentator + PWS engineer audio.

### Supporting code
- `FUN_004117b0` — channel config: `param_1==0` → TV paths, `==1` → PWS paths
- `FUN_00414600` (`%spws%s_`) / `FUN_00414a90` — filename builders (pws vs tv, stitch driver name)
- `FUN_004216f0` — base path `Audio\Commentary\`
- `FUN_0040d4c0` — scripted **intro** dispatcher (GREETING/GRIDWALK/FLY_OVER/WEATHER/
  TRACK_INFO/WELCOME_TO_COUNTRY/CROWD/CAMERA_*/COMMENTARY_START|STOP) — separate from runtime engineer lines

---

## Tomorrow's steps

1. **Dump `DAT_005bf9a0` table from the exe.**
   - Exe: `%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe` (IDA DB alongside).
   - VA `0x005bf9a0` → file offset via PE section headers (or IDA `get_bytes`).
   - Read N entries × 0x14 bytes. N ≥ 0x11d (highest msgID seen is 0x11c) — find real end
     (table likely bounded by next symbol / zero run).
   - Decode the 5 dwords per entry. Identify which field is the **PC_RE clip index**
     (cross-check: entry for a known msgID should point at a plausible clip 0–315).

2. **Find the collision/incident trigger msgID.**
   - Trace the damage/contact handler (physics side) to its `FUN_004144f0(msgID,…)` call.
   - My earlier two-car guess (msgID 1/2) was WRONG — those are battle/relative-position, not contact.

3. **(Optional) Extract the 316 `PC_RE_MAIN` clips to WAV** using the SDT offset table,
   listen, label by ear, back-map clip index → msgID → event.

**Deliverable:** a msgID → {event trigger, condition, PC_RE clip index, meaning} table.
Write it to a new `docs/` file (e.g. `docs/21` audio section or a new commentary-events doc).

## Note
`tools/investigate.py` handles code lookups but does NOT dump data tables. If this becomes
recurring, consider adding a `--data <VA> <stride> <count>` mode that resolves VA→file-offset
and prints decoded rows.
