int __thiscall sub_4E0280(_DWORD *this, int a2, int a3, int a4)
{
  void *v4; // esi
  int result; // eax
  int v7; // edi
  void *v8; // eax
  _UNKNOWN *retaddr; // [esp+1Ch] [ebp+0h]

  v4 = 0;
  if ( !a2 )
    return 0;
  result = sub_4DF040(this, a2);
  if ( result )
    return result;
  v7 = this[83];
  v8 = operator new(0x2Cu);
  retaddr = v8;
  if ( v8 )
    v4 = (void *)sub_4E33A0(v8);
  if ( !(unsigned __int8)sub_4E3680(a2, a2, a3) )
  {
    retaddr = v4;
    if ( v4 )
    {
      sub_4E2820(v4, 1);
      if ( *(_DWORD *)v4 )
        j_j__free(*(void **)v4);
      j__free(v4);
    }
    return 0;
  }
  if ( v7 )
  {
    for ( ; *(_DWORD *)(v7 + 40); v7 = *(_DWORD *)(v7 + 40) )
      ;
    *(_DWORD *)(v7 + 40) = v4;
    ++this[84];
    return (int)v4;
  }
  else
  {
    ++this[84];
    this[83] = v4;
    return (int)v4;
  }
}
