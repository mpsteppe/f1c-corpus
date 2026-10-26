# Current reconstruction scope

Project priority update, 2026-08-06: full replacement-engine recreation is
paused. The active use of this evidence pipeline is expansion of the canonical
mod SDK so the existing executable can expose broad typed observation, events,
commands, hooks and resource interfaces. Replacement artifacts and prior MAS
readiness evidence remain preserved but no engine code generation is planned.

Verified: **2026-08-06 after the bounded SDK lifecycle R1 instruction review.**

Phase: **R0 tooling hardened; R1 index verified; R2 pilot followed by fourteen
dependency-closed promoted static contracts and explicit implementation blockers.**

## Static baseline

- 7,132 validated function IR files and 7,132 semantic C++ maps.
- Wave 8 reports: 322 function records valid, 0 invalid/missing; 8 architecture
  packets valid, 0 invalid/missing.
- Canonical reconstruction index: 7,132 nodes and 7,109 SCCs.
- Dispositions: 5,781 `replacement_owned`, 715 `unresolved_residual`, 26
  `external_wrapper`, 610 `compiler_runtime`, 0 `compatibility_stub`.
- The contiguous statically linked MSVC CRT/C++ runtime block at
  `0x00587B97`-`0x0059B249` is classified `compiler_runtime`; exact direct
  import thunks retain `external_wrapper` precedence.
- The 26 external wrappers are direct raw-source thunks marked `attributes:
  thunk` whose complete body is one `__imp_*` forwarding statement. Ordinary
  game functions that merely call imports remain replacement-owned.

`VALID` and `RECONCILED` mean evidence-grounded static results. They do **not**
mean behaviorally confirmed, ABI-exact, observed, or equivalent to original
source.

## Tooling preflight completed

- Candidate paths are unique by subsystem, packet, and candidate ID. All three
  candidates for a packet share an immutable logical contract ID.
- Manifests hash packets, prompts, launchers, schema, worker rules, scheduler,
  and launch wrapper before freeze. Frozen hash mismatches are refused.
- The hidden scheduler has a per-manifest mutex, exact duplicate-wrapper checks,
  a global managed boundary of 48 (two of 50 slots reserved), and clean wrapper
  exits with separate stdout/stderr logs.
- Planning expands partial seeds to complete SCCs. Packetization never splits an
  SCC, records every cut edge, and enforces a 100,000-byte serialized limit.
- Evidence packets embed raw C, validated function IR, architecture excerpts,
  caller/callee context, strings, imports, seed provenance, and uncertainty
  rules.
- Candidate validation enforces logical identity, evidence membership, coverage,
  trust ceiling, cut dependencies, and cross-packet uniqueness.
- Reconciliation requires a complete candidate trio for `RECONCILED`; promotion
  requires no disputes, three candidate references, unique function ownership,
  and dependency closure.
- Synthetic reconstruction tests: 18 passing. The three existing shadow-source
  gates and replacement-engine CTest also pass.

## Preserved rejected/proof work

- The obsolete pit proof is archived under
  `shadow_source/reconstruction/rejected/pit_pilot_proof/`.
- The earlier address/path-only content launch is rejected and documented under
  `rejected/r2_premature_20260806/`. Its 34 candidate files, prompts, frozen
  manifests, launchers, and logs remain at their original paths; two tasks failed
  with `database is locked`. The strengthened validator reports 0 valid / 34
  invalid because the packets lacked immutable logical contract identities.
- One generated enriched packet exceeded the byte ceiling (122,550 bytes) and is
  preserved under `rejected/tooling_packetization/`; the corrected pilot packets
  are 77,524-95,062 bytes.

## R2 smoke and pilot results

### One-worker smoke

- One 18,348-byte MAS open/index packet for `0x0053CBC0` ran end to end.
- Output creation and schema/evidence validation passed.
- Two later independent candidates completed the trio: 3 valid / 0 invalid.
- Reconciliation retained 8 disputes and status `STATIC_DERIVED`; the record is
  not promotion-eligible. Eleven replacement-owned frontier dependencies remain
  explicit.

### Bounded content/bootstrap pilot

- Six RAW/search anchors expanded deterministically to 42 functions.
- 8 SCC-safe packets, 204 cross-frontier dependencies, 24 independent workers.
- Initial run produced 22 outputs; two workers exited without results. Two
  immutable one-packet repair manifests produced the missing candidates.
- Final validation: 24 valid / 0 invalid.
- All eight trios reconciled, but each retains 8-10 material field disputes and
  remains `STATIC_DERIVED`; none was promoted.

### Dependency-closed leaf repair and promotion

- `0x0053C6B0`, a no-callee pair/string copy helper used by StringRegistry and
  SearchPathPrune, was isolated as one function / one packet.
- 3 independent candidates passed validation. Static raw-body review adjudicated
  wording/type-label differences conservatively to `OpaquePairRecord` while
  retaining owner, field meaning, capacity, overlap, and runtime status as
  unresolved.
- Promoted contract:
  `content_bootstrap_r2_leaf.packet_000.v1` at trust level `RECONCILED`.
- Dependency closure: zero packet dependencies and zero external frontier cuts.
- No code generation ran and `replacement_engine/` was not edited.
- A read-only bounds audit now covers all 664 installed MAS files. Header-total
  equality is disproved by 111 files, and exact EOF equality is disproved by
  one file with 18,286 trailing bytes. The replacement policy now validates
  checked directory/per-record ranges without imposing either unsafe equality.
- A deterministic negative-path corpus now contains 17 byte fixtures plus four
  fault-injection cases under `reconstruction/fixtures/mas_negative`; its
  builder verifies exact bytes, sizes, hashes, and manifest membership.
- A read-only path probe now grounds the MAS search ladder: direct open first,
  then ascending 132-byte registry entries, stopping on first success. Ten root
  calls included four observed direct-failure/fallback-success paths. Registered
  prefixes already end in backslash, and the original successfully emits doubled
  separators. The parser reopens the logical name through the same ladder.
- Instruction audit proves that the root's 256-byte input copy and 256-byte
  fallback formatting are not bounded; the shared formatter uses a nominal
  `0x7FFFFFFF` limit. A proposed matrix now rejects overlong/unbounded input in
  replacement code without invoking the unsafe original path.
- The exact-binary root ABI is now instruction-reviewed across all 23 direct
  call instructions: two stack arguments, `ret 8`, and no semantically live
  hidden ECX context. The MAS slice freezes resolve-once/retain-selected-stream,
  transactional ownership, and main-thread-only mutation and is now
  `READY_FOR_REVIEWED_CODE_CANDIDATE`; engine code generation has not started.

### Dependency-closed MAS contract ladder

- Three true game-owned leaves were isolated into one-function packets and
  promoted after 9/9 independent candidates validated:
  `0x004B0170` (empty leaf), `0x0053C2A0` (global/object zero initializer), and
  `0x0053C590` (global error-buffer copy helper).
- The next level used promoted leaf contracts rather than unresolved address
  cuts. Another 9/9 candidates validated and static review promoted
  `0x00557470`, `0x0055FBE0`, and `0x0055FC40`.
- A fresh root packet for `0x0053CBC0` then resolved all four game-owned cuts to
  promoted contracts. Its 3/3 candidates validated and the conservative static
  contract was promoted.
- Instruction export resolved the parser call mapping: at `0x0053CD0B`, `ECX`
  receives the initialized object held in `ESI`, while the filename is the one
  stack argument. Allocation failure instead passes null `ECX`; the parser then
  derives destination address `0x14`, proving an unsafe original path for a
  non-empty filename. The allocator's deployed null-return behavior is unknown.
- Three teardown functions were then promoted after three independent candidates
  each validated: `0x0055FE30` closes/clears the handle and frees/clears the
  payload; `0x0053CE40` unlinks and frees one reachable node; `0x0053CED0`
  prunes nodes selected by flag bit 3 using the recovered look-ahead traversal.
- The scene `masfile` wrapper `0x0053CE10` was promoted after 3/3 candidates
  validated. It delegates to the root loader, propagates its result, and on a
  zero result with a non-null output slot sets bit 3 at object offset `0x114`.
  Cross-function static evidence links this mark to pruning after successful
  vertex-buffer/resource setup. A zero result with a non-null slot but invalid
  `*output` remains an explicit unsafe original path and replacement-policy
  blocker.
- Read-only instruction inspection of the original executable confirms that
  scene-parser local `v12` is not initialized before its address is passed to
  the wrapper. The normal 410 path writes it, but root zero-return/no-output
  paths leave the wrapper able to write through an uninitialized/stale value.
  Incoming `ECX` is forwarded but no hidden semantic context use was proven.
- A read-only installed-content audit covered 207 scene files, 1,391
  `MASFile` directives, and 458 candidate archive paths. Every candidate began
  with `CUBEMAS4.10\0`; the installed snapshot contains no scene directive that
  exercises the unrecognized-header zero/no-output path. Third-party and
  malformed-content policy remains unresolved.
- Cross-function ownership audit accounts for every recovered root-loader call
  site: fourteen loaders remove temporary archives locally; scene archives are
  bit-3 marked and bulk-pruned after resource setup; bitmap archives transfer
  into a registry released by resource-manager shutdown `0x004963D0` through
  bridge `0x00495010`. Thread confinement and error-branch completeness remain
  unproven.
- Instruction-level error-branch audit found that root parser failures `-2/-1`
  free the allocated object and then still publish that freed address through
  the output slot at `0x0053CDA9`. Unknown/empty inputs return zero without
  output, short header and payload reads are unchecked, and unexpected parser
  results would leak an unregistered object. The transactional replacement
  policy explicitly forbids all four behaviors.
- Direct-call ancestry supports main-thread confinement and the only recovered
  `CreateThread` entry has no direct MAS reach, but indirect virtual calls keep
  this below proof level. A read-only Frida probe now records actual mutation
  thread IDs and validates list count/link invariants; no game process was
  running, so the runtime gate remains unexecuted.
- Post-promotion bridge disassembly confirms stack cleanup (`ret 8` for
  `0x00494FE0`; tail target `ret 4` for `0x00495010`) and reveals a direct read
  of `0x008AFE64` into `ECX` in both bridges. Current callees do not demonstrably
  consume the incoming value, but immutable contract omissions are recorded in
  `reports/promoted_contract_errata.json` and remain an ABI-review item.
- The read-only lifecycle probe was executed through load, unload, and normal
  process exit: 268 root loads, 173 single removals, 79 bulk prunes, and 1,040
  actual list snapshots. Every MAS mutation matched the live main-loop thread;
  no actual count/link invariant failed; maximum live count was 12; shutdown
  ended with a null head and zero count. This runtime-confirms main-thread
  confinement for the exercised single-player path, not multiplayer.
- Five observed root loads returned `-2` for the absent
  `SEASONDATA\VEHICLES\GENERIC_F1.mas`; outputs were null and list state stayed
  valid. Capture v1's fixed-size Frida string read cannot establish whether the
  caller buffer was terminated; the probe now records explicit terminator
  state. No parser failure or zero-without-object path occurred, so those
  instruction-proven hazards still require negative tests.
- Two ownership bridges were then promoted after 6/6 candidates validated:
  `0x00494FE0` clears its output only for nonzero root results and exposes a
  second zero-without-output hazard in the bitmap loader; `0x00495010` forwards
  retained archive release from resource-manager shutdown to single-node
  removal.
- Total promoted contracts/source functions: 14. Compiler-runtime calls remain
  explicit external boundaries; there are no unresolved replacement-owned cuts
  in the new MAS ladder packets.
- The root review retains allocation/null policy, unchecked file reads/header
  termination, filename bounds, invalid-output policy, list synchronization,
  concrete ownership, and corrupt-list/count behavior as unresolved.
  These are explicit code-generation blockers, not runtime findings.
- No code generation ran and `replacement_engine/` was not edited.

## Current blockers and next frontier

### SDK expansion R1 high-leverage review (2026-08-06)

- The completed 16-packet candidate batch swept 48/48 valid with zero pending
  repairs. Eleven superseded invalid attempts remain quarantined under the
  rejected-candidate tree.
- Deterministic reconciliation produced 16 `STATIC_DERIVED` records; every
  packet retains 5-11 material disputes, so no contract or SDK interface was
  promoted.
- Read-only instruction export resolved mechanical receiver and stack-cleanup
  shapes for 15 anchors and left the no-argument `0x004628A0` convention
  spelling ambiguous. Concrete owners, return semantics, thread proof,
  lifecycle closure, side effects, and hook unload/reentrancy remain blocking.
- Exact entry bytes and whole-instruction detour windows are recorded in
  `reports/sdk_expansion_r1_high_leverage_instruction_review_20260806.md`.
  They are evidence, not approved hooks. `tools/sdk/` was not changed.
- This SDK wave is not complete. Do not dispatch another large wave; next use
  bounded caller/callee review for `0x0042D8A0`, `0x004C73F0`, `0x004EF5A0`,
  and `0x0057A6A0`, preserving opaque boundaries where proof is absent.

### SDK expansion R1 closure-core review (2026-08-06)

- The one-item immutable repair completed cleanly. Fresh deterministic
  validation reports 48/48 valid candidates and zero pending repairs.
- Fresh reconciliation produced 16 `STATIC_DERIVED` records. Every record
  retains 6-9 material disputes, and the selected frontier remains explicitly
  not dependency-closed.
- Independent instruction review recovered mechanical cleanup shapes and exact
  whole-instruction entry windows for all 16 functions. It did not prove
  concrete owners, semantic return contracts, passive thread/cadence behavior,
  lifecycle closure, payload ownership, or safe hook unload/reentrancy.
- No SDK interface, command, event, or hook was promoted. The entry bytes in
  `reports/sdk_expansion_r1_closure_core_instruction_review_20260806.md` are
  evidence only.
- This wave remains blocked at owner/thread/lifecycle/hook review. Do not start
  another broad batch; next work is bounded construction/destruction ancestry
  and passive thread/cadence observation for the four anchor paths.

### SDK expansion R1 closure-core follow-up (2026-08-06)

- The 16-function caller/callee closure produced 48 current candidates. The
  first immutable sweep found 47 valid and one evidence-membership failure;
  the rejected body was quarantined and one frozen one-worker repair passed.
  Final validation is 48/48 valid with zero pending repairs.
- All 16 trios reconciled to `STATIC_DERIVED`, retaining 120 material disputes
  (6-9 per record). Instruction review resolved mechanical stack cleanup and
  receiver shape but did not close concrete owners, runtime thread affinity,
  lifecycle preconditions, downstream side effects, or unload/reentrancy.
- No SDK interface or hook was promoted and no broader wave was dispatched.
  See `reports/sdk_expansion_r1_closure_core_instruction_review_20260806.md`.
- The original executable remained byte-identical. IDA unexpectedly rewrote
  the isolated untracked SDK-lab database during the no-save export; further
  IDA automation must use a disposable database copy.

### SDK lifecycle R1 anchors (2026-08-06)

- One unique bounded scheduler completed six immutable candidates for
  `0x004A0FD0` and `0x004EF5A0`; deterministic validation reports 6 valid, 0
  invalid, and no repair or quarantine was needed.
- Three-way reconciliation produced two `STATIC_DERIVED` records with 6 and 7
  disputes. Neither record is dependency-closed or promotion-eligible.
- Disposable-IDB instruction review proves `0x004A0FD0` is thiscall-shaped
  with no stack arguments and plain `ret`; its sole caller supplies the opaque
  global receiver `0x007CE24D`. `0x004EF5A0` consumes two 4-byte ABI slots and
  returns with `ret 8`, but its semantic return is path-dependent.
- Concrete owners, passive thread/cadence evidence, same-process second-session
  lifecycle, and hook unload/reentrancy remain unresolved. No SDK interface,
  command, event, or hook was promoted, and no broader worker wave was
  dispatched. See `reports/sdk_lifecycle_r1_instruction_review_20260806.md`.

1. Freeze and validate a one-function/single-entry implementation packet for
   the MAS loader slice, then generate independent reviewed code candidates only
   when the user authorizes the separate source-generation phase.
2. Wire the controlled fixture and path-boundary corpora into that future
   replacement-loader harness. Direct/prefix collision fixtures must prove
   selection at operation entry; multiplayer remains outside observed scope.
3. Split any reused multi-function pilot packet into one-function or
   single-entry contract packets; one signature cannot represent heterogeneous
   function clusters.
4. Add focused anchors for legacy loose-file/archive precedence, duplicate
   content registration, and session-lifecycle construction inputs. The current
   pilot deliberately does not claim full slice coverage.
5. Do not edit production mods or the original executable. The MAS slice has
   dependency-closed promoted contracts and a frozen ABI/ownership policy, but
   `replacement_engine/` source generation remains a separately authorized
   phase.
