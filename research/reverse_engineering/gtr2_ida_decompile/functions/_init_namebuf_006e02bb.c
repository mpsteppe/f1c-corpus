char *__cdecl init_namebuf(int a1)
{
  char *v1; // esi
  _BYTE *v2; // eax
  DWORD CurrentProcessId; // eax
  char *v5; // [esp-8h] [ebp-Ch]

  v1 = byte_FBB238;
  if ( a1 )
    v1 = &byte_FBB248;
  strcpy(v1, word_6F1F78);
  v2 = v1 + 1;
  if ( *v1 != 92 && *v1 != 47 )
  {
    *v2 = 92;
    v2 = v1 + 2;
  }
  if ( a1 )
    *v2 = 116;
  else
    *v2 = 115;
  v5 = v2 + 1;
  CurrentProcessId = GetCurrentProcessId();
  _ultoa(CurrentProcessId, v5, 32);
  return strcat(v1, ".");
}
