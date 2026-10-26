# F1C replacement-engine reconstruction orchestrator runbook

This runbook onboards an advanced LLM without conversation history. It begins
at the completed static-recovery milestone and ends with the acceptance gates
for a plug-compatible replacement executable.

Work from the repository root:

```text
%USERPROFILE%\Desktop\f1c_ida_decompiled
```

## 1. Mission

Build a clean, isolated replacement executable that can use an existing F1
Challenge installation and give the project source-level control over engine
features. Preserve the original executable and production mods throughout
development.

The project does not possess the original source text. It has a complete
evidence-linked semantic map of the eligible static function corpus. Use that
map as an investigation index and specification input. Promote a claim into the
replacement engine only after stronger evidence establishes its contract.

The intended final executable must:

- resolve an existing installation without rewriting it;
- honor legacy configuration, path precedence, archives, assets and saves;
- reproduce required platform, content, session and simulation behavior;
- expose coherent source modules that the user can rewrite;
- build and test from documented commands;
- refuse unsupported compatibility assumptions instead of corrupting data.

## 2. Current milestone

Static breadth recovery finished on 2026-08-06.

- Static corpus: 7,132 functions.
- Validated function IR: 7,132 files.
- Generated C++ semantic maps: 7,132 files.
- Wave 8 function report: 322 valid, 0 invalid, 0 missing.
- Wave 8 architecture report: 8 valid, 0 invalid, 0 missing.
- Static function coverage remaining: 0.
- Shadow-source, architecture and reconciliation tests pass.
- Replacement-engine CTest passes.
- The replacement executable currently handles install-root resolution,
  command-line parsing, `Config.ini`, content inventory and logging. It does
  not run a simulation or renderer.

Read these files in order before changing anything:

1. `shadow_source/AGENTS.md`
2. `shadow_source/RECONSTRUCTION_ORCHESTRATOR_RUNBOOK.md`
3. `shadow_source/architecture/CURRENT_SCOPE.md`
4. `shadow_source/architecture/WAVE_008_SUMMARY.md`
5. `replacement_engine/README.md`
6. `tools/sdk/README.md`
7. `tools/sdk/RECONSTRUCTION_WORKFLOW.md`
8. `tools/sdk/LARGE_MOD_AUTOMATION.md`
9. `tools/sdk/SEMANTIC_MEMORY_LINKER.md`
10. `tools/sdk/VARIANT_RESOLUTION.md`

Use `shadow_source/LLM_CONTINUATION_RUNBOOK.md` to audit the completed wave
pipeline. Its sections that call Wave 2 the current operation describe history.
Do not restart that work.

## 3. Meaning of the existing artifacts

The validator's `VALID` status means the worker returned schema-correct output,
cited material from its bounded packet, covered required facts and obeyed the
trust rules. It does not establish these claims:

- Hex-Rays recovered the original control flow without artifacts.
- A proposed function name matches the original name.
- An inferred class owner, field type or object boundary is correct.
- A function signature uses the right calling convention or stack cleanup.
- An isolated state write or internal call preserves game lifecycle rules.
- Generated pseudocode behaves like the original executable.

The files under `shadow_source/functions/` are semantic C++ maps. They are not
drop-in implementations. Do not copy all 7,132 files into the replacement
engine and call the result recovered source.

### Trust ladder

Use these levels in contracts, reports and code comments:

| Level | Meaning | Permitted use |
|---|---|---|
| `RAW` | Direct decompiler, disassembly, PE, string or shipped-data evidence | Cite as evidence; review decompiler artifacts |
| `STATIC_DERIVED` | One evidence-linked interpretation that passed structural validation | Plan investigations; do not freeze ABI |
| `RECONCILED` | Independent candidates agree or an adjudicator resolved the dispute from stronger static evidence | Draft a contract with unresolved items |
| `ABI_REVIEWED` | Calling convention, parameters, owner, stack behavior and thread requirement were reviewed | Expose behind reviewed wrappers |
| `OBSERVED` | Repeatable runtime observation supports identity or state behavior | Add behavioral constraints; writes still need causal proof |
| `DIFFERENTIAL_CONFIRMED` | Original and replacement pass the same controlled scenario and comparison gate | Use as replacement acceptance evidence |
| `IMPLEMENTED` | Code compiles and passes its declared tests | Integrate only within its dependency-closed slice |

No worker may promote its own proposal. A validator checks form and evidence.
The orchestrator promotes a contract after reconciliation and the required
gates.

## 4. Non-negotiable operating rules

1. Keep production mods, prototypes and the original executable outside this
   work. Store investigation output under `shadow_source/` and clean replacement
   code under `replacement_engine/`.
2. Preserve the dirty worktree. The repository contains extensive user work.
   Do not reset, clean, overwrite or reformat unrelated files.
3. Keep `functions/`, `skeleton_facts_all.json`, `callgraph.json`,
   `analysis/recovery_index.json` and reviewed SDK facts immutable during
   inference. New evidence goes through reviewed override or contract paths.
4. Do not create Wave 9. Static breadth coverage is complete.
   reasoning. Do not substitute v4-pro.
   owns at most 48 slots and leaves two slots for supervision or a probe.
7. Launch hidden, non-interactive PowerShell wrappers. Each wrapper must close
   after its worker exits and retain stdout/stderr.
8. Freeze a manifest after its first worker starts. Repairs create a new
   attempt directory and preserve rejected candidates.
9. Give workers disjoint output paths. Workers must not edit shared contracts,
   accepted headers, CMake files or production code in parallel.
10. Keep default runtime work read-only. An experiment that writes process
    memory, installs a hook, stages a DLL or changes an installation requires
    a scoped user request and a rollback plan.
11. Do not expose credentials. Follow the guarded rotation procedure in the
    historical runbook only after logs confirm quota or authentication failure.
12. Never weaken a validator to accept one worker result. Fix the candidate,
    the packet or a validator bug demonstrated with a synthetic test.

## 5. Verify the cold-start baseline

Run these existing commands before building the new reconstruction layer:

```powershell
$ir = @(Get-ChildItem shadow_source\ir\functions -Filter *.json -File)
$maps = @(Get-ChildItem shadow_source\functions -Filter *.cpp -File)
"IR=$($ir.Count) MAPS=$($maps.Count)"

$f = Get-Content shadow_source\reports\wave_008_validation.json -Raw |
  ConvertFrom-Json
$a = Get-Content shadow_source\reports\architecture_wave_008_validation.json -Raw |
  ConvertFrom-Json
$f.summary
$a.summary

python tools\sdk\tests\test_shadow_source.py
python tools\sdk\tests\test_shadow_architecture.py
python tools\sdk\tests\test_shadow_reconcile.py
& 'C:\Program Files\CMake\bin\ctest.exe' `
  --test-dir replacement_engine\build --output-on-failure

git status --short
```

Expected results:

- `IR=7132 MAPS=7132`
- both Wave 8 reports show zero invalid and zero missing;
- all three Python gates pass;
- CTest reports one passing bootstrap test;
- `git status` shows a dirty tree. Preserve it.

Check for stale workers before launching new jobs:

```powershell
Get-CimInstance Win32_Process |
  Where-Object {
    $_.CommandLine -match 'shadow_.*supervisor.py'
  } |
  Select-Object ProcessId, Name, CommandLine
```

Resolve exact command lines before stopping or starting anything.

## 6. Work that remains

Complete function coverage solved navigation and bounded semantic extraction.
The replacement engine still needs eight kinds of reconstruction work:

1. Resolve incompatible function, class, type and subsystem proposals.
2. Recover exact calling conventions, vtables, layouts, field widths and object
   lifetime rules.
3. Connect globals, registries, singletons and state machines across functions.
4. Define subsystem ownership and update order.
5. Separate game logic from Windows, DirectX, Miles audio, networking, compiler
   runtime and other external boundaries.
6. Convert accepted contracts into compilable headers and implementations.
7. Reconstruct startup, content loading, session construction and frame order.
8. Prove compatibility with tests, traces and controlled differential runs.

Runtime validation contributes to items 2, 3, 7 and 8. Static reconciliation,
ABI review, implementation and build integration remain separate workstreams.

## 7. Reconstruction artifact model

Create this tree during Phase R0. It does not exist at this milestone:

```text
shadow_source/reconstruction/
  schemas/
  manifests/
  packets/
  prompts/
  launchers/
  logs/
  candidates/
  reconciled/
  contracts/
  code_candidates/
  reports/
  rejected/
  status/
```

Use the directories as follows:

- `manifests/`: immutable work lists with exact inputs, outputs and hashes.
- `packets/`: bounded evidence copied or referenced from authoritative inputs.
- `candidates/`: independent worker proposals. A candidate never becomes a
  contract through a rename or move.
- `reconciled/`: adjudicated proposals with agreement and dispute records.
- `contracts/`: orchestrator-promoted interfaces that passed required gates.
- `code_candidates/`: generated code and patches that have not entered the
  replacement engine.
- `reports/`: deterministic validation, coverage, comparison and build reports.
- `rejected/`: immutable failed attempts grouped by manifest and attempt.
- `status/`: current phase, accepted dependencies, blockers and next frontier.

Store accepted implementation code under `replacement_engine/`. Keep generated
worker code in `code_candidates/` until the orchestrator checks the contract,
diff, build and tests.

### Contract record

Each promoted contract needs these fields. Implement the schema in R0 rather
than relying on prose:

```json
{
  "schema_version": 1,
  "contract_id": "content.archive.mas_index.v1",
  "subsystem": "content",
  "kind": "interface",
  "status": "RECONCILED",
  "source_functions": ["0x00000000"],
  "signature": {
    "calling_convention": "unknown",
    "return_type": "opaque",
    "parameters": []
  },
  "layouts": [],
  "globals": [],
  "preconditions": [],
  "postconditions": [],
  "side_effects": [],
  "thread_requirement": "unknown",
  "lifecycle": [],
  "external_dependencies": [],
  "evidence_refs": [],
  "candidate_refs": [],
  "disputes": [],
  "unresolved": [],
  "tests_required": [],
  "dependencies": []
}
```

Use an opaque type or handle when evidence does not support a concrete type.
Never fill a field to make generated C++ look finished.

## 8. DeepSeek worker protocol

### 8.1 Work-unit size

Package functions by lifecycle and dependency cohesion. Do not return to blind
address ranges.

- Target 20 to 80 related functions per architecture packet.
- Keep attached packet material below 100,000 bytes unless a test establishes a
  larger safe bound.
- Split strongly connected components only when the packet records the cut
  edges and required neighboring contracts.
- Put one large contract packet in one worker task.
- Combine up to three small, independent packets in one task.

### 8.2 Independent roles

Use separate output paths for these roles:

1. **Candidate recovery:** three workers propose a contract for ambiguous or
   high-impact packets. One candidate can cover a pure helper with direct raw
   evidence.
2. **Reconciliation:** one worker compares candidates against the packet. It
   records agreements and disputes. It cannot invent a compromise.
3. **Static reviewer:** one worker checks the reconciled result against callers,
   callees, raw C, isolated disassembly and neighboring contracts.
4. **Implementation candidate:** one worker writes code against promoted
   contracts into `code_candidates/`.
5. **Test candidate:** a different worker proposes fixtures, invariants and
   failure tests. The orchestrator checks that the tests exercise the contract.

Critical ABI, ownership, allocator, state-machine and frame-order contracts
require three candidates plus static review. Small pure functions can use one
candidate and deterministic tests.

### 8.3 Prompt rules

Every prompt must tell the worker:

- which files it may read and the one output path it may write;
- the exact schema and evidence-reference grammar;
- the trust ladder and current maximum permitted status;
- the functions and dependency edges it must account for;
- that raw Hex-Rays C outranks translated prose;
- that same-offset and same-`this` similarities do not prove ownership;
- that unresolved ambiguity belongs in `unresolved` or `disputes`;
- that it must run the named validator before exiting;
- that it may not edit accepted contracts or replacement-engine code.

### 8.4 Scheduler rules

Reuse the proven bounded-scheduler design from `tools/shadow_source.py` and
`tools/shadow_architecture.py`. Do not copy launcher logic by hand into hundreds
of scripts.

- Variant: `xhigh`
- Managed slots: 48
- PowerShell: hidden, non-interactive, auto-closing
- Logs: one stdout and one stderr file per task
- Repairs: one failed packet per task

Before launch, query exact command lines and refuse a duplicate manifest or
supervisor. Run a 12-packet pilot before opening all 48 slots for a new phase.

## 9. Deterministic gates

Workers supply hypotheses and code candidates. Python validators and compilers
decide whether the artifacts can advance.

Build these gates in Phase R0:

| Gate | Checks | Failure action |
|---|---|---|
| Schema | Required fields, enums, IDs and output path | Reject candidate |
| Evidence | Referenced functions, offsets, globals and strings exist in packet | Reject candidate |
| Coverage | Each manifest function has one declared role | Reject or split packet |
| ABI consistency | Calling convention, stack cleanup, parameter use and callers agree | Record dispute; block ABI promotion |
| Layout consistency | Field width, offset, alignment and overlap remain compatible across methods | Record type dispute |
| Global consistency | One canonical global identity maps to compatible widths and uses | Block dependent contracts |
| Lifecycle | Constructors, update paths, transitions and cleanup have declared ownership | Block implementation |
| Dependency closure | Every required contract is promoted or declared external/opaque | Block slice build |
| External boundary | Imported or library behavior has a replacement/wrapper decision | Block link integration |
| Symbol uniqueness | Public names, contract IDs and generated symbols do not collide | Reject generation |
| Compile | 32-bit C++20 build passes warnings and link | Reject code candidate |
| Tests | Unit, fixture, invariant and declared differential tests pass | Reject promotion |
| Isolation | Changed paths stay under approved reconstruction/replacement roots | Stop and inspect |

Validator error messages must identify the contract, evidence reference and
failed invariant. Do not return a generic invalid result.

## 10. End-to-end phases

### Phase R0: Build the reconstruction pipeline

No reconstruction orchestrator exists yet. Build and test it before launching
a large batch.

Create:

```text
tools/reconstruction_pipeline.py
tools/reconstruction_supervisor.py
tools/sdk/tests/test_reconstruction_pipeline.py
shadow_source/reconstruction/schemas/contract.schema.json
shadow_source/reconstruction/status/CURRENT_RECONSTRUCTION_SCOPE.md
```

`reconstruction_pipeline.py` should expose these subcommands:

```text
index               build canonical dependency/subsystem input
plan                select a dependency-closed frontier
packets             create bounded evidence packets
launchers           generate hidden bounded workers
validate-candidates validate schema, evidence and coverage
reconcile           prepare or validate reconciliation work
promote             copy a gated reconciled record into contracts
generate            create code candidates from promoted contracts
validate-code       run symbol, dependency, compile and test gates
status              print compact machine-readable progress
```

`reconstruction_supervisor.py` should wait for one immutable manifest, validate
results, archive rejected attempts and launch one-packet repairs. It must stop
at a promotion decision. It must not promote a disputed contract or write into
the replacement engine.

Use synthetic fixtures for every validator rule. Test duplicate symbols,
unsupported evidence, offset-width conflicts, missing cleanup paths, dependency
cycles and a valid minimal contract. Run the pilot with no more than 12 packets.

**R0 exit gate:** tool tests pass; the scheduler proves the 50-process ceiling;
fixtures demonstrate reject and accept paths; no production or evidence input
changed.

### Phase R1: Build the canonical reconstruction index

Join these existing inputs without changing them:

- `shadow_source/ir/functions/`
- `shadow_source/ir/architecture/`
- reconciliation comparison reports in `shadow_source/reports/`
- `functions/` raw Hex-Rays C
- `callgraph.json`
- `skeleton_facts_all.json`
- `analysis/recovery_index.json`
- `analysis/semantic_memory_index.json` when present
- reviewed facts in `tools/sdk/`
- imports, strings and PE metadata already indexed in the repository

The generated index must record function nodes, call edges, globals, field
accesses, candidate owners, confidence, lifecycle hints, imported functions,
strings and current reviewed SDK joins. Compute strongly connected components
and record every cut edge used to form a packet.

Assign every function to one of these dispositions:

- replacement-owned logic;
- external library or operating-system wrapper;
- compiler/runtime support;
- compatibility stub;
- unresolved residual.

Rank work using path-to-slice, callgraph centrality, reviewed-SDK overlap,
confidence gaps, lifecycle risk and side-effect risk. A low address must not win
priority solely because it comes first.

**R1 exit gate:** all 7,132 functions have one disposition and one packet or an
explicit residual reason; packet coverage has no duplicates or omissions;
dependency edges resolve to packet IDs.

### Phase R2: Recover contracts for the first vertical slice

Start with content/bootstrap because the existing executable already resolves
the installation, parses configuration and inventories files. Recover these
boundaries next:

1. legacy path precedence;
2. MAS/archive open, index and lookup;
3. content registration and duplicate precedence;
4. session-lifecycle construction inputs.

Use existing search and inspection commands to seed packets:

```powershell
python tools\f1c_mod.py search "MAS" --corpus raw --json `
  --output shadow_source\reconstruction\reports\mas_raw_search.json
python tools\f1c_mod.py search "archive" --corpus raw --json `
  --output shadow_source\reconstruction\reports\archive_raw_search.json
python tools\f1c_mod.py inspect <address-or-name> --full
python tools\query_recovery_index.py <address-or-name> --depth 2
```

Use `tools/f1c_mod.py ida-prepare` only when you need an isolated IDB with
reviewed types. Do not edit the primary IDB to make a candidate easier to read.

Recover function ABIs, structures, globals, ownership, lifecycle and external
dependencies as separate contract kinds. Reconcile three candidates for any
contract that crosses allocation, ownership, state or ABI boundaries.

**R2 exit gate:** the content/bootstrap slice has promoted contracts, explicit
unresolved items and dependency closure. No high-risk ABI dispute can remain on
the implementation path.

### Phase R3: Reconcile engine-wide types, globals and lifecycle

Build canonical registries for:

- types, inheritance and vtables;
- field offsets, widths and trust;
- function ABIs and thread requirements;
- globals, arrays, registries and singleton lifetimes;
- state machines and transition ownership;
- allocators, destructors and cleanup order;
- external imports and wrapper policy.

Resolve conflicts from callers, constructors, destructors, direct field uses,
stack behavior and raw disassembly. Keep an opaque boundary when evidence
cannot distinguish two layouts. Record the blocked downstream contracts.

Use `tools/sdk/f1c_sdk_overrides.json` only for reviewed facts that belong in
the public SDK. Do not put broad reconstruction guesses into the canonical SDK.

**R3 exit gate:** the first slice has consistent type, global, ABI and lifecycle
registries; every dependency either points to a promoted contract or an
explicit external/opaque boundary.

### Phase R4: Implement content/bootstrap

Generate implementation candidates against promoted contracts. Workers write
only under `shadow_source/reconstruction/code_candidates/`. The orchestrator
reviews and applies accepted patches to `replacement_engine/`.

Implement in this order:

1. legacy path resolution and precedence;
2. MAS/archive indexing and stream access;
3. content registry and duplicate handling;
4. session input assembly without simulation;
5. error reporting and clean shutdown.

Add unit tests for path precedence, malformed archives, duplicate content,
missing files, case handling and deterministic inventory order. Use synthetic
fixtures or user-owned installation data outside source control. Do not bundle
copyrighted game assets into tests.

Build with the existing 32-bit toolchain:

```powershell
cmake -S replacement_engine -B replacement_engine\build `
  -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug `
  -DCMAKE_CXX_COMPILER=C:/msys64/mingw32/bin/g++.exe
cmake --build replacement_engine\build --parallel
ctest --test-dir replacement_engine\build --output-on-failure
```

**R4 exit gate:** the executable inventories and opens content through the new
registry, all declared contract tests pass, malformed inputs fail closed and
the original installation remains unchanged.

### Phase R5: Build vertical slices in dependency order

Repeat the R2 to R4 contract, reconcile, implement and test loop for each slice:

1. **Platform shell:** window creation, timing, input dispatch, filesystem and
   error handling.
2. **Session shell:** game-state transitions, options, rules and lifecycle
   without world simulation.
3. **Track/world load:** track resources, AIW data, scene/world ownership and
   unload.
4. **Vehicle creation:** definitions, physics objects, controls, damage state
   and deterministic destruction.
5. **One simulation tick:** update order, fixed/variable timing, vehicle
   physics, collision and output state.
6. **Race systems:** grid/start, timing/scoring, race control, AI, pits, safety
   car and penalties.
7. **Presentation:** rendering, cameras, UI, audio and input feedback.
8. **Compatibility:** saves, replays, plugins, networking and command-line
   behavior required by the target use case.

Do not implement all functions one by one. Implement coherent behavior behind
contracts. Keep compiler helpers, library routines and inert stubs classified
without recreating them when the toolchain or wrapper already supplies the
behavior.

**Per-slice exit gate:** contract dependency closure, clean 32-bit build, unit
and fixture tests, lifecycle cleanup tests, no unresolved high-risk dispute and
an updated milestone report.

### Phase R6: Runtime and differential corroboration

Use the original executable as a behavioral oracle in controlled scenarios.
Start with passive observation and natural game transitions.

Existing tools include:

```powershell
python tools\f1c_mod.py runtime-observe <semantic> <tag> --seconds 300 --hz 5
python tools\f1c_mod.py runtime-validate <semantic> <observation-directory>
python tools\trace_sdk_vehicle.py --help
python tools\compare_event_traces.py --help
python tools\compare_vehicle_snapshots.py --help
python tools\f1c_mod.py memory-build
python tools\f1c_mod.py memory-correlate <event> --control <control-event>
```

For each scenario:

1. Write a scenario manifest with setup, inputs, capture rate, expected events
   and tolerances.
2. Capture at least two original runs plus a same-duration control.
3. Capture the replacement with the same inputs.
4. Compare state transitions, outputs, timing ranges and cleanup.
5. Attach the report to the contract.
6. Promote to `DIFFERENTIAL_CONFIRMED` only when the declared gate passes.

Separate identity proof from write safety. A field that tracks a lap counter
can still be unsafe to write. Recover the game-owned command or transition path
before exposing behavior-changing APIs.

**R6 exit gate:** each implemented slice has repeatable traces or fixtures for
its observable behavior, declared tolerances and retained failures.

### Phase R7: Integration and compatibility hardening

Test the assembled engine against a matrix of installation and content cases:

- clean and modded installations;
- missing or malformed configuration;
- loose-file and archive precedence;
- track and vehicle load/unload cycles;
- repeated session creation and shutdown;
- save/replay compatibility required by scope;
- renderer/audio/input loss and recovery;
- deterministic headless or replayable simulation checks where possible.

Keep deployment separate from build. Stage the replacement executable into a
dedicated test copy or user-approved staging directory. Do not overwrite the
original executable during reconstruction.

**R7 exit gate:** reproducible build, complete test matrix, no high-risk open
contract disputes on exercised paths, documented unsupported features and a
manual release checklist.

### Phase R8: Completion audit

Call the replacement engine complete for its declared scope only when:

- every static function has a recorded disposition;
- every exercised subsystem has promoted contracts and dependency closure;
- accepted layouts and ABIs pass consistency checks;
- all vertical slices build and pass tests from a clean build directory;
- differential scenarios meet their declared tolerances;
- shutdown, unload and repeated-session tests pass;
- configuration, content and compatibility behavior match declared scope;
- reports distinguish static hypotheses from observed behavior;
- source and build instructions let a cold operator reproduce the result;
- the user approves any final installation swap.

Full one-to-one implementation of 7,132 functions is not a completion
requirement. External libraries, compiler support and inert stubs need a correct
disposition and compatible behavior.

## 11. Daily orchestration loop

Follow this sequence for each manifest:

1. Read `status/CURRENT_RECONSTRUCTION_SCOPE.md` and the latest milestone.
2. Check exact process command lines and prior reports.
3. Re-run deterministic validation on accepted inputs.
4. Select the next dependency-closed frontier.
5. Freeze the manifest and packet hashes.
6. Generate hidden bounded launchers.
7. Start one scheduler and one supervisor after a duplicate-process check.
8. Monitor compact valid/invalid/missing counts and log timestamps.
9. Archive failures and run one-packet repairs.
10. Reconcile independent candidates.
11. Stop at disputes that lack stronger evidence.
12. Promote contracts through the deterministic promotion gate.
13. Generate code candidates into isolated paths.
14. Review the diff, apply accepted code and run build/tests.
15. Run declared static, fixture or differential checks.
16. Update scope, milestone, rejected-attempt index and next frontier.

Do not launch downstream implementation while an upstream contract remains
unpromoted.

## 12. Monitoring and failure recovery

report and process state before classifying failure.

For a stalled worker:

1. Match the exact manifest/task from its command line.
2. Check output existence, log modification time and CPU change.
3. Preserve partial output and logs.
4. If all expected outputs exist and logs have stopped for at least ten minutes,
5. If output remains incomplete and logs have stopped for at least twenty
   minutes, stop only that exact process and let validation schedule a repair.

Rotate credentials only after logs identify quota or authentication failure.
Follow the helper and rollback procedure in
`shadow_source/LLM_CONTINUATION_RUNBOOK.md`. A timeout without an authentication
message can indicate a service stall; preserve work and retry before changing
credentials.

When the same blocker repeats across three supervision turns and safe retries
cannot advance the manifest, stop launching work, record the blocker and ask
the user for the missing decision or external-state change.

## 13. Status and milestone records

Maintain these records once R0 creates them:

- `status/CURRENT_RECONSTRUCTION_SCOPE.md`: exact counts by trust level,
  subsystem, contract state and implementation state.
- `status/NEXT_FRONTIER.json`: dependency-closed candidate work with ranking
  reasons.
- `MILESTONE_NNN_SUMMARY.md`: inputs, contracts, disputes, code, tests,
  differential evidence and next slice.
- `reports/contract_coverage.json`: every function disposition and contract
  join.
- `reports/dependency_closure.json`: unresolved upstream dependencies.
- `reports/build_and_test.json`: toolchain, targets and results.

State `VALID means evidence-grounded, not behaviorally confirmed` in each
static milestone. Report runtime status with the exact observation or
differential level.

## 14. First actions for the next orchestrator

Execute these actions in order:

1. Run the cold-start baseline in Section 5.
2. Confirm no recovery worker or supervisor remains active.
3. Create the R0 directories, schemas, pipeline CLI and synthetic validator
   tests. Do not launch DeepSeek during the first implementation pass.
4. Build the canonical R1 index and prove 7,132-function disposition coverage.
5. Generate a 12-packet content/bootstrap pilot manifest.
6. Generate three independent contract candidates for high-impact packets with
   DeepSeek Flash/xhigh.
7. Validate and reconcile the pilot. Fix tooling bugs with synthetic tests;
   preserve worker failures.
8. Promote dependency-closed content contracts.
9. Generate code candidates and tests under reconstruction paths.
10. Apply reviewed code to `replacement_engine/`, build 32-bit and run CTest.
11. Update reconstruction scope and create Milestone 001.
12. Expand to 48 managed worker slots only after the pilot passes every R0 gate.

The first useful implementation milestone is a replacement executable that
resolves legacy paths, indexes MAS archives, registers content and assembles
session inputs while leaving the original installation untouched.
