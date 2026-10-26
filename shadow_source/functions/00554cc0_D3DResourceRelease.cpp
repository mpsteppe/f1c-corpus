// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00554CC0
// Canonical corpus name: D3DResourceRelease
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/D3DResourceRelease_00554cc0.c

void UnknownObject::D3DResourceRelease()
{
    // Release walk over a resource list rooted at (a2+36): for each linked-list node (next at node offset 48), iterate its entries (count at node offset 41, per-entry stride 37 dwords, element data at node offset 42 + 140). Entries whose flag byte (& 2) is set and that hold a resource at entry+84/4 get released through sub_53F6E0, EmptyStub_7470 and FreeWrapper_7bcf, then are zeroed and passed to UICleanupIterator. Returns the last count value read. Called by RenderTargetCleanup (0053F270); prelabeled as a structural twin of sub_45B5C0.
    // ASSIGNMENT: Seed the walk: result = a2, v3 = *(a2 + 36) (resource list head from the second argument). [source:raw]
    // LOOP: Outer traversal over linked-list nodes following the next pointer at node offset 48, starting from this. [source:raw]
    // ASSIGNMENT: result = v3[42]; entry data base for the node; inner count candidate from v3[41]. [source:raw]
    // GUARD: Enter the inner loop only when (int)v3[41] > 0. [source:raw]
    // LOOP: Inner do-while over v3[41] entries, stepping the cursor by 37 dwords each iteration. [source:raw]
    // GUARD: Skip the entry when its flag byte at cursor offset -19 has bit 2 clear. [source:raw]
    // GUARD: Skip the release when the resource pointer at *(entry + 84) + 4 is null. [source:raw]
    // CALL: Call sub_53F6E0(this, released resource) to begin the release. [callee:0x0053F6E0, source:raw]
    // CALL: Call EmptyStub_7470 on the held resource handle. [callee:0x00557470, source:raw]
    // CALL: Call FreeWrapper_7bcf on the freed buffer. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: After the free, write 0 back into the resource slot at *(entry + 84) + 4. [source:raw]
    // CALL: Call UICleanupIterator on the entry object. [callee:0x00554D70, source:raw]
    // RETURN: Return result (the last v3[41] count value read). [source:raw]
    // CALL: Invoked by RenderTargetCleanup (0053F270) as part of its render-target teardown. [caller:0x0053F270, source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall sub_554CC0(int *this, int a2) {
    //     result = a2;
    //     v3 = *(int**)(a2 + 36);
    //     for (i = this; v3; v3 = (int*)v3[48]) {
    //       result = v3[42];
    //       v5 = 0;
    //       if ((int)v3[41] > 0) {
    //         v6 = (int*)(result + 140);
    //         do {
    //           if ((*(_BYTE*)(v6 - 19) & 2) != 0) {
    //             v7 = *(int*)(*v6 + 84);
    //             if (*(int*)(v7 + 4)) {
    //               sub_53F6E0(i, *(int*)(v7 + 4));
    //               v8 = *(int*)(*v6 + 84);
    //               v9 = *(void**)(v8 + 4);
    //               if (v9) { EmptyStub_7470(*(int*)(v8 + 4)); FreeWrapper_7bcf(v9); }
    //               i = this;
    //               *(int*)(*(int*)(*v6 + 84) + 4) = 0;
    //             }
    //             UICleanupIterator(*v6);
    //           }
    //           result = v3[41]; v6 += 37; ++v5;
    //         } while (v5 < result);
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Node and entry layouts (next at node offset 48, count at 41, data base at 42, flag at -19, resource slot at entry+84/4) are numeric offsets from the raw source with no named packet field entries.
    // UNRESOLVED: Division of labor between sub_53F6E0, EmptyStub_7470, FreeWrapper_7bcf and UICleanupIterator is inferred from context and not independently verified.
    // UNRESOLVED: The cluster-copy prelabel (structural twin of sub_45B5C0) is DERIVED and not confirmed.
}
