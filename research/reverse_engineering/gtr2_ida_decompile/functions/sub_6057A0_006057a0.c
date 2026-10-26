int __thiscall sub_6057A0(char *this, _DWORD *a2)
{
  double *v3; // esi
  int v4; // edi
  HANDLE CurrentProcess; // eax
  int v6; // edi
  HANDLE v7; // eax
  HANDLE v8; // eax
  int v9; // edx
  int v10; // ebx
  int v11; // esi
  int v12; // esi
  int v13; // esi
  int v14; // esi
  int v15; // edx
  _BYTE *v16; // esi
  int v17; // eax
  int v18; // edi
  int v19; // eax
  int v20; // eax
  char *v21; // esi
  char *v23; // edi
  int v24; // ecx
  char *v25; // esi
  char *v27; // esi
  char *v29; // esi
  char *v31; // esi
  char *v33; // esi
  int v35; // eax
  char *v36; // esi
  char *v38; // esi
  int v41; // eax
  char *v42; // esi
  char *v44; // esi
  char *v46; // esi
  char *v48; // esi
  char *v50; // esi
  char *v53; // esi
  char *v55; // esi
  _DWORD *v57; // esi
  char v58; // al
  char *v59; // esi
  int v61; // eax
  int v62; // eax
  char *v63; // esi
  char *v65; // esi
  char *v68; // esi
  SIZE_T dwTotalPhys; // eax
  SIZE_T dwAvailPageFile; // ecx
  SIZE_T dwAvailPhys; // eax
  SIZE_T dwTotalPageFile; // eax
  char *v75; // eax
  unsigned int i; // ebx
  char *v77; // eax
  char v78; // cl
  void *Block; // [esp+18h] [ebp-160h]
  int *Blocka; // [esp+18h] [ebp-160h]
  signed int dwPriorityClass; // [esp+1Ch] [ebp-15Ch]
  DWORD dwPriorityClassa; // [esp+1Ch] [ebp-15Ch]
  __int64 v83; // [esp+20h] [ebp-158h] BYREF
  unsigned int v84; // [esp+28h] [ebp-150h] BYREF
  DWORD v85; // [esp+2Ch] [ebp-14Ch] BYREF
  _MEMORYSTATUS Buffer; // [esp+34h] [ebp-144h] BYREF
  struct _SYSTEM_INFO SystemInfo; // [esp+54h] [ebp-124h] BYREF
  _BYTE v89[253]; // [esp+78h] [ebp-100h] BYREF
  __int16 v90; // [esp+175h] [ebp-3h]
  char v91; // [esp+177h] [ebp-1h]

  memset(v89, 0, sizeof(v89));
  v90 = 0;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 207) = 0;
  v91 = 0;
  v3 = (double *)(this + 4);
  *((_DWORD *)this + 1) = 1852534357;
  *((_DWORD *)this + 2) = (char *)&loc_6E776B + 4;
  GetSystemInfo(&SystemInfo);
  if ( SystemInfo.dwProcessorType != 486 && SystemInfo.dwProcessorType != 586 )
    goto LABEL_127;
  if ( sub_5F5590((_DWORD *)&v83 + 1, &v83, (int)(this + 4), v89) )
  {
    Sleep(0);
    CurrentProcess = GetCurrentProcess();
    dwPriorityClassa = GetPriorityClass(CurrentProcess);
    v6 = 0;
    Blocka = (int *)operator new(0x14u);
    do
    {
      v7 = GetCurrentProcess();
      SetPriorityClass(v7, 0x80u);
      v3 = (double *)sub_5F5CE0((__int32)v3, 1);
      sub_5F5C70((int)v3, 1);
      sub_5F5760(v3, (LONG *)&v84, &v85, 2);
      while ( sub_5F59A0((int)v3) < 0.1 )
        ;
      sub_5F5760(v3, (LONG *)&v83 + 1, (DWORD *)&v83, 2);
      v8 = GetCurrentProcess();
      SetPriorityClass(v8, dwPriorityClassa);
      sub_5F5D40(v3);
      v83 -= __PAIR64__(v84, v85);
      sub_5D7710((int)dword_FB27A8, v9, 2, 0);
      Blocka[v6++] = (unsigned __int64)(((double)HIDWORD(v83) * 4294967300.0 * 0.000001
                                       + (double)(unsigned int)v83 * 0.000001)
                                      * 10.0);
    }
    while ( v6 < 5 );
    v10 = *Blocka;
    v11 = Blocka[1];
    dwPriorityClass = *Blocka;
    if ( (double)*Blocka * 0.05 > (double)(int)abs32(*Blocka - v11) )
    {
      v10 = (v11 + v10) / 2;
      dwPriorityClass = v10;
    }
    v12 = Blocka[2];
    if ( (double)dwPriorityClass * 0.05 > (double)(int)abs32(v10 - v12) )
    {
      v10 = (v12 + v10) / 2;
      dwPriorityClass = v10;
    }
    v13 = Blocka[3];
    if ( (double)dwPriorityClass * 0.05 > (double)(int)abs32(v10 - v13) )
    {
      v10 = (v13 + v10) / 2;
      dwPriorityClass = v10;
    }
    v14 = Blocka[4];
    if ( (double)dwPriorityClass * 0.05 > (double)(int)abs32(v10 - v14) )
    {
      v10 = (v10 + v14) / 2;
      dwPriorityClass = v10;
    }
    j__free(Blocka);
    sub_5D7710((int)dword_FB27A8, v15, 1, 0);
    v16 = this + 4;
    v17 = sub_5F5590((_DWORD *)&v83 + 1, &v83, (int)(this + 4), 0);
    v18 = v17 & 0x3000;
    Block = (void *)v17;
    if ( (v17 & 0x3000) != 0 )
    {
      if ( v18 == 4096 )
      {
        v19 = v17 & 0xF00;
        if ( v19 == 1280 || v19 == 1536 )
          return off_16C9260(a2);
        goto LABEL_126;
      }
      if ( v18 != 0x2000 )
        goto LABEL_126;
    }
    if ( !_stricmp(this + 4, "GenuineIntel") )
    {
      if ( v18 == 0x2000 )
        strcpy(this + 4, "Dual ");
      else
        *v16 = 0;
      v20 = (unsigned __int16)Block & 0xF00;
      if ( v20 != 1280 )
      {
        if ( v20 == 1536 )
        {
          switch ( (unsigned __int8)Block & 0xF0 )
          {
            case 0x10:
              v25 = this + 3;
              while ( *++v25 )
                ;
              strcpy(v25, "Intel Pentium Pro");
              return off_16C9260(a2);
            case 0x30:
            case 0x50:
              v27 = this + 3;
              while ( *++v27 )
                ;
              strcpy(v27, "Intel Pentium II");
              break;
            case 0x60:
              v29 = this + 3;
              while ( *++v29 )
                ;
              strcpy(v29, "Intel Celeron");
              break;
            case 0x70:
            case 0x80:
              v31 = this + 3;
              while ( *++v31 )
                ;
              strcpy(v31, "Intel Pentium III");
              *((_DWORD *)this + 207) |= 3u;
              *(_DWORD *)this = 2;
              if ( v10 <= 400 )
                *(_DWORD *)this = 1;
              goto LABEL_126;
            case 0x90:
              v33 = this + 3;
              while ( *++v33 )
                ;
              v23 = v33;
              qmemcpy(v33, "Intel Pentiu", 12);
              v24 = 5054573;
              goto LABEL_33;
            default:
              goto LABEL_126;
          }
          *((_DWORD *)this + 207) |= 1u;
          *(_DWORD *)this = 1;
        }
        else if ( v20 == 3840 )
        {
          v21 = this + 3;
          while ( *++v21 )
            ;
          v23 = v21;
          qmemcpy(v21, "Intel Pentiu", 12);
          v24 = 3416173;
LABEL_33:
          *((_DWORD *)v23 + 3) = v24;
          *((_DWORD *)this + 207) |= 3u;
          *(_DWORD *)this = 3;
        }
        goto LABEL_126;
      }
      v35 = (unsigned __int8)Block & 0xF0;
      switch ( v35 )
      {
        case 16:
          v38 = this + 3;
          while ( *++v38 )
            ;
          break;
        case 32:
          v38 = this + 3;
          while ( *++v38 )
            ;
          break;
        case 64:
          v36 = this + 3;
          while ( *++v36 )
            ;
          strcpy(v36, "Intel Pentium MMX");
          *((_DWORD *)this + 207) |= 1u;
          return off_16C9260(a2);
        default:
LABEL_126:
          *((_DWORD *)this + 65) = 1;
LABEL_127:
          v4 = dwPriorityClass;
          goto LABEL_128;
      }
      strcpy(v38, "Intel Pentium");
      return off_16C9260(a2);
    }
    if ( !_stricmp(this + 4, "AuthenticAMD") )
    {
      if ( v18 == 0x2000 )
        strcpy(this + 4, "Dual ");
      else
        *v16 = 0;
      v41 = (unsigned __int16)Block & 0xF00;
      switch ( v41 )
      {
        case 1280:
          switch ( (unsigned __int8)Block & 0xF0 )
          {
            case 0:
            case 0x10:
            case 0x20:
            case 0x30:
              v53 = this + 3;
              while ( *++v53 )
                ;
              strcpy(v53, "AMD K5 (tm) Processor");
              return off_16C9260(a2);
            case 0x60:
            case 0x70:
              v55 = this + 3;
              while ( *++v55 )
                ;
              strcpy(v55, "AMD K6 MMX");
              *((_DWORD *)this + 207) |= 1u;
              return off_16C9260(a2);
            case 0x80:
              v57 = this + 3;
              do
              {
                v58 = *((_BYTE *)v57 + 1);
                v57 = (_DWORD *)((char *)v57 + 1);
              }
              while ( v58 );
              qmemcpy(v57, "AMD K6 3D Proces", 16);
              v57[4] = &unk_726F73;
              *((_DWORD *)this + 207) |= 1u;
              return off_16C9260(a2);
            case 0x90:
              v59 = this + 3;
              while ( *++v59 )
                ;
              strcpy(v59, "AMD K6 3D+ Processor");
              v61 = *((_DWORD *)this + 207) | 1;
              *(_DWORD *)this = 1;
              *((_DWORD *)this + 207) = v61;
              goto LABEL_126;
            default:
              goto LABEL_126;
          }
        case 1536:
          switch ( (unsigned __int8)Block & 0xF0 )
          {
            case 0x10:
            case 0x20:
            case 0x40:
              v44 = this + 3;
              while ( *++v44 )
                ;
              strcpy(v44, "AMD Athlon (tm) Processor");
              goto LABEL_81;
            case 0x30:
            case 0x70:
              v46 = this + 3;
              while ( *++v46 )
                ;
              strcpy(v46, "AMD Duron (tm) Processor");
LABEL_81:
              *((_DWORD *)this + 207) |= 3u;
              *(_DWORD *)this = 2;
              goto LABEL_126;
            case 0x60:
              v48 = this + 3;
              while ( *++v48 )
                ;
              strcpy(v48, "AMD Athlon (tm) Processor");
              *((_DWORD *)this + 207) |= 3u;
              *(_DWORD *)this = 3;
              if ( v10 <= 1200 )
                *(_DWORD *)this = 2;
              goto LABEL_126;
            case 0x80:
              v50 = this + 3;
              while ( *++v50 )
                ;
              goto LABEL_91;
            case 0xA0:
              v50 = this + 3;
              while ( *++v50 )
                ;
LABEL_91:
              strcpy(v50, "AMD Athlon (tm) Processor");
              *((_DWORD *)this + 207) |= 3u;
              *(_DWORD *)this = 4;
              if ( v10 <= 1800 )
                *(_DWORD *)this = 3;
              break;
            default:
              goto LABEL_126;
          }
          break;
        case 3840:
          v42 = this + 3;
          while ( *++v42 )
            ;
          strcpy(v42, "AMD Athlon64 (tm) Processor");
          *((_DWORD *)this + 207) |= 3u;
          *(_DWORD *)this = 5;
          break;
      }
      goto LABEL_126;
    }
    if ( !_stricmp(this + 4, "CyrixInstead") )
    {
      if ( v18 == 0x2000 )
        strcpy(this + 4, "Dual ");
      else
        *v16 = 0;
      v62 = (unsigned __int16)Block & 0xF00;
      switch ( v62 )
      {
        case 1024:
          if ( ((unsigned __int8)Block & 0xF0) == 0x40 )
          {
            v68 = this + 3;
            while ( *++v68 )
              ;
            strcpy(v68, "Cyrix MediaGX");
            return off_16C9260(a2);
          }
          break;
        case 1280:
          v65 = this + 3;
          if ( ((unsigned __int8)Block & 0xF0) == 0x20 )
          {
            while ( *++v65 )
              ;
            strcpy(v65, "Cyrix 6x86");
          }
          else
          {
            while ( *++v65 )
              ;
            strcpy(v65, "Cyrix MediaGX MMX");
            *((_DWORD *)this + 207) |= 1u;
          }
          return off_16C9260(a2);
        case 1536:
          v63 = this + 3;
          while ( *++v63 )
            ;
          strcpy(v63, "Cyrix 6x86MX");
          return off_16C9260(a2);
      }
    }
    goto LABEL_126;
  }
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 65) = 0;
  *(_DWORD *)v3 = 762212174;
  strcpy(this + 8, "compatible CPU");
  v4 = 0;
  dwPriorityClass = 0;
LABEL_128:
  Buffer.dwLength = 32;
  GlobalMemoryStatus(&Buffer);
  if ( *(int *)this < 5 )
  {
    if ( v4 < 3000 )
    {
      if ( v4 >= 1500 )
        *(_DWORD *)this = 4;
    }
    else
    {
      *(_DWORD *)this = 5;
    }
  }
  dwTotalPhys = Buffer.dwTotalPhys;
  dwAvailPageFile = Buffer.dwAvailPageFile;
  *((_DWORD *)this + 203) = Buffer.dwTotalPhys;
  *((_DWORD *)this + 199) = dwTotalPhys;
  dwAvailPhys = Buffer.dwAvailPhys;
  *((_DWORD *)this + 204) = Buffer.dwAvailPhys;
  *((_DWORD *)this + 200) = dwAvailPhys;
  dwTotalPageFile = Buffer.dwTotalPageFile;
  *((_DWORD *)this + 202) = dwAvailPageFile;
  *((_DWORD *)this + 65) = Block;
  *((_DWORD *)this + 66) = v4;
  *((_DWORD *)this + 201) = dwTotalPageFile;
  if ( sub_4E3D00(a2) > 0 )
  {
    v75 = (char *)sub_5F6B50(a2, 0);
    sub_5FAFA0(v75, (int)(this + 532), (_DWORD *)this + 205, (_DWORD *)this + 206);
  }
  for ( i = 0; i < strlen(v89); ++i )
  {
    if ( v89[i] != 32 )
      break;
  }
  if ( !v89[0] )
  {
    v77 = this + 4;
    do
    {
      v78 = *v77;
      v77[v89 - (this + 4)] = *v77;
      ++v77;
    }
    while ( v78 );
  }
  memset(this + 4, 0, 0x100u);
  if ( *((int *)this + 66) < 1000 )
    return sprintf(this + 4, "%s @ %d MHz", &v89[i], dwPriorityClass);
  else
    return sprintf(this + 4, "%s @ %.2f GHz", &v89[i], (double)((dwPriorityClass + 50) / 100) * 0.1);
}
