## CollisionResponseStatus_00463cd0 — Collision Response and Session Sync with State Guard

**Summary:** Dispatches input commands to entities and synchronizes session if state at +0x3FC4 is non-zero, using default scoring return value. Always resets flag at +0x374 to 0 on exit.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x374 | RW | 0 | flag reset to 0 on every call (regardless of state) |
| obj | 0x3FC4 | R | — | state guard; must be non-zero to dispatch/sync |
| this | 0x0 | R | — | vtable/primary pointer |

**Written-by note (persistence):**
- obj 0x374: written to 0 every call; external poke overwritten on each invocation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045f4a0 | InputCommandDispatchToEntities | dispatches input commands to game entities |
| 0045f950 | SessionSynchronizer | synchronizes session state using default score return |

**Guard conditions:** State at +0x3FC4 must be non-zero to dispatch commands and synchronize. If zero: BLOCKED from dispatch/sync, still resets +0x374. PASSES only when state non-zero.
