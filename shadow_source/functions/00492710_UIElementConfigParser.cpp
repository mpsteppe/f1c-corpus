// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00492710
// Canonical corpus name: sub_492710
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_492710_00492710.c

void UnknownObject::UIElementConfigParser()
{
    // Parses a stream of UI element configuration tokens and builds them into a UI tree node. On entry it seeds a name buffer from global byte_5EA438, allocates a fresh tree node (OperatorNewNhMallocWrapper + FunctionCallWrapper_91e0), registers it via NodeInsertionIntoTree, stores it at this+428 (current node) and increments this+404 (tree node count). A loop consumes one token at a time via sub_491FB0; sub_587C20(&unk_7CDB70, asc_5CC4F4) aborts the loop on a termination token. Recognized tokens are dispatched with sub_5654A0/sub_565870: name (with optional ResourcePathBuilder when this+410 is set and this+412 < 4, then sub_49AD50), enter-target/escape-target (StringCopyWithBufferRealloc), location and posWH (float parse via CRTFtol then ShortComputation_a9c0), location2 (RectangleEdgeOffsetCalculator), surface (sub_497AD0/sub_497BA0/sub_4992E0), and gizmo (sub_492A40 then DualFieldSetterProcessCall with this+424 and this+428). On exit this+404 is decremented, this+428 cleared to 0, and 0 is returned.
    // ASSIGNMENT: Seed the name buffer: v29[0] = byte_5EA438[0], zero the remaining 0x7C bytes, then clear the trailing 16-bit and 8-bit fields, producing the base path string that the name token is resolved against. [global:0x005EA438, source:raw]
    // CALL: Allocate a 104-byte tree node with OperatorNewNhMallocWrapper(104); when the allocation succeeds it is constructed via FunctionCallWrapper_91e0(0), otherwise v3 is null. [callee:0x00587C03, callee:0x004991E0, source:raw]
    // CALL: Register the constructed node into the owning tree with NodeInsertionIntoTree(v3). [callee:0x00498E50, source:raw]
    // ASSIGNMENT: Record the node as the current tree node at this+428 and increment the tree node count at this+404. [field:this:0x000001AC, field:this:0x00000194, source:raw]
    // LOOP: Token loop: while sub_491FB0(this) returns a token, process it; if sub_587C20(&unk_7CDB70, asc_5CC4F4) reports a termination token the loop breaks. [callee:0x00491FB0, callee:0x00587C20, global:0x007CDB70, global:0x005CC4F4, source:raw]
    // GUARD: Name token (sub_5654A0(aName_2, v29)): when the flag byte at this+410 is set and the depth counter at this+412 is below 4, ResourcePathBuilder(v29) first builds the resource path; then sub_49AD50(v29) consumes the name value. [global:0x005CC650, field:this:0x0000019A, field:this:0x0000019C, guard:0, callee:0x00493E20, callee:0x0049AD50, source:raw]
    // CALL: Enter-target / escape-target token (sub_5654A0(aEntertarget, v28) or sub_5654A0(aEsctarget, v28)): capture the target string into v28 via StringCopyWithBufferRealloc(v28). [global:0x005CC6AC, global:0x005CC6A0, callee:0x005654A0, callee:0x00566650, source:raw]
    // CALL: Location token (sub_565870(aLocation, &v23, &v21, &v20, &v22, 0, 0, 0, 0)): convert the four parsed floats with CRTFtol and pass them to ShortComputation_a9c0. [global:0x005CC694, callee:0x00565870, callee:0x00587BDC, callee:0x0049A9C0, source:raw]
    // CALL: posWH token (sub_565870(aPosWH, &v25, &v24, &v27, &v26, 0, 0, 0, 0)): compute width = v25+v27 and height = v24+v26, convert all four via CRTFtol, and pass them to ShortComputation_a9c0. [global:0x005CC68C, callee:0x00565870, callee:0x00587BDC, callee:0x0049A9C0, source:raw]
    // CALL: location2 token (sub_565870(aLocation2, &v23, &v21, &v20, &v22, 0, 0, 0, 0)): convert the four parsed floats via CRTFtol and pass them to RectangleEdgeOffsetCalculator. [global:0x005CC680, callee:0x00565870, callee:0x00587BDC, callee:0x0049A9E0, source:raw]
    // CALL: Surface token (sub_5654A0(aSurface, v28)): sub_497AD0(v28, 1), then sub_497BA0(v28) and sub_4992E0(v8, 1) to attach the surface to the element. [global:0x005CC678, callee:0x00497AD0, callee:0x00497BA0, callee:0x004992E0, source:raw]
    // CALL: Gizmo token (sub_5654A0(aGizmo, v32)): resolve the gizmo via sub_492A40(v32); if non-null, DualFieldSetterProcessCall(v9, *(this+424), *(this+428)) binds it using the element field pointer at this+424 and the current node at this+428. [global:0x005CC5AC, callee:0x00492A40, callee:0x00497590, field:this:0x000001A8, field:this:0x000001AC, source:raw]
    // STATE_TRANSITION: Loop exit: decrement the tree node count at this+404 and clear the current node pointer at this+428 to 0, mirroring the push at entry. [field:this:0x00000194, field:this:0x000001AC, source:raw]
    // RETURN: Return 0 on every exit path of the parser. [source:raw]

    // Conservative worker pseudocode:
    //   v29[0] = byte_5EA438[0]; memset(&v29[1], 0, 0x7C); v30 = 0; v31 = 0;
    //   v3 = OperatorNewNhMallocWrapper(104) ? FunctionCallWrapper_91e0(0) : 0;
    //   NodeInsertionIntoTree(v3);
    //   *(this + 428) = v3;
    //   ++*(this + 404);
    //   while (sub_491FB0(this)) {
    //     if (sub_587C20(&unk_7CDB70, asc_5CC4F4)) break;
    //     if (sub_5654A0(aName_2, v29)) {
    //       if (*(BYTE*)(this + 410) && *(this + 412) < 4) ResourcePathBuilder(v29);
    //       sub_49AD50(v29);
    //     } else if (sub_5654A0(aEntertarget, v28) || sub_5654A0(aEsctarget, v28)) {
    //       StringCopyWithBufferRealloc(v28);
    //     } else if (sub_565870(aLocation, &v23, &v21, &v20, &v22, 0, 0, 0, 0)) {
    //       ShortComputation_a9c0(CRTFtol(v23), CRTFtol(v21), CRTFtol(v20), CRTFtol(v22));
    //     } else if (sub_565870(aPosWH, &v25, &v24, &v27, &v26, 0, 0, 0, 0)) {
    //       ShortComputation_a9c0(CRTFtol(v24), CRTFtol(v24 + v26), CRTFtol(v25), CRTFtol(v25 + v27));
    //     } else if (sub_565870(aLocation2, &v23, &v21, &v20, &v22, 0, 0, 0, 0)) {
    //       RectangleEdgeOffsetCalculator(CRTFtol(v23), CRTFtol(v21), CRTFtol(v20), CRTFtol(v22));
    //     } else if (sub_5654A0(aSurface, v28)) {
    //       sub_497AD0(v28, 1); sub_4992E0(sub_497BA0(v28), 1);
    //     } else if (sub_5654A0(aGizmo, v32)) {
    //       int g = sub_492A40(v32);
    //       if (g) DualFieldSetterProcessCall(g, *(this + 424), *(this + 428));
    //     }
    //   }
    //   --*(this + 404);
    //   *(this + 428) = 0;
    //   return 0;
    // UNRESOLVED: Global unk_7CD9D8 is listed in the packet global table but never referenced by the raw source text of this function.
    // UNRESOLVED: The exact stream/token protocol of sub_491FB0 (the per-iteration token reader) is not evidenced here, so the loop termination and token framing semantics are DERIVED.
    // UNRESOLVED: The meanings of ShortComputation_a9c0, RectangleEdgeOffsetCalculator, sub_49AD50, sub_497AD0, sub_497BA0, sub_4992E0 and sub_492A40 are only known by name from the skeleton and are not grounded in this packet's raw text.
    // UNRESOLVED: The second parameter a2 is declared but not used anywhere in the function body.
}
