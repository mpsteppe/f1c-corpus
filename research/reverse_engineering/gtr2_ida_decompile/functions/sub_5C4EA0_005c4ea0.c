_DWORD *__thiscall sub_5C4EA0(_DWORD *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v4; // eax

  v2 = operator new(0xCu);
  if ( v2 )
  {
    *v2 = &off_729ED0;
    v2[2] = 0;
    v2[1] = 0;
    v3 = v2;
  }
  else
  {
    v3 = 0;
  }
  v3[1] = this[1];
  v4 = this[2];
  if ( v4 )
    v3[2] = (*(int (**)(void))(*(_DWORD *)v4 + 8))();
  else
    v3[2] = 0;
  return v3;
}
