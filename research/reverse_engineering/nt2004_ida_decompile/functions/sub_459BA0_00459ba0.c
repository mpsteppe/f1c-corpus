CHAR *__thiscall sub_459BA0(void *this)
{
  CHAR *result; // eax

  result = *(CHAR **)(*(_DWORD *)this + 12);
  if ( !result )
    return &byte_629120;
  return result;
}
