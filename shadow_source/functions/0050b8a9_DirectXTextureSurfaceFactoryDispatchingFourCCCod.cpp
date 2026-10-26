// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050B8A9
// Canonical corpus name: DirectXTextureSurfaceFactoryDispatchingFourCCCod
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DirectXTextureSurfaceFactoryDispatchingFourCCCod_0050b8a9.c

void UnknownObject::DirectXTextureSurfaceFactoryDispatchingFourCCCod()
{
    // Format/object factory dispatcher: reads a DWORD format code from an input descriptor (`*(this+0x8)`, then `+0x4`), selects one of ~39 recognized codes (small integer codes 20-69 and large FourCC-like constants), allocates a format/object of a per-code size via operator new, stores the new pointer at `this+0x8`, writes a per-case tag into a frame slot `this-4`, and hands the object to a per-code constructor together with the input descriptor. Unrecognized codes return NULL. After construction the tag slot is reset to -1 and, if the constructed object is non-null and its dword at +0x10 is non-null, a virtual method through vtable slot 3 (+12) is invoked before returning the object. Called from D3DContextInit (005063a5); part of the Direct3D rendering pipeline initialization.
    // CALL: Set up structured exception handling scope via SEHHandlerInit. [callee:0x0058A5D8]
    // ASSIGNMENT: v1 = *(this + 8): load the input descriptor pointer that the format code is read from. [field:this:0x00000008]
    // CALCULATION: v2 = *(v1 + 4): read the DWORD format code used to select a constructor (field *(this+0x8)+0x4). [field:*(this+0x8):0x00000004]
    // ASSIGNMENT: v3 = 0: initialize the result pointer to NULL before the dispatch. [source:raw]
    // GUARD: Dispatch on the format code v2 through nested range comparisons and a switch (compiled from a jump table jpt_50B8EB); each recognized code routes to an allocation/construction branch. [field:*(this+0x8):0x00000004, global:0x0050BFC9]
    // RETURN: Unrecognized format code: return the default NULL result. [source:raw]
    // CALL: Format code 20: allocate 4204 bytes, store pointer at this+0x8, tag slot = 0, construct via ObjectConstructorWithSizeCountInit. [callee:0x00587C03, callee:0x0050A7C5, field:this:0x00000008]
    // CALL: Format code 21: allocate 4204 bytes, store pointer at this+0x8, tag slot = 1, construct via RenderFormatConstructor. [callee:0x00587C03, callee:0x0050A8D9, field:this:0x00000008]
    // CALL: Format code 22: allocate 4204 bytes, store pointer at this+0x8, tag slot = 2, construct via VTableSetterWithSubInit. [callee:0x00587C03, callee:0x0050A8F5, field:this:0x00000008]
    // CALL: Format code 23: allocate 4204 bytes, store pointer at this+0x8, tag slot = 3, construct via sub_50A911. [callee:0x00587C03, callee:0x0050A911, field:this:0x00000008]
    // CALL: Format code 24: allocate 4204 bytes, store pointer at this+0x8, tag slot = 4, construct via ShortComputation_ab19. [callee:0x00587C03, callee:0x0050AB19, field:this:0x00000008]
    // CALL: Format code 25: allocate 4204 bytes, store pointer at this+0x8, tag slot = 5, construct via sub_50AB35. [callee:0x00587C03, callee:0x0050AB35, field:this:0x00000008]
    // CALL: Format code 26: allocate 4204 bytes, store pointer at this+0x8, tag slot = 6, construct via ConstructorWithVTableSubInit. [callee:0x00587C03, callee:0x0050AE22, field:this:0x00000008]
    // CALL: Format code 27: allocate 4204 bytes, store pointer at this+0x8, tag slot = 7, construct via InitWithClass8. [callee:0x00587C03, callee:0x0050AE3E, field:this:0x00000008]
    // CALL: Format code 28: allocate 4204 bytes, store pointer at this+0x8, tag slot = 8, construct via Constructor_ae5a. [callee:0x00587C03, callee:0x0050AE5A, field:this:0x00000008]
    // CALL: Format code 29: allocate 4204 bytes, store pointer at this+0x8, tag slot = 9, construct via ConstructorSize0x10. [callee:0x00587C03, callee:0x0050AE76, field:this:0x00000008]
    // CALL: Format code 30: allocate 4204 bytes, store pointer at this+0x8, tag slot = 10, construct via RenderObjectConstructor. [callee:0x00587C03, callee:0x0050AE92, field:this:0x00000008]
    // CALL: Format code 31: allocate 4204 bytes, store pointer at this+0x8, tag slot = 11, construct via ObjectInitWithVTable_af3b. [callee:0x00587C03, callee:0x0050AF3B, field:this:0x00000008]
    // CALL: Format code 34: allocate 4204 bytes, store pointer at this+0x8, tag slot = 12, construct via sub_50AFC6. [callee:0x00587C03, callee:0x0050AFC6, field:this:0x00000008]
    // CALL: Format code 40: allocate 4204 bytes, store pointer at this+0x8, tag slot = 13, construct via InitVTableSet_b1d4. [callee:0x00587C03, callee:0x0050B1D4, field:this:0x00000008]
    // CALL: Format code 41: allocate 4204 bytes, store pointer at this+0x8, tag slot = 14, construct via ObjectInit_b1f0. [callee:0x00587C03, callee:0x0050B1F0, field:this:0x00000008]
    // CALL: Format code 50: allocate 4204 bytes, store pointer at this+0x8, tag slot = 15, construct via ConstructorWithInit. [callee:0x00587C03, callee:0x0050B20C, field:this:0x00000008]
    // CALL: Format code 51: allocate 4204 bytes, store pointer at this+0x8, tag slot = 16, construct via ShortComputation_b228. [callee:0x00587C03, callee:0x0050B228, field:this:0x00000008]
    // CALL: Format code 52: allocate 4204 bytes, store pointer at this+0x8, tag slot = 17, construct via sub_50B260. [callee:0x00587C03, callee:0x0050B260, field:this:0x00000008]
    // CALL: Format code 60: allocate 4204 bytes, store pointer at this+0x8, tag slot = 18, construct via ObjectConstructor_b37d. [callee:0x00587C03, callee:0x0050B37D, field:this:0x00000008]
    // CALL: Format code 61: allocate 4204 bytes, store pointer at this+0x8, tag slot = 19, construct via RenderObjectConstructor_b399. [callee:0x00587C03, callee:0x0050B399, field:this:0x00000008]
    // CALL: Format code 62: allocate 4204 bytes, store pointer at this+0x8, tag slot = 20, construct via RenderFormatConstructor2. [callee:0x00587C03, callee:0x0050B3B5, field:this:0x00000008]
    // CALL: Format code 63: allocate 4204 bytes, store pointer at this+0x8, tag slot = 21, construct via VTableSetterWithSubInit_b3d1. [callee:0x00587C03, callee:0x0050B3D1, field:this:0x00000008]
    // CALL: Format code 64: allocate 4204 bytes, store pointer at this+0x8, tag slot = 22, construct via sub_50B3ED. [callee:0x00587C03, callee:0x0050B3ED, field:this:0x00000008]
    // CALL: Format code 65: allocate 4204 bytes, store pointer at this+0x8, tag slot = 23, construct via ShortComputation_b409. [callee:0x00587C03, callee:0x0050B409, field:this:0x00000008]
    // CALL: Format code 67: allocate 4204 bytes, store pointer at this+0x8, tag slot = 24, construct via sub_50B42A. [callee:0x00587C03, callee:0x0050B42A, field:this:0x00000008]
    // CALL: Format code 69: allocate 4204 bytes, store pointer at this+0x8, tag slot = 25, construct via ConstructorWithVTableSubInit_b446. [callee:0x00587C03, callee:0x0050B446, field:this:0x00000008]
    // CALL: Format code 909200416: allocate 4204 bytes, store pointer at this+0x8, tag slot = 26, construct via InitWithClass0x10. [callee:0x00587C03, callee:0x0050B462, field:this:0x00000008]
    // CALL: Format code 909200449: allocate 4204 bytes, store pointer at this+0x8, tag slot = 27, construct via Constructor_b727. [callee:0x00587C03, callee:0x0050B727, field:this:0x00000008]
    // CALL: Format code 909201952: allocate 4204 bytes, store pointer at this+0x8, tag slot = 28, construct via ConstructorSize0x30. [callee:0x00587C03, callee:0x0050B743, field:this:0x00000008]
    // CALL: Format code 909201985: allocate 4204 bytes, store pointer at this+0x8, tag slot = 29, construct via ObjectInitWithVTable_b77b. [callee:0x00587C03, callee:0x0050B77B, field:this:0x00000008]
    // CALL: Format code 909202018: allocate 4252 bytes, store pointer at this+0x8, tag slot = 30, construct via ObjectConstructorWithSingleInit. [callee:0x00587C03, callee:0x0050B879, field:this:0x00000008]
    // CALL: Format code 844715353: allocate 4252 bytes, store pointer at this+0x8, tag slot = 31, construct via RenderObjectConstructor_b891. [callee:0x00587C03, callee:0x0050B891, field:this:0x00000008]
    // CALL: Format code 827611204: allocate 4292 bytes, store pointer at this+0x8, tag slot = 32, construct via sub_50B797. [callee:0x00587C03, callee:0x0050B797, field:this:0x00000008]
    // CALL: Format code 844388420: allocate 4292 bytes, store pointer at this+0x8, tag slot = 33, construct via ObjectInit_b7cb. [callee:0x00587C03, callee:0x0050B7CB, field:this:0x00000008]
    // CALL: Format code 861165636: allocate 4292 bytes, store pointer at this+0x8, tag slot = 34, construct via ConstructorWithInit_b7e3. [callee:0x00587C03, callee:0x0050B7E3, field:this:0x00000008]
    // CALL: Format code 877942852: allocate 4292 bytes, store pointer at this+0x8, tag slot = 35, construct via ShortComputation_b7fb. [callee:0x00587C03, callee:0x0050B7FB, field:this:0x00000008]
    // CALL: Format code 894720068: allocate 4292 bytes, store pointer at this+0x8, tag slot = 36, construct via ShortComputation_b813. [callee:0x00587C03, callee:0x0050B813, field:this:0x00000008]
    // STATE_TRANSITION: LABEL_104: allocation failed (or constructor branch skipped); result stays NULL, control falls through to the shared tail. [source:raw]
    // STATE_TRANSITION: LABEL_105 (shared tail): reset the tag slot this-4 to -1 and take the constructed object as the result. [source:raw]
    // CALL: Post-construction guard: if the constructed object is non-null and its dword at +0x10 is non-null, invoke the virtual method at vtable slot 3 (+12) on the object. [source:raw]
    // RETURN: Return the result object pointer, or NULL on failure/unrecognized format. [source:raw]

    // Conservative worker pseudocode:
    //   formatCode = *(*((DWORD*)this + 2) + 1);
    //   result = 0;
    //   switch (formatCode):
    //     case 20..34, 40..69 and large FourCC-like constants:
    //       obj = operator new(SIZE_per_code);  this[2] = obj;  frameTag = per_code_index;
    //       if (obj) result = Constructor_per_code(obj, inputDescriptor);
    //     default: return 0;
    //   frameTag = -1;
    //   if (result && result[4]) (*(result->vtbl[3]))(result);
    //   return result;
    // UNRESOLVED: The exact class types of the ~39 constructed objects are unknown; the callee names are semantic proposals only (UnknownObject owner).
    // UNRESOLVED: global loc_59C71A is referenced as read-only by this dispatch logic but its concrete role is not visible in the cleaned pseudocode.
    // UNRESOLVED: The __usercall ABI passes a1 via ebp and the prototype is not resolved; the 'this-4' tag slot is a local frame slot with unknown public meaning.
    // UNRESOLVED: Only the caller D3DContextInit is in the packet; the broader factory dispatch relationship to the Direct3D device/surface creation path is not confirmed.
}
