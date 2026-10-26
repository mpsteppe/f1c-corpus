// f1c  0x004c0f60  size=239
char __thiscall sub_4C0F60(int this)
{
  int v2; // eax
  int v3; // esi
  int v4; // edi
  int v5; // eax
  int i; // edx
  int v7; // edi
  int v8; // eax
  int v9; // esi
  int j; // eax
  int v11; // ecx

  if ( !*(_BYTE *)(this + 45392) )
  {
    v2 = sub_4C11D0(this);
    sub_4C0910((_DWORD *)(this + 44908), v2);
    v3 = this;
    v4 = 103;
    do
    {
      if ( *(_BYTE *)(v3 + 432) )
      {
        v5 = sub_4C11D0(this);
        sub_4C0910((_DWORD *)v3, v5);
      }
      v3 += 436;
      --v4;
    }
    while ( v4 );
    if ( *(_DWORD *)(this + 45388) == 7 )
    {
      for ( i = 0; i < 104; ++i )
      {
        v7 = 0;
        if ( i )
          v8 = 436 * i + this - 436;
        else
          v8 = this + 44908;
        if ( *(_BYTE *)(v8 + 432) )
        {
          v9 = *(_DWORD *)(v8 + 408);
          for ( j = 0; j < 104; ++j )
          {
            if ( i != j )
            {
              if ( j )
                v11 = 436 * j + this - 436;
              else
                v11 = this + 44908;
              if ( *(_BYTE *)(v11 + 432) && *(_DWORD *)(v11 + 408) > v9 )
                ++v7;
            }
          }
          if ( i )
            *(_DWORD *)(436 * i + this - 24) = v7;
          else
            *(_DWORD *)(this + 45320) = v7;
        }
      }
    }
    *(_BYTE *)(this + 45392) = 1;
  }
  return 0;
}
