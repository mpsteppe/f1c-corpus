> **UPDATE 2026-07-24 (prose only, fact table untouched) — `a2` IS THE DETACHED
> PART INDEX.** Hook-proven live (`tools/part_detach_watch.js`):
> **0-3 = wheels, 4 = FRONT wing, 5 = REAR wing, 6-13 = bodywork.**
> Bodywork indices are NOT stable per-panel — the same rear-end contact gave
> 6/9/10 in one trial and 7/8 in another.
> - Cases 0-3 set `ReasonCode` (`*this+16488` = `veh+0x4068`) to 6, guarded
>   first-write-wins. This is the ONLY path that writes it — a wing-loss
>   retirement leaves ReasonCode at 0.
> - Case 4 arms the FRONT wing record via `ConditionalResourceRelease(this+818)`,
>   case 5 the REAR via `this+835`. Only the rear one is tested by
>   `PitStopBlockingCondition_0042aee0`, so front = repair, rear = retire.
> - **`this` is NOT the vehicle — `*this` is.** Only fields reached through
>   `*this` are vehicle offsets. (An earlier session claim that `this[3928]` was
>   `veh+0x3D60` was wrong.)
> - Unresolved: `this+818`/`this+835` are `0xCC8`/`0xD0C` while the retire test
>   reads `*this+0xCD4`/`0xD18` — a consistent `0xC` base gap, not explained.
> Evidence: `investigations/part_detach_commentary/README.md`.

## RepairServiceStateDispatcher_004ed250 — repair/pit service state switch dispatcher

**Summary:** Dispatches repair service state transitions (0-13) with subslot cleanup, wheel collision flagging, resource release, and brush-model force solver calls. Part of repair/pit service system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelControllerInputDecoder (00410bc0), CollisionSparkParticleEffects (004ec1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4068 | RW | 6 | service state counter (initialized to 6 when zero) |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] — pointer to game object |
| this | 0x32BC | R | — | mode flag (0 → call WheelCollisionContactFlagSetter) |
| this | 0x3A70 | RW | — | brush model force output value |
| this | 0x3A80 | R | — | brush model force reference value |
| this | 0x3D60 | RW | 1 | service state flag (2 for active repair, 1 for completed) |

**Written-by note (persistence):**
- obj 0x4068: recalc every frame — external poke does NOT persist
- this 0x3A70: recalc every frame — external poke does NOT persist
- this 0x3D60: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004ed360 | jpt_4ED268 | R | jump table for service state cases |
| 004ed370 | byte_4ED370 | R | lookup byte for service state |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041afd0 | sub_41AFD0 | called on all state transitions with current service state |
| 0043e770 | WheelCollisionContactFlagSetter | sets wheel collision contact flags during repair |
| 004a56b0 | StateTransition | transitions state machine to new state |
| 004e0d70 | ConditionalResourceRelease | releases resources for given subslot |
| 004e0e70 | SubslotCleanup | cleans up subslot for states 0-3 |
| 004e8010 | TireBrushModelForceSolver | solves tire brush model forces during repair |

**Guard conditions:** Switch on a2 (0-13). States 0-3: obj+0x4068 initialized to 6 if zero. this[0x32BC] non-zero → BLOCKED (skip WheelCollisionContactFlagSetter). States 4-5: always execute full path with resource release and force solver. States 6-13: resource release only, then goto LABEL12.
