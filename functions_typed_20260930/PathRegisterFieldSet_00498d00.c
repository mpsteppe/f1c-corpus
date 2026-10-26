int __thiscall PathRegisterFieldSet(_DWORD *this, const char *a2, int a3)
{
  int result; // eax

  result = StringCopyWithBufferRealloc((int)(this + 15), a2);
  this[17] = a3;
  return result;
}

