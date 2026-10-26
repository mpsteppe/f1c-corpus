## AIDriverStructInit_00424790 — AI driver struct initialization

**Summary:** Initializes ~50 fields of the AI driver struct to default values. Sets max-speed sentinel at +0x4538 = 1,032,957.0f (0x497C1FF0) and speed multiplier at +0x453C = 1.0f. When `a2` is non-zero (first-time init), allocates message queue buffer (80 bytes), locates own vehicle pointer in global array by name comparison, and computes track spatial index value. Returns scaled AI difficulty value. ON_FRAME_PATH — runs per frame, but most writes are idempotent defaults.

**Struct fields accessed:**

| Offset (dec) | Offset (hex) | Read/Write | Init value (as literal) | Purpose inferred from code |
|---|---|---|---|---|
| this[1] (byte*4) | 0x0004 | Read | — | Used in -this[1]*7.0 computation for +0x4454 |
| this[2] (byte*8) | 0x0008 | Write | dword_5EA2D0 + *(*this + 18596) | Spatial tree search center pointer |
| *this + 18596 | *(DWORD*)this + 0x48A4 | Read | — | Track data index (passed to ArrayOfStructIndexedFieldCopy) |
| +17424 (byte) | 0x4410 | Write | 0 | AI flag byte cleared |
| +16704 (byte) | 0x4140 | Write | 0 | AI flag byte cleared |
| 4383 = +17532 | 0x447C | Write | 0 | Float field zeroed |
| 4418 = +17672 | 0x4508 | Write | 0 | Flag/integer zeroed |
| 4419 = +17676 | 0x450C | Write | 0 | Flag/integer zeroed |
| 4360 = +17440 | 0x4420 | Write | 0 | Flag/integer zeroed |
| 4188 = +16752 | 0x4170 | Write | 2139095039 = 0x7F7FFFFF = FLT_MAX | AI pit trigger sentinel |
| 4202 = +16808 | 0x41A8 | Write | 1232348144 ≈ 1,032,957.0f | AI loop threshold field (stride 0x44) |
| 4275 = +17100 | 0x42CC | Write | 0 | AI loop flag (stride 0x1C) |
| 4205 = +16820 | 0x41B4 | Write | -1 | AI loop sentinel (stride 0x44) |
| 4189 = +16756 | 0x4174 | Write | 0 | AI loop flag (stride 0x44) |
| 4278 = +17112 | 0x42D8 | Write | -998653952 = 0xC47A0000 = -1000.0f | AI loop initial (stride 0x1C) |
| 4274 = +17096 | 0x42C8 | Write | -1 | AI loop sentinel (stride 0x1C) |
| 4276 = +17104 | 0x42D0 | Write | -1 | AI loop sentinel (stride 0x1C) |
| +17784 (byte) | 0x4578 | Write | 1 | AI flag byte enabled |
| 4364 = +17456 | 0x4430 | Write | 0 | Flag/integer zeroed |
| 4425 = +17700 | 0x4524 | Write | 0 | Flag/integer zeroed |
| 4376 = +17504 | 0x4460 | Write | -1082130432 = 0xBF800000 = -1.0f | Float initialized to -1.0 |
| 4377 = +17508 | 0x4464 | Write | 1065353216 = 0x3F800000 = 1.0f | Float initialized to 1.0 |
| 4371 = +17484 | 0x444C | Write, Read | 0 | AI ring buffer state (re-cleared if a2 non-zero) |
| 4397 = +17588 | 0x44B4 | Write | this[3675] = +0x396C | Copy from base speed field |
| 4431 = +17724 | 0x453C | Write | 1065353216 = 1.0f | **Speed multiplier** (known struct: AI speed multiplier) |
| 4437 = +17748 | 0x4554 | Write | 1065353216 = 1.0f | Float initialized to 1.0 |
| 4414 = +17656 | 0x4498 | Write | 1065353216 = 1.0f | Float initialized to 1.0 |
| 4403 = +17612 | 0x44CC | Write | 1065353216 = 1.0f | Float initialized to 1.0 |
| 4373 = +17492 | 0x4454 | Write | -this[1] * 7.0 | Offset from starting position * 7 |
| 4479 = +17916 | 0x45FC | Write | 0 | AI processing gate |
| 4363 = +17452 | 0x442C | Write | 0 | Steering computed value init |
| 4385 = +17540 | 0x4484 | Write | 1232348144 ≈ 1,032,957.0f | AI threshold (max sentinel) |
| 4430 = +17720 | 0x4538 | Write | 1232348144 ≈ 1,032,957.0f | **Max-speed sentinel** (known struct) |
| 4432 = +17728 | 0x4540 | Write | 1086324736 = 0x40B9999A ≈ 5.8f | Float initialized to ~5.8 |
| 4433 = +17732 | 0x4544 | Write | 1 | Integer flag |
| +17736 (byte) | 0x4548 | Write | 0 | Byte flag |
| 4439 = +17756 | 0x455C | Write | 0 | Float/integer zeroed |
| 4435 = +17740 | 0x454C | Write | 0 | Float/integer zeroed |
| 4436 = +17744 | 0x4550 | Write | 0 | Float/integer zeroed |
| 4420 = +17680 | 0x4510 | Write | 0 | AI state machine init (0 = racing default) |
| 4438 = +17752 | 0x4558 | Write | 50 | AI speed threshold |
| 4440 = +17760 | 0x4560 | Write | 0 | AI speed timer |
| 4441 = +17764 | 0x4564 | Write | 0 | AI speed target |
| 4367 = +17468 | 0x443C | Write | 0 | Flag zeroed |
| 4353 = +17412 | 0x4404 | Write | -1082130432 = -1.0f | AI ability threshold init |
| 4374 = +17496 | 0x4458 | Write | -1 | AI sentinel |
| 4396 = +17584 | 0x44B0 | Write | -1 | AI sentinel |
| 4379 = +17516 | 0x446C | Write | 0 | Flag zeroed |
| 4350 = +17400 | 0x43F8 | Write | 0 | Flag zeroed |
| +17908 (byte) | 0x45F4 | Write | 0 | AI active flag byte |
| 4487 = +17948 | 0x461C | Write | 1232348144 ≈ 1,032,957.0f | AI proximity distance sentinel |
| 4429 = +17716 | 0x4534 | Write | 0 (if a2 non-zero) | Pit timer gate |
| 4177 to 4185 | 0x4144 to 0x4154 | Write | -1 (stride 8, 5 iter, if a2) | AI pit scheduling array init |
| 4394 = +17576 | 0x44A8 | Read, Write | malloc(80) (if a2) | AI message queue buffer pointer |
| 4395 = +17580 | 0x44AC | Write | 10 (if a2) | AI message queue size |
| 4478 = +17912 | 0x45F8 | Write | matching VehiclePtr (if a2) | Self-pointer in global vehicle array |
| 4352 = +17408 | 0x4400 | Write | SpatialTreeNearestNeighbor result (if a2) | Track spatial tree index |
| 4480 to 4492 | 0x4600 to 0x4618 | Write | GuardedCallWithCheck(i) | 7 guard values initialized |
| 4175 = +16700 | 0x413C | Write | 2139095039 = FLT_MAX | AI timer sentinel |

**Guard conditions:**

| Field | Checked values | What PASSES | What is BLOCKED |
|---|---|---|---|
| a2 (LOBYTE) | 0 vs non-zero | non-zero → full init (msg queue, track search, spatial index) | zero → skip conditional block |
| this[4394] | 0 vs non-zero | (after malloc check) non-zero → FreeWrapper call | zero → skip free |
| dword_5C329C | >0 | enters vehicle-matching loop | ≤0 → skip loop |
| strcmp(this->name, other->name) | match and not self | this[4478] = other vehicle ptr | no match → skip |

**Written-by note:** Writes ~50 fields. All written unconditionally (defaults) or conditionally on a2 (first-time init). The key sentinels at +0x4538 (max speed) and +0x453C (speed multiplier) are always set to defaults. ON_FRAME_PATH → any external poke to these fields is overwritten next frame. However, since most values are idempotent defaults, a poke that changes a conditional field (like +0x4534 which needs a2=0 branch) could survive until a2 becomes non-zero again.

**Globals referenced:**

| Address | IDA name | Read/Write | Role |
|---|---|---|---|
| 0x007C56A4 | dword_7C56A4 | Read | SessionType (compared vs 3,4,5 for difficulty scaling) |
| 0x005C329C | dword_5C329C | Read | VehicleCount |
| 0x007C54F0 | dword_7C54F0 | Read | Vehicle pointer array |
| 0x005EA2D0 | dword_5EA2D0 | Read | Track data base |
| 0x005EA2C0 | dword_5EA2C0 | Read | Track data structure |
| 0x005EA3E8 | flt_5EA3E8 | Read | Difficulty multiplier |
| 0x008AFEA0 | dbl_8AFEA0 | Read | Master game time (usage via ProgressBarEventEncode in caller) |

**Functions called:**

| Address | IDA name | Inferred purpose |
|---|---|---|
| 0x004264B0 | AIClearStateFlags | Clear all AI state flags |
| 0x00424080 | sub_424080 | AI pit scheduling init |
| 0x007B7BCF | FreeWrapper_7bcf | Free allocated memory |
| 0x0042B590 | OperatorNewNhMallocWrapper | Heap allocation (80 bytes) |
| 0x00424240 | AICommandMessageQueueDispatcher | Message queue setup |
| 0x00429680 | ArrayOfStructIndexedFieldCopy | Copy track data into local arrays |
| 0x0041D3D0 | SpatialTreeNearestNeighborSearch | Find nearest track node |
| 0x00429960 | sub_429960 | AI path init |
| 0x0042B3E0 | GuardedCallWithCheck | Guarded function call (7 iterations) |
| 0x00429CD0 | AIDifficultyInterpolation | Compute AI difficulty scalar |
| 0x0043EB50 | ScaleAudioPitch | Scale and return audio pitch |

**Call frequency:** per-frame tick (ON_FRAME_PATH, via SceneRenderUpdate → MainGameTickUpdate). Despite being "init" logic, runs every frame; most writes are idempotent defaults.
