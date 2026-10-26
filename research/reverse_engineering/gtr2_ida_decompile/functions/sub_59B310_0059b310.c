int *__thiscall sub_59B310(int *this, _DWORD *a2, _BYTE *a3)
{
  void *v4; // eax
  int v5; // eax

  *a3 = 0;
  if ( *a2 > 1u )
  {
    *this = 0;
    *a3 = 1;
  }
  else
  {
    v4 = operator new(0xC18u);
    if ( v4 )
      v5 = sub_5A3370(v4, a2, a3);
    else
      v5 = 0;
    *this = v5;
    if ( *a3 )
    {
      if ( v5 )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 68))(v5, 1);
      *this = 0;
    }
  }
  return this;
}
