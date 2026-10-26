// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00554560
// Canonical corpus name: sub_554560
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_554560_00554560.c

void UnknownObject::State18ConditionalSetter()
{
    // Sets GameDeviceObject state 18 via virtual dispatch (vtable+252) with a value selected by a2 and the byte_8B8C48 sound-routing flag. For a2==0 sends value 0; for a2==1 sends 2 if byte_8B8C48 bit 0 is set else 1; other a2 values store without dispatch. Records a2 into this[13] (offset 0x34) unless a2 equals -1 or the previous stored value.
    // GUARD: Early return when a2 == -1 or a2 equals the previously stored value at this[13] (offset 0x34). [field:this:0x00000052]
    // CALL: For a2 == 0: dispatch through GameDeviceObject vtable+252 with (device, *this id, state 18, value 0). [global:0x008B89A0, field:this:0x00000000]
    // GUARD: For a2 == 1: select dispatch value from byte_8B8C48 bit 0 - 2 when set, 1 when clear. [global:0x008B8C48]
    // CALL: For a2 == 1: dispatch through GameDeviceObject vtable+252 with (device, *this id, state 18, selected value 2 or 1). [global:0x008B89A0, field:this:0x00000000]
    // ASSIGNMENT: For a2 not in {-1, 0, 1}: result becomes a2 - 1; no dispatch occurs. [field:this:0x00000052]
    // ASSIGNMENT: Record a2 into this[13] (offset 0x34) after handling. [field:this:0x00000052]
    // RETURN: Return the dispatch result (or a2 - 1 for unhandled values). [function:0x00554560]

    // Conservative worker pseudocode:
    //   if (a2 == -1 || a2 == this[13]) return;
    //   if (a2 == 0) { result = dev->vtbl252(dword_8B89A0, this[0], 18, 0); }
    //   else if (a2 == 1) { result = dev->vtbl252(dword_8B89A0, this[0], 18, (byte_8B8C48 & 1) ? 2 : 1); }
    //   else { result = a2 - 1; }
    //   this[13] = a2;
    //   return result;
    // UNRESOLVED: result is uninitialized on the early-return path in the raw decompile; treated as decompiler artifact
    // UNRESOLVED: caller is context reference, not used in reconstruction
}
