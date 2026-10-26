_DWORD *__thiscall ObjectInitializerWithVtableIndex(_DWORD *this, int a2, int a3, int a4)
{
  sub_48C070(this, 0);
  this[200] = (char *)&unk_7C5770 + 64 * (a3 + 11 * a2);
  this[203] = a2;
  *this = &off_59F4F8;
  this[199] = a4;
  this[201] = 55;
  this[202] = a3;
  return this;
}
