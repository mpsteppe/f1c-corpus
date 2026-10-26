# Broker discovery independent review

Date: 2026-08-07

Status: **INDEPENDENTLY REVIEWED, BOUNDED-REPAIRED, AND CANONICALLY PACKAGED**

## Immutable-result sweep

- The active lifecycle worker set remains 6 valid, 0 invalid, with two
  deterministic reconciliation records and two instruction-reviewed records.
- No new worker failure required quarantine or retry. Existing rejected
  attempts remain preserved under the reconstruction rejected tree.
  this review.

## Independent findings and bounded repairs

1. Toolhelp module enumeration did not own a module reference before invoking
   `F1CBrokerGetInfo`, leaving a concurrent-unload race. Discovery now pins a
   broker-shaped module before the query call, retains the selected reference,
   and releases every rejected or duplicate candidate.
2. The compatible-new fixture only changed version integers while using the
   current info layout. The query contract now names a stable ABI-6 prefix and
   the future fixture reports a larger 32-byte record without requiring or
   writing beyond the caller's prefix.
3. ABI 5 negotiation still exposed ABI 6 snapshot/event capabilities and
   pointers. Discovery now masks the negotiated surface and the matrix proves
   that a downgraded client cannot request or receive ABI 6 observation APIs.
4. The concurrent ABI 7 session-snapshot draft inserted its pointer before the
   ABI 6 polling pointer and required the larger table, breaking the advertised
   ABI 6 compatibility. ABI 7 is now append-only; discover and release honor the
   caller's ABI 6 table size, clamp negotiation when the table lacks the ABI 7
   tail, and pass an overwrite-canary regression.

The isolated compatibility matrix passes after all three repairs. The complete
broker and discovery probes build as 32-bit C11 with warnings treated as
errors. The canonical SDK suite also passes.

## ABI, owner, thread, lifecycle, and hook review

- ABI: the built broker exports eleven undecorated `F1CBroker*` C symbols. The
  discovery and release routines compile as caller-cleanup x86 functions. ABI
  intersection now gates both capabilities and callable pointers.
- Owner: discovery obtains the module reference before calling broker code.
  Success transfers exactly that reference into `F1CBrokerApi`; release clears
  the entire table before `FreeLibrary`.
- Thread: discovery performs module enumeration, export lookup, and the
  side-effect-free info query synchronously on its caller. It schedules no
  callback and accesses no game memory.
- Lifecycle: missing, malformed, old, compatible-new, too-new, missing
  capability, duplicate, downgrade, retained-reference, and ABI 6 table-prefix
  paths pass in the isolated process. Live current/missing/duplicate startup,
  release, and orderly hook detach also pass in the supported game. Forced
  uncooperative unload remains outside the contract.
- Hook: discovery installs and removes no detour. Existing broker hook evidence
  is unchanged; live packaged startup/unload remains the relevant hook-owner
  gate.

## Promotion decision

The reviewed discovery/ABI client surface is packaged as `tools/sdk/f1c_broker_abi.h`,
`f1c_broker.h`, and `f1c_broker.c`, and its compatibility matrix is part of the
canonical regression runner. ABI 7 session/environment snapshots also have one
coherent live startup observation. Broader observation APIs and semantic events
remain gated on hostile-reader, overflow, second-session, and subsystem-specific
lifecycle evidence; no internal hook address is exposed as a public command.
