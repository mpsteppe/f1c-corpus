// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050F86A
// Canonical corpus name: StateMachineDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateMachineDispatch_0050f86a.c

void UnknownObject::StateMachineDispatch()
{
    // Drives a state machine over the state variable at a1[4] (this+0x10). State 200 (init) invokes two function-pointer slots (this+0x190 and this+0x14+8) and advances to 201; state 201 is a no-op that falls through to the shared processing call at this+0x18C; state 202 is terminal and returns 1. States 203..208 and 210 route directly through the this+0x18C processing function. Any other state is dispatched through the target object's vtable: writes opcode 18 to obj+0x14, the current state to obj+0x18, calls obj vtable slot 0, and returns 0. On a successful processing call (result 1) it invokes sub_50F6F7(a1) and sets state 202.
    // CALCULATION: Read the current state v1 from a1[4] (this+0x10). [field:this:0x00000010, caller:0x0050F9AB, function:0x0050F86A, source:raw]
    // GUARD: Dispatch on the state value: case 200 init, case 201 process, case 202 done, default handles everything else. [field:this:0x00000010, source:raw]
    // CALL: State 200 (init): call the function pointer at this+0x190 (slot this+0x18C + 4) with a1. [field:this:0x00000190, field:this:0x0000018C, source:raw]
    // CALL: State 200 (init): call the function pointer at this+0x14 + 8 with a1. [field:this:0x00000014, source:raw]
    // STATE_TRANSITION: State 200 sets the state variable at this+0x10 to 201. [field:this:0x00000010, source:raw]
    // GUARD: State 201 falls through to the shared processing call; state 202 is terminal and returns 1 immediately. [field:this:0x00000010, source:raw]
    // RETURN: Return 1 for terminal state 202. [source:raw]
    // CALL: Default branch for states 203..208 and 210: call the processing function pointer at this+0x18C with a1 and return its result directly. [field:this:0x0000018C, field:this:0x00000010, source:raw]
    // GUARD: Default branch for any other state: route the call through the target object (obj = *a1, whose vtable is obj+0x0). [field:this:0x00000000, field:obj:0x00000000, source:raw]
    // ASSIGNMENT: Write the operation code 18 to obj+0x14 before the default dispatch. [field:obj:0x00000014, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write the current state value to obj+0x18 as the operation parameter before the default dispatch. [field:obj:0x00000018, field:this:0x00000010, field:this:0x00000000, source:raw]
    // CALL: Call the target object's vtable slot 0 (obj+0x0) with a1 for the default-case dispatch. [field:obj:0x00000000, source:raw]
    // RETURN: Return 0 after the default-case dispatch. [source:raw]
    // CALL: After the state 201 path, call the processing function pointer at this+0x18C with a1 and capture its result v2. [field:this:0x0000018C, source:raw]
    // GUARD: When the processing call returns 1, complete processing: call sub_50F6F7(a1) and advance the state to 202. [callee:0x0050F6F7, field:this:0x00000010, source:raw]
    // STATE_TRANSITION: Set the state variable at this+0x10 to 202 on successful processing. [field:this:0x00000010, source:raw]
    // RETURN: Return v2 (the processing result). [source:raw]

    // Conservative worker pseudocode:
    //   int StateMachineDispatch(DWORD* a1) {
    //       DWORD state = a1[4];
    //       switch (state) {
    //           case 200:
    //               ((void (__cdecl *)(DWORD*))(a1[99] + 4))(a1);
    //               ((void (__cdecl *)(DWORD*))(a1[5] + 8))(a1);
    //               a1[4] = 201;
    //               break;
    //           case 201:
    //               break;
    //           case 202:
    //               return 1;
    //           default:
    //               if (state > 202 && (state <= 208 || state == 210))
    //                   return ((int (__cdecl *)(DWORD*))a1[99])(a1);
    //               *((DWORD*)*a1 + 5) = 18;
    //               *((DWORD*)*a1 + 6) = state;
    //               ((void (__cdecl *)(DWORD*))*a1)(a1);
    //               return 0;
    //       }
    //       DWORD v2 = ((int (__cdecl *)(DWORD*))a1[99])(a1);
    //       if (v2 == 1) {
    //           sub_50F6F7((int)a1);
    //           a1[4] = 202;
    //       }
    //       return v2;
    //   }
    // UNRESOLVED: this+0x1C (a1[7]) is listed as a read field but is not referenced anywhere in the displayed body; it is likely accessed via an elided or indirect path.
    // UNRESOLVED: The target object layout (obj) and the semantics of its vtable slot 0 for the default branch are not grounded by the packet.
    // UNRESOLVED: The meaning of the operation code 18 and of the state values 200..202 / 203..208 / 210 is derived from control flow, not from any naming source.
    // UNRESOLVED: Whether state 201's no-op fallthrough and state 203..208 direct calls are the same processing function is inferred from the shared this+0x18C slot.
}
