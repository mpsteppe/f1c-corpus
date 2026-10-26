# Chain: Network Packet Send/Receive — WinSock overlapped I/O

Seed: FUN_0050070d  |  System: docs/21-audio-network-internals.md  |  Depth: 4  |  Functions: ~12

---

## Overview

Network Packet Send/Receive (FUN_0050070d) sends/receives network data with WinSock/overlapped I/O. It acquires/releases network context, prepares buffers via D3D texture surface lock/copy (FUN_00506559), sets up overlapped struct with param data (5 fields from param_8), and calls D3D context init (FUN_005063a5) for actual I/O. Called from FUN_005008e4 and FUN_0050099c (both render surface/blit operations).

## Call Tree

```
FUN_0050070d — Network Packet Send/Receive  [trigger: render surface operation]
  +-- FUN_00502bea — Short Computation  [network context acquire]
  +-- FUN_005064bf — Zero-Init 4 Ints (fast path)  [zero buffer]
  +-- FUN_00506559 — D3D Texture Surface Lock/Copy  [buffer prep]
  |     +-- FUN_005064cf — Render Resource Teardown  [cleanup]
  |     +-- FUN_00500eac — [undocumented]
  |     +-- FUN_00587bcf — Free Wrapper
  +-- FUN_005063a5 — D3D Context Init  [I/O operation]
  |     +-- FUN_0050b8a9 — DirectX Texture/Surface Factory  [FourCC dispatch]
  |     |     +-- FUN_0058a5d8 — SEH Handler Init
  |     +-- FUN_005076fe — Texture Copy/Realloc  [texture resize]
  |     |     +-- FUN_00587bcf — Free Wrapper
  |     |     +-- FUN_0058b130 — Memmove
  |     +-- FUN_00504508 — Surface Pixel Copy  [pixel copy]
  |     |     +-- FUN_005033a5 — DXT Compressed Texture Block Copy
  |     +-- FUN_00506003 — D3D Vertex Buffer Creation  [init chain]
  |           +-- FUN_00502c28 — Complex Allocation  [alloc with float math]
  +-- FUN_005064cf — Render Resource Teardown  [resource cleanup]
  +-- FUN_00502bf4 — Dual VTable Destructor  [context release]
```

## Step-by-Step Trace

### Level 0: FUN_0050070d — Network Packet Send/Receive

**Trigger:** Called during render surface/blit operations that require network sync
**Called by:** FUN_005008e4 (Render Region Copy with Validation), FUN_0050099c (Surface/Blit Operation)
**Purpose:** Send/receive network data with WinSock overlapped I/O

**Key actions:**
1. Acquire network context via FUN_00502bea
2. Zero-init buffer via FUN_005064bf
3. Prepare buffer via FUN_00506559 (D3D texture surface lock/copy)
4. Set up overlapped struct with 5 fields from param_8
5. Call FUN_005063a5 for actual I/O operation
6. Cleanup resources via FUN_005064cf
7. Release context via FUN_00502bf4

**Data passed to callees:** param_8 contains 5 fields for overlapped I/O setup

### Level 1: FUN_005063a5 — D3D Context Init (I/O operation)

**Trigger:** Called from Network Packet Send/Receive
**Called by:** FUN_0050070d
**Purpose:** DirectX context initialization for network I/O

**Key actions:**
1. DirectX texture/surface factory dispatch via FUN_0050b8a9 (FourCC codes, SEH handler init)
2. Texture copy/realloc via FUN_005076fe (free wrapper, memmove)
3. Surface pixel copy via FUN_00504508 (DXT compressed block copy)
4. D3D vertex buffer creation via FUN_00506003 (complex allocation with float-to-int conversion)

## Globals Written in This Chain

None identified — this function works on passed buffers, not global state.

## Notes

- Despite being categorized as "Network Packet Send/Receive", the callee chain is entirely DirectX/D3D operations
- The name may be misleading — this could be a network-backed texture surface sync (send/receive texture data over network for multiplayer rendering)
- Two callers: FUN_005008e4 (Render Region Copy) and FUN_0050099c (Surface/Blit Operation) — both render-related
- FUN_0050b8a9 includes SEH handler init (FUN_0058a5d8) for structured exception handling around D3D operations

---
