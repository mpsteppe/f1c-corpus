# DS Trial Run — Answer Key (DO NOT SHARE WITH DEEPSEEK)

These are PROVEN ground truths from live game testing. After DeepSeek analyzes
the .c files blind, compare its interpretations against this key.

## Scoring criteria

For each function, check if DeepSeek correctly identifies the specific claim.
Score: PASS if it gets the key insight, FAIL if it misses or gets it wrong.

---

### 1. FUN_004a6db0 — VehicleControlEnabled

**Ground truth:** This function checks FinishState at offset +0x4064 (param_1's
vehicle ptr → iVar1+0x4064). It ONLY checks for values 1 and 3. Value 2 is
NOT checked — a car with FinishState=2 will NOT be disabled by this function.

**Test question:** "What values of the field at offset +0x4064 cause this
function to return false (disable the vehicle)?"

**Correct answer:** Values 1 and 3 only. Value 2 passes through.

---

### 2. FUN_00424e70 — AIMainUpdate

**Ground truth:** This is the main AI per-frame driving update. Key facts:
- Entry guard checks param_1[0xcb2] (offset +0x32C8) — only values 0 and 1
  proceed. Any other value makes AI skip the entire frame.
- param_1[0x1144] (offset +0x4510) is AI internal state (0=normal, 2=pit follow,
  3=pit approach, 4=formation, 5=qualifying). It is SET by the function, not
  an external input.
- param_1[0xd3c] (offset +0x34F0) is used as argument to fsin/fcos — it's a
  heading/yaw angle in radians, NOT a render position.
- param_1[0xf5b] (offset +0x3D6C, carConditions) == 2 triggers modified throttle
  behavior, but does NOT stop the car or retire it.
- param_1[0x1019] (offset +0x4064, FinishState) == 2 only clears a flag
  (param_1[0x117d]), does NOT stop AI driving.

**Test questions:**
- "What does writing value 2 to offset +0x32C8 do to this AI?"
- "Is offset +0x34F0 a position coordinate?"
- "Does setting +0x4064 to 2 stop the AI from driving?"

**Correct answers:**
- Writing 2 to +0x32C8 makes the function return immediately — AI skips frame
- +0x34F0 is NOT position, it's heading angle (fsin/fcos usage)
- Setting +0x4064=2 does NOT stop AI — only clears one internal flag

---

### 3. FUN_004a0fd0 — Restart Gate

**Ground truth:** Two restart paths:
- DAT_007ce25d != 0 → return 4 (mini-restart: Game_Restart cleanup, safe)
- DAT_007ce25e != 0 → return 6 (full restart chain, CRASHES in practice)

**Test question:** "What are the two restart trigger globals and their effects?"

**Correct answer:** 0x7CE25D triggers return 4 (safe restart), 0x7CE25E triggers
return 6 (full restart — game crashes when used during race).

---

### 4. FUN_004a0de0 — Pause Request Setter

**Ground truth:** This tiny function writes DAT_007ce25f = 1. It is a
pause REQUEST trigger, not a pause STATE flag. The actual pause state
is at 0x007C56AC.

**Test question:** "Is DAT_007ce25f the current pause state?"

**Correct answer:** No, it's a one-shot request setter. Current state is elsewhere.

---

### 5. FUN_004d82d0 — HUD Flag Renderer (Main)

**Ground truth:** Renders flag icons in the HUD. Writes byte 0x41 for blue flag
(from FUN_0049bb20). There is a SECOND renderer (FUN_004dbac3) that also
writes 0x41. To change flag color, BOTH must be patched.

**Test question:** "If you patch byte 0x41 to 0x40 in this function only,
does the flag change to red everywhere?"

**Correct answer:** No — a second renderer at 0x4DBAC3 also writes 0x41.
Must patch both.

---

### 6. FUN_004dbac3 — HUD Flag Renderer (Secondary)

**Ground truth:** Second flag renderer, also writes 0x41. Same flag byte
values as FUN_004d82d0. Both exist independently.

**Test question:** "Is this function related to FUN_004d82d0?"

**Correct answer:** Yes — both render flags to HUD, both write 0x41 for blue flag.

---

### 7. FUN_004bc0e0 — DQ Handler

**Ground truth:** param_1[0xc] is READ as a guard (`if (param_1[0xc] != 3)`).
The function does NOT write value 3 to param_1[0xc]. It processes a
disqualification with string formatting and logging, but the DSQ state
must already be set by the caller.

**Test question:** "Does this function set the DSQ state (value 3) at offset +0x30?"

**Correct answer:** No. It checks if +0x30 already equals 3, and returns if so
(avoiding double-DQ). The caller must set the state.

---

### 8. FUN_004a5d10 — AI State Machine Dispatcher

**Ground truth:** Dispatches AI behavior based on param_1[0x61]. Calls
FUN_004a6db0 (VehicleControlEnabled) for modes 1 and 2. Only runs
special handlers when vehicle's FinishState (+13000 from vtable) == 2 or 3.

**Test question:** "What triggers the 'Entering Pits Under Red' handler (FUN_004a5ea0)?"

**Correct answer:** Only when FinishState (from *param_1 + 13000) == 2 or 3
AND param_1[0x61] == 2.

---

### 9. FUN_00424790 — AI Init/Reset

**Ground truth:** Initializes AI state. Key insight:
- param_1[0x114e] (offset +0x4538) = 0x497423f0 (float ~1e6) = absolute max speed
- param_1[0x114f] (offset +0x453C) = 0x3f800000 (float 1.0) = speed MULTIPLIER

**Test question:** "What are the fields at +0x4538 and +0x453C?"

**Correct answer:** +0x4538 is absolute max speed (initialized to ~1e6 = unlimited).
+0x453C is a speed multiplier (initialized to 1.0 = full speed).

---

### 10. FUN_00429470 — AI Speed Update (tick function)

**Ground truth:** Updates param_1[0x114f] (offset +0x453C, the speed multiplier)
every tick based on race conditions. Writes to it 10+ times across branches.
Any external write to +0x453C will be OVERWRITTEN by this function on the
next tick.

**Test question:** "Can you persistently set offset +0x453C from outside?"

**Correct answer:** No — this function recalculates and overwrites it every frame.
Must use a tick loop to keep overwriting it.
