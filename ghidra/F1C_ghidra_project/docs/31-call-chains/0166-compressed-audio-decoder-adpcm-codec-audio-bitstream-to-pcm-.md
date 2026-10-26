# Chain: Compressed Audio Decoder (ADPCM/Codec) — Audio Bitstream to PCM Conversion

Seed: FUN_0052e6f0  |  System: docs/21-audio-network-internals.md  |  Depth: 2  |  Functions: 7

---

## Overview

Core compressed audio decoder. Decompresses encoded audio frames from a bitstream buffer and outputs float PCM samples to the resampler stage. Dual-mode decoder: initialized mode uses Huffman-like VLC decoding with codebook tables (DAT_005b2ba4, DAT_005b4788, DAT_005b4820); uninitialized mode reads raw nibbles as codebook selectors. Outputs 0x600 bytes PCM per call (12 blocks x 0x80 bytes). Feeds SIMD resampler (FUN_00532aa0) for stereo or mono output path (FUN_00531830).

## Call Tree

```
FUN_0052e6f0 — Compressed Audio Decoder (ADPCM/Codec)  [trigger: audio decode path]
  +-- FUN_0052e5e0 — DecodeHuffmanPair  [codec core: 32× per block: docs/06]
  +-- FUN_00532aa0 — Audio Resampler / SIMD FIR  [resampler: docs/21]
  |     +-- FUN_00534120 — 3D Transform with SIMD (pmaddwd)  [helper: docs/19]
  +-- FUN_00531830 — Audio Mixer: Float-to-16-bit PCM  [mono output: docs/06]
  |     +-- FUN_00531b50 — 32-Point MDCT Audio Transform  [docs/21]
  +-- FUN_004fd840 — Dual Linked List Destruction  [list free: docs/01]
  +-- FUN_004b3ce0 — Random/Noise Value Generator  [docs/20]
  +-- FUN_004fc9a0 — Float Array Initializer (20/0.3)  [buffer init: docs/20]
  +-- FUN_0058957a — Interrupt Dispatch  [docs/01]
```

## Step-by-Step Trace

### Level 0: FUN_0052e6f0 — Compressed Audio Decoder (ADPCM/Codec)

**Trigger:** Audio decode path (no callers recorded — likely dispatcher/thread-based).
**Called by:** [no callers recorded — audio pipeline internal]
**Purpose:** Decompresses encoded audio frames to float PCM samples.

**Key actions:**
1. Gate: param_1+0x24a4 (input buffer ptr) — returns -1 if null
2. Bitstream reader: param_1+0x24a8 tracks bit position; variable-length code extraction
3. Two modes based on DAT_008b0108 (codec init flag):
   - **Initialized**: Decodes 12 blocks × 32 entries per block via FUN_0052e5e0 with coefficient table DAT_005b2ba4. Outputs 0x80 bytes PCM per block.
   - **Uninitialized**: Direct 8-bit/4-bit nibble read → table lookup → float conversion via DAT_005b11a4
4. Post-decode: calls FUN_00532aa0 (SIMD resampler) for stereo or FUN_00531830 for mono
5. Output stride: param_1[0x24d0] × 2 bytes per channel

**Globals read:** DAT_008b0108 (codec init), DAT_008b0124 (workspace), DAT_008b0224 (VLC values), DAT_008b0324 (codebook selectors).

**Struct offsets:** +0x24a4 (input buffer), +0x24a8 (bit position), +0x24cc (channel count), +0x24d0 (output stride).

### Level 1: FUN_00532aa0 — Audio Resampler / SIMD FIR

**Trigger:** Called per decoded block for stereo output.
**Called by:** FUN_0052e6f0.
**Purpose:** SIMD-accelerated sample rate conversion via FIR filter.

**Key actions:**
1. Uses ring buffer indexed at +0x24bc
2. Calls FUN_00534120 for SIMD pmaddwd helper operations
3. Outputs resampled PCM data

### Level 1: FUN_0052e5e0 — DecodeHuffmanPair

**Trigger:** Called 32× per block (384× per call) for initialized mode.
**Called by:** FUN_0052e6f0.
**Purpose:** Decodes one Huffman-like VLC pair from bitstream.

**Key actions:**
1. Reads variable-length code from bitstream
2. Looks up coefficient in codebook table
3. Returns decoded float value pair

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0052e6f0 | compressed bitstream | VLC decode | 32 float PCM × 12 blocks |
| FUN_0052e5e0 | bitstream + table | Huffman-like decode | float sample pair |
| FUN_00532aa0 | float PCM | SIMD FIR resample | resampled PCM |
| FUN_00531830 | float PCM | float-to-16-bit | mono PCM out |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_008b0124 | AudioDecodeWorkspace | FUN_0052e6f0 | Intermediate decoded floats |
| DAT_008b0224 | VQDecodeWorkspace | FUN_0052e6f0 | VLC decoded values |

## Notes

- Heavy data transform: compressed bitstream → VLC decode → float PCM → FIR resample → fixed-point output.
- FUN_0052e5e0 called 384 times per FUN_0052e6f0 invocation (12 blocks × 32 entries).
- SIMD pmaddwd in FUN_00534120 (docs/19) shows renderer/audio crossover — shared SIMD math utility.
- 0x600 bytes PCM output per call = 12 blocks × 0x80 bytes.
- Two code paths (initialized vs uninitialized) allow for different compressed audio formats.

---
