# SDK expansion R1 closure-core instruction review

Date: 2026-08-06. Scope: the 16 one-function packets selected to close the
caller/callee neighborhood of `0x0042D8A0`, `0x004C73F0`, `0x004EF5A0`, and
`0x0057A6A0`.

## Gate result

- The bounded repair completed and its isolated validator reports 1 valid / 0
  invalid.
- A fresh deterministic sweep reports 48 valid / 0 invalid candidates.
- Fresh deterministic reconciliation produced 16 `STATIC_DERIVED` records.
  Each retains 6-9 material disputes; none is promotion-eligible.
- The selected frontier is not dependency-closed. The anchor bodies still cross
  unresolved game-owned call boundaries.
- No canonical SDK interface, command, event, or hook is promoted. Entry bytes
  below are construction evidence only, not hook approval.

`VALID` and `STATIC_DERIVED` mean evidence-grounded static results, not owner,
ABI, thread, lifecycle, hook-safety, or runtime confirmation.

## Instruction-level ABI and hook review

| Address | Instruction-supported ABI shape | Owner/thread/lifecycle review | Whole-instruction entry window | Decision |
|---|---|---|---|---|
| `0x00404460` | Live `ECX` receiver, no explicit stack arguments, plain `ret`; return semantics are not established. | Opaque processing-state receiver. Two callers place it in main/post-loop paths, but concrete owner, cadence, teardown, and reentrancy are not proven. | 7 bytes: `51 D9 05 E8 FE 8A 00`. | Block call and hook exposure. |
| `0x0040CA30` | Live `ECX` receiver, no explicit stack arguments, plain `ret`; candidate `char` return is not proven by cleanup shape. | Opaque camera director. Main-loop ancestry is derived only; camera target/resource lifetime and shutdown order remain open. | 5 bytes: `83 EC 38 53 55`. | Block pending owner and presentation-lifecycle evidence. |
| `0x0042ACA0` | Live `ECX`, one 4-byte stack slot, `ret 4`; thiscall-shaped setter. | Writes receiver `+0x4550` and conditionally touches another global object. Same offset or caller context does not prove a public vehicle owner or safe standalone command. | 7 bytes: `8B 44 24 04 83 F8 02`. | Block command/hook promotion. |
| `0x0042ADB0` | Live `ECX`, zero explicit arguments, plain `ret`; AL is read from receiver state but a semantic return contract is unresolved. | Writes receiver `+0x4424` and `+0x45F4`. Candidate `F1CVehicle` labels remain unproven; transition preconditions and cleanup ownership are disputed. | 6 bytes: `8A 81 10 44 00 00`. | Block command exposure. |
| `0x0042BD60` | No live incoming receiver or stack argument; plain `ret`. No-argument cdecl/stdcall spelling is mechanically indistinguishable. | Global scoring/reset routine with three callers. Season/session phase, ordering, and downstream transition ownership are not closed. | 9 bytes: `56 57 C6 05 90 56 7C 00 00`. | Retain as an internal lifecycle anchor. |
| `0x0042C690` | Incoming `ECX` is preserved as a receiver, zero explicit stack arguments, plain `ret`; EAX meaning remains unresolved. | Main-tick ancestry is strong static evidence, not observed thread/cadence proof. The body crosses many unresolved subsystem calls and globals. | 6 bytes: `55 8B EC 83 E4 F8`. | Block public tick call/hook. |
| `0x0042D8A0` | Incoming `ECX` is written at entry, zero explicit stack arguments, plain `ret`; thiscall-shaped coordinator. | Single direct caller is the game entry path. The receiver is an opaque coordinator; update ordering, shutdown paths, exception/reentrancy behavior, and callee closure remain unresolved. | 7 bytes: `53 C7 01 05 00 00 00`. | Block main-loop hook/interface. |
| `0x00447780` | Live `ECX`, one 4-byte stack argument, `ret 4`; thiscall-shaped. | Caller and field accesses support a physics-related opaque receiver, but the input object's exact layout, ownership, and tick lifetime are disputed. | 6 bytes: `55 8B EC 83 E4 F8`. | Block callable ABI and hook. |
| `0x00455E50` | Live `ECX`, zero explicit incoming arguments; the body tail-jumps to `0x00455BD0`, so independent return semantics are not established. | Main-loop ancestry is derived. The tail target owns final behavior; collision/update side effects and lifecycle are not closed. | 6 bytes: `DD 05 90 FE 8A 00`. | Block until the tail target is reviewed. |
| `0x0045B200` | Four 4-byte stack slots and `ret 10h`; callee-clean/stdcall-shaped entry. No live incoming owner receiver. | Executable entry wrapper. Main-thread origin is structurally strong, but exposing it as a mod API has no safe lifecycle or unload meaning. | 5 bytes: `8B 44 24 04 56`. | Do not expose or hook through the public SDK. |
| `0x0045F2B0` | Live `ECX`, one 4-byte stack argument, `ret 4`; thiscall-shaped renderer/helper. | Opaque session UI owner. Presentation lifetime, render-buffer validity, thread identity, and reentrancy are unobserved. | 6 bytes: `81 EC B0 01 00 00`. | Block hook/interface. |
| `0x0045FC50` | Live `ECX`, zero explicit stack arguments, plain `ret`; candidate `char` return is unresolved. | Opaque network/session manager with large receiver offsets and broad side effects. One direct caller does not prove thread affinity, construction, or shutdown order. | 6 bytes: `55 8B EC 83 E4 F8`. | Block callable and hook exposure. |
| `0x00460E90` | Live `ECX`, zero explicit stack arguments, plain `ret`; EAX meaning is unresolved. | Opaque server/session receiver. Network/UI/resource interactions cross unresolved callees; sender and track-resource lifetimes are open. | 6 bytes: `DD 05 A0 FE 8A 00`. | Block interface/hook. |
| `0x004C73F0` | Live `ECX`, exactly two 4-byte stack slots, `ret 8`. The second slot is consumed by both x87 and integer instructions as a 32-bit float bit pattern; the first remains opaque. | Opaque vehicle-physics receiver. Two tick-path callers support derived cadence only. Physics/audio/helper dependencies, packet ownership, update order, and teardown remain unresolved. | 6 bytes: `81 EC 8C 00 00 00`. | Block tick call and hook. |
| `0x004EF5A0` | Live `ECX`, exactly two 4-byte stack slots, `ret 8`; the second is byte-tested from its ABI slot. Return semantics and semantic parameter types remain disputed. | Opaque session-transition owner. Twenty-two call sites prove broad reuse, not a safe standalone command. Entry/exit ordering, cleanup, recursion, and thread proof remain open. | 7 bytes: `8B 44 24 04 83 EC 30`. | Keep as lifecycle investigation anchor only. |
| `0x0057A6A0` | Live `ECX`, exactly seven 4-byte stack slots, `ret 1Ch`. This rejects any eight-explicit-argument interpretation; byte-like values still occupy full ABI slots. | Opaque network sender aggregate. Five callers, virtual dispatch through receiver state, payload ownership, sender lifetime, network/game-thread affinity, and shutdown behavior are unresolved. | 5 bytes: `53 56 57 8B F9`. | Block all public and hook exposure. |

## Promotion decision and next bounded work

No record reaches `ABI_REVIEWED`: instruction cleanup establishes only the
mechanical call shape. Concrete owners remain opaque where constructors or
caller object identities do not prove them. Main-loop ancestry is not passive
thread/cadence observation, and no packet closes construction, steady-state,
shutdown, unload, reentrancy, and all side-effect dependencies.

This wave is therefore not genuinely complete and no new broad worker wave is
dispatched. The next useful work is bounded and read-only: construction and
destruction ancestry for the opaque coordinator/session/network receivers, plus
passive thread/cadence observation for the main tick, physics step, session
transition, and network send during an already-authorized scenario. Network
payload and sender ownership must remain opaque until lifetime evidence exists.

Evidence artifacts:

- `reports/sdk_expansion_r1_closure_core_instruction_export.json`
- `reports/sdk_expansion_r1_closure_core_candidate_validation.json`
- `reports/sdk_expansion_r1_closure_core_repair_001_validation.json`
- `reconciled/sdk_expansion_r1_closure_core.packet_000.v1.json` through
  `packet_015.v1.json`
