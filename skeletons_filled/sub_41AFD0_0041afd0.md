> **UPDATE 2026-07-24 (prose only, fact table untouched) — THIS IS THE PART-LOSS
> COMMENTARY EMITTER.** `a2` is the part index (0-3 wheel, 4 front wing,
> 5 rear wing, 6-13 bodywork), hook-proven live.
>
> | partIdx | player event | AI event | clip |
> |---|---|---|---|
> | 0/1/2/3 wheel | 106/107/109/110 | **221** `0xdd` | PWS_AIHIT07 |
> | 4 front wing | 108 | **222** `0xde` | PWS_AIHIT01 |
> | 5 rear wing | 111 | **223** `0xdf` | PWS_AIHIT02 |
> | 6-13 bodywork | none | none | silent — falls through `default: break`, yet still calls `InsertDriverTableEntry` with a sentinel-only struct |
>
> Player-vs-AI branch is `*(dword_7C54E8+18580) == *(veh+18580)`.
> Note the player wheel ids are NOT sequential — 108 is a wing.
> `0xdc`/220/PWS_AIHIT08 is emitted by NOBODY (zero references across all 7,138
> functions) — reachable only by queue injection; its table entry is normal
> (`pri=40 cooldown=15.0`), it simply has no caller.
> AI lines queue behind player-contact lines (`114`/`115`, `pri=20` vs `40`) and
> may be dropped if the wait times out — observed both playing and dropped.
> Evidence: `investigations/part_detach_commentary/README.md`.

## sub_41AFD0_0041afd0 — RepairServiceEventHandler

**Summary:** Handles repair/service events for AI commentary. Maps event subtype (0-5) to different event codes for player vehicle (106-111) vs AI vehicles (221-223). Triggered from repair service state dispatcher. Part of AI session event pipeline.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** RepairServiceStateDispatcher (004ed250)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4894 | R | — | Driver ID — matched against player vehicle to select player vs AI event codes |
| this | 0x489C | R | — | Driver ID — used as context index for AI vehicle event entries |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0041b154 | jpt_41B028 | R | Jump table for switch on a2 — player vehicle event ID mapping |
| 0041b16c | jpt_41B0D4 | R | Jump table for switch on a2 — AI vehicle event ID mapping |
| 0059e440 | flt_59E440 | R | Zero threshold constant (~0.0f) |
| 005ea618 | flt_5EA618 | R | Pointer to session event table |
| 007c54e8 | dword_7C54E8 | R | Player vehicle pointer — used to check player identity |
| 007c56a8 | dword_7C56A8 | R | Race phase — must not be 8 for AI vehicle path |
| 007cf3c8 | flt_7CF3C8 | R | Track condition state — must be nonzero |
| 007d0308 | dword_7D0308 | R | Race active flag — must be nonzero |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initializes local 8-DWORD struct for new event entry |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Fills local struct with repair event code and computed time |
| 00418560 | InsertDriverTableEntry | Inserts repair event into session event table |

**Guard conditions:** dword_7D0308 (race active) nonzero, flt_7CF3C8 (track condition) != 0.0. Player path: a1 driver ID must match player. AI path: race phase (dword_7C56A8) != 8. For both paths, a2 must be 0-5 to set an event; default (out of range) skips DriverDataTableLookupAndTimeConversion and inserts sentinel-only entry.
