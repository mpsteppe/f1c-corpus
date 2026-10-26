// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9C80
// Canonical corpus name: RangeWidthGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RangeWidthGetter_004b9c80.c

void UnknownObject::RangeWidthGetter()
{
    // Peeks the two end values currently held in the queue stored at this+0x0 via QueuePeek and returns their difference (second peeked value minus first), yielding the scalar range width the queue contents span. The caller set (TelemetryDisplaySwitch plus a thunk to this function) is consistent with a display helper that turns queued samples into a single width value.
    // CALL: Dereference the queue pointer v1 from this+0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Initialize the two peek output floats v4 and v3 to 0.0 before the peek call. [source:raw]
    // CALL: Call QueuePeek(v1, &v4, &v3) to read the two end values currently held in the queue; this is the function's only callee. [callee:0x004B87A0, source:raw]
    // CALCULATION: Compute the range width as v3 - v4 (second peeked value minus first). [source:raw]
    // RETURN: Return the computed difference as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   double rangeWidthGetter(void* this) {
    //     void* queue = *(void**)this;
    //     float a = 0.0f, b = 0.0f;
    //     QueuePeek(queue, &a, &b);
    //     return b - a;
    //   }
    // UNRESOLVED: QueuePeek argument order and which end (head/tail) each output represents are not evidenced, so the signed meaning of v3 - v4 is a DERIVED label.
    // UNRESOLVED: The element type and units of the queued values, and therefore the physical meaning of the returned width, are unknown; the TelemetryDisplaySwitch caller suggests a telemetry range widget.
    // UNRESOLVED: The prelabel action records a structural twin (the 00404f70 cluster representative), but the raw bodies differ in callee and return expression, so the cluster_copy label is not reflected in this source.
    // UNRESOLVED: this+0x0 is read as a queue pointer with no field-name evidence beyond the read itself.
}
