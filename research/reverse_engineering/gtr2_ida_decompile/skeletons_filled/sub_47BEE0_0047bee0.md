## sub_47BEE0_0047bee0 — netcomm message dispatcher (session/network messages)

**Summary:** Network message handler from netcomm.cpp: decodes the message header dword and dispatches on message category/type to session handlers — server verify, best times, next session/track, boot reasons, penalty sync, compressed ziploc data, track geometry checks — copying payloads into per-slot records and queueing UI text messages.

**Called by:** sub_47DA30 (0047da30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0047d964 | jpt_47BF46 | R | switch jump table for the message-category/type dispatch |
| 0047d9c4 | byte_47D9C4 | R | unknown (not visible in provided C) |
| 0047da00 | jpt_47CCF4 | R | switch jump table for the message-type dispatch |
| 0047da14 | jpt_47D205 | R | switch jump table for the message-type dispatch |
| 006e1fb6 | SEH_47BEE0 | R | SEH scope/exception-handler record for this function |
| 006f10ec | Sleep | R | WinAPI sleep (1000/2000 ms delays in the Next Session / waiting-for-server paths) |
| 006f115c | GetModuleFileNameA | R | WinAPI used to build the exe-relative path for the .car/.hdc file probe |
| 006f16bc | WindowName | R | fallback string for missing names/paths |
| 006f16d0 | flt_6F16D0 | R | unknown (not visible in provided C) |
| 006f16d4 | flt_6F16D4 | R | unknown (not visible in provided C) |
| 006f1ec0 | aRb | R | file mode "rb" for the fopen probe |
| 006f1f34 | aSS | R | format string "%s%s" |
| 006f3258 | flt_6F3258 | R | unknown (not visible in provided C) |
| 006f611c | flt_6F611C | R | unknown (not visible in provided C) |
| 006f6218 | asc_6F6218 | R | unknown (string constant, not visible in provided C) |
| 006f6244 | aDevSrcCopperhe_4 | R | source path "\Dev\Src\Copperhead\App\Source\netcomm.cpp" used in the debug-log gates |
| 006f6714 | off_6F6714 | R | failure flag string ("ERR") printed in the "Resending server OK request (ret=%s)" log |
| 006f6718 | aOk | R | success flag string "OK" printed in the same log |
| 006f671c | dword_6F671C | R | unknown (not visible in provided C) |
| 006f6720 | byte_6F6720 | R | unknown (not visible in provided C) |
| 006f6724 | aSpecialfxTec | R | literal "specialfx.tec" — tracked file name in the geometry-check loop |
| 006f6728 | byte_6F6728 | R | unknown (not visible in provided C) |
| 006f672c | byte_6F672C | R | unknown (not visible in provided C) |
| 006f6730 | byte_6F6730 | R | unknown (not visible in provided C) |
| 006f68a8 | aSS_2 | R | format string "%s%s" used by sub_632041 |
| 006f6b58 | aReceivedCompre | R | log message "received compressed ziploc from unknown or invalid owner" |
| 006f6b94 | aMismatch | R | message text "mismatch" |
| 006f6ba0 | aTrackGeometry | R | message text "Track Geometry" |
| 006f6bb0 | dword_6F6BB0 | R | unknown (not visible in provided C) |
| 006f6bb4 | byte_6F6BB4 | R | unknown (not visible in provided C) |
| 006f6bb8 | dword_6F6BB8 | R | unknown (not visible in provided C) |
| 006f6bbc | byte_6F6BBC | R | unknown (not visible in provided C) |
| 006f6bc0 | aReason | R | message text "Reason:" |
| 006f6bc8 | aWasRemovedFrom | R | message text "was removed from the game" |
| 006f6be4 | aYouHaveBeenBoo | R | message text "You have been booted" (default boot reason) |
| 006f6bfc | aBootedAsPossib | R | message text "Booted as possible cheat" (reason 5) |
| 006f6c18 | aYouHaveBeenVot | R | message text "You have been voted off" (reason 2) |
| 006f6c30 | aBootedDuplicat | R | message text "Booted.  Duplicate car" (reason 1) |
| 006f6c48 | aCarNotPresentO | R | message text "Car not present on server." (reason 4) |
| 006f6c64 | aServerNotReady | R | message text "Server not ready" (reason 3) |
| 006f6c78 | aNextTrack | R | text "Next Track" used to build the next-track string |
| 006f6c84 | aReceivedBestTi | R | log message "Received Best Times..." |
| 006f6c9c | aReceivedServer_0 | R | log message "Received server verify, setting self as ready..." |
| 006f6ccc | aReceivedServer | R | log message "Received server penalty sync...maximium slot:%d" |
| 006f6d00 | aResendingServe | R | log message "Resending server OK request (ret=%s)" |
| 006f6d28 | aWaitingForServ | R | text "Waiting for server..." |
| 006f6d40 | aNextSession | R | text "Next Session" used to build the next-session string |
| 006f6d50 | aServer_0 | R | fallback text "SERVER" |
| 00731ce8 | String2 | R | global string buffer receiving the parsed track/car name (bounded copy via sub_630FE0) |
| 00757c10 | dword_757C10 | R | number of entries in the local player/vehicle pointer array dword_91E088 |
| 0075b490 | dword_75B490 | RW | unknown (not visible in provided C) |
| 0082f494 | off_82F494 | RW | unknown (not visible in provided C) |
| 0091ca70 | dword_91CA70 | R | pointer whose target string is used as the base path (fallback WindowName) |
| 0091cc38 | byte_91CC38 | R | base object passed to the sub_41D840 text/path builder |
| 0091e084 | dword_91E084 | R | base of the local player/slot records (used with offset +19428) |
| 0091e088 | dword_91E088 | R | array of local player/vehicle pointers indexed by slot |
| 009204a0 | unk_9204A0 | R | per-owner record array base (stride 22616) for network player data |
| 009204b0 | unk_9204B0 | R | second per-owner array base (stride 22616) iterated up to byte_B5E870 |
| 00925ccc | dword_925CCC | W | per-owner table (stride 5654 dwords) written from ziploc messages by owner id |
| 0092a8e4 | unk_92A8E4 | R | strided record array base written in the server-verify copy loop |
| 0092a8f0 | unk_92A8F0 | R | strided record array base written in the best-times copy loop |
| 00b5e870 | byte_B5E870 | R | end address of the unk_9204B0 array (loop bound) |
| 00b640c0 | dword_B640C0 | R | mode/tag value; == 5 suppresses the debug log messages |
| 00b640c8 | dword_B640C8 | R | unknown (not visible in provided C) |
| 00b68ca4 | dword_B68CA4 | R | end bound of the unk_92A8E4 copy loop |
| 00b68cb0 | dword_B68CB0 | R | end bound of the unk_92A8F0 copy loop |
| 00b6cb98 | dword_B6CB98 | R | message queue object passed to sub_4730C0 |
| 00b6cba8 | dword_B6CBA8 | R | global lookup object passed to sub_4735E0 / sub_473630 |
| 00b6cea4 | dword_B6CEA4 | R | file/cache table passed to sub_486BC0 for name checks |
| 00b6f118 | byte_B6F118 | R | flag tested together with byte_B7345C before queueing a status message |
| 00b6f134 | unk_B6F134 | R | notification object passed to sub_4EB900 |
| 00b6f68c | dword_B6F68C | R | base path string for the .gdb handling (fallback WindowName) |
| 00b7235c | dword_B7235C | R | path string used in the "%s%s" mix with dword_91CA70 (fallback WindowName) |
| 00b7345c | byte_B7345C | R | flag tested together with byte_B6F118 |
| 00b73498 | dword_B73498 | R | flag: with sub_4735E0 true alters the file/name lookup path |
| 00b7360c | byte_B7360C | R | flag controlling the car-name matching loops against per-slot records |
| 00b73690 | byte_B73690 | R | bitmask; bit 2 selects the Track Geometry check flag |
| 00be1bd4 | dword_BE1BD4 | R | count of track entries in dword_BE1BD8 (stride 2824) |
| 00be1bd8 | dword_BE1BD8 | R | base pointer of the track entry list (stride 2824) |
| 00be1cdc | unk_BE1CDC | R | unknown (not visible in provided C) |
| 00fade38 | dword_FADE38 | W | global count of players carrying the readiness flag; also written directly in case 0x39 |
| 00fae910 | byte_FAE910 | R | debug/log channel object passed to sub_5612D0/sub_561210 |
| 00fb1d18 | dbl_FB1D18 | R | double constant whose low dword is passed as the magic argument to the sub_51B2A0 sends |
| 00fb1f3c | byte_FB1F3C | W | set to 1 after the car/track verification failure path |
| 01020304 | byte_1020304 | R | constant marker payload (0x01020304) passed to sub_4730C0 |
| 016c96f8 | off_16C96F8 | R | fallback function-pointer table invoked for unhandled/other message types |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00401760 | FloatClamp [exact] | exact-name clamp; bounds the fuel/amount delta to 0.0005..0.01 |
| 0040d7b0 | ReversePathSearchForBackslash [exact] | exact-name path helper; returns the file-name portion after the last backslash |
| 0040d7e0 | sub_40D7E0 | appends/extends the built path string (used after sub_4152E0 with the .gdb name) |
| 004152e0 | sub_4152E0 | applies the path component obtained from sub_40D7B0 |
| 0041d840 | sub_41D840 | text/path builder from base &byte_91CC38 and a literal |
| 00431af0 | sub_431AF0 | reset/release helper for the stack object filled by sub_5886A0 |
| 00435800 | sub_435800 | track match handler called with two caller registers (v177, v178) |
| 0043a460 | sub_43A460 | cleanup/destructor of the stack string object byref at STACK[0x4A4C] |
| 00472fe0 | sub_472FE0 | builds the SERVER text/path (byte_91CC38 fallback) |
| 004730c0 | sub_4730C0 | pushes a message (text, type 3, marker payload, float 5.0) onto the queue |
| 00473390 | sub_473390 | allocates/returns a new message entry index (stored into the session table) |
| 004733b0 | sub_4733B0 | boolean query (setup/ready state) used as v179/v180 |
| 004733e0 | sub_4733E0 | initializes the context struct at the given address |
| 004735e0 | sub_4735E0 | boolean check against the global lookup table dword_B6CBA8 |
| 00473630 | sub_473630 | second boolean check against the lookup table dword_B6CBA8 |
| 00473690 | sub_473690 | returns the current local slot id |
| 004736f0 | sub_4736F0 | finalizes the context built by sub_4733E0 |
| 00473720 | sub_473720 | applies slot info to the session object |
| 00473b70 | sub_473B70 | returns the next record in the car list walk |
| 00473cb0 | sub_473CB0 | boolean query (local player / host flag) |
| 00473fe0 | sub_473FE0 | returns the current user/player name string |
| 004740a0 | sub_4740A0 | handles the case-0 message (session object + payload dword) |
| 004745e0 | sub_4745E0 | commits/finalizes the outgoing message buffer |
| 00474860 | sub_474860 | queues/sends an entry for a slot with a type tag (1, 3 or 5) |
| 00475ed0 | sub_475ED0 | notification flush after the car-check failure path |
| 00475fb0 | sub_475FB0 | completes server-verify handling |
| 00476fc0 | sub_476FC0 | session state switch (session advance) on the session object |
| 00477040 | sub_477040 | applies track/session data with mode 1 |
| 00477540 | sub_477540 | resolves a track entry from names/paths; returns boolean |
| 00479360 | sub_479360 | applies the server-verify payload to the session object |
| 004796f0 | sub_4796F0 | looks up a player entry by id in the session table |
| 0047a1a0 | sub_47A1A0 | prepares server name handling (case 6) |
| 0047ac90 | sub_47AC90 | looks up a per-slot float value (flag 1) |
| 0047b4f0 | sub_47B4F0 | completes server-join handling (case 6) |
| 00486bc0 | sub_486BC0 | checks the file/cache table dword_B6CEA4 for a name |
| 00488890 | sub_488890 | compares/loads client name data; returns boolean |
| 004ea920 | SessionStateDispatch [structural] | structural name; dispatches a session-state notification with the formatted text |
| 004eb900 | sub_4EB900 | checks whether a text message already exists (returns boolean; callers Sleep when true) |
| 0051b2a0 | sub_51B2A0 | sends a network message of category 4 with parameters (code, sizes, magic value, 3) |
| 0051bfa0 | sub_51BFA0 | unknown (not visible in provided C) |
| 0051c6d0 | sub_51C6D0 | handles the compressed ziploc message (category 0x2800) |
| 00524660 | sub_524660 | adds/removes the matched car entry in a list (flag 1) |
| 00539670 | sub_539670 | resolves a player record from the owner name/id |
| 0053f0e0 | VTableDtorNullFields [exact] | exact-name helper (vtable dtor/nulling); invoked with 1 when the slot state is active |
| 0053f190 | sub_53F190 | applies ziploc data to the slot record |
| 00561210 | sub_561210 | writes a debug log message |
| 005612d0 | sub_5612D0 | debug-log gate/check before logging |
| 00573880 | sub_573880 | resets/sets the per-slot penalty value (0.0 on reset, slot value otherwise) |
| 005875f0 | sub_5875F0 | initializes the stack string/struct at STACK[0x4A4C] |
| 005886a0 | sub_5886A0 | looks up/binds a resource by name (mode 3) |
| 0059b460 | DualVirtualDispatchWrapper [exact] | exact-name wrapper for the dual virtual dispatch on the session object |
| 0059b580 | sub_59B580 | returns the local player id from the session object |
| 005fdfb0 | sub_5FDFB0 | queues/releases a notification object (flag 0 or 1) |
| 00615860 | StringCopyWithBufferRealloc [structural] | appends the text into the working buffer with reallocation |
| 00616480 | sub_616480 | substring search used to match car/track names in records |
| 00630739 | ??2@YAPAXI@Z | operator new — allocates the 8-byte notification objects and 0x84-byte payloads |
| 00630fe0 | sub_630FE0 | bounded string copy into String2 |
| 00631710 | _fclose | closes the probe file |
| 00631761 | _sprintf | builds "%s %s" messages |
| 00631a22 | _fopen | opens the exe-relative .car/.hdc path with mode "rb" as an existence probe |
| 00631bd0 | sub_631BD0 | entry initialization helper called at function start |
| 00631c0d | __stricmp | case-insensitive name comparison |
| 00632041 | sub_632041 | formats "%s%s" into the fixed destination buffer |

**Guard conditions:** Header decode: category = (*(DWORD*)a4 >> 29) - 1; category 0 takes the ziploc/owner sub-branch (inside: owner id ((v30>>18)&0x3F)==0 and command bits 0x2800 → sub_51C6D0; owner id >= 0x69 logs "received compressed ziploc from unknown or invalid owner" (suppressed when dword_B640C0==5); owner id < 0x69 writes dword_925CCC[5654*id] and, when the slot's field +3705 == 2, calls sub_53F0E0(1)/sub_53F190); category != 3 → fallback off_16C96F8 and return. Otherwise switch((v30>>18)&0x3F): case 2 requires *(session+113328)==3 (otherwise skip); case 3 requires *byte_B7360C and dword_757C10>0 for the name-match loop and byte_B7360C + dword_B73498 for the LABEL_77 short-circuit; cases 3/0x36 bail to sub_4745E0 when v184==NAN or *(...+2228)!=3 or flags set; case 4/0x34 copy loops bounded by dword_B68CA4/dword_B68CB0; case 5 logs and returns early when sub_4EB900 finds the text; case 6 requires *(session+113328)==1 for the name compare, else the else-branch runs only when the string is non-empty/SERVER fallback (dword_757C10), byte_B6F118/byte_B7345C gate one queue push; case 0x1C only continues when sub_473CB0()==0 (BYTE2 flag) and only queues when sub_59B580(...)==payload id or (payload reason != 3 and name != "?"); case 0x20 runs the geometry loop only when message bits > 0x1400 and the file probe path exists, then per-index checks: index 1 uses byte_B73690 bit 2, index 5 builds "%s%s" from dword_91CA70/dword_B7235C; case 0x2C requires byte_B7360C and a matching car name, and v149==104 selects one of two sends; case 0x31 branches on sub_473CB0() and slot equality with sub_473690(); case 0x37/0x38 require sub_473CB0(); default → fallback off_16C96F8. All log messages are additionally gated by dword_B640C0 != 5 and the sub_5612D0 debug gate.

**String literals referenced (deterministic):**

- `%s%s`
- `\Dev\Src\Copperhead\App\Source\netcomm.cpp`
- `\Dev\Src\Copperhead\App\Source\netcomm.cpp`
- `\Dev\Src\Copperhead\App\Source\netcomm.cpp`
- `\Dev\Src\Copperhead\App\Source\netcomm.cpp`
- `\Dev\Src\Copperhead\App\Source\netcomm.cpp`
- `ERR`
- `.gdb`
- `specialfx.tec`
- `%s %s`
- `%s %s`
- `%s %s`
- `received compressed ziploc from unknown or invalid owner`
- `mismatch`
- `Track Geometry`
- `.car`
- `.hdc`
- `Reason:`
- `was removed from the game`
- `You have been booted`
- … +13 more
