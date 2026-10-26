# Chain: Config.ini Parser — Initial Config Loading and Component Setup

Seed: FUN_00421cd0  |  System: docs/09-track-system.md  |  Depth: 2  |  Functions: 44+

---

## Overview

Triggered by Game::Main (FUN_0045b200) during earliest initialization. This function detects Windows version (XP/NT/2000), copies Config.ini to user's Documents folder on first run, then parses VERSION/IPADDRESS/VCRFILE/VCRCYCLE settings from Config.ini. Dispatches ~20+ component setup functions via a state machine loop (FUN_00587ca0 + FUN_005651b0) with 40+ branching paths, setting fields in a config struct at offsets 0xb8–0xe8. Writes to path registry (FUN_00566650) for track/game directory setup. Final effect: all config-driven subsystem init parameters are populated and registered.

## Call Tree

```
FUN_00421cd0 — Config.ini Parser  [called by Game::Main (FUN_0045b200)]
  +-- FUN_005881c0 — [undocumented string/file utility]
  +-- FUN_004230c0 — [undocumented system init]
  +-- FUN_00423250 — [undocumented admin check]
  +-- SHGetSpecialFolderPathA — Win32 API [Documents folder path]
  +-- CopyFileA — Win32 API [Config.ini copy on first run]
  +-- FUN_0058ba75 — [undocumented string util]
  +-- FUN_00566650 — Path Registry  [registers game/config directory paths]
  |     +-- FUN_005679c0 — String Search  [INI section/key lookup]
  +-- FUN_0058815f — [undocumented format util]
  +-- FUN_00589671 — [undocumented string util]
  +-- FUN_00587db0 — [undocumented file util]
  +-- FUN_00422be0 — [undocumented config util]
  +-- FUN_004d7a50 — Debug Gate  [assert/scope trace]
  +-- FUN_00587ca0 — [undocumented state machine driver]
  |     [dispatches 40+ component setup paths]
  +-- FUN_005651b0 — [undocumented state machine dispatch]
  +-- FUN_00587c20 — [undocumented file util]
  +-- FUN_00565520 — [undocumented string util]
  +-- FUN_0058850f — [undocumented compare/match]
  +-- FUN_005654a0 — [undocumented string util]
  +-- FUN_00565760 — [undocumented string util]
  +-- FUN_00404ef0 — [undocumented game mode util]
  +-- FUN_00404e60 — [undocumented path/name registry]
  +-- FUN_00404d50 — [undocumented game mode util]
  +-- FUN_00404d30 — [undocumented game mode util]
  +-- FUN_00404cc0 — QuickRace / Game Mode Lookup  [string match -> game mode ID]
  |     +-- FUN_00588410 — String Compare
  +-- FUN_00404d40 — [undocumented game mode util]
  +-- FUN_00421ad0 — Path Registry / String Set  [docs/08]
  +-- FUN_00421ab0 — [undocumented path registry]
  +-- FUN_00421af0 — Path Registry / String Set
  +-- FUN_00421b10 — [undocumented path registry]
  +-- FUN_00421a70 — Path Registry / String Set  [docs/20]
  +-- FUN_00421a50 — Path Registry
  +-- FUN_004219b0 — Path Registry
  +-- FUN_00421a90 — Path Registry / String Set  [docs/08]
  +-- FUN_00421a30 — Path Registry / String Set  [docs/08]
  +-- FUN_00421a10 — Path Registry / String Set
  +-- FUN_004219f0 — Path Registry Step 2
  +-- FUN_004219d0 — String Copy Utility
  +-- FUN_00421990 — Path Registry / String Set  [docs/09]
  +-- FUN_00421970 — [undocumented path registry util]
  +-- FUN_00421950 — Path Registry / String Set
  +-- FUN_00421930 — String Copy with Realloc
  +-- FUN_00421910 — Second Handler
  +-- FUN_004218f0 — [undocumented]
  +-- FUN_004218d0 — Path/Name Registry
```

## Step-by-Step Trace

### Level 0: FUN_00421cd0 — Config.ini Parser

**Trigger:** Called once during Game::Main startup, before any state machine loop begins.
**Called by:** FUN_0045b200 (Game Main Entry, docs/01) — step 2 of init sequence.
**Purpose:** One-time config initialization: OS detection, Config.ini discovery/copy, setting dispatch.

**Key actions:**
1. Detects Windows version by comparing OS version string against "Windows XP", "Windows NT", "Windows 2000"
2. On XP/NT/2000: calls FUN_00423250 (admin check). If not admin, gets CSIDL_DOCUMENTS path, copies Config.ini to user documents folder on first launch
3. Dispatches ~20+ component setup functions via FUN_00587ca0/FUN_005651b0 state machine loop with 40+ branching paths (setting fields at extraout_ECX+ offset 0xb8–0xe8)
4. Parses VERSION/IPADDRESS/VCRFILE/VCRCYCLE settings from Config.ini sections
5. Calls FUN_00566650 (Path Registry, docs/08) to register game config directory paths

**Data passed to callees:** extraout_ECX config struct pointer, string buffers for path registration

### Level 1: FUN_00566650 — Path Registry

**Trigger:** Called to register config directory/season paths during init.
**Purpose:** Registers string paths into a global path registry (docs/08).

**Data passed:** param_1 (path string), param_2 (path category index)

### Level 1: FUN_00404cc0 — QuickRace / Game Mode Lookup

**Trigger:** Called during config parsing for mode detection.
**Purpose:** String comparison to identify game mode (QuickRace, Championship, etc.) from config string.

**Data passed down:** Config string pointer → FUN_00588410 (string compare)

### Level 1 (selected): FUN_00421ad0/1af0/1a70/1a90/1a30/1a10 — Path Registry Functions

**Trigger:** Called repeatedly to register per-component directory paths.
**Purpose:** Sets each component's file path in the global path registry. Each of the ~20 calls registers a different path (season dir, track dir, game data dir, etc.)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00421cd0 | Config.ini path | OS detection + read config | Version string, IP, VCR params |
| FUN_00421cd0 | Config values | State machine dispatch (42 callees) | Component setup states |
| FUN_00566650 | Path strings | Registry insert | Path registry populated |
| FUN_00404cc0 | Mode string | String compare | Game mode ID |
| FUN_00421930 | Source string | String copy with realloc | Target buffer filled |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007c56b0 | VersionFloat | callers writes | ~1.025f version constant |
| DAT_007c56b4 | VersionString | callers writes | "ilya! _1011" watermark |
| DAT_007c56ad | InitFlag | callers writes | 0 initialization flag |
| DAT_007c56a0 | SessionMode | callers writes | 3 (session mode constant) |
| DAT_007ce2a0 | AppHandle | callers writes | Win32 app instance handle |

## Notes

- 42 callees is exceptionally large. The 5 most complex subtrees (state machine dispatch FUN_00587ca0, path registry FUN_00566650, game mode lookup FUN_00404cc0, admin check FUN_00423250, string copy FUN_00421930) account for ~30% of total call graph depth. Remaining 37 callees are leaf path registry sets, string utilities, and format helpers omitted for clarity.
- This function is a one-shot init — never called again during the game session.

---

---
