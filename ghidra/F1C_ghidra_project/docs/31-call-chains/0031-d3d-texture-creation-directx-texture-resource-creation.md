# Chain: D3D Texture Creation — DirectX Texture Resource Creation

Seed: FUN_00550080  |  System: docs/19-renderer.md  |  Depth: 2  |  Functions: 10

---

## Overview

Creates D3D texture with size validation and format selection. Computes texture dimensions via log2 with downsampling for oversized textures. Selects pixel format based on flag bits: 0x800000→format 8, 0x800→format 5, 0x40000→key event dispatch. Alpha flag 0x800 triggers alpha-capable format selection. All callees are leaf or near-leaf utility functions.

## Call Tree

```
FUN_00550080 — D3D Texture Creation  [called from resource loader: 0x0049e930]
  +-- FUN_0054fe50 — String Allocation + Path Extract  [docs/20: texture path]
  +-- FUN_005427d0 — [undocumented]
  +-- FUN_0055bfc0 — Simple Field Getter  [docs/20]
  +-- FUN_0053d890 — Indexed Pointer Accessor (+0xc + param_2*0x43c)  [docs/20]
  +-- FUN_0055c9a0 — Masked Field Getter  [docs/20]
  +-- FUN_0055c7f0 — Key Event Dispatch to Sub-Handlers  [docs/01: format dispatch]
  +-- FUN_0055c3c0 — Get VTable Param Based on Flag Bits  [docs/20]
  +-- FUN_005435c0 — [PARTIAL] Unknown (alpha path)  [docs/20: format with 0xff00ff]
  +-- FUN_005429b0 — [undocumented]
  +-- FUN_005502c0 — Destructor with Conditional Free + Flag Clear  [docs/01: cleanup on fail]
```

## Step-by-Step Trace

### Level 0: FUN_00550080 — D3D Texture Creation

**Trigger:** Resource loading — called when a texture needs to be created (caller: 0x0049e930)
**Purpose:** Creates D3D texture with size validation and format selection.

**Key actions:**
1. Computes texture dimensions via log2 (downsamples if too large)
2. Extracts texture path via FUN_0054fe50
3. Selects format based on flags:
   - 0x800000 → format 8
   - 0x800 → format 5
   - 0x40000 → FUN_0055c7f0 dispatch
4. Alpha flag 0x800 → calls FUN_005435c0 with 0xff00ff alpha key
5. On failure: cleanup via FUN_005502c0

### Level 1: All Callees Are Leaf/Near-Leaf Utilities

All 10 callees have no further sub-callees (max depth 2):
- **FUN_0054fe50** — string allocation and path extraction for texture filename
- **FUN_005427d0** — [undocumented]
- **FUN_0055bfc0** — simple field getter (reads field from param_1 struct)
- **FUN_0053d890** — indexed pointer accessor: returns param_1+0xc+param_2*0x43c, bounds-checked
- **FUN_0055c9a0** — masked field getter (reads field masked by param_2)
- **FUN_0055c7f0** — key event dispatch to sub-handlers (format selection dispatch)
- **FUN_0055c3c0** — get vtable param based on flag bits
- **FUN_005435c0** — [PARTIAL] alpha-capable format path, called with 0xff00ff alpha key
- **FUN_005429b0** — [undocumented]
- **FUN_005502c0** — destructor with conditional free and flag clear (cleanup on creation failure)

## Notes

- All 10 callees are terminal (no further sub-callees in call graph)
- FUN_0055c7f0 is the format selector dispatch referenced in the doc entry
- Chain terminates at depth 2 — purely utility accessors and format selection
- Moddability: configurable (texture formats selectable via flags)

---
