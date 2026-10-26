// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585BF0
// Canonical corpus name: IterateTriggersViaVtableCallHandlersPerTick
// Owner: TriggerDispatcher [DERIVED]
// Raw source: functions/IterateTriggersViaVtableCallHandlersPerTick_00585bf0.c

void TriggerDispatcher::DispatchTriggerHandlersPerTick()
{
    // Per-tick trigger dispatch: iterates a trigger collection through vtable methods on the object (this+0x0), filters items through a predicate, and invokes a handler at vtable slot 52 of a handler table obtained from FieldGetter_5cc0 with arguments from DualQueryIntoTwoOutputParams, sub_587220 and ReadFieldAtOffset0x14. Releases the current item and ends iteration, then returns 1.
    // CALL: Begin trigger iteration via vtable slot 200 (obj+0xC8). [field:this:0x00000000, field:obj:0x000000C8, source:raw]
    // ASSIGNMENT: Fetch the current item via vtable slot 28 (obj+0x1C) and the total item count via vtable slot 164 (obj+0xA4). [field:obj:0x0000001C, field:obj:0x000000A4, source:raw]
    // LOOP: Iterate triggers by index; the predicate at vtable slot 172 (obj+0xAC) filters each (index, item) pair. [field:obj:0x000000AC, source:raw]
    // CALL: DualQueryIntoTwoOutputParams fills two output parameters used in the dispatch. [callee:0x005871C0, source:raw]
    // CALL: FieldGetter_5cc0 returns the handler table; sub_587220 and ReadFieldAtOffset0x14 compute the remaining handler arguments from the current item. [callee:0x00585CC0, callee:0x00587220, callee:0x005871F0, source:raw]
    // CALL: Invoke the per-item handler at vtable slot 52 of the handler table with the query, field and loop-index arguments. [function:0x00585BF0, source:raw]
    // CALL: EmptyStub_0170 no-op runs after each successful dispatch. [callee:0x004B0170, source:raw]
    // CALL: After the loop, release the current item via vtable slot 32 (obj+0x20) and end iteration via vtable slot 204 (obj+0xCC). [field:obj:0x00000020, field:obj:0x000000CC, source:raw]
    // RETURN: Return 1 at the end of the tick. [function:0x00585BF0, source:raw]
    // CALL: Called by UtilityFunction_a800 (0x0057A800); the legacy ABI name is Iterate_Triggers_via_Vtable_Call_Handlers_per_Ti (abi:lead). [caller:0x0057A800, abi:lead]

    // Conservative worker pseudocode:
    //   char DispatchTriggerHandlersPerTick(void *this) {
    //     ((void (__thiscall *)(void *))(*(DWORD*)this + 200))(this);
    //     int item = ((int (__thiscall *)(void *))(*(DWORD*)this + 28))(this);
    //     int count = ((int (__thiscall *)(void *))(*(DWORD*)this + 164))(this);
    //     for (int i = 0; i < count; i++) {
    //       if (((BYTE (__thiscall *)(void *, int, int))(*(DWORD*)this + 172))(this, i, item)) {
    //         int out1 = 0, out2 = 0;
    //         DualQueryIntoTwoOutputParams(&out1, &out2);
    //         int *handlers = FieldGetter_5cc0(this);
    //         int extra = sub_587220(item);
    //         __int64 value = ReadFieldAtOffset0x14(item);
    //         ((void (__fastcall *)(int *, int, int, int, int, int, int))(*(DWORD*)handlers + 52))(
    //             handlers, (int)(value >> 32), i, (int)value, extra, out1, out2);
    //         EmptyStub_0170();
    //       }
    //     }
    //     ((void (__thiscall *)(void *, int))(*(DWORD*)this + 32))(this, item);
    //     ((void (__thiscall *)(void *))(*(DWORD*)this + 204))(this);
    //     return 1;
    //   }
    // UNRESOLVED: The handler at vtable slot 52 and its argument packing (out1/out2, extra, high/low halves of the 0x14-field read) are unverified.
    // UNRESOLVED: The mapping between obj fields and vtable slots is inferred from equal numeric offsets and is not runtime-confirmed.
}
