int __thiscall sub_4F5470(int this)
{
  double v2; // st7
  int result; // eax
  float *v4; // esi
  int v5; // ebp
  int v6; // ebx
  int v7; // [esp+4h] [ebp-18h]
  float v8; // [esp+8h] [ebp-14h]
  float v9; // [esp+Ch] [ebp-10h]
  float v10; // [esp+10h] [ebp-Ch]
  float v11; // [esp+10h] [ebp-Ch]

  if ( dword_7D5DA4 == 2 )
    v2 = sub_4D9E20(&dword_7D5DAC);
  else
    v2 = dbl_7DA9D0;
  result = *(_DWORD *)(this + 108);
  v9 = v2;
  v7 = 0;
  if ( result > 0 )
  {
    do
    {
      v4 = *(float **)(*(_DWORD *)(this + 112) + 4 * v7);
      v5 = 0;
      v8 = (v9 - v4[2]) * *(float *)(this + 72);
      if ( v8 < (double)v4[25] )
      {
        v10 = (v4[25] - v8) * 254.0;
        v5 = ((int)v10 << 24) + 0xFFFFFF;
      }
      v6 = 0;
      if ( v8 < (double)v4[24] )
      {
        v11 = (v4[24] - v8) * 254.0;
        v6 = ((int)v11 << 24) + 0xFFFFFF;
      }
      if ( v9 <= (double)v4[3] && v9 >= (double)v4[2] && (v5 || v6) )
      {
        sub_5B0D00(*(_DWORD *)v4, 0, v5);
        sub_5B0D00(*(_DWORD *)v4, 1, v6);
        sub_5B0D00(*(_DWORD *)v4, 2, v6);
        sub_5B0D00(*(_DWORD *)v4, 3, v5);
      }
      else
      {
        sub_4F2B40((_DWORD *)this, v4);
        --v7;
      }
      result = ++v7;
    }
    while ( v7 < *(_DWORD *)(this + 108) );
  }
  return result;
}
