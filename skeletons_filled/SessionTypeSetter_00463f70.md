## SessionTypeSetter_00463f70 — InitSessionTypeAndNetworkConfig

**Summary:** Initializes the game session type based on network state and stored config, sets multiplayer flags, copies network communication strings, and configures collision/session parameters for both online and offline modes.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x28 | RW | 1 | session-active flag (byte, set to 1 = initialized/running) |
| obj | 0x30 | RW | 0 | session sub-state flag (byte, cleared to 0 at end) |
| obj | 0x37C | RW | — | target region passed to GlobalFlagBasedStateSetter for session-flag initialization |
| obj | 0x3FC4 | R | — | session-type discriminant (DWORD: 0=early exit, 1/2=online, else=offline) |
| obj | 0x3FD8 | RW | 8 | session config byte (set to 8) |
| obj | 0x3FD9 | RW | 0 | session config byte 2 (set to 0) |
| this | 0x0 | R | — | pointer to the float-array session data object (dereferenced for all field accesses) |

**Written-by note (persistence):**
- obj 0x28: written once at init (set to 1) — persists across frames until next init
- obj 0x30: written once at init (set to 0) — persists across frames until next init
- obj 0x37C: written once at init via GlobalFlagBasedStateSetter — persists until re-init
- obj 0x3FD8: written once at init (set to 8) — persists until re-init
- obj 0x3FD9: written once at init (set to 0) — persists until re-init

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00464278 | jpt_464127 | R | jump table for switch on dword_7D0E50 (6-way dispatch: 1→8, 2→12, 3→14, 4→32, default→6) |
| 0059f0a8 | dword_59F0A8 | R | NetworkStateInt [DERIVED] |
| 005ea438 | byte_5EA438 | R | default application directory path (fallback string when path globals are null) |
| 007c56a0 | dword_7C56A0 | W | MultiplayerFlags [DERIVED] — set to 3 (online) or 2 (offline) |
| 007cd2a8 | dword_7CD2A8 | R | Unknown_Menu_Struct_7CD2A8 [DERIVED] |
| 007ce260 | byte_7CE260 | R | InitGuard_45d500 [DERIVED] — if zero, runs one-time setup (path init, skin load); skipped after first call |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007ce684 | dword_7CE684 | R | NationalityDataPath [DERIVED] — pointer to nationality path string (or null, uses default) |
| 007cfe0c | dword_7CFE0C | R | VehicleSkinOverridePath [DERIVED] — custom vehicle skin path |
| 007d0e50 | dword_7D0E50 | R | NetCommReadyFlag [DERIVED] — selects session-type ID via switch (1→8, 2→12, 3→14, 4→32, else→6) |
| 007d0e88 | dword_7D0E88 | R | NetCommContextPtr [DERIVED] — network communication context string (copied via StringCopyWithBufferRealloc if online) |
| 007d0e90 | dword_7D0E90 | R | Network_JoinState [DERIVED] — join-state string (copied if online) |
| 007d0e98 | dword_7D0E98 | RW | session-type ID value (written from switch result, clamped to [dword_7D0EA0, dword_7D0EA4]) |
| 007d0e9c | dword_7D0E9C | R | MessageBuffer7D0E9C [DERIVED] — copied to dword_7D0EC0 if online |
| 007d0ea0 | dword_7D0EA0 | R | NetworkSessionState [DERIVED] — lower bound clamp for session type ID |
| 007d0ea4 | dword_7D0EA4 | R | UI_LapDisplayFlags [DERIVED] — upper bound clamp for session type ID |
| 007d0eac | unk_7D0EAC | R | NetworkSessionStruct [DERIVED] |
| 007d0eb4 | unk_7D0EB4 | R | Network_SessionContext [DERIVED] |
| 007d0ebc | dword_7D0EBC | RW | Int_RaceSetupFuelStrat [DERIVED] — set to session type ID if online; otherwise read as fallback value |
| 007d0ec0 | dword_7D0EC0 | W | Unknown_Flag_7D0EC0 [DERIVED] — set to dword_7D0E9C value if online |
| 007d0ec4 | dword_7D0EC4 | W | SessionConfigValue_7D0EC4 [DERIVED] — set to dword_7D0EA0 (lower clamp) if online |
| 007d0ec8 | dword_7D0EC8 | W | OptionFlagBuffer [DERIVED] — set to dword_7D0EA4 (upper clamp) if online |
| 007d0ee0 | dword_7D0EE0 | R | SessionMessageFlag [DERIVED] — passed to SingleFunctionCallWrapper_a750 |
| 007d10ec | dword_7D10EC | R | NetworkJoinFlag [DERIVED] — passed to WheelSpeedConversionWithZeroGuard |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045d490 | GlobalFlagBasedStateSetter | initialize session state flags in the object region at offset 0x37C |
| 0045ecd0 | sub_45ECD0 | sub-session initialization / early-exit path when session-type discriminant is 0 |
| 0045f2a0 | CollisionInvDistanceStore | store inverse distance value for collision system based on session type |
| 00461470 | ThunkToFUN00461480 | initialize a small config struct (&v16) for one-time setup path |
| 004623b0 | ShortComputation_23b0 | short computation on the init struct during one-time setup |
| 00465150 | SingleCallWrapper | single-call wrapper invoked with NetCommReadyFlag value (online session init) |
| 00465160 | WheelSpeedConversionWithZeroGuard | convert wheel speed with zero-guard using network join flag |
| 004b0390 | NameComparisonAt0x1b4 | check/compare name at struct offset 0x1B4 (driver name lookup) |
| 004b0b20 | sub_4B0B20 | process path buffer (default directory path resolution) |
| 00566650 | StringCopyWithBufferRealloc | copy string with dynamic buffer reallocation (network context/join-state strings) |
| 0057a750 | SingleFunctionCallWrapper_a750 | call wrapper invoked with SessionMessageFlag |
| 00587dd0 | sub_587DD0 | copy string into fixed-size buffer (directory/path string copying) |

**Guard conditions:**
- `if (!v2)` where v2 = `*(obj + 0x3FC4)`: if session-type discriminant is 0 → early return via sub_45ECD0. BLOCKED: all subsequent init skipped.
- `if (v2 == 2 || v2 == 1)`: online session path (v14=1, dword_7C56A0=3). else: offline (v14=0, dword_7C56A0=2).
- `if (!byte_7CE260)`: one-time init guard — runs directory setup, skin path resolution, nationality lookup only when flag is zero. BLOCKED (skipped) when already initialized.
- `if (!dword_7CE684)` / `if (!dword_7CFE0C)` / etc.: null-pointer fallback to default directory string.
- `if ((unsigned __int8)NameComparisonAt0x1b4(...))`: conditional driver-name string copy into buffer.
- `if (v14)`: online-mode block — copies network strings and sets session config globals. BLOCKED when offline.
- `switch (dword_7D0E50)`: 6-way dispatch for session type ID.
- `if (v7 < dword_7D0EA0)` / `if (v7 > dword_7D0EA4)`: clamp session type to [lower, upper] bounds.
