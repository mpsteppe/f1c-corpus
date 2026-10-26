# f1c-frida-trace — deep reference

Depth for `SKILL.md` in this directory. Read when authoring/reading a Frida agent, driving
`watch_run.py` interactively, or unlocking the trace clamp. Addresses live in the tool files
and the canonical docs, not here.

## 1. Frida-first doctrine (why every mod is tested here first)

A Frida `.js` patches memory in the LIVE process. Two properties make it the mandatory first
rung of testing:
- **Reversible.** It exposes a `restore()` that writes the original bytes back — in-session
  undo, no exe touched.
- **Survives integrity checks.** A patched on-disk exe can trip copy-protection / AV; a
  post-load memory patch does not. This is why `MODDING_PLAYBOOK.md §Gotchas learned the hard
  way` says: if the baked exe is flagged, use the Frida memory patch.

Graduation criteria `.js` → baked patch: the Frida version must produce the CONFIRMED
in-game observable (not just "the write landed"). Only then bake the same edit list to a COPY
via `f1c-byte-patch`. The `.js` stays as the reversible reference twin (see the cut_track_dq
pair: `apply_cut_track_dq.py` + `cut_track_dq.js`, same EDITS list).

## 2. agent.js anatomy (`tools/trace/agent.js`)

The trace agent is a plain Frida script. Its shape:
- An `IMAGE_BASE` constant pinned to the game's fixed non-ASLR load base — because the exe
  never relocates, agent addresses match Ghidra/IDA directly (the base value is in the tool
  source and in INDEX.md §Key facts a fresh LLM needs; do not re-key it from memory).
- A `HOOKS` object grouping target `[address, short_name]` pairs by subsystem (main_loop,
  frame_dispatch, race_tick, physics, ai, render, …). Each hook uses
  `Interceptor.attach(ptr(addr), { onEnter/onLeave })` to record entry order + timing.
- `send(...)` streams rows back to the Python controller, which writes the log under
  `tools/trace/output/`.

A watch agent (from `mod_pipeline.py watch`, e.g. `investigations/ai_drying/ai_drying_watch.js`)
is simpler: a `GLOBALS` array of `{addr,label,type}` and optional `STRUCTS`, a `readVal()`
switch (float/double/int/byte/ptr), a `send('CSV_HEADER:...')` then a timer polling at `HZ`
emitting `send('CSV_ROW:...')`. You rarely hand-write these — generate with `mod_pipeline.py
watch <seed.json>`.

## 3. Reading a sample trace

Trace logs (`tools/trace/output/*.log`) are line-per-hook in execution order with frame
markers and thread ids. Feed them to `analyze_trace.py`:
- `--summary` → call counts, hot functions, frame stats.
- `--frame N` → what ran in one frame.
- `--threads` → which thread each hook fired on (physics + AI ran on the SAME thread at
  ~840Hz in past captures; render on another — that is how you learn threading).
- `--doc PATH` → writes a generated markdown doc from the trace.

State-only captures (`f1c_trace.py -S`) are tiny: they log only writes to the known
state-var globals — ideal for watching a race phase progression without the physics firehose.

## 4. watch_run.py interactive session

`python watch_run.py <agent.js> --interactive` (cwd `tools/mod_pipeline/`) attaches Frida,
loads the agent, streams CSV to `watch_capture.csv`, and gives a prompt. Commands (the agent
must export matching rpc):
- `row` — latest values, `header` — CSV header.
- `poke <off> <val>` — writes S32 to EVERY AI car at that struct offset, skips the player.
  ⚠ this WRITES live game memory — it is a probe, not a shipped mod.
- `dump <idx> <start> <end> <step>` — hex/interpreted dump of a vehicle struct range.
- `q` / `quit` / `exit`, `help` / `?`.
Precondition: `pip install frida`, game running. Not running → `ERROR: '<PROCESS>' not
running. Start a race first.`

## 5. patch_trace.py clamp mechanics

The game clamps the trace level to a hard max of 2. `patch_trace.py` raises that by patching
two immediate bytes in the exe (a `cmp imm` and a `mov imm`). Both expected originals are the
clamp value; if the tool sees anything else it warns `expected both 0x02; already patched or
wrong exe/offsets` and you STOP. It backs up to `<exe>.bak` once; `--restore` reverts.

This mechanism is owned by `f1c-source-recovery` (canonical mining procedure there); the
outline below is context only:
1. Archive `LOG/trace.txt` FIRST — it is overwritten every run (this warning is verbatim in
   the "Runtime procedure (after static mining)" section of `work/BREAKTHROUGH_trace_mining.md`).
   Use a timestamped copy so reruns do not self-clobber.
2. `--level N --dry` to preview, then apply.
3. `LIVE:` launch the game with the `notrace` cmdline arg — counterintuitively this ENABLES
   tracing per the game's parser — play a session.
4. Read the new `LOG/trace.txt`: every `Entered Class::Method()` line is an original name.
5. `--restore` to revert the exe.

Turning those recovered names into doc renames is NOT this skill — hand off to
`f1c-source-recovery` (workspace-isolated, exits via `[MERGE-READY]`).

## 6. The self-documentation payoff

Per `work/DISCOVERY_external_sources.md`, ~60 `Entered X::Y()` strings are already mapped to
function addresses in `tools/ida_strings.csv` (ref_funcs column) — the static half needs no
game run. Raising the trace level is the runtime half: a live, self-narrated execution log in
the engine's own terminology, directly comparable to (and correcting) the invented names in
`docs/`. It is described as the highest-value cheap work in the project.

---
Canonical sources: tools/trace/f1c_trace.py, tools/trace/analyze_trace.py, tools/mod_pipeline/watch_run.py, tools/patch_trace.py (all via _meta/toolfacts.md); work/DISCOVERY_external_sources.md §SOURCE 1 — The game's own debug trace system; tools/mod_pipeline/MODDING_PLAYBOOK.md §Gotchas learned the hard way
Last validated: 2026-07-18 against 6bcccfe
