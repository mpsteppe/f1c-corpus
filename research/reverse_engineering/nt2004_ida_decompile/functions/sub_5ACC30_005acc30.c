int __thiscall sub_5ACC30(_BYTE *this, const char *a2)
{
  FILE *v3; // eax
  FILE *v4; // edi
  int v6; // ebx
  const char *v7; // ebp
  FILE *v8; // eax
  FILE *v9; // edi
  size_t v10; // edi
  int v11; // ebx
  char Buffer[256]; // [esp+10h] [ebp-300h] BYREF
  char Str[256]; // [esp+110h] [ebp-200h] BYREF
  char FileName[256]; // [esp+210h] [ebp-100h] BYREF

  this[28] = 0;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  strcpy(Str, a2);
  _strupr(Str);
  if ( !Str[0] || !strstr(Str, aAnm) )
  {
    sprintf(Buffer, "Illegal mesh file name %s", a2);
    sub_591C60((int)this, -1, Buffer);
    return -1;
  }
  v3 = fopen(Str, aRb);
  v4 = v3;
  if ( v3 )
  {
    if ( sub_5ACEB0(v3, 0) )
    {
      fclose(v4);
      sprintf(Buffer, "Error loading animation file %s", a2);
      sub_591C60((int)this, -1, Buffer);
      return -1;
    }
    fclose(v4);
    return 0;
  }
  v6 = 0;
  if ( dword_7E8D58 > 0 )
  {
    v7 = byte_7E4CCC;
    while ( 1 )
    {
      sprintf(FileName, "%s\\%s", v7, Str);
      v8 = fopen(FileName, aRb);
      v9 = v8;
      if ( v8 )
        break;
      ++v6;
      v7 += 132;
      if ( v6 >= dword_7E8D58 )
        goto LABEL_16;
    }
    if ( sub_5ACEB0(v8, 0) )
    {
      fclose(v9);
      sprintf(Buffer, "Error loading animation file %s", FileName);
      sub_591C60((int)this, -1, Buffer);
      return -1;
    }
    fclose(v9);
  }
LABEL_16:
  if ( v6 != dword_7E8D58 )
  {
    v11 = -1;
LABEL_24:
    if ( v11 != dword_7E5D54 )
      return 0;
    sprintf(Buffer, "Could not locate mesh file %s", a2);
    sub_591C60((int)this, -1, Buffer);
    return -1;
  }
  v10 = ElementCount;
  v11 = 0;
  if ( !ElementCount )
    goto LABEL_24;
  while ( sub_5AF100(Str) )
  {
    v10 = *(_DWORD *)(v10 + 304);
    ++v11;
    if ( !v10 )
      goto LABEL_24;
  }
  if ( !sub_5ACEB0(*(FILE **)(v10 + 16), v10) )
    goto LABEL_24;
  sprintf(Buffer, "Error loading MAS animation file %s", a2);
  sub_591C60((int)this, -1, Buffer);
  return -1;
}
