// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00458050
// Canonical corpus name: sub_458050
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_458050_00458050.c

void UnknownObject::TrackControlPointLoader()
{
    // Parses control-point records from a structured file stream. Iterates a dispatch/read loop, extracting "ControlPoint" entries (3 coordinate dwords into v8/v9/v10) into a local buffer up to 20 points. With 4+ points collected, calls sub_457F90 to allocate/initialize the keyframe array. Returns 1 on parse failure or insufficient points, otherwise the sub_457F90 result.
    // GUARD: If ConditionalDispatchBasedOnFlag(v18, 384) reports no records on the first call, return 1 immediately. [callee:0x00566CC0, source:raw]
    // LOOP: Dispatch loop over the file stream; repeats while ConditionalDispatchBasedOnFlag(v18, 384) returns true. [callee:0x00566CC0, source:raw]
    // CALL: sub_5651B0(v12) reads the next record from the stream buffer; status 0 means data, 2 or 4 means end of stream. [callee:0x005651B0, source:raw]
    // GUARD: When the read status is 2 or 4, break out of the dispatch loop (end of stream). [source:raw]
    // CALL: sub_565870(aControlpoint, &v8, &v9, &v10, 0, 0, 0, 0, 0) parses a record matching the aControlpoint label, extracting 3 coordinate values into v8/v9/v10. [callee:0x00565870, global:0x005C5A70, source:raw]
    // ASSIGNMENT: When a ControlPoint parses successfully and the collected count is below 20, store v8/v9/v10 as the next 3 dwords of the v19 buffer and increment the count. [source:raw]
    // GUARD: After the loop, if fewer than 4 control points were collected, return 1. [source:raw]
    // CALL: sub_457F90(v11, v19, v2) allocates/initializes the keyframe array from the collected control points; its return value becomes the function result. [callee:0x00457F90, source:raw]
    // RETURN: Returns 1 on early failure or insufficient points; otherwise returns the sub_457F90 result. [source:raw]

    // Conservative worker pseudocode:
    //   if (!ConditionalDispatchBasedOnFlag(v18, 384)) return 1;
    //   do {
    //     status = sub_5651B0(v12);
    //     if (status == 0) {
    //       if (sub_565870(aControlpoint, &v8, &v9, &v10, 0, 0, 0, 0, 0) && count < 20) { store v8,v9,v10; count++; }
    //     } else if (status == 2 || status == 4) {
    //       break;
    //     }
    //   } while (ConditionalDispatchBasedOnFlag(v18, 384));
    //   if (count < 4) return 1;
    //   return sub_457F90(this, v19, count);
    // UNRESOLVED: Exact wire semantics of sub_5651B0 record status codes other than 0/2/4 not established.
}
