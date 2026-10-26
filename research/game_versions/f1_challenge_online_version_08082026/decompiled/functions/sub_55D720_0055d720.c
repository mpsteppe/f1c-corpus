void __thiscall sub_55D720(_DWORD *this, int a2, int a3)
{
  bool v4; // zf
  int v5; // eax
  int v6; // eax
  int v7; // edi
  int v8; // edx
  _DWORD *v9; // eax
  _DWORD *v10; // ecx
  int v11; // ecx
  _DWORD *v12; // eax
  _DWORD *v13; // ecx
  int v14; // edx

  v4 = sub_5414F0(dword_8B78A0) == 0;
  v5 = this[14];
  if ( v4 )
  {
    if ( (v5 & 0x100) == 0 || (v5 & 0x400) != 0 )
    {
      v11 = this[6];
      this[14] = v5 & 0xFFFFFAFF | 0x100;
      if ( !*(_DWORD *)(v11 + 316) )
      {
        v7 = a3;
        if ( a3 )
          this[8] = sub_540F00(dword_8B78A0, (_DWORD *)this[7], 160, this[11], this[2]);
        v12 = (_DWORD *)this[8];
        v13 = (_DWORD *)this[3];
        v14 = this[2];
        if ( (this[14] & 0x800) != 0 )
        {
          if ( v14 > 0 )
          {
            do
            {
              *v12 = *v13;
              v12[1] = v13[1];
              v12[2] = v13[2];
              v12[8] = v13[8];
              v12[9] = v13[9];
              v12 += 16;
              v13 += 12;
              --v14;
            }
            while ( v14 );
          }
        }
        else if ( v14 > 0 )
        {
          do
          {
            *v12 = *v13;
            v12[1] = v13[1];
            v12[2] = v13[2];
            v12 += 16;
            v13 += 12;
            --v14;
          }
          while ( v14 );
        }
        if ( (*this & 2) != 0 )
        {
          sub_55E320(a2);
        }
        else if ( (*this & 1) != 0 )
        {
          sub_55DA50(a2);
        }
        else
        {
          sub_55D900(a2);
        }
        if ( (*(_DWORD *)(this[6] + 20) & 0x400000) != 0 )
          sub_55EB30(this);
        goto LABEL_31;
      }
    }
  }
  else if ( (v5 & 0x100) == 0 )
  {
    v6 = v5 | 0x100;
    this[14] = v6;
    if ( (v6 & 0x200) == 0 || *(char *)(this[1] + 156) < 0 )
    {
      v7 = a3;
      if ( a3 )
        this[8] = sub_540F00(dword_8B78A0, (_DWORD *)this[7], 160, this[11], this[2]);
      if ( (this[14] & 0x200) == 0 )
      {
        v8 = this[2];
        v9 = (_DWORD *)this[8];
        v10 = (_DWORD *)this[3];
        if ( v8 > 0 )
        {
          do
          {
            *v9 = *v10;
            v9[1] = v10[1];
            v9[2] = v10[2];
            v9 += 16;
            v10 += 12;
            --v8;
          }
          while ( v8 );
        }
        this[14] |= 0x200u;
      }
      if ( *(char *)(this[1] + 156) < 0 )
        sub_55EBA0(a2);
LABEL_31:
      if ( v7 )
        sub_540F90(dword_8B78A0, this[7]);
    }
  }
}
