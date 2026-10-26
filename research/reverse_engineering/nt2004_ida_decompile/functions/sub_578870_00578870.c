_DWORD *__thiscall sub_578870(_DWORD *this)
{
  _DWORD *v2; // eax

  v2 = operator new(0x224u);
  if ( v2 )
  {
    *v2 = 0;
    v2[1] = 0;
    v2[2] = 0;
    v2[3] = 0;
    *((_BYTE *)v2 + 16) = 0;
    v2[132] = 0;
    v2[133] = -1;
    *((_BYTE *)v2 + 16) = 0;
    *((_BYTE *)v2 + 536) = 0;
    v2[135] = 0;
    v2[136] = 0;
    *this = v2;
  }
  else
  {
    *this = 0;
  }
  return this;
}
