## ConditionalMultiFieldReset_00535e10 — ElementConditionalInit

**Summary:** Resets multiple object fields to zero/default values after validating pointers and sub-object pointer (v1). Part of UI/element initialization system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_535C10 (00535c10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 0 | reset field, flag or counter |
| this | 0x14 | RW | 0 | reset field, flag or counter |
| this | 0x18 | RW | 0 | reset field, flag or counter |
| this | 0x1C | R | — | sub-object pointer (v1), null-checked for validity |
| this | 0x20 | RW | — | validity guard, must be non-null to proceed |
| this | 0x24 | R | — | validity guard, must be non-null to proceed |
| this | 0x2C | RW | 2 | state field, set to 2 on init |
| this | 0x30 | RW | 1 | state/flag, set to 1 on init |
| this | 0x34 | RW | 0 | signed counter, clamped to 0 if negative; determines v1[1] value (113 if non-zero, 42 if zero) |
| this | 0x3A | RW | 0 | byte flag in sub-object, cleared to 0 |

**Written-by note (persistence):**
- this 0x8: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x2C: recalc every frame — external poke does NOT persist
- this 0x30: recalc every frame — external poke does NOT persist
- this 0x34: recalc every frame — external poke does NOT persist
- this 0x3A: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00536260 | sub_536260 | post-init processing on sub-object |
| 00537e40 | UIElementInitialization | initialize UI sub-object v1 |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x34 | != | 0 | v1[6] non-zero check — PASSES non-zero (writes 113 to v1[1]), BLOCKED zero (writes 42) |
| this | 0x34 | < | 0 | v1[6] sign check — PASSES non-negative (keep value), BLOCKED negative (reset to 0) |

**Guard interpretation:** Early return guards: `this==NULL`, `this[7]==NULL`, `this[8]==0`, or `this[9]==0` all block execution (return -2). All four must pass (non-null/non-zero) to proceed with field resets. The later guards on `v1[6]` (offset 0x34) control sub-object field initialization: if negative it is clamped to zero, and v1[1] gets 113 when non-zero, 42 when zero.
