int __stdcall sub_433890(_BYTE *a1, int a2)
{
  char *v2; // eax
  const char *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  char *v7; // eax
  char *v8; // edx
  char v9; // cl
  char v11[256]; // [esp+10h] [ebp-100h] BYREF

  *a1 = 0;
  v2 = (char *)dword_7CE5EC;
  if ( !dword_7CE5EC )
    v2 = &byte_5EA438;
  if ( !SeasonRacesSectionFinder(v2) )
    return 1;
  v3 = 0;
  v4 = StringKeyedLinkedListSearch(off_5C3FA8[0]);
  if ( v4 )
    v3 = (const char *)DataEntryAccessor(v4);
  v5 = StringKeyedLinkedListSearch(off_5C3FB0);
  if ( v5 )
    v3 = (const char *)DataEntryAccessor(v5);
  if ( IterationCountMap(dword_7C56A4) == 5 )
  {
    v6 = StringKeyedLinkedListSearch(off_5C3FAC[0]);
    if ( v6 )
      v3 = (const char *)DataEntryAccessor(v6);
  }
  if ( !v3 )
    return 1;
  v7 = (char *)dword_5EC440;
  if ( !dword_5EC440 )
    v7 = &byte_5EA438;
  v8 = (char *)(v11 - v7);
  do
  {
    v9 = *v7;
    v7[(_DWORD)v8] = *v7;
    ++v7;
  }
  while ( v9 );
  strcat(v11, v3);
  sub_587DD0(a1, v11, a2 - 1);
  a1[a2 - 1] = 0;
  return 0;
}
