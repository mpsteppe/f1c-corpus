int __usercall write_multi_char@<eax>(int result@<eax>, char a2, int a3, int a4)
{
  _DWORD *v4; // esi

  v4 = (_DWORD *)result;
  do
  {
    if ( a3 <= 0 )
      break;
    LOBYTE(result) = a2;
    --a3;
    result = write_char(result, a4, v4);
  }
  while ( *v4 != -1 );
  return result;
}
