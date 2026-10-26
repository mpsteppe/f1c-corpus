int sub_490A60()
{
  int v0; // eax
  int v1; // eax
  int v3; // [esp+4h] [ebp-4h]

  if ( sub_57AE50(aSeasonraces)
    && sub_57A720((char *)(400 * dword_7D6B54 + dword_7D6B58 + 260))
    && (v0 = sub_57A720(aRacelaps)) != 0 )
  {
    v1 = sub_57A6D0(v0);
    sub_49EC60(v1);
    return 0;
  }
  else
  {
    sub_49EC60(v3);
    return 0;
  }
}
