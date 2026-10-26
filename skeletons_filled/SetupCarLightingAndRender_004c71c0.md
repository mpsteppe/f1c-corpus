## SetupCarLightingAndRender_004c71c0 — Vehicle Telemetry Packet Encoder

> **PROSE CORRECTED 2026-07-24.** `this+0x105D` is **DriverModelVisible**
> (1 = driver drawn, 0 = hidden), not a generic "car subsystem status indicator".
> This function re-encodes it into bit `0x8000000` of the outgoing packet word;
> `VehiclePhysicsTimeStep_004c73f0` decodes it back. Poke-proven on M. SALO.
> Detail: `mods/ai_pit_retire/RETIRE_SOLVED_2026-07-24.md`.


**Summary:** Encodes per-vehicle physics state (throttle, brake, RPM, gear, steering, suspension positions, temperatures, flags) into a bitfield-packed telemetry packet for rendering/network transmission. Reads car state fields and packs them via a series of encoding subroutines into a DWORD array output buffer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitTimingUpdate (004b7a90), TireTemperatureSimStep (004c77d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x73C | R | — | car body position/offset X (world-space) |
| this | 0x105D | R | — | boolean flag: car subsystem status indicator (bit 7 at offset) |
| this | 0x1067 | R | — | boolean flag: another subsystem ready/active flag |
| this | 0x1069 | R | — | boolean flag: third subsystem flag |
| this | 0x344C | R | — | flag byte: bitfield for vehicle state (checked at bit 0x8) |
| this | 0x357C | R | — | ThrottleFactor [CONFIRMED] |
| this | 0x3580 | R | — | clutch engagement factor (read alongside throttle/brake) |
| this | 0x3584 | R | — | BrakeFactor [CONFIRMED] |
| this | 0x35BC | R | — | damping/suspension reference value |
| this | 0x39A0 | R | — | EngineRPM [CONFIRMED] |
| this | 0x39FC | R | — | CurrentGear [FACT] (also: gearNumber) |
| this | 0x4024 | R | — | vehicle speed or velocity magnitude (used with steering) |
| this | 0x4028 | R | — | steering angle or lateral acceleration value |
| this | 0x4894 | R | — | per-wheel suspension position value (offset by wheel index in loop) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b2310 | sub_4B2310 | encodes 3D position/offset vector into packet |
| 004b2480 | UtilityFunction_2480 | encodes float value into 16-bit short field in packet |
| 004b25d0 | FloatToFixedConversionWithClamp | converts float to fixed-point with clamp, writes to packet |
| 004b2750 | FloatToShortClampedConversion | converts float to clamped 16-bit short |
| 004b2840 | FloatToByteShortEncoding | encodes a float + offset into byte/short pair in packet (per-wheel) |
| 004b2930 | FloatToBitfieldPack | packs a single float value into a bitfield slot in packet |
| 004b29b0 | BitfieldInsert | inserts a float value into a specific bitfield position |
| 004b2a10 | ShortComputation_2a10 | writes a DWORD value into packet with bit manipulation |
| 004b2a40 | FloatToBitfieldEncoder | encodes float into bitfield with shift/mask |
| 004b2aa0 | BitfieldSetClearByIndex | sets or clears a specific bit by index in packet |
| 004b2ae0 | sub_4B2AE0 | final packet encoding/closing subroutine |
| 004b2b10 | FunctionCallWrapper_2b10 | writes a float value into packet with specific encoding |
| 004b2b60 | BitfieldSetter | sets a bitfield value in packet from a DWORD source |
| 004b33b0 | ProgressBarEventEncode | encodes a progress/timing event marker into packet header |
| 004c7c00 | Constant5 | returns a constant or computed value for packet encoding |
| 004e18c0 | SubsystemReadyQuery | queries whether a subsystem index is ready (returns boolean) |

**Guard conditions:** No early-return guards — the function always encodes the full packet. However, individual bitfields are conditionally set/cleared based on flags: this+0x105D (subsystem flag) controls bit 0x80 in packet[11]; this+0x344C flag controls bit 0x28 in packet[12]; this+0x1067 flag controls bit 0x2000000 in packet[12]; this+0x1069 flag controls bit 0x80000000 in packet[12]; this+0x4024 flag controls bit 0x1000000 in packet[12]; velocity threshold (>0.01) controls bit 0x4000000 in packet[12].