# Rubric: f1c-frida-trace

Task prompt: "I think a per-frame global controls tire grip. Trace the game live to see what
writes it during a race, and test a memory override without touching the exe on disk."

Expected steps (in order):
1. Check prerequisites: `python -c "import frida; print(frida.__version__)"`; if
   ModuleNotFoundError → `pip install frida frida-tools`. Confirm the game is running for LIVE steps.
2. Choose the tracer: a seed-driven watch agent (`mod_pipeline.py watch <seed.json>` then
   `watch_run.py`) for a specific global, or `f1c_trace.py` for function/state traces.
3. LIVE: capture — e.g. `python tools/trace/f1c_trace.py --frames 3000 -o race_trace.log`
   (archive any prior output file first; runs overwrite).
4. Analyze offline: `python tools/trace/analyze_trace.py tools/trace/output/<file>.log --summary`.
5. Test the override REVERSIBLY with a Frida `.js` memory patch (has restore()); confirm the
   in-game behavior live.
6. Only after live confirmation, graduate to a baked patch on a COPY via f1c-byte-patch;
   keep the .js as the reversible twin.

For the trace-level path (if the task is name recovery):
- Archive `LOG/trace.txt` FIRST (overwritten per run) to tools/trace/output/.
- `python tools/patch_trace.py --level 10 --dry` then apply; launch with `notrace` arg;
  read the new trace.txt; `--restore` after. Hand name-mining to f1c-source-recovery.

Forbidden actions:
- Baking a patch to the exe before Frida-confirming it live (violates Frida-first doctrine).
- Rerunning a tracer / raising the trace level without archiving the prior trace.txt.
- Applying patch_trace.py when it warns the bytes are not the expected originals.
- Inlining volatile addresses into the skill.

Pass criteria:
- States the Frida-first doctrine (reversible + survives integrity checks) and the graduation
  criterion (.js confirmed live → bake to copy).
- Archives trace.txt / output logs before any overwriting rerun.
- Stops correctly at the first LIVE: step when the game is not running.
- Routes name-mining out to f1c-source-recovery and baking out to f1c-byte-patch.
