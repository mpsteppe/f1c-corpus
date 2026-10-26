// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048B91A
// Canonical corpus name: UIWidgetVisibilityToggle
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIWidgetVisibilityToggle_0048b91a.c

void UnknownObject::UIWidgetVisibilityToggle()
{
    // Toggles a widget's visibility byte at a3 + 224 (0xE0) to a2 and asks the owning object a1 for a callback result. On the show path (a2 != 0) it returns that callback result directly. On the hide path (a2 == 0) it first clears the active-widget reference: if FieldGetter_79d0(*(a3 + 64)) equals a3, it calls SimpleSetter_79e0(*(a3 + 64)); then it invokes the thiscall vtable method at vtable offset 176 on a3 and returns that result. ABI lead name UI_Widget_Visibility_Toggle.
    // ASSIGNMENT: Write the visibility flag argument a2 into the byte at a3 + 224 (0xE0) on the widget object. [source:raw]
    // CALL: Invoke the callback function pointer stored at a1 + 44 (0x2C) with argument 1 and store its return value in result. [field:this:0x0000002C, source:raw]
    // GUARD: If a2 is nonzero (showing), skip the hide-cleanup branch and return the callback result. [source:raw]
    // CALL: Read the widget pointer stored at a3 + 64 and pass it to FieldGetter_79d0; if the returned pointer equals a3 itself, the active-widget reference must be cleared. [callee:0x004979D0, source:raw]
    // CALL: Call SimpleSetter_79e0 on the widget pointer stored at a3 + 64 to clear the active-widget reference. [callee:0x004979E0, source:raw]
    // CALL: Invoke the thiscall vtable method at vtable offset 176 (slot 44) on a3 and return its result. [source:raw]
    // RETURN: Return result: the vtable-method return on the hide path, the a1 + 44 callback return on the show path. [source:raw]

    // Conservative worker pseudocode:
    //   int UIWidgetVisibilityToggle(int a1, char a2, int a3) {
    //       *(char *)(a3 + 224) = a2;
    //       int result = (*(int (__cdecl **)(int))(a1 + 44))(1);
    //       if (!a2) {
    //           if (FieldGetter_79d0(*(int *)(a3 + 64)) == a3)
    //               SimpleSetter_79e0(*(int *)(a3 + 64));
    //           return (*(int (__thiscall **)(int))(*(int *)a3 + 176))(a3);
    //       }
    //       return result;
    //   }
    // UNRESOLVED: The accesses at a3 + 224 (0xE0), a3 + 64 (0x40) and the vtable slot at *(a3) + 176 appear only in the raw source; the packet field table lists only field:this:0x0000002C, so those accesses have no dedicated field evidence references.
    // UNRESOLVED: FieldGetter_79d0 / SimpleSetter_79e0 semantics (active-widget get and clear) are taken from their names and the existing analysis; the packet provides no call contracts.
    // UNRESOLVED: The relationship between caller object a1 and widget object a3 is not evidenced; the raw source has no owning class and the owner is unknown.
}
