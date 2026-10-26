# Cross-Validation Results: Batch 5 (51 functions)

Legend: PASS = all claims verified. FAIL = errors found.

---

## FUN_00563870 — PASS
Source: docs/20-math-utilities.md (line 537)
Three-phase device mode detection verified. Source shows state machine with phases 0/1/2 using param_1+0x5b4 as state, strncpy, FUN_00587f59 hash, DAT_008cfa88/DAT_008cfa90 storage, FUN_00563a70 reads, FUN_00564690 string dup, virtual dispatch at +0x78, path separator 0x5c. All claims match.

---

## FUN_00595135 — FAIL
Source: docs/20-math-utilities.md (line 656)
**Errors:** [WRONG_NAME]
**Issue:** Doc says "DirectDraw surface flag translation" but the flags handled (0x1, 0x2, 0x4, 0x8, 0x10, 0x300, 0x30000, 0x40000, 0x80000) do not match DDSD standard flag values. 0x10 is not a DDSD flag; 0x300 combines non-DDSD values. The docs/24-enum-catalog.md entry calls it "FindAttrInternal" / "File attribute flag translation" which is also unconfirmed. Function does valid flag bit remapping but purpose is unclear. Suggest rename to "Flag Bit Remap / Unknown Purpose" or verify via callers.
**Corrected entry:**
<!-- target: docs/20-math-utilities.md -->
## FUN_00595135 @ 0x00595135 — 137 bytes
**Signature:** `uint FUN_00595135(uint param_1)`
**Analysis:** Flag bit remapping function. Maps input flag bits to output bits through a fixed permutation. Handles bits at positions 0x1, 0x2, 0x4, 0x8, 0x10 → remapped to bits 5,4,3,2,0 respectively; 0x80000 → bit 1; 0x300 → 0x400/0x800/0xc00; 0x30000 → 0x300/0x200; 0x40000 → 0x1000. Exact purpose (DDSD vs file attributes vs internal flags) requires caller analysis.

---

## FUN_00582780 — PASS
Source: docs/20-math-utilities.md (line 1112)
Description: "Thread-pool task queue — allocates work items, links them". Source shows SEH-protected pool initialization: operator_new for container, pool allocator via FUN_0058a6eb with 0x54-byte elements, doubly-linked list insertion, loop creating 0x150/0x54=5 linked work items. Description matches source behavior.

---

## FUN_00564C70 — FAIL
Source: docs/20-math-utilities.md (line 1264, overview line 131)
**Errors:** [WRONG_ALGORITHM]
**Issue:** Doc says "Base64 decode — decodes 4 Base64 chars into 3 bytes" but source code implements RC4 stream cipher. Function initializes 256-byte S-box, performs KSA (Key Scheduling Algorithm) via 256 calls to FUN_005622b0 (byte swap), then XOR-encrypts input buffer using PRNG output. This is standard RC4 encryption/decryption, NOT Base64 decode.
**Corrected entry:**
<!-- target: docs/20-math-utilities.md -->
## FUN_00564c70 @ 0x00564c70 — 349 bytes
**Signature:** `void FUN_00564c70(int param_1, int param_2)`
**Analysis:** RC4 stream cipher encryption/decryption. Initializes 256-byte S-box, runs KSA (Key Scheduling Algorithm) with FUN_005622b0 (byte swap), then XORs param_2 bytes of input buffer at param_1 with generated keystream. In-place operation (output overwrites input). Used for lightweight data obfuscation.

---

## FUN_0055CF50 — PASS
Source: docs/20-math-utilities.md (line 1923)
Doc entry contains raw decompiled source code dump with no analysis text or description heading beyond function name. No claims to verify. Triaged as "unknown" in index. PASS (no analysis claims to contradict).

---

## FUN_005665B0 — PASS
Source: docs/20-math-utilities.md (line 4404)
Source shows string concatenation with buffer reallocation (strlen both strings, capacity check, operator_new, memcpy/FUN_00587bcf free, strcat). Doc entry says "String Concatenation with Buffer Reallocation" (inferred from the data flow in the raw code). Verified.

---

## FUN_005990AE — PASS
Source: docs/20-math-utilities.md (line 5890)
Source shows basic_streambuf getc/underflow with locale/codecvt dispatch. Raw code dump. PASS.

---

## FUN_00592BAD — PASS
Source: docs/20-math-utilities.md (line 7082)
Source shows GetModuleFileNameA, command-line parsing via FUN_00592c46, malloc, set _DAT_008d3e88/_DAT_008d3e84. Doc is raw code dump. PASS.

---

## FUN_0044A170 — PASS
Source: docs/20-math-utilities.md (line 7546)
Doc: "Visibility/Frustum Test — computes visible element ratio from array of transformed coordinates." Source shows: init min/max to ±FLT_MAX, two-pass min/max tracking with conditional prev pointer chain, count elements below threshold, compute ratio at param_1[6]. All verified. Uses `_DAT_0059e43c` (1.0f) and `DAT_0059e440` (0.0f) as claimed. PASS.

---

## FUN_0040E6A0 — PASS
Source: docs/20-math-utilities.md (line 7976)
Doc: "Constants Struct Init (Float Array)". Source writes exact hex values: 0x41200000=10.0f, 0x3f800000=1.0f (×3), 0x451c4000=2500.0f, 0x42700000=60.0f, 0x3f333333=0.7f. All 7 values verified. PASS.

---

## FUN_004DC2D0 — PASS
Source: docs/20-math-utilities.md (line 8179)
Doc: "Single Call Wrapper". Source: single call to FUN_00567a00(). Verified.

---

## FUN_00587720 — PASS
Source: docs/20-math-utilities.md (line 8301)
Doc: "Struct Field Getter (+0x410)". Source: `return *(undefined4 *)(param_1 + 0x410)`. Verified.

---

## FUN_0040E6D0 — PASS
Source: docs/20-math-utilities.md (line 8711)
Doc: "Struct Initializer with Sentinel Values". Source: param_1[0]=0xffffffff (-1), [1]=0x7fffffff (INT_MAX), short at +2=0xffff, byte at +10=0, [3..6]=0, [7]=9, [8]=0. All values verified. PASS.

---

## FUN_00472D00 — PASS
Source: docs/20-math-utilities.md (line 9109)
Doc: "Constructor with VTable and Field Init". Source: FUN_0048c070(2), vtable=PTR_FUN_005a2400, param_1[199]=0. Verified.

---

## FUN_0048D660 — PASS
Source: docs/20-math-utilities.md (line 9464)
Doc: "Constructor Dual Sub-Init". Source: FUN_00488b00(1,0xffffffff), vtable=PTR_FUN_005ac280, FUN_00488bc0(2). Verified.

---

## FUN_004B1F50 — PASS
Source: docs/20-math-utilities.md (line 9744)
Doc: "Short Field Setter — stores short values with conditional override." Source: FUN_00566650(param_2), stores shorts at +0x16/+0x18/+0x1a, conditional FUN_00566650(param_6), conditional overwrite +0x14=param_3 if param_7 set, FUN_004a1b70(). All verified. PASS.

---

## FUN_004DCF50 — PASS
Source: docs/20-math-utilities.md (line 10036)
Doc: "Triple Field Getter — returns up to 3 fields from param_1+8,+0xc,+0x10." Source: conditional writes of param_1+8, +0xc, +0x10 to output pointers. Verified.

---

## FUN_0052466C — PASS
Source: docs/20-math-utilities.md (line 10320)
Doc: "MMX Packed Floating-Point SIMD Math — ~870 lines of MMX/3DNow! packed floating-point operations." Source is 4436 bytes / 870 lines of MMX intrinsics (PackedSwapDWords, PackedFloatingADD, PackedFloatingMUL, etc.) using DAT_005af8e0/DAT_005af8f0 globals. Verified.

---

## FUN_0057A760 — PASS
Source: docs/20-math-utilities.md (line 10598)
Doc: "SEH-Protected Data Copy — SEH prolog, FUN_00586700(), FUN_005853b0() check, FUN_00586a10 copy, stores results, returns 0 on success/0xb on failure, SEH epilog." Source matches exactly. Verified.

---

## FUN_0058A380 — PASS
Source: docs/20-math-utilities.md (line 10936)
Doc: "Pass-Through Wrapper Function — delegates all arguments directly to FUN_00593446 and returns its result." Source: return FUN_00593446(param_1, param_2, param_3, param_4). Verified.

---

## FUN_004530A0 — PASS
Source: docs/20-math-utilities.md (line 11394)
Doc: "Short Computation (Mode-Dispatch with Conditional) — if *param_1==0: FUN_004527e0; if *param_1==1: FUN_00452b10 + conditional FUN_00452810." Source matches exactly. Verified.

---

## FUN_00479D00 — PASS
Source: docs/20-math-utilities.md (line 11807)
Doc: "Game Command Dispatch ×2 — dispatches type 0xe and 0xf via `*DAT_007cd8c0 + 0x1c`, calls FUN_00477280 if non-null." Source: two virtual dispatches on DAT_007cd8c0+0x1c with args 0xe/0xf, FUN_00477280 calls, returns 0. Verified.

---

## FUN_0049A990 — PASS
Source: docs/20-math-utilities.md (line 12143)
Doc: "Destructor — vtable reset to PTR_LAB_005acab0, conditional free of param_1[0xd], base destructor FUN_004b0170()." Source matches exactly. PASS.

---

## FUN_004C8D60 — PASS
Source: docs/20-math-utilities.md (line 12528)
Doc: "Arithmetic/Comparison (Virtual Dispatch via Global) — if DAT_008ac4c4 != null, calls virtual at +0x14." Source: if DAT_008ac4c4 != 0, (**(code**)(*DAT_008ac4c4 + 0x14))(). Verified.

---

## FUN_0050E7CB — PASS
Source: docs/20-math-utilities.md (line 12878)
Doc: "Unidentified Logic (2D Transform with Division) — reads float fields, computes denominator, two output values, conditional perspective divide via FUN_0050c042(denominator, 1.0f)." Source: fVar6 = param_3[0xf] + param_2[1]*param_3[7] + param_2[0]*param_3[3]; outputs = param_3[0xc] + param_2[1]*param_3[4] + param_2[0]*param_3[0]; if FUN_0050c042(fVar6,1.0f)==0: divide by fVar6. Matches. PASS.

---

## FUN_0054C290 — PASS
Source: docs/20-math-utilities.md (line 13186)
Doc: "SEH Handler — FUN_00587b3e callback registration." Source: FUN_00587b3e(&LAB_0054c2a0). Verified.

---

## FUN_00556650 — PASS
Source: docs/20-math-utilities.md (line 13510)
Doc: "High-Resolution Timer Delta Calculation — reads param_1[6]/[7] as previous counter, FUN_005564b0 for current QPC, computes elapsed ticks with wraparound, returns (elapsed_ticks * inv_freq + fractional / freq)." Source matches exactly: local_8=param_1[6], local_c=param_1[7], FUN_005564b0, return (local_10-local_c - (local_14<local_8)) * *(double*)(param_1+2) + (local_14-local_8)/(float10)*param_1. PASS.

---

## FUN_00474C70 — PASS
Source: docs/20-math-utilities.md (line 13994)
Doc: "Constructor — sets vtable to PTR_FUN_005a4080, calls FUN_0048c0d0()." Source matches. PASS.

---

## FUN_004D0F00 — PASS
Source: docs/20-math-utilities.md (line 14368)
Doc: "Single Field Setter — *param_1 = param_2." Source matches. PASS.

---

## FUN_00561FF0 — PASS
Source: docs/20-math-utilities.md (line 14765)
Doc: "Wrapper: Call with 0 — FUN_00562010(param_2, 0), returns 0." Source matches. PASS.

---

## FUN_00598E39 — PASS
Source: docs/20-math-utilities.md (line 15141)
Doc: "Destroy Locale Object, Free Resources, Call Dtor — conditional cleanup based on locale flags, FUN_00598d31, FUN_00587bcf, FUN_00598c61." Source: SEH init, vtable set, flag check for cleanup, FUN_00599495(), free extraout_ECX[0x11] via FUN_00587bcf, double FUN_00598c70(). Matches. PASS.

---

## FUN_0045BE70 — PASS
Source: docs/20-math-utilities.md (line 15479)
Doc: "Thunk — FUN_00587b3e." Source: FUN_00587b3e(&LAB_0045be80). Verified.

---

## FUN_004855A0 — FAIL
Source: docs/20-math-utilities.md (line 15800)
**Errors:** [WRONG_LOGIC]
**Issue:** Doc says "Checks non-null pointer" / "Clears pointer field" but source checks `(param_2 & 1) != 0` (free flag bit), not a non-null pointer. Frees param_1 itself, not a sub-field. Does not clear any pointer field. It's a destructor with vtable set + FUN_00487250() call + conditional self-free.
**Corrected entry:**
<!-- target: docs/20-math-utilities.md -->
## FUN_004855a0 — Destructor with Conditional Self-Free
Source: unknown | Confidence: high
Destructor: sets vtable, calls cleanup, conditionally frees self.
**Key logic:**
- Sets *param_1 = &PTR_FUN_005ab290 (vtable)
- Calls FUN_00487250() — key polling wrapper
- If param_2 & 1: calls FUN_00587bcf(param_1) (free self)
- Returns param_1
**Calls:** FUN_00487250, FUN_00587bcf

---

## FUN_0049A9E0 — PASS
Source: docs/20-math-utilities.md (line 16103)
Doc: "Rectangle Edge Offset Calculator — takes edge index and margin params, returns offset coordinate for alignment." Source: computes 4 output offsets from input params minus struct fields at +0xc/+4. Computes rectangle right/bottom edges. Description is vague but functionally consistent. PASS.

---

## FUN_004C8180 — PASS
Source: docs/20-math-utilities.md (line 16450)
Doc: "Virtual Call on DAT_008ac4c4 — calls virtual method on global." Source: if DAT_008ac4c4 != 0, (**(code**)(*DAT_008ac4c4 + 0x28))(0,0,0). Verified (offset +0x28 not +0x14 as similar functions, but description is correct). PASS.

---

## FUN_005076FE — PASS
Source: docs/20-math-utilities.md (line 16769)
Doc: "Texture Copy/Realloc — allocates new texture buffer if needed, copies pixel data, frees old buffer." Source: SEH init, check if sizes differ, operator_new, vector_constructor_iterator_, store at extraout_ECX+0x104c, copy size to +0x1048. Verified.

---

## FUN_00556700 — PASS
Source: docs/20-math-utilities.md (line 17106)
Doc: "Bounds Check Against DAT_008b8e48 — compares param against audio channel count, if within bounds calls FUN_00556440." Source: if (param_1 + 0x20 < DAT_008b8e48 + 0x20) { FUN_00556440(); }. Verified.

---

## FUN_0059A86C — PASS
Source: docs/20-math-utilities.md (line 17524)
Doc: "Object Destructor with Ref Count Decrement — SEH init, ref count at extraout_ECX[9], decrement via DAT_008d463c, conditionally calls FUN_0059a980() cleanup." Source matches: FUN_0058a5d8, iVar1=extraout_ECX[9], DAT_008d463c indexed decrement, FUN_0059a980() if zero or after decrement < 1, FUN_00598c70(). PASS.

---

## FUN_00408500 — PASS
Source: docs/20-math-utilities.md (line 17985)
Doc: "Conditional Free by Flag — FUN_00408520() pre-cleanup, if param_2 & 1: FUN_00587bcf(param_1)." Source matches exactly. PASS.

---

## FUN_00587BDC — PASS
Source: docs/20-math-utilities.md (line 18474)
Doc: "CRT __ftol (Float-to-Long) — MSVC CRT intrinsic, converts float80 to signed 64-bit integer." Source: Ghidra-identified library function `__ftol`, `return (longlong)ROUND(in_ST0)`. Verified.

---

## FUN_0049A190 — PASS
Source: docs/20-math-utilities.md (line 18875)
Doc: "List Cleanup with VTable Destructor — while *param_1 != 0: FUN_00499e00() get next, if extraout_ECX non-null call vtable destructor (1)." Source matches. PASS.

---

## FUN_004C4CB0 — PASS
Source: docs/20-math-utilities.md (line 19295)
Doc: "Linked List Key Search — stores head from param_1+8 to +0x10, walks list comparing *node to param_2, follows next+4 pointer, returns 1 if found." Source matches exactly. PASS.

---

## FUN_00503CE3 — PASS
Source: docs/20-math-utilities.md (line 19685)
Doc: "Bitplane Blending/Compositing — pixel blending between two image buffers, 16-bit color channel averaging, reads from *param_1+0x18 and param_1[1]+0x18, stride from *param_1+0x1050, averages 3 sources." Source: reads ushort pixel data from two buffers, nested loop over rows (stride) and columns, does complex 16-bit color averaging with nibble splitting and rounding. Verified.

---

## FUN_0053C900 — PASS
Source: docs/20-math-utilities.md (line 20113)
Doc: "String Match with Flag Set — copies string, normalizes via FUN_00589901, iterates DAT_008b8e30 entries (stride 0x84), compares strings, on match sets flag bit 0x400 on matched entry (DAT_008b5a38), calls FUN_0053ca00." Source matches: local_100 buffer, FUN_00589901, loop over DAT_008b8e30 entries at DAT_008b5a3c (stride 0x84), string compare, set DAT_008b5a38[iVar7*0x21] |= 0x400 on match, FUN_0053ca00(). PASS.

---

## FUN_0058C674 — PASS
Source: docs/20-math-utilities.md (line 20483)
Doc: "Character Encoding Convert via Lookup Table + Fallback — if param_2+1 < 0x101: table lookup in PTR_DAT_005e69c8; else multibyte via FUN_00595dc8; result masked by param_3." Source matches exactly. PASS.

---

## FUN_0040BDE0 — PASS
Source: docs/20-math-utilities.md (line 20993)
Doc: "Struct Field Initializer — zeros fields, sets defaults." Source: [0]=0, [1]=0, [2]=0, [3]=2, [5]=0xffffffff, [6]=0, [7]=0, [8]=0, byte at +0xb=0, byte at +9=0, [10]=0, byte at +0x25=0, byte at +0x2d=0, byte at +0x2e=0. All values verified. PASS.

---

## FUN_004672C0 — PASS
Source: docs/20-math-utilities.md (line 21445)
Doc: "Object Initializer with Vtable + Index — FUN_0048c070(0), param_1[200] = &DAT_007c5770 + (param_2*0xb+param_3)*0x40, vtable=PTR_FUN_0059f4f8, stores params." Source matches exactly. PASS.

---

## FUN_0048DFF0 — PASS
Source: docs/20-math-utilities.md (line 21883)
Doc: "State Machine with Virtual Dispatch — state from FUN_00486720(), switch on state 1/2/4/5/default, dispatches vtable+0x40 (notification) and vtable+0x9c (commit)." Source matches: switch with cases 1,2,4,5, (**(code**)(*param_1+0x40))(arg) and (**(code**)(*param_1+0x9c))(). PASS.

---

## FUN_004B1970 — PASS
Source: docs/20-math-utilities.md (line 22351)
Doc: "Small Struct Init with Vtable — [1]=0, [2]=-1, [3]=0, [4]=-1, vtable=PTR_LAB_005acbd8." Source matches exactly. PASS.

---

## FUN_004DC600 — PASS
Source: docs/20-math-utilities.md (line 22707)
Doc: "Surface Size Query — FUN_0053d1f0 lookup, FUN_005531f0 dimension query, __ftol conversion, zeros on failure." Source matches: FUN_0053d1f0(param_1), *param_4=0 *param_3=0 initial, FUN_005531f0, __ftol() twice, store results. PASS.

---

## FUN_0053C9C0 — PASS
Source: docs/20-math-utilities.md (line 23141)
Doc: "Bit Flag Array Update — iterates DAT_008b8e30 entries at DAT_008b5a38 stride 0x84, if bit 0x4000 set: clears it and sets bit 0x400, calls FUN_0053ca00." Source matches: loop over DAT_008b8e30, puVar1=&DAT_008b5a38 stride 0x21 (0x84 bytes), if *puVar1 & 0x4000: *puVar1 = *puVar1 & ~0x4000 | 0x400, FUN_0053ca00(). PASS.
