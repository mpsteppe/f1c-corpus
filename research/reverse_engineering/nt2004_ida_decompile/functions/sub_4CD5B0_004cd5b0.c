int __thiscall sub_4CD5B0(char *this, char *Destination, int a3)
{
  unsigned int v3; // kr04_4
  char *i; // eax
  char Source[512]; // [esp+8h] [ebp-200h] BYREF

  if ( !Destination || a3 < 1 )
    return -1;
  sub_57B040(this + 20, 512);
  strncpy(Destination, Source, a3 - 1);
  Destination[a3 - 1] = 0;
  v3 = strlen(Destination) + 1;
  if ( (int)(v3 - 1) > 0 )
  {
    for ( i = &Destination[v3 - 2]; i >= Destination; *i-- = 0 )
    {
      if ( *i == 92 )
        break;
    }
  }
  return 0;
}
