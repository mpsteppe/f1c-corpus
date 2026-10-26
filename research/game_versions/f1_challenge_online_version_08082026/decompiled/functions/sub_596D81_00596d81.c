char *__cdecl sub_596D81(CHAR *lpString2)
{
  PCNZCH *v1; // esi
  char *v2; // edi

  v1 = (PCNZCH *)dword_8D3E90;
  if ( dword_8D5A48 )
  {
    if ( dword_8D3E90 || dword_8D3E98 && !sub_597FAC() && (v1 = (PCNZCH *)dword_8D3E90) != 0 )
    {
      if ( lpString2 )
      {
        v2 = sub_58E1B0(lpString2);
        while ( *v1 )
        {
          if ( sub_58E1B0(*v1) > v2 && v2[(_DWORD)*v1] == 61 && !sub_597F6D(*v1, lpString2, (int)v2) )
            return &v2[(_DWORD)*v1 + 1];
          ++v1;
        }
      }
    }
  }
  return 0;
}
