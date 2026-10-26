# Recovery wave 1 summary

## Function recovery

- Seed: 50 validated functions.
- New frontier functions selected: 280.
- Direct caller/callee selections: 265.
- Typed `F1CVehicle` field-overlap selections: 11.
- Valid function IR results: 280.
- Invalid results after repair: 0.
- Missing results after repair: 0.
- Total validated function IR after the wave: 330.
- Total generated C++ semantic maps: 330.

## Architecture recovery

- Architecture packets: 16.
- Valid packets after repair: 16.
- Invalid packets after repair: 0.
- Missing packets after repair: 0.
- Packet scopes: 7 generic runtime, 5 vehicle physics, 2 vehicle AI/pit,
  1 math/collision, and 1 UI/platform.

## Worker policy

processes and runs at most 48 managed tasks concurrently. Rejected worker output
is quarantined before repair and never overwrites production mod work.
