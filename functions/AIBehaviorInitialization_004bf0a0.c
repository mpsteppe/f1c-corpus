int __thiscall sub_4BF0A0(int this, int a2, char a3)
{
  int v3; // esi
  char *v5; // eax
  char v6; // al
  int v7; // edx
  int v8; // edi
  int v9; // esi
  int v10; // eax
  int v11; // ebx
  int v12; // eax
  double v13; // st7
  double v14; // st7
  unsigned __int8 v16; // c0
  unsigned __int8 v17; // c3
  double v18; // st7
  int result; // eax
  int v20; // ecx
  double v21; // st7
  float v22; // [esp+10h] [ebp-1ACh]
  float v23; // [esp+10h] [ebp-1ACh]
  float v24; // [esp+14h] [ebp-1A8h]
  float v25; // [esp+14h] [ebp-1A8h]
  int v26; // [esp+18h] [ebp-1A4h]
  float v27[104]; // [esp+1Ch] [ebp-1A0h] BYREF

  v3 = dword_5C329C;
  v26 = dword_5C329C;
  ArithmeticComparison_a140(&dword_8AB6E4, 1);
  *(float *)(this + 852) = dbl_8AFEA0;
  *(_DWORD *)(this + 856) = a2;
  v5 = (char *)dword_7CE5EC;
  if ( !dword_7CE5EC )
    v5 = byte_5EA438;
  v24 = (double)dword_7D01A0 * 0.0083333338;
  sub_4BE760(this, *(_DWORD *)(this + 864), (int)v5, v24);
  switch ( dword_7CEA5C )
  {
    case 1:
      if ( dword_7C56A4 != 7 )
        goto LABEL_39;
      v21 = 1.0 / flt_8ACF9C;
      v22 = v21;
      if ( v21 == 0.0 )
        goto LABEL_5;
      v6 = 1;
      goto LABEL_6;
    case 2:
LABEL_39:
      AnimationStateSetter(this, 1, 1, 1065353216, 1110704128);
      break;
    default:
      v22 = 0.0;
LABEL_5:
      v6 = 0;
LABEL_6:
      AnimationStateSetter(this, 1, v6, SLODWORD(v22), 1110704128);
      break;
  }
  v7 = 0;
  memset(v27, 0, sizeof(v27));
  do
  {
    *(_DWORD *)(this + 4 * v7) = -1082130432;
    *(_DWORD *)(this + 4 * v7++ + 416) = 0;
  }
  while ( v7 < 104 );
  v8 = 0;
  v25 = flt_5EA3FC;
  v23 = 0.0;
  if ( v3 > 0 )
  {
    do
    {
      v9 = dword_7C54F0[v8];
      v10 = *(_DWORD *)(v9 + 13000);
      if ( v10 != -1 )
      {
        if ( v10 )
        {
          v11 = *(_DWORD *)(v9 + 16444);
          if ( v11 < *(_DWORD *)(this + 860)
            && (dword_7C56A4 == 7 || v11 <= StateFlagsLookup((_DWORD *)dword_7C54F0[v8]))
            && *(_DWORD *)(dword_7C54F0[v8] + 16484) != 1 )
          {
            v12 = *(_DWORD *)(v9 + 16484);
            if ( v12 != 3 && v12 != 2 )
            {
              *(float *)(this + 4 * v8) = RandomVariationScaler(this, v7, v9, *(float *)(this + 844));
              v13 = *(float *)(v9 + 16452);
              if ( *(_DWORD *)(v9 + 16532) <= 1u )
                v13 = 0.0;
              ++*(_DWORD *)(v9 + 16444);
              v14 = (v25 - v13) * (*(float *)(this + 4 * v8) / v25);
              v27[v8] = v14;
              if ( !(v16 | v17) )
                v23 = v14;
              v18 = v14 + *(float *)(this + 852);
              if ( v18 < 0.0 )
                v18 = 0.0;
              *(float *)(v9 + 16536) = v18;
              if ( *(float *)(v9 + 16540) <= 0.0 || *(float *)(v9 + 16540) > (double)*(float *)(this + 4 * v8) )
                *(float *)(v9 + 16540) = *(float *)(this + 4 * v8);
              *(float *)(v9 + 16568) = *(float *)(this + 852) - flt_8ACF90 + v27[v8];
              AIDriverSorting(v9);
              v7 = *(_DWORD *)(v9 + 16444);
              if ( v7 >= *(_DWORD *)(this + 860) || a3 )
              {
                *(_DWORD *)(this + 4 * v8) = -1082130432;
                if ( *(_DWORD *)(v9 + 16484) != 3 )
                  *(_DWORD *)(v9 + 16484) = 1;
              }
            }
          }
        }
      }
      v3 = v26;
      ++v8;
    }
    while ( v8 < v26 );
  }
  result = 0;
  *(float *)(this + 852) = v23 + *(float *)(this + 852);
  if ( v3 > 0 )
  {
    v20 = this + 416;
    do
    {
      ++result;
      v20 += 4;
      *(float *)(v20 - 4) = v23 - v27[result - 1];
    }
    while ( result < v3 );
  }
  return result;
}
