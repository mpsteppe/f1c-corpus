char __thiscall sub_4D7550(int this, int *a2, int a3, float a4)
{
  double v5; // st7
  int i; // ecx
  double v7; // st7
  int j; // edi
  unsigned int v9; // eax
  int v10; // eax
  float v12; // [esp+4h] [ebp-D4h]
  int v13[52]; // [esp+8h] [ebp-D0h] BYREF

  if ( !*(_BYTE *)(this + 2140) )
  {
    if ( a3 )
      sub_4D54F0((int **)this, a3);
    v5 = sub_57B7C0(this + 1764);
    v12 = v5;
    if ( v5 > 0.025 && fabs(a4 - *(float *)(this + 1840)) > 0.001 )
    {
      sub_57B690(this + 1764);
      for ( i = sub_42F2D0(&unk_62BF64); i != 49; i = sub_42F310(&unk_62BF64) )
      {
        v7 = v12 + *(float *)(this + 4 * i + 1844);
        *(float *)(this + 4 * i + 1844) = v7;
        if ( v7 > *(float *)(this + 2144) )
        {
          *(_DWORD *)(this + 4 * i + 1844) = 0;
          sub_4EE360((int)v13, a4);
          sub_4D5660((_DWORD *)this, (int)v13, SLODWORD(a4));
        }
      }
      for ( j = *(_DWORD *)(this + 1760); j < 49; j += 12 )
        sub_4D5A50((_DWORD *)this, j);
      *(_DWORD *)(this + 1760) = (*(_DWORD *)(this + 1760) + 1) % 12;
    }
    *(float *)(this + 1840) = a4;
    if ( *a2 > 0 )
    {
      sub_4D1930(a2);
      while ( sub_4D18F0(a2, v13) )
      {
        switch ( (unsigned int)v13[0] >> 28 )
        {
          case 1u:
            v9 = HIWORD(v13[0]) & 0x3F;
            if ( v9 && v9 != 7 )
              goto LABEL_18;
            break;
          case 2u:
          case 3u:
          case 4u:
          case 6u:
LABEL_18:
            sub_4D5660((_DWORD *)this, (int)v13, SLODWORD(a4));
            break;
          default:
            break;
        }
      }
      v10 = *(_DWORD *)(this + 1320) + (*(_DWORD *)(this + 1328) << 7);
      if ( v10 && *(float *)(this + 2144) + *(float *)(v10 + 60) <= a4 )
        sub_4D6300((_DWORD *)this, a4);
    }
  }
  return 0;
}
