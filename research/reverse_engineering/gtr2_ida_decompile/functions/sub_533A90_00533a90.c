int __thiscall sub_533A90(int this, int a2, char a3)
{
  int v3; // ebx
  char *v5; // eax
  int v6; // ebp
  double v7; // st7
  char v8; // al
  int v9; // edx
  int v10; // edi
  int v11; // ebx
  int v12; // eax
  double v13; // st7
  double v14; // st7
  double v15; // st7
  unsigned __int8 v17; // c0
  unsigned __int8 v18; // c3
  double v19; // st7
  int result; // eax
  int v21; // ecx
  int v22; // esi
  float v23; // [esp+8h] [ebp-1B0h]
  float v24; // [esp+Ch] [ebp-1ACh]
  float v25; // [esp+10h] [ebp-1A8h]
  int v26; // [esp+14h] [ebp-1A4h]
  float v27[104]; // [esp+18h] [ebp-1A0h] BYREF

  v3 = dword_757C10;
  v26 = dword_757C10;
  sub_521110(&dword_BE1204, 1);
  *(float *)(this + 852) = dbl_FB1D18;
  *(_DWORD *)(this + 856) = a2;
  v5 = dword_B6F6A8;
  v6 = 0;
  v25 = (double)dword_B71FD8 * 0.0099999998;
  if ( !dword_B6F6A8 )
    v5 = (char *)WindowName;
  sub_530780(this, *(_DWORD *)(this + 864), v5, v25);
  switch ( dword_B6FD6C )
  {
    case 1:
      v7 = 1.0;
      if ( *(_DWORD *)dword_B640C8 == 6 )
      {
        v7 = 1.0 / flt_FADE28;
        if ( v7 == 0.0 )
          goto LABEL_5;
      }
      v8 = 1;
      break;
    case 2:
      v7 = 1.0;
      v8 = 1;
      break;
    default:
      v7 = 0.0;
LABEL_5:
      v8 = 0;
      break;
  }
  *(float *)(this + 836) = v7;
  *(_BYTE *)(this + 833) = v8;
  v9 = 0;
  *(_BYTE *)(this + 832) = 1;
  *(_DWORD *)(this + 848) = 1110704128;
  memset(v27, 0, sizeof(v27));
  do
  {
    *(_DWORD *)(this + 4 * v9) = -1082130432;
    *(_DWORD *)(this + 4 * v9++ + 416) = 0;
  }
  while ( v9 < 104 );
  v25 = flt_91BDE4;
  v24 = 0.0;
  if ( v3 > 0 )
  {
    do
    {
      v10 = *(&dword_91E088 + v6);
      if ( *(_DWORD *)(v10 + 14820) == 1 )
      {
        v11 = *(_DWORD *)(v10 + 19284);
        if ( v11 < *(_DWORD *)(this + 860)
          && (*(_DWORD *)dword_B640C8 == 6 || v11 <= sub_41FCB0((_DWORD *)*(&dword_91E088 + v6)))
          && *(_DWORD *)(*(&dword_91E088 + v6) + 19380) != 1 )
        {
          v12 = *(_DWORD *)(v10 + 19380);
          if ( v12 != 3 && v12 != 2 )
          {
            *(float *)(this + 4 * v6) = sub_530A70((_DWORD *)this, v10, *(float *)(this + 844));
            v13 = *(float *)(v10 + 19292);
            if ( *(_DWORD *)(v10 + 19428) <= 1u )
              v13 = 0.0;
            v14 = (v25 - v13) / v25;
            ++*(_DWORD *)(v10 + 19284);
            v15 = v14 * *(float *)(this + 4 * v6);
            v27[v6] = v15;
            if ( !(v17 | v18) )
              v24 = v15;
            v19 = v15 + *(float *)(this + 852);
            if ( v19 < 0.0 )
              v19 = 0.0;
            *(float *)(v10 + 19432) = v19;
            if ( *(float *)(v10 + 19436) <= 0.0 || *(float *)(this + 4 * v6) < (double)*(float *)(v10 + 19436) )
              *(_DWORD *)(v10 + 19436) = *(_DWORD *)(this + 4 * v6);
            if ( *(float *)(v10 + 19436) <= 0.0 || *(float *)(this + 4 * v6) < (double)*(float *)(v10 + 19448) )
              *(_DWORD *)(v10 + 19448) = *(_DWORD *)(this + 4 * v6);
            *(float *)(v10 + 19464) = *(float *)(this + 852) - flt_FADE1C + v27[v6];
            sub_530CE0(v10);
            if ( *(_DWORD *)(v10 + 19284) >= *(_DWORD *)(this + 860) || a3 )
            {
              *(_DWORD *)(this + 4 * v6) = -1082130432;
              sub_52D900((_DWORD *)(v10 + 19272));
            }
          }
        }
        v3 = v26;
      }
      ++v6;
    }
    while ( v6 < v3 );
  }
  result = 0;
  *(float *)(this + 852) = v24 + *(float *)(this + 852);
  if ( v3 >= 4 )
  {
    v21 = this + 420;
    do
    {
      result += 4;
      v21 += 16;
      *(float *)(v21 - 20) = v24 - *(&v23 + result);
      *(float *)(v21 - 16) = v24 - *(&v24 + result);
      *(float *)(v21 - 12) = v24 - *(&v25 + result);
      *(float *)(v21 - 8) = v24 - v27[result - 1];
    }
    while ( result < v3 - 3 );
  }
  if ( result < v3 )
  {
    v22 = this + 4 * result + 416;
    do
    {
      ++result;
      v22 += 4;
      *(float *)(v22 - 4) = v24 - v27[result - 1];
    }
    while ( result < v3 );
  }
  return result;
}
