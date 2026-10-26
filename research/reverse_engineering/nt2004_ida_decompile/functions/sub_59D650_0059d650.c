int __thiscall sub_59D650(_DWORD *this)
{
  int v2; // esi
  int i; // eax
  int v4; // edi
  int v5; // ecx
  int v6; // esi
  int j; // eax
  int v8; // esi
  int v9; // eax
  int v10; // ecx
  char *v11; // esi
  int v12; // ecx
  int v13; // edi

  v2 = this[129];
  if ( v2 )
  {
    for ( i = *(_DWORD *)(v2 + 16); i; i = *(_DWORD *)(v2 + 16) )
    {
      v4 = v2;
      v5 = v2;
      v2 = i;
      sub_59AD80(v5);
      sub_59DB60(v4);
      sub_5BE8AE();
    }
    sub_59AD80(v2);
    sub_59DB60(v2);
    sub_5BE8AE();
  }
  if ( this[123] )
    sub_5B8F40(this);
  if ( this[120] )
    sub_5A1200(this);
  v6 = this[137];
  if ( v6 )
  {
    for ( j = *(_DWORD *)(v6 + 4); j; j = *(_DWORD *)(v8 + 4) )
    {
      v8 = j;
      sub_5BE8AE();
    }
    sub_5BE8AE();
    this[137] = 0;
  }
  v9 = this[139];
  if ( v9 )
  {
    v10 = *(_DWORD *)(v9 - 4);
    v11 = (char *)(v9 + 56 * v10);
    v12 = v10 - 1;
    if ( v12 >= 0 )
    {
      v13 = v12 + 1;
      do
      {
        v11 -= 56;
        nullsub_6(v11);
        --v13;
      }
      while ( v13 );
    }
    sub_5BE8AE();
    this[139] = 0;
  }
  return 0;
}
