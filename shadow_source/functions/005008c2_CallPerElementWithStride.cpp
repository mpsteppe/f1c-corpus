// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005008C2
// Canonical corpus name: sub_5008C2
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5008C2_005008c2.c

void UnknownObject::CallPerElementWithStride()
{
    // Generic strided callback loop: calls the thiscall function pointer a4 once per element, a3 times, advancing the element pointer a1 by a2 bytes each iteration, and returns the result of the last call. When the count a3 is not positive the loop is skipped and the function returns a3 - 1 directly. It is invoked by a large group of allocation, texture, vertex-buffer and COM-vector helpers as a shared per-element apply helper.
    // GUARD: Count guard: seed the result as a3 - 1 and, if a3 - 1 is negative, skip the loop entirely and return a3 - 1 without invoking the callback. [source:raw, function:0x005008C2]
    // LOOP: Iterate a3 times: each pass calls a4(a1), stores the result, advances a1 by the stride a2, and decrements the counter v6 until it reaches zero. [source:raw]
    // RETURN: Return the result of the final a4(a1) call on the normal path, or the pre-computed a3 - 1 value when the count guard rejected the loop. [source:raw]
    // CALL: Used as a shared apply-over-range helper by allocation, texture and vertex processing paths, including MemoryAllocationWithVectorConstructor, Direct3DTextureResampling, COMInterfaceVectorProcessingMethod, MultiLevelBufferAllocationWithVectorOps, VertexBufferAllocationAndStageTransformation, DirectXTextureCreationWithMipmapChain, TextureCopyRealloc, RenderBufferVertexAllocator and DirectXTextureSurfaceBlitWithColorSpaceConversion, plus sub_502F31, sub_504731, sub_5054EC, sub_506003 and sub_507079. [caller:0x00504640, caller:0x00504933, caller:0x00504B37, caller:0x00504F5A, caller:0x005058D2, caller:0x00507496, caller:0x005076FE, caller:0x0050A7E1, caller:0x0050B47E, caller:0x00502F31, caller:0x00504731, caller:0x005054EC, caller:0x00506003, caller:0x00507079, source:raw]

    // Conservative worker pseudocode:
    //   int CallPerElementWithStride(int a1, int a2, int a3, int (__thiscall *a4)(int)) {
    //     int result = a3 - 1;
    //     if (a3 - 1 >= 0) {
    //       int v6 = a3;
    //       do { result = a4(a1); a1 += a2; --v6; } while (v6);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The callback a4 and the object layout behind the strided elements are caller-specific; neither is evidenced in this packet.
    // UNRESOLVED: The calling convention of a4 (thiscall) implies an implicit this in ecx supplied by the caller; the correspondence to the a1 pointer is not shown by this function alone.
    // UNRESOLVED: Caller names are prelabel labels; their semantics are not evidenced here.
}
