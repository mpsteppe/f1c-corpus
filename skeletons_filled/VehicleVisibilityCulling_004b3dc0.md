## VehicleVisibilityCulling_004b3dc0 — VehicleVisibilityCulling

**Summary:** Culls non-visible vehicles by sorting them by camera-space distance and marking only the nearest N (up to VisibleVehicleIndex). When vehicle visibility state changes, triggers audio (engine sound enable) for newly visible vehicles and disables flags/UI for newly hidden ones. Called from RenderScreenSave during frame render.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderScreenSave (004b40a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004b3d70 | FloatComparator | R | Comparator callback for sorting vehicles by distance |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e660 | flt_59E660 | R | VehicleBodyDamping [DERIVED] |
| 0059e8c8 | flt_59E8C8 | R | Physics_ConvergenceThreshold [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount — number of active vehicles |
| 005ea510 | dword_5EA510 | R | SessionManager — used to get camera/session object |
| 007c54e0 | dword_7C54E0 | R | postProcessInput — camera position read at offsets +13536/+13540/+13544 |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray — array of pointers to vehicle data |
| 007cfc8c | dword_7CFC8C | R | VisibleVehicleIndex — max number of vehicles to show (culling threshold index) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c870 | VirtualDispatchHelper | Get session object interface pointer |
| 004e0ed0 | AudioSoundEffectController | Start engine sound for newly visible vehicle |
| 0054c030 | FlagFieldBitManipulation | Clear visibility-related flags on vehicle when hidden |
| 0054c1b0 | UIWidgetRecursiveStateUpdate | Update UI widget visibility state |
| 00566e40 | EulerToRotationMatrix | Convert camera Euler angles to 3x3 rotation matrix |
| 005890aa | sub_5890AA | Sort vehicle distance array; returns sorted distances |

**Guard conditions:** 
1. If session object field at +112 is non-zero OR VehicleCount <= VisibleVehicleIndex: all vehicles pass (memset visibility to 1), skip culling math.
2. If dword_7C54E0 (postProcessInput) is zero: return early (no camera data).
3. If VehicleCount <= 0: skip all loops.
4. Core culling: vehicles sorted by camera-space distance; only those below distance threshold at VisibleVehicleIndex are marked visible (1) vs hidden (0).
5. State change detection: only triggers audio/UI/flags when visibility bit differs from previous frame.
