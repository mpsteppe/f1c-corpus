int __thiscall sub_4AD520(void *this, char *String2)
{
  int v3; // esi
  const char *v4; // eax
  _BYTE v6[24]; // [esp+8h] [ebp-18h] BYREF

  sub_4AFAB0(v6);
  sub_4AFB50(this);
  v3 = sub_4AFC50(v6);
  if ( v3 )
  {
    while ( 1 )
    {
      v4 = *(const char **)(v3 + 36);
      if ( !v4 )
        v4 = &byte_629120;
      if ( !_strcmpi(v4, String2) )
        break;
      sub_4AFB80(v6);
      v3 = sub_4AFC50(v6);
      if ( !v3 )
        goto LABEL_6;
    }
    nullsub_6(v6);
    return v3;
  }
  else
  {
LABEL_6:
    nullsub_6(v6);
    return 0;
  }
}
