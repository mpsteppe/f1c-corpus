# MAS content-loader slice implementation readiness

Date: 2026-08-06. Status: **READY_FOR_REVIEWED_CODE_CANDIDATE** for the exact
binary and exercised single-player lifecycle. This is not approval to replace
the original executable, deploy a mod, or claim multiplayer equivalence.

## Frozen implementation decisions

1. **Boundary ABI.** The exact binary bridge uses two 32-bit stack arguments,
   callee cleanup, and a signed 32-bit result. Incoming `ECX` is mechanically
   forwarded on error paths but semantically dead. The replacement-facing
   bridge is `int32_t __stdcall load_mas(void **output, const char *filename)`;
   internal code uses typed ownership rather than raw layout pointers.
2. **Search order.** Uppercase-compatible logical lookup tries the supplied
   path first, then registered prefixes in ascending index order, stopping on
   first success. Prefix records must terminate within 132 bytes. Every copy
   and join is bounded. Existing trailing separators and doubled backslashes
   remain accepted.
3. **Selected-path lifetime.** Resolve once and retain the selected path/stream
   through header validation and parsing. The original reopens the logical name,
   but retaining the selected source preserves initial precedence under stable
   files while eliminating a time-of-check/time-of-use race. Differential tests
   must prove direct and prefix collision selection at operation entry.
4. **Failure behavior.** Clear output before work. Preserve `-2` for exhausted
   open search and `-1` for malformed/obsolete/short/overflow/allocation/parser
   failures. Never publish or register a partial object. Zero success requires
   a valid object at every consuming wrapper.
5. **Ownership.** Build an archive object transactionally under unique local
   ownership. Transfer it explicitly to one of three owners only after success:
   function-local extraction, bitmap/path registry until shutdown, or marked
   scene lifetime until phase-end prune. Single removal is API-idempotent.
6. **Thread boundary.** Admit mutation only on the game/main thread and assert
   thread identity, count equality, reciprocal links, and empty shutdown in
   debug builds. Multiplayer remains unsupported until separately traced;
   callers from other threads must fail or dispatch rather than mutate directly.
7. **Compatibility data.** The offset-20 archive total is advisory. Checked
   directory and per-record stored ranges must fit, but exact payload-total and
   exact EOF equality are forbidden because installed content violates both.

## Evidence package

- Fourteen promoted dependency-closed contracts cover the root, parser ladder,
  list mutation/prune, runtime leaves, and ownership bridges.
- The lifecycle trace covers 268 loads, 173 single removals, 79 bulk prunes,
  1,040 valid list snapshots, one mutation thread, and empty shutdown.
- The path trace covers direct and fallback opens, ordered registry snapshots,
  parser reopen behavior, and exact bounded string lengths.
- The installed-content audit covers 664 archives.
- The deterministic negative corpus contains 17 file fixtures and four
  fault-injection cases with exact hashes.

## Remaining step before source generation

Create and validate a one-function/single-entry implementation packet that
references this frozen policy and all promoted dependencies, then generate
multiple independent code candidates for review. Code must remain isolated in
`replacement_engine/`; no original executable or production mod may be edited.
The user has not authorized starting that code-candidate phase in this work
segment, so no engine source is generated here.
