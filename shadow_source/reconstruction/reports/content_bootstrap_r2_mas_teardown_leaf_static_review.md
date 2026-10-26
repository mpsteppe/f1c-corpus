# Content bootstrap R2 MAS teardown leaf static review

Scope: `0x0055FE30` as a one-function, dependency-closed static contract. Three independent candidates validated 3/3 under the frozen `content_bootstrap_r2_mas_teardown_leaf_candidate_teardown_leaf_001_manifest.json` manifest.

The raw body and instruction export agree: test offset `0x10`, conditionally pass its value to the close wrapper and clear it; then test offset `0x128`, conditionally pass its value to the free wrapper and clear it; return zero. Candidate differences were evidence ordering, wording, owner spelling, and whether classified runtime cuts were repeated under `external_dependencies`.

The reconciled contract uses only dword widths visible in the body, classifies both cuts as CRT boundaries, and retains owner, concrete resource type, wrapper ABI, thread, and wider ordering as unknown. This is a static teardown contract, not runtime confirmation.
