# Address tier proposals (review only)

Fixed-rule proposals from a harvest. Nothing here is applied: a reviewer
decides and merges. FACT appears only as an R0 already-proven keep.

## Counts

| tier | code | data | vehicle_offset | total |
|---|---|---|---|---|
| FACT | 0 | 16 | 26 | 42 |
| CONFIRMED | 24 | 17 | 34 | 75 |
| CONFIRMED_PROPOSED | 1 | 17 | 20 | 38 |
| DERIVED | 115 | 49 | 22 | 186 |
| GUESS | 36 | 23 | 64 | 123 |
| needs_review |  |  |  | 199 |

## CONFIRMED_PROPOSED (38)

| kind | value | name | rule | evidence | context |
|---|---|---|---|---|---|
| code | 0x004EFAC0 | F1CAIEngineStopFn | R2 | hdrs=1 fp=1 tests=1 func=1 corpus=0 findings=0 products=1 | f1c_ida_decompiled/tools/sdk/f1c_ai_engine_stop.h:29 return f1c_ai_engine_stop_at(rd,vehicle,thread,authorized,(F1CAIEngineStopFn)0x004efac0u); |
| data | 0x005EA2C0 | SetupScenePtr | R3 | hdrs=2 fp=0 tests=2 func=- corpus=32 findings=1 products=1 | f1c_ida_decompiled/tools/sdk/f1c_pit_marker.h:41 object is directly based at 0x005EA2C0 (docs/52 section 3, OBSERVED live; |
| data | 0x005EA618 | PointerTableEntry | R3 | hdrs=1 fp=0 tests=0 func=- corpus=64 findings=4 products=2 | f1c_ida_decompiled/tools/sdk/f1c_pit_voice.h:72 return ((F1CPitVoiceInsert)0x00418560u)((void*)0x005EA618u,record)?1:0; |
| data | 0x005EC6D8 | PlayerDataPath | R3 | hdrs=1 fp=0 tests=1 func=- corpus=25 findings=0 products=2 | f1c_ida_decompiled/tools/sdk/f1c_replay_live_instances.h:15 #define F1C_LIVE_BASE 0x005EC6D8u |
| data | 0x007C569C | SessionType5 (5=server) | R3 | hdrs=1 fp=0 tests=1 func=- corpus=74 findings=0 products=3 | f1c_ida_decompiled/tools/sdk/f1c_session_guard.h:18 !read_at(0x007C569Cu, &g.game_state, sizeof(g.game_state)) \|\| |
| data | 0x007C56AC | EnableFlag | R3 | hdrs=1 fp=0 tests=1 func=- corpus=10 findings=0 products=3 | f1c_ida_decompiled/tools/sdk/f1c_session_guard.h:20 !read_at(0x007C56ACu, &g.paused, 1) \|\| |
| data | 0x007CC4C8 | CheckFlag | R3 | hdrs=1 fp=0 tests=1 func=- corpus=2 findings=0 products=2 | f1c_ida_decompiled/tools/sdk/f1c_replay_live_instances.h:14 #define F1C_LIVE_REQUEST 0x007CC4C8u |
| data | 0x007CD25C | GameModuleManager | R3 | hdrs=1 fp=0 tests=1 func=- corpus=53 findings=0 products=3 | f1c_ida_decompiled/tools/sdk/f1c_session_guard.h:22 !read_at(0x007CD25Cu, &manager, sizeof(manager)) \|\| !manager \|\| |
| data | 0x007CE258 | InitZeroFieldSet | R3 | hdrs=1 fp=0 tests=1 func=- corpus=5 findings=0 products=3 | f1c_ida_decompiled/tools/sdk/f1c_session_guard.h:21 !read_at(0x007CE258u, &g.player_out, sizeof(g.player_out)) \|\| |
| data | 0x007CE498 | AutoLoadConfigFile | R3 | hdrs=1 fp=0 tests=0 func=- corpus=24 findings=0 products=2 | f1c_ida_decompiled/tools/sdk/f1c_removal_options.h:10 static const uintptr_t addresses[3]={0x007CE498u+9696u+20u,0x007CE498u+9696u+24u,0x007D0A8Cu}; |
| data | 0x007CEF84 | PenaltiesEnabled | R3 | hdrs=1 fp=0 tests=0 func=- corpus=5 findings=0 products=1 | f1c_ida_decompiled/tools/sdk/f1c_race_penalty_issue.h:27 F1C_RACE_PENALTIES_ENABLED_ADDRESS=0x007CEF84u, |
| data | 0x007D0A8C | PitTimerFloat | R3 | hdrs=2 fp=0 tests=2 func=- corpus=1 findings=1 products=2 | f1c_ida_decompiled/tools/sdk/f1c_inverted_removal.h:43 return *(volatile float*)0x007d0a8cu; |
| data | 0x0083EE60 | RingBufferCount | R3 | hdrs=1 fp=0 tests=0 func=- corpus=27 findings=0 products=1 | f1c_ida_decompiled/tools/sdk/f1c_race_penalty_issue.h:25 F1C_RACE_EVENT_COUNT_ADDRESS=0x0083EE60u, |
| data | 0x008AAE64 | RingBufferWritePtr | R3 | hdrs=1 fp=0 tests=0 func=- corpus=23 findings=0 products=1 | f1c_ida_decompiled/tools/sdk/f1c_race_penalty_issue.h:26 F1C_RACE_EVENT_CURSOR_ADDRESS=0x008AAE64u, |
| data | 0x008AC38C | CurrentFontHandle | R3 | hdrs=1 fp=1 tests=4 func=- corpus=7 findings=0 products=2 | f1c_ida_decompiled/tools/sdk/f1c_runtime.h:124 return *(volatile int32_t *)(uintptr_t)0x008AC38Cu; |
| data | 0x008ACFEC | TrackMapEntryCount | R3 | hdrs=1 fp=0 tests=1 func=- corpus=2 findings=0 products=1 | f1c_ida_decompiled/tools/sdk/f1c_local_yellow.h:13 #define F1C_LOCAL_YELLOW_ZONE_COUNT 0x008ACFECu |
| data | 0x008ACFF0 | TrackDataArray | R3 | hdrs=1 fp=0 tests=1 func=- corpus=2 findings=0 products=1 | f1c_ida_decompiled/tools/sdk/f1c_local_yellow.h:12 #define F1C_LOCAL_YELLOW_ARRAY_POINTER 0x008ACFF0u |
| data | 0x008AFEA8 | InputAxisDeadZone | R3 | hdrs=1 fp=0 tests=0 func=- corpus=10 findings=0 products=2 | f1c_ida_decompiled/tools/sdk/f1c_pit_voice.h:81 double delay=f1c_pit_voice_front_delay(due,ids,*(volatile double*)0x008AFEA8u); |
| vehicle_offset | 0xC | Vehicle | R4 | hdrs=2 fp=1 tests=6 func=- corpus=0 findings=22 products=2 | f1c_ida_decompiled/tools/sdk/f1c_inverted_removal.h:4 /* Native sub_4F1FE0 receives vehicle+0x0c and a float delta (thiscall, |
| vehicle_offset | 0x14 | Rng | R4 | hdrs=1 fp=0 tests=1 func=- corpus=0 findings=14 products=2 | f1c_ida_decompiled/tools/sdk/f1c_ai_restart_pending.h:7 * vehicle+16752 with sim+10+(rng&0x14), compares it with current simulation |
| vehicle_offset | 0x58 | Uint32Max | R4 | hdrs=1 fp=0 tests=1 func=- corpus=0 findings=4 products=2 | f1c_ida_decompiled/tools/sdk/f1c_surface_contact.h:15 if(!read_at(vehicle+0x3674u+i*0xf8u,&hit,4)\|\|!hit\|\|hit>UINT32_MAX-0x58u)continue; |
| vehicle_offset | 0xB4 | This | R4 | hdrs=1 fp=0 tests=5 func=- corpus=0 findings=2 products=3 | f1c_ida_decompiled/tools/sdk/f1c_broker_abi.h:191 /* ABI 9: track-limits state at veh+0x40E8 (sub_4BCCC0's this+0xB4, |
| vehicle_offset | 0xF8 | I | R4 | hdrs=1 fp=0 tests=1 func=- corpus=0 findings=2 products=2 | f1c_ida_decompiled/tools/sdk/SURFACE_CONTACT_REVIEW_2026-09-08.md:4 consumer: vehicle+0x3674, four wheel-hit pointers stride0xF8; hit+0x54 material; |
| vehicle_offset | 0x180 | PitEntryLatch | R4 | hdrs=1 fp=0 tests=0 func=- corpus=0 findings=1 products=1 | f1c_ida_decompiled/tools/sdk/f1c_pit_struct.h:9 uint8_t pit_entry_latch;           /* 0x180 / vehicle+0x344C */ |
| vehicle_offset | 0x190 | ServiceReady | R4 | hdrs=1 fp=0 tests=0 func=- corpus=0 findings=2 products=1 | f1c_ida_decompiled/tools/sdk/f1c_pit_struct.h:14 uint8_t service_ready;             /* 0x190 / vehicle+0x345C */ |
| vehicle_offset | 0x1A0 | StopStartTime | R4 | hdrs=1 fp=0 tests=0 func=- corpus=0 findings=2 products=1 | f1c_ida_decompiled/tools/sdk/f1c_pit_struct.h:16 float stop_start_time;             /* 0x1A0 / vehicle+0x346C */ |
| vehicle_offset | 0x1A4 | StopEndTime | R4 | hdrs=1 fp=0 tests=0 func=- corpus=0 findings=2 products=1 | f1c_ida_decompiled/tools/sdk/f1c_pit_struct.h:17 float stop_end_time;               /* 0x1A4 / vehicle+0x3470 */ |
| vehicle_offset | 0x714 | Physics | R4 | hdrs=1 fp=0 tests=0 func=- corpus=0 findings=1 products=2 | f1c_ida_decompiled/tools/sdk/f1c_orientation.h:6 WheelContactTransform receives vehicle+12. Physics +0x714 = vehicle+0x720. |
| vehicle_offset | 0x720 | Vehicle | R4 | hdrs=1 fp=0 tests=0 func=- corpus=0 findings=1 products=2 | f1c_ida_decompiled/tools/sdk/f1c_orientation.h:6 WheelContactTransform receives vehicle+12. Physics +0x714 = vehicle+0x720. |
| vehicle_offset | 0x32CC | F1CVehicle | R4 | hdrs=1 fp=0 tests=0 func=- corpus=0 findings=7 products=1 | f1c_ida_decompiled/tools/sdk/f1c_pit_struct.h:1 /* Reviewed layout of the pit controller embedded at F1CVehicle+0x32CC. */ |
| vehicle_offset | 0x3984 | FuelLevel | R4 | hdrs=1 fp=0 tests=1 func=- corpus=0 findings=5 products=1 | f1c_ida_decompiled/tools/sdk/RESTART_FUEL_REVIEW_2026-09-21.md:11 body+14712 (vehicle+0x3984); role zero also updates the double player physics |
| vehicle_offset | 0x4034 | Vehicle | R4 | hdrs=1 fp=1 tests=4 func=- corpus=0 findings=2 products=1 | f1c_ida_decompiled/tools/sdk/f1c_runtime.h:114 return vehicle ? (void *)((uint8_t *)vehicle + 0x4034u) : NULL; |
| vehicle_offset | 0x40E8 | Veh | R4 | hdrs=1 fp=0 tests=5 func=- corpus=0 findings=1 products=3 | f1c_ida_decompiled/tools/sdk/f1c_broker_abi.h:191 /* ABI 9: track-limits state at veh+0x40E8 (sub_4BCCC0's this+0xB4, |
| vehicle_offset | 0x4174 | Uint32Max | R4 | hdrs=1 fp=0 tests=1 func=- corpus=0 findings=1 products=1 | f1c_ida_decompiled/tools/sdk/f1c_ai_restart_pending.h:16 if(!rd \|\| !vehicle \|\| vehicle>UINT32_MAX-0x4174u \|\| |
| vehicle_offset | 0x4420 | Vehicle | R4 | hdrs=1 fp=0 tests=1 func=- corpus=0 findings=1 products=1 | f1c_ida_decompiled/tools/sdk/f1c_ai_interaction.h:14 memcpy(&s.lateral_request,(const unsigned char*)vehicle+0x4420u,4); |
| vehicle_offset | 0x45E0 | Vehicle | R4 | hdrs=1 fp=0 tests=0 func=- corpus=0 findings=2 products=2 | f1c_ida_decompiled/tools/sdk/f1c_pit_strategy.h:9 *    the plan and zeroes the current-entry cursor at vehicle+0x45E0, so a car |
| vehicle_offset | 0x45FC | Vehicle | R4 | hdrs=1 fp=0 tests=1 func=- corpus=0 findings=1 products=1 | f1c_ida_decompiled/tools/sdk/f1c_ai_interaction.h:13 memcpy(&s.target_address,(const unsigned char*)vehicle+0x45FCu,4); |
| vehicle_offset | 0x48A8 | Vehicle | R4 | hdrs=1 fp=0 tests=1 func=- corpus=0 findings=7 products=2 | f1c_ida_decompiled/tools/sdk/f1c_vehicle_lifecycle.h:38 !f1c_lifecycle_read_at(rd,vehicle+0x48A8,&v.bay,4) \|\| |

## R1 reclassifications (data?) (1)

| kind | value | name | rule | evidence |
|---|---|---|---|---|
| code | 0x005BF9A0 | EVENT_TABLE | R1 | hdrs=0 fp=0 tests=0 func=0 corpus=0 findings=3 products=1 |

## Name conflicts (174)

| kind | value | proposed | existing | harvested names |
|---|---|---|---|---|
| code | 0x004144F0 | CommentaryEventQueue | CommentaryEventQueue (f1c_sdk_overrides) | DriverLookupFn, FN_DRIVER_LOOKUP, x004144D0u |
| code | 0x00424CD0 | AICommandMessageQueueDispatcher | AICommandMessageQueueDispatcher (f1c_sdk_overrides) | Calling, calls |
| code | 0x00424E70 | AIMainUpdate | AIMainUpdate (f1c_sdk_overrides) | AI0 |
| code | 0x0042AC70 | SetCallToBox | SetCallToBox (f1c_sdk_overrides) | Native, SetCallToBoxFn, void |
| code | 0x0042ACD0 | ParameterValueSetter | ParameterValueSetter (f1c_sdk_overrides) | ADDR_SET_MAXSPEED, AISpeedDeltaSetter, PARAMETER_VALUE_SETTER_ADDRESS, So, __thiscall, dispatches, governor, samples, set_maxspeed_fn |
| code | 0x0042BC80 | BuildActiveVehiclePointerArray | BuildActiveVehiclePointerArray (f1c_sdk_overrides) | A_REBUILD, BUILD_ACTIVE_VEHICLE_POINTER_ARRAY, BuildActiveVehiclePointerArrayFn, F1C_TARGET_PROBE_ADDRESS, x0040CDE0u |
| code | 0x0042C1A0 | DynMan_Init | DynMan_Init (f1c_sdk_overrides) | PRELOAD_ADDRESS |
| code | 0x0042C3B0 | DynMan_Restart | DynMan_Restart (f1c_sdk_overrides) | A_DYNRESTART, span |
| code | 0x004A5F20 | PitExitUnderRed | PitExitUnderRed (f1c_sdk_overrides) | handler |
| code | 0x004A6200 | PitStopReadyCheck | PitStopReadyCheck (f1c_sdk_overrides) | ADDR_READY_CHECK |
| code | 0x004BC2F0 | ConditionalFieldSetter | ConditionalFieldSetter (f1c_sdk_overrides) | Set, void |
| code | 0x004BFD90 | AIDriverCountSetup | AIDriverCountSetup (f1c_sdk_overrides) | A_AIDCS |
| code | 0x004C3F80 | VehicleLookupByName | VehicleLookupByName (f1c_sdk_overrides) | A_LOOKUP |
| code | 0x004C6960 | TeamIDSetter | TeamIDSetter (f1c_sdk_overrides) | A_TEAMID |
| code | 0x004C6C40 | VehgenScnFileLoader | VehgenScnFileLoader (f1c_sdk_overrides) | A_SCN |
| code | 0x004C6D90 | SceneRenderUpdate | SceneRenderUpdate (f1c_sdk_overrides) | A_RENDER, F1C_CAR_RESTART_ADDRESS, SCENE_RENDER_UPDATE, p, x0040DE60, x0042C409 |
| code | 0x004C78F0 | NationalityDriverInfoLoader | NationalityDriverInfoLoader (f1c_sdk_overrides) | A_NATLOAD |
| code | 0x004D0F00 | StewardZoneStateSet | StewardZoneStateSet (f1c_sdk_overrides) | F1C_LOCAL_YELLOW_SET_ADDRESS |
| code | 0x004EF5A0 | SessionStateTransition | SessionStateTransition (f1c_sdk_overrides) | A_STATE |
| code | 0x004EF7C0 | AIVehiclePathPositionTracking | AIVehiclePathPositionTracking (f1c_sdk_overrides) | F1C_PLACEMENT_SET, NATIVE_VEHICLE_POSE_APPLY, NativeVehiclePoseApplyFn, runtime_region_supported, void |
| code | 0x004EFB20 | F_3DTransformWithMatrixMultiplication | F_3DTransformWithMatrixMultiplication (f1c_sdk_overrides) | F1C_PLACEMENT_GET |
| code | 0x004F2320 | VehicleDynamicsStateReset | VehicleDynamicsStateReset (f1c_sdk_overrides) | F1C_MOTION_RESET |
| data | 0x005C329C | VehicleCount | VehicleCount (name_index) | ACTIVE_VEHICLE_COUNT_ADDRESS, COUNT, F1C_LIVE_COUNT, G_VEHCOUNT, HUD_POSITION_COUNT_ORIGINAL, SessionStateTransition, VEHICLE_COUNT, VEHICLE_COUNT_ADDR, VEH_COUNT, box, count, eax (+10 more) |
| data | 0x005C7530 | GlobalDataStructBase | GlobalDataStructBase (name_index) | HIGH_GEAR_TABLE_POINTER_ADDRESS, u32 |
| data | 0x005D6D60 | ScreenWidth | ScreenWidth (name_index) | HUD_SCREEN_W |
| data | 0x005D6D64 | ScreenWidth | ScreenWidth (name_index) | HUD_SCREEN_H, SCREEN_WIDTH_MINUS_48 |
| data | 0x005EA2C0 | SetupScenePtr | SetupScenePtr (name_index) | AI_DATABASE_BASE, SCENE_STRUCT, VEH_OBJ_PTR_GLOBAL, aiw, at, base, count, dim, direct, first, garages, lap (+9 more) |
| data | 0x005EA3FC | TrackRefSpeed | TrackRefSpeed (name_index) | YELLOW_TRACKLEN |
| data | 0x005EA404 | TrackRefValueArray | TrackRefValueArray (name_index) | x005EA400u |
| data | 0x005EA43C | SetupDirSuffix | SetupDirSuffix (name_index) | void |
| data | 0x005EA510 | SessionManager | SessionManager (name_index) | CAMERA_ACTION, CAMERA_MANAGER, action, void |
| data | 0x005EA560 | GlobalInstance_5EA560 | GlobalInstance_5EA560 (name_index) | DYNAMIC_MANAGER_OBJECT, DYNAMIC_MANAGER_PTR_GLOBAL, DelegationWrapperToFUN0040ed10, manager |
| data | 0x005EA618 | PointerTableEntry | PointerTableEntry (name_index) | BYTE, CM_CONTROLLER, CONTROLLER, CTRL, CTRL_OBJ, float, g_commentary_saved, int, queue, void |
| data | 0x005EC6D8 | PlayerDataPath | PlayerDataPath (name_index) | F1C_LIVE_BASE, PLAYER_VEH, V, VEH_BASE, a, x005EA510 |
| data | 0x005F0F74 | SeasonScoringDB2 | SeasonScoringDB2 (name_index) | passes |
| data | 0x00600000 | D3D_RenderState_Block | D3D_RenderState_Block (name_index) | AccessReasonEmptyDacl |
| data | 0x007C54DC | SpectatedVehicleSlot (was CurrentPlayerIndex) | SpectatedVehicleSlot (was CurrentPlayerIndex) (name_index) | SPECTATED_VEHICLE_SLOT_ADDRESS, int32_t |
| data | 0x007C54E0 | postProcessInput | postProcessInput (name_index) | VEH_OBJ_PTR_GLOBAL, YELLOW_VEH_PTR, ecx, veh, x008ACEE0u |
| data | 0x007C54E8 | PlayerVehiclePtr | PlayerVehiclePtr (name_index) | PLAYER_PTR, PLAYER_VEH_PTR, g_garage_escape_player, player, uint8_t, uintptr_t, veh, x007C54F0u |
| data | 0x007C54F0 | VehiclePtrArray | VehiclePtrArray (name_index) | ACTIVE_VEHICLE_POINTERS_ADDRESS, ARRAY, F1C_LIVE_ARRAY, VEHICLE_ARRAY, VEHICLE_ARRAY_ADDR, VEH_ARRAY, a, cur, d, full, iterates, li (+12 more) |
| data | 0x007C5694 | TimerOutputInt | TimerOutputInt (name_index) | tick_after, tick_before |
| data | 0x007C5698 | SessionTickCounter | SessionTickCounter (name_index) | window_after, window_before |
| data | 0x007C569C | SessionType5 (5=server) | SessionType5 (5=server) (name_index) | GAME_STATE, GAME_STATE_ADDR, GAME_STATE_ADDRESS, MultiplayerVehiclePlacement, a, g_monitor_game_state, gs, int, int32_t, read_at, restart_start_game_state, sets |
| data | 0x007C56A4 | SessionType | SessionType (name_index) | BROKER_PENALTY_SESSION_TYPE, G_SESSIONTYPE, SESSION_TYPE, SESSION_TYPE_ADDR, SESSION_TYPE_ADDRESS, a, if, int, phase, read_at, session_type, x007C54E8u |
| data | 0x007C56A8 | RacePhase | RacePhase (name_index) | BROKER_PENALTY_RACE_PHASE, G_RACEPHASE, RACE_PHASE, RACE_PHASE_ADDR, a, g_monitor_race_phase, int, int32_t, phase, race_phase, racing, read_at (+3 more) |
| data | 0x007C56AC | EnableFlag | EnableFlag (name_index) | BYTE, PAUSE_BYTE_ADDRESS, PAUSE_FLAG, Pause, a, char, g_aiw_player_game_paused, g_last_race_phase, g_monitor_paused, pause_byte, read_at, treats (+1 more) |
| data | 0x007C7428 | PlayerPhysicsObject | PlayerPhysicsObject (name_index) | PLAYER_PHYS_OBJ, TC_PHYS, WHEEL_BASE |
| data | 0x007C7430 | PoseInterpDuration | PoseInterpDuration (name_index) | ENG_TORQUE |
| data | 0x007C75C4 | GlobalSpeedTime (double) | GlobalSpeedTime (double) (name_index) | FUEL_NOW |
| data | 0x007C9081 | EngineRunningIgnitionFlag | EngineRunningIgnitionFlag (name_index) | ENG_RUNNING, ENG_RUNNING_B |
| data | 0x007C9174 | ParamBaseValueA | ParamBaseValueA (name_index) | OIL_TEMP_K |
| data | 0x007C91B4 | ParameterBaseCase1 | ParameterBaseCase1 (name_index) | WATER_K |
| data | 0x007C91D4 | EngineStressRate | EngineStressRate (name_index) | ENG_STRESS |
| data | 0x007C91DC | EngineLifeSeconds | EngineLifeSeconds (name_index) | ENG_LIFE |
| data | 0x007C920C | EngineDamageBank1_WhiteSmoke | EngineDamageBank1_WhiteSmoke (name_index) | ENG_BANK1 |
| data | 0x007C9214 | EngineDamageBank2_BlackSmoke | EngineDamageBank2_BlackSmoke (name_index) | ENG_BANK2 |
| data | 0x007C921C | EngineDamageBank3_Flames | EngineDamageBank3_Flames (name_index) | ENG_BANK3 |
| data | 0x007C9318 | PlayerCurrentGear | PlayerCurrentGear (name_index) | GEAR_CURRENT |
| data | 0x007C931C | PlayerTargetGear | PlayerTargetGear (name_index) | GEAR_TARGET |
| data | 0x007CB218 | InputDeviceCount | InputDeviceCount (name_index) | KEY_QUEUE_COUNT_ADDRESS, count |
| data | 0x007CB21C | InputActionMap | InputActionMap (name_index) | KEY_QUEUE_ADDRESS, at, queue |
| data | 0x007CC4C8 | CheckFlag | CheckFlag (name_index) | F1C_LIVE_REQUEST, int |
| data | 0x007CC4F4 | AudioMixerInt | AudioMixerInt (name_index) | AUDIO_SUSPEND_GATE_ADDRESS, NATIVE_PAUSE_ACTION_ADDRESS |
| data | 0x007CD204 | HUDMessageStripPtr | HUDMessageStripPtr (name_index) | HUD_OUTER_PTR, HUD_STRIP_POINTER_ADDRESS, MFH_OUTER, inner, this_, x007D05A0u |
| data | 0x007CD8C0 | GameCommandDispatchInterface | GameCommandDispatchInterface (name_index) | manager |
| data | 0x007CDE14 | CollisionSoundSurface2 | CollisionSoundSurface2 (name_index) | HUD_DRAW_SURFACE |
| data | 0x007CE24C | CriticalSection | CriticalSection (name_index) | sub_4A0250 |
| data | 0x007CE24D | SessionTransitionFlag | SessionTransitionFlag (name_index) | GlobalFlagSetter |
| data | 0x007CE250 | CollisionConfigVersion | CollisionConfigVersion (name_index) | int32_t, saved_ui_frame |
| data | 0x007CE254 | DisableHUDFlag | DisableHUDFlag (name_index) | char, if, saved_ui_active, uint8_t |
| data | 0x007CE258 | InitZeroFieldSet | InitZeroFieldSet (name_index) | FinishState, PLAYER_OUT, PLAYER_OUT_FLAG, RESTART_GATE, a, assertIn, clears, consumes, g_player_out_player_out, int, read_at, x007C569Cu |
| data | 0x007CE25D | GlobalFlagA0DA0 | GlobalFlagA0DA0 (name_index) | MINI_RESTART_FLAG, MINI_RESTART_FLAG_ADDRESS, RESTART_FLAG, char, reads, statement, uint8_t, unk_7CE24D, x007C569Cu, x007CE258u |
| data | 0x007CE25E | SessionRequestFlag | SessionRequestFlag (name_index) | FULL_RESTART_FLAG |
| data | 0x007CE25F | SessionPauseFlag | SessionPauseFlag (name_index) | session_pause_byte |
| data | 0x007CE2E8 | SessionCatchupFlag | SessionCatchupFlag (name_index) | PLAYER_OPTIONS_PTR, address |
| data | 0x007CE498 | AutoLoadConfigFile | AutoLoadConfigFile (name_index) | OPTIONS_BASE, PLAYER_OPTIONS_BASE, addresses, at, base, u, uintptr_t |
| data | 0x007CE6F4 | BrakeDiffSettings | BrakeDiffSettings (name_index) | TC_SWITCH |
| data | 0x007CE814 | QualifyingDSQEnabled | QualifyingDSQEnabled (name_index) | the |
| data | 0x007CEA5C | EngineWearMode (0/2/3) | EngineWearMode (0/2/3) (name_index) | on |
| data | 0x007CEF84 | PenaltiesEnabled | PenaltiesEnabled (name_index) | F1C_RACE_PENALTIES_ENABLED_ADDRESS |
| data | 0x007CF3C8 | TrackConditionState | TrackConditionState (name_index) | TRACK_COND, track_condition_state |
| data | 0x007D0308 | RaceActiveFlag | RaceActiveFlag (name_index) | RACE_ACTIVE, game_state, race_active |
| data | 0x007D0410 | ChampionshipMode | ChampionshipMode (name_index) | race_mode |
| data | 0x007D05A0 | Race_UriCheck_05A0 | Race_UriCheck_05A0 (name_index) | RESTART_TOTAL_LAPS_PTR, TOTAL_LAPS_PTR, VEH_BASE, int, race_phase, x005EC6D8u |
| data | 0x007D0798 | RaceSetupScaling | RaceSetupScaling (name_index) | RACE_DISTANCE_SCALE, address, scale, uintptr_t, void, x007D05A0u |
| data | 0x007D0A8C | PitTimerFloat | PitTimerFloat (name_index) | DWORD, REMOVAL_RUNTIME, VEHICLE_REMOVAL_RUNTIME, float, u |
| data | 0x00800000 | MMXFlag | MMXFlag (name_index) | AccessReasonNoGrant |
| data | 0x0083EE60 | RingBufferCount | RingBufferCount (name_index) | F1C_RACE_EVENT_COUNT_ADDRESS |
| data | 0x008AAE64 | RingBufferWritePtr | RingBufferWritePtr (name_index) | F1C_RACE_EVENT_CURSOR_ADDRESS |
| data | 0x008AAE74 | TrigLookup256 | TrigLookup256 (name_index) | TrigTableLookup_00447ab0, v36 |
| data | 0x008AB6E4 | ScoringGate | ScoringGate (name_index) | F1C_LIVE_MODE, F1C_REPLAY_MODE_ADDRESS, F1C_SC_REPLAY_MODE, SIM_FREEZE_GATE_ADDRESS, mode |
| data | 0x008AB6EC | ScoringDataPtr | ScoringDataPtr (name_index) | REPLAY_RECORDER_PTR_GLOBAL, recorder |
| data | 0x008AC38C | CurrentFontHandle | CurrentFontHandle (name_index) | G_DRVIDX, uintptr_t |
| data | 0x008AC394 | VehicleCatalog | VehicleCatalog (f1c_sdk_overrides) | G_ROSTER, OFF_ROSTER, ROSTER_BASE, roster, v6 |
| data | 0x008AC4C4 | InitStatus | InitStatus (name_index) | manager |
| data | 0x008ACEA0 | ScoringGridBase | ScoringGridBase (name_index) | SPECIALFX_BASE, SpecialFX_Init |
| data | 0x008ACEE0 | StewardObject | StewardObject (name_index) | STEWARD, YELLOW_STEWARD, count, table, x005EA2C0u |
| data | 0x008ACF8C | TotalRaceLaps | TotalRaceLaps (name_index) | LIVE_TOTAL_LAPS_PTR, TOTAL_LAPS_PTR, TOTAL_RACE_LAPS, dword_7C56A4, g_saved_total_laps, int, result, this, total_race_laps |
| data | 0x008ACF94 | SessionEndSeconds | SessionEndSeconds (f1c_sdk_overrides) | race_time_threshold |
| data | 0x008ACFB4 | IdleSpeedTarget | IdleSpeedTarget (name_index) | a2, convention, global, writes |
| data | 0x008ACFEC | TrackMapEntryCount | TrackMapEntryCount (name_index) | F1C_LOCAL_YELLOW_ZONE_COUNT |
| data | 0x008ACFF0 | TrackDataArray | TrackDataArray (name_index) | F1C_LOCAL_YELLOW_ARRAY_POINTER |
| data | 0x008AD254 | StateFlagPair | StateFlagPair (name_index) | G_BRANDDB |
| data | 0x008AD394 | AudioEmitter3 | AudioEmitter3 (name_index) | HUD_RENDER_OBJECT, a |
| data | 0x008AFE88 | CollisionGeometryHandle | CollisionGeometryHandle (name_index) | G_SCENE, scene |
| data | 0x008AFE98 | ScoringDefaultReturn | ScoringDefaultReturn (name_index) | frame_delta |
| data | 0x008AFEA0 | SessionClockSeconds | SessionClockSeconds (f1c_sdk_overrides) | G_SESSIONTIME, SESSION_TIME, SIMTIME, SV_SESSION_TIME, double, session_time, t |
| data | 0x008AFEA8 | InputAxisDeadZone | InputAxisDeadZone (name_index) | delay |
| data | 0x008AFEE8 | OnLineWetness | OnLineWetness (name_index) | EVENT_TABLE, ON_PATH_WETNESS, at, float, g_aiw_weather_on_wetness, if, online_wetness, read_at, v5, v8, wetness, x005BF9A0 |
| data | 0x008AFEEC | OffLineWetness | OffLineWetness (name_index) | OFF_PATH_WETNESS, g_aiw_weather_off_wetness, offline_wetness, x008AFEE8, x008AFEE8u |
| data | 0x008AFEF0 | AmbientTempC | AmbientTempC (name_index) | SizeOfImage, ambient_temp_c |
| data | 0x008AFEF4 | TrackTempC | TrackTempC (name_index) | track_temp_c |
| data | 0x008B8DC8 | RenderDevicePtr | RenderDevicePtr (name_index) | HUD_RENDER_TARGET |
| vehicle_offset | 0x0 | postProcessInput | postProcessInput (name_index) | vehicle |
| vehicle_offset | 0x1C | PhysX | PhysX (name_index) | OFF_PHYSX, OFF_RENDERX, the, veh |
| vehicle_offset | 0x20 | PhysY | PhysY (name_index) | OFF_PHYSY, OFF_PHYS_Y, OFF_RENDERY, veh |
| vehicle_offset | 0x24 | PhysZ | PhysZ (name_index) | OFF_PHYSZ, OFF_RENDERZ |
| vehicle_offset | 0xA0 | EngineAngVel | EngineAngVel (name_index) | OFF_ANGVEL |
| vehicle_offset | 0x6F0 | RenderObject | RenderObject (name_index) | OFF_GFX, vehicle |
| vehicle_offset | 0x744 | coordinatesInTrack.x (replay) | coordinatesInTrack.x (replay) (name_index) | OFF_PHYSX, veh, xC |
| vehicle_offset | 0x74C | coordinatesInTrack.y (replay) | coordinatesInTrack.y (replay) (name_index) | OFF_PHYSZ |
| vehicle_offset | 0xCD4 | FrontWingRecordPtr | FrontWingRecordPtr (name_index) | OFF_FRONTWING_PTR, veh |
| vehicle_offset | 0xD14 | FrontWingIntactFlag | FrontWingIntactFlag (name_index) | OFF_FRONTWING_FLAG, OFF_FWFLAG, veh |
| vehicle_offset | 0xD18 | RearWingRecordPtr | RearWingRecordPtr (name_index) | OFF_REARWING_PTR, veh |
| vehicle_offset | 0xD58 | RearWingIntactFlag | RearWingIntactFlag (f1c_sdk_overrides) | OFF_REARWING_FLAG, OFF_RWFLAG, veh |
| vehicle_offset | 0x105D | DriverModelVisible | DriverModelVisible (name_index) | OFF_DRIVERVIS, OFF_DRIVER_VISIBLE, OFF_MODELVIS, VEH_BASE, VEH_OFF_DRIVER_VIS, veh |
| vehicle_offset | 0x32C8 | WearTickGate__was__slot_live_marker_ | WearTickGate__was__slot_live_marker_ (f1c_sdk_overrides) | F1C_REPLAY_VEHICLE_STATE_OFF, OFF_ACTIVE, OFF_LIVE, OFF_MODE, OFF_SLOTLIVE, OFF_SLOT_LIVE, g_player_out_role, i, this, veh, vehicle |
| vehicle_offset | 0x32D4 | ActivePitCrewSetPtr | ActivePitCrewSetPtr (f1c_sdk_overrides) | OFF_CREW, veh, vehicle |
| vehicle_offset | 0x344C | PitEntryLatch | PitEntryLatch (f1c_sdk_overrides) | OFF_ENTRY, OFF_ENTRYLATCH, OFF_INPIT, veh, vehicle |
| vehicle_offset | 0x3450 | PitStatus | PitStatus (f1c_sdk_overrides) | OFF_AI_MODE, OFF_PITTING, OFF_PIT_STATUS, OFF_STATUS, PIT_STATUS, VEH_BASE, pit, pit_status, veh, vehicle |
| vehicle_offset | 0x345C | PitServiceReadyLatch | PitServiceReadyLatch (f1c_sdk_overrides) | OFF_READY, OFF_SRVREADY, OFF_SVCRDY, OFF_SVCREADY, veh, vehicle |
| vehicle_offset | 0x346C | PitStopStartTime | PitStopStartTime (f1c_sdk_overrides) | OFF_SRV_START, OFF_START, srv_start, stopStart, vehicle |
| vehicle_offset | 0x3470 | PitStopEndTime | PitStopEndTime (f1c_sdk_overrides) | OFF_END, OFF_ENDT, OFF_STOPEND, PIT_STOP_END, g_hold_stop, stopEnd, veh, vehicle |
| vehicle_offset | 0x34A0 | pitTime[0] | pitTime[0] (name_index) | OFF_TIRE_END |
| vehicle_offset | 0x34E0 | WorldPositionX | WorldPositionX (f1c_sdk_overrides) | OFF_BODYX, OFF_PHYSX, OFF_POSX, OFF_POS_X, OFF_YAWMAT, car_x, px, veh, vehicle, world_x, x34BC |
| vehicle_offset | 0x34E4 | WorldPositionY | WorldPositionY (f1c_sdk_overrides) | OFF_BODYY, OFF_POSY, OFF_POS_Y, py, veh, world_y, x34E0 |
| vehicle_offset | 0x34E8 | WorldPositionZ | WorldPositionZ (f1c_sdk_overrides) | OFF_BODYZ, OFF_POSZ, OFF_POS_Z, car_z, pz, veh, world_z, x34E4 |
| vehicle_offset | 0x34F0 | RenderX | RenderX (name_index) | OFF_YAWBODY, veh |
| vehicle_offset | 0x34F8 | RenderZ | RenderZ (name_index) | veh |
| vehicle_offset | 0x357C | ThrottleFactor | ThrottleFactor (name_index) | throttle_factor |
| vehicle_offset | 0x3584 | BrakeFactor | BrakeFactor (name_index) | brake_factor |
| vehicle_offset | 0x397C | tireChoice | tireChoice (name_index) | OFF_TIREIDX |
| vehicle_offset | 0x3984 | FuelLevel | FuelLevel (name_index) | OFF_FUEL, OFF_FUELLEVEL, veh, vehicle |
| vehicle_offset | 0x39A0 | EngineRPM | EngineRPM (name_index) | ENG_RPM_LIVE, OFF_ENGINE_RPM, OFF_ENG_ANGVEL, OFF_RPM, VEH_BASE, engine_rpm, g_monitor_jos_rpm, rpm, veh, vehicle |
| vehicle_offset | 0x39A4 | EngineMaxRPM | EngineMaxRPM (name_index) | UINT32_MAX, engine_max_rpm |
| vehicle_offset | 0x39FC | CurrentGear | CurrentGear (name_index) | OFF_GEAR, current_gear, veh |
| vehicle_offset | 0x3D6C | carConditions | carConditions (name_index) | OFF_CARC, OFF_CARCOND, OFF_CAR_CONDITIONS, OFF_CONDITIONS, VEH_OFF_CARC, car_conditions, g_monitor_jos_damage, veh |
| vehicle_offset | 0x3D70 | EngineLifeRemaining | EngineLifeRemaining (name_index) | OFF_ENGINE_LIFE, OFF_ENGLIFE, OFF_LIFE_SLOTS, g_monitor_jos_engine_life, veh, vehicle |
| vehicle_offset | 0x3D74 | BrakesLifeRemaining | BrakesLifeRemaining (name_index) | OFF_BRAKE_LIFE, veh, vehicle |
| vehicle_offset | 0x3D78 | GearboxLifeRemaining | GearboxLifeRemaining (name_index) | OFF_GEARBOX_LIFE, g_monitor_jos_gearbox_life, veh, vehicle |
| vehicle_offset | 0x3D7C | SuspensionLifeRemaining | SuspensionLifeRemaining (name_index) | OFF_SUSPENSION_LIFE, OFF_SUSP_LIFE, g_monitor_jos_suspension_life, veh, vehicle |
| vehicle_offset | 0x403C | lapNumber | lapNumber (name_index) | OFF_CURRENTLAP, OFF_LAP, OFF_LAPNUM, OFF_LAPNUMBER, g_player_out_lap, lap_number, veh |
| vehicle_offset | 0x4058 | plannedPositionAtStart | plannedPositionAtStart (f1c_sdk_overrides) | OFF_POSSTART, OFF_QUALPOS, V_I32, g_player_out_qualpos, veh |
| vehicle_offset | 0x4060 | position | position (f1c_sdk_overrides) | OFF_POS, OFF_POSITION, OFF_POSMAX, OFF_RACEPOS, current, g_player_out_racepos, race_position, rp, veh |
| vehicle_offset | 0x4064 | FinishState | FinishState (name_index) | OFF_FINISH, OFF_FINISHSTATE, VEH_OFF_FINISH, fin, finish, finish_state, veh, vehicle |
| vehicle_offset | 0x4068 | ReasonCode | ReasonCode (name_index) | OFF_REASON, OFF_REASONCODE, REASON_CODE_E, VEH_OFF_REASON, g_player_out_reason, reason_code, veh |
| vehicle_offset | 0x409C | bestLap | bestLap (name_index) | best_lap_time |
| vehicle_offset | 0x4354 | CurrentWaypointPtr | CurrentWaypointPtr (name_index) | OFF_CURWP, veh |
| vehicle_offset | 0x4410 | RetiredFlag | RetiredFlag (name_index) | OFF_RETIRED, OFF_RETIREDFLAG, g_monitor_jos_retired, ret, retired, veh, vehicle |
| vehicle_offset | 0x44F8 | TrackAggressionEffective | TrackAggressionEffective (f1c_sdk_overrides) | OFF_AGGRO |
| vehicle_offset | 0x4510 | driverStatus | driverStatus (name_index) | OFF_AI_STATE, OFF_DRIVERSTATUS, OFF_DRVSTAT |
| vehicle_offset | 0x4534 | timeOfNextExit | timeOfNextExit (name_index) | OFF_PIT_TIMER_GATE |
| vehicle_offset | 0x4538 | MaxSpeed | MaxSpeed (f1c_sdk_overrides) | OFF_MAXSPEED, veh |
| vehicle_offset | 0x4548 | PitLaneRouteFlag | PitLaneRouteFlag (f1c_sdk_overrides) | laneMode |
| vehicle_offset | 0x454C | CallToBox | CallToBox (f1c_sdk_overrides) | OFF_CALL, OFF_CALLBOX, OFF_CALLTOBOX, OFF_CALL_TO_BOX, call_to_box, observed, veh, vehicle |
| vehicle_offset | 0x4550 | WaypointSetSelector | WaypointSetSelector (name_index) | OFF_LANEMODE, veh |
| vehicle_offset | 0x4570 | elapsedTime | elapsedTime (name_index) | elapsed_time |
| vehicle_offset | 0x45F4 | AIControlFlag | AIControlFlag (name_index) | ActiveFlag, OFF_ACTIVE, OFF_ACTIVEFLAG, OFF_AICTRL, ai_control, g_monitor_jos_active, g_player_out_active_flag, veh, vehicle |
| vehicle_offset | 0x4620 | DriverName | DriverName (name_index) | OFF_DRIVERNAME, OFF_NAME, as, row, src, veh |
| vehicle_offset | 0x4714 | VehiclePath | VehiclePath (name_index) | vehicle |
| vehicle_offset | 0x4894 | VehicleSceneSlotId | VehicleSceneSlotId (f1c_sdk_overrides) | OFF_TEAMID, id, veh, x4898 |
| vehicle_offset | 0x4898 | VehicleRosterIndex | VehicleRosterIndex (f1c_sdk_overrides) | OFF_ROSTER, index, veh, vehicle |
| vehicle_offset | 0x489C | DriverID | DriverID (name_index) | OFF_DRVIDX, driver_id, veh, x4898 |
| vehicle_offset | 0x48A4 | PitTeamIndex | PitTeamIndex (f1c_sdk_overrides) | OFF_NATIVE_GARAGE_PIT, OFF_NODEIDX, OFF_PITTEAM, OFF_TEAM, nodeIdx, ordinal, pit, veh, vehicle |

## Top 30 R5 DERIVED by product count (of 186)

| kind | value | name | products | evidence |
|---|---|---|---|---|
| code | 0x004A0FD0 | RESTART_GATE_ADDRESS | game_update_broker, game_update_broker_r2_control_20260929, mechanical_failures, sdk, suspension_failure | hdrs=1 fp=0 tests=5 func=1 corpus=0 findings=0 products=5 |
| code | 0x00417640 | Functions | game_update_broker, game_update_broker_r2_control_20260929, pitstop_modding, sdk | hdrs=1 fp=0 tests=5 func=1 corpus=0 findings=0 products=4 |
| code | 0x0042C690 | anchor | game_update_broker, game_update_broker_r2_control_20260929, mechanical_failures, suspension_failure | hdrs=0 fp=0 tests=0 func=1 corpus=0 findings=0 products=4 |
| code | 0x00404B60 |  | game_update_broker, game_update_broker_r2_control_20260929, pitstop_modding | hdrs=0 fp=0 tests=0 func=1 corpus=0 findings=0 products=3 |
| code | 0x0043C250 | Q3 | game_update_broker, game_update_broker_r2_control_20260929, mechanical_failures | hdrs=0 fp=0 tests=0 func=1 corpus=0 findings=0 products=3 |
| code | 0x0046BF10 | Before | game_update_broker, game_update_broker_r2_control_20260929, sdk | hdrs=1 fp=0 tests=0 func=1 corpus=0 findings=0 products=3 |
| code | 0x00475050 | void | game_update_broker, game_update_broker_r2_control_20260929, pitstop_modding | hdrs=0 fp=0 tests=0 func=0 corpus=0 findings=0 products=3 |
| code | 0x004A115C | void | game_update_broker, game_update_broker_r2_control_20260929, pitstop_modding | hdrs=0 fp=0 tests=0 func=0 corpus=0 findings=0 products=3 |
| code | 0x004AFFF8 | required_image_size | game_update_broker, game_update_broker_r2_control_20260929, pitstop_modding | hdrs=0 fp=0 tests=0 func=0 corpus=0 findings=0 products=3 |
| code | 0x004BACD0 | twin | game_update_broker, game_update_broker_r2_control_20260929, pitstop_modding | hdrs=0 fp=0 tests=0 func=0 corpus=0 findings=0 products=3 |
| code | 0x004BCCC0 | x40E8 | game_update_broker, pitstop_modding, sdk | hdrs=1 fp=0 tests=5 func=1 corpus=0 findings=0 products=3 |
| code | 0x0059D7EA | HIGH_GEAR_LAYOUT_PROBE_ADDRESS | game_update_broker, game_update_broker_r2_control_20260929, pitstop_modding | hdrs=0 fp=0 tests=0 func=0 corpus=0 findings=0 products=3 |
| data | 0x005EA43C | SetupDirSuffix | game_update_broker, game_update_broker_r2_control_20260929, pitstop_modding | hdrs=0 fp=0 tests=0 func=- corpus=15 findings=0 products=3 |
| data | 0x007CC4F4 | AudioMixerInt | game_update_broker, game_update_broker_r2_control_20260929, pitstop_modding | hdrs=0 fp=0 tests=0 func=- corpus=1 findings=0 products=3 |
| data | 0x007CD8C0 | GameCommandDispatchInterface | game_update_broker, game_update_broker_r2_control_20260929, pitstop_modding | hdrs=0 fp=0 tests=0 func=- corpus=54 findings=0 products=3 |
| data | 0x007CE25D | GlobalFlagA0DA0 | esc_pause_menu, game_update_broker_r2_control_20260929, red_flag | hdrs=0 fp=0 tests=0 func=- corpus=2 findings=0 products=3 |
| data | 0x008AC4C4 | InitStatus | game_update_broker, game_update_broker_r2_control_20260929, red_flag | hdrs=0 fp=0 tests=0 func=- corpus=25 findings=0 products=3 |
| data | 0x008ACFB4 | IdleSpeedTarget | full_safety_car, game_update_broker, game_update_broker_r2_control_20260929 | hdrs=0 fp=0 tests=0 func=- corpus=8 findings=1 products=3 |
| vehicle_offset | 0x348C | OFF_FUELFLAG | full_safety_car_sdk_lab, pitstop_modding, synthetic_pitstop | hdrs=0 fp=0 tests=0 func=- corpus=0 findings=5 products=3 |
| vehicle_offset | 0x3490 | OFF_TIREFLAG | full_safety_car_sdk_lab, pitstop_modding, synthetic_pitstop | hdrs=0 fp=0 tests=0 func=- corpus=0 findings=5 products=3 |
| vehicle_offset | 0x34BC | veh | native_safety_car, native_safety_car_ntmode, synthetic_pitstop | hdrs=0 fp=0 tests=0 func=- corpus=0 findings=5 products=3 |
| code | 0x00400000 | TargetImageBase | red_flag, sdk | hdrs=1 fp=1 tests=0 func=0 corpus=0 findings=0 products=2 |
| code | 0x00404F30 | void | game_update_broker, game_update_broker_r2_control_20260929 | hdrs=0 fp=0 tests=0 func=1 corpus=0 findings=0 products=2 |
| code | 0x004144D0 | F1CPitVoiceInit | red_flag, sdk | hdrs=1 fp=0 tests=0 func=1 corpus=0 findings=1 products=2 |
| code | 0x00418560 | F1CPitVoiceInsert | red_flag, sdk | hdrs=1 fp=0 tests=0 func=1 corpus=0 findings=3 products=2 |
| code | 0x00429960 | Stops | red_flag, sdk | hdrs=1 fp=0 tests=0 func=1 corpus=0 findings=0 products=2 |
| code | 0x00442060 | __thiscall | mechanical_failures, suspension_failure | hdrs=0 fp=0 tests=0 func=1 corpus=0 findings=0 products=2 |
| code | 0x004441F0 | HOOK_SITE | mechanical_failures, suspension_failure | hdrs=0 fp=0 tests=0 func=1 corpus=0 findings=0 products=2 |
| code | 0x0045B840 | renderer | game_update_broker, game_update_broker_r2_control_20260929 | hdrs=0 fp=0 tests=0 func=1 corpus=0 findings=0 products=2 |
| code | 0x0045BB00 | sizer | game_update_broker, game_update_broker_r2_control_20260929 | hdrs=0 fp=0 tests=0 func=1 corpus=0 findings=0 products=2 |
