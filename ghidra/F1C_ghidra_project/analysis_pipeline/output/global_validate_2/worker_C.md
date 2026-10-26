=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_007CA3B8 | Unknown_Audio_SourcePtr | audio | ptr | read | 2 | Audio source/buffer pointer — compared against other audio source pointers in FUN_0044ff50 audio processing; listed in FUN_00452810 address match table |
| DAT_005BE5DC | LeftHandedPitsString | setup | char[] | offset | 1 | "aLeftHandedPits" string — UI/INI config string for left-handed pit configuration |
| DAT_008AFF84 | Unknown_Float_AFF84 | dynamics | float | write | 1 | Float written in FUN_00402690 — likely initialization constant |
| DAT_005BE45C | WPDWidthString | setup | char[] | offset | 1 | "aWpDWidth" string — UI/INI config string for width parameter |
| DAT_005BE91C | MirrorBmpString | setup | char[] | offset | 1 | "aMirrorBmp" string — mirror bitmap filename string reference |
| DAT_005BEAE0 | CameraTargetSetString | setup | char[] | offset | 1 | "aCameraTargetSe" string — camera target setup configuration string |
| DAT_005BE9D0 | WelcomeToCountryString | UI | char[] | offset | 1 | "aWelcomeToCount" string — welcome message with country name for session display |
| DAT_005BEB60 | PartString | setup | char[] | offset | 1 | "aPart" string — "Part" INI section key used in config parsing |
| DAT_005EC470 | Unknown_DirPtr | setup | ptr | read | 1 | Directory/string pointer read in FUN_00414600 — likely directory path for setup files |
| DAT_005C2594 | DriverNameMikaH | setup | char[] | offset | 1 | "aMikaH" string — driver name string for Mika Hakkinen, used in driver data table parsing |
| DAT_005C24C4 | DriverNameFernandoA | setup | char[] | offset | 1 | "aFernandoA" string — driver name string for Fernando Alonso, used in driver data table |
| DAT_007C9AF8 | Unknown_Struct_7C9AF8 | game | ptr | offset | 1 | Struct pointer used in FUN_00418ee0 — compared with vehicle ptr array in AI opponent selection logic |
| DAT_005C28CC | Year2000JaguarString | setup | char[] | offset | 1 | "a2000Jaguar" string — "2000 Jaguar" team name string for season/year-specific team data |
| DAT_005C27B8 | Year2002FerrariString | setup | char[] | offset | 1 | "a2002Ferrari" string — "2002 Ferrari" team name string for season/year-specific team data |
| DAT_005C2A20 | CircuitsString | setup | char[] | offset | 1 | "aCircuits" string — "Circuits" INI section key for track/circuit configuration |
| DAT_005C2C70 | OptionsSoundsString | setup | char[] | offset | 1 | "aOptionsSounds" string — "OptionsSounds" INI section for sound configuration |
| DAT_005C2B74 | VideoRefreshString | setup | char[] | offset | 1 | "aVideoRefresh" string — "VideoRefresh" INI section for display refresh configuration |
| DAT_005C2FE8 | VehicleSoundSString | setup | char[] | offset | 1 | "aVehicleSoundS" string — "VehicleSound.S" INI section for vehicle sound configuration |
| DAT_005C2E9C | VideoGuidSString | setup | char[] | offset | 1 | "aVideoGuidS" string — "VideoGuid.S" INI section for video guidance configuration |
| DAT_005C3064 | Unknown_Byte_5C3064 | setup | byte | read | 1 | Byte read in FUN_004230c0 — configuration byte for setup/filter logic |
| DAT_005C31B4 | CompletedLapsString | UI | char[] | offset | 1 | "aCompletedLaps" string — "CompletedLaps" UI display string for lap counter |
| DAT_0059E8AC | Unknown_Float_Physics | physics | float | read | 1 | Float read in FUN_00425920 — used in AI vehicle gap/distance comparison against waypoint distance |
| DAT_005C32CC | DisallowedString | UI | char[] | offset | 1 | "aDisallowed" string — "Disallowed" UI penalty/warning message string |
| DAT_005C33E8 | TractionControlString | setup | char[] | offset | 1 | "aTractionControl" string — "Traction Control" INI/setup parameter string |
| DAT_007C9350 | Unknown_FlagBlock_Clear | game | int | write | 1 | Zeroed as part of 12-global zero block (DAT_007c932c-9358) in FUN_0042c690 — cleared on update tick |
| DAT_005C355C | MultiplayerModeString | setup | char[] | offset | 1 | "aMultiplayerMode" string — "Multiplayer Mode" INI/setup configuration string |
| DAT_005C3710 | TrackTypeString | setup | char[] | offset | 1 | "aTrackType" string — "TrackType" INI key for track surface/type configuration |
| DAT_005C3EC4 | NotesSString | setup | char[] | offset | 1 | "aNotesS" string — "Notes.S" INI section key for car setup notes |
| DAT_005C3D50 | BrakeDuctSettingString | setup | char[] | offset | 1 | "aBrakeDuctSetting" string — "BrakeDuctSetting" INI key for brake duct configuration |
| DAT_005C3B38 | Rear3rdSlowReboundString | setup | char[] | offset | 1 | "aRear3rdSlowReb" string — "Rear3rdSlowRebound" INI key for rear 3rd element slow rebound damping |
| DAT_005C3984 | FrontRightString | setup | char[] | offset | 1 | "aFrontRight" string — "FrontRight" INI key for front-right wheel setup |
| DAT_008ADB60 | Unknown_Double_8ADB60 | dynamics | double | read | 1 | Double constant in FUN_00430750 — used in collision/impact force calculation with tire damping |
| DAT_005C3FA0 | Unknown_Off_5C3FA0 | data | ptr | read | 1 | Pointer/offset read in FUN_00432180 — likely pointer table entry |
| DAT_005C4118 | MinPosString | setup | char[] | offset | 1 | "aMinPos" string — "MinPos" INI key for minimum position parameter |
| DAT_0059EB88 | Unknown_Double_BrakeCalc | dynamics | double | read | 1 | Double in FUN_00438130 — multiplied against brake/damper pressure delta; part of brake torque calculation |
| DAT_0059EBF8 | Unknown_Double_Damper | dynamics | double | read | 1 | Double read in FUN_00439210 — damper/suspension force calculation constant |
| DAT_0059EC30 | Unknown_Double_Thermal | dynamics | double | read | 1 | Double in FUN_0043c250 — thermal/damper dissipation factor |
| DAT_0059EC98 | Unknown_Double_Dissipation | dynamics | double | read | 1 | Double in FUN_0043ef20 — energy dissipation factor in collision/impact model; multiplied against ABS angular velocity |
| DAT_007CC368 | Unknown_Ptr_7CC368 | renderer/UI | ptr | read | 1 | Pointer read in FUN_004441f0 — audio/UI handler pointer for processing |
| DAT_0059EE40 | Unknown_Double_Engine | dynamics | double | read | 1 | Double in FUN_004441f0 — engine/physics model constant used in force calculations |
| DAT_0059EEE8 | Unknown_Double_Tire_Tread | dynamics | double | read | 1 | Double in FUN_004472b0 — tire tread wear/force multiplier; multiplied against delta above threshold |
| DAT_007CFEE8 | Unknown_Byte_WeatherFlag | setup | byte | read | 1 | Byte checked in FUN_0044c0e0 — weather/environment flag that gates file path construction logic |
| DAT_007CA4FC | Unknown_Float_4FC_Zeroed | renderer | float | write | 1 | Zeroed in FUN_0044d220 — part of a 4-field struct initialization (DAT_007ca4f8-504) |
| DAT_007CCD04 | Unknown_Zeroed_CCD04 | collision | int | write | 1 | Zeroed in FUN_0044d460 — part of collision initialization struct (companion to DAT_007cccf0-504) |
| DAT_007D204C | Unknown_Int_7D204C | collision | int | read | 1 | Integer read in FUN_0044ff50 — collision/audio channel routing parameter |
| DAT_005AD384 | Unknown_Ptr_5AD384 | collision | ptr | read | 1 | Pointer read in FUN_0044ff50 — collision grid/struct base address |
| DAT_005AD390 | Unknown_Ptr_5AD390 | collision | ptr | read | 1 | Pointer read in FUN_0044ff50 — second collision grid/struct base address |
| DAT_007D21D0 | Unknown_Float_Visibility | renderer | float | read | 1 | Float in FUN_00451720 — visibility/render state parameter for object rendering control |
| DAT_007CD0E0 | Unknown_Ptr_7CD0E0 | collision | ptr | read | 1 | Pointer in FUN_00452b10 — collision parameter pointer match table entry |
| DAT_007CD1E8 | Unknown_Float_AudioCh | audio | float | write | 1 | Float in FUN_004537b0 — audio channel volume/balance value read from vehicle struct +0x1140 then clamped |
| DAT_007CC9F0 | Unknown_Float_AudioBalance | audio | float | write | 1 | Float in FUN_004537b0 — audio channel volume/balance companion to audio processing struct |
| DAT_005C5664 | AccelerateString | setup | char[] | offset | 1 | "aAccelerate" string — "Accelerate" INI key for acceleration/control binding |
| DAT_005C5548 | BrakeBiasFString | setup | char[] | offset | 1 | "aBrakeBiasF" string — "BrakeBiasF" INI key for brake bias front percentage |
| DAT_007CA508 | KeyboardLayoutHandle | input | ptr | write | 1 | HKL keyboard layout handle from GetKeyboardLayout(0) — stored for ToAsciiEx/MapVirtualKeyExA calls |
| DAT_005C5888 | SRadiusLimitsFString | setup | char[] | offset | 1 | "aSRadiusLimitsF" string — "SRadiusLimitsF" INI key for steering radius limits |
| DAT_005C5AE8 | SMovementRateFString | setup | char[] | offset | 1 | "aSMovementRateF" string — "SMovementRateF" INI key for steering movement rate |
| DAT_005C5B94 | HDVString | setup | char[] | offset | 1 | "aHdv" string — ".HDV" file extension string for handling/vehicle data files |
| DAT_005C5D38 | WasRemovedFromString | network | char[] | offset | 1 | "aWasRemovedFrom" string — network disconnect/kick message "was removed from the game" |
| DAT_005C5DE8 | AutoChat10String | network | char[] | offset | 1 | "aAutoChat10" string — "AutoChat10" INI key for auto-chat interval configuration |
| DAT_005C60E8 | OpeningString | network | char[] | offset | 1 | "aOpening" string — "Opening" network session status message |
| DAT_007CF040 | Unknown_Flag_7CF040 | setup | int | read | 1 | Flag read in FUN_00461900 — session config flag companion to DAT_007cf038; part of option bitfield parsing |
| DAT_007CEF44 | Unknown_Flag_7CEF44 | setup | int | read | 1 | Flag read in FUN_00461900 — session/option flag from config parsing |
| DAT_005C621C | NoJoinFailureString | network | char[] | offset | 1 | "aNoJoinFailure" string — "No Join Failure" network error message |
| DAT_005C6350 | MaxPlayersString | network | char[] | offset | 1 | "aMaxPlayers" string — "MaxPlayers" INI key for maximum multiplayer players |
| DAT_007D0EC0 | Unknown_Flag_7D0EC0 | network | int | write | 1 | Flag written in FUN_00463f70 — networking/session connection state flag |
| DAT_0059F7C8 | Unknown_VTable_59F7C8 | setup | ptr | offset | 1 | VTable pointer reference in FUN_00469872 — referenced as object vtable during constructor |
| DAT_005C6A40 | FTim14GreenOutString | UI | char[] | offset | 1 | "aFTim14GreenOut" string — "F.Tim14GreenOut" UI display string for flag/session state |
| DAT_005C666C | Unknown_Off_5C666C | UI | ptr | read | 1 | String pointer array used in FUN_0046ec10 — strcmp comparison target for UI page matching |
| DAT_005C715C | BmpString | setup | char[] | offset | 1 | "aBmp" string — ".BMP" file extension string for bitmap file loading |
| DAT_005C7330 | PlayBackwardsString | UI | char[] | offset | 1 | "aPlayBackwards" string — "PlayBackwards" UI/ playback control string |
| DAT_005C7420 | HeadquartersString | UI | char[] | offset | 1 | "aHeadquarters" string — "Headquarters" UI menu/screen name string |
| DAT_005ABE28 | Unknown_VTable_5ABE28 | UI | ptr | offset | 1 | VTable pointer assigned in FUN_0048aa40 — UI/gizmo vtable reference |
| DAT_005CC530 | DisableGizmoString | UI | char[] | offset | 1 | "aDisableGizmo" string — "DisableGizmo" gizmo configuration string |
| DAT_005CC6B8 | FriendGizmoString | UI | char[] | offset | 1 | "aFriendGizmo" string — "FriendGizmo" gizmo/UI component name |
| DAT_005CC838 | DropPopupsString | UI | char[] | offset | 1 | "aDropPopups" string — "DropPopups" UI behavior configuration string |
| DAT_007C7C7C | Unknown_Gizmo_7C7C7C | UI | ptr | offset | 1 | Gizmo/UI struct offset reference in FUN_00493fc0 |
| DAT_005CCAE4 | OptionsErrorString | UI | char[] | offset | 1 | "aOptionsError" string — "Options Error" UI error message string |
| DAT_005ACAE8 | Unknown_Float_Aggression | ai | float | read | 1 | Float in FUN_0049b7a0 — AI aggression/performance threshold; compared against driver performance ratio for overtaking behavior selection |
| DAT_005CCB70 | Unknown_VTable_5CCB70 | UI | ptr | read | 1 | VTable pointer read in FUN_0049ca00 — UI object method table |
| DAT_005CCB64 | Unknown_VTable_5CCB64 | UI | ptr | read | 1 | VTable pointer read in FUN_0049ca00 — paired with DAT_005CCB70 |
| DAT_005CCF8C | EnteredOnScreenString | UI | char[] | offset | 1 | "aEnteredOnScreen" string — "entered on screen" UI display message |
| DAT_005CD040 | AltOSCString | UI | char[] | offset | 1 | "aAltOSC" string — "AltOSC" UI/input alternative control string |
| DAT_007CE2BC | Unknown_Flag_7CE2BC | session | int | write | 1 | Session state flag written in FUN_004a1200 — session initialization step |
| DAT_005CD30C | RearJackUpString | UI | char[] | offset | 1 | "aRearJackUp" string — "Rear Jack Up" UI pit/garage message |
| DAT_005CD1DC | SmanString | UI | char[] | offset | 1 | "a10secSman4" string — "10sec Sman4" UI pit stop countdown message |
| DAT_005CD37C | MoveSSFString | UI | char[] | offset | 1 | "aMoveSSF" string — "Move SSF" UI/setup screen navigation |
| DAT_005CD4CC | ErrorString | UI | char[] | offset | 1 | "aError" string — "Error" UI error message |
| DAT_005CD658 | DDString | UI | char[] | offset | 1 | "aDD" string — "DD" UI label/button string |
| DAT_005ACB78 | Unknown_VTable_5ACB78 | UI | ptr | offset | 1 | VTable pointer reference in FUN_004a70e0 — UI widget vtable assignment |
| DAT_005D1EF8 | Help0New1NewString | setup | char[] | offset | 1 | "a0NewHelp1NewHe" string — help/new driver help text resource string |
| DAT_005D1C58 | HowLongAfterAMString | setup | char[] | offset | 1 | "aHowLongAfterAM" string — "How long after a..." UI help/option string |
| DAT_005D19B0 | MechanicalFailureString | setup | char[] | offset | 1 | "aMechanicalFail" string — "Mechanical Failure" option/help string |
| DAT_005D1760 | FlagRulesString | setup | char[] | offset | 1 | "aFlagRules" string — "Flag Rules" help/option configuration string |
| DAT_005D1568 | VolumeMultiplierString | setup | char[] | offset | 1 | "aVolumeMultipli" string — "Volume Multiplier" audio option string |
| DAT_005D1370 | PublicAddressSString | setup | char[] | offset | 1 | "aPublicAddressS" string — "Public Address System" audio option string |
| DAT_005D11C4 | MovingSteeringString | setup | char[] | offset | 1 | "aMovingSteering" string — "Moving Steering" control option string |
| DAT_005D0F90 | SkyboxPositionString | setup | char[] | offset | 1 | "aSkyboxPosition" string — "Skybox Position" video option string |
| DAT_005D0CBC | LeanAheadAngleString | setup | char[] | offset | 1 | "aLeanAheadAngle" string — "Lean Ahead Angle" camera option string |
| DAT_005D0A14 | MapOppDetailToString | setup | char[] | offset | 1 | "aMapOppdetailTo" string — "Map Opp Detail To" graphics option string |
| DAT_005D081C | NightLightingString | setup | char[] | offset | 1 | "aNightLighting" string — "Night Lighting" graphics option string |
| DAT_005D0570 | RaceSessionString | setup | char[] | offset | 1 | "aRaceSession" string — "Race Session" session type option string |
| DAT_005D0294 | MessageCenterDString | setup | char[] | offset | 1 | "aMessageCenterD" string — "Message Center Display" UI option string |
| DAT_005D0000 | MphKphString | setup | char[] | offset | 1 | "a0Mph1Kph" string — "0 Mph 1 Kph" speed unit option string |
| DAT_005CFD70 | SavesSeparateVString | setup | char[] | offset | 1 | "aSavesSeparateV" string — "Saves Separate V" savegame option string |
| DAT_005CF9B8 | ExplicitFlushString | setup | char[] | offset | 1 | "aAnExplicitFlus" string — "An Explicit Flush" file/cache option string |
| DAT_005CF618 | ClosedMpQualifString | setup | char[] | offset | 1 | "aClosedMpQualif" string — "Closed MP Qualif" multiplayer option string |
| DAT_005CF230 | BoneSpringMaxCString | setup | char[] | offset | 1 | "aBoneSpringMaxC" string — "Bone Spring Max C" physics/suspension option string |
| DAT_005CEF44 | GearSelectButtonString | setup | char[] | offset | 1 | "aGearSelectButt" string — "Gear Select Button" control option string |
| DAT_005CEBBC | Controller2RxString | setup | char[] | offset | 1 | "aController2Rx" string — "Controller 2 Rx" controller option string |
| DAT_005CE9E0 | ControlReverseString | setup | char[] | offset | 1 | "aControlReverse" string — "Control Reverse" control mapping string |
| DAT_005CE804 | ControlLookLeftString | setup | char[] | offset | 1 | "aControlLookLef" string — "Control Look Left" control mapping string |
| DAT_005CE5D4 | FfbEffectsLevelString | setup | char[] | offset | 1 | "aFfbEffectsLeve" string — "FFB Effects Level" force feedback option string |
| DAT_005CE114 | FfbSteerForceIString | setup | char[] | offset | 1 | "aFfbSteerForceI" string — "FFB Steer Force Intake" force feedback option string |
| DAT_005CDCA4 | FfbThrottleVibString | setup | char[] | offset | 1 | "aFfbThrottleVib" string — "FFB Throttle Vib" force feedback option string |
| DAT_005CD8B0 | AmountOfChangeString | setup | char[] | offset | 1 | "aAmountOfChange" string — "Amount Of Change" option string |
| DAT_005D2350 | EnteredPlayerfString | UI | char[] | offset | 1 | "aEnteredPlayerf" string — "Entered Player" UI message string |
| DAT_005ACCE0 | Unknown_Float_Skidding | renderer | float | read | 1 | Float in FUN_004b2c20 — used in tire skid/particle effect computation with bitfield packing |
| DAT_005ACD38 | Unknown_Float_AI_Count | ai | float | read | 1 | Float threshold in FUN_004b6190 — compared against AI candidate count for overtaking/passing selection |
| DAT_005D24BC | LoadingVcrFileString | UI | char[] | offset | 1 | "aLoadingVcrFile" string — "Loading VCR File" replay load message |
| DAT_005ACD70 | Unknown_Float_5ACD70 | renderer | float | read | 1 | Float read in FUN_004bc9b0 — rendering/texture parameter |
| DAT_005ACDB4 | Unknown_Float_FFB | input | float | read | 1 | Float in FUN_004bea10 — force feedback effect multiplier; multiplied against random component and input parameter |
| DAT_005D26D8 | SeasonPointsString | UI | char[] | offset | 1 | "aSeasonPoints" string — "SeasonPoints" UI/standings display string |
| DAT_005D2824 | RaceOverString | UI | char[] | offset | 1 | "aRaceOver" string — "Race Over" UI race conclusion message |
| DAT_005D2DEC | TotalPolesDString | UI | char[] | offset | 1 | "aTotalPolesD" string — "TotalPoles %d" UI stat display format |
| DAT_005D2B7C | GameoptSpeedCoString | UI | char[] | offset | 1 | "aGameoptSpeedCo" string — "Gameopt Speed Controller" option string |
| DAT_005C401C | ClassesString | setup | char[] | offset | 1 | "aClasses" string — "Classes" INI section key for vehicle class definition |
| DAT_005D30B4 | SCommonSString | setup | char[] | offset | 1 | "aSCommonS" string — "%sCommon%s" path format string for common file directory |
| DAT_008AC4C0 | Unknown_AnimCounter | renderer | int | read | 1 | Animation/frame counter in FUN_004c8650 — wraps at 4, indexes into animation frame table |
| DAT_005ACE20 | Unknown_Float_5ACE20 | UI | float | read | 1 | Float read in FUN_004c99d0 — UI/animation parameter |
| DAT_005D3678 | GrooveString | setup | char[] | offset | 1 | "aGroove" string — "Groove" tire/road configuration string |
| DAT_005D3568 | GouraudShadeString | setup | char[] | offset | 1 | "aGouraudShade" string — "GouraudShade" renderer configuration string |
| DAT_005D3770 | ZeroString | setup | char[] | offset | 1 | "aZero" string — "Zero" string constant for INI/setup parsing |
| DAT_005ACE9C | Unknown_Float_5ACE9C | renderer | float | read | 1 | Float read in FUN_004cb120 — renderer color/fog parameter |
| DAT_005D3880 | DirtString | setup | char[] | offset | 1 | "aDirt" string — "Dirt" track surface/particle configuration string |
| DAT_005D397C | ExcludeTracksString | setup | char[] | offset | 1 | "aExcludeTracks" string — "ExcludeTracks" track filter configuration string |
| DAT_005D3ACC | GirlBString | setup | char[] | offset | 1 | "aGirlB" string — "GirlB" UI/garage background image string |
| DAT_005D3C14 | PBox02dString | setup | char[] | offset | 1 | "aPbox02d" string — "PBox %02d" pit box number format string |
| DAT_005D40A0 | RaceLapsDString | setup | char[] | offset | 1 | "aRaceLapsD" string — "Race Laps %d" race length option string |
| DAT_005D3E84 | DriveAidsShiftString | setup | char[] | offset | 1 | "aDriveaidsShift" string — "DriveAids Shift" driver aid option string |
| DAT_005D3D08 | RaceLapsDAltString | setup | char[] | offset | 1 | "aRacelapsD" string — alternate "Race Laps %d" option string |
| DAT_005D42EC | StGlowString | setup | char[] | offset | 1 | "aStglow" string — "StGlow" starting grid glow configuration |
| DAT_005D4388 | Unknown_Word_5D4388 | UI | word | read | 1 | Word read in FUN_004d3cf0 — UI/flag state value |
| DAT_007CE9D0 | Unknown_Int_7CE9D0 | physics | int | read | 1 | Integer read in FUN_004d4a80 — tire/physics parameter |
| DAT_005D44C8 | RLString | setup | char[] | offset | 1 | "aRl" string — "RL" setup/configuration short key |
| DAT_005D45C0 | TireLoadFactorString | setup | char[] | offset | 1 | "aTireLoadFactor" string — "Tire Load Factor" tire model parameter |
| DAT_005D47FC | LatPeakString | setup | char[] | offset | 1 | "aLatPeak" string — "LatPeak" tire lateral peak parameter |
| DAT_005D4938 | CompoundString | setup | char[] | offset | 1 | "aCompound" string — "Compound" tire compound parameter |
| DAT_005D4AA8 | BroadcastDisplayString | setup | char[] | offset | 1 | "aBroadcastDispl" string — "Broadcast Display" hud/UI configuration |
| DAT_005D4AFC | Unknown_StringPtr_5D4AFC | UI | ptr | read | 1 | "TrackName" pointer reference in FUN_004d99e0 — used for track name display string retrieval |
| DAT_005D4CB8 | WCCarBodyString | setup | char[] | offset | 1 | "aWCCarBody" string — "WCCarBody" setup/repair garage body part string |
| DAT_005C6804 | Unknown_Asc_5C6804 | setup | char[] | offset | 1 | ASCII string constant in FUN_004ddf90 — character/encoding table entry |
| DAT_005D4DC0 | RFSpindleString | setup | char[] | offset | 1 | "aRFSpindle" string — "RFSpindle" front-right suspension part string |
| DAT_005D4D20 | TreadMedString | setup | char[] | offset | 1 | "aTreadMed" string — "TreadMed" tire tread medium parameter string |
| DAT_007C9214 | Unknown_Double_Suspension | dynamics | double | read | 1 | Double in FUN_004e49b0 — suspension geometry constant used in wheel position/orientation computation |
| DAT_007CF728 | Unknown_Byte_7CF728 | vehicle | byte | read | 1 | Byte checked in FUN_004eb430 — vehicle setup/state flag for damage/part initialization |
| DAT_007C9150 | Unknown_Double_Damage | dynamics | double | read | 1 | Double in FUN_004f12e0 — damage/impact threshold for part detachment force calculations |
| DAT_005D4F74 | RearWingDetachString | setup | char[] | offset | 1 | "aRearWingDetach" string — "RearWingDetach" damage/part parameter string |
| DAT_005D5290 | BumpStopRisingString | setup | char[] | offset | 1 | "aBumpStopRising" string — "BumpStopRising" suspension bumpstop parameter string |
| DAT_005D515C | PressureRangeString | setup | char[] | offset | 1 | "aPressureRange" string — "PressureRange" tire pressure parameter string |
| DAT_005D5348 | FenderDragParamString | setup | char[] | offset | 1 | "aFenderDragPara" string — "FenderDragParams" aero/drag parameter string |
| DAT_005D56FC | IdleThrottleString | setup | char[] | offset | 1 | "aIdleThrottle" string — "IdleThrottle" engine idle parameter string |
| DAT_005D5578 | EngineSpeedHeadString | setup | char[] | offset | 1 | "aEngineSpeedHead" string — "EngineSpeedHead" engine speed head parameter string |
| DAT_005D66BC | WedgePushrodString | setup | char[] | offset | 1 | "aWedgePushrod" string — "WedgePushrod" suspension geometry parameter |
| DAT_005D6588 | SymmetricString | setup | char[] | offset | 1 | "aSymmetric" string — "Symmetric" suspension setup parameter |
| DAT_005D6454 | FWDragParamsString | setup | char[] | offset | 1 | "aFWDragParams" string — "FWDragParams" front wing drag parameter string |
| DAT_005D6364 | RWLiftSidewaysString | setup | char[] | offset | 1 | "aRWLiftSideways" string — "RWLiftSideways" rear wing lateral lift parameter |
| DAT_005D6284 | BodyAftString | setup | char[] | offset | 1 | "aBodyAft" string — "BodyAft" body aero aft parameter |
| DAT_005D614C | ApplySlowToFastString | setup | char[] | offset | 1 | "aApplySlowToFast" string — "ApplySlowToFast" setup/parameter mapping string |
| DAT_005D5FB0 | Rear3rdBumpTravelString | setup | char[] | offset | 1 | "aRear3rdBumptra" string — "Rear3rdBumpTravel" suspension parameter string |
| DAT_005D5DF4 | LeftCasterSettingString | setup | char[] | offset | 1 | "aLeftCasterSett" string — "LeftCasterSetting" suspension alignment parameter |
| DAT_005D5C28 | Rear3rdPackersString | setup | char[] | offset | 1 | "aRear3rdPackers" string — "Rear3rdPackers" suspension packers parameter |
| DAT_005D5A84 | SteerLockSettingString | setup | char[] | offset | 1 | "aSteerLockSetti" string — "SteerLockSetting" steering lock parameter |
| DAT_005D5948 | UpshiftDelayString | setup | char[] | offset | 1 | "aUpshiftDelay" string — "UpshiftDelay" gearbox shift parameter |
| DAT_005D580C | DiffPumpRangeString | setup | char[] | offset | 1 | "aDiffPumpRange" string — "DiffPumpRange" differential pump parameter |
| DAT_005D67EC | MinimumRPMString | setup | char[] | offset | 1 | "aMinimumRPM" string — "MinimumRPM" engine parameter string |
| DAT_005D6C60 | PlayerEngineVolString | setup | char[] | offset | 1 | "aPlayerEngineVo" string — "PlayerEngineVol" audio engine volume parameter |
| DAT_005D6AEB | Unknown_String_6AEB | setup | char[] | offset | 1 | Unnamed string reference in FUN_004f7460 — engine volume/audio parameter |
| DAT_005D695B | Unknown_String_695B | setup | char[] | offset | 1 | Unnamed string reference in FUN_004f7460 — engine volume/audio parameter |
| DAT_005D6D48 | ProcNameString | setup | char[] | offset | 1 | "ProcName" string — "ProcName" process/memory configuration string |
| DAT_005D6E34 | Unknown_Word_5D6E34 | renderer | word | read | 1 | Word read in FUN_004f9480 — renderer/DirectX surface parameter |
| DAT_005D6E84 | EnteredVidManString | UI | char[] | offset | 1 | "aEnteredVidmanS" string — "Entered VidMan" renderer debug message |
| DAT_007CF950 | Unknown_Float_Camera | renderer | float | read | 1 | Float in FUN_004fbd70 — camera/viewport scale factor for offset positioning |
| DAT_005D6F78 | NightLightString | setup | char[] | offset | 1 | "aNightLight" string — "NightLight" lighting configuration string |
| DAT_005AD30C | Unknown_Float_DamperDecay | dynamics | float | read | 1 | Float in FUN_004fdeb0 — damper decay rate multiplier in suspension force model |
| DAT_005AD328 | Unknown_Float_TireWear | dynamics | float | read | 1 | Float in FUN_004fe2b0 — tire wear/grip degradation rate factor |
| DAT_005D7070 | Unknown_Asc_5D7070 | renderer | char[] | offset | 1 | ASCII string in FUN_004fe820 — renderer/shader configuration string |
| DAT_008B0090 | Unknown_Int_8B0090 | data | int | read | 1 | Integer read in FUN_00500eac — data/serialization flag |
| DAT_005AD4C0 | Unknown_Struct_5AD4C0 | data | ptr | offset | 1 | Struct base pointer used in FUN_00506559 — data/serialization context |
| DAT_005ADC48 | Unknown_Float_Texture | renderer | float | read | 1 | Float in FUN_0050ab51 — texture compression/chroma scale factor for color decoding |
| DAT_005ADD4C | Unknown_VTable_5ADD4C | renderer | ptr | offset | 1 | VTable pointer assigned in FUN_0050b3ed — renderer/texture vtable |
| DAT_005D7884 | Unknown_Ptr_5D7884 | renderer | ptr | read | 1 | Function pointer read in FUN_0050c134 — indirect rendering call through PTR_FUN_005d7884 |
| DAT_005ADE44 | Unknown_Float_QuatThreshold | math_util | float | read | 1 | Float in FUN_0050df9b — quaternion normalization threshold; if squared length <= this, result is zero quaternion |
| DAT_005AF2B0 | ZlibMemoryErrorString | data | char[] | offset | 1 | "aZlibMemoryErro" string — zlib "memory error" string, part of PNG/zlib decompression |
| DAT_00602000 | Unknown_Flag_602000 | data | byte | offset | 1 | Bitmask value 0x602000 used in FUN_0051378b — PNG/zlib pixel format flag for bit depth/channel processing |
| DAT_005D79CC | Unknown_Float_Render | renderer | float | read | 1 | Float in FUN_005147ea — renderer/vertex processing parameter |
| DAT_005AFC60 | OutOfPlaceIHDRString | data | char[] | offset | 1 | "aOutOfPlaceIhdr" string — "out of place IHDR" PNG decoder error message |
| DAT_005AFD78 | DuplicateGamaCString | data | char[] | offset | 1 | "aDuplicateGamaC" string — "duplicate gAMA chunk" PNG decoder warning |
| DAT_005AFF70 | ExtraCompressiString | data | char[] | offset | 1 | "aExtraCompressi" string — "extra compression" PNG decoder warning |
| DAT_005D8A30 | Unknown_Float_InvSqrt | math_util | float | read | 1 | Float in FUN_0051f160 — inverse square root Newton-Raphson iteration constant for quaternion/vector normalization |
| DAT_008D6100 | SSESignMask_XMM | math_util | xmm | read | 1 | SSE sign flip mask in FUN_0051fbf0 — used with _mm_xor_ps for 3D cross product sign manipulation |
| DAT_008D618C | Unknown_Float_VecThreshold | math_util | float | read | 1 | Float in FUN_0052042e — vector normalization threshold; if squared length <= this, result is zero vector |
| DAT_005D8C90 | SSEMask_XMM_5D8C90 | math_util | xmm | read | 1 | SSE AND mask in FUN_00520a7e — used with _mm_and_ps for SIMD vector component extraction |
| DAT_005AF9E8 | Unknown_QWord_Compare | math_util | qword | read | 1 | QWord used in FUN_005215db — SIMD packed floating comparison threshold (PackedFloatingCompareGE) |
| DAT_005D8F80 | Unknown_XMM_Filter | math_util | xmm | read | 1 | XMM constant in FUN_005289e0 — pixel/surface filter coefficient for SIMD color processing |
| DAT_005D9240 | Unknown_XMM_Filter2 | math_util | xmm | read | 1 | XMM constant in FUN_00528cc0 — pixel/surface filter coefficient for SIMD color channel processing |
| DAT_005D9374 | Unknown_DWord_Select | math_util | uint | read | 1 | DWord in FUN_00529000 — SIMD packed floating select mask for trigonometric approximation |
| DAT_005B0AF8 | EmptyDistanceToString | data | char[] | offset | 1 | "aEmptyDistanceT" string — "empty distance table" PNG/graphics error string |
| DAT_005B0BF0 | Unknown_QWord_MMX | math_util | qword | read | 1 | QWord in FUN_0052ab4e — MMX/3DNow packed multiply constant for SIMD math operations |
| DAT_005B4684 | Unknown_Word_5B4684 | data | word | read | 1 | Word in FUN_0052da30 — lookup table index for data processing |
| DAT_005B4790 | Unknown_DWord_5B4790 | data | uint | read | 1 | DWord in FUN_00531250 — bitfield extraction mask for texture/pixel decompression |
| DAT_005B7738 | Unknown_Float_DCT | renderer | float | read | 1 | Float in FUN_00531b50 — DCT/transform coefficient for texture color space conversion (companion to 005b772c-7768 array) |
| DAT_008B594C | Unknown_Float_DCT_Write | renderer | float | write | 1 | Float written in FUN_00531b50 — DCT/transform output coefficient stored to 0x8B59xx region |
| DAT_008B59A8 | Unknown_Float_DCT_Write2 | renderer | float | write | 1 | Float written in FUN_00531b50 — second DCT output coefficient |
| DAT_008B59C4 | Unknown_Float_DCT_Write3 | renderer | float | write | 1 | Float written in FUN_00531b50 — third DCT output coefficient |
| DAT_008B59E8 | Unknown_Float_DCT_Write4 | renderer | float | write | 1 | Float written in FUN_00531b50 — fourth DCT output coefficient |
| DAT_005B77E8 | Unknown_Word_Array | renderer | word | read | 1 | Word table in FUN_00536260 — indexed at stride 0xc by param+0x7a; contains initialization values for color/depth format config |
| DAT_005B8798 | Unknown_Struct_5B8798 | data | ptr | offset | 1 | Struct reference in FUN_0053a4d0 — memory/operator new context for variable-size allocation |
| DAT_008B8F08 | Unknown_Triple_Store | runtime | int | write | 1 | Three dword values stored in FUN_0053c680 — tri-param storage for implicit argument passing |
| DAT_005DBE94 | ReflectionMapString | setup | char[] | offset | 1 | "aReflectionMapp" string — "ReflectionMap" rendering/shader configuration string |
| DAT_005B8990 | Unknown_Double_Bink | audio | double | read | 1 | Double in FUN_00551eb0 — Bink audio volume threshold for normalized volume comparison |
| DAT_005DC26C | RangeString | setup | char[] | offset | 1 | "aRange" string — "Range" INI/setup parsing keyword |
| DAT_005DC2FC | MoveableString | setup | char[] | offset | 1 | "aMoveable" string — "Moveable" scene object configuration string |
| DAT_005DC3C4 | FogColorString | setup | char[] | offset | 1 | "aFogColor" string — "FogColor" scene/rendering configuration string |
| DAT_005DC580 | Unknown_DWord_Mesh | renderer | dword | read | 1 | DWord read in FUN_0055f0d0 — mesh/scene object parameter |
| DAT_005DC53C | Unknown_DWord_Mesh2 | renderer | dword | read | 1 | DWord read in FUN_0055f0d0 — mesh/scene parameter companion |
| DAT_005DC4F4 | Unknown_Word_Mesh | renderer | word | read | 1 | Word read in FUN_0055f0d0 — mesh element count/index parameter |
| DAT_005DC4A8 | Unknown_Word_Mesh2 | renderer | word | read | 1 | Word read in FUN_0055f0d0 — mesh element count/index companion |
| DAT_008CF080 | Unknown_File_Buffer_Toggle | file | int | read | 1 | Toggle/token in FUN_00562530 — XOR'd with 1 each call; used to select between two 0x100-byte string buffers (DAT_008cf088/188) for file path construction |
| DAT_008CFA88 | Unknown_Font_GlyphCount | UI | int | read | 1 | Count in FUN_00563870 — tracks number of loaded font/image glyphs; initialized from string parsing |
| DAT_005E5130 | LfLfString | setup | char[] | offset | 1 | "aLfLf" string — font/formatting string constant for newline in text |
| DAT_005E51F4 | Com6String | setup | char[] | offset | 1 | "aCom6" string — serial port "COM6" device name string |
| DAT_005E5348 | HingeString | setup | char[] | offset | 1 | "aHinge" string — "Hinge" scene/joint object configuration string |
| DAT_008D39EC | Unknown_DWord_Solver | dynamics | dword | offset | 1 | DWord in FUN_0056fa96 (17KB LDL^T factorization solver) — dynamics constraint workspace parameter |
| DAT_008D0FF0 | Unknown_Double_Solver | dynamics | double | read | 1 | Double in FUN_0056fa96 — dynamics solver workspace constant for LDL^T factorization |
| DAT_008CFEF8 | Unknown_Struct_Solver | dynamics | ptr | offset | 1 | Struct offset in FUN_0056fa96 — dynamics constraint solver workspace block |
| DAT_008D1398 | Unknown_Double_Solver2 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D15F8 | Unknown_Double_Solver3 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D0C68 | Unknown_Double_Solver4 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D1740 | Unknown_Double_Solver5 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D1838 | Unknown_Double_Solver6 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D1938 | Unknown_Double_Solver7 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D0748 | Unknown_Double_Solver8 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D0828 | Unknown_Double_Solver9 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D0928 | Unknown_Double_Solver10 | dynamics | double | write | 1 | Double in FUN_0056fa96 — solver workspace output element |
| DAT_008D3AB8 | Unknown_Double_Solver11 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D1098 | Unknown_Double_Solver12 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D1C48 | Unknown_Double_Solver13 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D1558 | Unknown_Double_Solver14 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D1560 | Unknown_Double_Solver15 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D1440 | Unknown_Double_Solver16 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D17C0 | Unknown_Double_Solver17 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D1A98 | Unknown_Double_Solver18 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D1E30 | Unknown_Double_Solver19 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D16B8 | Unknown_Struct_Solver2 | dynamics | ptr | offset | 1 | Struct offset in FUN_0056fa96 — solver workspace block |
| DAT_008D1BA8 | Unknown_Double_Solver20 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D3A08 | Unknown_DWord_Solver2 | dynamics | dword | offset | 1 | DWord in FUN_0056fa96 — solver workspace parameter |
| DAT_008D20E8 | Unknown_Double_Solver21 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D1DA0 | Unknown_Struct_Solver3 | dynamics | ptr | offset | 1 | Struct offset in FUN_0056fa96 — solver workspace block |
| DAT_008D2118 | Unknown_Double_Solver22 | dynamics | double | read | 1 | Double in FUN_0056fa96 — solver workspace matrix element |
| DAT_008D2350 | Unknown_Struct_Cholesky | dynamics | ptr | offset | 1 | Struct offset in FUN_00575bbd (13KB Cholesky/LDL^T factorizer) — solver workspace |
| DAT_008D2718 | Unknown_Struct_Cholesky2 | dynamics | ptr | offset | 1 | Struct offset in FUN_00575bbd — solver workspace block |
| DAT_008D3BA0 | Unknown_DWord_Cholesky | dynamics | dword | offset | 1 | DWord offset in FUN_00575bbd — solver workspace parameter |
| DAT_008D2ED0 | Unknown_Double_Cholesky | dynamics | double | write | 1 | Double written in FUN_00575bbd — solver workspace output element |
| DAT_008D3488 | Unknown_Struct_Cholesky3 | dynamics | ptr | offset | 1 | Struct offset in FUN_00575bbd — solver workspace block |
| DAT_008D3BF4 | Unknown_Struct_7A980 | runtime | ptr | offset | 1 | Struct ref in FUN_0057a980 — runtime function call bridge |
| DAT_005E53F8 | DDDDDDString | setup | char[] | offset | 1 | "aDDDDDD" string — format string for scene/object parameter |
| DAT_005E5FB8 | ABlockingWindowString | network | char[] | offset | 1 | "aABlockingWindo" string — "a blocking window" Winsock error message |
| DAT_005E57F0 | TheSocketIsMesString | network | char[] | offset | 1 | "aTheSocketIsMes" string — "The socket is message-oriented" Winsock error message |
| DAT_005BAAD8 | Unknown_Struct_5BAAD8 | network | ptr | offset | 1 | Struct reference in FUN_0057e280 — network/mutex struct used with WaitForSingleObject and ReleaseMutex |
| DAT_005BAEF0 | Unknown_Struct_5BAEF0 | runtime | ptr | offset | 1 | Struct reference in FUN_00582ce0 — runtime cleanup/destructor linked list context |
| DAT_005BB1C0 | Unknown_Struct_5BB1C0 | runtime | ptr | offset | 1 | Struct reference in FUN_00584230 — runtime object/allocator context |
| DAT_005E652C | Unknown_Off_5E652C | runtime | ptr | offset | 1 | Pointer offset in FUN_00588a34 — runtime/C++ exception handling vtable reference |
| DAT_008D3E58 | Unknown_DST_Active | runtime | int | read | 1 | Daylight Saving Time flag in FUN_005896ee — set to 0/1/-1 based on GetTimeZoneInformation DST status; used in time conversion |
| DAT_005B8CA8 | Unknown_Struct_Exception | runtime | ptr | offset | 1 | Struct reference in FUN_0058a677 — MSVC exception handling type descriptor |
| DAT_005B8E2C | Unknown_Double_FPU | math_util | double | read | 1 | Double in FUN_0058dd89 — FPU scale factor for fscale instruction in floating-point error handler |
| DAT_008D3F92 | Unknown_Word_CRC | runtime | word | read | 1 | Word in FUN_0058f014 — CRC32/checksum initializer for hash computation (FUN_005968f6 with starting value) |
| DAT_008D3FB1 | Unknown_Byte_Config | runtime | byte | write | 1 | Byte in FUN_0058ffec — config file path/status flag for system initialization |
| DAT_005E74F4 | Unknown_Float_FPU2 | math_util | float | read | 1 | Float in FUN_005908b0 — FPU precision scaling factor for extended-precision division handling |
| DAT_008D406C | Unknown_Word_Format | runtime | word | read | 1 | Word in FUN_0059249b — date/time format parameter for timestamp formatting function |
| DAT_005B9624 | GlobalHeapSelectString | data | char[] | offset | 1 | "aGlobalHeapSele" string — "Global Heap Select" memory/heap debug string |
| DAT_008D3E70 | Unknown_DWord_FileAttr | runtime | dword | read | 1 | DWord in FUN_00595af9 — file attribute/flag used with CreateFile in file creation wrapper |
| DAT_005B9B5C | SNANString | data | char[] | offset | 1 | "a1SNan" string — "1#SNAN" MSVC CRT string for signaling NaN output |
| DAT_008D5A6C | Unknown_DWord_CRT | runtime | dword | read | 1 | DWord in FUN_0059942b — CRT/exception handling parameter stored in constructor |
| DAT_005B9D44 | Unknown_Struct_CRT | runtime | ptr | offset | 1 | Struct ref in FUN_0059aab9 — CRT locale/global init singleton; strlen("C") used for locale setup |
| DAT_005BAB4C | Unknown_VTable_CxxFrame | runtime | ptr | offset | 1 | VTable reference in FUN_0059ca69 — MSVC __CxxFrameHandler exception handler bridge |
