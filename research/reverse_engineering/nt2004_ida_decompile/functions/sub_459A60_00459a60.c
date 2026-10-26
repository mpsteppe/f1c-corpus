_DWORD *__thiscall sub_459A60(_DWORD *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi

  v2 = operator new(0xBCu);
  v3 = v2;
  if ( v2 )
  {
    *v2 = 0;
    v2[1] = -1;
    v2[3] = 0;
    v2[4] = -1;
    v2[43] = 0;
    v2[44] = -1;
    v2[45] = 0;
    v2[46] = -1;
    sub_4586E0((int)v2);
    *this = v3;
  }
  else
  {
    *this = 0;
  }
  return this;
}
