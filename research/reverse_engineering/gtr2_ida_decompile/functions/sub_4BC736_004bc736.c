int __thiscall sub_4BC736(_DWORD *this)
{
  char *v2; // edi
  int result; // eax
  char v5; // [esp-1h] [ebp-105h] BYREF
  char Str1[260]; // [esp+0h] [ebp-104h] BYREF

  sub_527EB0(0, 0);
  strcpy(Str1, "?|");
  v2 = &v5;
  while ( *++v2 )
    ;
  strcpy(v2, "__ds.tmp");
  if ( !strncmp(Str1, Str2, 2u) )
    result = sub_614A60(Str1);
  else
    result = sub_617680(Str1);
  *this = 0;
  return result;
}
