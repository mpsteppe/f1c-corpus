int __thiscall sub_50D370(int *this)
{
  int v2; // eax
  int v3; // ebp
  int result; // eax
  bool v5; // zf
  int v6; // ebp
  int v7; // eax
  int v8; // ecx
  char *v9; // eax
  char **v10; // eax
  char *v11; // eax
  char *v12; // eax
  CHAR *v13; // eax
  char *v14; // eax
  CHAR *v15; // eax
  int v16; // eax
  int i; // esi
  int v18; // ecx
  int v19; // eax
  int *v20; // eax
  int v21; // ecx
  int j; // esi
  int v23; // edx
  int v24; // ecx
  int *v25; // ecx
  int v26; // eax
  int k; // esi
  int v28; // ecx
  int v29; // eax
  CHAR **v30; // eax
  CHAR *v31; // eax
  int v32; // edx
  char *v33; // edi
  int v34; // ecx
  __int16 v35; // ax
  int v36; // edx
  char *v37; // edi
  CHAR *v38; // esi
  CHAR *v39; // eax
  CHAR *v40; // ecx
  int v41; // ecx
  char *m; // eax
  CHAR *v43; // esi
  CHAR *v44; // eax
  char *v45; // eax
  int v46; // esi
  int v47; // ebp
  char v48; // bl
  char *v49; // edi
  CHAR *v50; // ecx
  char *v51; // eax
  char *v52; // edi
  const char *v53; // ecx
  const char *v54; // eax
  char *v55; // eax
  int v56; // esi
  int v57; // ebp
  __int16 v58; // bx
  char *v59; // edi
  CHAR *v60; // ecx
  char v61; // al
  char *v62; // eax
  char v63; // dl
  char *v64; // edi
  const char *v65; // ecx
  const char *v66; // eax
  char *v67; // eax
  int v68; // esi
  int v69; // ebx
  int v70; // ebp
  char *v71; // edi
  CHAR *v72; // ecx
  void *v73; // eax
  char *v74; // eax
  void *v75; // edx
  char *v76; // edi
  const char *v77; // ecx
  const char *v78; // eax
  char *v79; // eax
  int v80; // esi
  int v81; // ebp
  int v82; // ebx
  char *v83; // edi
  __int16 v84; // ax
  char v85; // cl
  const char *v86; // eax
  const char *v87; // ecx
  char *v88; // eax
  char *v89; // edi
  __int16 v90; // ax
  char v91; // cl
  int v92; // eax
  const char *v93; // ecx
  const char *v94; // eax
  const char **v95; // [esp+8h] [ebp-1014h]
  char Buffer[8]; // [esp+14h] [ebp-1008h] BYREF
  char FileName[512]; // [esp+1Ch] [ebp-1000h] BYREF
  char v99[512]; // [esp+21Ch] [ebp-E00h] BYREF
  char ArgList[512]; // [esp+41Ch] [ebp-C00h] BYREF
  char v101[512]; // [esp+61Ch] [ebp-A00h] BYREF
  char v102[512]; // [esp+81Ch] [ebp-800h] BYREF
  char v103[512]; // [esp+A1Ch] [ebp-600h] BYREF
  char v104[512]; // [esp+C1Ch] [ebp-400h] BYREF
  char v105[512]; // [esp+E1Ch] [ebp-200h] BYREF

  v2 = *this;
  *((_BYTE *)this + 156) = 1;
  v3 = *(_DWORD *)(v2 + 25252);
  result = dword_7D6A5C;
  v3 *= 1232;
  v5 = dword_7D6A5C + v3 == 0;
  v6 = dword_7D6A5C + v3;
  v95 = (const char **)v6;
  if ( !v5 )
  {
    if ( (v7 = sub_4E6CD0((char *)v6), v7 > 0) && this[37] < v7 || (result = this[38]) != 0 )
    {
      v8 = *this;
      FileName[0] = 0;
      v99[0] = 0;
      v101[0] = 0;
      ArgList[0] = 0;
      v102[0] = 0;
      v104[0] = 0;
      v103[0] = 0;
      v105[0] = 0;
      sprintf(Buffer, "_%02d", *(_DWORD *)(v8 + 25248));
      sub_405480(ArgList, 0x1FFu, "%s", (const char *)(v6 + 1164));
      v9 = &ArgList[strlen(ArgList)];
      if ( v9 > ArgList )
      {
        while ( *v9 != 46 )
        {
          if ( --v9 <= ArgList )
            goto LABEL_10;
        }
        *v9 = 0;
      }
LABEL_10:
      strcat(ArgList, Buffer);
      sub_405480(v102, 0x1FFu, Format, ArgList, &off_613158);
      sub_405480(v104, 0x1FFu, "%s%s", ArgList, aDriver_0);
      sub_405480(v103, 0x1FFu, "%s%s", ArgList, aDriverArm);
      sub_405480(v105, 0x1FFu, "%s%s", ArgList, aDriverhelm);
      v10 = (char **)this[38];
      if ( v10 )
      {
        v11 = *v10;
        if ( !v11 )
          v11 = &byte_629120;
        sub_4ED790(&dword_7D6B74, v11);
        v12 = *(char **)(this[38] + 8);
        if ( !v12 )
          v12 = &byte_629120;
        sub_4ED7B0(&dword_7D6B74, v12);
        v13 = *(CHAR **)(this[38] + 16);
        if ( !v13 )
          v13 = &byte_629120;
        sub_4ED7D0(&dword_7D6B74, (int)v13);
        v14 = *(char **)(this[38] + 24);
        if ( !v14 )
          v14 = &byte_629120;
        sub_4ED7F0(&dword_7D6B74, v14);
        v15 = *(CHAR **)(this[38] + 32);
        if ( !v15 )
          v15 = &byte_629120;
        sub_4ED810(&dword_7D6B74, (int)v15);
        v16 = this[38];
        for ( i = 0; i < *(_DWORD *)(v16 + 52); ++i )
        {
          v18 = i;
          if ( i >= 0 && i < *(_DWORD *)(v16 + 52) )
          {
            v19 = *(_DWORD *)(v16 + 40);
            if ( i <= 0 )
            {
LABEL_27:
              if ( v19 )
              {
                v20 = *(int **)v19;
                goto LABEL_30;
              }
            }
            else
            {
              while ( v19 )
              {
                v19 = *(_DWORD *)(v19 + 4);
                if ( --v18 <= 0 )
                  goto LABEL_27;
              }
            }
          }
          v20 = 0;
LABEL_30:
          sub_4ED830(&dword_7D6B74, *v20, i);
          v16 = this[38];
        }
        v21 = this[38];
        for ( j = 0; j < *(_DWORD *)(v21 + 68); ++j )
        {
          v23 = j;
          if ( j >= 0 && j < *(_DWORD *)(v21 + 68) )
          {
            v24 = *(_DWORD *)(v21 + 56);
            if ( j <= 0 )
            {
LABEL_37:
              if ( v24 )
              {
                v25 = *(int **)v24;
                goto LABEL_40;
              }
            }
            else
            {
              while ( v24 )
              {
                v24 = *(_DWORD *)(v24 + 4);
                if ( --v23 <= 0 )
                  goto LABEL_37;
              }
            }
          }
          v25 = 0;
LABEL_40:
          sub_4ED850(&dword_7D6B74, j != 0 ? 2 : 0, *v25);
          v21 = this[38];
        }
        v26 = this[38];
        for ( k = 0; k < *(_DWORD *)(v26 + 84); ++k )
        {
          v28 = k;
          if ( k >= 0 && k < *(_DWORD *)(v26 + 84) )
          {
            v29 = *(_DWORD *)(v26 + 72);
            if ( k <= 0 )
            {
LABEL_47:
              if ( v29 )
              {
                v30 = *(CHAR ***)v29;
                goto LABEL_50;
              }
            }
            else
            {
              while ( v29 )
              {
                v29 = *(_DWORD *)(v29 + 4);
                if ( --v28 <= 0 )
                  goto LABEL_47;
              }
            }
          }
          v30 = 0;
LABEL_50:
          v31 = *v30;
          if ( !v31 )
            v31 = &byte_629120;
          sub_4ED870(&dword_7D6B74, (int)v31, k);
          v26 = this[38];
        }
        sub_4CD5B0(byte_7663E0, FileName, 511);
        v32 = dword_61317C;
        v33 = &FileName[strlen(FileName) + 1];
        v34 = dword_613178;
        *(_DWORD *)--v33 = dword_613174;
        v35 = word_613180;
        *((_DWORD *)v33 + 1) = v34;
        LOBYTE(v34) = byte_613182;
        *((_DWORD *)v33 + 2) = v32;
        v36 = dword_5FC1F8;
        *((_WORD *)v33 + 6) = v35;
        v33[14] = v34;
        LOBYTE(v35) = byte_5FC1FC;
        v37 = &FileName[strlen(FileName)];
        *(_DWORD *)v37 = v36;
        v37[4] = v35;
        sub_4ED5C0(&dword_7D6B74, FileName);
        remove(FileName);
        v38 = sub_410E00((CHAR **)dword_62A0D0);
        v39 = sub_410E00((CHAR **)&dword_62A120);
        sub_405480(FileName, 0x1FFu, "%s%s%s", v38, v39, aCreateacarTga);
      }
      else
      {
        sub_4E7140((const char **)v6, this[37], FileName, 512);
      }
      v40 = *(CHAR **)v6;
      if ( !*(_DWORD *)v6 )
        v40 = &byte_629120;
      strcpy(v99, v40);
      v41 = strlen(v99);
      if ( v41 > 0 )
      {
        for ( m = &FileName[v41 + 511]; m >= v99; *m-- = 0 )
        {
          if ( *m == 92 )
            break;
        }
      }
      strcat(v99, (const char *)(v6 + 1164));
      v43 = sub_410E00((CHAR **)dword_62A068);
      v44 = sub_410E00((CHAR **)&dword_62A0B8);
      sprintf(v101, "%s%s%s%s", v43, v44, aWccarbody, (const char *)&dword_610E1C);
      sub_505E80(ArgList, 1, FileName, v99, v101, 0);
      sub_4E7140((const char **)v6, this[37], FileName, 512);
      v45 = &FileName[strlen(FileName)];
      if ( v45 > FileName )
      {
        while ( *v45 != 46 )
        {
          if ( --v45 <= FileName )
            goto LABEL_66;
        }
        *v45 = 0;
      }
LABEL_66:
      v46 = dword_6011F4;
      v47 = dword_6011F8;
      v48 = byte_6011FC;
      v49 = &FileName[strlen(FileName) + 1];
      v50 = (CHAR *)*v95;
      --v49;
      v5 = *v95 == 0;
      *(_DWORD *)v49 = dword_6011F4;
      *((_DWORD *)v49 + 1) = v47;
      v49[8] = v48;
      if ( v5 )
        v50 = &byte_629120;
      strcpy(v99, v50);
      v51 = &v99[strlen(v99)];
      if ( v51 > v99 )
      {
        while ( *v51 != 46 )
        {
          if ( --v51 <= v99 )
            goto LABEL_73;
        }
        *v51 = 0;
      }
LABEL_73:
      v52 = &v99[strlen(v99) + 1];
      v53 = (const char *)dword_62A0B8;
      --v52;
      v5 = dword_62A0B8 == 0;
      *(_DWORD *)v52 = v46;
      *((_DWORD *)v52 + 1) = v47;
      v52[8] = v48;
      if ( v5 )
        v53 = &byte_629120;
      v54 = *(const char **)dword_62A068;
      if ( !*(_DWORD *)dword_62A068 )
        v54 = &byte_629120;
      sprintf(v101, "%s%s%s%s", v54, v53, aWcrims, aBmp_0);
      sub_505E80(v102, 1, FileName, v99, v101, 0);
      sub_4E7140(v95, this[37], FileName, 512);
      v55 = &FileName[strlen(FileName)];
      if ( v55 > FileName )
      {
        while ( *v55 != 46 )
        {
          if ( --v55 <= FileName )
            goto LABEL_82;
        }
        *v55 = 0;
      }
LABEL_82:
      v56 = dword_6011CC;
      v57 = dword_6011D0;
      v58 = word_6011D4;
      v59 = &FileName[strlen(FileName) + 1];
      v60 = (CHAR *)*v95;
      v61 = byte_6011D6;
      --v59;
      v5 = *v95 == 0;
      *(_DWORD *)v59 = dword_6011CC;
      *((_DWORD *)v59 + 1) = v57;
      *((_WORD *)v59 + 4) = v58;
      v59[10] = v61;
      if ( v5 )
        v60 = &byte_629120;
      strcpy(v99, v60);
      v62 = &v99[strlen(v99)];
      if ( v62 > v99 )
      {
        while ( *v62 != 46 )
        {
          if ( --v62 <= v99 )
            goto LABEL_89;
        }
        *v62 = 0;
      }
LABEL_89:
      v63 = byte_6011D6;
      v64 = &v99[strlen(v99) + 1];
      v65 = (const char *)dword_62A0B8;
      --v64;
      v5 = dword_62A0B8 == 0;
      *(_DWORD *)v64 = v56;
      *((_DWORD *)v64 + 1) = v57;
      *((_WORD *)v64 + 4) = v58;
      v64[10] = v63;
      if ( v5 )
        v65 = &byte_629120;
      v66 = *(const char **)dword_62A068;
      if ( !*(_DWORD *)dword_62A068 )
        v66 = &byte_629120;
      sprintf(v101, "%s%s%s%s", v66, v65, aWccardriver, aBmp_0);
      sub_505E80(v104, 1, FileName, v99, v101, 0);
      sub_4E7140(v95, this[37], FileName, 512);
      v67 = &FileName[strlen(FileName)];
      if ( v67 > FileName )
      {
        while ( *v67 != 46 )
        {
          if ( --v67 <= FileName )
            goto LABEL_98;
        }
        *v67 = 0;
      }
LABEL_98:
      v68 = dword_613164;
      v69 = dword_613168;
      v70 = dword_61316C;
      v71 = &FileName[strlen(FileName) + 1];
      v72 = (CHAR *)*v95;
      v73 = off_613170;
      --v71;
      v5 = *v95 == 0;
      *(_DWORD *)v71 = dword_613164;
      *((_DWORD *)v71 + 1) = v69;
      *((_DWORD *)v71 + 2) = v70;
      *((_DWORD *)v71 + 3) = v73;
      if ( v5 )
        v72 = &byte_629120;
      strcpy(v99, v72);
      v74 = &v99[strlen(v99)];
      if ( v74 > v99 )
      {
        while ( *v74 != 46 )
        {
          if ( --v74 <= v99 )
            goto LABEL_105;
        }
        *v74 = 0;
      }
LABEL_105:
      v75 = off_613170;
      v76 = &v99[strlen(v99) + 1];
      v77 = (const char *)dword_62A0B8;
      --v76;
      v5 = dword_62A0B8 == 0;
      *(_DWORD *)v76 = v68;
      *((_DWORD *)v76 + 1) = v69;
      *((_DWORD *)v76 + 2) = v70;
      *((_DWORD *)v76 + 3) = v75;
      if ( v5 )
        v77 = &byte_629120;
      v78 = *(const char **)dword_62A068;
      if ( !*(_DWORD *)dword_62A068 )
        v78 = &byte_629120;
      sprintf(v101, "%s%s%s%s", v78, v77, aWcDriverArm, aBmp_0);
      sub_505E80(v103, 1, FileName, v99, v101, 0);
      sub_4E7140(v95, this[37], FileName, 512);
      v79 = &FileName[strlen(FileName)];
      if ( v79 > FileName )
      {
        while ( *v79 != 46 )
        {
          if ( --v79 <= FileName )
            goto LABEL_114;
        }
        *v79 = 0;
      }
LABEL_114:
      v80 = dword_6011B0;
      v81 = dword_6011B4;
      v82 = dword_6011B8;
      v83 = &FileName[strlen(FileName) + 1];
      v84 = word_6011BC;
      v85 = byte_6011BE;
      *(_DWORD *)--v83 = dword_6011B0;
      *((_DWORD *)v83 + 1) = v81;
      *((_DWORD *)v83 + 2) = v82;
      *((_WORD *)v83 + 6) = v84;
      v86 = *v95;
      v5 = *v95 == 0;
      v83[14] = v85;
      v87 = v86;
      if ( v5 )
        v87 = &byte_629120;
      strcpy(v99, v87);
      v88 = &v99[strlen(v99)];
      if ( v88 > v99 )
      {
        while ( *v88 != 46 )
        {
          if ( --v88 <= v99 )
            goto LABEL_121;
        }
        *v88 = 0;
      }
LABEL_121:
      v89 = &v99[strlen(v99) + 1];
      v90 = word_6011BC;
      v91 = byte_6011BE;
      *(_DWORD *)--v89 = v80;
      *((_DWORD *)v89 + 1) = v81;
      *((_DWORD *)v89 + 2) = v82;
      *((_WORD *)v89 + 6) = v90;
      v92 = dword_62A0B8;
      v5 = dword_62A0B8 == 0;
      v89[14] = v91;
      v93 = (const char *)v92;
      if ( v5 )
        v93 = &byte_629120;
      v94 = *(const char **)dword_62A068;
      if ( !*(_DWORD *)dword_62A068 )
        v94 = &byte_629120;
      sprintf(v101, "%s%s%s%s", v94, v93, aWcdriverhelm, aBmp_0);
      return sub_505E80(v105, 1, FileName, v99, v101, 0);
    }
  }
  return result;
}
