int __thiscall sub_4FCAA0(int this)
{
  const char *v2; // eax
  double v3; // st7
  double v4; // st7
  int result; // eax
  int v6; // [esp+8h] [ebp-10Ch] BYREF
  int v7; // [esp+Ch] [ebp-108h] BYREF
  int v8; // [esp+10h] [ebp-104h] BYREF
  _BYTE v9[256]; // [esp+14h] [ebp-100h] BYREF

  DualLinkedListDestruction();
  if ( !dword_7CF080 )
  {
    sub_4FD8B0(0.0, 432000.0);
    v2 = dword_5EC438;
    if ( !dword_5EC438 )
      v2 = byte_5EA438;
    StringFormatWithBufferOverflowCheck(v9, "%sweather.txt", v2);
    WeatherConditionsFileWriter(v9);
  }
  *(_DWORD *)(this + 164) = -1082130432;
  *(_DWORD *)(this + 24) = -1082130432;
  *(_DWORD *)(this + 12) = 1065353216;
  *(_DWORD *)(this + 16) = -1;
  ShortFieldAccessor(&v8, &v6, &v7);
  *(float *)(this + 180) = (double)v8 * 0.0039215689;
  *(float *)(this + 184) = (double)v6 * 0.0039215689;
  *(float *)(this + 188) = (double)v7 * 0.0039215689;
  GetOrientationAngleValues(this + 216, this + 220);
  FieldGetter_3a60(this + 224);
  ClampedReciprocalWithGuard(1040187392);
  v3 = 0.0099999998 - *(float *)(this + 224);
  *(_DWORD *)(this + 192) = 1061158912;
  *(_DWORD *)(this + 196) = 1061158912;
  v4 = v3 * *(float *)(this + 168);
  *(_DWORD *)(this + 200) = 1061158912;
  *(float *)(this + 236) = v4 + *(float *)(this + 224);
  *(_DWORD *)(this + 204) = 1056964608;
  *(_DWORD *)(this + 208) = 1056964608;
  *(_DWORD *)(this + 212) = 1056964608;
  *(_DWORD *)(this + 240) = 0;
  *(_DWORD *)(this + 244) = 1125515264;
  *(_DWORD *)(this + 248) = 1008981770;
  *(_DWORD *)(this + 228) = 1127153664;
  *(_DWORD *)(this + 232) = 1143521280;
  ValueClampRange(0.5, 0.0);
  result = sub_4FBA10((float *)(this + 264));
  *(_BYTE *)(this + 452) = 0;
  return result;
}

