# .text Gap Analysis

*Merged from 20 worker(s) on 2026-07-15.*

**Total gaps classified: 824**


## Summary by Category

| Category | Count |
|----------|-------|
| missed_function | 482 |
| jump_table_data | 171 |
| mixed | 115 |
| padding | 37 |
| data_table | 14 |
| exception_handler | 2 |
| unknown | 2 |
| string_data | 1 |

## Full Classification Table

| Start | End | Size | Classification | Confidence | Description |
|-------|-----|------|----------------|------------|-------------|
| 0x00401061 | 0x00401180 | 287 | mixed | medium | Function epilogue (loop+call ebx), then thunk wrappers (call+jmp), then thunk referencing 0x005ea2c0 (near TrackRefSpeed), then padding, then CRT init thunk |
| 0x0040821a | 0x00408230 | 22 | missed_function | medium | CRT global-register thunk: padding, push addr, call __Init, pop ecx, ret, padding |
| 0x0040bfc1 | 0x0040c070 | 175 | jump_table_data | high | Address table for Keyboard Input Action Mapper (prev func). 8+ target addrs in 0x0040be-0x0040bf range, followed by flag bytes (0x00/0x01/0x07 pattern) |
| 0x0040f35e | 0x0040f380 | 34 | jump_table_data | high | Address table for Mode-Dispatched Render/Physics Call (prev func). 7 addrs in 0x0040f3xx range, ending with 4-byte padding |
| 0x004155c8 | 0x00415650 | 136 | missed_function | medium | Valid function prologue (push ebx, push ebp, mov ebp,[esp+0xC]...) at offset+9. First 9 bytes unusual (LES+RETN) may be data or alternate entry. Linked list traversal between two linked list functions |
| 0x0041ff05 | 0x00420000 | 251 | missed_function | high | Valid MSVC function at offset+6. sub esp,0x50 push regs, mov ecx,0x007d2db0 (session/struct global). Also contains small epilogue+return0 stub at offset+0. Between ConfigSectionSearch and trampoline |
| 0x0042dbea | 0x0042dc60 | 118 | mixed | medium | 6 bytes padding + CRT thunk (push addr, call __Init) + 4 bytes padding + function referencing 0x007c7030 and 0x007c5728 (near SessionType/PlayerVehiclePtr) |
| 0x00448d80 | 0x00448da0 | 32 | jump_table_data | high | 6-entry address table: 0x00448913/2b/3b/53/63/7b for collision subroutines. Between Shadow Volume Extrusion and CollisionTreeTraversal |
| 0x0044c8e9 | 0x0044c900 | 23 | missed_function | medium | CRT global-register thunk: 7-byte padding, push addr, call __Init, pop ecx, ret, 4-byte padding |
| 0x0044cca9 | 0x0044ccc0 | 23 | missed_function | medium | CRT global-register thunk: 7-byte padding, push addr, call __Init, pop ecx, ret, 4-byte padding |
| 0x0044d069 | 0x0044d080 | 23 | missed_function | medium | CRT global-register thunk: 7-byte padding, push addr, call __Init, pop ecx, ret, 4-byte padding |
| 0x0044d426 | 0x0044d440 | 26 | missed_function | medium | CRT global-register thunk: 10-byte padding, push addr, call __Init, pop ecx, ret, 4-byte padding |
| 0x004562b5 | 0x004562f0 | 59 | missed_function | medium | First 9 bytes may be data offset. Then clear thiscall function: push esi, mov esi,ecx, sets vtable 0x0059efcc, checks and frees field at +0x04. Constructor+destructor pattern |
| 0x0045e4ed | 0x0045e570 | 131 | jump_table_data | high | 3-byte NOP (lea ecx,[ecx+0]) + ~12-entry address table in 0x0045d8-0x0045e4 range for NetComm Session Message Dispatcher (prev func) |
| 0x0046697c | 0x004669a0 | 36 | missed_function | high | 4-byte padding + thiscall constructor: mov eax,[esp+8], push esi, mov esi,ecx, sets vtable 0x0059f2c8, returns this+ret 8. Between Setup Value Display Formatters |
| 0x0046aef9 | 0x0046b070 | 375 | missed_function | high | Epilogue ending prev func, then valid thiscall function. Calls import at [0x0059e028] (indirect), reads DAT_007d1424. 375 bytes substantial function. Between session cleanup and timing check |
| 0x00472cf5 | 0x004735b0 | 2235 | missed_function | high | Large function. Starts with thunk call then thiscall constructor: sets vtable 0x005a2400, inits field at +0x31C to 0. 2235 bytes — major UI constructor between UI String Format and UI Counter Display |
| 0x004795db | 0x00479600 | 37 | mixed | medium | ASCII string "MYTH\0" (class/debug name?) at start, followed by thiscall constructor setting vtable 0x005a4ad8. Between File Path Resolver and Value Bar Display |
| 0x0047fc54 | 0x004857e0 | 23436 | data_table | medium | Massive 23KB region with no xrefs into it. Neither Ghidra nor IDA found function boundaries. Hex head shows unusual instruction mix — likely embedded data table (precomputed lookup/physics data) with potential missed function fragments. Requires deeper analysis |
| 0x00488fa9 | 0x004893c0 | 1047 | missed_function | high | First 6 bytes data/offset, then epilogue (pop esi, ret 0x10), then thiscall function setting vtable 0x005abcd0. 1047 bytes — substantial constructor between vtable-setter and Options Screen Init |
| 0x0048e0a5 | 0x0048e0d0 | 43 | missed_function | high | Two segments: (1) virtual call [eax+0x40] + cleanup epilogue (destructor pattern). (2) thiscall body with conditional cleanup. Between constructor and UI destructor |
| 0x00494617 | 0x00494630 | 25 | missed_function | medium | CRT global-register thunk: 9-byte padding, push 0x00494630, call __Init, pop ecx, ret, 4-byte padding |
| 0x0049a8fe | 0x0049a930 | 50 | jump_table_data | high | 2-byte NOP (mov edi,edi) + 12-entry address table. Entries: 0x0049a5ea/ef/0x9a672/dd/0x9a748/af/0x9a816/8f8/968... Note 0x0049a8f8 targets within this gap — jump table for prev func (Dual Conditional Free) |
| 0x0049ffa1 | 0x004a0030 | 143 | mixed | medium | Function epilogue (push 0, mov edi,ecx, call, pop regs, ret), then thunk pattern (call+jmp), padding, thunk referencing 0x007ce24d, padding, CRT init thunk. Between Merge Sort and Monitor Page Display |
| 0x004aa248 | 0x004aa270 | 40 | jump_table_data | high | 7-entry address table: 0x004aa1f2/f9/0x4aa200/07/0e/15/1c. Between Free Two Pointers and Player Options Initializer |
| 0x004b45d8 | 0x004b46b0 | 216 | mixed | medium | 8-byte padding + CRT thunk + 4-byte padding + function reading globals 0x008ab6e0 and 0x008ab700 (scoring/race region). Between Memory Pool Init and Struct Zero-Init |
| 0x004bc984 | 0x004bc9b0 | 44 | jump_table_data | high | 7-entry address table: 0x004bc84a, 0x004bc72e (repeated 5x — shared handler!), 0x004bc623. State machine jump table for penalty processing (prev: Lap Completion/Penalty, next: Jumped Start/Grid Penalty) |
| 0x004c7c7a | 0x004c7ca0 | 38 | mixed | medium | 6-byte padding + CRT thunk + padding + jmp-based thunk referencing 0x008ac494 (SceneArray near SceneFileCount). Between Passthrough and Network Message Receive/Dispatch |
| 0x004d3cd4 | 0x004d3cf0 | 28 | jump_table_data | high | 5-entry address table: 0x004d3c69/6d/71/7d/71 (repeat). Padding after. Between TrackTemperatureDisplay and Steward Update Main Dispatch |
| 0x004d9ed1 | 0x004da820 | 2383 | missed_function | high | 2383 bytes — very large function. Uses MessageBuffer (0x005ec4cc, UI global) and another string arg. Valid MSVC prologue at offset+8 (sub esp,0x80, push regs). Between Timer Display Render and State Block Initializer |
| 0x004e7f37 | 0x004e8010 | 217 | missed_function | high | Physics/vehicle struct manipulation. Uses offsets +0x1078, +0x3ab8, +0x3968 (large vehicle struct fields). Stores float via fstp. Struct field copy pattern (3 fields). Between Wheel Contact Force and Tire Brush Model Solver |
| 0x004fb9ef | 0x004fba10 | 33 | jump_table_data | high | Single-byte NOP + 8-entry address table: 0x004fb928/3a/48/56/68/7a/8c/96. Between Callback Registration and Camera/Viewport Render Setup |
| 0x0051f88b | 0x0051f89e | 19 | missed_function | high | Stack alignment prologue function. lea esi,[esi+eiz+0] (5-byte NOP), push ebx, mov ebx,esp, sub esp,8, and esp,0xFFFFFFF0, jmp to real function. MSVC CRT helper for 16-byte aligned math calls. Between Det3x3From4x4 and PlaneFromThreePoints |
| 0x005261ea | 0x005262c2 | 216 | missed_function | high | 3DNow!/MMX SIMD math function. Starts with femms, then movq/punpckldq/punpckhdq/movd etc. 216 bytes of SIMD vector math. Between 3DNow! 4×4 Matrix Multiply and SSE/3DNow! Vector Normalize |
| 0x0052e567 | 0x0052e577 | 16 | missed_function | medium | Two tiny function wrappers: (1) call+0xB, mov eax,esi, pop esi, ret. (2) jmp+0xB, 2-byte padding. Between Bounds-Checked Byte Setter and BufferInitZero |
| 0x0053d729 | 0x0053d750 | 39 | missed_function | high | First 7 bytes: add esp,4, xor eax,eax, pop esi, ret (previous func's tail). Then thiscall function: lea esi,[ecx+0x1398], loop over 8 elements with stride -0x44. Vehicle/physics struct stride. Between DirectX Device Init and Object Release |
| 0x00551e94 | 0x00551eb0 | 28 | jump_table_data | high | 4-entry address table: 0x00551e18/1f/26/2d, then 12-byte padding. Between Bink Video Frame Decoder and next function |
| 0x00561dff | 0x00561e30 | 49 | missed_function | high | Single-byte NOP + thiscall function: test esi,esi, if null load from DAT_005e4dfc, call, then jump. Second entry also reads DAT_005e4dfc. Between function at 0x00561d40 and NetworkPacketReceive |
| 0x0057a927 | 0x0057a940 | 25 | missed_function | medium | 9-byte padding + thunk (call + jmp) + 6-byte padding. Between Single Function Call Wrapper and Thunk wrapper |
| 0x0057d376 | 0x0057d400 | 138 | jump_table_data | high | 2-byte NOP + ~12-entry address table: 0x0057d31c/58/3a/e4/44/12/30/62/50/26/4e/6c... Between function at 0x0057ca10 and Structured Memory Copy |
| 0x00585df3 | 0x00585e80 | 141 | mixed | medium | OR+DATA op at import 0x0059e1a4, jmp, thunk pattern, padding, thunk referencing 0x008d3e2d (physics state block), padding, CRT init thunk. Between QueueUserAPC and Index-to-Bitmask |
| 0x0058b59f | 0x0058b5d4 | 53 | missed_function | high | Standard MSVC prologue (push ebp, mov ebp,esp, sub esp,8). Calls import at [0x0059e1b8]. Writes result to physics state block: [0x008d3ec0] (eax) and [0x008d3ec4] (edx). Between function at 0x0058b4d4 and 0x0058b5d4 |
| 0x0059a50b | 0x0059a535 | 42 | missed_function | high | Test+set flag pattern for physics state block. Reads DAT_008d46b8 (test byte,1) and sets it if clear. Same pattern for DAT_008d5a64. Call to nearby function. Between Self-Referential Pointer Ring Init and atexit Delegation |
| 0x00404805 | 0x00404850 | 75 | missed_function | medium | Small function with cmp/jl branch, epilogue (5b 5f 5e c3), call (e8). Data dword 0x00000001 at start then standard function code. |
| 0x00405879 | 0x004058a0 | 39 | missed_function | medium | thiscall method (56 8b f1) after initial pop esi. Has calls, conditional branch (74), ret c2 04 00. |
| 0x0040620f | 0x00406250 | 65 | missed_function | high | Two thiscall methods packed. First: test byte [esp+4], push esi, mov esi ecx, set vtable (c7 06), call, ret. Second: standard thiscall prologue, call, conditional cleanup. |
| 0x00406b74 | 0x00406ba0 | 44 | missed_function | medium | thiscall method (56 8b f1) with vtable set, conditional cleanup call, ret c2 04 00. Initial stc/sbb junk bytes likely dead code. |
| 0x00406ff1 | 0x004070e0 | 239 | missed_function | high | Loop body followed by thiscall method (56 8b f1 at offset +8). Accesses [esi+0x48] field (85 c0 test). Contains sub-function call at +0x4c. |
| 0x00407405 | 0x00407520 | 283 | missed_function | high | Switch-dispatch function with multiple code paths. push/push/call pattern, then ret 0xc. Second entry: sub/jz/dec chain (switch dispatch). IAT calls (ff 15). Between Miles Sound allocator and linked list insert — likely Miles sound wrapper. |
| 0x00408200 | 0x00408210 | 16 | missed_function | medium | Small thunk: call forward 0xb bytes, jmp forward 0x16 bytes. MSVC small thunk pattern. |
| 0x004084ff | 0x00408520 | 33 | missed_function | high | thiscall method: nop, 56 8b f1, call (e8), test byte [esp+4], conditional call, ret 4. Clean standard pattern. |
| 0x004087da | 0x00408800 | 38 | jump_table_data | high | Array of 8 function pointers (0x00408759, 0x0040875e, ..., 0x0040878c) all within prev function Float-Keyed Field Selector range. Jump table for field selector switch cases. |
| 0x00409946 | 0x00409970 | 42 | mixed | medium | Three zero-pad bytes (00 00 00) then prev function epilogue fragment (5b 83 c4 1c c2 08 00), then new function loading global DAT_008afe64 with push 1, push 0x20, call. |
| 0x00409f51 | 0x0040a610 | 1727 | missed_function | high | LARGE function. jmp backwards at start (prev func tail), then proper prologue: sub esp,0x18, push ebx/esi, mov esi ecx. Reads DAT_007cc470, tests nonzero. Uses DAT_007d3013 byte check. Multiple branches. |
| 0x0040ac1a | 0x0040ac40 | 38 | missed_function | medium | Pop ebp (5d) then call (e8) from prev func tail, then new thiscall method (56 8b f1) with call, conditional test, ret 4. |
| 0x0040b57a | 0x0040b5a0 | 38 | missed_function | medium | Similar pattern: prev func tail (sub/call), then new thiscall method with conditional cleanup, ret 4. |
| 0x0040cdb9 | 0x0040cdd0 | 23 | jump_table_data | high | lea ecx,[ecx] alignment. 5 function pointers: 0x0040cd77, 0x0040cd82, 0x0040cd8d, 0x0040cd98, 0x0040cda3. All targets within prev function Session Phase Decode. |
| 0x0040d197 | 0x0040d1b0 | 25 | jump_table_data | high | nop then 5 function pointers: 0x0040d17f, 0x0040d11f, 0x0040d137, 0x0040d14f, 0x0040d167. All within prev function Game State Branch Dispatch. nop padding after. |
| 0x0040de4b | 0x0040de60 | 21 | mixed | medium | nop, 2 function pointers (0x0040de47, 0x0040de09 within prev Cinematic Event State Machine), then data table: 00 00 00 00 01 01 01 01 (four 0s, four 1s = boolean case flags), then nop padding. |
| 0x0040e1ca | 0x0040e1e0 | 22 | missed_function | medium | nop padding, push address of next function (0x0040e1e0), call, pop ecx, ret. Small thunk wrapper between two wrappers. |
| 0x0040ee9e | 0x0040eec0 | 34 | jump_table_data | high | mov edi,edi nop. 8 function pointers: 6x 0x0040ed31 (same address - default case), 0x0040edbf, 0x0040edea. All within prev function Spatial Distance Query. Switch table with default fallthrough case. |
| 0x0040f199 | 0x0040f1c0 | 39 | jump_table_data | high | lea ecx,[ecx] alignment. 6 function pointers: 3 unique (0x0040f142, 0x0040f148, 0x0040f14e) each repeated twice. All within prev function State-Dependent Update Dispatch. nop padding after. |
| 0x0040f481 | 0x0040f4b0 | 47 | jump_table_data | high | lea ecx,[ecx] alignment. 7 function pointers: 4x 0x0040f39a (default case), 0x0040f3bd, 0x0040f3f4, 0x0040f447. All within prev function Switch-Based State Handler. nop padding. |
| 0x0040fae4 | 0x0040fb30 | 76 | mixed | high | First 40 bytes: 6 function pointers (0x0040f666, 0x0040f68e, 0x0040f6b6, 0x0040f6da, 0x0040f6ff, 0x0040f724) within prev Camera Shake function. Then nop padding. Then thiscall method (56 8b f1) with multi-field zero-init (89 46 08, 10, 18, 20, 28 — 5 fields zeroed) — constructor fragment. |
| 0x004110fd | 0x00411120 | 35 | jump_table_data | high | lea ecx,[ecx] alignment. 6 function pointers: 0x00410f82, 0x00410fa8, 0x00410fbe, 0x00410fe1, 0x00410ffd, 0x00411020. All within prev function SceneNodeDecoder. nop padding. |
| 0x00411d42 | 0x00411db0 | 110 | mixed | high | mov edi,edi nop. 10 function pointers (0x00411c30, 0x00411d3b, 0x00411c75, ..., 0x00411c55, 0x00411d3b again) within prev Race Event Message Dispatcher. Then data bytes: 00 09 00 00 01 02... Jump table + associated data table. |
| 0x00412dc6 | 0x00412e50 | 138 | jump_table_data | high | mov edi,edi nop. 12+ function pointers: 0x00412d99, 0x00412d89, 0x00412d79, ..., 0x00412cf3, 0x00412ce0... All within prev function MapCollisionShapeToBoneIndex range. Large switch table for collision shape-to-bone mapping. |
| 0x004140e4 | 0x00414140 | 92 | jump_table_data | high | 23+ function pointers at regular stride: 0x00414028, 0x00414032, 0x0041403c, 0x00414046, 0x0041404d, 0x00414054... All within prev function Enum Value Translation (Resource IDs). Stride ~10 bytes between targets. |
| 0x0041505d | 0x00415090 | 51 | missed_function | high | 3 nops then thiscall zero-init: mov eax,ecx; xor ecx,ecx; writes 0 to [eax], [eax+4], [eax+8], ..., [eax+0x2c] (12 dwords). ret c3. Then prev func tail fragment (5f 88 5e 10 5e). Small struct 12-field zero-init constructor. |
| 0x00418a51 | 0x00418ac0 | 111 | missed_function | medium | Loop start (ba ff ff b0 01 = counter init 0x1b0ffff; add ecx,20; dec edx; jnz) — large memset/memcpy loop tail from prev function. Then thiscall method (56 8b f1): accesses [esi+0xaf4], calls vtable at [ecx+8], accesses [esi+0xaec] with bounds check. |
| 0x00418dc7 | 0x00418e50 | 137 | mixed | high | nop padding, then push-address-call-pop-ret wrapper (call to 0x00418de0 within gap). More nops. Then mov ecx, 0x005eb978; jmp forward 6. More nops. Then proper function prologue: 53 55 56 8b e9 (push ebx, ebp, esi; mov ebp, ecx) with call. 3-4 items packed together. |
| 0x0041ac39 | 0x0041ac50 | 23 | jump_table_data | high | lea ecx,[ecx] alignment. 4 function pointers: 0x0041abc3, 0x0041abd9, 0x0041abef, 0x0041ac05. All within prev function Pit State Slot Activation / Commentary. nop padding. |
| 0x0041b8f0 | 0x0041b910 | 32 | jump_table_data | high | 6 function pointers: 0x0041b499, 0x0041b8d0, 0x0041b681, 0x0041b827, 0x0041b8d0 (repeat), 0x0041b843. Within prev function Pit Selection State Machine range. nop padding. |
| 0x0041c53a | 0x0041d630 | 4342 | missed_function | HIGH | LARGE game-logic function. References DAT_007d0308 (RaceActiveFlag — known global). Full prologue: sub esp,0x2c, push ebx/esi, test RaceActiveFlag, conditional big jump (0f 84 a3 09). FPU math: fld [DAT_007cf3c8], fcomp [DAT_0059e440], fnstsw test. Multiple branches. Likely race logic/commentary function. |
| 0x0041f55b | 0x0041f5d0 | 117 | jump_table_data | high | nop. ~16 function pointers at 7-byte stride: 0x0041f38c, 0x0041f393, 0x0041f39a, ..., all within prev function Championship Points Accumulator. Large switch table for points calculation cases. |
| 0x00421200 | 0x004212e0 | 224 | jump_table_data | high | ~32 function pointers at 7-byte stride: 0x00420daf, 0x00420db6, 0x00420dbd, ..., all within prev function Position Change Detector. Large switch table. |
| 0x0042347e | 0x00423490 | 18 | missed_function | medium | nop nop, call +5, jmp +22, nop padding. Standard small thunk. |
| 0x004263e9 | 0x00426430 | 71 | missed_function | high | FPU math gap between Physics Gear/Shift Logic and AI Waypoint Steering. Contains FPU ops: fdivp (de d9), fcomp (df e0), fnstsw test (f6 c4 41), conditional loops. Loads global constants [DAT_0059e8cc]. Physics engine function (gear ratio or shift timing calculation). |
| 0x0042b8aa | 0x0042b8c0 | 22 | missed_function | medium | nop padding, push address, call, pop ecx, ret, nops. Standard wrapper/thunk. |
| 0x0042cde1 | 0x0042ce00 | 31 | missed_function | high | Small function: reads VehiclePtrArray (mov eax,[eax*4+0x007c54f0]) indexed by eax, stores result to DAT_007c54e0 (adjacent to PlayerVehiclePtr). Data byte prefix. Then call+jmp thunk. Vehicle array lookup utility. |
| 0x0042d1f4 | 0x0042d210 | 28 | jump_table_data | high | Function pointers: 0x0042d1cd (appears 3x), 0x0042d1f0, 0x0042d183. All within prev function PenaltyStateDefaultInit range. nop padding. |
| 0x0042ea97 | 0x0042ebc0 | 297 | missed_function | high | IAT call (ff 15 5c e0 59 00) at start. Full prologue: push ebx; mov ebx,[esp+8]; mov eax,ebx; imul eax,0xb; add eax,ebp; shl eax,6; mov esi,ecx. Accesses struct at [eax+esi+0xc4]. Array indexing with stride 0x40*0xb = 0x2c0. Between Track Config / Garage Auto-Setup and History Buffer Shift — likely garage/setup memory access. |
| 0x0043138a | 0x004313c0 | 54 | missed_function | high | Accesses large offsets: byte set at [ecx+0x19a4], byte set at [ecx], float store at [ecx+eax*4+0x1ca8]. These are vehicle struct offsets (LifetimeAvg/Var range ~0x1330+, tire/thermal model ~0x1900+ at vehicle struct offset 0x1ca8). call, ret 8. Vehicle thermal/tire field accessor. |
| 0x00431bca | 0x00431c00 | 54 | mixed | medium | nop padding, push-address-call-pop-ret wrapper (call to 0x00431be0), nops. Then mov ecx, 0x007c73e0; jmp forward 0x4e6 (tail call to PhysicsGlobalStateInit context). More nops. Then call+jmp thunk. Between PhysicsGlobalStateInit thunks. Padding + wrapper + jmp thunk. |
| 0x00432816 | 0x00432870 | 90 | missed_function | high | Array accessor with bounds check: mov ecx,[ecx]; push 0; call. Then mov eax,[ecx]; mov edx,[esp+4]; add eax,0x20; test edx,edx; jl. cmp edx,[eax+0xc]; jge (array length check). Loop over entries checking [eax+4], decrementing edx. Bounds-checked array lookup. |
| 0x00433fb5 | 0x00434000 | 75 | missed_function | medium | Prev func tail (5f 5e jmp back). Then proper function: push ebx; mov ebx,[esp+8]; push esi; push edi; mov esi,1; push esi; mov edi,ecx; push ebx; mov ecx, DAT_007c56c0; call. Checks return, then byte load from param and conditional. Between vehicle file validation and file load function. |
| 0x00438c9f | 0x00438cc0 | 33 | missed_function | high | thiscall init delegator: nop, push esi, mov esi ecx. Calls func. Then lea ecx,[esi+0x15ac]; call sub-init. lea ecx,[esi+0x1ec]; pop esi; jmp tail-call. Initializes two subobjects at offsets +0x15ac and +0x1ec of vehicle/dynamics struct. Between Dynamics Object Initialization and BrakeBiasSetup. |
| 0x00448431 | 0x00448480 | 79 | missed_function | high | Writes to DAT_008aae70 (RingBufferCounter — known AI global). Then float comparison function: compares two structs' fields at offset +4 (fld [ecx+4]; fcomp [edx+4]; fnstsw test; returns bool). Between AudioDSPStateUpdate and Weighted Average Interpolation — likely audio buffer or AI ring buffer update. |
| 0x0044a121 | 0x0044a170 | 79 | mixed | medium | iretd (cf) at start — byte-data or alignment artifact. Then call prev func tail. Epilogue (5f 5e 5b 8b e5 5d c2 04 00). Then float comparison function at offset +0xc: fld [ecx+0xc]; fcomp [edx+0xc]; returns bool. Same pattern as GAP 331 at different offset. Between QuadraticSurfaceCollisionTest and Visibility/Frustum Test — collision comparison template. |
| 0x0044c5ea | 0x0044c620 | 54 | missed_function | medium | nop padding, push-address-call-pop-ret wrapper, nops, mov ecx global; jmp tail-call, nops, call+jmp thunk. Between collision thunk and collision state init. Collision init wrapper/thunk cluster. |
| 0x0044c6a9 | 0x0044c6c0 | 23 | missed_function | low | nop padding, push address, call, pop ecx, ret, nops. Standard collision init atexit/thunk wrapper. |
| 0x0044c721 | 0x0044c740 | 31 | mixed | low | ret stub (c3), then call+jmp thunk (e8 0b e9 36), nop padding. Between collision registration functions. |
| 0x0044c7c9 | 0x0044c7e0 | 23 | missed_function | low | push-address-call-pop-ret wrapper. Collision init atexit registration. |
| 0x0044c850 | 0x0044c860 | 16 | missed_function | low | call+jmp thunk. Small standard pattern. |
| 0x0044c961 | 0x0044c980 | 31 | mixed | low | ret stub (c3), call+jmp thunk, nops. |
| 0x0044ca09 | 0x0044ca20 | 23 | missed_function | low | push-address-call-pop-ret wrapper. |
| 0x0044ca84 | 0x0044cab4 | 48 | missed_function | medium | Writes constants to globals: c7 05 48 d1 7c 00 66 00 00 00 (= writes 0x66 to DAT_007cd148, an int ID/value), c7 05 4c d1 7c 00 00 00 00 00 (= zeros DAT_007cd14c). Then ret. Collision global init function — sets module ID + zero-inits adjacent field. |
| 0x0044cb29 | 0x0044cb40 | 23 | missed_function | low | push-address-call-pop-ret wrapper. |
| 0x0044cba2 | 0x0044cbd4 | 50 | missed_function | medium | Writes globals: c7 05 88 d1 7c 00 69 00 00 00 (= writes 0x69 to DAT_007cd188), c7 05 8c d1 7c 00 00 00 00 00 (= zeros DAT_007cd18c). Collision module ID init + field zero. |
| 0x0044cc49 | 0x0044cc60 | 23 | missed_function | low | push-address-call-pop-ret wrapper. |
| 0x0044ccc1 | 0x0044ccf4 | 50 | missed_function | medium | Writes globals: c7 05 58 d1 7c 00 20 00 00 00 (= writes 0x20 to DAT_007cd158), c7 05 5c d1 7c 00 00 00 00 00 (= zeros DAT_007cd15c). Collision module ID init. |
| 0x0044cd69 | 0x0044cd80 | 23 | missed_function | low | push-address-call-pop-ret wrapper. |
| 0x0044cde1 | 0x0044ce14 | 50 | missed_function | medium | Writes globals: c7 05 38 a4 7c 00 23 00 00 00 (= writes 0x23 to DAT_007ca438), c7 05 3c a4 7c 00 00 00 00 00 (= zeros DAT_007ca43c). Collision module ID init. |
| 0x0044ce89 | 0x0044cea0 | 23 | missed_function | low | push-address-call-pop-ret wrapper. |
| 0x0044cf01 | 0x0044cf34 | 50 | missed_function | medium | Writes globals: c7 05 a8 a3 7c 00 26 00 00 00 (= writes 0x26 to DAT_007ca3a8), c7 05 ac a3 7c 00 00 00 00 00 (= zeros DAT_007ca3ac). Collision module ID init. |
| 0x0044cfa9 | 0x0044cfc0 | 23 | missed_function | low | push-address-call-pop-ret wrapper. |
| 0x0044d021 | 0x0044d054 | 50 | missed_function | medium | Writes globals: c7 05 d8 a3 7c 00 29 00 00 00 (= writes 0x29 to DAT_007ca3d8), c7 05 dc a3 7c 00 00 00 00 00 (= zeros DAT_007ca3dc). Collision module ID init. |
| 0x0044d0c9 | 0x0044d0e0 | 23 | missed_function | low | push-address-call-pop-ret wrapper. |
| 0x0044d150 | 0x0044d160 | 16 | missed_function | low | call+jmp thunk. |
| 0x0044d1e9 | 0x0044d200 | 23 | missed_function | low | push-address-call-pop-ret wrapper. |
| 0x0044d261 | 0x0044d280 | 31 | mixed | low | ret stub, call+jmp thunk, nops. |
| 0x0044d309 | 0x0044d320 | 23 | missed_function | low | push-address-call-pop-ret wrapper. |
| 0x0044d390 | 0x0044d3a0 | 16 | missed_function | low | call+jmp thunk. |
| 0x0044d4b0 | 0x0044d4c0 | 16 | missed_function | low | call+jmp thunk. |
| 0x0044d546 | 0x0044d560 | 26 | missed_function | low | nop padding, push-address-call-pop-ret wrapper. |
| 0x0044d5c1 | 0x0044ee10 | 6223 | missed_function | HIGH | VERY LARGE (6.2KB). Starts with collision init wrapper tail. Then collision global init: xor eax,eax; writes 0x13 to DAT_007ccc80, zeros DAT_007ccc84. Then likely continues with the full collision subsystem initialization chain (all 0x4cXX init wrappers in sequence) AND D3D window/surface creation code. Between Collision Init Registration and D3D Window/Surface Creation — likely contains the main collision init sequence + D3D device init. |
| 0x0044f7b6 | 0x0044f7d0 | 26 | jump_table_data | high | mov edi,edi nop. 4 function pointers: 0x0044f700, 0x0044f70d, 0x0044f71a, 0x0044f727. These point BEFORE the reported prev function start (0x0044f73c) — Ghidra function boundary may be misaligned. nop padding. |
| 0x00452666 | 0x004526c0 | 90 | jump_table_data | high | mov edi,edi nop. ~11 function pointers: 0x00451967 (x2), 0x004519cf, 0x004519c9 (x2), 0x00451977, 0x004519a9, 0x00451989, 0x004519b9, 0x00451999, 0x00451a61. All within prev function Driver Input Controller. Switch table for driver input dispatch. Non-pointer data at end. |
| 0x004551f1 | 0x00455258 | 103 | missed_function | high | Prev func tail (dec eax, mov al,1, pop esi, ret 0xc). Then proper prologue: mov ecx,[esp+4]; cmp ecx,0x80; mov eax, 0x005ea438 (LoadPath/directory). Subtraction logic for index calculation: sub ecx,0x80; shr by 0x58; conditional jumps. shl ecx,4; add ecx... Index/path table lookup using LoadPath. Between Vehicle Input Smoothing and Two-Way Dispatch by Index. |
| 0x00456a32 | 0x00456f60 | 1326 | missed_function | high | LARGE (1.3KB). FPU physics function. Reads DAT_0059ef8c and DAT_0059ef90 (gear ratio or physics globals). fld [DAT_0059ef8c]; cmp param,1; conditional FPU paths. Byte flag check + conditional code. Between Steering/input smoothing and Collision Coefficient Application. Physics/vehicle dynamics function. |
| 0x0045a833 | 0x0045a8e0 | 173 | missed_function | high | Prev func tail (call, pop edi, pop esi). Then proper prologue: sub esp,0xc; push esi; mov esi,ecx. Accesses [esi+0xd8] (velocity component) and [esi+0xe0] (angular velocity/other component). fld [esi+0xd8]; push 0; fstp [esp+8]; fld [esi+0xe0]; fstp [esp+0x10]. Then call. Vehicle physics position/velocity integration sub-function. |
| 0x0045b99d | 0x0045b9c0 | 35 | missed_function | high | Small loop: nops, push esi; xor esi,esi; mov [ecx+0x31c], esi (zero-init field at +0x31c). Loop: push esi; call; inc esi; cmp esi,8; jl (8 iterations). pop esi; ret. Between Collision Damage Decay Processor and a utility function — zeroes 8 entries of a damage/contact array at +0x31c. |
| 0x0045be6e | 0x0045bea0 | 50 | missed_function | medium | nop padding, push-address-call-pop-ret wrapper (registers init function at 0x0045be80). nops. Then load from DAT_007cd208, call, load again, test, push+call if non-null. Then "MYTH" 4CC string literal at end. Between Collision System Reset and AVI Stream Cleanup. |
| 0x0045bfe9 | 0x0045c030 | 71 | missed_function | medium | nop padding, push-address-call-pop-ret wrapper. nops. Then reads byte flag DAT_007cd26c (test al,al; jz), reads dword DAT_007cd264, calls IAT [DAT_0059e1a8], test return, jumps. Global state check + IAT call. Collision/audio cleanup check. |
| 0x0045cc23 | 0x0045cd50 | 301 | missed_function | HIGH | Prev function tail (inc esi; cmp esi,0x68; jl — loop). Epilogue (5f 5e c2 04 00). Then new function: mov ecx, DAT_008afe18; call. Loads params, fstp [output]. Reads DAT_007c56a4 (SessionType! — known global). Sets [ecx] = 1. Game logic using SessionType for conditional behavior. Float store + flag set. |
| 0x0045d50f | 0x0045d530 | 33 | missed_function | high | Clean thiscall: nop, push esi, mov esi,ecx, call sub. mov ecx,[esi+0xc]; test ecx,ecx; jz (skip if null). call sub on field. mov [esi+0xc], 0 (zero field after). pop esi; ret. Pointer check at +0xc with conditional cleanup + zero. |
| 0x004618b2 | 0x004618d0 | 30 | jump_table_data | high | mov edi,edi nop. 4 function pointers: 0x0046181f, 0x00461826, 0x0046182d, 0x00461834. All within prev function SessionConfigBuilder range. nop padding. |
| 0x0046200e | 0x00462156 | 328 | missed_function | high | nop padding. Accesses large struct offset: mov eax,[ecx]; mov ecx,[eax+0x1b79c]. push esi/edi; call. test return; conditional big jump (0f 84 07 01 00 00). Push string refs 0x005c5bf0 and 0x005c5bfc (likely format strings or data section refs), mov ecx, call. Between Conditional Delegation and Network Filter/Sort — network server browser or game setup function. |
| 0x0046491f | 0x00464930 | 17 | missed_function | low | nop, call +5, jmp +22, nop padding. Small thunk. |
| 0x00464fd0 | 0x00465150 | 384 | missed_function | high | Allocation function: push esi; push 0xe5d0 (allocation size = 5872 bytes); mov esi,ecx; call alloc. test eax; branch if null. mov ecx,eax; call init. mov [esi],eax (store ptr). return eax. Null branch: xor eax; store 0; return. Tail call (5d 5b jmp back). Between Threshold-to-Rank Classifier and Single Call Wrapper. |
| 0x00465fe5 | 0x00466080 | 155 | missed_function | medium | nop padding (10 nops), push-address-call-pop-ret wrapper, nops. Then mov eax,[DAT_007cd460]; test; jz skip; push eax; call cleanup. Between Collision Distance Reset and a forwarding function. Collision cleanup/atexit. |
| 0x00466250 | 0x004662e0 | 144 | missed_function | high | TWO thiscall methods. Method 1: push esi; mov esi,ecx; mov ecx,[esi+0x40]; push 3; call. Set byte [esi+0xf4] = 1. Method 2: same pattern but sets byte [esi+0xf5] = 1 instead. Between Game Object Update Frame and State Reset with Zero. Flag-setting helpers for game object states. |
| 0x00466d99 | 0x004670e0 | 839 | missed_function | high | Prev func tail (5e 8a e9). Then function: mov eax,[ecx+0x31c]; push ebx; xor ebx,ebx; cmp eax,ebx; je (big jump 0x198). cmp [esp+8],1; push esi; mov esi,[eax]; conditional branches to +0x2c03 or +0x3003 offset accesses. Switch/branch on field at +0x31c with large offset table lookups. Vehicle struct at large offsets. 839 bytes. Between Object Init + VTable and Switch on Action ID — vehicle action handler. |
| 0x00467864 | 0x00467e40 | 1500 | missed_function | high | LARGE (1.5KB). Starts with data/garbage (cf byte). Some epilogue fragments. Then proper function: sub esp,0x338; push registers; mov esi,ecx; xor eax,eax; xor ebx,ebx. rep stosd zero-init (0x60 dwords = 0x180 bytes). mov ecx,[esi+0x40]; store results on stack. Between LinkedListNodeDestructor and credits.txt Parser. Game data/state initialization. |
| 0x004685df | 0x00468610 | 49 | mixed | medium | ret 0x10 stub, then pop esi; add esp,0x200; ret (another epilogue). Then thiscall method (56 8b f1): call, test byte [esp+8], conditional cleanup call, ret 4. Between forwarding function and Destructor. |
| 0x00469187 | 0x004692a0 | 281 | missed_function | high | IAT call (ff 15 8c e1 59 00) + prev func tail. Then thiscall: push esi; push 0; mov esi,ecx; call. Mov eax,[esi]; push 0; mov ecx,esi; call vtable at [eax+0x3c]. Multiple IAT calls. Between Player Profile Scanner and Short Computation — player profile or vtable dispatch. |
| 0x00469dcd | 0x0046a220 | 1107 | missed_function | HIGH | LARGE (1.1KB). Nop padding. thiscall: push esi; mov esi,ecx; mov ecx,[esi+0x40]; call. FPU math on vehicle struct: fadd [esi+0x174]; fst [esi+0x174]; fcomp [DAT_0059e800]; fnstsw test; conditional. Then mov eax,[esi+0x178]; xor ecx,ecx; more operations. Physics/display function updating vehicle fields +0x174 and +0x178 with FPU and global comparison. Between Player Stats Display Cleanup and Object Constructor — vehicle stats/display update. |
| 0x0046a86e | 0x0046a980 | 274 | missed_function | high | nop padding. Call; xor eax,eax; ret (small stub). More nops. Tail jmp (e9 55 fc). Then function: sub esp,0x100; push edi; push 0x100; lea eax,[esp+8]; mov edi,ecx; push eax; mov ecx, DAT_007ce498 (AutoLoadConfigFile! — known global); call string copy. 0x100 byte string copy from AutoLoadConfigFile. Between Standings Display and ID Pair Match and Clear. |
| 0x0046b317 | 0x0046b580 | 617 | missed_function | high | IAT call (ff 15 0c e3 59 00) at start (prev tail). Then sub esp,0x100; push esi; mov esi,ecx. mov ecx,[DAT_007cd8c0]; vtable call [eax+0x1c] with param 0x11. test edi; conditional. calls on result. Between Offset Accessor (+0x174) and UI Options Constructor. UI setup with DAT_007cd8c0 global. |
| 0x0046c6e6 | 0x0046c74c | 102 | missed_function | high | Prev func tail (call, pop esi, xor eax, pop ebx, ret). Then thiscall: push esi; mov esi,ecx; call. mov al,[esp+8]; mov [esi+0x174],al (byte store). set vtable 0x0059fb58. return this. Then nop + load from [edx+0x174]. Between Championship Standings HTML Writer and Key Binding Array Remove/Shift. Standings/UI field setter. |
| 0x0046cceb | 0x0046cd20 | 53 | mixed | medium | Starts with "MYTH\0" string literal (4d 59 54 48 00 — 4CC texture tag). Then code: push ecx; mov edx,ecx; push edi; or ecx,-1; xor eax,eax; mov edi, 0x007cd818; repne scasb (string length calc on buffer at 0x007cd818); not ecx; dec ecx. String length calculation on a global buffer. Then more operations. Between Profile Already Exists Page Handler and CopyProfileIconBMP. |
| 0x0046e229 | 0x0046e5c0 | 919 | missed_function | high | enter opcode (c8) at start — likely data/garbage. Then push ecx; push esi; mov esi,ecx; mov ecx,[esi+0x40]; vtable call with param 0x1f; test return. mov ecx,[eax+0x178]; test; conditional call. Further loading operations. Between Deferred Texture/Object Loader and Init with Stack Buffer — resource/asset loading function. |
| 0x0046ec78 | 0x0046fcf9 | 4225 | missed_function | HIGH | VERY LARGE (4.2KB). Prev func tail (call; jmp). Then: mov eax,[0x005c666c]; sub esp,0x200; push ebp/esi; mov esi,[esp+0x21c]; mov ebp,ecx; push ebx. Character-by-character string comparison loop: mov dl,[eax]; mov bl,[esi]; cmp dl,bl; jnz. String/file parser with character comparison. Between Object Name Matching + Activation and ObjectCreate_WithVtable. Likely scene/SCN file parser or config reader. |
| 0x004702fb | 0x00470400 | 261 | missed_function | HIGH | nop padding. thiscall: push esi; mov esi,ecx; mov eax,[esi+0x304]; sub eax,0x1af (or add eax, -0x1af); cmp eax,6; ja dispatch. INDIRECT JUMP TABLE: jmp [eax*4 + 0x004703e0] — jump table EMBEDDED WITHIN this gap at 0x004703e0! Case handlers: push 0x1a, push DAT_007cd818, call, etc. Between VTable Set and Engine Temperature Debug Display. Vehicle struct (+0x304) switch dispatch with embedded jump table. |
| 0x00471484 | 0x00472cc0 | 6204 | missed_function | HIGH | VERY LARGE (6.2KB). Starts with padding byte. Short func: mov ecx,esi; call; mov eax,esi; pop esi; ret. Then large thiscall: push esi; push 1; mov esi,ecx; call. push -1; push string 0x005c670c; set vtable 0x005a0d80; set field at +0x334 to 235 (0xeb). 6204 bytes of init/display setup. Between Mode-Specific Screen Setup and UI String Format + Display — main UI screen initialization function. |
| 0x00473b6b | 0x00474510 | 2469 | missed_function | HIGH | Starts with "MYTH\0" string (4CC tag). Then thiscall: push esi; mov esi,ecx; mov eax,[esi+0x320]; movzx ecx,byte [eax]; push ecx; call. More calls. Then another thiscall: mov ecx,[DAT_007cd8c0]; vtable call. 2469 bytes. Between Constructor (VTable + Config Data) and SessionEnter_Alt. UI/screen setup with MYTH texture tag and vtable dispatch. |
| 0x00475529 | 0x00475c80 | 1879 | missed_function | HIGH | LARGE (1.9KB). Starts with "CZ\0" data bytes (43 5a 00). Small stub: mov eax,esi; pop esi; ret. Then thiscall: push esi; mov esi,ecx; set byte [DAT_007cd850] = 0. call. Reads DAT_007d0e74 (global flag), DAT_007d0fac (another flag). Reads [esi+0x17c] (vehicle struct field). Multiple global state checks. Between forwarding function and Conditional Draw — game state / UI conditional logic. |
| 0x0047619a | 0x004761c0 | 38 | missed_function | medium | Prev func tail (mov ebp,eax). Then thunk: mov ecx, 0xfffff904 (large negative); mov eax,[esp+4]; test; jz. mov [esp+4],eax; add ecx,0x50; jmp (adjusts pointer and jumps). Then ret 4. IAT call (ff 15 50 e3 59 00). Between VTable Object Destructor and UI Object Init. Pointer adjustment thunk. |
| 0x004767cf | 0x00476ec0 | 1777 | missed_function | HIGH | LARGE (1.8KB). nop. Full prologue: sub esp,0x354; push ebx/ebp/esi; mov ebp,ecx; push edi. call. Loads byte from DAT_005ea438 (LoadPath — directory pointer). 1777 bytes of scene/game init. Between Renderer State Reset and Season Scene Search by Name — scene loading/init function. |
| 0x00477b67 | 0x00477ba0 | 57 | missed_function | high | IAT call (ff 15 64 e0 59 00) with padding. Then call; test; conditional. mov eax,[eax+4]; test; jnz. Loads default LoadPath string (b8 38 a4 5e 00 = mov eax, 0x005ea438). Pushes it. mov ecx, DAT_008ac368 (scene array); call. push 0; mov ecx, DAT_008ac368; call again. Between Game Content Filter Check and Scene List Search by Path — scene/scn file path resolver. |
| 0x00478e8b | 0x00478ec9 | 62 | missed_function | high | nop padding. mov edx,ecx; mov eax,[edx+0x15c]; test; jnz else load LoadPath default (0x005ea438). push edi; mov edi,eax; string length calc (repne scasb); dec ecx. mov eax,[edx+0x13c]; test; jz skip. Another field access. Between delegation function and SessionExitOrChecks — string/path field accessor with LoadPath fallback. |
| 0x0047aa73 | 0x0047aab0 | 61 | missed_function | medium | Data bytes/garbage (c6 5e c3). nop padding. then thiscall: push esi; mov esi,ecx; set vtable 0x005a66e0; call; conditional flag test; conditional cleanup call; ret 4. Between Empty Stub and TextWidget_Init. Widget constructor. |
| 0x0047c054 | 0x0047c360 | 780 | missed_function | high | Data bytes (01 00). Prev func tail (pop esi; add esp,0x80; jmp back). Then fld [DAT_008afe90]; push esi; mov esi,ecx; fmul [esi+0x174]; fst [esi+0x174]; fcomp [DAT_0059e440]; fnstsw test; conditional (7a = jp). call. FPU math on vehicle struct +0x174 with global constant comparison. Between File Extension Stripper and Double Delegate Call — vehicle physics/display update. |
| 0x0047c8fc | 0x0047daf0 | 4596 | missed_function | HIGH | VERY LARGE (4.6KB). Starts with writes to DAT_007cffcc (global zero). xor eax,eax. Then thiscall: push 0x3f800000 (1.0f); push 0; mov esi,ecx; call. Zero-init [esi+0xfc] etc. Set vtable 0x005a6e68. Between UILoadingPercentDisplay and TelemetryDisplaySwitch. Large UI loading/telemetry initialization function. |
| 0x0047e390 | 0x0047e3f4 | 100 | missed_function | high | thiscall: call sub. mov ecx,[DAT_007cd8c0]; vtable call with param 0x15; test edi; jz. mov ecx,edi; call. test return; conditional. Loads field at [eax+0x48]; test; conditional. Between ByteAccumAdd and Race Laps String Load on Trigger — UI/race display condition check. |
| 0x0047ee94 | 0x0047ef3c | 168 | missed_function | high | Switch dispatch: mov eax,[DAT_007cf134]; cmp eax,5; ja dispatch. jmp [eax*4 + 0x0047efd0] — switch table embedded at 0x0047efd0. Case branches push string refs (like 0x005c74e8, 0x005c6e58), call. Then another section that reads from PC-exclusive path vars. Between InitFromDataBlock and Percentage Display Formatter. Data block initialization with switch. |
| 0x0047f3c2 | 0x0047f3f0 | 46 | missed_function | medium | thiscall: call string utility (b9 68 c3 8a 00 = mov ecx, DAT_008ac368; call 0x04610400). Then another sub-call. Between Screen Data Struct Init and Destructor (3 sub-objects). Screen data constructor fragment. |
| 0x00485864 | 0x004859d0 | 364 | missed_function | high | thiscall: push esi; mov esi,ecx; lea ecx,[esi+0x130]; call sub. mov eax,[esi+0x128]; test; jnz: push eax; call free. mov eax,[esi+0x120]; more cleanup. Between Linked-List Buffer Destructor and LinkedListDtor. Buffer/container destructor method. |
| 0x0048669b | 0x004866ad | 18 | missed_function | low | "MYTH" string literal (4d 59 54 48 00)? No — this is 4d 59 54 48 00 53 8b 5c 24 08 56 8b f1 3a 5e 65 74 07 - that starts with "MYTH\0" then push ebx; mov ebx,[esp+8]; push esi; mov esi,ecx; cmp bl,[esi+0x65]; je. String tag + code! Between State Change Notification and UI Widget Property Propagator. |
| 0x0048730d | 0x00487330 | 35 | jump_table_data | high | lea ecx,[ecx] alignment. 5 function pointers: 0x004872a6, 0x00487276, 0x004872bc, 0x00487290, 0x004872d2. All within prev function range (State-Dependent vTable Dispatcher). nop padding. |
| 0x00487688 | 0x004876b0 | 40 | missed_function | medium | nop; thiscall: push esi; mov esi,ecx; call; test byte [esp+8]; jz; push esi; call cleanup; ret 4. Between UI Object Init with Byte Params and Short Computation (Constructor). UI object method. |
| 0x00487f02 | 0x00487f30 | 46 | missed_function | medium | call; xor eax,eax; ret (stub). Then or eax,-1; pop esi; ret (alternate ret). Then thiscall: push esi; mov esi,ecx; call; test byte; conditional cleanup; ret 4. Between a struct init and VTable Set + Cleanup. |
| 0x00488301 | 0x004883a0 | 159 | missed_function | high | nop padding. push 0; call. Then sub esp,0x34; push esi; mov esi,ecx; mov eax,[esi]; push edi; call vtable at [eax+0xa8]; test edi; jz. push ebx; lea ebx,[esi+0xe0]; push ebx; mov ecx,edi; call. Between Surface Render Region Setup and 5-Field Init. UI render region setup. |
| 0x00488f3a | 0x00488f90 | 86 | missed_function | high | thiscall: call (e8 19 d7 f7 ff). mov eax,[esi+0xc8]; test; jz. mov eax,[eax+0x40]; test; jnz (if null, load 0x005ea438 = LoadPath). load another field, call sub with path. Between UI Large Render Dispatcher and a vtable setter. UI render dispatch with LoadPath fallback. |
| 0x0048a634 | 0x0048a650 | 28 | jump_table_data | high | 5 function pointers: 0x0048a49d, 0x0048a4d7, 0x0048a54a, 0x0048a567. All within prev function UI List Management Handler range. nop padding. |
| 0x0048b4d0 | 0x0048b4e0 | 16 | missed_function | low | Short function: mov eax,[ecx]; push 1; call vtable [eax+0xa8]; xor eax,eax; ret. UI/browse function. |
| 0x0048b94c | 0x0048b9c0 | 116 | missed_function | high | nop padding. mov al,[esp+4]; mov edx,ecx; or ecx,-1; test al,al; push edi; jnz. mov [edx+0x2f0],eax; mov [edx+0x2f4],eax (zero-init two fields); mov byte [eax],0. Then string copy loop (rep stosb). Between UI Widget Visibility Toggle and Text Input Render / Password Mask — text input buffer init. |
| 0x0048ca30 | 0x0048ca50 | 32 | missed_function | medium | thiscall: push esi; mov esi,ecx; call; test byte; conditional cleanup; ret 4. Between IntFieldSetter and Linked List Destructor. |
| 0x0048d67f | 0x0048d6a0 | 33 | missed_function | medium | thiscall: push esi; mov esi,ecx; call; test byte; conditional cleanup; ret 4. Between Constructor Dual Sub-Init and Short Computation / VTable Init + Call. |
| 0x0048d9b5 | 0x0048d9d0 | 27 | jump_table_data | high | lea ecx,[ecx] alignment. 3 function pointers: 0x0048d8ea, 0x0048d887, 0x0048d94c. All within prev function UI Scroll Area/Auto-Scroll Manager range. Data bytes: 00 02 02 01 02 02 00 00 01 01 90 90 (case value table). Then nop padding. |
| 0x0048e643 | 0x0048e670 | 45 | missed_function | medium | Data/garbage (30 23 00 00). Then thiscall: call sub. another thiscall: push esi; mov esi,ecx; call; test byte; conditional cleanup; ret 4. Between UI Struct Init (Type 0) and Destructor. |
| 0x0048eda1 | 0x0048f590 | 2031 | missed_function | HIGH | LARGE (2KB). Data bytes (00 0a 00 00 00 88 8e 7c 01...). Then function: sub esp,8; push ebx; mov ebx,[esp+0x10]; ... mov eax,[esi+0xc]; mov [ecx],... Many field copies. mov edx,[esi+0x10]; mov [edx],... Struct field copy chain (reading from multiple offsets). Between UI Dimension Capture and Linked List Indexed Accessor. Possibly UI data copy or render dispatch. |
| 0x0048fe86 | 0x0048feb0 | 42 | missed_function | medium | thiscall: push esi; mov esi,ecx; call; test byte; conditional cleanup; ret 4. Between UI Component Init 5 and VTable + Sub-Init. |
| 0x00490282 | 0x004902c0 | 62 | missed_function | medium | nop padding (11 nops). xor eax,eax; ret 0x10 (small stub). 02 00 00 00 (data?). pop edi; jmp back (tail call). thiscall: push esi; mov esi,ecx; call; test byte; conditional cleanup; ret 4. Between Object Init with Field Zeroing and a linked list destructor. |
| 0x00490635 | 0x00490660 | 43 | missed_function | medium | nop padding (6 nops). jmp back (tail call). thiscall: push esi; mov esi,ecx; mov eax,[esi]; push 0; call vtable [eax+0x40]. mov ecx,esi; pop esi; jmp to another function. Between PanelMouseInteractionHandler and a linked list iterator. UI panel handler method. |
| 0x00494437 | 0x004944a0 | 105 | missed_function | high | IAT call (ff 15 0c e3 59 00). thiscall: push esi; mov esi,ecx; set vtable 0x005ac8d8; call; test byte; conditional cleanup call; ret 4. Between Resource Path Builder and Collision Global Zeroing. UI/resource constructor. |
| 0x00495156 | 0x00495190 | 58 | mixed | medium | nop padding. jmp back (tail call from prev). Then triple nops. Then fld [DAT_0059e43c]; fmul [DAT_005ac990]; fstp [DAT_007cde30]. Global float computation (multiply two globals, store to third). Then nop padding. Between Global Accessor and Large Struct Zero-Init. Global float constant initialization. |
| 0x00496dd5 | 0x00496e20 | 75 | jump_table_data | high | lea ecx,[ecx] alignment. Function pointers: 0x00496992, 0x0049699c (from prev function UI Large Render). Then data bytes: 00 00 01 00 01 00 01 01 00. More pointers: 0x00496abd, 0x00496abd (repeat), 0x00496ba6, 0x00496c4d, 0x00496c7f, 0x00496b7a. Data bytes: 02... Jump table + index data for UI render switch. |
| 0x00498cf6 | 0x00498d20 | 42 | missed_function | high | thiscall: mov eax,[esp+4]; push esi; push eax; lea ecx,[esi+0x3c]; call. mov ecx,[esp+0xc]; mov [esi+0x44],ecx (field set). ret 8. "MYTH\0" string literal at end (4d 59 54 48 00). Between Sprite/Texture Enumeration and an init function. |
| 0x00499082 | 0x00499140 | 190 | missed_function | high | thiscall: mov eax,[esi]; push 0; mov ecx,esi; call vtable [eax+0x2c]; pop edi; xor eax,eax; pop esi; ret. Then another function: mov edx,[esp+4]; cmp edx,[ecx+0xc]; jl ... cmp edx,[ecx+0x10]; jg ... Bounds check with rect/region comparison. Between Guarded Sub-Rectangle Render Dispatch and an init function. UI rectangle bounds check + dispatch. |
| 0x00499222 | 0x00499280 | 94 | missed_function | high | thiscall: mov eax,[esi+0x8c]; test esi,esi? Wait: 8b b6 8c 00 00 00 85 f6 75 ec 33 c0 c3 = check [esi+0x8c]; loop/conditional. Then another function: mov al,[esp+4]; test al,al; jz. Load [+0x10], [+0xc], [+0x8], [+0x4], [+0x50] — multi-field access. Between forwarding function and a Destructor. UI field accessor with rect checks. |
| 0x0049966a | 0x00499680 | 22 | missed_function | low | nop padding (6 nops). push address, call, pop ecx, ret. Standard wrapper/thunk. |
| 0x0049a110 | 0x0049a180 | 112 | missed_function | high | Series of field accessors: mov edx,[esp+4]; mov ecx,[ecx+8]; xor eax,eax; test edx,edx; jle. Loop checking [ecx+0x24] vs edx. Then another accessor for [ecx+0x28] field. Iterates through linked list nodes by pointer at +8, comparing index at +0x24. Between Vtable Field Getter and Zero-Init Int. Indexed linked list search. |
| 0x0049ac34 | 0x0049acc0 | 140 | missed_function | high | Prev func tail (add [ecx+0x10], edx; jmp back). Then new function: mov edx,[ecx+0x14]; or eax,-1; cmp edx,ebx; jnz. cmp [ecx+0x18],0; cmp [ecx+0x1c],0; cmp [ecx+0x20],0; conditional. mov eax,[ecx+0x4]; add eax,edx; ret. Multiple field comparisons at offsets +0x14, +0x18, +0x1c, +0x20, +0x4. Between Texture/Surface Dimension Validity Check and a scroll/offset updater. |
| 0x0049afaa | 0x0049afc0 | 22 | missed_function | low | nop padding, push address, call, pop ecx, ret. Standard wrapper. |
| 0x0049b03a | 0x0049b050 | 22 | missed_function | low | nop padding. call+jmp thunk. Between UI Delegate Wrapper and Empty Stub. |
| 0x0049b1ab | 0x0049b1c0 | 21 | jump_table_data | medium | 4 function pointers: 0x0049b10e, 0x0049b115, 0x0049b11c, 0x0049b123. All within prev function Free Callback Registration range. nop padding. |
| 0x0049cfbd | 0x0049d070 | 179 | missed_function | high | thiscall: push esi; mov esi,ecx; mov eax,[esi+0x4c]; test; jz. mov eax,[eax+0x54]; test; jz. push eax; lea eax,[esi+0x60]; push eax; push 0; mov ecx, 0x007ce048; call. mov eax,[esi+0x50]; test; conditional. Between Cockpit Dashboard LED/Gauge Setup and Steering Wheel Animation — cockpit/HUD setup function. |
| 0x0049e670 | 0x0049e7b0 | 320 | missed_function | high | push ecx; mov eax,[DAT_007c54e4]; mov edx,[DAT_007c54dc]; mov ecx,ebp. Accesses VehiclePtrArray (mov eax,[eax*4 + DAT_007c54f0]; mov edx,[edx*4 + DAT_007c54f0]). Compares +0x4894 (DriverNumber/TeamID fields). Between SetFourDwords and HUD_TachoTick. Vehicle array lookup with field comparison. |
| 0x004a0615 | 0x004a0630 | 27 | jump_table_data | high | lea ecx,[ecx] alignment. 7 function pointers: 0x004a05ae, 0x004a05b5, 0x004a05bc, 0x004a05c3, 0x004a05ca, 0x004a05d1. Within prev function Session Type Dispatch range. |
| 0x004a1553 | 0x004a1830 | 733 | missed_function | high | nop padding. Writes to DAT_007ce250 with jmp back. Then function: mov eax,[esp+8]; push esi; xor esi,esi; cmp eax,0x200; ja dispatch; jz (switch dispatch on param). sub eax,2; cmp eax,0x1e; ja. Large switch-case function. Between Window Rect Adjustment and Windows Message Pump with Sleep — likely Windows message or event handler. |
| 0x004a19ab | 0x004a19d0 | 37 | missed_function | medium | nop padding. Function: mov eax,[esp+4]; push eax; call (e8 14 65 0e 00). mov ecx,[esp+0xc]; mov [ecx],ax (stores short). add esp,4; mov eax,2; ret 8. nop padding. Between ObjectHandleReader and StringCompareWithDefault. Handle-to-short conversion. |
| 0x004a4097 | 0x004a40e0 | 73 | missed_function | medium | IAT call (ff 15 90 e3 59 00). Then call+jmp thunk. Then ret stub (c3). nop padding (8 nops). Then push address, call, pop ecx, ret. Between accumulator function and Large Buffer Zero-Init. |
| 0x004a5311 | 0x004a5330 | 31 | jump_table_data | high | lea ecx,[ecx] alignment. 5 function pointers: 0x004a523b, 0x004a5231, 0x004a5227, 0x004a521d. All within prev function (ShadowObject/LODOUT/LODIN/MESHFILE handler) range. nop padding. |
| 0x004a7079 | 0x004a70e0 | 103 | missed_function | high | sub esp,8; mov edx,[esp+0xc]; xor eax,eax; store 0 to [esp+4] and [esp+8]. lea eax,[esp+8]; push eax; mov esi,ecx; lea ecx,[esp+4]; push ecx; push DAT_005c5cc0 (string/data ref); push edx; call (e8 44 17 0e 00). Between DebugCoordinateFormat and UI Control Window Initialization. UI/format function with string param. |
| 0x004add23 | 0x004add50 | 45 | jump_table_data | high | 8 function pointers: 0x004ad254, 0x004ad274, 0x004ad294, 0x004ad2b1, 0x004ad2cb, 0x004ad2e5, 0x004ad2ff, 0x004ad319. All within prev function Force Feedback Config Initializer range. nop padding. |
| 0x004af382 | 0x004af3a0 | 30 | jump_table_data | high | mov edi,edi nop. 4 function pointers: 0x004af238, 0x004af286, 0x004af2d4, 0x004af31c. Within prev function TireCompoundClamp range. nop padding. |
| 0x004b1eb5 | 0x004b1f50 | 155 | missed_function | medium | Data/garbage. Then function: push ecx; mov edx,[esp+8]; push ebx; xor ebx,ebx; test edx,edx; push esi; mov esi,ecx; push edi; conditional. or ecx,-1; xor eax,eax; repne scasb (string length calc). dec ecx. Then call with string. Between ConfigKeyValueWrite and Short Field Setter — config file write helper. |
| 0x004b218a | 0x004b21a0 | 22 | missed_function | low | nop padding, push address, call, pop ecx, ret. Standard wrapper/thunk. |
| 0x004b39e8 | 0x004b3a90 | 168 | jump_table_data | high | Many function pointers: 0x004b3421, 0x004b34be, 0x004b36d3, 0x004b3749, 0x004b39e1, 0x004b3971, 0x004b3440, 0x004b3493. Within prev function Central Message/Event Dispatcher. Data bytes: 00 01 01 01 01 01 01 00. Jump table + case value table. |
| 0x004b3d4a | 0x004b3d60 | 22 | missed_function | low | nop padding, push address, call, pop ecx, ret. Standard wrapper. |
| 0x004b44d0 | 0x004b44e0 | 16 | missed_function | low | call+jmp thunk. Between File Operation Open + Write and Fixed-Block Memory Pool Init. |
| 0x004b4b33 | 0x004b4b50 | 29 | jump_table_data | high | 6 function pointers: 0x004b4a4f, 0x004b4a53, 0x004b4a53 (repeat), 0x004b4a5a, 0x004b4a68, 0x004b4a61. Within prev function Network Packet Router & Queue Manager. nop padding. |
| 0x004b66bd | 0x004b66e0 | 35 | jump_table_data | high | lea ecx,[ecx] alignment. 7 function pointers all at 0x004b6396 (same address — default case). Within prev function Game Command Data Validator. nop padding. |
| 0x004b784d | 0x004b7860 | 19 | jump_table_data | high | lea ecx,[ecx] alignment. 4 function pointers: 0x004b75fa, 0x004b75fe, 0x004b7605, 0x004b760c. Within prev function Replay Save State Machine. |
| 0x004b8d8b | 0x004b8da0 | 21 | jump_table_data | high | 5 function pointers: 0x004b8c5d, 0x004b8cc0, 0x004b8ce6, 0x004b8d06, 0x004b8d3d. Within prev function (Float Switch with AI/Game Mode Dispatch) range. |
| 0x004b9d1b | 0x004b9d80 | 101 | missed_function | medium | thiscall: call (e8 39 c9 f4 ff). mov ecx,[esi]; xor dl,dl; call. fcomp comparison: fld [ecx+0x3c0f]; wait no — d9 81 3c 0f 00 00 = fld [ecx+0xf3c]. ded9 = fdivp. df e0 = fnstsw. f6 c4 44 = test ah,0x44. Conditional. Then call. Between Float Accumulator and a thunk — float math with struct at offset +0xf3c. |
| 0x004b9f47 | 0x004b9f89 | 66 | mixed | medium | Function pointers (from prev function Pit Service Steering Animation Step) followed by thiscall: push esi; mov esi,ecx; lea ecx,[esi+8]; call. Between Pit Service Steering Animation Step and Single Call Wrapper. |
| 0x004be67c | 0x004be6f0 | 116 | missed_function | high | nop padding (4 nops). jmp back (e9 0b). nop padding. Then function: xor eax,eax; push edi; mov ecx,0x60; mov edi, 0x008ac1e8; rep stosd (zero-init 0x60 dwords = 0x180 bytes). Store to globals: a3 d0 c1 8a 00 (DAT_008ac1d0), a3 e4 c1 8a 00 (DAT_008ac1e4), a3 dc c1 8a 00 (DAT_008ac1dc). Between Sprite Grid Render and a Delegation — global array zero-init. |
| 0x004c1643 | 0x004c1660 | 29 | jump_table_data | high | 8 function pointers: 0x004c15ba, 0x004c15cd, 0x004c15e0, 0x004c15f3, 0x004c1606, 0x004c1619, 0x004c162c. Within prev function PitStop Phase Advance. |
| 0x004c2faa | 0x004c2fe0 | 54 | missed_function | medium | nop padding, push-address-call-pop-ret wrapper, nops, mov ecx, DAT_008ac388; jmp (tail call), nops, call+jmp thunk. Between Delegation Wrapper and Delegation. |
| 0x004c3d38 | 0x004c3d80 | 72 | missed_function | high | Prev func tail (5b 81 c4...). Then: mov ecx,[DAT_008ac394]; test; jz. mov eax,[ecx-4]; push ebx; lea ebx,[eax-4]; push esi; mov esi,ecx; imul esi,esi,0x424 (stride calculation!). sub edi,esi; lea edi,[edi+1]; add esi,0x424. Between TGA Texture File Scanner and Vehicle Lookup by Name. Vehicle array stride 0x424 computation (matches VehicleArray stride!). |
| 0x004c6917 | 0x004c6960 | 73 | missed_function | medium | thiscall: call (e8 58 d5 f5 ff). mov ecx,esi; set field [esi+0x4894] = -1 (0xffffffff) — this is the DriverNumber/TeamID field! call another. Another thiscall: call; mov eax,esi; ret. Between MergeSortLinkedList and TeamIDSetter. Vehicle struct field init at +0x4894. |
| 0x004c7c3a | 0x004c7c50 | 22 | missed_function | low | nop padding, push address, call, pop ecx, ret. Standard wrapper. |
| 0x004c8143 | 0x004c8180 | 61 | mixed | medium | Function pointers from prev function UpdateCameraFOV (6 unique targets: 0x004c7f52, 0x004c7f5f, 0x004c7f6c, 0x004c7fea, 0x004c7ff7, 0x004c8018, 0x004c80dd, 0x004c8025, 0x004c8047, 0x004c80e3, 0x004c80e3 repeat). Then nop padding. Jump table + padding. |
| 0x004c9211 | 0x004c9260 | 79 | missed_function | high | thiscall: call (e8 4e eb 0b 00); add esp,4. push -1; push 0; mov esi,ecx; call. test return; conditional. Reads DAT_00a4567c (global flag). test; jz. fld [DAT_007cf3b8] — FPU global. Between Triple VTable Destructor Release and a field return function. Game logic with FPU and global checks. |
| 0x004c9af3 | 0x004c9b70 | 125 | mixed | medium | Function pointers from prev function Memory Allocation / Particle Emitter Factory (0x004c9a63, 0x004c9a78, 0x004c9af0 [2x], 0x004c9a8d, 0x004c9ab1, 0x004c9ac6). Then thiscall: push esi; mov esi,ecx; set vtable 0x005ace6c; call. test byte; conditional cleanup; ret 4. Jump table + constructor. |
| 0x004ce813 | 0x004ce860 | 77 | missed_function | high | thiscall: mov al,?; pop esi; ret 4. Then mov al,0xe9; jmp back (tail). Then function: xor eax,eax; mov ecx,0; writes 0 to [eax], [eax+4], ..., [eax+0x2c] (12 dword zero-init). Between CollisionEffectDispatch and String List Lookup — small struct zero-init. |
| 0x004d003a | 0x004d0060 | 38 | missed_function | medium | nop padding, push-address-call-pop-ret wrapper, nops, mov ecx, DAT_008acee0; jmp (tail call). |
| 0x004d22f1 | 0x004d23d0 | 223 | missed_function | high | nop padding (12 nops). push ecx; mov ecx, DAT_007cd25c; call (e8 a5 fa f8 ff). test; jz. fld [DAT_008afea0]; fcomp [DAT_005acef0]; fnstsw; test; conditional (0f). More operations. Between flag/field setter and Pit Timer State Init — FPU comparison involving global physics constants. |
| 0x004d348d | 0x004d36d0 | 579 | missed_function | high | lea ecx,[ecx] alignment. Function pointers: 0x004d2e92, 0x004d2ec5, 0x004d3057, 0x004d30e4, 0x004d3110, 0x004d3286. All within prev function Pit Timer / Race Phase State Machine range. nop padding. Then function: mov eax,[DAT_00a4567c]; test; push esi; mov esi,ecx; js (0f 8c 8d). Between Pit Timer and Timer/Frame Rate Throttle — pit timer state machine code after jump table. |
| 0x004d4798 | 0x004d4840 | 168 | missed_function | high | thiscall: call sub. ret. Then function: push ecx; call (e8 6c e9 d8 ff). mov eax,[esp+4]; push eax; push [esp+?]; push 1; push edx; call (e8 91 38 0b 00). add esp,0x10; ret 8. Between Delegation Wrapper and Object Init (Zero Fields + VTable). Multi-call wrapper. |
| 0x004d5c4d | 0x004d5c60 | 19 | missed_function | low | nop padding, push address, call, pop ecx, ret. Standard wrapper. |
| 0x004d7ac6 | 0x004d7b00 | 58 | missed_function | high | Two short functions. Func1: pop edi; ret 0xc. Func2: xor al,al; pop edi; ret 0xc. Then function: push esi; push edi; lea edx,[esi+0x18]; mov esi,3; or edi,-1. Stub writes: mov [eax+0xc],0; mov [eax],0; mov [edi-0x18],edi; mov [edi-0xc],edi. add eax,4; loop. Between Debug Log Write and a range check function — loop init for 3 entries. |
| 0x004d8294 | 0x004d82c4 | 48 | missed_function | medium | thiscall: call (e8 20 fc ff ff); sub ecx,?; jmp back. Then function: push esi; push edi; mov esi,[ecx+0x10]; mov edi,0x19; loop: mov ecx,[esi]; test; jz or call sub. add esi,4; dec edi; jnz. pop edi; pop esi; ret. Between Race Init with Constants and Thunk with Byte Increment — loop over 25 entries in array. |
| 0x004d8f91 | 0x004d8fb0 | 31 | jump_table_data | high | lea ecx,[ecx] alignment. 5 function pointers: 0x004d8d26, 0x004d8d40, 0x004d8d5a, 0x004d8e30, 0x004d8e57. Within prev function Audio/State Dispatch by Index. |
| 0x004d92e2 | 0x004d93e0 | 254 | jump_table_data | high | mov edi,edi nop. Function pointers: 0x004d92a3, 0x004d92bd, 0x004d92cd, 0x004d92cd (repeat 3x), 0x004d92dd, 0x004d92df. Data bytes: 00 01 00 01 01 00 00 01 00 00 00 00 01 01 01 01 01 01. Jump table + case index table for ID/Type Permission Matrix. |
| 0x004db02c | 0x004db070 | 68 | jump_table_data | high | Function pointers at regular stride: 0x004dae0a, 0x004dae3a, ... wait: bd ae 4d 00 = 0x004daebd, e6 ae 4d 00 = 0x004daee6, 0f af 4d 00 = 0x004daf0f, 38 af 4d 00 = 0x004daf38, 61 af 4d 00 = 0x004daf61, 8e af 4d 00 = 0x004daf8e, b4 af 4d 00 = 0x004dafb4, d9 af 4d 00 = 0x004dafd9, 02 b0 4d 00 = 0x004db002, 29 b0 4d 00 = 0x004db029. All within prev function Direct3D Object Factory. Data bytes: 00 01 02 09 09 09 03 04. Jump table + material/type index codes. |
| 0x004db4d6 | 0x004db546 | 112 | missed_function | high | thiscall: mov eax,1; jmp back (tail). Then thiscall: push esi; mov esi,ecx; set vtable 0x005ad0dc. mov eax,[esi+0x10]; test; jnz: push eax; call free. test byte; set vtable 0x005ad06c. Then call sub. Between Steering/Ackermann Computation and Byte Increment on Struct — constructor/destructor with dual vtable set. |
| 0x004dc0ab | 0x004dc1a0 | 245 | missed_function | high | thiscall: call (e8 a9 a5 f2 ff). sub esp,0x40; push esi; push edi; push 0x40; lea eax,[esp+0xc]; mov esi,ecx; push eax; mov ecx, DAT_007ce234; call (e8 38 05 fc ff). More stack buffer operations. push float constants (68 00 00 80 3f = 1.0f, twice). push 2; push 1; push params. Between Multi-Color Text Render and Double Render Pass — text/render function with stack buffer. |
| 0x004dceb9 | 0x004dcee0 | 39 | jump_table_data | high | lea ecx,[ecx] alignment. 10 function pointers: 0x004dcdeb, 0x004dce01, 0x004dce1c, 0x004dce3c, 0x004dce55, 0x004dce5a, 0x004dce7d, 0x004dce83, 0x004dce8f. Within prev function Position Computation with Alignment (9 cases). |
| 0x004dfbaa | 0x004dfca0 | 246 | missed_function | high | thiscall: call (e8 a9 6a f2 ff). push ebx; push esi; push edi; lea ecx,[esi+4]; call sub. Set [esi+0x90] = 0, [esi+0x94] = -1. lea edi,[esi+0xd4]; mov ebx,4; loop init. Between 26-Byte Zero-Init and Dual Array Destructor Loop + Free — object init with array at +0xd4. |
| 0x004e1946 | 0x004e1970 | 42 | mixed | medium | mov edi,edi nop. Function pointers: 0x004e18d7, 0x004e18eb, 0x004e1907, 0x004e1923. Data bytes: 00 00 00 00 01 02 03 03 03 03 03 03 03 03 (case values). nop padding. Jump table + case value table. Between Subsystem ready query and Effect Data Table Initialization. |
| 0x004ebc1d | 0x004ebc60 | 67 | mixed | medium | lea ecx,[ecx] alignment. Function pointers: 0x004eb974, 0x004eb6b8, 0x004eb9a2, 0x004eb925. Data: 00 00 00 00 01 03 03 02. Then mov edi,edi. More pointers: 0x004eba6a, 0x004eba78, 0x004eba6a, 0x004eba78. Jump table + case values. Between ParticleEffectUpdateDispatch and Vehicle Contact Force Accumulation. |
| 0x004ef167 | 0x004ef180 | 25 | jump_table_data | high | 4 function pointers: 0x004ee3af, 0x004ee4ba, 0x004ee904, 0x004ee904 (repeat). Within prev function Vehicle Dynamics Update (Brake/Tire/Suspension) range. nop padding. |
| 0x004f23aa | 0x004f2430 | 134 | missed_function | high | nop padding (6 nops). push-address-call-pop-ret wrapper. nops. Then mov eax,[DAT_008adb1c]; test; jnz: push eax; call. mov eax,[DAT_008adb24]; test; jnz: push eax; call. Between Short Computation (Delegation) and Constructor: Zero-Init + Sub-Calls — global pointer cleanup/DLL unload check. |
| 0x004f6ae9 | 0x004f6b40 | 87 | missed_function | medium | nop padding (8 nops). push-address-call-pop-ret wrapper. nops. Then function: push esi; push edi; mov esi, 0x008afc74; mov edi, 0x2d; stack adjust. Loop: mov eax,[esi-0x14]; sub esi,0x14; test eax,eax; call/jz. Between Global Table Initialization and Tire/Grip Data Array Init (Rear) — array cleanup loop with stride 0x14. |
| 0x004f8113 | 0x004f81d0 | 189 | mixed | medium | Function pointers from prev function Switch-Based Param Setting: 0x004f80fc, 0x004f80ce, 0x004f80e5, 0x004f80fc (repeat), 0x004f80ce (repeat), 0x004f80e5 (repeat), 0x004f80fc (repeat), 0x004f80ce (repeat), 0x004f80e5 (repeat), 0x004f8044, 0x004f805b. Weird repeating pattern. Data bytes. Jump table with repeating entries. |
| 0x004f9121 | 0x004f9150 | 47 | jump_table_data | high | lea ecx,[ecx] alignment. 4 function pointers: 0x004f8f7a, 0x004f8fda, 0x004f9020, 0x004f90a1. Within prev function Conditional Init Branch. nop padding. |
| 0x004fb8ea | 0x004fb910 | 38 | missed_function | medium | nop padding, push-address-call-pop-ret wrapper, nops, mov ecx, DAT_008afec0; jmp (tail call). |
| 0x004fe79f | 0x004fe7c0 | 33 | mixed | medium | Function pointers: 0x004fe3f0, 0x004fe39e, 0x004fe3a5 (repeat), 0x004fe3c7, 0x004fe3ce, 0x004fe3f0 (repeat). Within prev function Weather Severity → Grip Multiplier. nop padding. Small switch table. |
| 0x0050bfc9 | 0x0050c021 | 88 | jump_table_data | high | 13 function pointers at 10-byte stride: 0x0050b8f2, 0x0050b919, 0x0050b943, 0x0050b96d, 0x0050b997, 0x0050b9c1, 0x0050b9eb, 0x0050ba15, 0x0050ba3f, 0x0050ba69, 0x0050ba93, 0x0050babd, 0x0050bae0. Within prev function DirectX Texture/Surface Factory Dispatching FourCC Codes. Switch table for FourCC pixel formats. |
| 0x0050eb53 | 0x0050eb73 | 32 | jump_table_data | high | 8 function pointers at 4-byte stride: 0x0050ea2c, 0x0050ea8e, 0x0050ea92, 0x0050ea96, 0x0050ea9a, 0x0050ea9e, 0x0050eaa1, 0x0050eaa5. Within prev function Color Matrix Transform with Blend. |
| 0x0051588c | 0x005158af | 35 | missed_function | medium | Function: push [esp+8]; push [esp+8]; call (e8 16 f9 ff ff). test; pop; pop; jl (7c 0f). mov ecx,[esp+4]; call (e8 07 e5 ff ff); test return; js (7c 02). xor eax,eax; ret. Between File Open and Validate and a validation function — numeric/size validation function. |
| 0x0051ecd9 | 0x0051ecee | 21 | padding | high | lea esp,[esp] alignment nop, push ebx; mov ebx,esp; sub esp,8; and esp,-0x10; add esp,8; jmp +3. Stack alignment prologue pattern (aligns stack to 16 bytes). Standard MSVC SSE prologue for math functions. Between SSE Weighted Vector Sum and 4x4 matrix × 4-vector transform. |
| 0x0051ef48 | 0x0051ef5e | 22 | padding | high | Same pattern: lea esp alignment, push ebx; mov ebx,esp; sub esp,8; and esp,-0x10; add esp,8; jmp +3. SSE stack alignment prologue. Between Vector Normalize with Threshold and SSE 4x4 Matrix Multiply. |
| 0x0051fd1c | 0x0051fd2e | 18 | padding | high | lea [esi] alignment, push ebx; mov ebx,esp; sub esp,8; and esp,-0x10; add esp,8; jmp +3. SSE prologue. Between Vector Normalize with Newton-Raphson and Vec3NormalizeNewtonRaphson. |
| 0x00520032 | 0x0052004e | 28 | padding | high | SSE stack alignment prologue (lea + push ebx + sub/and/add). Between SSE 3x4 Matrix-Vector Transform and 3×4 Matrix Transform with SSE. |
| 0x00520346 | 0x0052035e | 24 | padding | high | SSE stack alignment prologue. Between 4x4 Matrix Multiply (SSE) and VectorNormalizeThreshold. |
| 0x005207b9 | 0x005207ce | 21 | padding | high | SSE stack alignment prologue. Between SSEMatrix4x4Multiply and SSEVectorCross. |
| 0x00520972 | 0x0052098e | 28 | padding | high | SSE stack alignment prologue. Between SSE Matrix Construction from 4×4 Data and PlaneFromEdgesNormalizeSSE. |
| 0x00520df4 | 0x00520e0e | 26 | padding | high | SSE stack alignment prologue. Between TriangleClosestPointOrNormal and SSE Quaternion Composition from Axis-Angle Components. |
| 0x0052690f | 0x0052692f | 32 | jump_table_data | high | 8 function pointers: 0x005267e9, 0x0052683b, 0x0052683f, 0x00526843, 0x00526854, 0x00526858, 0x00526869, 0x0052687a. Within prev function Quaternion/Transform Composition range. Small switch table. |
| 0x00527393 | 0x00527578 | 485 | missed_function | high | 3DNow! SIMD function. Contains 3DNow! instructions (0f 0f = pfmin/pfmax/pfmul, 0f 0e = pfcmp, etc). Operates on packed floats. Between 3DNow! Cubic Bezier Interpolation and a 3DNow! normalize function. Likely a 3DNow! 4x4 matrix transform or vector math function. |
| 0x005290f7 | 0x00529200 | 265 | missed_function | high | 3DNow! SIMD function. Contains 3DNow! instructions: 0f 6e (movd), 0f 0f (pfmul/pfadd), 0f 0e (pfcmp), 0f 7f (movq). Loads from global constants at DAT_005d9358, DAT_005d935c, DAT_005d936c, DAT_005d9368. Between Square Root Approximation (SIMD/3DNow!) and Empty Stub. |
| 0x0052a068 | 0x0052a090 | 40 | jump_table_data | high | 9 function pointers: 0x00529b78, 0x00529c4e, 0x00529cfe, 0x00529d59, 0x00529de2, 0x00529e08, 0x00529ef9, 0x0052a00f, 0x0052a061, 0x0052a0e2. Within prev function Field Setter with VTable Alloc. |
| 0x0052d2a5 | 0x0052d8b0 | 1547 | data_table | HIGH | LARGE (1.5KB). Structured data starting with 00 00 00 0c cb 00 80 00 00 00 00 10 d4 5a 00 cc 00 00 00 0c cc 00 80... Appears to be dxil/dxbc constant buffer data or precompiled shader constants. 4-byte and 8-byte aligned blocks with small exponent floats. Between Quaternion Multiply & Surface Sample and DirectInput8Create Import Stub. Constant pool / shader data. |
| 0x0052df5d | 0x0052df70 | 19 | missed_function | medium | nop padding. call+jmp thunk. nop padding. Between [PARTIAL] Unknown and State Check and Conditional Init. |
| 0x0052e530 | 0x0052e550 | 32 | missed_function | high | thiscall: push esi; mov esi,ecx; xor eax,eax; push 1; store [ecx]=0, [ecx+4]=0; set byte [ecx+8]=0; call (constructor stub). return this. pop; ret 8. Between Halt/Assert Handler and Bounds-Checked Byte Setter — small object constructor (3 fields). |
| 0x00530739 | 0x00530840 | 263 | jump_table_data | high | lea ecx,[ecx] alignment. Many function pointers: 0x005302f6, 0x00530304, 0x00530313, 0x00530322, ..., up to 0x0053039a. Between MP3 Audio Decoder — Huffman + Sample Rendering and Bitstream Texture Decompression. Jump table for MP3 huffman decoding. |
| 0x00535bca | 0x00535c10 | 70 | jump_table_data | high | mov edi,edi nop. 12 function pointers: 0x00535832, 0x005358a9, 0x00535a8b, 0x00535ac4, 0x00535b02, 0x00535b3c, 0x00535b86, 0x0053591b, 0x00535982, 0x005359b7, 0x005359f1, 0x00535a2b. Within prev function Argument Reorder Wrapper range. |
| 0x00539f2e | 0x00539f60 | 50 | jump_table_data | high | mov edi,edi nop. 11 function pointers: 0x005398bf, 0x0053997b, 0x00539a6f, 0x00539af0, 0x00539bb0, 0x00539c23, 0x00539d4f, 0x00539e82, 0x00539ed3, 0x00539ed7. Within prev function Object Alloc + Field Init range. nop padding. |
| 0x0053b19a | 0x0053b1d0 | 54 | missed_function | medium | Three-field accessor: mov eax,[esp+4]; test; jz skip; mov edx,[ecx+0x10]; mov [eax],edx. mov eax,[esp+8]; test; jz skip; mov edx,[ecx+0x14]; mov [eax],edx. mov eax,[esp+0xc]; test; jz skip; mov edx,[ecx+0x18]; mov [eax],edx. ret 0xc. Triple field getter for offsets +0x10, +0x14, +0x18. Between Three-Field Accessor and Triple Field Getter. |
| 0x0053be91 | 0x0053c102 | 625 | missed_function | high | MOVUPS (0f 29) SSE instruction — movaps [esp], xmm0. Then mov eax,[esp+0x10]; mov ecx,[esp+0xc]; mov edx,[esp+8]; push edx; push ecx; push eax; call (e8 70 30 02 00); add esp,0xc; ret. IAT call: ff 15 a4 e3 59 00. Between 3D Squared Distance and Float Store from x87 ST(2). SSE math wrapper with IAT call. |
| 0x0053c1b0 | 0x0053c200 | 80 | missed_function | medium | push-address-call-pop-ret wrapper. nops. Then function: mov al,[DAT_008b8ee4]; mov bl,2; test al,al; jnz. push eax; or al,bl; mov [DAT_008b8ee4],al. mov esi, 0x008b78a0; mov edi, 0x2a; loop. Between Arithmetic/Comparison and Delegation Wrapper — flag setting + array init (0x2a entries at 0x008b78a0). |
| 0x00544720 | 0x00544740 | 32 | jump_table_data | high | 8 function pointers: 0x005445ab, 0x005445bb, 0x005445c8, 0x005445dd, 0x005445f1, 0x00544606, 0x0054461b. Within prev function Vertex Buffer Resource Allocation range. nop padding. |
| 0x00545ff6 | 0x00546010 | 26 | jump_table_data | high | mov edi,edi nop. 4 function pointers: 0x00545ff1, 0x00545f73, 0x00545fa7, 0x00545fe1. Within prev function Audio Volume/Load Computation range. nop padding. |
| 0x00547355 | 0x00547370 | 27 | jump_table_data | high | lea ecx,[ecx] alignment. 4 function pointers: 0x005472e2, 0x005472fe, 0x0054731a, 0x00547336. Within prev function Float-to-Int Switch (Cases 1-4) range. nop padding. |
| 0x0054d00a | 0x0054d030 | 38 | jump_table_data | high | mov edi,edi nop. 9 function pointers: 0x0054cbc7, 0x0054cc13, 0x0054cc53, 0x0054cc8c, 0x0054ce28, 0x0054ce7b, 0x0054cebf, 0x0054cefc. Within prev function D3D Vertex Buffer Creation and Software T&L range. nop padding at end. |
| 0x0054ee72 | 0x0054ee90 | 30 | jump_table_data | high | mov edi,edi nop. 6 function pointers: 0x0054eb54, 0x0054ebf7, 0x0054ec84, 0x0054ed01, 0x0054ed82, 0x0054edfa. Within prev function 2D/3D Triangle Point Test range. nop padding. |
| 0x005504bb | 0x005504d0 | 21 | jump_table_data | medium | 4 function pointers: 0x0055046d, 0x00550453, 0x00550463, 0x0055043a. Within prev function range (0x005503a0). nop padding. |
| 0x00552fa9 | 0x00552fc0 | 23 | jump_table_data | high | lea ecx,[ecx] alignment. 4 function pointers: 0x00552f38 (x2), 0x00552f41 (x2). Within prev function Texture Path Parsing and Dimension Calculation range. nop padding. |
| 0x0055422c | 0x00554260 | 52 | jump_table_data | high | Function pointers: 0x00553feb, 0x005540c7, 0x0055419e, 0x00554223, 0x00554134, 0x0055400e, 0x00554058, 0x005540b4, 0x0055419e (repeat), 0x00554223 (repeat), 0x00554223 (repeat). Within prev function (0x00553fc0) range. nop padding. |
| 0x00554f6a | 0x00554f80 | 22 | jump_table_data | high | mov edi,edi nop. 5 function pointers: 0x00554ed9, 0x00554ee3, 0x00554eed, 0x00554ef7, 0x00554f01. Within prev function (0x00554e90) range. |
| 0x0055678d | 0x005567f5 | 104 | missed_function | high | Old-school x86 code with 55 8b ec (push ebp; mov ebp,esp) prologue — FENTRY-style. Contains MUL (f7 6d 0c = imul dword [ebp+0xc]), ADD (05 00 80 00 00 = add eax,0x8000), SHRD (0f ac d0 10 = shrd eax,edx,0x10), SAR (5a c9 = sar ...), then more: 55 8b ec (another function). Float/int conversion with fixed-point math. Between a 45-byte function and a 101-byte function. |
| 0x0055bdc7 | 0x0055bde0 | 25 | missed_function | medium | nop padding (9 nops). mov eax,[ecx+0x11c]; ret. Then inc eax; mov [ecx+0x48],eax; jmp back (tail call). Between Field Getter at +0x118 and Linked List Indexed Traversal. Small field accessor at +0x11c. |
| 0x0055c9b7 | 0x0055ca40 | 137 | missed_function | high | thiscall: or eax,-1; sub ecx,?; jmp back (prev tail). Then function: push esi; mov esi,ecx; mov eax,[esi+0x1100]; test; push edi; jz. mov edx,[esp+0xc]; mov [esi+0x13e4],edx (field set). mov eax,[esi+0x13b0]; xor edi,edi; test; jle (loop). push ebx; lea ebx,[esi+?]; loop body. Large offset access at +0x1100, +0x13e4, +0x13b0. Between field returner and Enum-to-VTable-Call Mapper. |
| 0x005604c0 | 0x005609de | 1310 | missed_function | HIGH | LARGE (1.3KB). Old-school x86 code: 55 8b ec 83 c4 fc (push ebp; mov ebp,esp; add esp,-4) — standard prologue. push esi; push edi. mov [ebp-4], eax. PUSHF/POP (9c/...). FPU: fild [ebp+0x30], fild [ebp+0x18], fild [ebp+0x28], fild [ebp+0x14]. imul/emul chain: imul [ebp+0x10]; add [ebp+0xc]; add esi. Multiple FPU and integer operations. Between functions at 0x00560410 and 0x005609de. Custom fixed-point math or physics solver fragment. |
| 0x00562509 | 0x00562530 | 39 | jump_table_data | high | lea ecx,[ecx] alignment. 8 function pointers: 0x00562398, 0x005623ae, 0x005623c4, 0x005623da, 0x005623f0, 0x00562439, 0x005624b2, 0x005624c6. Within prev function File Path/Name Lookup range. |
| 0x00564375 | 0x00564390 | 27 | jump_table_data | high | lea ecx,[ecx] alignment. 4 function pointers: 0x00564323, 0x0056432f, 0x0056433b, 0x0056433b (repeat). Within prev function Struct Alloc/Init with Switch-Based Type range. |
| 0x005653ab | 0x005653f0 | 69 | mixed | medium | Function pointers: 0x005652c5, 0x00565261, 0x00565267, 0x0056526d, 0x00565294. Within prev function (0x005651b0) range. Data bytes: 00 04 04 00 04 04 04 04 04 04 04 04 04 04 04 04 04 04 04 04 04 04 04 04 04 (case index/grip mapping). Jump table + tire performance data? |
| 0x0056f657 | 0x0056f7f9 | 418 | missed_function | HIGH | Physics state init. Writes to DAT_008d3988 and surrounding globals: c7 05 88 39 8d 00 f0 fb 8c 00 ([DAT_008d3988] = 0x008cfbf0), c7 05 8c 39 8d 00 b8 fc 8c 00 ([DAT_008d398c] = 0x008cfcb8), c7 05 90 39 8d 00 80 fd 8c 00 ([DAT_008d3990] = 0x008cfd80). These are in the physics state block at 0x8D0000. Between functions at 0x0056f100 and 0x0056f80b. Physics constraint solver state initialization. |
| 0x00579f6b | 0x00579f89 | 30 | data_table | medium | jmp 0 (e9 00 00 00 00). Then mov ecx, DAT_008d3984; jmp (tail call). Then jmp 0 again. mov ecx, DAT_008d3980; jmp (tail call). Between Physics State Zero-Init and a small function. Two tail-call slots with zero-jmp padding. |
| 0x00579ffa | 0x0057a020 | 38 | missed_function | medium | nop padding, push-address-call-pop-ret wrapper, nops, mov ecx, DAT_008d3bf0; jmp (tail call to physics function). Between Single Function Call Wrapper and Struct Zero-Init (4 + 8 Words). Physics wrapper. |
| 0x0057a9d0 | 0x0057aa10 | 64 | missed_function | medium | Function: mov al,[DAT_008d46b8]; mov bl,1; test al,al; jnz. or al,bl; mov [DAT_008d46b8],al. jmp forward. nop padding (6 nops). push-address-call-pop-ret wrapper. nop padding. Between GenericDtorStub and Single Function Call Wrapper — flag setting + wrapper. |
| 0x0057ab43 | 0x0057abb0 | 109 | missed_function | high | thiscall: data bytes first (c4 00 00 00 = field at +0xc4?). then f6 d8 1b c0 40 c2 04 00 = neg al; sbb eax,eax; inc eax; ret 4. Then function: push ebx; mov esi, DAT_008d3bfc; xor ebx,ebx; cmp esi,ebx; jz. push edi; push edi; mov esi,[esi+4]; cmp [edi+0xc],esi; jz. mov edi,[edi]; cmp [ebx],edi; jz. mov ecx,edi; call. Between Pointer Check with Fallback and next function. Physics linked-list node matching. |
| 0x0057adfa | 0x0057ae30 | 54 | missed_function | medium | nop padding (6 nops). push-address-call-pop-ret wrapper. nops. mov ecx, DAT_008d3bf8; jmp (tail call). more nops. call+jmp thunk. Between Single Function Call Wrapper and [PARTIAL] Unknown. Physics wrapper chain. |
| 0x0057af75 | 0x0057afa0 | 43 | missed_function | medium | thiscall: store [eax+0x24]; mov [eax], jmp back (tail). Then thiscall: mov al,[esp+4]; push esi; mov esi,ecx; test al,1; set vtable 0x005b8a40; jz skip. push esi; call. add esp,4; mov eax,esi; pop esi; ret 4. Between Linked List Destruction & Cleanup and Network Packet Constructor — conditional vtable set based on flag. |
| 0x0057b2e4 | 0x0057b330 | 76 | missed_function | medium | thiscall: add esp,4; pop edi; mov eax,1; pop esi; ret 4. Then function: mov edx,[esp+4]; test edx,edx; jl; cmp edx,[ecx+0x24]; jge. mov eax,[ecx+0x18]; test edx,edx; jle; test eax,eax; jz. mov eax,[eax+4]; dec edx; jnz. test eax,eax; jz. ret. Between field returner and Network Connection List Duplication — bounds-checked index walk on linked list at +0x18, length at +0x24. |
| 0x0057c795 | 0x0057c7b0 | 27 | jump_table_data | high | lea ecx,[ecx] alignment. 4 function pointers: 0x0057c71f, 0x0057c744, 0x0057c760, 0x0057c768. Within prev function NetworkSocketCreate range. |
| 0x0057d4ea | 0x0057d5d0 | 230 | jump_table_data | high | mov edi,edi nop. Many function pointers: 0x0057d490, 0x0057d484, 0x0057d48a, 0x0057d46c, 0x0057d472, 0x0057d454, 0x0057d4b4, 0x0057d442, 0x0057d448, 0x0057d4a2, 0x0057d4d2, 0x0057d4ba. All within prev function (0x0057ca10) range. |
| 0x0057ef97 | 0x0057f0c8 | 305 | missed_function | high | IAT call (ff 15 a4 e1 59 00). Then sub esp,0x38; push edi; xor edi,edi; mov ebp,ecx. call (e8 ce 66 00 00). fld [ebp+0xe0]; fild [esp+0x78]; fcomp [DAT_0059ea08]; fnstsw; test. FPU comparison with physics constant. Between VtableDeleteWrapper and NetworkSocketAddressInit — physics/network init function with FPU. |
| 0x005806f9 | 0x00580c10 | 1303 | missed_function | HIGH | LARGE (1.3KB). Moves data around (8b c0 jmp chain). Then: mov ecx,[eax+0x680]; push ebx; push esi; push edi; lea ecx,[ecx+0x480]; mov [esp+0xc],ecx. IAT calls: ff 15 a0 e1 59 00 (socket/network API). test return; cmp 0x80. Between Network Packet Queue Reader and Network Packet Send — network packet send/receive with IAT socket calls. |
| 0x00581939 | 0x005819c0 | 135 | missed_function | high | Function: data bytes (01 cc 00 00 cc 3b ff). Then mov edi,[esp+0xc]; xor eax,eax; cmp edi,?; jz. mov esi,[edi]; xor edx,edx; cmp esi,?; jz. cmp [esi],edi; jz. Continue: mov edx,esi; mov esi,[esi+4]; cmp esi,?; jnz. pop edi; pop esi; ret 8. Then another: cmp [ecx+8],?; ... Linked list node removal by pointer match. Between List Destruction with Handle Close and Linked List Destroy with Vtable Destructor Call. |
| 0x0058326f | 0x005832e0 | 113 | missed_function | high | push ecx; push esi; mov esi,[ecx]; mov [esp+4],ecx; cmp esi,?; jz. push edi; push ebp; mov esi,[esi+4]; mov al,[ebp+8]; test al,al; jz. mov edi,[ebp+0]; test edi,edi; jz. mov ecx,[edi]; test; jnz. push 3; call [eax] (vtable call). Linked list traversal with vtable call on nodes. Between Linked List Node Alloc & Prepend and next function. |
| 0x00584f27 | 0x00584f90 | 105 | missed_function | high | nop padding (8 nops). Function: mov eax,[ecx+0x5a8]; push ebx; push esi; lea ecx,[ecx+0x598]; xor bl,bl; test eax,eax; jz. mov ecx,[esi+0x14]; push ecx; call [IAT] (ff 15 a0 e1 59 00 — socket). test; cmp 0x80000000; conditional. Between a function at 0x00584e30 and Mutex-Guarded Timer Read. Network/socket read with timeout. |
| 0x00585d63 | 0x00585de0 | 125 | missed_function | high | thiscall: push esi; push edi; push 5; mov eax,[esi+0x618]; xor edi,edi; push eax; call [IAT] (ff 15 a0 e1 59 00 — socket). cmp eax,0x10200; jae. sub eax,-1; jz. More socket IAT calls. Between Mutex-Protected Pointer Read + Release and QueueUserAPC Async Procedure Call. Network socket I/O completion check. |
| 0x005861d9 | 0x00586240 | 103 | missed_function | high | thiscall: mov al,[esi+0x5c]; test; jz. mov eax,[esi+0x54]; push eax; call [IAT] (ff 15 a8 e1 59 00 — closesocket/WSACleanup). test; jnz. set [esi+0x54] = 0. pop esi; ret. Then another function: stores values to [eax+?], [ebx+?], [ecx+?]. Between Handle Close & Linked List Cleanup and Linked-List Destruction with SEH + Alloc Cleanup. Network socket cleanup. |
| 0x00586e8d | 0x00586ed0 | 67 | missed_function | medium | Function: mov al,[DAT_008d46b8]; mov bl,1; test al,al; jnz. or al,bl; mov [DAT_008d46b8],al. jmp forward. nop padding. push-address-call-pop-ret wrapper. Between Short Computation / Struct Copy Assignment and Thunk to FUN_00598815. Physics flag setting. |
| 0x00587062 | 0x00587090 | 46 | missed_function | medium | Function: cmp ... jb. pop registers. Then thiscall with call, test byte, conditional cleanup, ret 4. Between Object Init with VTable Setup and Object Copy-Construct from Source. |
| 0x0058768a | 0x005876c0 | 54 | missed_function | medium | nop padding (6 nops). push-address-call-pop-ret wrapper. nops. mov ecx, DAT_008d3e39; jmp (tail call). nops. call+jmp thunk. Between a thunk to FUN_00598815 and Single Function Call Wrapper. |
| 0x00587a5a | 0x00587a90 | 54 | missed_function | medium | nop padding (6 nops). push-address-call-pop-ret wrapper. nops. mov ecx, DAT_008d3e3d; jmp (tail call). nops. call+jmp thunk. Between Thunk to FUN_00598815 and Single Function Call Wrapper. |
| 0x00588a19 | 0x00588a34 | 27 | missed_function | medium | Function: push ebp; mov ecx,[esp+8]; mov eax,[ecx]; push eax; mov eax,[ecx+0x1c]; push eax; mov eax,[ecx+0x18]; push eax; call (e8 79 fe ff ff). add esp,8; pop ebp; ret 4. Between ScriptFrameProcessor and next function. Script frame wrapper with field reads at +0x18 and +0x1c. |
| 0x0058d76e | 0x0058d78e | 32 | jump_table_data | high | 8 function pointers: 0x0058d1ec, 0x0058d0c2, 0x0058d0dd, 0x0058d129, 0x0058d160, 0x0058d168, 0x0058d19d, 0x0058d230. Within prev function (0x0058cf35) range. |
| 0x0058dd3e | 0x0058dd75 | 55 | missed_function | high | FPU/x87 status handler. cmp word [esp], 0x7f02; jz. fld/x87 ops. Compares FPU control word. Handles special float values and FPU status. Between Float Exponent Extract with NaN Guard and FPU Status/Error Handler — FPU exception/status handling. |
| 0x005909c7 | 0x005910a0 | 1753 | missed_function | HIGH | LARGE (1.75KB). sub esp,0x2c; and eax,-0x20; jmp [eax*4 + 0x005e3e75] — jump table dispatch! Contains FPU operations at vector: d8 f0 (fdiv st0,st0?), 83 c4 2c (add esp adjust), cd 06 (int 6???), cd 06 repeated, de f8 (fdivp), 83 c4 2c, c3. Many FPU operation stubs: d8 f0 / d8 f8 / de f0 / de f8 / d8 e0 combinations. Between Extended-Precision Division with Overflow Fixup and Double Arithmetic Wrapper. x87 FPU micro-operation dispatch for extended double precision math! |
| 0x005966e6 | 0x00596716 | 48 | jump_table_data | high | 12 function pointers: 0x005962af, 0x005962fe, 0x00596355, 0x0059637f, 0x005963da, 0x00596451, 0x00596487, 0x005964d1, 0x005964b0, 0x00596535, 0x0059651f, 0x005964eb. Within prev function (0x00596245) range. |
| 0x00598815 | 0x00598994 | 383 | missed_function | HIGH | Physics resource reference counting. mov eax, [DAT_0059d218]; call (e8 b9 1d ff ff). push ecx; push ecx; push ebx; push esi; mov [ebp-0x14],edi; xor esi,esi; lea ecx,[ebp-0x10]; mov [ebp-0x10],esi; call (e8 1a 1d 00 00). cmp [DAT_009ef49c],esi; jl. inc [DAT_009ef49c]. xor bl,bl; loop. Between PhysicsThunk and Ref Count Decrement with Cleanup. Reference counting with physics global. |
| 0x00599958 | 0x00599ad9 | 385 | missed_function | HIGH | Same pattern as GAP 563. mov eax, [DAT_0059d378]; call. push ecx; push ecx; push ebx; push esi; mov [ebp-0x14],edi; xor esi,esi; ... cmp [DAT_00a04e5c],esi; jl. inc [DAT_00a04e5c]. Between Thin Forwarding Wrapper and Ref Count Decrement with Check. Reference counting with different physics global. |
| 0x0059ac63 | 0x0059ac7f | 28 | missed_function | medium | thiscall: push esi; mov esi,ecx; call; test byte; conditional call cleanup; pop esi; ret 4. Between std::locale::facet Destructor and Object Teardown with Iterator Cleanup. |
| 0x0059bacc | 0x0059bae8 | 28 | missed_function | medium | thiscall: push esi; mov esi,ecx; call; test byte; conditional call cleanup; pop esi; ret 4. Between Type-Info Destructor and a forwarding function. |
| 0x0059ca45 | 0x0059ca69 | 36 | exception_handler | high | MSVC exception handler. Starts with 0xCC (int 3) padding. Then: mov eax,[ebp-0x114]; push eax; call (e8 73 b1 fe ff). pop ecx; ret. Then: lea ecx,[ebp-0x138]; jmp (tail call). Between ExceptionHandlerThunk and C++ Exception Handler Wrapper. SEH exception filter/handler. |
| 0x0059cab2 | 0x0059cb33 | 129 | exception_handler | high | MSVC exception handler. 0xCC padding. Then: mov eax,[ebp-0x20]; push eax; call. pop ecx; ret. mov eax, DAT_005babb8; jmp (tail). More 0xCC padding. lea ecx,[ebp-0xb0]; jmp. Between CxxFrameHandlerWrapper and C++ Exception Handler Wrapper. SEH handler wrapper. |
| 0x004049cc | 0x00404ac0 | 244 | missed_function | medium | Game logic code accessing globals (DAT_001c047d00 multiple times). Starts with 4 NOPs then valid instructions. No xrefs — possibly dead code or rarely-called init path. |
| 0x0040c5fe | 0x0040c610 | 18 | jump_table_data | high | 4 function pointers: 0x0040c5f1, 0x0040c5fd, 0x0040c5f1, 0x0040c5e8. Adjacent to Camera Mode Change Request func. Switch jump table. |
| 0x0040f52c | 0x0040f550 | 36 | jump_table_data | high | 7 function pointers: 0x0040f4d5, 0x0040f4f2, 0x0040f50f, 0x0040f4d5, 0x0040f4f2, 0x0040f50f, 0x0040f4c2. Adjacent to Mode Dispatch with Switch (0-6). Two case targets repeat (shared code). |
| 0x00420c43 | 0x00420cf0 | 173 | jump_table_data | high | 12+ function pointers with 7-byte stride pattern: 0x0042087c, 0x00420883, 0x0042088a... Incrementing by 7 each — switch case targets for Position Change Detector. Leading 0x90 padding. |
| 0x0042f2ef | 0x0042fd00 | 2577 | missed_function | very high | Classic prologue (55 8b ec 83 e4 f8 83 ec 14). Stack frame with alignment. imul by 0x0b, shl by 6, cmp with 0x0a. References jump table (ff 24 95). Vehicle setup file parsing function — between Setup Value Formatting and Vehicle Setup File Writer. Large, complex. |
| 0x0044c949 | 0x0044c960 | 23 | missed_function | high | Small wrapper: push 0x0044c960, call thunk_FUN_0057cb00, pop ecx, ret. Function pointer call pattern. Padding before and after. Part of collision init sequence. |
| 0x0044cd09 | 0x0044cd20 | 23 | missed_function | high | Same pattern as gap 95: push 0x0044cd20, call, pop, ret. Collision material init wrapper. |
| 0x0044d486 | 0x0044d4a0 | 26 | missed_function | high | Same pattern as 95-97: push 0x0044d4a0, call, pop, ret. Collision grid init wrapper. |
| 0x00458de4 | 0x00459010 | 556 | missed_function | high | Large function. First 11 bytes = tail of CollisionResponseFilter (pop ebx; add esp, 0x500; ret 8). Real function starts at ~0x00458def: sub esp, 0x30; push ebx/esi; mov esi, ecx. Accesses struct offsets +0x18, +0xa0. Component/transform initialization between collision and component code. |
| 0x00466b17 | 0x00466d60 | 585 | missed_function | high | Indirect call through function pointer [0x0059e3b0] (vtable dispatch). Reads global 0x007c7064. Conditional branches, multiple function calls. No xrefs — likely vtable method never statically called. |
| 0x0046b9ac | 0x0046ba20 | 116 | missed_function | high | Member function (push esi; mov esi, ecx). Writes -1 to field +0x178. Reads RaceMode global (DAT_007d0410), compares to 5. References string buffers (MessageBuffer at 0x005ec4cc, LoadPath at 0x005c6aa0). Session/UI init logic. |
| 0x0047a115 | 0x0047aa60 | 2379 | missed_function | very high | Starts with ~6 ambiguous bytes, then clear function: mov ecx, [ecx+0x104]; lea eax, [ecx-0xc0]; cmp 7; ja; jmp [4*eax+0x0047a16c] — jump table dispatch! Case entries return global addresses (0x007d14b8, 0x007d14b4, etc.). Large state/value lookup function. |
| 0x00485a65 | 0x00485a90 | 43 | missed_function | medium | 1 byte 0x00 padding + ~7 bytes previous-function tail (add esp, 4; pop esi/eax/ebx; ret 4). Then valid member function: push esi; mov esi, ecx; call; test [esp+8], 1; conditional free. Small destructor wrapper. |
| 0x0048e4a9 | 0x0048e600 | 343 | missed_function | high | Starts with OR operation to global 0x005ec68b00 (static init). Then member function: reads struct offsets +0xb0, +0xfc. Falls back to LoadPath global 0x005ea438 if null. Calls string/init functions. Font/UI resource load function continuation. |
| 0x004952d6 | 0x00495300 | 42 | missed_function | medium | 3 bytes previous-function tail (leave; pop edx). Then valid member function: push esi; mov esi, ecx; call; test [esp+8], 1; conditional call; pop esi; ret 4. Small destructor/cleanup wrapper. |
| 0x004a042a | 0x004a0490 | 102 | missed_function | high | 6 bytes ambiguous, then clear function: reads RaceMode (DAT_007d0410), compares to 4 and 5, loads globals 0x007cd25c and 0x007cd8c0, calls functions, conditional branches. Main menu/mode dispatch init. |
| 0x004ae46c | 0x004ae490 | 36 | jump_table_data | high | 6 function pointers: 0x004ae446, 0x004adf29, 0x004ae097, 0x004ae205, 0x004ae2f4, 0x004ae398. Adjacent to Driving Mode Parameter Setup. Switch table for driving mode cases. |
| 0x004bdbde | 0x004bdc10 | 50 | missed_function | high | 2 bytes padding, then function: lea esi, [ecx+0x900]; push edi; loop 64 times (mov edi, 0x40); calls init function at each step; sub esi, 0x24 per iteration. Audio mixer channel batch init (between AudioMixerChannelInit and the 65-call loop). |
| 0x004c81ee | 0x004c82c0 | 210 | missed_function | high | 2 bytes padding, then object initializer: xor-zeroes 6 fields at offsets 0,4,8,0xc,0x10,0x14; sets field +0x18 to float 100.0f (0x42c80000). Then more code follows. Multiple small init functions. |
| 0x004dad0a | 0x004dad30 | 38 | jump_table_data | high | 6 function pointers: 0x004dace9, 0x004dac44, 0x004dac65, 0x004dac86, 0x004daca7, 0x004dacc8. Adjacent to Size/Offset Table by Mode. Switch table for mode offset lookup. |
| 0x004ed35d | 0x004ed380 | 35 | mixed | high | jump_table_data: 4 entries (0x004ed26f, 0x004ed2c9, 0x004ed2d7, 0x004ed332) for Repair/Service State Dispatcher switch. Then data_table: 15 bytes of small integers (00 00 00 00 01 02 03 03 03 03 03 03 03 03) — repair cost/lookup table. |
| 0x0051fb0a | 0x0051fb1e | 20 | missed_function | medium | Stack-aligning thunk: lea esi, [esi] (6-byte NOP); push ebx; mov ebx, esp; sub esp, 8; and esp, -16; add esp, 8; jmp +3. Between 4x4 reflection matrix multiply and QuaternionToRotationMatrix. Alignment prologue that jmps into next function. |
| 0x00526b35 | 0x00526b55 | 32 | jump_table_data | high | 8 function pointers: 0x00526970, 0x005269c5, 0x005269d9, 0x005269ed, 0x00526a0c, 0x00526a1d, 0x00526a3c, 0x00526a5b. Entire gap = jump table. Adjacent to Matrix Interpolation/Blend. 8-way switch table for matrix/interpolation mode. |
| 0x0054279a | 0x005427d0 | 54 | jump_table_data | high | 12 function pointers: entries point to addresses 0x0054271d-0x00542777 (previous function area). Adjacent to Audio Emitter Create. Boundary issue — table points to locations BEFORE gap, suggesting previous function endpoint needs adjustment. |
| 0x00553039 | 0x00553050 | 23 | jump_table_data | high | 5 function pointers: 0x0055302f, 0x00553025, 0x0055301b, 0x00553011, 0x00553007. All point backward into previous function (Switch-Based Parameter Field Set). Switch table for parameter field dispatch. |
| 0x0057a98a | 0x0057a9b0 | 38 | missed_function | high | Two small thunk/wrappers: (1) push 0x0057a9a0; call; pop; ret. (2) mov ecx, 0x008d3bf4 (physics state block address!); jmp relative. Second thunk loads physics block ptr into ecx then jumps. Between Entity Constructor Wrapper and GenericDtorStub. |
| 0x0057d84d | 0x0057d890 | 67 | mixed | high | jump_table_data: 10 function pointers (0x0057d7de...0x0057d83c, stride varied). Adjacent to Buffer Unpack with Size Check. Then small data_table: 00 00 09 09 09 09 — 2 zero bytes + 4 bytes 0x09 (bitmask or flag values). |
| 0x0058c0f5 | 0x0058c1b1 | 188 | missed_function | high | Reads physics state block global 0x008d5a40, uses min/max logic (compare with 0x14, clamp to 0x200). Writes result back. Calls allocation function, stores result to 0x008d4a24. Physics buffer allocator — allocates size based on current vs requested capacity. |
| 0x0059ad07 | 0x0059ad31 | 42 | missed_function | high | Singleton/test-and-set pattern: test byte [0x008d46b8], 1; jnz skip; set byte; call 0x0059ad31 (Thunk). Same for byte [0x008d5a64]. Physics state one-time initialization guard. Double gate for two subsystems. |
| 0x00405044 | 0x004053e0 | 924 | missed_function | high | Contains multiple functions: first fragment (sub ebx, global load, ret), then constructor-like body with calls, output param write, return 1 on success. 924B likely contains 2-3 functions. |
| 0x004085c8 | 0x004085f0 | 40 | missed_function | high | Two tiny functions: 8-byte fld global + ret stub, then ~28-byte constructor (sets vtable 0x59e634, conditionally calls 0x587b70). Called by Simple Sound Playback context. |
| 0x0040f5da | 0x0040f600 | 38 | jump_table_data | high | 7 jump targets (0x0040f58f×2, 0x0040f5a8×2, 0x0040f5c1×2, 0x0040f562) into UI/Camera Mode Dispatch. |
| 0x00418bfc | 0x00418c10 | 20 | jump_table_data | high | 4 jump targets (0x00418ba4, 0x00418bbc, 0x00418bd1, 0x00418be6) into Score/Threshold Gate Check. |
| 0x004305e4 | 0x00430600 | 28 | jump_table_data | high | 4 jump targets (0x004303d1, 0x004303d8, 0x004303e4, 0x004303f0) into Vehicle Setup File Writer. |
| 0x0044b8f1 | 0x0044b910 | 31 | jump_table_data | high | 5 jump targets (0x0044b816, 0x0044b778×3, 0x0044b6f3) with duplicate entries. For Bezier Patch Tessellation renderer geometry dispatch. |
| 0x0044cd21 | 0x0044cd54 | 51 | missed_function | high | Contains thunk patterns PLUS two global writes: mov [0x007ca50c], 0x21 and mov [0x007ca510], 0x00. Clearly contains code. Collision constructor context. |
| 0x0044d0e1 | 0x0044d100 | 31 | mixed | medium | Similar pattern to GAP 138 — ret/call/jmp thunks with nop padding. Possibly incremental linking glue for collision system. |
| 0x0045954b | 0x00459830 | 741 | missed_function | high | Starts with ASCII "MYTH\0" (class/debug marker), then proper function prologue (sub esp,0x154, push ebx/esi/edi), fld from 0x59f030. Large function body with x87 FPU operations. Likely physics struct init. |
| 0x00461c6e | 0x00461cc3 | 85 | missed_function | high | Nops then push 0x1ce60, mov esi ecx, constructor-like pattern (calls 0x5e12880, calls 0x5b6ab8), stores ptr to [esi]. SessionConfig context. |
| 0x0046c03b | 0x0046c6e5 | 1706 | missed_function | high | Starts with ASCII "MYTH\0", then large function (dec/cmp field at +0x174, conditional push 1 + call, reads global 0x5cc9e8). SetIntegerField+2 context. Contains loop logic and conditional branches. |
| 0x0047455a | 0x004750f0 | 2966 | missed_function | high | Largest gap. Call to 0x406658, sets vtable 0x5a3b40, sets fields +0x1c03 (0x7cfd58) and +0x2403 (0x7cfd03). Constructor-like init with extensive field initialization. SessionEnter/SessionInit context. |
| 0x00485ad6 | 0x00485b90 | 186 | missed_function | high | Function body with conditional on field +0x174, call to allocator (0x5c10dc), then call to 0x5b3943. Destructor/GlobalShutdown context. |
| 0x0048a9e8 | 0x0048aa40 | 88 | missed_function | high | Nops then call to 0x5bf7f8, xor eax,eax; ret (simple stub). Then second function with param manipulation and call. UI Scroll List context. |
| 0x0049624d | 0x00496280 | 51 | jump_table_data | high | 10 jump targets (0x004960a9, 0x00496179, 0x004961be×3, 0x004960ca, 0x004960df, 0x004960f4, 0x0049610d, 0x00496122, 0x0049613b, 0x00496151) into Car Crash Damage Processing switch. |
| 0x0049ad73 | 0x0049adb0 | 61 | missed_function | high | Bounds check function: checks param_1 against [ecx+0x0c] (max) and [ecx+0x10] (min), param_2 against [ecx+0x04] and [ecx+0x08]. Returns 1 if both in range. String/Path Processing context. |
| 0x004af1f4 | 0x004af220 | 44 | jump_table_data | high | 8 jump targets (0x004aea0a, 0x004aec76, 0x004aeee2, 0x004af046, 0x004af1c7, 0x004af1d6×2, 0x004af1e5) into AI Difficulty Configuration per Race Mode. |
| 0x004b5be0 | 0x004b5c50 | 112 | mixed | high | Switch dispatch function: mov eax,[esp+4], cmp eax,4, mov [ecx+0x9ac],eax, ja +0x45, jmp [eax*4+0x4b5c38]. Jump table follows at end of gap (4 entries × 4B). DestroyUIWidgetHierarchy context. |
| 0x004c902c | 0x004c91d0 | 420 | missed_function | high | Constructor: loads global 0x5ace14, calls function, zeros fields +0x1c/+0x20/+0x24/+0x28, sets vtable 0x5ace3c. Then fld/fcomp comparison branch. Validation/Constructor context. |
| 0x004d48f6 | 0x004d4a58 | 354 | missed_function | high | Function body with call through global [0x5a43cc] (conditionally), multiple param handling, conditional returns. Countdown Timer context. |
| 0x004ee133 | 0x004ee150 | 29 | jump_table_data | high | 4 jump targets (0x004edbaa, 0x004edf5e, 0x004ee025, 0x004ee081) into FuelConsumptionAndWear and EngineWear/FailureSimulation. Fuel/engine state switch. |
| 0x004ff0d7 | 0x004ff127 | 80 | missed_function | high | x87 FPU comparison: fld [ecx+0x20], fcomp [0x59e440], fnstsw ax, sahf, conditional return 2. Two such comparison functions. ValueClampRange context. |
| 0x00526c88 | 0x0052704a | 962 | mixed | high | First 32B: 8 jump targets (0x00526b92-0x00526bb2) into 3DNow Vector Transform. Remainder: 3DNow instructions (femms, movq) — function body for 3DNow! math pipeline. |
| 0x00531147 | 0x00531250 | 265 | jump_table_data | high | ~66-entry jump table (0x00530ca4, 0x00530cb5, 0x00530cc7...) into Bitstream Texture Decompression. Variable stride addresses matching variable-length code targets. |
| 0x00553cc5 | 0x00553db0 | 235 | missed_function | high | Function body with arithmetic: sub, mul (0f af), add operations, multiple push param setup, call. Struct Init with Default Values context. |
| 0x00563f0f | 0x00563f70 | 97 | mixed | high | 4 dispatch entries (0x00563ed0-0x00563ee5) then function body: loads globals 0x8d46b0, 0x8d46b4, reads [ecx] and [edx+0x80], pushes params, calls near. Physics Sign/Direction context. |
| 0x0057ed35 | 0x0057ee80 | 331 | missed_function | high | Large function: push ebx/edi, xor ebx, test [edi+0xb10] against null, read [edi+0xb14], call through [0x59e1a0], compare result to 0x8000. Thread/Mutex context. |
| 0x00586634 | 0x00586670 | 60 | missed_function | high | Two parts: (1) stores to [esi+4] and [esi+8], jmp back into prev function (tail merge); (2) duplicate of GAP 168 pattern — global flag toggle at 0x8d46b4. Node Destruction context. |
| 0x0059b050 | 0x0059b07a | 42 | missed_function | high | Two set-once global flag init patterns: test byte [0x8d46b4],1; jnz skip; or byte [0x8d46b4],1; call near. Same for [0x8d5a64]. Singleton/init guard. |
| 0x00408712 | 0x00408740 | 46 | jump_table_data | high | 14-entry jump table for prev func Sound Effect Playback switch; addresses 0x00408607-0x0040863a, then nop padding |
| 0x0040d04d | 0x0040d080 | 51 | jump_table_data | high | 11-entry jump table for Game Action State Machine switch; addresses 0x0040ce03-0x0040d01b, prefixed by 3-byte NOP (lea ecx,[ecx+0]) |
| 0x00418da0 | 0x00418db0 | 16 | missed_function | high | Vtable thunk: e8 0b (call next func) + e9 26 (jmp forward) + 6 nops — standard 2-instruction thunk pattern |
| 0x0042145b | 0x00421470 | 21 | mixed | high | "MYTH\0" string literal (4D 59 54 48 00) at start, followed by thunk pattern (e8 0b + e9 16) + nop padding |
| 0x0044c5c9 | 0x0044c5e0 | 23 | mixed | high | First 4 bytes = float 1.0 (0x3f800000), then 2 bytes (59 c3 = pop ecx; ret) as standalone helper, then thunk pattern + nops |
| 0x0044c9a9 | 0x0044c9c0 | 23 | missed_function | high | Nop-aligned thunk: push addr of next function (0x0044c9c0) + call + pop ecx + ret — call wrapper for collision init |
| 0x0044d129 | 0x0044d140 | 23 | missed_function | high | Same pattern: nop-aligned thunk pushing next func addr (0x0044d140) — call wrapper for collision block 0x6C init |
| 0x0044d4e6 | 0x0044d500 | 26 | missed_function | high | Same pattern but more nops: push next func addr (0x0044d500) + call + pop + ret — call wrapper for collision state 17 init |
| 0x00461f68 | 0x00461f90 | 40 | mixed | high | 3 parts: (a) caller with rol bl,n; ret; mov eax,1; ret pattern, (b) vtable dispatch code at [eax+0x1b79c], (c) epilogue (pop esi; mov al,1; pop edi; add esp,0x40; retn 4) — likely 2 small functions merged |
| 0x0046712f | 0x00467260 | 305 | jump_table_data | high | 4-entry jump table (0x00467103-0x0046712c) followed by zero-padding and repeating 0x02 byte array — parallel case-index lookup data for Switch on Action ID function |
| 0x00475116 | 0x00475140 | 42 | missed_function | high | Two functions: (a) vtable thunk (mov ecx,esi; call [eax+0x38]; jmp back — 6 bytes), (b) thiscall function with param bit test (test [esp+8],1; jz; conditional push esi+call; retn 4) |
| 0x0047abb3 | 0x0047b730 | 2941 | missed_function | high | VERY LARGE. First 10 bytes may be data/tail from Return 0 Stub; real function starts at offset +10: sub esp,0x40; push ebx/ebp/esi; mov esi,ecx; mov eax,[esi+0xe0]; mov ecx,[esi+0x40]; call — big function likely spanning multiple sub-operations. Contains multiple interior call targets, potential sub-function boundaries |
| 0x0048ab24 | 0x0048b024 | 1280 | missed_function | high | Large gap. First function: vtable setter (mov [esi],0x005abe28; mov eax,esi; pop esi; ret) — constructor stub. Then full thiscall constructor: push ecx; push esi; lea eax,[esp+4]; push eax; mov esi,ecx; zero field; two sub-calls — constructor for large pool/list object. Likely contains additional functions |
| 0x0048e858 | 0x0048e890 | 56 | missed_function | high | Valid thiscall function: push esi; mov esi,ecx; test field at [esi+0xe8]; if non-null jump to vtable tail call through [eax+0xa0]; else load [esi+0x40] and call method — conditional dispatch with vtable fallback |
| 0x0049af84 | 0x0049afa0 | 28 | missed_function | high | Two small helpers: (a) mov al,1; pop ebx; retn 12 — returns true, (b) mov al,bl; pop ebx; retn 12 — returns byte param in al. Plus thunk pattern + nops |
| 0x004a11bb | 0x004a11d0 | 21 | mixed | medium | First 5 bytes (e8 99 54 f6 ff) = backward call tail of prev Global Flag Clear function; then thunk pattern (e8 0b + e9 16) + nops |
| 0x004b6059 | 0x004b6130 | 215 | missed_function | high | First 5 bytes = tail of prev LinkedBufferTransfer (pop esi; pop ebp; jmp back). Then valid switch-dispatch function: push ebx; mov ebx,ecx; call; mov eax,[ebx+0x9a4]; cmp eax,4; ja default; jmp [eax*4+0x004b6118] — jump-table dispatch on struct field at +0x9a4 with cases setting field at +0x9b4 |
| 0x004bec05 | 0x004bec55 | 80 | missed_function | high | AI/collision helper: loads arg at [esp+0x20]; fld [ebp+0x350]; fadd [edi+0x1a0]; fstp [edi+0x1a0]; then loads struct ptr from [eax+edi]; checks [esi+0x32c8] for -1 sentinel; conditional far jump — between AI Overtake and EngineFailureCheck |
| 0x004d5c2e | 0x004d5c40 | 18 | missed_function | high | Standard thunk: 2 nops + e8 0b (call next function Short Computation) + e9 16 (jmp into function body skipping init) + nops |
| 0x004db0b9 | 0x004db0e0 | 39 | missed_function | high | Small signed average helper: reads [ecx+0x10], increments, stores, does (value+sign)/2 via cdq+sub+ sar, stores at [ecx+0x14], returns 0. Also second small function returning 0 at end |
| 0x00504f3a | 0x00504f5a | 32 | jump_table_data | high | 8-entry address table: 0x00504cd6, 0x00504c46, 0x00504c4f, 0x00504c58, 0x00504c61, 0x00504c6a, 0x00504c73, 0x00504c7c — all within COM Interface Vector Processing function range |
| 0x0051fea4 | 0x0051febe | 26 | missed_function | high | Stack alignment prologue helper: two 7-byte NOPs (lea esi/edi,[esi/edi+0]), push ebx; mov ebx,esp; sub esp,8; and esp,-16 (16-byte stack alignment); add esp,8; jmp forward — __alloca/___chkstk-style alignment stub |
| 0x0053554c | 0x00535560 | 20 | mixed | medium | 4 nops + push 1; xor edx,edx; call backward; ret — small call wrapper. Remaining bytes (c8 e8 f9 10 ed ff) may be start of next function spillover or data |
| 0x00545b8a | 0x00545bb0 | 38 | missed_function | high | Two small helpers: (a) AND [ecx+0xEC], 0xFFFF7FFF — clears bit 15 (flag bit), ret; (b) OR [ecx+0xEC], 0x8000 — sets bit 15, ret. Toggle a flag at struct offset +0xEC |
| 0x00564081 | 0x00564110 | 143 | missed_function | high | First 8 bytes = 2 small return helpers (jp + or eax,-1 + add esp,8 + ret / xor eax,eax + add esp,8 + ret). Then name comparison function: loads global DAT_008d46b4 (hash table), compares string at [ecx] against name at [eax], calls with 0x005ea438 (LoadPath) — PhysicsObject name lookup |
| 0x0057aa1a | 0x0057aa50 | 54 | missed_function | high | 3 wrappers: (a) nop-align + push 0x0057aa30 + call + pop + ret — indirect caller; (b) mov ecx, DAT_008d3bfa + jmp forward — tail call with global this; (c) e8 0b + e9 16 + nops — standard thunk |
| 0x00586c86 | 0x00586ca0 | 26 | missed_function | high | Two helpers: (a) mov eax,1; pop esi; pop ecx; retn 12 — returns 1 with stack cleanup; (b) mov eax,[ecx]; inc eax; cmp eax,6; mov [ecx],eax; setl al — increments counter at [ecx], caps at 6 |
| 0x0058d857 | 0x0058d9be | 359 | missed_function | high | Large x87 FPU logarithm function: jump at start (eb 02 bypassing xor eax,eax), then fyl2x (y*log2x), fldl2e (log2(e)), fld1, faddp, fcomi. Between Read-2-Byte-Value and pow(2,x)/exp2 via f2xm1 — log/exp math family |
| 0x004058cf | 0x00405900 | 49 | missed_function | high | Constructor/destructor: 90 NOP then 56 8bf1 (thiscall prologue), sets vtable 0x0059e4b4, reads +0x04 field, conditionally calls two functions, ends 8bc6 5ec20400 |
| 0x0040d0ea | 0x0040d100 | 22 | jump_table_data | high | Switch table: 8bff + 4 addresses (0x0040d0ca-0x0040d0e2) + 4-byte 90 NOP tail |
| 0x0040fd81 | 0x0040fda0 | 31 | padding | high | Pure alignment: 15×90 NOPs + e9 rel32 jump (to ~0x00459541) + more NOPs |
| 0x00421566 | 0x004216f0 | 394 | missed_function | high | Previous function epilogue (8b442408 5d5b 83c454 c3) then new function: 56 8bf1 (thiscall), reads +0xb0 and +0xa8 fields, calls free function on each non-null — destructor/dealloc pattern; 394 bytes |
| 0x0043194a | 0x004319c0 | 118 | missed_function | medium | Code belonging to SetContactConstraint (prev func): 7e e8 (jle backward into prev function), then physics collision FPU code with globals DAT_0059eac8, DAT_00595c38, DAT_0059eac0; Ghidra excluded this tail from SetContactConstraint |
| 0x0044c9c1 | 0x0044c9f4 | 51 | mixed | high | Data fragment (c94400) + thunks + global init: mov [DAT_007cccb0]=11, mov [DAT_007cccb4]=0; collision State init context |
| 0x0044cd81 | 0x0044cdb4 | 51 | mixed | high | Data fragment + thunks + global init: mov [DAT_007cd0f8]=0x22, mov [DAT_007cd0fc]=0; between Collision Init Delegator and CollisionScaleInit |
| 0x0044d510 | 0x0044d520 | 16 | padding | high | Same thunk pair pattern as 0x0044d150; linker alignment |
| 0x0045b2e4 | 0x0045b360 | 124 | mixed | medium | Game Main Entry tail: cmp ebx,8/jle backward; epilogue (pop edi/esi/ebx); then thunks + NOPs + mov ecx DAT_007cd204 + jmp (thunk) + push 0x0045b320 (next func setup) |
| 0x004672b6 | 0x004677e0 | 1322 | missed_function | high | Major function: call+jmp loop, then 56 8bf1 (thiscall), 2D array calc (eax*11+ecx)*64 + base 0x7c5770, writes to [esi+0x320]; 1322 bytes — multiple functions possible |
| 0x0046c7a6 | 0x0046cb00 | 858 | missed_function | high | Loop tail then function: string/array scan with globals 0x007cd2b8/0x007cd470, counts non-minus-one entries in loop to 104 (0x68); 858 bytes |
| 0x0047be6e | 0x0047be90 | 34 | missed_function | high | Constructor: 90 90 (NOP), 56 8bf1 (thiscall), calls func, sets vtable 0x005a6788, zeros [esi+0x174], returns this (8bc6 5e c3) |
| 0x004866db | 0x00486710 | 53 | missed_function | high | "MYTH\0" string prefix + setter with dirty flag: compares [ecx+0x84] with param, if changed writes it, zeros [ecx+0x80], calls vtable method at +0x2c offset |
| 0x0048ea31 | 0x0048ea60 | 47 | missed_function | medium | 4 data bytes (da320b00 = 0x000b32da?) + prev func tail + multi-field setter: writes 4 params to struct at +0x1c, +0x20, +0x24, +0x28; returns c21000 (ret 16) |
| 0x0049787b | 0x00497890 | 21 | jump_table_data | high | Switch table: 90 NOP + 5×4-byte addresses (0x00497817-0x0049786c) pointing into previous function range |
| 0x004a11da | 0x004a11f0 | 22 | padding | high | Same callback registration thunk pattern: push 0x004a11f0 + call + pop ecx + ret |
| 0x004b0153 | 0x004b0170 | 29 | jump_table_data | high | Physics init switch table: 90 NOP + 4 addresses (0x004af3bb, 0x004af824, 0x004afc94, 0x004aff29) referencing Physics Parameter Initialization labels |
| 0x004bf380 | 0x004bf390 | 16 | jump_table_data | high | Switch/vtable: 4 addresses (0x004bf120, 0x004bf340, 0x004bf371, 0x004bf120) with first/last same; between AI Behavior Init/Tick and AI Driver Sorting |
| 0x004c9339 | 0x004c94d0 | 407 | missed_function | high | Constructor: prev func tail then sets vtable 0x005ace4c, zeros +0x1c/+0x20/+0x24, returns this; more code follows; 407 bytes total |
| 0x004db139 | 0x004db420 | 743 | missed_function | high | Physics constructor(s): clc + mov ebp,ecx (alignment + prologue), sets vtable 0x005acf5c, init fields at +0x10 (from global 0x5acf5c), +0x14=-1.0f, +0x18=1, +0x1c=0; second variant sets +0x14=20.0f; 743 bytes |
| 0x004f0d0e | 0x004f0d20 | 18 | jump_table_data | high | Vehicle setup switch table: 8bff + 4 addresses (0x004f078e, 0x004f0475, 0x004f04a1, 0x004f0b8f) within Vehicle Setup Init/Per-Frame Update |
| 0x0051ff71 | 0x0051ff8e | 29 | missed_function | high | SSE stack alignment prologue: 7-byte NOPs (lea esi,[esi]; lea edi,[edi]), then 53 8bdc 83ec08 83e4f0 83c408 eb03 — MSVC SSE alignment pattern; between Quaternion Transform and SSE Matrix-Vector Transform |
| 0x00527ec5 | 0x00527eed | 40 | jump_table_data | high | Allocator switch table: 10×4-byte addresses in 0x005277xx-0x00527exx range; previous function is Multi-Block Memory Allocator |
| 0x00545f23 | 0x00545f40 | 29 | jump_table_data | high | Bitfield flag switch table: 90 NOP + 4 addresses (0x00545e32-0x00545e5c) + 90 NOPs; previous function is Bitfield Flag Propagation |
| 0x005542af | 0x005542f0 | 65 | jump_table_data | high | Enum-to-offset switch table: 90 NOP + 13 addresses in 0x005542xx range (0x00554273-0x005542aa×6); previous function is Enum-to-Field-Offset Setter |
| 0x0057aa67 | 0x0057aaf0 | 137 | missed_function | medium | Physics flag code: thunk (push+call+ret) + NOPs + reads DAT_008d3bfb (physics state byte), test-and-set pattern, references DAT_008d3bfc, loop to 10; physics state block code |
| 0x0057f158 | 0x0057fb90 | 2616 | missed_function | high | Network socket code: call [0x0059e33c] (indirect), then 56 8bf1 57 33ff (thiscall prologue), reads [esi+0xaf4]/[esi+0xaf8], calls [0x0059e1a0], checks result vs 0x80; between NetworkSocketAddressInit and WinsockInit; 2616 bytes — one of largest gaps |
| 0x0058db63 | 0x0058dc29 | 198 | missed_function | high | FPU utility collection: 4+ tiny helpers — (1) call+fxch+fstp+ret, (2) call+jmp loop, (3) fstp×2+fldz+ret (load 0.0), (4) fstp×2+fld1+ret (load 1.0); then longer FPU tbyte load/store code |
| 0x0059bffd | 0x0059c0ac | 175 | missed_function | high | CRT memcmp/memory compare: cc cc cc (INT3 padding) then standard memcmp — check null, alignment test (and edx,3), byte-by-byte comparison loop; between __CxxThrowException_8 and next func |
| 0x00405a46 | 0x00405b00 | 186 | missed_function | high | Audio-related function with struct field zeroing (`c7465800000000`) — no xrefs but valid code between StopAudioSample and Audio Resource Release. MSVC `sub esp` + `push regs` prologue pattern. |
| 0x00408e1b | 0x00409440 | 1573 | missed_function | high | Large function starts with embedded "MYTH\0" identifier string then standard MSVC prologue (`53 55 56 57`). Between Conditionally call subsystem and View/Camera Mode Dispatch. Calls FUN_005881C0 and FUN_005968B0. Likely a scene/view resource parser or setup function. |
| 0x00410f44 | 0x00410f60 | 28 | jump_table_data | high | 6 function pointer dwords (0x00410dxx range). Between Wheel Controller Input Decoder and SceneNodeDecoder. Jump table for input decoding switch. |
| 0x00419c0a | 0x00419c50 | 70 | mixed | medium | 3 function pointers (jump table) followed by 29-byte byte lookup table (`01 01 01 01 01 01 01 01 01 01 02 02 01 02 02 02 02 01 02 02 02 02 02 01 02 02 02 02 02`). Between AI Retirement/Vehicle Failure and Per-Driver Race Commentary. Encoding/lookup for AI commentary state mapping. |
| 0x00431ba2 | 0x00431bc0 | 30 | missed_function | medium | Small thunk with possible tail bytes from previous function. Contains `call` + `jmp` thunk sequence and NOPs. Between Setup Date/Angle Display Format and another Thunk. |
| 0x0044c649 | 0x0044c660 | 23 | missed_function | high | Static initialization wrapper: `push 0x0044c660; call 0x00587b32; pop ecx; ret`. Passes struct address to shared init function. One of 5 identical patterns (gaps 266-270). |
| 0x0044cdc9 | 0x0044cde0 | 23 | missed_function | high | Static initialization wrapper: `push 0x0044cde0; call 0x00587b32; pop ecx; ret`. |
| 0x0044d189 | 0x0044d1a0 | 23 | missed_function | high | Static initialization wrapper: `push 0x0044d1a0; call 0x00587b32; pop ecx; ret`. |
| 0x0045b3dd | 0x0045b400 | 35 | missed_function | high | Conditional destructor wrapper. Takes bool param, conditionally calls `Destructor with Resource Cleanup` (next function at 0x45b400), returns this pointer. Prologue: `56 8b f1` (push esi, mov esi, ecx). |
| 0x00462de1 | 0x00462e00 | 31 | jump_table_data | high | 5 function pointer dwords (0x00462db1-0x00462dd1 range). All targets within prev function (Enum-to-Enum Translator). Jump table for that function's switch. |
| 0x0046cb0b | 0x0046cb50 | 69 | missed_function | high | Function with embedded "MYTH\0" identifier. Calls backward (`e8ebffffff`) then branch on `84c0` test. Between Global Sign Check and Profile Already Exists Page Handler. |
| 0x00475ff3 | 0x00476030 | 61 | missed_function | high | Dispatch function loading global pointer 0x007ca590 into ECX (`b990a57c00`) then calling through it 3 times. Between 2D Rectangle Drawing and UI Options Constructor. Likely UI dispatching through a function table global. |
| 0x00486efb | 0x00486f30 | 53 | missed_function | high | Function with embedded "MYTH\0" identifier. Takes byte parameter (`8a4c2404`), checks it (`84c9741f`), accesses struct at +0x98 (`8b8898000000`), dereferences pointer chain. Between Set Four Colors to White and linked list allocator. |
| 0x0048b5f4 | 0x0048b7e0 | 492 | mixed | medium | 12 bytes of data/fill at start (includes dword 0x1000 = 4096), then real function at +0x0C: `83ec14568bf1` (sub esp, 14h; push esi; mov esi, ecx). Accesses struct field at +0x2EC. Between Path/File Char Validator and General utility function. |
| 0x00498650 | 0x004986a0 | 80 | missed_function | high | String operation leaf function. Takes param in `[esp+4]` (`8b542404`), null-checks it (`85d2`), uses String Truncation Wrapper (prev function) patterns. Between String Truncation Wrapper and Render State Reset. |
| 0x0049afca | 0x0049afe0 | 22 | missed_function | high | Thunk: `e80b000000` (call) + `e946000000` (jmp) + NOP padding. Between CleanupCallbackRegister and Multi-Call Sequence. |
| 0x004b1d15 | 0x004b1d90 | 123 | missed_function | high | String/config processing function. 2-4 bytes of alignment at start, then standard prologue. Between ConfigKeyValueSerialize and Multi-Field Setter with String Copy. Likely config value parsing. |
| 0x004b67ac | 0x004b67d0 | 36 | jump_table_data | high | 8 function pointer dwords (0x004b66f3-0x004b6788 range). All targets within prev function (Lap/Speed Comparison with Switch-Selectable Thresholds). Jump table for lap/speed threshold switch. |
| 0x004c94fb | 0x004c9790 | 661 | missed_function | high | Game-logic function using known globals. Calls then reads `DAT_007c56a4` (SessionType) via `a1a4567c00`, reads `DAT_008aae70` (RingBufferCounter), indexes float array at `DAT_008aae74` with `fld dword ptr [ecx*4 + 0x8aae74]`. Between Virtual Release Array and Vtable Destructor + Null. |
| 0x004d790b | 0x004d7920 | 21 | missed_function | high | Thunk: `e849edf2ff` (call) + `e80b000000` (second call) + `e916000000` (jmp) + NOPs. Double call wrapper. Between Texture/Surface Destroyer and Single Function Call Wrapper. |
| 0x004f2382 | 0x004f23a0 | 30 | mixed | medium | 14 bytes of epilogue (pop edi, pop ebp, pop esi, add esp, 0x58, ret 4) — likely tail of prev function (Vehicle Dynamics State Reset). Then call+jmp thunk + NOPs. |
| 0x0050c28c | 0x0050c2a6 | 26 | missed_function | high | Two import thunks. Each: `6a01` (push 1) + `e8...` (call) + `ff25...` (jmp through IAT: 0x5d77ec and 0x5d77dc). Standard MSVC delay-load import wrappers. Between Startup Call Wrapper and DirectX Call Wrapper. |
| 0x00528e09 | 0x00528f00 | 247 | padding | high | Alignment padding. 7-byte NOP (`8db42600000000`) followed by ~240 bytes of 0xCC (INT 3). Between Color Space Transformation and 3D Vector Normalize. |
| 0x00536fc3 | 0x00536ff0 | 45 | mixed | medium | 12 bytes of epilogue from partial prev function (sete al; pop ebp; pop ebx; lea eax, [2*eax+1]; add esp, 0x10), then small wrapper (mov eax, [esp+4]; push eax; push edx; call; ret 4). |
| 0x005544a7 | 0x005544c0 | 25 | jump_table_data | high | 5 function pointer dwords (0x0055431b-0x00554453 range). All within function at 0x5542f0 (prev func). Jump table for game state setting switch. |
| 0x0056459d | 0x00564600 | 99 | missed_function | high | String/char processing function. NOP padding at start then `53568bf15733ff8bda8a06` (push ebx; push esi; mov esi, ecx; push edi; xor edi, edi; mov ebx, edx; mov al, [esi]). Between Audio Mixer Sample Get with Fallback and IndirectDwordCompare. |
| 0x0057fed1 | 0x005805c0 | 1775 | missed_function | high | Large audio-network bridge function. 2 bytes padding then `e82fd8ffff` (call backward), then full prologue `83ec1c535556`. Between Audio Streaming Thread Shutdown and Network Packet Queue Reader. |
| 0x00586eda | 0x00586f10 | 54 | missed_function | high | Multiple small wrappers: (1) `push 0x586ef0; call; pop ecx; ret`, (2) `mov ecx, 0x8d3e31; jmp`, (3) call+jmp thunk. Between Thunk to FUN_00598815 and Single Function Call Wrapper. |
| 0x0059c3f5 | 0x0059ca3b | 1606 | mixed | high | INT3 padding (~20 bytes) followed by series of SEH handler thunks (each: `ff75XX`=push [ebp+offset]; `e8...`=call; `59`=pop ecx; `c3`=ret), then `b870a45b00` (mov eax, 0x5ba470) + jmp. Between function at 0x59c30e and ExceptionHandlerThunk. |
| 0x004096aa | 0x00409890 | 486 | jump_table_data | high | Camera mode dispatch jump table; repeated 0x0040948e address pattern |
| 0x0040d94f | 0x0040d980 | 49 | jump_table_data | high | Race commentary director dispatch switch table; 6+ addresses |
| 0x0041ab19 | 0x0041ab30 | 23 | jump_table_data | high | AI session phase counter switch table; 4 entries ending with 90 padding |
| 0x0042382b | 0x00423890 | 101 | missed_function | high | String parsing function with MYTH debug marker; proper x86 code (8B442408 85C0 53 56 8BF0); sits between String/Hash Token Parsing and Binary Search in String Table |
| 0x0044c661 | 0x0044c680 | 31 | mixed | medium | FNSTENV/FSTP FPU instruction residue + thunk pair; FPU context save fragment |
| 0x0044ca21 | 0x0044ca40 | 31 | padding | medium | Call+pop+ret stub with 90 padding and thunk pair; no meaningful code |
| 0x0044d1b0 | 0x0044d1c0 | 16 | padding | high | Standard thunk pair + 90 NOPs; linker alignment |
| 0x0044d570 | 0x0044d580 | 16 | padding | high | Standard thunk pair + 90 NOPs; linker alignment |
| 0x00464278 | 0x00464290 | 24 | string_data | high | Four ASCII format identifiers: ".AF", "5AF", "<AF", "CAF" with null terminators |
| 0x0046808d | 0x004681b0 | 291 | missed_function | high | Object constructor: push esi/mov esi,ecx prologue; sets vtable to 0x005af668; sets +0x128 field to -1; large gap (291 bytes) |
| 0x00476073 | 0x004760d0 | 93 | missed_function | high | Constructor: 12-byte 90 prefix then push esi/mov esi,ecx; sets vtable to 0x005a4450 then to 0x005a443c; conditional call on +0x30 field |
| 0x0047c6b6 | 0x0047c770 | 186 | missed_function | high | Constructor with data prefix; push esi/mov esi,ecx entry; calls at +0xd5, +0xdc; ends with xor eax/ret; 186 bytes |
| 0x0048b90a | 0x0048b91a | 16 | unknown | low | Only 16 bytes; fragmented code tail between two known functions; contains debug/unusual register ops |
| 0x0048fb96 | 0x0048fc50 | 186 | missed_function | high | UI object constructor: push esi/push edi/mov edi,ecx prologue; reads +0xe0 field; has import call; 186 bytes of valid code |
| 0x0049b01c | 0x0049b030 | 20 | padding | high | 4-byte 90 prefix + thunk stub; linker alignment |
| 0x004a192a | 0x004a1969 | 63 | missed_function | high | Debug assertion/logging function between OSMan::Enter and ObjectHandleReader; push 0x1b1 + file offset string + call to assertion handler; 63 bytes |
| 0x004b6899 | 0x004b68c0 | 39 | jump_table_data | high | Steering alignment switch table; 8 address entries + 90 padding |
| 0x004c2c24 | 0x004c2c40 | 28 | padding | high | 12-byte 90 prefix + dec dword [ecx+0x3c] code fragment; mostly alignment fill |
| 0x004d792a | 0x004d7960 | 54 | padding | high | 90 NOPs + thunk stubs; no unique code |
| 0x004db5c6 | 0x004db6f0 | 298 | missed_function | high | SessionType dispatch function: reads DAT_007c56a4 (SessionType), compares to 7, jump table at 0x004db638; sets up arguments; 298 bytes substantial function |
| 0x0050da8b | 0x0050dab2 | 39 | missed_function | high | MSVC CRT import thunks: three sequential push 1 + call patterns via import table jumps; between transform and quaternion functions |
| 0x00520133 | 0x0052014e | 27 | missed_function | high | SSE stack alignment prologue routine: push ebx/mov ebx,esp/sub esp,8/and esp,-16; between two SSE matrix functions |
| 0x00537c9b | 0x00537ce0 | 69 | jump_table_data | high | Multi-block allocator switch table; 12+ address entries |
| 0x005471af | 0x005471c0 | 17 | jump_table_data | high | Indexed field copy switch table; 4 address entries |
| 0x0056462f | 0x00564640 | 17 | mixed | medium | NOP + thunk (mov ecx,[ecx]/push/call) + trailing data bytes; function tail + data |
| 0x0057ad6f | 0x0057adb0 | 65 | missed_function | medium | Global flag setter: reads DAT_008d46b8 byte, test-and-set pattern (OR), then thunk to 0x0047aa60; 65 bytes |
| 0x00586f1a | 0x00586f40 | 38 | padding | high | 90 NOPs + two thunk stubs; linker alignment |
| 0x0059067e | 0x00590703 | 133 | missed_function | high | FPU/MMX control function: push ebp/mov ebp,esp prologue; wait instruction; checks dword at 0x005e9ad0; after __cintrindisp2 CRT internal |
| 0x00406511 | 0x00406640 | 303 | missed_function | Medium | Method-style code with struct reads at [ecx+0x0c], indirect call via `ff 15`, conditional branches. No standard prologue but clear instruction flow with loop and subroutine calls. |
| 0x0040ddc5 | 0x0040ddf0 | 43 | jump_table_data | High | Seven 4-byte pointers (0x0040ddc1×3, 0x0040dd92×2, 0x0040ddb7, 0x0040ddc1) preceded by `8d 49 00` alignment NOP, followed by 0x90 padding. Switch case dispatch table. |
| 0x0041143a | 0x00411570 | 310 | missed_function | Medium | Method code with mov esi, ecx (`this`-based). Compares global DAT_008ab6e4 against 2 (ScoringGate). Accesses [esi+0x48] in loop, uses `repne scasb` for string ops. First byte `7c` (jl) may branch into prev function. |
| 0x00423e75 | 0x00424080 | 523 | missed_function | High | Function with `53 56 8b f1` (push ebx; push esi; mov esi, ecx) prologue at offset +9. Constructor/init: sets [esi+0x4034], zeroes field, stores 0xFFFFFFFF to [esi+4]. FPU instruction `fsqrt` + `fstp [ecx+0x24]` before prologue may be prev func tail. |
| 0x00431c58 | 0x00431c70 | 24 | missed_function | High | Tiny thunk: 8× NOP padding, push 0x00431c70, call via relative, pop ecx, ret. Between PhysicsGlobalStateInit and PhysicsShutdown — likely utility init thunk. |
| 0x0044ca69 | 0x0044ca80 | 23 | missed_function | High | Same thunk pattern: 7× NOP, push 0x0044ca80, call, pop, ret. Between CollisionStaticInit and InitMouseAbsAxisX. |
| 0x0044ce29 | 0x0044ce40 | 23 | missed_function | High | Same thunk pattern: 7× NOP, push 0x0044ce40, call, pop, ret. Between two Global State Initializers. |
| 0x0044d5a6 | 0x0044d5c0 | 26 | missed_function | High | Same thunk pattern with longer padding: 10× NOP, push 0x0044d5c0, call, pop, ret. Between Collision Region Init and Collision Material Coefficients. |
| 0x0045bb81 | 0x0045bbe0 | 95 | missed_function | Medium | Two small functions. First: loop with `cmp edx,8`/`jl` (iteration), struct step `add ecx,0x5c`. Second: `56 68 2c 03 00 00 8b f1` prologue, call, conditional branch. First function is ~14 bytes, second ~81 bytes. |
| 0x0046846a | 0x004685b0 | 326 | missed_function | High | Method function with `81 ec 00 02 00 00` (sub esp, 0x200 — stack frame) at offset +11. Virtual call via `ff 50 38` (call [eax+0x38]) with `6a 01` push param. First 11 bytes (`e1 e8 e9 e1 e9 ff a0 30 ff 7c 00`) are unusual — possibly data or prev-func tail. Between VehicleSceneLoadAndPositionTires and a forwarding function. |
| 0x0046cecf | 0x0046d0d0 | 513 | missed_function | High | Method function referencing known globals: pushes DAT_005ec4cc (MessageBuffer), DAT_005c30bc, and DAT_005ec4c0. Uses mov esi, ecx (`this`), calls function, then string copy loop with `repne scasb`/`movsb` pattern. Between CopyProfileIconBMP and SessionCheckEndCondition. |
| 0x0047c7ba | 0x0047c860 | 166 | missed_function | High | **Constructor**: pushes float 1.0 (0x3f800000), sets vtable pointer at [esi] to 0x005a69b0, stores param to [esi+0xfc], returns `this` in eax. Calls a sub-function. Between UI FPS/Performance Setting and UILoadingPercentDisplay — likely a UI element constructor. |
| 0x004873de | 0x00487400 | 34 | jump_table_data | High | `8b ff` (mov edi, edi) hot-patch NOP, then five 4-byte pointers to addresses within prev function (0x00487345, 0x0048735e, 0x00487373, 0x00487388, 0x0048739d), followed by 0x90 padding. Between State-Dependent VTable Dispatch and UI State Change Dispatcher. |
| 0x0048fd79 | 0x0048fdb0 | 55 | missed_function | High | **Destructor**: `56 8b f1 c7 06 3c 44 5a 00` (sets vtable 0x005a443c), reads child object at [esi+4], conditionally calls delete. Flag test on [esp+8] bit 0 for self-delete. First bytes `44 5a e9 f1 fe ff ff` jump backward into prev Constructor. |
| 0x00498d42 | 0x00498d90 | 78 | missed_function | Medium | Two small functions. First: FPU op (`fmul`), store to [esi+0x44], retn 8. Second: reads [ecx+0x10/0x0c/0x08/0x04], pushes four params, calls function, retn 4. Float store + struct field forwarding. |
| 0x004a1970 | 0x004a1990 | 32 | missed_function | High | Calls function with one param (mov eax/[esp+4]/push), stores float result via `fstp [ecx]`, returns 4 (mov eax, 4 / retn 8). Between OSMan::Exit and ObjectHandleReader. |
| 0x004b2055 | 0x004b20d0 | 123 | missed_function | High | String function: `66 8b 41 16` (read 16-bit from [ecx+0x16]), then `repne scasb` for string length, `not ecx; dec ecx`. Conditional branches. Second code fragment after `e9` jump into prev function. Between UI Config Entry Serialization and Clamp function. |
| 0x004c2f8c | 0x004c2fa0 | 20 | missed_function | High | Tiny delegation thunk: 4× NOP, `e8 0b 00 00 00` (call), `e9 16 00 00 00` (jump), 6× NOP. Between LinkedListDestructorWithData and Delegation Wrapper. |
| 0x004c9b7a | 0x004c9b90 | 22 | missed_function | High | Thunk: 6× NOP, push 0x004c9b90, call, pop, ret. Between thunk to FUN_004ce820 and Nullsub Wrapper. |
| 0x004db9f2 | 0x004dbb60 | 366 | missed_function | High | Method code: `83 ec 08 56 57 8b f9` prologue, mov ecx, 0x007ce234 (known global), calls function. First bytes `cf e8 ...` (iret then call) likely prev-func tail. Stack frame allocation. Between Number Format utility and DrawDebugTextOverlay. |
| 0x004f3471 | 0x004f3490 | 31 | jump_table_data | High | `8d 49 00` alignment NOP then six 4-byte pointers (0x004f3283, 0x004f32d9, 0x004f332f, 0x004f3386, 0x004f33dd, 0x004f3427) all within prev function's axis-direction switch. 0x90 padding at end. |
| 0x005201fb | 0x0052020e | 19 | missed_function | High | **SSE stack alignment thunk**: `53 8b dc 83 ec 08 83 e4 f0` (push ebx; mov ebx, esp; sub esp, 8; and esp, -16) aligns stack to 16 bytes, then `eb 03` jumps to next function (SSE 4x4 Matrix Multiply). Between two SSE matrix functions. |
| 0x005292e9 | 0x005295e0 | 759 | missed_function | High | **3DNow!/MMX math function**. Four 7-byte `lea esp,[esp]` alignment NOPs, `8b ff` hot-patch NOP, then `movd mm1, [DAT_005d940c]` (MMX load), 3DNow! instructions (`0f 0f` = pfmul/pfadd family). Large function between Empty Stub and Packed Floating-Point Math. |
| 0x00547224 | 0x00547240 | 28 | jump_table_data | High | Four 4-byte pointers (0x005471e1, 0x005471f1, 0x00547201, 0x00547211) within prev function (Switch-Based Float Setter), followed by 0x90 padding. |
| 0x00555e3e | 0x00555e50 | 18 | jump_table_data | High | `8b ff` hot-patch NOP then four 4-byte pointers (0x00555284, 0x0055529b, 0x005552b0, 0x005552f0) within the large function at 0x005550e0 (3422 bytes). |
| 0x0057adba | 0x0057adf0 | 54 | missed_function | High | Three tiny thunks: (1) 6×NOP + push 0x0057add0 + call + pop + ret, (2) mov ecx, 0x008d3bf9 + jmp, (3) call + jmp delegation. Between Single Delegation Call and Single Function Call Wrapper. |
| 0x0058122c | 0x00581600 | 980 | missed_function | High | **Network function**: reads [ecx+0x640] and [ecx+0x624] (network buffer/linked list fields), indirect call via `ff 15 a0 e1 59 00` (call [DAT_0059e1a0]), compares result with 0x80. Between Network File Transfer Accept Handler and Network Buffer Search. 980 bytes of code. |
| 0x0059083b | 0x0059086e | 51 | missed_function | High | **Has standard prologue**: `55 8b ec` (push ebp; mov ebp, esp). Allocates 0x2d0-byte stack frame, saves ebx. Pushes two params from stack, calls function, then FPU operations: `fstcw [ebp-0xa4]` (store FPU control word), modifies it. FPU control/init function. Between unidentified function and CRT __flload. |
| 0x0059ca73 | 0x0059ca8b | 24 | missed_function | Medium | Exception handler fragment. 12× `cc` (INT3 padding — MSVC exception handler pattern), then `lea ecx, [ebp-0x10c]`, then `jmp` to far address. Exception registration record setup. Between C++ Exception Handler Wrapper and CxxFrameHandlerWrapper. |
| 0x00406b44 | 0x00406b60 | 28 | padding | high | All 0x90 (NOP) bytes except trailing `d9 41 50 c3` which is fragment of prev func's FPU code. Pure alignment fill. |
| 0x004099de | 0x00409a00 | 34 | missed_function | high | Code at offset +2: `8b 0d 64 fe 8a 00` (mov ecx, [DAT_008afe64]), `6a 00 6a 20` (push args), `e8` (call). Prologue: 90 90 (alignment). Camera pipeline setup function — sets globals then calls FUN_00411e90. Adjacent to Conditional Camera Pipeline Setup. |
| 0x004119a3 | 0x004119d0 | 45 | missed_function | high | Full function: `a1 d0 a5 5e 00` (mov eax, [DAT_005ea5d0]), `85 c0` (test), `74 07` (jz), `50 e8 10 62 17 00` (call FUN_00587bc0), `c2 14 00` (ret 0x14). Multiple exit paths with cleanup. Font/string-related. |
| 0x0041ad5d | 0x0041ad80 | 35 | jump_table_data | high | 8-entry address array: 0x0041acf0, 0x0041acf7, 0x0041acfe, 0x0041ad05, 0x0041ad0c, 0x0041ad13. Switch table for Overtake/Position Swap event dispatch (next func). |
| 0x0043209e | 0x00432180 | 226 | missed_function | high | thisCALL method: `56 6a 40 8b f1` (push esi, push 0x40, mov esi, ecx). Allocator/constructor pattern. Allocates 0x40 bytes, calls FUN_00437b90 on success, stores pointer. Two exit paths (success/failure). |
| 0x0044c6c1 | 0x0044c6e0 | 31 | mixed | medium | Contains: unidentifiable bytes at start (`c6 44 00 e8 e4`), then `59 c3` (ret stub), then `c3 e8 0b 00 00 00 e9 36 00 00 00` (CRT atexit registration thunk). Not valid standalone function. |
| 0x0044ce41 | 0x0044ce74 | 51 | mixed | medium | Same atexit thunk pattern + global init: writes 0x24 to DAT_007ca448. Part of collision/init system (adjacent to CollisionDataTeardown_2 and InitFloatGlobals). |
| 0x0044d201 | 0x0044d220 | 31 | data_table | high | Pure CRT atexit registration thunk (`c3 e8 0b 00 00 00 e9 36 00 00 00`). No additional code. Standard VC++ static initializer record. |
| 0x0045be3d | 0x0045be50 | 19 | data_table | high | Atexit thunk only (`e8 0b 00 00 00 e9 26 00 00 00 90 90 90 90 90 90`). Part of collision system init chain. |
| 0x0046493a | 0x00464990 | 86 | missed_function | medium | String push thunk: `68 50 49 46 00` (push "PIF\0"), `e8 f4 31 12 00` (call). Then additional code: `b9 a8 d2 7c 00` (mov ecx, 0x007cd2a8), `e9 a6 06 00 00` (jmp). Contains at least one callout function. Name suggests PIF-related file operation. |
| 0x0046d1dc | 0x0046dd30 | 2900 | missed_function | high | Large function: `56 8b f1 57 b9 b0 2d 7d 00 33 ff` (push esi, mov esi, ecx, push edi, mov ecx=0x007d2db0, xor edi, edi). Loop setup + calls. Contains `83 b8 44 b1 00 00 02 75 15` (cmp dword ptr [eax+0xb144], 2 — mode check), `68 74 6b 5c 00` (push string). Session/race logic function — checks session state, pushes string resource. |
| 0x00476359 | 0x004765f0 | 663 | missed_function | high | Large stack frame: `81 ec 00 02 00 00` (sub esp, 0x200). `53 55 56 8b d9` (push ebx, ebp, esi, mov ebx, ecx). Reads fields at +0xf0, loops with `3b f5 74 25` (cmp esi, ebp; jz). Frontend/loading display function with string operations. |
| 0x0048752f | 0x00487660 | 305 | missed_function | high | thisCALL method: `56 8b f1 e8 a8 ff ff ff` (push esi, mov esi, ecx, call self). Calls itself recursively then dispatches via vtable at +0x98: `8b 06 8b ce ff 90 98 00 00 00` (mov eax, [esi]; mov ecx, esi; call [eax+0x98]). UI object method with vtable dispatch. |
| 0x0048bbd6 | 0x0048c070 | 1178 | missed_function | high | Code: `81 f8 02 00 00 00 e9 2a fd ff ff` (cmp eax, 2; jmp back). Then function: `56 8b f1 8b 4e 40 e8 e5 bd 00 00` (thisCALL, reads field +0x40, calls). Checks byte fields at +0xe000, +0xe100 for visibility flags. Text input/UI render method with character rendering. |
| 0x00498fde | 0x0049904c | 110 | missed_function | high | thisCALL with vtable dispatch: `56 8b f1 8b 46 60 85 c0 74 57 8b 06 57 ff 50 28` (mov esi, ecx; check field +0x60 non-null; vtable call via [eax+0x28]). Computes rectangle differences, dispatches render calls. List iteration / render dispatch. |
| 0x0049b051 | 0x0049b070 | 31 | data_table | medium | Mostly 0x90 padding, then `68 70 b0 49 00 e8 d4 ca 0e 00 59 c3` (push string at 0x0049b070, call FUN_00587bc0, pop, ret). String push thunk for cleanup/deinit. |
| 0x004b20f7 | 0x004b2180 | 137 | missed_function | medium | Starts with `ff 15 4c e0 59 00` (call dword ptr [0x0059e04c] — import call). Then `ff ff ff` (padding/alignment), then full function: `51 56 8b f1 85 f6 89 4c 24 04 74 35` (push ecx, push esi, mov esi, ecx, test esi, jz). thisCALL method with stack handling, null check, then more code with `55 57 8b ff 8b ee` (push ebp, push edi, mov edi, edi; mov ebp, esi). Complex function with nested prologues — likely two small functions merged. |
| 0x004b7c60 | 0x004b7c80 | 32 | jump_table_data | high | 5-entry address table: 0x004b7be6, 0x004b7bf3 (×3), 0x004b7c07. Switch table for Pit Timing Update (prev func). |
| 0x004cdb55 | 0x004cdb90 | 59 | jump_table_data | high | Address table (6 entries): 0x004cdb36, 0x004cdb3b, 0x004cdb40, 0x004cdb45, 0x004cdb4a, 0x004cdb4f. Followed by index mapping bytes: 00 00 00 00 01 02 02 03 06 06 06 04 05. Switch table + case index map for Steward scoring function (prev func). |
| 0x004d7d79 | 0x004d7e00 | 135 | mixed | medium | Contains: atexit thunk (`e8 0b 00 00 00 e9 16 00 00 00`), padding, then `b9 64 d2 8a 00 e9 36 fd ff ff` (mov ecx, DAT_008ad264; jmp to function). Then `68 b0 7d 4d 00 e8 94 fd 0a 00` (push string, call). Multiple thunks in series. Delegation wrappers for table interpolation functions. |
| 0x004f6a9c | 0x004f6ab0 | 20 | data_table | high | Atexit thunk only (`e8 0b 00 00 00 e9 46 00 00 00`). Part of physics/force evaluation init chain. |
| 0x0050ecf9 | 0x0050ed19 | 32 | jump_table_data | high | 8-entry address table: 0x0050ebb7, 0x0050ec19, 0x0050ec1c, 0x0050ec1f, 0x0050ec23, 0x0050ec26, 0x0050ec29, 0x0050ec2d. Switch table for Skeleton Animation Blending (prev func). |
| 0x0052981b | 0x00529af8 | 733 | missed_function | high | SSE/MMX SIMD code: `0f 7e c0` (movd eax, xmm0), `0f 7f c1` (movq mm0, mm1?), `0f 6e 1d 5c 93 5d 00` (movd mm3, [DAT_005d935c]). Bit manipulation: `d1 e3` (shl ebx, cl), `81 e3 00 00 00 80` (and ebx, 0x80000000), `c1 ea 1f` (shr edx, 0x1f), `33 c3` (xor eax, ebx), `3b 05 14 94 5d 00` (cmp eax, [DAT_005d9414]), `0f 6e 15 10 94 5d 00` (movd mm2, [DAT_005d9410]). MMX polynomial approximation / math function (~733B). |
| 0x0053ad08 | 0x0053ad50 | 72 | missed_function | high | thisCALL method: `56 8b f1 8d 4e 04 e8 85 15 00 00` (push esi, mov esi, ecx; lea ecx, [esi+4]; call). Then multiple allocations: `6a 10` (push 0x10) × 2 for fields at +0x10, `6a 40` (push 0x40) for field at +0x20. Writes vtable pointer `c7 06 10 89 5b 00`. Constructor with multi-field allocation. |
| 0x00556015 | 0x00556040 | 43 | jump_table_data | high | 5-entry address table: 0x00555f85, 0x00555f8c, 0x00555f93, 0x00555f9a, 0x00555f9f. Followed by index mapping: 00 01 02 04 04 04 04 04 04 04 04 04 04 04 04. Switch table with case compaction for Graphics/Display state sync (next func). |
| 0x005679a5 | 0x005679b7 | 18 | missed_function | high | Small search loop: `74 10 8b 4c 24 04 85 c9 7e 08 8b 40 04 49 85 c0 75 f4` (jz; mov ecx, [esp+4]; test ecx, ecx; jle; mov eax, [eax+4]; dec ecx; test eax, eax; jnz loop). Linked list traversal — follows next pointers (+4 offset), counts down from parameter. Find/search helper for String-Keyed Linked List (next func). |
| 0x00581746 | 0x00581780 | 58 | missed_function | high | Indirect call via import: `ff 15 a4 e1 59 00` (call [0x0059e1a4]). Then function: `56 8b f1 8a 46 0c 84 c0 74 15 8b 46 04 50 ff 15 a8 e1 59 00 85 c0 74 07 c7 46 04 00 00 00 00 5e c3` (thisCALL, checks byte field at +0xc, reads pointer at +0x4, calls [0x0059e1a8], conditionally clears pointer). Thread pool / job cleanup function. Adjacent to Thread Pool Job Dequeue. |
| 0x005873a3 | 0x00587460 | 189 | missed_function | high | Multiple code fragments: (1) `8a 0d b8 46 8d 00 b0 01 84 c8 75 08 0a c8 88 0d b8 46 8d 00` — read/write global DAT_008d46b8. (2) Then `68 60 aa 58 00` (push string), call. Array allocation function with count parameter. Contains at least one complete function plus initialization code. |
| 0x0059ca95 | 0x0059caa8 | 19 | padding | high | Mostly 0xCC (int 3) debug padding bytes. Last 5 bytes: `8d 4d b4 e9 b8 df ed ff` — lea ecx, [ebp-0x4c]; jmp to FUN_0047aa58. Tail of CxxFrameHandlerWrapper's SEH handler — overflow from prev func. |
| 0x00409f19 | 0x00409f40 | 39 | jump_table_data | high | CameraModeViewportUpdate switch table. 9 entries pointing to 0x00409a43-0x00409c37 range |
| 0x0040e12f | 0x0040e170 | 65 | jump_table_data | high | AI Behavior State Machine switch table. 12 entries pointing to 0x0040df-0x0040e1 range |
| 0x0041b151 | 0x0041b190 | 63 | jump_table_data | high | Session Event Commentary switch table. ~12 entries, 4 repeat (0x0041b0db x4 = default case fall-through) |
| 0x00429e9e | 0x00429eb0 | 18 | jump_table_data | high | AI Ability/Lap Ratio function switch table. 2 entries: 0x00429d5f, 0x00429ca2 |
| 0x0044c709 | 0x0044c720 | 23 | missed_function | high | Thunk: push 0x0044c720; call; pop ecx; ret. NOP padding wrapper |
| 0x0044cac9 | 0x0044cae0 | 23 | missed_function | high | Thunk: push 0x0044cae0; call; pop ecx; ret. NOP padding wrapper |
| 0x0044d249 | 0x0044d260 | 23 | missed_function | high | Thunk: push 0x0044d260; call; pop ecx; ret. NOP padding wrapper |
| 0x0044f00c | 0x0044f050 | 68 | missed_function | high | x87 FPU comparison function: fld/fcomp/fnstsw/fpu constant load from global 0x0059e440. NaN/epsilon handling with jp branch |
| 0x00464ec9 | 0x00464ee0 | 23 | jump_table_data | high | Buffer Size Lookup switch table. 4 entries pointing to 0x00464ea1-0x00464eb9 |
| 0x00468634 | 0x0046890d | 729 | missed_function | very high | LARGE missed function. Allocates 0x104 bytes stack. Reads global 0x005ea438 (LoadPath), references 0x005cc21c string, checks 0x007ce498 (AutoLoadConfigFile). File loading/configuration function |
| 0x004765fd | 0x00476660 | 99 | missed_function | high | Destructor: sets vtable (0x005a448c), checks +0x3c child non-null → free, sets vtable (0x005a4450), checks +0x30 child non-null → free. Dual vtable pattern |
| 0x0047dbb7 | 0x0047dbe0 | 41 | missed_function | medium | Small thiscall: indirect call through [0x0059e018] then call + sub-function with optional delete cleanup. First 6 bytes may be tail of Season Stats Display |
| 0x0048c0db | 0x0048c9a0 | 2245 | missed_function | very high | LARGEST GAP (2245 bytes). Standard thiscall with big function body. Reads 0x005ea438 (LoadPath), pushes string 0x005cc21c string constant, stores result at +0x30c. File parsing/loading function |
| 0x0048febb | 0x0048fee0 | 37 | missed_function | high | Virtual call delegation: loads pointer from +0xe0, calls [vtable+0x40] with it, calls another function, returns 0 |
| 0x0049b071 | 0x0049b0a0 | 47 | mixed | medium | Data table (0x45080000...) followed by small function: reads global 0x005ccbc0, adds 0x0a, writes to global 0x007ce238, returns |
| 0x004a1e55 | 0x004a1ea0 | 75 | missed_function | high | Path concatenation: reads pointers at +0x14 and +0x04, defaults to 0x005ea438 (LoadPath) if null, pushes 0x005cd13c string constant |
| 0x004b7fff | 0x004b8010 | 17 | jump_table_data | high | Hot Lap File Writer switch table. 4 entries pointing to 0x004b7f38-0x004b7f4a |
| 0x004c2fea | 0x004c3020 | 54 | missed_function | high | Thunks: (1) push 0x004c3000; call; pop; ret. (2) mov ecx, 0x008ac36c; jmp (global singleton call). (3) call+ret stub |
| 0x004d7fd0 | 0x004d7fe0 | 16 | jump_table_data | high | Switch-Based Global Lookup switch table. 4 entries pointing to 0x004d7fb0-0x004d7fc8 |
| 0x004dc2b7 | 0x004dc340 | 137 | missed_function | high | Three thunks: (1) push 0x004dc2f0; call; (2) mov ecx, 0x008ad3b4; jmp; (3) NOP padding. Singleton call pattern |
| 0x00513cf0 | 0x00513d2f | 63 | missed_function | high | Animation state check: test bit 0x20 at +0x10c, check mask at +0x5c (compare ==3), test bit 0x08 at +0x5d. Access +0x100 region. Animation-related |
| 0x00520416 | 0x0052042e | 24 | missed_function | medium | Stack-alignment prologue for next function (Velocity/Friction Clamp). LEA NOP padding, push ebx/mov ebx esp, sub/and esp -16, then jmp +3 to 0x0052042e |
| 0x0053b018 | 0x0053b0d0 | 184 | missed_function | high | x87 FP conversion: fild (int-to-float), fmul with constants. Takes byte args, converts to int then float. First 6 bytes (ff 15 [0x0059e29c]) may be tail of prev wrapper |
| 0x0054a1a6 | 0x0054a1c0 | 26 | missed_function | high | Tiny zero-init: zeros two dword fields at +0x1a8 and +0x1a4, ret. Flag/bitmask reset |
| 0x00568782 | 0x005687f0 | 110 | data_table | high | Character classification lookup bitmap (0/1 pattern for character types). Between ASCII Char Code Validation and next func. Matches isprint/isspace-style table |
| 0x0057ae3a | 0x0057ae70 | 54 | missed_function | high | Thunks: (1) push 0x0057ae50; call. (2) mov ecx, 0x008d3c19; jmp (dynamics constraint solver workspace call). (3) call+ret stub |
| 0x0058763b | 0x00587680 | 69 | missed_function | high | Flag setter: read byte from 0x008d46b8, test/set bit 1, write back (once-only flag pattern). Followed by thunk push 0x0047aa60; call |
| 0x00591629 | 0x0059163b | 18 | missed_function | high | FPU math stubs: 4 tiny wrappers — call+ret pair, then fpatan+ret, fptan+ret. Trig wrappers around x87 FPU |
| 0x00406c9b | 0x00406cc0 | 37 | mixed | high | "MYTH\0" class-name string followed by constructor body (push esi, vtable set at 0x0059e598, conditional call, return this). String at start is embedded class identifier. |
| 0x0040e1ae | 0x0040e1c0 | 18 | padding | high | Two nops, call forward, jmp forward, six nops. Standard thunk pattern but no xrefs — dead code thunk between Tick/Update Dispatch and Delegation Thunk. |
| 0x00412215 | 0x004122c0 | 171 | jump_table_data | high | Alignment nop (lea ecx,[ecx+0x00]) followed by array of 4-byte addresses (0x00411ed7, 0x00411efa, 0x00411f1d, 0x00411fdc, ...) all within Sound Event Dispatcher (0x00411e90 range). Switch/case jump table. |
| 0x0042b887 | 0x0042b8a0 | 25 | missed_function | high | Small stub: indirect call through [0x0059e04c], pop esi, ret, then dead thunk (call+jmp+padding). Between AI Steering and Thunk to FUN_004b3db0. Import-mediated dispatch stub. |
| 0x004328b2 | 0x004328e0 | 46 | missed_function | medium | Code fragment between Path String Combinator and Path Accessor. Reads global 0x005ea438 (SeasonDir) which is a path pointer. Two small code sequences separated by ret+jmp. Path utility function. |
| 0x0044cae4 | 0x0044cb14 | 48 | mixed | high | Call+pop+ret thunk, nops, ret, dead thunk (call+jmp+nops), then global initializer writing 0x67 to [0x007ccfdc] and 0x0 to [0x007ccfe0]. Between Thunk and Global Initializer (-1.0, 0.0). |
| 0x0044cea1 | 0x0044ced4 | 51 | mixed | high | Same pattern as gap 482: call+pop+ret thunk, nops, ret, dead thunk, then global initializer writing 0x25 to [0x007ccbf4] and 0x0 to [0x007ccbf8]. Between RegisterInputDevice1 and InitFloatConstants. |
| 0x0044f42c | 0x0044f460 | 52 | data_table | high | Two 4-byte addresses (0x0044f3ff, 0x0044f412) pointing into Force Feedback function, followed by 0/1 bitmask table (button mapping pattern). Then nop padding. Jump table + lookup table for joystick/FFB input processing. |
| 0x0045bf3c | 0x0045bf50 | 20 | padding | high | Four nops, dead thunk (call+jmp), six nops. No unique code. Between Wide Struct Zero-Init and Single Function Call Wrapper. |
| 0x00468b4b | 0x00468bf0 | 165 | missed_function | high | "MYTH\0" class-name string followed by proper function prologue (push ebp, push edi). Reads struct field at +0x184, loads global 0x005ea438 (SeasonDir). Method of MYTH class. Between Career Mode Driver Stats Reset and Grand Prix Results HTML Writer. |
| 0x0046e6ee | 0x0046e7f0 | 258 | missed_function | high | Two nops, then method with vtable call (call [eax+0x1c] = vtable slot 7), result check, conditional call to 0x00489912, return 0 on fail. Full 258 bytes contains method body. Between Path Builder with Backslash and Polling Loop with Branch. |
| 0x0047dcf1 | 0x0047dd10 | 31 | jump_table_data | high | Alignment nop (lea ecx,[ecx+0x00]) followed by array of 4-byte addresses (0x0047dc01, 0x0047dc22, 0x0047dc69, 0x0047dc9e) within TelemetryDisplaySwitch. Then nop padding. Switch/case jump table. |
| 0x004876bb | 0x00487720 | 101 | missed_function | high | Five nops then method: compares parameter to field at +0x84, checks byte flag at +0xe2, sets field +0x80, reads vtable, pushes 1, calls virtual method (vtable tail-call). State setter with conditional logic. Between Short Computation (Constructor) and Short Computation / State Value Transform. |
| 0x0049015e | 0x00490190 | 50 | missed_function | high | Two nops then setter: sets field at +0xe0 to 0 or 1 based on boolean parameter, then tail-calls virtual method at vtable+0x2c (slot 11). Clean state-toggle with virtual dispatch. Between UI State Machine Update and Zero-Check Getter. |
| 0x00499159 | 0x00499180 | 39 | mixed | high | First 6 bytes (or [ebx],bl; jmp back into prev function) are tail of previous function (Call FUN_00498d20, set vtable). Remaining 33 bytes: small method (same pattern as gap 493 — call next fn, test param bit 0, conditional cleanup call, return this). Method + prev-function tail. |
| 0x004a4026 | 0x004a4050 | 42 | mixed | high | First 7 bytes (0xFFFF = data/padding; pop esi; add esp,0xa4; ret) are tail epilogue of previous function. Then new code: sets field at [ecx+0x78]=2, reads [ecx+0x64] → if non-null calls 0x0054c015(0,1,1,1). Between General utility function and Updates accumulator based on state at +0x78. |
| 0x004b21aa | 0x004b21c0 | 22 | padding | high | Six nops, dead thunk (call+jmp), six nops. Standard dead thunk pattern. Between SeasonScoringDBCallback and Single Call Wrapper. |
| 0x004c302a | 0x004c3050 | 38 | mixed | high | Six nops, then: push 0x004c3040, call 0x00587b36, pop ecx, ret (constructor thunk). Five nops, then: mov ecx,0x008ac368 (global), jmp to 0x004c518c (method thunk on global). Two thunks. Between Delegation Thunk and State Struct Multi-Field Init. |
| 0x004cfc65 | 0x004cfc90 | 43 | mixed | high | Alignment nop, then jump table for SpecialFX::Init (addresses 0x004cf9aa, 0x004cf99f, 0x004cf9a3, 0x004cf9af within SpecialFX::Init range). Followed by small data table (0x00,0x03,0x01,0x01,0x01,0x02,0x02,0x00,0x00) — state/parameter values. Then nop padding. |
| 0x004dc401 | 0x004dc430 | 47 | jump_table_data | high | Alignment nop followed by array of 8× 4-byte addresses (0x004dc357, 0x004dc367, 0x004dc37d, 0x004dc3bf, 0x004dc398, 0x004dc3b4, 0x004dc3e6, 0x004dc3d5, 0x004dc3db) within Alignment/Position Switch. Then nop padding. |
| 0x004f6b79 | 0x004f6bf0 | 119 | missed_function | high | Eight nops, then: push 0x004f6b90, call 0x00587b36, pop ecx, ret (init thunk). Five nops, then: push esi, push edi, mov esi,0x008af8ec (global array), mov edi,0x2d (45 iterations), loop: mov eax,[esi-0x14], sub esi,0x14, test eax, jz... Array traversal loop on 0x008af8ec (vehicle/phys data). Between Tire/Grip Data Array Init (Rear) and RPM Range Loader (Per Gear). |
| 0x005204f8 | 0x0052050e | 22 | missed_function | high | 7-byte nop (lea esi,[esi+0x0]), then push ebx, mov ebx,esp, sub esp,8, and esp,-16 (align to 16 bytes), add esp,8, jmp +3. SSE stack alignment thunk — aligns stack to 16-byte boundary for SSE operations, then jumps to real function. Between Velocity/Friction Clamp with Stiction Threshold and SSEMatrix4x4Multiply. |
| 0x0052c5e9 | 0x0052d214 | 3115 | data_table | high | Small call+pop+ret code at start, then large data table: repeating 12-byte entries with pattern (0x005ad410 pointer, 0x00000000, 0x8000000c flags, 0x005ad410, 0x00000001, 0x8000010c flags, ...). GUID-like structure with interface pointers and flags — DirectInput device enumeration/creation table. Between Quaternion Multiply & Surface Sample and DirectInput8Create Import Stub. |
| 0x0054c251 | 0x0054c320 | 207 | mixed | medium | First 19 bytes: conditional jump, nop, mov ecx,[ecx+0x10], inc, jmp back (short loop — tail of prev function). Six nops, dead thunk. Then: push esi, push edi, mov esi,0x008b8f40 (global buffer), mov edi,0x100 (256 iterations). Buffer cleanup/resource traversal loop. Between Linked List Indexed Accessor and QueueResourceCleanup. |
| 0x0055685a | 0x0055687b | 33 | missed_function | high | FPU detection function: push ebp, mov ebp,esp, sub esp,4, fninit (FPU init), mov word [ebp-2],0x5a5a (test pattern), fnstcw [ebp-2] (store control word), read back, check if pattern matches, return 1 (FPU present) or 0. Classic CPU FPU presence/functionality check. Between unidentified function and RDTSC Timestamp Read. |
| 0x0057ae7a | 0x0057aea0 | 38 | mixed | high | Six nops, then: push 0x0057ae90, call 0x00587b4a, pop ecx, ret (constructor thunk). Five nops, then: mov ecx,0x008d3c18 (physics state block), jmp 0x00599ac6 (method thunk on physics global). Same pattern as gaps 500/504/514. Between Single Function Call Wrapper (to constructor) and WindowProc_Ignore6666. |
| 0x00582331 | 0x00582360 | 47 | mixed | high | First 5 bytes (0x08,0x00,0x00,0x00,0x00) = data constant (size 8?). Then: mov [ebp+0xc],0 ; jmp back (prev function tail). Then second fragment: mov al,[ecx+0x8], test, je; if non-zero: read pointer at [ecx], check non-null, call vtable+0x4 (slot 1) with arg 1; else: mov [esi+0x10],0 ; jmp back. Synchronization/mutex-related method. Between CloseHandle Wrapper and Win32 Mutex Create/Recreate. |
| 0x0059573c | 0x005957bd | 129 | missed_function | high | Memory allocator function: push ebx, push edi, push 2, xor ebx,ebx, call backward (allocator init?), push 3, pop edi, compare [0x008d5a40] with 3 (≥ threshold?), jle skip. Then: mov eax,[0x008d4a24] (heap/arena array base), esi=edi*4 (index), mov eax,[eax+esi] (get slot), test non-null, test byte at +0xc for flag 0x83, conditional path. Heap slot allocation/validation. Between __amsg_exit Runtime Error (CRT) and Memory Allocator Init (0x1000). |
| 0x0059cb3d | 0x0059d6a9 | 2924 | data_table | high | int3 (CC) padding then exception handler dispatch table: pattern "mov ecx,[ebp-0x14]; jmp 0x0058328a", "mov ecx,[ebp-0x10]; jmp 0x005818a9", "mov eax,0x005bac58; jmp 0x005a337e", etc. Multiple catch-block entries with stack-frame restore and jump to handler. Also contains "mov ecx,[ebp-0xec]; jmp" entries. Large SEH/C++ exception handler table (~2924 bytes) with ~30+ handler entries. Between C++ Exception Handler Wrapper and Null-Checked Call Wrapper. |
| 0x00406d9b | 0x00406e50 | 181 | missed_function | medium | Begins with embedded string "MYTH\0" then `51 53 57 8b f9` (function body with save regs + thiscall). Audio context (between Audio Driver Init and Audio System Shutdown). String + function code = function beginning with string literal. |
| 0x0040a658 | 0x0040a680 | 40 | jump_table_data | high | 8 consecutive 4-byte addresses (22a64000, 28a64000, etc.) followed by NOP padding. Switch dispatch table. |
| 0x00412aad | 0x00412c30 | 387 | jump_table_data | high | Begins with `8d 49 00` (NOP3) followed by ~20 4-byte addresses (cb244100, d5244100, etc.). Large switch table. Between Game Control Mapping and MapCollisionShapeToBoneIndex. |
| 0x0041c079 | 0x0041c090 | 23 | jump_table_data | high | `8d 49 00` then 4 jump targets (bbbe4100, 56bf4100, 98bf4100, bbbf4100) + NOP padding. Small switch table. |
| 0x00433ead | 0x00433ed0 | 35 | missed_function | high | NOPs then `56 8b f1 b9 c0 56 7c 00 e8 a3 ad ff ff 68 38 a4 5e 00 8d 4e 08 e8 86 27 13 00 5e c3` — clear thiscall prologue (push esi, mov esi, ecx), loads class ptr DAT_007c56c0, 2 calls, string ref "38a45e00". Physics object method (between Physics Object Destructor and Validate Vehicle Configuration File). |
| 0x0044c769 | 0x0044c780 | 23 | padding | high | NOP sled + `68 80 c7 44 00 e8 c4 b3 13 00 59 c3` (thunk pattern). Between CollisionGridInit4 and CollisionStateInit_Alpha. |
| 0x0044cee9 | 0x0044cf00 | 23 | padding | high | NOP sled + `68 00 cf 44 00 e8 44 ac 13 00 59 c3` (thunk pattern). Collision initialization context. |
| 0x0044d2a9 | 0x0044d2c0 | 23 | padding | high | NOP sled + `68 c0 d2 44 00 e8 84 a8 13 00 59 c3` (thunk pattern). Collision initialization context. |
| 0x0045bf5a | 0x0045bf90 | 54 | mixed | medium | Thunk pattern at start (`68 70 bf 45 00 e8 d4 bb 12 00 59 c3`), then more NOPs, then `b9 5c d2 7c 00 e9 26 5d 00 00` (mov ecx, DAT_007cd25c + jmp — tail call), then `e8 0b 00 00 00 e9 66 00 00 00` (call + jmp stub). Contains thunk + 2 small code fragments. Between Single Function Call Wrapper and Collision Mutex Initialization. Collision context. |
| 0x00465c17 | 0x00465c30 | 25 | jump_table_data | high | NOP then 4 jump targets (0x004655ba, 0x004655c4, 0x004655ce, 0x004655d8) + NOP fill. Small switch table. Between Entity Visibility Grid Manager and Linked List Pop-Front. |
| 0x0046e842 | 0x0046ec10 | 974 | missed_function | high | Tail of prev function (`fe 59 00 c6 86 74 01 00 00 00 8b c6 5e c3`), then large function at offset +12: `83 ec 28 8b 44 24 38 8b 54 24 30 53 55 56 57 8b e9` — proper stack frame alloc (0x28 bytes), saves all registers, thiscall (mov ebp, ecx). Contains multiple call instructions and complex control flow. Large game-logic function between Polling Loop and Object Name Matching + Activation. |
| 0x00477079 | 0x00477280 | 519 | mixed | medium | Starts `00 00 e9 02 ff ff ff` (likely end of prev function's data), then `56 8b f1 e8 48 7b 01 00` (thiscall body), `c6 86 7c 01 00 00 00 33 c0 5e c3` (store + return), then `8b 91 70 01 00 00 85 d2 56` (another fragment). Multiple function fragments separated by returns, with some data-like bytes. Between Driver Name Copy from Global Array and Object Name Comparison. |
| 0x00487755 | 0x00487ed0 | 1915 | missed_function | high | `83 e8 02 74 03 32 e9 d3 ff ff ff 53 e8 ba ef ff ff 83 f8 04 0f 87 9a 00 00 00 ff 24 85 10 78 48 00 8a 44 24 08 84 c0 0f 85 87 00 00 00 8b 01 5b` — subtract switch value by 2, check range against 4, then jump table dispatch (`ff 24 85 10 78 48 00`). Large switch function with string/byte operations. Between Range Check and Initializes struct with vtable. Worth documenting. |
| 0x0048d095 | 0x0048d230 | 411 | missed_function | high | `56 8b f1 8b 4e 40 e8 85 b6 00 00 51 8b ce d9 1c 24 e8 4a fa ff ff 8b 06 8b ce ff 90 ac 00 00 00 33 c0 5e c3` — thiscall function, reads field at +0x40 from `this`, calls virtual function at vtable+0xac. Between Scrollable UI List Rendering and Linked List Destruction with VTable Call. |
| 0x0049918b | 0x004991e0 | 85 | mixed | medium | Padding + `33 c0 c2 08 00` (xor eax, eax; ret 8 — stub returning 0), then `06 30 ca 5a 00` (data-like), then `56 e8 9a fc ff ff 8b d0 e8 b3 fd ff ff 85 d2 8b f0 74 07 8b ca e8 66 03 00 00`. Contains stub + function fragment with multiple calls. Between Short Computation (VTable Set) and Forwarding function. |
| 0x0049b66f | 0x0049b6d0 | 97 | missed_function | high | `51 d9 44 24 08 56 8b f1 e8 5f c5 0e 00 89 44 24 04 db 44 24 04 d8 0d bc e9 59 00 e8 4c c5 0e 00` — thiscall function with floating-point operations. Loads float from stack, calls function, multiplies by constant at DAT_0059e9bc. Between SpatialGridCell and Lap Time Gap Calculation. Likely a math/spatial function. |
| 0x004b21ca | 0x004b21e0 | 22 | padding | high | NOP sled + `68 e0 21 4b 00 e8 64 59 0d 00 59 c3` (thunk pattern). Between Single Call Wrapper and DebugPrintNullWrapper. |
| 0x004b97a9 | 0x004b97d0 | 39 | missed_function | medium | `c2 0c 00` (ret 0xc — epilogue), then `56 8b 31 85 f6 74 10 8b ce e8 72 c2 ff ff 56 e8 0b e4 0c 00 83 c4 04 5e c3 c0 89 06 8b c6 5e c3`. Two small function fragments: first does null check + 2 calls, second stores and returns. Between Arithmetic/Comparison function and thunk. |
| 0x004d001d | 0x004d0030 | 19 | padding | high | NOPs + `e8 0b 00 00 00 e9 16 00 00 00` (call 12 + jmp 22 — small dispatch stub) + NOPs. Between SpecialFX::Exit and Wrapper. |
| 0x004d89ca | 0x004d8a30 | 102 | missed_function | high | `89 e8 89 dc f2 ff 8b d1 83 c8 ff 89 02 89 42 04 89 42 08 a1 34 cf 5a 00 89 82 dc 00 00 00 c6 82 e0 00 00 00 01 b8 00 00 80 3f 89 82 e4 00 00 00` — initializes struct fields at offsets +0xdc, +0xe0, +0xe4. Loads constant from DAT_005acf34 (likely a default value). Sets +0xe0 byte to 1, +0xe4 to 1.0f. Between iterator function and Audio/State dispatch. |
| 0x004f6ef9 | 0x004f7010 | 279 | mixed | medium | Multiple function fragments: `05 89 e8 85 fe ff ff 8b c1 33 c9 88 08 89 48 04 89 48 08 89 48 0c 88 48 10 89 48 14 89 48 18 89 48 1c c3` (init struct to 0 + ret), then `90 90 90 90 56 8b f1 57 8d 96 b4 00 00 00` (thiscall body using field +0xb4), then more code. Between Parametric Interpolation/Blending and StateHandlerDispatch. |
| 0x00517569 | 0x005176ec | 387 | missed_function | high | `8b 44 24 08 8b 54 24 0c 8b 4c 24 04 d9 00 d8 0a d9 00 d8 4a 08 d9 00 d8 4a 04 d9 00 d8 4a 0c d9 cb d9 40 04 d8 4a 10 d9 40 04 d8 4a 18 d9 40 04` — stdcall function with 3 params, extensive x87 FPU operations. Matrix multiply or 4x4 transformation function. Between Mat2x2Mul and Vector Normalize (Fast rsqrt). Math utility. |
| 0x0052d225 | 0x0052d294 | 111 | data_table | high | Structured binary data: `00 00 00 0c c3 00 80 00 00 00 00 10 d4 5a 00 c4 00 00 00 0c c4 00 80 00 00 00 00 10 d4 5a 00 c5 00 00 00 0c c5 00 80 00 00 00 00 10 d4 5a 00 c6...` — repeating pattern of 16-byte entries with small exponent values and constant pointer 0x005ad410. Lookup table for physics coefficients. Between Quaternion Multiply & Surface Sample (Wheel Contact) and DirectInput8Create Import Stub. Physics data table. |
| 0x0053b3db | 0x0053b490 | 181 | mixed | medium | `e8 79 b2 ec ff 8b 01 83 e0 01 fe c8 f6 d8 1b c0 40 c3` (call + bit test + return boolean), then `90 90 90 90`, then `51 d9 41 3c d9 41 38 d9 c0 d8 c9 d9 c2 d8 cb de c1 d9 fa d9 5c 24 00 dd d8 dd d8` — floating-point math fragment comparing values at +0x3c and +0x38, computes difference. Between Identity 4×4 Matrix Init and Identity Function. |
| 0x00556896 | 0x00556900 | 106 | mixed | medium | `8b 00 e8 1f fd e9 84 fe ff ff` (load + call + jmp — tail call), `e8 0b 00 00 00 e9 26 00 00 00` (call + jmp stub), then NOPs, then `56 57 be 70 bf 8c 00 bf 00 02 00 00 8d 64 24 00 8b ce e8 39 25 ff` — thiscall body with memset-like pattern (rep stosw). Between RDTSC Timestamp Read and Add Float to Animation Channels. |
| 0x00574010 | 0x00575863 | 6227 | missed_function | high | **Major missed function.** `8b 44 24 04 83 f8 27 0f 87 d1 11 00 00 ff 24 85 f1 51 57 00` — stdcall function, parameter compared to 0x27 (39), jump table at 0x005751f1 dispatches >39 cases. Heavy x87 FPU operations: `d9 e8` (fld1), `dd 1d f0 fb 8c 00` (fstp qword ptr [DAT_008cfbf0]), `dd 1d b8 fc 8c 00` (fstp qword ptr [DAT_008cfcb8]). Stores results to known physics globals. Between Block LDL^T Sparse Constraint Factorization (17KB) and Enum value check. **This is a large switch/dispatch function in the dynamics constraint solver chain, likely handling constraint type setup (39 types).** |
| 0x00582f2a | 0x00582f60 | 54 | mixed | medium | `cc cc 00 3b cc c3` (int3 padding + data + ret), then `8a 0d b8 46 8d 00 b0 01 84 c8 75 08 0a c8 88 0d b8 46 8d 00` — reads/writes byte global DAT_008d46b8, then `e9 07 00 00 00` (jmp), then NOPs + thunk pattern. Between Linked-List Node Removal with Cleanup Callback and SEH-Protected Linked List Destruction. |
| 0x005876ca | 0x005876f0 | 38 | mixed | medium | NOPs + `68 e0 76 58 00 e8 64 04 00 00 59 c3` (thunk pattern), then NOPs + `b9 38 3e 8d 00 e9 ef 23 01 00` (mov ecx, DAT_008d3e38 + jmp — tail call). Between Single Function Call Wrapper and Buffered Char I/O Init. |
| 0x0040a8eb | 0x0040a910 | 37 | missed_function | high | MYTH module marker ("MYTH" = 4d 59 54 48) followed by function: 8b 44 24 04 53 32 db 85 c0 74 0c... Standard arg fetch + prologue. Small getter/validator. Context: Multi-Field Membership Check → MenuSlotActionDispatch. |
| 0x0040e74f | 0x0040e770 | 33 | jump_table_data | high | Address table: 0x0040e71f, 0x0040e72f, 0x0040e73f entries. 8 target addresses in sequence. Ends with 90 padding. Context: Short Computation (Field Set via Switch) → Short Computation / Session Update Dispatch. |
| 0x0041c3ba | 0x0041c3e0 | 38 | jump_table_data | high | 8b ff prologue + 6 jump table target addresses (0x0041c24a, 0x0041c254, 0x0041c27c, 0x0041c25e, 0x0041c27c, 0x0041c268, 0x0041c272). Ends 90 padding. Context: Pit Exit / Release Order → Display Message 0x151. |
| 0x0042bb37 | 0x0042bbd0 | 153 | missed_function | high | Call to import (ff 15 a0 e2 59 00) + relative calls/branches. Contains standard code pattern with conditional jumps and function epilogue. Context: AI Shift Pattern / Upshifts-Downshifts → Set Player Vehicle Index. AI config function. |
| 0x0044c790 | 0x0044c7a0 | 16 | missed_function | high | Thunk: e8 0b 00 00 00 (call rel) + e9 36 00 00 00 (jmp rel) + 90 padding. Delayed-call thunk. Context: Collision Callback Registration → CollisionStateInit_Alpha. |
| 0x0044cb44 | 0x0044cb74 | 48 | mixed | medium | Fragment 1: e8 64 b0 13 00 (call 0x00587bad) + 59 (pop ecx) + 90 padding + c3 (ret). Fragment 2: thunk pattern (e8 0b 00 00 00 e9 36 00 00 00). Then mov [0x007cd108], 0x68; mov [0x007cd10c], 0. State variable init. Context: CollisionGridFreeA → Input Handler Global Reset. |
| 0x0044d2c1 | 0x0044d2f4 | 51 | mixed | medium | Same 3-fragment pattern as 567-568. Fragment 1: address + call 0x00587bb0 + ret + padding. Fragment 2: thunk. Fragment 3: mov [0x007ca410], 0x3e; mov [0x007ca414], 0. State var init at +0x3e. Context: CollisionGridFreeB → InitRenderConstantsZeroOne. |
| 0x0044fa3f | 0x0044fa60 | 33 | jump_table_data | high | 90 (NOP padding) + 8 target addresses in 0x0044f9c2–0x0044f9f0 range. Context: D3D Texture Stage / Render Target Setup → DirectX Device Initialization. |
| 0x00465fb6 | 0x00465fd0 | 26 | missed_function | high | Fragment: 8b f1 (mov esi, ecx) + 5f (pop edi) + 8b c6 (mov eax, esi) + e9 a1 fd ff ff (jmp rel). This is a tail-call thunk returning esi. Then standard thunk pattern (e8 0b 00 00 00 e9 26 00 00 00). Context: Recursive Linked List Merge Sort → Collision Distance Reset. |
| 0x00469852 | 0x00469872 | 32 | mixed | medium | Fragment 1: 5e 5b c2 04 00 (pop esi; pop ebx; retn 4) — function epilogue. Fragment 2: b8 38 a4 5e 00 (mov eax, 0x005ea438) + e9 e8 fc ff ff (jmp rel) — import/global address thunk. Fragment 3: 56 8b f1 e8 f8 3a 02 00 (thiscall method). Context: Setup File Load and Finalize → ObjectConstructor. |
| 0x004774bb | 0x00477640 | 389 | missed_function | high | MYTH module marker ("MYTH" = 4d 59 54 48) followed by full prologue: 83 ec 08 53 55 56 57 (sub esp,8; push ebx,ebp,esi,edi) + 8b e9 (mov ebp, ecx). Thiscall method with large stack frame (~389 bytes). Context: UI Element List Destructor → Season/Scene Name Accessor. |
| 0x0047e4a6 | 0x0047e940 | 1178 | missed_function | high | Multiple function fragments. Fragment 1: e8 0e a7 00 00 (call 0x00478bb9) + 33 c0 5e c3 (xor eax,eax; pop esi; ret). Fragment 2: 81 ec 04 01 00 00 a0 38 a4 5e 00 (sub esp,0x104; mov al,[0x005ea438]) + 56 8b f1 — thiscall method checking file path byte. String/file path processing function ~1KB. Context: Circuit Info Page → Call FUN_00566650. |
| 0x0048d3eb | 0x0048d590 | 421 | missed_function | high | 90 padding then 56 8b f1 c7 06 d0 c1 5a 00 (push esi; mov esi, ecx; mov [esi], 0x005ac1d0) — thiscall constructor setting vtable. Followed by e8 b2 8a ff ff (call rel). Then checks byte at [esp+0x24+8] before cleanup call. Object init with vtable 0x005ac1d0 + sub-call. Context: Object Init with VTable+Cleanup → Input Dispatch (Arrow Up/Down). |
| 0x00490326 | 0x00490450 | 298 | missed_function | high | 90 padding + 56 8b f1 e8 e8 63 ff ff (thiscall method). Contains switch dispatch: 83 f8 05 77 1b ff 24 85 70 03 49 00 — compares to 5, jumps to table at 0x00490370. Has 6+ switch cases with virtual calls (ff 50 40, ff 50 48 etc). UI widget event handler. Context: Free linked list nodes → UIWidget_ProcessChildren. |
| 0x0049b8ae | 0x0049b8d0 | 34 | jump_table_data | high | 8b ff (mov edi, edi) hot-patch nop + 7 jump table addresses (0x0049b81f, 0x0049b826, 0x0049b82d, 0x0049b834, 0x0049b82d, 0x0049b826, 0x0049b81f). 90 padding. Context: SteeringInputToGear → Speed Multiplier. |
| 0x004a4810 | 0x004a4830 | 32 | jump_table_data | high | 5 jump table addresses (0x004a4804, 0x004a47ec, 0x004a47f2, 0x004a47f8, 0x004a47fe) + 90 padding. Context: Pit Service Type Name Lookup → Tire Compound Name → ID Mapping. |
| 0x004b9cb9 | 0x004b9cd0 | 23 | missed_function | medium | 90 padding + 8b 01 d9 80 34 0f 00 00 (mov eax,[ecx]; fld [eax+0xf34]) — reads float at offset +0xf34 from pointer. C3 (ret). Then 5f 5e 83 c4 0c c3 (pop edi; pop esi; add esp,0xc; ret) — function epilogue. Small float field accessor. Context: Vehicle Lifetime Average Accessor → Delegates to FUN_004b86e0. |
| 0x004c48f2 | 0x004c4990 | 158 | missed_function | high | Fragment 1: linkage data/call. Fragment 2: 33 c0 56 8b f1 (xor eax,eax; push esi; mov esi, ecx) — thiscall init. 89 06 (mov [esi], eax) then c7 46 04 ff ff ff ff (mov [esi+4], -1) then 89 46 08 89 46 0c 89 46 10 89 46 14 (zeroing 4 fields). Then call e8 d1 03 00 00 (sub-call). Constructor pattern zeroing struct + setting vtable. Context: Vehicle Data Copy → Vehicle Filtering/Selection. |
| 0x004d8a91 | 0x004d8ab0 | 31 | jump_table_data | high | 8d 49 00 (lea ecx,[ecx]; alignment NOP) + 8 jump table addresses (0x004d8a88, 0x004d8a47, 0x004d8a4f, 0x004d8a57, 0x004d8a5f, 0x004d8a67). Context: Unidentified Logic (Audio/State Dispatch) → Unknown. |
| 0x004ddf4c | 0x004ddf70 | 36 | jump_table_data | high | 9 jump table addresses (0x004ddc47, 0x004ddc56, 0x004ddc65, 0x004ddc74, 0x004ddc83, 0x004ddc92, 0x004ddca1, 0x004ddcb0, 0x004ddcbf). 9-entry dispatch table. Context: Pit Crew Instance Setup → Zero-Init Wrapper. |
| 0x00517e0b | 0x00517e43 | 56 | jump_table_data | high | Address table with ~12+ entries spanning 0x00517b20–0x00517da6 range. Context: Unknown → Alloc and Zero Init (Size by Type). |
| 0x00520866 | 0x0052087e | 24 | missed_function | high | Non-standard SSE prologue: 8d 76 00 (lea esi,[esi]; NOP) + 8d bc 27 00 00 00 00 (lea edi,[edi]; NOP) + 53 8b dc 83 ec 08 83 e4 f0 (push ebx; mov ebx,esp; sub esp,8; and esp,~0xf) — stack-aligned frame for SSE code. Followed by 83 c4 08 eb 03 (add esp,8; jmp). Context: SSEVectorCross → SSEVectorMatrixInit. |
| 0x0053b4a1 | 0x0053b4c0 | 31 | padding | high | 90 90 90... (13 NOPs) + 8b 44 24 04 83 c0 28 89 44 24 04 e9 00 00 00 00 — tiny thunk adding 0x28 to parameter then jumping. Mostly alignment padding. Context: Empty Stub → 3x3 Rotation Matrix from Quaternion. |
| 0x0054ea88 | 0x0054eaa0 | 24 | missed_function | high | ff 15 fc e3 59 00 (call [0x0059e3fc] — import) + 5d c3 (pop ebp; ret). Then standard thunk: e8 0b 00 00 00 (call +0x10) + e9 26 00 00 00 (jmp +0x2b) + 90 90 (padding). Import thunk + delayed-call thunk. Context: Bounding-Box from Vertex Data → Call FUN_00548e00 1024x. |
| 0x00579c47 | 0x00579ccf | 136 | jump_table_data | high | Address table with ~25+ entries spanning 0x00578f8a–0x00579c3b range. Physics dispatch table. Context: InitPhysicsTransformIdentity → Physics State Zero-Init. Contains addresses of physics constraint/joint initialization functions. |
| 0x0057b17a | 0x0057b230 | 182 | missed_function | medium | Starts with CC CC CC (int3 padding — debug breakpoint fill). Then ff 15 ff 8b 41 18 (call [0x00598bff] — import) + 56 (push esi) + 85 c0 (test eax,eax) + 57 (push edi) + 0f 84 8e 00 00 00 (je +0x8e). Function with conditional import call, struct field access, loop. Context: Linked-List Buffer Manager Destructor → IntSetInsert. |
| 0x00587a0f | 0x00587a50 | 65 | mixed | medium | Fragment 1: 90 + 8a 0d b8 46 8d 00 (mov cl,[0x008d46b8]) + b0 01 (mov al,1) + 84 c8 75 08 (test al,cl; jnz +8) + 0a c8 (or cl,al) + 88 0d b8 46 8d 00 — atomic flag set/clear on global byte. Fragment 2: thunk (push 0x0047aa60; call; pop; ret). Fragment 3: 90 padding. Global flag bit-set function. Context: Field Constants Initialization → Thunk to FUN_00598815. |
| 0x00597303 | 0x00597321 | 30 | missed_function | high | Two import thunks. Thunk 1: 68 bd 72 59 00 (push 0x005972bd) + ff 15 84 e0 59 00 (call [0x0059e084]) + a3 e4 41 8d 00 (mov [0x008d41e4], eax) + c3 (ret). Wraps import call, stores result to global. Thunk 2: ff 35 e4 41 8d 00 (push [0x008d41e4]) + ff 15 84 e0 59 00 (call [0x0059e084]) + c3 (ret). Passes stored value to same import. Context: Exception/Error Filter → IsBadReadPtr Wrapper. |
| 0x004071c5 | 0x004071f0 | 43 | mixed | medium | Loop body + epilogue (5e 5b c3) followed by zero-init stores and jmp, ending in NOP padding. No standard prologue. Likely tail of prev Spatial Query function. |
| 0x0040e83a | 0x0040e860 | 38 | jump_table_data | high | Repeated 4-byte addresses (0x0040e7cb, 0x0040e7da) in game code range. Jump table for prev short computation/dispatch function. Trailing NOP alignment. |
| 0x004132e2 | 0x004133b0 | 206 | jump_table_data | high | Address table (0x00412e7f, 0x00412e95, ... 0x00412f71+) pointing into prev DirectInput Scancode Mapping function (0x00412e50). 12+ entries, growing stride pattern. Used for scancode→action dispatch. |
| 0x0042c631 | 0x0042c690 | 95 | jump_table_data | high | Address table (0x0042c493, 0x0042c4a9, ... 0x0042c56a+) pointing into prev DynMan::Restart() function. 12+ entries. Jump table for dyn dispatch. |
| 0x00435250 | 0x00435260 | 16 | padding | high | Two instructions: call next_func (0x00435260) then jmp into next_func. Trailing NOPs. Failed thunk or alignment filler. No independent utility. |
| 0x0044cb89 | 0x0044cba0 | 23 | padding | medium | Same pattern as 608: NOPs + push/call/pop/ret. Between Input Handler Global Reset and CollisionGlobalInitF. |
| 0x0044cf49 | 0x0044cf60 | 23 | padding | medium | Same pattern as 608: NOPs + push/call/pop/ret. Between Global State Initializer and Collision/Audio Init Block. |
| 0x004516a0 | 0x00451720 | 128 | jump_table_data | high | Address table with 12+ entries (0x00450668, 0x0045073b, ... 0x0045140d) pointing into prev Audio Channel Initialization function (0x0044ff50). Jump table for audio channel state dispatch. |
| 0x0045c064 | 0x0045c0a0 | 60 | mixed | low | Contains sprintf/format call setup (push string pointers 0x005c5b80, 0x005c5b74), global refs (DAT_007cd264, DAT_007cd270), ret/c3, jmp, and NOP alignment. Mix of leftover init code and padding between struct init functions. |
| 0x004698bc | 0x00469900 | 68 | missed_function | high | NOP + thiscall prologue (56 8b f1). Accesses field at [esi+0x180]. Null-check then conditional call. More field access and function call. Method of UI dialog class related to prev function (UI Dialog/Property Page Constructor). |
| 0x0046fd4e | 0x00470190 | 1090 | missed_function | high | thiscall member function. Reads field at [ecx+0xe4]. Checks DAT_007c56a4 (SessionType) == 6 (qualifying branch). 1090 bytes — substantial game logic function with session-type dependent paths. |
| 0x0047e95a | 0x0047ee5c | 1282 | missed_function | high | C++ constructor/initializer. thiscall body (56 57 8b f1). Sets vtable pointer at [esi] to 0x005a6c78. Zero-init fields [esi+0xec], [esi+0xf0]=-1. Accesses [esi+0x44] for iteration. 1282 bytes. |
| 0x00487f3b | 0x00488180 | 581 | missed_function | high | Member function: loads field at [ecx+0x84], compares with param, conditional. Virtual dispatch through [edx+0x2c]. Zero-init of fields at 0x80 and 0x84. 581 bytes. VTable + cleanup pattern. |
| 0x00490535 | 0x00490550 | 27 | jump_table_data | high | Address entries (0x00490490 ×3, 0x004904a8 ×3) pointing into prev UIWidget_ProcessChildren function. Compact jump table for widget action dispatch. |
| 0x00499516 | 0x00499580 | 106 | missed_function | medium | Code starts messy (50 52 e8...) but contains a clean linked-list traversal loop at offset ~0x16: [ecx+0x44]→[esi+0x8c] chain with virtual call [eax+0xa4]. Loop body with null-check. Tail of render dispatch. |
| 0x004a48b1 | 0x004a4900 | 79 | mixed | medium | First 9 bytes = epilogue of prev function (ff d8 5f 5e 5d 32 c0 5b) + jmp back. Then new function at '53 56 57 8b f9': iterates 5 times (ebx=5, step 0x40). Contains both tail and new code. |
| 0x004b3acf | 0x004b3af0 | 33 | missed_function | high | Complete small function: mov eax,ecx, stores to [eax+0x6c00c] and related offsets, zero-init of [eax], ret. NOP alignment. Ring buffer / allocator context. |
| 0x004c5172 | 0x004c51a0 | 46 | mixed | high | First part: epilogue of prev function (5f 03 c1 5e c2 04 00). Cleanup function: loads DAT_008ac490 (SceneArray), null-check + call + zero-out global. References known global. |
| 0x004d0f09 | 0x004d1027 | 286 | missed_function | high | First 5 bytes garbled (c4 0c 5f 5e — les instruction, not executed). Real function at '56 57 8b f1': thiscall constructor/init. Zero-init of 10+ fields at offsets +0xe0, +0xe4, +0xec, +0xf0, +0xf8, etc. 286 bytes. |
| 0x004de57f | 0x004de5d0 | 81 | mixed | medium | Header: 4 jump table addresses (0x004de176 etc) into prev Scene File writer. Body: x87 comparison function — loads floats at [arg+0xc] and [arg2+0xc], compares via fcomp, returns boolean. Forward jump table + code. |
| 0x004f82f2 | 0x004f8330 | 62 | mixed | high | Jump table header: 3 addresses (0x004f82bc, 0x004f82d7, 0x004f82ee) into prev Color/Palette Lookup. Followed by 32-byte data table: repeating 0x01/0x02 bytes — palette category remap or color index mapping. |
| 0x005208eb | 0x005208fe | 19 | missed_function | high | Same CRT stack-alignment thunk as GAP 632 (53 8b dc 83 ec 08 83 e4 f0 83 c4 08 eb 03). Between SSE matrix functions. |
| 0x0052d96c | 0x0052d990 | 36 | missed_function | high | Null-check wrapper: loads [ecx], tests zero, calls function with 2 params if non-null, else returns 0. retn 8. Clean small member function. Trailing NOPs. |
| 0x0054eac0 | 0x0054eaf0 | 48 | mixed | medium | Tiny thunk: push 0x0054ead0 + call + pop + ret. Then backward-iterating loop: esi = 0x008cbf48, 1024 iterations (edi=0x400), step -0x18 (24 bytes), calls FUN_00548e00 each iteration. Destructor/cleanup mirror of prev forward init. |
| 0x0055be5e | 0x0055be80 | 34 | missed_function | medium | Loads DAT_008b8f28, pushes args, mov ecx=0x008b78a0, calls. retn 4. Remaining bytes (7c f2 5e c2 04 00 33 e9) unclear — data or unreachable tail. |
| 0x0057b290 | 0x0057b2e0 | 80 | missed_function | high | Set/lookup member function: reads [ecx+4] byte flag, early return. Reads [ecx+0x18], stores to [ecx+0x20], null-check. Linked-list traversal comparing param with [eax]. List/set data structure method. |
| 0x005834b4 | 0x00583530 | 124 | missed_function | high | Contains linked-list traversal with nested loop. Field accesses at [esi+4], [esi+8], [esi+4] (linked list next pointer). String byte check at [ebp+8]. Preceded by jmp tail from prev code. Data structure iteration. |
| 0x00597371 | 0x00597388 | 23 | missed_function | medium | Sequential call init sequence: push 0xa + call, push 0x16 + call (to next_func at 0x00597388), push 3 + call. No prologue. Stripped init thunk calling with literal arguments 10, 22, 3. |
| 0x0040721b | 0x004072e0 | 197 | missed_function | medium | "MYTH" tag (4-byte marker) followed by function prologue; audio context between Audio Sample Setter and Miles Sound allocator |
| 0x0040b25a | 0x0040b410 | 438 | missed_function | medium | No EBP frame but uses sub esp/push esi/mov esi,ecx (MSVC FPO); between Scene Loader and ListContains |
| 0x00413efa | 0x00414010 | 278 | jump_table_data | high | Repeating addresses 0x00413bb9..0x00413c27 in range of Season-Specific Team ID Lookup; 12+ entries |
| 0x0041f037 | 0x0041f070 | 57 | missed_function | medium | Starts with indirect call through import, then push esi/mov esi,ecx (thiscall); between Count Matching Entries and Relative Performance Comparator |
| 0x0043526a | 0x00435290 | 38 | mixed | high | NOP padding + small thunk (push addr + call + pop + ret) + NOPs + ecx-load thunk + NOPs |
| 0x0044c7f0 | 0x0044c800 | 16 | mixed | high | Thunk pattern: call-next-return (e8 0b) + forward jump (e9 36) + NOP padding; linker-generated |
| 0x0044cf61 | 0x0044cf94 | 51 | mixed | high | Data byte (0xcf) + thunk + NOPs + nullsub + thunk pair + code writing DAT_007ca480=0x27, DAT_007ca484=0 |
| 0x0044d321 | 0x0044d340 | 31 | mixed | high | Data byte + thunk + NOPs + nullsub + thunk pair + NOPs (last 4 bytes seem like start of next object) |
| 0x0045c75e | 0x0045c780 | 34 | mixed | medium | NOPs + small function (movsx two WORDs, subtract, ret) + tail bytes of previous function |
| 0x00466114 | 0x00466140 | 44 | mixed | high | NOP padding + two tiny nullsubs (xor al,al; ret 4) / (xor al,al; ret 0xc) + short code |
| 0x00470230 | 0x004702f0 | 192 | missed_function | high | Constructor: vtable pointer set to 0x005a0250, multiple push arguments, init call; second constructor with boolean parameter check |
| 0x00477ea0 | 0x00477f30 | 144 | missed_function | high | Constructor/init: lea ecx,[esi+0x124] sub-call, sets fields at +0x15c=-1, +0x158=0, +0x1c=-1, +0x120=-1; between Profile Bitmap Browser and ProfileIconBmpLoader |
| 0x004881a4 | 0x004881f0 | 76 | mixed | medium | NOP + vtable dispatch (call [eax+0xa8]) returning 0; then constructor/destructor with struct offset +0xe0 and delete check |
| 0x0048d6ab | 0x0048d740 | 149 | missed_function | medium | thiscall prologue, calls sub at [esi+0x40], conditional branch on result, reads [eax+0xc0], loads 0x005ea438 (LoadPath global); between Short Computation and Large Zero-Init Constructor |
| 0x0049964b | 0x00499660 | 21 | mixed | high | "MYTH" tag + null + thunk pattern + NOP padding |
| 0x0049d6ab | 0x0049d700 | 85 | jump_table_data | high | Addresses 0x0049d5e8..0x0049d6a7 in range of HUD_TachoRenderDispatch (0x0049d5d0); switch table |
| 0x004b3d2e | 0x004b3d40 | 18 | padding | high | Thunk pair + NOP padding; no real function |
| 0x004b9d87 | 0x004b9da0 | 25 | mixed | high | NOPs + small wrapper (mov arg, [ecx], call, ret 4); between thunk to FUN_004b8140 and MenuActionDispatch |
| 0x004d21ee | 0x004d2210 | 34 | mixed | medium | Thunk call + short jmp + data bytes (zeros, 01010101) + NOPs; between Race Phase Check and Pit Close |
| 0x004d90bb | 0x004d90d0 | 21 | jump_table_data | high | 5 addresses 0x004d9045..0x004d9061 in range of Audio Resource Release (0x004d9030) |
| 0x004f8cfa | 0x004f8d10 | 22 | padding | high | Thunk pair + NOP padding |
| 0x0051ed91 | 0x0051edae | 29 | padding | high | Alignment NOPs before Normalized Vector function; includes first 12 bytes of next function's prologue (push ebx/mov ebx,esp/stack align) |
| 0x0052d9c6 | 0x0052d9f0 | 42 | mixed | high | Garbage/tail bytes from prev function + destructor (check delete flag, call free, ret 4) |
| 0x0053c110 | 0x0053c140 | 48 | missed_function | high | 3D vector dot product: reads floats at [ptr+0],[ptr+4],[ptr+8], multiply-add pairs, ret 8; then thunk + NOP |
| 0x0055c62d | 0x0055c650 | 35 | jump_table_data | high | 6 addresses 0x0055c476..0x0055c4ef in range of prev func (0x0055c450) |
| 0x00579fa0 | 0x00579fb0 | 16 | padding | high | Thunk pair + NOP padding |
| 0x00584c27 | 0x00584c70 | 73 | jump_table_data | high | Addresses 0x005842fa..0x00584a4e in range of prev large function (0x00584130); includes entry 0x00584c08 just before gap |
| 0x00587a9a | 0x00587ac0 | 38 | mixed | high | NOPs + thunk (push 0x00587ab0 + call + pop + ret) + NOPs + ecx-thunk (loads DAT_008d3e3c, jmp to FUN_0058dae6) + NOPs |
| 0x0040b48b | 0x0040b560 | 213 | mixed | medium | Starts with "MYTH\0" string marker (5 bytes: `4d59544800`), then clear thiscall function prologue `83ec1c535657` (sub esp,0x1c; push ebx; push esi; push edi). String tag + function code. Likely a class method in the "MYTH" module namespace. |
| 0x0040ef52 | 0x0040ef70 | 30 | jump_table_data | high | Array of 6 identical 4-byte pointers `0eef4000` (all pointing to 0x0040ef0e within previous function), terminated by `90909090` padding. Switch jump table for previous function at 0x0040eec0. All cases fall through to same target. |
| 0x0041f147 | 0x0041f190 | 73 | missed_function | high | Clear thiscall function: `ff1538e05900` (call import), `c3` (ret), then `568bf1` (push esi; mov esi, ecx), `85f67420` (test esi,esi; jz skip), loads global `b9b02d7d00` (ecx=0x007d2db0), calls `e8ef360a00`, checks result, accesses `[esi+eax*4+0x14]`, returns bool. AI/ability lookup function. |
| 0x0042ce0a | 0x0042ce20 | 22 | missed_function | high | Thunk function: NOP padding, `6820ce4200` (push 0x0042ce20 - address of next function), `e824ad1500` (call somewhere), `59` (pop ecx), `c3` (ret), more NOPs. Redirect wrapper calling into next function. |
| 0x0044c829 | 0x0044c840 | 23 | missed_function | high | Thunk: NOPs, push 0x0044c840, call, pop, ret, NOPs. Calls into next function (Collision Material Coefficients). Collision pipeline wrapper. |
| 0x0044cbe9 | 0x0044cc00 | 23 | missed_function | high | Thunk: NOPs, push 0x0044cc00, call, pop, ret, NOPs. Calls into next function (Collision Globals Init #4). Collision init wrapper. |
| 0x0044d369 | 0x0044d380 | 23 | missed_function | high | Thunk: NOPs, push 0x0044d380, call, pop, ret, NOPs. Collision broadphase wrapper. |
| 0x00453293 | 0x004532d0 | 61 | missed_function | medium | Contains `eb` (short jmp) at start (likely branch from prior code), then `fld` and `e9` (long jmp) tail call, then function body with `5657` (push esi; push edi), `lea esi,[ecx+0x2410]`, loop over array of size 0x2c with `8b46f8` `83ee08` `85c0` pattern (traversing linked list or struct array). Memory/audio scene setup helper. |
| 0x004661a5 | 0x0046624e | 169 | missed_function | high | Contains at least 2 functions: (1) `32c0 c20c00` — `xor al,al; retn 0xc` (return false stub), (2) thiscall prologue `568bf1` with field access `[esi+0xe8]`, conditional call to `e888050300`, FPU ops (`d98624010000`, `d81d40e45900`). Between forwards-call and byte-flag-setter. |
| 0x0046a24a | 0x0046a270 | 38 | mixed | medium | Starts with `00` byte (add [eax],al — NOP-like), then `e809c4f9ff` (call), then thiscall prologue `568bf1`, conditional destruction via `f644240801` (test flags), calls cleanup. The leading `00` may be data or padding. Likely destructor/cleanup method. |
| 0x00477f9e | 0x00478e80 | 3810 | missed_function | high | **LARGE GAP — 3.8KB.** Clear thiscall function prologue: `568bf1` `8b4e40` (load [esi+0x40]), `8b01` (vtable ptr), `57` `6a03` `ff501c` (vtable call[+0x1c]), `8bf8` `85ff7426` (null check). Then calls `e8a5530100` and compares result with `[esi+0x11c]`. Likely contains multiple sub-functions Ghidra missed. May be a significant game logic function (3.8KB is large for a single function). Prev: ProfileIconBmpLoader. Next: delegates to FUN_00499b80. |
| 0x0047ef75 | 0x0047eff0 | 123 | jump_table_data | high | Array of 12+ 4-byte pointers to addresses 0x0047eb93–0x0047ed85 (within previous function space). Entries are ~0x2E bytes apart — consistent case label spacing. Switch jump table for previous function at 0x0047ef3c (Percentage Display Formatter). |
| 0x0048d7c3 | 0x0048d850 | 141 | missed_function | high | Contains multiple small vtable wrapper functions separated by NOP padding: (1) `8b01 ff90ac000000 33c0 c3` — call [vtable+0xac], return 0, (2) `8b01 6a00 ff5040 33c0 c3` — call [vtable+0x40], return 0, (3) function with `8b5424` and other logic. UI auto-scroll context. |
| 0x00491e91 | 0x00491ee0 | 79 | missed_function | high | Function with `56 e85f5d0f00 83c404` (push esi; call; add esp,4), then `e90b000000` (jmp over padding to memset block at 0x00491eb0): `33c0 57 b960000000 bf70db7c00 f3ab` — memset pattern clearing 0x60 dwords at 0x007cdb70. Then returns. Memory init for global buffer. |
| 0x0049e489 | 0x0049e4e0 | 87 | missed_function | high | Two functions: (1) `e8b90d0000 c3` — call + ret (tiny helper), (2) struct zero-init: `33c0` `88 01` `89 41 04 08 0c 10 14 18 1c 20 24 28 2c 30 34` — stores 0 to 14 consecutive dword fields (56 bytes) in a struct at [ecx]. Audio/effect trigger context. |
| 0x004a6fc4 | 0x004a6fe0 | 28 | unknown | low | Only 28 bytes. Hex `c41ce9bed2ffff5e83c41cc3e80b000000e916000000909090909090`. Contains `les ebx,[ecx]` (unusual instruction), `mov esi,-0x2e`, `pop esi`, `add esp,0x1c`, `ret`, then call+jmp. May be end of previous function that Ghidra cut at wrong boundary, or embedded data. Pit state context. Not clearly a standalone function. |
| 0x004b9e02 | 0x004b9e30 | 46 | jump_table_data | high | Array of 6 pointers to 0x004b9db7–0x004b9df6 (within previous MenuActionDispatch function), followed by `00000000` (3 dwords padding), then byte sequence `01 02 03 04 05` (case index map or action size table), then NOPs. Switch jump table + auxiliary small data table. |
| 0x004c7773 | 0x004c77d0 | 93 | missed_function | high | Thiscall function: `8bcd` (mov ecx,ebp), loads `[edi+0x38]`, shifts right 0x19 (bit 25 extraction), stores to `[ebx+0x1067]`. Calls FUN_00402aee (`e876b3feff`), pushes return value, calls another function, stores 16-bit result to `[ebx+0x48b0]`. Reads `[edi+0x3b]`. Between Vehicle Physics Time Step and TireTemperatureSimStep — likely tire/thermal wheel struct field extraction helper. |
| 0x004d921a | 0x004d9280 | 102 | jump_table_data | high | Array of 20+ pointers to addresses 0x004d91f2–0x004d9212 (within gap and prev function at 0x004d91e0, ID-to-Value Mapper). Multiple entries point to 0x004d9212 (same case handler). Switch jump table with shared cases. |
| 0x004e169a | 0x004e16c0 | 38 | jump_table_data | high | Array of 6 pointers to 0x004e0f24–0x004e1647 (within previous Audio/Sound Effect Controller function), followed by byte flags `00 01 00 01 01 00 00` (case property table: mapping from jump table entry index to some boolean attribute), then NOP padding. Switch jump table + attribute byte table. |
| 0x0051ee66 | 0x0051ee7e | 24 | missed_function | medium | Stack alignment prologue: `53 8bdc 83ec08 83e4f0 83c408 eb03` — push ebx; mov ebx,esp; sub esp,8; and esp,-16; add esp,8; jmp +3 (tail into next function). Part of a function split at wrong boundary. The stack realignment to 16 bytes is characteristic of SSE-aligned functions. Physics vector normalize context. |
| 0x00520a64 | 0x00520a7e | 26 | missed_function | medium | Same stack alignment prologue as gap 716: alignment NOPs + `53 8bdc 83ec08 83e4f0 83c408 eb03`. Stack realignment preamble for next function (QuaternionToRotationMatrix). SSE-aligned math function prologue split off. |
| 0x0053c14a | 0x0053c190 | 70 | missed_function | high | Two components: (1) thunk `6860c15300 e8e4b90400 59 c3` (push 0x0053c160, call, pop, ret). (2) global flag manipulation: reads `[0x008b8ee4]`, tests bit 0, sets bit 0 if clear, then loads `0x008b6bd0` (ecx), presumably tail-calls a method on that object. Global flag protect/unprotect pattern. |
| 0x0054fd1d | 0x0054fd30 | 19 | jump_table_data | high | 4 pointers to 0x0054fcd5–0x0054fd0e (within previous function at 0x0054fcc0, Unidentified Logic). Small switch jump table. |
| 0x00579fba | 0x00579ff0 | 54 | missed_function | high | Two functions: (1) thunk `68d09f5700 e874db0000 59 c3` (push 0x00579fd0, call, pop, ret). (2) tail-call function: `b9f13b8d00` (mov ecx, 0x008d3bf1 — physics state address), `e9bae90100` (jmp to function — tail call). Then NOPs + call/jmp stub. Physics constraint solver context. |
| 0x0057b6ca | 0x0057b780 | 182 | missed_function | medium | Starts with `cc 00 00 4b cc 00 51` — some INT3 (debug break) bytes followed by 32-bit value 0x004b0000? Then thiscall prologue `51 56 8bf1 8b4c2410 8d442404 57 8b7c2410 50 51 57 8bce c744241400000000` — pushes args, sets up stack, calls `e87debffff`. Struct init with vtable + field set context. The leading INT3 bytes may indicate a code region preceded by debug markers. |
| 0x00587b50 | 0x00587b7f | 47 | missed_function | high | Memory allocation: `6880000000` (push 0x80 = 128 bytes), `e8db2d0000` (call alloc), stores result to `[0x008d5a54]`, conditional: if null, `6a18 e83b270000` (push 0x18, call alt alloc), then clears dword at allocated ptr: `832000` (and [eax],0), stores to `[0x008d5a50]`. Global buffer allocation/init for timer or session data. |
| 0x005992d3 | 0x005992ef | 28 | missed_function | high | Destructor/cleanup: `568bf1` (thiscall), calls `e85efbffff`, checks `[esp+8]` bit 0 flag, if set: `56 e8e7e8feff 59` (push esi; call delete; pop ecx). Returns `8bc6` (mov eax, esi). Conditional deletion based on flag. Destructor pattern with allocator flag. |
| 0x004076d4 | 0x00407be0 | 1292 | mixed | medium | Jump table data (address array) + missed function at offset ~6 (53 56 57 8B F9 prologue). Large region, likely contains real function with preceding data. |
| 0x0040f0b0 | 0x0040f0d0 | 32 | jump_table_data | high | Alternating address pattern: 0x0040ef8c / 0x0040efb2 repeated 4 times. 8 entries total. Between Physics State Vector Conversion and Short Computation functions. |
| 0x004141d7 | 0x00414370 | 409 | mixed | medium | Collection of thunks/trampolines (E8 0B 00 00 00 E9 16 00 00 00 pattern) with padding (90s). Also contains MOV ECX, addr + JMP pattern (B9 ... E9 ...) and PUSH addr + CALL pattern. Multiple small trampoline stubs. |
| 0x0042cea0 | 0x0042cf10 | 112 | jump_table_data | high | 12 jump table entries pointing to 0x0042ce40-0x0042ce94 range. Between Session Type Name Lookup and Session Reset. |
| 0x0043b9d8 | 0x0043ba20 | 72 | mixed | high | Jump table (8 entries to SolverDispatch scope: 0x0043b94e-0x0043b9d5) + byte lookup table (00 07 07 07 07 07 01 02 07 07 07 07 03 07 07 07 07). Between SolverDispatch and Constraint Force Solver. |
| 0x0044cc02 | 0x0044cc34 | 50 | mixed | medium | Small data byte (44 00) + CALL to real function (0x00587bab) + P op ECX/RET + padding + thunk pattern (E8 0B/E9 16) + global init code writing 0x1e and 0x0 to 0x007ca3b8/bc. |
| 0x0044cfc1 | 0x0044cff4 | 51 | mixed | medium | Similar pattern to 735: data byte (CF 44 00) + CALL to 0x00587baa + POP/RET + thunk pattern + global init code writing 0x28 and 0x0 to 0x007ce9ec/f0. Between ThunkCollisionInitB and Float/float init. |
| 0x00454c4b | 0x00454d30 | 229 | mixed | high | Jump table (3 entries: 0x00454c3d, 0x00454c45, 0x00454c48) + byte lookup table (00 01 01 01 ... 02 02 02 ...). Byte table maps values 0/1/2, likely ID mapping. Between Enum-to-ID Mapping and parameter lookup function. |
| 0x0045d2cd | 0x0045d490 | 451 | missed_function | high | Real function with non-standard prologue. Starts with 3x 90 padding then 8B 44 24 08 83 F8 02 (parameter access + comparison). Switch-like dispatch on param_1 values 1, 2, 3. References globals including 0x007cd2a0. 451 bytes — substantial function. Between Network/Replay Buffer Init and Global Flag-Based State Setter. |
| 0x0046a3c7 | 0x0046a560 | 409 | missed_function | medium | Real function code after 9-byte padding. References 0x007ce5ec (global check) and 0x005ea438 (LoadPath). Uses thiscall convention (mov esi, ecx). Contains conditional load of LoadPath constant when global null. 409 bytes. Between VTable Set+Free+Call and Standings Display. |
| 0x00470632 | 0x00470f20 | 2286 | mixed | medium | Large region. Starts with 2-byte 00 00 then address write to [esi] (C7 06 08 03 5A 00 = 0x005a0308). Followed by what appears to be real function code with cmp at [ecx+0x304] vs 0x1b5, conditional branches. May contain data at start + missed function(s). 2286 bytes between Session Message/UI Command Handler and Race/Session Mode Data Loader. |
| 0x0047f10d | 0x0047f180 | 115 | missed_function | high | Real thiscall method. Reads global 0x007cd468 (pointer), loads 0x005ea438 (LoadPath) as fallback. Pushes 0x005ec4cc (MessageBuffer) and 0x005ec4c0. Real function with string/UI context. Between LoadAndProcessMessageBuffer and Doubly-Linked List Append. |
| 0x00488a1e | 0x00488a30 | 18 | missed_function | high | Small thunk: 2-byte padding + JMP backward (to 0x004883ce) + padding. Between Frame Rate Ratio and UIScrollWidgetUpdate. |
| 0x004943cf | 0x00494430 | 97 | jump_table_data | high | 12 jump table entries: 0x00494035-0x0049423a. All point within Resource Path Builder function (0x00493e20). Between Resource Path Builder and UI Destructor. |
| 0x00499bef | 0x00499c50 | 97 | missed_function | high | Contains 2+ small functions. First: boolean return (neg+sbb+inc pattern), takes one param, RET 4. Second: reads [esi+0x2c], tests, conditional jmp to function or ret. Between Struct Equality and Constructor with -1 Sentinels. |
| 0x004a6fea | 0x004a7000 | 22 | missed_function | high | Thunk: pushes address of next function (0x004a7000 = AutoLoadConfigFileInit) then calls function. Callback registration pattern. Between Single Call Wrapper and AutoLoadConfigFileInit. |
| 0x004b419d | 0x004b41b0 | 19 | missed_function | high | Small thunk identical to 734/737: 3-byte padding + CALL +0x10 + JMP +0x1b + padding. Between Render::Post() and Short Computation Call Wrapper. |
| 0x004c7c1b | 0x004c7c30 | 21 | missed_function | high | Small function: CALL backward + CALL +0x10 + JMP +0x1b + padding. Two sequential calls, then thunk pattern. Between Conditional Delegation and Single Function Call Wrapper. |
| 0x004d2448 | 0x004d24a0 | 88 | missed_function | high | Real function iterating vehicle array. References VehicleCount (0x005c329c) and VehiclePtrArray (0x007c54f0). Reads offset 0x6440 from each vehicle. Loop over all vehicles. Between Pit Timer State Init and Check First Uninitialized Vehicle. |
| 0x004e189e | 0x004e18c0 | 34 | jump_table_data | high | 8B FF nop + 4 jump table entries (0x004e17dd, 0x004e183f, 0x004e184d, 0x004e1873) + byte array (00 00 00 00 01 02 03 03 03...) + padding. Between Subsystem state machine and Subsystem ready query. |
| 0x004fa7b8 | 0x004fa7e0 | 40 | jump_table_data | high | 8 entries: 0x004fa690 (x5), 0x004fa6a3, 0x004fa6cb (x2). Targets in VidMan::Restart range. Padding after. Between VidMan::Restart and VidMan::Post(). |
| 0x00520bfa | 0x00520c0e | 20 | missed_function | medium | Nearly identical thunk to gap 758: alignment NOP, PUSH EBX, MOV EBX, ESP, stack alignment, JMP +3 (to next function at 0x00520c0e). Between QuaternionToRotationMatrix and SSE Reciprocal Square Root. |
| 0x0052e051 | 0x0052e080 | 47 | mixed | low | Large padding (15x 90) + thunk (PUSH addr in gap, CALL func, POP ECX, RET) + more padding + conditional code (MOV EAX,[0x008b0108], TEST, JE, JMP backward). Multiple small fragments. Between CPUID check function and 64-bit Integer Division. |
| 0x0054ffe4 | 0x00550080 | 156 | data_table | high | Binary permission/validity lookup table. Starts with address-like bytes (likely not valid code) then extended byte sequence of 0x00/0x01 values. Pattern resembles permission matrix. Between String Allocation+Path Extract and D3D Texture Creation. |
| 0x0055eeaf | 0x0055ef24 | 117 | missed_function | high | REAL FUNCTION WITH STANDARD PROLOGUE: 55 8B EC (PUSH EBP, MOV EBP, ESP). Saves many registers (56 57 50 53 51 52). Loads 3 params from stack. Performs element-wise floating-point multiply (FLD/FMUL sequence) operating on vectors at [ebp+8], [ebp+12], [ebp+16]. Math utility (3x3 matrix × vector or element-wise scaling). Between unnamed function and 3x3 Matrix×Float3 Multiply. |
| 0x0057b7ac | 0x0057b7f0 | 68 | missed_function | high | 2+ thiscall methods (56 8B F1). First: calls local function, tests byte [esp+8] bit 0, conditionally calls cleanup function, returns ESI. Second: reads param from stack, calls function. Between Object Init with VTable and VTable Pointer Init. |
| 0x0058543e | 0x00585470 | 50 | missed_function | high | Clean thiscall method. LEA ECX,[ESI+0x12c], calls function, compares return with [esp+8], writes result to [esi+0x80]. Conditional setter. Between VTable Dispatch and next function. |
| 0x00599754 | 0x0059977e | 42 | missed_function | high | Lazy initialization / one-time-init pattern. Tests byte flags at 0x008d46b8 and 0x008d5a64, sets them if not set, calls init functions. Between Char-by-Char Backward Scan and Cleanup Wrapper. |
| 0x00407fad | 0x004080b0 | 259 | missed_function | Medium | Function at offset +3 (56 8B 74 24 08). Orphan — no xrefs. Resource/list lookup context. |
| 0x0040b849 | 0x0040bcd0 | 1159 | mixed | Medium | First ~0x10 bytes data/garbage; then proper function prologue (53 55 56 8B E9 57) with memset (33 C0 B9 60 00 00 00 F3 AB). Large viable function in camera/scene context. |
| 0x00414477 | 0x004144c0 | 73 | missed_function | Medium | Starts with FF 15 (call [IAT]) then E8 (call). 73B viable. Near TableLookupByIndex — likely a small lookup/dispatch function. |
| 0x0041f82b | 0x0041f8a0 | 117 | jump_table_data | High | 12 x 4-byte function pointers: 0x0041f63c, 0x0041f643, ... 0x0041f689. All spaced 7B apart. For Championship Points logic. |
| 0x00447267 | 0x004472a8 | 65 | mixed | Medium | Heavy 90 padding. Small stub (C6 81 59 1C 00 00 00 C3 = byte store + ret, 9B). Rest likely alignment/padding in suspension context. |
| 0x0044c889 | 0x0044c8a0 | 23 | missed_function | High | Thunk: push 0x0044c8a0 → call → pop ecx → ret. Collision init context. |
| 0x0044d009 | 0x0044d020 | 23 | missed_function | High | Thunk: push 0x0044d020 → call → pop ecx → ret. Collision/float init context. |
| 0x0044d3c6 | 0x0044d3e0 | 26 | missed_function | High | Thunk: push 0x0044d3e0 → call → pop ecx → ret. Collision broadphase context. |
| 0x0045d4bd | 0x0045d4e0 | 35 | missed_function | Medium | Small function: cmp byte [ecx],0; je; mov al,[ecx+1]; test; je; xor ecx,ecx; jmp. Null-terminated string check pattern. |
| 0x0046633f | 0x00466350 | 17 | mixed | High | 8B 49 40 (mov ecx,[ecx+0x40]) → 6A 00 (push 0) → E8 (call) → C3 (ret) = small thunk. Followed by ASCII string "MYTH\0" (4D 59 54 48 00). |
| 0x00470f79 | 0x004713e0 | 1127 | missed_function | High | Constructor: sets vtable 0x005a0a80 at [esi], vtable 0x007cf65c at [esi+0x31c], zero-init fields. Large (1127B) — major missed function. Race/session data loading context. |
| 0x00478ed0 | 0x00479170 | 672 | missed_function | High | Clean member function: 56 8B F1 (push esi; mov esi, ecx), reads [esi+0x15c], strlen pattern (F2 AE). 672B. Hit test/bounds check context. |
| 0x00488aaa | 0x00488b00 | 86 | missed_function | High | Member function: 56 8B F1, loads vtable from [esi], sets byte [esi+0xed]=0, virtual call [eax+0x9c], checks result. UI scroll widget context. |
| 0x0048ddf5 | 0x0048df40 | 331 | missed_function | High | Thunk at start (8B 01 6A 00 FF = mov eax,[ecx]; push 0; jmp [eax]) then proper function: 83 EC 08 56 57 8B F1 with pointer/string setup. Media playback context. |
| 0x00499cbe | 0x00499ce0 | 34 | missed_function | Medium | Small member function: 56 8B F1 → E8 call → flag test → conditional call. Destructor-like pattern (flag check then conditional cleanup). |
| 0x0049f66d | 0x0049f6a0 | 51 | jump_table_data | High | 8 x 4-byte function pointers: 0x0049f563, 0x0049f57f, 0x0049f59d, ... 0x0049f610. Two entries duplicated. Followed by 90 padding. |
| 0x004b41ba | 0x004b41e0 | 38 | missed_function | High | Two thunks: (1) push 0x004b41d0 → call → pop → ret; (2) MOV ECX, 0x008ab6e4 (known global ScoringGate) → JMP. File stream writer context. |
| 0x004b9f90 | 0x004b9fa0 | 16 | missed_function | High | Thunk: ADD ECX, 8 → JMP backward (tail call with this+8 adjustment). Object init context. |
| 0x004d2dbb | 0x004d2dd0 | 21 | jump_table_data | High | 4 x 4-byte pointers: 0x004d2cfb, 0x004d2cb7, 0x004d2cfb (dup), 0x004d2d22. Race results context. |
| 0x004d9400 | 0x004d9420 | 32 | jump_table_data | High | 5 x 4-byte pointers, all 0x004d93f3 (same target — default case). Range check (1-5) context. |
| 0x004fb8c2 | 0x004fb8e0 | 30 | mixed | Medium | Two identical epilogue sequences (5F 5E 5D 5B 59 C3) with FSTP ST0 between them, followed by CALL + JMP. Possible EH cleanup thunk or dual-exit function. Collision context. |
| 0x0051f0a8 | 0x0051f0be | 22 | missed_function | High | SSE stack-alignment prologue: 8D B4 26 00 00 00 00 (NOP-like LEA), 53 8B DC 83 EC 08 83 E4 F0 83 C4 08 EB 03. Aligned stack setup for SSE. Matrix multiply context. |
| 0x0052e198 | 0x0052e1c0 | 40 | mixed | Medium | Import call (FF 15 60 E3 59 00) followed by 2 junk bytes (FF FF). Then member function: 56 8B F1 → CALL → flag test → conditional call. Render object context. |
| 0x0053c20a | 0x0053c2a0 | 150 | missed_function | High | Thunk: push 0x0053c220 → call → pop → ret + padding. Then function: reads global 0x008b8ee5 (byte), sets/clears bit flags. Global flag manipulation. |
| 0x0055fa1a | 0x0055fbc0 | 422 | mixed | High | Jump table (5 entries: 0x0055f41a, 0x0055f454, 0x0055f488, 0x0055f4c6, 0x0055f96b) + large index/flag mapping table (mostly 00 00 04 04 04... repeating). Struct init context. |
| 0x0057a127 | 0x0057a160 | 57 | mixed | Medium | Leftover data (04 00) + fragment (epilogue: 5E 32 C0 5B C2 04 00) + function reading global 0x008d46b8 (flag set/clear) + thunk (push 0x0047aa60). Memory copy/constructor context. |
| 0x00585805 | 0x00585860 | 91 | missed_function | Medium | Small fragment (ADC to global + mov/pop/pop/ret, 9B) at start — likely tail of prev function. Then proper function: reads [ecx+0x640], struct field access, IAT call [0x0059e1a0], result check. |
| 0x00589584 | 0x005895a2 | 30 | missed_function | High | FPU function: CMP dword [0x008d3e44], 1 → conditional branch → FPREM/FSTSW/SAHF loop pattern. Classic x87 FPU status checking. 30B. |
| 0x0040bdd3 | 0x0040be70 | 157 | data_table | medium | Ambiguous start byte 0x1c, no clean prologue — likely residual data from Multi-Line Text Draw |
| 0x0040f2d8 | 0x0040f300 | 40 | jump_table_data | high | 8 function pointers pointing into SceneObjectLoader (0x0040f1d7–0x0040f2c4) + 90 padding |
| 0x0041fa9d | 0x0041fb10 | 115 | jump_table_data | high | `8d4900` alignment NOP then 12 function pointers into Constructor Championship Clinch Detection (0x0041f8ec–0x0041f939) |
| 0x0042dbcb | 0x0042dbe0 | 21 | missed_function | high | 5 bytes 90 padding then two thunk stubs (CALL+JMP trampolines) + 90 padding |
| 0x0044c8b0 | 0x0044c8c0 | 16 | missed_function | high | Two thunk stubs (CALL+JMP trampolines) + 90 padding |
| 0x0044cc61 | 0x0044cc94 | 51 | mixed | high | INT3 debug byte + data, `pop ecx; ret` stub, then `c3` + 90s, then thunk stubs, then two global writes (0x007cc9bc=0x1f, 0x007cc9c0=0) |
| 0x0044d3e1 | 0x0044d400 | 31 | mixed | high | Same pattern as 819/820 — header byte, CALL thru, `pop ecx; ret`, 90s + `c3`, thunk stubs, 90s |
| 0x00455866 | 0x00455b30 | 714 | jump_table_data | high | `8bff` (hot-patch NOP) then array of DWORDs pointing into prev function Keyboard Scancode-to-ASCII (0x0045559c–0x004556bc, repeated). 714B of table data. |
| 0x00466900 | 0x00466910 | 16 | missed_function | high | Two small stubs: (1) CALL + xor eax,eax + ret; (2) push 0 + CALL + ret |
| 0x0046a9b5 | 0x0046ad50 | 923 | missed_function | high | Leading `00` byte (padding from prev function), then `mov dword [esi], 0xe959f9e8`, then standard function code with `push esi; push edi; mov esi,ecx` — large function body |
| 0x0047931b | 0x004793ec | 209 | missed_function | high | Embedded ASCII string "MYTH" at start (5 bytes) followed by thiscall prologue. String likely used as debug label or context tag. Function calls vtable method [ecx+0x40], reads +0x164 field, stores to +0x16c. |
| 0x0047f43a | 0x0047fb10 | 1750 | missed_function | high | 6 bytes 90 padding then standard prologue `53 55 56 8b 74 24 10 57` (push ebx,ebp,esi, mov esi,[esp+0x10], push edi). Large function with loop bounds up to 0x1fc. Reads from esi+0x1c19c array at index. |
| 0x0048dfe9 | 0x0048e070 | 135 | missed_function | high | Contains tail of prev function (`pop ebx; add esp,0x1c; ret 0x10`) then full function with thiscall prologue. Has switch statement via `jmp [eax*4+0x0048e050]`, vtable calls at [eax+0x40] and [eax+0x9c]. |
| 0x004945f0 | 0x00494600 | 16 | missed_function | high | Standard thunk stubs (CALL+JMP trampolines) + 90 padding |
| 0x0049fda7 | 0x0049feb0 | 265 | missed_function | high | Indirect call via `call dword [0x0059e254]` then clear function body. Reads byte global 0x007ce254, conditionally branches. Calls `0x007cd25c` object methods. Game logic context (near RaceMonitorOverlay). |
| 0x004a8b47 | 0x004a8b80 | 57 | missed_function | high | Indirect call via `call dword [0x0059e360]`, then `ret 4`. Followed by constructor/init function: zeroes +0x04, sets +0x08=-1, +0x0c=0, +0x10=0x59, +0x14=0, +0x18=0x59, sets vtable pointer at +0x00 to 0x005acc14. |
| 0x004bb775 | 0x004bb800 | 139 | mixed | high | `lea ecx,[ecx]` alignment NOP, then 8 function pointers into FailureCategoryNameLookup (0x004bb73f–0x004bb769), then 4 bytes 90 padding, then function code beginning with `push esi; mov esi,ecx; lea eax,[esi]` |
| 0x004c7c5a | 0x004c7c70 | 22 | missed_function | high | 6 bytes 90 padding then standard thunk stubs + 90 padding |
| 0x004d9c0a | 0x004d9dd0 | 454 | missed_function | high | Leading `00` padding byte, then function with FPU ops, reads DAT_007c54e0 (global), `fld dword [eax+0x3474]` from struct, `fcomp dword [0x0059e440]` against global float constant, stores float at [esi+0x10]. HUD/timing related. |
| 0x004e44f2 | 0x004e45b0 | 190 | missed_function | high | FPU-intensive function: `fstp dword [ecx+0xe0]`, `fcomp st(0)`, then loop/iteration code. Physics integration or constraint handling. Between PhysicsIntegration and LargeConfigWithPhysicsConstants. |
| 0x0051f7be | 0x0051f7ce | 16 | missed_function | high | `mov esi,esi` (NOP), `push ebx; mov ebx,esp; sub esp,8; and esp,-16; add esp,8; jmp +3` — alloca stack-alignment prologue |
| 0x00520ec1 | 0x00520fc6 | 261 | missed_function | high | NOP + two 7-byte alignment NOPs, then MMX vector math: `movq` loads/stores, `punpckhdq` shuffle, `pxor`, `paddw`. Returns via `emms; ret`. Between SSE quaternion composition and SSE 3D vector normalization. |
| 0x0053d1c1 | 0x0053d1f0 | 47 | missed_function | high | Tail of prev func (`pop edi,esi,ebp; xor eax,eax; pop ebx; add esp,0x100; ret 0xc`) then new function: loads param, calls sub, conditionally calls wide-string search function `FUN_005428e0`, `ret 4`. |
| 0x00551db3 | 0x00551dd0 | 29 | jump_table_data | high | NOP then 4 function pointers (0x00551d38–0x00551d4d) into prev Bink Video Frame Render, then 90 padding |
| 0x0057a55b | 0x0057a570 | 21 | missed_function | high | 5 bytes 90 padding then tiny function: `mov eax,[ecx]; mov al,[eax+0x5d]; ret`. Reads byte at vtable offset +0x5d. Returns byte value. |
| 0x0057ca07 | 0x0057cb50 | 329 | mixed | medium | Ambiguous start (`jecxz +0x59` then bytes that decode oddly), then clean function code with `sub esp,0x6c`, string copy loop (`mov cl,[eax]; mov [edx+eax],cl; inc eax; test cl,cl; jnz`), pushes string 0x005c3f6c. |
| 0x00589d97 | 0x00589db0 | 25 | missed_function | medium | 10 bytes INT3 padding (`cc`*10), then tiny function: `lea eax,[edx-1]; pop ebx; ret`, followed by alignment NOPs |
| 0x0059a38d | 0x0059a3a9 | 28 | missed_function | high | thiscall function: `push esi; mov esi,ecx; call -0x524; test byte [esp+8],1; jz +7; push esi; call -0x127d3; pop ecx; mov eax,esi; pop esi; ret 4`. Conditional self-free pattern. |

## Notable Findings

<!-- worker_A.md -->
**GAP 17: 0x00472cf5 — 0x004735b0 (2235 bytes) — missed_function [HIGH]**
Largest missed function in this batch. The hex shows a constructor-like function setting vtable 0x005a2400 and initializing field at +0x31C. Located between UI String Format+Display and UI Frontend Counter Display Update — likely a major UI widget constructor (possibly the frontend display manager or HUD controller). 2235 bytes indicates substantial initialization logic with multiple sub-calls.

**GAP 19: 0x0047fc54 — 0x004857e0 (23436 bytes) — data_table [MEDIUM]**
The 23KB gap at 0x0047fc54 that neither Ghidra nor IDA could resolve. No xrefs into this region. The hex head shows both code-like and data-like byte patterns. This is the largest remaining .text gap in the binary. Likely contains precomputed lookup tables (physics coefficients, spline data, AI path data) possibly interleaved with code fragments. Recommended: manual inspection with IDA Pro using linear sweep + data analysis.

**GAP 30: 0x004d9ed1 — 0x004da820 (2383 bytes) — missed_function [HIGH]**
Second-largest missed function (2383 bytes). References DAT_005ec4cc (MessageBuffer, UI globals table) and pushes string address 0x005d4b2c. Between Timer Display Render and State Block Initializer. Likely the main UI timer/status display update function — renders session timing information to the HUD. Contains string formatting logic and MessageBuffer interaction.

**GAP 31: 0x004e7f37 — 0x004e8010 (217 bytes) — missed_function [HIGH]**
Physics/vehicle struct manipulation function using large offsets (+0x1078, +0x3ab8, +0x3968). Located precisely between Wheel Contact Force & Suspension Update and Tire Brush Model Force Solver. Likely a suspension state copy or wheel hub transform function — bridges the contact force computation with the tire brush model.

**GAP 33: 0x0051f88b — 0x0051f89e (19 bytes) — missed_function [HIGH]**
MSVC stack alignment helper for SIMD math functions. Sets up 16-byte aligned stack frame before calling a math function. Located between Det3x3From4x4 and PlaneFromThreePoints. Indicates aligned vector operations in the math pipeline.

**GAP 34: 0x005261ea — 0x005262c2 (216 bytes) — missed_function [HIGH]**
3DNow!/MMX SIMD function using femms, movq, punpckldq, punpckhdq instructions. Between 3DNow! 4×4 Matrix Multiply and SSE/3DNow! Vector Normalize. Likely a 3DNow! matrix-vector transform or component-wise multiply-add. Part of the 3DNow! math library cluster in this address range.

**GAP 36: 0x0053d729 — 0x0053d750 (39 bytes) — missed_function [HIGH]**
Iterates over 8 elements of a struct array at [ecx+0x1398] with stride -0x44 (68 bytes). The 0x44 stride matches physics/collision struct sizes seen elsewhere. Between DirectX Device/Surface Init and Object Release — likely a physics structure zeroing or initialization function.

**GAP 42: 0x0058b59f — 0x0058b5d4 (53 bytes) — missed_function [HIGH]**
Standard MSVC function calling an import via [0x0059e1b8] and writing result to physics state block at 0x008d3ec0-0x008d3ec4. Part of the physics solver initialization pipeline (0x008d0000-0x008d9000 is the dynamics constraint solver workspace). Likely initializes the solver's vector workspace for the current frame.

**GAP 43: 0x0059a50b — 0x0059a535 (42 bytes) — missed_function [HIGH]**
Physics state block flag management function. Tests and sets flags at DAT_008d46b8 and DAT_008d5a64 — both in the physics state block. Located between Self-Referential Pointer Ring Init and atexit Delegation. Likely a physics system initialization flag checker — enables physics subsystems on first access.

**Jump table cluster (gaps 3, 4, 8, 14, 23, 25, 27, 29, 32, 37, 40):** 11 out of 43 gaps are jump table data (26%). This is expected — Ghidra often misses switch tables embedded between functions. All are high-confidence classifications based on the address-in-range pattern.

**CRT thunk cluster (gaps 2, 9, 10, 11, 12, 22):** 6 gaps are CRT global-register thunks. These follow the exact pattern: padding + push addr + call __Init + pop ecx + ret + padding. Part of MSVC's atexit/global initialization mechanism. Low individual value but important for complete call graph coverage.

**Physics state block references (gaps 41, 42, 43):** Three gaps reference addresses in the 0x008d0000-0x008d9000 physics state block range. These connect the physics dynamics solver to global initialization and APC-based scheduling — important for understanding the solver's activation path.

---

<!-- worker_B.md -->
**HIGH-VALUE MISSED FUNCTIONS (game logic):**
- **GAP 316** (0x0041c53a, 4342 bytes): Large race logic function. Reads DAT_007d0308 (RaceActiveFlag). FPU math with global constants. Between Position-based Message Display and Race Commentary / Best Lap Tracking — likely commentary/best-lap race logic.
- **GAP 370** (0x0045cc23, 301 bytes): Reads DAT_007c56a4 (SessionType — known global). Float store + flag set. Game logic using SessionType for conditional behavior.
- **GAP 393** (0x00475529, 1879 bytes): Reads DAT_007cd850, DAT_007d0e74, DAT_007d0fac (multiple game flags) and vehicle field at +0x17c.
- **GAP 395** (0x004767cf, 1777 bytes): Uses DAT_005ea438 (LoadPath). Full prologue with large stack frame (0x354 bytes). Scene/game initialization.
- **GAP 478** (0x004d9ed1, 2383 bytes): References DAT_005ec4cc (MessageBuffer). String comparison with global constants. UI text/render with message buffer.

**HIGH-VALUE MISSED FUNCTIONS (vehicle physics):**
- **GAP 321** (0x004263e9, 71 bytes): FPU math between Physics Gear/Shift Logic and AI Waypoint Steering. Gear ratio or shift timing calculation.
- **GAP 326** (0x0043138a, 54 bytes): Accesses vehicle struct at large offsets (+0x19a4, +0x1ca8). Thermal/tire field accessor.
- **GAP 365** (0x00456a32, 1326 bytes): Reads physics globals DAT_0059ef8c and DAT_0059ef90. FPU math with conditional paths.
- **GAP 366** (0x0045a833, 173 bytes): Accesses vehicle fields at +0xd8 and +0xe0 (velocity components). Vehicle physics velocity integration.
- **GAP 367** (0x0045b99d, 35 bytes): Loop zeroing 8 entries at +0x31c (damage/contact array). Between Collision Damage Decay Processor and collision utility.
- **GAP 383** (0x00469dcd, 1107 bytes): Vehicle physics/display updating +0x174 and +0x178. FPU add + compare against global DAT_0059e800.
- **GAP 400** (0x0047c054, 780 bytes): Vehicle physics/display updating +0x174. FMUL with DAT_008afe90, FCOMP with DAT_0059e440.
- **GAP 535** (0x0056f657, 418 bytes): Physics state init. Writes to DAT_008d3988, 008d398c, 008d3990 in the 0x8D0000 physics state block.

**HIGH-VALUE MISSED FUNCTIONS (vehicle struct access):**
- **GAP 323** (0x0042cde1, 31 bytes): Reads VehiclePtrArray (0x007c54f0 indexed by eax), stores to DAT_007c54e0. Direct vehicle array lookup.
- **GAP 325** (0x0042ea97, 297 bytes): Array indexing with stride 0x2c0 (imul by 0xb, shl by 6). Between Track Config / Garage and History Buffer.
- **GAP 379** (0x00466d99, 839 bytes): Accesses vehicle at offsets +0x31c, +0x2c03, +0x3003. Switch dispatch on field value.
- **GAP 390** (0x004702fb, 261 bytes): Switch on [esi+0x304] with EMBEDDED jump table at 0x004703e0. Between VTable Set and Engine Temperature Debug Display.
- **GAP 437** (0x0049e670, 320 bytes): Accesses VehiclePtrArray with +0x4894 field comparison (DriverNumber/TeamID). Between SetFourDwords and HUD_TachoTick.

**HIGH-VALUE MISSED FUNCTIONS (network):**
- **GAP 546** (0x0057ef97, 305 bytes): IAT calls + FPU comparison with physics constant. Between VtableDeleteWrapper and NetworkSocketAddressInit.
- **GAP 547** (0x005806f9, 1303 bytes): IAT socket calls (ff 15 a0 e1 59 00). Large packet send/receive function.
- **GAP 549** (0x0058326f, 113 bytes): Linked list traversal with vtable call on nodes.
- **GAP 550** (0x00584f27, 105 bytes): Socket IAT call with timeout comparison (cmp 0x80000000).
- **GAP 551** (0x00585d63, 125 bytes): Multiple socket IAT calls. I/O completion check.
- **GAP 552** (0x005861d9, 103 bytes): Network socket cleanup (closesocket/WSACleanup pattern).

**JUMP TABLES:**
- 60+ gaps classified as jump_table_data — switch tables for collision shape mapping, session phase decode, game state dispatch, pit state machine, keyboard input, championship points, MP3 huffman, DirectX FourCC codes, and many more.
- **GAP 293** (0x004087da, 38 bytes): Jump table for Float-Keyed Field Selector.
- **GAP 298** (0x0040bfc1, 175 bytes): Jump table + case value table for Keyboard Input Action Mapper.
- **GAP 309** (0x00412dc6, 138 bytes): Large jump table for MapCollisionShapeToBoneIndex.
- **GAP 363** (0x00452666, 90 bytes): Switch table for Driver Input Controller.
- **GAP 509** (0x0050bfc9, 88 bytes): Switch table for DirectX FourCC pixel format dispatch.

**LARGE DATA TABLES:**
- **GAP 509** (0x0052d2a5, 1547 bytes): Structured data — likely dxil/dxbc constant buffer data or precompiled shader constants. Between quaternion math and DirectInput8Create. NOT a function.
- **GAP 361** (0x0044d5c1, 6223 bytes): Contains collision init sequence AND D3D device init code packed together. Large combined gap from collision to D3D setup.

**PHYSICS REFERENCE COUNTING:**
- **GAP 563** (0x00598815, 383 bytes) and **GAP 564** (0x00599958, 385 bytes): Nearly identical patterns. Load from DAT_0059d218/DAT_0059d378, push ecx/push ecx/push ebx/push esi, xor esi,esi, call, compare/inc DAT_009ef49c / DAT_00a04e5c. Physics resource reference counting with different global counters.

**FPU MICRO-OP DISPATCH:**
- **GAP 561** (0x005909c7, 1753 bytes): x87 FPU micro-operation dispatch table. Contains d8 f0/d8 f8/de f0/de f8/d8 e0 FPU opcode patterns with jump table at 0x005e3e75. Extended double-precision math emulation or x87 opcode dispatch.

**SSE PROLOGUE PADDING (Gaps 496-504):**
- Gaps at 0x0051ecd9, 0x0051ef48, 0x0051f88b, 0x0051fd1c, 0x00520032, 0x00520346, 0x005207b9, 0x00520972, 0x00520df4 — all contain the same SSE stack alignment prologue (push ebx; mov ebx,esp; sub esp,8; and esp,-0x10; add esp,8; jmp +3). These are NOT padding — they are the 16-byte stack alignment entry stubs for SSE math functions. They appear between every pair of SSE math functions in the 0x51xxxx range. Each one is the prologue for the following function. Missed by Ghidra because they were merged into adjacent functions.

**3DNOW! SIMD FUNCTIONS:**
- **GAP 506** (0x00527393, 485 bytes): Contains 3DNow! packed float instructions (0f 0f and 0f 0e opcodes). Between Cubic Bezier Interpolation and vector normalize.
- **GAP 507** (0x005290f7, 265 bytes): 3DNow! function with global constants at DAT_005d9358+.

**COLLISION INIT WRAPPERS (Gaps 333-360):**
- 28 small gaps (16-54 bytes each) between collision initializer functions. Pattern: `68 XX XX XX XX e8 XX XX XX XX 59 c3` (wrapper/thunk) or `c7 05 ...` (global constant init). Some write module IDs (0x13 through 0x29) to collision globals (DAT_007cd148, 007cd188, 007cd158, etc.). These are collision subsystem atexit registration wrappers and module ID initializers.

**EXCEPTION HANDLERS:**
- **GAP 567** (0x0059ca45, 36 bytes) and **GAP 568** (0x0059cab2, 129 bytes): MSVC SEH exception filter/handler wrappers with 0xCC padding. Near CxxFrameHandlerWrapper. Standard MSVC exception handling thunks.

**TEXTURE 4CC TAGS:**
- Multiple gaps contain "MYTH\0" string literal (4d 59 54 48 00) — Gaps 368, 387, 392, 398, 406. This is a 4CC texture/material tag preceding constructors or UI init functions. "MYTH" may be a texture/asset identifier or internal codename. |

---

<!-- worker_C.md -->
**GAP 93 (0x0042f2ef, 2577 bytes) — HIGH: Vehicle Setup File Parser**
Classic full function prologue (55 8b ec 83 e4 f8). Index calculation: imul by 0x0b, shl by 6. Cmp with 0x0a. Jump table dispatch (ff 24 95). Between Setup Value Formatting and Vehicle Setup File Writer. This is the actual setup parsing function that reads .svm/.hdv file fields and dispatches by type index. Largest gap in this batch.

**GAP 103 (0x00473b6b, 2469 bytes) — HIGH: MYTH AI Personality Dispatcher**
Starts with ASCII "MYTH\0" string marker — likely a debug identifier or vtable-type marker. Accesses struct offset +0x320 (very large offset — deep in vehicle/AI struct). Calls multiple helper functions. Appears to be the main MYTH AI opponent personality trait evaluation function. Between Constructor (VTable + Config Data) and SessionEnter_Alt.

**GAP 104 (0x0047a115, 2379 bytes) — HIGH: State/Value Lookup with Jump Table**
Jump table at 0x0047a16c with switch cases returning globals in 0x007d14xx range (SessionType, RacePhase etc.). Each case entry returns a different global address. Between Parameter value clamping and Empty Stub. Large lookup/dispatch function.

**GAP 99 (0x00458de4, 556 bytes) — MEDIUM: Component Transform Initializer**
Function start is offset by ~11 bytes (first bytes belong to previous function's tail). Accesses struct offsets +0x18 and +0xa0. Between CollisionResponseFilter and Component Transform Initializer — likely the actual init function for component transforms in the physics/collision system.

**GAP 101 (0x00466b17, 585 bytes) — MEDIUM: Vtable Method (no static xrefs)**
Indirect call [0x0059e3b0] at entry — dispatches through a function pointer. Reads global 0x007c7064. No static xrefs (called only through vtable). Complex branching and multiple function calls.

**GAP 107 (0x0048e4a9, 343 bytes) — MEDIUM: Font/UI Resource Loader Extension**
Starts with static OR operation to global 0x005ec68b00. Falls back to LoadPath (0x005ea438) for null resource pointers. Between Font Resource Loader and UI Struct Init. Likely part of font/text resource loading pipeline.

**GAP 128 (0x0058c0f5, 188 bytes) — MEDIUM: Physics State Block Buffer Allocator**
Reads/writes physics state block globals (0x008d5a40, 0x008d4a24). Min/max size logic comparing with 0x14 and 0x200. Calls memory allocation. Between String Shift by Offset and Stream Buffer Lock. Functions as a capacity-managed buffer allocator for the physics engine workspace.

**GAP 129 (0x0059ad07, 42 bytes) — MEDIUM: Physics State One-Time Init Guard**
Double test-and-set pattern on bytes at 0x008d46b8 and 0x008d5a64 in the physics state block. Calls next function (Thunk at 0x0059ad31) on first invocation. Singleton initialization gate for two physics subsystems.

**GAP 117 (0x004ed35d, 35 bytes) — Repair Cost/Lookup Data Table**
Contains both a jump table (4 entries for Repair/Service State Dispatcher) AND a small integer lookup table (values 0,0,0,0,1,2,3,3,3,3,3...). The data table likely maps repair severity to cost multipliers or time values.

**GAP 121 (0x00530739, 263 bytes) — MP3 Audio Data Tables**
Jump table at start (12+ entries for MP3 decoder switch cases), then remaining ~215 bytes likely contain MP3 Huffman tables and sample coefficient arrays. Between MP3 Audio Decoder and Bitstream Texture Decompression.

**GAP 125 (0x0057a98a, 38 bytes) — Physics State Block Thunks**
Two thunks: second one loads 0x008d3bf4 into ecx (this pointer for physics block). This address (0x008d3bf4) is in the physics state block range (0x8d0000-0x8d9000), suggesting a physics-related wrapper function.

---

<!-- worker_D.md -->
**missed_function candidates (high confidence, should be created):**

1. **GAP 130 (0x00405044, 924B)** — Multiple missed functions between SettingsSaveWrapper and short computation. Contains global load from 0x5ea440, output parameter write pattern (return 1 on success, 0 on failure). Likely settings read/dispatch.

2. **GAP 142 (0x0045954b, 741B)** — "MYTH" class marker followed by large FPU function between Struct Init and Float/Double Coordinate Transform. Prologue: sub esp 0x154, push ebx/esi/edi/ebp. Loads double from 0x59f030. Likely physics struct initialization.

3. **GAP 145 (0x0046c03b, 1706B)** — "MYTH" class marker then large function with field dec at +0x174 and conditional, reads global 0x5cc9e8. Field setters context — possibly damage or wear counter decrement logic.

4. **GAP 146 (0x0047455a, 2966B)** — Largest gap. Constructor-like init with vtable 0x5a3b40, extensive field writes. Calls through 0x406658 (session enter?). Massive field initialization block. Session/UI init function.

5. **GAP 155 (0x004b5be0, 112B)** — Mixed: switch dispatch function reading param, storing to [ecx+0x9ac], dispatching via jump table. Jump table (4 entries) at end of gap. Two classifications in one gap.

6. **GAP 163 (0x00526c88, 962B)** — Mixed: 32B jump table for 3DNow Vector Transform, then 930B of 3DNow! math code (femms, movq). Part of the 3DNow accelerated math pipeline between vector transform and quaternion product.

7. **GAP 169 (0x0057ed35, 331B)** — Function with struct fields at +0xb10 and +0xb14, calls through global function pointer [0x59e1a0], compares result to 0x8000. Thread-safe mutex queue context — likely queue push/pop with timeout.

8. **GAP 152 (0x0049ad73, 61B)** — Clean bounds check function: checks two params against four boundary fields at +0x0c, +0x10, +0x04, +0x08. Returns boolean. String/Path processing — region/bounds validation.

9. **GAP 161 (0x004ff0d7, 80B)** — Two x87 comparison functions: fld [ecx+0x20] vs [0x59e440]. Returns 2 for specific comparison results. Value clamp range — probably NaN/infinity protection or edge clamp.

10. **GAP 168 (0x0057a9d0, 64B)** — Global flag toggle at 0x8d46b4 (set-once atomic pattern). Also contains thunk to 0x47aa60 via 0x587b20. Singleton/one-time init guard for physics or audio subsystem.

**Data tables (jump_table_data/vtable) that should NOT be created as functions:**

- **GAP 135 (0x00421200, 224B)** and **GAP 164 (0x00531147, 265B)** — Largest jump tables. Both should remain as data within their preceding functions.
- **GAP 159 (0x004db02c, 68B)** — D3D vtable. 10 entries pointing into preceding D3D Object Factory. Plus trailing struct metadata bytes.
- **GAP 151 (0x0049624d, 51B)** — Crash damage switch table with addresses containing duplicates (0x004961be ×3), suggesting shared case handlers.

**Repeat patterns in engine wear/fuel gaps (160, 161):**
GAP 160 (jump_table, 4 entries between FuelConsumptionAndWear and EngineWear) + GAP 161 (code, x87 comparisons) form a continuous logic block split by a missed function boundary. During function creation, these two gaps should be considered together.

---

<!-- worker_E.md -->
**GAP 190 (0x0047abb3, 2941 bytes):** Largest gap in this batch. First 10 bytes likely data/tail from preceding Return 0 Stub. Contains at minimum one large thiscall function starting at offset +10 with prologue `83 EC 40 53 55 56 8B F1` (sub esp,0x40; push ebx/ebp/esi; mov esi,ecx). This function accesses [esi+0xe0] for velocity data and calls through [esi+0x40] — likely a vehicle physics initialization or update function. May contain multiple interior functions.

**GAP 192 (0x0048ab24, 1280 bytes):** Contains a vtable constructor setting vtable to 0x005abe28, followed by a larger constructor with two sub-calls. The vtable pointer 0x005abe28 is a new reference that should be added to the global docs. Object appears to be a list/pool manager given prev context (Linked-List Pool Destructor).

**GAP 198 (0x004b6059, 215 bytes):** Contains a clean switch-dispatch function reading [ebx+0x9A4] and dispatching through [eax*4+0x004b6118]. The switch values 0-4 set [ebx+0x9B4] = 0x10 and likely other cases. In render context between buffer transfer and sprite cleanup — likely renders a specific sprite/overlay type.

**GAP 199 (0x004bec05, 80 bytes):** AI/collision helper that accumulates force on [edi+0x1a0] from [ebp+0x350] (suspension force?). Structure access via [eax+edi] suggests an indexed array of vehicles/objects. Sentinel check for -1 at [esi+0x32C8] indicates End-of-array boundary. Between AI Overtake and EngineFailureCheck.

**GAP 206 (0x00527393, 485 bytes):** 3DNow! SIMD function with femms (state clear), MMX vector loads (movq/movd), and 3DNow! instructions (0F 0F opcode). In the 3DNow! math cluster between Bezier Interpolation and Normalize functions — likely another geometry/vector operation.

**GAP 210 (0x00564081, 143 bytes):** Physics object name lookup function referencing global DAT_008d46b4 (hash/name table) and calling into 0x005ea438 (LoadPath). Small return helpers at start return -1 (error) or 0 (not found) with stack cleanup — standard MSVC name table query pattern.

**GAP 212 (0x0057ef97, 305 bytes):** FPU math function in network init path, loads value from [ebp+0xe0], multiplies by constant at 0x0059ea08, does FCMP comparison. Between VtableDeleteWrapper and NetworkSocketAddressInit — may be computing network timing or timeout values.

**GAP 214 (0x0058d857, 359 bytes):** Large x87 logarithm function using fyl2x, fldl2e, fld1, faddp. Goes between a simple stream reader and the exp2(f2xm1) function. Part of the x87 math library — provides log2/log10 computation for the game's math utilities.

**New global references found:**
- DAT_008d46b4 — name hash table (GAP 210)
- DAT_008d3bfa — global this pointer (GAP 211)
- Float constant: 0x3f800000 = 1.0f (GAP 180)
- Double constant at 0x0059ea08 — used in FPU multiply (GAP 212)
- Vtable 0x005abe28 — list/pool constructor (GAP 192)
- Vtable 0x0059fb58 — key binding/UI object (GAP 188)
- Struct offset +0xEC: flag bits (toggle bit 15) — render/visibility flag (GAP 208)

---

<!-- worker_F.md -->
**GAP 229: 0x0046200e-0x00462156 (328 bytes, missed_function)**
Real method accessing very large struct offset (+0x1b79c), pushing path strings at 0x005c5bf0/0x005c5bfc. Likely a file-path or configuration method in the network/game setup layer. Between Short Computation (Conditional Delegation) and Network Filter/Sort.

**GAP 230: 0x004672b6-0x004677e0 (1322 bytes, missed_function)**
Large function with 2D array computation: (eax*11+ecx)*64 + 0x7c5770, writing result to [esi+0x320]. The stride-64 2D array at 0x7c5770 (DAT_007c5770) with 11-wide dimension suggests a grid or matrix data structure. Between Object Constructor with Parameter Setup and LinkedListNodeDestructor.

**GAP 232: 0x00475529-0x00475c80 (1879 bytes, missed_function)**
Largest missed function in this batch. "CZ\0" string embedded at start followed by game logic: accesses DAT_007cd850, DAT_007d0e74, DAT_007d0fac, and struct field +0x17c. Between thunk and Conditional Draw. Likely a game state management or rendering dispatch function with conditional branching on global flags.

**GAP 245: 0x004db139-0x004db420 (743 bytes, missed_function)**
Physics constant constructor(s). Sets fields with float constants -1.0f and 20.0f — these are common physics boundary values (COF bounds, speed limits). References global at 0x5acf5c. Between Physics Constant Initializer and Dual-Vtable Destructor.

**GAP 255: 0x0057f158-0x0057fb90 (2616 bytes, missed_function)**
Massive network function between NetworkSocketAddressInit and WinsockInit. Indirect calls via imports at 0x0059e33c and 0x0059e1a0. Accesses +0xaf4/+0xaf8 fields (large offsets typical of socket state struct). Checks value against 0x80. Likely socket connect/read/write with buffer size validation.

**GAP 257: 0x0058db63-0x0058dc29 (198 bytes, missed_function)**
Collection of 4+ tiny FPU helper functions including fldz (load 0.0), fld1 (load 1.0), fstp (stack pop), and a call+jmp loop pattern. These are leaf FPU utilities for stack cleanup and constant loading — likely used by the FP-intensive collision/physics code nearby.

**GAP 258: 0x0059bffd-0x0059c0ac (175 bytes, missed_function)**
CRT memory comparison function (memcmp) following __CxxThrowException_8. Standard implementation with null check, alignment optimization, and byte comparison loop. Part of MSVC runtime support code at the end of the .text section.

---

<!-- worker_G.md -->
**Static init wrappers (Gaps 266-270):** Five identical-pattern wrappers, each `push <struct_addr>; call 0x00587B32; pop ecx; ret`. Pass address of adjacent data structure to a shared initialization function at 0x00587B32. All in collision/spatial init region of code.

**"MYTH" FOURCC functions (Gaps 260, 274, 277):** Three separate functions across the binary (0x408e1b, 0x46cb0b, 0x486efb) that each start with embedded "MYTH\0" string. Likely parsing functions for a MYTH-format resource/file. The consistency suggests a shared utility pattern. Gap 260 is the largest at 1573 bytes — a major function between subsystem dispatch and camera dispatch.

**Game-logic function at 0x4c94fb (Gap 286):** Uses `DAT_007c56a4` (SessionType) and `DAT_008aae70` (RingBufferCounter) with indexed float array access at `DAT_008aae74`. Confirmed game-logic context, not DirectX false positive.

**Physics/vehicle math at 0x47c054 (Gap 276):** Uses FPU to load double constant from `0x008afe90`, multiply with vehicle struct field at `+0x174`, store back. Confirmed vehicle physics context.

**Constructor at 0x4db4d6 (Gap 288):** Sets vtable pointer `0x005ad0dc` then `0x005ad06c` — two vtables, suggesting a class with multiple inheritance or interface pattern.

**Large missed function at 0x467864 (Gap 273, 1500 bytes):** Standard MSVC prologue with `sub esp, 0x338` and `rep stosd` zero-fill of 0x60 dwords (384 bytes). Between LinkedListNodeDestructor and credits.txt Parser.

**Window message handler at 0x4a1553 (Gap 282, 733 bytes):** Writes to global at 0x7ce250, compares parameter to 0x200 (WM_ constant), large switch cascade. Between Window Rect Adjustment and Windows Message Pump.

**Jump tables (Gaps 261, 262, 272, 284, 285, 294, 295):** 7 jump tables identified. Notable: Gap 284 (8 entries, lap/speed comparison switch), Gap 285 (7 entries, pitstop phase advance), Gap 294 (4 entries, audio volume switch).

**SSE prologue split (Gap 291, 28 bytes):** Ghidra mis-split the 3x4 Matrix Transform function — its SSE-alignment prologue (stack aligned to 16 bytes via `and esp, -16`) was separated from the function body. The `jmp +3` at the end bridges into the real function at 0x52004e.

**Import thunks at 0x50c28c (Gap 290):** Two delay-load import wrappers pushing constant 1 and jumping through IAT entries at 0x5d77ec and 0x5d77dc. Likely wrapping DirectX or OS calls.

**Physics state block reference at 0x57ab43 (Gap 297):** Loads pointer from `[0x008d3bfc]` (physics state block region 0x8D0000+). Confirms connection to dynamics solver workspace.

---

<!-- worker_H.md -->
**GAP 303: 0x004096aa-0x00409890 (486 bytes, jump_table_data)**
Camera mode dispatch table. 486 bytes of 4-byte pointers — ~121 jump targets for camera state machine. Between View/Camera Mode Dispatch and Conditional Camera Pipeline Setup. Largest jump table in this batch.

**GAP 307: 0x0042382b-0x00423890 (101 bytes, missed_function)**
String parsing utility with MYTH debug marker. Sits between String/Hash Token Parsing (0x004236f0) and Binary Search in String Table (0x00423a00). Likely a string comparison or hash computation helper used by both neighbors.

**GAP 316: 0x0046808d-0x004681b0 (291 bytes, missed_function)**
Constructor for an HTML/output-related object. Sets vtable to 0x005af668, initializes +0x128 field to -1. Between HTML Output Section Processor and VehicleSceneLoadAndPositionTires. Possibly a document node or section object.

**GAP 319: 0x0047c6b6-0x0047c770 (186 bytes, missed_function)**
Constructor with data prefix. Contains internal calls and initialization. Between Object Init with VTable and UI FPS/Performance Setting Display. Likely UI widget constructor.

**GAP 331: 0x004db5c6-0x004db6f0 (298 bytes, missed_function) **
SessionType dispatch function — reads DAT_007c56a4 (SessionType global), switches on value using jump table at 0x004db638. Between conditional dispatch based on DAT_007d0474 and Position/Order Name Display. Important game logic dispatch for session state handling.

**GAP 335: 0x005290f7-0x00529200 (265 bytes, missed_function)**
MMX/3DNow! SIMD math function. Loads 4 constants from data section (0x5d9358-0x5d936c), performs vector operations using MMX registers (pandn, punpck). Between Square Root Approximation and Empty Stub. Part of 3DNow! math library.

**GAP 341: 0x005806f9-0x00580c10 (1303 bytes, data_table)**
Largest gap in this batch (1.3KB). Between Network Packet Queue Reader (0x005805c0) and Network Packet Send (0x00580c10). Byte pattern does not decode to valid x86 code. Likely a packet template table, protocol constant array, or lookup table used by the network subsystem.

**GAP 343: 0x0059067e-0x00590703 (133 bytes, missed_function)**
FPU control/init function after __cintrindisp2 CRT internal. Checks FPU mode flag at 0x005e9ad0. Part of MSVC floating-point environment initialization.

---

<!-- worker_I.md -->
GAP 348 (0x0041143a, 310 bytes): Missed method comparing DAT_008ab6e4 (ScoringGate) against 2. Game logic context — scoring/race logic interaction. Check if ScoringGate is related to session state.

GAP 350 (0x00423e75, 523 bytes): Large missed constructor/init function. Uses FPU (`fsqrt`), accesses [esi+0x4034], stores 0xFFFFFFFF sentinel. Between short computation and AI Difficulty Scalar — likely an AI or difficulty-related object constructor.

GAP 357 (0x0045bb81, 95 bytes): Two functions. First iterates with step 0x5c, 8 iterations. Between ID to Color Mask Mapper and Double Delegate Call — likely a palette/color table initialization or iteration.

GAP 360 (0x0046cecf, 513 bytes): **References known game globals**: DAT_005ec4cc (MessageBuffer), DAT_005c30bc, DAT_005ec4c0. String copy between these buffers. Game-logic relevance — UI message or file path manipulation. Between CopyProfileIconBMP and SessionCheckEndCondition.

GAP 362 (0x0047c7ba, 166 bytes): UI element constructor. Sets vtable to 0x005a69b0, stores 1.0f. Contains both UI init and display logic between UI FPS/Performance Setting Display and UILoadingPercentDisplay.

GAP 364 (0x0048b94c, 116 bytes): Text/string handler at UI layer. Accesses field at [edx+0x2f0] and [edx+0x1e7] — likely UI text buffer offsets. String length computation + field copy. Between UI Widget Visibility Toggle and Text Input Render.

GAP 374 (0x004db9f2, 366 bytes): Method accessing DAT_007ce234 (known global). Between Number Format utility and DrawDebugTextOverlay — likely part of the debug text rendering pipeline.

GAP 377 (0x005201fb, 19 bytes): SSE stack alignment thunk. The pattern `53 8b dc 83 ec 08 83 e4 f0` ensures 16-byte stack alignment before jumping into the next SSE function. Important for SIMD math pipeline.

GAP 378 (0x005292e9, 759 bytes): **3DNow! function**. Loads from DAT_005d940c using `movd mm1` (MMX). Large block of 3DNow! packed float math. Between Empty Stub and Packed Floating-Point Math — part of the 3DNow! math library used in the physics/renderer pipeline.

GAP 382 (0x005653ab, 69 bytes): **Mixed jump table + data table**. After 5 jump target addresses, a byte array with repeating 0x00/0x04 values — likely a material coefficient or surface property lookup table.

GAP 384 (0x0058122c, 980 bytes): **Network function**. Large (980 bytes), references DAT_0059e1a0 (indirect call), accesses network buffer fields at [ecx+0x640] and [ecx+0x624]. Between Network File Transfer Accept Handler and Network Buffer Search. Likely network data send/receive processing.

GAP 386 (0x0059083b, 51 bytes): **Has standard `55 8b ec` prologue**! Rare among these gaps — MSVC frame pointer. FPU control word manipulation with `fstcw`. FPU mode initialization between two runtime/CRT functions.

GAP 387 (0x0059ca73, 24 bytes): **Exception handler glue**. 12× INT3 padding (MSVC exception handling pattern), then lea/jmp pair for exception registration. Between C++ Exception Handler Wrapper and CxxFrameHandlerWrapper in the CRT exception handling chain.

GAPS 351-356 (thunks in 0x0043-0x0044 range): Chain of 6 nearly identical thunks (push self-address, call, pop, ret) all between collision/physics init functions and mouse axis init functions. These are likely synthetic thunks generated by MSVC for dynamic initializers or COM-style registration. All ~23-26 bytes.

---

<!-- worker_J.md -->
**GAP 389 (0x004099de, +2 code offset):** Function setting globals DAT_008afe64 and DAT_008afe88, calls FUN_00411e90. Likely camera pipeline setup function — next func is CameraModeViewportUpdate. Should be promoted to `## FUN_`.

**GAP 391 (0x004119a3):** Clean function reading DAT_005ea5d0, conditional call to FUN_00587bc0. Font/string render helper. Should be promoted.

**GAP 393 (0x004263e9):** x87 FPU code comparing field at +0x37cc against constant 0x0059e8cc. Gear ratio or shift point comparison. Adjacent to Physics Gear/Shift Logic and AI Waypoint Steering. Should be promoted.

**GAP 394 (0x0043209e):** Constructor/allocator — allocates 0x40 bytes, calls FUN_00437b90, stores pointer. ThisCALL method. Should be promoted.

**GAP 399 (0x0044d5c1, 6223 bytes):** Large mixed region containing CRT atexit thunks and global initialization code. Writes values 0x13 to DAT_007ccc80 and 0x0 to DAT_007ccc84. Likely collision system CRT init. Not a single function — multiple init stubs. Consider marking as data_table region in Ghidra.

**GAP 403 (0x0046d1dc, 2900 bytes):** Large function with mode check (cmp dword ptr [eax+0xb144], 2), string push "\\help\\*.loc", and session/race logic. Adjacent to SessionCheckEndCondition. Should be promoted — likely session state evaluation function.

**GAP 404 (0x00476359, 663 bytes):** Function with 0x200-byte stack frame. Reads field at +0xf0, loops. Frontend/loading display handler. Should be promoted.

**GAP 405 (0x0047c8fc, 4596 bytes):** Large function zeroing DAT_007cffcc then initializing render state. Pushes 1.0f, 0 as args. ThisCALL render init. Should be promoted.

**GAP 407 (0x0048bbd6, 1178 bytes):** Text input render function checking byte fields at +0xe000, +0xe100 for visibility, calls FUN_004a7ab0. Should be promoted.

**GAP 412 (0x004b20f7):** Starts with import thunk (call [0x0059e04c]), then thisCALL method. Two functions in one gap.

**GAP 413 (0x004b7c60):** Jump table for Pit Timing Update function. Addresses point into prev func (0x004b7be6, 0x004b7bf3×3, 0x004b7c07). Essential for understanding Pit Timing Update's control flow.

**GAP 415 (0x004cdb55):** Jump table with index mapping (00 00 00 00 01 02 02 03 06 06 06 04 05). Steward scoring switch table. Index compaction suggests 7 unique cases mapped to 6 targets.

**GAP 421 (0x0052981b, 733 bytes):** MMX/SSE SIMD function reading globals DAT_005d935c, DAT_005d9414, DAT_005d9410. Bit manipulation with shifts and XOR. Likely polynomial approximation (adjacent to MMX Polynomial Approximation). Should be promoted.

**GAP 425 (0x005679a5, 18 bytes):** Tiny linked-list search loop — follows +4 next pointers. String-keyed list search helper. Should be promoted together with next func.

**GAP 427 (0x00581746):** Thread pool job cleanup. Calls imports at [0x0059e1a4] and [0x0059e1a8], checks byte field +0xc, clears pointer at +0x4 on success. Should be promoted.

**GAP 429 (0x005909c7, 1753 bytes):** 64-case switch dispatcher using jmp table at 0x005e753e. Each case is x87 FPU division variant (fdiv/fdivr). Extended precision division wrapper. Should be promoted — important for understanding math library FPU dispatch.

**GAP 420 (0x00520346, 24 bytes):** MSVC stack-alignment thunk (`and esp, -16` pattern). Precedes VectorNormalizeThreshold. Compiler-generated — mark as padding or data_table.

---

<!-- worker_K.md -->
**GAP 445 (0x00468634, 729 bytes) + GAP 450 (0x0048c0db, 2245 bytes) — Major missed file-loading functions**
Both are large functions referencing 0x005ea438 (LoadPath). GAP 450 is the single largest gap at 2,245 bytes. These likely load configuration files or game data. GAP 450 references 0x007ce498 (AutoLoadConfigFile) confirming config loading purpose.

**GAP 446 (0x0046e229, 919 bytes) — Second-largest, texture/object loading**
Between Deferred Texture/Object Loader and Init with Stack Buffer. Uses ENTER instruction (unusual), accesses struct offsets +0x40/+0x178, virtual call through [eax+0x1c]. Likely part of texture/resource loading pipeline.

**GAP 467 (0x0055678d, 104 bytes) — Fixed-point math library**
Two distinct fixed-point 16.16 math functions:
1. `result = (a * b + 0x8000) >> 16` — classic fixed-point multiply with rounding
2. Absolute value + sign tracking for fixed-point numbers
Pure math utility — no game logic.

**GAP 470 (0x00581939, 135 bytes) — Linked-list search**
Clean linked-list search implementation. Node format: [value at +0x00, next at +0x04]. Returns when found or list exhausted. Called from list destruction context (between List Destruction with Handle Close and Linked List Destroy with Vtable Destructor Call).

**GAP 472 (0x00591629, 18 bytes) — x87 FPU trig wrappers**
Four tiny stubs in 18 bytes: two relative-call wrappers + `fpatan` + `fptan`. Direct x87 FPU instruction wrappers for partial arctangent and tangent. Between Double-Precision Float Classification and errno handler.

**GAP 468 (0x00568782, 110 bytes) — Character classification table**
Bit table of 0s and 1s adjacent to ASCII Char Code Validation function. Character type lookup (printable/whitespace/special classification). Data, not code.

**GAP 432–436, 444, 456, 459, 464 — Jump tables (9 total)**
Cluster of switch-case jump tables for: camera modes, AI behavior states, race event messages, session commentary, AI ability, buffer size lookup, hot lap file writer, global switch lookup, field setter. These are not functions — they are data tables referenced by switch instructions in respective functions.

**GAP 438–441 (4 thunks in a row, 0x0044c7-0x0044d2) — Collision subsystem thunks**
Identical pattern (NOP padding → push addr → call → pop ecx → ret → NOP padding) across 4 consecutive gaps in the collision subsystem init area. Each wraps a different target address for collision grid/material initialization.

**GAP 447 (0x004765fd, 99 bytes) — Dual-vtable destructor**
Textbook MSVC destructor: writes two different vtable pointers during destruction, checks and frees child pointers at +0x3c and +0x30. Indicates a class with two-phase destruction or multiple sub-objects.

**GAP 452 (0x00499082, 190 bytes) — Two-function gap**
Contains two distinct functions: (1) 11-byte virtual dispatch stub, (2) bounds-check function comparing parameters against struct bounds at offsets +0x04/+0x08/+0x0c/+0x10. Between Guarded Sub-Rectangle Render Dispatch and a vtable init.

---

<!-- worker_L.md -->
**HIGH: GAP 490 — Renderer/Large Function (1777 bytes)**
0x004767cf: Large missed function with 852-byte stack frame (sub esp,0x354). Saves ebx,ebp,esi,edi. Reads from 0x005ea438 (SeasonDir). Between Renderer State Reset and Season Scene Search by Name. Likely scene setup or render-state initialization. May contain multiple fused functions — Ghidra should attempt function-scan with forced split.

**HIGH: GAP 475 — Dead Code Region (1727 bytes)**
0x00409f51: No xrefs but starts with code-like bytes (global reads at 0x008a1408, 0x008afe88; jmp backward). Largest gap with no xrefs. Possibly dead code from linker or orphaned functions. Recommend re-evaluation with IDA to confirm no reachable entry points.

**HIGH: GAP 507 — DirectInput Data Table (3115 bytes)**
0x0052c5e9: Large structured data table (~259 × 12-byte entries) containing interface pointers (0x005ad410), flags (0x8000000c, 0x8000010c, etc.), and object IDs. Between Quaternion Multiply (physics) and DirectInput8Create Import Stub. DirectInput device enumeration/creation configuration.

**HIGH: GAP 516 — Exception Handler Table (2924 bytes)**
0x0059cb3d: Large exception handler dispatch table. Pattern: load [ebp-0x14] or [ebp-0x10] or [ebp-0xec], jmp to handler address. ~30+ entries with int3 padding between groups. Located near binary end of .text before CRT wrappers.

**HIGH: GAP 511 — Physics Workspace Init (418 bytes)**
0x0056f657: Initializes 3 physics state block globals (0x008d3988, 0x008d398c, 0x008d3990) with sub-block addresses (0x8cfbf0, 0x8cfcb8, 0x8cfd80). Sets vtable at [eax] to 0x005b89c0. Part of constraint solver setup in dynamics code.

**MEDIUM: GAP 510 — FPU Detection (33 bytes)**
0x0055685a: Writes 0x5a5a to FPU control word, reads back, checks integrity. CPU feature detection function preceding RDTSC Timestamp Read. Classic FPU presence test.

**MEDIUM: GAP 515 — Memory Allocator (129 bytes)**
0x0059573c: Heap/arena allocator. Reads global arrays at 0x008d4a24 (slot base) and 0x008d5a40 (threshold). Checks slot validity with flag test at +0xc for 0x83 mask. Between CRT __amsg_exit and Memory Allocator Init.

**MEDIUM: GAP 506 — SSE Stack Alignment Thunk (22 bytes)**
0x005204f8: Aligns ESP to 16-byte boundary for SSE operations then jumps to target. Between Velocity/Friction Clamp (physics) and SSEMatrix4x4Multiply. Integration point for SSE-optimized math.

**MEDIUM: GAP 488 — MYTH Class Method (165 bytes)**
0x00468b4b: Second occurrence of "MYTH\0" class-name string followed by method with prologue (push ebp, push edi). Reads field at +0x184 and loads SeasonDir global (0x005ea438). Between Career Mode Driver Stats Reset and Grand Prix Results HTML Writer.

**MEDIUM: GAP 487 — Constructor/Factory (384 bytes)**
0x00464fd0: Allocates 0xe5d0 bytes via call, checks result, conditionally calls FUN_00464c... (threshold-related), returns this or null. Full 384-byte body between Threshold-to-Rank Classifier and Single Call Wrapper.

**LOW: Jump tables (multiple)**
Gaps 477, 478, 491, 496, 499, 503: All clear jump tables for adjacent functions (Sound Event Dispatcher, Pit Selection State Machine, TelemetryDisplaySwitch, Free Callback Registration, Unidentified Float Switch Logic, Alignment/Position Switch). Each switch table contains 4-9 entries with addresses in the preceding function's range.

**LOW: Padding + dead thunks (multiple)**
Gaps 476, 486, 498: Standard nop-padding + dead thunk pattern (call+jmp+nops). No recoverable code.
Gaps 482, 483, 484: Thunks + global initializers (setting adjacent dwords at 0x007ccfdc/d0cfce0, 0x007ccbf4/f8).

**LOW: Small methods (multiple)**
Gaps 493, 494, 502, 505, 508: Small (<55 byte) methods with conditional logic, vtable dispatch, or field access. All recoverable as functions.

---

<!-- worker_M.md -->
**GAP 554 (0x00574010–0x00575863, 6227 bytes) — MAJOR MISSED FUNCTION**
- **Type:** Large switch-dispatch function with 39+ cases
- **Context:** Dynamics constraint solver chain. Prev: Block LDL^T Sparse Constraint Factorization (0x0056fa96, 17KB). Next: Enum value check (0x00575875).
- **Structure:** stdcall with single int parameter, compared against 0x27 (39), jump table at 0x005751f1
- **Key operations:** Heavy x87 FPU, stores to known physics globals DAT_008cfbf0, DAT_008cfcb8, DAT_008cfd80
- **Importance:** Likely the constraint type handler that dispatches to 39 different constraint setup functions. Critical for dynamics solver completeness.
- **Recommendation:** Create as function in Ghidra immediately. This is the second-largest gap in the binary after the 0x0047fc54 data region.

**GAP 532 (0x0046e842–0x0046ec10, 974 bytes) — LARGE MISSED FUNCTION**
- **Type:** Full game-logic function with stack frame (0x28 bytes)
- **Context:** Between polling loop and object name matching
- **Structure:** thiscall (mov ebp, ecx), saves all registers, multiple calls
- **Importance:** Large function likely managing object state.

**GAP 535 (0x00487755–0x00487ed0, 1915 bytes) — LARGE SWITCH FUNCTION**
- **Type:** Switch function with jump table (max 4 cases)
- **Context:** Between Range Check and struct initialization
- **Structure:** Subtracts 2, range-check against 4, jump table at 0x00487810, string/byte processing
- **Importance:** 1915 bytes, string processing with switch dispatch.

**GAP 531 (0x00469187–0x004692a0, 281 bytes) — MULTIPLE FUNCTION FRAGMENTS**
- Calls imports at DAT_0059e18c and DAT_0059e05c
- 2+ thiscall function fragments separated by returns
- Between Player Profile Scanner and Short Computation.

**GAP 548 (0x00517569–0x005176ec, 387 bytes) — MATH FUNCTION**
- **Type:** 3-param stdcall with heavy x87 FPU, likely matrix multiply or 4x4 transformation
- **Context:** Between Mat2x2Mul and Vector Normalize (Fast rsqrt)
- **Importance:** Missing matrix math utility in the 0x0051xxxx series.

**GAP 523 (0x00433ead–0x00433ed0, 35 bytes) — SMALL THISCALL METHOD**
- Context: Between Physics Object Destructor and Validate Vehicle Configuration File
- Calls, string reference, class ptr access. Physics object method.

**GAP 534 (0x0047e390–0x0047e3f4, 100 bytes) — SMALL THISCALL WITH VTABLE CALL**
- Calls vtable+0x1c with arg 0x15
- Reads DAT_007cd8c0 (interface/vtable pointer)
- Between ByteAccumAdd and Race Laps String Load.

**GAP 545 (0x004d89ca–0x004d8a30, 102 bytes) — STRUCT INIT FUNCTION**
- Initializes struct fields at +0xdc, +0xe0 (byte=1), +0xe4 (float=1.0f)
- Loads constant from DAT_005acf34
- Between iterator and Audio/State dispatch.

**GAP 542 (0x004b97a9–0x004b97d0, 39 bytes) — TWO SMALL FUNCTIONS**
- First: null check + 2 calls
- Second: stores and returns (setter)
- Between arithmetic function and thunk.

**GAP 555 (0x0057af75–0x0057afa0, 43 bytes) — THISCALL WITH VTABLE SETUP**
- Sets vtable to DAT_005b8a40
- Checks byte param bit 0, conditionally calls sub-function
- Between Linked List Destruction and Network Packet Constructor.

**Data tables found (minor):**
- GAP 550 (0x0052d225, 111B): Physics lookup table with 16-byte entries — coefficients for wheel contact/quaternion context.

---

<!-- worker_N.md -->
**GAP 574: 0x0046ec78 — 0x0046fcf9 (4225 bytes) — missed_function HIGH**
Largest gap in this batch. Full function with prologue (81 ec 10 02 00 00 = sub esp, 0x210), register saves, and string comparison loop (byte-by-byte compare with 8a 10 8a 1e 8a ca 3a d3). Functions in this range (0x0046ec10 Object Name Matching + Activation, 0x0046fcf9 ObjectCreate_WithVtable) suggest this is an object management function — likely name-based object lookup, factory dispatch, or scene graph parsing. The 4KB size indicates significant logic. Candidate for Ghidra function creation.

**GAP 575: 0x004774bb — 0x00477640 (389 bytes) — missed_function HIGH**
MYTH module marker + full thiscall prologue (83 ec 08 53 55 56 57 8b e9). Stack frame setup suggests medium complexity method. Context: UI Element List Destructor → Season/Scene Name Accessor. Likely UI element initialization or setup function in the MYTH UI framework module.

**GAP 576: 0x0047e4a6 — 0x0047e940 (1178 bytes) — missed_function HIGH**
Multiple function fragments. Fragment 2 has sub esp, 0x104 stack frame and checks byte at 0x005ea438 (LoadPath / directory pointer global). File path processing function related to circuit info/page rendering. Context: Circuit Info Page → rendering callback.

**GAP 592: 0x0052d2a5 — 0x0052d8b0 (1547 bytes) — data_table HIGH**
Structured 16-byte record table with format: [length=0x0c] [4-byte ID] [flags 0x00800000] [timestamp/fingerprint] [1-byte code]. Sequential IDs cb, cc, cd, ce... ~96 entries total. Located between Quaternion Multiply and DirectInput8Create import stub — likely a D3D resource format descriptor table or graphics caps table. Not executable code.

**GAP 596: 0x00579c47 — 0x00579ccf (136 bytes) — jump_table_data HIGH**
Physics constraint/joint dispatch table with ~25 entries referencing functions in 0x00578f8a–0x00579c3b range. Located between InitPhysicsTransformIdentity and Physics State Zero-Init. Contains addresses of per-constraint-type initialization functions. Key to understanding the physics constraint solver architecture.

**GAP 598: 0x0058326f — 0x005832e0 (113 bytes) — missed_function HIGH**
Thiscall linked-list search function. Checks vtable pointer at [ecx], walks list comparing byte field at [esi+0x08]. Standard list traversal pattern (74 3d je, 8b 76 04 = mov esi,[esi+4]). Context: Linked List Node Alloc & Prepend → Unknown. Candidate for Ghidra function creation.

**GAP 597: 0x0057b17a — 0x0057b230 (182 bytes) — missed_function MEDIUM**
CC padding (debug int3 fill) suggests debug build artifact or deliberate padding. Contains import call via 0x00598bff with conditional branch, struct field access, loop. Context: Linked-List Buffer Manager → IntSetInsert. Buffer management function with error handling.

**GAP 600: 0x00597303 — 0x00597321 (30 bytes) — missed_function HIGH**
Two import thunks storing/loading from global 0x008d41e4. First calls import at 0x0059e084 with arg 0x005972bd, stores result. Second retrieves from global and calls same import. Context: Exception/Error Filter → IsBadReadPtr Wrapper. Wraps import function (likely IsBadReadPtr or similar) with result caching.

---

<!-- worker_O.md -->
**GAP 605 — 0x0041c53a (4342 bytes) — MISSED FUNCTION — HIGH**
Largest gap in batch. Valid function: calls 0x00406658, reads RaceActiveFlag (DAT_007d0308), allocates stack (sub esp,0x2c), push ebx/esi, conditional branch. Also reads DAT_007cf3c8 via x87. Game-state/race dispatch. Almost certainly a substantial game-logic function Ghidra failed to recognize.

**GAP 616 — 0x0046fd4e (1090 bytes) — MISSED FUNCTION — HIGH**
Member function checking SessionType (DAT_007c56a4) == 6 (qualifying). Reads struct field at +0xe4. Game logic function with session-dependent paths. Large enough to be significant.

**GAP 618 — 0x0047e95a (1282 bytes) — MISSED FUNCTION — HIGH**
C++ constructor/initializer. Sets vtable pointer to 0x005a6c78 (unknown vtable). Zero-inits fields at +0xec, sets +0xf0 to -1. Iterates on [esi+0x44] chain. Major constructor for a game object.

**GAP 635 — 0x0053be91 (625 bytes) — MISSED FUNCTION — HIGH**
SSE/x87 mixed math function in 3D math context (prev: 3D Squared Distance). Uses movaps, fld, import call. Likely SSE-accelerated 3D vector/matrix operation.

**GAP 619 — 0x00487f3b (581 bytes) — MISSED FUNCTION — HIGH**
Member function with vtable dispatch [edx+0x2c], conditional field compare/set at offsets +0x80 and +0x84. UI component method.

**GAP 639 — 0x0057b290 (80 bytes) — MISSED FUNCTION — HIGH**
Set/lookup data structure member function in physics/constraint context. Linked-list traversal, byte flag check, field store. Adjacent to IntSetInsert.

**GAP 632 — 0x0051ecd9 (21 bytes) — MISSED FUNCTION — HIGH**
CRT stack-alignment thunk (53 8b dc 83 ec 08 83 e4 f0 pattern) between SSE math functions. Part of SSE-aligned call infrastructure.

**GAP 633 — 0x005208eb (19 bytes) — MISSED FUNCTION — HIGH**
Same CRT stack-alignment thunk pattern as GAP 632. Between SSE matrix functions.

**GAPS 608-611 — 0x0044c7c9/0x0044cb89/0x0044cf49/0x0044d309 (23 bytes each) — PADDING**
Identical NOP + push/call/pop/ret pattern between collision init functions. Stripped macro wrappers or alignment artifacts. Not individual functions.

**GAP 638 — 0x00579f6b (30 bytes) — JUMP TABLE DATA — HIGH**
Physics solver dispatch: two entries setting ecx to 0x008d3984/0x008d3980 then jumping to solver functions at 0x0056f660/0x005756f9. Directly in physics state block context.

---

<!-- worker_P.md -->
**Gap 657 (0x00469dcd, 1107 bytes) — Largest gap in set**
Missed_function with FPU arithmetic, struct field access at +0x174/+0x178, and conditional branching. Between Player Stats Display Cleanup and Object Constructor. Likely a significant game logic function — possibly a physics or display computation in the UI/stats context.

**Gap 660 (0x0047ee94, 168 bytes) — Switch dispatcher**
Reads global DAT_007cf134 and dispatches through jump table at 0x0047efd0. Pushes string constants. Between InitFromDataBlock and PercentageDisplayFormatter. Likely a config/init routing function.

**Gap 658 (0x00470230, 192 bytes) — Constructor pair**
Two constructors: first sets vtable to 0x005a0250 with multiple push-0/push-1 arguments; second has boolean parameter for delete-on-destroy. Between Monitor Timing Display and Short Computation.

**Gap 669 (0x004c6917, 73 bytes) — TeamID initializer**
Writes -1 to offset +0x4894 (TeamID field from struct table). Confirms this offset as TeamID storage. Between MergeSortLinkedList and TeamIDSetter — may be an unset/clear function called during initialization.

**Gap 677 (0x0053c110, 48 bytes) — 3D vector dot product**
Clean implementation of dot product: loads 3 floats from two pointers at offsets 0,4,8, multiplies corresponding pairs with fld/fmul, sums with faddp. Returns 8-byte stack cleanup. Moddability: `hardcoded`.

**Gap 672 (0x004dfbaa, 246 bytes) — Constructor/initializer**
Calls FUN_00406658, sets +0x90=0, +0x94=-1, loops setting up structure. Between 26-Byte Zero-Init and Dual Array Destructor Loop. Likely part of a UI or game object lifecycle.

**Gap 684 (0x00598815, 383 bytes) — Substantial function**
Loads vtable pointer 0x0059d218, calls multiple subroutines, reads global 0x005e9ef4 with conditional increment. Uses stack frame with local variables. Between PhysicsThunk and RefCountDecrement. May be a physics lifecycle callback.

**Jump tables identified for:**
- Gap 646: Season-Specific Team ID Lookup (12+ entries)
- Gap 654: Driver Input Controller (multiple entries)
- Gap 665: HUD_TachoRenderDispatch (12+ entries)
- Gap 678: 2D/3D Triangle Point Test (6 entries)
- Gap 679: Function at 0x55c450 (6 entries)
- Gap 682: Large function at 0x00584130 (12+ entries)

**Thunk chain patterns (gaps 648, 649, 650, 651, 652, 653, 667, 673, 680):**
Multiple instances of the linker-generated pattern: `e8 0b 00 00 00` (call next instruction) followed by `e9 16 00 00 00` (jump forward). These are incremental linking thunks or import trampolines. No game logic value.

---

<!-- worker_Q.md -->
**GAP 701 (0x00477f9e–0x00478e80, 3810 bytes):**
Largest gap in this batch. Clear thiscall prologue with vtable dispatch (`ff501c`), null checks, and function calls. At 3.8KB, likely contains multiple sub-functions that Ghidra conflated into one. The `6a03` (push 3) and vtable call at +0x1c suggest a standardized interface call. Between ProfileIconBmpLoader and a delegate to FUN_00499b80. Recommend manual review for function boundaries.

**GAP 697 (0x0045cc23–0x0045cd50, 301 bytes):**
References `DAT_007c56a4` (SessionType global). Contains game-logic branch. The `ff ff` prefix bytes may indicate a data table header followed by a loop (cmp esi,0x68, jl). Accesses struct fields and calls functions. Likely a significant game logic function in the steward/session system.

**GAP 711 (0x004c7773–0x004c77d0, 93 bytes):**
Between Vehicle Physics Time Step and TireTemperatureSimStep. Reads bit-shifted flags from `[edi+0x38]` (bit 25), stores to `[ebx+0x1067]`, calls physics functions, stores 16-bit result to `[ebx+0x48b0]`. Accesses `[edi+0x3b]`. These offsets (+0x38, +0x3b, +0x48b0, +0x1067) are in vehicle struct range. Likely tire temperature or wheel state extraction function.

**GAP 702 (0x0047ef75–0x0047eff0, 123 bytes):**
Jump table for Percentage Display Formatter. 12+ entries with even spacing (~0x2E bytes) between case handlers — suggests a switch on a range-based value (e.g., percentage thresholds 0–100 with cases every ~8.3%).

**GAP 710 (0x004b9e02–0x004b9e30, 46 bytes):**
Jump table for MenuActionDispatch with companion byte table `01 02 03 04 05` — likely encoding action size or index-to-resource mapping for menu actions.

**GAP 716/717 (0x0051ee66 & 0x00520a64, 24/26 bytes):**
Identical stack alignment prologue pattern: `push ebx; mov ebx,esp; sub esp,8; and esp,-16; add esp,8; jmp +3`. These are prologues split from their function bodies by Ghidra. Both in physics math contexts (Vector Normalize, PlaneFromEdgesNormalize, QuaternionToRotationMatrix). The `and esp,-16` is SSE alignment requirement — suggests SSE-optimized math functions.

**GAP 705 (0x00491e91–0x00491ee0, 79 bytes):**
Contains memset pattern (`rep stosd`) zeroing 0x60 dwords (384 bytes) at global 0x007cdb70. Buffer initialization for UI/text display data.

**GAP 725 (0x00587b50–0x00587b7f, 47 bytes):**
Allocates 128 bytes via function call, stores to `[0x008d5a54]` and `[0x008d5a50]`. These globals at 0x008d5axx are in the session state region. Timer or session data allocation function.

---

<!-- worker_R.md -->
**GAP 727 (0x004076d4, 1292 bytes)** — Largest gap in this batch. Starts with jump table data but contains 53 56 57 8B F9 prologue at offset ~6. Likely a real function preceded by a jump table. Between Linked List Node Insert and Linked List Node Removal by Key — potential linked list utility function.

**GAP 739 (0x0045d2cd, 451 bytes)** — Real function with switch dispatch on parameter values 1, 2, 3. References global at 0x007cd2a0. Between Network/Replay Buffer Init and Global Flag-Based State Setter. Likely network/replay state management.

**GAP 742 (0x00470632, 2286 bytes)** — Largest gap in entire analysis. Context between Session Message/UI Command Handler and Race/Session Mode Data Loader. Starts with data (00 00, address write C7 06 08 03 5A 00) followed by function code comparing [ecx+0x304] vs 0x1b5. Likely session/race state transition logic. Requires further in-depth analysis — may contain multiple functions.

**GAP 749 (0x0049e670, 320 bytes)** — Vehicle system function. References VehiclePtrArray (0x007c54f0) and compares vehicle struct fields at offset +0x9448. Between SetFourDwords and HUD_TachoTick. Likely vehicle sorting or comparison for HUD display.

**GAP 754 (0x004d2448, 88 bytes)** — Clean vehicle iteration loop. References VehicleCount (0x005c329c) and VehiclePtrArray (0x007c54f0). Checks offset +0x6440. Between Pit Timer State Init and Check First Uninitialized Vehicle. Likely finds first uninitialized or matching vehicle.

**GAP 763 (0x0055eeaf, 117 bytes)** — ONLY gap in this batch with standard 55 8B EC prologue. Floating-point math performing element-wise multiply between vectors. Between two math functions. Definitely a missed math utility function.

**GAP 768 (0x00599754, 42 bytes)** — Clean lazy initialization pattern. Tests and sets byte flags at 0x008d46b8 and 0x008d5a64. One-time initialization of global state between Char-by-Char Backward Scan and Cleanup Wrapper.

---

<!-- worker_S.md -->
**GAP 770 (0x0040b849, 1159B)** — Largest gap. First ~16 bytes unclear (possibly leftover data from preceding Camera Transform). Then clean prologue (53 55 56 8B E9 57) + large memset (33 C0 B9 60 00 00 00 F3 AB = zero 0x60 dwords). Camera/scene context. Likely a camera or scene object initialization function. HIGH value for documentation.

**GAP 784 (0x00470f79, 1127B)** — Constructor function. Sets vtables 0x005a0a80 and 0x007cf65c at offsets +0x00 and +0x31c. Zero-initializes fields. Race/session data loading context. HIGH value — constructing a major session data object.

**GAP 785 (0x00478ed0, 672B)** — Clean member function (this in ecx). Reads [esi+0x15c], uses string length (F2 AE / REPNE SCASB). Hit test / bounds check context. Likely a UI widget or render object method.

**GAP 810 (0x00599958, 385B)** — Proper function with stack frame. References global 0x005ea04c (compare against esi in loop). Near Ref Count Decrement — possibly a reference-tracking or resource cleanup iteration function.

**GAP 800-801 (0x0051f0a8, 22B & 0x00520df4, 26B)** — SSE stack-alignment prologue pattern. Surrounding context is SSE math (matrix multiply, cross product, quaternion). These are entry points to SSE-optimized math functions.

**GAP 809 (0x00589584, 30B)** — FPU function using x87 `FPREM` (partial remainder), `FSTSW AX`, `SAHF` loop pattern. Checks global 0x008d3e44. Classic MSVC fmod() or FPU status check.

**GAP 798 (0x004e1946, 42B)** — Mixed: jump table (4 entries) + index mapping table (00 00 00 00 01 02 03 03 03 03 03 03 03 03). Likely maps effect/subsystem indices through a lookup.

**GAP 805 (0x0055fa1a, 422B)** — Mixed: jump table (5 entries) + large data table (mostly 00 00 04 04 04... repeating pattern). Struct zero-init constructor context. Data table may be size/offset/flag array for struct fields.

**GAP 793 (0x004b41ba, 38B)** — Contains thunk referencing global 0x008ab6e4 (ScoringGate, known from docs/12). This thunk loads ScoringGate and jumps to it.

**GAP 782 (0x0046633f, 17B)** — Contains embedded ASCII "MYTH\0" string after small thunk. Possibly a debug string or state name.

---

<!-- worker_T.md -->
1. **GAP 826 (0x00471484, 6204 bytes)** — Largest gap. Contains ~4-6 missed functions including a function referencing string 0x005c670c ("Configuration" or similar). Between Mode-Specific Screen Setup and UI String Format + Display. Likely UI initialization/setup functions.

2. **GAP 828 (0x0047f43a, 1750 bytes)** — Single large function with standard prologue `53 55 56 8b 74 24 10 57`. Loop iterating up to 0x1fc iterations indexed from esi+0x1c19c. Destructor-like behavior scanning arrays.

3. **GAP 847 (0x005604c0, 1310 bytes)** — Classic `55 8b ec` prologue (push ebp; mov ebp,esp). Full stack-frame function with `pushad`. Likely physics solver or matrix operation.

4. **GAP 825 (0x0046a9b5, 923 bytes)** — Large single function with `push esi; push edi; mov esi,ecx` prologue. Writes to struct at offset 0x1b7d08 (some global structure). Between IDPairMatchAndClear and Message/NameBufferUpdate.

5. **GAP 838 (0x004d348d, 579 bytes)** — Contains jump table data then function that reads `DAT_007c56a4` (SessionType global). Game logic function checking session type and branching. Adjacent to PitTimer/RacePhaseStateMachine.

6. **GAP 822 (0x00455866, 714 bytes)** — Pure jump table data for KeyboardScancodeToASCII function. Most entries map to same target (likely default case). 714 bytes = ~178 entries.

7. **GAP 827 (0x0047931b, 209 bytes)** — Embedded ASCII string "MYTH" at start followed by function code. Between SessionExitOrChecks and FilePathResolver. The string might be a context tag or debug label.

8. **GAP 843 (0x00520ec1, 261 bytes)** — MMX vector math with alignment NOPs. Uses `movq`, `punpckhdq`, `pxor`, `paddw`. Returns via `emms`. Between SSE quaternion composition and SSE 3D vector normalization.

9. **GAP 839 (0x004d9c0a, 454 bytes)** — FPU function reading DAT_007c54e0 global and struct field at +0x3474. Compares against global float constant at 0x0059e440. Between HUDVenue/TrackNameOverlay and TimerDisplayRender.

10. **GAP 813 (0x0040f2d8)** — Small but significant jump table for SceneObjectLoader state machine at 0x0040f1c0. 8 entries helping decode the state machine.

11. **Thunk stubs pattern** — Multiple gaps (811, 816, 818, 831, 835, 837) contain identical pattern `e80b000000 e9XXXX0000 909090909090` — pairs of CALL+JMP trampolines in 16-byte alignment slots. These are MSVC-compiled /GUARD:CF (Control Flow Guard) or incremental linking thunks.
