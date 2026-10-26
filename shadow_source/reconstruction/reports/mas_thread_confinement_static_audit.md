# MAS thread-confinement static audit and runtime gate

Date: 2026-08-06. Static call-graph evidence plus a prepared read-only runtime probe. The initially pending runtime gate was subsequently exercised; see `mas_lifecycle_runtime_validation_20260806.md`.

## Static result

The recovered process startup at `0x0058A19E` calls `GameMainEntry` at `0x0045B200`. Known MAS production, immediate removal, scene pruning, and resource-manager shutdown paths are reachable through the game initialization/setup graph. Representative complete paths include startup -> game main -> game init -> special-effects init -> root MAS load, and startup -> game main -> game setup -> options setup -> global-manager shutdown -> resource-manager shutdown.

The only raw `CreateThread` call recovered from the corpus is at `0x00585470`, and its entry is `0x00583D90`. The direct call graph reachable from that network/timing thread entry contains 54 functions and none of the MAS root, single removal, bulk prune, ownership bridge, resource setup, or resource-manager shutdown functions.

This strongly supports main-thread confinement for direct calls, but it is not proof: the thread entry performs virtual calls through slots `+0x50`, `+0x54`, and `+0x0C`, so indirect targets are not represented by the direct call graph. Several game loading roots are likewise disconnected because of indirect dispatch.

## Runtime gate

`shadow_source/reconstruction/tools/mas_lifecycle_probe.js` hooks the root loader, single removal, bulk prune, both lifecycle phase anchors, the live main-loop tick at `0x0042D8A0`, game-main entry, the recovered thread entry, and resource-manager shutdown. Each event records `Process.getCurrentThreadId()`. The main-loop marker fires only once per observed thread, so attaching after startup still identifies the active game-main thread without producing a per-frame log flood. Post-mutation snapshots walk the list read-only, compare the traversed and declared counts, verify reciprocal back links, and detect cycles or unreadable nodes.

Run only with the game already open:

```powershell
python shadow_source/reconstruction/tools/run_mas_lifecycle_probe.py --seconds 300
```

Exercise track loading, vehicle/cockpit/pit assets, a bitmap/font path, unloading back to menus, and normal shutdown. A promotion-quality trace requires one mutation thread, equality with the observed `GameMainEntry` thread, no mutation on the recovered network thread, no list invariant failures, no zero-result/no-object events, and a final empty live list after shutdown.

The probe attaches and reads only. It never starts the game, invokes game functions, patches instructions, or writes target memory. Its JSONL output remains evidence under `shadow_source/reconstruction/reports/`.

## Executed result

The 2026-08-06 single-player load/unload/shutdown trace observed all MAS mutations on the same thread as the live main-loop marker, 1,040 valid list snapshots with no actual invariant failure, and an empty list at shutdown. This supports main-thread confinement for the exercised path. The network-thread marker did not fire, so multiplayer/network lifecycle confinement remains unconfirmed.
