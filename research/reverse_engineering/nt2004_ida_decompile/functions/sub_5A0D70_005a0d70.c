int __thiscall sub_5A0D70(int this, int a2, int a3)
{
  int v3; // eax
  int v4; // ebp
  int v6; // esi
  int v7; // eax
  float *v8; // eax
  double v9; // st7
  double v10; // st7
  double v11; // st6
  double v12; // st5
  double v13; // st4
  double v14; // st5
  int v15; // eax
  int v16; // ecx
  int result; // eax

  v3 = *(_DWORD *)(a2 + 60);
  v4 = 0;
  if ( (v3 & 2) == 0 )
  {
    if ( dword_7F5E78 >= *(_DWORD *)(*(_DWORD *)(this + 480) + 4) )
    {
      return 1;
    }
    else
    {
      v6 = *(_DWORD *)(a2 + 516);
      if ( (v3 & 0x10) != 0 )
      {
        sub_59E210(a2, 0, *(_DWORD *)(a2 + 516));
        v7 = *(_DWORD *)(v6 + 20);
        if ( (v7 & 0x20000000) == 0 )
        {
          *(_DWORD *)(v6 + 20) = v7 | 0x20000000;
          (*(void (__cdecl **)(int, int, int, int))(*(_DWORD *)dword_7E8E58 + 4))(
            dword_7E8E58,
            v6 + 220,
            v6 + 232,
            a2 + 276);
        }
      }
      if ( (*(_BYTE *)(v6 + 20) & 0x40) != 0 )
      {
        v8 = *(float **)(this + 516);
        v9 = v8[60];
        if ( (*(_DWORD *)(a2 + 60) & 0x10) != 0 )
        {
          v10 = v9 - *(float *)(v6 + 240);
          v11 = v8[59] - *(float *)(v6 + 236);
          v12 = v8[58] - *(float *)(v6 + 232);
        }
        else
        {
          v10 = v9 - *(float *)(v6 + 228);
          v11 = v8[59] - *(float *)(v6 + 224);
          v12 = v8[58] - *(float *)(v6 + 220);
        }
        v13 = v12 * v12 + v11 * v11 + v10 * v10;
        v14 = *(float *)(v6 + 24) + **(float **)(this + 480);
        if ( v13 < v14 * v14 && (a3 & 1) != 0 )
        {
          v15 = (*(_DWORD *)(a2 + 60) & 0x10) != 0
              ? sub_5A06B0((_DWORD *)this, a2, (_DWORD *)v6, a3)
              : sub_5A0AD0((_DWORD *)this, a2, (int *)v6, a3);
          if ( v15 > 0 )
          {
            v16 = v15 + dword_7F5E78;
            result = 0;
            dword_7F5E78 = v16;
            return result;
          }
        }
      }
    }
  }
  return v4;
}
