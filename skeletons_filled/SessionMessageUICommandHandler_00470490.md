## SessionMessageUICommandHandler_00470490 — SessionMessageMultiTypeHandler

**Summary:** Multi-branch handler for session UI commands based on type selector at offset 0x304: copies track buffer strings (types 432/434) or processes a session message with progress bar event encoding, texture creation, path construction, and session state dispatch (type 435). Always calls vtable function at +168 before returning.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xA8 | R | — | vtable function at offset 168 — finalizer call with (this, 1) |
| this | 0x0 | R | — | vtable pointer (read for dispatch at offset 168) |
| this | 0x40 | R | — | this[16] — passed to FieldGetter_79d0 for ownership verification |
| this | 0x2F0 | R | — | this[188] — string/buffer pointer for copy or message processing |
| this | 0x304 | R | — | type selector (this[193]) — determines branch: 432, 434, or 435 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory path [DERIVED] — first byte read for path prefix |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] — passed to SessionStateCheckWrapper and TextureCreationWrapper |
| 007cd834 | byte_7CD834 | R | TrackDB_Buffer_7CD834 [DERIVED] — target for sub_587DD0 copy (type 432) |
| 007cd84d | byte_7CD84D | W | FilmModeFlag [DERIVED] — cleared to 0 (type 432) |
| 007cd860 | unk_7CD860 | R | TrackDataBuffer [DERIVED] — target for sub_587DD0 copy (type 434) |
| 007cd87f | byte_7CD87F | W | Byte_ReplayFlag [DERIVED] — cleared to 0 (type 434) |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] — passed to ProgressBarEventEncode for timestamp |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045bc50 | StringCopyWithFormatQuery | format and copy string for session command dispatch |
| 00461db0 | SessionStateCheckWrapper | check session state validity (guard for type 435) |
| 00462250 | TextureCreationWrapper | create or retrieve texture resource |
| 004979d0 | FieldGetter_79d0 | get field for ownership comparison with this |
| 004a0df0 | SessionStateDispatch | dispatch formatted message to session state system |
| 004b0b20 | sub_4B0B20 | file/directory path construction from app directory |
| 004b33b0 | ProgressBarEventEncode | encode progress bar event with length, session time, and flags |
| 00587dd0 | sub_587DD0 | copy string with length limit to target buffer |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x304 | == | 435 | type selector for session message branch |
| this | 0x304 | == | 434 | type selector for track data buffer copy branch |
| this | 0x304 | == | 432 | type selector for track DB buffer copy branch |

**Guard interpretation:** Three-way switch on this[193] at offset 0x304. Case 432: copies 25 bytes from track DB buffer, clears FilmModeFlag. Case 434: copies 31 bytes from track data buffer, clears Byte_ReplayFlag. Case 435 (else branch): additionally gated by SessionStateCheckWrapper, FieldGetter_79d0 ownership check, this[188] non-null, and string length > 0 before dispatching session message. All paths call vtable+168(this, 1) as finalizer.
