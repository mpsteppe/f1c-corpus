## SEHProtectedDirectXRenderStateSetup_00586700 — RenderStateBitmapAllocationSetup

**Summary:** Initializes render state by calling sub_587460(0) and sub_59B2F0(8,1,16,8), then registers 5 bitmap allocation tracker entries at offsets 0x34-0x44 from `this` with modes 1,8,1,2,16. Calls sub_586AA0 to finalize bitmap field initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SEHProtectedDataCopy (0057a760)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d186 | SEH_586700 | R | SEH handler registration for this function |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00586aa0 | sub_586AA0 | Initialize/reset multi-block bitmap fields (clears bitmap state after allocation) |
| 00587460 | sub_587460 | General init with parameter 0 |
| 0059b2f0 | sub_59B2F0 | Setup with parameters (8, 1, 16, 8) — likely render state dimensions |
| 0059b5c0 | BitmapAllocationTracker | Register bitmap allocation at various offsets with mode flags (1, 8, 1, 2, 16) |

**Guard conditions:** No guard conditions — always runs full init sequence.
