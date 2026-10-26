int __thiscall StringCopyWithGuard(void *this, const char *a2)
{
  int result; // eax

  result = (int)a2;
  if ( a2 )
    return StringCopyWithBufferRealloc((int)this + 80, a2);
  return result;
}

