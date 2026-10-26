void __thiscall sub_60BCD0(int *this, _DWORD *Block)
{
  void **v3; // eax
  int *v4; // ecx
  _DWORD *v5; // esi
  int v6; // eax
  void **v7; // eax
  void **v8; // eax
  _DWORD *v9; // eax
  int v10; // eax
  void **v11; // eax

  if ( Block )
  {
    if ( (*Block & 0x40000) != 0 )
    {
      v3 = (void **)this[178];
      v4 = this + 178;
      this[180] = (int)v3;
      if ( !v3 )
        goto LABEL_12;
      v5 = *v3;
      if ( !*v3 )
        goto LABEL_12;
      while ( v5 != Block )
      {
        v6 = this[180];
        if ( v6 )
          this[180] = *(_DWORD *)(v6 + 4);
        v7 = (void **)this[180];
        if ( v7 )
        {
          v5 = *v7;
          if ( *v7 )
            continue;
        }
        goto LABEL_12;
      }
      sub_59F730(v4, (int)v5, 1);
      if ( !v5 )
      {
LABEL_12:
        v8 = (void **)this[183];
        this[185] = (int)v8;
        if ( v8 )
        {
          v9 = *v8;
          if ( v9 )
          {
            while ( v9 != Block )
            {
              v10 = this[185];
              if ( v10 )
                this[185] = *(_DWORD *)(v10 + 4);
              v11 = (void **)this[185];
              if ( v11 )
              {
                v9 = *v11;
                if ( v9 )
                  continue;
              }
              return;
            }
            sub_59F730(this + 183, (int)v9, 1);
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
