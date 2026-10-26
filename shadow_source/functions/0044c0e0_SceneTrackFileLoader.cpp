// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044C0E0
// Canonical corpus name: SceneTrackFileLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneTrackFileLoader_0044c0e0.c

void UnknownObject::SceneTrackFileLoader()
{
    // Loads and rebuilds the track scene/terrain. Builds a weather-dependent path buffer (allocated, '.hat' + track basename + '^' separator, '.scn' handling), queries registry timestamps to detect a newer source, and when newer or when the weather-mode flag is set loads the terrain via HTreeTerrainFileFormatLoader, ensures the directory hierarchy exists via CreateDirectoryAWrapper, and rebuilds collision geometry (CollisionShapeInit, CollisionGeometryOperationSelector, BoundingBoxComputationFromTriangles, sub_44BC50, PhysicsBufferFree, CollisionGridRaycast32x32). Frees the temporary path buffer on exit. Gated by EmptyStubWithFlagCheck debug/profile stubs when dword_8B8F24 is non-zero.
    // GUARD: Entry debug/profile gate: if dword_8B8F24 is non-zero, call EmptyStubWithFlagCheck(2, 0). [global:0x008B8F24, callee:0x0053AC70, source:raw]
    // CALL: CollisionTreeNodeCleanup(this) clears the existing collision tree state before rebuilding. [callee:0x0044C470, source:raw]
    // CALL: SinTableInit() initializes sine tables. [callee:0x0044C430, source:raw]
    // CALCULATION: Take the track path from dword_7CE5D0 (fallback byte_5EA438) and walk back to the last backslash (decimal 92) to isolate the file basename into v4. [global:0x007CE5D0, global:0x005EA438, source:raw]
    // ASSIGNMENT: v26 = OperatorNewNhMallocWrapper(256); *v26 = 0 allocates the temporary path buffer. [callee:0x00587C03, source:raw]
    // CALL: StringCopyWithBufferRealloc(dword_5EC438 or byte_5EA438) copies the weather/season directory path into the v26 buffer. [callee:0x00566650, global:0x005EC438, global:0x005EA438, source:raw]
    // CALL: sub_5665B0(aHat) appends the '.hat' extension and sub_5665B0(v4) appends the track basename. [callee:0x005665B0, global:0x005C44A4, source:raw]
    // CALCULATION: Strip the extension: locate the period (decimal 46) in the built path and null-terminate there. [source:raw]
    // CALL: sub_5665B0(aHat_0) appends the '^' separator field during path building. [callee:0x005665B0, global:0x005C449C, source:raw]
    // GUARD: If byte_7CFEE8 (weather-mode flag) is set, skip the registry timestamp checks entirely and continue to the load path. [global:0x007CFEE8, source:raw]
    // CALL: RegistryKeyQuery on the built path and on dword_7CE5D0 (fallback byte_5EA438); if the source timestamp is not newer (query >= saved value v9), skip the rebuild. [callee:0x00449A20, global:0x007CE5D0, global:0x005EA438, source:raw]
    // CALL: strcpy SrcStr from the track path, sub_589901(SrcStr) normalizes it, then sub_587C20(SrcStr, aScn_0) locates the '.scn' substring. [callee:0x00589901, callee:0x00587C20, global:0x005C4494, source:raw]
    // GUARD: If the '.scn' substring is not found (v13 null), skip the rebuild path. [source:raw]
    // ASSIGNMENT: Copy the dword_5C448C string byte-by-byte to the destination offset v15 = v13 - &dword_5C448C, extending the scene path with the weather-dependent string identifier. [global:0x005C448C, source:raw]
    // GUARD: If RegistryKeyQuery(SrcStr) >= v11 skip; fill v30 via sub_4CEEF0(v30, 256); if RegistryKeyQuery(v30) >= v11 skip. [callee:0x00449A20, callee:0x004CEEF0, source:raw]
    // CALL: If HTreeTerrainFileFormatLoader(this, v26 path) succeeds, continue with the collision rebuild; otherwise fall to the cleanup path. [callee:0x0044BE70, source:raw]
    // CALL: On the successful load path CollisionTreeNodeCleanup(this) is called again before rebuilding geometry. [callee:0x0044C470, source:raw]
    // CALL: Shared cleanup path: StringCopyWithBufferRealloc(v26) reinitializes the path buffer. [callee:0x00566650, source:raw]
    // LOOP: Walk byte_5EA438 path segments; at each backslash segment call sub_587DD0(PathName, byte_5EA438, v21), null-terminate, and CreateDirectoryAWrapper(PathName); finally CreateDirectoryAWrapper(byte_5EA438) creates the full directory hierarchy. [callee:0x00587DD0, callee:0x00589671, global:0x005EA438, source:raw]
    // CALL: CollisionShapeInit(v28) initializes the collision shape/work structure. [callee:0x004492B0, source:raw]
    // CALL: CollisionGeometryOperationSelector(this, a2, v28) selects the geometry operation to run on the loaded data. [callee:0x0044BB60, source:raw]
    // CALL: BoundingBoxComputationFromTriangles(this, v28) computes bounding boxes from the collision triangles. [callee:0x0044B910, source:raw]
    // CALL: sub_44BC50(this, v26 path, v28) builds the collision structures, then PhysicsBufferFree(v28) releases the work buffer. [callee:0x0044BC50, callee:0x00449340, source:raw]
    // CALL: CollisionGridRaycast32x32(this) performs a 32x32 grid raycast setup over the rebuilt collision geometry. [callee:0x0044BA40, source:raw]
    // GUARD: Exit debug/profile gate: if dword_8B8F24 is non-zero, call EmptyStubWithFlagCheck(1, 0). [global:0x008B8F24, callee:0x0053AC70, source:raw]
    // RETURN: Return the temporary v26 path buffer, freeing it with FreeWrapper_7bcf when non-null. [callee:0x00587BCF, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_8B8F24) EmptyStubWithFlagCheck(2, 0);
    //   CollisionTreeNodeCleanup(this);
    //   SinTableInit();
    //   v4 = basename_after_last_slash(dword_7CE5D0 ?: byte_5EA438);
    //   v26 = OperatorNewNhMallocWrapper(256); *v26 = 0;
    //   StringCopyWithBufferRealloc(dword_5EC438 ?: byte_5EA438);
    //   sub_5665B0(".hat"); sub_5665B0(v4);
    //   strip_extension(v26);
    //   sub_5665B0("^");
    //   if (!byte_7CFEE8) {
    //       v11 = RegistryKeyQuery(v26);
    //       if (RegistryKeyQuery(dword_7CE5D0 ?: byte_5EA438) >= v11) goto cleanup;
    //       strcpy(SrcStr, dword_7CE5D0 ?: byte_5EA438); sub_589901(SrcStr);
    //       if (!sub_587C20(SrcStr, ".scn")) goto cleanup;
    //       copy_dword_5C448C_into(SrcStr);
    //       if (RegistryKeyQuery(SrcStr) >= v11) goto cleanup;
    //       sub_4CEEF0(v30, 256);
    //       if (RegistryKeyQuery(v30) >= v11) goto cleanup;
    //   }
    //   if (HTreeTerrainFileFormatLoader(this, v26)) {
    //       CollisionTreeNodeCleanup(this);
    //   }
    //   cleanup:
    //   StringCopyWithBufferRealloc(v26);
    //   create_directory_hierarchy(byte_5EA438);
    //   CollisionShapeInit(v28);
    //   CollisionGeometryOperationSelector(this, a2, v28);
    //   BoundingBoxComputationFromTriangles(this, v28);
    //   sub_44BC50(this, v26, v28);
    //   PhysicsBufferFree(v28);
    //   CollisionGridRaycast32x32(this);
    //   if (dword_8B8F24) EmptyStubWithFlagCheck(1, 0);
    //   if (v26) return FreeWrapper_7bcf(v26);
    // UNRESOLVED: dword_8ACEA0 is listed as a read global but does not appear in the raw function text.
    // UNRESOLVED: abi:lead names this function Scene_Track_File_Loader (LEGACY); canonical name SceneTrackFileLoader retained.
    // UNRESOLVED: RegistryKeyQuery comparison (timestamp freshness) is transcribed but its exact registry-value contract is not proven.
    // UNRESOLVED: Argument a2 is forwarded to CollisionGeometryOperationSelector; its meaning is not independently confirmed.
    // UNRESOLVED: The exact layout of the v28 collision work structure passed to the four geometry helpers is unknown.
}
