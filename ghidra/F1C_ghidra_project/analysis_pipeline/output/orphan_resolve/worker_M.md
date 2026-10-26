=== ORPHAN CLASSIFICATIONS ===
| address | classification | confidence | evidence | suggested_caller |
|---------|---------------|------------|----------|-----------------|
| 0x0040b360 | vtable_member | HIGH | Calls vtable[0x18]() then vtable[0x1c]() on result — classic C++ virtual dispatch chain. `__fastcall int*(param_1)` reads `*param_1` as vtable ptr. Pattern: `(**(code**)(*param_1 + 0x18))()` → if result non-null → `(**(code**)(*result + 0x1c))()`. Functions.json: algorithm_family="Virtual dispatch chain", used_by_system="docs/01-engine-architecture.md — C++ vtable-based object traversal" | FUN_00XXXXXX (parent's vtable at offset N) |
| 0x0044c9e0 | game_logic_isolated | HIGH | Writes DAT_007cccb0 = 0xB (CollisionConfigType, docs/12) + 5 zeroed fields. Same pattern as other collision state inits (0x11, 0x2d, 0x44, 0x53, 0x62). No direct callers found, but globals are used by collision system. Likely called via function pointer array during collision system init. | CollisionSystemInit (unknown — likely iterates an array of init func ptrs) |
| 0x0044cf80 | game_logic_isolated | MEDIUM | Writes DAT_007ca480 = 0x27 + 3 adjacent fields (_007ca484=0, _007ca488=0xbf800000/-1.0f, _007ca48c=0). DAT_007ca480 listed in docs/12 as AudioBufferObject but also referenced in collision context (FUN_0044ff50 audio mixer, FUN_00452810 config resolver). Value 0x27=39 suggests a type ID, not a buffer pointer. Likely misclassified in triage as "collision" — could be audio init block. Called via func ptr array during subsystem init. | SubsystemInit (audio or collision — iterates init func table) |
| 0x0044d520 | game_logic_isolated | HIGH | Writes DAT_007ccd20 = 0x11 (CollisionStateBlock, docs/17) + 5 zeroed fields. Already documented in docs/17 as CollisionStateInit_17. No new callers found. Same array-of-init-funcs pattern. | CollisionSystemInit (func ptr table) |
| 0x0044dac0 | game_logic_isolated | HIGH | Writes DAT_007cceb8 = 0x2d (ConstraintCount=45, docs/12) + 5 zeroed fields. Already documented in docs/17 as ConstraintSolverInit1. No new callers found. | ConstraintSolverInit (func ptr table) |
| 0x0044e060 | game_logic_isolated | HIGH | Writes DAT_007ccd68 = 0x44 (CollisionMagicVersion='D', docs/12) + 5 zeroed fields. Already documented in docs/17 as CollisionStateClear. No new callers found. | CollisionSystemInit (func ptr table) |
| 0x0044e600 | game_logic_isolated | HIGH | Writes DAT_007cca2c = 0x53 (CollisionContactCount=83, docs/12) + DAT_007cca40 = 9000. Last field non-zero (buffer size or timeout). Already documented in docs/17 as CollisionGlobalInit. No new callers found. | CollisionSystemInit (func ptr table) |
| 0x0044eba0 | game_logic_isolated | HIGH | Writes DAT_007ca420 = 0x62 (collision state block, docs/17) + 5 zeroed fields. Already documented in docs/17 as CollisionStateInit_62. No new callers found. | CollisionSystemInit (func ptr table) |
| 0x0046b310 | utility_isolated | HIGH | Trivial 3-instruction accessor: returns `param_1 + 0x174`. No game globals. No cross-refs. Likely an MSVC inline expansion or small virtual function (offset getter). 7 bytes total. | Inline call site (no standalone caller expected) |
| 0x004862e0 | game_logic_isolated | MEDIUM | String accessor: if `*(param_1+200) != 0` → deref `+0x48` for string ptr, fallback to `DAT_005ea438` (LoadPath, docs/12). 26 bytes. References game global DAT_005ea438 (setup directory path). Likely a virtual getter for resource path. | UI/Filesystem getter via vtable |
| 0x00499c10 | utility_isolated | HIGH | Struct copy/merge. Copies param_3[0-3], param_3[7-8] → param_1, then copies 13 elements param_1 → param_2 via loop. No game globals. Pure utility. | Inline memcpy-like call |
| 0x004f8c50 | callback | MEDIUM | Callback dispatcher. Checks `DAT_008afc84` (function pointer) — if null returns 4 (error code), else calls it and returns 0. This function IS the dispatch point for a dynamically-registered callback. Caller unknown; DAT_008afc84 setter is the registration side. | Unknown (whoever calls this dispatch wrapper) |
| 0x0050cdf9 | vtable_member | HIGH | Thunk (6 bytes) calling through `_DAT_005d785c` global function pointer. Odd address (thunk marker). Functions.json maps to "docs/19-renderer.md — matrix stack push/pop operations". Part of vtable or function ptr table. | Vtable entry at guessed offset |
| 0x0050e760 | utility_isolated | HIGH | 4-component vector × 4×3 matrix transform. Pure math: `out[i] = in[0]*mat[i] + in[1]*mat[i+4] + mat[i+12]` for i=0..3. No game globals. | Any 3D transform caller |
| 0x0051bcfc | game_logic_isolated | LOW | Render command dispatch. Reads struct at `param_1+0x188` for buffer, calls via vtable offsets `+0x19c` and `+0x1a4`. No game globals, but accesses render context struct. No direct callers found. | Renderer pipeline |
| 0x00538a90 | utility_isolated | HIGH | Bit buffer writer — variable-length coding. Writes values (5-bit, 5-bit, 4-bit) plus per-element bit patterns into packed buffer at `param_1+0x16ab`. References lookup table `UNK_005b7dec`. File format / serialization utility. No game globals. | File format serialization |
| 0x0055ef88 | utility_isolated | HIGH | 4×4 matrix multiply (row × 4×4). Pure math: outputs 4 rows of 4 elements each via dot products. No game globals. 206 bytes. | Any 3D math caller |
| 0x0057a260 | utility_isolated | HIGH | Byte field getter: returns `*(byte*)(param_1 + 0x2c) + 0x29`. 9 bytes. Trivial offset accessor. No game globals. | Inline call site |
| 0x00589d62 | entry_point | HIGH | ExitProcess import wrapper. MSVC CRT/import stub. Not game code. | Windows loader (IAT) |
| 0x0058fb90 | utility_isolated | HIGH | `_strcmp` — MSVC CRT library implementation. Not game code. | CRT/compiler-generated call |
| 0x0059865a | entry_point | HIGH | `closesocket` — Winsock import wrapper. Network library. Not game code. | Windows loader (IAT) |
| 0x00599475 | utility_isolated | HIGH | `std::basic_streambuf::_Gninc` — MSVC C++ standard library. Streambuf get-pointer-increment. Not game code. | C++ STL/compiler-generated call |
| 0x0059c7e0 | entry_point | HIGH | SEH unwind cleanup. Calls FUN_0057bc70. C++ exception handling frame. Registered by MSVC compiler. | MSVC exception handling runtime |
| 0x0059cf86 | entry_point | HIGH | SEH unwind cleanup. Calls FUN_00585f30. C++ exception handling frame. Registered by MSVC compiler. | MSVC exception handling runtime |
| 0x0059d558 | entry_point | HIGH | SEH unwind destructor. Calls `exception::~exception()`. C++ exception handling frame. Registered by MSVC compiler. | MSVC exception handling runtime |

=== FULL ENTRIES ===

<!-- target: docs/17-physics-collision.md -->
## FUN_0044c9e0 — Collision Config Init (Block 0xB)

Initializes collision system config block at DAT_007cccb0 with type 0xB.

**Key logic:**
- Sets DAT_007cccb0 = 0xB (CollisionConfigType, docs/12)
- Zeroes 4 adjacent fields (DAT_007cccb4–DAT_007cccbc)
- Sets DAT_007cccbc = 0x3f800000 (1.0f — scale factor or threshold)

**Globals:**
- `DAT_007cccb0` — CollisionConfigType (docs/12, offset 0x12-globals-reference.md)

**Reason orphaned:** Called via function pointer array during collision system init. No direct call documented because callers iterate an init table rather than calling each init function directly.

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044cf80 — Collision/Audio Init Block (Type 0x27)

Initializes a global config block at DAT_007ca480 with type 0x27.

**Key logic:**
- Sets DAT_007ca480 = 0x27 (type/magic identifier)
- Zeroes DAT_007ca484
- Sets DAT_007ca488 = 0xbf800000 (-1.0f — default extent/minimum)
- Zeroes DAT_007ca48c

**Globals:**
- `DAT_007ca480` through `_DAT_007ca48c` — config block (type=0x27, float extent=-1.0f, zeroed fields)
- NOTE: DAT_007ca480 is listed in docs/12 as AudioBufferObject but also referenced in collision context. Value 0x27 suggests a type identifier rather than a pointer.

**Reason orphaned:** Called via function pointer array during subsystem init. Same pattern as other collision/audio init functions (FUN_0044c9e0, FUN_0044d520, etc.). Triaged as "collision" but may be audio-related — globals overlap with audio system address range.

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044d520 — Collision State Init (Type 0x11)

Initializes collision state block at DAT_007ccd20 with type 0x11.

**Key logic:**
- Sets DAT_007ccd20 = 0x11 (state block type)
- Zeroes 5 adjacent fields

**Globals:**
- `DAT_007ccd20` through `_DAT_007ccd34` — collision state block

**Reason orphaned:** Called via function pointer array during collision system init.

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044dac0 — Constraint Solver Init (Count=0x2D)

Initializes constraint solver state at DAT_007cceb8 with count 0x2D (45).

**Key logic:**
- Sets DAT_007cceb8 = 0x2d (ConstraintCount = 45, docs/12)
- Zeroes 5 adjacent fields

**Globals:**
- `DAT_007cceb8` — ConstraintCount (docs/12)

**Reason orphaned:** Called via function pointer array during constraint solver init.

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044e060 — Collision State Clear (Magic=0x44)

Initializes collision state block at DAT_007ccd68 with magic/version 0x44 ('D').

**Key logic:**
- Sets DAT_007ccd68 = 0x44 (CollisionMagicVersion = 'D', docs/12)
- Zeroes 5 adjacent fields

**Globals:**
- `DAT_007ccd68` — CollisionMagicVersion (docs/12)

**Reason orphaned:** Called via function pointer array during collision system init.

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044e600 — Collision Global Init (Count=0x53, Buffer=9000)

Initializes collision system globals with contact count and buffer size.

**Key logic:**
- Sets DAT_007cca2c = 0x53 (CollisionContactCount = 83, docs/12)
- Zeroes 4 adjacent fields (DAT_007cca30–DAT_007cca3c)
- Sets DAT_007cca40 = 9000 (buffer size or timeout value)

**Globals:**
- `DAT_007cca2c` — CollisionContactCount (docs/12)
- `DAT_007cca40` — buffer size (9000)

**Reason orphaned:** Called via function pointer array during collision system init.

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044eba0 — Collision State Init (Type 0x62)

Initializes collision state block at DAT_007ca420 with type 0x62.

**Key logic:**
- Sets DAT_007ca420 = 0x62 (state block type = 98)
- Zeroes 5 adjacent fields (DAT_007ca424–DAT_007ca434)

**Globals:**
- `DAT_007ca420` through `DAT_007ca434` — collision state block (type=0x62)

**Reason orphaned:** Called via function pointer array during collision system init.

---

<!-- target: docs/19-renderer.md -->
## FUN_0051bcfc — Render Command Dispatch

Dispatches a draw command through render context function pointers.

**Key logic:**
- Reads render context from param_1
- Gets buffer object at offset +0x188
- Clamps param_7 — *param_6 against buffer capacity at *(buffer + 0x10)
- Calls vtable dispatch at *(param_1 + 0x19c) → offset +4 (draw command setup)
- Calls vtable dispatch at *(param_1 + 0x1a4) → offset +4 (draw command execute)
- Advances param_6 by param_1 (element count consumed)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x188 | DrawBuffer | int ptr to render buffer |
| +0x19c | DrawSetupFunc | vtable ptr at offset 4 — draw command setup |
| +0x1a4 | DrawExecFunc | vtable ptr at offset 4 — draw command execute |

**Calls:** Virtual calls through vtable offsets +4 on two render subsystem objects

**Moddability:** `hardcoded` — render pipeline internals

---

<!-- target: docs/20-math-utilities.md -->
## FUN_004f8c50 — Callback Dispatch via Global Function Pointer

Dispatches a call to a dynamically-registered function through DAT_008afc84.

**Key logic:**
- Checks if DAT_008afc84 (function pointer) is null
- If null: returns 4 (error code)
- If set: calls (*DAT_008afc84)(), returns 0 (success)

**Globals:**
- `DAT_008afc84` — function pointer (code*), undocumented. Set by registration side.

**Moddability:** `hookable` — the function pointer DAT_008afc84 can be replaced to intercept/extend this dispatch point.

---

<!-- target: docs/20-math-utilities.md -->
## FUN_0050e760 — 4-Component Vector × 4×3 Matrix Transform

Transforms a 4-component vector by a 4×3 (or 3×4) matrix.

**Key logic:**
- `out[0] = in[0]*mat[0] + in[1]*mat[4] + mat[12]`
- `out[1] = in[0]*mat[1] + in[1]*mat[5] + mat[13]`
- `out[2] = in[0]*mat[2] + in[1]*mat[6] + mat[14]`
- `out[3] = in[0]*mat[3] + in[1]*mat[7] + mat[15]`
- Standard 4-element vector transform with translation components at mat[12..15]

**Parameters:** param_1=output vector (float[4]), param_2=input vector (float[4]), param_3=matrix (float[16])

**Moddability:** omit — pure math utility

---

<!-- target: docs/20-math-utilities.md -->
## FUN_0055ef88 — 4×4 Matrix Multiply

Multiplies two 4×4 matrices: out = mat_a × mat_b.

**Key logic:**
- Loops 4 times (one per row of output)
- Each iteration computes 4 dot products: `out[i] = row_a · col_b`
- row_a selected from param_3[i*4 .. i*4+3]
- Full 4×4 matrix multiplication (16 multiply-adds per row)

**Parameters:** param_1=unused, param_2=unused, param_3=matrix A (float[16]), param_4=matrix B (float[16]), param_5=output matrix (float[16])

**Moddability:** omit — pure math utility

---

<!-- target: docs/06-session-race-logic.md -->
## FUN_004862e0 — UI String Path Accessor

Gets a string/resource path from an object, falling back to global LoadPath.

**Key logic:**
- Checks if `*(param_1 + 200)` (pointer field) is non-null
- If null: returns null
- If non-null: dereferences `*(*(param_1+200) + 0x48)` for string pointer
- If that is null: returns `DAT_005ea438` (LoadPath global — setup directory pointer)

**Globals:**
- `DAT_005ea438` — LoadPath / directory pointer (docs/12, setup module)

**Moddability:** `configurable` — returns DAT_005ea438 which is the user-configured load path
