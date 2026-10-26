int __thiscall sub_47B730(int this, int a2)
{
  const char *v3; // ebp
  unsigned int v4; // kr0C_4
  int v5; // ecx
  int v6; // edi
  int v7; // esi
  int v8; // eax
  char *v9; // eax
  int v10; // eax
  int v11; // eax
  char v12; // cl
  int result; // eax
  char v14; // dl
  char v15; // [esp+13h] [ebp-11h]
  int v16; // [esp+14h] [ebp-10h]
  int v17; // [esp+1Ch] [ebp-8h] BYREF
  _BYTE v18[4]; // [esp+20h] [ebp-4h] BYREF

  v3 = **(const char ***)(this + 224);
  if ( !v3 )
    v3 = byte_5EA438;
  v4 = strlen(v3) + 1;
  v5 = a2;
  v16 = a2;
  v6 = 32;
  do
  {
    v7 = v6 + v5;
    if ( v6 + v5 <= (int)(v4 - 1) )
    {
      v15 = v3[v7];
      v3[v7] = 0;
      v8 = *(_DWORD *)(this + 200);
      if ( v8 )
      {
        v9 = *(char **)(v8 + 64);
        if ( !v9 )
          v9 = byte_5EA438;
        sub_498560(v9);
      }
      TextRenderToSurface(&v3[a2], &v17, v18, 1);
      v10 = v17;
      v3[v7] = v15;
      if ( v10 <= *(_DWORD *)(this + 256) )
        v16 = v7;
      else
        v6 /= 2;
      v5 = v16;
    }
    else
    {
      v6 /= 2;
    }
  }
  while ( v6 > 0 );
  if ( v3[v5] )
  {
    v11 = v5 - 1;
    if ( v5 - 1 >= a2 )
    {
      while ( 1 )
      {
        v12 = v3[v11];
        if ( v12 == 32 || v12 == -1 )
          break;
        if ( --v11 < a2 )
          goto LABEL_22;
      }
      v16 = v11 + 1;
LABEL_22:
      v5 = v16;
    }
  }
  result = a2;
  if ( a2 >= v5 )
    return v5;
  while ( 1 )
  {
    v14 = v3[result++];
    if ( v14 == -1 )
      break;
    if ( result >= v5 )
      return v5;
  }
  return result;
}

