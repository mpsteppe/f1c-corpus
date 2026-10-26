char *__thiscall sub_594290(_DWORD *this, const char *a2)
{
  int v3; // esi
  _DWORD *v4; // eax
  char *v5; // eax
  int i; // eax
  _DWORD *v7; // eax
  char *v8; // esi

  v3 = this[58];
  if ( v3 )
  {
    for ( i = *(_DWORD *)(v3 + 20); i; i = *(_DWORD *)(i + 20) )
      v3 = i;
    v7 = operator new(0x18u);
    if ( v7 )
      v5 = (char *)sub_594070(v7);
    else
      v5 = 0;
    *(_DWORD *)(v3 + 20) = v5;
  }
  else
  {
    v4 = operator new(0x18u);
    if ( v4 )
    {
      v5 = (char *)sub_594070(v4);
      this[58] = v5;
    }
    else
    {
      v5 = 0;
      this[58] = 0;
    }
  }
  v8 = v5;
  strcpy(v5, a2);
  return _strupr(v8);
}
