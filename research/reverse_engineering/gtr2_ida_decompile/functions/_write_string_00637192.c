int __usercall write_string@<eax>(int result@<eax>, _BYTE *a2@<ecx>, int a3@<edi>, int a4)
{
  _DWORD *v4; // esi

  v4 = (_DWORD *)result;
  if ( (*(_BYTE *)(a3 + 12) & 0x40) == 0 || *(_DWORD *)(a3 + 8) )
  {
    do
    {
      if ( a4 <= 0 )
        break;
      LOBYTE(result) = *a2;
      --a4;
      result = write_char(result, a3, v4);
      ++a2;
    }
    while ( *v4 != -1 );
  }
  else
  {
    result = a4;
    *v4 += a4;
  }
  return result;
}
