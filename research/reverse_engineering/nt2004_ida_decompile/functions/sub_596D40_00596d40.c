int __thiscall sub_596D40(_DWORD *this)
{
  int v2; // esi
  int v3; // ebx
  _DWORD *v4; // esi
  int v5; // ebx
  int v6; // esi
  int v7; // esi
  int i; // edi

  if ( (this[60] & 0x100000) != 0 )
  {
    if ( this[92] )
    {
      v2 = 0;
      if ( (int)this[91] > 0 )
      {
        v3 = 0;
        do
        {
          sub_5A2660(v3 + this[92]);
          ++v2;
          v3 += 96;
        }
        while ( v2 < this[91] );
      }
      sub_599CB0(this[92]);
      v4 = (_DWORD *)this[90];
      this[92] = 0;
      for ( this[91] = 0; v4; v4 = (_DWORD *)v4[1] )
      {
        if ( *v4 )
          sub_5B8770();
      }
    }
    this[60] &= ~0x100000u;
  }
  if ( dword_7E8CD0 )
  {
    sub_59FA90(dword_7E8CD0);
    if ( dword_7E8CD0 )
    {
      j_nullsub_6((void *)dword_7E8CD0);
      sub_5BE8AE();
    }
    dword_7E8CD0 = 0;
  }
  if ( dword_7E8CD4 )
  {
    sub_59FA90(dword_7E8CD4);
    if ( dword_7E8CD4 )
    {
      j_nullsub_6((void *)dword_7E8CD4);
      sub_5BE8AE();
    }
    dword_7E8CD4 = 0;
  }
  v5 = this[65];
  if ( v5 )
  {
    while ( 1 )
    {
      v6 = *(_DWORD *)(v5 + 236);
      if ( v6 )
        break;
LABEL_23:
      v5 = *(_DWORD *)(v5 + 260);
      if ( !v5 )
        goto LABEL_24;
    }
    while ( !sub_597090(v6, 0) )
    {
      v6 = *(_DWORD *)(v6 + 76);
      if ( !v6 )
        goto LABEL_23;
    }
    return -1;
  }
LABEL_24:
  v7 = this[67];
  if ( v7 )
  {
    while ( !sub_597090(v7, 0) )
    {
      v7 = *(_DWORD *)(v7 + 76);
      if ( !v7 )
        goto LABEL_27;
    }
    return -1;
  }
LABEL_27:
  for ( i = this[85]; i; i = *(_DWORD *)(i + 104) )
    sub_5AF4E0(i);
  sub_5A78B0(&unk_7E6B48);
  return 0;
}
