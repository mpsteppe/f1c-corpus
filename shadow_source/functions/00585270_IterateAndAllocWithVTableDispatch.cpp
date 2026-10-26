// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585270
// Canonical corpus name: sub_585270
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_585270_00585270.c

void UnknownObject::IterateAndAllocWithVTableDispatch()
{
    // Iterates items from a container object and routes each item through sub_584130, then performs a final vtable dispatch. Two iteration protocols are selected by a flag byte: the first enumerates via the a1 object's vtable slots at byte offsets 0xA4/0xA8 (count + item-by-index) and reads a field from each item via ReadFieldAtOffset0x14 before calling sub_584130; the second enumerates via the v5 object's vtable slots at byte offsets 0x14/0x18 and passes each item directly to sub_584130. When sub_586CA0(a3) is non-zero the whole body is skipped and VTableDispatchWithConditionalCall(a3) is returned instead. Always returns 1 on the normal path. Invoked by NetworkSendDispatch.
    // GUARD: Alternate-path check: when sub_586CA0(a3) returns non-zero, return early with VTableDispatchWithConditionalCall(a3) and skip both iteration loops [callee:0x00586CA0, source:raw]
    // CALL: Alternate path: return VTableDispatchWithConditionalCall(a3), a conditional list-append vtable dispatch used instead of the standard iteration [callee:0x00585380, source:raw]
    // ASSIGNMENT: Load v5 = *(a3 + 72) and read the iteration-mode flag byte v5[4] [source:raw]
    // GUARD: Branch on the flag byte v5[4]: non-zero selects the a1-vtable iteration path, zero selects the v5-vtable iteration path [field:this:0x00000000, source:raw]
    // CALL: On the a1 path: read the item count v6 via the thiscall vtable slot at *a1 + 164, invoked with (a1, a2) [field:this:0x00000000, field:obj:0x000000A4, source:raw]
    // LOOP: On the a1 path: for i in 0..v6, fetch each item via the vtable slot at *a1 + 168 with (a1, i); when the item is non-null, read the field at offset 0x14 from it via ReadFieldAtOffset0x14 and pass it to sub_584130(a1, a3, value) [field:this:0x00000000, field:obj:0x000000A8, callee:0x005871F0, callee:0x00584130, source:raw]
    // LOOP: On the v5 path: read the count v10 via the vtable slot at *v5 + 20 with (v5, a2), then for j in 0..v10 fetch each item via the vtable slot at *v5 + 24 with (v5, j) and pass it directly to sub_584130(a1, a3, item) [field:this:0x00000000, callee:0x00584130, source:raw]
    // CALL: After either iteration path, dispatch the final thiscall at *a1 + 92 with (a1, a3) [field:this:0x00000000, field:obj:0x0000005C, source:raw]
    // RETURN: Return 1 on the normal path [function:0x00585270, source:raw]
    // CALL: Invoked by NetworkSendDispatch (0057A6A0) as part of the network send dispatch system [caller:0x0057A6A0, source:raw]

    // Conservative worker pseudocode:
    //   if (sub_586CA0(a3)) return VTableDispatchWithConditionalCall(a3);
    //   v5 = *(BYTE**)(a3 + 72);
    //   if (v5[4]) {
    //     n = a1.vtable[164](a1, a2);
    //     for (i = 0; i < n; ++i) {
    //       item = a1.vtable[168](a1, i);
    //       if (item) sub_584130(a1, a3, ReadFieldAtOffset0x14(item));
    //     }
    //   } else {
    //     n = v5.vtable[20](v5, a2);
    //     for (j = 0; j < n; ++j) sub_584130(a1, a3, v5.vtable[24](v5, j));
    //   }
    //   a1.vtable[92](a1, a3);
    //   return 1;
    // UNRESOLVED: The structure owning v5 (object at a3+72) and the meaning of its flag byte v5[4] are undocumented; the two iteration protocols likely reflect two container representations but the identities are unknown
    // UNRESOLVED: The exact semantics of sub_584130 (described in the fill as allocate-node-or-search-existing) are not established by the packet evidence
    // UNRESOLVED: The packet declared_name is the literal 'if' (a prelabel artifact); it is ignored in favor of the fill's IterateAndAllocWithVTableDispatch proposal
    // UNRESOLVED: The meaning of the value read by ReadFieldAtOffset0x14 from each a1-path item is not established
}
