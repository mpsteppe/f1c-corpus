_DWORD *__thiscall sub_55F0D0(char *this, _DWORD *a2)
{
  char *v3; // edi
  char *v4; // eax
  int v5; // edx
  char v6; // cl
  char *v7; // eax
  int v8; // ebx
  int v9; // edi
  char v10; // cl
  HANDLE CurrentProcess; // eax
  HANDLE v12; // eax
  HANDLE v13; // eax
  __int64 v14; // rax
  int v15; // ecx
  int v16; // eax
  __int16 v17; // ax
  __int16 v18; // bx
  int v19; // ebp
  int v20; // eax
  int v21; // ebx
  char *v22; // edi
  int v23; // eax
  int v24; // eax
  int v25; // eax
  char *v26; // edi
  SIZE_T dwTotalPhys; // eax
  SIZE_T dwTotalPageFile; // edx
  SIZE_T dwAvailPhys; // eax
  _DWORD *result; // eax
  char *v31; // eax
  int dwPriorityClass; // [esp+Ch] [ebp-A8h]
  DWORD dwPriorityClassa; // [esp+Ch] [ebp-A8h]
  int dwPriorityClassb; // [esp+Ch] [ebp-A8h]
  __int64 v35; // [esp+14h] [ebp-A0h] BYREF
  unsigned int v36; // [esp+1Ch] [ebp-98h] BYREF
  unsigned int v37; // [esp+20h] [ebp-94h] BYREF
  struct _MEMORYSTATUS Buffer; // [esp+24h] [ebp-90h] BYREF
  double v39[9]; // [esp+44h] [ebp-70h] BYREF
  _SYSTEM_INFO SystemInfo; // [esp+90h] [ebp-24h] BYREF

  v3 = this + 4;
  v4 = aUnknown;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 39) = 0;
  v5 = this + 4 - aUnknown;
  do
  {
    v6 = *v4;
    v4[v5] = *v4;
    ++v4;
  }
  while ( v6 );
  GetSystemInfo(&SystemInfo);
  if ( SystemInfo.dwProcessorType != 486 && SystemInfo.dwProcessorType != 586 )
    goto LABEL_74;
  if ( sub_5567F5((_DWORD *)&v35 + 1, &v35, (int)v3) )
  {
    Sleep(0);
    CurrentProcess = GetCurrentProcess();
    dwPriorityClassa = GetPriorityClass(CurrentProcess);
    v12 = GetCurrentProcess();
    SetPriorityClass(v12, 0x80u);
    v35 = 0;
    sub_5567F5((_DWORD *)&v35 + 1, &v35, (int)v3);
    sub_556220(v39);
    sub_556260(v39, 1u);
    HighResolutionTimerReset((int *)v39);
    RDTSCTimestampRead((int)&v36, &v37);
    while ( HighResolutionTimerDeltaCalculation(v39) < 0.25 )
      ;
    RDTSCTimestampRead((int)&v35 + 4, &v35);
    v13 = GetCurrentProcess();
    SetPriorityClass(v13, dwPriorityClassa);
    EmptyStubWithFlagCheck(2, 0);
    dwPriorityClassb = CRTFtol(
                         (((double)HIDWORD(v35) - (double)v36) * 4294967296.0 * 0.000001
                        + ((double)(unsigned int)v35 - (double)v37) * 0.000001)
                       * 4.0);
    EmptyStubWithFlagCheck(1, 0);
    v14 = 50 * ((4 * dwPriorityClassb + 25) / 50);
    v15 = (((BYTE4(v14) & 3) + (int)v14) >> 2) - dwPriorityClassb;
    if ( (int)abs32(v15) >= (int)abs32(200 * ((3 * dwPriorityClassb + 100) / 200) / 3 - dwPriorityClassb) )
      v16 = 200 * ((3 * dwPriorityClassb + 100) / 200) / 3;
    else
      v16 = v15 + dwPriorityClassb;
    dwPriorityClass = v16;
    v17 = sub_5567F5((_DWORD *)&v35 + 1, &v35, (int)v3);
    v18 = v17;
    v19 = v17 & 0x3000;
    if ( (v17 & 0x3000) != 0 )
    {
      if ( v19 == 4096 )
      {
        if ( (v17 & 0xF00) != 0x500 && (v17 & 0xF00) != 0x600 )
          goto LABEL_73;
        goto LABEL_72;
      }
      if ( v19 != 0x2000 )
        goto LABEL_73;
    }
    if ( !sub_588410(v3, aGenuineintel_0) )
    {
      if ( v19 == 0x2000 )
        strcpy(v3, aDual);
      else
        strcpy(v3, byte_5EA438);
      v20 = v18 & 0xF00;
      if ( v20 != 1280 )
      {
        if ( v20 == 1536 )
        {
          switch ( v18 & 0xF0 )
          {
            case 0x10:
              strcat(v3, "Intel Pentium Pro");
              goto LABEL_72;
            case 0x30:
            case 0x50:
              strcat(v3, "Intel Pentium II");
              goto LABEL_32;
            case 0x60:
              strcat(v3, "Intel Celeron");
LABEL_32:
              *((_DWORD *)this + 39) |= 1u;
              *(_DWORD *)this = 1;
              break;
            case 0x70:
            case 0x80:
              strcat(v3, "Intel Pentium III");
              *((_DWORD *)this + 39) |= 3u;
              *(_DWORD *)this = 2;
              if ( dwPriorityClass <= 400 )
                *(_DWORD *)this = 1;
              break;
            default:
              goto LABEL_73;
          }
        }
        else if ( v20 == 3840 )
        {
          strcat(v3, "Intel Pentium 4");
          *((_DWORD *)this + 39) |= 3u;
          *(_DWORD *)this = 3;
        }
        goto LABEL_73;
      }
      v21 = v18 & 0xF0;
      if ( v21 == 16 )
      {
        v22 = &v3[strlen(v3) + 1];
      }
      else
      {
        if ( v21 != 32 )
        {
          if ( v21 == 64 )
          {
            strcat(v3, "Intel Pentium MMX");
            *((_DWORD *)this + 39) |= 1u;
LABEL_72:
            *(_DWORD *)this = 0;
          }
LABEL_73:
          *((_DWORD *)this + 9) = 1;
          EmptyStub_7470(v39);
LABEL_74:
          v8 = dwPriorityClass;
          goto LABEL_75;
        }
        v22 = &v3[strlen(v3) + 1];
      }
      strcpy(v22 - 1, "Intel Pentium");
      goto LABEL_72;
    }
    if ( !sub_588410(v3, aAuthenticamd_0) )
    {
      if ( v19 == 0x2000 )
        strcpy(v3, aDual);
      else
        strcpy(v3, byte_5EA438);
      v23 = v18 & 0xF00;
      if ( v23 == 1280 )
      {
        switch ( v18 & 0xF0 )
        {
          case 0:
          case 0x10:
          case 0x20:
          case 0x30:
            strcat(v3, "AMD K5");
            goto LABEL_72;
          case 0x60:
          case 0x70:
            strcat(v3, "AMD K6 MMX");
            *((_DWORD *)this + 39) |= 1u;
            goto LABEL_72;
          case 0x80:
            strcat(v3, "AMD K6-2 MMX");
            *((_DWORD *)this + 39) |= 1u;
            goto LABEL_72;
          case 0x90:
            strcat(v3, "AMD K6-III MMX");
            v24 = *((_DWORD *)this + 39) | 1;
            *(_DWORD *)this = 1;
            *((_DWORD *)this + 39) = v24;
            break;
          default:
            goto LABEL_73;
        }
      }
      else if ( v23 == 1536 )
      {
        switch ( v18 & 0xF0 )
        {
          case 0x10:
          case 0x20:
          case 0x40:
            strcat(v3, "AMD Athlon");
            goto LABEL_51;
          case 0x30:
          case 0x70:
            strcat(v3, "AMD Duron");
LABEL_51:
            *((_DWORD *)this + 39) |= 5u;
            *(_DWORD *)this = 2;
            break;
          case 0x60:
            strcat(v3, "AMD Athlon 4");
            *((_DWORD *)this + 39) |= 5u;
            *(_DWORD *)this = 3;
            if ( dwPriorityClass <= 1200 )
              *(_DWORD *)this = 2;
            break;
          default:
            goto LABEL_73;
        }
      }
      goto LABEL_73;
    }
    if ( !sub_588410(v3, aCyrixinstead) )
    {
      if ( v19 == 0x2000 )
        strcpy(v3, aDual);
      else
        strcpy(v3, byte_5EA438);
      v25 = v18 & 0xF00;
      switch ( v25 )
      {
        case 1024:
          if ( (v18 & 0xF0) == 0x40 )
          {
            strcat(v3, "Cyrix MediaGX");
            goto LABEL_72;
          }
          break;
        case 1280:
          v26 = &v3[strlen(v3)];
          if ( (v18 & 0xF0) == 0x20 )
          {
            strcpy(v26, "Cyrix 6x86");
          }
          else
          {
            strcpy(v26, "Cyrix MediaGX MMX");
            *((_DWORD *)this + 39) |= 1u;
          }
          goto LABEL_72;
        case 1536:
          strcat(v3, "Cyrix 6x86MX");
          goto LABEL_72;
      }
    }
    goto LABEL_73;
  }
  v7 = aNonCompatibleC;
  v8 = 0;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 9) = 0;
  v9 = v3 - aNonCompatibleC;
  do
  {
    v10 = *v7;
    v7[v9] = *v7;
    ++v7;
  }
  while ( v10 );
LABEL_75:
  Buffer.dwLength = 32;
  GlobalMemoryStatus(&Buffer);
  if ( v8 >= 1500 )
    *(_DWORD *)this = 4;
  dwTotalPhys = Buffer.dwTotalPhys;
  dwTotalPageFile = Buffer.dwTotalPageFile;
  *((_DWORD *)this + 35) = Buffer.dwTotalPhys;
  *((_DWORD *)this + 31) = dwTotalPhys;
  dwAvailPhys = Buffer.dwAvailPhys;
  *((_DWORD *)this + 36) = Buffer.dwAvailPhys;
  *((_DWORD *)this + 32) = dwAvailPhys;
  result = (_DWORD *)Buffer.dwAvailPageFile;
  *((_DWORD *)this + 10) = v8;
  *((_DWORD *)this + 33) = dwTotalPageFile;
  *((_DWORD *)this + 34) = result;
  if ( a2 )
  {
    result = (_DWORD *)SimpleFieldGetter_bfc0(a2);
    if ( (int)result > 0 )
    {
      v31 = (char *)BoundedArrayAccessor_bfd0(a2, 0);
      return sub_55BE20(v31, (int)(this + 84), (_DWORD *)this + 37, (_DWORD *)this + 38);
    }
  }
  return result;
}

