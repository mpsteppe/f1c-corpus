// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00554560
// Canonical corpus name: sub_554560
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_554560_00554560.c

void UnknownObject::SetDeviceState18()
{
    // State-18 conditional setter on a game device object. Guards against redundant sets (a2 == -1 or a2 already equals this[13]). For a2 == 0 dispatches vtable+252 on the global dword_8B89A0 object with state 18 and value 0. For a2 == 1 dispatches vtable+252 with state 18 and value 2 when byte_8B8C48 bit 0 is set, else value 1. Records the last applied a2 into this[13] (this+0x34). Other a2 values store without dispatching.
    // GUARD: Entry guard: if a2 == -1 or a2 == this[13] (last applied value), return early with no dispatch. [field:this:0x00000034, source:raw]
    // CALL: a2 == 0 path: dispatch vtable+252 on global dword_8B89A0 with *this as object id, state 18, value 0. [field:this:0x00000000, global:0x008B89A0, source:raw]
    // CALL: a2 == 1 path: dispatch vtable+252 on global dword_8B89A0 with *this as object id, state 18, and value 2 (if byte_8B8C48 bit 0 set) or 1 (if clear). [field:this:0x00000000, global:0x008B89A0, global:0x008B8C48, source:raw]
    // STATE_TRANSITION: Record this[13] = a2 (last applied state value) on all non-redundant paths. [field:this:0x00000034, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 == -1 || a2 == this->lastState18) return;
    //   if (a2 == 0) {
    //       result = VTableCall(dword_8B89A0, *this, 18, 0);
    //   } else if (a2 == 1) {
    //       value = (byte_8B8C48 & 1) ? 2 : 1;
    //       result = VTableCall(dword_8B89A0, *this, 18, value);
    //   }
    //   this->lastState18 = a2;
    //   return result;
    // UNRESOLVED: The early-return path for a2 == -1 / a2 == this[13] returns an uninitialized `result` in the decompiled output; the caller may ignore it.
    // UNRESOLVED: Return value semantics differ per branch (vtable-call return for a2==0/1, a2-1 for other values); the caller's use of it is unconfirmed.
    // UNRESOLVED: Vtable slot +252's exact meaning (state setter) is DERIVED from existing analysis only.
}
