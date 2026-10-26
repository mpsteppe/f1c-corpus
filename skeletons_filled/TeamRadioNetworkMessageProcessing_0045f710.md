## TeamRadioNetworkMessageProcessing_0045f710 — TeamRadioMessageProcessor

**Summary:** Processes team radio network messages during active session phases (1-2). Handles resource cleanup, collision solving, message dispatching, and per-entity texture rendering. Ends with optional callback dispatch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | postProcessInput [CONFIRMED] — method pointer for dispatch |
| this | 0x388 | RW | 0 | Message processing counter/flag, reset to 0 each iteration |
| this | 0x410 | R | — | Entity index array (byte-sized indices per entity) |
| this | 0x3E14 | R | — | Number of active entities in the session |
| this | 0x3FB8 | R | — | COM interface pointer for SEH-protected data copy and final dispatch |
| this | 0x3FC4 | R | — | Session phase (1 or 2 = active racing, gates processing) |

**Written-by note (persistence):**
- this 0x388: conditional — reset to 0 each time a message is received; otherwise untouched

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ef9a0 | dword_5EF9A0 | R | VEH[0].0x32C8 — vehicle state array start |
| 007c87a0 | dword_7C87A0 | R | SuspensionStatePtr [DERIVED] — end bound for vehicle iteration |
| 007cd2a8 | dword_7CD2A8 | R | Unknown_Menu_Struct_7CD2A8 [DERIVED] — resource/visibility manager |
| 007d0e98 | dword_7D0E98 | R | Unknown_Flag_7D0E98 [DERIVED] — threshold guard (compared > 8) |
| 007d0f04 | dword_7D0F04 | R | NetCommStateFlag [DERIVED] — when zero, allows final dispatch |
| 007d2e50 | dword_7D2E50 | R | SessionMsgCount [DERIVED] — session message ring buffer |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] — passed to CollisionContactSolver |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045c8f0 | CollisionContactSolver | Solve collision contacts with session time |
| 0045d890 | NetCommSessionMessageDispatcher | Dispatch network communication session messages |
| 00460c30 | LinearSearchIn104ElementArray | Search 104-element array for matching entry (phase-specific) |
| 00461440 | ReferencesGlobalState | Check if object references global state |
| 00461470 | ThunkToFUN00461480 | Thunk for state copy |
| 004614c0 | TwoStageCheck | Two-stage condition check for entity filtering |
| 00462250 | TextureCreationWrapper | Create/update texture for entity rendering |
| 00462300 | SingleFunctionDispatch | Dispatch single function via method pointer |
| 004651c0 | ResourceManagerFrameCleanup | Cleanup resources at frame start |
| 004652d0 | ShortComputation_52d0 | Process vehicle entry (short computation) |
| 00465300 | sub_465300 | Process input command for global state |
| 004b0170 | EmptyStub_0170 | Empty stub |
| 004b3af0 | AdvanceRingBuffer | Advance ring buffer to next entry |
| 004b3b30 | SessionDataCopy | Copy session ring buffer data |
| 0057a730 | sub_57A730 | Final dispatch callback via COM interface |
| 0057a760 | SEHProtectedDataCopy | Copy network data with SEH protection |

**Guard conditions:**
- If ReferencesGlobalState(this): call ResourceManagerFrameCleanup, iterate vehicle state array (dword_5EF9A0, step 4656 bytes per entry), call ShortComputation_52d0 when *v3 != -1.
- Session phase (this+0x3FC4) == 1 or 2 → set v5 = true; otherwise v5 = false.
- Message loop: SEHProtectedDataCopy returns non-zero → break loop.
- Inside loop: this+0x388 reset to 0 (counter).
- If v5 (phase 1 or 2): call LinearSearchIn104ElementArray, merge result into command byte.
- Always call CollisionContactSolver and NetCommSessionMessageDispatcher.
- After loop, if v5 (phase 1 or 2):
  - ReferencesGlobalState: copy ring buffer, advance entries, call sub_465300 for each.
  - Not global state: call SingleFunctionDispatch, iterate entities with TwoStageCheck, skip self-entity (v11 == v15), create textures for non-self entities.
  - Final dispatch: only if !dword_7D0F04 && dword_7D0E98 > 8 && v9 > 0.
