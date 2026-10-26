// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B6940
// Canonical corpus name: PitstopActionSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PitstopActionSet_004b6940.c

void UnknownObject::PitstopActionSet()
{
    // Appends a new entry to a pit-stop circular buffer and writes a float value into its Z field. Always calls sub_4B7860(0) first. When CoordinateBoundCheck reports invalid indices, resets the write index (this+0x9B8) and read index (this+0x9BC) to 0 and reinitializes the buffer data array (this+0x9B0) via PhysicsObjectListManager; otherwise advances the buffer with CircularCounterIncrement. Computes the entry offset as 176 * writeIndex and stores a2 (as float) at array + offset + 108, returning the computed offset.
    // CALL: Call sub_4B7860(0) as pre-setup/reset before handling the buffer. [function:0x004B6940, source:raw, callee:0x004B7860]
    // GUARD: Guard on CoordinateBoundCheck(this): when buffer indices are invalid, reset write index this+0x9B8 and read index this+0x9BC to 0 and call PhysicsObjectListManager on the data array pointer this+0x9B0 to reinitialize. [source:raw, callee:0x004B69F0, callee:0x004B4E10, field:this:0x000009B8, field:this:0x000009BC, field:this:0x000009B0]
    // CALL: Else (valid indices) advance the circular buffer write index via CircularCounterIncrement(this). [source:raw, callee:0x004B69A0]
    // ASSIGNMENT: Compute the entry offset as 176 * writeIndex and write the float a2 into the entry Z field at array (this+0x9B0) + offset + 108. [source:raw, field:this:0x000009B0, field:this:0x000009B8]
    // RETURN: Return the computed entry offset (176 * writeIndex). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4B6940(int this, float a2) {
    //     sub_4B7860(0);
    //     if (CoordinateBoundCheck(this)) {
    //       char* data = (char*)this[620];
    //       this[623] = 0;
    //       this[622] = 0;
    //       PhysicsObjectListManager(data);
    //     } else {
    //       CircularCounterIncrement(this);
    //     }
    //     int offset = 176 * this[622];
    //     *(float*)(offset + this[620] + 108) = a2;
    //     return offset;
    //   }
    // UNRESOLVED: Whether the entry float at +108 is a Z-position or a speed is not resolvable from this function alone; the 176-byte entry stride and the +108 field layout are read from the raw source but not independently confirmed.
    // UNRESOLVED: The return value (176 * writeIndex) appears unused by the packet's callers but no caller usage was verified.
}
