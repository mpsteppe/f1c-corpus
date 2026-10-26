// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DCD80
// Canonical corpus name: TwoFieldSetterUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoFieldSetterUpdate_004dcd80.c

void UnknownObject::TwoFieldSetterUpdate()
{
    // Sets two dword fields on the object at +0x14 and +0x18 from a2 and a3, then calls sub_4DCA80(this) and returns its result. Unconditional, __thiscall; used as an update entry point by callers that re-render after changing position/size fields.
    // ASSIGNMENT: Write a2 into this[5] at offset +0x14. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Write a3 into this[6] at offset +0x18. [field:this:0x00000018, source:raw]
    // CALL: Call sub_4DCA80(this) after the field updates; per the skeleton this triggers the four-corner rectangle render using the updated fields. [callee:0x004DCA80, source:raw]
    // RETURN: Return the value produced by sub_4DCA80(this). [source:raw]
    // CALL: Called by F_2DTextRenderingWithScissorRectangle (0x0049B370), ShortComputation_f070 (0x0049F070) and FloatToIntConversionDispatch (0x004DCDA0) to update the two fields and re-render. [caller:0x0049B370, caller:0x0049F070, caller:0x004DCDA0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4DCD80(void *self, int a2, int a3) {
    //     self[0x14 / 4] = a2;
    //     self[0x18 / 4] = a3;
    //     return sub_4DCA80(self);
    //   }
    // UNRESOLVED: Object type is unknown; the semantics of +0x14 and +0x18 (position, size or other per-render fields) depend on the calling context.
}
