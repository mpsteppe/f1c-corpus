_DWORD *__thiscall ConstructorWithVTableAndParamStore(_DWORD *this, int a2)
{
  ConstructorWithByteParams((int)this, 0, 0);
  this[57] = a2;
  *this = &off_59FF80;
  return this;
}

