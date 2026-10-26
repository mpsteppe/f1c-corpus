## ModuleInitializationWithFallback_00434820 — ModuleInitializationWithFallback

**Summary:** Initializes constraint solver parameters and dispatches initialization. Tries sub_4348B0 first; if it fails, falls back to GameActionStateMachine and sets flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CarSelectionStateMachine (00434460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | bFallbackUsed: flag set to 1 when fallback initialization path is taken |
| this | 0x8 | RW | — | virtual dispatch result stored from VirtualDispatchHelper |

**Written-by note (persistence):**
- this 0x0: written once (set to 1) in fallback path. Survives.
- this 0x8: written once from VirtualDispatchHelper. Survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea510 | dword_5EA510 | R | SessionManager — passed to VirtualDispatchHelper and GameActionStateMachine |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c870 | VirtualDispatchHelper | dispatch virtual call on session manager |
| 0040cde0 | GameActionStateMachine | set game action state (mode 5, flag 1) |
| 00434860 | ConstraintSolverParamInit | initialize constraint solver parameters on this|
| 004348b0 | sub_4348B0 | primary initialization path (returns non-zero on success) |

**Guard conditions:** `sub_4348B0` return value is the key guard. If non-zero (success), function returns 1 immediately without calling GameActionStateMachine or setting flag. If zero (failure), fallback path executes: GameActionStateMachine called, `this[0]` flag set to 1, returns 0.
