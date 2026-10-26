// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00513E5D
// Canonical corpus name: FPUControlWordMerger
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FPUControlWordMerger_00513e5d.c

void UnknownObject::MergeFPUControlWordWithParamIntoGlobal()
{
    // Writes a value into the global dword_8B00A0 and returns that same value. The raw decompilation shows only an uninitialized stack local (v1) as the source, so the actual input value is not visible in the packet; the legacy ABI lead names this as merging an FPU control word / caller-supplied parameter into the global.
    // ASSIGNMENT: Store the value v1 into the global dword_8B00A0. v1 is an uninitialized stack local in the decompilation; per the legacy ABI lead the value derives from a caller-supplied parameter / FPU control word. [global:0x008B00A0, abi:lead, source:raw]
    // RETURN: Return the same value v1 that was just stored into dword_8B00A0. [function:0x00513E5D, source:raw]

    // Conservative worker pseudocode:
    //   dword_8B00A0 = v1;  // v1 source not captured by decompilation
    //   return v1;
    // UNRESOLVED: The input value v1 is an uninitialized local in the decompiled body; the actual argument or FPU control word feeding dword_8B00A0 is not evidenced by the packet source.
    // UNRESOLVED: The function body reads no parameter despite the legacy ABI lead naming 'param_1'; the mechanism by which the value reaches v1 is unresolved.
}
