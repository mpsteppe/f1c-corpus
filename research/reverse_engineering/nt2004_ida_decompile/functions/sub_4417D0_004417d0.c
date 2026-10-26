_DWORD *__thiscall sub_4417D0(int this, double *a2, int a3)
{
  int v4; // ebx
  int v5; // ecx
  double v6; // st7
  double v7; // st6
  _DWORD *result; // eax
  int v9; // ecx
  double v10[5]; // [esp+10h] [ebp-78h] BYREF
  double v11; // [esp+38h] [ebp-50h]
  double v12; // [esp+40h] [ebp-48h]
  double v13; // [esp+48h] [ebp-40h]
  double v14; // [esp+50h] [ebp-38h]
  double v15; // [esp+58h] [ebp-30h]
  double v16; // [esp+60h] [ebp-28h]
  double v17; // [esp+68h] [ebp-20h]
  double v18; // [esp+70h] [ebp-18h]
  double v19; // [esp+78h] [ebp-10h]
  double v20; // [esp+80h] [ebp-8h]

  v4 = sub_579ED0(512);
  sub_57EAD0(a3);
  v5 = *(_DWORD *)(this + 6164);
  v6 = v12 * *(double *)(this + 6176) + v13 * *(double *)(this + 6184) + v14 * *(double *)(this + 6192);
  v7 = v15 * *(double *)(this + 6176) + v16 * *(double *)(this + 6184) + v17 * *(double *)(this + 6192);
  v11 = v18 * *(double *)(this + 6176) + v19 * *(double *)(this + 6184) + v20 * *(double *)(this + 6192);
  v10[0] = *a2 - v6;
  v10[1] = a2[1] - v7;
  v10[2] = a2[2] - v11;
  sub_581E90(v5, v10, a3, 0);
  *(_DWORD *)(this + 196) = 0;
  result = (_DWORD *)(this + 952);
  v9 = 4;
  do
  {
    *(result - 8) = -1;
    *(result - 7) = -1048577;
    *result = -1;
    result[1] = -1048577;
    result += 314;
    --v9;
  }
  while ( v9 );
  if ( v4 != 512 )
    return (_DWORD *)sub_579F10(v4);
  return result;
}
