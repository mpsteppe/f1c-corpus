// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00449340
// Canonical corpus name: PhysicsBufferFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsBufferFree_00449340.c

void UnknownObject::PhysicsBufferFree()
{
    // Physics-buffer teardown routine called from collision and scene loaders (CollisionShapeInit, CollisionContactBufferAllocator, BezierPatchTessellation, CollisionGeometryOperationSelector, SceneTrackFileLoader): saves field 0x8, zeroes fields 0x4 and 0x0, frees the saved field-0x8 buffer through its allocation header (result-4), then conditionally destroys and frees the physics sub-components referenced by fields 0xC and 0x10 before zeroing them. Returns the last free result.
    // ASSIGNMENT: Save the current value of field this+0x8 into result before zeroing it. [field:this:0x00000008]
    // ASSIGNMENT: Zero field this+0x4. [field:this:0x00000004]
    // ASSIGNMENT: Zero field this+0x0. [field:this:0x00000000]
    // GUARD: If the saved field-0x8 value is non-zero, free its buffer via FreeWrapper_7bcf(result-4), where the allocation header precedes the buffer by 4 bytes. [field:this:0x00000008, callee:0x00587BCF]
    // ASSIGNMENT: Zero field this+0x8 after freeing the buffer. [field:this:0x00000008]
    // GUARD: If the pointer stored in field this+0xC is non-zero, enter the sub-component teardown branch. [field:this:0x0000000C]
    // CALL: PhysicsSubComponentDestroy(pointer at field this+0xC): destroy the physics sub-component. [field:this:0x0000000C, callee:0x00448570]
    // CALL: FreeWrapper_7bcf(pointer at field this+0xC): free the sub-component buffer. [field:this:0x0000000C, callee:0x00587BCF]
    // ASSIGNMENT: Zero field this+0xC after freeing. [field:this:0x0000000C]
    // GUARD: If the pointer stored in field this+0x10 is non-zero, enter the sub-component teardown branch. [field:this:0x00000010]
    // CALL: PhysicsSubComponentDestroy(pointer at field this+0x10): destroy the physics sub-component. [field:this:0x00000010, callee:0x00448570]
    // CALL: FreeWrapper_7bcf(pointer at field this+0x10): free the sub-component buffer. [field:this:0x00000010, callee:0x00587BCF]
    // ASSIGNMENT: Zero field this+0x10 after freeing. [field:this:0x00000010]
    // RETURN: Return result, the value of the most recent FreeWrapper_7bcf call, or the original saved field-0x8 value when no free ran. [source:raw]

    // Conservative worker pseudocode:
    //   result = this->field8;
    //   this->field4 = 0;
    //   this->field0 = 0;
    //   if (result) { result = FreeWrapper_7bcf(result-4); this->field8 = 0; }
    //   if (this->fieldC) { PhysicsSubComponentDestroy(this->fieldC); result = FreeWrapper_7bcf(this->fieldC); this->fieldC = 0; }
    //   if (this->field10) { PhysicsSubComponentDestroy(this->field10); result = FreeWrapper_7bcf(this->field10); this->field10 = 0; }
    //   return result;
    // UNRESOLVED: Why the field-0x8 buffer is freed through an allocation header (result-4) while the field-0xC and field-0x10 buffers are freed directly.
    // UNRESOLVED: Class identity of the owning object (fields at 0x0, 0x4, 0x8, 0xC, 0x10), used by several collision and scene loaders.
    // UNRESOLVED: Whether the sub-component buffers (fields 0xC, 0x10) are separately allocated or owned inside the field-0x8 allocation.
}
