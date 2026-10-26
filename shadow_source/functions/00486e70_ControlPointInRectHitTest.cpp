// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486E70
// Canonical corpus name: UIControlHitTest
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIControlHitTest_00486e70.c

void UnknownObject::ControlPointInRectHitTest()
{
    // UI control hit test (__thiscall): gated by the byte enable flag at this+0x65 (this[101]); when set, retrieves the control's bounding rectangle via the indirect bounds method at vtable+8 (dispatched through the vtable pointer at this+0x0) and returns 1 when point (a2, a3) lies inside that rectangle, otherwise 0.
    // GUARD: Enable gate on the byte flag this[101] (offset +0x65): when zero, hit testing is disabled and the function returns 0 without querying bounds. [field:this:0x00000065, source:raw]
    // CALL: Indirect virtual call: read the vtable pointer at this+0x0 and dispatch the bounds method at vtable+8 (field obj+0x8) on this, passing out-parameters that receive the rectangle edges (v4/v5 horizontal, v6/v7 vertical). [field:this:0x00000000, field:obj:0x00000008, source:raw]
    // GUARD: Point-in-rect test: return 1 when a2 lies between v4 and v5 (the horizontal edges) and a3 lies between v6 and v7 (the vertical edges). [source:raw]
    // RETURN: Default return is 0 for both the disabled path and a point outside the rectangle; the function returns BOOL result. [function:0x00486E70, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   BOOL ControlPointInRectHitTest(void *self, int x, int y) {
    //     int e0, e1, e2, e3;
    //     if (!self[0x65]) return 0;
    //     (*(void (**)(void *, int *, int *, int *, int *))*(void **)self)(self, &e0, &e1, &e2, &e3);
    //     return (x >= e2 && x <= e3 && y >= e0 && y <= e1) ? 1 : 0;
    //   }
    // UNRESOLVED: The mapping of the four out-parameters to left/top/right/bottom is inferred from the comparison order in the point test; the bounds method itself is unresolved (indirect call, no static callee).
    // UNRESOLVED: The owning control class and the semantic meaning of the enable flag at this+0x65 are unidentified.
}
