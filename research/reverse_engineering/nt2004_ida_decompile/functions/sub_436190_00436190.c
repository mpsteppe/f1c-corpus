signed int __thiscall sub_436190(void *this)
{
  signed int result; // eax
  int v2; // ebp
  const char *v3; // edx
  unsigned int v4; // kr04_4
  const char *j; // eax
  unsigned int v6; // kr08_4
  char *v7; // ecx
  char *v8; // esi
  CHAR *v9; // eax
  FILE *v10; // eax
  CHAR *v11; // eax
  FILE *v12; // eax
  CHAR *v13; // eax
  CHAR *v14[2]; // [esp+Ch] [ebp-94h] BYREF
  signed int i; // [esp+14h] [ebp-8Ch]
  signed int v16; // [esp+18h] [ebp-88h]
  void *v17; // [esp+1Ch] [ebp-84h]
  char Destination[128]; // [esp+20h] [ebp-80h] BYREF

  v17 = this;
  sub_436630(Destination, 128);
  result = 0;
  v16 = NumOfElements;
  for ( i = 0; i < v16; result = ++i )
  {
    v2 = dword_75AAD0[result];
    if ( *(_DWORD *)(v2 + 16584) )
    {
      if ( byte_7689B4 )
      {
        v14[0] = 0;
        v14[1] = (CHAR *)-1;
        sub_578600(v2 + 24992);
        v3 = v14[0];
        if ( !v14[0] )
          v3 = &byte_629120;
        v4 = strlen(v3) + 1;
        if ( (int)(v4 - 1) > 0 )
        {
          for ( j = &v3[v4 - 2]; j >= v3; *j-- = 0 )
          {
            if ( *j == 92 )
              break;
          }
        }
        v6 = strlen(sub_410E00(v14)) + 1;
        if ( (int)(v6 - 1) > 0 && sub_410E00(v14)[v6 - 2] != 92 )
          sub_578560(word_5FB9F4);
        v7 = dword_766594;
        if ( !dword_766594 )
          v7 = &byte_629120;
        v8 = sub_435430(v7);
        v9 = sub_410E00(v14);
        sub_578600(v9);
        sub_578560(v8);
        if ( sub_435C00(dword_75CBB0) == 5 )
          sub_578560(aQual);
        else
          sub_578560(aRace);
        sub_578560(aSvm);
        v10 = fopen(&byte_629120, aR);
        if ( v10 )
        {
          fclose(v10);
          sub_431E20((char *)(v2 + 25120), &byte_629120, 0x7Fu);
          goto LABEL_27;
        }
        v11 = v14[0];
        if ( !v14[0] )
          v11 = &byte_629120;
        sub_578600(v11);
        sub_578560(v8);
        sub_578560(aSvm);
        v12 = fopen(&byte_629120, aR);
        if ( v12 )
          goto LABEL_26;
        v13 = v14[0];
        if ( !v14[0] )
          v13 = &byte_629120;
        sub_578600(v13);
        sub_578560(aAiSvm);
        v12 = fopen(&byte_629120, aR);
        if ( v12 )
        {
LABEL_26:
          fclose(v12);
          strncpy((char *)(v2 + 25120), &byte_629120, 0x7Fu);
          *(_BYTE *)(v2 + 25247) = 0;
LABEL_27:
          if ( v14[0] )
            sub_5BE8AE(v14[0]);
          continue;
        }
        if ( v14[0] )
          sub_5BE8AE(v14[0]);
      }
      strncpy((char *)(v2 + 25120), Destination, 0x7Fu);
      *(_BYTE *)(v2 + 25247) = 0;
    }
  }
  return result;
}
