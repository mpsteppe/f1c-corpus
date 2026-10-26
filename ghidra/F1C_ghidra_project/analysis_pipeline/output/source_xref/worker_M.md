# Source Cross-Reference: docs/13-audit-report.md

Doc file: 13-audit-report.md (struct audit report, 7124 lines, 285 sections)
Functions in scope: 2

---

## FUN_004c71c0 — SetupCarLightingAndRender

Source: analyzed\0x004c71c0__FUN_004c71c0.c (91 lines, 553 bytes)

### RTTI Class Mappings

| rFactor Class | F1C Function | Confidence | Evidence |
|--------------|-------------|------------|----------|
| `Render` (`.?AVRender@@`) | FUN_004c71c0 | HIGH | Per-vehicle render function: sets world/view matrices (+0x744/+0x704), diffuse/specular/environment map (+0x34f8/+0x3510/+0x3540), renders 4 wheels with stride 0x128 wheel positions (+0x83c) + 0xf8 stride light positions (+0x35bc). Reads TeamID at +0x4894 for sound call. Accesses VehiclePtrArray (DAT_007c54f0) and vehicle index (DAT_007c54dc). Matches Render:: per-vehicle draw pattern described in docs/19-renderer.md call chain. |
| `SpecialFX` (`.?AVSpecialFX@@`) | FUN_004c71c0 | LOW | SpecialFX handles particle/light effects, not matrix transforms for vehicle rendering. Disqualified by world/view matrix setup. |

### Parameter-to-Offset Mappings

No config parameter reads. Function consumes pre-loaded render state struct. All field operations are internal to the rendering pipeline.

### String Matches

No string literals in decompiled .c — function works entirely through struct offsets and function calls.

### SDK Struct Alignment

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| (TelemInfoBase — not applicable) | — | — | NOT APPLICABLE — struct is internal render scene node, not exposed in InternalsPlugin.hpp |
| (GraphicsInfo — not applicable) | — | — | Camera position/orientation in SDK GraphicsInfo differ from render scene node | 

The render scene node struct (>0x3a00 bytes) has no equivalent in the public rFactor SDK. It is an internal renderer structure.

### Proposed Renames

| Current | Proposed | Evidence |
|---------|----------|----------|
| SetupCarLightingAndRender | — | Already correct per docs/19-renderer.md. No change needed. |
| RenderContext struct (offset group) | — | Already mapped correctly. Struct is the per-vehicle render context node (Render class member). |

---

## FUN_0053f270 — RenderTargetCleanup

Source: analyzed\0x0053f270__FUN_0053f270.c (71 lines, 374 bytes)

### RTTI Class Mappings

| rFactor Class | F1C Function | Confidence | Evidence |
|--------------|-------------|------------|----------|
| `VidMan` (`.?AVVidMan@@`) | FUN_0053f270 | HIGH | Manages D3D8 device resource lifecycle: releases front buffer (+0x1140), back buffer (+0x113c), depth/stencil (+0x1144). Iterates texture linked list (+0x1518) and render target list (+0x1580). Zeros viewport (+0x14f0..0x1504). Sets render state at +0x13a0. Checks cleanup flag at +0x13a8 (bit 28). VidMan owns all D3D device-level resource management in the rFactor architecture. |
| `Render` (`.?AVRender@@`) | FUN_0053f270 | MEDIUM | Render class could include resource cleanup methods, but buffer/surface management is more characteristic of VidMan. In rFactor Dedicated.exe RTTI, both VidMan and Render exist as separate classes. |

### Parameter-to-Offset Mappings

No config parameter reads. All offsets reference D3D device resources.

### String Matches

No string literals in decompiled .c.

### SDK Struct Alignment

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| (GraphicsInfo — not applicable) | — | — | NOT APPLICABLE — struct is internal VidMan device manager, separate from camera/plugin structs |

The VidMan struct (>0x1580 bytes) has no public SDK equivalent. It is the internal video device manager.

### Proposed Renames

| Current | Proposed | Evidence |
|---------|----------|----------|
| RenderTargetCleanup | — | Already correct per docs/19-renderer.md. No change needed. |
| RenderContext struct (cleanupFlags) | — | Already verified: +0x13a8 (cleanupFlags, bit 28), +0x13a0 (renderState). |

---

## Cross-File Consistency Check

| Check | Result |
|-------|--------|
| FUN_004c71c0: docs/19 vs docs/13-audit | CONSISTENT. docs/19-renderer.md documents it as "SetupCarLightingAndRender". docs/13-audit-report.md Section 238 confirms +0x83c wheelPositions (stride 0x128), +0x704 viewMatrix, +0x744 worldMatrix, +0x34f8 diffuseColor, +0x3510 specularColor, +0x3540 envMapHandle. |
| FUN_0053f270: docs/19 vs docs/13-audit | CONSISTENT. docs/19-renderer.md documents it as "RenderTargetCleanup". docs/13-audit-report.md Section 238 confirms +0x113c backBuffer, +0x1140 frontBuffer, +0x1144 depthStencil, +0x14f0..0x1504 viewportDims, +0x1518 textureList, +0x1580 targetList, +0x13a0 renderState, +0x13a8 cleanupFlags. Audit notes: viewportDims is int[6] not int[5]; +0x152c extraTexture observer claim for FUN_0053f270 is WRONG. |
| FUN_004c71c0: struct-offsets cross-ref | All offsets confirmed in docs/13-struct-offsets.md. Conflict at +0x83c (OvertakeTarget in ai_db struct vs wheelPositions in RenderContext) is NOT a real conflict — same offset, different structs. |
| FUN_0053f270: struct-offsets cross-ref | All offsets confirmed in docs/13-struct-offsets.md. Audit report flags: +0x14f0..0x1504 should be int[6] not int[5]; +0x1140 conflict with TireTelemetry in different struct. |

## HDV/PM Config Parameter Match Check

| Parameter | Section | F1C Usage | Match? |
|-----------|---------|-----------|--------|
| (none) | — | Neither function reads HDV/PM parameters | N/A |

Both functions are pure renderer internals — no configurable game parameters.

## Dev Tree Insight

- FUN_004c71c0 source path: Not directly found in string references, but operation pattern matches `vehgfx.cpp` (rFactor source path: `..\Source\vehgfx.cpp`)
- FUN_0053f270 source path: Matches `vidman.cpp` (rFactor source path: `..\Source\vidman.cpp`) — D3D device resource management
- Both exist in rFactor source listing: `..\Source\vidman.cpp` and `..\Source\vehgfx.cpp` confirmed in rFactor Dedicated.exe strings

## Call Chain Cross-Reference

FUN_004c71c0:
- Callers include: FUN_004b7a90 (Pit Timing Update, docs/07), FUN_004c77d0 (tire wear visualization, docs/06)
- Called functions: FUN_004b33b0 (sound), FUN_004b2310 (matrix mult), FUN_004b2480 (diffuse), FUN_004b25d0 (specular), FUN_004b2750 (env map), FUN_004b2840 (wheel light), FUN_004b2930 (shadow), FUN_004b29b0 (effect), FUN_004b2a10 (shadow), FUN_004b2a40 (post-fx), FUN_004e18c0 (shadow 14 passes), FUN_004b2aa0 (shadow per-pass), FUN_004b2b10 (reset state), FUN_004b2b60 (team color), FUN_004c7c00 (scene)
- All callees are renderer internals (docs/19)

FUN_0053f270:
Called functions: FUN_00540eb0 (release surface), FUN_00587bcf (free/delete), FUN_00541040 (release D3D), FUN_00554d70 (release resource), FUN_005528b0 (flush), FUN_00544af0 (reset device state), FUN_00554e10 (clear state), FUN_00545f40 (get device), FUN_00554cc0 (set state)
- All callees are D3D device management internals
