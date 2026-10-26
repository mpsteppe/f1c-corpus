_DWORD *__thiscall InitWithVTableSet(_DWORD *this, int a2)
{
  ConstructorWithStringCopy((int)this, 0, 0, 0, 0, 1, 0);
  this[193] = a2;
  *this = &off_5A0308;
  return this;
}

