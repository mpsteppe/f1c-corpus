// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498FE0
// Canonical corpus name: GuardedDrawRenderDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GuardedDrawRenderDispatch_00498fe0.c

void UnknownObject::GuardedDrawRenderDispatch()
{
    // Guard-enabled render dispatcher. If an enable flag at this+0x60 is set, a vtable[0x28] virtual predicate decides whether to fill a rectangular region of a render surface obtained from Accessor(), then a secondary render list is dispatched via RenderDispatchWithIteration(this+0x50), a linked list rooted at this+0x4C is walked calling each node's vtable[0x44] draw virtual, and the vtable[0x2C] virtual is invoked as a finalize step. Always returns 0.
    // GUARD: Guard on the enable flag at this+0x60 (offset 0x60); the entire body runs only when it is non-zero. [field:this:0x00000060, source:raw]
    // CALL: Call the virtual predicate at vtable[0x28] (offset 0x28) as (this, a2); a non-zero result gates the rectangle fill. [field:obj:0x00000028, source:raw]
    // CALCULATION: Compute fill width as right minus left: *(this+0x8) - *(this+0x4). [field:this:0x00000008, field:this:0x00000004, source:raw]
    // CALCULATION: Compute fill height as bottom minus top: *(this+0x10) - *(this+0xC). [field:this:0x00000010, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Prepare the rectangle origin: left from this+0x4 and top from this+0xC. [field:this:0x00000004, field:this:0x0000000C, source:raw]
    // CALL: Obtain the render surface via Accessor(), then call RenderSurfaceFillCopy(surface, top, left, height, width). [callee:0x00490920, callee:0x004918D0, source:raw]
    // CALL: Dispatch the secondary render list by calling RenderDispatchWithIteration(*(this+0x50)). [field:this:0x00000050, callee:0x004993D0, source:raw]
    // LOOP: Walk the linked list rooted at this+0x4C (first node vtable at *(this+0x4C)); per node, dispatch the draw virtual at vtable[0x44] of the node, advancing with StructFieldAccessor(node) until null. [field:this:0x0000004C, field:*(this+0x4C):0x00000000, field:*(*(this+0x4C)+0x0):0x00000044, callee:0x00486320, source:raw]
    // CALL: Invoke the finalize virtual at vtable[0x2C] (offset 0x2C) with arguments (this, 0); this vtable pointer is read from this+0x0. [field:obj:0x0000002C, field:this:0x00000000, source:raw]
    // RETURN: Return 0 unconditionally. [source:raw]

    // Conservative worker pseudocode:
    //   int GuardedDrawRenderDispatch(int this, int a2) {
    //     if (*(int*)(this + 96)) {
    //       if ((*(int (**)(int, int))(*(int*)this + 40))(this, a2)) {
    //         int w = *(int*)(this + 8) - *(int*)(this + 4);
    //         int h = *(int*)(this + 16) - *(int*)(this + 12);
    //         int x = *(int*)(this + 4);
    //         int y = *(int*)(this + 12);
    //         RenderSurfaceFillCopy(Accessor(), y, x, h, w);
    //       }
    //       RenderDispatchWithIteration(*(int**)(this + 80));
    //       for (int* n = *(int**)(this + 76); n; n = StructFieldAccessor(n))
    //         (*(void (**)(int*))(*n + 68))(n);
    //       (*(void (**)(int, int))(*(int*)this + 44))(this, 0);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Identity and purpose of the vtable[0x28] guard predicate and the vtable[0x2C] finalize virtual are not resolvable from this function alone.
    // UNRESOLVED: Semantics of a2 (used only as the guard predicate argument) and of the render lists at this+0x4C and this+0x50 are caller/owner dependent.
    // UNRESOLVED: Owner class is unknown; the this pointer layout (rect fields at 0x4..0x10, list at 0x4C, dispatch pointer at 0x50, enable flag at 0x60) is only partially understood.
}
