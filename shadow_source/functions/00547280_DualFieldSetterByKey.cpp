// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00547280
// Canonical corpus name: DualFieldSetterByKey
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualFieldSetterByKey_00547280.c

void UnknownObject::DualFieldSetterByKey()
{
    // Key-value config setter on the object pointed to by this. If a3 equals 4096 (0x1000) it stores a2 at this+0x8C (this[35]); else if a3 equals 0x2000 it stores a2 at this+0x90 (this[36]). Returns a2 when a key matched, otherwise returns the original a3 unchanged.
    // ASSIGNMENT: Seed result with a3 so a non-matching key returns the input key unchanged. [source:raw]
    // GUARD: Guard on a3 == 4096 (0x1000); when it passes, this[35] (this+0x8C) is written. [source:raw]
    // ASSIGNMENT: Write a2 into this[35] (this+0x8C). [source:raw, field:this:0x0000008C]
    // ASSIGNMENT: Update result to a2 after the first branch matched. [source:raw]
    // GUARD: Else-guard on a3 == 0x2000; when it passes, this[36] (this+0x90) is written. [source:raw]
    // ASSIGNMENT: Write a2 into this[36] (this+0x90). [source:raw, field:this:0x00000090]
    // RETURN: Return a2 when a key matched, else return the original a3. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_547280(int* this, int value, int key) {
    //     int result = key;
    //     if (key == 4096) {
    //       result = value;
    //       this[35] = value;
    //     } else if (key == 0x2000) {
    //       this[36] = value;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the keys 0x1000 and 0x2000 and the object layout behind this+0x8C / this+0x90 is unknown; caller sub_4CEF30 supplies the key-value pairs.
    // UNRESOLVED: Whether the two fields are a logical pair or two independent settable parameters is undetermined.
}
