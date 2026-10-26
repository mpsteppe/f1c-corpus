void __thiscall sub_60BB00(int *this, _DWORD *Block, int a3)
{
  void **v4; // eax
  int *v5; // ecx
  _DWORD *v6; // esi
  int v7; // eax
  void **v8; // eax
  void **v9; // eax
  _DWORD *v10; // esi
  int v11; // eax
  void **v12; // eax
  void **v13; // eax
  _DWORD *v14; // eax
  int v15; // eax
  void **v16; // eax

  if ( Block )
  {
    if ( (*Block & 0x40000) != 0 )
    {
      v4 = (void **)this[168];
      v5 = this + 168;
      this[170] = (int)v4;
      if ( !v4 )
        goto LABEL_12;
      v6 = *v4;
      if ( !*v4 )
        goto LABEL_12;
      while ( v6 != Block )
      {
        v7 = this[170];
        if ( v7 )
          this[170] = *(_DWORD *)(v7 + 4);
        v8 = (void **)this[170];
        if ( v8 )
        {
          v6 = *v8;
          if ( *v8 )
            continue;
        }
        goto LABEL_12;
      }
      sub_59F730(v5, (int)v6, 1);
      if ( !v6 )
      {
LABEL_12:
        v9 = (void **)this[173];
        this[175] = (int)v9;
        if ( !v9 )
          goto LABEL_21;
        v10 = *v9;
        if ( !*v9 )
          goto LABEL_21;
        while ( v10 != Block )
        {
          v11 = this[175];
          if ( v11 )
            this[175] = *(_DWORD *)(v11 + 4);
          v12 = (void **)this[175];
          if ( v12 )
          {
            v10 = *v12;
            if ( *v12 )
              continue;
          }
          goto LABEL_21;
        }
        sub_59F730(this + 173, (int)v10, 1);
        if ( !v10 )
        {
LABEL_21:
          v13 = (void **)this[188];
          this[190] = (int)v13;
          if ( v13 )
          {
            v14 = *v13;
            if ( v14 )
            {
              while ( v14 != Block )
              {
                v15 = this[190];
                if ( v15 )
                  this[190] = *(_DWORD *)(v15 + 4);
                v16 = (void **)this[190];
                if ( v16 )
                {
                  v14 = *v16;
                  if ( v14 )
                    continue;
                }
                return;
              }
              sub_59F730(this + 188, (int)v14, 1);
            }
          }
        }
      }
    }
    else
    {
      j__free(Block);
    }
  }
}
