int __stdcall sub_65E964(char *String, char *a2, char *a3)
{
  char *i; // esi
  unsigned int v5; // ebx
  char v6; // al
  char *j; // esi
  char v8; // al
  char v9[27]; // [esp+8h] [ebp-1Ch] BYREF
  char v10; // [esp+23h] [ebp-1h]

  for ( i = String; *i; ++i )
  {
    if ( !sub_633848() )
      break;
  }
  if ( *i )
    v10 = j__atol(i);
  else
    v10 = 0;
  if ( (unsigned __int8)v10 > 0xFu )
  {
    *a2 = 0;
    *a3 = -1;
    return -2147467259;
  }
  v5 = i - String;
  if ( i != String && v5 <= 0x14 )
  {
    v6 = *i;
    if ( !*i )
      goto LABEL_15;
    do
    {
      if ( !isdigit(v6) )
        break;
      v6 = *++i;
    }
    while ( *i );
    if ( !*i )
    {
LABEL_15:
      for ( j = String; *j; (j++)[v9 - String] = sub_633CD6() )
      {
        if ( !sub_633848() )
          break;
      }
      v9[v5] = 0;
      if ( !strcmp(v9, "POSITION") )
      {
        v8 = 0;
LABEL_48:
        *a2 = v8;
        *a3 = v10;
        return 0;
      }
      if ( !strcmp(v9, "BLENDWEIGHT") )
      {
        v8 = 1;
        goto LABEL_48;
      }
      if ( !strcmp(v9, "BLENDINDICES") )
      {
        v8 = 2;
        goto LABEL_48;
      }
      if ( !strcmp(v9, "NORMAL") )
      {
        v8 = 3;
        goto LABEL_48;
      }
      v8 = 6;
      if ( !strcmp(v9, "PSIZE") )
      {
        v8 = 4;
        goto LABEL_48;
      }
      if ( !strcmp(v9, "TEXCOORD") )
      {
        v8 = 5;
        goto LABEL_48;
      }
      if ( !strcmp(v9, "TANGENT") )
        goto LABEL_48;
      if ( !strcmp(v9, "BINORMAL") )
      {
        v8 = 7;
        goto LABEL_48;
      }
      v8 = 11;
      if ( !strcmp(v9, "TESSFACTOR") )
      {
        v8 = 8;
        goto LABEL_48;
      }
      if ( !strcmp(v9, "POSITIONT") )
      {
        v8 = 9;
        goto LABEL_48;
      }
      if ( !strcmp(v9, "COLOR") )
      {
LABEL_47:
        v8 = 10;
        goto LABEL_48;
      }
      if ( !strcmp(v9, "FOG") )
        goto LABEL_48;
      if ( !strcmp(v9, "DEPTH") )
      {
        v8 = 12;
        goto LABEL_48;
      }
      if ( !strcmp(v9, "SAMPLE") )
      {
        v8 = 13;
        goto LABEL_48;
      }
      if ( !strcmp(v9, "DIFFUSE") )
      {
        v10 = 0;
        goto LABEL_47;
      }
      if ( !strcmp(v9, "SPECULAR") )
      {
        v10 = 1;
        goto LABEL_47;
      }
    }
  }
  return -2147467259;
}
