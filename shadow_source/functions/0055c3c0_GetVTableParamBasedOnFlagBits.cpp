// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055C3C0
// Canonical corpus name: GetVTableParamBasedOnFlagBits
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GetVTableParamBasedOnFlagBits_0055c3c0.c

void UnknownObject::GetVTableParamBasedOnFlagBits()
{
    // Flag-selected virtual fetch. Reads the flag word at a2[6], chooses a target object by its bits (bit0 -> a2[2], bit1 -> a2[3], otherwise a2 itself), invokes the virtual slot at vtable offset 32 on that object with an 8-dword out buffer v7, stores the result into this[0], returns 255 on a non-zero result, otherwise calls sub_55C450 with a result-dependent first argument (21 when v7[0]==22, else v7[0]) and returns a2.
    // CALCULATION: Load the flag word v3 = a2[6] and branch on its bits. [source:raw]
    // CALCULATION: Select the target object pointer v4: bit0 (value 1) set -> a2[2]; else bit1 (value 2) set -> a2[3]; else v4 = a2 itself. [source:raw]
    // CALL: Indirect __stdcall virtual call through the selected object's vtable: v5 = (*(*v4 + 32))(v4, v7), slot at byte offset 32, passing v7 as an 8-dword out buffer. [source:raw]
    // ASSIGNMENT: Store the virtual call result into the first dword: this[0] (byte offset 0x0) = v5. [field:this:0x00000000, source:raw]
    // GUARD: If v5 is non-zero, return 255 and skip the sub_55C450 dispatch. [source:raw]
    // CALL: Dispatch by the out-buffer value: when v7[0] equals 22 call sub_55C450(21, 0, &a2), otherwise call sub_55C450(v7[0], 0, &a2). [callee:0x0055C450, source:raw]
    // RETURN: Return a2 (the parameter object pointer). [source:raw]

    // Conservative worker pseudocode:
    //   flags = a2[6];
    //   if (flags & 1)      obj = (DWORD*)a2[2];
    //   else if (flags & 2) obj = (DWORD*)a2[3];
    //   else                obj = a2;
    //   result = (*(stdcall**)(obj->vtable + 32))(obj, out_buf);
    //   this->field_0x0 = result;
    //   if (result) return 255;
    //   if (out_buf[0] == 22) sub_55C450(21, 0, &a2);
    //   else                  sub_55C450(out_buf[0], 0, &a2);
    //   return (int)a2;
    // UNRESOLVED: The identity of the class behind the selected object and the purpose of the virtual slot at vtable offset 32 are unidentified.
    // UNRESOLVED: The semantics of the v7[0] sentinel (22 mapped to argument 21) and why the function returns a2 are not established.
}
