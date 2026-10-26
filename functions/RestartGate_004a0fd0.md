## RestartGate_004a0fd0 — Restart-type dispatcher with timer and menu-state handling

**Summary:** Multiplexed restart-entry gate called from GamePostMainLoop. Reads several restart-flag bytes to decide restart type: `byte_7CE25D` triggers mini-restart (return 4, copies a vehicle field across all vehicles); `byte_7CE25E`/`byte_7CE260` triggers full restart (return 6). Otherwise runs a timer-based state machine (`dword_7CE258`), checks `byte_7CE25F` via `sub_485B90`, and monitors a word array at `word_7CB21C` for menu-transition requests.

**Globals referenced — Reads:**

| Address | IDA name | Read/Write | Role |
|---|---|---|---|
| 0x007CE25D | byte_7CE25D | Read/Write (clear to 0) | Mini-restart flag; if set → returns 4 |
| 0x007CE25E | byte_7CE25E | Read/Write (clear to 0) | Full-restart flag; if set → returns 6 |
| 0x007CE260 | byte_7CE260 | Read | Restart precondition flag; paired with byte_7CE25E |
| 0x007CE25F | byte_7CE25F | Read | Passed to sub_485B90 for restart-progress check |
| 0x007CE254 | byte_7CE254 | Read | Gate byte; when 0, bypasses restart-progress and menu-loop blocks |
| 0x007CE258 | dword_7CE258 | Read/Write | Restart-state machine (0, 1, 2) |
| 0x007CE264 | dword_7CE264 | Read | Secondary restart mode flag |
| 0x007CE269 | byte_7CE269 | Read/Write (clear to 0) | Timer-active flag |
| 0x007CE26C | dword_7CE26C | Read/Write (decrement, clear to 0) | Timer countdown value |
| 0x007C56A4 | dword_7C56A4 (SessionType) | Read | Session type guard (7 = race for FieldCopy) |
| 0x005C329C | dword_5C329C (VehicleCount) | Read | Loop bound for copying field across vehicles |
| 0x007C54F0 | dword_7C54F0 (VehiclePtrArray) | Read | Vehicle pointer array (indexed by i) |
| 0x007C54E8 | dword_7C54E8 (PlayerVehiclePtr) | Read | Player vehicle pointer |
| 0x007C569C | dword_7C569C | Read/Write | Return/menu-state value; final return value |
| 0x007CB218 | dword_7CB218 | Read | Count of entries in word_7CB21C array |
| 0x007CB21C | word_7CB21C | Read | Array of word entries; value 1 triggers menu-transition check |
| 0x008AFEA0 | dbl_8AFE98 | Read | Constant subtracted from timer (type appears as dbl but used as float) |

**Globals referenced — Writes:**

| Address | IDA name | Write | Value | Role |
|---|---|---|---|---|
| 0x007CE25D | byte_7CE25D | Clear | 0 | Mini-restart flag consumed |
| 0x007CE25E | byte_7CE25E | Clear | 0 | Full-restart flag consumed |
| 0x007CE258 | dword_7CE258 | Set | 1 | Restart-state reset |
| 0x007CE250 | dword_7CE250 | Increment | +1 | Counter passed to sub_485B90 |
| 0x007CE269 | byte_7CE269 | Clear | 0 | Timer deactivated |
| 0x007CE26C | dword_7CE26C | Clear | 0 | Timer countdown reset |
| 0x007C569C | dword_7C569C | Set | 6 | Menu-transition code |

**Guard conditions (execution flow):**

| Checked values | What PASSES | What is BLOCKED |
|---|---|---|
| `byte_7CE25D` nonzero | **Mini-restart path**: clears flag, copies field +0x4034 for all vehicles (if SessionType==7), runs ScoringGateCheck, returns 4 | All later checks skipped |
| `byte_7CE25E` or `byte_7CE260` nonzero | **Full-restart path**: clears byte_7CE25E, returns 6 | All later checks skipped |
| `dword_7CE264 == 1` | Checks `dword_7CE258`: if ==1 returns 6; else falls through | If dword_7CE258 != 1, continues to sub_404B60 |
| `byte_7CE254` zero | Skips sub_485B90 and menu-loop entirely (goto LABEL_18) | Nonzero → runs sub_485B90 |
| `sub_485B90(byte_7CE25F)` result -1 or 3 | **Returns 6** (full restart) | Other values continue |
| `sub_485B90(byte_7CE25F)` result 4 | **Returns 4** (mini-restart) | Other values fall through to LABEL_18 |
| `byte_7CE269` && timer > 0.0 | Decrements timer by dbl_8AFE98. Timer <=0: clears flag+count, sets dword_7CE258=1 | Timer >0: decrement only |
| `dword_7CE258` | 1: enters restart-init block; 2: sets to 1 then goto end | 0: falls through |
| `dword_7CE264 == 1` (within restart-init) | Sets `dword_7C569C = 6` | Otherwise calls ConditionalInitGuard |
| `byte_7CE254` zero (second check) | Enters word_7CB21C loop | Nonzero: skip loop |
| `word_7CB21C[i] == 1` | Calls ByteFieldExtractorWithShift; if true → dword_7C569C=6 + MainMenuTransition; else → dword_7CE258=1 | Not 1: continue loop |

**Written-by note:** This function is a reader/decider, not a state maintainer. It reads flag bytes and writes return values. The key writes:
- `byte_7CE25D` cleared to 0 (consumed, written once)
- `byte_7CE25E` cleared to 0 (consumed, written once)
- `dword_7CE258` set to 1 (written in timer-expiry or restart-init paths; conditionally)
- `dword_7CE250` incremented (passed to sub_485B90, written once per call)
- `dword_7C569C` set to 6 in menu-transition path (conditionally)
- Timer globals cleared on expiry

Because Frame-path is NOT_FOUND (no static path from tick root), call frequency is UNKNOWN. Do not assume init-only or per-frame. External pokes to these flag bytes **will persist until this function next runs** — but when it does run, it clears them.

**Functions called:**

| Address | IDA name | Inferred purpose |
|---|---|---|
| — | FieldCopy_c330 | Copy a field (at +0x4034 offset) from one vehicle to another |
| — | ScoringGateCheck | Check scoring state before mini-restart |
| — | SessionStateTransition | Transition session state (called when ScoringGateCheck passes and player vehicle at +0x32C8==1) |
| — | sub_404B60 | Clear/free a structure (called early regardless) |
| — | sub_485B90 | Restart-progress check with byte_7CE25F and counter |
| — | ConditionalInitGuard | Conditional initialization guard (non-264 path) |
| — | ByteFieldExtractorWithShift | Extract boolean field from structure; determines menu transition |
| — | MainMenuTransition | Transition to main menu |
| — | sub_4A0CB0 | Post-check cleanup (always called at end) |

**Call frequency:** UNKNOWN (Frame-path: NOT_FOUND)
