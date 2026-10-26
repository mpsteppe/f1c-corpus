// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048E8D0
// Canonical corpus name: CUBESceneLoaderEntry
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CUBESceneLoaderEntry_0048e8d0.c

void UnknownObject::CUBESceneLoaderEntry()
{
    // CUBE scene data load entry point. Resolves a directory path (this[56], defaulting to byte_5EA438) and fails early when sub_588410(path, byte_5EA438) rejects it. Otherwise traverses the child linked list at this[16], then attempts AudioEngineInitialization(this + 58, path, 0). On failure, when this[58] is set it stores this[59] = SimpleGetter_5020(), and when this[59] is set it dispatches the fallback UtilityFunction_1cd0(0, 0, 0.0, 0, 0, 0) and sub_541CA0(0) before returning 0. On success it relocates string data via StringRelocationCopy(0, v5) and logs an error via DebugLogWrite(&dword_8AD25C, aCubeErrorLoadi_1) if StringSplitLoop(1, aDDevF119992002_27, 8793) reports a split error; returns 1.
    // ASSIGNMENT: Resolve the directory path: v2 = this[56], defaulting to byte_5EA438 when null. [function:0x0048E8D0, field:this:0x000000E0, global:0x005EA438, source:raw]
    // GUARD: When sub_588410(v2, byte_5EA438) is false (path validation fails), return 0 immediately. [callee:0x00588410, global:0x005EA438, source:raw]
    // CALL: Traverse the child linked list: LinkedListTraversalWithVirtualCall(this[16]). [callee:0x00496E40, field:this:0x00000040, source:raw]
    // CALL: Initialize the audio engine: AudioEngineInitialization(this + 58, v3, 0), where v3 is the resolved directory path (default byte_5EA438). [callee:0x00546010, field:this:0x000000E0, global:0x005EA438, source:raw]
    // GUARD: On audio init failure: when this[58] is set, this[59] = SimpleGetter_5020(); when this[59] is then set, dispatch the fallback calls. [callee:0x00545020, field:this:0x000000E8, field:this:0x000000EC, source:raw]
    // CALL: Fallback on failure: UtilityFunction_1cd0(0, 0, 0.0, 0, 0, 0) followed by sub_541CA0(0). [callee:0x00541CD0, callee:0x00541CA0, source:raw]
    // RETURN: Audio-init failure path returns 0. [source:raw]
    // CALL: On success, relocate string data: StringRelocationCopy(0, v5). [callee:0x0053C5B0, source:raw]
    // CALL: When StringSplitLoop(1, aDDevF119992002_27, 8793) returns non-zero, write the cube error message: DebugLogWrite(&dword_8AD25C, aCubeErrorLoadi_1). [callee:0x004D7A50, global:0x005CC248, callee:0x004D7AA0, global:0x008AD25C, global:0x005CC220, source:raw]
    // RETURN: Success path returns 1. [source:raw]

    // Conservative worker pseudocode:
    //   char CUBESceneLoaderEntry(this) {
    //     char* dir = this[56] ? (char*)this[56] : byte_5EA438;
    //     if (!sub_588410(dir, byte_5EA438)) return 0;
    //     LinkedListTraversalWithVirtualCall(this[16]);
    //     dir2 = this[56] ? (char*)this[56] : byte_5EA438;
    //     if (!AudioEngineInitialization(this + 58, dir2, 0)) {
    //       if (this[58]) this[59] = SimpleGetter_5020();
    //       if (this[59]) {
    //         UtilityFunction_1cd0(0, 0, 0.0, 0, 0, 0);
    //         sub_541CA0(0);
    //       }
    //       return 0;
    //     }
    //     StringRelocationCopy(0, v5);
    //     if (StringSplitLoop(1, aDDevF119992002_27, 8793))
    //       DebugLogWrite(&dword_8AD25C, aCubeErrorLoadi_1);
    //     return 1;
    //   }
    // UNRESOLVED: Global dword_8AFE64 appears in the packet global list but is not a named reference in the decompiled body; existing analysis labels it RaceTimeDelta.
    // UNRESOLVED: Semantics of sub_588410's path comparison, SimpleGetter_5020, UtilityFunction_1cd0, sub_541CA0 and the aDDevF119992002_27 split at 8793 are not established beyond their call sites.
    // UNRESOLVED: The this + 58 / this[58] and this[59] fields are dword indices; their byte offsets (0xE8 / 0xEC) match the packet fields but the object layout is unverified.
}
