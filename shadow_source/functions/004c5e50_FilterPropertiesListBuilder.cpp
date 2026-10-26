// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C5E50
// Canonical corpus name: FilterPropertiesListBuilder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FilterPropertiesListBuilder_004c5e50.c

void UnknownObject::FilterPropertiesListBuilder()
{
    // Builds a linked list of filter-property entries for scene names that match all caller-supplied filter criteria. Iterates scene entries (count dword_8AC488, stride 396), skips indices present in the exclusion list via LinkedListKeySearch and null scene entries, builds a 256-byte "Filter Properties <scene>" name with StringCopyWithValidation, validates it against every criterion a2[i] via sub_566810, then allocates a 16-byte filter property via sub_4C5C80 and a 12-byte list node via OperatorNewNhMallocWrapper, linking it onto the result list stored in this+0x8/0xC/0x10 and bumping the count at this+0x14. Returns the number of matches. Called by SceneFileFilterBuilder.
    // ASSIGNMENT: Initialize counters: v4 = 0, v11 = 0, v12 = 0, and v13 = dword_8AC488 (scene count). [global:0x008AC488, function:0x004C5E50]
    // GUARD: Guard on *a2 non-zero, a3 > 0, and dword_8AC488 > 0; when any fails return the initial result 0. [global:0x008AC488]
    // LOOP: Outer do-while loop over scene index v4 while v4 < v13, advancing the scene pointer offset v12 by 396 (scene stride) each iteration. [global:0x008AC490]
    // CALL: LinkedListKeySearch(this, v4): check whether scene index v4 is already in the exclusion keyed list. [callee:0x004C4CB0]
    // GUARD: Skip this scene when it is in the exclusion list, and also skip when the scene entry pointer v12 + dword_8AC490 is null. [global:0x008AC490]
    // ASSIGNMENT: Seed the 256-byte name buffer v14 with byte_5EA438[0] and zero-fill the remaining 0xFC bytes plus the trailing word and byte. [global:0x005EA438]
    // CALL: StringCopyWithValidation(v14, 256, aFilterProperti, v12 + dword_8AC490 + 260): build the "Filter Properties <scene>" name; proceed only when it succeeds. [callee:0x004C58A0, global:0x005D31EC, global:0x008AC490]
    // LOOP: Inner for loop over i < a3 testing each filter criterion via sub_566810(v14, a2[i]); break early when a criterion fails. [callee:0x00566810]
    // GUARD: Only accept the scene when every criterion matched, i.e. the inner loop completed with i == a3. [source:raw]
    // CALL: v7 = OperatorNewNhMallocWrapper(16): allocate a 16-byte filter-property node. [callee:0x00587C03]
    // CALL: v8 = sub_4C5C80(v7, v4, v14): construct the filter property from the scene index v4 and the built name. [callee:0x004C5C80]
    // GUARD: Proceed only when the filter-property construction returned a valid pointer v8. [source:raw]
    // CALL: v9 = OperatorNewNhMallocWrapper(12): allocate a 12-byte list node and initialize it with node[0] = v8, node[1] = 0, node[2] = 1. [callee:0x00587C03]
    // STATE_TRANSITION: Append the node to the result list: when head this+0x8 is set, link this+0xC's next field to v9; otherwise set head this+0x8 and permanent-first this+0x10 to v9. Then update tail this+0xC to v9 and increment the count this+0x14. [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, abi:lead]
    // CALCULATION: Increment the local match counter v11. [source:raw]
    // RETURN: Return v11 (number of matching filter properties), or the initial 0 when any guard failed. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C5E50(FilterResultList* this, Criterion* criteria, int count) {
    //     int v4 = 0, v11 = 0;
    //     if (!*criteria || count <= 0) return 0;
    //     int sceneCount = dword_8AC488;
    //     if (sceneCount <= 0) return 0;
    //     int sceneOff = 0;
    //     do {
    //       if (!LinkedListKeySearch(this, v4) && sceneOff + dword_8AC490) {
    //         char name[256];
    //         name[0] = byte_5EA438[0];
    //         memset(&name[1], 0, 0xFC);
    //         if (!StringCopyWithValidation((int)name, 256, (int)aFilterProperti, sceneOff + dword_8AC490 + 260)) {
    //           int i = 0;
    //           for (; i < count; ++i) if (!sub_566810(name, criteria[i])) break;
    //           if (i == count) {
    //             FilterProp* fp = (FilterProp*)OperatorNewNhMallocWrapper(16);
    //             if (fp && sub_4C5C80(fp, v4, (int)name)) {
    //               ListNode* node = (ListNode*)OperatorNewNhMallocWrapper(12);
    //               if (node) { node[0] = fp; node[1] = 0; node[2] = 1; }
    //               else node = 0;
    //               if (this[2]) *(int*)(this[3] + 4) = node;
    //               else { this[2] = node; this[4] = node; }
    //               this[3] = node;
    //               this[5] = this[5] + 1;
    //               ++v11;
    //             }
    //           }
    //         }
    //       }
    //       ++v4;
    //       sceneOff += 396;
    //     } while (v4 < sceneCount);
    //     return v11;
    //   }
    // UNRESOLVED: global unk_8AC368 (0x8AC368) is marked read but not referenced directly in the raw source; likely consumed by a callee such as sub_4C5C80.
    // UNRESOLVED: Exact layout of the 16-byte filter property produced by sub_4C5C80 is not proven.
    // UNRESOLVED: The exclusion list representation (this+0x0/0x4) consulted by LinkedListKeySearch is not described by the field evidence.
}
