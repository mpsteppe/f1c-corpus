int __thiscall sub_5B3910(void *this, char *FileName)
{
  int v2; // edi
  FILE *v4; // eax
  FILE *v5; // esi
  size_t v6; // ebx
  int v7; // ebx
  const char *v8; // edi
  FILE *v9; // eax
  FILE *v10; // esi
  size_t v11; // edi
  int v12; // esi
  int v13; // ebx
  char Buffer[256]; // [esp+14h] [ebp-200h] BYREF
  char v16[256]; // [esp+114h] [ebp-100h] BYREF

  v2 = (int)this;
  if ( !*FileName )
  {
    sprintf(Buffer, "Illegal scene file name %s", FileName);
    sub_591C60(v2, -1, Buffer);
    return -1;
  }
  v4 = fopen(FileName, aRb);
  v5 = v4;
  if ( v4 )
  {
    fseek(v4, 0, 2);
    v6 = ftell(v5);
    fseek(v5, 0, 0);
    if ( sub_5B3460(v2, v5, v6) )
    {
      fclose(v5);
      return -1;
    }
    fclose(v5);
    return 0;
  }
  v7 = 0;
  if ( dword_7E8D58 > 0 )
  {
    v8 = byte_7E4CCC;
    while ( 1 )
    {
      sprintf(v16, "%s\\%s", v8, FileName);
      v9 = fopen(v16, aRb);
      v10 = v9;
      if ( v9 )
        break;
      ++v7;
      v8 += 132;
      if ( v7 >= dword_7E8D58 )
        goto LABEL_16;
    }
    fseek(v9, 0, 2);
    v11 = ftell(v10);
    fseek(v10, 0, 0);
    if ( sub_5B3460((int)this, v10, v11) )
    {
      fclose(v10);
      return -1;
    }
    fclose(v10);
LABEL_16:
    v2 = (int)this;
  }
  if ( v7 == dword_7E8D58 )
  {
    v12 = ElementCount;
    v13 = 0;
    if ( ElementCount )
    {
      while ( sub_5AF100(v12, FileName) )
      {
        v12 = *(_DWORD *)(v12 + 304);
        ++v13;
        if ( !v12 )
          goto LABEL_25;
      }
      if ( sub_5B3460(v2, *(FILE **)(v12 + 16), *(_DWORD *)((*(_DWORD *)(v12 + 292) << 8) + *(_DWORD *)(v12 + 296) + 8)) )
        return -1;
    }
  }
  else
  {
    v13 = -1;
  }
LABEL_25:
  if ( v13 != dword_7E5D54 )
    return 0;
  sprintf(Buffer, "Could not locate scene file %s", FileName);
  sub_591C60(v2, -1, Buffer);
  return -1;
}
