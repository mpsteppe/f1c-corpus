## FUN_0054D080 — PASS

## FUN_004493A0 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_OFFSET] Per-triangle struct: +0x04 is Neighbor0 (edge 0-1 reference), not Index1
- [WRONG_OFFSET] Per-triangle struct: +0x08 is Index1, not Index2
- [WRONG_OFFSET] Per-triangle struct: +0x0c is Neighbor1 (edge 1-2 reference), not Reserved
- [WRONG_OFFSET] Per-triangle struct: +0x10 is Index2 (third vertex), not MaterialA
- [WRONG_OFFSET] Per-triangle struct: +0x14 is Neighbor2 (edge 2-0 reference), not MaterialB
- [WRONG_DESCRIPTION] "up to 6 edge neighbors per triangle, 2 per edge" — source shows max 11 neighbors per triangle (check vs 0xb), and 1 neighbor per edge slot (not 2). Each edge stores 1 neighbor reference at odd slots (1,3,5).

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_004493a0 — Triangle Mesh Adjacency Builder

Source: Unknown (no assert strings). Builds triangle-triangle adjacency data for a collision mesh. Tracks shared edges between triangles (max 11 neighbors per triangle via neighbor list at +0x1c).

**Key logic:**
- Manages dynamic array of triangles (each 0x20 bytes), growing by 0x2000 entries when full
- Copies old triangle data to new buffer, relinking adjacency pointers
- Creates new triangle from three vertex pointers (param_2, param_3, param_4) using FUN_00448ec0/FUN_00448480
- Allocates two 0x60-byte auxiliary buffers (edge/vertex data) when first needed
- Core neighbor search: for each edge slot (puVar9[1],[3],[5]), searches all other triangles' edges for matching shared-vertex pair
- If shared edge found, determines which edge slot the neighbor occupies using clockwise ordering
- Stores neighbor triangle pointer in odd slots puVar9[1],[3],[5]
- After building all 3 neighbor pairs, writes back self-reference (puVar9) into each neighbor's +0x1c edge list and increments neighbor count at +0x18
- If param_6 is non-zero, copies collision material/surface properties to neighbor's +0x10 and +0x14

**Struct offsets (param_1 — mesh container):**
| Offset | Field | Notes |
|--------|-------|-------|
| param_1[0] | TriangleCount | Number of triangles in mesh |
| param_1[1] | AllocatedCapacity | Total allocated triangle slots |
| param_1[2] | TriangleArray | Pointer to triangle data (stride 0x20 per triangle) |
| param_1[3] | EdgeBufferA | Auxiliary buffer (0x60 bytes) for edge data |
| param_1[4] | EdgeBufferB | Auxiliary buffer (0x60 bytes) for edge data |

**Per-triangle structure (stride 0x20):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | Vertex0 | Pointer to vertex 0 data (from FUN_004485d0) |
| +0x04 | Neighbor0 | Triangle pointer for shared edge 0-1 |
| +0x08 | Vertex1 | Pointer to vertex 1 data (from FUN_004485d0) |
| +0x0c | Neighbor1 | Triangle pointer for shared edge 1-2 |
| +0x10 | Vertex2 | Pointer to vertex 2 data (from FUN_004485d0) |
| +0x14 | Neighbor2 | Triangle pointer for shared edge 2-0 |
| +0x18 | NeighborCount | Number of adjacent triangles (0-11) |
| +0x1c | NeighborList | Pointer to array of neighbor triangle pointers |

**Calls:** FUN_00448e90 (init triangle), FUN_00448e50 (free buffer), FUN_00587bcf (delete), FUN_00448ec0 (setup triangle), FUN_00448480 (compute edge vectors), FUN_00448510 (init buffer), FUN_004485d0 (register vertex — returns pointer)

**Moddability:** hardcoded — standard mesh adjacency builder

## FUN_0044E030 — PASS

## FUN_0044C9B0 — PASS

## FUN_004651C0 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_OFFSET] "node at +0x4c for next" — source shows node next pointer at puVar2[1] = offset +0x04, not 0x4c

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_004651c0 — Collision State Cleanup

Source: collision_cleanup.cpp. Computes feedback value from physics state, then frees two linked lists of collision data.

**Key logic:**
- Calls FUN_00568cf0() to get a random or time-based value
- Clamps result: if < `_DAT_0059e600` → 0.001; if > `_DAT_0059e43c` → 1.0
- Stores result at `*param_1 + 0x60`
- Walks linked list at `*param_1 + 0x6c` (node struct: +0x00 payload ptr, +0x04 next ptr, +0x08 flag byte): frees payload if flag set, then frees node
- Walks second linked list at `*param_1 + 0x7c`: same cleanup pattern
- Zeros the 4 linked list pointers for both lists (+0x6c/+0x70/+0x74/+0x78 and +0x7c/+0x80/+0x84/+0x88)
- Clears array of 0x62 (98) elements starting at +0xf8 with stride 0x230
- Sets +0xe40c = 0

**Calls:** FUN_00568cf0 (random/time value), FUN_00464ef0 (apply feedback), FUN_00587bcf (free)

**Moddability:** hardcoded

## FUN_0044EAE0 — PASS

## FUN_0044D2B0 — PASS

## FUN_0044BB60 — PASS

## FUN_0044EC60 — PASS

## FUN_0044D490 — PASS

## FUN_0044C470 — PASS

## FUN_0044F640 — PASS

## FUN_0044D610 — PASS

## FUN_004039C0 — PASS

## FUN_0049F530 — PASS

## FUN_0044D9A0 — PASS

## FUN_00464EF0 — PASS

## FUN_004BAC20 — PASS

## FUN_00567120 — PASS

## FUN_004E94A3 — PASS

## FUN_00438F00 — PASS

## FUN_0043BC20 — PASS

## FUN_00524553 — PASS

## FUN_00448E90 — PASS

## FUN_004486E0 — PASS

## FUN_00433FC0 — PASS

## FUN_0043E5D0 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_0043e5d0` entry found in docs/18-physics-dynamics.md. Function does not have a documented entry.

## FUN_00430600 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_00430600` entry found in docs/18-physics-dynamics.md. Function does not have a documented entry.

## FUN_00448510 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_00448510` entry found in docs/18-physics-dynamics.md. Function does not have a documented entry.

## FUN_004B31A0 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_004b31a0` entry found in docs/18-physics-dynamics.md. Function does not have a documented entry.

## FUN_00583790 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_00583790` entry found in docs/18-physics-dynamics.md. Function does not have a documented entry.

## FUN_004F6D90 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_004f6d90` entry found in docs/18-physics-dynamics.md. Function does not have a documented entry.

## FUN_004C9C00 — PASS

## FUN_004149A0 — PASS
## FUN_00487010 — PASS
## FUN_0048A3C0 — PASS
## FUN_004976C0 — PASS
## FUN_004607A0 — PASS
## FUN_005607C1 — PASS
## FUN_0053D4F0 — PASS
## FUN_00540250 — PASS
## FUN_00459330 — PASS
## FUN_00506003 — PASS
## FUN_0051D57F — PASS
## FUN_004FD8B0 — PASS
## FUN_00554E10 — PASS
## FUN_00523E7A — PASS
## FUN_004A3390 — PASS
## FUN_00519375 — PASS
## FUN_00519EB7 — PASS
## FUN_00486540 — PASS
## FUN_00516883 — PASS
## FUN_00485A70 — PASS
## FUN_005450E0 — PASS
## FUN_005666B0 — PASS
## FUN_0058BB10 — PASS
## FUN_00556E70 — PASS
## FUN_0058AA6F — PASS
## FUN_0058EEF7 — PASS
## FUN_00598323 — PASS
## FUN_00558B30 — PASS
## FUN_0058F7C9 — PASS
## FUN_00504B37 — PASS
## FUN_00595733 — PASS
## FUN_00495810 — PASS
## FUN_0053C680 — PASS
## FUN_00588A19 — PASS
## FUN_00460C60 — PASS
## FUN_00599CB7 — PASS
## FUN_004995E0 — PASS
## FUN_004C2BE0 — PASS
## FUN_0050B7E3 — PASS
## FUN_005461B0 — PASS
## FUN_0059C5BC — PASS
## FUN_00407D40 — PASS
## FUN_004652D0 — PASS
## FUN_0048C9B0 — PASS
## FUN_004B3A90 — PASS
## FUN_004DEF70 — PASS
## FUN_0052A5A8 — PASS
## FUN_00587890 — PASS
## FUN_004084A0 — PASS
## FUN_00499660 — PASS
## FUN_005262C2 — PASS
## FUN_00551A30 — PASS
## FUN_0040E860 — PASS
## FUN_0046D630 — PASS
## FUN_00490160 — PASS
## FUN_004B2A30 — PASS
## FUN_004DC340 — PASS
## FUN_0051E1EF — PASS
## FUN_00589FFD — PASS
## FUN_00476F90 — PASS
## FUN_004219F0 — PASS
## FUN_0048F330 — PASS
## FUN_004B2190 — PASS
## FUN_004DB0E0 — PASS
## FUN_00513D63 — PASS
## FUN_0054FDA0 — PASS
## FUN_0058A55A — PASS
## FUN_00424060 — PASS
## FUN_00479880 — PASS
## FUN_00498FE0 — PASS
## FUN_004C2C30 — PASS
## FUN_0051227F — PASS
## FUN_00587B3E — PASS
## FUN_0059C878 — PASS
## FUN_00418DD0 — PASS
## FUN_00475020 — PASS
## FUN_00495A20 — PASS
## FUN_004BA6C0 — PASS
## FUN_004F3040 — PASS
## FUN_00526B55 — PASS
## FUN_0056CF70 — PASS
## FUN_00585E80 — PASS
## FUN_00499DF0 — PASS
## FUN_00595058 — PASS
## FUN_004080B0 — PASS
## FUN_00464B10 — PASS
## FUN_0048B4F0 — PASS
## FUN_004A3B30 — PASS
## FUN_004D5BE0 — PASS
## FUN_0050F199 — PASS
## FUN_00549110 — PASS
## FUN_00559630 — PASS
## FUN_00585020 — PASS
## FUN_00541CD0 — PASS
## FUN_0050F632 — PASS
## FUN_004C2DC0 — PASS
## FUN_004916E0 — PASS
## FUN_00470170 — PASS
## FUN_00410B20 — PASS
## FUN_004C84A0 — PASS
## FUN_0050AB35 — PASS
## FUN_0053FC30 — PASS
## FUN_00595304 — PASS
## FUN_0058A770 — PASS
## FUN_004058A0 — PASS
## FUN_004661B0 — PASS
## FUN_0048D230 — PASS
## FUN_004A8AF0 — PASS
## FUN_004D7E00 — PASS
## FUN_0051184F — PASS
## FUN_0054B530 — PASS
## FUN_0050DF95 — PASS
## FUN_0040DD30 — PASS
## FUN_0046C030 — PASS
## FUN_0048FC80 — PASS
## FUN_004B25D0 — PASS
## FUN_004DBDE0 — PASS
## FUN_005158AF — PASS
## FUN_00550AC0 — PASS
## FUN_00557410 — PASS
## FUN_00411330 — PASS
## FUN_004702F0 — PASS
## FUN_00491770 — PASS
## FUN_004B5460 — PASS
## FUN_004E21D0 — PASS
## FUN_00521712 — PASS
## FUN_005678F0 — PASS
## FUN_00598C1C — PASS
## FUN_00461CD0 — PASS
## FUN_00490930 — PASS
## FUN_004B2B90 — PASS
## FUN_004DCD80 — PASS
## FUN_00517EE1 — PASS
## FUN_0055CEB0 — PASS
## FUN_005952E9 — PASS
## FUN_00499AE0 — PASS
## FUN_004F9F60 — PASS
## FUN_0057A330 — PASS
## FUN_00414490 — PASS
## FUN_005648B0 — PASS
## FUN_004082B0 — PASS
## FUN_00470CC0 — PASS
## FUN_004919C0 — PASS
## FUN_004B5E30 — PASS
## FUN_004E2A60 — PASS
## FUN_0051C813 — PASS
## FUN_00564A00 — PASS
## FUN_0058A2EF — PASS
## FUN_00452780 — PASS
## FUN_00479C80 — PASS
## FUN_00499560 — PASS
## FUN_004BFD40 — PASS
## FUN_004FEAA0 — PASS
## FUN_005397A0 — PASS
## FUN_005876D0 — PASS
## FUN_004263EB — PASS
## FUN_00486400 — PASS
## FUN_0049F150 — PASS
## FUN_0059C92C — PASS
## FUN_0059C552 — PASS
## FUN_0059C7D8 — PASS
## FUN_0059C648 — PASS
## FUN_0059D318 — PASS

## FUN_004F88A0 — PASS
## FUN_00556730 — PASS
## FUN_0057DD40 — PASS
## FUN_004B4A30 — PASS
## FUN_0052A6EC — PASS
## FUN_00562C50 — PASS
## FUN_0057E8D0 — PASS
## FUN_00598660 — PASS
## FUN_00563160 — PASS
## FUN_00564810 — PASS
