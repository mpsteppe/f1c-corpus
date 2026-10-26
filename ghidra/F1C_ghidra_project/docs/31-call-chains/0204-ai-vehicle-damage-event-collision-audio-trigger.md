# Chain 203: AI Vehicle Damage Event — Collision Audio Trigger

Seed: FUN_0041a170  |  System: docs/02-ai-system.md  |  Depth: 2  |  Functions: 4 callees

---

## Overview

FUN_0041a170 triggers audio feedback for AI vehicle collision/damage events. It checks collision severity via FUN_004c7bd0 (IsDriverPlayer, docs/06), then dispatches audio events based on collision presence and session type. Triggered by FUN_00419500 (AI damage system). The chain is small — only 4 callees including driver data table lookup (FUN_004144d0, FUN_004144f0, both docs/20) and driver table entry insertion (FUN_00418560, docs/02).

## Call Tree

```
FUN_0041a170 — AI Vehicle Damage Event  [trigger: AI damage system via 0x00419500]
  +-- FUN_004c7bd0 — IsDriverPlayer  [leaf, docs/06 — session/race logic]
  +-- FUN_004144d0 — Struct Init with Sentinel Values  [leaf, docs/20 — math_util]
  +-- FUN_004144f0 — Driver Data Table Lookup and Time Conversion  [leaf, docs/02 — AI]
  +-- FUN_00418560 — InsertDriverTableEntry  [docs/02 — AI]
        +-- FUN_004145c0 — Struct Copy (32 bytes)  [docs/20]
        +-- FUN_004144d0 — Struct Init with Sentinel Values  [docs/20]
        +-- FUN_004b0170 — Empty Stub (vtable slot)  [docs/20]
```

## Step-by-Step Trace

### Level 0: FUN_0041a170 — AI Vehicle Damage Event

**Trigger:** Called by FUN_00419500 (AI damage system) when vehicle collision/damage occurs.
**Called by:** FUN_00419500 (AI damage system)
**Purpose:** Triggers audio feedback for vehicle collision/damage events.

**Key actions:**
1. Checks collision severity via FUN_004c7bd0
2. If collision: triggers audio 0x34
3. If no collision and SessionType == 7 (race): triggers audio 0xc4
4. Reads driver data tables for context (FUN_004144d0, FUN_004144f0)
5. Updates driver table entry via FUN_00418560

**Globals read:**
- SessionType (DAT_007c56a4) — determines race vs non-race audio

### Level 1: FUN_004c7bd0 — IsDriverPlayer

**Trigger:** Called first to check collision severity.
**Purpose:** Checks if the driver is the player vehicle.
**Called by:** 1 caller (this function)
**Key actions:**
1. Compares driver ID against player vehicle ID
2. Returns boolean: is this the player's vehicle?

### Level 1: FUN_004144f0 — Driver Data Table Lookup and Time Conversion

**Trigger:** Called to get driver skill/time data.
**Purpose:** Looks up driver data from DriverDataTable (DAT_005bf9b0) and converts time values.

**Key actions:**
1. Indexes into DriverDataTable at stride 0x14
2. Reads and converts time values

### Level 1: FUN_00418560 — InsertDriverTableEntry

**Trigger:** Called to update driver table with collision data.
**Purpose:** Inserts or updates an entry in the driver data table.

**Key actions:**
1. Copies 32 bytes of struct data via FUN_004145c0
2. Initializes struct with sentinel values via FUN_004144d0
3. Calls vtable cleanup stub via FUN_004b0170

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0041a170 | Damage event | Collision check | Audio event (0x34 or 0xc4) |
| FUN_004c7bd0 | Driver ID | Player check | IsPlayer boolean |
| FUN_004144f0 | DriverDataTable | Time lookup | Driver time data |
| FUN_00418560 | Driver data | Table insert | Updated table entry |

## Notes

- Smallest chain (4 callees)
- Deepest leaf: FUN_00418560 → 3 sub-callees (FUN_004145c0, FUN_004144d0, FUN_004b0170)
- Cross-system: FUN_004c7bd0 from docs/06 (session-race-logic)
- SessionType check (DAT_007c56a4) determines which audio event to play
- All callees are leaf utilities or AI-specific functions

---
