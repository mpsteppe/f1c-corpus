int __thiscall sub_594440(_DWORD *this, int a2)
{
  int v3; // esi
  void *v4; // eax
  int result; // eax
  int i; // eax
  void *v7; // eax

  v3 = this[60];
  if ( v3 )
  {
    for ( i = *(_DWORD *)(v3 + 52); i; i = *(_DWORD *)(i + 52) )
      v3 = i;
    v7 = operator new(0x38u);
    if ( v7 )
    {
      result = sub_5B58A0(v7);
      *(_DWORD *)(v3 + 52) = result;
    }
    else
    {
      result = 0;
      *(_DWORD *)(v3 + 52) = 0;
    }
  }
  else
  {
    v4 = operator new(0x38u);
    if ( v4 )
    {
      result = sub_5B58A0(v4);
      this[60] = result;
    }
    else
    {
      result = 0;
      this[60] = 0;
    }
  }
  return result;
}
