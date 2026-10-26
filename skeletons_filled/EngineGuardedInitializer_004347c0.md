## EngineGuardedInitializer_004347c0 — EngineGuardedInitializer

**Summary:** Guarded one-time engine initialization. Checks flag byte; if unset, initializes sound system, buffer, and session phase dispatch, then sets flag to 1. Returns immediately if already initialized.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_40DE60 (0040de60), TickUpdateDispatch (0040e170)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2 | RW | 1 | bInitialized: guard flag — 0=uninitialized, 1=initialized |
| this | 0x8 | R | — | session parameter passed to SessionPhaseDispatchWithCascadeChecks |

**Written-by note (persistence):**
- this 0x2: written once (set to 1) on first successful initialization. Survives (immutable after init).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea510 | dword_5EA510 | R | SessionManager — session manager for phase dispatch |
| 005ea618 | flt_5EA618 | R | PointerTableEntry — buffer data pointer for BufferInitWith10fDefaults |
| 005eb10c | dword_5EB10C | R | SoundSystemPtr — engine sound system interface pointer |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d1b0 | SessionPhaseDispatchWithCascadeChecks | dispatch session phase with cascade checks |
| 004186a0 | BufferInitWith10fDefaults | initialize buffer with default float values |
| 004d8760 | sub_4D8760 | initialize engine subsystems |

**Guard conditions:** Flag at `this+2` is the sole guard. If non-zero (already initialized), function returns immediately without action. If zero, performs full initialization then sets flag to 1.
