# 33 — F1C Capability Bible

Canonical, evidence-grounded assessment of how deeply `F1 Challenge Online.exe`
(x86 PE32, MSVC 6.0, 2002, isiMotor1/gMotor) can be modified, what can be ported
into it, and where the hard ceilings are. Written to be fed to lower-throughput
models as ground truth.

**Evidence tiers used throughout** (per `INDEX.md`): FACT = raw `.c` / exe bytes;
CONFIRMED = NASCAR cross-match identity; DERIVED = IDA/graph CSVs; GUESS = DS-worker
offsets/labels; LEAD = call chains/semantic names (may be hallucinated).

**Confidence labels on every claim:**
- **PROVEN** — already shipped/confirmed in-repo (`mods/`, in-game tested).
- **FEASIBLE** — clear path, tooling exists, not yet done.
- **SPECULATIVE** — plausible, unverified; blockers unquantified.

**Audit status (2026-07-17, Architect pass):** every load-bearing claim independently
re-verified — cut=DQ patch bytes, VFXDrive loader bytes, and the `0x47fc54` gap head
byte-read directly from the exe; `DAT_008acfd4` writer-absence re-run via
`investigate.py`; port-table addresses + Port verdicts checked against `docs/32` and
`source_material/*/docs/40`. Two corrections applied vs the first draft: `replay-ai-fix`
is NOT a shipped patch (3 failed attempts, docs/28 BUG-001), and `red-flag-dll` in-game
injection is proven by its runtime log. See `work/CHANGELOG.md` 2026-07-17.

---

## 1. Executive summary

F1C is **wide open to modification** and there is **no anti-tamper**: the exe already
loads an unsigned custom DLL through its own `VFXDrive.dll` plugin slot
(`FUN_004f8b50`, [docs/22 §7](22-modding-reference.md)) and runs Frida-injected byte
patches, so injection is PROVEN, not theorized. Two mods are **in-game proven**:
`cut_track_dq` (3-byte call-redirect turning any track cut into instant DQ) and
`red-flag-dll` (injected DLL toggling red-flag state globals live — runtime log
`mods/red-flag-dll/red_flag_log.txt`). A third effort, `replay-ai-fix`, has **no
working patch yet** — three byte-patch attempts failed (docs/28 BUG-001) — a useful
honest data point on byte-patch limits. The realistic ceiling is not "can we change behavior" — we can, at
data / byte-patch / DLL-hook / vtable levels — but **correctness verification**: every
struct offset and global label above FACT tier is a DS-worker GUESS and must be
confirmed against raw source or an exe byte-read before shipping. The single biggest
gameplay capability the game *lacks* and could gain is a **full-course caution /
safety-car system** (portable from NASCAR Thunder 03/04, self-contained). The hard
ceilings are architectural: D3D8 is locked in, the physics solver is a monolithic
anonymous-function kernel (407 funcs, no strings, [docs/15](15-analysis-limits.md)),
there is no RTTI (`/GR-`, no class names), and any "port" between sibling builds risks
**struct-offset drift** because F1C's source root (`D:\dev\F1_1999_2002\Source\`) differs
from the Common-path builds — offsets may have moved.

---

## 2. Modification mechanisms

| Mechanism | Reach | Proven example | Hard limit |
|-----------|-------|----------------|------------|
| **Data-file** (`.svm`/`.hdv`/`.gdb`/`.tbc`/`.veh`/`.scn`/`.plr`, setup) | Every field a parser reads: engine power/thermal, damage detach thresholds, per-gear RPM, brakes, tire compounds (IDs 2–6), track-surface grip, AI dry/wet grip, weather wetness/grip multipliers, pit-window open/close, championship scoring. Parser map: [docs/16](16-moddable-fields.md), [docs/22 §3+§15](22-modding-reference.md). | Standard modding scene (F1C mod tools) — FACT: all fields confirmed present in master parser `FUN_004f4270` (8038 B). | Can only touch what a parser reads. No new logic, no new state. Unknown field names silently skipped (basis of "ghost fields", Method D). |
| **Byte-patch** (in-place, must fit original footprint) | Flip constants, force branches (NOP a `jz`), redirect a call. Address = VA − 0x400000 (no ASLR, ImageBase 0x400000). | **PROVEN, in-game confirmed:** `cut_track_dq` — 3 edits in steward routine `FUN_004bccc0` redirecting warning+stopgo penalty calls to DQ handler `FUN_004bc0e0`, incl. a `push 0xA`→NOP to fix a `ret imm` stack delta of 4 ([PLAYBOOK](../tools/mod_pipeline/MODDING_PLAYBOOK.md); original bytes at `0x004bd0aa/b3/c1` byte-read-verified 2026-07-17). **Counter-example (know the limits):** `replay-ai-fix` (BUG-001) — **3 byte-patch attempts FAILED** (grid bunching; timer delay; unconditional-enable still gated) and there is NO working patch yet ([docs/28](28-known-bugs.md), `mods/replay-ai-fix/apply_replay_ai_fix.py` header). Single-byte patches can't fix multi-gate timing interactions. | Must not grow code. Redirecting between handlers with different `ret N` arg counts needs push/pop fixup or the stack corrupts (rule 4, PLAYBOOK). On-disk patch may trip a naive AV/integrity check → fall back to Frida memory patch. |
| **Runtime memory write** (Frida, or `WriteProcessMemory` from external tool) | Any global or struct field at a known address, live. ~50 named globals with exact semantics + ~400 struct offsets documented. Includes **HUD text overlay**: write text+timer to slot array directly — no game function calls needed ([docs/40](40-hud-text-overlay.md)). | **PROVEN:** F1CLiveUI (external, `OpenProcess`+`WriteProcessMemory`) injects punctures (`0.77f` to tire condition), forces AI errors ([docs/22 §16](22-modding-reference.md)). Frida versions of every shipped mod. **HUD text** (2026-07-22): `*(uint32_t*)0x7cd204` = slot manager ptr; 8 slots × 0x5c; text `+0x3c`, timer `+0x90`; timer > 0 = shown. `mods/grid_reorder/gr21.c` is the reference implementation. | Volatile (revert on restart). Offsets are GUESS-tier until byte-read-confirmed. Multiplayer: local-only → desync. **Do NOT call `0x0045b9c0` (b9c0) from injected thread** — thiscall + callee-cleanup = crash. Pure memory write only. |
| **DLL hook/detour** (in-process, replace/add whole functions) | Everything runtime-write can do, plus per-frame logic and function replacement. Two proven injection routes: **VFXDrive.dll** (game's own 5-export plugin slot, `VFXGetTracking` = free per-frame callback, `FUN_004f8b50`); **D3D8 proxy** (local `d3d8.dll`, hook `Present`/`EndScene`/`CreateDevice`). | **PROVEN:** `mods/red-flag-dll/` — injected DLL writes red-flag state globals (`DAT_008acfd4=2` etc.) to reactivate the cut "red flag" feature. `inject.exe` + `red_flag.dll` ship; **in-game runtime log** (`red_flag_log.txt`: "DLL loaded into F1 Challenge Online.exe … RED FLAG ON") proves injection + hotkey toggle worked live. | Detouring a game function requires correct calling convention: **thiscall** (`this` in ECX, callee cleans via `ret N`). Struct offsets must be right or you deref garbage (red-flag `+0x204` waypoint caveat). |
| **Vtable patch** (swap one virtual slot) | Surgical behavioral replacement — replace one dispatch target, call original as fallback. Known vtable globals: `DAT_007cd8c0` (game command dispatch, slots +0x1c/+0x44/+0x5c), `DAT_008b8f24` (D3D wrapper). [docs/22 §8](22-modding-reference.md). | FEASIBLE — technique documented, not yet shipped as a mod. | No RTTI → slot→method mapping is manual/inferred (GUESS). Wrong slot = crash. |
| **Full subsystem replacement** (reimplement + hook) | Replace an entire subsystem via DLL (e.g. a new caution state machine driven from a per-frame hook, reading/writing game globals). | FEASIBLE (multi-week), not done. Closest: red-flag-dll drives partial session state from a hook. | Cost scales with how much game state the subsystem touches and how many GUESS offsets must be verified. Anything reading the physics kernel is months+. |

**Hard ceilings** (impossible without partial engine rewrite; [docs/15](15-analysis-limits.md)):

- **D3D8 → newer API** — renderer is 265 D3D8-bound functions; swapping the graphics
  API means reimplementing the render path. Wrappers (dgVoodoo) can *translate* D3D8 but
  not modernize the engine's own pipeline. SPECULATIVE beyond wrapper-level.
- **Physics-solver restructure** — the 407 large anonymous physics functions
  (collision SAT/GJK, rigid-body integration, LDL^T constraint solver on the
  `0x8D0000–0x8D9000` matrix workspace) reference no documented globals and no strings.
  They are decompilable but re-architecting them is "rFactor physics modding territory"
  ([docs/15](15-analysis-limits.md)) — not reachable by data/patch/hook.
- **Adding multiplayer where a subsystem is absent** — NetComm exists but is diverged;
  a brand-new netcode is a rewrite, not a port.
- **C++ class recovery** — `/GR-`, no RTTI. Class hierarchy is unrecoverable; all class
  identity is inferred from NASCAR cross-match (CONFIRMED for 29 shared source files only).

---

## 3. Portable-feature ranked table

Ranked by (gameplay value × portability cleanliness). Sources: [docs/32](32-sibling-exclusive-functions.md),
`source_material/<game>/docs/40-43`, `cross_binary/_delta/`. Addresses are in the **source**
binary unless noted. "Verdict" is the repo's Port verdict; "Real blocker" is the honest gate.

| # | Feature | Source | Key funcs (source addr) | Verdict | Real blocker | Effort |
|---|---------|--------|-------------------------|---------|--------------|--------|
| 1 | **Full-course caution / yellow / pace lap / safety-car** | NASCAR 03/04 | `0x004c9a50` (Green/Yellow flag), `0x004c9650` (Full/Quickie Caution), `0x004cb3e0` (Begin Pace Lap), `0x004d3190` (green-flag field-order gate, `raceevent.cpp`) | **drop-in** (self-contained flag state machine) | F1C has *no* full-course yellow at all → no diverged struct to fight. Blocker is wiring the state machine's outputs (AI speed cap, flag state) to F1C globals via a DLL hook. Verify AI-speed + flag-state offsets by runtime dump before shipping. | multi-week |
| 2 | **Detailed penalty / infraction detection** | NASCAR 04 | `0x004e0e10` "Accelerated Too Early / Illegally Passed / Lapped Field Multiple Times" (`steward.cpp` extended) | **merge** | F1C already has a Steward (`0x004d0110`). Do NOT drop-in — *extend* it. Must re-map vehicle telemetry offsets (speed/position deltas) from NASCAR's layout to F1C's. Compile-and-diff or runtime struct dump. | multi-week |
| 3 | **Driving School / Test Day mode** | F1 2002 | `0x0042a520` (lesson/challenge parser), `0x0042ea50` (scripted-event factory: CAMERA/VEHICLE_CONTROL/CONE_COLLISION/LapTimeEvaluate), `0x0042de40` (start/finish markers), `0x0042b490` (rewards), `0x0042e540` (`drivingschool.mas` loader), `0x0042e340` (event reaction) | **drop-in** (whole subsystem lives on F1 2002 side only) | Cleanest self-contained port: loader+parser+event factory+rewards+UI. Blocker is UI integration (menu entry) and that F1C must ship the `drivingschool.mas` content. Same compiler generation → byte-mask matched well. | multi-week |
| 4 | **Lap-timing HUD (Best/Last/Current)** | NASCAR 03 | `0x00495c60` "Best/Last/Current Lap Time" | **drop-in / reimpl** | Small, self-contained display. Easier to *reimplement* in a D3D8-proxy overlay than to port the source function. Read lap times from vehicle struct. | weekend–multi-week |
| 5 | **Replay helper data stream** | NASCAR 04 | `0x004d4bd0` (`replay.cpp`) | **merge** | Extra replay stream; F1C has replay. Diverged — offsets must match. Low urgency. | multi-week |
| 6 | **Multiplayer voting** | NASCAR 04 | `0x0046bb40` "No vote in progress / vote" | **merge** | Needs netcode hooks into F1C's NetComm (diverged). Server+client both patched. | multi-week+ |
| 7 | **Connection-speed netcode + GameSpy matchmaking** | NASCAR 04 | `0x0046caf0` (Cable/DSL/56K), `0x00465d40` `MatcherAddServer` | **merge** (not drop-in) | NetComm is diverged across all siblings; NASCAR 04's is most advanced. Merging means re-mapping packet/queue structs against F1C's (`0x008ab700` free-list, class routing by top-3-bits). GameSpy backend is dead anyway. | months |
| 8 | **Career / reputation / economy (RPG layer)** | NASCAR 04 | `0x00410f10` `career.cpp` (`Reputation/Level%d/ResearchLevel%d/Condition/CurrentCar/CurrentCost`), `0x0040C7A0`/`0x0040CAA0` awards parser/writer | **merge** (large, UI-heavy) | Bolts onto F1C championship but is deeply UI-coupled; string-keyed serialization, exact offsets TBD from callers. Not a quick win. | months / team |
| 9 | **Per-part collision/damage refinement** (F1C→others, not a port-in) | F1C already HAS | `0x004f24f0` `Part%dCollParams` | n/a (F1C's own) | Listed for completeness — F1C's damage model is *ahead* here. | n/a |
| — | SCGT rendering/scene features | SCGT (1999) | Glide/3dfx (`grAADrawLine`), old `INSTANCE=` scene fmt | **not-worth-it** | **Compiler-generation gap**: SCGT is isiMotor1's 1999 ancestor; byte-matching yields 3.0% (mostly false novels, [cross_binary](../cross_binary/_README.md)). Exclusives are Glide-era rendering useless to F1C's D3D8. Excluded from delta. | n/a |

**Drop-in vs merge, restated:** *genuine-exclusive* features (caution, driving school —
the whole subsystem lives on one side) can be hooked in without fighting F1C's own copy →
DLL drop-in feasible. *Diverged* subsystems (`htree.cpp` HAT, `NetComm.cpp`,
`hdvehicle`/`tire_manager`, `util.cpp`, `game.cpp` grid) exist on both sides with different
source roots → a "port" is a merge, and **you must verify F1C's struct offsets match the
donor's before reusing any code**. This is the crux of the whole port question.

**How to close a `merge` blocker** (the offset-drift oracle):
1. Runtime struct dump — Frida-dump the F1C struct live (`tools/trace/`, `monitor_output/`)
   and compare field positions against the donor's decompiled offsets. FACT-tier.
2. Compile-and-diff — where an assert/string names the `.cpp` and field, cross-ref both
   builds' source roots to see if the field moved.
3. Never trust a `docs/13` offset for a ported hook — it's GUESS-tier.

---

## 4. Effort tiers

| Tier | Definition | Features / changes that fit |
|------|-----------|------------------------------|
| **Weekend mod** | Data-file edit, single byte-patch, constant flip, one small hook. Verifiable in one sitting. | Any `.svm`/`.hdv`/`.gdb` field (grip, wear, fuel, damage thresholds, pit window, scoring). Cut=DQ-class call redirects. Constant flips (AI difficulty range, array caps like the 128-vehicle / 20-sort / 17-team limits — patch with care). Lap-timing overlay via D3D8 proxy (reimpl, not port). "Ghost field" `X_`-prefixed config read by a DLL. |
| **Multi-week** | Self-contained subsystem port via DLL, or a behavioral system driven from a per-frame hook, with runtime offset verification. | **Full-course caution/safety-car** (port NASCAR state machine + wire to F1C globals). **Driving School** (port F1 2002 subsystem + UI entry). **Penalty/infraction extension** (merge into F1C Steward). Adaptive AI / dynamic weather from `VFXGetTracking`. Vtable-swap behavioral mods. |
| **Months / team** | Full subsystem reimplementation or the open-source ladder. | Career/economy RPG layer. NetComm merge + modern matchmaking. Reimplementing any physics/renderer subsystem. Standalone sim core. |

---

## 5. Open-source-recreation ladder

| Stage | Reachable now? | Bottleneck |
|-------|----------------|-----------|
| **0. Mod (patch/data/hook)** | **YES — PROVEN.** Shipped mods exist. | None. This is the current frontier. |
| **1. Subsystem-by-subsystem DLL replacement** | FEASIBLE now for self-contained subsystems (caution, driving school, HUD). | Per-subsystem struct-offset verification. Labor-bound, not blocked. |
| **2. Reimplementation library** (clean-room modules that mirror documented behavior, hooked in one at a time) | FEASIBLE for well-documented, string-anchored systems (session logic, file parsers, AI decision layer — [docs/01–10](01-engine-architecture.md)). | **Correctness verification, not parallelism.** Each reimpl must match the original bit-for-bit in behavior; the only oracle is running both and diffing. |
| **3. Standalone sim core** (physics + tire + AI running without the exe) | SPECULATIVE. | The physics kernel (407 anonymous funcs, LDL^T solver) is decompilable but semantically opaque — no strings, no documented globals ([docs/15](15-analysis-limits.md)). Reproducing it correctly is the true wall. |
| **4. Wrapper exe** (original data files, new engine) | SPECULATIVE / long-horizon. | Requires stages 2+3 complete *and* a rendering path. D3D8 lock-in means either a wrapper or a full new renderer. |

**The true bottleneck across the whole ladder is correctness verification, not throughput.**
More workers do not help past stage 1 — you cannot parallelize "prove this reimplementation
behaves identically to the original." The physics kernel is the hard ceiling.

---

## 6. Risk / blocker register

| Blocker | Status | Evidence |
|---------|--------|----------|
| **Anti-tamper / DRM** | **NONE on the retail exe.** It loads an unsigned custom DLL via its own plugin slot and runs Frida patches. | `FUN_004f8b50` VFXDrive loader; shipped `red-flag-dll`; `cut_track_dq` in-game confirmed. |
| **On-disk integrity / AV** | Possible on static exe patch. Mitigation exists. | PLAYBOOK gotcha: "patched on-disk exe may be flagged … use Frida memory patch." |
| **D3D8 lock** | Hard ceiling for API modernization; wrapper-level only. | 265 renderer funcs D3D8-bound; import thunk `0x0059b250`. |
| **Compiler-generation gap** | Blocks SCGT (1999) ports; F1 2002 + NASCAR 03/04 (2002–04) match fine. | `cross_binary`: SCGT 3.0% match (false novels); masking gate passes only same-gen. |
| **Struct-offset drift between builds** | The #1 `merge`-port risk. F1C root `D:\dev\F1_1999_2002\Source\` ≠ Common-path builds. Fields may have moved. | [docs/32 "Reading nuance"](32-sibling-exclusive-functions.md); PLAYBOOK "may have moved between builds." |
| **RTTI absence (`/GR-`)** | No class names; vtable slot→method mapping is manual/GUESS. | [INDEX.md](../INDEX.md) key facts; vtable scan yields 0. |
| **Offset/global labels are GUESS-tier** | Every `docs/12` global and `docs/13` offset is DS-worker inferred; a `docs/31` chain literally mislabeled a network func as "track grip." | INDEX trust tiers; PLAYBOOK iron rule 1. Verify before every mod. |
| **Red-flag setter never existed** | The original trigger logic (`0x004a5840–0x004a5bc0`, ~896 B) was never a recognized function; no packet type writes the flag. **Runtime-confirmed:** `investigate.py global DAT_008acfd4` → only 2 refs, both *readers* (`0x004441f0` physics, `0x004a5f20` exit-pit), **zero writers**. Caveat: a writer could live in the un-decompiled `0x004a5840` region. | [mods/red-flag.md] "What is missing." Feature is re-enable-by-write only, no native trigger. |
| **55 undocumented string-less helpers** | Small analysis gap; low mod relevance. | Repo memory / gap notes. |
| **String-less anonymous mass not fully analyzed** | `decompiled_full` = 6,116 anonymous funcs (physics/math kernel); [docs/15](15-analysis-limits.md) sampled 50+ and found NO new moddable fields. Plus 852 `.text` gaps + inlined copies. Exact "unanalyzed" count is unverified — do not cite a hard number. | docs/15 "Skip decompiled_full for modding." |
| **Multiplayer desync** | Any local memory mod desyncs MP; GameSpy backend is dead. | [docs/22 §17](22-modding-reference.md). |

---

## 7. Appendix — decision tree for lower models (copy-pasteable)

Paste this block as a system-prompt fragment. It assumes the repo at
`%USERPROFILE%\Desktop\F1C_ghidra_project`.

```
GOAL: change some F1C behavior. Pick the LOWEST mechanism that reaches it.

STEP 0 — TRUST. Raw .c (analysis_pipeline/analyzed/, decompiled_all/, tools/decompiled_ida/)
and exe bytes are FACT. docs/12 globals + docs/13 offsets are GUESS. docs/31 chains are LEAD
(may be hallucinated). NEVER ship a mod on a GUESS/LEAD label — confirm in raw .c or byte-read.

STEP 1 — CLASSIFY the change:
  (a) A value the game already reads from a file (grip, wear, fuel, damage, pit window,
      scoring, AI grip, weather)?
        -> DATA-FILE mod. Read docs/16 + docs/22 §3/§15 for the field name + parser.
           Edit the .svm/.hdv/.gdb/.tbc/.veh. Done. Weekend.
  (b) A hardcoded constant / threshold / branch already in the exe?
        -> BYTE-PATCH. tools/mod_pipeline/asm_tools.py resolve <addr> --source to read it.
           Flip constant / NOP a jump / redirect a call (asm_tools.py redirect — it reports
           the ret-N STACK DELTA; if delta != 0 you MUST NOP the matching push). Patch a COPY,
           verify original bytes first, test with Frida before baking. Weekend.
  (c) A live global/struct field with no file field?
        -> RUNTIME WRITE. Find the global in docs/22 §11 (verify addr by byte-read).
           Write via Frida or a DLL. Volatile. Weekend.
  (d) New per-frame logic, or replace a whole function?
        -> DLL HOOK. Inject via VFXDrive.dll (5 exports; VFXGetTracking = per-frame tick,
           docs/22 §7) or a d3d8.dll proxy (docs/22 §6). thiscall = this in ECX, callee cleans
           via ret N. Multi-week.
  (e) Add a feature F1C lacks that another isiMotor1 game has?
        -> PORT. Check docs/32 + source_material/<game>/docs/40-43 for the Port verdict:
             drop-in  = self-contained, F1C lacks the whole subsystem (caution, driving school)
                        -> hook it in via DLL; verify only the OUTPUT offsets it writes.
             merge    = F1C has a diverged version (penalty, netcomm, HAT, tire)
                        -> extend F1C's version; you MUST re-map struct offsets. Verify by
                           runtime struct dump (tools/trace/) — NOT by trusting docs/13.
             no       = engine-generic or SCGT-1999 -> don't.
           Multi-week to months.

STEP 2 — VERIFY. Predict the exact observable ("cut a corner -> instant DQ"). Test in-game.
A failed prediction usually means a doc oversimplification -> reread raw .c, correct the doc.

HARD CEILINGS (don't attempt without a rewrite): D3D8->newer API; physics-solver internals
(407 anonymous funcs, no strings); new-from-scratch multiplayer; C++ class recovery (no RTTI).

KEY FACTS: ImageBase 0x400000, no ASLR (VA == file VA). File offset = VA - 0x400000.
MSVC 6.0 /GR-. Exe: "%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe".
No anti-tamper — custom DLLs and patches load fine.
```

---

## 8. What cannot be reached / modified — and how sure we are

The honest question is not "what's impossible" but "impossible vs merely expensive, and
did we *confirm* it or *assume* it." Very little is truly impossible; most "can't" is
labor-bound. Four classes:

- **ARCHITECTURAL** — impossible without an engine rewrite. Structural fact, not testable away.
- **INFO-UNRECOVERABLE** — the information was stripped at compile time; you can't *know* it
  statically, but can often brute-force around it at runtime.
- **LABOR-BOUND** — doable, just expensive. **Not a ceiling.** Cost, not a wall.
- **ABSENT** — the thing doesn't exist in the binary, so there's nothing to hook.

**Confirmation status** is explicit per row: CONFIRMED (a check was run — cited),
UNVERIFIED (asserted from docs, not tested), or STRUCTURAL (true by construction).

| Item | Class | Impossible? | Confirmation method | Status |
|------|-------|-------------|---------------------|--------|
| **D3D8 → newer graphics API** (engine's own render pipeline) | Architectural | Yes (rewrite). Wrapper-level translation (dgVoodoo) only. | Engine calls D3D8 directly; 265 funcs bound; import thunk `0x0059b250`. Not a thing you test away. | STRUCTURAL |
| **Re-thread the tick loop** (physics+AI share one 864 Hz thread) | Architectural | Yes (rewrite). Can hook the tick, can't parallelize it. | Frida trace: physics+AI ~864 Hz same thread (`monitor_output/`). | CONFIRMED |
| **Change the C++ ABI / class field layout** | Architectural | Yes — layout is baked into every access site. | thiscall/`ret N`; offsets hard-compiled. | STRUCTURAL |
| **Byte-patch that grows code in place** | Architectural (of that *mechanism*) | Yes for byte-patch — can't add bytes. **But a DLL can add logic.** So it's a mechanism limit, not an absolute one. | PLAYBOOK iron rule 4 (footprint). | STRUCTURAL |
| **Know the C++ class hierarchy** (`/GR-`, no RTTI) | Info-unrecoverable | Can't *know* statically. Can rebuild at runtime (trace vtable ptrs / indirect calls). | `ida_vtables.csv` = header only, **0 rows** — scan genuinely empty. Runtime recovery not yet run. | CONFIRMED (absence); recovery UNVERIFIED |
| **Physics/dynamics solver semantics** (407 anon funcs, LDL^T on `0x8D0000–0x8D9000`) | Labor-bound | **No** — decompilable, just semantically opaque (huge RE cost). | [docs/15](15-analysis-limits.md) sampled 50+: no documented globals, no strings. That proves *cost*, not impossibility. | CONFIRMED (opacity); solvability UNVERIFIED |
| **Weather simulation math** | Labor-bound | No — in the anonymous mass, unanchored. | docs/15 #4: string scan found `weather.cpp` funcs but not the math. | UNVERIFIED |
| **Derived values w/ no setter** (`DAT_005ea3d8` track ref speed) | Labor-bound | No — computed in an anon session-init func. | docs/15 #6: "not recoverable without deeper anonymous analysis." | UNVERIFIED |
| **`0x0047fc54` "23 KB gap"** (23,436 B) | Labor-bound | **No — CORRECTION: region head is CODE, not a data table** (contradicts docs/23 GAP 19 "data_table"). Recoverable by manual `MakeFunction`. | Byte-read 2026-07-17: at `0x47fc54+0x12`: `8b442404 56 6a7f 8db10c210000 50 56 c60600 e8…(memset) 83c40c c6467f00 5e c20400` = complete thiscall buffer-clear fn (`memset(this+0x210C, 0, 0x7F)`, `ret 4`). First 0x12 bytes are tail of prior code. Whole-region composition (code vs interleaved data) still unknown — only the head is confirmed. | CONFIRMED (head is code); full region UNVERIFIED |
| **852 `.text` gaps** | Labor-bound | No — classify by disassembly. | `ida_gaps.csv`. Not individually triaged. | UNVERIFIED |
| **Inlined functions** | Labor-bound | "Can't *detour*" = true (no single entry). "Can't *mod*" = **false** — patch every inline copy. | Structural (MSVC inlining). Duplicate-byte-sequence scan not yet run to enumerate them. | STRUCTURAL (no entry); count UNVERIFIED |
| **String-less anonymous mass** (`decompiled_full` = 6,116 physics/math funcs) | Labor-bound | No — analyzable; low mod value. | docs/15: 50+ sampled, no new moddable fields. Exact unanalyzed count unverified — cite no hard number. | UNVERIFIED |
| **Red-flag native trigger/setter** | Absent | Nothing to hook — no code sets the flag. | `investigate.py global DAT_008acfd4` → 2 refs, both readers (`0x004441f0`, `0x004a5f20`), **0 writers**. Caveat: could hide in un-decompiled `0x004a5840`. | CONFIRMED (absent from recovered code) |
| **GameSpy matchmaking backend** | Absent (external) | Netcode is reachable; the backend servers are dead/gone. | External fact; `0x00465d40 MatcherAddServer` present but points at dead infra. | STRUCTURAL |

### The one-line rule

Only the **architectural** items are true hard-impossibles (D3D8 pipeline, threading model,
C++ ABI). **INFO-UNRECOVERABLE** (class hierarchy) blocks *knowing* but not *doing* — brute-force
it at runtime. Everything tagged **LABOR-BOUND** (the solver, gaps, inlines, `0x47fc54`) is
money/time, **not a ceiling** — do not document these as "impossible." **ABSENT** things
(red-flag trigger) have nothing to intercept; you add the behavior, you don't hook it.

### Cheap confirmations still owed (to move UNVERIFIED → CONFIRMED)

- Inlined-function enumeration: scan for identical byte-sequences at ≥2 addresses.
- Runtime writer-trace on any "absent trigger" global (memory watchpoint) to confirm
  no writer exists *at runtime*, closing the un-decompiled-region caveat.
- Runtime vtable/RTTI recovery: trace `call [reg+N]` sites to rebuild the class map the
  static scan (0 rows) could not.

---

*Grounded in: [INDEX.md](../INDEX.md), [MANIFEST.md](../MANIFEST.md), [docs/15](15-analysis-limits.md),
[docs/16](16-moddable-fields.md), [docs/22](22-modding-reference.md), [docs/32](32-sibling-exclusive-functions.md),
[tools/mod_pipeline/MODDING_PLAYBOOK.md](../tools/mod_pipeline/MODDING_PLAYBOOK.md),
[mods/red-flag.md](../mods/red-flag.md), [mods/_README.md](../mods/_README.md),
[cross_binary/_README.md](../cross_binary/_README.md),
`source_material/Nascar Thunder 2004/docs/40-gameplay.md`.*
