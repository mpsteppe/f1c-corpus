void __thiscall sub_5A3FF0(_DWORD *this, const char *a2, int a3, int a4, int a5, __int16 a6)
{
  int v8; // eax
  int v9; // ecx
  const char *v10; // edi
  bool v11; // zf
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // eax
  unsigned int v16; // ebp
  unsigned int v17; // ebp
  int v18; // [esp-4h] [ebp-18h]
  int i; // [esp+10h] [ebp-4h]
  int v20; // [esp+18h] [ebp+4h]

  if ( *a2 )
  {
    v8 = this[25];
    v9 = -1;
    v10 = a2;
    if ( (v8 & 0x20000) != 0 )
    {
      do
      {
        if ( !v9 )
          break;
        v11 = *v10++ == 0;
        --v9;
      }
      while ( !v11 );
      v12 = 3 * (-v9 - 2);
      v13 = this[3];
      v20 = 2 * v12;
      v18 = 2 * v12;
      if ( 2 * v12 <= 768 - v13 )
      {
        v15 = sub_5A8020(this[4], 32, v13, v18);
      }
      else
      {
        v14 = this[4];
        this[3] = 0;
        v15 = sub_5A8020(v14, 96, 0, v18);
      }
      this[5] = v15;
      if ( v15 )
      {
        v16 = 0;
        for ( i = this[3]; v16 < strlen(a2); ++v16 )
          a3 += sub_5A3350((int)this, a2[v16], a3, a4, a5, a6);
        sub_5A80B0(this[4]);
        sub_5B4CC0(a5, 1);
        if ( !dword_7E8D04 )
          sub_5AB360(0);
        sub_5A8250(dword_7E8E5C, this[4], i, v20, this[1070], this[39], this[40], this[42], 0);
        if ( !dword_7E8D04 )
          sub_5AB3A0(0);
        sub_5B4CC0(0, 0);
      }
    }
    else
    {
      v17 = 0;
      do
      {
        if ( !v9 )
          break;
        v11 = *v10++ == 0;
        --v9;
      }
      while ( !v11 );
      if ( -v9 != 2 )
      {
        do
          a3 += sub_5A3350((int)this, a2[v17++], a3, a4, a5, a6);
        while ( v17 < strlen(a2) );
      }
    }
  }
}
