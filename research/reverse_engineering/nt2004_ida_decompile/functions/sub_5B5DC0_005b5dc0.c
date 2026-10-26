void __thiscall sub_5B5DC0(_DWORD *this, int a2, int a3)
{
  int v4; // eax
  _DWORD *v5; // ecx
  _DWORD *v6; // eax
  int v7; // edi
  int v8; // edx
  int v9; // edx
  int v10; // edi
  int v11; // edx
  int v12; // edi

  v4 = this[14];
  if ( (v4 & 0x100) == 0 || (v4 & 0x400) != 0 )
  {
    this[14] = v4 & 0xFFFFFAFF | 0x100;
    if ( !*(_DWORD *)(this[6] + 316) )
    {
      if ( a3 )
        this[8] = sub_5A8020(dword_7E6B48, (_DWORD *)this[7], 160, this[11], this[2]);
      v5 = (_DWORD *)this[8];
      v6 = (_DWORD *)this[3];
      v7 = 12;
      if ( ((unsigned int)&unk_800000 & *(_DWORD *)(this[6] + 20)) != 0 )
        v7 = 16;
      v8 = this[14];
      if ( (v8 & 0x200) != 0 )
      {
        if ( (v8 & 0x800) != 0 )
        {
          v11 = this[2];
          if ( v11 > 0 )
          {
            v12 = 4 * v7;
            do
            {
              *v5 = *v6;
              v5[1] = v6[1];
              v5[2] = v6[2];
              v5[8] = v6[8];
              v5[9] = v6[9];
              v5 += 16;
              v6 = (_DWORD *)((char *)v6 + v12);
              --v11;
            }
            while ( v11 );
          }
        }
      }
      else
      {
        v9 = this[2];
        if ( v9 > 0 )
        {
          v10 = 4 * v7;
          do
          {
            *v5 = *v6;
            v5[1] = v6[1];
            v5[2] = v6[2];
            v5 += 16;
            v6 = (_DWORD *)((char *)v6 + v10);
            --v9;
          }
          while ( v9 );
        }
        this[14] |= 0x200u;
      }
      if ( (*this & 2) != 0 )
      {
        sub_5B6930(a2);
      }
      else if ( (*this & 1) != 0 )
      {
        sub_5B6060(a2);
      }
      else
      {
        sub_5B5F10(a2);
      }
      if ( (*(_DWORD *)(this[6] + 20) & 0x400000) != 0 )
        sub_5B7170(this);
      if ( a3 )
        sub_5A80B0(dword_7E6B48, this[7]);
    }
  }
}
