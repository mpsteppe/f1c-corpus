# Address harvest summary

Read-only collection of address-like values already used by the
project. No trust tier is assigned here; a reviewer decides tiers.

## Counts

| kind | total | in a store (FACT/CONFIRMED) | known, unproven | not in any store | name conflicts |
|---|---|---|---|---|---|
| code | 176 | 24 | 0 | 152 | 22 |
| data | 122 | 33 | 59 | 30 | 91 |
| vehicle_offset | 166 | 60 | 3 | 103 | 61 |

## Top 40 not-in-any-store entries

### code

| value | names | files | hits | first context |
|---|---|---|---|---|
| 0x004F93E0 | STOPPED_SPEED, damaged, predicate, predicates, scanner | 878 | 2561 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:8213 |
| 0x005BF9A0 | CM_EVENT_TABLE, EVENT_TABLE, EVTBL, x005EA618 | 799 | 799 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:332 |
| 0x004144D0 | F1CPitVoiceInit, FN_STRUCT_INIT, SESSION_TICK_UPDATE, StructInitFn | 734 | 871 | f1c_ida_decompiled/tools/sdk/f1c_pit_voice.h:70 |
| 0x00418560 | F1CPitVoiceInsert, FN_INSERT_ENTRY, IDTE_ADDR, InsertEntryFn, __thiscall, and, game, ret, x004144F0u | 733 | 4211 | f1c_ida_decompiled/tools/sdk/f1c_pit_voice.h:72 |
| 0x004D1730 | functions, in, signal, through | 720 | 2391 | f1c_ida_decompiled/tools/sdk/LOCAL_YELLOW_REVIEW_2026-09-08.md:5 |
| 0x004F95D0 | quickie, s, split | 719 | 1833 | development/mods/full_safety_car/trials/v0.10.88_dq_wording/safety_car_hardened_rf70r2.private.c:1661 |
| 0x00403CD0 | SingleFunctionDispatch_10e0, and, sub_4D10E0, thunk, x4058, x4D10E0 | 711 | 2941 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:3445 |
| 0x0049BAD0 | ADDR_YELLOW_PRED, Calling, FN_NATIVE_YELLOW, at, calibrated, is, s | 710 | 2589 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:1159 |
| 0x0049D4C0 | and, updater | 710 | 710 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:1704 |
| 0x004D10E0 | A_GRIDPLACE, PLAYER_GRID_PLACE_ENTRY, via, with | 644 | 1756 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:2269 |
| 0x004F9040 | caller | 557 | 2228 | development/mods/full_safety_car/trials/v0.10.88_dq_wording/safety_car_hardened_rf70r2.private.c:1645 |
| 0x00418563 |  | 557 | 557 | development/mods/full_safety_car/trials/v0.10.88_dq_wording/safety_car_hardened_rf70r2.private.c:4694 |
| 0x00418564 |  | 557 | 557 | development/mods/full_safety_car/trials/v0.10.88_dq_wording/safety_car_hardened_rf70r2.private.c:4695 |
| 0x0041B3C0 | sub_4D1730 | 557 | 557 | development/mods/full_safety_car/trials/v0.10.88_dq_wording/safety_car_hardened_rf70r2.private.c:3919 |
| 0x004B99F0 | by | 557 | 557 | development/mods/full_safety_car/trials/v0.10.88_dq_wording/safety_car_hardened_rf70r2.private.c:1656 |
| 0x0051C630 | product | 557 | 557 | development/mods/full_safety_car/trials/v0.10.88_dq_wording/safety_car_hardened_rf70r2.private.c:1684 |
| 0x0042CE30 | SessionTypeNameLookup | 555 | 555 | development/mods/full_safety_car/trials/v0.10.88_dq_wording/safety_car_hardened_rf70r2.private.c:959 |
| 0x0054FA00 | loop | 553 | 553 | development/mods/full_safety_car/trials/v0.10.88_dq_wording/safety_car_hardened_rf70r2.private.c:9217 |
| 0x0054FA06 | at | 553 | 553 | development/mods/full_safety_car/trials/v0.10.88_dq_wording/safety_car_hardened_rf70r2.private.c:9219 |
| 0x004FA8E0 |  | 222 | 222 | development/mods/full_safety_car/trials/v0.10.66_private_friend_20260922/previous-sc54.c:6118 |
| 0x004FAEF0 | sub_4FA8E0 | 222 | 222 | development/mods/full_safety_car/trials/v0.10.66_private_friend_20260922/previous-sc54.c:6118 |
| 0x004FAFF0 | sub_4FAEF0 | 222 | 222 | development/mods/full_safety_car/trials/v0.10.66_private_friend_20260922/previous-sc54.c:6118 |
| 0x004F1FE0 | Native, OFF_REMOVAL_ACC, from, path, storage, void | 157 | 159 | f1c_ida_decompiled/tools/sdk/f1c_inverted_removal.h:4 |
| 0x0042C409 | CALL_SITE, call_site_targets, rel, void | 155 | 179 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:662 |
| 0x0042D1E1 | TICK_CALL_SITE, call_site_targets, rel, void | 155 | 179 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:665 |
| 0x004C6B60 | SESSION_TICK_UPDATE, p, x0042D1E1 | 155 | 161 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:666 |
| 0x004B7500 | REPLAY_FINALIZE_ORIGINAL, uintptr_t, x004C6B60 | 149 | 151 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:668 |
| 0x004D3083 | GRID_CAMERA_CALL_SITE, call_site_targets, uintptr_t, void | 141 | 165 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:375 |
| 0x0040DE60 | GRID_CAMERA_ORIGINAL, p, uintptr_t, x0042ACD0u, x004D3083 | 141 | 147 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:376 |
| 0x004A6FE0 | byte_7CE498 | 141 | 141 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:338 |
| 0x0040CDE0 | game_action_state_fn | 139 | 274 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:757 |
| 0x00400000 | AccessReasonOwnership, F1C_TARGET_IMAGE_BASE, ImageBase, base, x008AFEF0u | 136 | 408 | f1c_ida_decompiled/tools/sdk/f1c_target.h:5 |
| 0x004C6E80 | Native, and, assertNotIn, clear_site, g, inspect, native, site | 128 | 220 | f1c_ida_decompiled/tools/sdk/LLM_WORKFLOW_REVIEW_2026-09-30.md:16 |
| 0x004B9890 | A_REPLAY, BEFORE, after, and, before, replay, stale, unlike, while | 119 | 230 | f1c_ida_decompiled/tools/sdk/f1c_live_replay.h:10 |
| 0x0049C670 | at | 104 | 104 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:523 |
| 0x00411330 | by, spawned | 91 | 151 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:7351 |
| 0x0049C6D0 | A_POSDISPLAY, HUD_POSITION_COUNT_LOAD, sibling | 89 | 175 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:574 |
| 0x004D1140 | NATIVE_GARAGE_POSE_READ | 81 | 81 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:4521 |
| 0x004BA6C0 | A_2PATH, F1C_LIVE_DISPATCH | 78 | 85 | f1c_ida_decompiled/tools/sdk/f1c_replay_live_instances.h:12 |
| 0x004FA1A0 | s | 68 | 68 | development/mods/full_safety_car/trials/v0.10.41_removal_owner/safety_car_guardrails.c:6338 |

### data

| value | names | files | hits | first context |
|---|---|---|---|---|
| 0x0075CBB0 | ONE, sub_4F9040 | 557 | 1114 | development/mods/full_safety_car/trials/v0.10.88_dq_wording/safety_car_hardened_rf70r2.private.c:1649 |
| 0x005FD344 | count | 557 | 557 | development/mods/full_safety_car/trials/v0.10.88_dq_wording/safety_car_hardened_rf70r2.private.c:1122 |
| 0x00767310 | sub_4F9040 | 557 | 557 | development/mods/full_safety_car/trials/v0.10.88_dq_wording/safety_car_hardened_rf70r2.private.c:1651 |
| 0x005EA400 | x005EA3FCu | 135 | 135 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:768 |
| 0x007C90C4 | ENG_RPM | 26 | 26 | development/mods/mechanical_failures/dll/engine_failure.c:405 |
| 0x007C90EC | ENG_IDLE_RPM | 26 | 26 | development/mods/mechanical_failures/dll/engine_failure.c:406 |
| 0x005C0000 | memory, void | 22 | 39 | development/mods/full_safety_car/trials/v0.10.62_callback_cost/benchmark-1789810042316733300/sc62.c:11 |
| 0x007C9104 | ENG_REV_LIMIT, REV_LIM | 19 | 21 | development/mods/mechanical_failures/dll/engine_failure.c:906 |
| 0x007C917C | OIL_LIMIT_K | 13 | 13 | development/mods/mechanical_failures/dll/engine_failure.c:905 |
| 0x007C91BC | RAD_BASE | 11 | 11 | development/mods/mechanical_failures/dll/engine_failure.c:2118 |
| 0x007C91C4 | RAD_AIR | 11 | 11 | development/mods/mechanical_failures/dll/engine_failure.c:2119 |
| 0x007C8C50 | RAD_AIR_K0 | 9 | 9 | development/mods/mechanical_failures/dll/engine_failure.c:2125 |
| 0x007C8C58 | RAD_AIR_K1 | 9 | 9 | development/mods/mechanical_failures/dll/engine_failure.c:2126 |
| 0x005C01F4 | IMAGE_BASE_VA, commentary | 6 | 6 | development/mods/player_damage_commentary/source.c:154 |
| 0x005C0208 | commentary | 5 | 5 | development/mods/player_damage_commentary/source.c:156 |
| 0x005C021C | commentary | 5 | 5 | development/mods/player_damage_commentary/source.c:150 |
| 0x005C0230 | commentary | 5 | 5 | development/mods/player_damage_commentary/source.c:158 |
| 0x005C0244 | commentary | 5 | 5 | development/mods/player_damage_commentary/source.c:160 |
| 0x005C0258 | commentary | 5 | 5 | development/mods/player_damage_commentary/source.c:152 |
| 0x007C0000 | void | 3 | 4 | development/mods/full_safety_car/trials/v0.10.50_crash_20260914/hud_probe_r3.c:6 |
| 0x007C90B4 | REV_SHIFT | 3 | 3 | development/mods/mechanical_failures/dll/engine_failure.c:1672 |
| 0x007C910C | REV_LO | 3 | 3 | development/mods/mechanical_failures/dll/engine_failure.c:1670 |
| 0x007C9114 | REV_HI | 3 | 3 | development/mods/mechanical_failures/dll/engine_failure.c:1671 |
| 0x008A0000 | void | 3 | 3 | development/mods/full_safety_car/trials/v0.10.50_crash_20260914/hud_probe_r3.c:7 |
| 0x00700000 | AccessReasonNoSD | 2 | 2 | development/mods/red_flag/trials/2026-09-07/changelog-audit/new.pre.c:4391 |
| 0x005C02D0 | commentary | 1 | 1 | development/mods/player_retire_commentary/source.c:60 |
| 0x005C02E4 | commentary | 1 | 1 | development/mods/player_retire_commentary/source.c:58 |
| 0x005C02F8 | commentary | 1 | 1 | development/mods/player_retire_commentary/source.c:62 |
| 0x005C0550 | commentary | 1 | 1 | development/mods/player_dq_commentary/source.c:56 |
| 0x005FA000 | F1C_TARGET_IMAGE_SIZE | 1 | 1 | f1c_ida_decompiled/tools/sdk/f1c_target.h:9 |

### vehicle_offset

| value | names | files | hits | first context |
|---|---|---|---|---|
| 0x48A8 | OFF_NATIVE_GARAGE_ORDINAL, OFF_SUBIDX, ordinal, subIdx, veh, vehicle | 740 | 1381 | f1c_ida_decompiled/tools/sdk/f1c_vehicle_lifecycle.h:38 |
| 0x4040 | OFF_PIT, OFF_PITSTATE, g_monitor_jos_pitstate, g_player_out_pitstate, pit, veh | 737 | 748 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:409 |
| 0x4044 | OFF_LAPDIST, best_blocking_lapdist, veh | 728 | 730 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:488 |
| 0x40E8 | OFF_OFF_TRACK, g_aiw_player_off_track, i, off_track, veh, vehicle | 653 | 709 | f1c_ida_decompiled/tools/sdk/f1c_broker_abi.h:191 |
| 0x58 | OFF_VELX, UINT32_MAX, not, veh | 575 | 1133 | f1c_ida_decompiled/tools/sdk/f1c_surface_contact.h:15 |
| 0x10 | crew, entry, x0008 | 574 | 1131 | development/mods/pitstop_modding/release_candidates/pitstop_failures-v1.0.5-rc.2/src/pit_commentary.c:464 |
| 0x5C | OFF_VELY, x58 | 574 | 575 | development/mods/full_safety_car/trials/v0.10.88_dq_wording/safety_car_hardened_rf70r2.private.c:1052 |
| 0x60 | OFF_VELZ, x5C | 574 | 575 | development/mods/full_safety_car/trials/v0.10.88_dq_wording/safety_car_hardened_rf70r2.private.c:1053 |
| 0x48A0 | OFF_TEAMIDX, veh | 572 | 1686 | development/mods/full_safety_car/trials/v0.10.88_dq_wording/safety_car_hardened_rf70r2.private.c:4664 |
| 0x4048 | NOT | 557 | 557 | development/mods/full_safety_car/trials/v0.10.88_dq_wording/safety_car_hardened_rf70r2.private.c:822 |
| 0x1E0 | this | 553 | 553 | development/mods/full_safety_car/trials/v0.10.88_dq_wording/safety_car_hardened_rf70r2.private.c:9219 |
| 0x4108 | DAT_7C54E0, OFF_VEHICLE_FLAG, Offset, rb, veh, x4108 | 156 | 1366 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:176 |
| 0x40 | red | 153 | 306 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:176 |
| 0x41 | blue, from | 153 | 306 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:175 |
| 0x3FC4 | OFF_SESSION_STATE | 153 | 153 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:9762 |
| 0x3674 | OFF_WHEEL_HIT, hit, veh, vehicle | 143 | 146 | f1c_ida_decompiled/tools/sdk/SURFACE_CONTACT_REVIEW_2026-09-08.md:4 |
| 0x4170 | OFF_AI_PIT_TRIGGER, OFF_RECOVERY_GUARD, address, trigger, trigger_bits, veh, vehicle | 142 | 150 | f1c_ida_decompiled/tools/sdk/f1c_native_removal_repair.h:33 |
| 0x4480 | OFF_AI_CURRENT_TIME, OFF_AI_TIME, ai_time | 140 | 140 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:357 |
| 0x714 | OFF_UP_VECTOR_Y, Physics, col1, physics, s, that, up_dot, x720 | 130 | 219 | f1c_ida_decompiled/tools/sdk/f1c_orientation.h:6 |
| 0x700 | veh | 124 | 124 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:8083 |
| 0x724 | x700 | 124 | 124 | development/mods/red_flag/releases/v1.1.5-rc.2/redflag.hardened.c:8083 |
| 0xC | ECX, F1CVehicle, OFF_TIREIDX, OFF_TIREOBJ, crew, dword_5EA560, this, veh, vehicle | 114 | 178 | f1c_ida_decompiled/tools/sdk/f1c_inverted_removal.h:4 |
| 0x4488 | OFF_GARAGEFLAG_A, VEH_BASE, VEH_OFF_GARAGE_A | 114 | 114 | development/mods/esc_pause_menu/releases/v1.0.5-rc.1/esc_pause_menu.c:57 |
| 0x4578 | OFF_GARAGEFLAG_B, VEH_BASE, VEH_OFF_GARAGE_B | 114 | 114 | development/mods/esc_pause_menu/releases/v1.0.5-rc.1/esc_pause_menu.c:58 |
| 0x720 | OFF_UP_VECTOR_Y, f, offset, s, that, vehicle, x714 | 42 | 83 | f1c_ida_decompiled/tools/sdk/f1c_orientation.h:6 |
| 0x39FA | veh | 41 | 41 | development/mods/mechanical_failures/dll/engine_failure.c:17 |
| 0x3484 | OFF_FUELTARGET, OFF_FUEL_TGT, VEH_BASE, x3480 | 34 | 50 | development/mods/pitstop_modding/release_candidates/pitstop_failures-v1.0.5-rc.2/src/pit_commentary.c:46 |
| 0x3480 | OFF_RAMP, OFF_REFUEL_RAMP, veh, x347C | 33 | 65 | development/mods/pitstop_modding/release_candidates/pitstop_failures-v1.0.5-rc.2/src/pit_commentary.c:45 |
| 0x347C | OFF_FUEL_START, vehicle | 33 | 33 | development/mods/pitstop_modding/release_candidates/pitstop_failures-v1.0.5-rc.2/src/pit_commentary.c:44 |
| 0x2A | mem | 32 | 32 | development/mods/full_safety_car/trials/v0.10.16_guardrails/evidence/pit_reset_20260908_173543_845919/test.c:184 |
| 0x3D64 | engine | 26 | 26 | development/mods/mechanical_failures/dll/engine_failure.c:8 |
| 0x100 | __builtin_trap, veh, void | 24 | 90 | development/mods/race_data_collector/trials/rf_audit_20260923_110548/rf-pit-strategy/test.c:370 |
| 0x45E0 | vehicle | 20 | 20 | f1c_ida_decompiled/tools/sdk/f1c_pit_strategy.h:9 |
| 0x349C | OFF_TIRE_START, OFF_TYRE_START | 18 | 18 | development/mods/pitstop_modding/release_candidates/pitstop_failures-v1.0.5-rc.2/src/pit_commentary.c:47 |
| 0x34A4 | OFF_QUEUE_EID, veh | 17 | 34 | development/mods/pitstop_modding/release_candidates/pitstop_failures-v1.0.5-rc.2/src/pit_commentary.c:206 |
| 0x34A8 | OFF_QUEUE_DELAY, and | 17 | 18 | development/mods/pitstop_modding/release_candidates/pitstop_failures-v1.0.5-rc.2/src/pit_commentary.c:207 |
| 0x3478 | OFF_LOLLI | 17 | 17 | development/mods/pitstop_modding/release_candidates/pitstop_failures-v1.0.5-rc.2/src/pit_commentary.c:57 |
| 0x3A10 | OFF_SHIFT_TMR, veh | 16 | 17 | development/mods/mechanical_failures/dll/gear_failure.c:8 |
| 0x14 | OFF_SND_OBJ, rng | 16 | 16 | f1c_ida_decompiled/tools/sdk/f1c_ai_restart_pending.h:7 |
| 0x3A04 | OFF_MAX_GEAR | 16 | 16 | development/mods/mechanical_failures/dll/gear_failure.c:64 |

