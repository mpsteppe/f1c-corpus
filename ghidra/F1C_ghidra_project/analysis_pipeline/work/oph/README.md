# Safety Car Plugin for F1 Challenge 99-02

A drop-in `oph.dll` that adds safety car deployment to the game.

## What It Does

- Monitors for DNFs (retirements) during a race
- After N DNFs (default: 1), deploys safety car automatically
- Forces all AI to enter **safety car follow mode** — reduced speed, no overtaking
- Shows HUD messages: "SAFETY CAR DEPLOYED", "SAFETY CAR ON TRACK", etc.
- After ~90 seconds, withdraws safety car and restores green-flag racing
- Cooldown period (~45s) prevents back-to-back deployments
- **Manual override** — press **F9** to deploy, **F10** to withdraw anytime during a race

## How It Works

The game already has a built-in AI command `0xe` labeled "safety car" in the decompilation docs, and an AI flag at vehicle struct offset `+0x443c` that enables reduced-speed following. This code was left over from a cut feature — the DLL activates it.

No 3D model, no vehicle spawning. It uses the game's own AI infrastructure.

## Installation

1. **Build** the DLL (see below) OR download a pre-built release
2. Copy `oph.dll` into your **F1 Challenge 99-02** game directory (same folder as `F1 Challenge Online.exe`)
3. Launch the game normally

**Important:** If your game directory already has an `oph.dll`, back it up first. This replaces it.

## Uninstall

Delete `oph.dll` from the game directory.

## Building

### MinGW (cross-compile)

```
i686-w64-mingw32-gcc -shared -Os -s -o oph.dll oph.c -static-libgcc
```

Or use the Makefile:

```
make mingw
```

### MSVC

From a Visual Studio command prompt:

```
cl /LD /O2 /GS- oph.c
```

## Configuration

Edit `oph.c` and adjust these values before compiling:

| Constant | Default | Description |
|----------|---------|-------------|
| `DEPLOY_DNF_THRESHOLD` | 1 | DNF count to trigger automatic deployment |
| `ACTIVE_DURATION_MS` | 90000 | How long safety car stays out (ms) |
| `COOLDOWN_MS` | 45000 | Min time between deployments (ms) |
| `TICK_MS` | 200 | Monitor thread tick rate (ms) |
| `KEY_MANUAL_DEPLOY` | `VK_F9` | Key to force safety car deployment |
| `KEY_MANUAL_WITHDRAW` | `VK_F10` | Key to force safety car withdrawal |

## Technical Details

### Game Addresses Used

| Address | Description |
|---------|-------------|
| `0x007c54f0` | Vehicle pointer array |
| `0x005c329c` | Vehicle count |
| `0x007c56a8` | Race phase |
| `0x007c56a4` | Session type (7=race) |
| `0x007d0308` | Race active flag |

### Vehicle Struct Offsets

| Offset | Field | Values |
|--------|-------|--------|
| `+0x4064` | FinishState | 0=running, 2=DNF |
| `+0x443c` | SafetyCarFollow | 0=normal, 1=follow mode |
| `+0x44a8` | CmdQueueArray | Pointer to AI command queue |
| `+0x44b0` | CmdQueueCount | -1=empty, 0..9=entries |

### HUD Display

Uses `FUN_0045bd10` at `0x0045bd10` (__cdecl) — the game's own text display function, called with priority 3.

## Limitations

- **No safety car vehicle** — AI just slow down and follow leader using existing path logic
- **No overtaking ban enforcement** — AI won't overtake naturally when in follow mode, but there's no hard block
- **No yellow flags** — no visual flag marshal posts change
- **No unlapping** — backmarkers won't unlap
- **Race-only** — only activates during session type 7 (race)
- **Single deployment at a time** — cooldown prevents stacking

## Future Ideas

- Add actual safety car vehicle spawn (reuse existing car model with repaint)
- Add yellow flag HUD overlay
- Add pit lane closure during safety car
- Variable deployment duration based on track position

## License

Public domain. Use at your own risk.
