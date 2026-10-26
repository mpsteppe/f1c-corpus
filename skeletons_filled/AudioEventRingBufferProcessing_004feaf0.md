## AudioEventRingBufferProcessing_004feaf0 — Audio Event Ring Buffer Processor

**Summary:** Processes a ring buffer of timed audio events, computing ADSR envelopes across 720 time slots, detecting peaks above noise thresholds, and spawning sorted linked-list nodes for audio events to be played. Uses weather noise and track conditions to randomize event timing and intensity.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCC30 (004fcc30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x54)+0x4)+0x4) | 0x4 | R | — | second linked-list node's next pointer (read during merge sort) |
| *(*(this+0x54)+0x4) | 0x4 | RW | 0 | first linked-list node's next pointer (cleared during split, then reassigned during merge) |
| *(this+0x3C) | 0x8 | R | — | input audio event: amplitude/volume level (float at event+8) |
| *(this+0x54) | 0x4 | R | — | first linked-list node pointer (head of event list, checked for NULL) |
| *(this+0x58) | 0x4 | RW | — | tail node's next pointer (last node in list, updated on append) |
| this | 0x0 | R | — | base frequency/scale factor (float, used to compute ADSR envelope input range) |
| this | 0x4 | RW | 0 | processing counter (DWORD, reset to 0 at start of ring buffer pass) |
| this | 0x24 | R | — | base amplitude reference level (float at this+36, used as offset for envelope values) |
| this | 0x38 | RW | — | ring buffer head pointer (DWORD, set to current input event at start) |
| this | 0x3C | R | — | input audio event pointer (DWORD, source event with timing/amplitude data) |
| this | 0x54 | RW | — | linked-list first node pointer (this+84, head of output event list) |
| this | 0x58 | RW | — | linked-list last node pointer (this+88, tail of output event list for O(1) append) |
| this | 0x5C | RW | — | linked-list root pointer (this+92, set along with first node on initial allocation) |
| this | 0x60 | R | — | linked-list node count (this+96, incremented on each node allocation) |

**Written-by note (persistence):**
- *(*(this+0x54)+0x4) 0x4: recomputed when event list is rebuilt — external poke persists until next rebuild
- *(this+0x58) 0x4: recomputed when event list is rebuilt — external poke persists until next rebuild
- this 0x4: recomputed when ring buffer is processed — external poke persists until next processing pass
- this 0x38: recomputed when ring buffer is processed — external poke persists until next processing pass
- this 0x54: recomputed when ring buffer is processed — external poke persists until next processing pass
- this 0x58: recomputed when ring buffer is processed — external poke persists until next processing pass
- this 0x5C: recomputed when ring buffer is processed — external poke persists until next processing pass

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e454 | flt_59E454 | R | PhysicsConstant_59E454 [DERIVED] |
| 0059e458 | flt_59E458 | R | ConstraintForceEpsilon [DERIVED] (also: ` — constraint force threshold (near-zero) |
| 0059e470 | flt_59E470 | R | TrackNodeSearchRadiusSq [DERIVED] |
| 0059e4e0 | flt_59E4E0 | R | ForceIncrementClamp [DERIVED] (also: ` — scroll auto-repeat threshold (delta time gate) |
| 0059e5fc | flt_59E5FC | R | FrameRateCorrectionFactor [DERIVED] (also: ` â€” global frame-rate correction) |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e80c | flt_59E80C | R | PitlaneTimeThreshold [DERIVED] |
| 0059e8b4 | flt_59E8B4 | R | ClampUpperThreshold [DERIVED] |
| 0059e8cc | flt_59E8CC | R | WheelSpeedThreshold [DERIVED] (also: ` — wheel speed threshold (not in docs/12) |
| 0059e940 | flt_59E940 | R | Flt_PhysicsLimit_9E940 [DERIVED] |
| 0059ef64 | flt_59EF64 | R | HeadlightRangeFactor [DERIVED] |
| 005acb3c | flt_5ACB3C | R | PitDensityThreshold [DERIVED] |
| 005acd3c | flt_5ACD3C | R | AeroDragCoefficient [DERIVED] (also: ` — aero constant) |
| 005acd94 | flt_5ACD94 | R | Flt_AiAudioFreqGain_CD94 [DERIVED] |
| 005ad144 | flt_5AD144 | R | DeformationOffsetConst [DERIVED] (also: � offset constant for deformation) |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 007cf8cc | flt_7CF8CC | R | TrackGripNoiseAmp [DERIVED] |
| 007cf8f0 | flt_7CF8F0 | R | RainIntensityFactor [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004fde00 | sub_4FDE00 | processes a single audio event (prepares timing/amplitude from event data) |
| 004fdeb0 | AudioADSREnvelope | computes ADSR (Attack-Decay-Sustain-Release) envelope value for a time slot |
| 004ff2b0 | sub_4FF2B0 | extracts a sub-list from linked list for merge sort (splitting operation) |
| 00587c03 | OperatorNewNhMallocWrapper | wrapper for operator new / heap allocation (allocates 12-byte audio event nodes) |

**Guard conditions:** 
- `*(_DWORD *)(this + 60)` (this+0x3C): If input event pointer is NULL, return immediately — no audio events to process.
- `v6` (loop result): If no positive envelope values found in any of the 720 time slots after ADSR computation, return early — no audible events.
- `v48 > 0.0 && v50 < 300.0`: Peak detection gate — a time slot must have a positive envelope peak AND be within 300ms distance to trigger event spawn. If either fails, skip to next slot.
- `v13 < 0.12 - v45 * 0.06`: Weather noise gate — random value from trig lookup table must be below a threshold (adjusted by distance factor) to allow event creation. BLOCKED if noise is too high.
- `v46 > 0.0`: Computed intensity must be positive. If <= 0, skip event creation. If > 1.0, clamp to 1.0.
- `v16 < flt_7CF8CC - v52`: Track grip noise gate — random value must be below (track grip noise amp - distance offset) for primary event spawn.
- `v20 < flt_7CF8F0 - v52`: Rain intensity gate — random value must be below (rain intensity - distance offset) for secondary event spawn.
- Merge sort: If node count >= 2, split list at midpoint and merge two sorted halves.
