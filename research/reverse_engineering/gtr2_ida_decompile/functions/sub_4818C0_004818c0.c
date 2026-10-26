char *__stdcall sub_4818C0(int a1)
{
  const char *v3; // [esp+8h] [ebp+4h]

  if ( a1 < (dword_B6CEAC + dword_B6CEA8) / 2 )
    return sub_41D840(&byte_91CC38, "Modem");
  if ( a1 < (dword_B6CEB0 + dword_B6CEAC) / 2 )
    return sub_41D840(&byte_91CC38, "ISDN");
  v3 = "Broadband";
  if ( a1 >= 10000 )
    v3 = (const char *)&off_6F6EF4;
  return sub_41D840(&byte_91CC38, v3);
}
