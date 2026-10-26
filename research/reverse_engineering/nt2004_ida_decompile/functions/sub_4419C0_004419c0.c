int __thiscall sub_4419C0(_DWORD *this, double *a2)
{
  int v3; // eax
  int v4; // esi
  int v5; // ebx
  long double v6; // st7
  long double v7; // st6
  int result; // eax
  long double v9; // [esp+10h] [ebp-30h] BYREF
  long double v10; // [esp+18h] [ebp-28h]
  long double v11; // [esp+20h] [ebp-20h]
  double v12[3]; // [esp+28h] [ebp-18h] BYREF

  v3 = sub_579ED0(512);
  v4 = this[1541];
  v5 = v3;
  v12[0] = *a2 + *(double *)(v4 + 4);
  v12[1] = *(double *)(v4 + 12) + a2[1];
  v12[2] = *(double *)(v4 + 20) + a2[2];
  v9 = -asin(*(double *)(v4 + 68));
  if ( fabs(*(double *)(v4 + 68)) == 1.0 )
  {
    v6 = -*(double *)(v4 + 76);
    v7 = *(double *)(v4 + 28);
    v11 = 0.0;
    v10 = atan2(v6, v7);
  }
  else
  {
    v10 = atan2(*(double *)(v4 + 44), *(double *)(v4 + 92));
    v11 = atan2(*(double *)(v4 + 52), *(double *)(v4 + 60));
  }
  result = sub_581E90(v4, v12, &v9, 0);
  if ( v5 != 512 )
    return sub_579F10(v5);
  return result;
}
