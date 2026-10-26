## RenderUISystemGlobalInit_0053c360 — InitializeRenderAndAudioSystems

**Summary:** Initializes global render and audio system state — zeroes entry arrays, sets default flags (visibility mask, audio init, mipmap, texture effects), applies audio quality presets (medium or high) based on init flags, starts audio subsystems, and allocates network config (160 bytes) and render resource (12 bytes) handles.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SystemInitAllocatorWrapper (0053d470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b5a3c | byte_8B5A3C | R | AudioEntryArray [DERIVED] (also: ` — entry array base (stride 0x84) |
| 008b6abc | byte_8B6ABC | R | MemPoolEndMarker [DERIVED] |
| 008b6ac0 | dword_8B6AC0 | W | PhysicsObjectCount [DERIVED] |
| 008b6ac4 | dword_8B6AC4 | W | TextureEffectGate [DERIVED] (also: undocumented global, gates flag manipulation) |
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |
| 008b8cec | dword_8B8CEC | W | Int_AudioQuality [DERIVED] |
| 008b8cf0 | flt_8B8CF0 | W | RendererBrightness [DERIVED] |
| 008b8cf4 | flt_8B8CF4 | W | AudioMusicVolume [DERIVED] |
| 008b8dc4 | dword_8B8DC4 | W | AudioMixer_InitFlag [DERIVED] |
| 008b8dc8 | dword_8B8DC8 | W | RenderDevicePtr [DERIVED] (also: RenderDevicePtr (D3D device/renderer interface, docs/12, docs/19) |
| 008b8dcc | dword_8B8DCC | W | RendererStateFlag [DERIVED] |
| 008b8dd0 | dword_8B8DD0 | W | RendererInitZero [DERIVED] |
| 008b8e24 | dword_8B8E24 | W | AudioInitFlag [DERIVED] |
| 008b8e28 | dword_8B8E28 | W | AudioInitialized [DERIVED] |
| 008b8e2c | dword_8B8E2C | W | RendererMipmapFlag [DERIVED] |
| 008b8e30 | dword_8B8E30 | W | RegisteredEntryCount [DERIVED] (also: ` — entry count (max 0x20) |
| 008b8e34 | dword_8B8E34 | W | RenderVisibilityMask [DERIVED] (also: ` — renderer state/flag mask (not in docs/12; likely renderer visibility or active-state mask) |
| 008b8ee0 | dword_8B8EE0 | W | AudioSystemFlags [DERIVED] |
| 008b8f04 | dword_8B8F04 | W | NetConfigData [DERIVED] |
| 008b8f14 | dword_8B8F14 | W | ObjLinkedListHead [DERIVED] |
| 008b8f18 | dword_8B8F18 | W | NetConfigData [DERIVED] |
| 008b8f1c | dword_8B8F1C | W | NetConfigData [DERIVED] |
| 008b8f20 | dword_8B8F20 | W | NetConfigData [DERIVED] |
| 008b8f2c | dword_8B8F2C | W | RenderResourceHandle2 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053b0d0 | ArithmeticComparison_b0d0 | Arithmetic comparison / initialization sequence step |
| 0053d750 | sub_53D750 | Initializes sound manager subsystem from global pointer |
| 0053d930 | StateIntSetter4 | Sets 4 integer state values (audio parameters: -1, -1, 16000, 12000) |
| 005566d0 | InitializeAudioSystemChannels | Initializes audio system channel array from entry array base |
| 005593b0 | StructZeroInit_93b0 | Zero-initializes 12-byte struct and returns pointer (for render resource) |
| 0055be80 | sub_55BE80 | Initializes renderer with device parameters and init flag (a5 & 1) |
| 0055f060 | GlobalMemoryStatusWrapper | Queries global memory status for system diagnostics |
| 0055f080 | StructZeroInitConstructor_f080 | Zero-initializes and constructs 160-byte struct (for net config) |
| 0055f0d0 | sub_55F0D0 | Additional initialization step after net config allocation |
| 00587c03 | OperatorNewNhMallocWrapper | Operator new (nothrow) memory allocation |

**Guard conditions:** a5 & 2 → skip audio/render configuration (goto LABEL_10, BLOCKED: bit 2 bypasses all audio/render init). a5 & 4 → medium quality audio preset: sets quality=2, brightness=0.5, volume=0.5 (PASSES). a5 & 8 → high quality audio preset: sets quality=3, brightness≈0.333, volume≈0.333 (PASSES). Neither 4 nor 8 → skips audio quality config, proceeds directly to sub_53D750 sound manager init (PASSES default path). After quality preset (if any), always calls StateIntSetter4 and sub_53D750 (unconditional progression).
