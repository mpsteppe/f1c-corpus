// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00494690
// Canonical corpus name: sub_494690
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_494690_00494690.c

void UnknownObject::InitializeRenderSurfaces()
{
    // Video-manager initialization that builds three rendering surfaces. For each of S-buffer (256x256), B-buffer (1024x1024) and A-buffer (512x512) it allocates a 96-byte object (OperatorNewNhMallocWrapper + StructInitWithZeroFill), stores it in a dword_7CDE0x global, calls sub_54FEC0 with the buffer's name token and dimensions to configure it, caches a sub-object pointer from object+84 into the companion global, then constructs a texture/object handle via ObjectConstructorWithAllocationAndSubInit. When a construction returns 0, it installs four UV-corner entries via sub_553650 using the screen dimensions from dword_5D6D60/dword_5D6D64. Returns the last constructor result (0 on the A-buffer success path, otherwise the B-buffer constructor result).
    // CALL: Allocate a 96-byte surface-descriptor object: v0 = OperatorNewNhMallocWrapper(96); v1 = v0 ? StructInitWithZeroFill(v0) : 0; store v1 into dword_7CDE04. [callee:0x00587C03, callee:0x0054FE10, global:0x007CDE04, source:raw]
    // CALL: Configure the S-buffer: sub_54FEC0(aSbuf, 256, 256, 0, 4) using the aSbuf name token and 256x256 dimensions. [callee:0x0054FEC0, global:0x005CC9D8, source:raw]
    // ASSIGNMENT: Cache a sub-object pointer: dword_7CDE08 = *(dword_7CDE04 + 84). [global:0x007CDE08, global:0x007CDE04, source:raw]
    // CALL: Construct the S-buffer texture handle: ObjectConstructorWithAllocationAndSubInit(&dword_7CDE0C, 2, dword_7CDE04, 48, 64). [callee:0x00553980, global:0x007CDE0C, source:raw]
    // CALL: Allocate the second 96-byte descriptor: v2 = OperatorNewNhMallocWrapper(96); v3 = v2 ? StructInitWithZeroFill(v2) : 0; store v3 into dword_7CDE10. [callee:0x00587C03, callee:0x0054FE10, global:0x007CDE10, source:raw]
    // CALL: Configure the B-buffer: sub_54FEC0(aBbuf, 1024, 1024, 0, 4) using the aBbuf name token and 1024x1024 dimensions. [callee:0x0054FEC0, global:0x005CC9D0, source:raw]
    // ASSIGNMENT: Cache a sub-object pointer: dword_7CDE14 = *(dword_7CDE10 + 84). [global:0x007CDE14, global:0x007CDE10, source:raw]
    // CALL: Construct the B-buffer texture handle: ObjectConstructorWithAllocationAndSubInit(&dword_7CDE18, 2, dword_7CDE10, 16, 64). [callee:0x00553980, global:0x007CDE18, source:raw]
    // CALCULATION: When the B-buffer constructor returns 0, convert the screen dimensions: v9 = (float)dword_5D6D60, v7 = (float)dword_5D6D64. [global:0x005D6D60, global:0x005D6D64, source:raw]
    // CALL: Install four UV-corner entries for the B-buffer with sub_553650(index, x, y, 1.0, u, v, 0xFFFFFF) at corners (0,0), (0,height), (width,height), (width,0) using u in {0.0, 0.78125} and v in {0.0, 0.5859375}. [callee:0x00553650, source:raw]
    // CALL: Allocate the third 96-byte descriptor: v4 = OperatorNewNhMallocWrapper(96); v5 = v4 ? StructInitWithZeroFill(v4) : 0; store v5 into dword_7CDE1C. [callee:0x00587C03, callee:0x0054FE10, global:0x007CDE1C, source:raw]
    // CALL: Configure the A-buffer: sub_54FEC0(aAbuf, 512, 512, 0, 4) using the aAbuf name token and 512x512 dimensions. [callee:0x0054FEC0, global:0x005CC9C8, source:raw]
    // ASSIGNMENT: Cache a sub-object pointer: dword_7CDE20 = *(dword_7CDE1C + 84). [global:0x007CDE20, global:0x007CDE1C, source:raw]
    // CALL: Construct the A-buffer texture handle: result = ObjectConstructorWithAllocationAndSubInit(&dword_7CDE24, 2, dword_7CDE1C, 16, 64). [callee:0x00553980, global:0x007CDE24, source:raw]
    // CALCULATION: When the A-buffer constructor returns 0, convert the screen dimensions: v8 = (float)dword_5D6D60, v10 = (float)dword_5D6D64. [global:0x005D6D60, global:0x005D6D64, source:raw]
    // CALL: Install four UV-corner entries for the A-buffer with sub_553650(index, x, y, 1.0, u, v, 0xFFFFFF) at corners (0,0), (0,height), (width,height), (width,0) using u in {0.0, 0.78125} and v in {0.0, 0.5859375}. [callee:0x00553650, source:raw]
    // RETURN: Return the last constructor result: on the A-buffer success path the final sub_553650(3, ...) result (nonzero), otherwise the B-buffer/A-buffer ObjectConstructorWithAllocationAndSubInit result. [function:0x00494690, source:raw]

    // Conservative worker pseudocode:
    //   int InitializeRenderSurfaces() {
    //     dword_7CDE04 = StructInitWithZeroFill(OperatorNewNhMallocWrapper(96));
    //     sub_54FEC0(aSbuf, 256, 256, 0, 4);
    //     dword_7CDE08 = *(int*)(dword_7CDE04 + 84);
    //     ObjectConstructorWithAllocationAndSubInit(&dword_7CDE0C, 2, dword_7CDE04, 48, 64);
    //     dword_7CDE10 = StructInitWithZeroFill(OperatorNewNhMallocWrapper(96));
    //     sub_54FEC0(aBbuf, 1024, 1024, 0, 4);
    //     dword_7CDE14 = *(int*)(dword_7CDE10 + 84);
    //     if (!ObjectConstructorWithAllocationAndSubInit(&dword_7CDE18, 2, dword_7CDE10, 16, 64)) {
    //       float w = (float)dword_5D6D60;
    //       float h = (float)dword_5D6D64;
    //       sub_553650(0, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0xFFFFFF);
    //       sub_553650(1, 0.0f, h, 1.0f, 0.0f, 0.5859375f, 0xFFFFFF);
    //       sub_553650(2, w, h, 1.0f, 0.78125f, 0.5859375f, 0xFFFFFF);
    //       sub_553650(3, w, 0.0f, 1.0f, 0.78125f, 0.0f, 0xFFFFFF);
    //     }
    //     dword_7CDE1C = StructInitWithZeroFill(OperatorNewNhMallocWrapper(96));
    //     sub_54FEC0(aAbuf, 512, 512, 0, 4);
    //     dword_7CDE20 = *(int*)(dword_7CDE1C + 84);
    //     int result = ObjectConstructorWithAllocationAndSubInit(&dword_7CDE24, 2, dword_7CDE1C, 16, 64);
    //     if (!result) {
    //       float w = (float)dword_5D6D60;
    //       float h = (float)dword_5D6D64;
    //       sub_553650(0, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0xFFFFFF);
    //       sub_553650(1, 0.0f, h, 1.0f, 0.0f, 0.5859375f, 0xFFFFFF);
    //       sub_553650(2, w, h, 1.0f, 0.78125f, 0.5859375f, 0xFFFFFF);
    //       return sub_553650(3, w, 0.0f, 1.0f, 0.78125f, 0.0f, 0xFFFFFF);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Which surfaces the aAbuf/aBbuf/aSbuf tokens name and the precise meaning of the ObjectConstructorWithAllocationAndSubInit parameters (2, 48/16, 64) are inferred, not confirmed.
    // UNRESOLVED: The meaning of the object+84 sub-pointer cached into dword_7CDE08/14/20 (likely a D3D surface) is unproven.
    // UNRESOLVED: dword_8AFE64 is listed in the packet's globals but never appears in the raw function text; its referenced role here is unknown.
    // UNRESOLVED: The LEGACY ABI lead name 'Render_Surface_Allocation_and_Text_Initializatio' is truncated and not used to name the owner.
    // UNRESOLVED: Whether sub_553650 writes texture-coordinate data into the surface descriptors or a shared UV table is not established.
}
