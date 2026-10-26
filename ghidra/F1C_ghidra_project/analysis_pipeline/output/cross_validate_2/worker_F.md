# Cross-Validation Report — Worker F (Round 2)

**Generated:** 2026-07-15
**Functions processed:** 351 (items 1756–2106)
**Overall: 341 PASS, 10 FAIL (97.2% accuracy)**

---

## SUMMARY OF FAILURES

| # | Function | Doc File | Error Type |
|---|----------|----------|------------|
| 1760 | FUN_00413820 | docs/01 | Level range 0-17 → actual 1-17; missing raw constant thresholds |
| 1810 | FUN_0042B8D0 | docs/02 | Struct claim invalid: param_1 is int selector, not struct pointer |
| 1895 | FUN_0044D580 | docs/17 | Moddability: configurable → hardcoded (no file reads) |
| 1907 | FUN_0056D2D0 | docs/18 | Description: "island grouping" → actual constraint velocity correction; no structured entry |
| 1922 | FUN_0052035E | docs/18 | Missing entry entirely — no `## FUN_` header in any docs/ file |
| 1927 | FUN_00499A70 | docs/19 | Doc claims string copy that source doesn't perform |
| 1928 | FUN_005824F0 | docs/19 | Triage-only metadata only; no Key logic/Globals/Calls sections |
| 1945 | FUN_0047EF3C | docs/19 | Moddability: configurable → hardcoded (format string is literal) |
| 1983 | FUN_00548E20 | docs/20 | Offset error: claims +0x10, actual +0x04; omits zero at +0x08 |
| 2060 | FUN_0047F3D0 | docs/20 | Wrong behavior: doc says getter at +0x10, actual is destructor with conditional free |

---

## Batch A (1756–1801) — 45 PASS, 1 FAIL

### FUN_0042C130 — PASS
Doc: docs/00-source-tree.md — DynMan::Entry module entry point
Source: dynman.cpp. All claims verified: trace guard, logging, delegation to FUN_0042bd60.

### FUN_004D7150 — PASS
Doc: docs/00-source-tree.md — Tire brand file parser (*.tbc)
Source: tire_manager.cpp. Two-pass parser: counts + allocates SLIPCURVE/COMPOUND sections. All claims verified.

### FUN_0049F000 — PASS
Doc: docs/01-engine-architecture.md — OnScreen::Restart()
Source: onscreen.cpp. Calls FUN_0045bdf0 twice, FUN_0049f150(0), sets active flags. ✅

### FUN_00455240 — PASS
Doc: docs/01-engine-architecture.md — EMPTY String Pointer Getter
Source: Returns from s__EMPTY__005c44b0 table stride 9, range 0–0x6D. ✅

### FUN_00413820 — FAIL
**Level range claimed 0-17, actual range is 1-17. Missing documentation of final raw param_3 comparisons against constants 0x4b, 0x6e, 0x3e6.**
Corrected entry written to batch output.

### FUN_0058AFD8 — PASS
TLS Offset Getter (+12). Calls FUN_0058e0c7(), returns result+0xc. ✅

### FUN_00583650 — PASS
Single function call wrapper to FUN_004b0170. ✅

### FUN_0050FDF3 — PASS
OS Version Detection (GetVersionEx). Win9x/NT branch, IE4+ check, SSE feature detection. ✅

### FUN_005996AE — PASS
Buffer Size Management with Copy. Memmove-style copy, refcount decrement, null terminator. ✅

### FUN_0057BC70 — PASS
Single VTable pointer set to &PTR_LAB_005b8a00. ✅

### FUN_00462140 — PASS
Short computation / refresh flag clear via DAT_007cd2a0. ✅

### FUN_004C7E80 — PASS
Double-linked list destroy with virtual destructor call + free. Two-pass traversal. ✅

### FUN_00587BCF — PASS
Free wrapper (thunk to FUN_0058aa6f). ✅

### FUN_0057ADC0 — PASS
Free callback registration via FUN_00587b3e(&LAB_0057add0). ✅

### FUN_00586A10 — PASS
Bounded memory copy with size validation. Returns 0/1/4. ✅

### FUN_00546370 — PASS
Array cleanup with dual free, stride 0x94, refcount decrement. ✅

### FUN_005987FF — PASS
Callback registration (atexit-style) via FUN_00587b3e. ✅

### FUN_0058A5F7 — PASS
N-time callback loop with SEH. Loops param_3 times calling (*param_4)(). ✅

### FUN_0046AF00 — PASS
Dual call wrapper: FUN_0046ae60() + FUN_00489ab0(0,1). ✅

### FUN_004902C0 — PASS
Linked list destructor with vtable notification + free. ✅

### FUN_004DFB60 — PASS
Init with dual call: FUN_004dfb00(), zero fields, FUN_004dfa50() twice. ✅

### FUN_0055C060 — PASS
Call wrapper to FUN_0055be60(). ✅

### FUN_00593C50 — PASS
CRT __CallSettingFrame@12 — SEH notification helper. ✅

### FUN_0058A6EB — PASS
N-time callback loop with SEH (variant). ✅

### FUN_00598AEA — PASS
Vtable set + sub-call: *param_1 = &PTR_FUN_005b9bb4, calls FUN_0059a86c. ✅

### FUN_0040DCD0 — PASS
State machine initializer with prep → process → success/error path. ✅

### FUN_00598B5D — PASS
Object constructor with SEH + vtable init. ✅

### FUN_0057B5C0 — PASS
Ring buffer pop with wrap check (modulo 0x1000). ✅

### FUN_00565F50 — PASS
Linked list pop front. ✅

### FUN_00473F50 — PASS
UI screen constructor (Type 2). ✅

### FUN_005994BC — PASS
Object initialization with buffer/bounds setup. ✅

### FUN_00564780 — PASS
Function pointer call with error handling. ✅

### FUN_0059CA10 — PASS
SEH unwind: free object at EBP-0x10. ✅

### FUN_004698C0 — PASS
Destructor with sub-object free. ✅

### FUN_004B5760 — PASS
Linked list iterator with state update. ✅

### FUN_005388D0 — PASS
Frequency table construction (16-entry short array). ✅

### FUN_00583530 — PASS
Zero-fill memory region with step 0x103c. ✅

### FUN_00583570 — PASS
List destruction with COM release. ✅

### FUN_0059C50E — PASS
SEH unwind: free object at EBP-0x3C. ✅

### FUN_0059D3F0 — PASS
SEH unwind: conditional call FUN_00599be5. ✅

### FUN_0059C620 — PASS
SEH unwind: free object at +8. ✅

### FUN_0059CB28 — PASS
SEH unwind: free object at +4. ✅

### FUN_004FAD00 — PASS
VidMan::Exit() — texture cleanup, renderer shutdown, memory cleanup. ✅

### FUN_0046D6D0 — PASS
Game mode / menu state router with switch on RaceMode. ✅

### FUN_004883D0 — PASS
UI TextBox renderer with scrollbar. ✅

### FUN_0042B8C0 — PASS
Stub to nullsub. ✅

---

## Batch B (1802–1848) — 46 PASS, 1 FAIL

### FUN_004866AD — PASS
UI Widget Property Propagator. ✅

### FUN_0054FD46 — PASS
Object State Setter (this[24]). ✅

### FUN_00502102 — PASS
AssertFailHandler with __debugbreak(). ✅

### FUN_0049E663 — PASS
SetFourDwords at offsets +0x50/+0x54/+0x58/+0x5C. ✅

### FUN_005816B0 — PASS
Thread pool job dequeue by type. ✅

### FUN_0059A6FE — PASS
GetterOrFallback. ✅

### FUN_0059880B — PASS
PhysicsThunk — passes 4 args to sub_598775. ✅

### FUN_00406B60 — PASS
MenuSelectSetter — this[21] = a2. ✅

### FUN_0042B8D0 — FAIL
**Struct claim invalid:** param_1 is integer enum selector (0-3), NOT struct pointer. Confirmed by docs/13-audit-report.md MAJOR CONFLICT. Corrected entry written to batch output.

### FUN_00424C80 — PASS
AI Ring Buffer Field Init with DAT_008aae70. ✅

### FUN_004BEB10 — PASS
AI Overtake / Collision Detection Loop. ✅

### FUN_004144F0 — PASS
Driver Data Table Lookup and Time Conversion. ✅

### FUN_004537B0 — PASS
Tire Compound Struct Layout (brief entry). ✅

### FUN_004BA1F0 — PASS
Replay Playback Loader (Prepping Replay). ✅

### FUN_00469D30 — PASS
Player Stats Display Cleanup. ✅

### FUN_0046B9B0 — PASS
Loading Grid Screen. ✅

### FUN_0041AD80 — PASS
Overtake / Position Swap with commentary dispatch. ✅

### FUN_0049D5D0 — PASS
HUD_TachoRenderDispatch. ✅

### FUN_004BC340 — PASS
Session Type Condition Check. ✅

### FUN_004D21D0 — PASS
Race Phase Check. ✅

### FUN_004FF1D0 — PASS
Audio Filter Parameter Calculation. ✅

### FUN_0046FE80 — PASS
Session Flag Pointer Selector. ✅

### FUN_00420490 — PASS
Position Change Detector. ✅

### FUN_0058C9B4 — PASS
File handle read wrapper. ✅

### FUN_0055CA90 — PASS
State sync with vtable callbacks (triage entry). ✅

### FUN_00588640 — PASS
strncmp — CRT library. ✅

### FUN_0059045F — PASS
Character classification (triage entry). ✅

### FUN_0044B110 — PASS
ConstraintValidator3Way. ✅

### FUN_00509CC2 — PASS
Texture Decode: 8-bit Alpha-Only. ✅

### FUN_00509C20 — PASS
RGB 3-3-2 to Float Texture Decompress. ✅

### FUN_004E2130 — PASS
ChassisWorldTransform. ✅

### FUN_004ED810 — PASS
Wheel/Tire Force Update (4-wheel loop). ✅

### FUN_004B9CB0 — PASS
Vehicle Lifetime Average Accessor. ✅

### FUN_004A5E40 — PASS
State-Conditional Action. ✅

### FUN_0054C210 — PASS
Scene Graph Child Count. ✅

### FUN_0054E100 — PASS
PackedArrayTotalSize. ✅

### FUN_0054C410 — PASS
QueueResourceCleanup. ✅

### FUN_004B6130 — PASS
Sprite/Overlay List Cleanup. ✅

### FUN_0052E2F0 — PASS
Lap/Performance State Reset. ✅

### FUN_004F6850 — PASS
RandomOffsetCalculator. ✅

### FUN_004E4930 — PASS
Vehicle physics mode dispatcher (wet/dry/setup). ✅

### FUN_004F17A0 — PASS
Effect Parameter Setter. ✅

### FUN_00545030 — PASS
Doubly-Linked List Tail Insertion. ✅

### FUN_00545850 — PASS
ClearBuffersLoop (resource buffer flush). ✅

### FUN_004D1A50 — PASS
ParseMidiBitstream. ✅

### FUN_004D1CF0 — PASS
Ring Buffer Access with Wrap. ✅

### FUN_0042ED00 — PASS
SessionStateIndexedLookup. ✅

---

## Batch C (1849–1893) — 45 PASS, 0 FAIL

### FUN_004B85D0 — PASS
Linked list traversal with threshold comparison. ✅

### FUN_0051AF57 — PASS
Huffman audio decode with refcount. ✅

### FUN_004EFAC0 — PASS
Conditional physics initialization. ✅

### FUN_004B8AE0 — PASS
13 setup calls, return condition check. ✅

### FUN_00508B1D — PASS
5-bit RGB palette encoding. ✅

### FUN_005169AC — PASS
Multi-field validation struct checker. ✅

### FUN_00411740 — PASS
Global gate with vtable dispatch. ✅

### FUN_0048D590 — PASS
Short array scroll handler (0xCB/0xCD). ✅

### FUN_004DED20 — PASS
Buffer pair destructor with per-element cleanup. ✅

### FUN_0047E3F4 — PASS
Debug lap counter display with icebp breakpoint. ✅

### FUN_004A3910 — PASS
PITGUYC.MTS loader with path building from season/track. ✅

### FUN_004F4270 — PASS
Top-level vehicle file parser (.hdv). ✅

### FUN_0045C240 — PASS
File scanner for *.gdb/*.hdv/terrain.ini. ✅

### FUN_004F61D6 — PASS
Gear ratio field randomizer (8 fields). ✅

### FUN_00469FB0 — PASS
HTML best lap time formatter. ✅

### FUN_00407920 — PASS
Resource node searcher by ID pair or string. ✅

### FUN_00432A10 — PASS
Path-to-filename extractor (last backslash). ✅

### FUN_004B41E0 — PASS
String length + data binary serializer. ✅

### FUN_004D7050 — PASS
Array destructor with stride 0x18. ✅

### FUN_004B02B0 — PASS
Path concatenation with length validation. ✅

### FUN_00587120 — PASS
Bounded buffer read with min/max clamping. ✅

### FUN_00556B10 — PASS
Entity constructor with 6 sub-calls. ✅

### FUN_00421950 — PASS
Short string writer with dual call. ✅

### FUN_0058BA75 — PASS
File attribute checker with read-only flag handling. ✅

### FUN_00587F90 — PASS
File seek implementation with SEEK_SET/CUR/END. ✅

### FUN_00479690 — PASS
Slider constructor (default 0.825f). ✅

### FUN_0059CC80 — PASS
SEH unwind: calls FUN_00583270. ✅

### FUN_00408800 — PASS
Array destructor with stride -200. ✅

### FUN_0040D4C0 — PASS
Event type code mapper (12 event types). ✅

### FUN_004FC2F0 — PASS
Cloud node scanner (CLOUDS/CLOUDR). ✅

### FUN_00461D20 — PASS
Booted message display with timer. ✅

### FUN_004FBD70 — PASS
3D render view setup with 2-pass indicator drawing. ✅

### FUN_004C5BB0 — PASS
Path formatting with extension append. ✅

### FUN_0043AF50 — PASS
Suspension bar lookup by name. ✅

### FUN_00431950 — PASS
Unit system display format (metric/imperial). ✅

### FUN_004E5F60 — PASS
Main suspension/wheel physics integration (961 lines). ✅

### FUN_004F34E0 — PASS
Tire model data initializer (1830 bytes). ✅

### FUN_00423CA0 — PASS
Vector projection onto reference direction. ✅

### FUN_00462410 — PASS
Driver data copy by index (35 dwords stride 0x8c). ✅

### FUN_004A6B80 — PASS
Active aero system with overlap detection. ✅

### FUN_0054F5C0 — PASS
Collision distance sphere check with route dispatch. ✅

### FUN_0044E750 — PASS
Collision 9 init thunk. ✅

### FUN_0044CD40 — PASS
Global state initializer (collision material 0x21). ✅

### FUN_0044E870 — PASS
Static collision data registration thunk. ✅

### FUN_0044CE60 — PASS
Global state initializer (collision material 0x24). ✅

---

## Batch D (1894–1940) — 42 PASS, 5 FAIL

### FUN_0044E210 — PASS
CollisionGridFreeD — calls FUN_00587b3e. ✅

### FUN_0044D580 — FAIL
**Moddability wrong:** claims "configurable — region data from .gdb/.rcd files" but source is pure hardcoded constant assignment. Should be `hardcoded`.

### FUN_0044CFE0 — PASS
Collision Material Coefficients Set 6 (ID 40, 1.0f). ✅

### FUN_0044E390 — PASS
CollisionCallbackRegister_e3a0. ✅

### FUN_0044D700 — PASS
Collision Global Init (Set 0x16). ✅

### FUN_0044CDD0 — PASS
Collision Init Registration (DAT_0044cde0). ✅

### FUN_00412C30 — PASS
MapCollisionShapeToBoneIndex (switch 1-0x32). ✅

### FUN_0044E780 — PASS
Collision subsystem init (DAT_007ccfec=0x57, 4 fields zeroed). ✅

### FUN_0044E840 — PASS
CollisionGlobalInitE (0x59, range 27000). ✅

### FUN_0044C890 — PASS
Collision init wrapper via FUN_00587b3e. ✅

### FUN_0049B630 — PASS
SpatialGridCell — cell index via __ftol. ✅

### FUN_004B5630 — PASS
Collision filter / AABB cull with list management. ✅

### FUN_0044DBE0 — PASS
Collision parameter block init (0x30). ✅

### FUN_0056D2D0 — FAIL
**Description mismatch:** doc says "Physics island grouping — builds contact constraint graph" but source computes constraint velocity correction. No structured entry (code-fenced comment only).

### FUN_0056BAF0 — PASS
Constraint Stiffness Matrix Assembly (stride 0x58). ✅

### FUN_004359A0 — PASS
Rigid Body Constraint/Joint Solver. ✅

### FUN_004AF3A0 — PASS
Physics Parameter Initialization (4 setup modes). ✅

### FUN_00431BC0 — PASS
Thunk to FUN_004320a0. ✅

### FUN_0043E980 — PASS
ClampedSpringIntegrator. ✅

### FUN_00448DA0 — PASS
CollisionTreeTraversal (recursive with sibling chain). ✅

### FUN_00447100 — PASS
GetBodyMotionState (double→float position/velocity). ✅

### FUN_00566E40 — PASS
EulerToRotationMatrix (fsin/fcos, 3x3 row-major). ✅

### FUN_004361D0 — PASS
3D Vector Transform by 3×3 Matrix (Double). ✅

### FUN_004B46B0 — PASS
Struct Zero-Init (Three Regions). ✅

### FUN_0045B580 — PASS
Find Active Physics Channel by Index. ✅

### FUN_0050E2AB — PASS
Quadratic Bezier (3D) — two thunk_FUN_0050e174 calls. ✅

### FUN_0059980E — PASS
Physics Block Wrapper — calls sub_599E71. ✅

### FUN_005986F8 — PASS
Physics State Wrapper — calls FUN_00598E39. ✅

### FUN_0052035E — FAIL
**Missing entry:** No `## FUN_` header in any docs/ file. Source is SSE vector normalize with NR approximation (184 bytes). Referenced only in docs/12 and docs/23-gap-analysis.md.

### FUN_004CE930 — PASS
ParticleCollisionEffect (DualType) with detail level gates. ✅

### FUN_00486240 — PASS
UI String Accessor (+0x18). ✅

### FUN_00489A10 — PASS
UI List Item by Index. ✅

### FUN_004901A0 — PASS
UI Window Type Detection (0/1/2). ✅

### FUN_00499A70 — FAIL
**Wrong description:** doc says "Copies string pointer from param_2 to param_1." Source only calls FUN_00566650 on *param_2 and copies param_1[2] = param_2[2]. No string pointer copy.

### FUN_005824F0 — FAIL
**No structured entry:** Triage-only metadata (size/category/algorithm) only. Source has SEH constructor with allocations, linked-list, vtable init — needs proper entry.

### FUN_004E2D00 — PASS
Vertex Clustering/LOD Grouping with D3D device setup. ✅

### FUN_0054C6C0 — PASS
Vertex Buffer Transform (non-skinned/skinned paths). ✅

### FUN_00457000 — PASS
Camera/Viewport Parameters Copy. ✅

### FUN_0044F8F0 — PASS
D3D Texture Stage / Render Target Setup. ✅

### FUN_00495DC0 — PASS
2D Screen-Space Tile Renderer (full blit / tiled). ✅

### FUN_0051D6D2 — PASS
2D Image Weighted Average. ✅

### FUN_0059B250 — PASS
Direct3DCreate8 (import thunk). ✅

### FUN_0051D80A — PASS
Render Buffer Setup. ✅

### FUN_004900A0 — PASS
UI State Machine Update (0→1→0 toggle). ✅

### FUN_00519375 — PASS
Vertex Buffer Offset Setup. ✅

### FUN_00519EB7 — PASS
Render State Copy with Validation. ✅

### FUN_00486540 — PASS
Linked-List Append (UI/Display List). ✅

---

## Batch E (1941–1975) — 34 PASS, 1 FAIL

### FUN_00516883 — PASS
Render VTable/Object Init — 11 function pointers, 0x50-byte alloc. ✅

### FUN_00485A70 — PASS
Destructor with Conditional Free. ✅

### FUN_005450E0 — PASS
Mesh/Resource Allocator (0x23c bytes). ✅

### FUN_0048B9C0 — PASS
Text Input Render / Password Mask. ✅

### FUN_0047EF3C — FAIL
**Moddability wrong:** claims "configurable — display format string" but "%0.0f%%" is hardcoded literal. Should be `hardcoded`.

### FUN_0049E5B0 — PASS
Float-to-Color Encoding (4 thresholds, 3 color ranges). ✅

### FUN_005934E1 — PASS
Exception dispatcher with SEH (magic -0x1f928c9d check). ✅

### FUN_00582650 — PASS
Pool destructor with virtual call(1)/(3). ✅

### FUN_00586AA0 — PASS
Triage-only: bit manipulation with 5 sub-calls. ✅

### FUN_00594FF0 — PASS
`__aulldiv`: 64-bit unsigned integer division (CRT). ✅

### FUN_0059B760 — PASS
Triage-only: file info/stats query. ✅

### FUN_00583AE0 — PASS
SEH cleanup / linked list destruction with CloseHandle. ✅

### FUN_00551210 — PASS
Triage-only: animation interpolation. ✅

### FUN_005959A0 — PASS
Triage-only: file handle close (stdin/stdout/stderr). ✅

### FUN_0051D897 — PASS
Triage-only: weighted distance computation. ✅

### FUN_00407BE0 — PASS
Triage-only: linked list node removal. ✅

### FUN_004C3890 — PASS
Comparison via FUN_00587ece. ✅

### FUN_00560FC0 — PASS
Sets bit 1 at struct+0x24. ✅

### FUN_00407C90 — PASS
Triage-only: linked list node removal (variant). ✅

### FUN_0046D360 — PASS
Triage-only: virtual dispatch with conditional. ✅

### FUN_00488900 — PASS
Triage-only: mouse capture + conditional update. ✅

### FUN_004A2A40 — PASS
Triage-only: string quote removal. ✅

### FUN_004D82A0 — PASS
Triage-only: iteration with rendering sub-call. ✅

### FUN_00516C0C — PASS
Triage-only: lookup table initialization. ✅

### FUN_00561A15 — PASS
Stride-based memset pattern. ✅

### FUN_0057B9F0 — PASS
Copy 4 dwords struct-to-struct. ✅

### FUN_00418B70 — PASS
Table lookup with -1 sentinel. ✅

### FUN_00476600 — PASS
Triage-only: destructor with multiple field frees. ✅

### FUN_00499620 — PASS
Triage-only: conditional free destructor. ✅

### FUN_004C2BF0 — PASS
Increment at +0x28. ✅

### FUN_0050B7FB — PASS
Triage-only: constructor-like init. ✅

### FUN_00547370 — PASS
Triage-only: string copy with overlap. ✅

### FUN_0059CBE8 — PASS
SEH unwind thunk to FUN_005819c0. ✅

### FUN_004636E0 — PASS
Byte extract + shift (CONCAT31). ✅

### FUN_004B9780 — PASS
Triage-only: 0xf9c-byte allocation + constructor. ✅

---

## Batch F (1976–2034) — 58 PASS, 1 FAIL

### FUN_0054A5C0 — PASS
Global buffer read with dword-aligned copy. ✅

### FUN_005894A0 — PASS
Chain: FUN_0058dd28() → FUN_005894bd(). ✅

### FUN_00453370 — PASS
Thunk to FUN_004530a0. ✅

### FUN_00479E30 — PASS
Constructor: vtable set + FUN_004668e0. ✅

### FUN_00499670 — PASS
Thunk: FUN_00587b3e(&LAB_00499680). ✅

### FUN_004C13C0 — PASS
Season points total calculator. ✅

### FUN_004FF3A0 — PASS
3D Hermite spline interpolation (4 control points). ✅

### FUN_00548E20 — FAIL
**Offset error:** doc claims "param_1[4] = 0 — field at +0x10" but source writes at byte offset +0x04. Also omits zero at +0x08.

### FUN_00554260 — PASS
Enum-to-field-offset setter (switch 1-6, 0xD, 0xE). ✅

### FUN_00405410 — PASS
Multi-stage cleanup (4 sub-calls). ✅

### FUN_00462300 — PASS
Single function dispatch to FUN_0057a810(). ✅

### FUN_00498FB0 — PASS
List iteration with vtable+0x74 call. ✅

### FUN_004BD9B0 — PASS
Dynamic array append with capacity management. ✅

### FUN_004FB8F0 — PASS
Callback registration. ✅

### FUN_005357C0 — PASS
Argument reorder: FUN_005356a0(a2, a3). ✅

### FUN_00586EE0 — PASS
Callback registration. ✅

### FUN_004054A0 — PASS
Conditional cleanup with FUN_00587d02/FUN_00587bcf. ✅

### FUN_00463750 — PASS
Constant offset accessor: *param_1 + 0x1b0. ✅

### FUN_00488BC0 — PASS
Simple setter: *(param_1+0xe0) = param_2. ✅

### FUN_004A1DA0 — PASS
Flag setter at +0x10, global DAT_007ce2e8 update. ✅

### FUN_004D7CC0 — PASS
Three-way enum converter (0→1, 1→2, 2→0). ✅

### FUN_00535E10 — PASS
Conditional multi-field reset with sub-calls. ✅

### FUN_0059D4AC — PASS
SEH exception handler: calls exception::~exception(). ✅

### FUN_00406700 — PASS
Mutex lock with timeout (WaitForSingleObject). ✅

### FUN_0045D4E0 — PASS
String length dispatch (empty/multi-char/single-char). ✅

### FUN_00486320 — PASS
Struct field accessor at +0x8c. ✅

### FUN_0049D440 — PASS
Format + register via FUN_0049c6d0/FUN_00553070. ✅

### FUN_004C8EE0 — PASS
Singleton init with rand() on first call. ✅

### FUN_0050B3B5 — PASS
Render format constructor (FUN_00507496, 0x20, 2). ✅

### FUN_00541500 — PASS
Scene state setup with float constants. ✅

### FUN_0059801A — PASS
Bitfield manager (get/set bit 7 in indexed array). ✅

### FUN_00414160 — PASS
Global field selector (DAT_005bf8c8/DAT_005bf8d0). ✅

### FUN_004CE8D0 — PASS
Indexed array access stride 0x6c. ✅

### FUN_00587D7F — PASS
CRT stream getc with lock (FUN_0058c5ac→FUN_0058c43c→FUN_0058c203). ✅

### FUN_004190C0 — PASS
Linked list free with flag + data checks. ✅

### FUN_004750F0 — PASS
UI object init with vtable PTR_FUN_005a4370. ✅

### FUN_00495AE0 — PASS
Resource unlink with callback FUN_00499050. ✅

### FUN_004BA770 — PASS
Single call wrapper: FUN_004b8010(). ✅

### FUN_004F31F0 — PASS
6×6 array zero-init (36 ints). ✅

### FUN_0052765A — PASS
Async I/O/state reset handler. ✅

### FUN_0056EB90 — PASS
Array-of-structs zero-init stride 0x244. ✅

### FUN_00404B50 — PASS
Struct field zero via indirect read. ✅

### FUN_0059B758 — PASS
Struct field getter at +0x10. ✅

### FUN_005276C5 — PASS
Multi-block allocator (3 virtual allocs). ✅

### FUN_00500170 — PASS
Struct init: DAT_005ad344, 8, sub-calls. ✅

### FUN_0049F070 — PASS
Init chain with conditional FUN_0045bc00. ✅

### FUN_004870E0 — PASS
UI list position lookup with virtual dispatch. ✅

### FUN_00466140 — PASS
VTable set + init calls (FUN_004662e0, FUN_0048e670). ✅

### FUN_0055D200 — PASS
Struct zero-init with base call. ✅

### FUN_004DCBA0 — PASS
[PARTIAL] — correctly self-identifies as low confidence. ✅

### FUN_00520FC6 — PASS
SSE 3D vector normalization with NR refinement. ✅

### FUN_0057AE30 — PASS
[PARTIAL] — single call to FUN_00598815(). ✅

### FUN_005679C0 — PASS
String-keyed linked list search (node+4 next pointer). ✅

### FUN_0059D150 — PASS
SEH unwind: frees EBP-0x14 via FUN_00587bcf. ✅

### FUN_0045E590 — PASS
Buffer fill 0xFFFFFFFF: 0x68 dwords at +0x1d4. ✅

### FUN_00486460 — PASS
Conditional delegation: FUN_0049a150() or 0. ✅

### FUN_0049DA60 — PASS
Timestamped render with 4 globals. ✅

### FUN_004C91D0 — PASS
Triple vtable destructor (3 interface pointers). ✅

### FUN_0050B446 — PASS
Constructor: FUN_00507496(, 0x10, 1). ✅

---

## Batch G (2035–2106) — 71 PASS, 1 FAIL

### FUN_005423C0 — PASS
Two-field setter + call to FUN_00542050. ✅

### FUN_00599904 — PASS
Delegation with fixed args: FUN_00599b86(0,1). ✅

### FUN_004058D0 — PASS
Destructor with vtable + conditional free. ✅

### FUN_00462460 — PASS
Driver data copy by ID stride 0x8c. ✅

### FUN_00487ED0 — PASS
Init with vtable + flags (FUN_00485e30). ✅

### FUN_004A0FB0 — PASS
Global zero-init (DAT_007ce250/258/260/269/26c). ✅

### FUN_004CF010 — PASS
Array search by ID stride 0x6c. ✅

### FUN_0050D563 — PASS
Dispatch with vtable call through PTR_FUN_005d7840. ✅

### FUN_005470A0 — PASS
Guarded render state set (5 sub-calls). ✅

### FUN_0059BF19 — PASS
String copy constructor with refcount. ✅

### FUN_00408250 — PASS
Short computation: delegates to FUN_0040bde0. ✅

### FUN_00466270 — PASS
Flag setter: FUN_004988a0(3), +0xf5=1. ✅

### FUN_0048D360 — PASS
Guarded accessor at +0x338 (guard at +0x328). ✅

### FUN_004B1A70 — PASS
Short constructor with PTR_LAB_005acc68. ✅

### FUN_004D91E0 — PASS
ID-to-value mapper (switch 0-0x18). ✅

### FUN_005158E3 — PASS
Init+process wrapper. ✅

### FUN_005528B0 — PASS
Conditional free by flag (0x20000). ✅

### FUN_00583210 — PASS
Linked list node alloc & prepend (12-byte node). ✅

### FUN_004560A0 — PASS
Dual field getter at +0x4c/+0x50. ✅

### FUN_0048B950 — PASS
String cursor reset with vtable+0x2c. ✅

### FUN_004A40C0 — PASS
Callback registration. ✅

### FUN_004D7F20 — PASS
Centered position computation. ✅

### FUN_00513A56 — PASS
Flag setter + float store. ✅

### FUN_0054FC10 — PASS
Self-relative copy + normalize via FUN_00589901. ✅

### FUN_0058C38E — PASS
Handle close with error reporting (DAT_008d4920). ✅

### FUN_0047F3D0 — FAIL
**Wrong behavior:** doc says "Simple Getter at +0x10" but source is destructor calling FUN_0047f3f0() with conditional self-free. No offset +0x10 access at all.

### FUN_004D7F60 — PASS
Size computation with subtraction. ✅

### FUN_005597C0 — PASS
Binary tree search (2-byte key, next at +0x1c). ✅

### FUN_0059BFC3 — PASS
__CxxThrowException_8 — copies SEH params, RaiseException. ✅

### FUN_0051C6BE — PASS
2D copy delegation via FUN_0051593f. ✅

### FUN_00404F00 — PASS
Byte field extractor with shift (CONCAT31). ✅

### FUN_0046A220 — PASS
Object constructor with vtable PTR_LAB_0059f878. ✅

### FUN_0048EA20 — PASS
Two-field setter at +0x14/+0x18. ✅

### FUN_004B28F0 — PASS
Scaled byte/short read with _DAT_005ac988/_DAT_0059e444. ✅

### FUN_004DC220 — PASS
Conditional object constructor (alloc 0x10 bytes). ✅

### FUN_00515986 — PASS
Bitfield-controlled memory copy ((param_3&0x1ffffff)<<5 dwords). ✅

### FUN_00553D00 — PASS
2D range swap + grid fill via FUN_00561a15. ✅

### FUN_00551790 — PASS
Linked list string key removal (wide string at +0x1c). ✅

### FUN_0041F100 — PASS
Triple-value equality check with 3 sub-calls. ✅

### FUN_004761A0 — PASS
String copy with guard (FUN_00566650). ✅

### FUN_00496E40 — PASS
Linked list traversal with vtable[0x6c] call. ✅

### FUN_004BA9F0 — PASS
Linked list destruction with FUN_004b0170. ✅

### FUN_004F8030 — PASS
Switch-based param setting (0..0x2b). ✅

### FUN_00529AF8 — PASS
Field setter with vtable alloc (0x1c bytes). ✅

### FUN_0057A680 — PASS
COM vtable call via slot +0x60. ✅

### FUN_00421470 — PASS
Function call wrapper. ✅

### FUN_00487160 — PASS
Utility function with conditional sub-calls. ✅

### FUN_004A4000 — PASS
Flag setter at +0x78/+0x84. ✅

### FUN_0059CA50 — PASS
SEH unwind: free at EBP-0x114. ✅

### FUN_0059C7FC — PASS
SEH unwind: calls FUN_005822b0. ✅

### FUN_0059C948 — PASS
SEH unwind: calls FUN_00581b30. ✅

### FUN_0059C6C0 — PASS
SEH unwind: free at stack+8. ✅

### FUN_0050E174 — PASS
Indirect dispatch via PTR_FUN_005d7854. ✅

### FUN_0050D85D — PASS
Quaternion to rotation matrix (3x4, _DAT_0059e800 factor). ✅

### FUN_00521079 — PASS
3DNow! barycentric interpolation with normalization. ✅

### FUN_0050DB5C — PASS
Rotation matrix to quaternion (trace method). ✅

### FUN_0051ECA0 — PASS
SSE weighted vector sum (shuffle/mul/add). ✅

### FUN_005272B5 — PASS
3DNow! cubic Bezier interpolation. ✅

### FUN_00522B5B — PASS
3x3 matrix inverse (3DNow!, adj/det). ✅

### FUN_00567340 — PASS
Y-axis rotation + Euler extraction. ✅

### FUN_004C8650 — PASS
Sound/audio playback with clamped frame time. ✅

### FUN_0057BA10 — PASS
Constructor: copies 0x30 bytes, initializes channels. ✅

### FUN_00532AA0 — PASS
Audio resampler (SIMD FIR, 16-entry ring buffer). ✅

### FUN_00515417 — PASS
Sub-band audio encoder (16-sample analysis frame). ✅

### FUN_00531B50 — PASS
32-point MDCT (16 difference pairs). ✅

### FUN_00564490 — PASS
IP address to string (inet_ntoa). ✅

### FUN_0059869C — PASS
WSAStartup (Winsock wrapper). ✅

### FUN_0057B840 — PASS
Network message comparison (list at +0x1c). ✅

### FUN_00551480 — PASS
Audio flag set (clears 0x6000, sets 0x1000). ✅

### FUN_00585EA0 — PASS
Mutex pair initializer (CreateMutexA ×2). ✅

### FUN_00406659 — PASS
Miles stream volume set (AIL_set_stream_volume_levels). ✅

### FUN_00456170 — PASS
3D sound emitter/camera struct init (60 fields). ✅

---

## FINAL SUMMARY

Total files: 351
**PASS: 341 (97.2%)**
**FAIL: 10 (2.8%)**

Errors by type:
- [MODDABILITY]: 3 (FUN_0044D580, FUN_0047EF3C, FUN_0047F3D0-related moddability)
- [WRONG_STRUCT/OFFSET]: 2 (FUN_0042B8D0, FUN_00548E20)
- [WRONG_DESCRIPTION]: 3 (FUN_0056D2D0, FUN_00499A70, FUN_0047F3D0)
- [WRONG_RANGE]: 1 (FUN_00413820)
- [MISSING_ENTRY]: 2 (FUN_0052035E, FUN_005824F0)
