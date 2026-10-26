// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B7300
// Canonical corpus name: GameDataFileIO
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GameDataFileIO_004b7300.c

void UnknownObject::GameDataFileIO()
{
    // Loads or resets game data files for a track/vehicle. With the cleanup flag set (a3 nonzero) it frees the linked node list headed at this+0x6C0 (each node freed by NodeDataFree then FreeWrapper_7bcf), zeroes the list pointers and several state fields, rebuilds directory and name path strings by scanning the path globals dword_7CE5D0 and dword_7CE608 for the last byte 92 (0x5C backslash, falling back to byte_5EA438), runs a settings-file existence check, re-reads the vehicle data reference at dword_7C54F0[dword_7C54E4] + 18580 into this+0xF1C and the session type dword_7C56A4 into this+0xF20, and stores 1 or 0 into this+0x700 depending on whether the settings file was found. With the cleanup flag clear it opens an audio stream from a2, loads a model/scene file, stores 2 into this+0x700 on success and closes the handle on failure. Returns whether this+0x6E4 holds a nonzero loaded-data handle.
    // CALL: Initialize loader state: sub_4B7500(1) runs at function entry before either branch. [callee:0x004B7500, source:raw]
    // GUARD: Branch on the cleanup flag a3: nonzero selects the reset/cleanup path, zero selects the load path. [source:raw]
    // CALL: Cleanup path: LinkedBufferTransfer(this) transfers buffered data back into the object. [callee:0x004B5F60, source:raw]
    // CALL: Cleanup path: sub_4B5E50(this) prepares/reinitializes internal data structures for a reload. [callee:0x004B5E50, source:raw]
    // LOOP: Walk the singly-linked list headed at this+0x6C0, following each node's next pointer at node+0x8 until the terminator is reached. [field:this:0x000006C0, field:*(this+0x6C0):0x00000008, source:raw]
    // CALL: Per node in the walk: NodeDataFree(node) releases the node's data payload. [callee:0x004BB3D0, source:raw]
    // CALL: Per node in the walk: FreeWrapper_7bcf(node) releases the node allocation itself. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the four list-state dwords this+0x6C0, this+0x6C4, this+0x6C8 and this+0x6CC after freeing. [field:this:0x000006C0, field:this:0x000006C4, field:this:0x000006C8, field:this:0x000006CC, source:raw]
    // CALL: StringCopyWithBufferRealloc(a2) copies the caller-supplied path string into the object's path buffer. [callee:0x00566650, source:raw]
    // CALCULATION: Resolve the first directory path: base = dword_7CE5D0, or byte_5EA438 when dword_7CE5D0 is null; scan backward from the string end while the byte differs from literal 92 (0x5C) to locate the last backslash, then advance one byte past it. [global:0x007CE5D0, global:0x005EA438, source:raw]
    // CALL: StringCopyWithBufferRealloc(v7) stores the directory portion derived from the first path. [callee:0x00566650, source:raw]
    // CALCULATION: Resolve the second directory path: base = dword_7CE608, or byte_5EA438 when dword_7CE608 is null; same backward scan for literal 92 (0x5C) and advance past the last backslash. [global:0x007CE608, global:0x005EA438, source:raw]
    // CALL: StringCopyWithBufferRealloc(v9) stores the directory portion derived from the second path. [callee:0x00566650, source:raw]
    // CALL: FileSettingExistenceCheck(this) verifies the settings/data file at the constructed path. [callee:0x004B8010, source:raw]
    // CALL: sub_4B9830(this+0x704) processes the filename stored at this+0x704 from a full path. [callee:0x004B9830, field:this:0x00000704, source:raw]
    // CALL: sub_566940(v10, 0, 0, 1) tests presence of the candidate settings file, where v10 is the name at this+0x704 or byte_5EA438 when null. [callee:0x00566940, field:this:0x00000704, global:0x005EA438, source:raw]
    // GUARD: Branch on the nonzero return of sub_566940: true means the settings file exists. [source:raw]
    // ASSIGNMENT: Found: this+0x700 is set to literal 1. [field:this:0x00000700, source:raw]
    // CALL: Not found: StringCopyWithBufferRealloc(byte_5EA438) copies the fallback path. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Not found: this+0x700 is set to literal 0. [field:this:0x00000700, source:raw]
    // ASSIGNMENT: Zero the three state dwords this+0xF24, this+0xF28 and this+0xF2C. [field:this:0x00000F24, field:this:0x00000F28, field:this:0x00000F2C, source:raw]
    // ASSIGNMENT: Zero the state dword this+0xD28. [field:this:0x00000D28, source:raw]
    // ASSIGNMENT: Zero the byte flag at this+0xF78. [field:this:0x00000F78, source:raw]
    // ASSIGNMENT: this+0xF1C = *(dword_7C54F0[dword_7C54E4] + 18580): copy a field from the current vehicle object (array base dword_7C54F0 indexed by dword_7C54E4, offset 18580 bytes). [field:this:0x00000F1C, global:0x007C54F0, global:0x007C54E4, source:raw]
    // ASSIGNMENT: this+0xF20 = dword_7C56A4: copy the session type global. [field:this:0x00000F20, global:0x007C56A4, source:raw]
    // RETURN: Cleanup path returns *(this+0x6E4) != 0, the loaded-data handle guard from the packet. [guard:0, field:this:0x000006E4, source:raw]
    // CALL: Load path: AudioStreamOpen(a2, 0) opens an audio stream from the caller-supplied path. [callee:0x00566B20, source:raw]
    // GUARD: Branch on the return of ModelSceneFileLoader(this, this+0x6E4): true selects the success path, false the failure path. [callee:0x004B6C90, field:this:0x000006E4, source:raw]
    // CALL: Success path: AngleClampWrap(*(float*)(this+0xF30)) normalizes the loaded angle value. [callee:0x004B86E0, field:this:0x00000F30, source:raw]
    // ASSIGNMENT: Success path: this+0x700 is set to literal 2 to mark the model as loaded. [field:this:0x00000700, source:raw]
    // RETURN: Success path returns *(this+0x6E4) != 0. [field:this:0x000006E4, source:raw]
    // CALL: Failure path: ConditionalFileHandleCloseWithFlagDispatch(this+0x6E4) closes the loaded-data handle conditionally. [callee:0x00566B90, field:this:0x000006E4, source:raw]
    // RETURN: Failure path returns *(this+0x6E4) != 0. [field:this:0x000006E4, source:raw]

    // Conservative worker pseudocode:
    //   BOOL GameDataFileIO(int this, int path, int cleanup) {
    //     sub_4B7500(1);
    //     if (cleanup) {
    //       LinkedBufferTransfer(this);
    //       sub_4B5E50(this);
    //       node = *(int*)(this + 1728);
    //       while (node) { next = *(int*)(node + 1); NodeDataFree(node); FreeWrapper_7bcf(node); node = next; }
    //       *(int*)(this+1728)=0; *(int*)(this+1732)=0; *(int*)(this+1736)=0; *(int*)(this+1740)=0;
    //       StringCopyWithBufferRealloc(path);
    //       base = dword_7CE5D0 ? dword_7CE5D0 : byte_5EA438;
    //       end = base + strlen(base);
    //       while (end > base && *end != 92) --end;
    //       if (end > base) ++end;
    //       StringCopyWithBufferRealloc(end);
    //       base = dword_7CE608 ? dword_7CE608 : byte_5EA438;
    //       end = base + strlen(base);
    //       while (end > base && *end != 92) --end;
    //       if (end > base) ++end;
    //       StringCopyWithBufferRealloc(end);
    //       FileSettingExistenceCheck(this);
    //       sub_4B9830(this + 1796);
    //       name = *(char**)(this + 1796); if (!name) name = byte_5EA438;
    //       if (sub_566940(name, 0, 0, 1)) { *(int*)(this + 1792) = 1; }
    //       else { StringCopyWithBufferRealloc(byte_5EA438); *(int*)(this + 1792) = 0; }
    //       *(int*)(this+3876)=0; *(int*)(this+3880)=0; *(int*)(this+3884)=0;
    //       *(int*)(this+3368)=0; *(char*)(this+3960)=0;
    //       *(int*)(this + 3868) = *(int*)(dword_7C54F0[dword_7C54E4] + 18580);
    //       *(int*)(this + 3872) = dword_7C56A4;
    //       return *(int*)(this + 1764) != 0;
    //     } else {
    //       AudioStreamOpen(path, 0);
    //       if (ModelSceneFileLoader(this, this + 1764)) {
    //         AngleClampWrap(*(float*)(this + 3888));
    //         *(int*)(this + 1792) = 2;
    //         return *(int*)(this + 1764) != 0;
    //       } else {
    //         ConditionalFileHandleCloseWithFlagDispatch(this + 1764);
    //         return *(int*)(this + 1764) != 0;
    //       }
    //     }
    //   }
    // UNRESOLVED: The object type behind `this` and the identity of the linked-list nodes at this+0x6C0 (each freed with NodeDataFree then FreeWrapper_7bcf) are not established; the packet owner is UnknownObject.
    // UNRESOLVED: The 18580-byte offset read from the current vehicle object dword_7C54F0[dword_7C54E4] is copied to this+0xF1C, but the meaning of that vehicle field is not defined in this packet.
    // UNRESOLVED: The backward scan comparing bytes against literal 92 is interpreted as directory-separator (backslash 0x5C) extraction; that reading is DERIVED, no callee contract states it.
    // UNRESOLVED: sub_566940's exact contract (arguments 0, 0, 1 and its return semantics) is treated as a boolean file-presence test from the skeleton fill; it is not proven by this packet.
    // UNRESOLVED: The purpose of the StringCopyWithBufferRealloc(byte_5EA438) call on the settings-not-found path is unclear beyond storing the fallback string.
}
