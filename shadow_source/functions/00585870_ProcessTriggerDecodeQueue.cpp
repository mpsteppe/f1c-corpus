// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585870
// Canonical corpus name: sub_585870
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_585870_00585870.c

void UnknownObject::ProcessTriggerDecodeQueue()
{
    // Trigger/event queue processor. Guards an object with MutexProtectedPointerReadRelease and a WaitForSingleObject/ReleaseMutex pair on the mutex handle at this+0x640 (timeout this+0x644); ThreadSafeIntReadWithMutex returns the current object index v29. ObjectInitWithVTableSetup(-1, 255, 0) initializes scratch state and, when arg a3 or the byte flag at this+0x63D is set, CopyBufferHeaderFieldsCallInit(v9) runs. Iterates objects through vtable dispatch on the vtable at this+0 (entry +164 count, +28 next, +172 predicate, +32 release, +200 begin, +204 end, +88 decode target, +180 header fill): qualifying objects are collected into a 12-byte linked-list node chain (allocated via OperatorNewNhMallocWrapper(12), object at +0, next at +4, byte flag at +8) while non-qualifying objects are released. Then the chain is walked: AddConstantWrapper and DecompressionDecode feed a decode chain that calls sub_586800, a vtable call through *(v18+72), SingleFunctionCallWrapper_6a00 and VTableDispatchWithConditionalCall, with NodeDestructionWithVirtualCall and FreeWrapper_7bcf tearing down each processed node. If the header-copy path ran, CounterIncrementDecrementByFlag(0) and a second mutex release on *(v9+28) occur. Finally remaining nodes are freed and SetVtablePointerAndCallInit(v30) returns.
    // CALL: Setup: MutexProtectedPointerReadRelease(this) releases the guarded pointer; v29 = ThreadSafeIntReadWithMutex((int*)this) reads the current object index; ObjectInitWithVTableSetup(-1, 255, 0) initializes scratch [callee:0x00585D20, callee:0x00585770, callee:0x00587030, field:this:0x00000000, source:raw]
    // GUARD: Mutex acquire: v5 = *(this + 1600) is the mutex handle; when v5 is non-null and WaitForSingleObject(v5, *(this + 1604)) returns 0 or 128 the guarded object v9 = this + 1572, otherwise v9 = 0; if *(this + 1600) is set, ReleaseMutex releases it afterwards [global:0x0059E1A0, global:0x0059E1A4, field:this:0x00000640, field:this:0x00000644, source:raw]
    // GUARD: Header-copy path: when a3 or the byte at v9 + 25 (this + 0x63D) is set, CopyBufferHeaderFieldsCallInit(v9) runs and v7 = 1 [callee:0x00587370, field:this:0x0000063D, source:raw]
    // CALL: Iteration begins via vtable+200 on this; when v7 is set, v22 = vtable+180(this, v29, v30, 1) fills the 28-byte header buffer v30 [field:this:0x00000000, source:raw]
    // LOOP: Object iteration: v11 = vtable+164(this) is the object count; each pass v13 = vtable+28(this) fetches the next object, and vtable+172(this, index, v13) plus the conditions (a3 or byte at v13 + 25), a2 != v29 and v13 != 0 decide whether to collect the object or release it via vtable+32(this, v13) [field:this:0x00000000, source:raw]
    // ASSIGNMENT: List build: v14 = OperatorNewNhMallocWrapper(12) allocates a 12-byte node storing the object at +0, 0 at +4 and a byte flag at +8; nodes append to the chain headed by v24 with tail v25 and count v27, or start the chain when empty [callee:0x00587C03, source:raw]
    // CALL: Iteration ends via vtable+204 on this [field:this:0x00000000, source:raw]
    // LOOP: Decode chain: each node object v16 is stepped by v23 = AddConstantWrapper(v16); when (byte)DecompressionDecode(v31, &v23) succeeds, v18 = vtable+88(this), sub_586800(0, 8, 1, 2, -1) runs, a call is dispatched through *(*(v18 + 72) + 12), SingleFunctionCallWrapper_6a00(v31, v23) and VTableDispatchWithConditionalCall((_DWORD*)this, v18) process the decoded payload, then vtable+32(this, v16) releases the node object [callee:0x00587250, callee:0x00587260, callee:0x00586800, callee:0x00586A00, callee:0x00585380, field:this:0x00000000, source:raw]
    // CALL: Node teardown: NodeDestructionWithVirtualCall(v4) destroys the node object and FreeWrapper_7bcf(v4) frees the node itself [callee:0x00586620, callee:0x00587BCF, source:raw]
    // GUARD: Tail mutex release: when v22 (header-copy path) is set, *(v6 + 28) is waited on with *(v6 + 32) via WaitForSingleObject, CounterIncrementDecrementByFlag(0) runs, and ReleaseMutex releases *(v6 + 28) when it is set [callee:0x00587230, global:0x0059E1A0, global:0x0059E1A4, source:raw]
    // LOOP: Final cleanup: walks the remaining chain, invoking the object vtable entry at +0 with argument 1 when the byte flag at node +8 is set and the object pointer is non-null, then frees each node with FreeWrapper_7bcf [callee:0x00587BCF, source:raw]
    // RETURN: Returns SetVtablePointerAndCallInit(v30), re-establishing the vtable on the header buffer v30 [callee:0x005870D0, source:raw]
    // CALL: Reached from sub_57E280 (0057e280) and sub_584230 (00584230) [caller:0x0057E280, caller:0x00584230, source:raw]

    // Conservative worker pseudocode:
    //   MutexProtectedPointerReadRelease(this);
    //   v29 = ThreadSafeIntReadWithMutex((int*)this); ObjectInitWithVTableSetup(-1, 255, 0);
    //   v5 = *(void**)(this + 1600);
    //   if (v5 && WaitForSingleObject(v5, *(this + 1604)) in {0, 128}) v9 = this + 1572; else v9 = 0;
    //   if (a3 || *(_BYTE*)(v9 + 25)) { CopyBufferHeaderFieldsCallInit(v9); v7 = 1; }
    //   if (*(this + 1600)) ReleaseMutex(*(this + 1600));
    //   vtable+200(this);
    //   if (v7) v22 = vtable+180(this, v29, v30, 1);
    //   for (i = 0; i < vtable+164(this); ++i) {
    //     v13 = vtable+28(this);
    //     if (vtable+172(this, i, v13) && (a3 || *(_BYTE*)(v13 + 25)) && a2 != v29 && v13) collect_node(v13);
    //     else vtable+32(this, v13);
    //   }
    //   vtable+204(this);
    //   for each node in chain:
    //     v23 = AddConstantWrapper(node->object);
    //     if (DecompressionDecode(v31, &v23)) {
    //       v18 = vtable+88(this);
    //       sub_586800(0, 8, 1, 2, -1);
    //       (*(**(v18 + 72) + 12))(*(v18 + 72), a2);
    //       SingleFunctionCallWrapper_6a00(v31, v23);
    //       VTableDispatchWithConditionalCall(this, v18);
    //     }
    //     vtable+32(this, node->object);
    //     NodeDestructionWithVirtualCall(node); FreeWrapper_7bcf(node);
    //   if (v22) { wait mutex at *(v6+28); CounterIncrementDecrementByFlag(0); release mutex at *(v6+28); }
    //   free remaining nodes;
    //   return SetVtablePointerAndCallInit(v30);
    // UNRESOLVED: The obj offset fields (+0x1C/+0x20/+0x58/+0xA4/+0xAC/+0xB4/+0xC8/+0xCC) are carried in packet evidence from the called decode chain (VTableDispatchWithConditionalCall / DecompressionDecode / sub_586800) but do not appear as explicit operands in this function's raw text; their meanings are unresolved here.
    // UNRESOLVED: SEH_585870 (global 0x0059D101) is the registered SEH handler for this function; its unwind semantics are not reconstructed.
    // UNRESOLVED: The internal layout of the 768-byte decompression scratch buffer v31 is unknown.
    // UNRESOLVED: The distinction between v24 (head), v26 (aux cursor) and v25 (tail) in the collection chain is inferred from usage and not confirmed.
}
