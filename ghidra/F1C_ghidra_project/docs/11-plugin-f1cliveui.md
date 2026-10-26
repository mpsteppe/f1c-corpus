# F1CLiveUIPlugin - External Plugin

## F1CLiveUIPlugin â€” How It Works

The plugin (`F1CUILive.jar`) is a standalone Java application that:

1. Reads `magic.ini` at startup to configure all parameters
2. Opens the running `F1 Challenge Online.exe` process via Win32 `OpenProcess`
   (JNA â†’ `Kernel32.dll` â†’ `OpenProcess(PROCESS_VM_WRITE, pid)`)
3. Reads live telemetry from shared memory via `F1C_readLiveData.exe` (native bridge)
4. **Writes back** to the game process using `WriteProcessMemory` to inject events

This is NOT a game plugin DLL â€” it is a separate process doing raw memory patching.

### Puncture Injection (`setFakePuncture`)

At scheduled time, the plugin writes `0.77f` to `tireConditions[worstTire]` at offset
`driverMemoryAddress - 4312` in the game process. The game then degrades the tire
naturally from that condition â€” not an instant flat. `removeFakePuncture` writes `0.75f`
(cleanup if driver already in pits).

### AI Error Injection

Writes to offsets within each vehicle's struct corresponding to internal flags
`DriverErrorRace083` / `DriverErrorNonRace082`, forcing the game's AI into an error
state for a scheduled window.

---



---

## Puncture Scheduling - Mechanics

## Puncture Scheduling â€” Mechanics

Source: `f1p_businessLogic/f1c_badEventsEngine.class`, method `schedulePunctures()`

Single global `TirePuncturesFrequency` from magic.ini. No per-driver override.

**Loop count:** `20 + 5 * TirePuncturesFrequency`  
**Time per event:**
```
t = 30000/frequency + nextGaussian() * 50000/frequency
t *= (1.5 + (11 - frequency) * 0.5)
# adjusted for lap count and session length
```
Only events where `t > elapsedTime + 30 && t < totalTime` are kept.
One additional guaranteed "unlucky" driver scheduled at t=40s if any events were added.

**Practical scale:**
- `frequency=2` (default) â†’ ~0â€“1 punctures per race (very rare)
- `frequency=3` â†’ occasional
- `frequency=5` â†’ several per race
- For reliable 1 puncture/race: use 4â€“5

---


---

## AI Error Scheduling - Mechanics

## AI Error Scheduling â€” Mechanics

Source: `f1p_businessLogic/f1c_badEventsEngine.class`, method `scheduleErrors(sessionNumber)`

**Per-driver frequency source (priority order):**
1. Driver's `.plg` file `AIErrorRaceFrequency` / `AIErrorQualyFrequency` â€” if present AND value â‰¥ 0
2. Falls back to `magic.AIErrorRaceFrequency` / `magic.AIErrorQualyFrequency`

Per-driver `.plg` override is a **hard override** â€” magic.ini value ignored for that driver.

**Session multiplier (qualifying only):**
- Session total time > 3630s â†’ multiplier = 4.0
- Session total time > 1830s â†’ multiplier = `2 * totalTime / 1830`
- Short session with `IncreaseExitPitRate` enabled â†’ multiplier = `0.2 * (20 - pitRate)`
- Short session, rate disabled â†’ multiplier = 4.0
- Race (session 7) â†’ multiplier = 1.0

**Time scheduling:**
```
effectiveFrequency = rawFrequency * multiplier / 10
for i in range(effectiveFrequency):
    t = 10000/frequency + nextGaussian() * 50000/frequency
    # adjusted for lap count
    add t to driver's error schedule
```
Higher frequency = more events, closer together. `AIErrorRaceFrequency=6` â†’ ~6 error
moments per driver per 2h race, spaced ~1667s Â± Gaussian apart.

---

