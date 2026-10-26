char __stdcall sub_477BC0(int a1, char *String, char a3)
{
  CHAR *v3; // edi
  char *v4; // eax
  const char *v5; // esi
  const char *v6; // edi

  v3 = sub_457C50(&ppvOut, a1);
  v4 = sub_457840(&dword_76A67C[7 * a1]);
  v5 = v4;
  if ( v3 && String )
  {
    if ( sub_41F230(dword_62A170, v3, Destination) )
    {
      strncpy(Destination, v3, 0x1FFu);
      byte_62A37B = 0;
    }
    strcpy(String, Destination);
    _strupr(String);
    sub_49F640(String);
    if ( v5 )
    {
      if ( sub_41F230(dword_62A170, v5, Destination) )
      {
        strncpy(Destination, v5, 0x1FFu);
        byte_62A37B = 0;
      }
      v6 = Destination;
    }
    else
    {
      v6 = &byte_629120;
    }
    LOBYTE(v4) = a3;
    strcat(String, v6);
    if ( a3 )
      LOBYTE(v4) = sub_49F730(String, 0, 0, 0, 0);
  }
  return (char)v4;
}
