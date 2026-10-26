# Rejected premature R2 launch (2026-08-06)

This record preserves the reason the existing content/bootstrap worker batch
must not be promoted. The original prompts, launchers, immutable manifests,
logs, 34 candidate JSON files, and two database-lock failures remain at their
original paths so their provenance and frozen hashes are not broken.

- The one-worker smoke used an address/path-only packet and was incorrectly
  marked `RECONCILED` from one candidate.
- The 36-task pilot launched before the current preflight was complete.
- Two tasks (`content_bootstrap_003_candidate_2` and
  `content_bootstrap_005_candidate_1`) failed with `database is locked` and
  produced no candidate.
- The three candidates for each packet were not assigned one immutable logical
  contract identity, so their differing `contract_id` values cannot be treated
  as independent proposals for the same contract.
- The packets did not embed raw C, validated function IR, architecture context,
  or complete cut-edge contract dependencies.
- The strengthened validator reports 0 valid and 34 invalid candidates. This
  is a deterministic tooling rejection, not a judgment that every individual
  static observation in those files is false.

No candidate or reconciled record from this attempt is promotion-eligible.
