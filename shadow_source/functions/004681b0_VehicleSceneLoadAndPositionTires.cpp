// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004681B0
// Canonical corpus name: VehicleSceneLoadAndPositionTires
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleSceneLoadAndPositionTires_004681b0.c

void UnknownObject::VehicleSceneLoadAndPositionTires()
{
    // Vehicle visual-scene loader and tire repositioner. Guarded by this[74] >= 0. Builds a temporary scene filename (root dir + aTmpvehicleScn) and a view scene path (dirs + aVviewScn), writes the view scene via SceneFileTEAMDIRVEHDIRNOTSPINWriter, copies the temp file, then initializes state. When this[58] is set, assigns this[60] = LinkedListNodeFinder(0) and zero-initializes this[58]. If this[58], this[59] and this[60] are all set, evaluates cockpit/mirror node properties and toggles flags on match, then searches the four tire nodes (LF/RF/LR/RR, each with a Y offset literal), accumulating their positions; when more than one tire is found it computes the average and repositions every child node in the scene root's child chain via OffsetDispatch around the negative center offset. Finally deletes the temporary scene file.
    // GUARD: Guard this[74] >= 0; when negative the whole body is skipped and 0 is returned. [guard:0, field:this:0x00000128, source:raw]
    // CALL: Build the temporary scene filename: StringFormatWithBufferOverflowCheck(FileName, "%s%s", root, aTmpvehicleScn), where root defaults to byte_5EA438 when dword_5EC440 is null. [callee:0x0058815F, global:0x005EC440, global:0x005EA438, global:0x005C6798, source:raw]
    // CALL: Build the view scene path: StringFormatWithBufferOverflowCheck(v23, "%s%s%s", dir1, dir2, aVviewScn), with each directory defaulting to byte_5EA438 when its dword is null (dword_5EC3D8, dword_5EC428). [callee:0x0058815F, global:0x005EC3D8, global:0x005EC428, global:0x005EA438, global:0x005C678C, source:raw]
    // CALL: Write the view scene: SceneFileTEAMDIRVEHDIRNOTSPINWriter(0, v23). [callee:0x004DDF90, source:raw]
    // CALL: Copy the temporary scene into place: StringCopyWithBufferRealloc(FileName). [callee:0x00566650, source:raw]
    // CALL: Initialize object state: StateInitializerWithFlagCheck(this). [callee:0x00466300, source:raw]
    // ASSIGNMENT: When this[58] is non-null: this[60] = LinkedListNodeFinder(0) and ZeroInitWrapper(this[58]). [callee:0x00545340, callee:0x004DDF70, field:this:0x000000E8, field:this:0x000000F0, source:raw]
    // GUARD: Proceed to scene-node handling only when this[58], this[59] and this[60] are all non-null. [field:this:0x000000E8, field:this:0x000000EC, field:this:0x000000F0, source:raw]
    // CALL: When EvaluateSceneNodeProperty(aCockpit, this[60]) matches, manipulate a flag via FlagFieldBitManipulation(0, 0, 0, 0); the same is done for the aMirror node. [callee:0x005453A0, callee:0x0054C030, global:0x005C677C, global:0x005C6774, field:this:0x000000F0, source:raw]
    // LOOP: Loop over the four tire node names (i 0..3): aLftire with Y offset 0.037999999, aRftire with -0.037999999, aLrtire with 0.013, aRrtire with -0.013; each found tire calls sub_5506A0(0, 0, 0), sub_54B450(0.0, 0.0, v15), increments the found count v5 and accumulates the position triple from TripleFieldQuery(&v19, &v20, &v21). [global:0x005C6754, global:0x005C675C, global:0x005C6764, global:0x005C676C, callee:0x005506A0, callee:0x0054B450, callee:0x0054B420, field:this:0x000000F0, source:raw]
    // GUARD: When more than one tire node was found (v5 > 1), compute the average tire position: scale accumulated v16/v18 by 1.0 / v5 (v17 reset to 0.0). [source:raw]
    // CALL: Apply the computed center offset to the scene root: GlobalVectorOffsetUpdate(this[60], &v16). [callee:0x0040E1F0, field:this:0x000000F0, source:raw]
    // LOOP: Walk the scene-root child chain starting at *(this[60] + 68), following each node's next pointer at node + 76; for every child call OffsetDispatch(-v16, -v17, -v14) to reposition it relative to the center. [callee:0x0054B3F0, source:raw]
    // CALL: Cleanup: delete the temporary scene file via FileDeleteWithErrorHandling(FileName). [callee:0x0058986E, source:raw]
    // RETURN: Return 0 on all paths. [source:raw]

    // Conservative worker pseudocode:
    //   char VehicleSceneLoadAndPositionTires(this) {
    //     if (this[74] < 0) return 0;
    //     root = dword_5EC440 ? dword_5EC440 : byte_5EA438;
    //     StringFormatWithBufferOverflowCheck(FileName, "%s%s", root, aTmpvehicleScn);
    //     d1 = dword_5EC3D8 ? dword_5EC3D8 : byte_5EA438;
    //     d2 = dword_5EC428 ? dword_5EC428 : byte_5EA438;
    //     StringFormatWithBufferOverflowCheck(v23, "%s%s%s", d1, d2, aVviewScn);
    //     SceneFileTEAMDIRVEHDIRNOTSPINWriter(0, v23);
    //     StringCopyWithBufferRealloc(FileName);
    //     StateInitializerWithFlagCheck(this);
    //     if (this[58]) { this[60] = LinkedListNodeFinder(0); ZeroInitWrapper(this[58]); }
    //     if (this[58] && this[59] && this[60]) {
    //       if (EvaluateSceneNodeProperty(aCockpit, this[60])) FlagFieldBitManipulation(0,0,0,0);
    //       if (EvaluateSceneNodeProperty(aMirror, this[60])) FlagFieldBitManipulation(0,0,0,0);
    //       found = 0; acc = {0,0,0};
    //       tires = { {aLftire, 0.037999999}, {aRftire, -0.037999999}, {aLrtire, 0.013}, {aRrtire, -0.013} };
    //       for (i = 0; i < 4; ++i) {
    //         if (EvaluateSceneNodeProperty(tires[i].name, this[60])) {
    //           sub_5506A0(0,0,0); sub_54B450(0.0, 0.0, tires[i].y); ++found;
    //           TripleFieldQuery(&v19, &v20, &v21); acc += {v19, v20, v21};
    //         }
    //       }
    //       if (found > 1) {
    //         acc.x *= 1.0/found; acc.y = 0.0; acc.z *= 1.0/found;
    //         GlobalVectorOffsetUpdate(this[60], &acc);
    //         for (child = *(this[60]+68); child; child = *(child+76))
    //           OffsetDispatch(-acc.x, -acc.y, -acc.z);
    //       }
    //     }
    //     FileDeleteWithErrorHandling(FileName);
    //     return 0;
    //   }
    // UNRESOLVED: Packet fields this+0x134 and *(this+0x134)+0x4C come from IDB struct annotation, not the decompiled body; the raw source walks the child chain from *(this[60]+68) via node+76 instead, so the 0x134/0x4C chain's role is unverified.
    // UNRESOLVED: Globals flt_59E43C, aSS, aSSS_0 and dword_7CFE0C appear in the packet global list but are not named references in the decompiled body; flt_59E43C is labeled a physics constant in existing analysis.
    // UNRESOLVED: Semantics of the Y offsets (0.037999999 / 0.013 / -0.013) applied per tire and of sub_5506A0 / sub_54B450 / TripleFieldQuery are not established beyond positioning.
}
