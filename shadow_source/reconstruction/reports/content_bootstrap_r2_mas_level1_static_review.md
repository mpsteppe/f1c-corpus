# Content bootstrap R2 MAS level 1 static review

Scope: three one-function packets whose game-owned callees are already promoted contracts. This review is static only. It makes no runtime, ABI-reviewed, or behavior-verified claim.

## `0x00557470`

The raw body is a thiscall-shaped forwarding thunk that ignores `this`, calls `0x004B0170`, and returns void. Candidate differences are labels and wording, not behavioral conflicts. The reconciled contract retains unknown owner/lifecycle and ABI uncertainty.

## `0x0055FBE0`

The raw body calls the promoted zero-initialization dependency, copies the `aCubemas410` literal to the object base with `strcpy`, explicitly clears the recovered offsets, and returns `this`. The review uses only byte/dword widths directly visible in the body. Object identity, capacity, and semantic field names remain unresolved.

## `0x0055FC40`

The raw body establishes the return codes and control flow: invalid input returns `-1`; open exhaustion logs and returns `-2`; bad header or allocation failure closes, logs, and returns `-1`; success retains the handle and allocated payload and returns `0`. The contract records exact recovered offsets and the two registry globals actually read as state. String literals are evidence, not promoted mutable globals. Compiler-runtime cuts remain external boundaries, and the logging cut resolves to the promoted dependency. Buffer bounds, short reads, allocation overflow, ownership teardown, semantic names, and ABI remain unresolved.

All three candidate trios were independently generated under the frozen `content_bootstrap_r2_mas_level1_candidate_level1_001_manifest.json` manifest and validated 9/9 before review. Automated prose disputes were resolved only where the embedded raw C made the common behavior explicit.
