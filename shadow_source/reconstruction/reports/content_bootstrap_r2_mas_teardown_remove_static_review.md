# Content bootstrap R2 MAS single-node teardown static review

Scope: `0x0053CE40` after promotion of its game-owned cleanup dependencies. Three independent candidates validated 3/3 under the frozen `content_bootstrap_r2_mas_teardown_remove_candidate_teardown_remove_001_manifest.json` manifest.

Raw C and the IDA instruction export agree on the full recovered sequence: walk from global head `0x008B8F14` through offset `0x130`; return zero if absent; patch predecessor `0x130` and successor `0x12C`; update the head when no predecessor exists; invoke `0x0055FE30`, `0x00557470`, and the CRT free wrapper; decrement `0x008B6AC0`; return zero.

Candidate differences were type spelling, evidence ordering, lifecycle labels, prose, and whether the CRT cut was repeated as an external dependency. The reconciled contract retains owner identity, synchronization, corrupt-list behavior, count underflow, allocator pairing, and ABI as unknown. It makes no runtime-safety claim.
