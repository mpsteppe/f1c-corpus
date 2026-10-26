_DWORD *__thiscall ObjectCopyInitWithVTableSetup(_DWORD *this, int a2)
{
  ObjectCopyConstructFromSource(this, a2);
  *this = &off_5B8A64;
  this[7] = 0;
  return this;
}
