# Chain: Win Videos — Post-Race Bink Video Playback (winRace.bik / windrivers.bik)

Seed: 0x004a0760  |  System: docs/06-session-race-logic.md  |  Depth: 1  |  Functions: 12

---

## Overview

Called from post-race UI handler (0x00486920) when race session ends. Checks championship standing and plays Bink video reward: winRace.bik for race win, windrivers.bik for championship win. All 12 callees are leaf functions — cursor control, sound setup, Bink decoder, championship checks, input polling. Sets DAT_005cc9e8 = 3 on completion.

## Call Tree

```
0x004a0760 — Win Videos  [trigger: post-race UI handler]
  +-- 0x004186a0 — cursor hide
  +-- 0x004b17b0 — sound setup
  +-- 0x0042bc10 — [undocumented]
  +-- 0x004f9b70 — Bink play  [plays .bik files]
  +-- 0x004c2850 — championship check
  |     +-- 0x004c15a0 — season finished check (== 3)
  +-- 0x004c1390 — [undocumented]
  +-- 0x004c2c10 — [undocumented]
  +-- 0x004c2a80 — [undocumented]
  +-- 0x004c2810 — [undocumented]
  +-- 0x0047c360 — input key check
  +-- 0x0041daf0 — [undocumented]
```

## Step-by-Step Trace

### Level 0: 0x004a0760 — Win Videos

**Trigger:** Called from post-race UI flow after race completion
**Called by:** 0x00486920 (post-race UI handler)
**Purpose:** Plays championship/race win Bink video during post-race flow

**Key actions:**
1. Hides cursor via 0x004186a0, sets up sound via 0x004b17b0
2. If escape not pressed AND player mode==1 AND DAT_007d032c==1 (videos enabled):
   - Plays <track_path>\winRace.bik via 0x004f9b70 (Bink decoder)
3. Checks championship via 0x004c2850:
   - If championship won: checks season finished (==3) via 0x004c15a0
   - If human driver (+0x19c==0): plays <track_path>\windrivers.bik
4. Falls through to 0x004c2a80/0x004c2810 for alternate paths
5. Checks input via 0x0047c360 for menu display
6. Sets DAT_005cc9e8 = 3

**Globals used:** DAT_007d032c (videos enabled), DAT_007d0410 (mode), DAT_007c56a4 (session type), DAT_005cc9e8 (write)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| 0x004a0760 | DAT_007d032c | Check videos enabled | skip/play |
| 0x004a0760 | track_path + "winRace.bik" | Bink play | video rendered |
| 0x004c2850 | championship data | Check if won | windrivers.bik path |
| 0x004a0760 | — | Set completion flag | DAT_005cc9e8 = 3 |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_005cc9e8 | (unknown) | 0x004a0760 | Set to 3 on completion |

## Notes

- All 12 callees are leaf functions — no further recursion needed
- Bink play (0x004f9b70) is the main video decoder — part of Bink/RAD Game Tools library
- Championship check uses driver struct field +0x19c (human flag)
---
