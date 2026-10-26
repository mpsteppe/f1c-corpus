int __thiscall sub_545BB0(_DWORD *this)
{
  int v2; // edi
  int v3; // ecx
  int v4; // eax
  void *v5; // ebx
  int v6; // edx
  int v7; // eax
  int v8; // esi
  int v9; // edi
  int v10; // esi
  _DWORD *v11; // eax
  _DWORD *v12; // ebx
  _DWORD *v13; // edi
  int v14; // esi
  int v15; // ecx
  int v16; // edx
  int v17; // eax
  int v18; // ecx
  int v19; // edx
  int v20; // eax

  v2 = 0;
  if ( (int)this[93] > 0 )
  {
    v3 = this[94];
    if ( v3 )
    {
      v4 = *(_DWORD *)(v3 - 4);
      v5 = (void *)(v3 - 4);
      v6 = 3 * v4;
      v7 = v4 - 1;
      v8 = v3 + 8 * v6;
      if ( v7 >= 0 )
      {
        v9 = v7 + 1;
        do
        {
          v8 -= 24;
          nullsub_3();
          --v9;
        }
        while ( v9 );
        v2 = 0;
      }
      sub_587BCF(v5);
    }
    v10 = this[93];
    v11 = (_DWORD *)sub_587C03(24 * v10 + 4);
    if ( v11 )
    {
      v12 = v11 + 1;
      *v11 = v10;
      v13 = v11 + 1;
      if ( v10 - 1 >= 0 )
      {
        do
        {
          sub_548E00(v13);
          v13 += 6;
          --v10;
        }
        while ( v10 );
      }
      v2 = 0;
    }
    else
    {
      v12 = 0;
    }
    v14 = this[64];
    for ( this[94] = v12; v14; v14 = *(_DWORD *)(v14 + 260) )
    {
      if ( (*(_BYTE *)(v14 + 4) & 0x40) == 0 )
      {
        v15 = *(_DWORD *)(v14 + 236);
        if ( v15 )
        {
          v16 = 24 * v2;
          do
          {
            v17 = *(_DWORD *)(v15 + 516);
            if ( v17 )
            {
              while ( (*(_DWORD *)(v17 + 20) & 0x20000) == 0 )
              {
                v17 = *(_DWORD *)(v17 + 16);
                if ( !v17 )
                  goto LABEL_22;
              }
              *(_DWORD *)(v16 + this[94] + 16) = v15;
              ++v2;
              v16 += 24;
            }
LABEL_22:
            v15 = *(_DWORD *)(v15 + 76);
          }
          while ( v15 );
        }
      }
    }
    v18 = this[66];
    if ( v18 )
    {
      v19 = 24 * v2;
      do
      {
        v20 = *(_DWORD *)(v18 + 516);
        if ( v20 )
        {
          while ( (*(_DWORD *)(v20 + 20) & 0x20000) == 0 )
          {
            v20 = *(_DWORD *)(v20 + 16);
            if ( !v20 )
              goto LABEL_31;
          }
          *(_DWORD *)(v19 + this[94] + 16) = v18;
          v19 += 24;
        }
LABEL_31:
        v18 = *(_DWORD *)(v18 + 76);
      }
      while ( v18 );
    }
  }
  return 0;
}
