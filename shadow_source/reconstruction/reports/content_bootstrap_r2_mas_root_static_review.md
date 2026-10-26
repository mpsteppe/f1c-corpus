# Content bootstrap R2 MAS root static review

Scope: `0x0053CBC0` in a new one-function packet generated only after its four game-owned dependencies were promoted. This is static evidence only; it makes no runtime or ABI-reviewed claim.

Three independently generated candidates validated under the frozen `content_bootstrap_r2_mas_root_candidate_root_001_manifest.json` manifest. Their behavioral summaries agree on file lookup, 12-byte header dispatch, allocation, negative-result cleanup, zero-result list insertion, count update, and output assignment. Differences in kind, prose, literal treatment, lifecycle naming, and compiler-runtime grouping were normalized against the embedded raw C.

The reconciled record deliberately does not adopt the candidates' implied class identity. It records only the 308-byte allocation, the two list offsets directly visible in the root body, and the four mutable globals actually read or written. Fixed-address literals remain evidence rather than promoted mutable globals.

The later instruction-level audit resolves the decompiler's omitted `this` argument. At `0x0053CD00`, `ESI` receives the initializer result; `0x0053CD0A` pushes the filename; `0x0053CD0B` copies `ESI` to `ECX`; and `0x0053CD0D` calls `0x0055FC40`. Allocation failure explicitly zeroes `ESI`, so the same call receives null `ECX`; the parser then derives destination address `0x14` for non-empty input. That unsafe original path, unexpected parser results, unchecked reads, header termination, list synchronization, and implementation policy remain blockers. The separate teardown ladder now contracts resource cleanup and single-node unlink/free behavior.
