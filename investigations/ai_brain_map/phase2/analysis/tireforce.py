# tireforce.py — C8.2: Python model of TireForce (0x4E9100), read-only research code.
#
# Derived from functions/TireForce_004e9100.c plus capstone disassembly of the call site
# in AIRacingLine (0x425ED9, `fmul st(1)` consumes the dropped return) and of TireForce
# itself (0x4E9100..0x4E92EE). Semantics, with `this` = veh+0xC (so this[N] -> veh + 0xC + 4N):
#
#   v27 = v*v
#   v28 = v27*T[3740] - (v27*wp116 + wp124)*T[3397]
#   v25 = |v27*wp112 - wp120| * T[3397]
#   select table by the FPU compare of v25 with 0.0 (asm: fcomp [0x59e440]; test ah,5; jp):
#     normal (v25 >= 0) -> selector T[3871], table T[3872], next T[3873]
#     else              -> selector T[3855], table T[3856], next T[3857]
#   v12 = v28 * selector; i = (int) frnd(v12)   (frnd = sub_5895A2; its return IS stored)
#   if i < 0: v14 = base[0]; elif i >= 14: i = 13; interpolate base[i], base[i+1]
#   v19 = v14*v14 - v25*v25
#   if v19 <= 0: v22 = 0
#   else:
#     v26 = sqrt(v19)/v14
#     j = (int) frnd(v28 * T[3839]); clamp to 13
#     v22 = interp(T[3840+j], T[3841+j]) * T[3398] * v26
#   v22 = min(v22, T[3919])
#   return v22 + T[3921]*T[3398]*v27 + wp128
#
# MISSING FROM ALL RECORDED LOGS (see phase2/RECORDER_REQUESTS.md): every T[...] entry and
# wp+124/wp+128. The function is therefore parameterized; it cannot be evaluated on
# watch_race2/2b/3 until those fields are logged.
import math

# vehicle-relative offsets of the table fields (this = veh+0xC)
VEH = {
    3397: 0x3520, 3398: 0x3524, 3740: 0x3A7C,
    3839: 0x3C08, 3840: 0x3C0C,
    3855: 0x3C48, 3856: 0x3C4C,
    3871: 0x3C88, 3872: 0x3C8C,
    3919: 0x3D48, 3921: 0x3D50,
}
TABLE_LEN = 15  # arrays at 3840, 3856, 3872; entry j and j+1 are interpolated

MISSING = (
    [dict(id='tire_T%d' % n, hex='0x%X' % VEH[n], n=n, count=TABLE_LEN if n in (3840, 3856, 3872) else 1,
          group='tire_model', note='TireForce 0x4E9100 table/field') for n in sorted(VEH)]
    + [dict(id='tire_T3903', hex='0x3D08', n=3903, count=1, group='tire_model',
            note='TireForceSolver selector'),
       dict(id='tire_T3904', hex='0x3D0C', n=3904, count=TABLE_LEN, group='tire_model',
            note='TireForceSolver table (entries 3904..3918)'),
       dict(id='wp_124', hex='wp+0x7C', n=124, count=1, group='waypoint', note='TireForce a4[1]'),
       dict(id='wp_128', hex='wp+0x80', n=128, count=1, group='waypoint', note='TireForce a4[2]')]
)


def frnd(x):
    """sub_5895A2 = MSVC _frnd: round to nearest integer, ties per FPU mode (nearest-even)."""
    return float(round(x))


def _interp(arr, i, frac):
    """C: v15 = this[N+i]; v16 = this[N+i+1]; v = v15 + (v16-v15)*(frac-i)."""
    a, b = arr[i], arr[i + 1]
    return a + (b - a) * (frac - i)


def tireforce(v, wp112, wp116, wp120, wp124, wp128, T, round_index=True):
    """T is a dict {field: value}; table fields (3840/3856/3872) are lists of 15 floats (adjacent entries)."""
    t = lambda n: T[n]
    v27 = v * v
    v28 = v27 * t(3740) - (v27 * wp116 + wp124) * t(3397)
    v25 = abs(v27 * wp112 - wp120) * t(3397)
    if v25 >= 0.0:
        sel, arr = t(3871), t(3872)
    else:
        sel, arr = t(3855), t(3856)
    v12 = v28 * sel
    f = frnd(v12) if round_index else v12
    i = int(f)
    if i < 0:
        v14 = arr[0]
    else:
        if i >= TABLE_LEN - 1:
            i = TABLE_LEN - 2
        v14 = _interp(arr, i, f)
    v19 = v14 * v14 - v25 * v25
    if v19 <= 0.0:
        v22 = 0.0
    else:
        v26 = math.sqrt(v19) / v14
        f2 = frnd(v28 * t(3839)) if round_index else v28 * t(3839)
        j = int(f2)
        if j < 0:
            v22 = t(3840)[0] * t(3398) * v26
        else:
            if j >= TABLE_LEN - 1:
                j = TABLE_LEN - 2
            v22 = _interp(t(3840), j, f2) * t(3398) * v26
        v22 = min(v22, t(3919))
    return v22 + t(3921) * t(3398) * v27 + wp128


def _selftest():
    T = {}
    for n in (3397, 3398, 3740, 3839, 3855, 3871, 3919, 3921):
        T[n] = 100.0 if n == 3919 else 1.0
    for n in (3840, 3856, 3872):
        T[n] = [float(k) for k in range(TABLE_LEN)]
    val = tireforce(30.0, 0.5, 0.1, 0.2, 0.0, 0.0, T)
    print('tireforce selftest: v=30 -> F=%.6f (finite=%s)' % (val, isinstance(val, float)))


if __name__ == '__main__':
    print('MISSING fields (%d):' % len(MISSING))
    for m in MISSING:
        print('  %-12s %-10s count=%d' % (m['id'], m['hex'], m['count']))
    _selftest()
