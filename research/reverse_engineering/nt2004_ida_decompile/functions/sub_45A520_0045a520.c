_DWORD *__thiscall sub_45A520(_DWORD *this)
{
  _DWORD *v2; // eax

  v2 = operator new(8u);
  if ( v2 )
  {
    *v2 = 0;
    v2[1] = 0;
    *this = v2;
  }
  else
  {
    *this = 0;
  }
  return this;
}
