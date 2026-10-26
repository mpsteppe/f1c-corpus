int __stdcall sub_435A70(int a1, char *a2, int a3)
{
  const char *v3; // eax
  char *v4; // eax
  char Destination[256]; // [esp+Ch] [ebp-100h] BYREF

  if ( !a1 )
    return 1;
  v3 = (const char *)sub_4CE000();
  strncpy(Destination, v3, 0xFFu);
  Destination[255] = 0;
  v4 = &Destination[strlen(Destination)];
  if ( v4 > Destination )
  {
    while ( *v4 != 46 )
    {
      if ( --v4 <= Destination )
        goto LABEL_7;
    }
    *v4 = 0;
  }
LABEL_7:
  if ( strlen(Destination) + strlen(off_5FE05C[0]) >= 0x100 )
    return 1;
  strcat(Destination, off_5FE05C[0]);
  strncpy(a2, Destination, a3 - 1);
  a2[a3 - 1] = 0;
  return 0;
}
