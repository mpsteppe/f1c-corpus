// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044BE70
// Canonical corpus name: HTreeTerrainFileFormatLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HTreeTerrainFileFormatLoader_0044be70.c

void UnknownObject::HTreeTerrainFileFormatLoader()
{
    // Terrain H-tree file loader: opens the file via the audio-stream abstraction, validates a 46-byte version string against the expected literal and reads the header fields (three 8-byte geometry blocks into this[2]/this[4]/this[6]/this[8] and three 4-byte counts), allocates the main collision data buffer (92 bytes per object) and a collision-object array (16 bytes per node), then deserializes the collision tree and frees scratch buffers. Returns 0 on success, -1 after cleanup on any validation or read failure.
    // CALL: Zero-initialize the cleanup tracking struct v20 via ZeroInitSmallStruct(v20). [callee:0x005668B0, source:raw]
    // CALL: Open the file for reading via AudioStreamOpen(a2, 0). [callee:0x00566B20, source:raw]
    // GUARD: Combined validation guard: open failure (v20[0] null), short 46-byte version read, version string mismatch, short reads of any header block or count all route to the error-cleanup path (LABEL_26). [source:raw]
    // CALL: Read the 46-byte version string via FileWriteWithBackendDispatch(v19, 46), expecting exactly 46 bytes. [callee:0x00566C00, source:raw]
    // CALL: Compare the read version string against the expected literal aVer006ThisFile. [global:0x005C445C, source:raw]
    // CALL: Read the first 8-byte header block into this+2 (dword index 2) via FileWriteWithBackendDispatch. [callee:0x00566C00, source:raw]
    // CALL: Read three further 8-byte header blocks into this+4, this+6 and this+8 via FileWriteWithBackendDispatch. [callee:0x00566C00, source:raw]
    // CALL: Read three 4-byte counts into v18, v17 and v16 via FileWriteWithBackendDispatch. [callee:0x00566C00, source:raw]
    // CALL: Allocate the main collision data buffer with OperatorNewNhMallocWrapper(92 * v18), store it at *this and track it in v20[9]. [callee:0x00587C03, field:this:0x00000000, source:raw]
    // CALL: Allocate the collision-object array with OperatorNewNhMallocWrapper(16 * v17 + 4); on success store the count at the leading word and iterate the body. [callee:0x00587C03, source:raw]
    // LOOP: do-while loop over v17 collision nodes calling CollisionObjectInit(v8) on each 16-byte slot. [callee:0x0044A430, source:raw]
    // ASSIGNMENT: Store the collision-object array pointer in this[1] (and mirror it in v23). [field:this:0x00000004, source:raw]
    // CALL: Allocate the scratch entry buffer with OperatorNewNhMallocWrapper(16 * v16) as v25. [callee:0x00587C03, source:raw]
    // LOOP: Loop over v16 entries reading 4+8+4 bytes per entry into the scratch buffer; any short read jumps to the failure cleanup (LABEL_24). [callee:0x00566C00, source:raw]
    // GUARD: Tree deserialization runs only when v17 (node count) is greater than zero; sets v21 = 1 before it. [source:raw]
    // CALL: Deserialize collision tree nodes via CollisionTreeNodeDeserializer(v23, v20); a non-zero return triggers failure cleanup. [callee:0x0044A700, source:raw]
    // CALL: Free the scratch buffer v25 via FreeWrapper_7bcf(v25) on both the failure and success paths. [callee:0x00587BCF, source:raw]
    // CALL: Error path: run SubCallWithConditionalFieldFree(v20) and return -1. [callee:0x005668D0, source:raw]
    // CALL: On success, close the file handle via ConditionalFileHandleCloseWithFlagDispatch(v20), then run SubCallWithConditionalFieldFree(v20). [callee:0x00566B90, source:raw]
    // RETURN: Return 0 on successful load. [source:raw]
    // CALL: Invoked by SceneTrackFileLoader (0x0044C0E0) to load a terrain H-tree file. [caller:0x0044C0E0]

    // Conservative worker pseudocode:
    //   ZeroInitSmallStruct(v20);
    //   AudioStreamOpen(a2, 0);
    //   if (!v20[0] || FileWriteWithBackendDispatch(v19, 46) != 46
    //       || strcmp(v19, aVer006ThisFile)
    //       || FileWriteWithBackendDispatch(this+2, 8) != 8
    //       || FileWriteWithBackendDispatch(this+4, 8) != 8
    //       || FileWriteWithBackendDispatch(this+6, 8) != 8
    //       || FileWriteWithBackendDispatch(this+8, 8) != 8
    //       || FileWriteWithBackendDispatch(&v18, 4) != 4
    //       || FileWriteWithBackendDispatch(&v17, 4) != 4
    //       || FileWriteWithBackendDispatch(&v16, 4) != 4) goto error;
    //   *this = OperatorNewNhMallocWrapper(92 * v18); v20[9] = *this;
    //   arr = (int*)OperatorNewNhMallocWrapper(16 * v17 + 4);
    //   if (arr) { arr[0] = v17; for (n = v17; n; --n) CollisionObjectInit(slot), slot += 16; }
    //   this[1] = arr ? (int)(arr + 1) : 0;
    //   v25 = (char*)OperatorNewNhMallocWrapper(16 * v16);
    //   for (n = 0; n < v16; ++n)
    //       if (FileWriteWithBackendDispatch(v25+n*16, 4) != 4
    //           || FileWriteWithBackendDispatch(v25+n*16+4, 8) != 8
    //           || FileWriteWithBackendDispatch(v25+n*16+12, 4) != 4) goto fail;
    //   if (v17 > 0) { v21 = 1; if (CollisionTreeNodeDeserializer(this[1], v20)) goto fail; }
    //   fail: if (v25) FreeWrapper_7bcf(v25);
    //   error: SubCallWithConditionalFieldFree(v20); return -1;
    //   if (v25) FreeWrapper_7bcf(v25);
    //   ConditionalFileHandleCloseWithFlagDispatch(v20);
    //   SubCallWithConditionalFieldFree(v20);
    //   return 0;
    // UNRESOLVED: Exact meaning of the three counts (v18, v17, v16) and the geometry layout of the 8-byte header blocks is inferred from allocation sizes only.
    // UNRESOLVED: CollisionObjectInit and CollisionTreeNodeDeserializer internals are out of scope; only their call sites are asserted here.
}
