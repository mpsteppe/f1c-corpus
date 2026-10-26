# physics_id — recover F1C's physics solver as a behavioral model

Goal: turn the opaque physics kernel (407 anonymous funcs, no strings, no globals —
[docs/15](../../docs/15-analysis-limits.md)) into a **spec**, by treating it as a black
box: drive known inputs, record outputs at the 864 Hz physics tick, fit a model. This
is the one thing static RE structurally cannot get, and the hard ceiling of the
open-source-recreation ladder ([docs/33 §5](../../docs/33-capability-bible.md)).

## Staged plan (each stage gates the next; each needs the game RUNNING)

| Stage | Tool | Answers / produces | Gating unknown it kills |
|-------|------|--------------------|--------------------------|
| **0. Channel discovery** | `map_channels.py` | Which vehicle-struct offsets are live telemetry (grip/slip/load/speed/temp) | "Does the struct expose the channels we want to fit?" |
| **1. Input-drive proof** | *(next)* | Set ONE input (e.g. tire load) between ticks, read output — deterministically | "Can we drive inputs without perturbing the measurement?" |
| **2. Tick-locked capture** | *(next)* | Hook physics tick `0x004441f0`, sample per-call = true 864 Hz | Polling jitter → clean synchronous samples |
| **3. Multi-instance / headless** | *(next)* | Run N copies (null-present D3D8 proxy?) | Sets real collection throughput |
| **4. Active-learning sweep + fit** | *(next)* | Surrogate NN (GPU) picks next samples; symbolic regression recovers equations | The actual model |

**Do not build stage N+1 before stage N's output is in hand.** The GPU/fitting end
(stage 4) is the easy part; the harness + headless questions (stages 1–3) are the risk.

## Run stage 0

1. Launch the game, start a **practice/hotlap**, get the car **on track and moving**.
2. `python map_channels.py --secs 20` (drive the car during the 20 s).
3. Read the ranked "LIVE CHANNELS" table it prints. High-variance offsets during
   driving = candidate physics channels. Raw samples in `channels.csv`.
4. For each channel you care about, **confirm against raw .c** (the physics update
   `FUN_004441f0`, tire funcs) before trusting the label — offsets here are GUESS-tier.

## Hardware note (RTX 5080 + 3090, i7-12700K, 32 GB)

The **game is the throughput bottleneck**, not the GPUs — F1C is single-threaded
DirectX8, you can't GPU-parallelize it. Collection is CPU/game-bound (a few instances);
the GPUs are ~overkill for tabular-regression fitting. So stage 4 is architected for
**sample efficiency** (active learning: GPU surrogate chooses the fewest, most
informative inputs) rather than max FLOPS. 32 GB RAM is the tightest resource once
multiple instances + capture + fitting run together — stream samples to disk.

## Trust

Everything this produces is DERIVED/runtime — the read path (Frida attach, telemetry
read) is PROVEN (see `tools/trace/`, `monitor_output/`, F1CLiveUI in
[docs/11](../../docs/11-plugin-f1cliveui.md)), but the offset→meaning mapping is GUESS
until confirmed against raw `.c`.
