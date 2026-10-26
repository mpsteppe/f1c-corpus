_DWORD *__thiscall ConstructorWithBulkInitAndVTable(_DWORD *this)
{
  ConstructorWithStringCopy((int)this, 0, 0, 0, 0, 1, 0);
  *this = &off_5A0250;
  return this;
}

