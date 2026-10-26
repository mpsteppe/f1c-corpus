// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040ED10
// Canonical corpus name: sub_40ED10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_40ED10_0040ed10.c

void UnknownObject::ComputePositionMagnitude()
{
    // Mode-dispatch helper (this[7], cases 0-7) that fills a three-component position vector (this[3..5]) and a magnitude/radius (this[6]). Modes 0-5 go through sub-object+208; if that pointer is non-zero a TripleFieldQuery plus sqrt(MaxSquaredMagnitudeSearch) path runs. Mode 6 copies precomputed fields directly from the sub-object. Mode 7 either runs the same query path when sub-object+60 bit 0x10 is set, or computes the bounding-box center and half-diagonal radius via BoundingBoxComputation otherwise. Default case returns immediately.
    // ASSIGNMENT: Initialize this[6] to 0.0 before dispatch; any case may overwrite it. [field:this:0x00000018, source:raw]
    // CALCULATION: Read the mode selector this[7] and dispatch on it via the jump table at 0x0040EEA0. [field:this:0x0000001C, global:0x0040EEA0, source:raw]
    // GUARD: Modes 0-5: load v3 from the sub-object pointer this[8] at offset +208; a non-zero v3 redirects to the LABEL_16 query path. [field:this:0x00000020, field:*(this+0x20):0x000000D0, source:raw]
    // ASSIGNMENT: Mode 6: copy this[3], this[4], this[5] and this[6] verbatim from sub-object fields at offsets 0x34D4, 0x34D8, 0x34DC and 0x3B70. [field:*(this+0x20):0x000034D4, field:*(this+0x20):0x000034D8, field:*(this+0x20):0x000034DC, field:*(this+0x20):0x00003B70, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, source:raw]
    // GUARD: Mode 7: bail out of the case when the sub-object pointer this[8] is null. [field:this:0x00000020, source:raw]
    // GUARD: Mode 7: check bit 0x10 of the flag byte at sub-object+60; when set, run the LABEL_16 query path, otherwise run the bounding-box path. [field:*(this+0x20):0x0000003C, source:raw]
    // CALL: LABEL_16 path: fill the position vector via TripleFieldQuery(this+3, this+4, this+5). [callee:0x0054B420, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // CALCULATION: LABEL_16 path: this[6] = sqrt of the value returned by MaxSquaredMagnitudeSearch on the sub-object. [callee:0x004DD8F0, field:this:0x00000018, source:raw]
    // CALL: Bounding-box path: BoundingBoxComputation(&v10) fills a six-float box (min/max corners) in locals v10..v15. [callee:0x004DD550, source:raw]
    // CALCULATION: Bounding-box path: set this[3], this[4], this[5] to the box center, i.e. (min+max)/2 along each axis. [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // CALCULATION: Bounding-box path: set this[6] to the distance from the box center to the min corner (half the box diagonal), computed as sqrt of summed squared axis differences. [field:this:0x00000018, source:raw]
    // RETURN: Return immediately for any mode not handled (default switch case). [source:raw]

    // Conservative worker pseudocode:
    //   void sub_40ED10(float *this) {
    //     this[6] = 0.0f;
    //     switch (this[7]) {
    //       case 0: case 1: case 2: case 3: case 4: case 5:
    //         if (*(this[8]+208) != 0) goto query_path;
    //         break;
    //       case 6:
    //         this[3] = this[8][3381]; this[4] = this[8][3382];
    //         this[5] = this[8][3383]; this[6] = this[8][3804];
    //         break;
    //       case 7:
    //         if (this[8] != 0) {
    //           if ((*(this[8]+60) & 0x10) == 0x10) {
    //   query_path:
    //             TripleFieldQuery(&this[3], &this[4], &this[5]);
    //             this[6] = sqrt(MaxSquaredMagnitudeSearch(this[8]));
    //           } else {
    //             float box[6]; BoundingBoxComputation(box);
    //             this[3] = (box[0] + box[3]) * 0.5f;
    //             this[4] = (box[1] + box[4]) * 0.5f;
    //             this[5] = (box[2] + box[5]) * 0.5f;
    //             this[6] = sqrt((box[0]-this[3])*(box[0]-this[3])
    //                         + (box[1]-this[4])*(box[1]-this[4])
    //                         + (box[2]-this[5])*(box[2]-this[5]));
    //           }
    //         }
    //         break;
    //       default:
    //         return;
    //     }
    //   }
    // UNRESOLVED: The object type behind this[8] and the meanings of offsets +60 flag, +208 pointer, 0x34D4/0x34D8/0x34DC/0x3B70 fields are not established by this packet alone.
    // UNRESOLVED: Global flt_59E450 is listed as read but does not appear in the raw source text; its role here is unknown.
    // UNRESOLVED: Why the decompiler duplicates the this[8]+208 read for every mode 0-5 is an artifact, not a behavioral difference.
}
