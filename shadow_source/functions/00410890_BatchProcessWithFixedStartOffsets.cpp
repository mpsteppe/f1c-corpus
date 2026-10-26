// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00410890
// Canonical corpus name: BatchProcessWithFixedStartOffsets
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BatchProcessWithFixedStartOffsets_00410890.c

void UnknownObject::BatchProcessWithFixedStartOffsets()
{
    // Dispatches StateDependentUpdateDispatch over six arrays of 36-byte objects held in a single struct. Each batch has a count field and a base pointer field; three batches start from index 0, three start from a fixed start index (416, 208, 832) below which no objects exist. Resets this+0x6C to 0. Returns the last batch's count (this+0x60). Called by DynMan_Restart.
    // ASSIGNMENT: Reset this+0x6C (this[27]) to 0. [field:this:0x0000006C]
    // LOOP: Batch 1: for index 0..this+0x24-1, call StateDependentUpdateDispatch(base at this+0x28 + index*36). [callee:0x0040F130, field:this:0x00000024, field:this:0x00000028, source:raw]
    // LOOP: Batch 2 (guard this+0x30 > 0): for index 0..this+0x30-1, call StateDependentUpdateDispatch(base at this+0x34 + index*36). [guard:0, callee:0x0040F130, field:this:0x00000030, field:this:0x00000034]
    // LOOP: Batch 3 (guard this+0x3C > 0): for index 0..this+0x3C-1, call StateDependentUpdateDispatch(base at this+0x40 + index*36). [guard:1, callee:0x0040F130, field:this:0x0000003C, field:this:0x00000040]
    // LOOP: Batch 4 (guard this+0x48 > 416): for index 416..this+0x48-1, call StateDependentUpdateDispatch(base at this+0x4C + index*36); start pointer offset 14976 = 416*36. [guard:2, callee:0x0040F130, field:this:0x00000048, field:this:0x0000004C]
    // LOOP: Batch 5 (guard this+0x54 > 208): for index 208..this+0x54-1, call StateDependentUpdateDispatch(base at this+0x58 + index*36); start pointer offset 7488 = 208*36. [guard:3, callee:0x0040F130, field:this:0x00000054, field:this:0x00000058]
    // LOOP: Batch 6 (guard this+0x60 > 832): for index 832..this+0x60-1, call StateDependentUpdateDispatch(base at this+0x64 + index*36); start pointer offset 29952 = 832*36. [callee:0x0040F130, field:this:0x00000060, field:this:0x00000064, source:raw]
    // RETURN: Return this+0x60 (last batch's count, reloaded each loop iteration). [field:this:0x00000060]

    // Conservative worker pseudocode:
    //   int BatchProcessWithFixedStartOffsets(this) {
    //     this->f6C = 0;
    //     for (i = 0; i < this->f24; i++) StateDependentUpdateDispatch(this->f28 + i*36);
    //     if (this->f30 > 0) for (i = 0; i < this->f30; i++) StateDependentUpdateDispatch(this->f34 + i*36);
    //     if (this->f3C > 0) for (i = 0; i < this->f3C; i++) StateDependentUpdateDispatch(this->f40 + i*36);
    //     if (this->f48 > 416) for (i = 416; i < this->f48; i++) StateDependentUpdateDispatch(this->f4C + i*36);
    //     if (this->f54 > 208) for (i = 208; i < this->f54; i++) StateDependentUpdateDispatch(this->f58 + i*36);
    //     if (this->f60 > 832) for (i = 832; i < this->f60; i++) StateDependentUpdateDispatch(this->f64 + i*36);
    //     return this->f60;
    //   }
    // UNRESOLVED: Object type per 36-byte batch entry and why batches 4-6 have fixed start indices (416/208/832) not established.
    // UNRESOLVED: Batch 1 and batch 6 count guards exist in raw source but are not indexed in the packet guards array; described from source:raw.
}
