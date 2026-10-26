int __thiscall sub_54A770(_DWORD *this)
{
  _DWORD *v2; // esi
  _DWORD *i; // eax
  void *v4; // edi
  _DWORD *v5; // ecx
  _DWORD *v6; // esi
  _DWORD *j; // eax
  int v8; // eax
  int v9; // ecx
  void *v10; // ebp
  int v11; // esi
  int v12; // ecx
  int v13; // edi
  void *v15; // [esp-4h] [ebp-10h]

  v2 = (_DWORD *)this[129];
  if ( v2 )
  {
    for ( i = (_DWORD *)v2[4]; i; i = (_DWORD *)v2[4] )
    {
      v4 = v2;
      v5 = v2;
      v2 = i;
      sub_54C410(v5);
      sub_54AC30(v4);
      sub_587BCF(v4);
    }
    sub_54C410(v2);
    sub_54AC30(v2);
    sub_587BCF(v2);
  }
  if ( this[123] )
    sub_561940(this);
  if ( this[120] )
    sub_54FA50(this);
  v6 = (_DWORD *)this[137];
  if ( v6 )
  {
    for ( j = (_DWORD *)v6[1]; j; j = (_DWORD *)v6[1] )
    {
      v15 = v6;
      v6 = j;
      sub_587BCF(v15);
    }
    sub_587BCF(v6);
    this[137] = 0;
  }
  v8 = this[139];
  if ( v8 )
  {
    v9 = *(_DWORD *)(v8 - 4);
    v10 = (void *)(v8 - 4);
    v11 = v8 + 56 * v9;
    v12 = v9 - 1;
    if ( v12 >= 0 )
    {
      v13 = v12 + 1;
      do
      {
        v11 -= 56;
        nullsub_3();
        --v13;
      }
      while ( v13 );
    }
    sub_587BCF(v10);
    this[139] = 0;
  }
  return 0;
}
