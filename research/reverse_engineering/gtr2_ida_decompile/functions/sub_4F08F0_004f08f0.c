_DWORD *__thiscall sub_4F08F0(_DWORD *this, int a2)
{
  _DWORD *v3; // esi
  int v4; // ebx
  int v5; // edi

  v3 = operator new(0x18u);
  if ( !v3 )
    return 0;
  v4 = this[4];
  v5 = this[3];
  sub_5BFC50(a2);
  v3[4] = v4;
  v3[3] = v5;
  *v3 = &off_714684;
  v3[5] = 0;
  return v3;
}
