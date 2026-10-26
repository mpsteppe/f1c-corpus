## RenderSurfaceFillCopy_004918d0 — UpdateBroadphaseRegion

**Summary:** Dispatches broadphase collision update for screen region (a2-a5). If race phase timer allows, updates all stored broadphase structures; otherwise updates only current ring-bucket slot. Called from many render paths.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIScrollViewRender (00486ac0), F_2DSurfaceBlitWithViewportClipping (0048a240), MediaBufferPlaybackManager (0048d9d0), sub_48E4B0 (0048e4b0), ConditionalGeometryDisplayUpdate (0048e5c0), FPSOverlayDraw (00495440), UIComboListRender (00495580), UITextDialogRendering (00495bd0), sub_496E90 (00496e90), sub_4973D0 (004973d0), BitmapDraw (004980d0), sub_4989E0 (004989e0), GuardedDrawRenderDispatch (00498fe0), GuardedSubRectangleRenderDispatch (00499050), ScrollOffsetUpdateWithConditionalDispatch (0049acc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | First DWORD of each 16-byte array element (broadphase substructure head) |
| obj | 0x4 | R | — | Second DWORD of each array element |
| obj | 0x8 | R | — | Third DWORD of each array element |
| this | 0x0 | R | — | Outer pointer — *this is header with count[0], index[1], array_base[2] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer — decides full vs incremental update |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490ee0 | CollisionBroadphaseBuilder | Build/update broadphase list for given AABB (a2-a5) on target struct |
| 004f9b20 | sub_4F9B20 | Check race phase timer: true = full update all buckets, false = single bucket |

**Guard conditions:** If a4 <= 0 or a5 <= 0 (no extent) → return 0, no update. If `**this` (count) > 0: iterate all elements calling CollisionBroadphaseBuilder on each. If timer check fails: call CollisionBroadphaseBuilder only on current ring slot `(*this)[2] + 16*(*this)[1]`.
