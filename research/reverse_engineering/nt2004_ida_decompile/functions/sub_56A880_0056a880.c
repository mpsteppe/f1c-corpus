int sub_56A880()
{
  int i; // esi
  int v1; // edi
  int result; // eax

  for ( i = dword_7E05EC; i; result = sub_5BE8AE() )
  {
    v1 = i;
    i = *(_DWORD *)(i + 4);
    if ( *(_BYTE *)(v1 + 12) && *(_DWORD *)v1 )
    {
      sub_56A1F0(*(_DWORD **)v1);
      sub_5BE8AE();
    }
  }
  dword_7E05EC = 0;
  dword_7E05F0 = 0;
  dword_7E05F4 = 0;
  dword_7E05F8 = 0;
  return result;
}
