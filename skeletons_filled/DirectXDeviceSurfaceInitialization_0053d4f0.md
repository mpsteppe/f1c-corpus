## DirectXDeviceSurfaceInitialization_0053d4f0 — DirectXDeviceSurfaceInitialization

**Summary:** Initializes a DirectX renderer configuration structure — zeroes state flags and counters, runs StructZeroInitConstructor on 8 rendering-pass sub-structures, sets default viewport resolution (640×480) with internal buffer dimensions (7680×1200), and configures default rendering parameters (identity scale values 1.0f, texture/buffer size limits 8192/32768, and a debug color key 11513775).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 0 | Object state/version field — zeroed at init |
| this | 0x8 | RW | 0 | Secondary state field — zeroed at init |
| this | 0x10FC | RW | 0 | Render pass 0 config block (start of 8 StructZeroInitConstructor targets at 17-DWORD stride each) |
| this | 0x1100 | RW | 0 | Render pass 0 sub-field — zeroed within StructZeroInitConstructor |
| this | 0x113C | RW | 0 | Render pass 1 config block |
| this | 0x1140 | RW | 0 | Render pass 1 sub-field |
| this | 0x1144 | RW | 0 | Render pass 1 sub-field |
| this | 0x1148 | RW | 0 | Render pass 2 config block |
| this | 0x114C | RW | 0 | Render pass 2 sub-field |
| this | 0x1150 | RW | 8192 | Texture/surface buffer size limit (2048×4 or 8192) — max texture dimension |
| this | 0x1154 | RW | 0 | Buffer usage counter — zeroed |
| this | 0x1158 | RW | 8192 | Second texture/surface buffer size limit |
| this | 0x115C | RW | 0 | Second buffer usage counter — zeroed |
| this | 0x1160 | RW | 32768 | Large buffer/render-target size limit (32768 = 128×256 or 8192×4) |
| this | 0x1164 | RW | 0 | Large buffer usage counter — zeroed |
| this | 0x1168 | RW | 32768 | Second large buffer size limit |
| this | 0x116C | RW | 0 | Second large buffer usage counter — zeroed |
| this | 0x1174 | RW | 0 | Additional render state — zeroed |
| this | 0x1398 | RW | 0 | Render pass sub-field (later pass) — zeroed |
| this | 0x139C | RW | 0 | Render pass sub-field — zeroed |
| this | 0x13A0 | RW | 1 | Enable flag for a rendering feature — initialized to 1 (on) |
| this | 0x13A4 | RW | 2 | Render mode/index — initialized to 2 |
| this | 0x13A8 | RW | 0 | Render counter/state — zeroed |
| this | 0x13B0 | RW | 1 | Feature toggle flag — initialized to 1 (enabled) |
| this | 0x13B4 | RW | 0 | Feature state — zeroed |
| this | 0x13B8 | RW | 1 | Another feature toggle — initialized to 1 (enabled) |
| this | 0x13BC | RW | 0 | Feature state — zeroed |
| this | 0x13C0 | RW | 0 | Render state flag — zeroed |
| this | 0x13C4 | RW | 0 | Render state flag — zeroed |
| this | 0x13C8 | RW | 11513775 | Debug color key value (0xAFAFAF = gray) — used for render target clear or chroma-key |
| this | 0x13D0 | RW | 0 | Render state — zeroed |
| this | 0x13D4 | RW | 0 | Render state — zeroed |
| this | 0x13D8 | RW | 0 | Render state — zeroed |
| this | 0x13DC | RW | 1 | Feature enable flag — 1 (on) |
| this | 0x13E0 | RW | 1 | Feature enable flag — 1 (on) |
| this | 0x13E4 | RW | 0 | Render state — zeroed |
| this | 0x140C | RW | 1065353216 → 1.0f | Default scale/alpha value — identity 1.0 |
| this | 0x1410 | RW | 0 | Render parameter — zeroed |
| this | 0x1414 | RW | 0 | Render parameter — zeroed |
| this | 0x1418 | RW | 0 | Render parameter — zeroed |
| this | 0x141C | RW | 0 | Render parameter — zeroed |
| this | 0x1420 | RW | 1065353216 → 1.0f | Second default scale/alpha value — identity 1.0 |
| this | 0x1424 | RW | 0 | Render parameter — zeroed |
| this | 0x1428 | RW | 0 | Render parameter — zeroed |
| this | 0x142C | RW | 0 | Render parameter — zeroed |
| this | 0x1430 | RW | 0 | Render parameter — zeroed |
| this | 0x1434 | RW | 1065353216 → 1.0f | Third default scale/alpha value — identity 1.0 |
| this | 0x1438 | RW | 0 | Render parameter — zeroed |
| this | 0x143C | RW | 0 | Render parameter — zeroed |
| this | 0x1440 | RW | 0 | Render parameter — zeroed |
| this | 0x1444 | RW | 0 | Render parameter — zeroed |
| this | 0x1448 | RW | 1065353216 → 1.0f | Fourth default scale/alpha value — identity 1.0 |
| this | 0x144C | RW | 1 | Blend/render mode flag — 1 (enabled) |
| this | 0x1450 | RW | 0 | Blend parameter — zeroed |
| this | 0x1454 | RW | 1065353216 → 1.0f | Fifth default scale/alpha value — identity 1.0 |
| this | 0x14F0 | RW | 0 | Viewport/surface state — zeroed |
| this | 0x14F4 | RW | 0 | Viewport/surface state — zeroed |
| this | 0x14F8 | RW | 0 | Viewport/surface state — zeroed |
| this | 0x14FC | RW | 0 | Viewport/surface state — zeroed |
| this | 0x1500 | RW | 0 | Viewport/surface state — zeroed |
| this | 0x1504 | RW | 0 | Viewport/surface state — zeroed |
| this | 0x1508 | RW | 640 | Default screen/viewport width (pixels) |
| this | 0x150C | RW | 480 | Default screen/viewport height (pixels) |
| this | 0x1510 | RW | 7680 | Internal render buffer width (640 × 12 line stride) |
| this | 0x1514 | RW | 1200 | Internal render buffer height (480 × 2.5 or related dimension) |
| this | 0x1518 | RW | 0 | Surface state — zeroed |
| this | 0x151C | RW | 0 | Surface state — zeroed |
| this | 0x1520 | RW | 0 | Surface state — zeroed |
| this | 0x1524 | RW | 0 | Surface state — zeroed |
| this | 0x1528 | RW | 0 | Surface state — zeroed |
| this | 0x152C | RW | 0 | Surface state — zeroed |
| this | 0x1530 | RW | 0 | Surface state — zeroed |
| this | 0x1550 | RW | 0 | Audio buffer start index — zeroed |
| this | 0x1554 | RW | 512 | Audio buffer size/length (512 samples/frames) |
| this | 0x1558 | RW | 6 | Audio channel count or format flag (6 = 5.1 surround) |
| this | 0x1580 | RW | 0 | Audio playback position/counter — zeroed |

**Written-by note (persistence):**
- this 0x4: written once at device init — external poke does NOT persist (re-init overwrites)
- this 0x8: written once at device init — external poke does NOT persist
- this 0x10FC: written once at device init — external poke does NOT persist
- this 0x1100: written once at device init — external poke does NOT persist
- this 0x113C: written once at device init — external poke does NOT persist
- this 0x1140: written once at device init — external poke does NOT persist
- this 0x1144: written once at device init — external poke does NOT persist
- this 0x1148: written once at device init — external poke does NOT persist
- this 0x114C: written once at device init — external poke does NOT persist
- this 0x1150: written once at device init — external poke does NOT persist
- this 0x1154: written once at device init — external poke does NOT persist
- this 0x1158: written once at device init — external poke does NOT persist
- this 0x115C: written once at device init — external poke does NOT persist
- this 0x1160: written once at device init — external poke does NOT persist
- this 0x1164: written once at device init — external poke does NOT persist
- this 0x1168: written once at device init — external poke does NOT persist
- this 0x116C: written once at device init — external poke does NOT persist
- this 0x1174: written once at device init — external poke does NOT persist
- this 0x1398: written once at device init — external poke does NOT persist
- this 0x139C: written once at device init — external poke does NOT persist
- this 0x13A0: written once at device init — external poke does NOT persist
- this 0x13A4: written once at device init — external poke does NOT persist
- this 0x13A8: written once at device init — external poke does NOT persist
- this 0x13B0: written once at device init — external poke does NOT persist
- this 0x13B4: written once at device init — external poke does NOT persist
- this 0x13B8: written once at device init — external poke does NOT persist
- this 0x13BC: written once at device init — external poke does NOT persist
- this 0x13C0: written once at device init — external poke does NOT persist
- this 0x13C4: written once at device init — external poke does NOT persist
- this 0x13C8: written once at device init — external poke does NOT persist
- this 0x13D0: written once at device init — external poke does NOT persist
- this 0x13D4: written once at device init — external poke does NOT persist
- this 0x13D8: written once at device init — external poke does NOT persist
- this 0x13DC: written once at device init — external poke does NOT persist
- this 0x13E0: written once at device init — external poke does NOT persist
- this 0x13E4: written once at device init — external poke does NOT persist
- this 0x140C: written once at device init — external poke does NOT persist
- this 0x1410: written once at device init — external poke does NOT persist
- this 0x1414: written once at device init — external poke does NOT persist
- this 0x1418: written once at device init — external poke does NOT persist
- this 0x141C: written once at device init — external poke does NOT persist
- this 0x1420: written once at device init — external poke does NOT persist
- this 0x1424: written once at device init — external poke does NOT persist
- this 0x1428: written once at device init — external poke does NOT persist
- this 0x142C: written once at device init — external poke does NOT persist
- this 0x1430: written once at device init — external poke does NOT persist
- this 0x1434: written once at device init — external poke does NOT persist
- this 0x1438: written once at device init — external poke does NOT persist
- this 0x143C: written once at device init — external poke does NOT persist
- this 0x1440: written once at device init — external poke does NOT persist
- this 0x1444: written once at device init — external poke does NOT persist
- this 0x1448: written once at device init — external poke does NOT persist
- this 0x144C: written once at device init — external poke does NOT persist
- this 0x1450: written once at device init — external poke does NOT persist
- this 0x1454: written once at device init — external poke does NOT persist
- this 0x14F0: written once at device init — external poke does NOT persist
- this 0x14F4: written once at device init — external poke does NOT persist
- this 0x14F8: written once at device init — external poke does NOT persist
- this 0x14FC: written once at device init — external poke does NOT persist
- this 0x1500: written once at device init — external poke does NOT persist
- this 0x1504: written once at device init — external poke does NOT persist
- this 0x1508: written once at device init — external poke does NOT persist
- this 0x150C: written once at device init — external poke does NOT persist
- this 0x1510: written once at device init — external poke does NOT persist
- this 0x1514: written once at device init — external poke does NOT persist
- this 0x1518: written once at device init — external poke does NOT persist
- this 0x151C: written once at device init — external poke does NOT persist
- this 0x1520: written once at device init — external poke does NOT persist
- this 0x1524: written once at device init — external poke does NOT persist
- this 0x1528: written once at device init — external poke does NOT persist
- this 0x152C: written once at device init — external poke does NOT persist
- this 0x1530: written once at device init — external poke does NOT persist
- this 0x1550: written once at device init — external poke does NOT persist
- this 0x1554: written once at device init — external poke does NOT persist
- this 0x1558: written once at device init — external poke does NOT persist
- this 0x1580: written once at device init — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b6ab8 | dword_8B6AB8 | W | AudioBufferLoopBoundary [DERIVED] |
| 008b6ac8 | byte_8B6AC8 | W | StringBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00553de0 | StructZeroInitConstructor | Zero-initializes a 17-DWORD (68-byte) render-pass configuration sub-structure; called 8 times for 8 rendering passes |

**Guard conditions:** None — pure initialization function, always writes all fields unconditionally. No branches, no early returns.
