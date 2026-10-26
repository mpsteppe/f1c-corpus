_DWORD *__thiscall sub_5F05E0(void *this, char *a2, int a3, int a4, int a5, int a6, int a7)
{
  _DWORD *result; // eax

  result = (_DWORD *)sub_5F04C0(this, a2);
  if ( result )
  {
    result[34] = a4;
    result[35] = a5;
    return (_DWORD *)sub_5EEAD0(result, a6, a7);
  }
  return result;
}
