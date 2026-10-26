# Chain 200: Vehicle List Builder from Global Array — Vehicle File Enumeration

Seed: FUN_00415780  |  System: docs/08-file-formats.md  |  Depth: 2  |  Functions: 7 callees

---

## Overview

FUN_00415780 builds a linked list of vehicle entries from the global VehicleArray (DAT_008ac394, stride 0x424). It iterates DAT_008ac390 vehicle file count entries, allocates a 0xb0-byte node per vehicle, reads the vehicle name at stride offset +0xbc, and calls FUN_00414600 for each. The chain involves linked list node allocation, struct initialization (FUN_00415900, FUN_00415520, FUN_00401000), text format struct init (FUN_004149a0, docs/19), string copy (FUN_00566650, docs/20), and memory management (FUN_00587bcf). Triggered at startup. No documented callers.

## Call Tree

```
FUN_00415780 — Vehicle List Builder from Global Array  [trigger: game startup]
  +-- FUN_00587bcf — Free Wrapper (clear existing list)  [leaf]
  +-- FUN_00415900 — Struct Destructor (Internal Buffer Cleanup)  [docs/06]
  |     +-- FUN_004145c0 — Struct Copy (32 bytes)  [docs/20]
  |     +-- FUN_00587bcf — Free Wrapper  [leaf]
  +-- FUN_00415520 — Small Entry Struct Init  [docs/19, called 4x]
  |     +-- FUN_00418b70 — Short Computation (Table Lookup with Sentinel)  [docs/20]
  +-- FUN_00401000 — Callback Loop N Times  [docs/20]
  +-- FUN_004149a0 — Text Format Struct Initializer (Large)  [docs/19]
  |     +-- FUN_00418b90 — Score/Threshold Gate Check  [docs/06]
  +-- FUN_00566650 — String Copy with Buffer Realloc  [leaf, docs/20]
  +-- FUN_00414600 — [undocumented in functions.json lookup]
```

## Step-by-Step Trace

### Level 0: FUN_00415780 — Vehicle List Builder from Global Array

**Trigger:** Called during game startup to build vehicle list from global array.
**Called by:** No documented callers (callers.json empty — likely called during vehicle system init)
**Purpose:** Builds linked list of vehicle entries from DAT_008ac394.

**Key actions:**
1. Clears existing linked list — frees nodes via FUN_00587bcf
2. Loops over VehicleCount (DAT_008ac390)
3. For each: allocates 0xb0-byte node + sub-structs
4. Reads vehicle name at stride offset +0xbc
5. Calls FUN_00414600 per vehicle
6. Inserts into linked list

**Globals read:**
- DAT_008ac390 (VehicleFileCount) — number of vehicles
- DAT_008ac394 (VehicleArray, stride 0x424) — vehicle data array

### Level 1: FUN_00415520 — Small Entry Struct Init (called 4x per vehicle)

**Trigger:** Called for each vehicle entry to initialize sub-structs.
**Purpose:** Initializes a small struct entry with sentinel values.

**Key actions:**
1. Sets up a small struct (likely 0x10-0x20 bytes)
2. Calls FUN_00418b70 for table lookup with sentinel

### Level 1: FUN_004149a0 — Text Format Struct Initializer (Large)

**Trigger:** Called for each vehicle to set up text format data.
**Purpose:** Initializes a large text format struct for vehicle display.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| DAT_008ac394 | VehicleArray | Iterate stride 0x424 | Per-vehicle data |
| FUN_00415780 | Vehicle data at +0xbc | Name extraction | Vehicle name string |
| FUN_00414600 | Vehicle data | Per-vehicle processing | Initialized vehicle entry |
| Linked list | Nodes | Append at *param_1 | Vehicle linked list |

## Notes

- 7 callees, file format / initialization focused
- No documented callers — entry point likely from vehicle system startup
- Actual per-vehicle processing delegated to FUN_00414600 (undocumented)
- FUN_00415520 called 4x per vehicle (possibly 4 wheel entries)

---
