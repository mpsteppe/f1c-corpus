## LapSplitTimeEvent_004bc390 — LapSplitTimeEvent

**Summary:** Processes lap/split timing events with state-dependent routing. Early-returns if a ride-height threshold exceeded; validates current state against expected state for event type (0→expect state 2, 1→expect state 0, 2→expect state 1); computes intersection time delta; encodes event data into ring buffer; records lap completion.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TimerFrameRateThrottle (004d3740)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | flag-property bitmask checked via FlagPropertyGetter |
| this | 0x0 | R | — | pointer to parent structure (used to check container+13000 for recording gate) |
| this | 0x4 | R | — | event parameter 1 (used in ProgressBarEventEncode) |
| this | 0x8 | R | — | event parameter 2 (used in LapCompletion call) |
| this | 0xC | R | — | current lap/sector state (0/1/2), compared against expected state for event type |
| this | 0x60 | R | — | split-time mode flag (if == 2 use delta from this[25], else delta = -1.0) |
| this | 0x64 | R | — | previous split time (float, subtracted for delta when mode == 2) |
| this | 0xB0 | R | — | ride-height threshold (if > 10.0, early return) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059eb48 | dbl_59EB48 | R | RideHeightThreshold [DERIVED] |
| 0083ee60 | dword_83EE60 | RW | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |
| 008ad238 | dword_8AD238 | R | ScoringGateOpen [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b33b0 | ProgressBarEventEncode | encodes lap/split event into ring buffer entry |
| 004bc340 | sub_4BC340 | validation gate — returns truthy if event should be processed |
| 004bc4e0 | LapCompletion | records lap completion with delta time and event type |
| 004d5900 | EncodedDataWriterWithXOR | writes XOR-encoded timing data when recording gate is open |
| 004efbd0 | RayTriangleIntersectionWithBarycentricCoordinate | computes intersection point for split-line crossing |
| 0054c150 | FlagPropertyGetter | retrieves property flags from event object with mask 2048 |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC | == | 2 | current state must be 2 when event type = 0 |
| this | 0xC | == | 0 | current state must be 0 when event type = 1 |
| this | 0xC | == | 1 | current state must be 1 when event type = 2 |
| this | 0x60 | == | 2 | split time delta mode: compute delta if 2, else use -1.0 |

**Guard interpretation:** PASSES when ride-height <= 10.0 AND (event type 0 AND state==2, OR type 1 AND state==0, OR type 2 AND state==1) AND sub_4BC340 returns true. BLOCKED when ride-height > 10.0, or state doesn't match expected, or sub_4BC340 returns false.
