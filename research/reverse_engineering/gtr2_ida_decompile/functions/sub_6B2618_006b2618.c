int __thiscall sub_6B2618(_DWORD *this, __int64 a2, int a3)
{
  int result; // eax
  unsigned int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx

  result = sub_6CB1D4(HIDWORD(a2) | a2);
  if ( result >= 0 )
  {
    if ( ((WORD2(a2) | (unsigned __int16)a2) & 0x2000) != 0 && (unsigned __int16)this[50] >= 0x200u )
    {
      if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * a3) + 4)) + 4) & 0x10) != 0 )
      {
        v5 = -253491200;
      }
      else
      {
        v6 = *(_DWORD *)(4 * a3 + this[5]);
        v7 = *(_DWORD *)(v6 + 12);
        v8 = *(_DWORD *)(v6 + 16);
        v5 = v7 & 0x7FF | 0xB0000000;
        if ( v8 )
        {
          v9 = v8 - 1;
          if ( v9 )
          {
            v10 = v9 - 1;
            if ( v10 )
            {
              if ( v10 == 1 )
                v5 |= (unsigned int)dword_FF0000;
            }
            else
            {
              v5 |= (unsigned int)&unk_AA0000;
            }
          }
          else
          {
            v5 |= 0x550000u;
          }
        }
      }
      sub_6CB1D4(v5);
    }
    return 0;
  }
  return result;
}
