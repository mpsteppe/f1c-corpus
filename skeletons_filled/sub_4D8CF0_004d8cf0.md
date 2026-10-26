## sub_4D8CF0_004d8cf0 — HUD texture/quad resource initializer

**Summary:** Initializes HUD render resources (texture quads) for types 1-5: releases existing resource, then creates a new render object with 4 textured quad vertices positioned at screen-scaled coordinates using normalized dimensions (this[57]/this[58]). Type 3 additionally loads a D3D texture from file and allocates a 96-byte zero-filled struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceInitWithConstants (004d8220)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE4 | R | — | Normalized screen width — scales quad X positions |
| this | 0xE8 | R | — | Normalized screen height — scales quad Y positions |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004d8f94 | jpt_4D8D1F | R | Switch jump table for a2 (1-5 dispatch) |
| 005c6784 | aSSS_0 | R | sFormatPath [DERIVED] |
| 005d4ad8 | aHud51264Tga | R | HUD texture filename "HUD51264.tga" for type 3 |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 005ec428 | dword_5EC428 | R | SeasonName [DERIVED] |
| 00800004 | unk_800004 | R | InvalidPtrSentinel [DERIVED] |
| 008ad398 | dword_8AD398 | R | StateHandleArray [DERIVED] — render object handle for type 1 |
| 008ad39c | dword_8AD39C | R | RenderBufferID_2 [DERIVED] — render object handle for type 2 |
| 008ad3a0 | dword_8AD3A0 | R | AudioEmitter_Idx3 [DERIVED] — render object handle for type 3 |
| 008ad3a4 | dword_8AD3A4 | R | AudioChannel4 [DERIVED] — render object handle for type 4 |
| 008ad3a8 | flt_8AD3A8 | R | AudioStreamHandle [DERIVED] — render object handle for type 5 |
| 008ad3ac | dword_8AD3AC | RW | TrackDB_DataPtr [DERIVED] — type 3 extra struct (96-byte alloc, texture metadata) |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d9030 | AudioResourceReleaseByType | Releases existing resource of given type before re-init |
| 0054fe10 | StructInitWithZeroFill | Zero-fills allocated 96-byte struct for type 3 |
| 00550080 | D3DTextureCreation | Loads D3D texture from constructed TGA path |
| 005502c0 | DestructorWithConditionalFreeFlagClear | Destructor for type 3 extra struct on texture load failure |
| 00553620 | SetterWrites0x10Returns0 | Post-creation setter for type 3 after quad init |
| 00553650 | sub_553650 | Sets up one quad vertex with position and UV coordinates (4 calls per quad) |
| 00553980 | ObjectConstructorWithAllocationAndSubInit | Creates render object with allocation parameters (2, 0, 32, 64) |
| 00557470 | EmptyStub_7470 | Stub called during cleanup on texture load failure |
| 00587bcf | FreeWrapper_7bcf | Memory deallocation for type 3 extra struct on failure |
| 00587c03 | OperatorNewNhMallocWrapper | Allocates 96 bytes for type 3 extra struct |
| 0058815f | StringFormatWithBufferOverflowCheck | Formats texture path with season dir/name + filename |

**Guard conditions:** `a2` outside [1-5] → return 1 (failure). For cases 1,2,4,5: if `*v5` (handle) is already non-null → skip creation (already initialized). Type 3: path components `dword_5EC428`/`dword_5EC3D8` null → fallback to `byte_5EA438`; if D3DTextureCreation fails → cleanup and reset `v4` to sentinel.
