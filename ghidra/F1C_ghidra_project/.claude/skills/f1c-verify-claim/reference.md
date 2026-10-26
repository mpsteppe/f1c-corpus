# f1c-verify-claim reference — preflight grammar + worked probes

Companion to `f1c-verify-claim` SKILL.md. Command syntax source of truth:
`.claude/skills/_meta/toolfacts.md` §tools/preflight.py. All commands run from
`cd /c%USERPROFILE%/Desktop/F1C_ghidra_project`. Every probe below except `example`
is `LIVE:` (needs `F1 Challenge Online.exe` running; may need admin).

Placeholder convention: `0x00XXXXXX` / `+0xNNN` are shapes, not values. Real
addresses/offsets come from `docs/12-globals-reference.md` / `docs/13-struct-offsets.md`
(GUESS tier — that is exactly why you are probing them) or `CLAUDE.md` §Key pointers.

## Expression grammar

```
expr := atom (('+'|'-') hex)*
atom := '[' expr ']' | name | hexaddr
```

| Form | Meaning |
|---|---|
| `SessionType` | SDK global by name — case-insensitive EXACT match only. No substrings: substring resolution is a poke.py feature; preflight rejects partial names |
| `0x00XXXXXX` | raw absolute address (non-ASLR binary — VAs are stable) |
| `[0x00XXXXXX]` | deref: read u32 pointer at addr, use as base |
| `[0x00XXXXXX]+0xNNN` | deref then offset |
| `[[0x00XXXXXX]+0xNNN]+0xNNN` | nests arbitrarily (pointer chains) |
| `<expr>:float` | per-expr type override (probe only; `run` uses each fact's `"type"`) |

Types: `float double int32 uint32 int int16 uint16 int8 uint8 byte ptr`.
Probe defaults: `--type int32 --secs 2.0 --hz 30.0`.

## facts.json schema (for `run`)

```json
{ "name": "<claim_or_mod_name>",
  "facts": [
    {"id":"<fact_id>","expr":"<expr>","type":"<type>","expect":{...},"stable":true,"gate":true} ] }
```

- `expect` kinds: `{"eq":v}` | `{"in":[..]}` | `{"range":[lo,hi]}` | `{"nonzero":true}`
  (omit = readable-only check).
- `stable:true` — sampled for `--stable-secs` (default 2.0 s at 30 Hz); FAILs if the game
  rewrites the value (your write would be clobbered — the "writes stick ≠ game reacts" trap).
- `gate:true` — precondition (e.g. must be in a race); reported **GATE**, not FAIL,
  and excluded from the exit code.
- Output: one `PASS`/`FAIL`/`GATE` line per fact, then `<N> hard failure(s).`
  **Exit code = number of FAILed facts.** 0 = safe to compose. Template: `preflight.py example`.

## Worked probes

### 1. Named global, expected value known (claim: "SessionType equals the race value in a race")

```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/preflight.py probe SessionType
```
LIVE: game running, session loaded. Expected: integer samples; in a race the value
should match the race constant given in `CLAUDE.md` §Key pointers (7 = race — re-check
there, do not trust this file). Steady expected value = claim CONFIRMED for the session
you are in.

### 2. Type-override probe (claim: "this global is a float, not an int")

```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/preflight.py probe "TotalRaceLaps:float" --secs 1
```
Expected: a sane float (e.g. a plausible lap count). If reading it as int32 gives a
huge magic integer while `:float` gives a sane value, the doc's int claim is REFUTED —
this exact class (float stored, int documented) is a known `[CORRECTION]` pattern in
`work/CHANGELOG.md`.

### 3. Pointer deref (claim: "the player-vehicle pointer global holds a live pointer in-session")

```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/preflight.py probe "[PlayerVehiclePtr]" --type ptr
```
Expected: nonzero pointer while in a session; zero/`<unreadable>` in menus. If nonzero
only in-session, treat "in-session" as a `gate:true` fact in any facts.json built on it.

### 4. Deref + struct offset (claim: "vehicle field F lives at +0xNNN, type float")

```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/preflight.py probe "[PlayerVehiclePtr]+0xNNN:float"
```
Substitute the offset from the docs/13 entry under test. Expected: values plausible for
the field's meaning that move when the game state moves (drive, pit, change setup).
Garbage magnitudes / NaN = offset or type REFUTED. Cross-check the dossier offset table
first (`f1c-locate` Step 4) — a `↳` row means the docs/13 offset belongs to a
sub-object and the plain deref WILL read garbage even though the doc is "sort of" right.

### 5. A failing run (claim with wrong expectation — what FAIL looks like)

facts.json fragment: `{"id":"phase","expr":"RacePhase","type":"int32","expect":{"eq":99}}`

```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/preflight.py run <path-to-facts.json>
```
Expected output shape:
```
FAIL  phase  RacePhase = <observed>  (expected eq 99)
1 hard failure(s).
```
Exit code 1 (= FAIL count). The correct response is NEVER "tweak the code until it
passes" — it is: the FACT is wrong; fix the claim (value, type, offset, or gate),
re-run, and if a doc asserted the wrong value, route to `f1c-doc-audit` for a
`[CORRECTION]`.

## Attach/resolve failure messages (verbatim, pattern-match these)

- `'F1 Challenge Online.exe' is not running — start the game first` → LIVE precondition unmet; stop, report unverified facts.
- `OpenProcess failed (run as admin?) — pid <N>` → elevate the shell.
- `mods/sdk/f1c_sdk.json missing — run: python tools/gen_sdk.py` → SDK absent; regenerating overwrites SDK files — do it deliberately, not casually.
- `unknown name '<tok>' (not in SDK; run tools/gen_sdk.py?)` → the token is not an
  exact (case-insensitive) SDK entry. Find the exact name via `python tools/poke.py
  list <substring>` and retry. Despite the message's hint, do NOT reflexively run
  gen_sdk.py — it overwrites both SDK files and is only warranted after a docs merge.

---
Canonical sources: CLAUDE.md §Iron rules; CLAUDE.md §Key pointers; REFERENCE.md §Verification Methodology (Architect role); INDEX.md §Trust tiers — READ THIS BEFORE TRUSTING ANY FILE
Last validated: 2026-07-18 against 6bcccfe
