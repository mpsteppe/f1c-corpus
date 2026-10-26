int __thiscall StringLengthGuardedFieldSetter(_DWORD *this, const char *a2, int a3, int a4, int a5)
{
  int result; // eax

  if ( a2 )
  {
    result = 0;
    if ( strlen(a2) )
    {
      StringCopyWithBufferRealloc((int)(this + 1366), a2);
      result = a3;
      this[1368] = a3;
      this[1369] = a4;
      this[1370] = a5;
    }
  }
  return result;
}
