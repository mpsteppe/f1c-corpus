## AIStateMachineWithModeDispatch_004a5d10 — AI state machine with mode-aware dispatch to steering/physics subsystems

**Summary:** Updates AI vehicle mode and speed from external state descriptor (`a2`). Depending on vehicle pit-lane state at `*(*this)[3250]` (+0x32C8 == 2 or 3), dispatches to pit-under-red or formation-lap handlers. Then routes control based on **mode value** at `*((_DWORD *)this + 97)` (+0x184): mode 0 calls a flag-based loop on the steering subsystem; modes 1 or 2 call VehicleControlEnabled, steering dispatch (`sub_4A3390`), delegate dispatch, and physics subsystems (`sub_4A3320` on two pointers at +0x010 and +0x00C).

**Struct fields accessed:**

| Offset (dec) | Offset (hex) | Read/Write | Init value (if written as literal) | Purpose inferred from code |
|---|---|---|---|---|
| `*((_DWORD *)this + 97)` | +0x184 | Read/Write | a2+8 (char) | AI mode/state value; triggers AIPitStrategyState on change |
| `this[98]` (float) | +0x188 | Write | a2+4 (float) | Speed value from external state descriptor |
| `*(_DWORD **)this` | +0x000 | Read | — | Object base pointer; dereferenced for pit-lane state at [3250] |
| `*(*this)[3250]` (int) | +0x32C8 | Read | — | Pit-lane state (2=pit-exit-lane, 3=pit-entry-lane) |
| `*((_DWORD *)this + 2)` | +0x008 | Read | — | Pointer to steering subsystem object |
| `*((_DWORD *)this + 3)` | +0x00C | Read | — | Pointer to physics subsystem 2 |
| `*((_DWORD *)this + 4)` | +0x010 | Read | — | Pointer to physics subsystem 1 |

**Guard conditions:**

| Field | Checked values | What PASSES | What is BLOCKED |
|---|---|---|---|
| `*((_DWORD *)this + 97) != (char)a2[8]` | mismatch | Updates mode field, calls AIPitStrategyState | Already same → skip |
| `v4[3250]` (+0x32C8) | 2 or 3 | Enters pit-lane dispatch block | Other → skip |
| `*((_DWORD *)this + 97)` (mode) within pit-lane block | 0 vs 2 vs other | **0** → calls sub_4A5F20; **2** → calls sub_4A5EA0 | 1 or other → no sub-call |
| `*((_DWORD *)this + 97)` (mode) for main dispatch | 0 vs 1 vs 2 | 0 → FlagBasedLoopConditionalCall on steering ptr. 1 or 2 → full steering+physics dispatch | Other → skip all |
| `v9 = VehicleControlEnabled(this)` | bool result | Passed to sub_4A3390 as `v9 == 0` | Always called (controls internal steering logic) |
| `*((_DWORD *)this + 2)` (steering ptr) | nonzero/null | Nonzero → dispatch to subsystem | Null → skip |
| `*((_DWORD *)this + 4)` (physics1 ptr) | nonzero/null | Nonzero → call sub_4A3320 | Null → skip |
| `*((_DWORD *)this + 3)` (physics2 ptr) | nonzero/null | Nonzero → call sub_4A3320 and return | Null → skip (returns prior result) |

**Written-by note:** Only two fields are written by this function:
- `*((_DWORD *)this + 97)` (+0x184): mode value. Written **conditionally** — only when `(char)a2[8]` differs from current value. An external poke would survive until the next mode change from the state descriptor.
- `this[98]` (+0x188): speed value. Written **every call** from a2+4. An external poke to this field does NOT persist — overwritten every call.

Because Frame-path is ON_FRAME_PATH, these writes happen every tick (when called). Call frequency is per-frame tick.

**Functions called:**

| Address | IDA name | Inferred purpose |
|---|---|---|
| — | AIPitStrategyState | Notify pit strategy state of mode change |
| — | sub_4A5EA0 | Pit-under-red handler (mode 2, pit state 2 or 3) |
| — | sub_4A5F20 | Formation-lap/start handler (mode 0, pit state 2 or 3) |
| — | ConditionalDispatch_55e0 | State-conditioned general dispatch |
| — | VehicleControlEnabled | Check if vehicle control is enabled (returns bool) |
| — | sub_4A3390 | Steering subsystem dispatch (receives control-enabled negation) |
| — | ConditionalDelegateDispatch | Dispatch via delegate/state condition |
| — | sub_4A3320 | Physics subsystem dispatch (called on [4] and [3] pointers) |
| — | FlagBasedLoopConditionalCall | Flag-based loop call on steering ptr (mode 0 path) |

**Call frequency:** per-frame tick (ON_FRAME_PATH from MainGameTickUpdate)
