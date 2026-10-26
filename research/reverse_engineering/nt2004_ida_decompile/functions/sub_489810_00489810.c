char __thiscall sub_489810(_DWORD *this, int a2)
{
  int v3; // ecx
  int v4; // eax
  char *v6; // eax
  char Source[253]; // [esp+8h] [ebp-100h] BYREF
  __int16 v8; // [esp+105h] [ebp-3h]
  char v9; // [esp+107h] [ebp-1h]

  if ( a2 < 0 || a2 >= this[219] )
    return 0;
  sub_4893B0(a2);
  v3 = a2;
  if ( a2 >= this[219] )
  {
    this[218] = 0;
  }
  else
  {
    this[218] = this[216];
    if ( a2 > 0 )
    {
      do
      {
        v4 = this[218];
        if ( !v4 )
          break;
        --v3;
        this[218] = *(_DWORD *)(v4 + 4);
      }
      while ( v3 > 0 );
    }
  }
  if ( sub_4E7760(&unk_7D6A50)
    && (Source[0] = byte_629120,
        memset(&Source[1], 0, 0xFCu),
        v8 = 0,
        v9 = 0,
        (unsigned __int8)sub_4E7210(a2, Source, 256)) )
  {
    sub_4A1AC0(Source);
    return 1;
  }
  else
  {
    v6 = sub_4897C0(this, a2);
    sub_4A1AC0(v6);
    return 1;
  }
}
