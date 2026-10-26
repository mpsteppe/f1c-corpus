int __thiscall sub_59D750(_BYTE *this, const char *a2)
{
  FILE *v3; // eax
  FILE *v4; // esi
  int v5; // edi
  int v6; // ebp
  unsigned int v7; // ebp
  char *v8; // edi
  int v9; // ebp
  const char *v10; // edi
  FILE *v11; // eax
  FILE *v12; // esi
  int v13; // edi
  _DWORD *v14; // esi
  int v15; // edi
  int v16; // eax
  int v18; // [esp+10h] [ebp-408h] BYREF
  int v19; // [esp+14h] [ebp-404h]
  char Format[256]; // [esp+18h] [ebp-400h] BYREF
  char Str[256]; // [esp+118h] [ebp-300h] BYREF
  char Buffer[256]; // [esp+218h] [ebp-200h] BYREF
  char FileName[256]; // [esp+318h] [ebp-100h] BYREF

  strcpy(Str, a2);
  _strupr(Str);
  if ( !Str[0] || !strstr(Str, off_6114AC) )
  {
    sprintf(Format, "Illegal mesh file name %s", Str);
    sub_591C60((int)this, -1, Format);
    return -1;
  }
  v3 = fopen(Str, aRb);
  v4 = v3;
  if ( !v3 )
  {
    v9 = 0;
    if ( dword_7E8D58 > 0 )
    {
      v10 = byte_7E4CCC;
      while ( 1 )
      {
        sprintf(FileName, "%s\\%s", v10, Str);
        v11 = fopen(FileName, aRb);
        v12 = v11;
        if ( v11 )
          break;
        ++v9;
        v10 += 132;
        if ( v9 >= dword_7E8D58 )
          goto LABEL_19;
      }
      v13 = ftell(v11);
      fseek(v12, 0, 2);
      v19 = ftell(v12);
      fseek(v12, v13, 0);
      if ( sub_59DBA0(this, v12, v19, &v18, 0, 410) )
      {
        fclose(v12);
LABEL_17:
        sub_591C90(0, Format);
        sprintf(Buffer, " for file %s", Str);
        v7 = strlen(Buffer) + 1;
        v8 = &Format[strlen(Format) + 1];
        goto LABEL_6;
      }
      fclose(v12);
    }
LABEL_19:
    if ( v9 == dword_7E8D58 )
    {
      v14 = (_DWORD *)ElementCount;
      v15 = 0;
      if ( ElementCount )
      {
        do
        {
          if ( !sub_5AF100(Str) )
          {
            v16 = sub_59DBA0(this, v14[4], *(_DWORD *)((v14[73] << 8) + v14[74] + 8), &v18, v14, 410);
            if ( !v16 )
              break;
            if ( v16 == -1 )
              goto LABEL_17;
          }
          v14 = (_DWORD *)v14[76];
          ++v15;
        }
        while ( v14 );
      }
    }
    else
    {
      v15 = -1;
    }
    if ( v15 == dword_7E5D54 )
    {
      sprintf(Format, "Could not locate mesh file %s", Str);
      sub_591C60((int)this, -1, Format);
      return -1;
    }
    goto LABEL_8;
  }
  v5 = ftell(v3);
  fseek(v4, 0, 2);
  v6 = ftell(v4);
  fseek(v4, v5, 0);
  if ( sub_59DBA0(this, v4, v6, &v18, 0, 410) )
  {
    fclose(v4);
    sub_591C90(0, Format);
    sprintf(Buffer, " for file %s", Str);
    v7 = strlen(Buffer) + 1;
    v8 = &Format[strlen(Format) + 1];
LABEL_6:
    qmemcpy(v8 - 1, Buffer, v7);
    sub_591C60((int)this, -1, Format);
    return -1;
  }
  fclose(v4);
LABEL_8:
  *(_DWORD *)(v18 + 312) = this;
  if ( (this[60] & 0x10) != 0 )
    sub_59E170(
      *(_DWORD *)(v18 + 256),
      *(_DWORD *)(v18 + 260),
      *(_DWORD *)(v18 + 264),
      *(float *)(v18 + 268),
      *(float *)(v18 + 272),
      *(float *)(v18 + 276));
  else
    sub_59E170(0, 0, 0, 0.0, 0.0, 0.0);
  sub_59E210(0, v18);
  sub_59DB10(v18);
  *((_DWORD *)this + 15) &= ~0x8000u;
  return 0;
}
