int __usercall findenv@<eax>(size_t a1@<edi>, unsigned __int8 *Str1)
{
  const unsigned __int8 **i; // esi
  unsigned __int8 v3; // al

  for ( i = (const unsigned __int8 **)dword_FB81B4; ; ++i )
  {
    if ( !*i )
      return -(((char *)i - (_BYTE *)dword_FB81B4) >> 2);
    if ( !_mbsnbicoll(Str1, *i, a1) )
    {
      v3 = (*i)[a1];
      if ( v3 == 61 || !v3 )
        break;
    }
  }
  return ((char *)i - (_BYTE *)dword_FB81B4) >> 2;
}
