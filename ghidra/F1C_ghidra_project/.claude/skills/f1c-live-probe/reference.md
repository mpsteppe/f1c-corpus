# f1c-live-probe — deep reference

Worked transcript: hunting an unknown offset with snapshot → act → diff.
All command syntax is from `_meta/toolfacts.md` §tools/poke.py. Output lines below
are shape-illustrations, not recorded values — addresses are shown as
`DAT_XXXXXXXX` placeholders on purpose (real names/addresses live in
`docs/12-globals-reference.md` and the SDK; never copy them from a skill).

## The problem shape

You suspect "something in memory changes when the player does X" (pits, gets a
penalty, toggles an option) but no SDK name matches. Watching one guessed global
(`poke.py watch`) only works if the guess is right. The snapshot→diff loop instead
observes ALL known globals and lets the game tell you which ones moved.

## Transcript

Terminal 1 — capture baseline while the game sits in a stable state (e.g. garage):

```
$ cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/poke.py snapshot before.json
```

Expected shape: a confirmation that all known globals were captured to
`before.json`. The file is plain JSON — you can open it, but you never need to.

Now perform EXACTLY ONE in-game action. Discipline matters: one action per
snapshot pair. If you pit AND change a setting, the diff cannot tell you which
change caused which delta.

Then diff:

```
$ cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/poke.py diff before.json
```

Expected shape (illustrative):

```
DAT_XXXXXXXX  (SomeTimerName)     12.31 -> 14.02
DAT_XXXXXXXX  (unnamed)               0 -> 1
DAT_XXXXXXXX  (FrameCounterName)  88123 -> 91210
... many more rows ...
```

## Narrowing the candidate set

First diffs are noisy — timers, frame counters, RNG state all move constantly.
Narrow in three moves:

1. **Threshold.** Re-run with `--thresh 0.5` (or higher) to suppress jitter in
   float channels. `--thresh` is a float; default `0.0` shows everything.
2. **Null-action control.** Take a second snapshot pair where you do NOTHING for
   the same wall-clock time. Every global that appears in the null diff is
   ambient noise — subtract that set mentally (or with a scratch script) from the
   action diff.
3. **Repeat and intersect.** Run the action pair 2–3 times. The real state
   variable appears in every action diff and no null diff, usually with a clean
   discrete transition (`0 -> 1`, enum step) rather than a drifting float.

## Confirming the survivor

For each surviving candidate:

1. `LIVE:` watch it while repeating the action:
   ```
   cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/poke.py watch <tok> --hz 10
   ```
   It must transition exactly when the action happens, every time.
2. `LIVE:` write-test it (save replays/setups first):
   ```
   cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/poke.py write <tok> <value>
   ```
   poke prints before→after; log both plus the gate state (CLAUDE.md iron rule 6).
   Then check whether the game rewrites it: re-read after a second or two. A value
   the game re-derives every tick will not hold a poked value — your mod would
   need a per-tick writer (`f1c-dll-mod`) or a patch to the producer
   (`f1c-byte-patch` via `f1c-mod-lifecycle`).
3. Remember the trap: **log confirms write ≠ game reacted.** A candidate that
   accepts writes but produces no in-game effect may be a mirror/telemetry copy of
   the real state. Only a predicted in-game observable confirms you found the
   causal variable.

## What a finished hunt produces

- The candidate token (address + type) with its observed transition table
  (state → value), each row backed by a watch/diff run.
- A note on writability: holds a poke / rewritten per tick / write refused.
- Verdict wording per `INDEX.md` §Trust tiers — READ THIS BEFORE TRUSTING ANY
  FILE: the offset is at best CONFIRMED-behavior for YOUR observation; its
  semantic label stays GUESS until cross-checked against raw `.c`
  (`f1c-verify-claim`).
- If it contradicts an existing doc label → flag `[CORRECTION]` in
  `work/CHANGELOG.md` (never silently edit docs — output rules per CLAUDE.md).

---
Canonical sources: `_meta/toolfacts.md` §tools/poke.py; `CLAUDE.md` §Iron rules; `INDEX.md` §Trust tiers — READ THIS BEFORE TRUSTING ANY FILE
Last validated: 2026-07-18 against 6bcccfe
