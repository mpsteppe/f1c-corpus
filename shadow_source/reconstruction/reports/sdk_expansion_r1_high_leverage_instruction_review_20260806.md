# SDK expansion R1 high-leverage instruction review

Date: 2026-08-06. Scope: the 16 one-function packets in
`sdk_expansion_r1_high_leverage_candidate_sdk_api_001_manifest.json`.

## Outcome

- The immutable result sweep checked 48 current candidates: 48 valid, 0
  invalid, 0 pending repairs. Eleven superseded invalid attempts remain under
  `shadow_source/reconstruction/rejected/candidates/sdk_expansion_r1_high_leverage_*`.
- Deterministic reconciliation produced 16 records. Every record remains
  `STATIC_DERIVED`; each has 5 to 11 material candidate disputes. No record is
  eligible for promotion.
- A read-only IDA 9.1 export from the prepared SDK-lab database captured every
  instruction, direct caller, direct call, return, and the first 32 entry bytes
  for all 16 functions. It did not save the database or modify the executable.
- Instruction evidence resolves the mechanical receiver/stack-cleanup shape of
  15 functions. `0x004628A0` is a no-explicit-argument function whose cdecl vs
  stdcall spelling is mechanically indistinguishable. Return-value semantics,
  concrete owners, and several parameter types remain unresolved.
- No public SDK interface or hook is promoted. Instruction shape alone does
  not establish owner identity, safe invocation phase, thread affinity,
  lifecycle preconditions, side-effect closure, or unload safety.

`VALID` means evidence-grounded, not behaviorally confirmed.

## Instruction-level ABI and safety matrix

`thiscall-shaped` means incoming `ECX` is used as the receiver and the shown
stack-byte count is callee-cleaned by `ret N`. It does not confirm the proposed
class name. Thread labels below are static ancestry signals, not runtime proof.

| Address | Mechanical ABI evidence | Owner/thread/lifecycle review | Hook review | Decision |
|---|---|---|---|---|
| `0x0040BE70` | Live `ECX` copied to `ESI`; no stack cleanup operand; zero explicit stack args. EAX return meaning/width unresolved. | Opaque camera-input receiver. Only direct caller is `0x0040CA30`; game-loop affinity is derived through that caller. One-shot input and camera-state transitions are not lifecycle-closed. | First whole-instruction window is 7 bytes: `51 56 8B F1 8A 46 24`; no relative control transfer. | Block callable and hook promotion. |
| `0x0040CA30` | Live `ECX` receiver; no explicit stack args; plain `ret`. EAX is consumed along multiple return paths but semantic type is unresolved. | Opaque camera-director receiver. Called from `0x0042D8A0` and `0x004B8AE0`; game-thread use is strongly suggested, not observed. Many vtable/camera dependencies and transition rules remain open. | Entry window is 5 bytes: `83 EC 38 53 55`; mechanically relocatable. | Block pending owner, vtable, and lifecycle closure. |
| `0x0042D8A0` | Incoming `ECX` is immediately written, zero explicit stack args, plain `ret`: thiscall-shaped state owner. | Direct caller `GameMainEntry` (`0x0045B200`) supports main/game-thread placement. The function writes phase value 5 before dispatching many session/render/update dependencies, so it is a lifecycle root, not a free-standing command. | Entry window is 7 bytes: `53 C7 01 05 00 00 00`; mechanically relocatable but includes the phase write that must execute exactly once. | Block hook/callable promotion; use only as a frame-order investigation anchor. |
| `0x00451720` | Live `ECX` receiver; zero explicit stack args; plain `ret`; aligned-stack prologue. | Opaque driver-input controller. Single caller `0x0042C690` supports per-tick/game-thread use. Large stateful body and input/output ownership are not closed. | Entry window is 6 bytes: `55 8B EC 83 E4 F8`; trampoline must preserve the nonstandard stack-alignment prologue. | Block pending lifecycle, state ownership, and return semantics. |
| `0x0045BD10` | Live `ECX` receiver and `ret 0Ch`: thiscall-shaped with three 4-byte stack arguments. Candidate spellings of argument 1 differ. | Opaque text/render owner; 31 direct call sites span UI/session/render paths. Thread and buffer ownership are unproven. | Entry window is 5 bytes: `A1 E4 02 7D 00`; absolute global read is position-independent, but text-buffer lifetime and reentrancy are unresolved. | Block public rendering hook/interface. |
| `0x004628A0` | No incoming receiver survives; `ECX` is replaced with a stack-local address. No explicit stack args and plain `ret`; cdecl vs stdcall spelling cannot be distinguished. | No object owner established. Single caller `0x0046E2CE`; update phase and thread are not reviewed. | Entry window is 6 bytes: `81 EC 30 02 00 00`; mechanically relocatable. | Block until caller and weather-surface lifecycle are reviewed. |
| `0x00496030` | Live `ECX` receiver and `ret 4`: thiscall-shaped with one 4-byte stack argument. | Opaque damage-state receiver. Single caller `0x00496E90`; game-thread use is plausible but unobserved. Function mutates crash/damage state and crosses downstream effects. | Entry window is 5 bytes: `51 53 56 8B F1`; mechanically relocatable. | Block behavior-changing call/hook pending damage ownership and causal side-effect review. |
| `0x004C55B0` | Incoming value is one stack argument; no live receiver; `ret 4`: one-argument callee-clean/stdcall-shaped entry. | No class owner. Eleven loader call sites; load phase, output ownership, error cleanup, and thread are not closed. The entry performs an unbounded local string copy in original behavior. | Entry window is 8 bytes: `8B 44 24 04 8D 54 24 B0`; mechanically relocatable, but hooking an unsafe loader entry does not make its buffer behavior safe. | Block SDK exposure; retain as loader investigation boundary. |
| `0x004C73F0` | Live `ECX` receiver and `ret 8`: thiscall-shaped with two 4-byte arguments. The second is read through x87 and integer instructions consistently with a 32-bit float bit-pattern; first remains opaque. | Opaque vehicle-physics receiver. Direct callers `0x004F03E0` and `0x004F0430`; game-thread/tick use is derived. Large update body has unresolved physics, audio, and object dependencies. | Entry window is 6 bytes: `81 EC 8C 00 00 00`; mechanically relocatable. | Block until tick ordering, packet ownership, and full side-effect closure are reviewed. |
| `0x004D82D0` | Live `ECX` receiver; zero explicit stack args; plain `ret`. EAX return semantics remain unresolved. | Opaque HUD renderer owner. Single caller `0x004D8450`; presentation-thread/game-thread identity and render-buffer lifetime are unproven. | Entry window is 5 bytes: `A1 A0 FE 7C 00`; mechanically relocatable absolute read. | Block hook/interface pending render lifecycle and reentrancy evidence. |
| `0x004E0ED0` | Live `ECX` receiver and `ret 4`: thiscall-shaped with one 4-byte argument. | Opaque audio controller. Twenty-seven direct call sites include camera, session, physics, and audio paths; caller breadth does not prove one thread. Audio resource lifetime and backend boundary remain open. | Entry window is 5 bytes: `53 55 56 8B F1`; mechanically relocatable. | Block public call/hook pending audio ownership, thread, and shutdown ordering. |
| `0x004EF5A0` | Live `ECX` receiver and `ret 8`: thiscall-shaped with two 4-byte arguments. Candidate agreement supports pointer/state plus byte-like flag use, but semantic types and return meaning remain disputed. | Opaque session owner. Twenty-two call sites establish broad transition use, not safe standalone invocation. Entry/exit ordering and cleanup dependencies are unresolved. | Entry window is 7 bytes: `8B 44 24 04 83 EC 30`; mechanically relocatable. | Block as a command; retain as session-lifecycle anchor. |
| `0x004EF930` | Live `ECX` receiver and `ret 4`: thiscall-shaped with one 4-byte argument. | Opaque race-start state owner. Seven direct call sites, including session/load paths; game-thread label remains derived. Countdown/audio/telemetry side effects are not dependency-closed. | Entry window is 10 bytes: `53 56 8B F1 8A 86 EE 39 00 00`; mechanically relocatable. | Block callable/hook promotion. |
| `0x004F24F0` | Live `ECX` receiver and `ret 4`: thiscall-shaped with one 4-byte stream/handle argument. Return has at least zero and negative failure behavior in static control flow, but public type remains unresolved. | Receiver is a damage-parameter destination, not independently proven to be the legacy-named class. Single caller `0x004F4270` supports load-time use; allocation/stream/helper ownership is open. | Entry window is 6 bytes: `81 EC B8 03 00 00`; mechanically relocatable. | Block SDK promotion pending parser helper contracts, bounds policy, and load-thread proof. |
| `0x004F88A0` | Live `ECX` receiver; zero explicit stack args; plain `ret`. x87 return behavior needs caller-level confirmation; `float *` is not proven by the return instruction. | Opaque race/audio/HUD state receiver. Callers `0x00447E00` and `0x004EF930`; cadence and noise-cursor ownership remain unresolved. | Entry window is 6 bytes: `83 EC 08 56 8B F1`; mechanically relocatable. | Block interface/hook pending return, owner, and shared-global review. |
| `0x0057A6A0` | Live `ECX` receiver and `ret 1Ch`: thiscall-shaped with exactly seven 4-byte stack slots. This rejects any interpretation with eight explicit stack arguments; byte-like arguments occupy 4-byte ABI slots. | Opaque network/session sender. Five callers; network-vs-game-thread affinity, vtable owner, payload ownership, and sender lifetime are unproven. | Entry window is 5 bytes: `53 56 57 8B F9`; mechanically relocatable. | Block all public/hook exposure; network thread and lifetime risk are high. |

## Promotion and next-frontier decision

The entry-byte windows are hook-construction evidence only. None is an approved
hook: every candidate still lacks at least one of owner identity, thread proof,
lifecycle preconditions, side-effect closure, or safe unload/reentrancy proof.
No canonical SDK file was changed.

This wave is not genuinely complete, so no next large wave is dispatched. The
highest-leverage bounded follow-up is caller-window and callee-contract review
for the mechanically strongest roots (`0x0042D8A0`, `0x004C73F0`,
`0x004EF5A0`, and `0x0057A6A0`), followed by passive thread/cadence observation
where an already-authorized scenario exists. The network path must remain
opaque until its thread and payload lifetime are proven.

Evidence artifacts:

- `reports/sdk_expansion_r1_high_leverage_instruction_export.json`
- `reports/sdk_expansion_r1_high_leverage_candidate_validation.json`
- `reconciled/sdk_expansion_r1_high_leverage.packet_000.v1.json` through
  `packet_015.v1.json`

