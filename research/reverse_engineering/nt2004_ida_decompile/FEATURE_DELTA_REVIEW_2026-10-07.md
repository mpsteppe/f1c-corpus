# NT2004 versus F1 Challenge: prior research review

Date: 2026-10-07 (local time). Task stage: investigate.
Product: F1C SDK/research platform; governance lists the SDK at implement,
candidate maturity. This review does not change product stages.

## Objective and boundaries

Recover earlier searches for features present in NT2004 and missing from
vanilla F1C; check important claims against the preserved decompiled corpus
and distinguish vanilla omissions from capabilities supplied by current mods.
Acceptance: identify prior work, recover candidates, correct material errors,
record evidence and unresolved verification. No implementation, live memory
access, game launch, installation, executable modification or promotion.

## Previous research entry points

- [Original feature-delta survey, 2026-07-31](../../../f1c_ida_decompiled/investigations/nt2004_feature_delta/README.md): 14-entry verdict table; static DERIVED conclusions, not runtime proof.
- [Caution-system port paper](../../../f1c_ida_decompiled/docs/48-nt2004-caution-flag-system-port.md): steward, command transport, pace control, ordering, vehicle and enforcement layers.
- [NT2004 Safety Car map](SAFETY_CAR_MAP.md).
- [Corpus handoff](HANDOFF.md): binary identity, extraction method and cross-match limitations.
- [Canonical findings](../../../f1c_ida_decompiled/findings.jsonl): July/August corrections, including session ladder semantics, incompatible command queues and a retracted order-preservation measurement.

The SDK route command classifies the July survey as historical-investigation.
It is prior art, not current execution authority. Existing files were preserved.

## Recovered candidates and present interpretation

| Feature | Evidence and interpretation | Current relevance |
|---|---|---|
| Full-course caution / pace car | Strong static map of the NT2004 steward and pace system; vanilla F1C lacks the complete equivalent. | Already supplied by the Safety Car mod. Governance records paid beta shipment, with wider acceptance and re-entry/HUD limitations. |
| Red flag | Dormant machinery in both games. NT2004 `sub_460A50` literally returns zero; the historical trigger analysis must be read with the later session-ladder correction. | F1C Red Flag mod has shipped. Do not present this as an untouched opportunity. |
| No-passing enforcement under caution | NT2004 `sub_4DF490`, `sub_4DFF10`, `sub_4DF420`: geometry checks, penalties and lap deduction. | Remaining enforcement research candidate; this review does not establish which exact pieces current SC/RF releases implement. |
| Directional pit-speed offences | NT2004 `sub_4DDB70` distinguishes entry, exit, both, and excessive speeding. F1C `sub_4BCCC0` accumulates speeding while inside the lane and issues the generic offence on exit. | Concrete static delta worth further investigation. |
| Richer penalties and stacking | NT2004 `sub_4DC690` dispatches Stop/Go, Pass-Through and Start At End Of Longest Line; `sub_4DC900` adds 15 when an incoming type-1 penalty meets existing type 1. F1C's examined `StopGoPenaltyHandler` uses one duration byte and an existing-penalty guard. | Good bounded research lead; safe serving, timing, AI/player parity and integration are unverified. Do not call it a trivial port. |
| Lap deduction | NT2004 `sub_4DF420` subtracts `ArgList` from `this[3]`, posts a penalty, and announces deducted laps. | NASCAR-specific policy, useful as an implementation reference rather than an F1 requirement. |
| Wall-riding warning/penalty | NT2004 `sub_4DDB70` warns then penalizes when `dword_75CBB0 == 7`, and invalidates a lap under a separate `== 5` gate. | Static mechanism exists; the old survey mislabeled those gates as caution versus normal race. |
| Track cutting / wrong way | F1C already issues Stop/Go for repeated or severe cutting and disqualifies sustained wrong-way driving. | Caution-specific consequences may differ; generic track-cut penalties are not absent in F1C. |
| Drafting AI / draft HUD | NT2004 string index contains `draft some car`, `draft`, `break draft`, `DRAFT_01.bmp`, `DRAFT_02.bmp`; no draft/slipstream tokens found in F1C's index. | OPEN: absence of strings does not prove absence of aerodynamic slipstream physics. Draft-benefit implementation and any missing tactical behaviour remain unlocated. |
| Additional AIW waypoint fields | Original survey maps NT2004 extras such as `wp_cheat`, `wp_stockcarlat`, `wp_pitlane`, transitions, locked lats and marks. | Historical static lead, not individually revalidated in this pass. Potential line/transition research; no proven F1 benefit yet. |
| Caution HUD and rule levels | Original survey records caution messages and Off / Black Only / All rule levels. | Supporting systems, mostly NASCAR policy; not revalidated as independent port targets here. |
| Career economy / sponsors / research | NT2004 code references sponsor interest/contracts and research data; `sub_410E10` loads them and `sub_4115D0` writes research levels. F1C index lacks research/sponsor terms. | A larger game-mode reference. The workspace career platform is already an active prototype with pending validation and repairs. |
| In-race ESC pause menu | Later findings identify NT2004 `sub_4BACD0` as a port reference; inspected code pauses/resumes simulation and audio. | Omitted from the initial 14-row survey; subsequently supplied by the shipped ESC Pause Menu mod. |
| AI aggression | Original survey explicitly excluded it because F1C has per-driver `TrackAggression`. | Not a missing feature. Current Driver AI Toolkit also ships. |
| Alleged Chase playoff | The sole NT2004 code xref for `Chase` is `sub_487D90`, alongside `Cockpit`, `Roof`, `Nose`. | DISPROVEN as support for the survey's playoff claim: this is a camera option. No playoff implementation established. |

## Evidence tiers and corrections

CONFIRMED static observations in this review:

1. The Chase string reference is a camera-menu constructor, not evidence of a playoff.
2. F1C `sub_4BCCC0` calls `StopGoPenaltyHandler(..., aCutTrack, 10)` when
   `(violation_count > 1 || severity > 2.75) && session_type == 7` after the
   severity threshold and penalties-enabled gate. The old lap-invalidation-only
   description is incomplete.
3. NT2004 wall-riding is gated by session value 7, not an explicit caution
   predicate. Prior finding `nt2004-75cbb0-is-session-ladder-not-caution-phase`
   establishes why the original survey's interpretation is wrong.
4. NT2004's penalty accumulator contains a literal `this[19] += 15` for two
   successive type-1 penalties. Runtime timing and serving remain unverified.

OPEN: F1C slipstream absence. The July survey inferred too much from token
absence. Later October 3 AI findings describe following/attack patience and
lane-change behaviour; these do not prove or disprove aerodynamic wake effects.
This review neither claims F1C has aerodynamic slipstreaming nor that it lacks it.

The 4,014 cross-matched functions in the old survey combine 1,261 exact matches
with structural fingerprints. HANDOFF explicitly warns about structural
collisions and unmatched false negatives. An unmatched function is not proof
of a missing feature. The later trusted structural file reports 1,874 matches,
still using a heuristic; the 51% figure is historical method output, not a
verified feature-equivalence percentage.

## Useful next investigations

1. Specify drive-through and directional pit-speed behaviour in F1 terms;
   compare current F1C penalty storage, serving and race-results paths before
   designing any extension.
2. Audit current SC/RF enforcement against NT2004 geometry/penalty machinery;
   identify actual release omissions rather than repeating the July vanilla list.
3. Trace NT2004 drafting data-table consumers and both games' aero-force
   calculations, separating drag benefit from AI lane choice and HUD display.
4. If career work resumes, use NT2004 economy/R&D functions as references,
   alongside the existing career platform's documented defects and owner gates.

All native behaviour and port acceptance remain pending. No runtime safety,
performance, binary compatibility or completed implementation is claimed.

## Verification, changed state and restoration

- Read required workspace/SDK orientation documents and NT2004 HANDOFF.
- SDK `start --json`: freshness.stale false; explicit user research took
  precedence over unrelated checkpoint objectives.
- Queried canonical findings for NT2004, slipstream and draft; inspected F1C
  penalty function through the SDK front door; read focused NT2004/F1C functions
  and compared extracted string records.
- Workspace validator before and after documentation: one existing error,
  unexpected top-level `.claude`, zero warnings. Left untouched.
- No builds or SDK regeneration: documentation/static review only.
- Added this report, a research index link, and appended correction/open entries
  to canonical findings. Governance status and historical survey unchanged.
- Complete prior research index preserved at
  `workspace_organization_audit/NT2004_FEATURE_REVIEW_BEFORE_2026-10-07/research_README.md`.
  Restoration: compare the preserved index and remove only the new link in an
  owner-authorized edit if needed; preserve this report and findings as evidence.

Documentation gate: report indexed from research/README.md; static facts,
inferences and pending native validation explicitly distinguished; reviewed
UTF-8 without BOM and checked text for encoding damage.

Wasted-effort check: initial broad listings/query output was truncated and
required narrower reads; nonexistent game_mechanics path and Windows wildcard
path arguments caused avoidable search errors. No broad builds/tests. No polling
or idle waits. Future review should start with this report and bounded findings.
