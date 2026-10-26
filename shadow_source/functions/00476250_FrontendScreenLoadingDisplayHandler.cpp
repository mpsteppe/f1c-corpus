// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00476250
// Canonical corpus name: FrontendScreenLoadingDisplayHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FrontendScreenLoadingDisplayHandler_00476250.c

void UnknownObject::FrontendScreenLoadingDisplayHandler()
{
    // Frontend loading display/audio handler. It obtains a scene list element via LinkedListIndexedAccessor_f590, retrieves a scene object from the container at this+0x40 through a vtable call (entry +28, id 1), copies the scene name string (defaulting to global byte_5EA438) into the object, builds an audio file path by combining the season directory global dword_5EC3D8 with the scene name using StringFormatProcessingWithNullTerm, loads and decodes the audio via AudioFileLoadDecode, and on success dispatches a game filter command through ConditionalDispatch_81f0/SingleFunctionDispatch_6f90 and triggers the +160 virtual play/show methods on the queried dispatch objects. Always returns 0.
    // CALL: Obtain a scene list element v2 via LinkedListIndexedAccessor_f590(); bail out (return 0) when it is null. [callee:0x0048F590, source:raw]
    // CALL: Virtual call on the container object at this+0x40 (vtable entry +28) with id 1 to retrieve object v3; bail out (return 0) when v3 is null. [field:*(this+0x40):0x0000001C, field:this:0x00000040, source:raw]
    // ASSIGNMENT: Resolve the scene name string: use the pointer stored at v2+60 if set, else the global byte_5EA438, then copy it via StringCopyWithBufferRealloc into the string region v3+228. [global:0x005EA438, callee:0x00566650, source:raw]
    // CALL: Virtual call on the global dispatch interface dword_7CD8C0 (vtable entry +28) with id 21 to retrieve object v6; bail out (return 0) when v6 is null. [global:0x007CD8C0, source:raw]
    // CALCULATION: Build the audio path: first part from the string at *v5 (or global byte_5EA438), second part from global dword_5EC3D8 (or byte_5EA438), combined with the "%s%s" format string (global aSS) via StringFormatProcessingWithNullTerm into stack buffer v13 with capacity 255. [global:0x005EA438, global:0x005EC3D8, global:0x005BE860, callee:0x0058969D, source:raw]
    // CALL: Zero-initialize the stack struct v12 via StructZeroInit_7a00, then load and decode the audio file v13 via AudioFileLoadDecode; proceed with dispatch only when it returns 1. [callee:0x00567A00, callee:0x00567F40, source:raw]
    // CALL: On audio load success, resolve a filter string via ConditionalDispatch_81f0(aGameFilter) and dispatch it with SingleFunctionDispatch_6f90, falling back to the global String1 when the filter result is null. [global:0x005C7130, global:0x007CD8BC, callee:0x005681F0, callee:0x00476F90, source:raw]
    // CALL: Invoke the virtual method at vtable offset +160 on object v6 (play/show action), then re-query the dispatch interface dword_7CD8C0 with id 17 and invoke the same +160 method on the returned object when non-null. [global:0x007CD8C0, source:raw]
    // CALL: Tear down the stack struct v12 via LinkedListDestructorWithInnerFree. [callee:0x00567A30, source:raw]
    // RETURN: Return 0 on every exit path. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_476250(_DWORD **this) {
    //     int elem = LinkedListIndexedAccessor_f590();
    //     if (!elem) return 0;
    //     _DWORD* obj = (*(int (__thiscall **)(_DWORD*, int))(this[0x40][0] + 28))(this[0x40], 1);
    //     if (!obj) return 0;
    //     const char* scene = *(char**)(elem + 60);
    //     if (!scene) scene = byte_5EA438;
    //     StringCopyWithBufferRealloc(scene);
    //     _DWORD* disp = (*(int (__thiscall **)(int, int))(*(_DWORD*)dword_7CD8C0 + 28))(dword_7CD8C0, 21);
    //     if (!disp) return 0;
    //     const char* first = *(const char**)(obj + 228);
    //     if (!first) first = byte_5EA438;
    //     const char* season = dword_5EC3D8;
    //     if (!season) season = byte_5EA438;
    //     if (StringFormatProcessingWithNullTerm(v13, 255, "%s%s", season, first) >= 0) {
    //       StructZeroInit_7a00(v12);
    //       if (AudioFileLoadDecode(v13, 0) == 1) {
    //         int f = ConditionalDispatch_81f0(aGameFilter);
    //         SingleFunctionDispatch_6f90(f ? f : String1);
    //         (*(void (__thiscall **)(int))(*(_DWORD*)disp + 160))(disp);
    //         int other = (*(int (__thiscall **)(int, int))(*(_DWORD*)dword_7CD8C0 + 28))(dword_7CD8C0, 17);
    //         if (other) (*(void (__thiscall **)(int))(*(_DWORD*)other + 160))(other);
    //       }
    //       LinkedListDestructorWithInnerFree(v12);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The identity of the scene list obtained from LinkedListIndexedAccessor_f590 and the meaning of the pointer at element +60 are unknown.
    // UNRESOLVED: The two virtual +160 method calls are interpreted as play/show actions (DERIVED) but their exact semantics are unproven.
    // UNRESOLVED: Whether global aSS (the "%s%s" format string) is the only path separator or part of a longer pattern is unresolved.
}
