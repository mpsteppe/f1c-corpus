## VehicleOrientationMatrixConstruction_0045b050 — Vehicle Orientation Matrix & Network Packet Writer

**Summary:** Constructs a 4x4 vehicle orientation matrix from forward/up/right direction vectors (negated velocity components at offsets 264-280), then iterates 8 sub-blocks writing 12-byte rows via NetworkPacketDataWriter for network transmission.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | RW | — | matrix row 0: up-vector X component (stored from velocity-derived direction) |
| this | 0x64 | RW | — | matrix row 0: up-vector Y component |
| this | 0x68 | RW | 0 | matrix row 0: up-vector Z component (0) |
| this | 0x6C | RW | — | matrix row 1: right-vector X (from normalized cross-product) |
| this | 0x70 | RW | — | matrix row 1: right-vector Y |
| this | 0x74 | RW | — | matrix row 1: right-vector Z |
| this | 0x78 | RW | — | matrix row 2/3 intermediate: forward-vector X (negated up) |
| this | 0x7C | RW | — | matrix row 2/3 intermediate: forward-vector Y |
| this | 0x80 | RW | — | matrix row 2/3 intermediate: forward-vector Z |
| this | 0x84 | RW | — | matrix row: negated-right X (for opposing side) |
| this | 0x88 | RW | — | matrix row: negated-right Y |
| this | 0x8C | RW | — | matrix row: negated-right Z |
| this | 0x90 | RW | — | matrix row: reconstructed from earlier values |
| this | 0x94 | RW | 0 | matrix padding element = 0 |
| this | 0x98 | RW | 0 | matrix padding element = 0 |
| this | 0x9C | RW | — | matrix row 0 col 0 (final: up vector component) |
| this | 0xA0 | RW | — | matrix row 0 col 1 |
| this | 0xA4 | RW | — | matrix row 0 col 2 |
| this | 0xA8 | RW | — | matrix row 1 col 0 |
| this | 0xAC | RW | — | matrix row 1 col 1 |
| this | 0xB0 | RW | — | matrix row 1 col 2 |
| this | 0xB4 | RW | — | matrix row 2 col 0 |
| this | 0xB8 | RW | — | matrix row 2 col 1 |
| this | 0xBC | RW | — | matrix row 2 col 2 |
| this | 0x108 | R | — | velocity X (negated, used as forward direction component) |
| this | 0x110 | R | — | velocity Y (negated, used as forward direction component) |
| this | 0x118 | R | — | velocity Z (negated, used as forward direction component) |
| this | 0x318 | R | — | target orientation value (at 0x318, possibly pitch component) |
| this | 0x320 | R | — | target orientation value (at 0x320, possibly yaw component) |

**Written-by note (persistence):**
- this 0x60: computed per call — external poke does NOT persist (always recomputed from velocity)
- this 0x64: computed per call — external poke does NOT persist
- this 0x68: computed per call — external poke does NOT persist
- this 0x6C: computed per call — external poke does NOT persist
- this 0x70: computed per call — external poke does NOT persist
- this 0x74: computed per call — external poke does NOT persist
- this 0x78: computed per call — external poke does NOT persist
- this 0x7C: computed per call — external poke does NOT persist
- this 0x80: computed per call — external poke does NOT persist
- this 0x84: computed per call — external poke does NOT persist
- this 0x88: computed per call — external poke does NOT persist
- this 0x8C: computed per call — external poke does NOT persist
- this 0x90: computed per call — external poke does NOT persist
- this 0x94: computed per call — external poke does NOT persist
- this 0x98: computed per call — external poke does NOT persist
- this 0x9C: computed per call — external poke does NOT persist
- this 0xA0: computed per call — external poke does NOT persist
- this 0xA4: computed per call — external poke does NOT persist
- this 0xA8: computed per call — external poke does NOT persist
- this 0xAC: computed per call — external poke does NOT persist
- this 0xB0: computed per call — external poke does NOT persist
- this 0xB4: computed per call — external poke does NOT persist
- this 0xB8: computed per call — external poke does NOT persist
- this 0xBC: computed per call — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e428 | dbl_59E428 | R | NaNInvalidSentinel [DERIVED] (also: NaN sentinel constant) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054fa00 | NetworkPacketDataWriter | write orientation matrix row to network packet buffer (called 8 times, once per sub-block) |

**Guard conditions:** NaN/invalid sentinel check: if the velocity magnitude sqrt is zero, a fallback path sets matrix rows directly from the target value at this+0x320 (avoids division-by-zero in normalization). The loop at the end writes 8 12-byte matrix rows (indices 1-8) via NetworkPacketDataWriter unconditionally.
