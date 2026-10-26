int __thiscall sub_597C70(_DWORD *this)
{
  int v2; // edi
  int v3; // ecx
  int v4; // eax
  int v5; // edx
  int v6; // eax
  char *v7; // esi
  int v8; // edi
  int v9; // esi
  _DWORD *v10; // eax
  _DWORD *v11; // ebx
  _DWORD *v12; // edi
  int v13; // esi
  int v14; // ecx
  int v15; // edx
  int v16; // eax
  int v17; // ecx
  int v18; // edx
  int v19; // eax

  v2 = 0;
  if ( (int)this[82] > 0 )
  {
    v3 = this[83];
    if ( v3 )
    {
      v4 = *(_DWORD *)(v3 - 4);
      v5 = 3 * v4;
      v6 = v4 - 1;
      v7 = (char *)(v3 + 8 * v5);
      if ( v6 >= 0 )
      {
        v8 = v6 + 1;
        do
        {
          v7 -= 24;
          nullsub_6(v7);
          --v8;
        }
        while ( v8 );
        v2 = 0;
      }
      sub_5BE8AE();
    }
    v9 = this[82];
    v10 = operator new(24 * v9 + 4);
    if ( v10 )
    {
      v11 = v10 + 1;
      *v10 = v9;
      v12 = v10 + 1;
      if ( v9 - 1 >= 0 )
      {
        do
        {
          sub_594070(v12);
          v12 += 6;
          --v9;
        }
        while ( v9 );
      }
      v2 = 0;
    }
    else
    {
      v11 = 0;
    }
    v13 = this[65];
    for ( this[83] = v11; v13; v13 = *(_DWORD *)(v13 + 260) )
    {
      if ( (*(_BYTE *)(v13 + 4) & 0x40) == 0 )
      {
        v14 = *(_DWORD *)(v13 + 236);
        if ( v14 )
        {
          v15 = 24 * v2;
          do
          {
            v16 = *(_DWORD *)(v14 + 516);
            if ( v16 )
            {
              while ( (*(_DWORD *)(v16 + 20) & 0x4000) == 0 )
              {
                v16 = *(_DWORD *)(v16 + 16);
                if ( !v16 )
                  goto LABEL_22;
              }
              *(_DWORD *)(v15 + this[83] + 16) = v14;
              ++v2;
              v15 += 24;
            }
LABEL_22:
            v14 = *(_DWORD *)(v14 + 76);
          }
          while ( v14 );
        }
      }
    }
    v17 = this[67];
    if ( v17 )
    {
      v18 = 24 * v2;
      do
      {
        v19 = *(_DWORD *)(v17 + 516);
        if ( v19 )
        {
          while ( (*(_DWORD *)(v19 + 20) & 0x4000) == 0 )
          {
            v19 = *(_DWORD *)(v19 + 16);
            if ( !v19 )
              goto LABEL_31;
          }
          *(_DWORD *)(v18 + this[83] + 16) = v17;
          v18 += 24;
        }
LABEL_31:
        v17 = *(_DWORD *)(v17 + 76);
      }
      while ( v17 );
    }
  }
  return 0;
}
