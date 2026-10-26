// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00500F55
// Canonical corpus name: ArithmeticComparison_0f55
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_0f55_00500f55.c

void UnknownObject::DestroyTree()
{
    // Recursive destructor for a tree/list node. The data pointer at this+0x4 is freed via FreeWrapper_7bcf only when both it and the ownership flag at this+0x38 are non-null. The data pointer at this+0x8 is freed only when both it and the flag at this+0x3C are non-null, and FreeWrapper's result is retained. Each child node pointer (this+0x4C and this+0x50), when non-null, is recursively destroyed through this same function and then freed. Returns the last FreeWrapper result when the second child was processed, otherwise the result captured from the this+0x8 free branch.
    // GUARD: if (*(this+0x4) != 0 && *(this+0x38) != 0) : data pointer A is freed only when present and its ownership flag at 0x38 is set. [field:this:0x00000004, field:this:0x00000038, source:raw]
    // CALL: FreeWrapper_7bcf(*(this+0x4)) : free data pointer A. [callee:0x00587BCF, field:this:0x00000004, source:raw]
    // ASSIGNMENT: result = *(this+0x8) : read data pointer B. [field:this:0x00000008, source:raw]
    // GUARD: if (result != 0 && *(this+0x3C) != 0) : data pointer B is freed only when present and its ownership flag at 0x3C is set. [field:this:0x00000008, field:this:0x0000003C, source:raw]
    // CALL: result = FreeWrapper_7bcf(*(this+0x8)) : free data pointer B, keeping the result as the fallthrough return value. [callee:0x00587BCF, field:this:0x00000008, source:raw]
    // ASSIGNMENT: v3 = *(this+0x4C) : read child node pointer A. [field:this:0x0000004C, source:raw]
    // GUARD: if (v3 != 0) : child A is processed only when present. [field:this:0x0000004C, source:raw]
    // CALL: DestroyTree(*(this+0x4C)) : recursively destroy child node A. [callee:0x00500F55, field:this:0x0000004C, source:raw]
    // CALL: result = FreeWrapper_7bcf(v3) : free child node A after its recursive destruction. [callee:0x00587BCF, field:this:0x0000004C, source:raw]
    // ASSIGNMENT: v4 = *(this+0x50) : read child node pointer B. [field:this:0x00000050, source:raw]
    // GUARD: if (v4 != 0) : child B is processed only when present. [field:this:0x00000050, source:raw]
    // CALL: DestroyTree(v4) : recursively destroy child node B. [callee:0x00500F55, field:this:0x00000050, source:raw]
    // RETURN: return FreeWrapper_7bcf(v4) : free child node B and return the FreeWrapper result immediately. [callee:0x00587BCF, field:this:0x00000050, source:raw]
    // RETURN: return result : fallthrough return when child B was absent, yielding the result captured from the this+0x8 free branch (or the raw pointer read at entry). [field:this:0x00000008, source:raw]

    // Conservative worker pseudocode:
    //   int sub_500F55(int this) {
    //     int result;
    //     if (*(_DWORD *)(this + 4) && *(_DWORD *)(this + 56))
    //       FreeWrapper_7bcf(*(void **)(this + 4));
    //     result = *(_DWORD *)(this + 8);
    //     if (result && *(_DWORD *)(this + 60))
    //       result = FreeWrapper_7bcf(*(void **)(this + 8));
    //     void *v3 = *(void **)(this + 76);
    //     if (v3) {
    //       sub_500F55(*(_DWORD *)(this + 76));
    //       result = FreeWrapper_7bcf(v3);
    //     }
    //     void *v4 = *(void **)(this + 80);
    //     if (v4) {
    //       sub_500F55(v4);
    //       return FreeWrapper_7bcf(v4);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Owner object and the semantics of the guard flags at 0x38/0x3C (ownership flags gating the free of the data pointers at 0x4/0x8) are unknown; no evidence ties them to a concrete container type.
    // UNRESOLVED: Child pointers at 0x4C/0x50 are nodes of the same recursive type; the concrete node layout beyond the fields named here is not in evidence.
}
