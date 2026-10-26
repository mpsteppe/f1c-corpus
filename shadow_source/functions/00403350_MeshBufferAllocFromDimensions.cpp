// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00403350
// Canonical corpus name: F_3DBufferMeshMemoryAllocation
// Owner: F3DBufferMesh [DERIVED]
// Raw source: functions/F_3DBufferMeshMemoryAllocation_00403350.c

void F3DBufferMesh::MeshBufferAllocFromDimensions()
{
    // (Re)allocates the three mesh buffers of a 3D buffer object from dimension fields this+0x15C/0x160/0x164/0x168 (vertex count, index count, batch count, sub-batch multiplier). Frees existing allocations at this+0x150/0x154/0x158 via FreeWrapper_7bcf, computes layout offsets, allocates a stream buffer (28 * batchCount), an index buffer (28 * indexCount), and a batch buffer (28 * batchCount * subBatchMultiplier) via OperatorNewNhMallocWrapper, then zero-fills all three in 28-byte records (nested batch loop strides by batchCount). Sets this+0x8 to 1 (allocated marker) and writes offset fields this+0xC/0x10/0x14.
    // CALL: Free existing buffer pointers at this+0x150, this+0x154, this+0x158 with FreeWrapper_7bcf when non-null, before reallocation. [callee:0x00587BCF, field:this:0x00000150, field:this:0x00000154, field:this:0x00000158]
    // CALCULATION: Compute layout offsets from dimension fields: this+0xC = vertexCount (this+0x15C) + 1; this+0x10 = that plus indexCount (this+0x160); this+0x14 = that plus batchCount (this+0x164); set allocated marker this+0x8 = 1. [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x0000015C, field:this:0x00000160, field:this:0x00000164]
    // ASSIGNMENT: Allocate three buffers with OperatorNewNhMallocWrapper and store them: stream buffer 28 * batchCount to this+0x154, index buffer 28 * indexCount to this+0x150, batch buffer 28 * batchCount * subBatchMultiplier (this+0x168) to this+0x158. [callee:0x00587C03, field:this:0x00000150, field:this:0x00000154, field:this:0x00000158, field:this:0x00000160, field:this:0x00000164, field:this:0x00000168]
    // LOOP: Zero-fill the stream buffer at this+0x150 in 28-byte records; guarded by batchCount (this+0x164) > 0. [field:this:0x00000164, field:this:0x00000150, guard:1]
    // LOOP: Zero-fill the index buffer at this+0x154 in 28-byte records; guarded by indexCount (this+0x160) > 0. [field:this:0x00000160, field:this:0x00000154, guard:0]
    // LOOP: Zero-fill the batch buffer at this+0x158 in a nested loop: for each of batchCount groups (guard this+0x164 > 0), subBatchMultiplier (this+0x168) records of 28 bytes are cleared at stride batchCount (this+0x164). [field:this:0x00000164, field:this:0x00000168, field:this:0x00000158, guard:0, guard:1]
    // RETURN: Return the loop-counter __int64 value seeded from unsigned batchCount (this+0x164) after the nested batch zero-fill completes. [function:0x00403350, field:this:0x00000164, source:raw]

    // Conservative worker pseudocode:
    //   int sub_403350(F3DBufferMesh* this) {
    //     if (this->stream) FreeWrapper_7bcf(this->stream);
    //     if (this->index) FreeWrapper_7bcf(this->index);
    //     if (this->batch) FreeWrapper_7bcf(this->batch);
    //     int v2 = this->vertexCount + 1;
    //     int v3 = v2 + this->indexCount;
    //     this->offsetA = v2; this->offsetB = v3; this->offsetC = this->batchCount + v3;
    //     this->allocated = 1;
    //     this->index = OperatorNewNhMallocWrapper(28 * this->batchCount);
    //     this->stream = OperatorNewNhMallocWrapper(28 * this->indexCount);
    //     this->batch = OperatorNewNhMallocWrapper(28 * this->batchCount * this->subBatchMultiplier);
    //     for (int i = 0; i < this->batchCount; ++i) clear28(&this->index[i]);
    //     for (int j = 0; j < this->indexCount; ++j) clear28(&this->stream[j]);
    //     for (int g = 0; g < this->batchCount; ++g)
    //       for (int k = 0; k < this->subBatchMultiplier; ++k) clear28(&this->batch[g + k * this->batchCount]);
    //     return this->batchCount;
    //   }
    // UNRESOLVED: Return value semantics: the raw decompilation returns a loop-modified __int64 seeded from this+0x164; whether it is used as a status/count by the caller is not evidenced here.
    // UNRESOLVED: The 28-byte record layout (7 _DWORD slots) is only inferred from the zero-fill stride; the record structure is not described by other evidence.
    // UNRESOLVED: Assignment order of the three buffer pointers to this+0x150/0x154/0x158 differs between the source and the existing analysis; source order (this+0x154 then this+0x150 then this+0x158) is recorded here.
}
