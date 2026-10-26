bool __thiscall sub_4328F0(void *this)
{
  const char *v1; // eax

  v1 = *(const char **)(*(_DWORD *)this + 8);
  if ( !v1 )
    v1 = &byte_5EA438;
  return strlen(v1) == 0;
}

