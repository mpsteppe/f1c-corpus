// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00560C10
// Canonical corpus name: sub_560C10
// Owner: ShadowCascadeViewInitializer [DERIVED]
// Raw source: functions/sub_560C10_00560c10.c

void ShadowCascadeViewInitializer::InitializeShadowCascadeView()
{
    // Initializes one shadow-map cascade view for directional-light rendering: detects whether the cascade already exists via a shadow-config pointer chain, allocates and constructs a 444-byte shadow view object, names it 'SHADOWVIEW%03d', sets projection near/far from the light near plane, clears its color, derives rotation from the light direction, allocates a 76-byte secondary object and a 1024-int array, marks itself initialized, then recursively initializes sibling and child cascade views. Returns 0.
    // GUARD: Resolve the shadow-config pointer chain (this+0x18 -> +0x138 -> +0x40); the cascade view is considered absent when the resolved pointer is null or its +0x230 validity flag is zero. [field:*(this+0x18):0x00000138, field:*(*(this+0x18)+0x138):0x00000040, field:*(*(*(this+0x18)+0x138)+0x40):0x00000230]
    // CALL: When the cascade already exists (resolved pointer valid), set bit 2 of this+0x24 before continuing. [field:this:0x00000024, source:raw]
    // GUARD: Skip all recreation when bit 0 of this+0x24 is already set (both the fresh and existing-cascade paths jump to the shared tail). [field:this:0x00000024, source:raw]
    // CALL: Format the shadow view name into a 256-byte buffer using the 'SHADOWVIEW%.3d' format string and the view index at this+0x28. [callee:0x0058815F, global:0x005DD84C, field:this:0x00000028]
    // CALL: Allocate the 444-byte shadow view object via OperatorNewNhMallocWrapper; when allocation fails the stored pointer stays null. [callee:0x00587C03, source:raw]
    // CALL: Construct the allocated object via ConstructorInit. [callee:0x005418B0, source:raw]
    // ASSIGNMENT: Store the constructed view pointer at this+0x0C and write a2 into its first word. [field:this:0x0000000C, source:raw]
    // CALL: Name the shadow view via SoundInstanceInit using the formatted name buffer. [callee:0x005418E0, source:raw]
    // CALCULATION: Read the light near-plane value at (this+0x18)->+0x18, double it, add and subtract flt_5DD848 to form a two-field pair, and set it on the shadow view via TwoFieldSetterCall. [field:this:0x00000018, field:*(this+0x18):0x00000018, global:0x005DD848, callee:0x005423C0]
    // CALL: Clear the shadow view color via ColorPack(0, 0, 0). [callee:0x005423E0]
    // CALL: Walk the a2 linked list via LinkedListTraversal and read a direction triple from the node via TripleFieldGetter_d590. [callee:0x005457C0, callee:0x0055D590]
    // CALCULATION: Derive a yaw angle from the direction triple with atan2 of two components, passing the value through FloatConvertWrapper. [callee:0x00588570, source:raw]
    // CALL: Set the shadow view rotation from the derived angles via RandomRotationMatrixFromEulerAngles. [callee:0x00541DB0, source:raw]
    // CALCULATION: Compute the vertical field-of-view from the light near-plane value and flt_5DD848 via atan2(fabs), doubled, and set the projection angle via sub_542050. [callee:0x00542050, global:0x005DD848, field:*(this+0x18):0x00000018]
    // CALCULATION: Set the projection extent from dword_8B8DF4 with a square aspect via sub_542200. [callee:0x00542200, global:0x008B8DF4]
    // CALL: Allocate the 76-byte secondary object via OperatorNewNhMallocWrapper and construct it via sub_556220; store the result at this+0x1C. [callee:0x00587C03, callee:0x00556220, field:this:0x0000001C]
    // CALL: Initialize the secondary object via sub_556260 with flag 1. [callee:0x00556260, source:raw]
    // CALL: Allocate the 8-byte array object via OperatorNewNhMallocWrapper and initialize it with 1024 ints via IntArrayAllocation; store the result at this+0x20. [callee:0x00587C03, callee:0x00560B60, field:this:0x00000020]
    // ASSIGNMENT: Mark the view fully initialized by setting bit 0 of this+0x24. [field:this:0x00000024, source:raw]
    // GUARD: When the sibling cascade view pointer at this+0x2C is non-null, recursively call sub_560C10(a2, 1) to initialize it. [field:this:0x0000002C, callee:0x00560C10]
    // GUARD: When the child cascade view pointer at this+0x34 is non-null and a3 is set, recursively call sub_560C10(a2, 1) to initialize it. [field:this:0x00000034, callee:0x00560C10]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   cascade = *(**(*(this+0x18)+0x138)+0x40);
    //   exists = cascade && *(cascade+0x230);
    //   if (exists) this->flags |= 4;
    //   if (this->flags & 1) goto tail;
    //   format(v28, "SHADOWVIEW%.3d", this->viewIndex);
    //   view = new(444);
    //   if (view) view = Construct(view);
    //   this->shadowView = view;
    //   view->first = a2;
    //   SoundInstanceInit(view, v28);
    //   TwoFieldSetterCall(view, near - spread, near + spread);
    //   ColorPack(view, 0, 0, 0);
    //   read direction triple from a2 list;
    //   yaw = FloatConvertWrapper(atan2(...));
    //   RandomRotationMatrixFromEulerAngles(view, pitch, yaw, 0.0);
    //   sub_542050(view, fov, fov, 1);
    //   sub_542200(view, 0.0, 0.0, dword_8B8DF4, dword_8B8DF4, 1);
    //   this->subObject = new(76) ? sub_556220(new) : 0;
    //   sub_556260(this->subObject, 1);
    //   this->intArray = new(8) ? IntArrayAllocation(new, 1024) : 0;
    //   this->flags |= 1;
    //   tail:
    //   if (this->sibling) sub_560C10(a2, 1);
    //   if (this->child && a3) sub_560C10(a2, 1);
    //   return 0;
    // UNRESOLVED: Packet global dbl_5B8998 is not referenced by the raw body; the source references flt_5DD848, aShadowview3d and dword_8B8DF4 only.
}
