# .rdata Constants Reference

## Confirmed Constants

| Address | Value | Meaning | Source |
|---------|-------|---------|--------|
| _DAT_0059e420 | 1.0 | One comparison | Global |
| _DAT_0059e430 | 0.0 | Zero comparison | Global |
| _DAT_0059e440 | 0.0 (float) | Zero float | Global |
| _DAT_0059e460 | 0.01 | Percentage scalar | Weather |
| _DAT_0059e478 | 0.01 | Default interpolation | AI DB |
| _DAT_0059e474 | Slider<=100 interpolation rate | AI DB |
| _DAT_0059e448 | Slider>100 interpolation rate | AI DB |
| _DAT_0059e7d8 | 0.5 | Halving constant | Physics |
| _DAT_0059e7e0 | 2.0 | Doubling constant | Physics |
| _DAT_0059e7f8 | BumpAmp multiplier | Track materials |
| _DAT_0059e880 | 0.5 | Halving constant | Physics |
| _DAT_0059e898 | 90.0 | Camber angle limit (degrees) | Tire |
| _DAT_0059e890 | Camber constant | Tire |
| _DAT_0059e9c0 | Time conversion | Weather |
| _DAT_0059ea38 | RPM display scalar | Engine |
| _DAT_0059ea58 | Gravity constant | Physics |
| _DAT_0059ea60 | 0.5 | Physics constant |
| _DAT_0059eac8 | 273.15 | Celsius->Kelvin offset | Engine/Tire |
| _DAT_0059ec10 | 2.0 | Spline constant | Tire |
| _DAT_0059ec50 | Camber sensitivity scalar | Tire |
| _DAT_0059ec58 | Load normalization scalar | Tire |
| _DAT_0059ec60 | Camber factor 2 scalar | Tire |
| _DAT_0059ec68 | Camber factor 1 scalar | Tire |
| _DAT_0059ed18 | Weather noise scalar | Weather |
| _DAT_0059ed28 | Bump frequency constant | Track materials |
| _DAT_0059e85c | 22.0 | RaceAbility reference max | AI |
| _DAT_0059e854 | Unknown scalar | Vehicle scene |
| _DAT_0059e43c | 1.0 | Interpolation anchor | AI DB |
| _DAT_0059e65c | Rotation conversion | Pit crew |
| _DAT_0059e6f8 | 100.0 | Percentage conversion | Weather |
| _DAT_0059e5fc | Time step per weather change | Weather |
| _DAT_005acb08 | Minute threshold | Weather |
| _DAT_0059e9f8 | Track config threshold | Track config |
| _DAT_005ad258 | RPM->rad/s (2*pi/60) | Engine |
| _DAT_0059e4dc | 2.0 | Scene extent scalar | SearchGrid |

## Source Build Path
Original source: D:\dev\F1_1999_2002\Source\ (from assert strings)

## Source Files Identified
ai_db.cpp, dynman.cpp, game.cpp, garage.cpp, hdvehicle.cpp, hwinput.cpp,
osman.cpp, onscreen.cpp, options.cpp, pitcrew.cpp, plrfile.cpp, render.cpp,
camera.cpp, searchgrid.cpp, setup.cpp, sound.cpp, specialfx.cpp, steward.cpp,
tire_manager.cpp, util.cpp, vehload.cpp, vehgf.cpp, vidman.cpp, weather.cpp
