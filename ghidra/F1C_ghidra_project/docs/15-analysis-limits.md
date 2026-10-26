# Analysis Limits - Where the Wall Is

## Analysis Limits â€” Where the Wall Is

1. **Float constant scanning** doesn't work against MSVC `.rdata`-referenced constants.
   To find the 107% rule or AI slider functions: search for cross-references to the
   constant's `.rdata` address, not byte patterns inline.

2. **C++ class hierarchy** is unrecoverable without RTTI on game classes.

3. **Physics functions** (407 large anonymous) are decompilable but unidentifiable without
   additional anchoring â€” they call each other without strings. Reverse engineering them
   fully is rFactor physics modding territory, not relevant to mods.

4. **Weather simulation** (`weather.cpp`) â€” the string scan found functions from this file
   but none of the large anonymous functions are anchored to it. Weather math lives in
   the anonymous mass.

5. **1-byte struct fields** (StartStalls, RaceAbility, RainAbility at offsets 0x112fâ€“0x1138)
   were not found by the xref scan. A targeted disassembly scan for `MOV reg, [reg+112Fh]`
   patterns would find them.

6. **DAT_005ea3d8** (track reference speed â€” bridge between aiDB[0x46] and per-car speed
   targets) is written by an anonymous session init function. Its exact computation
   (incorporating aiDB[0x46] Ã— track_lap_time) is not recoverable without deeper
   anonymous function analysis.

---


## Xref False Positives
### Xref False Positives â€” QualifyingAbility (+0x1130) and RainAbility (+0x1132)

Two functions matched the xref scan at offsets +0x1130 and +0x1132 but are graphics functions with no connection to the vehicle AI struct:

| Function | Claimed offset | Actual identity |
|----------|---------------|-----------------|
| `FUN_0053e070` | QA +0x1130 | DirectX display mode initializer (DXT texture format detection, display caps setup) |
| `FUN_0054ca00` | RainAbility +0x1132 | Graphics vertex buffer manager (UV coordinate transformation, vertex copying) |

Root cause: xref scans match raw 4-byte displacements without struct-type context. Any struct with the same byte offset produces a false hit. Both functions contain DirectX API calls and no game logic.

True consumers of QualifyingAbility and RainAbility are the AI ability pipeline functions documented in the "AI Ability Processing" section.

## decompiled_full Deep Analysis (712 flagged functions)

As of 2026-07-14, only 10 of 712 `needs_deep_analysis=true` functions had been read.
Reading 50+ confirms they are exclusively internal physics/math engine code:

**Categories verified:**
- **physics_math (395):** Collision detection (SAT, GJK, contact manifolds), rigid body dynamics (integration, constraint solving, spring/damper), spatial partitioning (BVH/octree queries), suspension geometry, tire brush model math
- **unknown (317):** Same type of pure math — matrix operations, vector transforms, quaternion slerp, interpolation, root-finding (Newton-Raphson), numerical integration (RK4)

**Key finding:** None of the 712 flagged functions reference documented globals (`DAT_007cxxxx` or `DAT_008axxxx`). They operate on opaque struct offsets (+0x94/0x98/0x9c for position, stride 0x13c for objects). They contain no string literals, no file I/O, and no game-logic branching.

**Conclusion:** These functions implement the physics engine kernel. They read physics state from structs, compute forces, and write results back. They do NOT read any `.svm`, `.rcd`, `.tbc`, `.hdv`, or `.gdb` file fields. No new moddable fields exist in decompiled_full.

The math_util (4,005) category is even lower value — standard library math wrappers, STL-style algorithms, memory copies, and allocators.

**Recommendation:** Skip decompiled_full for modding work. All file fields are loaded by the decompiled_all functions — which are now at 98.8% coverage (648/656).

---

## Intentional Skips — 7 Functions Not Documented

These `decompiled_all` functions contain ONLY rendering pipeline, audio/media library, or MSVC CRT strings — no game logic, no file fields, no modding relevance. Skipped per WORKER.md rules.

| Address | Lines | Reason |
|---------|-------|--------|
| `0x00457670` | 114 | StaticCam camera config serializer — pure rendering pipeline |
| `0x00458a60` | 114 | TrackingCam camera config serializer — pure rendering pipeline |
| `0x00456670` | 106 | LocalCam camera config serializer — pure rendering pipeline |
| `0x004c83b0` | 65 | Phd3 audio playlist loader — media library only |
| `0x004c8920` | 54 | Pit\pitSounds.mp3 audio playback — media library only |
| `0x00404fa0` | 17 | LowPass Filter name lookup — audio DSP, no game state |
| `0x00404fc0` | 17 | LowPass Cutoff name lookup — audio DSP, no game state |

---
