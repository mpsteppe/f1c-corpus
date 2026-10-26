int __thiscall sub_59AB10(_DWORD *this, int a2, int a3)
{
  int v4; // esi
  _DWORD *v5; // eax
  int *v6; // eax
  int i; // eax
  _DWORD *v8; // eax

  v4 = this[95];
  if ( v4 )
  {
    for ( i = *(_DWORD *)(v4 + 24); i; i = *(_DWORD *)(i + 24) )
      v4 = i;
    v8 = operator new(0x1Cu);
    if ( v8 )
      v6 = sub_59A870(v8);
    else
      v6 = 0;
    *(_DWORD *)(v4 + 24) = v6;
  }
  else
  {
    v5 = operator new(0x1Cu);
    if ( v5 )
    {
      v6 = sub_59A870(v5);
      this[95] = v6;
    }
    else
    {
      v6 = 0;
      this[95] = 0;
    }
  }
  if ( sub_59A8A0(v6, a2, a3) )
    return -1;
  ++this[94];
  return 0;
}
