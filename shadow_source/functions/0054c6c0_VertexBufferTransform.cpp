// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054C6C0
// Canonical corpus name: VertexBufferTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VertexBufferTransform_0054c6c0.c

void UnknownObject::VertexBufferTransform()
{
    // Transforms vertex-buffer data through the D3D device using the object's stored position and Euler-angle inputs, then clears the transform inputs, recomputes the bounding box, and allocates a fresh 8-element structure. Runs once, guarded by the 0x4000000 done flag in the flags word at this+0x14. Per-vertex work iterates over the element count at this+0x118 with array base at this+0x11C, branching on flags bit 0x800000 (mask global unk_800000 at 0x00800000) between a 16-DWORD and a 12-DWORD vertex stride.
    // GUARD: Entry guard: when the done flag bit 0x4000000 is already set in the flags word at this+0x14, the transform was already applied and the function returns 0 [field:this:0x00000014, source:raw]
    // CALL: F_10FloatStructInitializer(v24) zero-initializes the local 10-element float struct used to build the rotation matrix [callee:0x0053B130, source:raw]
    // CALL: MultiFieldSetter(v24, this+0x100, this+0x104, this+0x108) loads the position/translation input triple into the struct [callee:0x0053B200, field:this:0x00000100, field:this:0x00000104, field:this:0x00000108, source:raw]
    // CALL: EulerAngleToRotationMatrix(v24, this+0x10C, this+0x110, this+0x114) converts the Euler-angle triple into the rotation matrix [callee:0x0053B240, field:this:0x0000010C, field:this:0x00000110, field:this:0x00000114, source:raw]
    // GUARD: Vertex element count at this+0x118 must be greater than 0 for the per-element transform loop to run [guard:0, field:this:0x00000118, source:raw]
    // LOOP: Iterate over the vertex elements described by the count at this+0x118 and the array base at this+0x11C with a 64-byte stride [field:this:0x00000118, field:this:0x0000011C, source:raw]
    // GUARD: Flags word bit 0x800000 (mask constant unk_800000 at 0x00800000) AND this+0x14 selects the 16-DWORD vertex stride path instead of the 12-DWORD path [field:this:0x00000014, global:0x00800000, source:raw]
    // CALL: Two indirect vtable dispatches on the D3D device object dword_8B8F24 transform the element's position (into v20/v22) and its normal/up vector (into v21/v23), writing through a 64-byte scratch buffer [global:0x008B8F24, source:raw]
    // GUARD: Sub-object flag at *(this+0x138)+0x3C: when bit 0x10 is clear, the transformed position and normal are written back into the vertex element [field:*(this+0x138):0x0000003C, field:this:0x00000138, source:raw]
    // ASSIGNMENT: Write-back of the transformed position and normal into the element, followed by a tail component swap across the element's trailing fields (differing between the 16-DWORD and 12-DWORD strides) [source:raw]
    // CALL: sub_54B4D0 on the sub-object at this+0x138 with zeroed parameters resets per-instance render state on the 16-DWORD stride path [callee:0x0054B4D0, field:this:0x00000138, source:raw]
    // ASSIGNMENT: After each element, the element control entry is reset (element count to -1, scalar/accumulator fields to 0); when the a2 bit 0x4 flag is set, 0x8000 is ORed onto the element's referenced object [source:raw]
    // CALL: F_3DBoundingBoxExtentsComputation(1.0f) runs after all elements have been transformed [callee:0x0054D520, source:raw]
    // CALL: BoundingBoxComputationFromVertexData(this) recomputes the bounding box from the transformed vertex data [callee:0x0054E270, source:raw]
    // CALL: sub_54D080(0) is invoked as part of the post-transform pipeline [callee:0x0054D080, source:raw]
    // CALL: FlagSetLoop(this) re-sets the object's flags after the transform completes [callee:0x0054E080, source:raw]
    // ASSIGNMENT: All six transform inputs (position this+0x100..0x108 and Euler this+0x10C..0x114) are cleared back to 0 [field:this:0x00000100, field:this:0x00000104, field:this:0x00000108, field:this:0x0000010C, field:this:0x00000110, field:this:0x00000114, source:raw]
    // CALL: OperatorNewNhMallocWrapper(452) allocates a 452-byte block; the first dword is set to 8 and 8 sub-structs at a 14-DWORD stride are initialized via StructZeroInitWithBaseCall [callee:0x00587C03, callee:0x0055D200, source:raw]
    // ASSIGNMENT: The allocated block pointer is stored into this+0x110, reusing the Euler Y field as an output pointer slot [field:this:0x00000110, source:raw]
    // ASSIGNMENT: Done flag 0x4000000 is ORed into the flags word at this+0x14 so the transform does not re-run [field:this:0x00000014, source:raw]
    // CALL: EmptyStub_b160() is invoked at the end of the guarded transform block [callee:0x0053B160, source:raw]
    // RETURN: Return 0 (no error indicator) [source:raw]
    // CALL: Invoked by AudioNetworkTreeWalker (00544d30) and sub_557670 (00557670) [caller:0x00544D30, caller:0x00557670]

    // Conservative worker pseudocode:
    //   if ((flags & 0x4000000) != 0) return 0;
    //   F_10FloatStructInitializer(m);
    //   MultiFieldSetter(m, this[0x100/4], this[0x104/4], this[0x108/4]);
    //   EulerAngleToRotationMatrix(m, this[0x10C/4], this[0x110/4], this[0x114/4]);
    //   for (each of count(this+0x118) elements at this+0x11C) {
    //     if (flags & 0x800000) /* 16-DWORD stride * /
    //       transform via dword_8B8F24 vtable; write back when subflag 0x10 clear;
    //     else /* 12-DWORD stride * /
    //       transform via dword_8B8F24 vtable; write back when subflag 0x10 clear;
    //     reset element control entry (count=-1, scalars=0);
    //   }
    //   F_3DBoundingBoxExtentsComputation(1.0f);
    //   BoundingBoxComputationFromVertexData(this);
    //   sub_54D080(0); FlagSetLoop(this);
    //   clear this+0x100..0x114 to 0;
    //   block = OperatorNewNhMallocWrapper(452);
    //   block[0] = 8; for (8 structs) StructZeroInitWithBaseCall(block + i*14);
    //   this+0x110 = block;
    //   flags |= 0x4000000;
    //   EmptyStub_b160();
    //   return 0;
    // UNRESOLVED: The semantics of the post-write-back component swap (element tail fields exchanging values) are preserved verbatim but their geometric meaning is unknown
    // UNRESOLVED: The element control array (count and base read beyond the fields listed in the packet) is described only through the listed this+0x118/0x11C fields; the per-entry control offsets are not packet evidence
    // UNRESOLVED: The role of the 8-element structure allocated at the end (stored into this+0x110) is unknown
}
