// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00488A30
// Canonical corpus name: UIScrollWidgetUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIScrollWidgetUpdate_00488a30.c

void UnknownObject::UIScrollWidgetUpdate()
{
    // Main per-frame update for a UI scroll widget. When the enable flag at this+0xEC is set, reads the input delta pair via DualFieldRead, dispatches virtual calls to fetch the current position (vtable+24) and its lower/upper scroll bounds (vtable+28 and vtable+36), sets the active/in-range flag at this+0xED when the delta lies inside those bounds, runs DeltaBasedUpdate, and finally, if the widget is not hidden (vtable+152 returns false), dispatches a notify call (vtable+44, arg 1) and runs the extra widget update sub_486600.
    // GUARD: Guard on the enable flag at this+0xEC; when it is zero the entire update body is skipped and the function returns 0. [field:this:0x000000EC, source:raw]
    // CALL: Call DualFieldRead(v6, &v5) to read the input delta pair backing the scroll position range data at obj+0x2C. [callee:0x00498880, field:obj:0x0000002C, source:raw]
    // CALL: Dispatch the vtable entry at obj+0x18 (vtable+24) with no argument to update the current position. [field:obj:0x00000018, field:this:0x00000000, source:raw]
    // CALL: Dispatch the vtable entry at obj+0x1C (vtable+28) and store its return as the low scroll bound. [field:obj:0x0000001C, field:this:0x00000000, source:raw]
    // CALL: Dispatch the vtable entry at obj+0x24 (vtable+36) and store its return as the high scroll bound. [field:obj:0x00000024, field:this:0x00000000, source:raw]
    // GUARD: Range check: only when the delta v5 is greater than or equal to the low bound and less than or equal to the high bound is the widget considered in-range. [field:this:0x000000ED, source:raw]
    // ASSIGNMENT: Set the active/in-range flag at this+0xED to 1 when the delta is within the scroll bounds. [field:this:0x000000ED, source:raw]
    // CALL: Call DeltaBasedUpdate(this) to process scroll delta changes. [callee:0x00488900, source:raw]
    // GUARD: Hidden check: dispatch vtable entry at obj+0x98 (vtable+152); when it returns false (not hidden) the notify path runs. [field:obj:0x00000098, field:this:0x00000000, source:raw]
    // CALL: Dispatch the vtable entry at vtable+44 with argument 1 to notify the widget of the visible state. [field:this:0x00000000, source:raw]
    // CALL: Call sub_486600(this), the additional widget update step for the not-hidden path. [callee:0x00486600, source:raw]
    // RETURN: Return 0 at the end of the guarded body and when the enable flag is clear. [source:raw]

    // Conservative worker pseudocode:
    //   int UIScrollWidgetUpdate(_BYTE *this) {
    //     int low, high; int v5; char pair[4];
    //     if (!this[236]) return 0;
    //     DualFieldRead(pair, &v5);
    //     vtable(this)[24](this);
    //     low  = vtable(this)[28](this);
    //     high = vtable(this)[36](this);
    //     if (v5 >= low && v5 <= high) this[237] = 1;
    //     DeltaBasedUpdate(this);
    //     if (!vtable(this)[152](this)) {
    //       vtable(this)[44](this, 1);
    //       sub_486600(this);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Vtable offsets 24, 28, 36, 44 and 152 are called through the object vtable but their concrete implementations are outside this function.
    // UNRESOLVED: obj+0x2C is read in the field table as DualFieldRead backing data; the exact layout of the delta pair is not visible here.
}
