char __stdcall sub_4C0670(char *Destination, int a2)
{
  unsigned int v2; // kr04_4
  const char *v3; // eax
  char *v4; // ecx

  v2 = strlen(aPitmodDat) + 1;
  v3 = (const char *)sub_4CE000(&unk_7663E0);
  strncpy(Destination, v3, a2 - v2);
  Destination[a2 - v2] = 0;
  v4 = &Destination[strlen(Destination)];
  if ( v4 > Destination )
  {
    while ( *v4 != 46 )
    {
      if ( --v4 <= Destination )
        goto LABEL_6;
    }
    *v4 = 0;
  }
LABEL_6:
  strcat(Destination, "PitMod.dat");
  return aPitmodDat[10];
}
