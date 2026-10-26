int sub_495090()
{
  int result; // eax
  int v1; // edi
  char *v2; // eax
  int v3; // esi
  char *v4; // edi
  char v6; // [esp+3h] [ebp-85h] BYREF
  char v7[4]; // [esp+4h] [ebp-84h] BYREF
  char Buffer[128]; // [esp+8h] [ebp-80h] BYREF

  if ( !(unsigned __int8)sub_54B750(&unk_BE27B0) )
    return sub_4CE020(WindowName);
  v1 = dword_BE1BD0;
  v2 = (char *)sub_54B330(&unk_BE27B0);
  result = sub_539670(v2);
  v3 = result;
  dword_BE1BD0 = v1;
  if ( result )
  {
    sub_630FE0(v7, result + 1716, 2);
    v7[2] = 0;
    v4 = &v6;
    while ( *++v4 )
      ;
    *(_WORD *)v4 = 39;
    sprintf(Buffer, "%s %s %s", v7, (const char *)(v3 + 1718), (const char *)(v3 + 1980));
    return sub_4CE020(Buffer);
  }
  return result;
}
