int __thiscall sub_6CB231(_DWORD *this, __int64 a2, int a3)
{
  int result; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  unsigned int v8; // eax
  int v9; // ecx
  int v10; // ecx

  result = sub_6CB1D4(this, HIDWORD(a2) | a2);
  if ( result >= 0 )
  {
    if ( ((WORD2(a2) | (unsigned __int16)a2) & 0x2000) != 0 )
    {
      v5 = *(_DWORD *)(this[5] + 4 * a3);
      v6 = *(_DWORD *)(v5 + 12);
      v7 = *(_DWORD *)(v5 + 16);
      v8 = v6 & 0x7FF | 0xB0000000;
      if ( v7 )
      {
        v9 = v7 - 1;
        if ( v9 )
        {
          v10 = v9 - 1;
          if ( v10 )
          {
            if ( v10 == 1 )
              v8 |= (unsigned int)dword_FF0000;
          }
          else
          {
            v8 |= (unsigned int)&unk_AA0000;
          }
        }
        else
        {
          v8 |= 0x550000u;
        }
      }
      sub_6CB1D4(this, v8);
    }
    return 0;
  }
  return result;
}
