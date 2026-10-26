_DWORD *__thiscall sub_5B7620(char *this, _DWORD *a2)
{
  char *v3; // edi
  char *v4; // eax
  int v5; // edx
  char v6; // cl
  char *v7; // eax
  int v8; // edi
  char v9; // cl
  int v10; // ebx
  SIZE_T dwTotalPhys; // eax
  SIZE_T dwTotalPageFile; // edx
  SIZE_T dwAvailPhys; // eax
  _DWORD *result; // eax
  char *v15; // eax
  HANDLE CurrentProcess; // eax
  HANDLE v17; // eax
  HANDLE v18; // eax
  __int64 v19; // rax
  int v20; // ecx
  int v21; // eax
  int v22; // eax
  int v23; // ebp
  int v24; // eax
  int v25; // eax
  int v26; // eax
  char *v27; // edi
  __int16 v28; // dx
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // ecx
  bool v33; // zf
  int dwPriorityClass; // [esp+Ch] [ebp-A8h]
  DWORD dwPriorityClassa; // [esp+Ch] [ebp-A8h]
  int dwPriorityClassb; // [esp+Ch] [ebp-A8h]
  __int64 v37; // [esp+14h] [ebp-A0h] BYREF
  __int64 v38; // [esp+1Ch] [ebp-98h] BYREF
  struct _MEMORYSTATUS Buffer; // [esp+24h] [ebp-90h] BYREF
  double v40[9]; // [esp+44h] [ebp-70h] BYREF
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
    goto LABEL_8;
  if ( !sub_5ADFB5((_DWORD *)&v37 + 1, &v37, (int)v3) )
  {
    v7 = aNonCompatibleC;
    *(_DWORD *)this = 0;
    dwPriorityClass = 0;
    *((_DWORD *)this + 9) = 0;
    v8 = v3 - aNonCompatibleC;
    do
    {
      v9 = *v7;
      v7[v8] = *v7;
      ++v7;
    }
    while ( v9 );
LABEL_8:
    v10 = v38;
    goto LABEL_9;
  }
  Sleep(0);
  CurrentProcess = GetCurrentProcess();
  dwPriorityClassa = GetPriorityClass(CurrentProcess);
  v17 = GetCurrentProcess();
  SetPriorityClass(v17, 0x80u);
  v37 = 0;
  sub_5ADFB5((_DWORD *)&v37 + 1, &v37, (int)v3);
  sub_5AC560(v40);
  sub_5AC5A0(v40, 1);
  sub_5AC740((int *)v40, 1);
  sub_5AE03B((int)&v38 + 4, &v38);
  while ( sub_5AC980(v40) < 0.25 )
    ;
  sub_5AE03B((int)&v37 + 4, &v37);
  v18 = GetCurrentProcess();
  SetPriorityClass(v18, dwPriorityClassa);
  sub_590140(2, 0);
  dwPriorityClassb = (__int64)((((double)HIDWORD(v37) - (double)HIDWORD(v38)) * 4294967296.0 * 0.000001
                              + ((double)(unsigned int)v37 - (double)(unsigned int)v38) * 0.000001)
                             * 4.0);
  sub_590140(1, 0);
  v19 = 50 * ((4 * dwPriorityClassb + 25) / 50);
  v20 = (((BYTE4(v19) & 3) + (int)v19) >> 2) - dwPriorityClassb;
  if ( (int)abs32(v20) >= (int)abs32(200 * ((3 * dwPriorityClassb + 100) / 200) / 3 - dwPriorityClassb) )
    v21 = 200 * ((3 * dwPriorityClassb + 100) / 200) / 3;
  else
    v21 = v20 + dwPriorityClassb;
  dwPriorityClass = v21;
  v22 = sub_5ADFB5((_DWORD *)&v37 + 1, &v37, (int)v3);
  v10 = v22;
  v23 = v22 & 0x3000;
  if ( (v22 & 0x3000) != 0 )
  {
    if ( v23 == 4096 )
    {
      v24 = v22 & 0xF00;
      if ( v24 != 1280 && v24 != 1536 )
        goto LABEL_87;
      goto LABEL_86;
    }
    if ( v23 != 0x2000 )
      goto LABEL_87;
  }
  if ( _strcmpi(v3, aGenuineintel_0) )
  {
    if ( !_strcmpi(v3, aAuthenticamd_0) )
    {
      if ( v23 == 0x2000 )
        strcpy(v3, aDual);
      else
        strcpy(v3, &byte_629120);
      v29 = v10 & 0xF00;
      if ( v29 == 1280 )
      {
        switch ( v10 & 0xF0 )
        {
          case 0:
          case 0x10:
          case 0x20:
          case 0x30:
            strcat(v3, "AMD K5");
            goto LABEL_86;
          case 0x60:
          case 0x70:
            strcat(v3, "AMD K6 MMX");
            *((_DWORD *)this + 39) |= 1u;
            goto LABEL_86;
          case 0x80:
            strcat(v3, "AMD K6-2 MMX");
            *((_DWORD *)this + 39) |= 1u;
            goto LABEL_86;
          case 0x90:
            strcat(v3, "AMD K6-III MMX");
            v30 = *((_DWORD *)this + 39) | 1;
            *(_DWORD *)this = 1;
            *((_DWORD *)this + 39) = v30;
            break;
          default:
            goto LABEL_87;
        }
      }
      else if ( v29 == 1536 )
      {
        switch ( v10 & 0xF0 )
        {
          case 0x10:
          case 0x20:
          case 0x40:
            strcat(v3, "AMD Athlon");
            goto LABEL_60;
          case 0x30:
          case 0x70:
            strcat(v3, "AMD Duron");
LABEL_60:
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
            goto LABEL_87;
        }
      }
      else if ( v29 == 3840 && (v10 & 0xF0) == 0x50 )
      {
        strcat(v3, "AMD Opteron");
        *((_DWORD *)this + 39) |= 5u;
        *(_DWORD *)this = 3;
      }
      goto LABEL_87;
    }
    if ( _strcmpi(v3, aCyrixinstead) )
      goto LABEL_87;
    if ( v23 == 0x2000 )
      strcpy(v3, aDual);
    else
      strcpy(v3, &byte_629120);
    v31 = v10 & 0xF00;
    if ( v31 != 1024 )
    {
      if ( v31 == 1280 )
      {
        v32 = -1;
        if ( (v10 & 0xF0) == 0x20 )
        {
          do
          {
            if ( !v32 )
              break;
            v33 = *v3++ == 0;
            --v32;
          }
          while ( !v33 );
          strcpy(v3 - 1, "Cyrix 6x86");
        }
        else
        {
          do
          {
            if ( !v32 )
              break;
            v33 = *v3++ == 0;
            --v32;
          }
          while ( !v33 );
          strcpy(v3 - 1, "Cyrix MediaGX MMX");
          *((_DWORD *)this + 39) |= 1u;
        }
        goto LABEL_86;
      }
      if ( v31 == 1536 )
      {
        strcat(v3, "Cyrix 6x86MX");
        goto LABEL_86;
      }
      goto LABEL_87;
    }
    if ( (v10 & 0xF0) != 0x40 )
      goto LABEL_87;
    v27 = &v3[strlen(v3)];
    qmemcpy(v27, "Cyrix MediaG", 12);
    v28 = word_61C098;
LABEL_85:
    *((_WORD *)v27 + 6) = v28;
    goto LABEL_86;
  }
  if ( v23 == 0x2000 )
    strcpy(v3, aDual);
  else
    strcpy(v3, &byte_629120);
  v25 = v10 & 0xF00;
  if ( v25 != 1280 )
  {
    if ( v25 == 1536 )
    {
      switch ( v10 & 0xF0 )
      {
        case 0x10:
          strcat(v3, "Intel Pentium Pro");
          goto LABEL_86;
        case 0x30:
        case 0x50:
          strcat(v3, "Intel Pentium II");
          goto LABEL_38;
        case 0x60:
          strcat(v3, "Intel Celeron");
LABEL_38:
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
          strcat(v3, "Class 2 CPU");
          *(_DWORD *)this = 2;
          break;
      }
    }
    else if ( v25 == 3840 )
    {
      strcat(v3, "Intel Pentium 4");
      *((_DWORD *)this + 39) |= 3u;
      *(_DWORD *)this = 3;
    }
    goto LABEL_87;
  }
  v26 = v10 & 0xF0;
  switch ( v26 )
  {
    case 16:
      strcat(v3, "Intel Pentium");
      goto LABEL_86;
    case 32:
      v27 = &v3[strlen(v3)];
      qmemcpy(v27, "Intel Pentiu", 12);
      v28 = word_61C160;
      goto LABEL_85;
    case 64:
      strcat(v3, "Intel Pentium MMX");
      *((_DWORD *)this + 39) |= 1u;
LABEL_86:
      *(_DWORD *)this = 0;
      break;
  }
LABEL_87:
  *((_DWORD *)this + 9) = 1;
  j_nullsub_6(v40);
LABEL_9:
  Buffer.dwLength = 32;
  GlobalMemoryStatus(&Buffer);
  if ( dwPriorityClass >= 1500 )
    *(_DWORD *)this = 4;
  dwTotalPhys = Buffer.dwTotalPhys;
  dwTotalPageFile = Buffer.dwTotalPageFile;
  *((_DWORD *)this + 35) = Buffer.dwTotalPhys;
  *((_DWORD *)this + 31) = dwTotalPhys;
  dwAvailPhys = Buffer.dwAvailPhys;
  *((_DWORD *)this + 36) = Buffer.dwAvailPhys;
  *((_DWORD *)this + 32) = dwAvailPhys;
  result = (_DWORD *)Buffer.dwAvailPageFile;
  *((_DWORD *)this + 9) = v10;
  *((_DWORD *)this + 10) = dwPriorityClass;
  *((_DWORD *)this + 33) = dwTotalPageFile;
  *((_DWORD *)this + 34) = result;
  if ( a2 )
  {
    result = (_DWORD *)sub_5A97F0(a2);
    if ( (int)result > 0 )
    {
      v15 = (char *)sub_5A9800(a2, 0);
      return sub_5A9650(v15, (int)(this + 84), (_DWORD *)this + 37, (_DWORD *)this + 38);
    }
  }
  return result;
}
