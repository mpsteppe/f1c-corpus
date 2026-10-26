// f1c  0x0058d7c3  size=49
_DWORD *__cdecl sub_58D7C3(unsigned __int8 a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *result; // eax
  _DWORD *i; // edi

  result = a2;
  for ( i = (_DWORD *)((char *)a2 - 1); (int)result > 0; i = (_DWORD *)((char *)i - 1) )
  {
    result = sub_58D78E(a1, a3, a4);
    if ( *a4 == -1 )
      break;
    result = i;
  }
  return result;
}
