## ShortComputation_1330_00411330 — PhysicsStateUpdateByType

**Summary:** Dispatches a physics/computation update based on operation type (3/4/5). Indexes into different local arrays and global data tables, computes a float offset, then calls three downstream processing functions. Sets an activity flag at v7+0x0A. Part of collision effects/physics system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CollisionSparkParticleEffects (004ec1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4C | R | — | Base pointer for type-3 array (36-byte stride elements) |
| this | 0x58 | R | — | Base pointer for type-4 array (36-byte stride elements) |
| this | 0x64 | R | — | Base pointer for type-5 array (36-byte stride elements) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ecf0c | dword_5ECF0C | R | Type-3 global data table (4656-byte stride per a4, 74-element sub-index) |
| 005ed3ac | dword_5ED3AC | R | Type-4 sub-table 0 (a5==0), global data per a4 |
| 005ed3f0 | dword_5ED3F0 | R | Type-4 sub-table 1 (a5!=0), global data per a4 |
| 005ed434 | dword_5ED434 | R | Type-5 global data table (4656-byte stride per a4, 17-element sub-index) |
| 007d0ad4 | flt_7D0AD4 | R | Global float offset added to input value |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040e770 | ShortComputation_e770 | Downstream state computation on selected element |
| 0040eec0 | SwitchBasedFloatProcessing | Float processing pass on selected element |
| 0040ef70 | PhysicsStateVectorConversion | Vector conversion on selected element |

**Guard conditions:** Branch on `a2` parameter: 3, 4, or 5 each use different array bases and global tables. All other values skip the float-computation block (passthrough with v6=a5, v7=a5). After the branch, always runs the three downstream calls and sets byte flag at (v7+0x0A) to 1.
