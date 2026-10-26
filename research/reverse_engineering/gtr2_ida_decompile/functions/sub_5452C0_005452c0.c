int __thiscall sub_5452C0(int this)
{
  double v2; // st7
  int result; // eax
  float *v4; // esi
  char *v5; // ebx
  int v6; // eax
  int v7; // edx
  float v8; // edx
  float v9; // [esp+0h] [ebp-20h]
  float v10; // [esp+0h] [ebp-20h]
  int v11; // [esp+14h] [ebp-Ch]
  float v12; // [esp+18h] [ebp-8h]
  float v13; // [esp+1Ch] [ebp-4h]

  if ( dword_BE1204 == 2 )
    v2 = sub_5210A0(&dword_BE120C);
  else
    v2 = dbl_FB1D18;
  result = *(_DWORD *)(this + 108);
  v13 = v2;
  v11 = 0;
  if ( result > 0 )
  {
    while ( 1 )
    {
      v4 = *(float **)(*(_DWORD *)(this + 112) + 4 * v11);
      v12 = (v13 - v4[2]) * *(float *)(this + 72);
      if ( v12 < (double)v4[25] )
        break;
      v5 = 0;
      if ( v12 < (double)v4[24] )
      {
        v10 = (v4[24] - v12) * 254.0;
        v5 = &byte_FFFFFF[0x1000000 * sub_4015C0(v10)];
      }
      if ( v13 <= (double)v4[3] && v13 >= (double)v4[2] && v5 )
      {
        sub_5FCDB0(*(_DWORD *)v4, 0, 0);
        sub_5FCDB0(*(_DWORD *)v4, 1, v5);
        sub_5FCDB0(*(_DWORD *)v4, 2, v5);
        sub_5FCDB0(*(_DWORD *)v4, 3, 0);
      }
      else
      {
        v6 = *(_DWORD *)(this + 112);
        v7 = *(_DWORD *)(this + 108) - 1;
        *(_DWORD *)(this + 108) = v7;
        *(_DWORD *)(v6 + 4 * *((_DWORD *)v4 + 1)) = *(_DWORD *)(v6 + 4 * v7);
        *(float *)(*(_DWORD *)(*(_DWORD *)(this + 112) + 4 * *((_DWORD *)v4 + 1)) + 4) = v4[1];
        v8 = *v4;
        v4[1] = NAN;
        sub_5FCB20(LODWORD(v8));
        --v11;
      }
      result = ++v11;
      if ( v11 >= *(_DWORD *)(this + 108) )
        return result;
    }
    v9 = (v4[25] - v12) * 254.0;
    sub_4015C0(v9);
    return off_16C9648();
  }
  return result;
}
