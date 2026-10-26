_DWORD *__thiscall sub_59BF56(_DWORD *this, int a2)
{
  int v3; // eax
  char *v4; // eax
  int v5; // eax

  *this = &exception::`vftable';
  v3 = *(_DWORD *)(a2 + 8);
  this[2] = v3;
  if ( v3 )
  {
    v4 = Strlen(*(_DWORD **)(a2 + 4));
    v5 = OperatorNewNhMallocWrapper((int)(v4 + 1));
    this[1] = v5;
    if ( v5 )
      sub_58FCA0();
  }
  else
  {
    this[1] = *(_DWORD *)(a2 + 4);
  }
  return this;
}

