char __thiscall sub_4D3130(const char **Buffer, unsigned __int8 Buffera)
{
  const char *v3; // eax
  CHAR *v4; // eax

  sub_57A3A0(Buffer, 4u);
  v3 = Buffer[1];
  if ( !v3 )
    v3 = &byte_629120;
  Buffera = strlen(v3);
  sub_57A3A0(&Buffera, 1u);
  if ( Buffera )
  {
    v4 = (CHAR *)Buffer[1];
    if ( !v4 )
      v4 = &byte_629120;
    sub_57A3A0(v4, Buffera);
  }
  return 1;
}
