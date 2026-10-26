int __stdcall sub_4B37E0(char *Buffer, int a2)
{
  char *v2; // esi
  int v3; // eax

  v2 = strcpy(Buffer, asc_609460);
  if ( !*(_DWORD *)(dword_75AAC4 + 20892) )
  {
    v3 = *(_DWORD *)(dword_75AAC4 + 21012);
    if ( v3 )
    {
      sprintf(v2, "%s:", (const char *)(v3 + 24972));
      _strupr(v2);
    }
  }
  return 0;
}
