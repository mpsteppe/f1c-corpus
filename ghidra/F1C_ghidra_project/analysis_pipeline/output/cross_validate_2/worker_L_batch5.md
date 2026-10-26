# Cross-Validation Results: Batch 5 (Functions 4051-4100)

## All in docs/20-math-utilities.md unless noted.

---

### FUN_0058806E — result: PASS (minor doc gap)
**Current doc:** docs/20-math-utilities.md (line 62 overview, line 552 entry)
**Issues found:** none critical
**Details:**
- Overview line 62: "buffered file read: intermediate buffer for unbuffered reads, partial read handling" — correct
- Entry line 552: "Buffered file read. Reads param_3 elements of size param_2 into param_1 buffer. Uses intermediate buffer for unbuffered reads (FUN_0058c9b4). Handles partial reads." — matches source at analyzed\0x0058806e__FUN_0058806e.c
- Source confirmed: param_2 * param_3 element count, buffered read with flag check on (param_4+3)&0x10c, FUN_0058c9b4 for unbuffered reads, partial read return calculation at end
- No analysis of the flag bits (0x10c) meaning — minor doc gap but not an error

---

### FUN_00587AC0 — result: PASS
**Current doc:** docs/20-math-utilities.md (line 50 overview, line 671 entry)
**Issues found:** none
**Details:**
- Overview line 50: "stack-based memory allocator push: thread-safe, capacity check, reallocation via FUN_0058b5d4" — correct
- Entry line 671: Analysis matches — capacity check on DAT_008d5a54/DAT_008d5a50, realloc via FUN_0058b5d4 if needed, push value, thread-safe via FUN_00589d6b/FUN_00589d74
- Source: calls FUN_00589d6b() (lock), checks capacity, calls FUN_0058b5d4 to realloc, pushes param_1 to *DAT_008d5a50, increments pointer, calls FUN_00589d74() (unlock)

---

### FUN_0059BE0C — result: ISSUE
**Current doc:** docs/20-math-utilities.md (line 1130)
**Issues found:** [miscategorized, description misleading]
**Details:**
- Entry line 1130: brief inline after source dump — "File read — reads from file handle into buffer, locks/unlocks"
- Triage index: "unknown —"
- Source (analyzed\0x0059be0c__FUN_0059be0c.c): function does NOT do simple file read. It reads characters from a byte stream with code-page-aware multi-byte character decoding:
  - Checks flag at (param_2+3)&0x40
  - If set: reads from buffer with backreferences to DAT_008d4920 table (multi-byte character structure)
  - Uses PTR_DAT_005e69c8 lookup table for multi-byte continuation bytes
  - Calls FUN_00596716 (character decode) and FUN_0058afcf (error set)
  - Falls back to FUN_0059c30e for wide character read
- This is NOT a simple file read — it's a multi-byte/wide character decoder from an I/O stream
- The "locks/unlocks" claim is not verified in the code (no lock/unlock calls visible)

---

### FUN_0057ACB0 — result: ISSUE
**Current doc:** docs/20-math-utilities.md (line 105 overview, line 1303 inline)
**Issues found:** [incorrect description]
**Details:**
- Overview line 105: "queue user callback via QueueUserAPC (async thread callback)"
- Inline entry line 1308: "Queue user callback — posts async callback to thread via QueueUserAPC"
- Source (analyzed\0x0057acb0__FUN_0057acb0.c): function does linked list node REMOVAL, NOT queuing:
  - Calls FUN_00585cc0() + vtable call at +4
  - Walks linked list starting at DAT_008d3bfc searching for node matching param_1
  - Removes node from doubly-linked list (updates prev/next pointers at +4/+8)
  - Decrements counter at DAT_008d3c08
  - Optionally calls FUN_0057a4c0 + FUN_00587bcf on node data
  - Frees node via FUN_00587bcf
- No QueueUserAPC call present in source
- Function is a "callback/event deregistration + cleanup" function, not a queue function
- Claimed at line 105 as QueueUserAPC wrapper — source contradicts

---

### FUN_00575882 — result: ISSUE
**Current doc:** docs/20-math-utilities.md (line 2410)
**Issues found:** [missing analysis — source code dump only]
**Details:**
- Entry at line 2410 has title, size, and raw source code dump but NO analysis text
- Source (analyzed\0x00575882__FUN_00575882.c): 827 bytes, complex function:
  - Initiates a 108-short lookup table with run-length encoded structure (local_f0 array)
  - Compares param_2 against value 0x22 (34 double-precision values)
  - For each of 0x22 data rows: compares each column against _DAT_0059e430 (zero threshold)
  - Tracks alternating runs (local_5 boolean toggles) of zero/nonzero values
  - Validates run lengths against expected pattern in local_f0 lookup table
  - Returns success if total run count == 0x6a and final run_a == 0x31
- This appears to be a data validation/checksum function — validates a 34-entry double array against expected zero/nonzero pattern
- No analysis text exists — function is undocumented despite being 827 bytes

---

### FUN_0058FFEC — result: ISSUE
**Current doc:** docs/20-math-utilities.md (line 4677)
**Issues found:** [missing analysis — source code dump only]
**Details:**
- Entry at line 4677 has raw source code dump with NO analysis text
- Source (analyzed\0x0058ffec__FUN_0058ffec.c): 516 bytes:
  - Calls FUN_005905dd(param_1) — locale/encoding conversion
  - Calls through function pointer DAT_008d3fb8 (GetLocaleInfoW-like)
  - Compares with FUN_00588410 against DAT_008d3fac/DAT_008d3fa8 (locale strings)
  - References DAT_008d3f9c, DAT_008d3fa4, DAT_008d3fa0 (locale state globals)
  - Uses _strlen on locale strings
  - Calls EnumSystemLocalesA in caller (FUN_0058ff65)
- This is a locale info comparison callback used by EnumSystemLocalesA
- Falls under OS locale enumeration — no analysis present

---

### FUN_00581B30 — result: ISSUE
**Current doc:** docs/20-math-utilities.md (line 6088)
**Issues found:** [missing analysis — source code dump only]
**Details:**
- Entry at line 6088 has title, size, source file link, and raw source code dump with NO analysis text
- Source (analyzed\0x00581b30__FUN_00581b30.c): 231 bytes:
  - SEH-protected destructor with __fastcall convention
  - Closes handle at param_1[8] if flag at param_1+0x28 (byte at param_1+10 when int-indexed) is set
  - Walks two linked lists: first list at param_1[4] (calls vtable+0 with arg 1 on each), second list at *param_1 (calls vtable+0 with arg 3 on each)
  - Frees nodes via FUN_00587bcf
  - Zeroes list heads and counters
- This is a resource/callback manager destructor with handle and linked-list cleanup
- No analysis text exists despite being 231 bytes with complex logic

---

### FUN_0058FF65 — result: ISSUE
**Current doc:** docs/20-math-utilities.md (triage index only)
**Issues found:** [missing dedicated entry]
**Details:**
- Triage index: "unknown —"
- Source (analyzed\0x0058ff65__FUN_0058ff65.c): 135 bytes:
  - Calls _strlen on DAT_008d3fa8 and DAT_008d3fac (locale name buffers)
  - Sets DAT_008d3fa4 = (strlen == 3) — likely detecting ISO 3-letter locale codes
  - Sets DAT_008d3f9c = (strlen == 3)
  - If DAT_008d3fa4 == 0: calls FUN_00590616 on locale string to get length
  - Calls EnumSystemLocalesA(FUN_0058ffec, 1) — enumerates system locales
  - Post-enumeration validation: checks DAT_008d3fb0 flags (0x100 & 0x200 & 7)
- This is locale initialization/enumeration — not a math_util at all
- Should be classified as OS/platform locale init, not "unknown"

---

### FUN_00558CB0 — result: PASS (minor)
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** none critical
**Details:**
- Triage entry at line 6352: "Data/FlagSet: Array element flag set with bounds check" — correct
- Source (analyzed\0x00558cb0__FUN_00558cb0.c): checks param_2 < *(param_1+0x2c), calls FUN_0053b330, sets bit 0x4000 at computed offset. Matches description
- First triage line says "math_util —" without description — second triage line more accurate

---

### FUN_0045CBF0 — result: ISSUE
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** [category mismatch, missing description]
**Details:**
- Triage: "math_util — short computation"
- Source (analyzed\0x0045cbf0__FUN_0045cbf0.c):
  - Reads short at (param_1 + 0x12c4 + param_2 * 2) — vehicle struct offset
  - Passes through FUN_0045c7c0
  - Compares result float against DAT_0059e440 (zero threshold)
  - Returns 1 if not equal, else 0
- Uses vehicle struct offset 0x12c4 (suspension/steering parameter indexed by param_2) — this is vehicle-specific, not pure math_util
- DAT_0059e440 is a known physics zero-threshold constant
- Should be classified as vehicle physics threshold check, not generic math_util

---

### FUN_0050D748 — result: ISSUE
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** [missing analysis — function is mislabeled "unidentified"]
**Details:**
- Triage: "unknown — unidentified logic" with 44 bytes
- Source (analyzed\0x0050d748__FUN_0050d748.c): Rodrigues' rotation formula — clear axis-angle to rotation matrix conversion
  - fcos(param_3) and fsin(param_3) — angle
  - Normalizes axis vector param_2 via thunk_FUN_0050c2a6
  - Computes Rodrigues formula: R = I + sin(θ)[k]× + (1-cos(θ))(kk^T - I)
  - Fills 4x4 matrix (16 floats, rows 0-3)
  - Bottom row: 0,0,0,1 (homogeneous)
- This is a well-known computer graphics algorithm — should be documented as "rotation matrix from axis-angle (Rodrigues' formula)"

---

### FUN_005992D3 — result: PASS (minor)
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** none critical
**Details:**
- Triage line 7547: "Destructor pattern: calls FUN_00598e39, conditional free on bit 0" — correct
- Source (analyzed\0x005992d3__FUN_005992d3.c): calls FUN_00598e39(), checks param_2 & 1, calls FUN_00587bcf if set. Matches description
- First triage line "math_util —" is less accurate than second triage description

---

### FUN_0041F180 — result: PASS
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** none
**Details:**
- Triage: "math_util — short computation"
- Source (analyzed\0x0041f180__FUN_0041f180.c): 12 bytes — calls FUN_0041f040(), returns (result == 1). Trivial boolean wrapper. Matches "short computation" classification

---

### FUN_004781A0 — result: ISSUE
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** [category mismatch — not pure math_util]
**Details:**
- Triage: "math_util — short computation"
- Source (analyzed\0x004781a0__FUN_004781a0.c):
  - Calls FUN_00461cd0() and branches on result == 3
  - Branches to different resource IDs (0x18 vs 0x11)
  - Calls through DAT_007cd8c0 vtable at +0x1c — renderer resource allocation
  - Stores result at param_1 + 0xe0
- Contains game-state branching (FUN_00461cd0 result) and renderer vtable call
- Not pure math_util — should be classified as renderer resource allocation

---

### FUN_004910D0 — result: ISSUE
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** [miscategorized as "unidentified"]
**Details:**
- Triage: "unknown — unidentified logic"
- Source (analyzed\0x004910d0__FUN_004910d0.c): linked list destruction with callback:
  - First pass: walks linked list from *param_1 via param_1[2] pointer, calls FUN_00490aa0() on each
  - Second pass: walks list from *param_1 again, for each node: calls FUN_004b0170(), frees data via FUN_00587bcf, frees node
  - Zeroes list head/count fields
- Clearly a linked list destructor with per-element callback — should be classified as "linked list destructor / cleanup"

---

### FUN_004B46F0 — result: ISSUE
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** [miscategorized as "unidentified"]
**Details:**
- Triage: "unknown — unidentified logic"
- Source (analyzed\0x004b46f0__FUN_004b46f0.c): linked list array destructor:
  - Calls FUN_004b4e10() — initialization/cleanup
  - Iterates 4 linked lists (indices 0-3) stored at offsets -0x10, -0xc, -0x8, -0x4 from starting offset 0xb0
  - For each list: walks nodes, frees *puVar2 if flag at puVar2+2 set, frees node
  - Zeroes list head/tail/count fields (4 fields per list)
- Clearly a resource array destructor with multiple linked lists — miscategorized

---

### FUN_004F8280 — result: ISSUE
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** [miscategorized as "unidentified"]
**Details:**
- Triage: "unknown — unidentified logic"
- Source (analyzed\0x004f8280__FUN_004f8280.c): switch-based color constant assignment:
  - Sets *param_2 = _DAT_005d67c8, *param_3 = _DAT_005d67cc, *param_4 = _DAT_005d67d0 (default colors)
  - Switch on param_1:
    - Cases 0-4, 0x2b: sets from DAT_005d67b0/b4/b8
    - Cases 0xc-0x14, 0x26-0x29, 0x2c: sets from DAT_005d67bc/c0/c4
- This is a color constant lookup table based on index (possibly tire compound, car color, or UI theme)
- Should be classified as "color constant lookup"

---

### FUN_005355A0 — result: ISSUE
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** [miscategorized, conditional game logic]
**Details:**
- Triage: "unknown — utility function"
- Source (analyzed\0x005355a0__FUN_005355a0.c):
  - Checks param_1 == 0 → returns 0xfffffffe
  - Checks *(param_1+0x5c) == 'w' — conditional branch on character flag
  - If 'w': calls FUN_005352d0(), if result nonzero calls FUN_00534ee0(), else calls FUN_005355f0() twice
  - Falls through to FUN_00534ee0()
- Has conditional game logic (character/flag check), multiple branches
- Not "utility" — should be classified as game logic with conditional dispatch

---

### FUN_00587880 — result: PASS
**Current doc:** docs/20-math-utilities.md (line 10645)
**Issues found:** none
**Details:**
- Entry: "Field Getter at +0x400 — Returns *(int*)(param_1 + 0x400)"
- Source (analyzed\0x00587880__FUN_00587880.c): 7 bytes — returns *(undefined4 *)(param_1 + 0x400). Matches perfectly.

---

### FUN_00599D17 — result: PASS
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** none critical
**Details:**
- Triage line 7003: "Data/VTableInit: VTable pointer init"
- Triage line 7547 (second pass): "VTable pointer init"
- Source (analyzed\0x00599d17__FUN_00599d17.c): 14 bytes — *param_1 = &PTR_FUN_005b9ca0; FUN_00598c70(); Matches description

---

### FUN_0045BDE0 — result: PASS
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** none
**Details:**
- Triage: "math_util — short computation"
- Source (analyzed\0x0045bde0__FUN_0045bde0.c): 12 bytes — calls FUN_0045ba60(). Trivial wrapper. Matches classification.

---

### FUN_00485540 — result: PASS
**Current doc:** docs/20-math-utilities.md (line 11861)
**Issues found:** none
**Details:**
- Entry: "Short Computation (Destructor) — vtable set, function call, conditional free"
- Source (analyzed\0x00485540__FUN_00485540.c): *param_1 = &PTR_FUN_005ab3f0; FUN_00487250(); if param_2&1: FUN_00587bcf(param_1). Matches.

---

### FUN_004A1B20 — result: ISSUE
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** [category mismatch — string concat, not arithmetic]
**Details:**
- Triage: "math_util — arithmetic/comparison"
- Source (analyzed\0x004a1b20__FUN_004a1b20.c): string concatenation:
  - Selects source base string (DAT_005cd138 or DAT_005cd12c) based on param_2 emptiness
  - Measures lengths of both strings via strlen-like loops
  - Copies source string to end of dest string via 4-byte and 1-byte loops
- NOT "arithmetic/comparison" — this is string concatenation with path prefix selection
- Should be reclassified as "string concat / path join"

---

### FUN_004D4A30 — result: PASS
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** none
**Details:**
- Triage: "math_util — short computation"
- Source (analyzed\0x004d4a30__FUN_004d4a30.c): 12 bytes — calls FUN_00587b3e(&LAB_004d4a40). Trivial callback registration. Fits "short computation" loosely, but actually "callback registration" is more precise.

---

### FUN_00513C80 — result: ISSUE
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** [miscategorized as "unidentified"]
**Details:**
- Triage: "unknown — unidentified logic"
- Source (analyzed\0x00513c80__FUN_00513c80.c): memory allocation + zero-init:
  - Computes param_2 * param_3 (total size)
  - Calls FUN_00517e92(param_1, size) — custom allocator
  - Zeroes memory in three stages:
    - If size > 0x8000: zeroes first 0x8000 bytes in 0x2000-word chunks
    - Zeroes remaining % 4 bytes via 4-byte loop
    - Zeroes remaining % 4 bytes via 1-byte loop
- Clearly a "calloc-like" allocation + zero-init function
- Should be classified as "memory alloc + zero-init"

---

### FUN_00561E20 — result: PASS
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** none
**Details:**
- Triage: "math_util —"
- Source (analyzed\0x00561e20__FUN_00561e20.c): 12 bytes — calls FUN_00561e30(). Trivial thunk. Matches.

---

### FUN_00581AD0 — result: PASS (minor)
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** none critical
**Details:**
- Triage line 6638: "Resource/Cleanup: Close handle, destroy linked list, free nodes"
- Source (analyzed\0x00581ad0__FUN_00581ad0.c):
  - CloseHandle(param_1[4]) if flag at param_1+0x18 (byte at param_1+6 when int-indexed) set
  - Walk linked list from *param_1, free data if flag at node+2 set, free node
  - Zero list head/count fields
- Matches the second triage description exactly
- First triage "unknown —" is superseded by second

---

### FUN_00479DB0 — result: ISSUE
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** [category mismatch — constructor, not short computation]
**Details:**
- Triage: "math_util — short computation"
- Source (analyzed\0x00479db0__FUN_00479db0.c): constructor:
  - Calls FUN_004668e0(0, 0x3f800000) — float param init
  - Sets vtable: *param_1 = &PTR_FUN_005a5d88
  - Sets byte at (param_1+0x41*4=offset+0x104) = 0
- This is a C++ constructor with vtable assignment, not a "short computation"
- Should be classified as "constructor / vtable init"

---

### FUN_004DAE80 — result: PASS
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** none
**Details:**
- Triage: "math_util — arithmetic/comparison"
- Source (analyzed\0x004dae80__FUN_004dae80.c): reads uint from param_1+0x20, if >0 and divisible by 6: returns high byte set to (value/6) & 0x1 with low byte zeroed. Otherwise returns value & 0xffffff00. Simple arithmetic. Matches classification.

---

### FUN_00589D7D — result: PASS
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** none
**Details:**
- Triage line 6783: "Utility: Function pointer array call-all (non-null)"
- Source (analyzed\0x00589d7d__FUN_00589d7d.c): iterates from param_1 to param_2 (exclusive), calls each non-null function pointer. Matches description.

---

### FUN_004053E0 — result: PASS
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** none
**Details:**
- Triage: "math_util — short computation"
- Source (analyzed\0x004053e0__FUN_004053e0.c): sets param_1+4=0, param_1+8=0xffffffff, calls FUN_0049a180(), FUN_004d4840(), FUN_00405440(). Constructor/init sequence. Fits "short computation" classification loosely; more accurately a struct initializer.

---

### FUN_00462250 — result: PASS
**Current doc:** docs/20-math-utilities.md (line 15523)
**Issues found:** none
**Details:**
- Overview line 147: "texture creation wrapper: allocate + init width/height/format"
- Entry line 15523: "Creates/manages texture object. Allocates texture structure, initializes texture properties (width, height, format), returns texture handle"
- Source (analyzed\0x00462250__FUN_00462250.c):
  - Extracts bits from *param_2 (texture flags/format)
  - Allocates via FUN_0057a680()
  - Conditionally sets parameter or calls vtable method
  - Calls FUN_0057a6a0() with texture params
  - Calls FUN_0057a690()
- The source is more complex than the doc suggests — involves D3D format negotiation and resource allocation through vtable
- Doc lacks specifics about the D3D/texture format bits extracted from param_2
- Overall description is adequate but lacks detail

---

### FUN_00487740 — result: ISSUE (minor)
**Current doc:** docs/20-math-utilities.md (line 15851)
**Issues found:** ["param_2" claim is inaccurate]
**Details:**
- Entry line 15851: "Checks value is in range (1, 4). Tests 1 < param_2 < 4. Returns boolean result."
- Source (analyzed\0x00487740__FUN_00487740.c):
  - Calls FUN_00486720() — which itself is a field getter at +0x84
  - Checks return value: (1 < result) && (result < 4)
- Doc claims param_2 is tested directly, but source shows it calls a getter first
- The function has NO parameters — it calls FUN_00486720() which reads a field internally
- MISMATCH: doc describes as "Tests 1 < param_2 < 4" but source has no param_2 — calls getter function

---

### FUN_004A0CF0 — result: PASS
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** none
**Details:**
- Triage: "math_util — short computation"
- Source (analyzed\0x004a0cf0__FUN_004a0cf0.c): if DAT_007ce254 == '\0': calls FUN_004a0250(), sets DAT_007ce258 = 0. Conditional initialization with global state check. Fits "short computation" loosely but has game state dependency.

---

### FUN_004CDB90 — result: ISSUE
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** [miscategorized as "unidentified"]
**Details:**
- Triage: "unknown — unidentified logic"
- Source (analyzed\0x004cdb90__FUN_004cdb90.c): struct zero-initialization constructor:
  - Zeroes param_1[0] through param_1[10] (mostly)
  - Sets param_1[1] = 0xffffffff, param_1[0xc] = 0xffffffff, param_1[0xd] = 0xffffffff, param_1[0xe] = 0xffffffff (sentinel -1 values)
  - Sets param_1[6] = 0x427b53d1 (float ~62.95 — magic constant)
  - Zeroes param_1[0x10] through param_1[0x17] (8 entries)
  - Zeroes param_1[0x19], param_1[0x1a]
- Clearly a constructor/initializer with specific defaults and sentinels
- Should be classified as "struct constructor / zero-init with sentinels"

---

### FUN_0050C85D — result: ISSUE
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** [category mismatch — delegation, not arithmetic]
**Details:**
- Triage: "math_util — arithmetic/comparison"
- Source (analyzed\0x0050c85d__FUN_0050c85d.c): calls FUN_0050fea7(1), then calls through PTR_FUN_005d789c (static function pointer). Pure delegation. No arithmetic or comparison. Should be reclassified as "delegation / callback dispatch."

---

### FUN_00566650 — result: PASS
**Current doc:** docs/20-math-utilities.md (line 17165)
**Issues found:** none
**Details:**
- Entry line 17165: "String Copy with Buffer Realloc — If dest buffer too small: reallocates. Copies string via strcpy. Returns dest."
- Source (analyzed\0x00566650__FUN_00566650.c): 94 bytes:
  - If param_2 == NULL: returns 0xffffffff
  - strlen-like loop on param_2
  - If *param_1 != 0 and strlen <= param_1[1]: goto copy (fast path)
  - Else: frees old buffer via FUN_00587bcf, allocates via operator_new
  - Copies string byte-by-byte (strcpy-like loop)
  - Returns 0
- Matches description. Note: the function returns 0 on success, not dest pointer as doc says. (Minor inaccuracy)

---

### FUN_0046A950 — result: PASS
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** none
**Details:**
- Triage: "math_util — short computation"
- Source (analyzed\0x0046a950__FUN_0046a950.c): destructor pattern: calls FUN_0046a970(), checks param_2 & 1, calls FUN_00587bcf(param_1) if set. Matches classification.

---

### FUN_0040E880 — result: PASS
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** none
**Details:**
- Triage: "math_util — short computation"
- Source (analyzed\0x0040e880__FUN_0040e880.c): sets param_1+8 = param_2 (short), param_1+0x1c = 7, param_1+0x20 = param_3, calls FUN_0040e770(). Field setter + init. Fits classification.

---

### FUN_004869E0 — result: ISSUE
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** [miscategorized as "unidentified"]
**Details:**
- Triage: "unknown — unidentified"
- Source (analyzed\0x004869e0__FUN_004869e0.c): recursive bounds-aware field accumulator:
  - Reads param_1[1], param_1[2], param_1[3], param_1[4] (dimension fields)
  - Computes min/max for param_2 and param_3 (new values)
  - Calls FUN_00499050() with adjusted dimensions
  - Updates all four fields with additions
  - Calls vtable+0x2c with arg 1
  - Recursively calls FUN_004869e0 on each linked node at param_1[0x24]
  - Calls vtable+0xa0
- This is a recursive tree traversal with bounds-aware dimensional accumulation
- Has vtable dispatch and recursive linked structure traversal
- Should be classified as "tree traversal / dimensional accumulation"

---

### FUN_0049ECA0 — result: PASS
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** none
**Details:**
- Triage: "math_util — short computation"
- Source (analyzed\0x0049eca0__FUN_0049eca0.c): if *(param_1+4) != 0: calls FUN_005539f0(*(param_1+4)), zeroes field. Conditional cleanup. Fits classification.

---

### FUN_004C9B80 — result: PASS
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** none
**Details:**
- Triage: "math_util — short computation"
- Source (analyzed\0x004c9b80__FUN_004c9b80.c): calls FUN_00587b3e(&LAB_004c9b90). Callback registration. Fits "short computation" but more precisely "callback registration."

---

### FUN_0050B879 — result: PASS
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** none
**Details:**
- Triage: "math_util — short computation"
- Source (analyzed\0x0050b879__FUN_0050b879.c): calls FUN_0050a7e1(param_2), sets *param_1 = &PTR_FUN_005ade1c. Constructor with init + vtable. Fits "short computation" broadly.

---

### FUN_00543230 — result: PASS
**Current doc:** docs/20-math-utilities.md (line 20180)
**Issues found:** none
**Details:**
- Entry line 20180: "Argument Reorder Wrapper — calls FUN_00540150 with reordered arguments (param_1, param_3, param_2)"
- Source (analyzed\0x00543230__FUN_00543230.c): calls FUN_00540150(param_1, param_3, param_2). Matches exactly.

---

### FUN_00599796 — result: PASS
**Current doc:** docs/20-math-utilities.md (line 20543)
**Issues found:** none
**Details:**
- Entry line 20543: "Empty Stub — bare return. Referenced as callback target."
- Source (analyzed\0x00599796__FUN_00599796.c): 1 byte — bare return. Matches exactly.

---

### FUN_00410890 — result: ISSUE (minor)
**Current doc:** docs/20-math-utilities.md (line 21063)
**Issues found:** [per-element claim inaccurate]
**Details:**
- Entry line 21063: "Iterates multiple arrays/segments of a structure, calling FUN_0040f130 on each element from varying start positions"
- Source (analyzed\0x00410890__FUN_00410890.c):
  - Zeroes field at +0x6c ✓
  - Segment 1 (+0x24): iterates i from 0 to count, calling FUN_0040f130() ✓
  - Segment 2 (+0x30): iterates i from 0 to count, calls FUN_0040f130() ✓
  - Segment 3 (+0x3c): iterates i from 0 to count, calls FUN_0040f130() ✓
  - Segment 4 (+0x48): starts at 0x1a0 if 0x1a0 < count, calls FUN_0040f130() ✓
  - Segment 5 (+0x54): starts at 0xd0 if 0xd0 < count, calls FUN_0040f130() ✓
  - Segment 6 (+0x60): starts at 0x340 if 0x340 < count, calls FUN_0040f130() ✓
- Doc claims "on each element" but FUN_0040f130() is called with NO arguments — just iterates counter. Not per-element — it's just a counter-based loop calling the same no-arg function.
- MINOR MISMATCH: doc implies element-specific processing but source shows simple count-based iteration with no element indexing

---

### FUN_0046FDF0 — result: ISSUE
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** [category mismatch — not pure math_util]
**Details:**
- Triage: "math_util — short computation"
- Source (analyzed\0x0046fdf0__FUN_0046fdf0.c):
  - Calls FUN_0048fec0() — unknown setup
  - Calls FUN_00490160(1)
  - Calls through DAT_007cd8c0 vtable at +0x1c (renderer context) with resource ID 0xc
  - If non-null: calls FUN_00477280(param_1)
- Contains renderer vtable dispatch and resource allocation
- Not pure math_util — should be classified as "renderer resource init"

---

### FUN_00491330 — result: PASS
**Current doc:** docs/20-math-utilities.md (line 21953)
**Issues found:** none
**Details:**
- Entry line 21953: "Short Array Zero-Init — Zeros 5 shorts and 1 int in a small struct"
- Source (analyzed\0x00491330__FUN_00491330.c): param_1[0]=0, [1]=0, [2]=0, [3]=0, *(param_1+6)=0 (int at offset 12), param_1[4]=0. Matches description.

---

### FUN_004B3CE0 — result: ISSUE
**Current doc:** docs/20-math-utilities.md (triage index)
**Issues found:** [category understated — bitcount + indexed table lookup, not simple arithmetic]
**Details:**
- Triage: "math_util — arithmetic/comparison"
- Source (analyzed\0x004b3ce0__FUN_004b3ce0.c):
  - Calls FUN_004b3c60() — random/entropy source
  - Counts bits (popcount) over 32 iterations: iVar5 += (iVar3 >> i & 1)
  - Reads param_1[(*param_1 & 0xff) + 0x101] — indexed float lookup table at param_1+0x101 entries
  - Increments param_1[0] — state update
  - Computes: (float_value * 0.5f + (popcount - 16.0)) * DAT_005accf8
- This is a non-uniform random number generator using bit-count distribution + lookup table
- More complex than "arithmetic/comparison" — involves entropy extraction, table lookup, and state mutation
- Should be classified as "random number generation / noise distribution"

---

### FUN_004E4910 — result: PASS
**Current doc:** docs/20-math-utilities.md (line 22780)
**Issues found:** none
**Details:**
- Entry line 22780: "Collision Wrapper with Lock — wraps FUN_00401c90 with acquire/release lock calls"
- Source (analyzed\0x004e4910__FUN_004e4910.c): FUN_004e8010(1), FUN_00401c90(param_1), FUN_004e8010(0). Matches exactly.

---

## Summary

| # | Function | Result | Issue Type |
|---|----------|--------|------------|
| 4051 | FUN_0058806E | PASS | — |
| 4052 | FUN_00587AC0 | PASS | — |
| 4053 | FUN_0059BE0C | ISSUE | miscategorized, misleading description (multi-byte decoder, not file read) |
| 4054 | FUN_0057ACB0 | ISSUE | incorrect description (node removal, not QueueUserAPC) |
| 4055 | FUN_00575882 | ISSUE | missing analysis (source dump only, 827 bytes) |
| 4056 | FUN_0058FFEC | ISSUE | missing analysis (source dump only, 516 bytes) |
| 4057 | FUN_00581B30 | ISSUE | missing analysis (source dump only, 231 bytes) |
| 4058 | FUN_0058FF65 | ISSUE | miscategorized (locale init, not unknown) |
| 4059 | FUN_00558CB0 | PASS | — |
| 4060 | FUN_0045CBF0 | ISSUE | missing description (vehicle physics threshold check) |
| 4061 | FUN_0050D748 | ISSUE | mislabeled (Rodrigues' rotation, not unidentified) |
| 4062 | FUN_005992D3 | PASS | — |
| 4063 | FUN_0041F180 | PASS | — |
| 4064 | FUN_004781A0 | ISSUE | miscategorized (renderer resource alloc, not math_util) |
| 4065 | FUN_004910D0 | ISSUE | miscategorized (linked list destructor, not unidentified) |
| 4066 | FUN_004B46F0 | ISSUE | miscategorized (linked list array destructor, not unidentified) |
| 4067 | FUN_004F8280 | ISSUE | miscategorized (color constant lookup, not unidentified) |
| 4068 | FUN_005355A0 | ISSUE | miscategorized (conditional game logic, not utility) |
| 4069 | FUN_00587880 | PASS | — |
| 4070 | FUN_00599D17 | PASS | — |
| 4071 | FUN_0045BDE0 | PASS | — |
| 4072 | FUN_00485540 | PASS | — |
| 4073 | FUN_004A1B20 | ISSUE | miscategorized (string concat, not arithmetic) |
| 4074 | FUN_004D4A30 | PASS | — |
| 4075 | FUN_00513C80 | ISSUE | miscategorized (alloc+zero-init, not unidentified) |
| 4076 | FUN_00561E20 | PASS | — |
| 4077 | FUN_00581AD0 | PASS | — |
| 4078 | FUN_00479DB0 | ISSUE | miscategorized (constructor, not short computation) |
| 4079 | FUN_004DAE80 | PASS | — |
| 4080 | FUN_00589D7D | PASS | — |
| 4081 | FUN_004053E0 | PASS | — |
| 4082 | FUN_00462250 | PASS | — |
| 4083 | FUN_00487740 | ISSUE | minor inaccuracy (claims param_2, but calls getter) |
| 4084 | FUN_004A0CF0 | PASS | — |
| 4085 | FUN_004CDB90 | ISSUE | miscategorized (constructor/init, not unidentified) |
| 4086 | FUN_0050C85D | ISSUE | miscategorized (delegation, not arithmetic) |
| 4087 | FUN_00566650 | PASS | — |
| 4088 | FUN_0046A950 | PASS | — |
| 4089 | FUN_0040E880 | PASS | — |
| 4090 | FUN_004869E0 | ISSUE | miscategorized (tree traversal/bounds accumulator, not unidentified) |
| 4091 | FUN_0049ECA0 | PASS | — |
| 4092 | FUN_004C9B80 | PASS | — |
| 4093 | FUN_0050B879 | PASS | — |
| 4094 | FUN_00543230 | PASS | — |
| 4095 | FUN_00599796 | PASS | — |
| 4096 | FUN_00410890 | ISSUE | minor inaccuracy (claims per-element, but no-arg calls) |
| 4097 | FUN_0046FDF0 | ISSUE | miscategorized (renderer resource, not math_util) |
| 4098 | FUN_00491330 | PASS | — |
| 4099 | FUN_004B3CE0 | ISSUE | understated (RNG/distribution, not simple arithmetic) |
| 4100 | FUN_004E4910 | PASS | — |

**Totals:** 22 PASS, 28 ISSUES (7 missing analysis, 13 miscategorized, 3 incorrect descriptions, 5 minor inaccuracies)
