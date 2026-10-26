int __thiscall sub_6C6237(_DWORD *this, int a2, unsigned int *a3)
{
  int v3; // edx
  unsigned int v4; // eax
  _DWORD *v5; // edx
  int v6; // eax
  int v7; // edx
  int v8; // edx
  int v9; // edx

  v3 = *(_DWORD *)(a2 + 20);
  v4 = 0;
  if ( v3 != -1 )
  {
    v5 = *(_DWORD **)(this[5] + 4 * v3);
    if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * v5[1]) + 4) & 8) != 0 )
    {
      v6 = v5[3];
      v7 = v5[4];
      v4 = v6 & 0x7FF | 0xB0001000;
      if ( v7 )
      {
        v8 = v7 - 1;
        if ( v8 )
        {
          v9 = v8 - 1;
          if ( v9 )
          {
            if ( v9 == 1 )
              v4 |= (unsigned int)dword_FF0000;
          }
          else
          {
            v4 |= (unsigned int)&unk_AA0000;
          }
        }
        else
        {
          v4 |= 0x550000u;
        }
      }
      if ( !*(_DWORD *)(a2 + 24) )
        v4 |= 0xD000000u;
    }
  }
  if ( a3 )
    *a3 = v4;
  return 0;
}
