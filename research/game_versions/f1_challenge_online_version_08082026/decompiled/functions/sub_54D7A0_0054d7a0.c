int __thiscall sub_54D7A0(int this, float *a2, float *a3, int a4)
{
  double v5; // st7
  int v6; // edx
  double v7; // st6
  double v8; // st5
  int v9; // ebp
  unsigned int v10; // edx
  int v11; // ebx
  float *i; // esi
  double v13; // st7
  float v15; // [esp+18h] [ebp+8h]

  v5 = a2[11] + a3[2];
  v6 = *(_DWORD *)(this + 20);
  v7 = a2[10] + a3[1];
  v8 = a2[9] + *a3;
  v15 = sqrt(v8 * v8 + v7 * v7 + v5 * v5);
  if ( (v6 & 0x10) == 0 )
  {
    if ( v15 < (double)*(float *)(this + 248) && v15 > (double)*(float *)(this + 244) )
    {
      *(_DWORD *)(this + 20) = v6 & 0xFFFFFFF8 | 4;
      return 0;
    }
    goto LABEL_18;
  }
  v9 = *(_DWORD *)(this + 252);
  if ( v9 > 4 && v15 - *(float *)(this + 24) > a2[2]
    || !a4 && (*(float *)(this + 248) * a2[34] < v15 || *(float *)(this + 244) * a2[34] >= v15) )
  {
LABEL_18:
    *(_DWORD *)(this + 20) = v6 & 0xFFFFFFF8 | 2;
    return 0;
  }
  v10 = v6 & 0xFFFFFFF8 | 1;
  v11 = 0;
  *(_DWORD *)(this + 20) = v10;
  if ( v9 <= 0 )
    return 0;
  for ( i = a2 + 65; ; i += 4 )
  {
    v13 = -(*(i - 2) * *a3) - *(i - 1) * a3[1] - *i * a3[2] - i[1];
    if ( v13 > *(float *)(this + 24) )
    {
      *(_DWORD *)(this + 20) = v10 & 0xFFFFFFFC | 2;
      return 0;
    }
    if ( v13 > -*(float *)(this + 24) )
      break;
    if ( ++v11 >= v9 )
      return 0;
  }
  *(_DWORD *)(this + 20) = v10 & 0xFFFFFFFA | 4;
  return 0;
}
