# Session and Race Logic
## FUN_004b3b30 — SessionDataCopy

Source: unknown. Copies a single int from +0x6c008 to +0x6c00c in session structure.

**Key logic:**
- Copies value at param_1+0x6c008 to param_1+0x6c00c

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x6c008 | SourceValue | int |
| +0x6c00c | DestValue | int |

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004ed220 — PhysicsTimeStep

Source: unknown. Advances physics simulation by given time step.

**Key logic:**
- Calls FUN_004ed0f0(param_2) — update physics base
- If param_1+0x32bc == 0 (no override flag):
  - Calls FUN_0043ec50((double)param_2) — update sub-system with float->double time step

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x32bc | OverrideFlag | int, skips sub-system update when non-zero |

**Calls:** FUN_004ed0f0 (physics base step), FUN_0043ec50 (sub-system step)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0052de00 — NetworkColorIsDefault

Source: unknown. Checks if a color value matches the default/empty color via hash.

**Key logic:**
- Reads color from param_1+0x24a4 (if non-null use deref) or param_1+0x24f0 (fallback)
- Byte-swaps color from RGBA to ARGB: (color>>24 | (color&0xff0000)>>8 | (color&0xff00)<<8 | color<<24)
- Calls FUN_0052da30 with swapped color
- Returns TRUE if FUN_0052da30 returns -1 (not found / default)

**Called by:** network team color validation

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x24a4 | ColorPtr | uint*, pointer to color (nullable) |
| +0x24f0 | ColorFallback | uint, direct color value |

**Calls:** FUN_0052da30 (color hash/lookup, returns -1 for default)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054fb40 — SceneNodeVisibilityToggle

Source: unknown. Toggles scene node visibility flag.

**Key logic:**
- Gets node struct from param_1+0x204
- If param_2 != 0: ORs bit 0x40 into node flags (+0x14) — show
- If param_2 == 0: ANDs out bit 0x40 — hide

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x204 | NodePtr | pointer to node struct |
| Node+0x14 | NodeFlags | uint, bit 0x40 = visible |

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e2370 — MultiplayerSessionType

Source: unknown. Sets multiplayer session type flag and triggers init.

**Key logic:**
- Sets param_1+0xb6c = 0 (default)
- If param_2 == 4: set +0xb6c = 1, call FUN_004e23ad()
- If param_2 == 5: set +0xb6c = 2, call FUN_004e23ad()
- If param_2 == 6: set +0xb6c = 3, call FUN_004e23ad()
- Otherwise: call FUN_0059db09() (unknown fallback)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xb6c | SessionTypeFlag | byte (0=default, 1=type4, 2=type5, 3=type6) |

**Calls:** FUN_004e23ad (session init), FUN_0059db09 (fallback)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_005124de — PacketFieldEncoding

Source: unknown. Encodes/packs network/replay packet fields based on flag bits.

**Key logic:**
- Reads flag bytes at param_1+0x60, 0x61 (bitfield of fields to pack)
- Checks bit 0x10 at param_1+0x61 (flags field present):
  - If param_2+0x19 == 3: sets to (param_1+0x10a != 0)*4 + 2 (convert boolean to flag value)
  - Else if param_1+0x10a != 0: ORs 4 into field
  - Sets header byte param_2+6 = 8
- If bit 0x20 at param_1+0x61: copies int from param_1+0x130 to param_2[10]
- If bit 0x04 at param_1+0x61 AND param_2[6]==0x10: sets param_2+6 = 8
- Checks bit 0x40 at param_1+0x60:
  - If state is 2 or 6 AND param_1+0x174 != 0 AND header == 8: sets state = 3
- If bit 0x04 at param_1+0x60 AND header < 8: sets header = 8
- Computes field descriptor at param_2+0x1d:
  - State 3 or (state&2)==0: descriptor = 1
  - Else: descriptor = 3
  - If state & 4: descriptor += 1
  - If bit 0x80 at param_1+0x61 AND state is 0 or 2: descriptor += 1
- Computes encoded size = descriptor * header, size_in_bytes = (size + 7) >> 3

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| param_1+0x60 | FieldFlags0 | byte, bitfield for encoding |
| param_1+0x61 | FieldFlags1 | byte, bitfield for encoding |
| param_1+0x10a | BoolFlag | short |
| param_1+0x130 | IntField | int |
| param_1+0x174 | FlagField | int |
| param_2[6] | HeaderByte | encoded header |
| param_2[10] | IntPayload | int field |
| param_2+0x16 | ZeroField | short, always cleared |
| param_2+0x19 | StateValue | byte |
| param_2+0x1d | DescriptorSize | byte |
| param_2+0x1e | EncodedSize | byte |

**Calls:** none

**Moddability:** hardcoded — fixed bit positions

<!-- target: docs/06-session-race-logic.md -->

## FUN_004a5e10 — SessionTransitionDispatch

Source: unknown. Dispatches session transition based on current state.

**Key logic:**
- Reads param_1+0x184 (current session state)
- If 0 or 4: calls FUN_004a5c80(1) — transition to next mode
- If 1: calls FUN_004a5c80(0) — transition to previous/menu
- If anything else: return (no action)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x184 | SessionState | int (0=idle, 1=active, 4=finished) |

**Calls:** FUN_004a5c80 (session transition, param 0=end, 1=continue)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c77d0 — TireTemperatureSimStep

Source: unknown. Steps tire temperature/suspension simulation with wear effects.

**Key logic:**
- Guard: if param_1+13000 is 0 or 1 (session mode), continue; else return
- Calls FUN_00461db0() — check if tire model is active
- If active:
  - Compares tire temp (param_1+0x48b8) against DAT_0059e440 (zero) and _DAT_0059e7ec (threshold)
  - If temp >= 0: if temp > _DAT_0059e7ec: reset to 5.0f (0x40a00000)
  - If temp < 0: set to 0.0
  - Subtracts _DAT_008afe90 (cooling factor) from temp
  - If temp drops <= 0: early return
  - Calls FUN_00462ff0 with TeamID (param_1+0x4894) and -1.0f (0xbf800000) — tire grip curve
  - Clamps result to [-grip, grip] range
- Globals check for session state:
  - If DAT_0083ee60 > 0x3fe (global step counter > 1022):
    - Calls FUN_004c71c0 with DAT_008aae64 (tire wear pointer)
    - Calls FUN_004ef2e0() — advance simulation
  - Else: increments DAT_0083ee60, adds 0x1b0 to DAT_008aae64, then processes

**Globals:**
- `DAT_0059e440` — zero constant
- `_DAT_0059e7ec` — temperature threshold (max before reset)
- `_DAT_008afe90` — cooling rate per frame
- `DAT_0083ee60` — global frame step counter
- `DAT_008aae64` — tire wear data pointer (advances by 0x1b0 per frame)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4894 | TeamID | int |
| +0x48b8 | TireTemp | float |
| +13000 | ModeFlag | int |

**Calls:** FUN_00461db0 (tire model active check), FUN_00462ff0 (tire grip curve by team), FUN_004c71c0 (tire wear simulation), FUN_004ef2e0 (physics advance)

**Moddability:** configurable — cooling rate _DAT_008afe90, temp threshold _DAT_0059e7ec, reset value 5.0f

<!-- target: docs/06-session-race-logic.md -->

## FUN_005078b5 — VertexColorFloatToByte

Source: unknown. Converts float RGBA vertex colors to packed bytes with brightness scaling.

**Key logic:**
- If param_1+0x1048 != 0: calls FUN_00506ce2(param_4) — transform color matrix
- Iterates param_1+0x1058 vertices (stride 0x10 = 16 bytes per input):
  - Reads float color from table at param_1+0x2c, indexed by (param_3&3) + (param_2&3)*8 + (idx&3)
  - Adds scaled transform color: param_4[n] * DAT_0059fec8 (brightness/gamma)
  - Outputs 3 bytes (BGR) per vertex
- Uses extraout_EDX as output pointer register

**Globals:**
- `DAT_0059fec8` — brightness/gamma scale factor

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x02c | ColorTable | float*, indexed by position in patch |
| +0x1048 | ColorTransformFlag | int, non-zero = apply matrix |
| +0x1058 | VertexCount | int |

**Calls:** FUN_00506ce2 (color transform), FUN_00507473 (init/start)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00519720 — AudioStreamBufferFill

Source: unknown. State-machine driven audio streaming buffer fill (double-buffered).

**Key logic:**
- State 0 (init): if +0x30 == 0:
  - Checks if vtable at param_1+0x184 method +0xc returns 0 (no data) → early return
  - Increments +0x4c (buffer counter)
  - Sets +0x30 = 1 (ready)
- State check on +0x44:
  - If == 1: goes to normal fill (LAB_004197cd)
  - If == 2:
    - Calls vtable method at param_1+0x188 +4 (fill function with position, size, callback params)
    - If position+0x34 < size+0x48: still filling → return
    - Sets +0x44 = 0 (done)
    - If param_4 <= *param_3: return (all data transferred)
  - If > 2: return
- Normal fill:
  - Resets position (+0x34 = 0)
  - Sets size (+0x48) = param_1+0x114 - 1 (buffer size)
  - If +0x4c (counter) == param_1+0x118 (total transfers): calls FUN_00519622 (stream complete)
  - Sets +0x44 = 1 (filling)
- LAB_004197cd:
  - Calls fill vtable method
  - If position >= size:
    - If counter == 1: calls FUN_0051954e (start of stream)
    - Toggles buffer index at +0x40 (xor 1 = double buffer swap)
    - Sets +0x30 = 0 (not ready)
    - Sets position = param_1+0x114 + 1 (reset position past end)
    - Sets size = param_1+0x114 + 2 (reset size)
    - Sets +0x44 = 2 (buffer switch)

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x030 | ReadyFlag | byte, 0=needs init, 1=ready |
| +0x034 | Position | uint, current read position |
| +0x038 | SourcePointer | ptr, varies by buffer index |
| +0x040 | BufferIndex | uint, double-buffer toggle (xor 1) |
| +0x044 | FillState | int (0=idle, 1=filling, 2=buffer switch) |
| +0x048 | BufferSize | uint |
| +0x04c | BufferCounter | int, tracks completed fills |
| +0x114 | BufferSizeBase | int, buffer size reference |
| +0x118 | TotalBuffers | int |
| +0x180 | StreamPtr | pointer to stream state |
| +0x184 | VtableDecoder | vtable, method +0xc = data available check |
| +0x188 | VtableFiller | vtable, method +4 = buffer fill |

**Calls:** FUN_00519622 (stream complete), FUN_0051954e (stream start), indirect vtable calls

**Moddability:** hardcoded — double-buffer hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054d030 — SceneNodeChildrenClear

Source: unknown. Clears all child nodes when a dirty flag is set.

**Key logic:**
- Checks if bit 0x8000000 at param_1+0x14 is set
- If set: iterates param_1+0x118 child nodes at stride 0x40, calls FUN_00540cb0 on each
- Clears bit 0x8000000 after processing
- Returns 0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x014 | Flags | uint, bit 0x8000000 = children dirty |
| +0x118 | ChildCount | int |
| +0x11c | ChildArrayPtr | ptr, stride 0x40 |

**Calls:** FUN_00540cb0 (clear/release child node)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054e100 — PackedArrayTotalSize

Source: unknown. Sums sizes of all records in a packed array.

**Key logic:**
- Iterates records at param_1+0x11c (stride 0x10 between sizes)
- Sums int at offset +8 of each record
- Returns total count

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x118 | RecordCount | int |
| +0x11c | RecordArrayPtr | ptr to records, each has int at +8 |

**Calls:** none

**Moddability:** hardcoded

**Key logic:**
- Iterates records at param_1+0x11c (stride 0x10 between sizes)
- Sums int at offset +8 of each record
- Returns total count

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x118 | RecordCount | int |
| +0x11c | RecordArrayPtr | ptr to records, each has int at +8 |

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00541810 — SoundInstanceUpdate

Source: unknown. Updates a set of active sound effect instances with new parameters.

**Key logic:**
- Guard: returns if param_1[0x4f6] == 0 (no sound system)
- If param_1[0x557] > 0 (existing instances): 
  - Iterates through instance IDs at param_1[0x558+], calls vtable method at [param_1[0x440]]+0xb8 (setter) with each ID
  - Sets *param_1 = vtable result
- Sets instance count to param_2
- If param_2 > 0 (new instances):
  - Reads new instance IDs from param_3[0] (stride 0xe = 14 bytes between entries)
  - Calls vtable method with each ID and flag 1 (activate)
  - Sets *param_1 = vtable result

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x000 | AudioResult | undefined4, stores last op result |
| +0x4f6×4 | SoundSystemPtr | int, null guard |
| +0x440×4 | SoundSystemVtable | int, vtable pointer |
| +0x557×4 | InstanceCount | int |
| +0x558×4 | InstanceIDs[] | int array of sound IDs |

**Called by:** audio management code

**Calls:** indirect vtable call at [param_1[0x440]]+0xb8 (set sound instance param)

**Moddability:** hardcoded — stride 0xe between param_3 entries

<!-- target: docs/06-session-race-logic.md -->

## FUN_004a0ba0 — RaceFinishHandler

Source: unknown. Handles race finish / DNF logic for a driver.

**Key logic:**
- Calls FUN_00419c50(param_1) — update race state base
- If param_1+13000 == 0 (some mode flag) AND DAT_007ce814 == 0 (session active):
  - Calls FUN_0040cde0(5, 1) — steward notification
  - Calls FUN_004ef5a0(1, 0) — timing freeze
  - If FinishPosition (+0x4060) != 1 (not first place):
    - Gets player index via FUN_004d1b50(0)
    - Checks SeasonScoringDB at DAT_005f073c + index*0x48c0: first int == 1 (season active)
    - Checks if (raceTime + _DAT_008acf90) - _DAT_008afea0 > _DAT_0059f118 (time threshold exceeded)
    - Checks DAT_008ad298 != 0x13 (not in qualification mode)
    - If all true: calls FUN_004a0c60() — advance to next session
- If FinishPosition == 1 (first place/won):
  - Calls FUN_004d8760(0x13, 0) — play winner fanfare/celebration

**Globals:**
- `DAT_007ce814` — session active flag
- `DAT_005f073c` — SeasonScoringDB base (stride 0x48c0)
- `DAT_0059f118` — race time threshold
- `_DAT_008acf90` — RaceTimeOffset
- `_DAT_008afea0` — start time offset
- `DAT_008ad298` — session mode (0x13=qualifying)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4060 | FinishPosition | int (1=winner) |
| +13000 | ModeFlag | int, 0=active |

**Calls:** FUN_00419c50 (update race state), FUN_0040cde0 (steward notify), FUN_004ef5a0 (timing freeze), FUN_004d1b50 (get player index), FUN_004a0c60 (advance session), FUN_004d8760 (fanfare)

**Moddability:** hookable — finish position check at +0x4060

<!-- target: docs/06-session-race-logic.md -->

## FUN_0050a223 — VertexUnpackRGBA

Source: unknown. Unpacks vertex color data from packed char+byte to float RGBA.

**Key logic:**
- Computes source pointer from param_1+0x1050 * param_2 + param_1+0x1054 * param_3 + param_1+0x18
- Computes end from source + param_1+0x1058 * 4
- For each 4-byte input (signed char RGB + byte A):
  - RGB converted to float and scaled by _DAT_0059e774 (1/127 or similar)
  - Alpha = byte * _DAT_0059e460 (1/255)
  - Output: 4 floats per vertex (RGBA), Z=0.0
- If param_1+0x10 != 0: calls FUN_00507845 with last output pointer

**Globals:**
- `_DAT_0059e774` — RGB scale factor (likely 1/127 or 0.007874)
- `_DAT_0059e460` — Alpha scale factor (likely 1/255)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x010 | HasPostProcess | int, flag |
| +0x018 | VertexBase | base pointer |
| +0x1050 | StrideX | int stride |
| +0x1054 | StrideY | int stride |
| +0x1058 | VertexCount | int |

**Calls:** FUN_00507845 (post-process colors)

**Moddability:** hardcoded — Z forced to 0.0

<!-- target: docs/06-session-race-logic.md -->

## FUN_00541b70 — CameraProjectionUpdate

Source: unknown. Updates camera projection matrix parameters based on flags.

**Key logic:**
- If param_2 & 4 (update):
  - Calls FUN_0053ac70(2, 0) — lock/prepare
  - If param_2 & 0x10 == 0 (perspective mode):
    - Sets scale_x = ScreenWidth/focal_x, scale_y = ScreenWidth/focal_y
    - Computes depth ratio: near/(near-far) and depth offset
    - If (param_1+0x80 & 0x10) != 0: negates scale_x (mirror/flip)
  - Else (orthographic mode):
    - Sets scale_x = 0.2, scale_y = 0.2
    - Computes depth from near/far plane
  - Calls FUN_0055ca40(4, matrix) — apply projection matrix
- If param_2 & 2: calls FUN_0055ca40(2, param_1+0x15c) — apply view matrix
- If param_2 & 8: calls FUN_0055cc20(param_1) — apply viewport

**Globals:**
- `_DAT_0059e420` — screen width (float)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x004 | NearPlane | float |
| +0x008 | FarPlane | float |
| +0x01c | FocalX | float |
| +0x020 | FocalY | float |
| +0x080 | Flags | byte, bit 0x10=mirror |
| +0x15c | ViewMatrix | 4×4 matrix |

**Calls:** FUN_0053ac70 (lock matrix), FUN_0055ca40 (set matrix type), FUN_0055cc20 (set viewport)

**Moddability:** hardcoded — orthographic scale 0.2

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054e120 — PackedArrayIndexLookup

Source: unknown. Finds which variable-length record in a packed array contains a given position index, returning offset into that record's data.

**Key logic:**
- Iterates records at param_1+0x11c (array of stride 0x40)
  - Each record has size at offset +8, data-start offset at +0xc
- Accumulates sizes until finding the record containing param_2
- Returns: (param_2 - accumulatedSize) * 0x30 + recordDataPtr + recordOffset
- Returns 0 if param_2 exceeds total array size

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x118 | RecordCount | int |
| +0x11c | RecordArrayPtr | pointer to array, stride 0x40 |

**Each record (stride 0x40):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x08 | RecordSize | int |
| +0x0c | DataStart | int, offset for data |

**Called by:** many render/geometry functions (0x40e1f0, 0x40e2b0, 0x40e480, 0x4c9fb0, 0x4dd550, 0x4dd8f0, 0x4dd7c0, 0x4de610, 0x4e21d0, 0x4e2ad0, 0x4e2d00, 0x4ea040, 0x4ea970, 0x4fc170, 0x4fbd70)

**Calls:** none

**Moddability:** hardcoded — stride 0x30 for data elements

<!-- target: docs/06-session-race-logic.md -->

## FUN_00537f30 — BitstreamWriteBits

Source: unknown. Writes bits into a compressed bitstream buffer for network/replay serialization.

**Key logic:**
- Maintains a bit accumulator at param_1+0x16ab (ushort) with bits-left counter at param_1+0x16ad
- If bits-left > 13 (0xd): space to pack all bits without flush
  - ORs param_3 (shifted by bits-left) into accumulator
  - Writes 2 bytes to output buffer at (param_1+8)[param_1+0x14]
  - Decrements bits-left by 13
  - Stores remaining bits back in accumulator
  - Calls FUN_005397a0(param_2, 1) — flush/output callback
- Else (not enough room):
  - Accumulates param_3 into buffer
  - Increments bits-left by 3
  - Calls FUN_005397a0(param_2, 1) — flush without full output

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x008 | OutputBufferPtr | byte buffer |
| +0x014 | BufferPosition | int, current write offset |
| +0x16ab | BitAccumulator | ushort, bits waiting to write |
| +0x16ad | BitsRemaining | int, count of valid bits in accumulator |

**Calls:** FUN_005397a0 (flush byte to output stream)

**Moddability:** hardcoded — bit packing uses fixed 13-bit threshold

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042a780 — AIComputePassScore

Source: unknown. Computes AI overtaking/passing score for a vehicle against an opponent.

**Key logic:**
- Calls FUN_004e8ce0 with:
  - param_2+0x74 (opponent speed?), param_2+0x78 (opponent position?), param_2+0x70 (own speed?), threshold 0x41800000 (16.0f)
- Result is distance/speed-based passing difficulty score
- Multiplies by: param_1+0x4504 (passing bias add), param_1+0x4500 (passing bias mult)
- Multiplies by: param_1+0x4580 (aggression factor)
- Multiplies by: param_1+0x453c (track-specific cornering factor)
- Multiplies by: param_2+0x84 (opponent speed delta factor)
- Returns final score used for AI pass decision

**Struct offsets (param_1 — AI driver):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4500 | PassScoreBiasAdd | float |
| +0x4504 | PassScoreBiasMult | float |
| +0x453c | TrackCorneringFactor | float |
| +0x4580 | AggressionFactor | float |

**Struct offsets (param_2 — opponent):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x70 | OpponentSpeed | float |
| +0x74 | OpponentDistance | float |
| +0x78 | OpponentPosition | float |
| +0x84 | OpponentSpeedDelta | float |

**Called by:** FUN_00425920 (AI pass decision logic)

**Calls:** FUN_004e8ce0 (distance/speed score with threshold 16.0)

**Moddability:** configurable — bias/aggression factors could come from AI difficulty .svm

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042ae00 — AIClearStateFlags

Source: unknown. Clears all AI state flags for a vehicle.

**Key logic:**
- Zeroes 20 dwords (80 bytes) starting at param_1 + 0x4354
- Offset +0x4354 maps to AIStateFlags in vehicle struct (docs/13)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4354 | AIStateFlags | 80 bytes cleared to zero |

**Called by:** multiple AI functions (FUN_00423e80, 00424790, 00424b20, 00425670, 00425920, 00424e70, 00429470)

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0050a92d — VertexColorPackRGBto16

Source: unknown. Converts float RGB vertex colors to packed 16-bit format.

**Key logic:**
- Guard: returns if either buffer at param_1+0x108c or +0x1090 is null
- Reads input count from param_1+0x1070 (index), 0x1078 (count)
- Computes output pointer using stride at param_1+0x1080 and 0x1074, base at param_1+0x18
- For each vertex (stride 8 floats per input):
  - Transforms float RGB via 3x3 color matrix (_DAT_005adc00.._DAT_005adc14) plus bias (_DAT_0059e450)
  - Clamps results to [0, 255]
  - Packs into 16-bit values with channel bit shifts from param_1+0x1094, 0x1098
  - Output: two 16-bit words per vertex (RG + BA)
- Sets param_1+0x108c = 0 (dirty flag clear)

**Globals:**
- `_DAT_005adc00`–`_DAT_005adc14` — 3×4 color transformation matrix (float)
- `_DAT_0059e450` — color bias/offset

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x18 | OutputBufferPtr | base pointer for output |
| +0x1050 | InputStride | stride for input vertices |
| +0x1054 | OutputStride | stride for output |
| +0x106c | InputVertexArray | float[8] per vertex |
| +0x1070 | CurrentIndex | vertex index |
| +0x1078 | VertexCount | total vertices |
| +0x1080 | OutputRowStride | output row stride |
| +0x108c | InputBuffer | dirty flag (null check) |
| +0x1090 | OutputBuffer | output buffer |
| +0x1094 | ChannelBitShift0 | bit shift for channel 0/2 |
| +0x1098 | ChannelBitShift1 | bit shift for channel 1/3 |

**Calls:** none (pure math, no sub-calls)

**Moddability:** hardcoded — color matrix built into code

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042ec60 — AIStateBufferInitialize

Source: unknown. Initializes/resets vehicle AI state history buffers.

**Key logic:**
- Shifts data at param_1+0xc4: 4 groups of 11 dwords each, stride 0x40 (64 bytes) — each group overwritten by next (history shift)
- Shifts data at param_1+0xbc4: 55 dwords (0x37) at stride 0x40 — larger history buffer shift
- Sets 4 floats at +0x1ca8..+0x1cb4 to 0x3f000000 (0.5f) — interpolation/smoothing coefficients
- Sets *param_1 = 1 (initialized flag)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x000 | InitializedFlag | byte, set to 1 |
| +0x0c4 | HistoryBuffer1 | 4×11 dwords, stride 0x40 |
| +0xbc4 | HistoryBuffer2 | 55 dwords, stride 0x40 |
| +0x1ca8 | SmoothCoeff[4] | 4 floats, initialized to 0.5 |

**Calls:** none

**Moddability:** hardcoded — 0.5 smoothing coefficients

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0041fe00 — ConfigSectionSearchByKeyValue

Source: unknown (calls INI/config API functions 0x004cxxxx). Searches config file sections for entry with value == 10 whose key matches param_1 string.

**Key logic:**
- Gets section count via FUN_004c2990()
- Iterates sections in reverse order (last to first)
- For each section: gets entry count via FUN_004c1370()
- If first entry value == 10, reads next entry's string directly
- Otherwise iterates all entries, reads name via FUN_004c0a20(), checks if value == 10
- Compares entry name against input param_1 via FUN_00588410 (string compare)
- Returns index of matching section, or 0 if not found
- Buffer size 0x50 (80) for string reads

**Globals:** none

**Calls:** FUN_004c2990 (get section count), FUN_004c2850 (set section), FUN_004c1390 (get entry count), FUN_004c1370 (get entry count variant), FUN_004c0a80 (read string), FUN_004c0a20 (read entry name), FUN_00588410 (string compare)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051e6ec — ChecksumCompute_Type1

Source: unknown. Computes checksum over byte buffer using lookup-table S-box approach. Selected as CRC/checksum variant when type==1 in FUN_0051ea90.

**Key logic:**
- Reads block parameters from param_1 +0x64 (iVar3 = entry count), +0x1a4 (table base), +0x5c (block size)
- Outer loop: iterates param_4 times (number of data blocks)
- Inner loop: for each byte in block, looks up via 3 table arrays and sums into output
- Table structure: *(int *)(iVar4 + 0x18) is entry array, each entry has sub-tables at 0x40-byte stride
- Round counter at iVar4+0x30 cycles 0-15 (bitmask &0xf)
- Each output byte = sum of table lookups for each input byte
- Tables indexed by input byte value plus entry-specific offset

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x64 | EntryCount | int, number of parallel streams |
| +0x5c | BlockSize | int, bytes per block |
| +0x1a4 | TableBase | pointer to checksum context |

**Calls:** FUN_005159a8 (buffer init/reset)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051e65f — ChecksumCompute_Type0_3Stream

Source: unknown. Simplified checksum using 3 lookup tables with byte-interleaved input. Faster variant for type==0 with block size 3.

**Key logic:**
- Reads 3 lookup table pointers from *(param_1+0x1a4)->0x18 array
- Outer loop: param_4 iterations (data blocks)
- Inner loop: param_5 (block size) iterations
- Each output byte = table0[byte] + table1[byte+1] + table2[byte+2] from 3 input bytes at stride 1
- Tables indexed at iVar4, iVar5, iVar6 (3 consecutive ints from context)

**Calls:** none (pure computation)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042aca0 — AISpeedDeltaSetter

Source: unknown. Sets AI speed delta field on vehicle struct with bounds check.

**Key logic:**
- If param_2 is 0 or 1, writes it to param_1+0x454c (AISpeedDelta field)
- If param_2 == 1, additionally calls FUN_004a46f0(param_1, 1, 0) to enable related behavior
- Value is clamped: only 0 or 1 accepted

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x454c | AISpeedDelta | int (0 or 1), AI speed delta mode |

**Calls:** FUN_004a46f0 (enable AI behavior)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_005385e0 — HeapSiftDown

Source: unknown. Binary heap sift-down operation on priority queue. Restores heap property by moving element downward.

**Key logic:**
- Heap stored at param_1+0xb52 (int array), size at param_1+0x1446
- Elements compared via ushort values at param_2 + index*4
- Tiebreaker: byte at param_1+0x144e+index (higher byte wins)
- Starting from element param_3, compares with children at 2*i and 2*i+1
- If child has higher priority (lower ushort, or equal ushort with higher byte), swaps
- Continues until heap property restored or leaf reached
- Standard binary min-heap sift-down

**Calls:** none (pure computation)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042ac70 — AIStateFlagSetter

Source: unknown. Sets AI flag field on vehicle struct, 0 or 1 only.

**Key logic:**
- If param_2 is 0 or 1, writes to param_1+0x454c
- No other side effects

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x454c | AIFlag | int (0/1), AI state flag |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054fae0 — BufferEntryClear

Source: unknown. Clears buffer entry flags at 0x74-byte stride. Bulk or single entry.

**Key logic:**
- Reads buffer base from param_1+0x1e0
- If param_2 == 0x8000000: clears ALL entries (reset bit 0, zero offset +0x10 for each)
- Otherwise: clears single entry at index param_2 (stride 0x74)
- Clear: entry->flags &= ~1, entry->field10 = 0
- Entry count at buffer+4, entry array at buffer+8

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1e0 | BufferPtr | pointer to buffer header struct |

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0050a2b4 — VertexByteDecompress

Source: unknown. Decompresses byte-encoded vertex data to float array with uniform scale.

**Key logic:**
- Reads strides: param_1+0x1050 (strideX), +0x1054 (strideY), +0x1058 (strideZ)
- Start offset = strideX*param_2 + strideY*param_3 + base(+0x18)
- End = start + strideZ*4
- Scale factor from global _DAT_0059e774 (float)
- Each vertex: 4 bytes -> 4 floats (byte * scale)
- Output to param_4 array (groups of 4 floats)
- If param_1+0x10 != 0, calls FUN_00507845 post-process

**Globals:**
- `_DAT_0059e774` — vertex scale factor (float)

**Calls:** FUN_00507845 (vertex post-process)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004be340 — GridCellIterate

Source: unknown. Iterates 2D grid range from float parameters, clamped [0,7], calls cell render function.

**Key logic:**
- 4 float params converted to int via __ftol(), each clamped [0,7]
- Nested loop: row range (yStart..yEnd), col range (xStart..xEnd)
- Calls FUN_004bda20(param_1+0x934, param_2, param_3, param_4) per cell
- If any clamping occurred, calls FUN_004bda20 once extra for boundary
- Increments cell counter at param_1+0x934

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x934 | CellCounter | int, increments per call |

**Calls:** FUN_004bda20 (render/update grid cell)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054c410 — QueueResourceCleanup

Source: unknown. Frees/resets multiple resource lists and buffers. Cleanup/shutdown for a queue manager.

**Key logic:**
- Calls FUN_00545f40() (global pre-cleanup)
- Iterates array at param_1+0x11c (entries count at +0x118, stride 0x40)
- For each entry: calls FUN_00547710(release), zeros pointer, calls FUN_00540cb0(free)
- Walks linked list at param_1+0x13c: FUN_005511a0() + FUN_00587bcf(free) per node
- Frees block at param_1+0x110 (refcounted, loops iVar2 times calling FUN_004b0170())
- Frees block at param_1+0x144 via FUN_004b0170()
- Returns 0

**Calls:** FUN_00545f40, FUN_00547710, FUN_00540cb0, FUN_005511a0, FUN_00587bcf (free), FUN_004b0170 (free)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054e1a0 — IndexedTransformRead

Source: unknown. Reads 3 indexed transform matrices (or positions) from lookup table. Stride 0x24 per table entry, 0x30 per value block (3 floats each).

**Key logic:**
- Guard: param_2 must be < param_1+0x120 (table entry count)
- Table base at param_1+0x124
- Each entry at param_2*0x24: contains 3 ushort indices (puVar1[0], [1], [2]) and a pointer at puVar1+4
- Each index * 0x30 + *(*(pointer)+0xc) gives a 3-float block
- Copies 3 floats (0x30 bytes / 4 = 12) to each of 3 output params (param_3, param_4, param_5)
- Null output params are skipped

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054f7a0 — UIFocusChange

Source: unknown. Handles UI focus change between elements. Updates flags and calls through global vtable.

**Key logic:**
- Guard: param_2 != param_1 and buffer at param_1+0x1e0 exists
- Sets global _DAT_008c5f44 = 0
- Calls FUN_0054b570(0, param_1+0x204)
- Checks flag 0x20000000 at *(param_1+0x204)+0x14
- If not set: ORs it in, calls through DAT_008b8f24 vtable to update bounds (+0xdc to +0xe8 area)
- Sets DAT_008c5f40 = FUN_0054f710(param_3)
- Calls FUN_0054f5c0(param_2, param_3)

**Globals:**
- `DAT_008c5f44` — UI focus flag (cleared)
- `DAT_008c5f40` — set from FUN_0054f710
- `DAT_008b8f24` — UI vtable pointer

**Calls:** FUN_0054b570, FUN_0054f710, FUN_0054f5c0

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051a4b7 — ProtocolStateHandler

Source: unknown. Network/protocol state machine handler. Sets callback function pointer based on state flags.

**Key logic:**
- Reads context from param_1+0x184
- If context+0x10 != 0 (context active):
  - If param_1+0x49 != 0 (special flag) AND FUN_00519eb7() returns non-zero:
    - Sets function pointer at context+0xc to LAB_00519f9a
  - Otherwise sets to FUN_00519d51
- Clears param_1+0x88 = 0

**Calls:** FUN_00519eb7 (state check)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00508105 — ByteColorTransform

Source: unknown. Transforms float color data to byte array using lookup matrix. Texture/shader color conversion.

**Key logic:**
- If param_1+0x1048 != 0, preprocesses param_4 via FUN_00506ce2
- Reads float base from param_1+0x2c
- Calls FUN_00507473 (state setup)
- For each byte output (param_1+0x1058 count):
  - Rounds sum of: data from param_4 at stride 0x10, scaled by global DAT_0059fec8
  - Plus lookup from matrix at iVar1 indexed by (param_3 & 3) + (param_2 & 3)*8 + (uVar2 & 3)

**Globals:**
- `DAT_0059fec8` — float scale factor

**Calls:** FUN_00506ce2 (data preprocess), FUN_00507473 (state setup)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004dba00 — UIMessageCompose

Source: unknown. Composes UI message string from state flags and displays it.

**Key logic:**
- Checks FUN_0049b9a0() (pause state?): if true, adds byte 0x82
- Checks FUN_0049ba50(): if true, adds byte 0x44
- Checks FUN_0049ba30(): returns 1 -> adds byte 0x8c; returns 2 -> adds byte 0x8d
- Terminates byte array with 0
- Calls FUN_004d7e40(bytes, param_1+0x113, param_2, 0xffffff, 1, 3, DAT_005acf50, DAT_005acf54) to render text

**Globals:**
- `DAT_005acf50` — text render param
- `DAT_005acf54` — text render param

**Calls:** FUN_0049b9a0, FUN_0049ba50, FUN_0049ba30, FUN_004d7e40 (text render)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004a8b80 — StaticInitBulk

Source: unknown. Bulk static initialization calling constructors for subsystems. Large function with many repetitive init calls.

**Key logic:**
- Calls FUN_004c1700() (global init)
- Loops of 16x calls to FUN_004aa1b0() (4 times = 64 init calls)
- ~180+ individual calls to FUN_00414370()
- 0x2c (44) loop of FUN_00414370()
- 0x30 (48) loop of FUN_004aa1b0()
- ~200+ more FUN_00414370() calls
- 7x loops of FUN_004aa170() (varying patterns)
- FUN_00401030() calls to init arrays at struct offsets +0xcd0, +0xbd4, +0xad8, +0x9dc, +0x8e0, +0x7e4, +0x5b0 with sizes 0x18 or 0x24
- Many more FUN_004aa1b0() calls
- Concludes with FUN_004b2100()

**Calls:** FUN_004c1700, FUN_004aa1b0, FUN_00414370, FUN_004aa170, FUN_00401030, FUN_004b2100

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004a06e0 — SessionInit

Source: unknown. Initializes session state: sound, scoring, config loading.

**Key logic:**
- If DAT_005eb10c != null, calls its vtable+0xc method
- Calls FUN_004186a0() (sound system init)
- Calls FUN_004b0ef0(4) (memory/alloc init)
- Sets DAT_008ab6e4 = (DAT_007d0038 != 0) (ScoringGate from global)
- Sets DAT_005cc9e8 = 1
- Calls FUN_004c2810() (config system init)
- Sets DAT_007c5690 = 1
- If config sections exist: gets FUN_004c11c0() and calls FUN_0042cf10(data)
- Returns 0

**Globals:**
- `DAT_005eb10c` — sound system pointer
- `DAT_008ab6e4` — ScoringGate (docs/12)
- `DAT_007d0038` — global flag
- `DAT_005cc9e8` — init state
- `DAT_007c5690` — init state

**Calls:** FUN_004186a0, FUN_004b0ef0, FUN_004c2810, FUN_004c2850, FUN_004c11c0, FUN_0042cf10

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0053ce10 — ErrorHandlerSet

Source: unknown. Calls validation function and sets error flag (bit 3) on failure.

**Key logic:**
- Calls FUN_0053cbc0(param_1, param_2)
- If return 0 AND param_1 != null: sets bit 3 at *param_1 + 0x114

**Calls:** FUN_0053cbc0 (validation check)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_005439f0 — ShortFieldAccessor

Source: unknown. Reads 3 short fields from struct and writes as ints to output pointers.

**Key logic:**
- Reads short at param_1+0x18c -> writes to *param_2 (if non-null)
- Reads short at param_1+0x18a -> writes to *param_3 (if non-null)
- Reads short at param_1+0x188 -> writes to *param_4 (if non-null)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004352c0 — Plane-Line Intersection Ratio

Source: likely_collision_math.cpp. Computes parameter `t` for intersection of line with plane in 2D, handling degenerate axes.

**Key logic:**
- Takes P (param_1), D (param_2), Q (param_3), N (param_4) — point, direction, plane-point, normal
- If N.x (param_4[0]) == 0: handle x-degenerate case, compute t = (Q.x - P.x - (N.x/N.z)*(Q.z - P.z)) / (D.x - (N.x/N.z)*D.z)
- Else: compute alternative form with swapped axes
- If divisor fVar3 == 0: return infinity (DAT_0059eae0)
- Returns fVar4 / fVar3

**Globals:**
- `DAT_0059e440` — 0.0f constant
- `DAT_0059eae0` — infinity/FLT_MAX return value

**Calls:** none

**Moddability:** hardcoded — pure math utility.

## FUN_00541340 — Texture/Surface Allocation

Source: likely_renderer_d3d.cpp. Allocates and initializes a graphics surface/container with two sub-buffers.

**Key logic:**
- operator_new(0x4c) allocates 76 bytes
- Structure: first dword = 2 (count of sub-buffers), rest = two arrays of 9 dwords each, zeroed
- Sets values: 0x22 (34), 0x142 (322), 0x18 (24) — likely width/height/stride pattern
- Two copies at offset 0 and +0x24 from puVar2
- Calls FUN_00540df0 to validate each sub-buffer

**Struct offsets:**
| Offset | Field | Notes |
|---|---|---|
| +0x114c | SurfacePtr | pointer to allocated surface |

**Calls:** operator_new (heap alloc), FUN_00540df0 (surface validation)

**Returns:** 0 on success, 0xffffffff on failure

**Moddability:** hardcoded.

## FUN_004b8360 — Sprite/Overlay Display List Cleanup

Source: likely_ui_render.cpp. Iterates a linked list of display items, removes expired entries by float value comparison.

**Key logic:**
- Walks linked list starting at param_1+0x6c0
- Compares each item's float value against threshold at param_1+0xf38
- If value below threshold: item removal using linked list unlink (prev/next pointers at offsets +4/+8)
- If item has flags (piVar3[3] != 0) and data (piVar3[0] != 0): frees sub-data via FUN_00587bcf
- Frees node with FUN_00587bcf
- Decrements count at param_1+0x6cc
- Sets dirty flag at param_1+0x6d0 to 1

**Struct offsets (param_1):**
| Offset | Field | Notes |
|---|---|---|
| +0x6c0 | ListHead | linked list anchor |
| +0x6c4 | ListTail | linked list tail |
| +0x6c8 | CurrentNode | iterator position |
| +0x6cc | ItemCount | decremented on removal |
| +0x6d0 | DirtyFlag | set to 1 on change |
| +0xf38 | Threshold | float comparison value |

**Calls:** FUN_00587bcf (memory free)

**Moddability:** hardcoded — threshold-driven expiry.

## FUN_0042dc60 — Small Data Struct Init

Source: likely_race.cpp. Initializes a 6-element uint32 array with defaults.

**Key logic:**
- Sets [0]–[3] to 0
- Sets [4] to 0x1e (30)
- Sets [5] to 0x2a (42)

**Moddability:** hardcoded — constants 30 and 42.

## FUN_00541d10 — Orientation/Rotation Matrix Update

Source: likely_physics_transform.cpp. Applies rotation angles to orientation matrix, computes transformed axes.

**Key logic:**
- Takes angles (param_2, param_3, param_4) stored at +0x24, +0x28, +0x2c
- Dot products with stored axis vectors at +0x15c/0x16c/0x17c (row 0), +0x160/0x170/0x180 (row 1), +0x164/0x174/0x184 (row 2)
- Stores transformed axes at +0x18c (x-axis), +0x190/400 (y-axis), +0x194 (z-axis)
- Sets +0x198 to 0x3f800000 (1.0) — scale/w factor

**Struct offsets (param_1):**
| Offset | Field | Notes |
|---|---|---|
| +0x24–0x2c | InputAngles | 3 floats |
| +0x15c, +0x16c, +0x17c | RotationMatrixRow0 | 3 floats |
| +0x160, +0x170, +0x180 | RotationMatrixRow1 | 3 floats |
| +0x164, +0x174, +0x184 | RotationMatrixRow2 | 3 floats |
| +0x18c | OutputAxisX | float |
| +0x190 | OutputAxisY | float |
| +0x194 | OutputAxisZ | float |
| +0x198 | ScaleFactor | 1.0f |

**Calls:** none

**Moddability:** configurable — rotation angles are inputs.

## FUN_0042ad00 — Lateral Force/Torque Calculation

Source: likely_vehicle_physics.cpp. Computes force as product of int param, float at +0x44f4, and global constant.

**Key logic:**
- Force = (float)param_2 * *(param_1+0x44f4) * DAT_0059e444
- Stored at param_1+0x453c

**Globals:**
- `DAT_0059e444` — conversion/scale factor

**Struct offsets (param_1):**
| Offset | Field | Notes |
|---|---|---|
| +0x44f4 | ForceCoefficient | float multiplier |
| +0x453c | OutputForce | float result |

**Moddability:** configurable — ForceCoefficient field.

## FUN_0050a34b — Vertex Buffer Generation

Source: likely_ui_render.cpp. Converts short int vertex data to float vertex buffer with scale.

**Key logic:**
- Computes vertex count from param_1+0x1050 * param_2 + param_1+0x1054 * param_3 + param_1+0x18
- Iterates over source (short[2] per vertex), scales by DAT_0059e780
- Writes 4 floats per vertex: x*fVar2, y*fVar2, 0.0, 1.0
- If param_1+0x10 != 0, calls FUN_00507845 for alpha/color post-process

**Globals:**
- `DAT_0059e780` — vertex scale factor

**Struct offsets (param_1):**
| Offset | Field | Notes |
|---|---|---|
| +0x10 | PostProcessFlag | int |
| +0x18 | BaseIndex | int |
| +0x1050 | WidthFactor | int |
| +0x1054 | HeightFactor | int |
| +0x1058 | VertexCount | int |

**Calls:** FUN_00507845 (alpha/color post-process)

**Moddability:** hardcoded.

## FUN_004be4e0 — Sprite Grid Render

Source: likely_ui_render.cpp. Renders a 2D grid of sprites with boundary clamping (0–7 range).

**Key logic:**
- Converts 4 float params to int indices via __ftol(), clamps to 0–7
- Nested loop over rows (iVar2..iVar3) and columns (local_8..local_c)
- Calls FUN_004bdb10 for each cell in the grid
- If any clamp occurred (bVar1), calls an extra FUN_004bdb10 at end
- Increments counter at param_1+0x934

**Struct offsets (param_1):**
| Offset | Field | Notes |
|---|---|---|
| +0x934 | RenderCounter | int, incremented per call |

**Calls:** FUN_004bdb10 (sprite render primitive)

**Moddability:** hardcoded — 0–7 grid boundary.

## FUN_0054fa00 — Network Packet Data Writer

Source: likely_network_packet.cpp. Writes 6 dwords from source into packet buffer at stride 0x74.

**Key logic:**
- Checks buffer at param_1+0x1e0 → +8 is valid and param_3 < count at +4
- At packet index param_3 * 0x74 + data_start:
  - Writes param_2[0..2] to +0x4, +0x8, +0xc
  - Writes param_2[3..5] to +0x1c, +0x20, +0x24
  - Sets flag bit 8 at *puVar2

**Calls:** none

**Moddability:** hardcoded — network protocol format.

## FUN_0054fa90 — Network Packet Data Reader

Source: likely_network_packet.cpp. Reads 16 dwords from packet buffer at stride 0x74.

**Key logic:**
- Checks buffer at param_1+0x1e0 is valid and param_2 < count at +4
- Checks flag bit 0 on packet entry
- Copies 16 (0x10) dwords from packet+0x34 to param_3
- Returns 1 on success, 0 on failure

**Calls:** none

**Moddability:** hardcoded — network protocol format.

## FUN_004b6130 — Sprite/Overlay List Cleanup

Source: likely_ui_render.cpp. Frees all items in a linked list at param_1+0x9b0.

**Key logic:**
- Reads count from *(param_1+0x9b0 - 4) (embedded before list)
- Loops count times calling FUN_004b46f0
- Frees the allocation base with FUN_00587bcf
- Zeros +0x9b0 and +0x9b4

**Struct offsets (param_1):**
| Offset | Field | Notes |
|---|---|---|
| +0x9b0 | ListPtr | pointer to item array |
| +0x9b4 | ListEnd | pointer, zeroed |

**Calls:** FUN_004b46f0 (item cleanup), FUN_00587bcf (free)

**Moddability:** hardcoded.

## FUN_00508d2d — Texture Color Cache Fill

Source: likely_renderer_texture.cpp. Fills a color lookup table/cache from palette entries with brightness scaling.

**Key logic:**
- If param_1+0x1048 != 0, transforms param_4 via FUN_00506ce2
- Gets palette data from param_1+0x2c
- For each entry (0..param_1+0x1058):
  - Index = ((param_3 & 3) + (param_2 & 3) * 8 + (i & 3)) * 4
  - Computes color channels (BGRA) by rounding source + brightness * scale
  - Uses DAT_0059e6fc as brightness/scale factor
  - Packs into 32-bit ARGB: (A<<24)|(R<<16)|(G<<8)|B

**Globals:**
- `DAT_0059e6fc` — brightness/color scale factor

**Struct offsets (param_1):**
| Offset | Field | Notes |
|---|---|---|
| +0x2c | PalettePtr | pointer to float palette data |
| +0x1048 | TransformFlag | int flag |
| +0x1058 | EntryCount | int |

**Calls:** FUN_00506ce2 (palette remap), FUN_00507473 (setup)

**Moddability:** hardcoded — 8x4 palette pattern.

## FUN_004e0c90 — UI Timer/Tween Update

Source: likely_ui_animation.cpp. Updates a timer/deadline by subtracting elapsed time.

**Key logic:**
- If +0x894 != 0 (active): gets current values via FUN_0054b420, computes new deadline = +0x930 - param_2 * DAT_0059e7e8, updates via FUN_0054b4d0

**Globals:**
- `DAT_0059e7e8` — time speed multiplier

**Struct offsets (param_1):**
| Offset | Field | Notes |
|---|---|---|
| +0x894 | ActiveFlag | int |
| +0x930 | Deadline | float |

**Calls:** FUN_0054b420 (get timer state), FUN_0054b4d0 (set timer)

**Moddability:** hardcoded.

## FUN_00519986 — Sprite Frame Selector

Source: likely_ui_sprite.cpp. Selects sprite frame based on direction or animation state.

**Key logic:**
- Reads iVar1 from param_1+0x184 (target struct)
- If count at param_1+0x120 < 2: pick source from +0xc or +0x48 based on position relative to limit, store at iVar1+0x1c
- Else: store 1 at iVar1+0x1c (single frame)
- Resets iVar1+0x14 and iVar1+0x18 to 0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|---|---|---|
| +0x80 | CurrentPosition | uint |
| +0x118 | PositionLimit | int, -1 |
| +0x120 | FrameCount | int |
| +0x124 | FrameArray | array of frame data |
| +0x184 | OutputStruct | destination struct |

**Calls:** none

**Moddability:** hardcoded.

## FUN_004ed030 — Actor Motion/Post-Processing Update

Source: likely_actor_postfx.cpp. Updates actor post-processing state with interpolation and selection logic.

**Key logic:**
- Calls FUN_004e0d00 on +0xcc8 and +0xd0c (cleanup)
- Calls FUN_004a56b0(0) (reset)
- If +0x3d60 == 1: set to 0
- Smooths +0x3a6c toward +0x3a78: v = (target + current) * 0.5 (DAT_0059e450)
- Selects +0x3a70: if +0xd0c==0 or +0xd4c byte != 0: use +0x3a7c; else use +0x3a80
- Calls FUN_004e8010(0)
- If +0x32bc == 0: calls FUN_0043ec80

**Globals:**
- `DAT_0059e450` — 0.5f interpolation factor

**Struct offsets (param_1):**
| Offset | Field | Notes |
|---|---|---|
| +0xcc8 | TimerA | timer object |
| +0xd0c | TimerB | timer object |
| +0xd4c | TimerBFlag | byte flag |
| +0x32bc | ModeSwitch | int |
| +0x3a6c | CurrentValue | float (interpolated) |
| +0x3a78 | TargetValue | float target |
| +0x3a70 | SelectedValue | float output |
| +0x3a7c | ValueOptionA | float |
| +0x3a80 | ValueOptionB | float |
| +0x3d60 | StateFlag | int |

**Calls:** FUN_004e0d00 (timer cleanup), FUN_004a56b0 (reset), FUN_004e8010 (update), FUN_0043ec80 (post-process)

**Moddability:** hardcoded.

## FUN_005408f0 — Graphics Config State Setter

Source: likely_renderer_config.cpp. Sets two state fields based on mode parameter (0/1/2).

**Key logic:**
- param_2 == 0: set +0x13e0 = 0, +0x13dc = 0
- param_2 == 1: set +0x13e0 = 1, +0x13dc = 1
- param_2 == 2: set +0x13e0 = 2, +0x13dc = 1

**Struct offsets (param_1):**
| Offset | Field | Notes |
|---|---|---|
| +0x13dc | ModeA | int (0 or 1) |
| +0x13e0 | ModeB | int (0, 1, or 2) |

**Moddability:** configurable — param_2 selects mode.

## FUN_004f1890 — Speed/Value Setter with Global Mirror

Source: likely_race_clock.cpp. Stores a float at +0x3978; conditionally mirrors to global.

**Key logic:**
- Stores param_2 at param_1+0x3978
- If param_1+0x32bc == 0: writes DAT_007c75c4 = (double)param_2

**Globals:**
- `DAT_007c75c4` — global speed/time value (double)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|---|---|---|
| +0x32bc | GlobalMirrorFlag | int (0 = mirror enabled) |
| +0x3978 | LocalValue | float |

**Moddability:** configurable — local value writer.

## FUN_004b97e0 — Render Toggle/Refresh

Source: likely_ui_render.cpp. Calls render update with conditional on DAT_007d0038.

**Key logic:**
- Calls FUN_004b7500(CONCAT31((int3)((uint)DAT_007d0038 >> 8), DAT_007d0038 != 0))

**Globals:**
- `DAT_007d0038` — refresh/poll flag

**Calls:** FUN_004b7500 (render update)

**Moddability:** hardcoded.

## FUN_00543a30 — Get Orientation/Angle Values

Source: likely_physics_transform.cpp. Returns stored orientation values via output pointers.

**Key logic:**
- If param_2 != NULL: *param_2 = *(param_1+0x194)
- If param_3 != NULL: *param_3 = *(param_1+0x198)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|---|---|---|
| +0x194 | OutputAngleZ | float |
| +0x198 | OutputScale | float |

**Moddability:** read-only getter.

## FUN_0041f220 — Championship Points Accumulator

Source: likely steward.cpp. Accumulates driver/team championship points across multiple scoring entries. Two modes: iteration (batch) and single-shot.

**Key logic:**
- If param_1 == 0 → return -1 (invalid/null pointer)
- If param_2 != -1 (batch mode): loops param_2 times (outer), then loops over iVar1 (count from FUN_004c1370) times (inner)
  - Each inner iteration: copies 0x50-byte buffer via FUN_004c0a20, checks validity via FUN_00566810
  - If valid: accumulates result from FUN_0041ed20 (individual score value) into running total iVar4
  - Returns accumulated iVar4
- If param_2 == -1 (single mode): directly processes param_1 via FUN_0041c13c0, returns result

**Globals:**
- None directly accessed; called by FUN_0041e320 which gates on DAT_007d0308 (RaceActiveFlag)

**Calls:** FUN_004c2850 (buffer reset), FUN_004c1370 (get count), FUN_004c1390/FUN_004c13a0 (iteration helpers), FUN_004c0a20 (buffer copy, 0x50 bytes), FUN_00566810 (validity check), FUN_0041ed20 (individual score extraction), FUN_004c13c0 (single-item processor)

**Moddability:** hardcoded — internal scoring accumulator, no config fields

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_00435390 — Category Scoring State Initializer

Source: likely steward.cpp. Initializes a 0x60-byte scoring/classification state struct.

**Key logic:**
- Sets element [0] = -1 (0xFFFFFFFF)
- Sets element [1] through [0x17] (23 elements) = 0 (92 bytes total)
- Element [4] = 0x3FF00000 (float ~1.875f — default score weight/multiplier)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | CategoryID | int32, initialized to -1 |
| +0x04 | Reserved0 | zeroed |
| +0x10 | Weight | float, initialized to ~1.875 |
| +0x14 | Remaining fields | zeroed, totalling 0x5C bytes |

**Moddability:** hardcoded — struct init only

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054b770 — Transformation Matrix Update

Source: likely physics/collision system. Updates a 4×4 transformation matrix from source to destination with optional per-axis scaling. Handles COM interface-based copy or direct memcpy.

**Key logic:**
- If field +0x40 == 0 (null parent): if flag +0x3C & 1, copy 16 dwords (matrix) from +0xD4 to +0x114
- Else: call COM vtable method at DAT_008B8F24+8 to transform matrix from +0xD4 through parent to +0x114
- If flag +0x3C & 0x4000 (per-axis scale enabled):
  - Scale matrix rows by factors at +0x194 (row0), +0x198 (row1), +0x19C (row2)
  - Route result to +0x1A0, using vtable call if parent exists or bit 0 flag for alternate path
- Else: copy +0x114 to +0x1A0 directly

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x3C | TransformFlags | bitfield: bit0=hasLocal, bit14=hasScale |
| +0x40 | ParentPtr | pointer to parent transform |
| +0x94 | AltTransformDest | alt destination (used with bit0 flag) |
| +0xD4 | LocalMatrix | 16 floats (4×4 matrix) |
| +0x114 | WorldMatrix | 16 floats (4×4, computed) |
| +0x194 | ScaleX | float, row0 multiplier |
| +0x198 | ScaleY | float, row1 multiplier |
| +0x19C | ScaleZ | float, row2 multiplier |
| +0x1A0 | OutputMatrix | 16 floats (4×4, result) |

**Globals:**
- `DAT_008B8F24` — COM interface pointer (physics/collision transform engine)

**Moddability:** hardcoded — internal transform pipeline

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c0f60 — Race Standings/Rankings Computation

Source: likely steward.cpp. Computes position rankings for up to 104 competitors (0x68 entries, stride 0x1B4) based on integer score at +0x198.

**Key logic:**
- Guarded by dirty flag at +0xB150: if already computed (non-zero), skip
- First pass (if flag +0xB150 == 0): iterate all 0x68 entries, check active flag at +0x1B0
  - For each active entry: iterate all others, count how many have larger score at +0x198
- Store rank count: entry 0 → +0xB108; others → (entry * 0x1B4 + base) - 0x18 offset
- If field +0xB14C == 7 (session type check): compute rankings normally
- Set flag +0xB150 = 1 (mark complete)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xB14C | SessionType | int32, compared to 7 (race) |
| +0xB150 | RankingsDirtyFlag | byte, 0=needs compute, 1=done |
| +0xB108 | RankEntry0 | int32, rank count for entry 0 |
| +0x1B0 | EntryActive | byte per entry (stride 0x1B4) |
| +0x198 | EntryScore | int32 per entry, compared for ranking |

**Calls:** FUN_004c11d0 (session data access), FUN_004c0910 (data lookup)

**Moddability:** hardcoded — internal standings computation

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042adb0 — Session Cleanup Flag Clear

Source: likely racecontrol.cpp. Clears session tracking fields when a completion flag is unset.

**Key logic:**
- If byte at +0x4410 == 0 (not completed): zero +0x4424, set +0x45F4 = 1

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4410 | CompletionFlag | byte, checked for 0 |
| +0x4424 | TrackingValue | int32, zeroed |
| +0x45F4 | NeedsUpdateFlag | byte, set to 1 |

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042d350 — Session Reset

Source: likely racecontrol.cpp. Resets session state by calling two initialization functions.

**Key logic:**
- Calls FUN_004d7800() (session data clear/reset)
- Calls FUN_00422be0(0) (reset with mode 0)

**Calls:** FUN_004d7800 (session data reset), FUN_00422be0 (init/reset with param=0)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_004be700 — Performance/Setup Struct Initializer

Source: likely racecontrol.cpp or session setup. Initializes a performance struct with default parameters: flags, multipliers, and iteration counts.

**Key logic:**
- Set bytes at +0x340=1, +0x341=1, +0x342=0 (3 flags)
- +0x344 = 1.0f, +0x348 = 1.0f (two multiplier defaults)
- +0x34C = DAT_005ACDAC (global threshold value)
- +0x350 = 10.0f (float limit), +0x354=0, +0x358=0
- +0x35C = 10 (int), +0x360 = 5 (int) — iteration/repetition counts

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x340 | FlagA | byte, 1 |
| +0x341 | FlagB | byte, 1 |
| +0x342 | FlagC | byte, 0 |
| +0x344 | MultiplierA | float, 1.0 |
| +0x348 | MultiplierB | float, 1.0 |
| +0x34C | ThresholdRef | float, from DAT_005ACDAC |
| +0x350 | FloatLimit | float, 10.0 |
| +0x35C | IterationCount | int32, 10 |
| +0x360 | SubIterationCount | int32, 5 |

**Globals:**
- `DAT_005ACDAC` — global threshold/reference value (used as default)

**Moddability:** hardcoded — struct init only

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b8480 — Linked List Destructor

Source: likely sessiondata.cpp. Frees all nodes and referenced data in a linked list, then zeros list pointers.

**Key logic:**
- Set flag at +0x6D0 = 1
- Walk list at +0x6C0: for each node:
  - Save next pointer
  - If node[3] flag byte non-zero AND *node (data ptr) non-zero:
    - Free node data[+4] via FUN_00587bcf
    - Free node data via FUN_00587bcf
  - Free node itself via FUN_00587bcf
- Zero list head/tail/count fields at +0x6C0..+0x6CC

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x6C0 | ListHead | pointer, zeroed after cleanup |
| +0x6C4-0x6CC | ListMeta | tail/prev/count, zeroed |
| +0x6D0 | CleanupFlag | byte, set to 1 |

**Calls:** FUN_00587bcf (memory free)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c07f0 — Lap/Session Data Array Initializer

Source: likely steward.cpp. Initializes two parallel arrays of 48 entries each (-1 fill) and resets summary fields.

**Key logic:**
- Loop 0x30 (48) times: set element at base+0x18 and base+0xD8 to -1, advancing by 4 bytes each
  - Effectively: write -1 to [base+0x18 .. base+0xCC] and [base+0xD8 .. base+0x18C]
- Set +0x198 = 0, +0x19C = 0, +0x1A0 = 0 (zeroed accumulators)
- Set +0x1A8 = 0 (zeroed)
- Set +0x1AC = -1 (invalid/sentinel)
- Set +0x1B0 = 0 (flag off)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x18 | ArrayA | 48 × int32, initialized to -1 |
| +0xD8 | ArrayB | 48 × int32, initialized to -1 |
| +0x198 | AccumulatorA | int32, zeroed |
| +0x19C | AccumulatorB | int32, zeroed |
| +0x1A0 | AccumulatorC | int32, zeroed |
| +0x1A8 | Reserved | int32, zeroed |
| +0x1AC | Sentinel | int32, -1 |
| +0x1B0 | ReadyFlag | byte, 0 |

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0053ce40 — Physics Object Linked List Removal

Source: likely dynamics.cpp. Unlinks a physics body from the global collision list and decrements the object count.

**Key logic:**
- Walk global linked list from DAT_008B8F14 looking for node matching param_1
- If found: unlink from doubly-linked list (adjust next/prev pointers at +0x130 and +300)
- If node being removed is head (field +300 == 0): update DAT_008B8F14 to next
- Call FUN_0055FE30 (tag removal)
- Call FUN_00557470 (scene graph update)
- Call FUN_00587BCF (free memory)
- Decrement DAT_008B6AC0

**Globals:**
- `DAT_008B8F14` — global linked list head (physics/collision objects)
- `DAT_008B6AC0` — global physics object count

**Calls:** FUN_0055FE30, FUN_00557470, FUN_00587BCF

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_005093f9 — Vertex/Coordinate Transform to Screen

Source: likely hudoverlay.cpp. Transforms 3D coordinate data into 2D screen shorts using scale+offset, indexed by a 3D grid.

**Key logic:**
- If +0x1048 != 0: transform param_4 via FUN_00506CE2
- Get base pointer at +0x2C (vertex data)
- Get count at +0x1058 (number of vertices)
- For each vertex (0 to count-1):
  - Index into source floats using (param_3&3) + (param_2&3)*8 + (uVar5&3) pattern (3D grid lookup, 8×4×4)
  - Read 3 floats from param_4 (x,y,z offset), multiply by _DAT_0059F120 (scale factor), add base value
  - Write ROUND result as 3 shorts (screen x,y,z or u,v,w)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x2C | VertexBase | float*, source coordinate data |
| +0x1048 | TransformFlag | int32, enables coordinate transform |
| +0x1058 | VertexCount | int32, number of vertices to process |

**Globals:**
- `_DAT_0059F120` — float scale factor (screen coordinate conversion)

**Calls:** FUN_00506CE2 (coordinate transform), FUN_00507473 (setup/init)

**Moddability:** hardcoded — internal coordinate transform

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0052e2f0 — Lap/Performance State Reset

Source: likely timing.cpp. Copies a reference lap time and zeros accumulator fields.

**Key logic:**
- Copy +0x249C (lap reference) → +0x24E8
- Zero +0x24AC, +0x24A8 (accumulators)
- Zero +0x24E4, +0x24B4 (delta/adjustment fields)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x249C | LapRef | int32, reference lap/sector time |
| +0x24E8 | LapCopy | int32, working copy |
| +0x24AC | AccumA | int32, zeroed |
| +0x24A8 | AccumB | int32, zeroed |
| +0x24E4 | Delta | int32, zeroed |
| +0x24B4 | Adjustment | int32, zeroed |

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f03e0 — Team Color Loader

Source: likely vehicleappearance.cpp. Loads team color data by TeamID and sends it to the renderer.

**Key logic:**
- Read TeamID from *param_1 + 0x4894 (vehicle struct)
- Call FUN_00463D50(TeamID, buffer, param_2) — load color data into 432-byte buffer
- If data loaded: call FUN_004C73F0(buffer, param_2) — apply to renderer

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| *param_1 + 0x4894 | TeamID | int32, team identifier |

**Calls:** FUN_00463D50 (team color lookup), FUN_004C73F0 (color data apply)

**Moddability:** hookable — team colors loaded dynamically per vehicle

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_00542560 — Suspension/Physics Parameter Set

Source: likely physics/driver car setup. Copies a parameter and calls a setup function with float-converted values.

**Key logic:**
- If param_2 != 0: store param_2 at param_1 + 0x19C
- Call FUN_00542200 with floats: *(param_1+0x68), *(param_1+0x64), *(param_1+0x54), *(param_1+0x58), 1

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x19C | ParamSlot | int32, stored if non-zero |
| +0x68 | FloatParamA | int32 → float, passed to setup |
| +0x64 | FloatParamB | int32 → float |
| +0x54 | FloatParamC | int32 → float |
| +0x58 | FloatParamD | int32 → float |

**Calls:** FUN_00542200 (physics/setup update)

**Moddability:** configurable — accepts external parameter

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_00544ef0 — Scene Graph Tree Destructor

Source: likely dynamics/scene.cpp. Recursively destroys a scene graph/dynamics tree node, freeing children first.

**Key logic:**
- If field at +0x1B0 != 0: recurse into it (first child/sibling)
- If both +0x1AC and +0x1B8 are non-zero: recurse into +0x1B8 (second child)
- Call FUN_004B0170 (scene graph maintenance)
- Call FUN_00545090(param_1) (node-specific cleanup)
- Call FUN_00557470 (scene graph update)
- Call FUN_00587BCF(param_1) (free memory)

**Calls:** FUN_004B0170, FUN_00545090 (node cleanup), FUN_00557470 (scene update), FUN_00587BCF (free)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_005414e0 — Field 0x13B0 Accessor

Source: likely dynamics.cpp. Simple getter returning a 4-byte value at struct offset +0x13B0.

**Key logic:**
- Return *(int32 *)(param_1 + 0x13B0)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x13B0 | StateValue | int32/float, returned directly |

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0040a910 — MenuSlotActionDispatch

Source: Unknown (likely UI menu layer). Dispatches UI action index based on slot ID matching.

**Key logic:**
- Compares `param_2` against 8 stored slot IDs at `param_1[4]` through `param_1[0xc]` (indices 4,5,6,7,9,10,11,12)
- On match: calls `FUN_00409440(slot_index, 1, 1)` — dispatches UI menu action (sound/feedback) for matched slot
- If no direct match: linear search through linked entries starting at `param_1[8]` with stride 200 bytes per entry, up to `param_1[0xe]` entries
- On linear-search match: calls `FUN_00409440(4, 1, 1)` and stores found index at `param_1[0xf]`
- If `param_3` (flag) is non-zero after dispatch: calls virtual method at vtable+0x10 on the object

**Calls:** FUN_00409440 (UI sound/feedback dispatch, per analyzed/0x00409440)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042e290 — PositionIndexClamp

Source: Unknown. Clamps a float/double value to a valid position index range [0, max-1].

**Key logic:**
- Reads double from `param_2`/`param_3` combined (64-bit float)
- If value < threshold `_DAT_0059e880`: result = round(value * 2 * *(int*)(param_1+0x18))
- Else: result = *(int*)(param_1+0x18) + round(((value*2 - _DAT_0059e420) * (*(int*)(param_1+0x10) - *(int*)(param_1+0x18) - 1)))
- Clamps result to [0, *(int*)(param_1+0x10)-1]
- Stores clamped result at `param_1+0x14`

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x10 | MaxIndex | int, exclusive upper bound |
| +0x14 | ResultIndex | int, clamped output |
| +0x18 | MinIndex | int, lower bound |

**Globals:**
- `_DAT_0059e880` — lower threshold constant
- `_DAT_0059e420` — upper threshold constant

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042dd00 — RatioCalculator

Source: Unknown. Computes weighted ratio from two index-based arrays.

**Key logic:**
- Bounds-checks `param_2` against `param_1[0]` and `param_3` against `param_1[2]`
- Reads int values at `param_1[1]+param_2*8` and `param_1[3]+param_3*8` (stride 8 arrays)
- If both values > 0 and `param_1[4]` > 0: computes `(val2_plus4 * val1_plus4 * param_1[5]) / (param_1[4] * count2 * count1)`
- Returns default float `_DAT_0059e430` if any validation fails

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | Dim1Size | int, first dimension count |
| +0x04 | Array1Ptr | int*, stride 8 array |
| +0x08 | Dim2Size | int, second dimension count |
| +0x0c | Array2Ptr | int*, stride 8 array |
| +0x10 | Divider | int, divisor |
| +0x14 | Multiplier | int, numerator multiplier |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042ddd0 — ScoreSlotDeallocator

Source: Unknown (\_\_fastcall). Deallocates two score/data entries.

**Key logic:**
- Sets `param_1[0]` = 0
- If `param_1[1]` non-null: calls `FUN_00587bcf` (memory dealloc) and sets to 0
- Sets `param_1[2]` = 0
- If `param_1[3]` non-null: calls `FUN_00587bcf` (memory dealloc) and sets to 0

**Calls:** FUN_00587bcf (memory deallocation/free)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042af40 — AIStateReset

Source: Unknown. Resets AI behavior flags and calls session initialization.

**Key logic:**
- Calls `FUN_004a5c80(0)` — reset with parameter 0
- Calls `FUN_004efac0()` — some setup/init
- Sets byte at `param_1 + 0x4410` = 1 (AI state flag)
- Sets byte at `param_1 + 0x45f4` = 0 (another AI flag)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4410 | AIStateFlag | byte, set to 1 (active) |
| +0x45f4 | AIControlFlag | byte, cleared to 0 |

**Calls:** FUN_004a5c80 (reset), FUN_004efac0 (setup)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042dc80 — BoundedArrayAccessor

Source: Unknown. Bounds-checked read from an int array with stride 8.

**Key logic:**
- Checks `param_2` in range [0, *param_1)
- If valid: returns `*(int*)(param_1[1] + param_2 * 8)` (first int of struct at stride 8)
- If invalid: returns 0

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042ed50 — NameStringCopy

Source: Unknown. String copy with length limit and null termination.

**Key logic:**
- Calls `_strncpy(param_1 + 0x70, param_2, 0x3f)` — copies up to 63 chars
- Null-terminates at `param_1 + 0xaf`

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051bdf1 — BufferedDataReader

Source: Unknown. Streaming data copy between source and destination buffers with progress tracking.

**Key logic:**
- Reads sub-struct pointer from `param_1 + 0x188`
- If `iVar1 + 0x18` (progress offset) == 0: calls virtual function at vtable+0x1c to allocate source buffer, stores result at `iVar1 + 0xc`
- Computes `uVar4` = min(remaining source data, remaining destination capacity, remaining space at intermediate buffer)
- Calls copy function via vtable+4 with (param_1, src_ptr + progress*4, dst_ptr + progress*4, count)
- Advances source progress by `uVar4`
- When source progress >= source size: resets progress, advances source position

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c28d0 — TrackSceneNodeAdd

Source: Unknown (track system). Adds a scene geometry node to a linked list.

**Key logic:**
- Calls `FUN_004c2860(param_2)` — check if scene already loaded
- If not loaded: calls `FUN_004c5690(param_2)` — load/init scene
- Computes current scene record: `DAT_008ac48c * 0x18c + DAT_008ac490`
- Allocates new 0x18-byte node, gets index via `FUN_004c03a0()`
- Calls `FUN_00566650` on scene offsets +0x104 and +4 (likely reference counting)
- Creates linked list entry (12 bytes): stores index, next=0, active=1
- Appends to linked list at `param_1+0x10` (head), `param_1+0x18` (tail), count at `param_1+0x1c`

**Globals:**
- `DAT_008ac48c` — CurrentSceneIndex (docs/12)
- `DAT_008ac490` — SceneArray (docs/12)
- `DAT_008ac488` — SceneFileCount (related)

**Calls:** FUN_004c2860 (scene check), FUN_004c5690 (scene load), FUN_004c03a0 (index alloc), FUN_00566650 (ref count)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004bdfe0 — MatrixClear

Source: Unknown (\_\_fastcall). Clears an 8x8 grid of ints and a counter.

**Key logic:**
- Iterates 8x8 = 64 entries with stride 9 ints (36 bytes) per column
- Zeroes each entry
- Zeroes `param_1 + 0x904` (total/sum counter)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004d1ad0 — ScoringGateSelector

Source: Unknown. Scans a range of scoring/gate entries and returns the best-matching value.

**Key logic:**
- Calls `FUN_004d7bf0` (get min index) and `FUN_004d7c00` (get max index) for `param_2`
- If max < min: returns 0 (empty range)
- Iterates entries at `param_1 + 0x110` with stride 8, within [min, max]
- Compares entry values (2, 3, 8) with priority logic:
  - If value 3 found: immediately returns 3
  - If value 2 found: tracks as best (priority over 8)
  - If value 8 found: fallback
  - Special case: if iVar4 == 3, keeps it (trumping)

**Globals:**
- `DAT_008ab6e4` — ScoringGate (related, docs/12)

**Calls:** FUN_004d7bf0, FUN_004d7c00

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00516f76 — ObjectConstructor

Source: Unknown. Allocates and initializes an object with vtable setup.

**Key logic:**
- Virtual alloc call at `*(param_1+4)` vtable: allocates 0x1c bytes
- Stores result at `param_1 + 0x17c`
- Sets vtable pointer at allocated object to `LAB_00516e28`
- Sets secondary vtable at +4 to `LAB_00516f55`
- Zeroes byte at offset +2
- Calls `FUN_00516c7b()` — constructor continuation

**Calls:** FUN_00516c7b (constructor init)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e0e20 — ArrayEntryCleanup

Source: Unknown. Cleans up one entry in an array (stride 0x128).

**Key logic:**
- Computes entry address: `param_1 + param_2 * 0x128`
- Calls `FUN_004e0d00(param + 0x144)` — cleanup sub-object
- Calls `FUN_004e0d00(param + 0x188)` — cleanup sub-object
- If value at +0x188 was non-null: calls `FUN_0054c030(1,1,0,0)` — notification/update

**Calls:** FUN_004e0d00 (cleanup), FUN_0054c030 (notification)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b8150 — LinkedListFloatAccessor

Source: Unknown (\_\_thiscall). Traverses a linked list to retrieve a float value by index.

**Key logic:**
- Bounds-checks `param_2` against `*(int*)(param_1 + 0x6cc)` (list count)
- Walks linked list from `param_1 + 0x6c0` (head), using `[1]` as next pointer
- At target index: returns `*(float*)*puVar1` (float value at node's data pointer)
- Returns default `_DAT_0059e670` if position invalid or null

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00537fe0 — BitstreamEncoder

Source: Unknown (\_\_fastcall). Variable-length bit encoder writing packed data to a buffer.

**Key logic:**
- Maintains bit accumulator at +0x16ab (ushort), bit position at +0x16ad
- Two encoding patterns with thresholds at 0xe and 10 bits:
  - If bit position < threshold: accumulates bits in ushort at +0x16ab
  - If >= threshold: flushes accumulated bytes to buffer at (+8), advances (+0x14) position
- Encodes value 2 with 3-bit length prefix when position < 0xe
- Encodes value 0 with 7-bit length prefix when position < 10
- Calls `FUN_00539690()` after each complete write
- Final flush at end, sets `param_1 + 0x16a7 = 7` (remaining bits/flush state)

**Calls:** FUN_00539690 (bitstream flush/commit)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f6850 — RandomOffsetCalculator

Source: Unknown (\_\_thiscall). Computes float with optional random perturbation.

**Key logic:**
- If byte at `param_1 + 0x56c` == 0: generates random via `FUN_005881f0()`, multiplies by `*(double*)(param_1+0x578)`
- If flag != 0: uses param_2 as-is
- Returns result + `*(double*)(param_1+0x570)` (base offset)

**Calls:** FUN_005881f0 (random number generation)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00543960 — DisplayModeSetter

Source: Unknown. Sets display/render mode flags based on parameter.

**Key logic:**
- If `param_2 == 0x20000`: stores 0x20000 at +0x19c, ORs 0x10000 into +0xec
- If `param_2 == 0x40000`: stores 0x40000 at +0x19c, ORs 0x10000 into +0xec
- If `param_2 == 0x80000`: stores 0x80000 at +0x19c, ORs 0x10000 into +0xec
- If none match: stores 0 at +0x19c, ORs 0x10000 into +0xec (clears mode)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f1b50 — CameraModeSetter

Source: Unknown. Sets global camera/view mode state based on parameter and vehicle state.

**Key logic:**
- If `param_2 == 0` AND `*(int*)(param_1+0x32bc) == 0`: sets `_DAT_007c74f8 = 0` (default mode)
- If `param_2 != 0` AND `*(int*)(param_1+0x32bc) == 0`: sets `_DAT_007c74f8 = 2` (alternate mode)
- If `*(int*)(param_1+0x32bc) != 0`: zeroes three fields at +0x34ec, +0x34f0, +0x34f4 (clear camera/position data)

**Globals:**
- `_DAT_007c74f8` — camera/view mode global

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c7bf0 — PropertySetter

Source: Unknown (\_\_thiscall). Simple property write to struct offset.

**Key logic:**
- Stores `param_2` at `param_1 + 0x48ac`

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_005414f0 — SimpleGetter

Source: Unknown (\_\_fastcall). Returns a stored value from struct.

**Key logic:**
- Returns `*(int*)(param_1 + 0x13d8)`

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_00411440 — ScoringGate vehicle lookup

Search three driver arrays (entry list, qualifying entry list, practice entry list) for a matching vehicle ID, then remove it from roster if found.

**Key logic:**
- Guard: if `DAT_008ab6e4` (ScoringGate) == 2, skip all — no-op
- Three passes through arrays at `param_1+0x48` (entry count), `+0x50` (ptr, stride 0xca), `+0x54` (quali count), `+0x5c` (quali ptr, stride 0xc6), `+0x60` (practice count), `+0x68` (practice ptr, stride 0xc6)
- Each entry has a vehicle ID at `ptr+0xd0`; compares against `param_2`
- If match found and slot at `param_1+0x4c/0x58/0x64 + iVar1*0x24` != -1: call `FUN_00410af0` (remove from array), then `FUN_004bdf90` (audio/notification)
- If match found but slot == -1: call `FUN_004be180` (different audio/notification)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x48 | EntryCount | int, number of entries in first array |
| +0x4c | EntryRosterPtr | int*, per-entry stride 0x24 |
| +0x50 | EntryArray | array of entry structs, stride 0xca |
| +0x54 | QualiCount | int |
| +0x58 | QualiRosterPtr | int*, per-entry stride 0x24 |
| +0x5c | QualiArray | stride 0xc6 |
| +0x60 | PracticeCount | int |
| +0x64 | PracticeRosterPtr | int*, per-entry stride 0x24 |
| +0x68 | PracticeArray | stride 0xc6 |

**Globals:**
- `DAT_008ab6e4` — ScoringGate (docs/12)

**Calls:** FUN_00410af0 (remove element from array), FUN_004bdf90 (notification/audio, 65x FUN_004bd8c0), FUN_004be180 (notification/audio, 65x FUN_004bd970)

**Moddability:** `hardcoded` — ScoringGate check only

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_0042e4a0 — Weighted-sum comparator with binary adjustment

Compare two weighted sums against a global tolerance and adjust indices to find ordering.

**Key logic:**
- Computes `(index1 * param_1[1] + param_1[0]) * DAT_0059e9f0` vs `(index2 * param_2[1] + param_2[0])`
- If param_1 < param_2: loop adjusting either param_1 index up or param_2 index down
- `param_3` controls direction: 0 → increment param_1 index; nonzero → decrement param_2 index
- Guard: if `param_3 == 0` or `param_2 index < 1`, increment param_1 index instead
- Stops when param_1 sum >= param_2 sum

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | BaseValue | double array[0] |
| +0x08 | ScaleFactor | double array[1] |
| +0x14 | CurrentIndex | int, index within array |

**Globals:**
- `_DAT_0059e9f0` — tolerance/multiplier for comparison

**Moddability:** `hardcoded`

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_004ec080 — Vehicle telemetry position accumulator

Accumulates scaled velocity deltas into vehicle position and orientation, with broadcasting.

**Key logic:**
- Reads three velocity components from `param_2+0x2c/0x30/0x34` scaled by `param_2+8` (delta time?)
- Accumulates into `param_1[0xd35]` (float X), `param_1[0xd36]` (int Y), `param_1[0xd37]` (int Z)
- Calls `FUN_004e23d0` (coordinate transform / orientation update) on position and rotation data
- Calls `FUN_004e16c0` (physics integration step)
- Branch on `param_1[0xcaf]`:
  - == 0: accumulate velocity into local doubles, call `FUN_0043e6a0` (broadcast position)
  - == 2: lookup TeamID (+0x4894) via `FUN_00463dc0`; if team exists, transform local space via `FUN_004b2420`/`FUN_004b2310` and accumulate

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4894 | TeamID | int, read via `*param_1 + 0x4894` |
| +0xcaf | BroadcastMode | int, 0=full broadcast, 2=team-filtered |
| +0xd2c | RotationPtr | transform/orientation input |
| +0xd35 | PosX | float accumulator |
| +0xd36 | PosY | int accumulator |
| +0xd37 | PosZ | int accumulator |
| +0xd38 | PosFloat | float position for transform |

**Struct offsets (param_2):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x08 | DeltaTime | float |
| +0x2c | VelX | float, scaled velocity component |
| +0x30 | VelY | float |
| +0x34 | VelZ | float |

**Calls:** FUN_004e23d0 (coordinate/orientation transform), FUN_004e16c0 (physics integration step), FUN_0043e6a0 (broadcast doubles), FUN_00463dc0 (team lookup by TeamID), FUN_004b2420 (transform to local space), FUN_004b2310 (transform from local space)

**Moddability:** `hardcoded`

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_0042e1c0 — Struct initializer (28-byte state block)

Zeroes 6 ints (24 bytes) and sets three byte flags.

**Key logic:**
- `param_1[0..5]` = 0
- `*(byte*)(param_1+0x1c)` = 1 (active flag)
- `*(byte*)(param_1+0x1d)` = 0
- `*(byte*)(param_1+0x1e)` = 0
- Total initialized: 28 bytes (0x1c + 1)

**Moddability:** `hardcoded`

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_004f0f40 — Wheel contact force aggregation (4-wheel)

Aggregate tire contact forces from four wheels into resultant force vector, apply to wheel.

**Key logic:**
- Guard: if local tire pressure [`local_1c`] starts at 0.86; reduced to 0.5 if `param_1[0x32bc]` != 0 (wet/rain mode)
- Iterates 4 wheels at stride 0x3e (62 ints) from `param_1+0x3668`
- For each active wheel where `*(float)(*wheelPtr->ptr + 0x34) == param_2`:
  - Computes contact force `fVar3 = (pressure - slip) * grip * _DAT_005ad230`
  - Tracks peak force `local_20`
  - Accumulates weighted sums: direction, moment, lateral, longitudinal via per-wheel multipliers
- If `local_20 <= _DAT_0059e600` (threshold), skip (no meaningful force)
- Normalizes resultant by total force inverse (`_DAT_0059e43c / fVar1`)
- Calls `FUN_004f8850` (apply force to wheel channel 2)

**Globals:**
- `_DAT_005ad230` — grip/multiplier for contact force
- `_DAT_0059e440` — zero constant
- `_DAT_0059e43c` — normalization factor (1.0?)
- `_DAT_0059e600` — minimum force threshold
- `_DAT_0059e9e4` — force bias term
- `_DAT_0059e450` — slip coefficient

**Calls:** FUN_004f8850 (apply force to wheel slot, channel 2)

**Moddability:** `hardcoded` — thresholds and constants global

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_0044f4a0 — Session type flag guard

Check activation flag with session-type filtering for multiplayer server mode.

**Key logic:**
- Calls `FUN_00404f10()` (connection/session check)
- If connected AND `DAT_007c569c` (SessionType5) == 5 (server mode) AND `param_2 != 1`: returns false (suppressed)
- Otherwise returns byte at `param_2 + 0x37c + param_1` (flag indexed by param_1)

**Globals:**
- `DAT_007c569c` — SessionType5 (5=server, docs/12)

**Calls:** FUN_00404f10 (session connection check)

**Moddability:** `hardcoded`

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_0042bda0 — Timer conversion with sin

Convert double value via multiplier, apply sin, store integer result.

**Key logic:**
- `param_1 * DAT_0059e9b0` → passed to `FUN_005895a2` (sin function)
- Result truncated to int via `__ftol()` → stored to `DAT_007c5694`

**Globals:**
- `DAT_0059e9b0` — conversion multiplier
- `DAT_007c5694` — timer/angle output global

**Calls:** FUN_005895a2 (sin/math function)

**Moddability:** `hardcoded`

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_0042dca0 — Bounds-checked array lookup

Safe read from 8-byte stride array with bounds checking.

**Key logic:**
- Bounds check: `param_2 >= 0 && param_2 < *param_1` (array count)
- If valid: return `*(param_1[1] + 4 + param_2 * 8)` (second field of 8-byte entry)
- If invalid: return 0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | Count | int, number of entries |
| +0x04 | DataPtr | int*, array of 8-byte records |

**Moddability:** `hardcoded`

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_004353f0 — Constructor stub

Initialize field and call parent constructor.

**Key logic:**
- Sets `param_1+0x9c` = 0
- Calls `FUN_004358f0()` (parent/subobject constructor)
- Returns `param_1`

**Calls:** FUN_004358f0 (parent constructor)

**Moddability:** `hardcoded`

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_0053bb30 — Force vector computation with accumulator

Compute three-component force vector from scaled inputs plus optional accumulator, apply multipliers.

**Key logic:**
- Base: `param_2[0x8/0xc/0x10] * param_2[0x14] * param_3[0x54/0x58/0x5c]` → fVar3, fVar2, fVar1 (X,Y,Z)
- fVar4 = `DAT_0059e440^2`
- If param_1 != 0: adds accumulator values at `param_1+0x17c/0x180/0x184` and increments fVar4 by `DAT_0059e440`
- Adds param_3 bias offsets at `+0x74/0x78/0x7c`
- Scales X,Y,Z by `DAT_0059fec8`; fVar4 scaled by `DAT_0059e440`
- Writes 4 floats to param_4

**Globals:**
- `DAT_0059e440` — zero constant
- `DAT_0059fec8` — force scaling factor

**Calls:** none (pure computation)

**Moddability:** `hardcoded`

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_004c69e0 — Path filename extractor

Extract filename portion from null-terminated path string at vehicle struct offset.

**Key logic:**
- String location: `param_1 + 0x4714` (path buffer)
- Finds string end via strlen loop
- Scans backward from end for last `\` backslash
- Returns pointer to character after last backslash (filename)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4714 | PathBuffer | char[], null-terminated path string |

**Moddability:** `hardcoded`

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_004e0db0 — Multi-system struct initializer

Initialize wheel systems (4x) and additional subsystems (8x) via FUN_004e0d00.

**Key logic:**
- Calls `FUN_004e0d00` on `param_1+0x5e4` (system A) and `param_1+0x628` (system B)
- Loop 4: calls `FUN_004e0d00` at `param_1+0x144 + i*0x128` and `param_1+0x188 + i*0x128` (wheel pairs)
- Loop 8: calls `FUN_004e0d00` at `param_1+0x66c + i*0x44` (subsystems)

**Calls:** FUN_004e0d00 (struct initialization)

**Moddability:** `hardcoded`

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_004e17c0 — Subsystem state machine (activate/deactivate)

Control activation/deactivation of vehicle subsystems by ID.

**Key logic:**
- Switch on param_2 (0-13):
  - Cases 0-3: Wheels 0-3 at stride 0x128. Check `+0x144` (active flag) and `+0x184` (ready flag)
  - Case 4: system at `param_1+0x5e4`
  - Case 5: system at `param_1+0x628`
  - Cases 6-13: subsystems at `param_1+0x66c + (id-6)*0x44`
- If `param_3 == 0`: activate (call `FUN_004e0d00` or `FUN_004e0e20`)
- If `param_3 != 0`: deactivate (call `FUN_004e0d70` or `FUN_004e0e70`)
- Guards prevent redundant operations

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x144 + i*0x128 | WheelActive[i] | int, wheel activation flag |
| +0x184 + i*0x128 | WheelReady[i] | char, wheel ready flag |
| +0x5e4 | SystemA | int, dedicated system |
| +0x628 | SystemB | int, dedicated system |
| +0x66c + i*0x44 | Subsystem[i] | int, 8 subsystems |

**Calls:** FUN_004e0d00 (activate), FUN_004e0d70 (deactivate), FUN_004e0e20 (wheel activate), FUN_004e0e70 (wheel deactivate)

**Moddability:** `hardcoded`

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_004e18c0 — Subsystem ready query

Query whether a subsystem by ID is ready (active and not busy).

**Key logic:**
- Switch on param_2 (0-13):
  - Cases 0-3: wheel at `param_2*0x128 + 0x144`: returns 1 if active, then checks `+0x10` byte (busy flag)
  - Cases 4-5: dedicated systems at `+0x5e4` / `+0x628`, checks active and `+0x40` byte (ready)
  - Cases 6-13: subsystems at `param_2*0x44 + 0x4d4`, checks active and ready byte
- Returns 1 (ready) or 0 (busy/inactive)

**Calls:** none (pure field reads)

**Moddability:** `hardcoded`

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_0052dc90 — Media file decode header

CD/file-backed decode header read for MPEG player.

**Key logic:**
- If flag at `param_1+0x2d3c` set: read 4 bytes via function pointer at `param_1+0x2d34+8` (vtable I/O)
- If read != 4 bytes: print "waiting for cd access" and return -1
- Convert byte order (big-endian to little-endian), call `FUN_0052da30` (validate/setup)
- If `param_1+0x2498` (header size) < 4: print "CMpegFilePlayer::DecodeHeader" error
- Else read header data via vtable; verify read size matches expected
- Set `param_1+0x2d3c` = 1 (header loaded flag), `param_1+0x24a8` = 0

**String:** `"waiting for cd access"`, `"CMpegFilePlayer::DecodeHeader"`

**Moddability:** `hardcoded`

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_004e4930 — Vehicle physics mode dispatcher

Route initialization to wet/normal/setup handler based on surface mode.

**Key logic:**
- Read mode at `param_1+0x32bc`:
  - 0 (wet/rain): calls `FUN_004a6e50` + `FUN_00441650` (wet surface setup), stores `param_2` at `+0x34ac`, calls `FUN_004e49b0`
  - 1 (normal/dry): calls `FUN_004a6e50` + `FUN_004e4e60` (dry surface setup)
  - 2 (setup/pit): stores `param_2` at `+0x34ac`, calls `FUN_004f03e0` (setup mode)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x32bc | SurfaceMode | int, 0=wet, 1=dry, 2=setup |
| +0x34ac | SurfaceParam | int, stored parameter |

**Calls:** FUN_004a6e50, FUN_00441650 (wet init), FUN_004e4e60 (dry init), FUN_004f03e0 (setup init), FUN_004e49b0

**Moddability:** `hardcoded`

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_005418b0 — Constructor init

Parent constructor call, zero fields, return this.

**Key logic:**
- Calls `FUN_0053c2a0()` (parent init)
- Zeros `param_1+0x80`, `+0x19c`, `+0x1b8`, `+0x1b4`
- Returns `param_1`

**Calls:** FUN_0053c2a0 (parent constructor)

**Moddability:** `hardcoded`

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_004f6880 — Bias value computation

Compute output as random-scaled value plus bias.

**Key logic:**
- If flag at `param_1+0x56c == 0`: use `FUN_005881f0()` (random) × `*(double*)(param_1+0x590)` (scale)
- If flag set: use `param_2` as-is
- Always add `*(double*)(param_1+0x588)` (bias)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x56c | UseExternalFlag | char, 0=generate, nonzero=use passed value |
| +0x588 | Bias | double, additive bias |
| +0x590 | Scale | double, multiplier for random value |

**Calls:** FUN_005881f0 (random number generation)

**Moddability:** `hardcoded`

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_004c6980 — Set driver name

Copy driver name string into vehicle struct.

**Key logic:**
- `_strncpy(param_1+0x4620, param_2, 0x3f)` — copy up to 63 chars
- Null-terminate at `param_1+0x465f`
- Call `FUN_004c6a10()` (name change notification)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4620 | DriverName | char[64], driver name string |

**Calls:** FUN_004c6a10 (name update handler)

**Moddability:** `configurable` — DriverName field

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_0054baa0 — Doubly-linked list node transplant

Remove node from one linked list, transplant to another list's tail.

**Key logic:**
- Unlink `param_2` from current list: reconnect prev (`+0x48`) and next (`+0x4c`)
- If `param_2` was head of list at `param_1+0x44`, update head to next node
- If `DAT_008b8f28` (global list root) exists: append `param_2` at tail of its linked list
- Walk to end of target list via `+0x4c` next pointers
- If both `param_2+0x230` and `param_2+0x40->0x230` nonzero: call `FUN_00560f40`
- Zero `param_2+0x40` (detach)

**Globals:**
- `DAT_008b8f28` — global list root pointer

**Calls:** FUN_00560f40 (node-specific cleanup)

**Moddability:** `hardcoded`

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_004f1ba0 — Wheel force parameter set (non-wet)

Store per-wheel force parameters when not in wet mode.

**Key logic:**
- If `param_1+0x32bc == 0` (wet): call `FUN_00441f00()` (wet-specific handler), return
- Otherwise store 4 parameters at wheel-specific offsets:
  - `param_1+0x3664` = param_2 (wheel 0?)
  - `param_1+0x375c` = param_3 (wheel 1?)
  - `param_1+0x3854` = param_4 (wheel 2?)
  - `param_1+0x394c` = param_5 (wheel 3?)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x32bc | WetModeFlag | int, 0=wet mode active |
| +0x3664 | WheelForce[0] | int, parameter for wheel 0 |
| +0x375c | WheelForce[1] | int, stride 0xf8 between wheels |
| +0x3854 | WheelForce[2] | int |
| +0x394c | WheelForce[3] | int |

**Calls:** FUN_00441f00 (wet mode force handler)

**Moddability:** `hardcoded`

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_004d1100 — Conditional delegate dispatch

Conditional check then delegate to render callback.

**Key logic:**
- If `param_1+0x48a4 < 0`: call `FUN_004c6f10()` (reinitialize?)
- Call `FUN_00403f70(param_1+0x48a4, param_2, param_3)` (render delegate)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x48a4 | RenderHandle | int, handle/resource ID |

**Calls:** FUN_004c6f10 (handle reinit), FUN_00403f70 (render dispatch)

**Moddability:** `hardcoded`

===
<!-- target: docs/06-session-race-logic.md -->

## FUN_004150c0 — Drawable/Resource Cleanup

Source: unknown. Iterates three linked lists of drawable resources and frees them.

**Key logic:**
- Traverses first linked list (param_1[0..3], head at param_1). For each node: if node[2] != 0 and *node non-null, calls FUN_004149a0 (pre-cleanup), then FUN_00401030 on offsets +0x88, +0x60, +0x38, +0x10 each with size 0x14, type 2, callback FUN_00414370 — removing 4 timer/callback registrations. Calls FUN_00414370 then frees inner resource via FUN_00587bcf. Frees node. Zeros list head.
- Traverses second linked list (param_1[4..7]). Calls FUN_00414380 then frees.
- Traverses third linked list (param_1[8..11]). Calls FUN_00414fe0, removes 2 timers at offsets +0x34 and +0xc, frees.

**Calls:** FUN_004149a0, FUN_00401030 (timer remove), FUN_00414370, FUN_00587bcf (free), FUN_00414380, FUN_00414fe0

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b9e40 — Pit Service Steering Animation Step

Source: pit.cpp likely. Advances pit crew wheel service animation state machine.

**Key logic:**
- Switch on state at *param_1+0xf8c:
  - Case 0: Calls FUN_004b87a0, adds _DAT_0059e600 to result, stores via FUN_004b86e0, sets state=5.
  - Case 1: Similar but subtracts _DAT_0059e600.
  - Case 2: fVar1 = -_DAT_008afe90 → calls FUN_004b9d00 with fVar1 * _DAT_005acd18.
  - Case 3: FUN_004b9d00(-_DAT_008afe90 * _DAT_005acd14).
  - Case 4: FUN_004b9d00(-_DAT_008afe90).
  - Case 6: FUN_004b9d00(_DAT_008afe90).
  - Case 7: FUN_004b9d00(_DAT_008afe90 * _DAT_005acd14).
  - Case 8: fVar1 = _DAT_008afe90 → FUN_004b9d00(fVar1 * _DAT_005acd18).
  - Default: return.

**Struct offsets (param_1 indirect via *param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xf8c | ServiceAnimState | int, animation state for wheel service |

**Calls:** FUN_004b87a0, FUN_004b86e0, FUN_004b9d00

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b67d0 — Steering Alignment Tolerance Check

Source: pit.cpp likely. Compares steering angle against per-gear threshold to determine if alignment service needed.

**Key logic:**
- Reads gear index from param_1+0x9ac, subtracts 1.
- Selects angle tolerance based on gear: case 0=0.04909rad (2.81°), 1=0.02454rad (1.41°), 2=0.01636rad (0.94°), 3=0.01227rad (0.70°), default=0.09817rad (5.62°).
- Compares ABS(param_2) < tolerance → returns early flag if under threshold.
- Loads multiplier from second switch (gear-dependent global: _DAT_005acd60/5c/58/44 or _DAT_0059e84c default).
- Computes fVar1 = multiplier * param_3, clamps below to 2*tolerance.
- Returns comparison of param_2 vs fVar1 as byte pair CONCAT11(flag, 0/1).

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x9ac | CurrentGear | int, gear index for threshold selection |

**Calls:** None leaf

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e16f0 — Particle Effect World Transform

Source: effects/particle code. Transforms 17 particle positions from local to world space.

**Key logic:**
- Guarded by DAT_008aceb8 global enable flag.
- Iterates 17 entries (stride 28 bytes = 7 ints) starting at param_1+0x998.
- If entry active byte (at pfVar1[-2] i.e. entry+0x998-8 = +0x990) non-zero:
  - Computes 3D transform: local_c = param_2×rotation + param_3 translation for each axis.
  - Calls FUN_004cce90 with transformed position and entry data.
- 17 iterations correspond to component count (likely wheels + body parts).

**Calls:** FUN_004cce90 (particle/spawn callback)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b3bd0 — Random Noise Table Initialization

Source: weather/rain code. Seeds RNG and generates two 256-entry noise tables.

**Key logic:**
- Sets *param_1 = 0.0.
- Seeds RNG with GetTickCount() via FUN_005884e0.
- Generates 256 uniform random floats in [0,1): val = rand() * _DAT_0059e6e0.
- Generates 256 signed random floats in [-1,1): val = rand() * _DAT_005accf0 - _DAT_0059e43c.
- Calls FUN_0055687b to finalize table at param_1+0x201.

**Calls:** GetTickCount, _rand, FUN_005884e0 (RNG seed), FUN_0055687b

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042dcc0 — Array Element Getter (Stride 8)

Source: unknown. Bounds-checked access into array of 8-byte elements.

**Key logic:**
- If param_2 in range [0, *(param_1+8)): returns element at *(param_1+0xc) + param_2*8.
- Otherwise returns 0.

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x08 | ArrayCount | int, element count |
| +0x0c | ArrayData | pointer to array of 8-byte elements |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f68b0 — Tire Force/Torque Computation

Source: vehicle/tire physics. Computes tire lateral force and aligning torque.

**Key logic:**
- If *(param_1+0x1ec) != 0 (tire active):
  - *param_5 (self-aligning torque) = polynomial in param_2 (slip angle) + camber term + constant.
  - *param_4 (lateral force magnitude) = ABS of double at param_1+0x250.
  - param_4[1] = ABS of double at param_1+0x288.
  - param_4[2] = polynomial in param_2 (longitudinal/combined).
- If inactive: zeros all outputs.

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1ec | TireActive | char, active flag |
| +0x1f8 | ForceConst1 | double |
| +0x200 | ForceLinCoeff | double |
| +0x208 | ForceQuadCoeff | double |
| +0x210 | ForceConst2 | double |
| +0x218 | TorqueLinCoeff | double |
| +0x220 | TorqueQuadCoeff | double |
| +0x228 | TorqueCamberCoeff | double |
| +0x250 | LatForcePeak | double |
| +0x288 | LongForcePeak | double |
| +0x2e8 | CamberAngle | double |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e1970 — Effect Data Table Initialization

Source: effects code. Initializes 14-element effect parameter array.

**Key logic:**
- Loops iVar2 from 0 to 13.
- Calls FUN_004e18c0(iVar2) for each index, stores result at param_1+0xb70[i].

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xb70 | EffectParams | array of 14 effect parameter values |

**Calls:** FUN_004e18c0 (effect param getter by index)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00545930 — Linked List Node Insert (Audio/Scene Graph)

Source: audio/scene graph code. Inserts a node at end of linked list, tracking count.

**Key logic:**
- Allocates 0x38-byte node. If fails, iVar4=0.
- If allocation succeeds: calls FUN_00560ba0(param_2, *(param_1+0x158)).
- Reads list head at param_1+0x15c:
  - If empty: sets head = new node.
  - If param_3==0 or param_3->+0x230==0: walks from head to tail (following +0x34), appends.
  - Else (param_3 specified): walks from param_3->+0x230's +0x2c child list.
- Sets node->prev = iVar5, node->next = 0.
- Increments count at param_1+0x158.

**Calls:** operator_new (0x38), FUN_00560ba0

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e513e — Speed Ratio Clamp

Source: effects code. Computes and clamps speed ratio parameter.

**Key logic:**
- Computes: *(param_1+0x3570) = (in_ST0 - *(param_1+0x3994) + _DAT_0059e828) * _DAT_0059e444.
- Clamps below: if < DAT_0059e440 → set to 0.
- Clamps above: if > _DAT_0059e43c → set to 1.0 (0x3f800000).

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x3570 | SpeedRatio | float, clamped 0-1 |
| +0x3994 | SpeedOffset | float, subtracted from input |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004bbfc0 — Pit Crew State Machine (Input Processing)

Source: pit crew code. Processes input packet to trigger crew state changes.

**Key logic:**
- If packet type match (param_2 & 0xFC0000 == 0x680000):
  - If param_1[0xc] == 0 (idle): Sets param_1[0xc]=2 (active). If param_1[0xd]==0, sets from packet byte. Clears car+0x105d flag, calls FUN_004e0ed0 (hide indicator). Calls FUN_0042af40 (sound/action).
- Else (non-matching packet):
  - If param_1[0xc]==2: resets to 0 (idle).
  - If car+0x105d != 1: sets to 1, calls FUN_004e0ed0 (show indicator).

**Struct offsets (param_1 indirect via *param_1 = car):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x105d | PitIndicatorFlag | char, 0=hide 1=show indicator |
| +0x1054 | PitIndicatorParam | param for indicator call |
| param_1[0xc] | CrewState | int, 0=idle 2=active |
| param_1[0xd] | CrewTimer | int, timer countdown |

**Calls:** FUN_004e0ed0 (show/hide pit indicator), FUN_0042af40 (pit sound)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00543800 — 3D Position Set with UIRefresh

Source: UI/positioning code. Sets X/Y/Z position and triggers UI refresh.

**Key logic:**
- Sets param_1+0x17c = param_2 * _DAT_0059e460 (X).
- Sets param_1+0x180 = param_3 * _DAT_0059e460 (Y).
- Sets param_1+0x184 = param_4 * _DAT_0059e460 (Z).
- Calls FUN_00541670 with packed color (param_2*0x100+param_3)*0x100+param_4.
- Sets DAT_008b8f28+0xec bit 0x800 (dirty flag).

**Globals:**
- `DAT_008b8f28` — UI state struct, bitflag at +0xec

**Calls:** FUN_00541670 (color/position update)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004fe060 — Car Position Target Check

Source: race/position logic. Checks if car has reached target position for service.

**Key logic:**
- If DAT_007c56a0 & 1 (multiplayer flag):
  - If DAT_008ab6e4 != 2: return (wrong game phase).
  - If FUN_004b9a00() != 0 (player not in pit): return.
- Calls FUN_004fc910(param_2) — compute target position.
- If ABS(pos - target) <= _DAT_0059e450 (threshold): sets *(param_1+4)=2.0f (arrived), calls FUN_004fd6f0.
- Else: sets *(param_1+4)=0 (still moving), calls FUN_004fd6f0.

**Globals:**
- `DAT_007c56a0` — multiplayer flags
- `DAT_008ab6e4` — ScoringGate / race phase

**Calls:** FUN_004b9a00 (is player in pit?), FUN_004fc910, FUN_004fd6f0

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f17a0 — Effect Parameter Setter

Source: effects code. Sets three effect configuration values.

**Key logic:**
- param_1+0x3994 = param_2.
- param_1+0x3570 = param_4.
- param_1+0x3978 = param_3 * param_1+0x397c.

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x3994 | EffectParam1 | int/float |
| +0x3570 | EffectParam2 | int/float |
| +0x3978 | EffectParam3 | float, scaled by +0x397c |
| +0x397c | EffectScale | float, multiplier |

**Moddability:** configurable — external code sets params

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054c110 — Render Flag Setter (Bitmask)

Source: render/UI code. Sets render state flags via bitmask.

**Key logic:**
- If param_3 & 0x800: param_1+0x234 = param_2; param_1+0x3c |= 0x800 (dirt flag).
- If param_3 & 0x1000: param_1+0x238 = param_2; param_1+0x3c |= 0x1000.

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x234 | RenderTarget1 | int |
| +0x238 | RenderTarget2 | int |
| +0x03c | DirtyFlags | uint, bitmask |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00512334 — Driver State Flag Set

Source: driver/state code. Sets a state flag when condition met.

**Key logic:**
- If *(param_1+0x117) < 8: sets bit 2 at param_1+0x60, sets param_1+0x118 = 8.

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x117 | SomeCounter | byte, compared against 8 |
| +0x060 | StateFlags | uint, bit 2 set |
| +0x118 | StateValue | byte, set to 8 |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00545670 — Camera Position Getter

Source: camera code. Returns camera XYZ position components.

**Key logic:**
- If param_2 != NULL: *param_2 = *(param_1+0x11c) (X).
- If param_3 != NULL: *param_3 = *(param_1+0x124) (Y).
- If param_4 != NULL: *param_4 = *(param_1+300) (Z).

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x11c | CameraPosX | int/float |
| +0x124 | CameraPosY | int/float |
| +300 (0x12c) | CameraPosZ | int/float |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054e190 — Camera Distance Getter

Source: camera code. Simple getter for camera distance parameter.

**Key logic:**
- Returns *(param_1 + 0x120).

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x120 | CameraDistance | int/float |

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_00415900 — Struct Destructor (Internal Buffer Cleanup)

Source: unknown. Frees internal pointer arrays within a struct then optionally frees the struct itself.

**Key logic:**
- Iterates 4 groups of pointer slots at offsets +0x2c, +0x22, +0x18, +0xe — each group has 2 elements
- For each non-null pointer, calls FUN_00587bcf (memory deallocation)
- Checks pointer at param_1[0] and frees if non-null
- If `param_2 & 1` is set, frees param_1 itself (self-destruct flag)
- Calls FUN_004149a0 (likely base initializer/cleanup) before freeing

**Calls:** FUN_004149a0 (init/cleanup), FUN_00587bcf (memory free/dealloc)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004ef6c0 — Coordinate Transform with Offset

Source: unknown. Converts a position + offset from one coordinate space to another using a transformation matrix.

**Key logic:**
- Calls FUN_00566e40 (math init) and FUN_004ef680 (build transform matrix/basis)
- Reads position vector at param_1 + 0x34d4 (X), 0x34d8 (Y), 0x34dc (Z)
- Adds param_2 offset components to position
- Computes: output = (source_position + offset) - (matrix * vector + source_position)
- The subtraction effectively computes a relative displacement in the new coordinate space
- Writes result to param_4 as 3 floats

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x34d4 | PosX | float, world position X |
| +0x34d8 | PosY | float, world position Y |
| +0x34dc | PosZ | float, world position Z |

**Calls:** FUN_00566e40 (math/vector init), FUN_004ef680 (build transform matrix)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051dc01 — Packed Pixel Copy with Palette Lookup

Source: unknown. Copies pixel data from a packed 3-byte source format to 8-bit output using a color palette, with palette-fill on missing entries.

**Key logic:**
- Source data is packed in 3-byte groups per pixel (3 bytes per pixel encoding)
- Decodes using: `(bVar3 >> 3)`, `(pbVar8[1] >> 2)`, `(*pbVar7 >> 3)` as palette indices — likely RGB 332 or similar
- Palette is stored at `*(*(param_1 + 0x1a4) + 0x18)` — a 2-byte per entry lookup table
- If palette entry is 0, calls FUN_0051db31 to fill/generate it
- Output pixel = palette value - 1
- param_4 controls number of pixels to process
- param_1 + 0x5c controls bytes per pixel (stride)
- param_2 is source buffer, param_3 is destination pixel array

**Calls:** FUN_0051db31 (palette entry fill/generate if missing)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051c176 — Monochrome Buffer Byte-Duplicate Copy

Source: unknown. Copies pixel data duplicating each source byte to two consecutive destination bytes (monochrome to 16-bit expansion).

**Key logic:**
- Copies data from source buffer to destination, writing each byte twice
- param_4 points to source data array
- param_3 provides an offset applied as `source_ptr = param_4 - (param_3 - param_4_base)` — adjusts for memory layout
- Stride per element: param_1 + 0x5c (bytes copied per entry)
- Element count: param_1 + 0x110
- Inner loop: reads byte from source, writes to `puVar2[0]` and `puVar2[1]` = same byte value
- Effect: expands 8-bit data to 16-bit (two copies per source byte) — likely font/texture rendering for 16-bit display

**Calls:** none significant

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f2320 — Vehicle Dynamics State Reset

Source: unknown. Zeroes multiple fields in a vehicle dynamics struct, resetting force/acceleration accumulators.

**Key logic:**
- Zeroes 9 consecutive float-sized fields at offsets 0x34ec–0x350c (force/accel accumulators)
- Zeroes 4 entries at stride 0xF8 (0x3e * 4) starting at 0x35b0 — wheel-specific accumulators
- Checks flag at param_1 + 0x32bc — if 0, calls FUN_0043e360 (additional reset)
- Used when resetting vehicle physics state for a new frame or session

**Calls:** FUN_0043e360 (conditional additional reset)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b71e0 — Buffer Pool Allocator Initialization

Source: unknown. Clears a linked list of file/buffer nodes, then allocates a new pool of objects sized 0xB0.

**Key logic:**
- Calls FUN_004b5f60, FUN_004b5e50 (base cleanup)
- Walks linked list at param_1 + 0x6c0, freeing each node and its contents using FUN_00587bcf
- Zeroes linked list head (0x6c0–0x6cc), state fields (0xf38, 0xf3c, 0x6d0)
- Sets 0x9b8, 0x9bc to -1 (invalidate indices)
- Sets 0xf8c to 5 (default allocation tier)
- Based on enum at param_1 + 0x9a4 (0–4), selects pool size: 0x10, 0x18, 0x20, 0x30, or 0x60 elements
- Each element is 0xB0 bytes — allocates via `operator_new(iVar3 * 0xB0 + 4)`
- Stores pool pointer at param_1 + 0x9b0, count at header

**Calls:** FUN_004b5f60 (cleanup), FUN_004b5e50 (cleanup), FUN_00587bcf (free), FUN_004b6130 (init), FUN_004b46b0 (element init), operator_new (allocation)

**Moddability:** `configurable` — pool size tier depends on enum at param_1 + 0x9a4

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042dce0 — Bounded Array Element Accessor

Source: unknown. Returns an element from a packed 8-byte stride array, with bounds checking.

**Key logic:**
- Validates: `0 <= param_2 < *(param_1 + 8)` (bounds check)
- If valid: returns `*(*(param_1 + 0xC) + 4 + param_2 * 8)` — index into array of 8-byte records, returning second 4-byte field
- Returns 0 if index out of bounds

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b5120 — Vehicle Identity String Comparison

Source: unknown. Compares driver name and path-based identifier strings for vehicle identity matching.

**Key logic:**
- Reads path string from param_2 + 0x4714
- Finds last backslash `\` in path (extracts filename)
- Compares filename against string at param_1 + 0x41 (2-byte char comparison)
- If filename matches, also compares param_2 + 0x4620 (DriverName) against param_1 + 1
- Returns 1 if both match, negative value (via `(1 - (uint)bVar5) - (uint)(bVar5 != 0)`) if no match
- The comparison uses wide-character (2-byte) string compare

**Struct offsets (param_2):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4620 | DriverName | wide string, vehicle driver name |
| +0x4714 | FilePath | wide string, path-based identifier |

**Calls:** none significant

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054bf10 — State Array Word-Sign Extension

Source: unknown. Iterates a linked list of state blocks, sign-extending lower 16-bit values in each state array.

**Key logic:**
- Walks linked list starting at param_1 + 0x204 (next link at +0x10)
- For each node: processes uint array at +0x11c, count at +0x118
- Per element: masks upper 16 bits, sign-extends lower 16 bits and merges back
- Effect: `result = (original & 0xFFFF0000) | sign_extend(original & 0xFFFF)`
- Converts unsigned lo-word to signed while preserving hi-word flags

**Calls:** none significant

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e3940 — Repeated Position Offset Transform

Source: unknown. Computes relative position from a reference point and repeatedly transforms it.

**Key logic:**
- Reads reference position from param_1 + 0x48 (X), 0x4c (Y), 0x50 (Z)
- Computes delta = param_3 - reference_position (3 components)
- Loops `param_1 + 0xba8` times, calling FUN_004def70(delta, param_4)
- Each call transforms the delta vector through some operation

**Calls:** FUN_004def70 (vector/position transform)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00507ac4 — Color Value Packing with Scaled Float Input

Source: unknown. Packs RGB float values into a uint with scaling and global multiplier.

**Key logic:**
- If param_1 + 0x1048 flag set, transforms param_4 via FUN_00506ce2 (color space conversion?)
- Uses param_1 + 0x1058 as element count
- Indexing: `((param_3 & 3) + (param_2 & 3) * 8 + (uVar8 & 3)) * 4` — selects from a 4x4x4 or similar 3D lookup
- For each element: computes `ROUND(value * DAT_0059fec8 + offset)`, packs R, G, B as consecutive bytes into uint
- DAT_0059fec8 is a global brightness/contrast scaling factor

**Globals:**
- `DAT_0059fec8` — float multiplier for color value scaling

**Calls:** FUN_00506ce2 (optional color space transform)

**Moddability:** `configurable` — DAT_0059fec8 global multiplier

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e3890 — State Array Reset

Source: unknown. Resets an array of state entries by calling a clear function on each.

**Key logic:**
- Loops param_1 + 0xba8 times (array element count)
- Array starts at param_1 + 0xbac, stride 0x2ec per element
- Per iteration: calls FUN_004df110(0, 0xffffffff) (reset/clear), zeroes field at element + 0x18

**Calls:** FUN_004df110 (state entry clear)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00548d40 — Linked List Node Appender with Lazy Allocation

Source: unknown. Appends a node to a singly-linked list, allocating the head node lazily if needed.

**Key logic:**
- Checks linked list head at param_1 + 0x170
- If null: allocates 0x1c-byte node via `operator_new`, initializes via FUN_00548aa0
- If non-null: walks to end of chain (via +0x18 links), appends new node
- Calls FUN_00548ad0(param_2, param_3) — if non-zero, returns -1 (error/conflict)
- Increments counter at param_1 + 0x16c
- Returns 0 on success, -1 on error

**Calls:** FUN_00548aa0 (node init), FUN_00548ad0 (validation check), operator_new

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00538940 — Performance/Sector Time Accumulator

Source: unknown. Accumulates time penalty or performance adjustment based on sector timing data.

**Key logic:**
- Calls FUN_005389b0 twice with values from param_1 + 0xb12, param_1 + 0xb1e (release timestamps?)
- Calls FUN_005383d0 (base timing update)
- Backward-searches table indexed by UNK_005b7dec into array at param_1 + 0xa74 (short array, stride 4)
- Stops when non-zero short found (sector completed flag?)
- Computes: `*(param_1 + 0x169b) += iVar1 * 3 + 0x11` — accumulation proportional to remaining sectors

**Calls:** FUN_005389b0 (release/clear), FUN_005383d0 (base update)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c1670 — Timer Countdown with State Transition

Source: unknown. Increments a countdown counter and triggers a state transition when threshold is reached.

**Key logic:**
- Checks param_1 + 0xb150 (active flag)
- If active: increments counter at param_1 + 0xb148
- Calls FUN_004c1190 (get threshold)
- If counter >= threshold: sets param_1 + 0xb144 = 3 (state/phase change)
- Sets param_1 + 0xb14c = 1 (completion flag)
- Clears param_1 + 0xb150 (deactivates timer)

**Calls:** FUN_004c1190 (threshold retrieval)

**Moddability:** `configurable` — threshold from FUN_004c1190

<!-- target: docs/06-session-race-logic.md -->

## FUN_00545030 — Doubly-Linked List Tail Insertion

Source: unknown. Appends a node to the tail of a doubly-linked list.

**Key logic:**
- Walks linked list starting at param_1 + 0xf8 following +0x1b8 (next) pointers
- If list empty: sets param_1 + 0xf8 = param_2 as head
- If non-empty: appends at tail, sets prev link (0x1b4) and next link (0x1b8)
- New node's next = 0, prev = old tail

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004fffb0 — Zone/Threshold Comparison with Conditional Action

Source: unknown. Tests if a value falls within a range defined by two thresholds, triggering an action if so.

**Key logic:**
- Reads float from param_3 + 4 (value to test)
- Two conditions trigger FUN_004b3a90(param_3):
  1. `value < param_2 AND param_1 + 0x1bc < value` — value between lower bound (param_1+0x1bc) and threshold param_2
  2. `param_2 < value AND value < param_1 + 0xc` — value between threshold param_2 and upper bound (param_1+0xc)
- The range boundaries come from the struct at param_1

**Calls:** FUN_004b3a90 (conditional action when value in zone)

**Moddability:** `configurable` — thresholds from param_1 fields

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f1b10 — Ratio Computation with Clamping

Source: unknown. Computes absolute ratio of two float values and clamps to range.

**Key logic:**
- Computes: `ABS(value_at_0x3964 / value_at_0x3968)` using x87 extended precision (float10)
- Clamps to [DAT_0059e440, _DAT_0059e43c]
- Returns clamped ratio
- Used for slip ratio, wear ratio, or similar physics proportion calculation

**Globals:**
- `DAT_0059e440` — float, lower clamp limit
- `_DAT_0059e43c` — float, upper clamp limit

**Moddability:** `configurable` — clamp limits via DAT_ globals

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054fa50 — Linked Node Destruction

Source: unknown. Frees a linked list node and its associated data buffer.

**Key logic:**
- If param_1 + 0x1e0 is non-null:
  - Frees internal buffer at `*(*(param_1 + 0x1e0) + 8)` via FUN_00587bcf
  - Frees the node struct at param_1 + 0x1e0 via FUN_00587bcf
  - Nulls the pointer

**Calls:** FUN_00587bcf (memory free/dealloc)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051234d — Flag-Based Session Mode Selector

Source: unknown. Returns session mode value based on a flag byte, setting a mode bit.

**Key logic:**
- Checks param_1 + 0x113 (byte flag — possibly QualifyingAbility or similar)
- If non-zero: sets bit 1 at param_1 + 0x60 (mode/state flag), returns 7 (race? qualifying?)
- If zero: returns 1 (practice/pit?)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004ef4f0 — Position Update with Telemetry Recording

Source: unknown. Updates a stored position and records to a ring buffer if within capacity.

**Key logic:**
- Checks if `_DAT_008afea0 <= param_1 + 0x4014 + _DAT_005acb5c` — if true, returns early (no update needed)
- Sets `param_1 + 0x4014 = _DAT_008afea0` (stores new position/reference)
- If DAT_0083ee60 < 0x3ff (ring buffer not full):
  - Increments DAT_0083ee60 (entry count)
  - Adds 0x1b0 to DAT_008aae64 (ring buffer offset — near DAT_008aae70 RingBufferCounter)
- Calls FUN_004b33b0(2, 0, 0, param_1+4, param_1+0x34ac, 0) — telemetry recording with type 2

**Globals:**
- `_DAT_008afea0` — float, current value to store
- `_DAT_005acb5c` — float, tolerance offset
- `DAT_0083ee60` — int, ring buffer entry count (incremented up to 0x3ff)
- `DAT_008aae64` — int, ring buffer write offset (near DAT_008aae70 RingBufferCounter)

**Calls:** FUN_004b33b0 (telemetry/data recording, type 2)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054fb70 — Linked List Flag Bit Extraction

Source: unknown. Extracts bit 6 from a flag byte in the head of a linked list.

**Key logic:**
- Dereferences linked list head at param_1 + 0x204
- Reads byte at head + 0x14
- Extracts bit 6: `(value & 0x40) >> 6`
- Returns 0 or 1

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_005386c0 — RankRedistribution (position/score redistribution)

Source: likely steward/standings.cpp. Redistributes ranked positions or scores across a field, ensuring values fit within a maximum bound.

**Key logic:**
- Zeros 8 counters at param_1+0xb32 (histogram bins for rank counts)
- Reads current count from param_1+0x144a, processes up to 0x23d (573) entries
- For each entry index at param_1+0xb52[]: gets its current rank from a lookup table, clamps to max allowed (uVar11), increments bin counter
- Accumulates weighted sums into param_1+0x169b and param_1+0x169f (total score, secondary score)
- Performs redistribution pass: for bins with excess entries, distributes them downward to higher ranks
- Final pass: for each rank from max down to 0, adjusts any misplaced entries upward

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xb32 | RankHistogram[8] | 8 short counters per rank bucket |
| +0xb52 | SortedIndexArray[] | int array of sorted entry indices |
| +0x144a | EntryCount | current number of entries |
| +0x169b | TotalScoreAccum | int, aggregated score sum |
| +0x169f | SecondaryAccum | int, secondary accumulator |

**Calls:** none (uses param_2 data directly)

**Moddability:** `hardcoded` — uses internal struct arrays

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051e5d7 — TableWeightedMix (multi-table weighted sum)

Source: likely audio/effects.cpp. Sums weighted values from multiple lookup tables indexed by source data bytes, produces blended output array.

**Key logic:**
- Reads output element count from param_1+0x5c (iVar4) and table count from param_1+100 (iVar5)
- For each of param_4 input entries from param_3[]:
  - Gets source byte pointer via offset table
  - For each output element: sums contributions from iVar5 different tables indexed by source byte, writes summed char to output
- Inner loop: `cVar1 = Σ_table[i]_weight[source[j]]` across all tables, accumulating byte sum
- Operates on arrays of pointers: each table is a flat byte weight array

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x5c | OutputElementCount | int, elements per chunk |
| +0x64 (100) | TableCount | int, number of weight tables |
| +0x1a4 | TableArrayPtr | int, pointer to table array |
| *(param_1+0x1a4)+0x18 | TableArray | int*, array of table base pointers |

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b81a0 — SortedLinkedListInsert (merge-sort insert with name)

Source: likely steward/standings.cpp. Inserts scored node into sorted doubly-linked list using merge sort.

**Key logic:**
- Builds default name string if param_2 empty
- Allocates 12-byte data node: stores score from param_1+0xf38, next=0, prev=-1
- Calls FUN_00566650(name) on node
- Allocates 16-byte list wrapper, inserts into doubly-linked list at param_1+0x6c0/0x6c4
- Increments count at param_1+0x6cc
- If count > 1: mergesort list by float score comparison
- Splits list at midpoint via FUN_004bb2e0, merges by score order
- Rebuilds prev links, sets sorted flag at +0x6d0=1

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x6c0 | ListHead | int*, linked list head |
| +0x6c4 | ListTail | int*, linked list tail |
| +0x6c8 | ListCursor | int*, current position |
| +0x6cc | ListCount | int, number of elements |
| +0x6d0 | SortedFlag | byte, 1=sorted |
| +0xf38 | ScoreValue | float, sort key |

**Calls:** FUN_004b8360, FUN_0058815f (sprintf), FUN_00566650, FUN_004bb2e0, operator_new

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051c1cd — BufferInterleaveCopy (sample duplication interleave)

Source: likely audio/effects.cpp or streamer. Copies source data to interleaved destination with sample duplication (each byte written twice consecutively).

**Key logic:**
- Reads element count from param_1+0x110, element stride from param_1+0x5c
- For each entry in param_3[] (count = element count):
  - Copies bytes from source pointer (taken from param_4[entry]) to destination (param_4[0] + entry * stride)
  - Each source byte is written twice: `dest[i] = src[j]`, `dest[i+1] = src[j]` (interleaving/padding)
  - Calls FUN_0051593f(iVar2, iVar6, iVar2, iVar6+1, 1, stride) — likely a memory fill/copy operation
- Steps by 2 through output indices

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x5c | Stride | int, bytes per output element |
| +0x110 | ElementCount | int, number of elements to process |

**Calls:** FUN_0051593f (mem fill/copy)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00435240 — StateFlagCheck (inverse bool wrapper)

Source: likely game/state.cpp. Returns whether a subsystem is NOT active, by inverting FUN_00418940.

**Key logic:**
- Calls FUN_00418940() — returns 0=active, non-zero=inactive
- Returns bool: `FUN_00418940() == '\0'` — true when active flag is zero

**Calls:** FUN_00418940 (state query)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b84f0 — SortedListSeekByValue (cursor advance to threshold)

Source: likely steward/standings.cpp. Advances sorted linked list cursor to first element whose score exceeds a threshold value.

**Key logic:**
- If list is empty (count < 1): returns 0
- Starting from list head at param_1+0x6c0, walks forward while `*(float*)*node <= *(float*)(param_1+0xf38)` (threshold)
- Tracks iteration count iVar3
- If reached end (iVar3 == count): wraps cursor back to head
- Otherwise: advances cursor iVar3 steps from head
- If cursor is valid: reads compare value from node data for next call
- Returns 0 if list empty, non-zero otherwise

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x6c0 | ListHead | int*, linked list head |
| +0x6c8 | ListCursor | int*, current position |
| +0x6cc | ListCount | int, element count |
| +0xf38 | SeekThreshold | float, comparison threshold |

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054e080 — FlagSetLoop (bitmask OR on objects)

Source: likely game/entity.cpp. Sets a flag bit on managed objects in a collection.

**Key logic:**
- Calls FUN_00545f40 (pre-operation hook)
- Iterates through objects at param_1+0x124 (array), stride 0x24 per entry
- For each object: reads *(int*)(object_ptr + 4), accesses +0x9c field
- If bit 1 set at +0x9c: ORs with bit 0 (`uVar2 | 1`)
- Processes *(param_1+0x120) iterations

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x120 | ObjectCount | int, number of objects |
| +0x124 | ObjectArrayPtr | int, pointer to object handle array |

**Calls:** FUN_00545f40

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00507bc5 — ColorVertexTransform (RGB565 fixed-point conversion)

Source: likely renderer/lighting.cpp. Transforms float color/vertex data to packed 16-bit RGB565 format with offset.

**Key logic:**
- If param_1+0x1048 != 0: calls FUN_00506ce2(param_4) for coordinate transform
- Gets source texture/vertex array from param_1+0x2c (iVar5)
- Calls FUN_00507473 (pre-transform)
- For *(param_1+0x1058) iterations:
  - Reads float from (iVar5 + ((param_3&3)+(param_2&3)*8)*4 + (uVar8&3)*4) — bilinear sample
  - Converts 3 consecutive floats to fixed-point RGB565 packed ushort:
    - R: `ROUND(r * _DAT_005accd0 + offset) << 6`
    - G: `ROUND(g * _DAT_005accd8 + offset) << 5`
    - B: `ROUND(b * _DAT_005accd0 + offset)`
  - Step 0x10 through input array per iteration

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x2c | SourceDataPtr | int, source float array |
| +0x1048 | TransformFlag | int, enable coordinate transform |
| +0x1058 | VertexCount | uint, number of vertices |

**Globals:**
- `_DAT_005accd0` — R/B channel scale factor (fixed-point multiplier)
- `_DAT_005accd8` — G channel scale factor (different precision)

**Calls:** FUN_00506ce2 (coord transform), FUN_00507473 (pre-transform hook)

**Moddability:** `configurable` — scale factors from render config

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f6950 — QuadraticForceModel (suspension/tire force quadratic)

Source: likely hdvehicle/suspension.cpp. Evaluates a quadratic force model (spring/damper) with absolute magnitude outputs, if enabled by flag.

**Key logic:**
- Checks flag at param_1+0x2f8: if zero, zeroes all outputs and returns
- If enabled:
  - `*param_4 = A*param_2 + B*param_2² + C` (quadratic force, using doubles at +0x31c/+0x324/+0x314)
  - `param_3[0] = ABS(*(double*)(param_1+0x34c))` (magnitude 1)
  - `param_3[1] = ABS(*(double*)(param_1+900))` (magnitude 2, offset 0x384)
  - `param_3[2] = A2*param_2 + B2*param_2² + C2` (second quadratic at +0x304/+0x30c/+0x2fc)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x2f8 | ModelEnabledFlag | byte, enables force evaluation |
| +0x2fc | QuadraticC | double, constant term |
| +0x304 | QuadraticA | double, linear term coeff |
| +0x30c | QuadraticB | double, quadratic term coeff |
| +0x314 | OutputQuadC | double, output quadratic constant |
| +0x31c | OutputQuadA | double, output quadratic linear |
| +0x324 | OutputQuadB | double, output quadratic squared |
| +0x34c | AbsOutput1 | double, absolute magnitude 1 |
| +0x384 (900) | AbsOutput2 | double, absolute magnitude 2 |

**Calls:** none (pure math)

**Moddability:** `configurable` — coefficients from suspension .hdv

<!-- target: docs/06-session-race-logic.md -->

## FUN_005084f5 — Color565Transform (16-bit color packing with offset)

Source: likely renderer/lighting.cpp. Converts float color pairs to packed 16-bit RGB565 format (2 pixels per 32-bit word).

**Key logic:**
- If param_1+0x1048 != 0: calls FUN_00506ce2(param_4) for coordinate transform
- Gets source array from param_1+0x2c
- Calls FUN_00507473 (pre-transform)
- For *(param_1+0x1058) iterations:
  - Reads float from texture lookup (same bilinear formula as FUN_00507bc5)
  - Packs 2 consecutive float pixels into one 32-bit dword:
    - Low 16 bits: `ROUND(G * _DAT_0059f120 + offset)` (G channel)
    - High 16 bits: `ROUND(R * _DAT_0059f120 + offset)` (R channel)
    - Unlike FUN_00507bc5: no B channel; uses _DAT_0059f120 instead of _DAT_005accd0
- Step 0x10 through input array

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x2c | SourceDataPtr | int, source float array |
| +0x1048 | TransformFlag | int, enable coordinate transform |
| +0x1058 | PixelCount | uint, number of pixels |

**Globals:**
- `_DAT_0059f120` — Color scale factor (different from FUN_00507bc5)

**Calls:** FUN_00506ce2 (coord transform), FUN_00507473

**Moddability:** `configurable` — scale factor from render config

<!-- target: docs/06-session-race-logic.md -->

## FUN_00542400 — StructFieldArrayCopy (16-dword memcpy)

Source: likely game/entity.cpp. Copies 64-byte block from param_1+0x15c to param_2.

**Key logic:**
- If param_2 non-null: copies 16 dwords (64 bytes) starting from param_1+0x15c to param_2

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x15c | SourceData[16] | undefined4[16], 64-byte data block |

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004ee230 — ThrottleBrakeOverride (dynamic force override)

Source: likely hdvehicle/engine.cpp. Computes a dynamic throttle/brake/clutch force ratio and overrides default values when they match a sentinel.

**Key logic:**
- Computes ratio: `fVar1 = *(param_1+0x3994) / *(param_1+0x3998)` (current/max)
- Computes cubic-scaled force: `fVar1 = fVar1 * *(param_1+0x3570) * fVar1³ * _DAT_0059e450`
- For each of 3 output channels (+0x77c, +0x790, +0x7a4):
  - Copies default value from +0x3d48/+0x3d4c/+0x3d50
  - If default == sentinel (`_DAT_005ad1f8`): overrides with computed fVar1

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x3570 | ForceScaling | float, base force scaling |
| +0x3994 | CurrentValue | float, current (rpm/load) |
| +0x3998 | MaxValue | float, maximum value |
| +0x3d48 | DefaultOutput1 | float |
| +0x3d4c | DefaultOutput2 | float |
| +0x3d50 | DefaultOutput3 | float |
| +0x77c | Output1 | float, throttle/brake output 1 |
| +0x790 | Output2 | float, output 2 |
| +0x7a4 | Output3 | float, output 3 |

**Globals:**
- `_DAT_005ad1f8` — Sentinel value (likely 0.0 or -1.0, indicating "use dynamic")
- `_DAT_0059e450` — 0.5 constant

**Calls:** none (pure math)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c69b0 — ShortStringSet (7-char name + hash)

Source: likely game/registry.cpp. Stores a 7-character string and computes its hash.

**Key logic:**
- Copies up to 7 chars from param_2 to param_1+0x4708 via _strncpy
- Null-terminates at param_1+0x470f
- Calls FUN_00587ece to compute hash, stores at param_1+0x4710

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4708 | NameBuffer[7] | char[7], short name |
| +0x470f | NullTerminator | byte, always 0 |
| +0x4710 | NameHash | uint, computed hash |

**Calls:** _strncpy, FUN_00587ece (hash computation)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00545850 — ClearBuffersLoop (resource buffer flush)

Source: likely audio/streamer.cpp. Walks two linked lists clearing audio/stream buffers via FUN_0054b330/FUN_0054b2c0.

**Key logic:**
- First loop: walks list at param_1+0x100 (next at +0x104)
  - For each: walks sub-list at +0xec (next at +0x4c)
  - Calls FUN_0054b330(0, 0x20, 0) and FUN_0054b2c0(0, 0x10000000, 0) (clear buffer ops)
- Second loop: walks list at param_1+0x108 (next at +0x4c), same clear ops

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x100 | AudioStreamList | int*, first audio stream list |
| +0x108 | EffectList | int*, effects list |
| *(node+0xec) | SubBufferList | int*, per-stream buffer list |
| *(node+0x4c) | NextNode | int, linked list next |

**Calls:** FUN_0054b330, FUN_0054b2c0 (buffer clear operations)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0052851d — AudioSampleLookup (indexed audio sample read)

Source: likely audio/sample.cpp. Reads a single audio sample from a table indexed by a 10-bit hash, writes it to output buffer.

**Key logic:**
- Computes index: `(*(short**)(param_2+0x50) * *param_3 + 4 >> 3) & 0x3ff` (10-bit index, 0-1023)
- Offsets by +0x80 + *(param_1+0x11c) (base + table offset)
- Writes byte to `param_5 + *param_4` (output buffer at position)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x11c | TableBaseOffset | int, base offset into sample table |

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004ff040 — ValueClampRange (clamp two values with min bound)

Source: likely hdvehicle/controller.cpp. Clamps two float values between 0 and 1 with a mutual minimum constraint.

**Key logic:**
- `*(param_1+0xfc) = 1.0 - param_2` (invert input)
- Clamps upper bound: if > 1.0, sets to 1.0; if < 0.0, sets to 0.0
- `*(param_1+0x100) = 1.0 - param_3` (invert second input)
- If second < first: second = first (mutual minimum clamping)
- If second > 1.0: second = 1.0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xfc | Output1 | float, first clamped value |
| +0x100 | Output2 | float, second clamped value |

**Globals:**
- `_DAT_0059e43c` — 1.0 constant
- `DAT_0059e440` — 0.0 constant

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/09-track-system.md -->

## FUN_00542540 — PointerStorePair2 (two-ptr setter)

Source: likely game/entity.cpp. Stores two pointer values at consecutive offsets.

**Key logic:**
- Sets `*(param_1+0x1a4) = param_2`
- Sets `*(param_1+0x1a8) = param_3`

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1a4 | PointerA | undefined4 |
| +0x1a8 | PointerB | undefined4 |

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f1860 — ConditionalMathDispatch (guarded solver call)

Source: likely hdvehicle/solver.cpp. Calls a math solver function only if a flag is zero.

**Key logic:**
- If *(param_1+0x32bc) == 0: calls FUN_0043b930(param_2, param_3, param_4) (math solver dispatch)
- Otherwise: returns immediately (solver already active or disabled)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x32bc | SolverActiveFlag | int, 0 = solver can run |

**Calls:** FUN_0043b930 (math solver dispatch)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054ac30 — DoublyLinkedListUnlink (node removal from linked list)

Source: likely game/container.cpp. Unlinks a node from a doubly-linked list, rewiring prev/next pointers.

**Key logic:**
- If node has next: sets `next->prev = node->prev`
- If node has prev: sets `prev->next = node->next`
- If node is list head at param_1+0x204: updates head to node->next
- Returns 0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x204 | ListHead | int*, linked list head pointer |
| *(node+0x10) | NodeNext | int, next node pointer |
| *(node+0x140) | NodePrev | int, previous node pointer |

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_00421380 — CountActiveEntitiesByState

Source: unknown (string-free). Iterates nested entity list, counts entities with state field == 10.

**Key logic:**
- Outer loop: iterates over entity collection (FUN_004c1370 returns count)
- Inner loop: for each entity, checks sub-entity list (FUN_004c11d0 returns count)
- Counts sub-entities where *(int*)(base + 0xd8 + i*4) == 10
- Returns total count matching state 10
- Returns 0 if param_1 (entity ptr) is null

**Calls:** FUN_004c2850 (entity list iteration), FUN_004c1370 (entity count), FUN_004c13a0 (entity deref), FUN_004c0a20 (string/name lookup), FUN_00566810 (validity check), FUN_004c11d0 (sub-entity count)

**Moddability:** `hardcoded` — state value 10 is magic constant

<!-- target: docs/06-session-race-logic.md -->

## FUN_00541a70 — TransformWheelForcesToChassis

Source: unknown. Transforms wheel-level force vectors to chassis coordinate frame. Matrix/vector math with virtual function call.

**Key logic:**
- Copies 4x4 matrix from param_1+0x15c to stack local
- Loop 6 iterations (6 wheels): transforms force vectors
- Uses DAT_008b8f24 (function pointer vtable) for coordinate transform
- First 4 wheels (front): simple dot product with suspension vectors
- Last 2 wheels (rear): additional position-dependent offset calculation
- Combines result with suspension geometry data at +0x24, +0x28, +0x2c

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x15c | WheelTransform[16] | 4x4 matrix, 16 floats |
| +0x104 | WheelForceBase | float array, 6 wheels × 4 floats |
| +0x24 | ChassisOffset_X | float |
| +0x28 | ChassisOffset_Y | float |
| +0x2c | ChassisOffset_Z | float |

**Globals:** DAT_008b8f24 — virtual function table pointer

**Calls:** DAT_008b8f24 virtual (coordinate transform function)

**Moddability:** `hardcoded` — suspension geometry in struct

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e9980 — ComputeSlipVelocityNorm

Source: unknown. Computes magnitude of slip velocity vector for a tire contact patch.

**Key logic:**
- Computes delta vector: contactPointVelocity (+0x3b60..) - wheelHubVelocity (+0x34d4..)
- Transforms delta by rotation matrix at +0x34b0, +0x34bc, +0x34c8 (first row), +0x34b4/+0x34c0/+0x34cc (second), +0x34b8/+0x34c4/+0x34d0 (third)
- Takes SQRT of sum of squares of transformed components
- Adds _DAT_005ad1d8 (epsilon to avoid division by zero)
- Clamps result to minimum of +0x3b6c (threshold)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x3b60 | ContactVelX | float, contact patch velocity |
| +0x3b64 | ContactVelY | float |
| +0x3b68 | ContactVelZ | float |
| +0x34d4 | HubVelX | float, wheel hub velocity |
| +0x34d8 | HubVelY | float |
| +0x34dc | HubVelZ | float |
| +0x34b0 | RotationMatrix[3][3] | 9 floats, local-to-world rotation |
| +0x3b6c | MinSlipSpeed | float, minimum clamp threshold |

**Globals:** `_DAT_005ad1d8` — small epsilon value

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0052e5e0 — DecodeHuffmanPair

Source: unknown. Decodes two Huffman-coded values from a bitstream into output buffer. Audio/codec decompression routine.

**Key logic:**
- Reads signed byte from param_3 (length/symbol table) at index param_2*2
- If non-zero: reads bits from bitstream at param_1+0x24a8, uses lookup tables DAT_005b4788 and DAT_005b4820 for decoding
- Performs byte-reversal on uint (endian swap), masks with window, shifts result
- Writes decoded 16-bit value to param_5 + param_2*2
- Repeats for second byte at param_3+1+param_2*2, writes to param_5+0x40+param_2*2
- Process for 2 channels (stereo) based on offset 0x80 in param_4

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x24a8 | BitStreamPos | int, current bit position |
| +0x24a4 | BitStreamBase | int, base pointer for bitstream |

**Globals:** DAT_005b4788, DAT_005b4820 — Huffman lookup tables

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054a0a0 — TestFrustumPlanes

Source: unknown. Tests an axis-aligned bounding box against 8 half-space planes for frustum/spatial culling.

**Key logic:**
- Saves flag bits at param_1+4, clears low 4 bits
- Iterates over 6 planes (stride 4 floats each) starting from param_2+0x104
- For each plane: tests 8 vertices against plane equation: dot(vertex, normal) + distance < 0
- Sets bitmask bit per vertex that is outside the plane
- If all 8 vertices outside same plane (bitmask 0xff): sets flag 2 (fully outside)
- If any vertex outside (bitmask != 0): sets flag 4 (partially outside)
- If no vertices outside (all planes passed): sets flag 1 (fully inside)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x04 | CullFlags | uint, bitmask: 1=inside, 2=fully outside, 4=partial |
| +0x24 | BoxVertices | 8 vertices × 3 floats (AABB corners) |

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004dbb60 — DrawDebugTextOverlay

Source: unknown. Renders multi-line debug text overlay with color-coded status lines.

**Key logic:**
- Allocates buffer via FUN_0049c6d0
- Draws first line at param_1+0x32 with yellow color (0xffff00), size=2
- Moves to param_1+0x145 for remaining lines
- Draws 4 more lines at offset 0x145 with white color (0xffffff)
- First and subsequent lines: alternating background (size 1/2) for readability
- All strings at 0x32 (50) and 0x5a (90) character widths

**Calls:** FUN_0049c6d0 (buffer alloc), FUN_004d7e40 (draw text), FUN_0049c310/0x370/0x490/0x4e0 (draw state transitions)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042ac90 — WrapPlayerCallback

Source: unknown. Thin wrapper that calls FUN_0042ac70 with offset param_1+4 + DAT_005ea2cc.

**Key logic:**
- Adds DAT_005ea2cc to value at param_1+4
- Passes result to FUN_0042ac70

**Globals:** DAT_005ea2cc — offset/constant

**Calls:** FUN_0042ac70 (player callback handler)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f1510 — ScaleAudioPitch

Source: unknown. Scales audio playback pitch/speed factor across multiple channels.

**Key logic:**
- Computes pitch ratio: param_2 / param_1+0x3bf4 (current speed)
- Iterates 4 elements at +0x361c with stride 0x3e (62 floats), scales each by ratio
- If DAT_007d01c4 bit 0 set: applies RNG jitter via FUN_005881f0 to buffer at +0x39a4
- If DAT_007d01c4 bit 1 set: calls different jitter path for +0x39f8 buffer
- If DAT_007d01c4 bit 2 set: scales value at +0x3984 by RNG
- Stores new param_2 at +0x3bf4
- Calls FUN_004e8010(0)

**Globals:** DAT_007d01c4 — audio processing flags bitmask

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x3bf4 | CurrentPlaybackSpeed | float |
| +0x361c | PitchScale[4] | 4 floats, stride 0x3e |
| +0x39a4 | JitterBuffer0 | pointer, RNG-adjusted |
| +0x39b0 | JitterBuffer0Len | int |
| +0x39f8 | JitterBuffer1Len | int |
| +0x3984 | GlobalJitterScale | float |

**Calls:** FUN_005881f0 (RNG), FUN_0059d9b5 (buffer jitter apply), FUN_004e8010 (finalize)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00507cc6 — ConvertFloatColorTo16Bit

Source: unknown. Converts float RGBA color data to 16-bit RGB565 format for texture output.

**Key logic:**
- If param_1+0x1048 set: decrypts/uncompresses data via FUN_00506ce2
- Gets base pointer from param_1+0x2c
- Loops param_1+0x1058 times (pixel count)
- Reads 3 float values (R, G, B), multiplies by _DAT_005accd0 (scale), rounds to int
- Packs into ushort: R<<5 | G<<5 | B (RGB565-like)
- Writes to output via extraout_EDX pointer

**Globals:** `_DAT_005accd0` — color scale factor (likely 255.0 or similar)

**Calls:** FUN_00506ce2 (decrypt/decompress), FUN_00507473 (premultiply/setup)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00500560 — CollisionTestWithThreshold

Source: unknown. Performs collision detection between two objects with velocity threshold branching.

**Key logic:**
- Calls FUN_005001f0 (collision enable check), returns early if disabled
- If FUN_005001d0 returns false or param_2 <= param_1+0x1bc (speed threshold): runs standard collision via FUN_004ff680
- If above threshold: computes clamped excess speed (fVar1), runs FUN_004ff680 with offset + FUN_004ff8f0 for extended collision response
- Calls FUN_004b3a90 (cleanup/release)
- If collision detected and param_6 set: calls FUN_005000e0 (spawn effect)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1bc | SpeedThreshold | float, threshold for extended response |
| +0x1b8 | ExtendedCollisionData | unknown struct |
| +0x08 | CollisionShape | unknown struct |

**Globals:** `_DAT_0059e600`, `_DAT_0059e450` — speed clamp bounds

**Calls:** FUN_005001f0 (collision enabled check), FUN_005001d0 (extended collision check), FUN_004ff680 (collision sweep), FUN_004ff8f0 (penetration response), FUN_004b3a90 (release), FUN_005000e0 (spawn collision effect)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_005086dd — FindNearestVertexWeight

Source: unknown. Finds nearest vertex among 256 candidates by 4-component squared distance. Vertex skinning weight assignment.

**Key logic:**
- If param_1+0x1048 set: decrypts/uncompresses via FUN_00506ce2
- Computes output buffer address via param_1+0x1050/0x1054/0x18 (stride * index)
- Loops param_1+0x1058 times (output vertex count)
- For each vertex: compares against 256 reference vertices (stride 4 floats)
- Computes squared distance across 4 components (position + weight or RGBA)
- Returns index of nearest vertex as byte

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1048 | EncryptedFlag | int, if set → decrypt first |
| +0x1050 | StrideA | int, output stride |
| +0x1054 | StrideB | int, additional stride |
| +0x18 | BaseOffset | int |
| +0x1058 | VertexCount | uint, output vertex count |
| +0x38 | ReferenceVerts | 256 × 4 floats, reference vertex data |

**Calls:** FUN_00506ce2 (decrypt/decompress)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b5a30 — DestroyUIWidgetHierarchy

Source: unknown. Tears down a complete UI widget/layer hierarchy, freeing linked lists and components.

**Key logic:**
- Calls FUN_004b6130, FUN_004b5e50, FUN_004b5f60 (pre-cleanup)
- Frees object at +0xf94 via FUN_00587bcf
- Calls FUN_004b52a0, FUN_004ba9f0×2, FUN_004bb4f0, FUN_004b0170×2 (sub-component cleanup)
- Frees objects at +0x72c, +0x724, +0x70c, +0x704
- Calls FUN_004bb400, FUN_005668d0
- Walks linked list at +0x6d4 chain: calls FUN_004646f0(1) per node, zeros head
- Walks linked list at +0x6c0 chain: calls FUN_004ba900(1) per node
- Walks 0x68 (104) additional linked lists at +0x6c0 downward: calls FUN_004ba8c0(1) per node
- Final cleanup: FUN_0049af30×2, FUN_004bb650, FUN_004baeb0×2, FUN_004bb5a0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xf94 | ComponentPtr0 | freed object |
| +0x72c | ComponentPtr1 | freed object |
| +0x724 | ComponentPtr2 | freed object |
| +0x70c | ComponentPtr3 | freed object |
| +0x704 | ComponentPtr4 | freed object |
| +0x6d4 | LinkedListHead0 | linked list of widgets |
| +0x6c0 | LinkedListHead1 | linked list base |

**Calls:** Many UI cleanup functions

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_005453a0 — EvaluateSceneNodeProperty

Source: unknown. Walks a scene graph node chain and evaluates a property/attribute, returning first truthy result.

**Key logic:**
- If param_3 (skip chain flag) is non-zero: directly evaluates param_2 via FUN_0054bc60, returns result
- Otherwise: walks linked list starting at param_1+0x100
- For each node: if +0xec flag set, evaluates param_2, returns first non-zero result
- Falls back to param_1+0x108 (default node) if chain exhausted with no result

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x100 | NodeChainHead | int, linked list pointer |
| +0x108 | DefaultNode | int, fallback node |

**Calls:** FUN_0054bc60 (property evaluator)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004ef560 — SetWheelContactFlags

Source: unknown. Stores contact state for a wheel index: two byte flags and a 3D contact position vector.

**Key logic:**
- Index: param_2 * 0x1c (stride per wheel)
- Writes param_3 (byte) to +0x3b78
- Writes param_4 (byte) to +0x3b79
- Writes param_5[0..2] (3 floats) to +0x3b88, +0x3b8c, +0x3b90

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x3b78 | ContactFlag0 | byte, per wheel |
| +0x3b79 | ContactFlag1 | byte, per wheel |
| +0x3b88 | ContactPosX | float, per wheel |
| +0x3b8c | ContactPosY | float, per wheel |
| +0x3b90 | ContactPosZ | float, per wheel |

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004d1a50 — ParseMidiBitstream

Source: unknown. Parses MIDI-like bitstream data, reading sample/note values and dispatching to FUN_004d0f00.

**Key logic:**
- Checks header: if `(*param_2 & 0xfc0000) == 0x280000`: loops calling FUN_004d0f00(0) for param_1+0x10c iterations (reset/init)
- Extracts 9-bit count from param_2 >> 9 & 0x1ff
- Loops count times: reads 6-bit value from each uint in stream (ushort & 0x3f), calls FUN_004d0f00 with it

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x10c | ResetCount | int, number of reset iterations |

**Calls:** FUN_004d0f00 (MIDI note/sample trigger)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00549250 — LinkedListByteBufferInsert

Source: unknown. Inserts a byte buffer node into a doubly-linked list chain, either as head or appended to tail.

**Key logic:**
- Checks param_2 bit 4: if set, reads base pointer from *param_1 + 0x128 instead of param_2
- If param_1[0x3d] (list head) is null: sets head = buffer, zeros 8 bytes at param_2+0x68–0x6f
- Else: walks to end of list (following +0x6c pointers), appends node, sets +0x68 to previous tail

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0050aeae — CopyTextureSurface

Source: unknown. Copies a texture/surface data block to a computed destination, handling decryption and row strides.

**Key logic:**
- If param_1+0x1048 set: decrypts via FUN_00506ce2
- Computes source index via param_2 + param_1+0x1034 and param_3 + param_1+0x1040
- Calls FUN_0050ab51 to check if copy needed (checks if row count differs)
- If index valid (≥0): computes destination address using stride math
- Copies (pixelCount & 0xfffffff) dwords from source to dest
- Handles remaining bytes with byte copy loop
- Sets completion flag at +0x108c to 1

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1048 | EncryptedFlag | int |
| +0x1034 | OffsetA | int, row offset |
| +0x1040 | OffsetB | int, column offset |
| +0x1088 | CurrentRowCount | int |
| +0x1058 | TargetRowCount | int |
| +0x1030 | DestWidth | int |
| +0x1070 | RowPitch | int |
| +0x106c | DestBuffer | int, base pointer |
| +0x108c | CopyCompleteFlag | int |

**Calls:** FUN_00506ce2 (decrypt), FUN_0050ab51 (copy check)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b3af0 — AdvanceRingBuffer

Source: unknown. Advances or resets a ring buffer pointer (stride 0x1b0 bytes per element). Returns availability.

**Key logic:**
- If current == end: resets current = start, returns 0 (buffer empty/reset)
- Else: advances current by 0x1b0 bytes, calls FUN_004b3a90 to process element, returns 1 (data available)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x6c00c | CurrentPtr | int, current read position |
| +0x6c004 | EndPtr | int, end of buffer |
| +0x6c008 | StartPtr | int, start of buffer |

**Calls:** FUN_004b3a90 (process buffer element)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_005437e0 — ReleaseSceneNode

Source: unknown. Releases a scene graph node by freeing its child pointer.

**Key logic:**
- Calls FUN_0053caf0 with value at param_1+0x110 (child/attachment pointer)
- Calls FUN_004b0170 (general cleanup)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054b9e0 — LogSessionEvent

Source: unknown. Logs an event by calling FUN_0055ca40 with ID=1 and param_1+0x1a0 as data.

**Key logic:**
- Calls FUN_0055ca40(1, param_1 + 0x1a0) — likely writes event to log buffer

**Calls:** FUN_0055ca40 (event logger)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_00447e00 — Position/Lap State Update

Source: unknown. Updates vehicle position tracking state when lap count or race position changes.

**Key logic:**
- Compares param_2 (new position/lap value) with stored value at +0x1ef4. Only acts on change.
- param_2 == -1: sets +0x1ef8 = 1 (reverse or invalid state)
- param_2 == 0: sets +0x1ef8 = 0 (start/neutral state)
- param_2 > 0: sets +0x1ef8 to 2*(prev < new) - 1 (direction: +1 forward, -1 backward)
- After change: resets counter at +0x1ef0 to 0
- If direction is negative (backward): copies +0x1e94/+0x1e98 to +0x1e7c/+0x1e80, calls FUN_004f89a0. If param_3==0 sets state=2 at +0x34, param_3==4 sets state=5
- If direction >= 0 (forward): copies +0x1e84/+0x1e88 to +0x1e7c/+0x1e80, calls FUN_004f88a0. param_3==0 → state=3. param_3==4 → state=6

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1ef4 | LastPosition | int, previous param_2 value |
| +0x1ef8 | DirectionFlag | -1/0/1, direction of movement |
| +0x1ef0 | Counter | int, reset on position change |
| +0x1e7c | TargetPosition | float[2], destination position |
| +0x1e84 | ForwardPos | float[2], forward-facing target |
| +0x1e94 | BackwardPos | float[2], backward-facing target |
| +0x34 | State | 2/3/5/6, animation/position state |
| +0x38/0x3c | Position | float[2], current position |
| +0x60/0x64 | Velocity | float[2], source velocity |

**Calls:** FUN_004f89a0 (negative direction handler), FUN_004f88a0 (positive direction handler)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042ebc0 — History Buffer Shift

Source: unknown. Shifts historical data forward in a ring buffer by copying structs at stride 0x40 (16 ints).

**Key logic:**
- First loop: 4 iterations × 11 items starting at param_1 + 0xc8 (200). Each item is 0x40 bytes apart. Copies puVar1[-1] → *puVar1 (shifts forward).
- Second loop: 55 iterations × 1 item starting at param_1 + 0xbc8. Same stride 0x40.
- Total: 44 + 55 = 99 slots shifted. Maintains sliding window of historical state data.

**Struct offsets (param_1):**
| Offset | Purpose |
|--------|---------|
| +0xc8 | History buffer start (first segment) |
| +0xbc8 | History buffer start (second segment) |
| Stride 0x40 | Per-slot size (16 floats or ints) |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e2070 — Local-to-World Coordinate Transform

Source: unknown. Transforms a local-space offset into world coordinates using a 3×3 rotation matrix and translation vector.

**Key logic:**
- Reads local offset components: +0x8f4+0x900, +0x8f8+0x904, +0x8fc+0x908 (offset + base = total input vector)
- Multiplies by 3×3 rotation matrix at +0x20..+0x40 (row-major, 9 floats)
- Adds translation at +0x8, +0xc, +0x10
- Copies 9 floats from rotation matrix to local array for preservation
- Calls FUN_00567120 with pointer param_1 + 0x90c and param_3

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x8 | PosX | float, world position x |
| +0xc | PosY | float, world position y |
| +0x10 | PosZ | float, world position z |
| +0x20..+0x40 | RotationMatrix | 9 floats, 3×3 row-major |
| +0x8f4 | LocalOffset1 | float[3], first offset component |
| +0x900 | LocalOffset2 | float[3], second offset component |
| +0x90c | OutputBuffer | passed to FUN_00567120 |

**Calls:** FUN_00567120 (processes transformed coordinates)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->
[PARTIAL — function is actually DDS texture loader, not race logic; categorized as game_logic per input list but is renderer]

## FUN_005026a4 — DDS Texture Surface Creation

Source: unknown. Creates Direct3D texture surfaces from DDS pixel data with mipmap support.

**Key logic:**
- Validates header: checks magic 0x20534444 ("DDS "), minimum size of 0x80 bytes, param_3 >= 4
- Extracts width (param_2[4]), height (param_2[3]) from DDS header
- Detects compressed formats: DXT1 (0x31545844), DXT2 (0x32545844), DXT3 (0x33545844), DXT4 (0x34545844), DXT5 (0x35545844), YUY2 (0x32595559), UYVY (0x59565955)
- Walks format table at DAT_005d71f8 to match pixel format
- Allocates surfaces: if format supports mips (bit 0x80 in byte 10), uses 4 mipmap levels, else 1
- Calculates surface pitch: DXT1 = (w+3>>2)<<3, DXT2-5 = (w+3>>2)<<4, YUY2 = (w+1>>1)<<2
- Allocates 0x54-byte surface objects via operator_new + FUN_00500f3c
- Manages memory budget: subtracts allocated size from remaining pool
- Returns 0 on success, 0x80004005/E_FAIL on failure, 0x8007000e/E_OUTOFMEMORY

**Calls:** FUN_00500680 (lookup format handler), FUN_00500f3c (surface constructor), operator_new

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042acd0 — Parameter Value Setter

Source: unknown. Sets a float parameter at +0x4538, using global value when param_2 == 0x12 (18).

**Key logic:**
- If param_2 == 18: copies _DAT_008acfb4 (global) to +0x4538
- Otherwise: casts param_2 to float, stores at +0x4538

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4538 | Parameter | float, some vehicle/driver parameter |

**Globals:**
- `_DAT_008acfb4` — float value used when param_2 == 18

**Moddability:** configurable via param_2 value; 0x12 triggers global default

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054bb40 — UI List Node Manager

Source: unknown. Creates and manages a linked list of UI/list nodes with stride-0x88 data arrays.

**Key logic:**
- If param_1+0x214 is null: allocates first node (0x28 bytes) via operator_new + FUN_005510f0(param_2+0xc)
- If list exists: walks to tail via +0x24 pointers, appends new node
- Each node stores count at +0x14, initializes array at +0x18 with stride 0x88, filling indices 0..count-1
- Calls FUN_00551440 (initialization) then FUN_00557350 (post-setup)
- Sets rendering parameters: color 0xdfdf1f (pale yellow), size 100.0f (0x42c80000), type 2, alpha 0x10
- If param_1+0x218 is null, calls FUN_00559200 to initialize display buffer
- Calls FUN_004b0170 (finalize/render registration)

**Calls:** FUN_005510f0 (node allocator), FUN_00551440 (list init), FUN_00557350 (post-setup), FUN_00559200 (display buffer init), FUN_004b0170 (render register)

**Moddability:** configurable — color/size/alpha set from constants

<!-- target: docs/06-session-race-logic.md -->

## FUN_00509644 — Texture Byte-to-Float Converter

Source: unknown. Converts byte RGB buffer to float RGBA with BGR→RGB channel swap.

**Key logic:**
- Computes buffer offset from param_1+0x18 using param_2 × +0x1050 + param_3 × +0x1054 (UV lookup)
- For each pixel: reads 3 bytes, writes 4 floats with channel swap B→R, G→G, R→B
- Scale factor _DAT_0059e460 applied, alpha = 1.0
- If flag at +0x10 set, calls FUN_00507845 to clear matching pixels

**Struct offsets (param_1):** +0x10 (int, clear flag); +0x18 (byte*, pixel base); +0x1050/+0x1054 (int, stride X/Y); +0x1058 (int, pixel count); +0x1064 (int, data size)

**Globals:** `_DAT_0059e460` — byte-to-float scale

**Calls:** FUN_00507845 (clear matching pixels)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042b8a0 — Thunk to FUN_004b3db0

Thunk — delegates to FUN_004b3db0. No entry needed.

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f6720 — Parameterized Curve Interpolation

Source: unknown. Linear interpolation from a keyframe table with dual value tracks.

**Key logic:**
- Table at param_1+0x6c4 has count, keys at +0x6c8 (stride 0x18=24B), value tracks at +0x6d0 and +0x6d8
- count<1: returns zero. count==1: returns single entry.
- Linear interpolation: finds segment i where param_2 >= key[i] && param_2 < key[i+1]
- Computes t = (param_2 - key[i]) / (key[i+1] - key[i]), lerps both tracks
- If value2 < value1: blends toward midpoint using _DAT_0059e880

**Struct offsets:** +0x6c4 (int, count); +0x6c8 (double[], keys stride 0x18); +0x6d0 (double[], track A); +0x6d8 (double[], track B)

**Globals:** `_DAT_0059e880` — blend factor

**Moddability:** configurable — table-driven

<!-- target: docs/06-session-race-logic.md -->

## FUN_005082d1 — DXT Color Encoder (16-bit)

Source: unknown. Encodes float RGBA pixels to 16-bit DXT color format with palette lookup.

**Key logic:**
- If flag at +0x1048 set: transforms input via FUN_00506ce2
- Colorspace offset: ((param_3 & 3) + (param_2 & 3) * 8) * 4 + (uVar8 & 3) * 4
- Iterates pixel count from +0x1058, stride 0x10 (4 floats/pixel)
- Each pixel: ROUND(r * scale + palette), packed 16-bit R[7:4]G[3:0]|G[7:4]B[3:0]

**Struct offsets (param_1):** +0x2c (float*, palette base); +0x1048 (int, transform flag); +0x1058 (int, pixel count)

**Globals:** `_DAT_0059e8d8` — color scale factor

**Calls:** FUN_00506ce2 (input transform), FUN_00507473 (texture setup)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0050895d — DXT Color Encoder (8-bit with matrix)

Source: unknown. Encodes float RGBA pixels to 8-bit using RGB matrix transform.

**Key logic:**
- If flag at +0x1048 set: transforms input via FUN_00506ce2
- Colorspace offset: ((param_3 & 3) + (param_2 & 3) * 8) * 4 + (uVar6 & 3) * 4
- For each pixel: RGB dot product (r×_DAT_005adb18 + g×_DAT_005adb1c + b×_DAT_005adb20)
- Adds palette offset, multiplies by _DAT_0059e8d8, combines with alpha<<4 → single byte

**Globals:** `_DAT_005adb18/1c/20` (RGB matrix), `_DAT_0059e8d8` (scale)

**Calls:** FUN_00506ce2 (input transform), FUN_00507473 (texture setup)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_005087a2 — DXT Color Encoder (8-bit additive)

Source: unknown. Encodes float RGBA pixels to 8-bit using additive blending.

**Key logic:**
- Same structure as FUN_0050895d but uses DAT_0059fec8 as additive scale instead of _DAT_0059e8d8
- RGB dot product × DAT_0059fec8 + palette value → byte output

**Globals:** `_DAT_005adb18/1c/20` (RGB matrix), `DAT_0059fec8` (additive scale)

**Calls:** FUN_00506ce2 (input transform), FUN_00507473 (texture setup)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054abe0 — Linked List Append (offset +0x204)

Source: unknown. Appends a node to a singly-linked list rooted at param_1+0x204.

**Key logic:**
- If head (+0x204) null: head = param_2, zeroes links
- Else: walks to tail via +0x10, appends param_2. Sets +0x140 back-pointer.

**Struct offsets:** +0x204 (int*, head); +0x10 (int*, next); +0x140 (int*, prev)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004ef930 — Race Start/Countdown State Update

Source: unknown. Manages race start countdown and state transitions based on speed/position.

**Key logic:**
- Clears flag at +0x39ec. If flag at +0x39ee != 0: returns early.
- If param_2 == 0: resets all counters, returns.
- Compares +0x3a04 against DAT_0059e440 (zero):
  - If < zero: calls FUN_004f88a0 (positive delta). Copies +0x39fc→+0x3a04. If param_2==1 AND counter==0: triggers +0x39ec=1.
  - If >= zero: calls FUN_004f89a0 (negative delta). Copies +0x3a00→+0x3a04. Checks 4 speed conditions → calls FUN_004ef4f0 if met.
- Sets +0x3a08 = param_2, resets +0x39f0

**Struct offsets:** +0x3578 (float, speed); +0x3978 (float, other speed); +0x3994/+0x3998 (float); +0x39ec (byte, trigger); +0x39ee (byte, disable); +0x39f0 (int, counter); +0x39fc (float, high target); +0x3a00 (float, low target); +0x3a04 (float, current); +0x3a08 (int, state)

**Globals:** DAT_0059e440 (zero ref), _DAT_0059e450 (scale)

**Calls:** FUN_004f88a0, FUN_004f89a0, FUN_004ef4f0

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004d1cf0 — Ring Buffer Access with Wrap

Source: unknown. Indexes ring buffer with modulo wrap.

**Key logic:**
- __ftol(param), subtracts 1, wraps by modulo +0x10c (buffer size)
- Clamps to [0, size-1], returns element from +0x110 (stride 8)

**Struct offsets:** +0x10c (int, size); +0x110 (int*, buffer ptr)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054a270 — Linked List Append (offset +0x100)

Source: unknown. Appends to doubly-linked list at param_1+0x100.

**Key logic:**
- If head null: head = param_2, zeroes links
- Else: walks via +0x104 to tail, appends, sets back-link at +0x100

**Struct offsets:** +0x100 (int*, head); +0x104 (int*, next)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0050b27c — Texture Dimension Setup

Source: unknown. Sets texture scaling factors and rounds dimensions.

**Key logic:**
- Selects scale: DXT2/DXT3 use _DAT_0059e8d8, others use DAT_0059fec8
- Stores at +0x106c, reciprocal at +0x1070
- Rounds 4 dims via ROUND(val×factor+0.5f)×reciprocal

**Struct offsets:** +0x4 (int, format); +0x1c/20/24/28 (float[4], dims); +0x106c (float, scale); +0x1070 (float, inv scale)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_005457c0 — Linked List Traversal

Source: unknown. Walks linked list (stride +0x6c), returns Nth node.

**Key logic:**
- Validates param_2: if < 0 or >= +0x11c, returns 0
- Walks from +0x120, param_2 steps via +0x6c links

**Struct offsets:** +0x11c (int, size); +0x120 (int*, head); node+0x6c (int*, next)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f1c20 — Replay/AI State Check

Source: unknown. Checks if replay/AI playback is active.

**Key logic:**
- Returns 1 if param_1+0x3a9c non-null AND (value at offset 300) == 1

**Struct offsets:** +0x3a9c (int*, replay state ptr)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054c1b0 — UI Widget Recursive State Update

Source: unknown. Recursive UI state propagation.

**Key logic:**
- If +0x44 non-null AND param_3 != 0: recursive call
- If +0x4c non-null AND (param_4 & param_3) != 0: recursive call
- If +0x230 non-null: calls FUN_00560fc0 (enable) or FUN_00560fd0 (disable)

**Struct offsets:** +0x44 (int*, childA); +0x4c (int*, childB); +0x230 (int*, handler)

**Calls:** self (recursive), FUN_00560fc0, FUN_00560fd0

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_004674e0 — Menu Command Dispatcher

Source: unknown UI source. Dispatches menu/UI commands based on command ID at param_1+0x174.

**Key logic:**
- Calls FUN_00489cb0() for common setup
- Switch on command ID at param_1+0x174:
  - Case 0x1be: Formats string via FUN_00431950 with DAT_007c737c, sets DAT_007c7378=0
  - Cases 0x1bf-0x1c2: If DAT_007d048c != 0, formats with FUN_00431aa0(mode=3), displays via FUN_00489600. Else if value at +0x178==1, runs FUN_0042ec00. Then formats with modes 2,1,0 and displays each
  - Cases 0x1c3-0x1c6: Indexed lookup into DAT_007c7384 array, formats via FUN_00431950, clears DAT_007c7380[i], displays
  - Cases 0x1c7-0x1ca: Formats with FUN_004319e0
  - Default: returns

**Globals:**
- `DAT_007c7378` — menu state flag (written 0)
- `DAT_007c7380` / `DAT_007c7384` — indexed menu globals array
- `DAT_007d048c` — conditional flag for menu path

**Calls:** FUN_00489cb0 (menu setup), FUN_00431950 (string format), FUN_00431aa0 (string format with mode), FUN_0042ec00 (action handler), FUN_004319e0 (string format), FUN_00489600 (menu display)

**Moddability:** hardcoded

⌾ 861 — FUN_0051af57

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f1120 — Wheel Force Aggregation

Source: vehicle dynamics. Aggregates per-wheel forces into net force/moment on vehicle.

**Key logic:**
- Iterates 4 wheels (stride 248 = 0x3e*4 from param_1+0x3668)
- For each active wheel matching param_2: force = clamp(param_3, 0, _DAT_0059ec20) * wheel_downforce * _DAT_005ad234
- Tracks max, sum, torque sum, lateral/long/vertical components
- If max_force <= _DAT_0059e600: return early
- Normalizes: inv_total = _DAT_0059e43c / total_force; scales components
- Calls FUN_004f8850 to apply

**Globals:**
- `_DAT_0059ec20` — force clamp max
- `_DAT_005ad234` — force scale
- `_DAT_0059e600` — min force threshold
- `_DAT_0059e43c` — 1.0f constant
- `DAT_0059e440` — 0.0f constant

**Calls:** FUN_004f8850 (apply force, docs/18)

**Moddability:** hardcoded

⌾ 863 — FUN_0051378b

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042bb50 — Repeated Call Loop

Source: unknown. Calls FUN_004c6920() 104 times.

**Calls:** FUN_004c6920 (unknown, per worker_F)

**Moddability:** hardcoded

⌾ 865 — FUN_0054d7a0

<!-- target: docs/06-session-race-logic.md -->

## FUN_00509fde — Texture Grayscale Conversion

Source: renderer. Converts 2-byte grayscale+alpha pixels to float RGBA.

**Key logic:**
- Each pixel: byte0→RGB (all channels same), byte1→alpha
- Scales by _DAT_0059e460
- If palette flag at +0x10: calls FUN_00507845

**Globals:**
- `_DAT_0059e460` — byte-to-float scale

**Calls:** FUN_00507845 (palette remap)

**Moddability:** hardcoded

⌾ 867 — FUN_004e8b80

<!-- target: docs/06-session-race-logic.md -->

## FUN_005096d0 — Texture RGBA Byte-to-Float Conversion

Source: renderer. Converts 4-byte RGBA pixels to 4-float RGBA.

**Key logic:**
- Each pixel: reads 4 bytes (R,G,B,A), converts to float via _DAT_0059e460 scale
- Outputs 4 floats per pixel
- If palette flag at +0x10: calls FUN_00507845

**Globals:**
- `_DAT_0059e460` — byte-to-float scale

**Calls:** FUN_00507845 (palette remap)

**Moddability:** hardcoded

⌾ 869 — FUN_0042b8b0

<!-- target: docs/06-session-race-logic.md -->

## FUN_005079a1 — Texture Float-to-32bit ARGB Pack

Source: renderer. Converts 4 floats/pixel to packed 32-bit ARGB.

**Key logic:**
- If palette flag at +0x1048 != 0: calls FUN_00506ce2 for palette lookup
- For each pixel: rounds RGBA floats, scales by DAT_0059fec8, packs into 32-bit (A<<24 | R<<16 | G<<8 | B)
- Inner loop over count at +0x1058

**Globals:**
- `DAT_0059fec8` — float-to-int scale factor

**Calls:** FUN_00506ce2 (palette lookup), FUN_00507473 (setup)

**Moddability:** hardcoded

⌾ 871 — FUN_005085c5

<!-- target: docs/06-session-race-logic.md -->

## FUN_00508a48 — Texture Float-to-16bit Pack (565?)

Source: renderer. Converts 4 floats/pixel to 16-bit packed (likely RGB 565 layout).

**Key logic:**
- For each pixel: packs R and G bytes into 16-bit value using _DAT_0059e6fc scale
- Each component clamped by palette table at param_1+0x2c
- If palette flag: calls FUN_00506ce2

**Globals:**
- `_DAT_0059e6fc` — float-to-int scale for 16-bit

**Calls:** FUN_00506ce2 (palette), FUN_00507473 (setup)

**Moddability:** hardcoded

⌾ 873 — FUN_00508b1d

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f17d0 — Matrix/Vector Setup

Source: vehicle dynamics. Copies 9 floats to param_1+0x34b0, then computes 3 dot products for rotation transform.

**Key logic:**
- Copies 9 floats from param_2 to param_1+0x34b0..0x34d0
- Copies 3 floats from param_3 to param_1+0x3534..0x353c
- Computes 3 dot products: each output = row_i dot param_3, stored at +0x3540..+0x3548

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x34b0..0x34d0 | RotationMatrix | 3x3 matrix (9 floats) |
| +0x3534 | InputVec | input vector XYZ |
| +0x3540..0x3548 | OutputVec | transformed vector |

**Moddability:** hardcoded

⌾ 877 — FUN_004d1d40

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054b950 — Scene Node Position Getter

Source: scene graph. Reads transform from node, returns X/Y/Z values.

**Key logic:**
- If node's flags at +0x14 (bit 29 clear): calls vtable function to compute transform at node+0xdc/e8, then sets flag bit 29
- Copies position values (node+0xe8/ec/f0) to output params

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| param_1+0x204 | NodePtr | scene node pointer |
| node+0x14 | NodeFlags | transform dirty flag |
| node+0xdc | TransformA | intermediate transform |
| node+0xe8..0xf0 | PositionXYZ | world position |

**Globals:**
- `DAT_008b8f24` — scene manager singleton

**Moddability:** hardcoded

⌾ 879 — FUN_00541420

<!-- target: docs/06-session-race-logic.md -->

## FUN_00512366 — State Flag Setter

Source: unknown game logic. Sets flags and state values based on type byte.

**Key logic:**
- Sets bit 7 at +0x61
- Stores param_2 to +0x11e (ushort)
- If param_3==1: sets bit 7 at +0x5c, else clears bit 7
- If type at +0x116==2: sets +0x11b=4
- If type==0 AND byte at +0x117 > 7: sets +0x11b=2

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x5c | FlagByteA | flag with bit 7 |
| +0x61 | FlagByteB | flag with bit 7 |
| +0x116 | TypeByte | data type |
| +0x117 | SubType | sub-type value |
| +0x11b | ResultByte | output state |
| +0x11e | ValueWord | stored value |

**Moddability:** hardcoded

⌾ 881 — FUN_004c0b10

<!-- target: docs/06-session-race-logic.md -->

## FUN_005457f0 — Linked List Nth Element

Source: linked list utility. Walks +0x6c-linked list to find Nth element.

**Key logic:**
- If index < 0 or >= param_1+0x124: return 0
- Starts from param_1+0x128, follows +0x6c links for index iterations

**Calls:** none

**Moddability:** hardcoded

⌾ 883 — FUN_005001d0

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054e240 — Array Index Read

Source: unknown. Bounds-checked array read from a struct array.

**Key logic:**
- If param_2 < param_1+0x120: reads from param_1+0x124 + 8 + param_2*0x24, deref +4

**Moddability:** hardcoded

⌾ 885 — FUN_0044b910

<!-- target: docs/17-physics-collision.md -->

## FUN_0051c237 — PixelBlendFilterHorizontal

Source: renderer/image processing. Applies horizontal pixel blending filter with 3-tap weighted averaging.

**Key logic:**
- Reads pixel data from source buffer, output to destination
- First pixel: copies source byte, computes second byte as (src*3 + next*2 + 2) >> 2
- Middle pixels (width-2 loop): computes (prev*1 + cur*3 + next*2) >> 2 pattern for pairs
- Last pixel: computes (prev*1 + cur*3 + 1) >> 2, copies final byte directly
- Width from param_1+0x110, height-2 from param_2+0x28
- All arithmetic uses integer bit-shift averaging — no floating point
- 3:1:3:2 tap weight pattern for 2× upsampling

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042cee0 — PenaltyStateDefaultInit

Source: likely steward.cpp. Initializes a small penalty/flag state array to defaults.

**Key logic:**
- Sets param_1[0] = 1 (enabled)
- Sets param_1[1] = 3 (penalty type)
- Sets param_1[2] = 1 (severity)
- Sets param_1[3] = 0, param_1[4] byte = 0, param_1+0x11 byte = 0
- Sets param_1[5] = 0, param_1[6] = 0
- Sets param_1[7] = -1 (invalid/not applied)
- Pattern matches penalty state struct with type/severity/remaining/timeout fields

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042ed00 — SessionStateIndexedLookup

Source: likely steward.cpp. Indexed lookup into session struct with conditional negation.

**Key logic:**
- Reads value at param_1[param_2 * 0x40 + 0xbc4] (param_2 uses 0x40 stride table)
- Passes through FUN_0042dd00 (arithmetic transform) with param_1+0x1644 as second arg
- If param_2 == 0x2b (43), negates the result (special-case inversion)
- Returns float10

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1644 | LookupParam | float/int, secondary input to FUN_0042dd00 |
| +0xbc4 + param_2*0x40 | IndexedTable | per-index 0x40-byte entry struct |

**Calls:** FUN_0042dd00 (arithmetic transform on indexed value)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00435290 — FloatEpsilonCompare

Source: math utility. Compares two doubles within epsilon tolerance.

**Key logic:**
- Returns 1 if |param_1 - param_2| < _DAT_0059ead8 (global epsilon threshold)
- Returns 0 otherwise
- Used as fuzzy equality check for floating-point comparisons

**Globals:**
- `DAT_0059ead8` — epsilon threshold (double)

**Calls:** none

**Moddability:** `hardcoded` — epsilon is a global constant

<!-- target: docs/06-session-race-logic.md -->

## FUN_0050a067 — TextureUnpackNibbles

Source: renderer/texture. Unpacks 4-bit-per-channel texture data into float4.

**Key logic:**
- Computes pixel offset: param_1+0x1050*param_2 + param_1+0x1054*param_3 + param_1+0x18 (base + x*width + y*stride)
- For each pixel up to count at param_1+0x1058:
  - Reads byte, extracts low nibble (& 0xf) and high nibble (>> 4)
  - Low nibble * scale → replicated to RGB (param_4[0], [1], [2])
  - High nibble * scale → alpha (param_4[3])
  - Advances param_4 by 4 floats per pixel
- If param_1+0x10 != 0, calls FUN_00507845 on output buffer (post-process)

**Globals:**
- `DAT_005ac108` — color scale factor (float)

**Calls:** FUN_00507845 (output post-process, conditional)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00509776 — TextureUnpackRGB

Source: renderer/texture. Unpacks 24-bit RGB texture data into float4 (RGBA).

**Key logic:**
- Computes pixel offset: param_1+0x1050*param_2 + param_1+0x1054*param_3 + param_1+0x18
- For each pixel up to count at param_1+0x1058:
  - Reads 3 bytes (R, G, B) at offsets +2, +1, +0 from pixel base
  - Each byte * scale factor _DAT_0059e460 → float
  - Sets alpha = 1.0
  - Advances param_4 by 4 floats per pixel
- If param_1+0x10 != 0, calls FUN_00507845 on output buffer

**Globals:**
- `DAT_0059e460` — color scale factor (float)

**Calls:** FUN_00507845 (output post-process, conditional)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042bb80 — ThunkDebugLog

Thunk — delegates to FUN_00587b3e(&LAB_0042bb90) with a format string. No entry needed.

<!-- target: docs/06-session-race-logic.md -->

## FUN_00507dc7 — TextureEncode16Bit

Source: renderer. Encodes float4 color data into 16-bit 4444 format.

**Key logic:**
- If param_1+0x1048 != 0, calls FUN_00506ce2 on param_4 (palette remap)
- Reads color table at iVar6 (param_1+0x2c) indexed by (param_3 & 3) + (param_2 & 3)*8 + (uVar9 & 3)
- For each pixel: packs 4 channels (ARGB) into 16-bit ushort using bit shifts:
  - R: ROUND(fVar5 + Rchannel), shifted left 5
  - G: ROUND(G * coeff + fVar5), shifted left 5
  - B: ROUND(B * coeff + fVar5), shifted left 5
  - A: ROUND(A * coeff + fVar5), no shift
- Each channel uses 4 bits (<<5 pattern means 5 shifts × 3 = 15 bits + 1 bit = 16)

**Globals:**
- `DAT_005accd0` — color matrix coefficient (float)

**Calls:** FUN_00506ce2 (palette remap, conditional), FUN_00507473 (pixel state setup)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00508867 — TextureEncode16BitMatrix

Source: renderer. Encodes float4 color data into 16-bit format with color matrix multiplication.

**Key logic:**
- If param_1+0x1048 != 0, calls FUN_00506ce2 on param_4 (palette remap)
- Reads color multiplier from iVar3 (param_1+0x2c) — table lookup indexed by coords
- For each pixel:
  - Computes weighted sum: R*c0 + G*c1 + B*c2 → luminance-like value
  - Multiplies by DAT_0059fec8 and adds fVar2 (color table entry)
  - Packs into ushort: high byte from A*coeff+fVar2 (rounded), low byte from weighted sum
  - Advances 1 ushort per pixel

**Globals:**
- `DAT_005adb18`, `DAT_005adb1c`, `DAT_005adb20` — RGB color matrix coefficients
- `DAT_0059fec8` — output scale factor

**Calls:** FUN_00506ce2 (palette remap, conditional), FUN_00507473 (pixel state setup)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051bcfc — RenderCommandDispatch

Source: renderer. Dispatches two virtual render commands via vtable.

**Key logic:**
- Reads render context from param_1+0x188, gets buffer capacity from iVar1+0x10
- Clamps write count to min(remaining, buffer capacity)
- Calls first virtual method via (param_1+0x19c) vtable entry 1 (offset 4) — a write/emplace command
- Calls second virtual method via (param_1+0x1a4) vtable entry 1 (offset 4) — a flush/send command
- Tracks written count in *param_6

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x188 | RenderContext | pointer to render context structure |
| +0x19c | WriteVtable | vtable pointer, entry+4 = write method |
| +0x1a4 | FlushVtable | vtable pointer, entry+4 = flush method |

**Calls:** none directly — all via vtable dispatch

**Moddability:** `hookable` — vtable methods can be overridden

<!-- target: docs/06-session-race-logic.md -->

## FUN_00508e67 — TextureEncode16BitPair

Source: renderer. Encodes float4 data into paired 16-bit format (two channels per ushort).

**Key logic:**
- If param_1+0x1048 != 0, calls FUN_00506ce2 (palette remap)
- Reads color table at iVar2 (param_1+0x2c) indexed by coords
- For each pixel:
  - Reads first two floats, multiplies each by _DAT_005acc84, adds fVar1 (color table entry)
  - Packs into one ushort: channel0 in low 16 bits, channel1 shifted left 16 into high bits
  - Advances 1 dword per pixel (2 channels packed)
- Stride: 0x10 bytes per pixel input (4 floats), 4 bytes output (1 dword)

**Globals:**
- `DAT_005acc84` — color multiplier (float)

**Calls:** FUN_00506ce2 (palette remap, conditional), FUN_00507473 (pixel state setup)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e19a0 — UIElementIterateUpdate

Source: likely UI system. Iterates 14 elements calling update function on each.

**Key logic:**
- Loops iVar1 = 0 to 13 (< 0xe)
- Each iteration calls FUN_004e17c0(iVar1, puVar2) where puVar2 reads from param_1+0xb70 + iVar1*4
- Passes element index and element pointer to update function

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xb70 | ElementArray | array of 14 pointers (0xe elements) |

**Calls:** FUN_004e17c0 (element update, per-index)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054bd30 — SceneGraphRenderWalk

Source: renderer/scene. Walks scene graph hierarchy and registers renderable nodes.

**Key logic:**
- Starts at param_1, traverses children linked via +0x10
- Checks each node's flags at +0x14 for bit 0x80000 (visible/renderable flag)
- If flag set: stores param_1 into global render list at DAT_008b8f28+0x150 (offset by DAT_008b8f28+0x14c counter), increments counter
- If node has child at +0x44, recurses via FUN_0054bd30
- Follows sibling link at +0x4c to continue traversal
- Returns when sibling link is null

**Globals:**
- `DAT_008b8f28` — scene/renderer global context
- `DAT_008b8f28+0x14c` — render list counter (incremented per node)
- `DAT_008b8f28+0x150` — render list array base

**Calls:** FUN_0054bd30 (recursive, for child nodes)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00517f72 — AnimationStateCheck

Source: animation/character system. Checks state flags and compares animation index.

**Key logic:**
- Checks bit 0x20 at param_1+0x10c (flagA)
- Checks bit 8 at param_1+0x5d (flagB)
- If flagA set AND bits 0x300 at +0x5c == 0x300 (both bits set) → returns false (state locked)
- If flagA NOT set AND flagB NOT set → returns false
- Otherwise → returns true (state allows animation switch)
- Then calls FUN_00513bd1(param_1, &param_1, 4) — serializes 4 bytes
- If bVar3 true: compares FUN_00517f35(&param_1) result with param_1+0x100 (current animation ID)
- Returns true if animation ID changed

**Calls:** FUN_00513bd1 (data serialize/copy), FUN_00517f35 (animation ID lookup)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e39d0 — UIElementMultiDispatch

Source: UI system. Dispatches a command to multiple UI elements.

**Key logic:**
- Reads element count from param_1+0xba8
- Loops from 0 to count-1, calling FUN_004df030(param_2) each iteration
- Passes same param_2 (message/command ID) to each call

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xba8 | ElementCount | int, number of UI elements |

**Calls:** FUN_004df030 (UI element message handler)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_005419d0 — LinkedListInsertTail

Source: scene graph/linked list manager. Inserts a node at tail of doubly-linked list.

**Key logic:**
- Removes param_2 from its current position by linking prev→next to param_2's next
- Updates param_2's next's prev pointer to param_2's prev
- If param_2 is head of global list (DAT_008b8f28+0xf8), updates global head to param_2's next
- Appends param_2 to list at param_1+0x1b0:
  - If list empty: sets head = param_2
  - Else: walks to tail via +0x1b8 (next pointers), appends
- Sets param_2→prev = iVar2 (old tail), param_2→next = 0, param_2→parent = param_1

**Globals:**
- `DAT_008b8f28+0xf8` — global linked list head pointer

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1b0 | ListHead | head of child list |
| +0x1b4 | PrevPtr | previous sibling pointer |
| +0x1b8 | NextPtr | next sibling pointer |
| +0x1ac | ParentPtr | parent node pointer |

**Calls:** none (direct pointer manipulation only)

**Moddability:** `hookable`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00513cd8 — AnimationHandleAlloc

Source: animation system. Allocates animation handle and stores to struct.

**Key logic:**
- Calls FUN_0051923d(0, 0, 0) to allocate/get an animation handle
- Stores result at param_1+0x100 (animation handle field)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x100 | AnimationHandle | int, animation resource handle |

**Calls:** FUN_0051923d (animation handle allocation)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c6960 — TeamIDSetter

Source: vehicle/team data. Sets TeamID and triggers notification.

**Key logic:**
- Sets param_1+0x4894 = param_2 (TeamID assignment)
- Calls FUN_00424060 (notification/update callback)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4894 | TeamID | int, team identifier |

**Calls:** FUN_00424060 (change notification)

**Moddability:** `configurable` — TeamID is a set-once value

<!-- target: docs/06-session-race-logic.md -->

## FUN_00545820 — LinkedIndexedAccess

Source: linked list utility. Walks linked list by index to access Nth element.

**Key logic:**
- Returns 0 if param_2 < 0 or param_2 >= param_1+0x12c (300 — bounds check)
- Starts at head pointer at param_1+0x130
- Follows +0x6c (next) pointers param_2 times to reach Nth element
- Returns pointer to Nth node or 0 if error

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x12c | ListSize | int, max 300 entries |
| +0x130 | ListHead | pointer to first node |

**Node offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x6c | NextPtr | pointer to next node in linked list |

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00512322 — AnimationStateFlagSet

Source: animation/character. Sets a state flag when specific animation type detected.

**Key logic:**
- Checks if byte at param_1+0x117 == 0x10 (specific animation type ID)
- If match: sets bit 0x10 at param_1+0x60 (state flag field)
- Otherwise: no-op

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x117 | AnimType | byte, current animation type |
| +0x60 | StateFlags | uint, state flag bitfield |

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004d0f10 — Session/Lap Timer Structure Init

Source: likely_session.cpp. Initializes a lap timing / sector time structure with sentinel defaults. Called by FUN_004d0030 to prepare session timing data.

**Key logic:**
- Calls FUN_0040d980 (memset or base init)
- Zeros lap/sector time fields at offsets 0xe0, 0xe4, 0xec, 0xf0, 0xf8, 0xfc, 0xa4, 0xa8
- Sets sentinel at 0xac to 0x7fffffff (MAX_INT for DNF/unset)
- Zeros fields at 0xb0, 0xb4
- Sets 0xb8 to 0x45e10000 (7200.0f = 2-hour session max time)
- Sets 0xbc to 0x3f800000 (1.0f = default multiplier)
- Zeros 0xc0, 0xc3, 0xd4, 0xd0
- Initializes array at 0x128 (26 ints) to 0xffffffff (sector/lap flags)
- Sets 0x190 (400) to 0xffff (short) and 0x192 to 0xff
- Zeros remaining fields through 0x1ac
- Clears 52 ints (0x34 × 4 = 0xD0 bytes) at 0x280 (pit window history buffer)
- Returns param_1

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xac | BestTime | int, 0x7fffffff = DNF sentinel |
| +0xb8 | MaxSessionTime | float, 7200.0 (2 hours) |
| +0xbc | TimeMultiplier | float, 1.0 |
| +0x128 | SectorFlags | int[26], initialized to -1 |
| +0x190 | LapCount | short, 0xffff |
| +0x192 | CurrentSector | byte, 0xff |
| +0x280 | PitWindowHistory | int[52], zeroed |

**Calls:** FUN_0040d980 (memory init), called by FUN_004d0030 (session timer setup)

**Moddability:** `hardcoded` — structure initialization, no config file reads

<!-- target: docs/06-session-race-logic.md -->

## FUN_0052835f — Audio FIR/Convolution Filter

Source: likely_audio.cpp. 8-channel audio processing function using fixed-point arithmetic with FIR filter coefficients. NOTE: Classified as game_logic but is clearly audio DSP — 8-channel iteration, short-integer multiply-accumulate with DSP coefficients.

**Key logic:**
- Takes 5 params: param_1 (iteration count/selection flag), param_2 (input buffer), param_3 (filter state), param_4 (output buffer array), param_5 (base offset)
- Outer loop: 8 iterations (param_1 starts at 8, decrements), skips channels 6, 4, 2
- Checks channel activity: if all taps (0x30, 0x20, 0x10, 0x00 shorts) are zero → pure gain path: `(psVar4[-0x18] * psVar6[-0x18] * 4)` with scaling
- Otherwise: performs 4-tap FIR filter with fixed-point coefficients: 0x1b37, -0x1712, 0x73fc, -0x28ba — these are Q15-format filter coefficients
- `>> 0xd` = divide by 8192 (fixed-point normalization)
- Second loop: 2 iterations, writes 2 bytes per output channel using indexed lookup from filter result (`>> 5 & 0x3ff`, `>> 0x14 & 0x3ff`)
- Output stored as bytes to param_4[param_5] (interleaved stereo/quad)

**Globals:**
- `_DAT_005acd20` — silence/clipping threshold

**Calls:** none, called by FUN_0051bad1 (via function pointer assignment)

**Moddability:** `hardcoded` — coefficients baked in, no file reads

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b85d0 — Linked List Priority Search by Float Threshold

Source: likely_ai_path.cpp. Traverses a sorted linked list of event/penalty nodes to find the first element whose stored float value falls below a dynamically-computed threshold.

**Key logic:**
- Reads count at param_1+0x6cc, head pointer at param_1+0x6c0, current pointer at param_1+0x6c8
- If count > 0: traverses list nodes (each node has next ptr at +4, data ptr at +0)
- Compares float at node data against `*(param_1+0xf38) - _DAT_005acd20` (threshold minus epsilon)
- If below threshold: navigates to the previous node (via next pointer chain) and searches backward
- If at/above threshold: advances to next node via +8 offset
- Updates current pointer (param_1+0x6c8) to found position
- Stores first float from found node into param_1+0xf38
- Returns lower byte of node data (flags/type)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x6c0 | ListHead | int*, linked list head pointer |
| +0x6c4 | ListTail | int*, linked list tail pointer |
| +0x6c8 | CurrentPtr | int*, current iterator position |
| +0x6cc | ListCount | int, number of nodes |
| +0xf38 | CurrentThreshold | float, comparison value |

**Globals:**
- `_DAT_005acd20` — search epsilon tolerance

**Calls:** none directly, called by FUN_004b9da0

**Moddability:** `hardcoded` — epsilon constant baked in

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b66e0 — Lap/Speed Comparison with Switch-Selectable Thresholds

Source: likely_qualifying.cpp. Compares ABS(param_2) and param_3 against threshold tables indexed by vehicle state (param_1+0x9ac). Returns comparison flags encoded in ushort bits (NaN, eq, lt). Used for lap timing or speed delta evaluation.

**Key logic:**
- Reads state index from param_1+0x9ac, subtracts 1, switches on result 0-3
- First comparison: ABS(param_2) < fVar1 (threshold per state: 0=2.0, 1=variable, 2=variable, 3=variable)
- If passes: returns ushort flag encoding (NaN flags in bits 10, eq in bit 14, lt in bit 8) with high byte=1
- Second comparison: param_3 vs _DAT_0059e8f4 (upper bound) — if param_3 > bound or >= 0f, clamp check
- Third comparison: ABS(param_2) < fVar2 (secondary threshold per state with distinct constants per state)
- Returns combined ushort flags

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x9ac | ComparisonMode | int, 0-3 selecting threshold set |

**Calls:** none, called by FUN_004b6360

**Moddability:** `hardcoded` — per-state thresholds are compile-time constants

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b0e30 — Vehicle Data Field Copy

Source: likely_transmission.cpp. Copies 15 vehicle data fields from one offset range to another. Reads from wide-spaced source offsets (0x654-0x2858) and writes to consecutive destination offsets (0x496c-0x49a4). Likely a gearbox/transmission state snapshot for UI or replay.

**Key logic:**
- Copies 15 fields by assignment (source → dest):
  - 0x654 → 0x496c, 0x888 → 0x4970, 0x984 → 0x4974, 0xa80 → 0x4978
  - 0xb7c → 0x497c, 0xc78 → 0x4980, 0xd44 (byte) → 0x4984 (byte)
  - 0x209c → 0x4988, 0x2198 → 0x498c, 0x2294 → 0x4990
  - 0x2390 → 0x4994, 0x2588 → 0x4998, 0x275c → 0x499c
  - 0x2858 → 0x49a0, 0x248c → 0x49a4
- Returns CONCAT31 of 0x2858 byte shifted right, with 1 in lowest byte (success flag)

**Calls:** none, called by FUN_004b0720, FUN_004b0930

**Moddability:** `hardcoded` — pure data copy, no configuration

<!-- target: docs/06-session-race-logic.md -->

## FUN_0050a3ce — Vertex/Texture Decoder 10-10-10-2

Source: likely_renderer_texture.cpp. Decodes 32-bit packed vertex/texel data to float RGBA. NOTE: Classified as game_logic but is a renderer texture format converter.

**Key logic:**
- Computes source pointer: param_1+0x18 + param_1+0x1050×param_2 + param_1+0x1054×param_3 (row-major texture addressing)
- Iterates over count at param_1+0x1058
- For each uint32 texel: unpack channels via bit shifts and sign extension:
  - R: bits 0-9, `(short)(val << 6) >> 6` (signed 10-bit) × _DAT_0059e4d8
  - G: bits 10-19, `(short)(val >> 10) << 5 >> 5` (signed 10-bit) × _DAT_005acf38
  - B: bits 21-31, `(short)(val >> 0x15)` (signed 11-bit) × _DAT_005acf38
  - A: 1.0
- If param_1+0x10 != 0: calls FUN_00507845 (swizzle/endian fixup)

**Globals:**
- `_DAT_0059e4d8` — R channel scale factor
- `_DAT_005acf38` — G/B channel scale factor
- `_DAT_0059e98c` — alpha scale (unused here)

**Calls:** FUN_00507845 (pixel swizzle, worker Q), FUN_00506ce2 (indirect resolution)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00509812 — Vertex/Texture Decoder RGB 5-6-5

Source: likely_renderer_texture.cpp. Decodes 16-bit 5-6-5 RGB texels to float RGBA. NOTE: Classified as game_logic but is a renderer texture format converter.

**Key logic:**
- Same row-major addressing as FUN_0050a3ce (param_1+0x1050, 0x1054, 0x1058)
- For each uint16 texel: unpack 5-6-5:
  - R: bits 11-15, `val >> 0xb` × _DAT_005accd4
  - G: bits 5-10, `(val & 0x7e0) >> 5` × _DAT_005accdc
  - B: bits 0-4, `val & 0x1f` × _DAT_005accd4
  - A: 1.0
- If param_1+0x10 != 0: calls FUN_00507845 (swizzle/endian fixup)

**Globals:**
- `_DAT_005accd4` — R/B channel scale (1.0/31 = 0.032258f)
- `_DAT_005accdc` — G channel scale (1.0/63 = 0.01587f)

**Calls:** FUN_00507845 (pixel swizzle)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042ce00 — Thunk

Thunk — delegates to FUN_0042cee0 (game state update, worker S). No entry needed.

<!-- target: docs/06-session-race-logic.md -->

## FUN_00507ee4 — Texture Encoder RGBA 4-4-4-4

Source: likely_renderer_texture.cpp. Quantizes float RGBA pixels to 16-bit 4-4-4-4 format with dithering. NOTE: Classified as game_logic but is a renderer texture format converter.

**Key logic:**
- If param_1+0x1048 != 0: resolves indirect buffer via FUN_00506ce2
- Calls FUN_00507473 (dither state init)
- Loops over count at param_1+0x1058
- For each pixel: reads 4 floats at stride 0x10, applies dither offset from 4x4 dither matrix (param_1+0x2c, indexed by (param_3&3) + (param_2&3)×8 + (uVar9&3))
- Quantizes RGBA: `round(f * _DAT_0059e8d8 + dither)`, packs into 4-4-4-4 ushort (4 bits per channel, << 4 shifts)
- Writes ushort to output buffer

**Globals:**
- `_DAT_0059e8d8` — 4-4-4-4 quantization scale (15.0f)

**Calls:** FUN_00506ce2 (buffer resolve), FUN_00507473 (dither init)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_005094e8 — Texture Encoder RGBA 8-8-8-8 Packed

Source: likely_renderer_texture.cpp. Quantizes float RGBA pixels to 32-bit packed format with dithering. NOTE: Classified as game_logic but is a renderer texture format converter.

**Key logic:**
- If param_1+0x1048 != 0: resolves indirect buffer via FUN_00506ce2
- Computes source address with row-major stride (param_1+0x1050×param_2 + param_1+0x1054×param_3)
- Calls FUN_00507473 (dither init)
- Loops over count at param_1+0x1058
- For each pixel: reads RGBA floats, applies dither from 4×4 matrix
- Quantizes: `round(f * _DAT_0059f120 + dither)` for each channel
- Packs into two uint32s with complex bit packing (channel interleave)

**Globals:**
- `_DAT_0059f120` — 8-bit quantization scale (255.0f)

**Calls:** FUN_00506ce2 (buffer resolve), FUN_00507473 (dither init)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0052ddc0 — Network Packet Send

Source: likely_network.cpp. Sends a 4-byte message over network with byte swapping. NOTE: Classified as game_logic but is a network function.

**Key logic:**
- Reads device pointer from param_1+0x2d34
- Calls device send function (vtable+8) with 4-byte packet
- Swaps byte order: `(val >> 24) | ((val & 0xff0000) >> 8) | ((val & 0xff00) << 8) | (val << 24)` (big-endian network order)
- Passes to FUN_0052da30 (network send with validation)
- Returns 0 on success, -1 on failure

**Calls:** FUN_0052da30 (network send), device vtable through param_1+0x2d34

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e3a10 — Vehicle Wheel Count Iterator

Source: likely_wheel_manager.cpp. Calls a per-wheel function for each wheel on the vehicle.

**Key logic:**
- Reads wheel count from param_1+0xba8
- If count > 0: loops calling FUN_004df0a0(param_2) for each wheel
- param_2 is passed through unchanged (likely context/payload)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xba8 | WheelCount | int, number of wheels to process |

**Calls:** FUN_004df0a0 (per-wheel update), called by vehicle physics update

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00543870 — UI Element Position Setter

Source: likely_ui_layout.cpp. Sets three 16-bit position/dimension values and marks a dirty flag.

**Key logic:**
- Stores param_2 → param_1+0x18c (width/height)
- Stores param_4 → param_1+0x188 (x position)
- Stores param_3 → param_1+0x18a (y position)
- ORs bit 0x10000 into param_1+0xec (dirty/update flag)

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00513cf0 — Music/Sound Selection Controller

Source: likely_audio_music.cpp. Conditionally selects next track/sound based on control flags. NOTE: Classified as game_logic but is an audio playback controller.

**Key logic:**
- Checks param_1+0x10c bit 0x20 (loop flag): if set, checks param_1+0x5c & 0x300 == 0x300 (both channels busy) → return (skip selection)
- If loop flag not set: checks param_1+0x5d bit 8 (stop flag) → return
- Otherwise: calls FUN_0051923d with stored handle at param_1+0x100 and new params
- Stores returned handle back to param_1+0x100

**Calls:** FUN_0051923d (track/sound selection)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c7a70 — Vehicle AI Control Flag

Source: likely_ai_control.cpp. Sets/clears bit 0 of the AI control flags field.

**Key logic:**
- If param_2 != 0: sets bit 0 at param_1+0x48bc (AI control enabled)
- If param_2 == 0: clears bit 0 at param_1+0x48bc (AI control disabled)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x48bc | AIControlFlags | uint, bit 0 = AI enable |

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00545a10 — UI LinkedList Cleanup Iterator

Source: likely_ui_manager.cpp. Traverses a linked list of UI nodes and calls cleanup for each.

**Key logic:**
- Starts at param_1+0x15c (list head)
- Walks linked list via `next` pointer at offset +0x34
- For each node: calls FUN_00560c10(param_1, 0) (cleanup/destroy)
- Returns 0

**Calls:** FUN_00560c10 (UI cleanup)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051249f — Camera/Rotation State Setter

Source: likely_transform.cpp. Stores two float values (rotation/position) with threshold validation.

**Key logic:**
- Checks if `ABS(param_2 * param_3 - _DAT_0059e420)` > _DAT_005af428 (tolerance)
- If above threshold: sets bit 0x20 at param_1+0x61 (dirty/clamp flag)
- Stores param_3 as float → param_1+0x130 (x/rotation)
- Stores param_2 as float → param_1+0x134 (y/position)

**Globals:**
- `_DAT_0059e420` — reference value (gravity?)
- `_DAT_005af428` — validation threshold

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b8140 — Vehicle List Count Getter

Source: likely_vehicle_list.cpp. Returns the count field from a vehicle list structure.

**Key logic:**
- Returns *(param_1+0x6cc) — the node count of a linked list

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0052de60 — Audio/Network Buffer Timing Calc

Source: likely_audio.cpp. Computes buffer timing parameters from sample rate. NOTE: Classified as game_logic but is an audio timing function.

**Key logic:**
- Reads sample rate from param_1+0x2484, buffer size from param_1+0x2494
- Computes buffer duration in ms: `(bufferSize * 0x23280) / sampleRate` → stored at 0x24d8
- Remainder/100 → 0x24dc, sampleRate/100 → 0x24e0
- Sets 0x24d4 = 1 (flag: ready)
- If param_1+0x2490 (mode) == 1: `bufferSize * 0x300` (768 samples) → 0x248c
- Else: `bufferSize * 0x900` (2304 samples) → 0x248c
- Sets 0x24bc = 1 (dirty flag), copies to 0x249c

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x2484 | SampleRate | int, Hz |
| +0x2494 | BufferSize | int, samples |
| +0x2490 | ModeFlag | char, 1=small buffer mode |
| +0x24d4 | ReadyFlag | int, set to 1 |
| +0x24d8 | BufferDurationMs | int, computed |
| +0x248c | FrameSize | int, 768 or 2304 samples |

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00508f3d — Texture Encoder RGB 5-6-5

Source: likely_renderer_texture.cpp. Quantizes float RGB pixels to 16-bit 5-6-5 format with dithering. NOTE: Classified as game_logic but is a renderer texture format converter.

**Key logic:**
- If param_1+0x1048 != 0: resolves indirect buffer via FUN_00506ce2
- Calls FUN_00507473 (dither state init)
- Loops over count at param_1+0x1058
- For each pixel: reads 3 floats (RGB), applies dither from 4×4 matrix indexed by (param_3&3) + (param_2&3)×8 + (uVar5&3)
- Quantizes: R 5-bit (×_DAT_005accb4), G 6-bit (×_DAT_005acee4), B 5-bit (×_DAT_005acee4)
- Packs into ushort: `R & 0x3ff | (G & 0x7ff) << 10 | (B & 0x7ff) << 0xb`

**Globals:**
- `_DAT_005accb4` — 5-bit R scale
- `_DAT_005acee4` — 6-bit G / 5-bit B scale

**Calls:** FUN_00506ce2 (buffer resolve), FUN_00507473 (dither init)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00509ab8 — Vertex/Texture Decoder RGBA 10-10-10-2

Source: likely_renderer_texture.cpp. Decodes 32-bit packed RGBA 10-10-10-2 texels to float RGBA. NOTE: Classified as game_logic but is a renderer texture format converter.

**Key logic:**
- Same row-major addressing as above
- For each uint32 texel: unpack 10-10-10-2:
  - R: bits 0-9, `val & 0x3ff` × _DAT_005adba4
  - G: bits 10-19, `val >> 10 & 0x3ff` × _DAT_005adba4
  - B: bits 20-29, `val >> 0x14 & 0x3ff` × _DAT_005adba4
  - A: bits 30-31, `val >> 0x1e` × _DAT_0059e98c
- If param_1+0x10 != 0: calls FUN_00507845

**Globals:**
- `_DAT_005adba4` — RGB channel scale
- `_DAT_0059e98c` — alpha scale (0.333f for 2-bit)

**Calls:** FUN_00507845 (pixel swizzle)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_00423e80 — RaceStructInit

Source: Unknown. Initializes a large driver/vehicle struct to default state.

**Key logic:**
- Calls sub-initializers FUN_004e4500 (top-level subsystem init), FUN_004bb7a0 (sub-struct init), and FUN_0042ae00 (zeroes 20 ints at AIStateFlags +0x4354)
- Zeroes ~30 fields across offsets 0x4400–0x44AC (int-indexed 0x1100–0x112b)
- Sets several sentinel values: field at int-index 1 to 0xffffffff, field at int-index 2 to 0xffffffff
- Sets float fields at int-indices 0x110e and 0x1111 to 1.0f (0x3f800000) — these are AIFollowTarget-related
- Sets float fields at int-indices 0x104f and 0x1121 to FLT_MAX (0x7f7fffff)
- Sets byte fields at int-indices 0x1117 and 0x1122 to 1 (boolean flags)
- Sets int-index 0x112c to 0xffffffff
- Returns param_1 pointer

**Calls:** FUN_004e4500 (subsystem init), FUN_004bb7a0 (sub-struct init), FUN_0042ae00 (clear AIStateFlags at +0x4354)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051af57 — BitstreamDecoder

Source: Unknown. Reads compressed bitstream from param_2 and writes decoded 16-bit values to output buffers.

**Key logic:**
- Reads bitstream state from param_1 fields at +0x194 (bitstream struct), +0x174, +0xfc, +0x13c, +0x14
- Returns 0 early if conditions fail: param_1+0xfc != 0 and bitstream offset 0x34 indicates no output space or FUN_0051aefc returns false
- Iterates through input entries pointed to by param_2 array, count controlled by param_1+0x13c
- For each entry, reads bits from stream using FUN_0051a794 (buffer refill)
- Decodes symbols using lookup tables at DAT_005b0488 and DAT_005b04c8 (likely Huffman tables)
- Tracks bit position in stream (param_1+0x14, iVar10 tracks remaining bits)
- Writes decoded values as 16-bit shorts via target pointers from param_2
- Decrements bitstream refcount at bitstream struct +0x34
- Returns 1 on success, 0 on decode error

**Calls:** FUN_0051aefc (check condition), FUN_0051a794 (buffer refill), FUN_0051a87e (decode symbol)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b9da0 — MenuActionDispatch

Source: Unknown. Dispatches a parameter value (0–0xD) to corresponding codec/playback actions.

**Key logic:**
- Switch on param_2 (0–0xD):
  - Cases 0–8: Writes param_2 value to `*param_1 + 0xf8c` (menu selection state), returns 1
  - Case 9: Calls FUN_004b81a0(0) — replay/playback reset
  - Case 10: Calls FUN_004b8360() — rewind or seek
  - Case 11: Calls FUN_004b8480() — play/start
  - Case 12: Calls FUN_004b84f0() — pause
  - Case 13: Calls FUN_004b85d0() — stop
- All paths return 1

**Calls:** FUN_004b81a0 (playback reset, docs/06), FUN_004b8360 (seek/rewind), FUN_004b8480 (play start), FUN_004b84f0 (pause), FUN_004b85d0 (stop)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051ba70 — HuffmanTreeAlloc

Source: Unknown. Allocates and initializes a Huffman decode tree structure.

**Key logic:**
- Allocates 0x50-byte struct via vtabled allocator at param_1+4, stores at param_1+0x194
- Sets vtable pointer to FUN_0051b7cd
- Zeroes fields at indices 0xe–0x11 (tree node counters)
- Allocates second buffer of size (param_1+0x20) << 8 (256 bytes per entry in tree table)
- Initializes all entries to 0xffffffff (empty/unused nodes)
- Stores buffer at param_1+0x8c

**Calls:** Vtable allocator function at param_1+4

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051d166 — StreamDecoderInit

Source: Unknown. Initializes a stream decoding context with FIR filter coefficients.

**Key logic:**
- Allocates 0x30-byte struct via vtabled allocator, stores at param_1+0x19c
- Sets vtable function based on param_1+0x110: if ==2, uses FUN_0051cd53/FUN_0051cf80 with buffer allocation; else uses FUN_0051cdf9/FUN_0051ce2a
- Allocates four 0x400-byte buffers (coefficient tables or intermediate buffers)
- Fills buffers with precomputed FIR filter coefficients using fixed-point math:
  - Buffer 0: init value -0xb2f480>>16, increment +0x166e9 (decompanding table)
  - Buffer 1: init value -0xe25100>>16, increment +0x1c5a2
  - Buffer 2: pointer to DAT_005b6900, decrement -0xb6d2
  - Buffer 3: init value 0x2c8d00, decrement -0x581a
- Loop runs until value below -0x2b34e7

**Calls:** Vtable allocator, FUN_0051cd53, FUN_0051cf80, FUN_0051cdf9, FUN_0051ce2a

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0044f460 — PackedFlagRead

Source: Unknown. Reads a packed boolean flag from a struct byte array, with server-mode override.

**Key logic:**
- Calls FUN_00404f10 (assertion check)
- If assertion active and DAT_007c569c (SessionType5) == 5 (server mode) and param_2 != 1: returns param_2 & 0xffffff00 (masks out low byte)
- Otherwise: reads byte at offset param_2 + 0x37c + param_1, shifts right by 1, masks bit 0

**Globals:**
- `DAT_007c569c` — SessionType5 (5=server, docs/12)

**Calls:** FUN_00404f10 (assertion/validation)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e8ce0 — TireForceSolver

Source: Unknown. Iterative numerical root-finder for vehicle tire/contact patch force solution.

**Key logic:**
- Computes fVar2 = ABS(param_4) * *(float *)(param_1 + 0x3cfc) (scaled input)
- Uses lookup table at param_1+0x3d00 (14 entries, stride 4) with linear interpolation via FUN_005895a2 (sqrt) and ROUND
- Compares against global thresholds: _DAT_0059e6fc (upper clamp), DAT_0059e440 (zero threshold), _DAT_0059e46c (offset)
- Evaluates force/slip function using fields at param_1+0x3a70, +0x3514, +0x3c7c, +0x3c3c (stiffness/damping coefficients)
- Branches on sign of computed value relative to DAT_0059e440 (zero threshold) — selects between two interpolation tables at +0x3c80 (tension) and +0x3c40 (compression)
- Iterates between bounds local_2c and local_30, stepping by param_5
- Returns interpolated root when sign change detected between fVar4 and fVar5 (regula falsi method)
- Clamps result to _DAT_0059e6fc upper bound or 128.0

**Globals:**
- `DAT_0059e440` — zero/comparison threshold
- `_DAT_0059e6fc` — upper bound clamp
- `_DAT_0059e46c` — offset value
- `_DAT_0059e450` — fallback ratio

**Calls:** FUN_005895a2 (math sqrt utility, docs/20)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051bf23 — PlaybackBufferAlloc

Source: Unknown. Allocates and initializes a playback/stream buffer with optional shared memory.

**Key logic:**
- Allocates 0x1c-byte struct via vtabled allocator, stores at param_1+0x188
- Sets vtable pointer to FUN_0051be7d
- Zeroes fields at indices 2 and 3
- If flag at param_1+0x4a is non-zero:
  - Copies param_1+0x110 to puVar2[4] (buffer size)
  - If param_2 == 0: allocates buffer via vtable+8 of size (param_1+100)*(param_1+0x5c), stores at puVar2[3]
  - If param_2 != 0: calls FUN_00515927 with param_1+0x60, then allocates via vtable+0x10, stores at puVar2[2]

**Calls:** FUN_00515927 (shared memory lookup), vtabled allocator

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004ed380 — AnisoVectorTripleProduct

Source: Unknown. Computes an anisotropic vector triple product with offset. Pure math utility.

**Key logic:**
- Takes two 3-element float vectors (param_2, param_3) and computes cross product terms
- Each cross term scaled by anisotropic factor from param_1: +0x3528 (x), +0x352c (y), +0x3530 (z)
- Combines scaled cross terms with dot product against the second vector
- Adds base offset at param_1+0x3518
- Formula: result = Σ_i (cross_product(param_2, param_3)_i * scale_i) · param_3 + offset
- Triple precision (float10) intermediate arithmetic

**Calls:** None (pure math)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051aec2 — HuffmanCtxAlloc

Source: Unknown. Allocates and initializes Huffman encoding/decoding context.

**Key logic:**
- Allocates 0x58-byte struct via vtabled allocator, stores at param_1+0x194
- Sets vtable pointers: FUN_0051ad93 and FUN_0051a9c6
- Zeroes 4 int32s starting at index +0xd (fields at bytes +0x34 through +0x43)

**Calls:** Vtabled allocator

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004ef5a0 — SessionStateTransition

Source: Unknown. Handles session state transitions with server-side notification.

**Key logic:**
- Stores param_2 into param_1[0xcaf] (session state)
- If param_3 != 0 (forced update):
  - Returns early if DAT_007c569c != 5 (not server mode)
  - If transitioning from non-zero state to zero: calls FUN_004efb20, FUN_004ef7c0, load 3 floats from int-indices 0xd3b-0xd3d, calls FUN_00447780 (vector math)
- If DAT_007c569c == 5 (server mode) and transitioning to state 1:
  - Calls FUN_004e9630 (get session context), extracts value at offset 300
  - Calls FUN_0042adb0(), FUN_0042aca0(uVar2)
  - Clears AIStateFlags at +0x4354 and +0x4358

**Globals:**
- `DAT_007c569c` — SessionType5 (5=server, docs/12)

**Calls:** FUN_004efb20, FUN_004ef7c0, FUN_00447780 (vector math), FUN_004e9630 (session ctx), FUN_0042adb0, FUN_0042aca0

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e2ca0 — ScalePropagate

Source: Unknown. Propagates a scaling ratio to dependent subsystems when a parameter changes.

**Key logic:**
- Compares param_2 against current value at param_1+0x970
- If changed: computes ratio = param_2 / old_value, updates stored value
- Calls FUN_004e2a00(main, ratio, 0) on main target at param_1+4
- If secondary target at *(param_1+4)+0x44 exists: calls FUN_004e2a00(secondary, ratio, 1)

**Calls:** FUN_004e2a00 (apply scaling ratio)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_0053d340 — LinkedListAppend

Source: Unknown. Appends a node to a global doubly-linked list.

**Key logic:**
- If DAT_008b8e20 (list head) is non-null: traverses list via +0x870 (next pointer) to find tail, appends node (sets prev +0x86c and next +0x870)
- If list is empty: sets DAT_008b8e20 = param_1, zeroes prev (+0x86c) and next (+0x870)

**Globals:**
- `DAT_008b8e20` — linked list head pointer

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e0e70 — SubslotCleanup

Source: Unknown. Cleans up a sub-slot in a resource array (stride 0x128).

**Key logic:**
- Computes slot address: param_1 + param_2 * 0x128
- Calls FUN_004e0d70(param_1 + 0x144) and FUN_004e0d70(param_1 + 0x188) — cleanup two sub-objects
- Calls FUN_004e2230(param_2, 0) — deregister/unlink
- If pointer at +0x188 is non-null: calls FUN_0054c030(0,0,0,0)

**Calls:** FUN_004e0d70 (object cleanup), FUN_004e2230 (deregister), FUN_0054c030 (resource release)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00537ec0 — ScorecardZero

Source: Unknown. Zeroes scorekeeping/history arrays in a session struct.

**Key logic:**
- Zeroes uint16 array at +0x8a: 0x11e entries (lap/sector history)
- Zeroes uint16 array at +0x97e: 0x1e entries (30)
- Zeroes uint16 array at +0xa72: 0x13 entries (19)
- Zeroes 4 int32 at offsets +0x169f, +0x169b, +0x16a3, +0x1693 (aggregate scores)
- Sets uint16 at +0x48a to 1 (flag/enabled)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e0d00 — LazyInitCallback

Source: Unknown. One-time initialization guard for a callback/connection object.

**Key logic:**
- If param_2[0] (object pointer) != 0 and param_2[0x10] (init flag) == 0:
  - Calls FUN_0054ba00(*param_2, 0) — register/connect
  - Calls FUN_0054b4d0 with 6 params from param_2[1..6] — configure callback
  - Sets param_2[0x10] = 1 (mark initialized)
  - Calls FUN_004e0ed0(param_1+0x964) and FUN_00411440 — post-init hooks

**Calls:** FUN_0054ba00 (register), FUN_0054b4d0 (configure), FUN_004e0ed0, FUN_00411440

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b7a00 — QueuePop

Source: Unknown. Pops front entries from two parallel queues and returns their values.

**Key logic:**
- Calls FUN_00566d70 and drains FUN_004b7860(1) until empty (flush pending)
- If count at param_1+0x720 > 0:
  - Reads front entry from queue1 at param_1+0x714, stores value at param_1+0xf30
  - Reads front entry from queue2 at param_1+0x718, stores value at param_1+0xf34
  - Advances queue pointers via param_1+0x71c
  - Returns non-zero if both queues have entries
- If count <= 0: zeroes +0xf30 and +0xf34, returns count

**Calls:** FUN_00566d70, FUN_004b7860 (queue flush)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f83b0 — DoubleBufferFree

Source: Unknown. Frees two dynamically allocated buffers of 180 bytes each.

**Key logic:**
- If buffer at param_1+0x694 is non-null: iterates 0xb4/4 = 45 entries, calls FUN_004f8250 on each, then calls FUN_00587bcf to free, zeroes pointer
- If buffer at param_1+0x6d8 is non-null: same cleanup
- Clears flag at param_1+4

**Calls:** FUN_004f8250 (per-entry cleanup), FUN_00587bcf (heap free)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b87a0 — QueuePeek

Source: Unknown. Reads front values from two parallel queues without dequeuing.

**Key logic:**
- Copies param_1+0xf30 → *param_2 (queue1 value)
- Copies param_1+0xf34 → *param_3 (queue2 value)
- Returns combined status: upper 3 bytes of queue2 value with low byte set to 1

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_00541420 — SubBufferFree

Source: Unknown. Frees a pair of allocated sub-buffers (main + offset +0x24).

**Key logic:**
- If param_1+0x114c is non-null:
  - Calls FUN_00540eb0 on the pointer (destructor)
  - Calls FUN_00540eb0 on the pointer +0x24 (sub-buffer destructor)
  - Re-allocates: calls FUN_00587bcf(pointer - 4) to free underlying allocation
  - Zeroes param_1+0x114c

**Calls:** FUN_00540eb0 (object destructor), FUN_00587bcf (heap free)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004a5c80 — StateChangeNotify

Source: Unknown. Handles a state change with ring-buffer logging and notification.

**Key logic:**
- If param_2 differs from stored state at param_1+0x184:
  - If param_2 == 1 OR (stored != 1 AND param_2 == 2): sets float at param_1+0x18c from _DAT_008afea0
  - Increments DAT_008aae64 (ring buffer counter) by 0x1b0
  - Increments DAT_0083ee60 if < 0x3ff (stops at 1023 entries)
  - Calls FUN_004b33b0(6, 1, 1, ...) — log/notify with severity 6
  - Stores param_2 as byte in ring buffer at iVar1+8
  - Calls FUN_004a5d10(iVar1) — process ring buffer entry

**Globals:**
- `DAT_008aae64` — ring buffer counter
- `DAT_0083ee60` — sequence counter (capped at 1023)
- `_DAT_008afea0` — state value source

**Calls:** FUN_004b33b0 (notification/log), FUN_004a5d10 (ring buffer process)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004efac0 — ConditionalGate

Source: Unknown. Conditional gate: either calls init or sets idle state.

**Key logic:**
- If param_1+0x32bc == 0 (not initialized): calls FUN_00447270 (init sequence)
- Else: zeroes param_1+0x3994 (idle/reset flag)

**Calls:** FUN_00447270

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f1c00 — ConditionalBufferCall

Source: Unknown. Conditional buffer operation based on initialization state.

**Key logic:**
- If param_1+0x32bc == 0 (not initialized): calls FUN_00447c70(param_2, 1)
- Otherwise: no-op

**Calls:** FUN_00447c70

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_005459d0 — LinkedListRemove

Source: Unknown. Removes a node from a doubly-linked list.

**Key logic:**
- Unlinks param_2 from list: updates prev node's +0x34 → param_2+0x34, next node's +0x30 → param_2+0x30
- If param_2 is the head (param_1+0x15c): updates head to param_2's next (+0x34)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c11d0 — FlagsGetter

Source: Unknown. Returns a uint32 value from a field offset.

**Key logic:**
- Returns *(uint32 *)(param_1 + 0xb148)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xb148 | UnknownFlags | uint32, purpose unknown |

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0042e320 — SessionStructInit

Source: unknown (game session module). Zero-initializes session state struct and sets default values.

**Key logic:**
- Sets field +0x68 to 0 and +0x6c to -1 (sentinel/inactive marker)
- Calls FUN_0042e1c0 in two loops: first 44 times, then 55 times (likely clearing sub-arrays)
- Calls FUN_0042dc60 (further setup)
- Sets bytes at +0x19a4 and +0x19a5 to 1 (enabled flags)
- Zeroes first byte and multiple int fields at +0x70, +0x1988 through +0x19a0
- Writes 0x3f000000 (0.5f) to four float fields at +0x1ca8 through +0x1cb4
- Clears three 0x80-byte blocks starting at +0x19a6 (+0x1b26-0x180) with stride 0x80
- Calls FUN_0042e400 (finalize init)
- Returns param_1 pointer

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x68 | int | init to 0 |
| +0x6c | int | init to -1 (sentinel) |
| +0x70 | byte | init to 0 |
| +0x1988-0x19a0 | 6xint | zeroed (sub-struct) |
| +0x19a4 | byte | set to 1 (enabled) |
| +0x19a5 | byte | set to 1 (enabled) |
| +0x19a6 | 3x0x80 blocks | cleared 3 entries at stride 0x80 |
| +0x1ca8 | float | init to 0.5f |
| +0x1cac | float | init to 0.5f |
| +0x1cb0 | float | init to 0.5f |
| +0x1cb4 | float | init to 0.5f |

**Calls:** FUN_0042e1c0 (sub-array clear, looped 44+55=99 times), FUN_0042dc60 (session setup), FUN_0042e400 (finalize)

**Moddability:** hardcoded constants (0.5f default)

<!-- target: docs/06-session-race-logic.md -->

## FUN_004a4db0 — UIComponentCleanup

Source: unknown (UI module). Destructor/cleanup for UI component -- sets all state fields to defaults and frees sub-objects.

**Key logic:**
- Sets byte flags at +0x35, +0x75, +0xb5, +0xf5, +0x135 to 1 (enabled per entry)
- Zeroes int fields at +0x158, +0x184, +0x188, +0x18c, +0x194-0x1cc (large block), +8
- Sets byte at +0x190 (400 decimal) to 0
- Sets sentinel values -1 at +0x15c, +0x160
- Frees three sub-objects at +0xc, +0x10 (via FUN_004a29a0 + FUN_00587bcf) and +0x14 (via FUN_004a3b30 + FUN_004a2220 + FUN_00587bcf)
- Sets freed pointers to 0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x35 | byte | per-entry enabled flag |
| +0x75 | byte | per-entry enabled flag |
| +0xb5 | byte | per-entry enabled flag |
| +0xf5 | byte | per-entry enabled flag |
| +0x135 | byte | per-entry enabled flag |
| +0x158 | int | counter/state, zeroed |
| +0x15c | int | set to -1 |
| +0x160 | int | set to -1 |
| +0x184-0x1cc | ints | zeroed cleanup block |

**Calls:** FUN_004a29a0 (pre-free check), FUN_00587bcf (heap free), FUN_004a3b30 (sub-object cleanup), FUN_004a2220 (pre-free)

**Moddability:** hardcoded (cleanup)

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042bd60 — SeasonScoringReset

Source: steward module. Resets all season scoring entries and clears DAT_007c5690 flag.

**Key logic:**
- Sets DAT_007c5690 to 0 (scoring disabled)
- Iterates through season scoring database at DAT_005ec6e4 with stride 0x48c0 (matches SeasonScoringDB entry size) until address reaches 0x7c54e4
- For each entry: calls FUN_004c6960(iVar2) to reset entry, then FUN_004ef5a0(0xffffffff, 0)

**Globals:**
- `DAT_007c5690` -- scoring active flag (written to 0)
- `DAT_005ec6e4` -- SeasonScoringDB base pointer (stride 0x48c0)

**Calls:** FUN_004c6960 (reset scoring entry), FUN_004ef5a0 (clear per-vehicle, param1=-1 = all)

**Moddability:** hardcoded (system reset)

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b7c80 — NetworkBufferRead

Source: unknown (network/session). Reads data from a streaming buffer with chunk-size boundary checks.

**Key logic:**
- Reads linked list head at param_1+0x714, stores current position in param_1+0x71c
- Walks linked list of buffer segments, comparing float param_5 (offset bound) against each segment start
- When param_4 (read_size) <= segment_start, copies 0x400-byte chunks via FUN_00566bd0/FUN_00566c00
- Returns number of bytes read (iVar6)
- If next segment is null, calls FUN_00566d70 to check remaining, calculates gap

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x714 | ptr | linked list head (buffer segments) |
| +0x71c | ptr | current read position cursor |
| +0x718 | ptr | linked list tail |

**Calls:** FUN_00566db0 (stream position), FUN_00566d70 (stream available check), FUN_00566e20 (stream tell), FUN_00566c00 (buffer read prepare), FUN_00566bd0 (buffer read execute)

**Moddability:** configurable (buffer chunk size 1024 is hardcoded)

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042bc10 — ScoringGateCheck

Source: steward module. Checks if scoring gate DAT_007d2e44 is active or if FUN_00461cd0 returns non-1.

**Key logic:**
- If DAT_007d2e44 == 0: calls FUN_00461cd0(), returns 1 if result != 1
- Returns 0 otherwise (gate inactive or test passed)

**Globals:**
- `DAT_007d2e44` -- scoring gate enable flag

**Calls:** FUN_00461cd0 (condition test)

**Moddability:** configurable (DAT_007d2e44 gating flag)

<!-- target: docs/06-session-race-logic.md -->

## FUN_005389b0 — RunLengthAnalyzer

Source: unknown (AI analysis). Analyzes consecutive value runs in a data sequence, updating frequency counters based on run length.

**Key logic:**
- Reads first value from param_2+2 (ushort)
- Sets sequence terminator at param_2+6+param_3*4 to 0xffff
- Walks ushort pairs at param_2+6, counting consecutive equal values
- Three thresholds: short (3-4), mid (6-0x8a), long
- If value == 0: increments counter at +0xab6 (short runs < 11) or +0xaba (long runs >= 11)
- If value != 0 and run length < threshold: increments per-value counter at +0xa72+value*4
- Else: increments generic counter at +0xab2
- Adjusts thresholds based on current/next value match pattern

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xa72 | short[256] | per-value run frequency counters |
| +0xab2 | short | generic cross-value run counter |
| +0xab6 | short | zero-value short run counter |
| +0xaba | short | zero-value long run counter |

**Calls:** (none, pure logic)

**Moddability:** hardcoded (thresholds 3,4,6,0x8a,11)

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f0050 — DistanceProjectionCalc

Source: vehicle physics. Computes distance between two tracked positions and projects a value onto that vector, clamped by TrackRefSpeed limits.

**Key logic:**
- Gets player vehicle ptr via FUN_004e9630
- Reads positions from ptr[0x44] and ptr[0x43] (vec3 pairs)
- If both positions equal (diff=0), returns ptr[0x12] (base lap value)
- Normalizes direction vector, computes dot product with (target_position - base_position)
- Clamps result: if below 0 -> 0; if above TrackRefSpeed DAT_005ea3fc -> reduce by DAT_005ea3fc; if still above -> set to DAT_005ea3fc

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x34d4 | float | target X |
| +0x34d8 | float | target Y |
| +0x34dc | float | target Z |

**Globals:**
- `DAT_0059e440` -- zero constant (0.0f)
- `DAT_0059e43c` -- 1.0f constant
- `DAT_005ea3fc` -- TrackRefSpeed threshold (clamp limit)

**Calls:** FUN_004e9630 (get player vehicle ptr)

**Moddability:** configurable (DAT_005ea3fc TrackRefSpeed)

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042ae90 — StateFlagsLookup

Source: unknown (game session). Returns entry from a 0x10-byte-strided table indexed by (param_1+0x4588 - 1), clamped non-negative.

**Key logic:**
- Reads value at param_1+0x4588 (likely count/state), subtracts 1
- If result negative, wraps to 0 via (uVar1 & ((int)uVar1 < 0) - 1) trick
- Multiplies by 0x10 (entry stride) and adds base offset +0x4590
- Returns uint at computed address

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4588 | int | state/count index |
| +0x4590 | uint[?] | table at stride 0x10 |

**Moddability:** hardcoded (table stride 0x10)

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042add0 — AIDelegateCall

Source: unknown (AI module). Delegates to FUN_00403aa0 with AI state flag from param_1+0x4354 and target param at +0x4550.

**Key logic:**
- Calls FUN_00403aa0(param_1+0x34e0, *(param_1+0x4354), *(param_1+0x4550), 0)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x34e0 | ptr | AI state struct base |
| +0x4354 | int | AIStateFlags (AI state flags) |
| +0x4550 | int | AI target parameter |

**Calls:** FUN_00403aa0 (AI state machine transition)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00548c20 — SceneRenderTransform

Source: renderer/scene. Sets up 3D camera transformation for rendering a scene node.

**Key logic:**
- If param_1[2] != 0 (child count): calls FUN_0054b530 to get translation values
- Calls FUN_00541d10(-tx, -ty - y_offset, -tz) to set camera position
- Calls FUN_00541db0(~pi/2, -local_c[0], 0) for rotation
- If param_2+0x174 > 0: iterates render passes, calling FUN_00556930 for each
- Calls FUN_005550e0 to finalize render

**Struct offsets (param_2):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x174 | int | render pass count |

**Calls:** FUN_0054b530 (compute translation), FUN_00541d10 (translate), FUN_00541db0 (rotate), FUN_005572b0 (render begin), FUN_00541a70, FUN_00541b70 (render state), FUN_00556930 (render object), FUN_005550e0 (render finalize)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f7010 — StateHandlerDispatch

Source: unknown (game module). Dispatches vtable callbacks based on state flag at param_1+0xb0, iterating arrays at +0x6d8 or +0x694.

**Key logic:**
- If byte at +0xb0 == 0: iterates 0xb4/4 = 45 entries at array +0x6d8, calling each vtable+8 if non-null
- If byte at +0xb0 != 0: iterates 0xb4/4 = 45 entries at array +0x694, calling each vtable+8 if non-null
- Stores param_2 into +0xb0 after dispatch

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xb0 | byte | state flag (0=first array, non-zero=second array) |
| +0x694 | ptr | array of vtable pointers (state 1) |
| +0x6d8 | ptr | array of vtable pointers (state 0) |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00544c50 — TreeNodeAccumulator

Source: unknown (scene graph/tree). Recursively traverses a tree structure accumulating values from leaf nodes.

**Key logic:**
- Selects counter base at param_1+0x3c or +0x40 based on flag (bit 0x10) at param_2+0x3c
- Walks param_2 child linked list at +0x204 (stride 0x10), accumulating +0x120 value into param_1+0x38 and incrementing count at param_1+0x34
- For each child: zeroes short values at child+0x11c+2, copies uint fields, calls FUN_005473c0
- Accumulates child+0x11c+8 into selected base
- Increments loop counter at param_1+100
- Recurses into param_2+0x44 child, then follows sibling at +0x4c

**Calls:** FUN_005473c0 (per-child processing)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b5f60 — LinkedBufferTransfer

Source: unknown (network/session). Transfers items between two linked lists with state management, removing from one list and adding to another FIFO queue.

**Key logic:**
- Walks linked list at param_1+0x714 using cursor at param_1+0x71c
- Searches for matching value iVar1 in the linked list
- Removes matching node from the linked list (updating prev/next pointers at offsets +4/+8)
- Decrements count at param_1+0x720
- If node has flag at offset +3 nonzero: calls FUN_00587bcf to free contained data
- Frees the node with FUN_00587bcf
- Creates new node (0xc bytes) with same iVar1 value
- Appends to FIFO queue at param_1+0x30/0x34/0x38
- Increments count at param_1+0x3c

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x714 | ptr | linked list head |
| +0x718 | ptr | linked list tail |
| +0x71c | ptr | traversal cursor |
| +0x720 | int | linked list count |
| +0x30 | ptr | FIFO queue head |
| +0x34 | ptr | FIFO queue first |
| +0x38 | ptr | FIFO queue last |
| +0x3c | int | FIFO queue count |

**Calls:** FUN_00587bcf (heap free), FUN_004b4460 (blocking wait/poll), operator_new (heap alloc)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e23ad — ArrayInitNegOne

Source: unknown. Initializes 4 entries in an array to -1 with stride 0x4a * 4 bytes.

**Key logic:**
- Writes 0xffffffff to 4 entries starting at param_1+0x1ec, each spaced by 0x4a * 4 = 0x128 bytes

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1ec | int[4] | entries at stride 0x128 |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054b330 — BitmaskClear

Source: unknown (scene graph). Recursively clears bitmask flags in a tree structure.

**Key logic:**
- Clears ~param_2 bits from param_1+0x3c
- If param_3 != 0: clears ~param_3 bits from first child (+0x204) and all siblings (+0x10 chain) at offset +0x14
- Recurses into child at +0x44
- Continues to sibling at +0x4c (recursive flag propagation)

**Calls:** FUN_0054b330 (recursive self-call)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004ed0f0 — AccumulatorClamp

Source: vehicle physics/handling. Updates an accumulator with clamped range using threshold checks.

**Key logic:**
- accumulator = param_2 * DAT_005acee8 + *(param_1+0x3a6c)
- If upper_bound < accumulator: clamp to upper bound (DAT_0059e8fc + +0x3a78)
- If accumulator < lower_bound (+0x3a78 + DAT_0059e868): set flag at +0x3d60=1 and decay +0x3a70 = (+0x3a80 + +0x3a70) * DAT_0059e450 (0.5f)
- If accumulator < extreme_lower (+0x3a78 + DAT_0059e8b4): set +0x3a70 = +0x3a80 (reset decay)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x3a6c | float | accumulator value |
| +0x3a70 | float | decay value |
| +0x3a78 | float | base threshold |
| +0x3a80 | float | reset/initial decay value |
| +0x3d60 | int | flag (set to 1 when below threshold) |

**Calls:** FUN_004e8010

**Moddability:** configurable (DAT_005acee8, DAT_0059e450=0.5f scale factor, thresholds)

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b8ae0 — StateTriggerCheck

Source: unknown (game loop). Checks conditions and triggers a sequence of setup calls if conditions met.

**Key logic:**
- Returns 0 if (fValue +0xf34 - +0xf30) < 0
- Otherwise calls 13 setup/init functions in sequence
- Returns 1 if DAT_007cc4c8 == 0 AND FUN_0044f460(1) returns 0 AND FUN_004b8790() result < *(param_1+0xf34)
- Returns 0 otherwise

**Globals:**
- `DAT_007cc4c8` -- check flag

**Calls:** FUN_004b8c40, FUN_004ba180, FUN_004cfcc0, FUN_00404460, FUN_004d4580, FUN_00455e50, FUN_0042c690, FUN_0040ca30, FUN_004c8b70, FUN_004b40a0, FUN_0049f070, FUN_004fa7e0, FUN_004a1830 (various system setup/init), FUN_0044f460 (condition check), FUN_004b8790 (compare value)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00515db8 — VtableDelegateDispatch

Source: unknown. Calls vtable functions from two function pointers, then copies a value between them.

**Key logic:**
- Calls FUN_00515bb0 (pre-dispatch)
- Calls FUN_00515d26 (pre-dispatch)
- Calls vtable[0] from param_1+0x194
- Calls vtable[0] from param_1+0x184
- Copies value from param_1+0x184+4 into *(param_1+0x18c)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x184 | ptr | vtable pointer A |
| +0x18c | ptr | output location |
| +0x194 | ptr | vtable pointer B |

**Calls:** FUN_00515bb0, FUN_00515d26 (pre-dispatch helpers)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e2c70 — ScoringGateValueSelect

Source: unknown. Returns value based on ScoringGate DAT_008ab6e4 state.

**Key logic:**
- If DAT_008ab6e4 == 2: calls FUN_004b9ce0() and writes result to param_1+0x984
- Otherwise: writes DAT_008afea0 value to param_1+0x984

**Globals:**
- `DAT_008ab6e4` -- ScoringGate (game state enum)
- `DAT_008afea0` -- default value

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x984 | float | output value |

**Calls:** FUN_004b9ce0 (gate-specific value calculation)

**Moddability:** configurable (DAT_008ab6e4 scoring gate)

<!-- target: docs/06-session-race-logic.md -->

## FUN_00544e20 — TreeActiveCheck

Source: unknown (scene/tree). Recursively checks if any leaf node in a tree is active via FUN_0054d030.

**Key logic:**
- If child at +0x44 exists and recursive check returns non-zero: returns -1
- If no sibling (+0x4c) OR param_2==0 OR sibling check returns 0: walks leaf chain at +0x204
- If any leaf's FUN_0054d030 returns non-zero: returns -1
- Otherwise returns 0

**Calls:** FUN_0054d030 (leaf active check), FUN_00544e20 (recursive self)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b69a0 — CircularCounterIncrement

Source: unknown. Increments a counter modulo the limit value, then triggers update.

**Key logic:**
- Counter at +0x9b8 = (counter + 1) % limit at +0x9b4
- Calls FUN_004b4e10

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x9b4 | int | modulo limit |
| +0x9b8 | int | counter |

**Calls:** FUN_004b4e10 (post-update handler)

**Moddability:** configurable (limit at +0x9b4)

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f1aa0 — VelocityThresholdCheck

Source: vehicle logic. Checks velocity magnitude against threshold, returns visibility/state flag.

**Key logic:**
- If param_1+0x32bc == 0: returns DAT_007c9080 (system default)
- If gear (1 < +0x3444 < 5): checks if velocity^2 < 1.0 and FUN_004effd0() returns non-zero -> returns 0 (disabled)
- Otherwise returns 1 (active)
- If gear out of range: returns 0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x32bc | int | enable flag |
| +0x3444 | int | current gear |
| +0x34ec | float | velocity X |
| +0x34f0 | float | velocity Y |
| +0x34f4 | float | velocity Z |

**Globals:**
- `DAT_007c9080` -- default return value
- `DAT_0059e43c` -- 1.0f constant

**Calls:** FUN_004effd0 (additional condition check)

**Moddability:** configurable (gear range thresholds)

<!-- target: docs/06-session-race-logic.md -->

## FUN_005001d0 — FieldCompareConstant

Source: unknown. Compares float field at +0x1bc against global constant DAT_005ad348.

**Key logic:**
- Returns 1 if field != DAT_005ad348, 0 otherwise

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1bc | float | field to compare |

**Globals:**
- `DAT_005ad348` -- comparison constant

**Moddability:** configurable (DAT_005ad348)

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b6920 — IndexedPointerLookup

Source: unknown. Returns pointer from array at param_1+0x9b0 indexed by param_2 * 0xb0.

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x9b0 | ptr | base of array (stride 0xb0) |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c1390 — FixedOffsetReturn

Source: unknown. Returns input pointer + 0xaf6c (constant offset into large struct).

**Key logic:**
- Returns param_1 + 0xaf6c

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_004e8010 — Tire Brush Model Force Solver

Source: Unknown (vehicle physics). Solves combined-slip tire forces using friction-circle brush model with 15 relaxation iterations per wheel.

**Key logic:**
- Computes longitudinal slip ratio and lateral slip angle for each of 4 wheels using speed-dependent scaling
- Inner loops (4 iterations × 4 patterns) compute longitudinal force, lateral force, and aligning moment using brush-model cubic equations
- Branch on param_2: if 0 → wet-grip multipliers applied via DAT_007d020c, DAT_007d0230, DAT_007d0254; if non-zero → dry-grip multipliers via DAT_005ad1b4, DAT_005ad1b0
- 15 outer iterations (0xf) solve relaxation/slip convergence with 128.0 initial step size halving each iteration (×DAT_0059e450 ≈ 0.5)
- Final pass computes wheel-load-dependent friction limits and stores 15 slip values per wheel
- Iteration count limited to 15, yields final force outputs per wheel

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x3514 | Unknown | float, per-vehicle multiplier |
| +0x3518 | Unknown | float, final force scaling |
| +0x358c/0x3594 | Suspension deflection | float, L/R front |
| +0x3610/0x362c | Wheel force base | float[4] at stride +0x3e×4 |
| +0x3684/0x368c | Suspension velocity | float, L/R front |
| +0x3708/0x377c/0x3784 | Suspension deflection/velocity rear | float |
| +0x3800/0x3874/0x387c | Spring forces rear | float |
| +0x38f8 | Anti-roll bar force front | float |
| +0x39b4 | Brake/TractionControl mode | int (0=off, 1=TC, 2=other) |
| +0x3a30/0x3a44 | Tire-road friction mu | float, front/rear pair |
| +0x3a6c/0x3a70 | Camber/relaxation length | float |
| +0x3bf4 | Unknown | float, inverse for wet scaling |
| +0x3bfc/0x3c3c/0x3c7c/0x3cbc | Tire stiffness per wheel | float × 4 |
| +0x3c40–0x3cff | Friction lookup table | float[16] per wheel, stride 0x10 |
| +0x3cfc | Combined stiffness factor | float |
| +0x3d00–0x3d3b | Solved slip ratios | float[15] |
| +0x3d3c | Total force output | float |
| +0x3d40 | Anti-roll contribution | float |
| +0x3d44 | Aligning moment | float |
| +0x4024 | Downforce multiplier | float |

**Globals:**
- `_DAT_0059e43c` — constant 1.0f
- `_DAT_0059e440` — constant 0.0f
- `_DAT_0059e450` — constant 0.5f (halving factor)
- `_DAT_0059e420` — constant 0.0? (inverse threshold)
- `_DAT_005acb44` — wheelbase or gear ratio constant
- `_DAT_005ad1b4` — dry grip multiplier
- `_DAT_005ad1b0` — dry grip secondary multiplier
- `_DAT_005aceb8` — constant offset in brush model
- `_DAT_005acee8` — front/rear distribution weight
- `_DAT_005ad1b8` — moment arm constant
- `_DAT_005ad1bc` — rear distribution weight
- `_DAT_005ad1c0` — cornering stiffness coefficient
- `_DAT_0059e8c8` — convergence threshold (terminates iteration)
- `_DAT_0059e670` — under-relaxation lower bound
- `_DAT_0059e800` — under-relaxation upper bound
- `_DAT_007d020c` — wet grip multiplier
- `_DAT_007d0230` — wet stiffness scale
- `_DAT_007d0254` — wet force scale
- `_DAT_005acdc4` — wet secondary scale
- `_DAT_0059e7f8` — anti-roll mixing factor
- `_DAT_007d0278` — speed scaling denominator
- `_DAT_007d029c` — reference speed
- `_DAT_0059e450` — 0.5f (halving)

**Calls:** FUN_005895a2 (floating-point sqrt lookup), thunk_FUN_004e8200 (if any)

**Moddability:** `configurable` — TireMu, Stiffness, GripMultipliers are field-configurable from .svm

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c15a0 — PitStop Phase Advance

Source: Unknown. Advances pit-stop animation/state machine through phases 1→7, then triggers pit execution.

**Key logic:**
- Switch on int at offset +0xb14c (current phase 1–7)
- Each case increments phase by 1 and resets byte at +0xb150 to 0
- Phase 7 → calls thunk_FUN_004c0f60 (pit service execution) and FUN_004c1670 (pit cleanup/post)
- After switch fallthrough, always resets +0xb150 = 0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xb14c | PitPhase | int, 1–7 phase counter |
| +0xb150 | PitPhaseSubStep | byte, reset to 0 each advancement |

**Calls:** thunk_FUN_004c0f60 (pit service), FUN_004c1670 (pit post-service)

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051a4f2 — UI List/ComboBox Constructor

Source: Unknown. Initializes a UI list control with either empty slots (param_2=0) or populated items (param_2≠0).

**Key logic:**
- Allocates 0x74 bytes via vtable allocator, stores at +0x184, sets vtable pointer and destructor
- Branch on param_2: if 0 → allocates 0x500 bytes, partitions into 10×0x80 blocks for item storage, sets vtable FUN_005199d5
- If param_2≠0 → iterates items from list at +0xc4 (stride 0x15), checks byte at offset 200 (selected flag), calls FUN_00515927 for name hashing, allocates/inserts into UI slots
- Count limited by *(param_1+0x20) — total item count

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x184 | ListDataPtr | void*, allocated storage |
| +0x20 | ItemCount | int, number of list items |
| +0xc4 | ItemArray | pointer array, stride 0x15×4 |

**Calls:** FUN_0051a4b7 (destructor), FUN_005199d5 (list handler), FUN_00515927 (string hashing), FUN_00519bb2 (handler, param_2≠0 branch), FUN_00519d51 (handler, param_2≠0 branch)

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051378b — Texture/Image Color Transform

Source: Unknown. Applies RGB color offset and bit-shift transformations to pixel data in a UI texture buffer.

**Key logic:**
- Checks flag at +0x60 for 0x602000 mask → if set, calls FUN_00513482 and, when byte at +0x116 == 3, adds offset from +0x138 to each RGB byte of every pixel (3 bytes per pixel, count from +0x108)
- Checks flag 8 at +0x60 → if set AND byte at +0x116 == 3, performs right-shift on RGB bytes using shift amounts from +0x150/+0x151/+0x152 (clamped to 0–8)
- Shift values outside 0–8 range are forced to 0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x60 | RenderFlags | uint, checked against 0x602000 and 8 |
| +0x116 | ColorDepthMode | byte, ==3 triggers processing |
| +0x104 | PixelDataPtr | pointer to RGB pixel data |
| +0x108 | PixelCount | ushort, number of pixels |
| +0x138 | ColorOffset | int, additive offset per channel |
| +0x150 | ShiftR | byte, R channel shift (clamped 0–8) |
| +0x151 | ShiftG | byte, G channel shift (clamped 0–8) |
| +0x152 | ShiftB | byte, B channel shift (clamped 0–8) |

**Calls:** FUN_00513482 (prior texture state update)

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e4e60 — Physics Integration State Machine

Source: Unknown. Selects between two physics integration modes based on squared magnitude thresholds and iterates wheel-level physics.

**Key logic:**
- Reads iteration count at +0x3498 and squared magnitude at +0x3508
- If square ≤ threshold at +0x349c → checks against upper threshold at +0x350c²+0x3504²+fVar1, if below → increments iteration count, copies +0x34a4 to +0x34a8
- If square > threshold → copies +0x34a0 to +0x34a8, increments iteration count
- Propagates selected value to 4 wheel slots at +0x35f0 with stride 0x3e
- If iteration count ≥ 1, runs loops of: FUN_004e4f40, FUN_004e58d0, FUN_004e51a0, FUN_004e5470, FUN_004e5ae0
- Sets +0x34ac = param_2 after loop

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x3498 | IterationCount | int |
| +0x349c | ForceThresholdLower | float |
| +0x34a0 | ValueA | undefined4 (state selection) |
| +0x34a4 | ValueB | undefined4 |
| +0x34a8 | SelectedOutput | undefined4 |
| +0x34ac | FinalOutput | undefined4 (= param_2) |
| +0x3504 | VarA | float |
| +0x3508 | VarB | float |
| +0x350c | VarC | float |
| +0x35f0 | WheelOutputs[4] | undefined4 at stride 0x3e±4 |

**Calls:** FUN_004e4f40, FUN_004e58d0, FUN_004e51a0, FUN_004e5470, FUN_004e5ae0 (wheel physics sub-solvers)

<!-- target: docs/06-session-race-logic.md -->

## FUN_004ae490 — Car Part Visibility Controller

Source: Unknown. Manages car body part visibility and animation parameters based on damage/repair state.

**Key logic:**
- Branches on repair state at +0x1ac8: 1 = repair active, 2 = not repairing
- State 1: hides front wing parts (+0xb10=0, +0xb34=0, +0xb58=0), shows rear wing (+0x1c30=1), sets animation speed 0.05f (0x3d4ccccd)
- State 2: shows front wing parts (+0xb10=1, etc.), hides rear wing (+0x1c30=0), sets animation speed 0.5f (0x3f000000)
- When state != 0: shows 7 additional body parts (set to 1), calls FUN_004b20d0 multiple times for audio/effects, then FUN_00423060 for additional sequences

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1ac8 | RepairState | int, 0=none, 1=repairing, 2=not repairing |
| +0xb10 | PartFrontWing1 | int, visibility flag |
| +0xb34 | PartFrontWing2 | int, visibility flag |
| +0xb58 | PartFrontWing3 | int, visibility flag |
| +0x1c30 | PartRearWing | int, visibility flag |
| +0x2348 | AnimParamA | float (0.05f or 0.5f) |
| +0x236c | AnimParamB | float (0.05f or 0.5f) |
| +0x26f0–0x2834 | BodyParts[7] | int[7], additional part visibility flags |

**Calls:** FUN_0047f1f0 (set part visibility), FUN_004646c0 (animation transform), FUN_004b20d0 (audio effect trigger), FUN_00423060 (random/sequence generator)

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042b8b0 — Deferred Callback Registration

Source: Unknown. Registers a function pointer for deferred execution via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e with pointer to LAB_0042b8c0 (code at 0x0042b8c0)
- This is a thunk/registration wrapper — the actual logic is at the callback address

**Calls:** FUN_00587b3e (deferred function registration, MSVC _atexit-like)

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051bc88 — UI List/ComboBox Buffer Allocator

Source: Unknown. Allocates and initializes per-item buffers for a UI list/combobox control.

**Key logic:**
- Allocates 0x54 bytes via vtable allocator, stores at +0x198, sets handler vtable to FUN_0051bad1
- For each item (count at +0x20), allocates 0x100-byte buffer via vtable allocator, stores pointer at stride 0x15 from +0xc4+0x50 offset
- Each 0x100-byte buffer zeroed (0x40 dwords)
- Each slot index set to 0xffffffff (unselected)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x198 | ListDataPtr | void*, allocated control header |
| +0x20 | ItemCount | int |
| +0xc4 | ItemBufferArray | pointer array, +0x50 offset per item |

**Calls:** FUN_0051bad1 (list item handler)

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054d7a0 — Collision Contact State Detection

Source: Unknown. Determines contact/collision state between a collision shape and a set of planes.

**Key logic:**
- Computes distance from contact point to collision shape center using param_3 offset and param_2 transform
- Checks bit 4 of flags at +0x14: if clear → simple distance test against thresholds at +0xf8/+0xf4, sets contact state to 4 (touching) if below threshold
- If bit 4 set → entering/exiting test: checks iteration count at +0xfc against 5, evaluates plane equations at param_2+0x104 (4-float stride = plane normal+distance)
- Tests each plane: if point is outside all planes → state 4 (touching); if inside any → state 2 (penetrating)
- Returns 0 always (success)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x14 | CollisionStateFlags | uint, bits 0-2 state, bit 4 mode flag |
| +0x18 | ContactMargin | float, tolerance for contact |
| +0xf4 | OuterRadius | float, bounding sphere outer |
| +0xf8 | InnerRadius | float, bounding sphere inner |
| +0xfc | ContactIteration | int, contact solver iteration count |

**Calls:** FUN_005895a2 (sqrt), FUN_00588570 (unused here)

**Moddability:** `configurable` — ContactMargin configurable from .svm

<!-- target: docs/06-session-race-logic.md -->

## FUN_00507845 — Contact Manifold Cleanup

Source: Unknown. Clears/resets collision contact entries when all 4 floats match reference values.

**Key logic:**
- Computes entry count from +0x1058 × 16 (0x10-byte entries)
- Iterates through 4-float entries at param_2
- If all 4 floats match reference values at +0x1c/+0x20/+0x24/+0x28, zeros all 4
- Used to remove stale/resolved contacts from collision manifold

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1058 | ContactCount | int, number of contact entries |
| +0x1c | RefX | float, reference X for matching |
| +0x20 | RefY | float, reference Y |
| +0x24 | RefZ | float, reference Z |
| +0x28 | RefW | float, reference W (penetration/distance) |

<!-- target: docs/06-session-race-logic.md -->

## FUN_005085c5 — Vertex Color Transform (Indexed + Offset)

Source: Unknown. Transforms vertex colors with texture lookup, blending with indexed palette values.

**Key logic:**
- If data at +0x1048 is non-null, calls FUN_00506ce2 for memory address translation
- Calls FUN_00507473 (prepare/dirty state)
- For each of *(param_1+0x1058) entries: searches 0x100 entries at param_1+0x38 (4-float stride) for closest match to param_4 (3-float position) within threshold _DAT_0059eae0
- Encodes a ushort: low byte = matched index, high byte = rounded float from extra data scaled by DAT_0059fec8 + palette entry from param_2/param_3-indexed table
- 0x10-byte stride for extra data in param_4

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1048 | DataTransformFlag | int |
| +0x2c | PaletteArrayPtr | int, base pointer |
| +0x1058 | VertexCount | int |
| +0x38 | ReferenceArray | float[4]×256 entries |

**Globals:**
- `_DAT_0059eae0` — distance threshold for vertex matching
- `DAT_0059fec8` — brightness/color multiplier

**Calls:** FUN_00506ce2 (memory/address translation), FUN_00507473 (state update)

<!-- target: docs/06-session-race-logic.md -->

## FUN_00508b1d — Vertex Color Transform (Direct Palette)

Source: Unknown. Encodes vertex colors directly from palette with lighting offset.

**Key logic:**
- If +0x1048 non-null, calls FUN_00506ce2 (address translation)
- Calls FUN_00507473 (state update)
- For each vertex: computes 5-bit RGB values from extra float data (param_4, stride 0x10) multiplied by _DAT_0059eed0 + palette value indexed by param_2/param_3/loop counter
- Result packed into ushort: bits 0-4 = R, bits 5-9 = G, bits 10-14 = B

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1048 | DataTransformFlag | int |
| +0x2c | PaletteArrayPtr | int, base pointer |
| +0x1058 | VertexCount | int |

**Globals:**
- `_DAT_0059eed0` — brightness multiplier for R/B channels
- `_DAT_005accd8` — brightness multiplier for G channel

**Calls:** FUN_00506ce2 (memory/address translation), FUN_00507473 (state update)

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054a770 — Scene Graph / Object Tree Cleanup

Source: Unknown. Traverses linked lists of scene objects and destroys/releases resources.

**Key logic:**
- Walks linked list at +0x204 (stride +0x10 = next pointer), for each node: calls FUN_0054c410 (dirty state), FUN_0054ac30 (release), FUN_00587bcf (free)
- If +0x1ec non-null, calls FUN_00561940 (audio resource cleanup)
- If +0x1e0 non-null, calls FUN_0054fa50 (render resource cleanup)
- Walks linked list at +0x224 (stride +4 = next), frees each node with FUN_00587bcf, zeros +0x224
- Walks array/list at +0x22c, iterates count times calling FUN_004b0170 (release), then frees base with FUN_00587bcf, zeros +0x22c
- Returns 0

**Calls:** FUN_0054c410, FUN_0054ac30, FUN_00587bcf (free), FUN_00561940 (audio cleanup), FUN_0054fa50 (renderer cleanup), FUN_004b0170 (object release)

<!-- target: docs/06-session-race-logic.md -->

## FUN_004ed250 — Repair/Service State Dispatcher

Source: Unknown. Dispatches vehicle repair and service operations based on wheel/part index.

**Key logic:**
- Switch on param_2 (0–0xd):
- Cases 0–3 (wheels): checks ReasonCode at offset +0x4068 of *param_1 → if 0, sets to 6 (puncture/flat). Calls FUN_004e0e70 (wheel repair). Sets param_1[0xf58]=2. If param_1[0xcaf]==0, calls FUN_0043e770 and FUN_0041afd0
- Cases 4–5 (front/rear wing): calls FUN_004e0d70 with wing-specific offset, FUN_004a56b0(1). Sets +0xf58 if 0. Copies +0xea0 to +0xe9c. Calls FUN_004e8010 with 0. Calls FUN_0041afd0
- Cases 6–0xd (additional parts): calls FUN_004e0d70 with stride 0x11

**Calls:** FUN_004e0e70 (wheel repair), FUN_0043e770 (suspension?), FUN_0041afd0 (part repair), FUN_004e0d70 (wing/part service), FUN_004a56b0 (audio), FUN_004e8010 (tire model solver)

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054f710 — Render List Iteration / Hit Test

Source: Unknown. Iterates render list entries, counting type-2 entries and dispatching type-1 via vtable callback.

**Key logic:**
- Reads render list at +0x1e0, gets entry count from list header +4
- For each entry (stride 0x1d): if *entry == 2 → counts it; else calls vtable method through DAT_008b8f24 with entry offsets+1 and +4 (position data) and param_1+0x114 (output buffer)
- Second call with offsets +7 and +10 for same entry
- Returns count of type-2 entries

**Globals:**
- `DAT_008b8f24` — renderer/manager vtable pointer

**Calls:** (via DAT_008b8f24) render callback dispatcher

<!-- target: docs/06-session-race-logic.md -->

## FUN_004a0c60 — Session/Menu Mode Switch

Source: Unknown. Determines session type and sets up menu state.

**Key logic:**
- Calls FUN_00404f00 (keyboard/menu check)
- If non-zero → sets DAT_007c569c = 6 (SessionType5), calls FUN_00404f30 (menu handler), returns 0
- If DAT_007ce814 == 0 → calls FUN_00408420(0x3f000000 = 0.5f) and FUN_004a0d10 (menu/UI init)

**Globals:**
- `DAT_007c569c` — SessionType5 (5=server, 6=menu)
- `DAT_007ce814` — menu already initialized flag

**Calls:** FUN_00404f00 (input check), FUN_00404f30 (menu handler), FUN_00408420 (fade/transition), FUN_004a0d10 (menu initialization)

<!-- target: docs/06-session-race-logic.md -->

## FUN_004d1d40 — Indexed Float Array Lookup (Clamped)

Source: Unknown. Converts float to int index, clamped to array bounds, reads 8-byte entry.

**Key logic:**
- Converts float to int via __ftol()
- Lower bound clamp to 0; upper bound clamp to (*(param_1+0x10c)-1)
- Returns 4-byte value from array at +0x110, offset = clamped_index × 8

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x10c | ArrayLength | int |
| +0x110 | ArrayPtr | int*, stride 8 per entry |

<!-- target: docs/06-session-race-logic.md -->

## FUN_004a5e60 — State/Phase Setter

Source: Unknown. Sets state and triggers action if active.

**Key logic:**
- Sets *(param_1+0x184) = 4, *(param_1+0x180) = 1
- If *(param_1+0x14) != 0 → calls FUN_004a3fe0 (sub-action handler)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x180 | StateFlag | byte, set to 1 |
| +0x184 | StateValue | int, set to 4 |
| +0x14 | ActiveFlag | int, non-zero triggers action |

**Calls:** FUN_004a3fe0 (sub-action handler)

<!-- target: docs/06-session-race-logic.md -->

## FUN_0052e320 — Deferred Deactivation

Source: Unknown. Resets state and triggers cleanup when active flag is set.

**Key logic:**
- Checks byte at +0x24ec: if non-zero → zeros +0x24f0 and +0x24ec, calls FUN_0047abb0 (deactivation), FUN_004b0170 (release)
- Returns 0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x24ec | ActiveFlag | byte |
| +0x24f0 | StateData | int, cleared to 0 |

**Calls:** FUN_0047abb0 (deactivation handler), FUN_004b0170 (object release)

<!-- target: docs/06-session-race-logic.md -->

## FUN_004a0e70 — Session Type Guard

Source: Unknown. Conditional execution guard based on session type.

**Key logic:**
- If DAT_007cd8c0 != 0 AND (SessionType5 == 2 OR 6 OR DAT_007ce254 != 0) → calls FUN_004989e0(param_1), returns 1
- Otherwise returns 0

**Globals:**
- `DAT_007cd8c0` — session active flag
- `DAT_007c569c` — SessionType5 (2=race, 6=menu)
- `DAT_007ce254` — additional session flag

**Calls:** FUN_004989e0 (conditional action)

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c0b10 — Pit Stop Memory Cleanup

Source: Unknown. Frees pit stop related memory allocations.

**Key logic:**
- If pointer at +0xb128 non-null → calls FUN_00587bcf (free)
- If pointer at +0xb120 non-null → calls FUN_00587bcf (free)
- Calls FUN_0049a270 once, then 0x67 times in a loop (104 iterations)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xb120 | PitAllocA | void*, freed |
| +0xb128 | PitAllocB | void*, freed |

**Calls:** FUN_00587bcf (free/delete), FUN_0049a270 (memory pool release)

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b69f0 — Coordinate Bound Check

Source: Unknown. Returns 0 if both coordinates are non-negative, 1 otherwise.

**Key logic:**
- Checks ints at +0x9b8 and +0x9bc
- If both >= 0 → returns 0
- Else returns 1

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x9b8 | CoordX | int |
| +0x9bc | CoordY | int |

<!-- target: docs/06-session-race-logic.md -->

## FUN_00545090 — Doubly-Linked List Node Removal

Source: Unknown. Removes a node from a doubly-linked list.

**Key logic:**
- If node (param_2) has next (+0x1b8) → sets next.prev = node.prev
- If node has prev (+0x1b4) → sets prev.next = node.next
- If node is list head (param_1+0xf8) → sets head = node.next

**Struct offsets (param_1 — list):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xf8 | ListHead | int, pointer to first node |

**Struct offsets (param_2 — node):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1b4 | Prev | int, pointer to previous node |
| +0x1b8 | Next | int, pointer to next node |

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b8790 — Float Getter

Source: Unknown. Returns float from offset +0xf38.

**Key logic:**
- Returns *(float *)(param_1 + 0xf38) as 80-bit float (float10)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xf38 | Value | float |

<!-- target: docs/06-session-race-logic.md -->

## FUN_00545f40 — Value Getter

Source: Unknown. Returns int from offset +0x110.

**Key logic:**
- Returns *(int *)(param_1 + 0x110)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x110 | Value | int |

<!-- target: docs/17-physics-collision.md -->

## FUN_0042e400 — PenaltyStructInit

Source: Unknown. Initializes penalty-related struct fields with default values.

**Key logic:**
- Sets double at +0x1cbc to 0x4392947b (~295.0f, speed threshold?)
- Sets byte at +0x1cb8 to 1 (enabled flag)
- Loop 4 iterations (wheels/corners):
  - Sets each +0x1cd8 slot to 0x4392947b (threshold)
  - Sets each +0x1cd4 byte to 1
  - Sets 3 consecutive floats at +0x1cec offset to 0x43b3ee14 (~359.0f, timer/angle?)
- Clears +0x1cd8 value to 0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1cbc | SpeedThreshold | float 295.0, penalty trigger speed |
| +0x1cb8 | Flag | byte, enabled flag |
| +0x1cd4 | CornerFlags[4] | byte per corner |
| +0x1cd8 | CornerThresholds[4] | float per corner |
| +0x1cec | CornerTimers[4][3] | 3 floats per corner, ~359.0 |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042ae20 — AIDriverRandomSelector

Source: Unknown. Manages AI driver random selection or pit assignment.

**Key logic:**
- Compares param_2 against struct field at +0x45fc
- If match: resets +0x45fc to 0, calls FUN_0042ad00(100) for random value
- Stores random result at +0x4420
- Compares param_2 against struct field at +0x45f8
- If match: clears +0x45f8 to 0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x45fc | CurrentSelection | int, drivers count/depth |
| +0x45f8 | LastSelection | int |
| +0x4420 | RandomResult | int |

**Calls:** FUN_0042ad00(100) (random number generator, range 0-100)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042dd80 — WeightedDataLookup

Source: Unknown. Looks up weighted value from indexed data array.

**Key logic:**
- Bounds check: param_2 >= 0 AND param_2 < param_1[0x8]
- Array at *(param_1+0xc), indexed by param_2, stride 8 bytes
- If numerator > 0 AND denominator > 0:
  - Returns (array_entry[+4] * param_1[0x14]) / (param_1[0x10] * array_entry[0])
- Otherwise returns _DAT_0059e430 (zero constant)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x8 | Count | int, number of entries |
| +0xc | ArrayPtr | pointer to data array |
| +0x10 | DenominatorMult | int multiplier |
| +0x14 | NumeratorMult | int multiplier |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c79e0 — VehicleDriverInfoClear

Source: Unknown. Clears vehicle driver info and identification fields to defaults.

**Key logic:**
- Zeros string fields: +0x4620 (DriverName), +0x4660, +0x4678 (VehicleDescription), +0x46b8, +0x46f8, +0x4708, +0x4714, +0x4794
- Sets +0x4710, +0x4898, +0x489c (DriverNumber), +0x48a0, +0x48a4, +0x48a8 to -1 (0xffffffff)
- Sets +0x48ac to 0, +0x48b0 (short) to 0
- Sets +0x48b4 to 0xff7fffff (-FLT_MAX, best lap time reset)
- Sets +0x48b8 to 0, +0x48bc to 0xb (11, finish state?)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4620 | DriverName | char string |
| +0x4678 | VehicleDescription | char string |
| +0x4898 | UnknownID1 | int, -1 = unset |
| +0x489c | DriverNumber | int, -1 = unset |
| +0x48a0 | UnknownID2 | int, -1 = unset |
| +0x48a4 | UnknownID3 | int, -1 = unset |
| +0x48a8 | UnknownID4 | int, -1 = unset |
| +0x48ac | UnknownFlag | int, 0 |
| +0x48b0 | UnknownShort | short, 0 |
| +0x48b4 | BestLapTimeReset | float, -FLT_MAX |
| +0x48b8 | UnknownTime | int, 0 |
| +0x48bc | FinishState | int, 0xb default |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042e470 — EventTriggerOnStateChange

Source: Unknown. Detects state change between two objects and triggers event.

**Key logic:**
- Compares +0x10 fields of param_2 and param_3 (type/state ID)
- If equal AND +0x14 fields differ (state value changed):
  - Copies +0x14 from param_2 to param_3 (state sync)
  - Sets param_1[0x19a4] = 1 (event flag)
  - Sets *param_1 = 1 (trigger flag)

**Struct offsets:**
| param | Offset | Field | Notes |
|-------|--------|-------|-------|
| param_2 | +0x10 | StateType | int |
| param_2 | +0x14 | StateValue | int |
| param_3 | +0x10 | StateType | int, must match param_2 |
| param_3 | +0x14 | StateValue | int, must differ |
| param_1 | +0x19a4 | EventFlag | byte |
| param_1 | +0x0 | TriggerFlag | byte |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e9630 — PositionChangeMonitor

Source: Unknown. Monitors position change and updates on threshold exceed.

**Key logic:**
- Computes squared distance: (current position at +0x3aa0 - target at +0x34d4)² + (y)² + (z)²
- If distance² > _DAT_0059e9e0 threshold OR current ID is 0:
  - Calls FUN_00403640 to update object
  - Stores new position from +0x34d4 to +0x3aa0
- Returns ID at +0x3a9c

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x34d4 | TargetPosX | float, reference position |
| +0x34d8 | TargetPosY | float |
| +0x34dc | TargetPosZ | float |
| +0x3a9c | CurrentID | int, object/waypoint ID |
| +0x3aa0 | CurrentPosX | float, cached position |
| +0x3aa4 | CurrentPosY | float |
| +0x3aa8 | CurrentPosZ | float |

**Globals:**
- `_DAT_0059e9e0` — distance threshold

**Calls:** FUN_00403640 (object/ID update)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_005169ac — ComplexStateValidator

Source: Unknown. Validates many nested struct conditions, returns 1 if all pass or in_EAX & 0xffffff00 if any fail.

**Key logic:**
- Nested condition checks on param_2 struct and sub-struct at param_2+0xc4:
  - param_2+0x48 must be 0 (byte)
  - param_2+0x108 must be 0 (byte)
  - param_2+0x24 must be 3 (int)
  - param_2+0x20 must be 3 (int)
  - param_2+0x28 must be 2 (int)
  - param_2+100 must be 3 (int)
  - iVar1 = *(param_2+0xc4), then checks:
    - iVar1+8 must be 2
    - iVar1+0x5c must be 1
    - iVar1+0xb0 must be 1
    - iVar1+0xc must be <= 2
    - iVar1+0x60 must be 1
    - iVar1+0xb4 must be 1
    - iVar1+0x24 must equal param_2+0x114
    - iVar1+0x78 must equal param_2+0x114
    - iVar1+0xcc must equal param_2+0x114
- If any condition fails: returns in_EAX & 0xffffff00 (clears low byte)

**Struct offsets (param_2):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x48 | FlagA | byte, must be 0 |
| +0x108 | FlagB | byte, must be 0 |
| +0x20 | ModeA | int, must be 3 |
| +0x24 | ModeB | int, must be 3 |
| +0x28 | ModeC | int, must be 2 |
| +0x64 | ModeD | int, must be 3 |
| +0xc4 | SubStructPtr | pointer to sub-struct |
| +0x114 | MatchID | int, used for cross-checks |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e8b80 — AerodynamicForceCalc

Source: Unknown. Computes aerodynamic force with table lookup and interpolation.

**Key logic:**
- Input param_2 (speed²) used in formula:
  - fVar3 = speed² * +0x3a70 - (speed² * DAT_0059e440 - _DAT_005aceb8) * +0x3514) * +0x3bfc
- Calls FUN_005895a2 for sqrt/function evaluation
- Table lookup at +0x3c00[0..13], clamped to 0xd max
- Linear interpolation between table entries
- Result multiplied by +0x3518 (scale factor)
- Clamped to +0x3d3c (max value)
- Adds linear term: +0x3d44 * +0x3518 * speed²
- If below DAT_0059e440 (zero): returns 0 or param_2 depending on _DAT_0059e43c threshold
- Final computation with SQRT and velocity-dependent terms

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x3a70 | DragCoeffA | float |
| +0x3514 | LiftCoeff | float |
| +0x3bfc | AreaCoeff | float |
| +0x3c00 | TableBase[14] | float array, 14 entries |
| +0x3518 | ScaleFactor | float |
| +0x3d3c | MaxForce | float, clamp upper |
| +0x3d44 | LinearDragCoeff | float |

**Globals:**
- `DAT_0059e440` — zero constant
- `_DAT_005aceb8` — aero constant
- `_DAT_0059e99c` — conversion factor
- `_DAT_0059e46c` — another constant
- `_DAT_0059e43c` — threshold

**Calls:** FUN_005895a2 (evaluate function, sqrt?)

**Moddability:** configurable — table values determine aero curve

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e24a0 — SuspensionParamUpdate

Source: Unknown. Updates suspension parameters at wheel index.

**Key logic:**
- param_2 is wheel index, multiplied by 0x128 (296 byte stride)
- Computes displacement: param_3 - param_1[+0x4c]
- Stores displacement at +0x14c and +400 offsets
- Adds +0x1cc value to param_5
- Stores param_4 at +0xd4+0xfc offset
- If param_5 != stored value at +200: updates it and calls FUN_005670d0
- Copies 9 dwords from +0xd0 to +0x8c (shift buffer)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4c | RestHeight | float, rest position |
| +0xd4 | SuspArray[4] | per-wheel suspension struct, stride 0x128 |
| +0x1cc | SpringBias | float |
| +0x200 | PrevForce | float |
| +0xcc | WheelID | int |

**Calls:** FUN_005670d0 (force/param update), FUN_00567340 (buffer copy)

**Moddability:** configurable — suspension travel and spring bias from .svm

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e2230 — VibrationStateMachine

Source: Unknown. Three-state vibration/force feedback controller based on threshold.

**Key logic:**
- param_2 * 0x128 stride + 0xd4 offset (per-wheel struct)
- If ABS(param_3) < _DAT_0059e708 (small threshold):
  - State 0: if not already 0, clear +0x118 flag, call FUN_005506a0(0,0,0), iterate DAT_008ad3ec array
- Else if ABS(param_3) < _DAT_0059eed0 (medium threshold):
  - State 1: if not already 1, set +0x118 = 1, call FUN_005506a0(1,0,0), iterate DAT_008ad3ec array
- Else:
  - State 2: if not already 2, set +0x118 = 2, call FUN_005506a0(2,0,0), iterate DAT_008ad3ec array

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| param_1+0xb6c | BaseSoundID | int |
| +0x118 | VibeState | int (0=off, 1=low, 2=high) |

**Globals:**
- `_DAT_0059e708` — low threshold
- `_DAT_0059eed0` — high threshold
- `DAT_008ad3ec` — sound/effect array

**Calls:** FUN_005506a0 (vibration/sound trigger)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c1370 — ActiveEntityCounter

Source: Unknown. Counts non-null entries in strided array.

**Key logic:**
- Iterates 0x67 (103) entries starting at param_1+0x1b0, stride 0x1b4
- Counts non-zero bytes
- Returns count

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1b0 | EntityArray[103] | byte array of active flags, stride 0x1b4 |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0053c5d0 — LinkedListAppend

Source: Unknown. Appends node to singly-linked list with doubly-linked links.

**Key logic:**
- DAT_008b8f28 is list head pointer
- If list non-empty: walks to last node via +0x1e8 (next pointer)
- Appends param_1: sets previous tail's +0x1e8 = param_1
- Sets param_1+0x1e4 = previous tail (prev pointer)
- Sets param_1+0x1e8 = 0 (null terminator)
- If list empty: sets head = param_1, zeroes both links

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1e4 | PrevPtr | pointer to previous node |
| +0x1e8 | NextPtr | pointer to next node |

**Globals:**
- `DAT_008b8f28` — list head pointer

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b86e0 — AngleClampWrap

Source: Unknown. Clamps or wraps angular/steering value between bounds.

**Key logic:**
- Stores previous value: +0xf3c = old +0xf38
- Sets +0xf38 = param_2 (new value)
- If +0xf81 != 0 (clamp mode):
  - Clamps param_2 between +0xf30 (min) and +0xf34 (max)
- Else (wrap mode):
  - Infinite loop: reflects value when exceeding bounds
  - If param_2 > max: param_2 -= (max - min)
  - If param_2 < min: param_2 += (max - min)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xf30 | MinValue | float |
| +0xf34 | MaxValue | float |
| +0xf38 | CurrentValue | float |
| +0xf3c | PreviousValue | float |
| +0xf81 | Mode | byte, 0=wrap, non-0=clamp |

**Moddability:** configurable — min/max from setup, mode from .hdv?

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f0dd0 — SteeringForceWithRandom

Source: Unknown. Computes steering/control force with speed-dependent term and random noise.

**Key logic:**
- Uses DAT_007c56ac (unknown flag) and DAT_008ab6e4 (ScoringGate == 2) to set allow flag
- Reads +0x1058 from *param_1 (base velocity/speed)
- Computes angular velocity magnitude from param_1[0xd3b..0xd3d] for aerodynamic/downforce term
- If allow flag set: downforceTerm = |ω|² * constants (_DAT_0059f128 * _DAT_005acd3c)
- If not: downforceTerm = 0
- Random sign (_rand() & 1): adds ±_DAT_0059e670 / ±_DAT_0059e43c perturbation
- Interpolation: newValue = lerp(oldValue, downforceTerm + velocityTerm, coeff)
- Clamp: if < _DAT_005ad22c → -0.3, if > _DAT_0059e8b4 → 0.3
- Calls FUN_004e0c90(result)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| [0xd3b] | AngularVelX | float |
| [0xd3c] | AngularVelY | float |
| [0xd3d] | AngularVelZ | float |
| [0xd50] | BaseSpeed | float |
| *param_1+0x1058 | ReferenceValue | float |

**Globals:**
- `DAT_007c56ac` — enable flag (byte)
- `DAT_008ab6e4` — ScoringGate (int, 2 = allow)
- `_DAT_0059f128` — aero constant
- `_DAT_005acd3c` — aero constant
- `_DAT_0059e99c` — conversion factor
- `_DAT_008afe98` — interpolation coefficient
- `_DAT_0059e670` — random high value
- `_DAT_0059e43c` — random low value
- `_DAT_0059e8b4` — clamp upper threshold
- `_DAT_005ad22c` — clamp lower threshold

**Calls:** _rand(), FUN_004e0c90 (apply steering force)

**Moddability:** configurable — interpolation coefficient and clamp values

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c6d90 — SceneRenderUpdate

Source: Unknown. Orchestrates scene/render update sequence.

**Key logic:**
- Calls FUN_004e0800, FUN_004e45b0, FUN_00410b60(param_1+0xc)
- If param_2 != 0: calls FUN_004bb810, FUN_004d1180, FUN_004ef7c0
- Calls FUN_004d10e0, FUN_004d1100, FUN_004d1140 for rendering
- Sets param_1+0x48b4 = 0xff7fffff (-FLT_MAX, reset best time)
- Calls FUN_004c6b60(1), FUN_004d1670()
- If _DAT_005ea408 > 0: calls FUN_004e4910()

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xc | ScenePtr | pointer |
| +0x48b4 | BestLapReset | float, -FLT_MAX |

**Globals:**
- `_DAT_005ea408` — threshold

**Calls:** Multiple render/scene functions

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b68c0 — CircularBufferCheck

Source: Unknown. Checks circular buffer state and returns item count or validity.

**Key logic:**
- param_1+0x9b8 (head), +0x9bc (tail), +0x9b4 (capacity)
- If tail < head: count = (capacity - tail) + 1 + head (wrapped)
- If tail >= head:
  - calls FUN_004b69f0() for validation, returns 0 if fails
  - count = (head - tail) + 1 (linear)
- If count == 1: checks byte at [tail * 0xb0 + param_1+0x9b0] for active flag
- Returns 0 (inactive), 1 (active), or count

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x9b0 | DataArrayBase | int, base pointer |
| +0x9b4 | Capacity | int |
| +0x9b8 | Head | int |
| +0x9bc | Tail | int |

**Calls:** FUN_004b69f0 (validation check)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e3a50 — MultiObjectRemove

Source: Unknown. Removes multiple objects via repeated call.

**Key logic:**
- Loops from 0 to param_1+0xba8 (count)
- Calls FUN_004df110(param_2, 0xffffffff) each iteration

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xba8 | ObjectCount | int |

**Calls:** FUN_004df110 (object removal)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004a5e80 — ObjectStateClear

Source: Unknown. Clears state flag and optionally calls cleanup.

**Key logic:**
- Sets param_1+0x184 = 0
- Sets param_1+0x180 = 0 (byte)
- If param_1+0x14 != 0: calls FUN_004a3fe0()

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x180 | FlagA | byte |
| +0x184 | FlagB | int |
| +0x14 | Ptr | pointer, triggers cleanup if non-null |

**Calls:** FUN_004a3fe0 (cleanup/reset)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00540cb0 — AudioResourceFree

Source: Unknown. Frees audio/sound resources conditionally.

**Key logic:**
- If param_1+0x13dc != 0 (shared resource mode):
  - Frees param_2+0x1c via FUN_00587bcf if non-null
  - Clears +0x1c and +0x2c
  - Frees param_2+0x24 via FUN_00587bcf if non-null
  - Clears +0x24 and +0x30
  - Returns 0
- If param_1+0x13dc == 0 (owned resource mode):
  - Calls FUN_00540eb0(param_2+0x1c)
  - Frees +0x1c via FUN_00587bcf if non-null
  - Calls FUN_00541040(param_2+0x24)
  - Frees +0x24 via FUN_00587bcf if non-null
  - Returns 0

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| param_1+0x13dc | SharedFlag | int, 0=owned, non-0=shared |
| param_2+0x1c | ResourceA | pointer |
| param_2+0x2c | SizeA | int |
| param_2+0x24 | ResourceB | pointer |
| param_2+0x30 | SizeB | int |

**Calls:** FUN_00587bcf (free/delete), FUN_00540eb0 (process resource A), FUN_00541040 (process resource B)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004a56b0 — StateTransition

Source: Unknown. Two-state transition based on boolean input.

**Key logic:**
- If param_2 == 0:
  - Sets state (+0x128) = 1
  - Sets flagA (+300) = 0
  - Sets flagB (+0x130) = 0
- Else if state != 2:
  - Sets state = 2
  - Sets flagA = 1
  - Sets flagB = 1

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x128 | State | int, 1 or 2 |
| +0x12c | FlagA | int |
| +0x130 | FlagB | int |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e9600 — SuspensionStateUpdate

Source: Unknown. Updates suspension state for a wheel.

**Key logic:**
- Calls FUN_004e23d0 with three offsets: +0x34d4 (position), +0x34e0 (velocity), +0x34b0 (force)
- Calls FUN_004e16c0()

**Calls:** FUN_004e23d0 (state update), FUN_004e16c0()

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004d1140 — RenderCallWithGuard

Source: Unknown. Conditional render call with guard.

**Key logic:**
- If param_1+0x48a4 < 0: calls FUN_004c6f10() (recovery/init)
- Calls FUN_00403fc0(param_1+0x48a4, param_1+0x48a8, param_2, param_3)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x48a4 | ResourceID | int, -1 = uninitialized |
| +0x48a8 | ResourceSubID | int |

**Calls:** FUN_004c6f10 (resource init), FUN_00403fc0 (render/draw)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_005452b0 — LinkedListRemove

Source: Unknown. Removes node from doubly-linked list.

**Key logic:**
- If param_2+0x48 (prev) non-null: prev->0x4c = param_2+0x4c (skip forward)
- If param_2+0x4c (next) non-null: next->0x48 = param_2+0x48 (skip backward)
- If param_1+0x108 (head) == param_2: updates head to param_2+0x4c

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x108 | ListHead | pointer to head node |

**Struct offsets (param_2):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x48 | Prev | pointer |
| +0x4c | Next | pointer |

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b9820 — WheelForceAccessor

Source: Unknown. Returns dereferenced wheel force value.

**Key logic:**
- Returns *param_1 + 0xf1c content (single value read)

**Moddability:** hardcoded

## FUN_0040d1b0 — Session Phase Dispatch with Cascade Checks

Source: unknown | Confidence: high (game_logic — session flow)
Three-level cascade check (FUN_0040a910 → FUN_0040b450 → FUN_0040bcd0) then dispatches via FUN_0040cdd0 and notifies session via FUN_0040cd60/FUN_0040cde0.

**Key logic:**
- If param_2 != 0:
  - Calls FUN_0040a910(param_2, param_3) — MenuSlotActionDispatch (per docs/06)
  - If returns false: calls FUN_0040b450(param_2, param_3)
  - If returns false: calls FUN_0040bcd0(param_2, param_3)
  - On match at any level: reads value from param_1[0x18/0x1c/0x20] (cascade-specific data)
  - Calls FUN_0040cdd0(value) — dispatch with context
  - Sets param_1[0x2c] = 1 (active flag)
  - Calls FUN_0040cd60(0) — session phase query
  - Calls FUN_0040cde0(result, 0) — game action state transition (per docs/09)
  - If param_3 != 0 AND param_1[8] != 0: calls vtable[0x10] method (callback)
- Returns combined status byte

**Calls:** FUN_0040a910 (MenuSlotActionDispatch, docs/06), FUN_0040b450, FUN_0040bcd0, FUN_0040cdd0, FUN_0040cd60 (session phase, docs/06), FUN_0040cde0 (Game Action State Machine, docs/09)

**Used by system:** docs/06-session-race-logic.md — session action dispatch with cascade

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040f4b0 — Mode Dispatch with Switch (0-6)

Source: unknown | Confidence: high (game_logic)
Dispatches based on state at param_1+0x1c. Cases 0-5 call FUN_0040f0d0 + FUN_004599c0; case 6 calls FUN_004ebc60.

**Key logic:**
- Switch on *(param_1 + 0x1c):
  - cases 0, 3: FUN_0040f0d0 + FUN_004599c0(param_2, param_3)
  - cases 1, 4: FUN_0040f0d0 + FUN_004599c0(param_2, param_3)
  - cases 2, 5: FUN_0040f0d0 + FUN_004599c0(param_2, param_3)
  - case 6: FUN_004ebc60(param_2, 1) — vehicle contact force accumulation (docs/18)
- Cases 0-5: collision contact impulse (FUN_004599c0, docs/17) + physics event (FUN_0040f0d0, docs/18)
- Case 6: direct vehicle force accumulation

**Calls:** FUN_0040f0d0 (physics event, docs/18), FUN_004599c0 (Collision Contact Impulse, docs/17), FUN_004ebc60 (Vehicle Contact Force Accumulation, docs/18)

**Used by system:** docs/06-session-race-logic.md — collision response mode dispatch

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00411740 — Global VTable Dispatch with Query

Source: unknown | Confidence: high (game_logic)
Queries system via FUN_004117b0 using DAT_008ac4c4 global context, dispatches vtable method twice on success.

**Key logic:**
- If DAT_008ac4c4 (global context pointer) != NULL:
  - Sets up 4 local variables: local_10, local_c = -1, local_8, local_4 = 0
  - Calls FUN_004117b0(param_1, &local_10, &local_c, &local_4, &local_8) — query
  - If query returns 0 (success): calls vtable[0x4c/4] method twice on global context
    - (**(code**)(*piVar1 + 0x4c))(local_10) — called twice with same arg

**Globals:**
- `DAT_008ac4c4` — global context/manager pointer

**Calls:** FUN_004117b0 (query/discovery function)

**Used by system:** docs/06-session-race-logic.md — manager dispatch with double notification

**Moddability:** hardcoded

<!-- target: docs/02-ai-system.md -->

## FUN_0041f150 — Season Race Count Check

Source: unknown | Confidence: high (game_logic)
Checks if race count > 0 and a season-specific field < 5.

**Key logic:**
- If param_1 != 0:
  - Calls FUN_004c2850() (season data query) — may set global state
  - Calls FUN_004c11d0() (race count remaining)
  - If count > 0 AND *(param_1 + 0x14 + race_count * 4) < 5: returns 1
- Returns 0 otherwise

**Calls:** FUN_004c2850 (season data), FUN_004c11d0 (remaining races)

**Used by system:** docs/06-session-race-logic.md — season/race status check

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0046a480 — Global Dispatch with Reset

If DAT_005eb10c non-null: calls vtable[0xc] method. Then calls FUN_004186a0, FUN_004c5830(param_3), FUN_004c54f0(0). Zeroes param_1+0x344.
**Globals:** DAT_005eb10c (global context ptr)
**Calls:** FUN_004186a0, FUN_004c5830, FUN_004c54f0

<!-- target: docs/06-session-race-logic.md -->

## FUN_0046d270 — Input Binding Dispatch (Keys 0x27, 0x29)

If DAT_005eb10c non-null: calls vtable[0xc]. Calls FUN_004186a0. Queries vtable[0x1c](0x27) and vtable[0x1c](0x29) — input key bindings. If active: calls FUN_0047c360(1/0). Calls FUN_0041c540(). Returns 0.
**Globals:** DAT_005eb10c (global context ptr)
**Calls:** FUN_004186a0, FUN_0047c360, FUN_0041c540

<!-- target: docs/06-session-race-logic.md -->

## FUN_0046f4d0 — Input Binding Dispatch (Key 0x2c)

Queries vtable[0x1c](0x2c) — input key binding. If active: calls FUN_00489920() and on success FUN_0046f490().
**Calls:** FUN_00489920, FUN_0046f490

<!-- target: docs/06-session-race-logic.md -->

## FUN_004711a0 — UI/Mode Init with Defaults

Calls FUN_00466d60(1). Sets vtable PTR_FUN_005a0b40. Initializes fields: param_1[199]=&DAT_007d0a20, [0xc9]=99, [0xca]=2, [0xcb]=1, [0xcc]=1. Returns param_1.
**Globals:** DAT_007d0a20 (shared data ptr, near other game state)
**Calls:** FUN_00466d60(1)

<!-- target: docs/06-session-race-logic.md -->

## FUN_00472cc0 — UI String Format + Display

Calls FUN_00487010 to get string ID from vtable, formats via FUN_0058815f, dispatches display via FUN_0048b810.
**Calls:** FUN_00487010, FUN_0058815f (format), FUN_0048b810 (UI display)

<!-- target: docs/06-session-race-logic.md -->

## FUN_00474a10 — UI List Init with Default (400)

Calls FUN_0048c070(1). Sets vtable PTR_FUN_005a3e40. Sets param_1[199]=400. Calls FUN_00474ab0(). Returns param_1.

<!-- target: docs/06-session-race-logic.md -->

## FUN_004761c0 — UI Object Init

Calls FUN_0048fc50(). Sets param_1[0x10]=0, [0x11]=0xFFFFFFFF. Sets vtable PTR_FUN_005a4478. Returns param_1.

<!-- target: docs/06-session-race-logic.md -->

## FUN_00478180 — Command Dispatch (0x11)

Queries DAT_007cd8c0+0x1c(0x11) (command dispatch). If result non-zero: stores at param_1+0xe0.
**Globals:** DAT_007cd8c0 (game command dispatch, docs/22)

<!-- target: docs/20-math-utilities.md -->

## FUN_00479ca0 — Command Dispatch (0xe) with Guard

Queries DAT_007cd8c0+0x1c(0xe). If result non-zero: calls FUN_00477280(param_1).
**Globals:** DAT_007cd8c0 (game command dispatch)

<!-- target: docs/06-session-race-logic.md -->

## FUN_0047a640 — Command Dispatch (0x13) with Guard

Queries DAT_007cd8c0+0x1c(0x13). If result: calls FUN_00477280(param_1).
**Globals:** DAT_007cd8c0 (game command dispatch)

<!-- target: docs/06-session-race-logic.md -->

## FUN_0047c7c0 — UI Object Init with Float Constant

Calls FUN_0048d3a0(0, 1.0f). Sets param_1[0x3f]=param_2. Vtable PTR_FUN_005a69b0.

<!-- target: docs/06-session-race-logic.md -->

## FUN_0047fbd0 — Linked List Destroy at +0x444

Walks linked list at param_1+0x444, frees each node's inner data and node itself via FUN_00587bcf. Zeros 4 list fields (+0x444-0x450). Calls FUN_0048ca50(). If param_2 bit 0 set: frees param_1 (scalar deleting destructor).

<!-- target: docs/06-session-race-logic.md -->

## FUN_00485b20 — Scalar Deleting Destructor

If param_1+0x17c non-null: frees. Same for +0x174. Calls FUN_00489440(). If param_2 bit 0 set: frees param_1.

<!-- target: docs/06-session-race-logic.md -->

## FUN_00486660 — State Change Notification

If param_2 != param_1[0x19]: calls vtable[0x2c](1) — notify state change. Sets param_1[0x19]=param_2. Iterates list at param_1[0x24], notifies each via vtable[0x38](param_2).

<!-- target: docs/06-session-race-logic.md -->

## FUN_00487660 — UI Object Init with Byte Params

Calls FUN_00485e30(). Sets vtable PTR_FUN_005aba18. Stores param_2 at +0x38, param_3 at +0xe1.

<!-- target: docs/06-session-race-logic.md -->

## FUN_004888f0 — Byte Field Setter

Writes param_2 to param_1 + 0xec. Simple single-byte setter.

<!-- target: docs/06-session-race-logic.md -->

## FUN_00489cb0 — State Cleanup + Notification

Iterates linked list at param_1[0x24], calls vtable destructor on each node. Zeros fields: [0x24]=0, [0x5a]=-1, [0x25]=0. Calls vtable[0x2c](1) — state change notify.

<!-- target: docs/06-session-race-logic.md -->

## FUN_0048c940 — State Query + Dispatch (Two Paths)

Calls FUN_00486710() (state query). If true: calls vtable[0x40](5), then vtable[0xac](). If false: calls FUN_00486720() — if result==5, calls vtable[0x40](0). Always calls vtable[0xac]().

<!-- target: docs/06-session-race-logic.md -->

## FUN_0048d590 — Input Dispatch (Arrow Up/Down: 0xCB, 0xCD)

Processes short array at param_2. Handles 0xCB (up) and 0xCD (down) — decrements/increments counter. If param_1[0x3c] flag set: uses vtable[0xb4]/[0xa4] dispatch. Otherwise: directly modifies param_1[0x38] and calls FUN_00488970(). Calls vtable[0x2c](1) on change.

<!-- target: docs/06-session-race-logic.md -->

## FUN_0048ea60 — Rectangle Bounds Check

Checks if (param_2, param_3) within rectangle defined by offset+size at param_1+0x14/0xc (width) and param_1+0x18/0x10 (height). Returns combined success flag.

<!-- target: docs/06-session-race-logic.md -->

## FUN_0048fe90 — Scalar Deleting Destructor

Calls FUN_0048feb0(). If param_2 & 1: frees param_1 via FUN_00587bcf. Returns param_1.

<!-- target: docs/17-physics-collision.md -->

## FUN_004970e0 — Field Setter with Guarded Call

Writes param_2 to param_1+0x1918. If param_1[0x30] != 0: calls FUN_004993d0().

<!-- target: docs/06-session-race-logic.md -->

## FUN_00497f90 — String Array Match Search

Copies param_2 to local buffer, strips delimiter at DAT_005cc79c via FUN_00587c20. Iterates array at param_1+0x114 (stride 0x50, count at param_1+0x1514). Compares each entry via FUN_00588410. Returns 1 on match, 0 on miss/null input.

<!-- target: docs/06-session-race-logic.md -->

## FUN_00498eb0 — Linked List Append (Increment Counter)

Increments param_1+0x5c (counter). Reads head from param_2+0x90, sets fields at +0x98/+0x9c. Traverses chain via +0x8c next pointer. Appends param_2 to end. Returns param_2.

<!-- target: docs/06-session-race-logic.md -->

## FUN_00499580 — Linked List Destroy (vtable destructor variant)

Similar to FUN_004819c0 — walks linked list at *param_1. Calls vtable destructor on each node's data if flag at node[3] set. Frees nodes via FUN_00587bcf. Zeros 4 list fields.

<!-- target: docs/06-session-race-logic.md -->

## FUN_00499b80 — Object Field Init with Indirect Lookup

Sets param_1[8]=param_2, zeros [0]/[2]. If param_2 non-null: reads from *(param_2+0xc) offsets +0x1c/+0x20 into param_1[1]/[3]. Otherwise zeros both.

<!-- target: docs/20-math-utilities.md -->

## FUN_0049e9a0 — Audio/Sound Create with Handle

Allocates 0x60-byte object via operator_new, calls FUN_0054fe10 (audio init). Sets bit 0 at +0x44. Calls FUN_00550080 (load resource, 0x804). On failure: cleans up via FUN_00557470 + FUN_00587bcf. Returns handle at param_1+0xc.

<!-- target: docs/20-math-utilities.md -->

## FUN_004a1a60 — Formatted String Copy

Formats via FUN_0058815f(local_20, format, *param_2). Copies result onto end of param_1 string. strcat-like with runtime format.

<!-- target: docs/06-session-race-logic.md -->

## FUN_004a29a0 — Array/Resource Cleanup

Zeros param_1[0..2]. Iterates param_1[3] entries at stride 0x78, zeros each at +100. Calls per-element cleanup via FUN_004a2220. Frees allocation base via FUN_00587bcf. If DAT_008afe88 non-zero and param_1[5] non-null: calls FUN_00545150. Zeros [3]/[4]/[5].

<!-- target: docs/06-session-race-logic.md -->

## FUN_004a55a0 — Conditional Dispatch (Three Guards)

If param_1+0x10 non-null: calls FUN_004a3570(param_3). If +0xc non-null: calls FUN_004a3570(param_3). If +0x14 non-null: calls FUN_004a4050(param_2).

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b04e0 — String Copy + File Check + Dispatch

Copies param_2 to param_1+0x14 (string buffer). Calls FUN_00566810() — file/string read check. If 0: calls FUN_004b01b0(param_2, param_1+0x14). Calls FUN_004b0540(param_3).

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004c29d0 — Delegation Chain

Calls FUN_004c2990(), passes result to FUN_004c29b0(). Season-related (per docs/06 references).

<!-- target: docs/20-math-utilities.md -->

## FUN_004c8900 — Global Dispatch with Guard

If DAT_008ac4c8 non-null: calls vtable[0x1c] method on it. Guarded dispatch.

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c9790 — Vtable Destructor + Null

If param_1+0x20 non-null: calls vtable[0](1) destructor, zeros pointer. Single-object cleanup.

<!-- target: docs/19-renderer.md -->

## FUN_004d0b20 — 3D Distance Check + Accumulate

Calls FUN_0040c870() for camera position. Negates camera x/y/z. Iterates param_1 array (stride 0x84). For active entries (at +0x68 within stride): computes distance from camera via FUN_0054b420. If within _DAT_005acee4 radius: accumulates param_2 into entry+0x80, wraps at +0x7c threshold. Calls FUN_004a2840. Audio/event proximity.

<!-- target: docs/06-session-race-logic.md -->

## FUN_004d48b0 — Countdown Timer with Callback

Checks PTR_FUN_005d43c8 (callback) and param_1+4 (active flag). Decrements param_1+8 counter. When < 1: calls callback, frees param_1+0xc via FUN_00587bcf, zeros +0xc and +4.

<!-- target: docs/06-session-race-logic.md -->

## FUN_004d7aa0 — Debug Log Write

Calls FUN_0058a163 with string from param_1+4 and param_2, then calls FUN_00589ffd (thread-safe file write). Debug/log output.

<!-- target: docs/06-session-race-logic.md -->

## FUN_004d8220 — Race Init with Constants

Calls FUN_004d8720(). Computes float params: param_1+0xe4 = DAT_005d6d60 × _DAT_005acf3c; param_1+0xe8 = DAT_005d6d64 × _DAT_005acf38. Calls FUN_004d8ab0, FUN_004d8cf0(1-5), FUN_004d88d0(), FUN_004d8760(-1,0). Race/Timing init.

<!-- target: docs/20-math-utilities.md -->

## FUN_004ded20 — Dual Array Destructor

Frees two allocated buffers at param_1+0xc and param_1+0x14. Each: calls refcounted destructor (FUN_004dd4c0/FUN_004dd4d0) per element, then frees base alloc via FUN_00587bcf. Zeros all 4 fields.

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004f8f10 — Conditional Init Branch

If *param_1 != 0: sets param_1[1]=param_2. Calls FUN_00556440(). Zeros param_1[3]. If param_2==0: calls FUN_0053d1d0().

<!-- target: docs/10-vehicle-physics.md -->

## FUN_00545f50 — Audio Volume/Load Computation

Switch on DAT_008b8ef8 (mode 1-3). Computes ratio-based volume using DAT_008b8ee8/ef0 or eec/ef4. Scales by _DAT_0059e8ec/e990. If result >= _DAT_0059e7f8 threshold: calls DAT_008b8f00 callback. Mode 3: calls with 100.0f (0x42c80000). Audio load/volume.

<!-- target: docs/06-session-race-logic.md -->

## FUN_005472b0 — Relative String Copy

Copies param_2 string to offset (param_1 - param_2) from itself. Self-overlapping copy (memmove-like). If param_2 non-null: copies char by char using relative addressing.

<!-- target: docs/06-session-race-logic.md -->

## FUN_00548a00 — Linked List Float Search

Searches linked list starting at param_1+0x2c. Compares each node's float at +8 against param_2. Traverses via +0x14 next pointer. Returns matching node pointer or 0.

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054a240 — Destroy + Free

Calls FUN_00548eb0(). If param_1 non-null: calls FUN_00557470() then FUN_00587bcf(param_1). Returns 0.

<!-- target: docs/20-math-utilities.md -->

## FUN_00554be0 — Mode/State Setter Through Vtable

If param_2 != param_1[0x4e8]: stores new value. Calls vtable[200](ptr, 0xe, param_2) — command dispatch with type 0xe. Sets *param_1 = result. Toggle/state setter.

<!-- target: docs/20-math-utilities.md -->

## FUN_004d0c20 — Driver Standing Comparator (Sort)

Source: unknown | Confidence: medium
Compares two drivers by championship status and points for sorting.

**Key logic:**
- Checks DAT_005f073c[] status bytes (3=active) at stride 0x48c0
- Compares points at DAT_005f0774[] stride 0x1230
- Falls back to pointer comparison for tie-breaking
- Returns -1/0/1 for sorting

**Globals:** DAT_005f073c, DAT_005f0774, DAT_005f0738 — championship/driver DB

**Used by system:** docs/06-session-race-logic.md — standings sorting

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040d3c0 — Short Computation / Session Phase Transition

Source: steward/session | Confidence: high
Handles special session phase transitions (7-10) when global session flag is active.

**Key logic:**
- If DAT_007d0350 != 0 (session active flag):
  - Gets current phase: FUN_0040cd60() — returns iVar1 (-1..5)
  - If param_2 in range (7..10 = special phases):
    - If iVar1 in range (0..5): stores at param_1+0x10
    - Calls FUN_0040cde0(param_2, 0) — set game action state
    - Sets byte at param_1+0x24 = 1
    - Calls FUN_00408420() — update/notify

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x10 | StoredPhase | int | Saved session phase |
| +0x24 | ActiveFlag | byte | Set to 1 on transition |

**Globals:**
- `DAT_007d0350` — session active flag (near GameState DAT_007d00ec)

**Calls:**
- FUN_0040cd60 — session phase
- FUN_0040cde0 — game action state machine
- FUN_00408420 — update/notify

**Used by system:** docs/06-session-race-logic.md — Session phase transition handler for special phases 7-10.

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0040e770 — Short Computation / Session Update Dispatch

Source: steward/session | Confidence: high
Session update dispatcher with mode switching based on state. Calls subsystem updates and writes output data.

**Key logic:**
- Calls FUN_0054fb40(0) — update/init
- If param_1+0x1c in [0..2]: calls FUN_0040e2b0() — basic update
- Calls FUN_0054b530() — reads 6 values into local vars (color/timing values)
- Switch on param_1+0x1c (mode):
  - Cases 0-5: sets puVar1[0x34] = param_2, calls vtable dispatch at (*puVar1)()
- Writes 6 local values to *(param_1+0x20)+4 through +0x18
- Calls FUN_0040ed10() — post-update
- If param_3 == 0: calls FUN_004be010(param_1) — finalize

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x1c | ModeIndex | int | Switch mode (0-5 valid) |
| +0x20 | OutputStruct | int* | Struct pointer for output data |

**Calls:**
- FUN_0054fb40 — update/init
- FUN_0040e2b0 — basic session update
- FUN_0054b530 — read 6 state values
- FUN_0040ed10 — post-update
- FUN_004be010 — finalize/cleanup

**Used by system:** docs/06-session-race-logic.md — Session tick/update dispatch with mode-dependent virtual call.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004a5750 — Utility Function / Index Increment with Wrap

Source: game logic | Confidence: high
Increments an index with wrap-around based on array bounds. Handles special case for param_2==2.

**Key logic:**
- If param_2 == 2: calls FUN_004a57f0() — special handling
- Computes iVar1 = param_2 * 0x40 + param_1 (base + param_2 * 0x40)
- Increments counter at iVar1 + 0x2c
- If counter > max at iVar1 + 0x28:
  - If flag at iVar1 + 0x35 == 0: wrap to max-1
  - Else: wrap to 0
- If param_2 == 0: calls FUN_004a55e0() — update

**Struct offsets (param_1 — array of 0x40-byte entries indexed by param_2):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x28 | MaxIndex | Maximum allowed index |
| +0x2c | CurrentIndex | Incremented (wraps) |
| +0x35 | WrapFlag | If 0: clamp to max-1; if non-0: wrap to 0 |

**Calls:** FUN_004a57f0, FUN_004a55e0

**Used by system:** docs/06-session-race-logic.md — Menu/option index cycling.

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_004bb7a0 — Short Computation / Race/Timing Struct Init

Source: game logic/timing | Confidence: high
Initializes a race/timing data structure with sentinel values.

**Key logic:**
- Zeros 4 pairs of ints (8 fields) starting at +0x10 (stride 2)
- Zeros fields: [0], [0x23], [0x24], [0x25], [0xc], [0x29]
- Sets sentinels: [1] = -1, [9] = -1, [0xb] = -1
- Sets [10] = 0xbf800000 (-1.0f as float)
- Calls FUN_004bb950() — timing init/cleanup

**Calls:** FUN_004bb950 — race/timing initialization

**Used by system:** docs/06-session-race-logic.md — Race/timing data structure initializer.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d8760 — Unidentified Logic / Race State Transition

Source: race/steward | Confidence: medium
Handles race state transition: checks timing priority, global flag, and conditions before allowing a state change.

**Key logic:**
- Reads iVar1 = param_1[param_2 + 4] — state flag
- If DAT_007cf638 == 0: checks FUN_004d9280(param_2) — authorization check
- If current state != -1: compares priorities via FUN_004d91e0
  - If new priority <= current AND not same param: block transition (bVar2 = false)
- Calls FUN_00404f10() — global block check
- If ALL conditions pass (iVar1 != 0, bVar3 authorized, bVar2 priority ok, no block):
  - If param_3 == 1: sets param_1[0x37]=0, current=param_2, calls FUN_004d7e30()
  - Else: sets param_1[0x37]=DAT_005acf34, current=param_2, calls FUN_004d7e30()
  - Returns 0 (accepted)
- If param_2 == -1: reset current to -1
- Returns 1 (rejected)

**Globals:**
- `DAT_007cf638` — bypass/disable flag for authorization
- `DAT_005acf34` — state constant

**Calls:** FUN_004d9280, FUN_004d91e0 (×2), FUN_00404f10, FUN_004d7e30

**Used by system:** docs/06-session-race-logic.md — Race state machine transition with priority arbitration.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040f130 — State-Dependent Update Dispatch

Source: unknown | Confidence: medium
Dispatches to different code paths based on param_1[7] state, with audio notifications.

**Key logic:**
- Switch on `param_1[7]` (state 0-5):
  - Cases 0/3: no-op before dispatch
  - Cases 1/4: no-op before dispatch  
  - Cases 2/5: no-op before dispatch
  - Default: return immediately
- Calls FUN_00459830(param_1 + 3) — prepare/init
- If `*param_1 == -1` (inactive): calls FUN_004be180 (notification) + FUN_004be010 (update)
- Else: calls FUN_00410af0 (remove array element), FUN_004bdf90 (notification/audio), FUN_004be010 (update)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | int | Active flag (-1 = inactive) |
| +0x0c | int | param_1[3] — data passed to dispatch |
| +0x1c | int | param_1[7] — state selector (0-5) |

**Calls:** FUN_00459830, FUN_00410af0 (remove from array), FUN_004bdf90 (notification/audio), FUN_004be180 (notification/audio), FUN_004be010 (update)

**Used by system:** docs/06-session-race-logic.md — stateful update with audio/notification dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0041efe0 — Count Matching Season Entries

Source: unknown | Confidence: medium
Counts how many season entries have a matching ID field.

**Key logic:**
- Calls FUN_004c2850() — get/validate season data
- If valid: calls FUN_004c11d0() — get race count
- Iterates race entries (array starting at param_1 + 0x18)
- Compares each entry's first field against param_2 (match ID)
- Returns count of matches

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x18 | int | First entry ID field (array start) |

**Calls:** FUN_004c2850 (season data access, docs/06), FUN_004c11d0 (race count, docs/06)

**Used by system:** docs/06-session-race-logic.md — season entry counting

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0046c750 — Array Shift/Remove by Index

Source: unknown | Confidence: high
Removes element at param_2 from an array (0x67 elements), shifts remaining left, sets last to -1.

**Key logic:**
- Selects global array base: DAT_007cd2b8 (0) or DAT_007cd470 (1) based on param_1 flag
- Reads and saves element at index param_2 as return value
- If param_2 < 0x67: shifts elements from param_2+1 to end left by 1, sets last to -1
- Else: directly sets element to -1
- Returns original value

**Globals:**
- `DAT_007cd2b8` — array A (103 elements, qualifying)
- `DAT_007cd470` — array B (103 elements)

**Used by system:** docs/06-session-race-logic.md — ordered array removal (qualifying positions)

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0049fdb0 — Condition-Gated UI Render

Source: unknown | Confidence: medium
Gated UI rendering: checks multiple session states before rendering.

**Key logic:**
- If all conditions true: renders UI via FUN_0049b200 + FUN_004dcdd0 + FUN_004dcd80 + FUN_004dcf20 + FUN_004dcd60

**Globals:** DAT_007ce254, DAT_007ce244, DAT_007ce248, DAT_007ce240, DAT_005d6d64, DAT_005d6d60

**Calls:** FUN_00461db0 (session state), FUN_00461cd0 (state check), FUN_00462380, FUN_004636e0/f0/a0, FUN_0049b200, FUN_004dcdd0/80/20/60

**Used by system:** docs/06-session-race-logic.md — condition-gated UI overlay rendering

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004d9290 — ID/Type Permission Matrix

Source: unknown | Confidence: high
Returns whether a given ID is valid for a given type (1-5). Permission lookup table.

**Key logic:**
- Switch on type (1-5) then on ID (0-0x18)
- Returns 1 for allowed combinations, 0 otherwise
- Type 1: IDs 1,3,6,7,9,10,11,12,20,21,22,23
- Type 2: All IDs 0-0x18 except some
- Types 3-5: All IDs 0-0x18

**Used by system:** docs/06-session-race-logic.md — session/UI permission check

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

