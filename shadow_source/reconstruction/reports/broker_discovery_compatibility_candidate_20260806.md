# Broker discovery and compatibility candidate

Date: 2026-08-06

Status: **ISOLATED MATRIX AND LIVE INTEGRATION VALIDATED; NOT YET PUBLICLY PACKAGED**

Phase 1 is closed for the exercised single-player lifecycle. The next bounded
Phase 2 candidate adds load-path-independent discovery of an already loaded
broker plus ABI-range and capability negotiation under
`mods/sdk_sandbox/game_update_broker/`.

## Deterministic matrix

The 32-bit compatibility test builds four isolated broker fixtures and passes:

- missing broker -> `NOT_FOUND`;
- ABI 4 broker for a 5..6 client -> `INCOMPATIBLE_ABI`;
- ABI 6/minimum 5 broker -> ABI 6 selected;
- ABI 8/minimum 6 broker for a 5..6 client -> ABI 6 selected;
- ABI 8/minimum 7 broker -> `INCOMPATIBLE_ABI`;
- absent requested capability -> `MISSING_CAPABILITY`;
- two broker-shaped modules -> `DUPLICATE` before selection.

The complete broker DLL also builds with warnings as errors, and the canonical
SDK suite passes.

## ABI, owner, thread, lifecycle, and hook review

- ABI: only undecorated C exports are bound. Version selection is the explicit
  intersection of client and broker compatibility ranges. Advertised snapshot
  and polling capabilities require their corresponding exports.
- Owner: successful discovery increments the broker module reference count;
  `f1c_broker_release` clears the complete API table before releasing it.
- Thread: discovery invokes only `F1CBrokerGetInfo`; it schedules no callback,
  performs no game-memory access, and installs no hook.
- Lifecycle: all failure paths leave the caller table empty. Duplicate modules
  fail closed. Live startup ordering and concurrent unload remain unproven.
- Hook: this candidate neither patches nor changes the existing broker-owned
  detours. Existing single-owner exact-byte hook evidence is unchanged.

No canonical SDK header, executable, production mod, or replacement-engine
source was changed. Orchestrator review and live current/missing/duplicate/
startup/orderly-unload integration now pass. Public promotion remains gated on
packaging, mandatory module-pin documentation, and canonical test integration.
