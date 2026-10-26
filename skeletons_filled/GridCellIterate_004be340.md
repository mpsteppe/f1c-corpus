## GridCellIterate_004be340 — GridCellIterate

**Summary:** Computes 2D grid cell coordinates (0-7 range) from a position and radius using grid origin/scale fields, then calls ProximityCheckWithTagUpdate on all overlapping cells and the overflow list.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleEffectUpdateDispatch (004eb430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x924 | R | — | grid X origin |
| this | 0x928 | R | — | grid X scale inverse |
| this | 0x92C | R | — | grid Y origin |
| this | 0x930 | R | — | grid Y scale inverse |
| this | 0x934 | RW | — | iteration counter (incremented each call) |

**Written-by note (persistence):**
- this 0x934: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bda20 | ProximityCheckWithTagUpdate | update proximity tags on objects in each cell |
| 00587bdc | CRTFtol | convert float coordinate to integer cell index |

**Guard conditions:** if X range (v6 > v8) or Y range (v13 > v11) is degenerate, skips cell iteration. Coordinates clamped to 0-7 range. When any coordinate falls outside [0, 7), the sentinel flag triggers a fallback call to ProximityCheckWithTagUpdate on the overflow list at this+2304.
