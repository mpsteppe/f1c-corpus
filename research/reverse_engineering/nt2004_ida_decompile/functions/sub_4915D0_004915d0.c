int sub_4915D0()
{
  CHAR *v0; // esi

  v0 = sub_464810(dword_764D70);
  if ( v0 && strlen(v0) )
  {
    if ( sub_41F230(dword_62A170, v0, Destination) )
    {
      strncpy(Destination, v0, 0x1FFu);
      byte_62A37B = 0;
    }
    sub_49EC60(Destination);
    return 0;
  }
  else
  {
    sub_49EC60(&byte_629120);
    return 0;
  }
}
