// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004348B0
// Canonical corpus name: sub_4348B0
// Owner: CameraObject [DERIVED]
// Raw source: functions/sub_4348B0_004348b0.c

void CameraObject::CameraObjectInit()
{
    // Allocates and initializes a 208-byte 3D transform/camera object, stores it at this+0xC, configures float camera fields from this+0x10/0x30, assigns the camera name from the 'gridwalkcam' string, and runs post-init camera setup. Shuts down any previously stored object first. Returns 0 on success, 1 if the object could not be created or track-spline setup fails.
    // GUARD: If this+0xC already holds a camera object, shut it down via VtableMethodShutdown. [field:this:0x0000000C, callee:0x00434D40]
    // CALL: Allocate a 208-byte object via OperatorNewNhMallocWrapper(208). [callee:0x00587C03]
    // CALL: Initialize the allocated object with F_3DTransformObjectInit_83b0; result is 0 if allocation failed. [callee:0x004583B0]
    // ASSIGNMENT: Store the created camera/transform object pointer at this+0xC. [callee:0x004583B0, field:this:0x0000000C]
    // GUARD: If the object is null, or TrackSplineExtrapolation(this) fails, return 1 (failure). [field:this:0x0000000C, callee:0x004349A0]
    // CALL: Copy the camera name 'gridwalkcam' (aGridwalkCam) via StringCopyWithBufferRealloc. [callee:0x00566650, global:0x005C4088]
    // ASSIGNMENT: Copy camera+0x38 from this+0x10 (float parameter). [field:*(this+0xC):0x00000038, field:this:0x00000010]
    // ASSIGNMENT: Set camera+0x3C to literal 1115291648 (62.5f). [field:*(this+0xC):0x0000003C]
    // CALL: Run GuardedFunctionWithFlagSet(0.0). [callee:0x004582C0]
    // ASSIGNMENT: Copy camera+0xA8 from this+0x30 (float parameter). [field:*(this+0xC):0x000000A8, field:this:0x00000030]
    // ASSIGNMENT: Set camera+0xA4 to literal 1073741824 (2.0f). [field:*(this+0xC):0x000000A4]
    // ASSIGNMENT: Set camera+0x48 to literal 1067450368 (1.25f). [field:*(this+0xC):0x00000048]
    // CALCULATION: Zero a local struct buffer with memset and pass it to StructFieldCopy. [callee:0x00456150, source:raw]
    // CALL: Invoke vtable method at offset 0x1C on the camera object. [field:*(*(this+0xC)+0x0):0x0000001C, field:*(this+0xC):0x00000000]
    // CALL: Run SteeringInterpolationCameraFollow(0) as final camera follow setup. [callee:0x00434D60]
    // RETURN: Return 0 on the success path. [source:raw]

    // Conservative worker pseudocode:
    //   int CameraObjectInit(this) {
    //     if (this->camera != NULL) VtableMethodShutdown();
    //     void* obj = OperatorNewNhMallocWrapper(208);
    //     this->camera = obj ? F_3DTransformObjectInit_83b0(obj) : 0;
    //     if (!this->camera || TrackSplineExtrapolation(this)) return 1;
    //     StringCopyWithBufferRealloc(&aGridwalkCam);
    //     this->camera->f38 = this->f10;
    //     this->camera->f3C = 62.5f;
    //     GuardedFunctionWithFlagSet(0.0);
    //     this->camera->fA8 = this->f30;
    //     this->camera->fA4 = 2.0f;
    //     this->camera->f48 = 1.25f;
    //     memset(&local, 0, sizeof(local)); StructFieldCopy(&local);
    //     this->camera->vtbl[7](this->camera);
    //     SteeringInterpolationCameraFollow(0);
    //     return 0;
    //   }
    // UNRESOLVED: Exact semantic meaning of camera+0x38/+0x3C/+0x48/+0xA4/+0xA8 float fields (FOV, scale, near/far) not established from this function alone.
}
