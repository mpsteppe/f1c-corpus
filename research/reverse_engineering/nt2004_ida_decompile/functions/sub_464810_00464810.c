CHAR *__thiscall sub_464810(void *this)
{
  CHAR *result; // eax

  result = *(CHAR **)(*(_DWORD *)this + 144);
  if ( !result )
    return &byte_629120;
  return result;
}
