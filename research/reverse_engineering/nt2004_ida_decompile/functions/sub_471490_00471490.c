int sub_471490()
{
  int result; // eax
  char *v1; // eax
  int v2; // esi
  int v3; // ebp
  char v4; // bl
  char *v5; // edi
  const char *v6; // ecx
  bool v7; // zf
  char *v8; // eax
  char *v9; // edi
  CHAR *v10; // esi
  CHAR *v11; // eax
  const char **v12; // esi
  char *v13; // eax
  int v14; // ebp
  int v15; // ebx
  char *v16; // edi
  __int16 v17; // ax
  char v18; // cl
  const char *v19; // ecx
  char *v20; // eax
  __int16 v21; // dx
  char *v22; // edi
  const char *v23; // ecx
  char v24; // al
  const char *v25; // eax
  char *v26; // eax
  int v27; // ebp
  int v28; // ebx
  int v29; // edx
  char *v30; // edi
  __int16 v31; // ax
  char v32; // cl
  const char *v33; // eax
  const char *v34; // ecx
  char *v35; // eax
  int v36; // edx
  char *v37; // edi
  __int16 v38; // ax
  char v39; // cl
  int v40; // eax
  const char *v41; // ecx
  const char *v42; // eax
  const char **v43; // [esp+0h] [ebp-804h]
  char Source[512]; // [esp+4h] [ebp-800h] BYREF
  char v45[512]; // [esp+204h] [ebp-600h] BYREF
  char Destination[512]; // [esp+404h] [ebp-400h] BYREF
  char Buffer[512]; // [esp+604h] [ebp-200h] BYREF

  result = sub_4E7760(&unk_7D6A50);
  v43 = (const char **)result;
  if ( result )
  {
    if ( *(int *)(result + 1228) > 0 )
    {
      Destination[0] = 0;
      Source[0] = 0;
      v45[0] = 0;
      Buffer[0] = 0;
      result = sub_4E7140(dword_768228, Destination, 512);
      if ( (_BYTE)result )
      {
        sub_505E80(Destination, 0, 0, dword_7656E0);
        sub_505E80(Destination, 0, 0, dword_7656E0);
        sub_505E80(Destination, 0, 0, dword_7656E0);
        strcpy(Source, Destination);
        v1 = &Source[strlen(Source)];
        if ( v1 > Source )
        {
          while ( *v1 != 46 )
          {
            if ( --v1 <= Source )
              goto LABEL_9;
          }
          *v1 = 0;
        }
LABEL_9:
        v2 = dword_6011F4;
        v3 = dword_6011F8;
        v4 = byte_6011FC;
        v5 = &Source[strlen(Source) + 1];
        v6 = *v43;
        --v5;
        v7 = *v43 == 0;
        *(_DWORD *)v5 = dword_6011F4;
        *((_DWORD *)v5 + 1) = v3;
        v5[8] = v4;
        if ( v7 )
          v6 = &byte_629120;
        strcpy(v45, v6);
        v8 = &v45[strlen(v45)];
        if ( v8 > v45 )
        {
          while ( *v8 != 46 )
          {
            if ( --v8 <= v45 )
              goto LABEL_16;
          }
          *v8 = 0;
        }
LABEL_16:
        v9 = &v45[strlen(v45)];
        *(_DWORD *)v9 = v2;
        *((_DWORD *)v9 + 1) = v3;
        v9[8] = v4;
        v10 = sub_410E00((CHAR **)dword_62A068);
        v11 = sub_410E00((CHAR **)&dword_62A0B8);
        sprintf(Buffer, "%s%s%s%s", v10, v11, aWcrims, aBmp_0);
        sub_505E80(Source, v45, Buffer, dword_7656E0);
        v12 = v43;
        sub_4E7140(dword_768228, Source, 512);
        v13 = &Source[strlen(Source)];
        if ( v13 > Source )
        {
          while ( *v13 != 46 )
          {
            if ( --v13 <= Source )
              goto LABEL_21;
          }
          *v13 = 0;
        }
LABEL_21:
        v14 = dword_6011CC;
        v15 = dword_6011D0;
        v16 = &Source[strlen(Source) + 1];
        v17 = word_6011D4;
        v18 = byte_6011D6;
        *(_DWORD *)--v16 = dword_6011CC;
        *((_DWORD *)v16 + 1) = v15;
        *((_WORD *)v16 + 4) = v17;
        v16[10] = v18;
        v19 = *v12;
        if ( !*v12 )
          v19 = &byte_629120;
        strcpy(v45, v19);
        v20 = &v45[strlen(v45)];
        if ( v20 > v45 )
        {
          while ( *v20 != 46 )
          {
            if ( --v20 <= v45 )
              goto LABEL_28;
          }
          *v20 = 0;
        }
LABEL_28:
        v21 = word_6011D4;
        v22 = &v45[strlen(v45) + 1];
        v23 = (const char *)dword_62A0B8;
        v24 = byte_6011D6;
        --v22;
        v7 = dword_62A0B8 == 0;
        *(_DWORD *)v22 = v14;
        *((_DWORD *)v22 + 1) = v15;
        *((_WORD *)v22 + 4) = v21;
        v22[10] = v24;
        if ( v7 )
          v23 = &byte_629120;
        v25 = *(const char **)dword_62A068;
        if ( !*(_DWORD *)dword_62A068 )
          v25 = &byte_629120;
        sprintf(Buffer, "%s%s%s%s", v25, v23, aWccardriver, aBmp_0);
        sub_505E80(Source, v45, Buffer, dword_7656E0);
        sub_4E7140(dword_768228, Source, 512);
        v26 = &Source[strlen(Source)];
        if ( v26 > Source )
        {
          while ( *v26 != 46 )
          {
            if ( --v26 <= Source )
              goto LABEL_37;
          }
          *v26 = 0;
        }
LABEL_37:
        v27 = dword_6011B0;
        v28 = dword_6011B4;
        v29 = dword_6011B8;
        v30 = &Source[strlen(Source) + 1];
        v31 = word_6011BC;
        v32 = byte_6011BE;
        *(_DWORD *)--v30 = dword_6011B0;
        *((_DWORD *)v30 + 1) = v28;
        *((_DWORD *)v30 + 2) = v29;
        *((_WORD *)v30 + 6) = v31;
        v33 = *v12;
        v7 = *v12 == 0;
        v30[14] = v32;
        v34 = v33;
        if ( v7 )
          v34 = &byte_629120;
        strcpy(v45, v34);
        v35 = &v45[strlen(v45)];
        if ( v35 > v45 )
        {
          while ( *v35 != 46 )
          {
            if ( --v35 <= v45 )
              goto LABEL_44;
          }
          *v35 = 0;
        }
LABEL_44:
        v36 = dword_6011B8;
        v37 = &v45[strlen(v45) + 1];
        v38 = word_6011BC;
        v39 = byte_6011BE;
        *(_DWORD *)--v37 = v27;
        *((_DWORD *)v37 + 1) = v28;
        *((_DWORD *)v37 + 2) = v36;
        *((_WORD *)v37 + 6) = v38;
        v40 = dword_62A0B8;
        v7 = dword_62A0B8 == 0;
        v37[14] = v39;
        v41 = (const char *)v40;
        if ( v7 )
          v41 = &byte_629120;
        v42 = *(const char **)dword_62A068;
        if ( !*(_DWORD *)dword_62A068 )
          v42 = &byte_629120;
        sprintf(Buffer, "%s%s%s%s", v42, v41, aWcdriverhelm, aBmp_0);
        return sub_505E80(Source, v45, Buffer, dword_7656E0);
      }
    }
  }
  return result;
}
