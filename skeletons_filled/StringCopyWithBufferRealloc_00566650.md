## StringCopyWithBufferRealloc_00566650 — StringCopyWithRealloc

**Summary:** Copies a source string into a dynamically-allocated buffer, reallocating if the current buffer is null or too small. Returns 0 on success, -1 on null input.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** LinkedListNodeInsertion (00404e60), CameraViewStructInitializer (00405440), ViewProjectionStructInit (004057f0), MutexSynchronizationObjectInit (00406130), SortedStringListInsert (004062b0), ViewCameraReset (004064c0), sub_406790 (00406790), sub_4069F0 (004069f0), LinkedListInsertOperation (00407450), LinkedListNodeInsert (00407520), CameraPositionDefinitions (00408870), F_3DTransformObjectAllocator (0040aa20), FontRenderingPrep (00411840), CharacterCodeMapper (00411b50), FontCharacterRenderDispatcher (00411db0), SessionStringNameLookup (004122c0), TextAttributeLookup (004133b0), TextAttributeLookup_34d0 (004134d0), TextAttributeLookup_3600 (00413600), TextAttributeLookup_3710 (00413710), FilePathExtensionCheck (00414900), TextFormatStructInitializer (004149a0), TextFormatStructInitializer_4d70 (00414d70), TextFormatStructInitializer_4fe0 (00414fe0), NamedEntryLookupInFormatList (00415230), SmallEntryStructInit (00415520), VehicleListBuilderFromGlobalArray (00415780), NameListBuilderFromVehicleArray (004159b0), SceneListBuilderFromGlobalArray (00415c40), DriverNameIDLookup (00415d90), sub_417640 (00417640), sub_417AF0 (00417af0), TrackNameDisplayIDLookup (00417f60), TextOverlayDisplayTimer (004186f0), sub_41F340 (0041f340), sub_41F5D0 (0041f5d0), ConstructorChampionshipClinchDetection (0041f8a0), ConstructorStandingsParser (00420820), GdbSeasonSelector (00420cf0), ConfigDirectoryPathRegistration (004216f0), NameRegistrationDelegation (004218d0), StringCopyRealloc (004218f0), DoubleDelegateCall (00421910), ChainedCall (00421930), StringWritePathRegister (00421950), DualFunctionCallChain (00421970), ShortComputation_1990 (00421990), ShortComputation_19b0 (004219b0), sub_4219D0 (004219d0), DualFunctionDispatch (004219f0), DualRegistrationCall (00421a10), DualDispatchProcessPathRegister (00421a30), DualCallWrapper (00421a50), sub_421A70 (00421a70), ShortComputation_1a90 (00421a90), FunctionCallWrapper_1ab0 (00421ab0), PathRegistrationWrapper (00421ad0), D... (line truncated to 2000 chars)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | string buffer pointer (allocated on null, kept if large enough) |
| this | 0x4 | RW | — | buffer capacity (updated after reallocation) |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees old buffer on reallocation |
| 00587c03 | OperatorNewNhMallocWrapper | allocates new buffer memory |

**Guard conditions:** If a2 (source string) is null → return -1 (BLOCKED: no input). If buffer pointer is null OR capacity < source length → free old, allocate new, update capacity (PASS: allocation/reallocation). If capacity sufficient → copy directly without reallocation (PASS: in-place). Always copies string via strcpy after ensuring buffer is large enough.
