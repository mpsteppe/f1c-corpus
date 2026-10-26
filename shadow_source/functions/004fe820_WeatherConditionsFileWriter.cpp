// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FE820
// Canonical corpus name: WeatherConditionsFileWriter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WeatherConditionsFileWriter_004fe820.c

void UnknownObject::WeatherConditionsFileWriter()
{
    // Writes a per-session weather-conditions report to a text file. Opens the file for the config path (unk_5C2AB0), writes a header, then for each of 8 session types writes the session name and the per-session weather duration, simulates the weather transition in 10.0-unit steps via AudioADSREnvelope, and iterates a linked list of weather data points (nodes chained at +12) printing minute, condition, ambient and track temperatures. Ends the file, closes it and returns 0, or logs a failure via DebugLogWrite and returns -1.
    // CALL: Open the output file for argument a2: sub_587DB0(a2, &unk_5C2AB0) returns a handle stored in v4. [callee:0x00587DB0, global:0x005C2AB0, source:raw]
    // GUARD: Branch on the open result: nonzero handle proceeds to the write path, zero goes to the error path returning -1. [source:raw]
    // CALL: Write the aWeather header token to the file. [callee:0x005887B1, global:0x005D7100, source:raw]
    // CALL: Write the asc_5C4060 separator/format token following the header. [callee:0x005887B1, global:0x005C4060, source:raw]
    // LOOP: Outer loop over the 8 session types: for (i = 0; i < 8; ++i). [source:raw]
    // CALL: Look up the session type name for index i via SessionTypeNameLookup(i, 0). [callee:0x0042CE30, source:raw]
    // CALL: Write the aS_3 session-name token. [callee:0x005887B1, global:0x005D70F8, source:raw]
    // CALL: Write the asc_5D70F4 separator token after the session name. [callee:0x005887B1, global:0x005D70F4, source:raw]
    // CALL: Obtain the per-session weather duration v10 from sub_4FB910(i). [callee:0x004FB910, source:raw]
    // ASSIGNMENT: Reset the weather data iterator: this[14] = this[15] (current pointer set to the iterator start held in this[15]). [field:this:0x00000038, field:this:0x0000003C, source:raw]
    // LOOP: Weather transition simulation loop: start v9 at 0.0 and step by 10.0 while v9 < v10. [source:raw]
    // CALL: Each simulation step calls AudioADSREnvelope(this, 10.0, v9, 0) to advance the weather state by one 10.0-unit interval. [callee:0x004FDEB0, source:raw]
    // CALL: Write the aConditions2f conditions format token. [callee:0x005887B1, global:0x005D70E0, source:raw]
    // CALL: Write the aOnpathwetness2 on-path wetness format token. [callee:0x005887B1, global:0x005D70C8, source:raw]
    // CALL: Write the aOffpathwetness off-path wetness format token. [callee:0x005887B1, global:0x005D70B0, source:raw]
    // CALL: Write the aAmbienttemp2f ambient-temperature format token. [callee:0x005887B1, global:0x005D709C, source:raw]
    // CALL: Write the aTracktemp2f track-temperature format token. [callee:0x005887B1, global:0x005D7088, source:raw]
    // ASSIGNMENT: Load the first weather data point: v8 = *(float **)(this[14] + 12), reading the next-node pointer of the current iterator node. [field:this:0x00000038, source:raw]
    // LOOP: Linked-list traversal: for (this[14] = v8; v8; this[14] = v8) walk the weather data points via the +12 next-node pointers. [field:this:0x00000038, source:raw]
    // GUARD: Stop the traversal when (*v8 - v10) * 0.016666668 > 150.0, i.e. the point is more than 150.0 scaled time units past the session duration. [source:raw]
    // CALL: Write the aMinute2f minute format token for the current data point. [callee:0x005887B1, global:0x005D7078, source:raw]
    // CALL: Write the asc_5D7070 separator token. [callee:0x005887B1, global:0x005D7070, source:raw]
    // CALL: Write the aConditions2f_0 per-point conditions format token. [callee:0x005887B1, global:0x005D705C, source:raw]
    // CALL: Write the aAmbienttemp2f_0 per-point ambient-temperature format token. [callee:0x005887B1, global:0x005D7044, source:raw]
    // CALL: Write the asc_5D703C per-point separator token. [callee:0x005887B1, global:0x005D703C, source:raw]
    // ASSIGNMENT: Advance to the next data point: v8 = *(float **)(this[14] + 12). [field:this:0x00000038, source:raw]
    // CALL: Write the asc_5D7038 token closing the per-session block. [callee:0x005887B1, global:0x005D7038, source:raw]
    // CALL: Write the asc_5D7034 token closing the whole file. [callee:0x005887B1, global:0x005D7034, source:raw]
    // CALL: Close the file via FileCloseWithLock(v4). [callee:0x00587D02, source:raw]
    // RETURN: Return 0 on successful write. [source:raw]
    // GUARD: Error path: if StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_9, 2102) is nonzero, log via DebugLogWrite(dword_8AD25C, aCouldNotWriteT, a2). [callee:0x004D7A50, callee:0x004D7AA0, global:0x008AD25C, global:0x005D7128, global:0x005D710C, source:raw]
    // RETURN: Return -1 on file-open failure. [source:raw]
    // CALL: Invoked by sub_4FCAA0 as part of the weather-condition save path. [caller:0x004FCAA0]

    // Conservative worker pseudocode:
    //   int sub_4FE820(void *this, const char *a2) {
    //     int h = sub_587DB0(a2, &unk_5C2AB0);
    //     if (!h) {
    //       if (StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_9, 2102))
    //         DebugLogWrite(dword_8AD25C, aCouldNotWriteT, a2);
    //       return -1;
    //     }
    //     StringFormatWithNestedIO(h, aWeather);
    //     StringFormatWithNestedIO(h, asc_5C4060);
    //     for (i = 0; i < 8; ++i) {
    //       SessionTypeNameLookup(i, 0);
    //       StringFormatWithNestedIO(h, aS_3);
    //       StringFormatWithNestedIO(h, asc_5D70F4);
    //       v10 = sub_4FB910((void *)i);
    //       this[14] = this[15];
    //       for (v9 = 0.0; v9 < v10; v9 += 10.0)
    //         AudioADSREnvelope(this, 10.0, v9, 0);
    //       StringFormatWithNestedIO(h, aConditions2f);
    //       StringFormatWithNestedIO(h, aOnpathwetness2);
    //       StringFormatWithNestedIO(h, aOffpathwetness);
    //       StringFormatWithNestedIO(h, aAmbienttemp2f);
    //       StringFormatWithNestedIO(h, aTracktemp2f);
    //       v8 = *(float **)(this[14] + 12);
    //       for (this[14] = v8; v8; this[14] = v8) {
    //         if ((*v8 - v10) * 0.016666668 > 150.0) break;
    //         StringFormatWithNestedIO(h, aMinute2f);
    //         StringFormatWithNestedIO(h, asc_5D7070);
    //         StringFormatWithNestedIO(h, aConditions2f_0);
    //         StringFormatWithNestedIO(h, aAmbienttemp2f_0);
    //         StringFormatWithNestedIO(h, asc_5D703C);
    //         v8 = *(float **)(this[14] + 12);
    //       }
    //       StringFormatWithNestedIO(h, asc_5D7038);
    //     }
    //     StringFormatWithNestedIO(h, asc_5D7034);
    //     FileCloseWithLock(h);
    //     return 0;
    //   }
    // UNRESOLVED: Five read-only float globals (flt_59E440, flt_59E5FC, flt_59E6F8, flt_59E9C0, flt_5ACB08) are listed in the packet facts but do not appear anywhere in the raw decompiled source; the fill's proposed roles (physics/clamp constants) are not verifiable from this function.
    // UNRESOLVED: this[17] (offset 0x44) and the pointed-to float at *(this+0x44)+0 appear only in the fill's field table, not in the raw source; their access is not visible in this decompilation.
    // UNRESOLVED: The +12 next-node pointer layout of the weather data linked list is inferred from call shape only.
    // UNRESOLVED: The meaning of sub_4FB910's return value (per-session weather duration) is inferred from how it is compared against node time values.
}
