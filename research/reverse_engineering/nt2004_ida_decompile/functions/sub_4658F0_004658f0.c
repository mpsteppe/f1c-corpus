CHAR *__thiscall sub_4658F0(void *this)
{
  CHAR *result; // eax

  result = *(CHAR **)(*(_DWORD *)this + 156);
  if ( !result )
    return &byte_629120;
  return result;
}
