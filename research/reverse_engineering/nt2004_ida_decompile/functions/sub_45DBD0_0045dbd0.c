char __thiscall sub_45DBD0(unsigned __int8 *this, char *Source, _DWORD *a3)
{
  char *v3; // eax
  int v4; // ebx
  int v5; // ebp
  int i; // esi
  int v7; // edi
  char v9; // [esp+13h] [ebp-205h]
  int v10; // [esp+14h] [ebp-204h] BYREF
  char Destination[512]; // [esp+18h] [ebp-200h] BYREF

  *a3 = 0;
  v9 = 1;
  if ( (unsigned __int8)sub_57B490(Source, this[1], (int)&v10) )
    *a3 += v10;
  else
    v9 = 0;
  strncpy(Destination, Source, 0x1FFu);
  Destination[511] = 0;
  v3 = &Destination[strlen(Destination)];
  if ( v3 > Destination )
  {
    while ( *v3 != 46 )
    {
      if ( --v3 <= Destination )
        goto LABEL_9;
    }
    *v3 = 0;
  }
LABEL_9:
  v4 = dword_7D6B50;
  v5 = 0;
  if ( dword_7D6B50 > 0 )
  {
    for ( i = 0; ; i += 400 )
    {
      v7 = i + dword_7D6B58;
      if ( !_strcmpi(Destination, (const char *)(i + dword_7D6B58 + 4)) )
        break;
      if ( ++v5 >= v4 )
        return v9;
    }
    *a3 += *(_DWORD *)(v7 + 396);
  }
  return v9;
}
