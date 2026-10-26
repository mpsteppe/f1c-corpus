_DWORD *__thiscall SimpleObjectConstructor(_DWORD *this, int a2)
{
  ConstructorWithByteParams((int)this, 0, 0);
  this[57] = a2;
  *this = &off_5A42C0;
  return this;
}

