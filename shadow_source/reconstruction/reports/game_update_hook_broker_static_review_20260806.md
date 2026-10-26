# Game-update hook broker static review

Date: 2026-08-06. Scope: independent post-proof review of the isolated
`mods/sdk_sandbox/game_update_broker` implementation and the
`core_lifecycle.main_game_update_hook.v1` evidence boundary.

## Decision

The two-client runtime proof supports a narrow `OBSERVED` claim: one broker
owned the exact-byte detour in the exercised active-race session, rejected a
competing detour, and executed 512 cooperative no-op tasks exactly once on one
observed hook thread. It does not support public SDK promotion.

The raw target remains an internal thiscall-shaped boundary with an opaque
receiver, opaque integer return meaning, and no stack parameters. The broker
preserves the receiver and trampoline return mechanically. Concrete owner,
non-race lifecycle, teardown across transitions, reentrancy, and semantic
command safety remain unresolved.

## Broker review

- Hook ownership fails closed on canonical PE identity, the six-byte
  whole-instruction entry window, and an already-installed competing detour.
- The queue is globally bounded to 256 records, each client is bounded to 32
  queued records, and one hook invocation executes at most 32 valid tasks.
- Registration tokens are generation-tagged. Unregister purges queued work,
  waits for in-flight work, rejects self-unregister from that client's callback,
  and stale tokens are rejected.
- Arbitrary native callbacks remain unsafe: callback faults are not contained,
  a slow callback can block the game thread, and packaged process-wide broker
  discovery/version negotiation is absent.
- The proof did not exercise a hostile sustained producer or establish a
  fairness guarantee across clients.

## Bounded repair

Static review found two fail-open unload paths in the post-proof experimental
source: a detach failure could unload a still-hooked DLL, and a one-second
drain timeout could delete broker state and unload while a hook/API call was
still active. The sandbox implementation now retains the DLL on detach failure
and waits for all active hook/API calls before releasing its trampoline,
critical section, or module reference.

This repair is compile-tested and the full canonical SDK gate passes, but it
has not been runtime-retested. The 512-task proof predates it, so clean detach
must be repeated during the required multi-phase lifecycle run before any
broker interface can advance.

## Promotion boundary

Keep `0x0042C690`, arbitrary callback registration, and the experimental broker
header out of the canonical public SDK. The next admissible surface is a
broker-owned semantic command or copy-out observation whose ABI, owner,
phase/lifetime, budget, fault boundary, and unload behavior are independently
proven.
