// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056D930
// Canonical corpus name: VehiclePhysicsJointSystemLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehiclePhysicsJointSystemLoader_0056d930.c

void UnknownObject::VehiclePhysicsJointSystemLoader()
{
    // Two-pass parser and solver initializer for a vehicle physics joint-system configuration file. Pass one counts Body/Joint/Hinge/Bar keyword records so the per-entity arrays can be sized; pass two parses each record's name, mass, inertia, and transform groups and links joints/hinges/bars to their positive and negative bodies, validating names and emitting error strings to a buffer. After parsing it allocates the solver matrix (8*N*N) and row-pointer array, runs the init routine, negotiates with a solver instance (sub_579F89), and links every body entry to the solver buffers. Called by VehiclePhysicsBodyNameMapping (00438DA0).
    // ASSIGNMENT: Zero the 384-byte line/state block v111 and local counters v106/v108/v109/v110; set state flag v107 to 1 before parsing begins. [source:raw]
    // CALL: sub_56E970(this) prepares the joint-system container object before the file is parsed. [callee:0x0056E970, function:0x0056D930]
    // CALL: FileDeleteWithErrorHandling(aPmodelErrorTxt) removes the stale physics error-log file so a fresh parse starts clean. [callee:0x0058986E, global:0x005E5248]
    // CALL: sub_534B00() opens the joint-system configuration file; the handle is kept in v86/v4. When it returns NULL, StringFormatWithBufferOverflowCheck formats the aCouldNotOpenS_0 message into v112 and control jumps to the shared error cleanup at LABEL_139. [callee:0x00534B00, callee:0x0058815F, global:0x005E5360, source:raw]
    // ASSIGNMENT: Zero the four record counters before pass one: *this=0, this[2]=0, this[4]=0, this[6]=0. [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018]
    // LOOP: Pass one count loop: read lines with LineInputReader(v3, v111, 384); sub_5651B0(v105) returns the token class so comment/token lines are skipped; sub_587C20 compares each line against the keyword strings aBody_1/aJoint/aHinge/aBar/aJointHinge and increments the matching count (aJointHinge bumps both joint this[2] and hinge this[4]). [callee:0x005351D0, callee:0x005651B0, callee:0x00587C20, global:0x005E5358, global:0x005E5350, global:0x005E5348, global:0x005E5340, global:0x005E5330, field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018]
    // CALCULATION: Allocate the body array: OperatorNewNhMallocWrapper(580*bodyCount+4), store the count at array[0], and initialise each 580-byte entry via ShortComputation_8e30 stepping 145 dwords; assign this[1] (NULL when allocation fails). [callee:0x00587C03, callee:0x00568E30, field:this:0x00000004]
    // CALCULATION: Allocate the joint array: OperatorNewNhMallocWrapper(48*jointCount+4), store the count, zero the 12 dwords of every entry; assign this[3]. [callee:0x00587C03, field:this:0x0000000C]
    // CALCULATION: Allocate the hinge array: 48*hingeCount+4 bytes, count stored at entry 0, 12 dwords zeroed per entry; assign this[5]. [callee:0x00587C03, field:this:0x00000014]
    // CALCULATION: Allocate the bar array: 72*barCount+4 bytes, count stored at entry 0, 18 dwords zeroed per entry; assign this[7]. [callee:0x00587C03, field:this:0x0000001C]
    // CALL: AudioStreamBufferRead(v4, 0, 0) rewinds the stream so pass two can re-read every record. [callee:0x00535390]
    // LOOP: Body post-load pass guarded by *this > 0 (guard:0): TripleBufferAllocation runs over each this[1]+i*580 body entry. [callee:0x005697F0, guard:0, field:this:0x00000000, field:this:0x00000004]
    // CALL: this[8] = sub_56D430(this) computes the total entity/DOF count the solver matrices must be sized for. [callee:0x0056D430, field:this:0x00000020]
    // LOOP: Joint fix-up loop guarded by this[2] > 0 (guard:1): copy the 3-double group at entry+20 into v94, run F_3DPositionDeltaToBodyFrameVectorTransform for the +4 and +12 links, clear entry+44, then F_3x3MatrixVectorMultiply. [callee:0x00569860, callee:0x0056CF70, guard:1, field:this:0x00000008, field:this:0x0000000C]
    // LOOP: Hinge fix-up loop guarded by this[4] > 0 (guard:2): BufferEntryAppendWithMatrixInit for the +4 and +12 links, clear entry+44, then F_3x3MatrixInverseCoordinateTransform. [callee:0x005698E0, callee:0x0056D020, guard:2, field:this:0x00000010, field:this:0x00000014]
    // LOOP: Bar fix-up loop guarded by this[6] > 0 (guard:3): copy two 3-vector groups (entry+20, entry+44), compute the separation length with sqrt, run F_3DVectorTransformWithBufferWrite for the +4 and +12 links, clear entry+68, then sub_56D2D0. [callee:0x00569990, callee:0x0056D2D0, guard:3, field:this:0x00000018, field:this:0x0000001C]
    // CALCULATION: Solver buffer setup: this[10] = 4*this[8] (row-pointer array) and this[9] = 8*this[8]*this[8] (matrix buffer); fill the row pointers so row i addresses this[9] + 8*i*N. [callee:0x00587C03, field:this:0x00000028, field:this:0x00000024, field:this:0x00000020]
    // CALL: ZeroFillArraysAndCallInitRoutineRepeatedly(this, this[10], this[8]) zeroes the solver matrices and runs the default init routine. [callee:0x0056D880]
    // LOOP: Solver-instance negotiation: iterate sub_579F89(v60); when an instance whose vtable+16 handler accepts (this[10], this[8]), free the default buffers with FreeWrapper_7bcf, allocate instance-owned buffers through the vtable+8 and vtable+0 handlers, store this[12]=v61 and break. [callee:0x00579F89, callee:0x00587BCF, field:this:0x00000030, field:this:0x00000024, field:this:0x00000028]
    // GUARD: Fallback when no instance claimed the solver (this[12] == 0): re-zero the arrays, allocate this[11] = 8*this[8] as the solution vector, and run sub_56C830(this+13, ...) to initialise the default solver. [callee:0x0056D880, callee:0x00587C03, callee:0x0056C830, field:this:0x0000002C, field:this:0x00000030]
    // LOOP: Link every body entry to the solver: *(body+552) = this[10] (row-pointer array) and *(body+548) = this[11] (solution vector). [field:this:0x00000004, field:this:0x00000028, field:this:0x0000002C, source:raw]
    // CALL: StreamFileTypeCheckWithDispatch(v86) finalises the stream; the successful parse path returns 0. [callee:0x005355A0, caller:0x00438DA0, function:0x0056D930]
    // LOOP: Second-pass body parser: for each Body block, read lines via LineInputReader; sub_5651B0 token class 1 terminates the block; sub_565520 extracts the name (aName_0) into SrcStr and sub_589901 strips it; sub_565AA0 reads mass (aMass_0 into double v88), inertia (aInertia_0 into three groups), and the transform groups off_5E5314, off_5E5310, off_5E530C, off_5E5308. [callee:0x005351D0, callee:0x005651B0, callee:0x00565520, callee:0x00565AA0, callee:0x00589901, global:0x005E5328, global:0x005E5320, global:0x005E5318, global:0x005E5314, global:0x005E5310, global:0x005E530C, global:0x005E5308]
    // GUARD: When a Body block ends with an empty name (SrcStr[0]==0), format the aBodyDMustBeNam message into v112 and error out. [global:0x005E52D4, callee:0x0058815F]
    // GUARD: Duplicate-name scan via sub_588410 (reports whether names differ) over previously parsed bodies: when a prior body already equals SrcStr, format the aTwoBodiesNamed message and error; when all prior bodies differ the entry is accepted. [callee:0x00588410, global:0x005E52BC]
    // CALL: Store the parsed body: sub_568E70(body, SrcStr, v88, v89) sets name/mass/inertia; qmemcpy the 24-byte quaternion group, F_3x3RotationTensorMatrixTransform, qmemcpy the second 24-byte group, and Copy6DwordsToStructCall apply the remaining transform data. [callee:0x00568E70, callee:0x005691D0, callee:0x00569280, source:raw]
    // LOOP: Second-pass joint/hinge/bar parser: set flags v75/v76/v81 from aJoint/aHinge/aBar/aJointHinge via sub_587C20 (aJointHinge forces both v75 and v76); per block extract name (aName_0), aPosbody, aNegbody, axis (aAxis), and the off_5E52EC / off_5E5314 groups through sub_565520 / sub_565AA0. [callee:0x005351D0, callee:0x005651B0, callee:0x00565520, callee:0x00565AA0, callee:0x00587C20, global:0x005E5350, global:0x005E5348, global:0x005E5340, global:0x005E5330, global:0x005E5328, global:0x005E5300, global:0x005E52F8, global:0x005E52F0, global:0x005E52EC, global:0x005E5314]
    // GUARD: Copy-body resolution: when the copied-body name v102 was supplied but matches no parsed body, format the aInvalidCopyBod message, call sub_56D8F0 and return -1; when a match exists, copy that body's transform group into v92. [callee:0x00588410, callee:0x0058815F, callee:0x0056D8F0, global:0x005E528C, source:raw]
    // GUARD: Positive-body resolution: v103 must match one parsed body, otherwise format the aInvalidBodyNam message, call sub_56D8F0 and return -1. [callee:0x00588410, callee:0x0058815F, callee:0x0056D8F0, global:0x005E5260]
    // ASSIGNMENT: Link each joint/hinge/bar to its positive body: joint entry+4 = body (body+556 refcount++), hinge entry+4 = body (body+564++), bar entry+4 = body (body+572++). [field:this:0x0000000C, field:this:0x00000014, field:this:0x0000001C, source:raw]
    // GUARD: Negative-body resolution: when v104 matches no body, format the aInvalidBodyNam message and error; when a match exists each joint/hinge/bar entry stores its negative-body pointer at +12, increments the body refcount, allocates and strcpy's the name into +0 when present, copies the transform groups (bars copy both v92 and v100), stamps an id at +44 (bars at +68), and advances the per-array write offset. [callee:0x00588410, callee:0x00587C03, global:0x005E5260, source:raw]
    // RETURN: All error paths converge on LABEL_139, call sub_56D8F0 (shared error cleanup) and return -1; the fully parsed path returns 0. [callee:0x0056D8F0, function:0x0056D930]

    // Conservative worker pseudocode:
    //   int VehiclePhysicsJointSystemLoader(int* this, char* path) {
    //     // pass 1: count records
    //     FILE* f = sub_534B00(path); if (!f) return -1;
    //     this[0]=this[2]=this[4]=this[6]=0;
    //     while (LineInputReader(f, buf, 384)) {
    //       if (sub_587C20(buf, "Body")) this[0]++;
    //       if (sub_587C20(buf, "Joint")) this[2]++;
    //       if (sub_587C20(buf, "Hinge")) this[4]++;
    //       if (sub_587C20(buf, "Bar")) this[6]++;
    //       if (sub_587C20(buf, "JointHinge")) { this[2]++; this[4]++; }
    //     }
    //     // allocate body/joint/hinge/bar arrays (580/48/48/72-byte strides)
    //     // pass 2: parse records, link bodies, validate names
    //     // solver init: matrix 8*N*N, row ptrs, instance negotiation
    //     return 0;
    //   }
    // UNRESOLVED: sub_588410 polarity (nonzero when names differ) is inferred from the three name-resolution loops and is not provable from this packet alone.
    // UNRESOLVED: Body-entry offsets +548/+552/+556/+564/+572 are read from raw source but are not flagged as packet fields; their exact meanings are DERIVED from the existing analysis.
    // UNRESOLVED: The exact role of the single read global aR (0x005C36F0) inside this function is not visible in the raw body.
    // UNRESOLVED: sub_56D430's count is assumed to be the total entity/DOF count because it sizes every solver buffer; the function itself is not in this packet.
}
