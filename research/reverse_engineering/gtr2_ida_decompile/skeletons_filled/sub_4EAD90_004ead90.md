## sub_4EAD90_004ead90 — Race-exit post-race monitor setup / teardown

**Summary:** Handles the game-state transition out of the in-race state: when state is 6 (race) and it is changing, it decides between the endurance and normal post-race monitor paths, pushes the "POST RACE MONITOR"/"ENDURANCE POST RACE MONITOR" state, then runs the per-frame teardown of race resources (object list iteration, audio/HUD settling, virtual dispatch resets).

**Called by:** sub_409F60 (00409f60), sub_47B550 (0047b550)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0071361c | aPostRaceMonito | R | "POST RACE MONITOR" state/string pushed via sub_4E1810 when not endurance mode |
| 00713630 | aEndurancePostR | R | "ENDURANCE POST RACE MONITOR" state/string pushed via sub_4E1810 in endurance mode |
| 00757718 | flt_757718 | R | float counter reset via sub_40E040(..., 0.0) — timing/transition timer |
| 00757c10 | dword_757C10 | R | loop bound: number of entries in the race object array at dword_91E088 |
| 00757c1c | dword_757C1C | R | when byte-nonzero, requests a secondary reset (sub_573540, sub_53E6F0(0.0), clears dword_91E084+19428) |
| 00903a10 | dword_903A10 | R | object/state passed to sub_557150 (ResourceDestroy) and sub_55EDA0 — race scene resource being destroyed |
| 0091be2c | dword_91BE2C | R | argument to sub_408A50 — global state/mode value |
| 0091bf20 | dword_91BF20 | R | structure reset by sub_413DC0 and cleared by sub_410C90 |
| 0091bf40 | dword_91BF40 | R | checked together with byte_B722CC/byte_B722FC to decide sub_4124A0() |
| 0091dc48 | byte_91DC48 | R | unknown |
| 0091e048 | byte_91E048 | R | compared to 2 before running the state-8 HUD/entry sequence |
| 0091e050 | byte_91E050 | R | used as v12/v17 argument (index/id) for sub_41DF60 and the item lookup with id 57 |
| 0091e054 | dword_91E054 | R | copied into v18[1] as float argument for sub_41DF60 |
| 0091e080 | dword_91E080 | R | index into object array dword_91E088 used to fetch entry at +22468 |
| 0091e084 | dword_91E084 | R | base pointer of a large manager/state struct (offsets +16, +14820, +19428 accessed) |
| 0091e088 | dword_91E088 | R | base of array of object pointers iterated by dword_757C10 |
| 00b640c0 | dword_B640C0 | R | unknown |
| 00b640c8 | dword_B640C8 | R | holds current game state (compared == 6, in-race) |
| 00b6a328 | dword_B6A328 | R | unknown |
| 00b6cba8 | dword_B6CBA8 | R | argument to sub_475BF0 — state/mode object being set |
| 00b6e090 | dword_B6E090 | R | main scene/game object; its vtable slot +28 is called to look up entries by id (21/22/57/58) |
| 00b6e4d0 | dword_B6E4D0 | R | argument to sub_4E5FC0(..., 0) — some UI/state object reset |
| 00b6f114 | dword_B6F114 | W | zeroed when byte_B6F118 != 1 — companion counter to the guard flag |
| 00b6f118 | byte_B6F118 | RW | one-shot guard: when != 1, set to 1 and dword_B6F114=0 |
| 00b6f121 | byte_B6F121 | W | set to 1 on the non-monitor wait path (with v20=1) |
| 00b6f1c8 | dword_B6F1C8 | R | argument to sub_4EDFE0 — object updated at race exit |
| 00b70030 | dword_B70030 | R | checked on non-paused path: when zero, takes the wait path |
| 00b70900 | byte_B70900 | R | when byte_B722CC==1, compared ==1, on match jumps to the reset path |
| 00b70918 | byte_B70918 | R | alternative flag: with byte_B722CC==0, ==1 also goes to the reset path |
| 00b722cc | byte_B722CC | R | mode flag: ==1 selects first reset branch; 0 falls through to byte_B70918 check |
| 00b722e4 | byte_B722E4 | R | endurance-mode flag: selects item id 22 vs 21 and endurance vs normal monitor string |
| 00b722fc | byte_B722FC | R | OR'ed with byte_B722CC to gate sub_4124A0() |
| 00b72314 | dword_B72314 | R | current race/session sub-state; 6 = race, 5 and 8 checked specially |
| 00b761ec | dword_B761EC | R | scene/object pointer passed to sub_41DF60 and sub_41DC90 |
| 00be1d20 | dword_BE1D20 | R | argument to sub_5403D0 — virtual dispatch target object |
| 00be1d30 | byte_BE1D30 | R | state object passed to sub_540130, sub_5400F0, sub_540150, sub_5400B0 |
| 00fadd40 | dword_FADD40 | R | unknown |
| 00fae988 | dword_FAE988 | R | argument to sub_562430(..., -1, 0) — timer/audio object reset |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00408a50 | sub_408A50 | cleanup/reset with dword_91BE2C |
| 0040e040 | sub_40E040 | set float counter flt_757718 to 0.0 |
| 00410c90 | sub_410C90 | reset dword_91BF20 with 0 |
| 004124a0 | sub_4124A0 | conditional recompute gated by (byte_B722CC || byte_B722FC) && dword_91BF40 |
| 00413dc0 | sub_413DC0 | reset dword_91BF20 |
| 00413e70 | sub_413E70 | no-arg transition/update |
| 00414450 | sub_414450 | update dword_91BF20 with object field from current entry (+22468) |
| 0041dc90 | sub_41DC90 | helper on dword_B761EC |
| 0041df60 | sub_41DF60 | register HUD/race entry (dword_B761EC, id, float, 0) |
| 0041e1e0 | sub_41E1E0 | counterpart of sub_41EBB0 |
| 0041ebb0 | sub_41EBB0 | begin HUD/entry update block |
| 0042a720 | sub_42A720 | state-8 epilogue |
| 004304c0 | sub_4304C0 | race bookkeeping call (twice) |
| 0045dde0 | sub_45DDE0 | first call in teardown sequence |
| 00475bf0 | sub_475BF0 | set state object dword_B6CBA8 |
| 00497e00 | sub_497E00 | setup on entry found with id 57 |
| 004ae810 | sub_4AE810 | init entry found with id 21/22, arg 0 |
| 004e1810 | sub_4E1810 | push state/monitor (string or id) onto dword_B6E090 |
| 004e5fc0 | sub_4E5FC0 | reset dword_B6E4D0 with 0 |
| 004edfe0 | sub_4EDFE0 | update object dword_B6F1C8 |
| 0052bf50 | sub_52BF50 | called with 1 when linger count (dword_91E084+14820) <= 1 |
| 0053e6f0 | sub_53E6F0 | set 0.0 (speed/time scale reset) |
| 005400b0 | VirtualDispatchStateReset [exact] | virtual-dispatch state reset on unk_BE1D30 |
| 005400f0 | GlobalVirtualDispatchGuarded [exact] | guarded global virtual dispatch on unk_BE1D30 |
| 00540130 | sub_540130 | dispatch on unk_BE1D30 (wait path) |
| 00540150 | VirtualCallOnDAT008ac4c4_8d80 [exact] | virtual call on unk_BE1D30 (state 8) |
| 005403d0 | VirtualCallOnDAT008ac4c4 [exact] | virtual call on dword_BE1D20 |
| 00540850 | sub_540850 | adjust value by -1.0 |
| 00551a90 | sub_551A90 | boolean test deciding monitor vs wait path |
| 00557150 | ResourceDestroy [structural] | destroy resource dword_903A10 |
| 0055eda0 | sub_55EDA0 | second-stage release of dword_903A10 |
| 00562430 | sub_562430 | reset dword_FAE988 with -1, 0 |
| 0056fd00 | sub_56FD00 | per-object teardown (offset +2704) when flag +2864 is clear |
| 00573540 | sub_573540 | helper invoked on dword_91E084+16 (twice) |
| 0058cd40 | sub_58CD40 | per-object teardown (offset 24) when flag +276 set |

**Guard conditions:** Outer gate: `*(_DWORD*)dword_B640C8 == 6` (game state is race) AND `*(_DWORD*)dword_B72314 != 6` (race sub-state not yet 6) — otherwise the whole monitor block is skipped. Inside, sub_551A90() must return nonzero to take the monitor path; when it returns 0 the code takes the wait path only if `*(_DWORD*)dword_B72314 != 5` AND `dword_B70030 == 0`. Within the monitor path, `*(_DWORD*)(dword_91E084+14820) <= 1` triggers sub_52BF50(1), and entry setup (id 21/22) is skipped only when the sub-state is 5. byte_B6F118 != 1 forces a one-shot reset. Reset branch: if byte_B722CC == 1 it requires byte_B70900 == 1, else with byte_B722CC == 0 it requires byte_B70918 == 1, to run the sub_5400B0/sub_540850 reset. Final state-8 block only runs when `*(_DWORD*)dword_B72314 == 8`, and inside byte_91E048 must equal 2 for the HUD entry sequence.

**String literals referenced (deterministic):**

- `POST RACE MONITOR`
- `ENDURANCE POST RACE MONITOR`
