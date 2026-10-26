# Implementation Spec: Audio Network Internals

Source: docs/21-audio-network-internals.md  |  Functions: ~181  |  Date: 2026-07-15

---

## Overview

This spec covers two mostly independent low-level subsystems: the **audio engine** (built on Miles Sound System / Bink SDK) and the **network transport layer** (built on Winsock 2.2). Both share a common infrastructure of thread-pool, mutex, and critical-section primitives used for background loading, streaming, and async I/O.

**Audio subsystem:** Runs across multiple execution contexts — per-frame game-loop calls trigger sound effects (engine RPM, collisions, skids), a background mixer thread drains sample buffers, and MSS callbacks drive hardware output. The audio subsystem encompasses:
- Miles Sound System integration (driver lifecycle, sample management)
- Codec/decoder pipeline (ADPCM, MPEG Layer3, IMDCT, DSP filtering, SIMD resampling)
- Sound synthesis (ADSR envelopes, waveform generation, frequency modulation)
- Sound event triggering (50+ event types dispatched from game logic)
- 3D audio positioning (listener-relative, doppler, distance attenuation, occlusion)
- Mixer background processing (dual-priority work queue, ring buffer management)

**Network subsystem:** Runs on its own thread pool with async socket I/O via WSAAsyncSelect, processing packets in a mutex-guarded work queue. The network subsystem encompasses:
- Connection management (TCP socket lifecycle, port scanning, async event notification)
- Packet send/receive (mutex-protected buffer management, completion queues, query matching)
- Message routing (3-bit class extraction → 5 type queues, 6-bit key handler dispatch)
- Thread-pool infrastructure (dual-priority work queues, mutex/critical-section wrappers)
- Winsock import thunks (35+ direct trampolines to ws2_32.dll)

Neither subsystem is "owned" by a single source file — the code is scattered across ~40 inferred modules spanning `audio_play.cpp`, `audio_codec.cpp`, `network_socket.cpp`, `NetComm.cpp`, `F1Network.cpp`, etc.

## Data Structures

### AudioStreamBuffer (param_1 — audio stream state)
```c
struct AudioStreamBuffer {
    /* +0x030 */ uint8_t  readyFlag;        // 0=needs init, 1=ready
    /* +0x034 */ uint32_t position;         // current read position
    /* +0x038 */ void*    sourcePointer;    // varies by buffer index
    /* +0x040 */ uint32_t bufferIndex;      // double-buffer toggle (xor 1)
    /* +0x044 */ int      fillState;        // 0=idle, 1=filling, 2=switch
    /* +0x048 */ uint32_t bufferSize;
    /* +0x04c */ int      bufferCounter;    // completed fills
    /* +0x114 */ int      bufferSizeBase;
    /* +0x118 */ int      totalBuffers;
    /* +0x180 */ void*    streamPtr;        // stream state
    /* +0x184 */ void*    vtableDecoder;    // method +0xc = data available
    /* +0x188 */ void*    vtableFiller;     // method +4 = buffer fill
    /* +0x19c */ void*    playCallback;     // vtable for playback/write
    /* +0x1a4 */ void*    flushCallback;    // vtable for flush
};
// Size: 0x1a8+ bytes
```

### NetworkConnectionManager (param_1)
```c
struct NetworkConnectionManager {
    /* +0x250 */ void*    sessionObj;       // session object pointer
    /* +0x29d */ uint8_t  cleanupFlag;      // controls WSACleanup call
    /* +0x2af */ HANDLE   mutexHandles[6];  // mutex handles for channels 0-5
    /* +0x2b6 */ HANDLE   primaryMutex;     // main send/receive mutex
    /* +0x2b7 */ DWORD    primaryTimeout;   // ms timeout
    /* +0x2bd */ HANDLE   secondaryMutex;   // secondary mutex
    /* +0x2c4 */ HANDLE   channelMutex3;
    /* +0x2cb */ HANDLE   channelMutex4;
    /* +0x2da */ HANDLE   channelMutex5;
    /* +0x2e5 */ HANDLE   channelMutex6;
    /* +0x2f0 */ HANDLE   channelMutex7;
    /* +0x640 */ HANDLE   packetMutex;      // packet builder mutex
    /* +0x6c  */ int      socketCount;      // number of sockets
    /* +0x08  */ SOCKET   socketArray[];    // stride 0x1c
    /* +0x778 */ WSADATA  wsaData;          // WSAStartup data
    /* +0x938 */ SOCKET   listenSocket;     // listening socket
    /* +0x93c */ SOCKET   altSocket;        // secondary socket (cancel)
    /* +0xa74 */ uint8_t  winsockInitFlag;  // 1 = initialized
    /* +0xaac */ void*    sendQueueHead;    // send queue linked list
    /* +0xabc */ HANDLE   sendMutex;
    /* +0xac0 */ DWORD    sendMutexTimeout;
    /* +0xac8 */ void*    connectionList;   // linked list of connections
    /* +0xad8 */ HANDLE   sessionMutex;
    /* +0xadc */ DWORD    sessionMutexTimeout;
    /* +0xb00 */ void*    cleanupConnectionList;
    /* +0xb10 */ HANDLE   cleanupMutex;
    /* +0xb14 */ DWORD    cleanupMutexTimeout;
    /* +0xb38 */ int      packetIdCounter;  // shared, mutex-protected
    /* +0xb3c */ HANDLE   packetIdMutex;
    /* +0xbec */ HANDLE   acceptMutex;
    /* +0xbf8 */ // end
};
// Size: 0xBF8 bytes (allocated by FUN_0057a420)
```

### AudioDecoderContext (param_1 — codec state)
```c
struct AudioDecoderContext {
    /* +0x24a4 */ void*    inputBuffer;      // compressed data ptr (null → skip)
    /* +0x24a8 */ uint32_t bitPosition;      // current bit position in stream
    /* +0x24bc */ int      ringIndex;        // ring buffer index (masked 0xf)
    /* +0x24cc */ int      channelCount;     // 2 = stereo, else mono
    /* +0x24d0 */ int      outputStride;     // bytes per channel
};
// Part of larger audio codec struct
```

### AudioMixerChannel (per-source state)
```c
struct AudioMixerChannel {
    /* +0x000 */ int      state;            // 0=idle, 1=active
    /* +0x034 */ int      channels;
    /* +0x038 */ int      samplesPerFrame;
    /* +0x03c */ int      frameSize;
    /* +0x044 */ int      alignment;
    /* +0x048 */ int      remainder;
    /* +0x04c */ int      voiceCount;       // tracked active voices
    /* +0x050 */ int      voiceTable[10];   // voice index mapping
    /* +0x024bc */ int    ringIndex;        // FIR ring buffer index
    /* +0x024cc */ int    channelMode;      // 2 = stereo
};
```

### ThreadPoolWorkQueue (param_1 — work queue processor)
```c
struct ThreadPoolWorkQueue {
    /* +0x57c */ void*    highPriorityQueue; // linked list head
    /* +0x598 */ void*    lowPriorityQueue;  // linked list head
    // Each work item node: { data_ptr, next_ptr, timer, callback }
};
```

### NetworkPacketNode (linked list)
```c
struct NetworkPacketNode {
    /* +0x00 */ void*    data;             // packet data or sockaddr_in ptr
    /* +0x04 */ void*    next;             // linked list next pointer
    /* +0x08 */ uint8_t  flags;            // flags/busy flag
    /* +0x0c */ // tail
};
// Size: 12 bytes. Used for send queues, connection lists, free lists.
```

## Global Variables Owned by This System

| Global | Type | Name | Description |
|--------|------|------|-------------|
| DAT_008d3e24 | void* | NetworkSingleton | Global network subsystem instance |
| DAT_008d3e28 | HWND | NetworkWindowHandle | Window handle for WSAAsyncSelect messages |
| DAT_008cef80 | char[256] | RecvBuffer | UDP receive buffer |
| DAT_008b0108 | int | CodecInitFlag | Audio codec initialized flag (0/1) |
| DAT_008b0124 | float[32] | DecodeWorkspace | Decoded PCM sample workspace |
| DAT_008b0224 | char[] | VLCWorkspace | VLC decoded values workspace |
| DAT_008b3xxx | float[] | ResampleCoeffs | FIR resampler coefficient tables (stereo) |
| DAT_005b7xxx | float[] | ResampleCoeffsMono | FIR resampler coefficient tables (mono) |
| DAT_008b6ac4 | int | AudioEffectGate | Audio effect enable flag |
| DAT_008b5a3c | void* | AudioEntryArray | Audio entry array base |
| DAT_008ac4c4 | void* | AudioSystemPtr | Primary audio system interface pointer |
| DAT_008ac4c8 | void* | AudioMixerPtr | Audio mixer object pointer |
| DAT_008ac4d0 | void* | AudioCodecPtr | Audio codec object pointer |
| DAT_007ca3b8–DAT_007ca480 | void* | AudioBufferPtrs[12] | Audio buffer/source object pointers |
| DAT_007d1ffc | int | AudioQualityLevel | 0–4, audio detail level |
| DAT_007d2044 | int | MuteChannelFlags | Left/right channel mute bitmask |
| DAT_007d2068 | int | AudioMuteFlags | Per-channel mute flags |
| DAT_007d1fd8 | int | AudioRaceModeFlag | Race-mode higher gain flag |
| DAT_007d208c | int[] | SampleRateDivisors | Per-sample rate divisors |
| DAT_007d20f8 | int | GainEnvelopeSelector1 | Gain envelope curve selector |
| DAT_007d22f0 | int | GainEnvelopeSelector2 | Gain envelope curve selector |
| DAT_007ce64c | char[] | PlayerNameList | Multiplayer player name list |
| DAT_005d3254 | char[] | AudioFileFormat | Audio file format string |
| DAT_008b8e48 | int | AudioChannelCount | Total initialized audio channels |

## Public API — Entry Points

### FUN_00406cc0 — Audio Driver Init (MSS)

**Inferred signature:** `int AudioDriverInit(void* audioState, int sampleRateIdx)`
**Called from:** game startup
**Called by:** not found in callers.json (likely called from game init)

**What it does:**
1. Calls pre-init vtable methods
2. Calls AIL_startup_0 and AIL_set_preference_8(0x1f, 0)
3. Selects sample rate from param_1[0x15]:
   - 0 → 11025 Hz (0x2b11)
   - 1 → 44083 Hz (0xac33)
   - else → 22050 Hz (0x5622)
4. Opens digital driver with 2 channels, 16-bit
5. On failure: calls vtable[0x34](0), AIL_shutdown, state=0, returns 1
6. On success: calls vtable[0x34](0xc), sets window handle, zeros 9 state fields
7. Sets file callbacks (FUN_00405050, FUN_00405160)
8. Sets state to 1, returns 0

**Side effects:**
- Opens Miles Sound System digital audio driver
- Sets global audio state
- Returns 0 on success, 1 on failure

---

### FUN_00406e50 — Audio System Shutdown

**Inferred signature:** `void AudioSystemShutdown(void* audioState)`
**Called from:** game shutdown (0x00406ba0)

**What it does:**
1. Check initialized flag — skip if 0 (already shutdown)
2. Walk 4 linked lists (pending, active, free samples), call vtable destructor per node
3. Free nodes via FUN_00587bcf
4. Call vtable destructor on audio state
5. Close waveOut: AIL_waveOutClose_4
6. Call AIL_shutdown_0
7. Clear initialized flag

---

### FUN_00411e90 — Sound Event Dispatcher

**Inferred signature:** `void DispatchSoundEvent(void* context, SoundEvent* event)`
**Called from:** 0x00411840

**What it does:**
Uses _rand() for randomization, dispatches 50+ event types:
- 1 → FUN_00413600 (engine loop)
- 2 → FUN_00413710 (exhaust)
- 4, 0x2f → FUN_004122c0 (tire skid)
- 5, 10, 0x17 → FUN_00412490 (collision, repeat=1)
- 6, 0x1b → FUN_00412490 (collision, repeat=0)
- 0xe, 0x13, 0x29 → FUN_00412e50 (ambient)
- 0x11, 0x34 → FUN_00414010 (radio/voice)
- 0x1e → FUN_004133b0 (gear change)
- 0x1f → FUN_00413820 (wind)
- 0x20 → FUN_004139c0 (rain)
- 0x32 → FUN_00412c30 (special)

Uses pitch/volume/pan from event param_3+0x10/0x14/0x18.

---

### FUN_004f12e0 — Vehicle Sound Trigger

**Inferred signature:** `void TriggerVehicleSounds(void* vehicle)`
**Called from:** 0x004f0430 (vehicle update)

**What it does:**
1. Iterates 4 wheel pointers at param_1+0x3668 (stride 0x3e)
2. Collects unique surface types (+0x54→+0x34) and wheel IDs (+0x54→+0x30)
3. Computes vehicle speed from wheel velocity (+0x34ec/0x34f0/0x34f4)
4. Triggers surface-contact sounds via FUN_004f87c0
5. Triggers skid sounds when slip angle (+0x7a4) > 0
6. Triggers engine/road noise by suspension type (+0x32bc)

**Calls:** FUN_004f0f40 (wheel data gather), FUN_004f1120 (surface mapping), FUN_004f87c0 (play dispatch)

---

### FUN_0057fb90 — Winsock Init

**Inferred signature:** `int WinsockInit(void* netState)`
**Called from:** network startup

**What it does:**
1. Check flag at param_1+0xa74 — skip if already initialized
2. Call WSAStartup(0x202, &param_1+0x778) — version 2.2
3. On success: set flag at +0xa74 to 1
4. On failure: set flag to 0, call FUN_0057d400 (error handler)
5. Return initialization status

---

### FUN_0057ba10 — Network Subsystem Constructor

**Inferred signature:** `void* NetworkCtor(void* this, void* params, uint32_t mode)`
**Called from:** 0x0057a420 (object allocation + construction)

**What it does:**
1. Copy 0x30 bytes from param_2 into param_1+0x242
2. Initialize 6 mutex-protected channels (IDs 0-5) via repeated FUN_00582360/FUN_00586500 calls
3. Create 2 semaphore-style objects (FUN_00582720)
4. Start 2 worker threads (FUN_005828b0, FUN_00581fd0, FUN_00581d40)
5. Set vtable pointer, global singleton at DAT_008d3e24
6. Call FUN_0057e480 for final setup
7. Return param_1

**Side effects:**
- Creates 6 mutex handles
- Creates 2 worker threads
- Sets global singleton DAT_008d3e24

---

### FUN_00563260 — Network Connection / Session Management

**Inferred signature:** `int NetworkSessionConnect(void* state, char* hostIP, int sessionID, int localFlag, int param5)`
**Called from:** 0x00461ed0 (Configuration set)

**What it does:**
1. Resolve host IP via inet_addr(param_2), session via FUN_005631a0
2. If *param_1 == 0 (fresh connection):
   - Create socket via FUN_00562d20
   - If session == -1 (client): FUN_00563160 connect
   - Else (host): setup server on port 9999 via FUN_005648b0/FUN_00564990
   - Get max clients via FUN_00563e70 → store at param_1[0x1c]
   - Set attempt counter param_1[0x1d] = 0
   - Network init FIN_00562fe0
   - If param_4 == 0: enter listen mode via FUN_00563000
3. Else if *param_1 > 0 AND session == -1 (disconnected):
   - Reconnect handler FUN_005633d0
   - Increment retry counter param_1[0x26] if state 1 or 2
4. Else (existing, valid session):
   - Allocate socket, bind session, clear client entry
   - Decrement max clients counter

---

### FUN_00580c10 — Network Packet Send

**Inferred signature:** `void SendNetworkPacket(void* netState, void* packetData)`
**Called from:** network send path

**What it does:**
1. Acquire 3 mutexes at +0xb3c/+0xad8/+0x640 (WaitForSingleObject)
2. Get packet ID from shared counter at +0xb38 (mutex-protected)
3. Allocate 0x20-byte packet buffer via operator_new
4. Build packet via FUN_0057b780 (packet constructor)
5. Send via FUN_0057dd40 (normal) or FUN_00587370 (mutex-protected)
6. Link sent packet into completion queue linked list
7. Use htonl/htons for network byte order
8. Release mutexes

---

### FUN_0052e6f0 — ADPCM/Codec Decoder

**Inferred signature:** `int DecodeAudioFrame(void* codecCtx, void* output)`
**Called from:** audio decode pipeline

**What it does:**
1. Gate: return -1 if param_1+0x24a4 (input buffer) is null
2. Two modes based on DAT_008b0108:

   **Initialized mode (DAT_008b0108 != 0):**
   - Stereo (param_1[0x24cc] == 2): read 32 bytes → extract 64 nibbles → call FUN_0052e5e0 32× per block (12 blocks) → output via FUN_00532aa0 (resampler)
   - Mono: read VLC-coded nibbles via Huffman-like tables (DAT_005b4788, DAT_005b4820, DAT_005b2ca4) → decode to float PCM → output via FUN_00531830

   **Uninitialized mode (raw PCM):**
   - Direct 8-bit or 4-bit nibbles → table lookup via DAT_005b11a4 → float conversion

3. Post-decode: call resampler (FUN_00532aa0 for stereo, FUN_00531830 for mono) on each of 12 output blocks
4. Output: 0x600 bytes PCM per call (12 blocks × 0x80 bytes)

---

### FUN_00532aa0 — SIMD FIR Resampler

**Inferred signature:** `void ResampleAudio(void* ctx, short* output, void* input)`
**Called from:** 0x00531250 (alt write), 0x0052e6f0 (decoder)

**What it does:**
1. Ring buffer index at param_1+0x24bc (masked to 0xf)
2. Entry count check: param_1[0x24cc] == 2 → stereo path, else mono path
3. Stride: +0x480 through input per iteration, +0x40 shorts output (64 samples)
4. Processing per channel: 16 pmaddwd accumulations (4×16-bit samples × 4 coefficients) + pmulhw + accumulation + >> 13 + packssdw
5. Output: 0x20 stereo pairs (32 stereo samples) or 0x40 mono samples per call
6. Coefficient pointer alternates between two sets for stereo interleave

**Calls:** FUN_00534120 (SIMD helper)

---

### FUN_00583f50 — Thread-Pool Work Queue Processor

**Inferred signature:** `void ProcessWorkQueue(void* queue)`
**Called from:** background worker thread

**What it does:**
1. Drain mutex-protected work queue with timeout-based watchdog
2. Process two priority queues (offsets 0x57c/0x598)
3. For each work item: execute callback, decrement timer
4. Remove completed items from linked list
5. Handle SEH (structured exception handling) around processing

---

### FUN_00564390 — Audio Mixer Polling Loop

**Inferred signature:** `void DrainMixerQueue(void* mixer)`
**Called from:** background audio thread

**What it does:**
1. Call FUN_00564220 to check for pending work
2. Loop while work remains:
   - Call FUN_00564220 (advance/update mixer state)
   - Check FUN_00564410 (need mix operation?)
   - If yes: call FUN_00564270 twice (left/right channel mix) + FUN_00564780
3. Continue until queue drained (FUN_00564220 returns 0)

---

## Internal Call Graph

### Audio Decode Pipeline
```
FUN_0052e6f0 — ADPCM/Codec Decoder  [audio decode path]
  +-- FUN_0052e5e0 — Codec Core Per-Entry Decode (32× per block, 12 blocks)
  +-- FUN_00532aa0 — SIMD FIR Resampler (stereo out)
  |     +-- FUN_00534120 — SIMD Helper Operations
  +-- FUN_00531830 — Mono Output Handler
        +-- FUN_00531b50 — 32-Point MDCT Transform

FUN_0051bad1 — DSP Filter Selector  [post-decode]
  +-- FUN_0052851d/5f/4a/5a/a6 — FIR/Crossfeed/Reverb filters
  +-- FUN_005285f2 — 8-Point Inverse MDCT (synthesis filterbank)

FUN_0052a6ec — MPEG Layer3 IMDCT (int)  [MP3 path]
FUN_0052b206 — MPEG Layer3 IMDCT (short)  [MP3 alt path]
```

### Sound Trigger Pipeline
```
FUN_004f12e0 — Vehicle Sound Trigger  [per vehicle tick]
  +-- FUN_004f0f40 — Wheel Data Gather
  +-- FUN_004f1120 — Surface Type Mapping
  +-- FUN_004f87c0 — Sound Play Dispatch

FUN_00411e90 — Sound Event Dispatcher  [game event → audio]
  +-- FUN_00413600 — Engine Loop Sound
  +-- FUN_00413710 — Exhaust Sound
  +-- FUN_004122c0 — Tire Skid Sound
  +-- FUN_00412490 — Collision Sound
  +-- FUN_00412e50 — Ambient Sound
  +-- FUN_00414010 — Radio/Voice Sound
  +-- FUN_004133b0 — Gear Change Sound
  +-- FUN_00413820 — Wind Sound
  +-- FUN_004139c0 — Rain Sound
  +-- FUN_00412c30 — Special Sound

FUN_004f88a0 — Engine RPM Sound Trigger
  +-- FUN_004f1b10 — RPM Ratio Read
  +-- FUN_004f87c0 — Sound Play Dispatch

FUN_0045f710 — Team Radio Message Processor
  +-- FUN_00461440 — Radio State Check
  +-- FUN_00460c30 — Team ID Append
  +-- FUN_0057a760 — Message Queue Read (FIFO)
```

### Mixer Pipeline
```
FUN_00564390 — Mixer Polling Loop  [background thread]
  +-- FUN_00564220 — Advance Mixer State / Poll Work
  +-- FUN_00564410 — Check if Mix Operation Needed
  +-- FUN_00564270 — Mix Operation Pair (L/R channels)
  +-- FUN_00564780 — Function Pointer Call with Error Handling

FUN_00560fe0 — 3D Audio Source Update  [per source]
  +-- Position relative to listener
  +-- Distance attenuation computation
  +-- Doppler pitch shift calculation
  +-- Occlusion/obstruction handling
  +-- Audio channel state flag management

FUN_00515bb0 — Voice Allocation
  +-- FUN_00515917 — Aligned Allocation / Alignment Adjustment
```

### Network Send Pipeline
```
FUN_00580c10 — Packet Send  [send path]
  +-- FUN_0057b780 — Packet Constructor (0x20-byte buffer)
  +-- FUN_0057dd40 — Queue to Thread-Pool
  +-- FUN_00587370 — Mutex-Protected Send

FUN_0057d8d0 — Send with Query Matching  [query/response]
  +-- FUN_0057d5d0 — Query Encode
  +-- FUN_0057b6b0 — Socket Getter
  +-- FUN_0057b0d0 — Query Iterator
  +-- FUN_0057b2e0 — Query Handler Check
  +-- FUN_0057db80 — ID Matching Check

FUN_005813e0 — Connection Manager + Send
  +-- FUN_0057b7d0 — Socket Create
  +-- FUN_0057b9f0 — Socket Setup/Config
  +-- FUN_0057dd40 — Socket Send
```

### Network Receive Pipeline
```
FUN_00561e30 — UDP Packet Receive  [receive loop]
  +-- select() — poll for data
  +-- recvfrom() → DAT_008cef80 (256-byte buffer)
  +-- FUN_005622c0 — Process Received Packet

FUN_004c7ca0 — Network Message Receive  [per-player]
  +-- 4096-byte receive buffer per player
  +-- FUN_0054c110 — Receive Operation Start
  +-- FUN_005452f0/5340 — Per-Player Receive
  +-- Event allocation + queue management

FUN_004b4a30 — Packet Router  [class-based dispatch]
  +-- Extract 3-bit class from top bits of param_2[0]
  +-- Route to queue: index = (class+7) × 16
  +-- Walk linked list, remove matching packet
  +-- FUN_00587bcf — Free packet node
  +-- FUN_004b47a0 — Notify class handler
  +-- Insert tracking node into global free list

FUN_004b54e0 — Message Dispatch  [handler lookup]
  +-- Extract 6-bit key from bits 18-23
  +-- Walk handler list, match offsets +0x368 and +0x36c
  +-- FUN_004ba7a0 — Handler Lookup
  +-- FUN_004ba980 — Alloc handler (if not found)
  +-- FUN_004fffb0 — Dispatch Message
```

### Shared Infrastructure
```
FUN_0057ba10 — Subsystem Constructor  [once at network init]
  +-- FUN_00582360/6500 — Create Mutex Channels (×6)
  +-- FUN_00582720 — Create Semaphores (×2)
  +-- FUN_005828b0/1fd0/1d40 — Start Worker Threads (×2)

FUN_0057bce0 — Subsystem Destructor  [shutdown]
  +-- CloseHandle ×6 (mutexes in reverse order)
  +-- FUN_0057e530 — Teardown Step 1
  +-- FUN_0057fbe0 — Network State Cleanup
  +-- FUN_00582dc0/2ce0/2a10/2650 — Sub-destructors
  +-- FUN_00583ae0 — Final cleanup

FUN_00583f50 — Work Queue Processor  [background thread]
  +-- Mutex-protected linked list operations
  +-- Two priority queues (0x57c/0x598)
  +-- Timer decrement + removal of completed items
  +-- SEH exception handling

FUN_0059a54d — Thread-Safe Critical Section  [sync primitives]
  +-- InterlockedExchange for one-time init
  +-- Spin-wait during concurrent init
  +-- EnterCriticalSection on DAT_008d45f8
```

## Constants and Magic Numbers

| Value | Used in | Meaning |
|-------|---------|---------|
| 11025 | FUN_00406cc0 | Sample rate selection 0 |
| 22050 | FUN_00406cc0 | Sample rate selection default |
| 44083 | FUN_00406cc0 | Sample rate selection 1 |
| 0x2b11 | FUN_00406cc0 | 11025 Hz as hex |
| 0x5622 | FUN_00406cc0 | 22050 Hz as hex |
| 0xac33 | FUN_00406cc0 | 44083 Hz as hex |
| 2 | FUN_00406cc0 | Number of audio channels (stereo) |
| 16 | FUN_00406cc0 | Bits per sample |
| 0x480 | FUN_00532aa0 | Input stride per iteration (1152 bytes) |
| 0x40 | FUN_00532aa0 | Output stride per iteration (64 shorts) |
| 16 | FUN_00532aa0 | pmaddwd accumulations per channel |
| 13 | FUN_00532aa0 | Fixed-point right-shift after accumulation |
| 0x600 | FUN_0052e6f0 | PCM output per call (12 blocks × 0x80) |
| 12 | FUN_0052e6f0 | Blocks per decode frame |
| 32 | FUN_0052e6f0 | Codec entries per block |
| 0x800 | FUN_0052a6ec | Right-shift for window coefficients |
| 8 | FUN_0052a6ec | Blocks of 8 frequency lines |
| 64 | FUN_005285f2 | Sub-bands for 8-point IMDCT |
| 1024 | FUN_0052a6ec | Lookup table size for synthesis filterbank |
| 0x1f (31) | FUN_0052e6f0 | Max codebook entry index |
| 0x1FFFFFF | FUN_0052e6f0 | 25-bit mask for VLC decode |
| 0x207c | FUN_00581fd0 | Pool allocator control block size |
| 0x103c | FUN_00581fd0 | Pool slot size (×2 slots) |
| 0xbf8 | FUN_0057a420 | Network object size |
| 0x20 | FUN_00580c10 | Packet buffer size |
| 0x10 | FUN_0057b9a0 | sockaddr_in size |
| 0xff | FUN_00561e30 | Receive buffer size (255 bytes) |
| 0x40 | FUN_00561e30 | select() fd_set size |
| 0x3f | FUN_0057c860 | WSAAsyncSelect event mask (all events) |
| 9999 | FUN_00563260 | Default server port |
| 0x7fffffff | FUN_005804a0 | listen() backlog size |
| 100 | FUN_0057c7b0 | Port scan retry limit |
| 35+ | various | Winsock import thunks |

## Inter-System Dependencies

**Reads from (external globals/systems):**
- DAT_007c56a4 (SessionType) — gates audio commentary responses
- DAT_007d0308 (RaceActiveFlag) — gates sound trigger dispatch
- DAT_007cf3c8 (TrackConditionState) — weather/condition audio cues
- DAT_007c54e8 (PlayerVehiclePtr) — player-relative audio positioning
- DAT_005c329c (VehicleCount) — iteration bounds for vehicle sounds
- DAT_007c54f0 (VehiclePtrArray) — vehicle pointer access
- DAT_008acfcc (Sentinel) — network active flag check

**Calls into:**
- docs/20-math-utilities.md: FUN_00588410 (string compare), FUN_00587bcf (free), FUN_005871f0 (RNG), FUN_0058815f (format)
- docs/19-renderer.md: FUN_00543210 (surface acquire), FUN_004cefa0 (debug draw)

**Called by:**
- docs/01-engine-architecture.md: game init chain (audio startup, network startup, thread creation)
- docs/06-session-race-logic.md: session state machine (FUN_0045d890 → network dispatch)
- docs/10-vehicle-physics.md: vehicle update (FUN_004f0430 → vehicle sound trigger)
- docs/02-ai-system.md: AI event handlers (→ audio commentary)

## Reimplementation Notes

1. **MSS dependency**: Audio output goes through Miles Sound System (MSS), a third-party library. Modern reimplementation must either stub MSS or replace it with OpenAL/XDSP/etc. Key MSS calls: AIL_startup, AIL_open_digital_driver, AIL_allocate_sample_handle, AIL_init_sample, AIL_set_sample_processor, AIL_waveOutClose.

2. **Codec tables**: The audio decoder uses pre-computed lookup tables (DAT_005b2ba4 coefficients, DAT_005b4788 VLC bit lengths, DAT_005b4820 VLC offsets, DAT_005b11a4 multipliers). These must be reverse-engineered or the codec must be replaced.

3. **SIMD resampler**: FUN_00532aa0 uses MMX/SSE pmaddwd + pmulhw + packssdw. Fixed-point arithmetic with 13-bit right-shift. The coefficient tables (DAT_008b3xxx stereo, DAT_005b7xxx mono) must match exactly.

4. **WinSock version**: WSAStartup requests version 2.2 for the primary network init, but 1.01 for the secondary (FUN_00564660). Modern systems support both, but this may cause issues on locked-down environments.

5. **Port 9999 hardcoded**: The server port is hardcoded to 9999 in FUN_00563260. Mods may want to make this configurable.

6. **Thread pool architecture**: Two worker threads, 6 mutex channels, 2 priority queues. Work items are processed with timer decrement and auto-removal on completion. This is a custom implementation, not std::thread or Win32 thread pool.

7. **WSAAsyncSelect**: Socket I/O uses WSAAsyncSelect with window message routing (message 0x1a0a, window handle DAT_008d3e28). Requires a Windows message pump. The event mask 0x3f covers FD_READ|FD_WRITE|FD_ACCEPT|FD_CONNECT|FD_CLOSE.

8. **Packet routing**: 3-bit class field in top bits → 5 queues (class 0-4), 6-bit key in bits 18-23 → handler list lookup. This is a custom protocol on top of UDP/TCP.

9. **Audio mixing model**: Background thread drains a mixer queue. Each mix operation is called in pairs (left/right channel). The resampler produces 64 samples per call (32 stereo pairs). About 11 simultaneous voices max.

10. **No low-latency audio path**: Audio goes through a polling loop with SleepEx-based timing. Not suitable for real-time music performance but adequate for game sound effects.

## Completeness

- Full specs written: 10 entry points + overview + data structures + call chains
- Winsock thunks omitted: 35+ import thunks (pure ws2_32.dll trampolines — no game logic)
- Minor audio helpers omitted: FUN_00556730 (parameter fetch), FUN_00568210 (channel stop), FUN_00541fb0 (flag setter)
- Confidence: **high** — all major subsystems documented from decompiled source
- Remaining unknowns: exact coefficients in codec lookup tables, exact Bink video integration details, exact AIL_preference values
