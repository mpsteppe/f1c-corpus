// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046B070
// Canonical corpus name: UIClickHandlerWithBoundsCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIClickHandlerWithBoundsCheck_0046b070.c

void UnknownObject::UIClickHandlerWithBoundsCheck()
{
    // UI click handler for the key binding screen. Resets the screen-mode setting dword_7CFF84 to 0, reads a dual-field value, then compares it against two bounds obtained by dispatching vtable methods at offsets +24 and +32 (slots obj+0x18 and obj+0x20) on the object. If the read value is below both bounds it invokes KeyBindingUIPressKeyOrController(1, 1) to open the key/controller binding UI. Always returns 0.
    // ASSIGNMENT: Reset the screen-mode setting dword_7CFF84 to 0 on click. [global:0x007CFF84, source:raw]
    // CALL: Read the dual-field values v5 and v6 via DualFieldRead(&v5, v6). [callee:0x00498880, source:raw]
    // CALL: Dispatch the vtable method at slot +24 (obj+0x18) through the object's vtable pointer (this+0x0) to obtain the first bound value v2. [field:obj:0x00000018, field:this:0x00000000, source:raw]
    // GUARD: If v5 is not less than the first bound v2, skip the binding-UI path. [source:raw]
    // CALL: Dispatch the vtable method at slot +32 (obj+0x20) through the object's vtable pointer (this+0x0) to obtain the second bound value v3. [field:obj:0x00000020, field:this:0x00000000, source:raw]
    // GUARD: If v5 is not less than the second bound v3, block the binding-UI call. [source:raw]
    // CALL: Open the key/controller binding UI via KeyBindingUIPressKeyOrController(1, 1) when the value is below both bounds. [callee:0x0046B0C0, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   dword_7CFF84 = 0;
    //   DualFieldRead(&v5, &v6);
    //   v2 = (*(thiscall**)(*(DWORD*)this + 24))(this);
    //   if (v5 < v2) {
    //     v3 = (*(thiscall**)(*(DWORD*)this + 32))(this);
    //     if (v5 < v3)
    //       KeyBindingUIPressKeyOrController(1, 1);
    //   }
    //   return 0;
    // UNRESOLVED: v6, the second dual-field value, is read but never used in the visible logic.
    // UNRESOLVED: The exact semantics of the two vtable bound getters (slot +24 / +32) are DERIVED from context; the object layout and owner are unknown.
}
