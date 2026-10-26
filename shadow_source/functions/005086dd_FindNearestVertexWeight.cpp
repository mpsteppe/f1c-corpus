// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005086DD
// Canonical corpus name: FindNearestVertexWeight
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FindNearestVertexWeight_005086dd.c

void UnknownObject::FindNearestVertexWeight()
{
    // Vertex-buffer weight matcher (__thiscall): for each input vertex, scans a fixed 0x100-entry table of 4-float weights and writes the byte index of the entry with the minimum squared Euclidean distance into an output buffer. If the format-conversion flag this[1042] (byte 0x1048) is set, the input buffer is first remapped through DirectXVertexBufferFormatConversion. The output byte pointer is computed as this[6] (byte 0x18) + a3 * this[1045] (byte 0x1054) + a2 * this[1044] (byte 0x1050); the scan runs over this[1046] (byte 0x1058) vertices and the table base is float this+14 (byte 0x38). Returns the vertex counter.
    // GUARD: Guard on the format-conversion flag this[1042] (byte 0x1048); when non-zero the input vertex buffer is remapped before weight matching. [field:this:0x00001048, source:raw]
    // CALL: When the flag is set, result = DirectXVertexBufferFormatConversion(this, a4); when clear, result = a4. The chosen pointer is the source of vertex components. [callee:0x00506CE2, field:this:0x00001048, source:raw]
    // ASSIGNMENT: Compute the output byte pointer v5 = this[6] (byte 0x18) + a3 * this[1045] (byte 0x1054) + a2 * this[1044] (byte 0x1050); initialize the outer counter v14 to zero. [field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // GUARD: Guard on the vertex count this[1046] (byte 0x1058); when zero the entire scan is skipped and the function returns the counter (zero). [field:this:0x00001058, source:raw]
    // LOOP: Outer do-while loop over this[1046] (byte 0x1058) input vertices; per vertex, reset the best distance v15 to 3.4028235e38 and the nearest index v7 to zero, then run the inner table scan. [field:this:0x00001058, source:raw]
    // LOOP: Inner do-while loop over the 0x100 table entries, advancing v8 by 4 floats per entry; the input vertex start is at result+8, with the four components read from byte offsets +0, +4, +8, +12. [field:this:0x00000038, source:raw]
    // CALCULATION: Per entry, compute the squared distance v13 as the sum of squares of the four component differences (the fourth component difference v12 is computed first in the raw source). Each table entry is the 4-float row beginning at float this+14 (byte 0x38), so entry fields include byte 0x3C and the following floats. [field:this:0x00000038, field:this:0x0000003C, source:raw]
    // STATE_TRANSITION: If the entry's squared distance v13 is below the current best v15, record the entry counter v16 into the nearest-index v7 and update the best distance. [field:this:0x00000038, source:raw]
    // ASSIGNMENT: After the 0x100-entry scan, write the nearest entry index v7 as one byte to the output pointer v5, advance v5, advance the input pointer v6 by 4 floats, and increment the outer counter v14 (also stored back to result). [field:this:0x00000018, source:raw]
    // RETURN: Return the outer counter (last value of v14). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_5086DD(float* this, int a2, int a3, int a4) {
    //     int result = this[1042] ? DirectXVertexBufferFormatConversion(this, a4) : a4;
    //     char* out = (char*)(this[6] + a3 * this[1045] + a2 * this[1044]);
    //     unsigned int outer = 0;
    //     if (this[1046]) {
    //       float* vin = (float*)(result + 8);
    //       do {
    //         char bestIdx = 0; float best = 3.4028235e38; unsigned int i = 0;
    //         float* table = (float*)(this + 14);
    //         do {
    //           double dx3 = vin[0] - table[0];
    //           double dx2 = vin[1] - table[1];
    //           double dx0 = vin[2] - table[2];
    //           double dx1 = vin[3] - table[3];
    //           double dist = dx0 * dx0 + dx1 * dx1 + dx2 * dx2 + dx3 * dx3;
    //           if (dist < best) { bestIdx = (char)i; best = dist; }
    //           i++; table += 4;
    //         } while (i < 0x100);
    //         *out++ = bestIdx;
    //         result = ++outer;
    //         vin += 4;
    //       } while (outer < this[1046]);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Purpose and side effects of DirectXVertexBufferFormatConversion (0x00506CE2) are unknown beyond remapping the input buffer.
    // UNRESOLVED: The owning object type and the exact meaning of the 4-component weight table (float this+14, byte 0x38) are unknown; the scan is always over 0x100 entries regardless of this[1046].
    // UNRESOLVED: The roles of the a2/a3 stride fields (bytes 0x1050 and 0x1054) relative to the output buffer layout are not established by the packet.
    // UNRESOLVED: Field this+0x3C is flagged read and is interpreted here as the second float of the first weight-table entry; this association is DERIVED, not stated by the packet.
}
