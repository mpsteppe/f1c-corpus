// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042EBC0
// Canonical corpus name: HistoryBufferShift
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HistoryBufferShift_0042ebc0.c

void UnknownObject::HistoryBufferShift()
{
    // FIFO history-buffer shift over two separate buffer regions of the struct. Each 16-dword record is overwritten with its predecessor, discarding the oldest record. The first region (start at 0xC8) is shifted as 4 groups of 11 records; the second region (start at 0xBC8) is shifted as 55 records.
    // ASSIGNMENT: Initialize v1 to this + 50 dwords, i.e. the start of the first history buffer at byte offset 0xC8. [field:this:0x000000C8, source:raw]
    // LOOP: Outer do-while loop running 4 times (one pass per group of the first buffer), counting down a group counter. [source:raw]
    // LOOP: Inner do-while loop over 11 records per group: copy the previous record into the current slot (*v1 = *(v1 - 1)) and advance v1 by 16 dwords each iteration. [source:raw]
    // ASSIGNMENT: Initialize result to this + 754 dwords, i.e. the start of the second history buffer at byte offset 0xBC8. [field:this:0x00000BC8, source:raw]
    // LOOP: do-while loop over 55 records of the second buffer: copy the previous record into the current slot (*result = *(result - 1)) and advance result by 16 dwords each iteration. [source:raw]
    // RETURN: Return result, the one-past-end pointer after the final copied record of the second buffer. [source:raw]

    // Conservative worker pseudocode:
    //   int *HistoryBufferShift(int *this) {
    //     int *v1 = this + 50;
    //     for (int g = 4; g; --g) {
    //       for (int n = 11; n; --n) {
    //         *v1 = *(v1 - 1);
    //         v1 += 16;
    //       }
    //     }
    //     int *result = this + 754;
    //     for (int n = 55; n; --n) {
    //       *result = *(result - 1);
    //       result += 16;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantic meaning of the shifted history records is unknown; first region holds 4 groups of 11 records, second holds 55 records.
    // UNRESOLVED: Called by ValidateVehicleConfigurationFile (0x00433ED0), but no static path from the tick root reaches it, so the call context is unknown.
}
