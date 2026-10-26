_DWORD *__thiscall sub_4F16D0(_DWORD *this, int a2, int a3)
{
  sub_5BFC50(a2);
  this[3] = a3;
  *this = &off_7146D4;
  *(float *)(*(_DWORD *)(*(_DWORD *)(a3 + 232) + 4) + 52) = *(float *)(*(_DWORD *)(*(_DWORD *)(a3 + 232) + 4) + 52)
                                                          - 0.1;
  sub_5BC090(2);
  return this;
}
