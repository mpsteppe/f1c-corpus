_DWORD *__thiscall sub_5D59C0(_DWORD *this, int a2, int a3)
{
  _DWORD *v4; // esi
  _DWORD *result; // eax
  int v6; // ebx
  int v7; // edi

  v4 = operator new(0x18u);
  result = 0;
  if ( v4 )
  {
    v6 = this[4];
    v7 = this[3];
    sub_5D1B50(v4, a2);
    v4[4] = v6;
    *v4 = &off_72B5BC;
    v4[3] = v7;
    *((_BYTE *)v4 + 20) = 1;
    return v4;
  }
  return result;
}
