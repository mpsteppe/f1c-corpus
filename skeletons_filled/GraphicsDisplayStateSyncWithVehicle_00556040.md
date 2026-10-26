## GraphicsDisplayStateSyncWithVehicle_00556040 — SyncVehicleDashboardDisplayState

**Summary:** Synchronizes vehicle dashboard/HUD display parameters from vehicle state struct to D3D device render states. Caches values to avoid redundant D3D calls. Part of graphics display system for in-car HUD rendering.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5550E0 (005550e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0xC8 | R | — | D3D device vtable method at offset 200 (setter for render state/parameter) |
| this | 0x0 | RW | — | result/status storage for last D3D call |
| this | 0x1100 | R | — | pointer to IDirect3DDevice9 interface |
| this | 0x13A8 | R | — | device capability flags; bits 0x4000/0x8000 select display mode path |
| this | 0x14F0 | RW | 0 | display enabled flag (0=disabled, 1=enabled) |
| this | 0x14F4 | RW | — | cached combined dashboard value (from vehicle int16 fields at a2+392/394/396) |
| this | 0x14F8 | RW | — | cached float value 1 (synced from vehicle a2+400) |
| this | 0x14FC | RW | — | cached float value 2 (synced from vehicle a2+404) |
| this | 0x1500 | RW | — | cached float value 3 (synced from vehicle a2+408) |
| this | 0x1504 | RW | — | cached state flags (synced from vehicle a2+412) |

**Written-by note (persistence):**
- this 0x0: overwritten each D3D call, transient status
- this 0x14F0: set to 0 or 1 each call based on whether vehicle has display state
- this 0x14F4: written only when combined int16 value changed from cache
- this 0x14F8: written only when float at a2+400 changed from cache
- this 0x14FC: written only when float at a2+404 changed from cache
- this 0x1500: written only when float at a2+408 changed from cache
- this 0x1504: written only when state flags from a2+412 changed from cache

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** 
1. `(*(_DWORD *)(a2 + 412) & 0xE0000) == 0` → vehicle has no dashboard state: set enabled=0, call D3D setter(28, 0), return. PASSES: non-zero state present.
2. Per-field cache compare: only call D3D setter when cached value != new vehicle value (avoid redundant calls for unchanged fields).
3. `this[1345] == v6` (state flags unchanged) → return 0 early.
4. flag bit 0x4000 at this+0x13A8 set → use D3D setter(35, mapped_mode).
5. flag bit 0x8000 at this+0x13A8 set → use D3D setter(140, mapped_mode).
6. neither flag → disable display: set enabled=0, call D3D setter(28, 0).