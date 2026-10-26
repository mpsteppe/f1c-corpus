int __stdcall sub_527360(char a1)
{
  int v1; // esi
  __int16 *v2; // edi
  CHAR *v3; // eax
  int v4; // eax
  int result; // eax

  v1 = 0;
  v2 = word_762A08;
  while ( v1 < ((dword_761FF8 & 1) != 0 ? dword_762A04 : 0) )
  {
    if ( *v2 == 88 )
    {
      v3 = (CHAR *)dword_62A110;
      if ( !dword_62A110 )
        v3 = &byte_629120;
      sub_5B5490(dword_7E8CDC, 0, 0, dword_7E8CE8, dword_7E8CEC, (int)v3);
      if ( sub_41F230(dword_62A170, aScreenSaved, Destination) )
      {
        strncpy(Destination, aScreenSaved, 0x1FFu);
        byte_62A37B = 0;
      }
      sub_45D100(&byte_764D68, (int)Destination, 3, 16909060, 0);
    }
    ++v1;
    ++v2;
  }
  v4 = 2 - sub_527350();
  if ( a1 || byte_76617C )
    v4 |= 4u;
  result = sub_5A98C0(v4);
  if ( result == -2 )
    byte_7DA996 = 1;
  return result;
}
