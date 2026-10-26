char __thiscall sub_434F10(char **this)
{
  int v2; // edx
  char v3; // al
  char *v4; // edi
  char Destination[512]; // [esp+8h] [ebp-200h] BYREF

  Destination[0] = 0;
  sub_4CD5B0(Destination, 512);
  v2 = dword_5FE15C;
  v3 = byte_5FE160;
  v4 = &Destination[strlen(Destination)];
  *(_DWORD *)v4 = dword_5FE158;
  *((_DWORD *)v4 + 1) = v2;
  v4[8] = v3;
  *(_WORD *)&Destination[strlen(Destination)] = *(_WORD *)word_5FB9F4;
  sub_578600(Destination);
  sub_578600(&byte_629120);
  sub_434B40(*this, 0);
  return 1;
}
