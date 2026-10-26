| DAT_005c73b8 | aNationality | ui | ptr | read | 3 | UI label "Nationality" for driver nationality selector |
| DAT_005d2310 | aRacetime | ui | ptr | read | 3 | UI label/config key "RaceTime" for race time settings |
| DAT_008ad3a4 | AudioChannel4 | audio | int | read | 3 | Audio channel handle index 4 of 5, plays/stops via FUN_00553700 |
| DAT_005d8a60 | SSE_CONST_0_CubicInterp | math | float | read | 3 | SSE vector constant for Hermite/cubic interpolation polynomial evaluation |
| DAT_008b6ab8 | AudioBufferLoopBoundary | audio | int | write | 3 | Loop boundary in audio/network buffer processing, set to 0 in init |
| DAT_008d2540 | ConstraintMatrix_Body0_DOF5 | dynamics | double | both | 3 | LDL^T constraint matrix element for body 0, degree of freedom 5 |
| DAT_008d2d90 | ConstraintMatrix_Body3_Row6 | dynamics | double | both | 3 | LDL^T constraint matrix element for body 3, row 6, stride 24 |
| DAT_008d30d8 | ConstraintMatrix_Body5_6 | dynamics | double | both | 3 | LDL^T constraint matrix element in body 5-6 range |
| DAT_005e7718 | MathTableBoundary_5E7640 | math | double | read | 3 | MSVC CRT math constant/table boundary for atan/asin/log/exp at 0x5e7640 |
| DAT_007cb2fc | SCREEN_WIDTH | renderer | int | read | 2 | Window width in pixels, assigned to screen width offset 0x64 |
| DAT_0059e6a4 | MIN_VELOCITY_THRESHOLD | physics | float | read | 2 | Minimum velocity threshold for collision response, below this no forces applied |
| DAT_0059e788 | SessionLengthThreshold_11 | game_logic | double | read | 2 | Elapsed time threshold for session length category (~12 thresholds) |
| DAT_0059e8a8 | AIOvertakeThreshold | ai | float | read | 2 | AI overtaking/positioning threshold for steering angle and passing logic |
| DAT_007cec78 | PitTimerVisible | race | byte | read | 2 | Pit timer visibility flag in timer/pit display logic (already in docs/12) |
| DAT_005c3f94 | vtable_UIWidget_00432a70 | ui | ptr | read | 2 | Vtable pointer for C++ UI widget class, used in constructor/destructor |
| DAT_007cca50 | UISliderMinThreshold | ui | float | both | 2 | UI slider minimum value threshold, compared against vehicle struct offset 0x1140 |
| DAT_007cd110 | UIElementFloat_7CD110 | ui | float | both | 2 | UI element float state, init to 0.0 in sub_44CB74 |
| DAT_007ccfac | UIElementFloat_7CCFAC | ui | float | both | 2 | UI element float state, init to 0 in FUN_0044d1c0 |
| DAT_007ccf18 | UIElementSelector_7CCF18 | ui | ptr | read | 2 | UI element pointer/selector in factory dispatch (~30 targets) |
