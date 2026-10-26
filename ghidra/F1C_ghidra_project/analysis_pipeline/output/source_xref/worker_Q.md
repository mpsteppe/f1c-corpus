# Source Cross-Reference: docs/19-renderer.md

## RTTI Class Mappings

| rFactor Class | F1C Function(s) | Confidence | Evidence |
|--------------|-----------------|------------|----------|
| `Render` | ~481 renderer functions across docs/19 | HIGH | rFactor Dedicated.exe RTTI contains `.?AVRender@@`; source path `..\Source\render.cpp` present in both binaries (rfactor_binaries.txt lines 134, 726). F1C renderer matches rFactor Render class lifecycle: Init/Setup/Post/Restart/Enter/Exit pattern. |
| `VidMan` | D3D device/display group (~30 funcs: FUN_0044fa60, FUN_0053d4f0, FUN_0053eb70, FUN_0053f270, FUN_00543bf0, FUN_00563e00, FUN_005646d0, FUN_0053db90, FUN_0053c360, FUN_0055bbf0, FUN_0044ee10) | HIGH | rFactor RTTI: `.?AVVidMan@@`. Source path `..\Source\vidman.cpp` in both binaries. F1C VidMan handles D3D device lifecycle matching rFactor's VidMan role. |
| `SpecialFX` | Particle/effect group (~20 funcs: FUN_004eb430, FUN_004f8850, FUN_004c8f10, FUN_004ce930, FUN_004cb620, FUN_004cbc50, FUN_004cfcc0, FUN_004fd8b0, FUN_004ccdc0, FUN_004cc500, FUN_004c9d60, FUN_004ec080, FUN_0040f550) | HIGH | rFactor RTTI: `.?AVSpecialFX@@`. Source path `..\Source\specialfx.cpp` shared (rfactor_binaries.txt line 135). Particle effect dispatch, trail/spark/smoke emission matches SpecialFX class role. |
| `SoundMan` | FUN_004e0ed0 (Audio/Sound Effect Controller) | HIGH | rFactor RTTI: `.?AVSoundMan@@`. Source `..\Source\sound.cpp` shared. F1C FUN_004e0ed0 handles engine/gear/skid/brake/collision sounds matching SoundMan behavior. |
| `OnScreen` | UI/HUD group (~80 funcs: FUN_0048aed0, FUN_0048b030, FUN_0048b600, FUN_004957a0, FUN_00489ab0, FUN_00411840, FUN_00411b50, FUN_00411db0, FUN_0049b370, FUN_0048f640, FUN_00498560, FUN_0048f870, etc.) | HIGH | rFactor RTTI: `.?AVOnScreen@@`. Source `..\Source\onscreen.cpp` shared. UI screen load/render/event dispatch pattern matches OnScreen class. |
| `Options` | UI options struct init functions (FUN_0048e600, FUN_0048e9e0, FUN_0048ebd0, FUN_0048f9f0) | HIGH | rFactor RTTI: `.?AVOptions@@` plus full UI widget hierarchy. Source `..\Source\options.cpp` shared. Matches options screen setup. |
| `Options_SliderBar` | FUN_00495580 (combo/list render), FUN_00496930 (type-based render) | MEDIUM | RTTI `.?AVOptions_SliderBar@@` in rFactor. Slider bar pattern matches UI slider rendering functions. |
| `Options_CheckBox` | FUN_00487460 (radio/check state handler) | MEDIUM | RTTI `.?AVOptions_CheckBox@@` present. Checkbox state change handler matches documented behavior. |
| `Options_SpinBox` | FUN_004874e0 (UI value validator), FUN_00489600 (UI menu item creator with ranges) | MEDIUM | RTTI `.?AVOptions_SpinBox@@` present. SpinBox has value range validation matching documented behavior. |
| `Options_BinkAnimation` | Bink playback functions | MEDIUM | RTTI `.?AVOptions_BinkAnimation@@` present. BINK video playback in UI (FUN_00488f40 dispatch). |
| `TvOverlayPageBase` | HUD/overlay group (FUN_0048b030 — UI full render pass, FUN_0048fee0 — full render with dims) | MEDIUM | rFactor RTTI has full `TvOverlayPage*` hierarchy. F1C HUD overlay matches broadcast overlay pattern but less advanced. |
| `TvOverlayPageRaceHUD` | FUN_0048b030 (full HUD render), FUN_004c7f30 (FOV/HUD interaction) | MEDIUM | RTTI `.?AVTvOverlayPageRaceHUD@@` present. HUD overlay during race matches. |
| `cubeDirectX` | D3D device creation functions (FUN_0044fa60, FUN_0053d4f0) | HIGH | rFactor RTTI: `.?AVcubeDirectX@@`, `.?AVcubeGraphicsDevice@@`, `.?AVcubeBase@@`. These are the CUBE engine base classes for D3D abstraction. F1C uses CUBE41 (NASCAR_2003 era) based on dev_tree.txt timeline. |
| `cubeGraphicsDevice` | Render state management (FUN_00586700, FUN_00554790, FUN_0053eb70 state init) | HIGH | RTTI: `.?AVcubeGraphicsDevice@@`. Manages D3D device interface. |
| `cubeBase` | Resource lifecycle base class (allocation/release chain) | MEDIUM | RTTI: `.?AVcubeBase@@`. Parent of cubeDirectX/GfxDevice. |
| `ReplayMan` | Replay-related rendering (FUN_004c8b70 checks replay mode) | MEDIUM | RTTI `.?AVReplayMan@@` in rFactor. Replay rendering integration. |
| `PFController` | UI text/control input handling (FUN_004896c0 text input, FUN_0048b600 event handler) | MEDIUM | RTTI `.?AVPFController@@`. Player file/controller config integration. |
| `HWInput` | Input device handling in UI context | LOW | RTTI `.?AVHWInput@@`. Input device reading during menu navigation. |

## Parameter-to-Offset Mappings

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| `RenderMethod` | COMPONENTS | — | — | RenderMethod (component selection: 0=HW T&L, 1=SW) | MEDIUM |
| `RenderTargetParms` | COMPONENTS | — | — | RenderTargetParams (position/size) | MEDIUM |
| `RenderTexSize` | COMPONENTS | — | — | RenderTextureSize (0=low, 1=high) | MEDIUM |
| `LODMultiplier` | GARAGE | — | DAT_007cf8a8 (detail level) | LODMultiplier (garage LOD quality 0.01-1.00) | MEDIUM |
| `VisibleVehicles` | GRAPHICS | — | DAT_007cfc8c (max visible vehicles) | MaxVisibleVehicles | HIGH |
| `MipmapBias` | GRAPHICS | — | — | MipmapBias (texture LOD bias) | MEDIUM |
| `VSync` | DISPLAY | — | — | VSync (0=off, 1=on) | LOW |
| `HeadPhysics` | VEHICLE | param_1+0x48bc (bit 1) | VCAN+0x48bc | HeadPhysicsMode (head movement effect) | MEDIUM |
| `GraphicalOffset` | GENERAL (.hdv) | — | DAT_007cf2cc (GfxOffset) | GraphicalOffset (vehicle body visual offset) | MEDIUM |
| `TextureFilter` | DISPLAY | — | — | TextureFilter (enum: bilinear/trilinear/anisotropic) | LOW |

## String Matches

| String | Found In | F1C Function | Insight |
|--------|----------|-------------|---------|
| `CUBE 3D Engine v` | NASCAR_2003_3DConfig, NASCAR_2004_3DConfig, rF_Config | FUN_0044fa60 (D3D Device Init) | Identifies F1C CUBE engine as v4.1 (CUBE41) from NASCAR_2003 era (dev_tree.txt: CUBE41\Library\Source\) |
| `CUBEMAS4.00` / `CUBEMAS4.01` / `CUBEMAS4.10` | ALL ISI binaries | FUN_00547b40 (mesh parse), FUN_0054fc10 (texture load) | CUBE MAS archive format version markers. F1C uses 4.00 — earliest version. |
| `..\Source\render.cpp` | rFactor Dedicated.exe, NASCAR_2004_Dedicated | All docs/19 functions | Shared source tree: `D:\dev\F1_1999_2002\Source\render.cpp` |
| `..\Source\vidman.cpp` | rFactor Dedicated.exe | VidMan group | Shared source: `D:\dev\F1_1999_2002\Source\vidman.cpp` |
| `..\Source\specialfx.cpp` | rFactor Dedicated.exe | Particle/effect group | Shared source: `D:\dev\F1_1999_2002\Source\specialfx.cpp` |
| `..\Source\onscreen.cpp` | rFactor Dedicated.exe | UI/HUD functions | Shared source: `D:\dev\F1_1999_2002\Source\onscreen.cpp` |
| `..\Source\options.cpp` | rFactor Dedicated.exe | Options UI functions | Shared source across all ISI games |
| `Source map for render target %s CANNOT be a DXTn format.` | rFactor, NASCAR_2004, rF_Config | FUN_00548190 (texture creation) | Identifies DXT texture format check during render target creation |
| `Update texture: Source texture is not a render target - video to system.` | rFactor, rF_Config | FUN_00502a15 (surface format negotiation) | Render target vs system memory texture path |
| `CUBENORMALIZER` | rFactor, NASCAR_2004, rF_Config | FUN_0053eb70 (render device init) | CUBE resource normalization step during device init |
| `No cubeView allocated - no use for a texture.` | rFactor Dedicated, NASCAR_2004_Dedicated | FUN_00548190 | Texture allocation guard: no viewport → skip texture creation |
| `Error 0x%x creating D3D cube render target` | rFactor, rF_Config | FUN_0044fa60 | Cube map render target creation error |
| `Invalid CUBE vertex buffer pointer` / `Invalid CUBE index buffer pointer` | rFactor, rF_Config | FUN_00540df0, FUN_00540f00 | Vertex/index buffer validation in D3D resource code |
| `CUBEApp` / `CUBERealtime` | rFactor Dedicated | FUN_00563e00 (display mode init) | Application mode: App vs Realtime rendering path |
| `D3DXCreateCubeTexture` / `D3DXFillCubeTexture` | rFactor, rF_Config | FUN_00548190 | DirectX D3DX utility calls for cube texture creation |
| `HeadPhysics` | rFactor Dedicated, NASCAR_2004_Dedicated | FUN_004c7f30 (FOV interpolation) | Head physics integration with camera system |
| `CUBE error loading scene file %s: %s` | rFactor Dedicated | FUN_0044c0e0 (scene/track file loader) | Scene loading error string shared across ISI binaries |
| `CUBE Error: %s` | rFactor Dedicated | FUN_0053eb70 | Generic CUBE engine error |
| `CUBE error loading pitcrew mesh %s: %s` | rFactor Dedicated | FUN_004c71c0 (car render) | Pit crew mesh loading — part of vehicle rendering |
| `APP_SpinBox_GraphOpt_VisibleVehicles` | NASCAR_2003_Demo, NASCAR_2003_Patch | FUN_004c8b70 (RenderTickUpdate) | UI control for max visible vehicles — matches DAT_007cfc8c |
| `APP_Slider_GraphOpt_HeadPhysics` | NASCAR_2003_Demo, NASCAR_2003_Patch | FUN_004c7f30 (FOV update) | UI slider for head physics effect |
| `APP_SpinBox_GraphOpt_CockPit` | NASCAR_2003_Demo | FUN_004c7aa0 (driver visibility) | Cockpit view toggle in UI |
| `APP_SpinBox_GraphOpt_PitCrewAnimDetail` | NASCAR_2003_Demo | FUN_004c71c0 | Pit crew animation detail level |
| `LOD multiplier when vehicle is in garage` | rFactor Dedicated | FUN_004f8440 (position/state update for render) | Garage LOD quality parameter |
| `For opponents' vehicle textures` | rFactor Dedicated | FUN_0050b8a9 (texture FourCC dispatch) | Opponent texture quality override |
| `Safety car light animation` | rFactor Dedicated | FUN_004c71c0 (car render) | Safety car light rendering path |
| `Disabling suspension deformation because instance has no mesh with an LOD switch in of 0.0` | rFactor Dedicated | FUN_004c71c0 | LOD switch validation during vehicle render setup |
| `PitStopStrategies` | rFactor Dedicated | FUN_0048d6b0 (UI selection handler) | Pit stop strategy UI display |
| `Address of the alternate ISI Matchmaking server` | rFactor Dedicated | FUN_004c8b70 | Network config passed through render tick for companion app |
| `Details and visible vehicles will be automatically reduced (by up to half) if framerate is under this threshold` | rFactor Dedicated | FUN_004b3dc0 (visibility culling) | Auto-LOD based on framerate threshold |
| `Extra Visible Vehicles` | rFactor Dedicated | FUN_004b3dc0 | Extra vehicles shown outside driving |
| `Display Vehicle Labels` | rFactor Dedicated | FUN_0048b030 (UI render pass) | Vehicle label toggle |

## SDK Struct Alignment

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| **GraphicsInfo** | | | |
| `mCamPos` (TelemVect3 xyz) | +0x00 (12 bytes) | param_1+0x24 (camera pos, 12 bytes float[3]) | MATCH — FUN_0040c870 reads +0x24/0x28/0x2c, matches SDK mCamPos |
| `mCamOri` (TelemVect3 xyz) | +0x0c (12 bytes) | param_1+0x30 (camera orient) | MATCH — adjacent to position, 12 bytes |
| `mHWND` (HWND) | +0x18 (4 bytes) | param_1+0x3c | PROBABLE MATCH — window handle stored after orientation |
| **GraphicsInfoV2** | | | |
| `mAmbientRed` | +0x1c (4 bytes) | — | NOT FOUND — F1C likely uses per-frame ambient from weather system, not stored in camera context |
| `mAmbientGreen` | +0x20 (4 bytes) | — | NOT FOUND |
| `mAmbientBlue` | +0x24 (4 bytes) | — | NOT FOUND |
| **TelemInfoBase** | | | |
| `mPos` (world position) | +0x20 (12 bytes) | param_1+0x24 | STRUCTURAL MATCH — F1C camera/emitter context follows same pattern |
| `mOriX/Y/Z` (orientation matrix) | +0x30 (36 bytes) | param_1+0x30 | STRUCTURAL MATCH — 36 bytes orientation matrix |
| `mLocalRot` (rotation) | +0x54 (12 bytes) | — | NOT MAPPED in render context |
| **VehicleScoringInfoV2** | | | |
| `mPos` (world position) | +0x84 (12 bytes) | VehicleRenderContext+0x24 | PATTERN MATCH — F1C renderer reads positions from vehicle struct at same conceptual offsets |
| `mInPits` | +0x53 (1 byte) | param_1+0x48bc bit0 (VCAN state) | CONCEPTUAL MATCH — pit state flag used by FUN_004eb430 to skip particles |
| **D3D Render State Cache** (docs/13) | | | |
| D3DRS values (cached) | +0x34..+0x44 | +0x34=ZEnable, +0x38= D3DRS_8, +0x3c=D3DRS_0x1b, +0x40=D3DRS_2, +0x44=D3DRS_0x10 | NEW — F1C has 5 D3DRS cached values in state cache struct, not exposed in SDK |
| D3D Vertex Buffer Object | +0x138 (devicePtr) | +0x138=devicePtr | NEW — not part of SDK, internal impl detail |

## Proposed Renames

| Current | Proposed | Evidence |
|---------|----------|----------|
| FUN_0044fa60 — DirectXDeviceInitialization | DirectXDeviceInitialization | Confirmed CUBE D3D device init. RTTI: cubeDirectX. String: `Error 0x%x creating D3D cube render target`. |
| FUN_0053eb70 — RenderDeviceInitialization | CubeGraphicsDeviceInit | RTTI: cubeGraphicsDevice. Strings: `CUBENORMALIZER`, `CUBE Error: %s`. Matches CUBE41 device init pattern. |
| FUN_0053c360 — Render/UISystemGlobalInit | OnScreenGlobalInit | RTTI: OnScreen class. Initializes UI system globals. |
| FUN_004c8b70 — RenderTickUpdate | RenderTickUpdate | Keep name but note: maps to rFactor Render::Tick or Render::Update. |
| FUN_004b3dc0 — VehicleVisibilityCulling | VehicleVisibilityCulling | Keep name. Matches documented behavior across ISI games. |
| FUN_004eb430 — ParticleEffectUpdateDispatch | SpecialFX::Update | RTTI: SpecialFX class. Per-frame particle update matches SpecialFX role. |
| FUN_004e0ed0 — Audio/Sound Effect Controller | SoundMan::UpdateVehicleSounds | RTTI: SoundMan class. Per-vehicle sound state update. |
| FUN_0048b030 — UIFullRenderPass | OnScreen::Render | RTTI: OnScreen class. Full UI render pass. |
| FUN_00411840 — Font Rendering Prep | OnScreen::RenderText | Via OnScreen class, text/font rendering prep. |
| FUN_0053f270 — cleanup function | VidMan::ReleaseDeviceResources | RTTI: VidMan class. Releases D3D front/back buffer, depth/stencil. |
| FUN_00554790 — RenderStateChangeManager | cubeGraphicsDevice::SetRenderStates | RTTI: cubeGraphicsDevice. Diff-based render state management. |
| DAT_007cf8a8 — detail level | LODMultiplier | Config param `LODMultiplier` matches usage in particle spawn (FUN_004ce930) |
| DAT_007cfc8c — max visible vehicles | MaxVisibleVehicles | Config param `VisibleVehicles`/`APP_SpinBox_GraphOpt_VisibleVehicles` |
| DAT_008b8f24 — D3D device COM | cubeGraphicsDevicePtr | RTTI: cubeGraphicsDevice. Pointer to CUBE GPU device wrapper, not raw IDirect3DDevice8. |

## Summary

**Key findings:**

1. **CUBE41 engine base:** F1C uses CUBE v4.1 (CUBE41) renderer, same generation as NASCAR_2003, not the newer CUBE42 from NASCAR_2004. Confirmed by CUBEMAS4.00 archive version and `CUBE 3D Engine v` string shared with NASCAR_2003-era config tools.

2. **rFactor class mapping is direct:** The renderer splits cleanly into 5 main rFactor classes: `Render` (scene traversal), `VidMan` (D3D device lifecycle), `SpecialFX` (particles), `SoundMan` (audio), and `OnScreen` (UI/HUD). The CUBE graphics classes (`cubeDirectX`, `cubeGraphicsDevice`, `cubeBase`) form the D3D abstraction layer.

3. **No config params mapped to renderer struct offsets:** The rendering config params (RenderMethod, RenderTargetParms, RenderTexSize, VSync, MipmapBias) do NOT appear in F1C — they are rFactor additions. F1C's renderer uses hardcoded values with limited configurability (only VisibleVehicles and LODMultiplier are adjustable).

4. **SDK GraphicsInfo struct confirms camera layout:** GraphicsInfo's mCamPos/mCamOri layout matches F1C camera context at +0x24/+0x30. Ambient color fields (mAmbientRed/Green/Blue) are missing in F1C — ambient lighting comes from weather system instead.

5. **String evidence confirms source files:** All F1C renderer source file paths (render.cpp, vidman.cpp, specialfx.cpp, onscreen.cpp, options.cpp, sound.cpp) are shared with rFactor, confirming the common isiMotor heritage.
