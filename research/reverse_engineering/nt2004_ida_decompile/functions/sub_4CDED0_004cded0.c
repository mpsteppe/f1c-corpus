int __thiscall sub_4CDED0(int this, const char *a2)
{
  size_t v4; // esi
  unsigned int v5; // kr04_4
  char Source[512]; // [esp+8h] [ebp-600h] BYREF
  char Destination[1024]; // [esp+208h] [ebp-400h] BYREF

  if ( !a2 )
    return -1;
  sub_4BC4C0((int **)this);
  sub_4CD510(a2, (char *)(this + 20));
  sub_57B040((char *)(this + 20), 512);
  v4 = 0;
  v5 = strlen(Source) + 1;
  if ( (int)(v5 - 1) > 0 )
  {
    do
    {
      if ( v4 >= 0x400 )
        break;
      if ( Source[v4] == 92 )
      {
        strncpy(Destination, Source, v4);
        Destination[v4] = 0;
        _mkdir(Destination);
      }
      ++v4;
    }
    while ( (int)v4 < (int)(v5 - 1) );
  }
  _mkdir(Source);
  sub_4CD540(a2, (char *)(this + 20));
  if ( (byte_762F00 & 1) != 0 )
    sub_4CB410(this, COERCE_FLOAT(2));
  else
    sub_4CB410(this, COERCE_FLOAT(1));
  if ( dword_7D6B50 > 0 )
    sub_4E8A30(&byte_7D6A30);
  sub_578600(&byte_629120);
  sub_4CA8D0();
  sub_4CA940((_DWORD *)this, 1);
  sub_435F50((int)&dword_75E8F0);
  sub_4CDC80(this, 1);
  return 0;
}
