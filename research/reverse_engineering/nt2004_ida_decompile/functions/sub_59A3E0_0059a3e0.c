int __thiscall sub_59A3E0(_DWORD *this, char *FileName)
{
  FILE *v3; // esi
  int v5; // ebx
  const char *v6; // edi
  FILE *v7; // esi
  size_t v8; // esi
  int v9; // edi
  char Buffer[256]; // [esp+14h] [ebp-100h] BYREF

  v3 = fopen(FileName, aRb);
  if ( v3 )
  {
    if ( sub_599F40(this, 0, 410) )
    {
      fclose(v3);
      return -1;
    }
    fclose(v3);
    return 0;
  }
  v5 = 0;
  if ( dword_7E8D58 > 0 )
  {
    v6 = byte_7E4CCC;
    while ( 1 )
    {
      sprintf(Buffer, "%s\\%s", v6, FileName);
      v7 = fopen(Buffer, aRb);
      if ( v7 )
        break;
      ++v5;
      v6 += 132;
      if ( v5 >= dword_7E8D58 )
        goto LABEL_14;
    }
    if ( sub_599F40(this, 0, 410) )
    {
      fclose(v7);
      return -1;
    }
    fclose(v7);
  }
LABEL_14:
  if ( v5 == dword_7E8D58 )
  {
    v8 = ElementCount;
    v9 = 0;
    if ( ElementCount )
    {
      while ( sub_5AF100(FileName) )
      {
        v8 = *(_DWORD *)(v8 + 304);
        ++v9;
        if ( !v8 )
          goto LABEL_22;
      }
      if ( sub_599F40(this, 0, 410) )
        return -1;
    }
  }
  else
  {
    v9 = -1;
  }
LABEL_22:
  if ( v9 != dword_7E5D54 )
    return 0;
  sprintf(Buffer, "Unable to locate material lib %s", FileName);
  sub_591C60((int)this, -1, Buffer);
  return -1;
}
