int __thiscall sub_5AEB50(char *Buffer, char *a2)
{
  char *v2; // eax
  int v4; // edx
  char v5; // cl
  FILE *v6; // eax
  int v7; // ebp
  const char *v8; // edi
  FILE *v9; // eax
  void *v11; // eax
  unsigned int v12; // [esp-34h] [ebp-240h]
  char Buffera[256]; // [esp+Ch] [ebp-200h] BYREF
  char Format[256]; // [esp+10Ch] [ebp-100h] BYREF

  v2 = a2;
  if ( !a2 || !*a2 )
    return -1;
  v4 = Buffer + 20 - a2;
  do
  {
    v5 = *v2;
    v2[v4] = *v2;
    ++v2;
  }
  while ( v5 );
  _strupr(Buffer + 20);
  v6 = fopen(Buffer + 20, aRb);
  *((_DWORD *)Buffer + 4) = v6;
  if ( !v6 )
  {
    v7 = 0;
    if ( dword_7E8D58 > 0 )
    {
      v8 = byte_7E4CCC;
      do
      {
        sprintf(Buffera, "%s\\%s", v8, Buffer + 20);
        v9 = fopen(Buffera, aRb);
        *((_DWORD *)Buffer + 4) = v9;
        if ( v9 )
          break;
        ++v7;
        v8 += 132;
      }
      while ( v7 < dword_7E8D58 );
    }
    if ( v7 == dword_7E8D58 )
    {
      sprintf(Format, "Error opening MAS file %s", Buffer + 20);
      sub_591C60((int)Buffer, -2, Format);
      return -2;
    }
  }
  sub_5BED6F(Buffer, 1u, 0xCu, *((FILE **)Buffer + 4));
  if ( strcmp(Buffer, aCubemas410) && strcmp(Buffer, aCubemas400) && strcmp(Buffer, aCubemas401) )
  {
    fclose(*((FILE **)Buffer + 4));
    sub_591C60((int)Buffer, -1, aIncorrectMasFi);
    return -1;
  }
  sub_5BED6F(Buffer + 276, 1u, 4u, *((FILE **)Buffer + 4));
  sub_5BED6F(Buffer + 280, 1u, 4u, *((FILE **)Buffer + 4));
  sub_5BED6F(Buffer + 288, 1u, 4u, *((FILE **)Buffer + 4));
  v12 = *((_DWORD *)Buffer + 70) << 8;
  *((_DWORD *)Buffer + 71) = v12;
  v11 = operator new(v12);
  *((_DWORD *)Buffer + 74) = v11;
  if ( !v11 )
  {
    fclose(*((FILE **)Buffer + 4));
    sub_591C60((int)Buffer, -1, aUnableToAlloca);
    return -1;
  }
  sub_5BED6F(v11, 1u, *((_DWORD *)Buffer + 71), *((FILE **)Buffer + 4));
  *((_DWORD *)Buffer + 71) += 24;
  return 0;
}
