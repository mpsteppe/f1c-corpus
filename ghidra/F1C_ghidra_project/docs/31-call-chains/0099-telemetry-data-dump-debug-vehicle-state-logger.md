# Chain: Telemetry Data Dump — Debug Vehicle State Logger

Seed: FUN_004d4a80  |  System: docs/09-track-system.md  |  Depth: 3  |  Functions: 18

---

## Overview

Telemetry Data Dump outputs a comprehensive snapshot of vehicle state to the debug log stream. It is gated on session type, telemetry enable flags, and vehicle count. When active, it iterates the first active vehicle in VehiclePtrArray and logs per-wheel data (wheelspin, suspension deflection, ride height, tire temps, tire pressure, tire wear, corner weight) and vehicle-level data (water/oil temp, RPM, clutch, throttle, brake, steering, elapsed time, position, yaw, accelerations). The chain mostly calls utility functions for logging, timestamping, RNG, and file I/O.

## Call Tree

```
FUN_004d4a80 — Telemetry Data Dump  [per-frame or event-triggered]
  +-- FUN_004d5be0 — FIR Filter / Convolution Accumulator [log output]
  |     +-- FUN_00588678 — File Read Wrapper with Lock
  |           +-- FUN_0058c1b1 — file lock/read
  |           +-- FUN_005886a7 — file read
  |           +-- FUN_0058c203 — file close
  +-- FUN_0042bc10 — ScoringGateCheck [telemetry allowed?]
  |     +-- FUN_00461cd0 — gate check
  +-- FUN_004d5840 — Resource Destroy (timestamp) [time stamp]
  |     +-- FUN_00587bcf — Free Wrapper
  |           +-- FUN_0058aa6f — free
  +-- FUN_00587db0 — Delegation with Fixed Arg (0x40) [random]
  |     +-- FUN_00587d7f — RNG implementation
  +-- FUN_00588678 — File Read Wrapper with Lock [RNG seed]
  |     +-- FUN_0058c1b1, FUN_005886a7, FUN_0058c203
  +-- FUN_004ceef0 — [undocumented]
  +-- FUN_004f34e0 — Tire Model Data Init
  |     +-- FUN_004f3040 — tire model setup
  |     +-- FUN_004f31f0 — tire parameter init
  |     +-- FUN_004f2b10 — tire data load
  +-- FUN_0042e320 — SessionStructInit
  |     +-- FUN_0042e1c0 — struct init
  |     +-- FUN_0042dc60 — session state
  |     +-- FUN_0042e400 — session data
  +-- FUN_004f4270 — .svm/.hdv Vehicle File Parser
  +-- FUN_004b3c60 — Deterministic Hash/Pseudo-Random Generator
  |     +-- FUN_0055687b — hash
  +-- FUN_00568a60 — Weighted Running Checksum over File Stream
  |     +-- FUN_00587db0 — RNG
  |     +-- FUN_00589fcc — file handle
  |     +-- FUN_00587d02 — stream read
  +-- FUN_00566650 — String Copy with Buffer Realloc (name set)
  +-- FUN_00588410 — String Compare (name match)
  +-- FUN_0042ddd0 — ScoreSlotDeallocator
  |     +-- FUN_00587bcf — free
  +-- FUN_004d5af0 — File: Open, count entries, read/decrypt XOR data
        +-- FUN_00587db0 — RNG
        +-- FUN_00589fcc — file open
        +-- FUN_004d5be0 — log output
        +-- FUN_00587f64 — file read
        +-- FUN_00587d02 — file close
```

## Step-by-Step Trace

### Level 0: FUN_004d4a80 — Telemetry Data Dump

**Trigger:** Called per-frame or per-event from steward/main loop (FUN_004a00a0).
**Called by:** FUN_004a00a0 (steward loop, single caller).
**Purpose:** Outputs comprehensive vehicle state telemetry to debug log.

**Key actions:**
1. Gate checks: VehicleCount > 0, DAT_007ce9d0 > 0, SessionType gate
2. Find first active vehicle in VehiclePtrArray
3. Generate random session identifier
4. Output per-wheel telemetry: wheelspin, suspension, ride height, tire temps (L/C/R), tire pressure, wear, corner weight
5. Output vehicle-level: water temp, oil temp, RPM, clutch, throttle, brake, steering, time, position, yaw, acceleration
6. Reads DriverName, VehicleDescription, VehicleFilePath from vehicle struct

**Data passed to callees:** Vehicle struct pointers (param_2), format strings, log handles.

### Level 1: FUN_004d5be0 — FIR Filter / Convolution Accumulator

**Trigger:** Called as log output sink.
**Purpose:** Log output function — writes formatted telemetry to log stream.

### Level 1: FUN_0042bc10 — ScoringGateCheck

**Trigger:** Called to check if telemetry is allowed.
**Purpose:** Checks ScoringGate (DAT_008ab6e4) to determine if telemetry output is enabled.

### Level 1: FUN_004d5840 — Resource Destroy (timestamp)

**Trigger:** Gets current timestamp for log entry.
**Purpose:** Gets system time for telemetry log entries.

### Level 1: FUN_00587db0 — RNG / Delegation

**Trigger:** Generates random seed for session identifier.
**Purpose:** Random number generator with fixed argument 0x40.

### Level 1: FUN_00588678 — File Read Wrapper with Lock

**Trigger:** Seeds RNG from file entropy.
**Purpose:** Thread-safe file read with lock for RNG seeding.

### Level 1: FUN_004f4270 — .svm/.hdv Vehicle File Parser

**Trigger:** Opens vehicle setup files for telemetry data.
**Purpose:** Parses vehicle specification files (.svm/.hdv) to read telemetry config.

### Level 1: FUN_004d5af0 — File Open/Read/Decrypt XOR

**Trigger:** Opens telemetry data files.
**Purpose:** Opens file, counts entries, reads and decodes XOR-encrypted data.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Gate | VehicleCount, DAT_007ce9d0, SessionType | conditional AND | pass/fail |
| Vehicle select | VehiclePtrArray | iterate for active | vehicle_ptr |
| RNG | DAT_007c935c | XOR 0x516141f2 | session_id |
| Per wheel | vehicle_ptr+wheels | format + log | 4 wheel telemetry lines |
| Vehicle level | vehicle_ptr+fields | format + log | 1 summary line |

## Globals Written in This Chain

None written — all output goes to log stream.

## Notes

- 15 callees, mostly utility (log, RNG, file I/O).
- Heavy call to .svm/.hdv parser (FUN_004f4270) for setup data.
- Deepest subtree is FUN_004d5af0 (file open/decrypt) with 5 sub-callees.
- Debug-only feature — gated on telemetry enable flags.

---
