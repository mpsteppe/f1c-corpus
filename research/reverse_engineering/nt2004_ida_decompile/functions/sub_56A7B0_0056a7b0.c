void __cdecl sub_56A7B0()
{
  int v0; // esi
  int v1; // edi

  if ( (byte_7E05EB & 1) == 0 )
  {
    v0 = dword_7E05EC;
    byte_7E05EB |= 1u;
    while ( v0 )
    {
      v1 = v0;
      v0 = *(_DWORD *)(v0 + 4);
      if ( *(_BYTE *)(v1 + 12) )
      {
        if ( *(_DWORD *)v1 )
        {
          sub_56A1F0(*(_DWORD **)v1);
          sub_5BE8AE();
        }
      }
      sub_5BE8AE();
    }
    dword_7E05EC = 0;
    dword_7E05F0 = 0;
    dword_7E05F4 = 0;
    dword_7E05F8 = 0;
  }
}
