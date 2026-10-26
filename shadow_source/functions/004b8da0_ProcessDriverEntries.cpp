// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B8DA0
// Canonical corpus name: ProcessDriverEntries
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ProcessDriverEntries_004b8da0.c

void UnknownObject::ProcessDriverEntries()
{
    // Driver/vehicle entry loader. Iterates the vehicle entry array starting at unk_5EC6D8 with stride 4656 (0x1230), bounded by the byte_7C54D8 end pointer. For each entry it walks a per-entry linked list (head this+0x40, cursor this+0x48) matching a float key this+0xF38, copies up to three name/path strings from the matched node, resolves the entry's path/filename, and when the path is new it loads the vehicle-generation scene, transitions session state and adjusts the vehicle count dword_5C329C; empty entries that were previously active are deactivated. Finally it updates the driver name via SetDriverName when the stored name differs. Returns the one-past-end entry pointer.
    // LOOP: Iterate the vehicle entry array from base unk_5EC6D8 with stride 4656, stopping once the entry pointer reaches the end sentinel byte_7C54D8. [global:0x005EC6D8, global:0x007C54D8, source:raw]
    // ASSIGNMENT: Per entry, rebuild three name/path buffers (29, 29 and 61 bytes) each seeded with the first byte of byte_5EA438. [global:0x005EA438, source:raw]
    // ASSIGNMENT: Read the linked-list head pointer at this+0x40 and mirror it into the traversal cursor at this+0x48. [field:this:0x00000040, field:this:0x00000048, source:raw]
    // GUARD: If the list head at this+0x40 is null, skip the name-extraction inner block for this entry. [field:this:0x00000040, guard:0, source:raw]
    // LOOP: Walk the linked list via the this+0x48 cursor while UtilityFunction_50c0(first-node key, float key this+0xF38) is false; the node key comes from the first node's data at *(this+0x40)+0. [callee:0x004B50C0, field:*(this+0x40):0x00000000, field:this:0x00000F38, field:this:0x00000048, source:raw]
    // ASSIGNMENT: Copy three string fields from the matched node (at node+65, node+97 and node+1) into the per-entry path buffers using byte-wise copy loops. [source:raw]
    // CALL: Extract the path/filename of the current entry via PathFilenameExtractor. [callee:0x004C69E0, source:raw]
    // GUARD: Proceed with the load/update path when the extracted path already exists (sub_588410) or the entry was not previously active (entry flag v17 == 0). [callee:0x00588410, source:raw]
    // CALL: Delegation and name copy: TwoCallDelegation(v27), StringCopyWithBufferRealloc(v30) and a second PathFilenameExtractor pass on the same entry. [callee:0x004C7B20, callee:0x00566650, callee:0x004C69E0, source:raw]
    // CALL: Only when the re-checked path is not already loaded: if the entry was previously active run sub_4C6E80, then SessionStateTransition(0, 0), increment vehicle count dword_5C329C, BuildActiveVehiclePointerArray, VehgenScnFileLoader(1), SceneRenderUpdate(1) and SessionStateTransition(3, 0). [callee:0x004C6E80, callee:0x004EF5A0, callee:0x0042BC80, callee:0x004C6C40, callee:0x004C6D90, global:0x005C329C, source:raw]
    // STATE_TRANSITION: When the name buffer is empty but the entry was previously active: deactivate it (sub_4C6E80), SessionStateTransition(-1, 0), decrement vehicle count dword_5C329C and rebuild the active-vehicle array. [callee:0x004C6E80, callee:0x004EF5A0, callee:0x0042BC80, global:0x005C329C, source:raw]
    // CALL: When the driver-name buffer v33 differs from the stored name at entry +17940, update it via SetDriverName(v33). [callee:0x004C6980, source:raw]
    // RETURN: Advance to the next entry (base pointer += 4656) and return the one-past-end entry pointer when the array end byte_7C54D8 is reached. [global:0x005EC6D8, global:0x007C54D8, source:raw]

    // Conservative worker pseudocode:
    //   char *ProcessDriverEntries(float ***this) {
    //     char *entry = (char *)&unk_5EC6D8;
    //     float ***i = this + 16;
    //     for (;;) {
    //       char nameA[32] = { byte_5EA438[0], 0 };
    //       char nameB[32] = { byte_5EA438[0], 0 };
    //       char path[64] = { byte_5EA438[0], 0 };
    //       float **list = (float **)i[0];
    //       i[2] = (float **)list;
    //       if (list) {
    //         float *node = list[0];
    //         if (node) {
    //           while (!UtilityFunction_50c0(node, ((float *)this)[974])) {
    //             if (i[2]) i[2] = (float **)i[2][1];
    //             if (!i[2]) goto done_entry;
    //             node = i[2][0];
    //             if (!node) goto done_entry;
    //           }
    //           strcpy(nameA, (char *)node + 65);
    //           strcpy(nameB, (char *)node + 97);
    //           strcpy(path, (char *)node + 1);
    //         }
    //       }
    //   done_entry:
    //       if (strlen(nameA)) {
    //         int active = ((int *)entry)[445];
    //         int a = PathFilenameExtractor(entry);
    //         if (sub_588410(a, nameA) || !active) {
    //           TwoCallDelegation(nameA); StringCopyWithBufferRealloc(nameB);
    //           if (!sub_588410(PathFilenameExtractor(entry), nameA)) {
    //             if (active) sub_4C6E80(entry);
    //             SessionStateTransition(0, 0); ++dword_5C329C; BuildActiveVehiclePointerArray();
    //             VehgenScnFileLoader(1); SceneRenderUpdate(1); SessionStateTransition(3, 0);
    //           }
    //         }
    //       } else if (((int *)entry)[445]) {
    //         sub_4C6E80(entry); SessionStateTransition(-1, 0); --dword_5C329C; BuildActiveVehiclePointerArray();
    //       }
    //       if (strcmp((char *)entry + 17943, path)) SetDriverName(path);
    //       if ((int)(entry + 4656) >= (int)byte_7C54D8) return entry + 4656;
    //       i += 4; entry += 4656;
    //     }
    //   }
    // UNRESOLVED: Packet field this+0x4C does not appear in the recovered raw body and is unaccounted.
    // UNRESOLVED: Packet global unk_5EC6D0 does not appear in the recovered raw body and is unaccounted (only unk_5EC6D8 is used as the array base).
    // UNRESOLVED: ABI lead name 'ProcessDriverEntries' (LEGACY) is kept only as a lead; the owner object stays UNKNOWN.
    // UNRESOLVED: The caller ConditionalMultiPathDispatcher (004ba180) is external to this reconstruction.
}
