# Source Cross-Reference: docs/21-audio-network-internals.md

## RTTI Class Mappings

| rFactor Class | F1C Function(s) | Confidence | Evidence |
|--------------|-----------------|------------|----------|
| `NetComm` | FUN_0045d890, FUN_0045fc50, FUN_00460520, FUN_00460e90, FUN_00461190, FUN_00461f90, FUN_00463160, FUN_00464290 | HIGH | Direct match — NetComm::SetSelfAsReady, NetComm::ParseCommandLine, NetComm session msg dispatcher. Doc explicitly mentions "NetComm.cpp" for >10 functions. |
| `Response@HotPacket` | FUN_004b54e0, FUN_004b4a30 | HIGH | Doc describes "6-bit key dispatch" and "HotPacket_over_Winsock" string pattern. RTTI shows `Response@HotPacket` class. |
| `SoundMan` | FUN_00406cc0, FUN_00406e50, FUN_004072e0, FUN_00406750 | HIGH | Doc explicitly says "MSS lifecycle" and "SoundMan" class pattern. RTTI confirms `SoundMan` class in rFactor Dedicated. |
| `SoundSource` | FUN_004085f0, FUN_004f12e0, FUN_00560fe0, FUN_0055d5c0 | HIGH | Doc describes "3D positional audio per sound source". RTTI shows `SoundSource` class. |
| `AudioBufferInterface` | FUN_00541120, FUN_0051868c, FUN_0044ff50 | MEDIUM | Doc describes audio buffer format setup. RTTI shows `AudioBufferInterface` in rFactor. F1C uses different struct offsets but same concept. |
| `AmbientSoundCrowd` / `AmbientSoundAirHorns` / `AmbientSoundAnnouncer` / `AmbientSoundPitHorn` / `AmbientSoundReverb` | FUN_00411e90 (case 0xe/0x13/0x29 → ambient), FUN_00412e50 | MEDIUM | Doc dispatches ambient sound events. rFactor has full ambient sound class hierarchy not present in F1C (isiMotor2 vs isiMotor1). |
| `PluginManager` / `RFPluginManager` | FUN_00580c10, FUN_0057d8d0, FUN_00563260 | MEDIUM | Network packet send/connection mgmt share patterns with plugin manager pattern. No direct mapping — rFactor has plugin system, F1C does not. |
| `ReplayMan` | FUN_00564390, FUN_00568320 | LOW | Doc mentions background mixer thread. rFactor `ReplayMan` class exists but F1C audio mixer is separate from replay system. |
| `PitMan` | FUN_0044ff50 (case 7) | LOW | Doc mentions race-mode audio flag DAT_007d1fd8==3 with higher gain heads — could be pit/race audio mode distinction. PitMan class in rFactor handles pit audio. |
| `beepSoundMiles` / `beepStreamMiles` / `beepObjectMiles` | FUN_004072e0, FUN_00406cc0, FUN_00406e50 | MEDIUM | rFactor has Miles Sound wrappers (beepSoundMiles). F1C MSS integration documented as "Miles Sound System Integration (16 functions)". Same underlying SDK. |

## Parameter-to-Offset Mappings

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| `EngineRPMSound` | (general vehicle config) | param_1+0x39a0 / +0x39a4 | RPM ratio numerator/denom | EngineRPMCur / EngineRPMMax | MEDIUM — string "EngineRPMSound" appears in NASCAR 2003 crossref shared strings. Used in FUN_004f88a0 (RPM ratio= *+0x39a0 / *+0x39a4). |
| `Vehicle Roadnoise FreqMult` | (PLR/audio) | +0x32bc | SuspensionType/EngineRoadNoiseSelector | RoadNoiseFreqMult | MEDIUM — FUN_004f12e0 reads +0x32bc for "suspension type" to trigger road noise. HDV params in rFactor have "Vehicle Roadnoise FreqMult/FreqMin/VolMult/VolSpeed". |
| `Vehicle Skidding VolMult` | (PLR/audio) | +0x7a4 | SlipAngleThreshold | SkidTriggerThreshold | MEDIUM — FUN_004f12e0 checks +0x7a4 (slip angle) > 0 for skid sounds. rFactor HDV has "Vehicle Skidding VolMult/FreqSpeed/FreqGrip". |
| `Vehicle Scrubbing VolMult` | (PLR/audio) | (implicit in FUN_00411e90 case 4/0x2f) | TireScrubSoundEvent | ScrubbingVolParam | LOW — FUN_00411e90 dispatches tire skid (case 4, 0x2f). rFactor has "Vehicle Scrubbing VolMult/FreqSpeed/FreqGrip". |
| `Maximum sound effects playing simultaneously` | (PLR audio) | ~11 voices | MaxVoices (FUN_00515bb0) | MaxSimultaneousSfx | MEDIUM — FUN_00515bb0 tracks up to ~11 simultaneous voices. NASCAR 2003 shared strings include "Maximum sound effects playing simultaneously". |
| `Additional volume multiplier for other vehicles` | (PLR audio) | param_1+0x24d0 | OutputStride | OtherVehicleVolMult | LOW — FUN_0052e6f0 uses output stride from +0x24d0 for volume scaling. rFactor HDV comments mention "Additional volume multiplier for other vehicles" and "for player's vehicle". |
| `Additional volume multiplier for player's vehicle` | (PLR audio) | DAT_0059f09c | DefaultVolume | PlayerVehicleVolMult | LOW — FUN_0045d530 sets default volume from DAT_0059f09c. |

## String Matches

| String | Found In | F1C Function | Insight |
|--------|----------|-------------|---------|
| `"Entered Sound::Enter()"` | NASCAR2003, rFactor Shared | FUN_004c8ab0 (Sound::Enter per doc/01) | Confirms Sound class lifecycle — Enter/Exit/Init/Post/Restart/Setup all match across ISI binaries. |
| `"Entered Sound::Exit()"` | NASCAR2003, rFactor ShareD | FUN_004c8b20 (Sound::Exit per doc/01) | Same pattern — confirms Sound class methods. |
| `"Entered Sound::Init()"` | NASCAR2003, rFactor Shared | FUN_004c8650 (Sound::Init) | Sound init pattern consistent across all ISI games. |
| `"EngineRPMSound"` | NASCAR2003, rFactor Shared | FUN_004f88a0, FUN_004f89a0 | Used in FUN_004f88a0 for RPM-based sound event triggering. String appears as parameter name in .hdv files. |
| `"EngineRPMSoundInside"` | NASCAR2003, rFactor Shared | FUN_004f88a0 | Interior RPM sound variant — mapped via event type (0xe vs 0xc/0xd). |
| `"EngineRPMSoundOutside"` | NASCAR2003, rFactor Shared | FUN_004f88a0 | Exterior RPM sound variant — mapped via event type. |
| `"Error: %s while setting DirectSound"` | NASCAR2003, rFactor Shared | FUN_00406cc0 | DirectSound init error path in MSS driver init. |
| `"Error: %s while setting Miles sound"` | NASCAR2003, rFactor Shared | FUN_00406cc0 | Miles Sound System init error path. |
| `"Maximum sound effects playing simultaneously"` | NASCAR2003 Shared | FUN_00515bb0 (voice/channel alloc) | Corresponds to ~11 voice limit in voice allocator. |
| `"HotPacket_over_Winsock"` | NASCAR2003, rFactor Shared, F1C | FUN_004b4a30, FUN_004b54e0 | HotPacket string in doc/00-methodology confirms identity: HotPacket/Winsock networking layer. |
| `"<HotPacket::Winsock>"` | NASCAR2003, rFactor Shared, F1C | FUN_00580190, FUN_0057fb90 | Same HotPacket networking layer. |
| `"Music Toggle"` | NASCAR2003 Shared | FUN_00441120 | Audio format setup related to music playback toggle. |
| `"Music Volume"` | NASCAR2003 Shared | FUN_0045d530 | Default volume settings. |
| `"Sound Detail"` | NASCAR2003 Shared | FUN_0051bad1 | DSP filter selector relates to sound quality/detail setting. |
| `"Sound Options"` | NASCAR2003 Shared | (UI layer) | Sound options page configures parameters used by audio functions. |
| `"AUDIO ASSERT !!! ..."` | NASCAR2003, rFactor Shared | FUN_00406e50, FUN_00406cc0 | Audio debug assertions in MSS wrapper code. |
| `_BinkClose_4` / `_BinkDoFrame_4` / `_BinkCopyToBuffer_28` | NASCAR2003, rFactor, F1C | FUN_00551ce0, FUN_00551cf0, FUN_00551dd0 | Bink video API wrappers confirmed across all ISI games. |
| `"Duplicate connection"` | NASCAR2003, rFactor Shared | FUN_005813e0, FUN_00580190 | Network connection mgmt — duplicate detection in accept handler. |
| `"MultiClient"` / `"MultiServer"` | NASCAR2003, rFactor Shared | FUN_00563260 | Client/server distinction in connection lifecycle. |
| `"D:\Dev\AudioDev\Shared\Engine\Dev\LbMpeg.cpp"` | NASCAR2003, NASCAR2004 Shared | FUN_0051b45f, FUN_00510d60, FUN_0052e6f0 | Source path for MPEG audio codec — confirms these functions are from shared audio library (LbMpeg.cpp). |

## SDK Struct Alignment

SDK structs from rFactor InternalsPlugin.hpp apply to isiMotor2 (rFactor) not isiMotor1 (F1C). No direct struct offset alignment. However, conceptual alignment:

| SDK Field | SDK Struct | F1C Equivalent | Status |
|-----------|-----------|---------------|--------|
| `mWheel[4].mSuspensionDeflection` | TelemWheel | +0x3668 wheel array stride 0x3e (FUN_004f12e0) | CONCEPTUAL — F1C uses smaller wheel struct (0x3e vs 0x4c bytes) |
| `mWheel[4].mRideHeight` | TelemWheel | +0x32bc suspension type (FUN_004f12e0) | CONCEPTUAL — different struct layout |
| `mWheel[4].mBrakeTemp` | TelemWheel | vehicle struct brake temp fields (docs/10) | STRUCTURE — not in doc/21 functions |
| `mEngineRPM` | TelemInfoBase | +0x39a0 (FUN_004f88a0) | CONCEPTUAL — RPM ratio used for sound triggering |
| `mUnfilteredThrottle` | TelemInfoBase | param_3+0x10 (FUN_00411e90) | CONCEPTUAL — throttle input modulates sound volume |
| `mGear` | TelemInfoBase | case 0x1e in FUN_00411e90 | CONCEPTUAL — gear change triggers distinct sound event |
| `GraphicsInfo.mHWND` | GraphicsInfo | DAT_008d3e28 (FUN_0057c860) | CONCEPTUAL — window handle passed to WSAAsyncSelect |
| `ScoringInfoV2.mGamePhase` | ScoringInfoV2 | DAT_007c56a8 (RacePhase) | SEPARATE — F1C race phase tracking matches rFactor mGamePhase concept |
| `ScoringInfoV2.mYellowFlagState` | ScoringInfoV2 | DAT_008acf94 (RaceTimeThreshold) | NOT MAPPED — caution state not directly in audio/network functions |

## Proposed Renames

| Current | Proposed | Evidence |
|---------|----------|----------|
| Source: audio_codec.cpp / audio_resampler.cpp | Source: D:\Dev\AudioDev\Shared\Engine\Dev\LbMpeg.cpp | String crossref shows LbMpeg.cpp as shared audio codec source across NASCAR2003, NASCAR2004. F1C uses same codec library. |
| Source: audio_play.cpp / soundmanager.cpp | Source: ..\Source\sound.cpp (from rFactor dev tree) | rFactor source paths show sound.cpp as audio module. F1C dev tree has f1sounds.cpp as Common/Source file. The MSS integration lives in these files. |
| Source: network_session.cpp / F1Network.cpp | Source: ..\Source\NetComm.cpp / ..\Source\NetCommUtil.cpp | rFactor source paths confirm NetComm.cpp + NetCommUtil.cpp. F1C dev tree maps to same files. |
| Source: bink_video.cpp | Source: binkw32.dll import library | Bink video is 3rd-party RAD Game Tools SDK — not ISI source code. All Bink functions are import wrappers. |
| FUN_0052e6f0 — "Compressed Audio Decoder (ADPCM/Codec)" | FUN_0052e6f0 — "MPEG Audio Layer 3 Decoder (MP3)" | Evidence: string "D:\Dev\AudioDev\Shared\Engine\Dev\LbMpeg.cpp" and structural match to MP3 decoder pattern (12-block frames, IMDCT, 64 sub-bands). LbMpeg = MPEG audio library. |
| FUN_00532aa0 — "Audio Resampler / Sample Rate Converter (SIMD FIR)" | FUN_00532aa0 — "MPEG Synthesis Polyphase Filterbank + Resampler" | Evidence: sits downstream of MP3 decoder chain, processes 64 sub-band outputs, uses coefficient tables DAT_008b3xxx. Part of LbMpeg MPEG pipeline. |
| FUN_005285f2 — "8-point Inverse MDCT" | FUN_005285f2 — "MPEG Layer 3 64-Band Synthesis IMDCT" | Evidence: part of LbMpeg MP3 decode chain, 64 sub-bands, butterfly computation matches MPEG standard. |
| FUN_0051bad1 — "Audio DSP Filter Selector" | FUN_0051bad1 — "MPEG Joint Stereo / Intensity Stereo Decode Selector" | Evidence: 6 mode flags (1,2,4,8), channel stride 0x15 per channel, crossfeed from DAT_005b0588 table — matches MPEG stereo processing modes. |
| FUN_0052a6ec — "MPEG Audio Layer 3 IMDCT / Synthesis Filterbank (int)" | (keep) | Already correctly identified as MPEG Layer 3. High confidence. |
| FUN_0052b206 — "MPEG Audio Layer 3 IMDCT / Synthesis Filterbank (short)" | (keep) | Already correctly identified as MPEG Layer 3 short block variant. High confidence. |
| FUN_00530050 — "MP3 Audio Decoder — Huffman + Sample Rendering" | (keep) | Already correctly identified as MP3 Huffman decoder. High confidence. |
| DAT_008b0108 — codec initialized flag | DAT_008b0108 — MPEGCodecReady | Evidence: codes two decode modes (initialized=MP3 VLC decode, uninitialized=raw PCM passthrough). |
| DAT_008b0124 — decoded sample workspace | DAT_008b0124 — MPEGFrameDecodeBuffer | Evidence: 32-float workspace used per frame. |
| FUN_004f88a0 — "SoundEffectTrigger (EngineRPM)" | FUN_004f88a0 — "EngineRPM_Sound_Play" | Evidence: reads RPM ratio from struct fields matching .hdv EngineRPMSound parameters. rFactor has EngineRPMSound/EngineRPMSoundInside/EngineRPMSoundOutside config params. |
| FUN_00411e90 — "Sound Event Dispatcher" | FUN_00411e90 — "SoundManager::TriggerEvent" | Evidence: sound class has Enter/Exit/Init/Post/Restart/Setup lifecycle (confirmed by crossref strings). This is likely SoundManager::TriggerEvent or Sound::TriggerEvent method. |
| FUN_0057fb90 — "WinsockInit" | FUN_0057fb90 — "NetComm::InitWinsock" | Evidence: uses global param_1+0xa74 init flag and +0x778 WSADATA which match NetCommSession struct in docs/13. |
| FUN_00563260 — "Network Connection / Session Management" | FUN_00563260 — "NetComm::ConnectSession" | Evidence: documented as entry point for multiplayer session join/host. Matches NetComm lifecycle in rFactor. |
| FUN_00580190 — "Network Accept / Connection Handler" | FUN_00580190 — "NetComm::AcceptConnections" | Evidence: operates on socket at param_1+0x938 (ListenSocket from NetCommSession struct). |

## Additional Notes

1. **MPEG Audio Codec Source**: The string "D:\Dev\AudioDev\Shared\Engine\Dev\LbMpeg.cpp" confirms that FUN_0051b45f, FUN_00510d60, FUN_0052e6f0, FUN_005285f2, FUN_0052a6ec, FUN_0052b206, FUN_00530050, FUN_00531b50, FUN_0051bad1, FUN_0051e3e7, FUN_00532aa0, FUN_00516a1d, FUN_00515417 are all from a shared ISI audio codec library (LbMpeg = "Library MPEG"). This is NOT game-specific code — it's a 3rd-party or shared library used across all ISI games (NASCAR2003, NASCAR2004, rFactor).

2. **Bink Video**: All Bink functions (FUN_00551ce0, FUN_00551cf0, FUN_00551dd0, FUN_00551eb0) are wrappers to binkw32.dll — RAD Game Tools SDK. Not ISI source code.

3. **Miles Sound System**: MSS functions (FUN_00406cc0, FUN_00406e50, FUN_004072e0, FUN_004060c0, FUN_004059f0, FUN_00405b50) wrap the Miles Sound System SDK (mss32.dll). Confirmed by AIL_ API calls and "Error: %s while setting Miles sound" string.

4. **Sound class lifecycle**: The Sound class has methods Enter/Exit/Init/Post/Restart/Setup — confirmed by cross-binary strings. This is the isiMotor Sound component pattern.

5. **HotPacket networking**: F1C uses HotPacket library (predecessor to OpenPlay). Strings "HotPacket_over_Winsock" and "<HotPacket::Winsock>" confirmed across all NASCAR/F1C binaries. This is the low-level Winsock wrapper that NetComm builds upon.

6. **NetComm component**: The NetComm class pairs with HOTPACKET for network transport. NetComm handles high-level session management (join/leave/sync), while HotPacket handles raw socket I/O. Both are documented in the file.

7. **rFactor vs F1C differences**: rFactor has many AudioBuffer/RFAudio/RFTrack/RFClip classes that don't exist in F1C. These are isiMotor2 additions. F1C uses simpler pattern: MSS handles play audio samples, custom mixer does 3D audio, no plugin-based audio routing.

8. **Network packet routing**: FUN_004b4a30 (3-bit class -> 5 queues) and FUN_004b54e0 (6-bit key -> handler list) form the HotPacket message dispatch layer. The 3-bit class field allows 8 message types (5 used), the 6-bit key allows 64 sub-types per class.
