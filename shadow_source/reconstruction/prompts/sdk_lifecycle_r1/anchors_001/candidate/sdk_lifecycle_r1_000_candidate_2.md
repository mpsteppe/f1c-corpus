# Reconstruction candidate task sdk_lifecycle_r1_000_candidate_2

Read and obey `tools\agents\F1C_RECONSTRUCTION_CANDIDATE_WORKER.md` completely.

Packet: `shadow_source\reconstruction\packets\sdk_lifecycle_r1\sdk_lifecycle_r1_000.json`
Schema: `shadow_source\reconstruction\schemas\contract.schema.json`
Logical contract ID (write this exact value): `sdk_lifecycle_r1.packet_000.v1`
Candidate ID (provenance only, not the contract ID): `candidate_2`
Write your one JSON result to exactly this path: `shadow_source\reconstruction\candidates\sdk_lifecycle_r1\sdk_lifecycle_r1_000\candidate_2.json`

Validate only that file with: `python tools/reconstruction_pipeline.py validate-candidates --path shadow_source\reconstruction\candidates\sdk_lifecycle_r1\sdk_lifecycle_r1_000\candidate_2.json`.
