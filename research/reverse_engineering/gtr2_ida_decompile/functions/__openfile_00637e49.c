_DWORD *__cdecl _openfile(char *FileName, _BYTE *a2, int ShareFlag, _DWORD *a4)
{
  unsigned int v4; // kr00_4
  int v5; // ecx
  _BYTE *v6; // edi
  char v7; // al
  bool v8; // zf
  unsigned int v9; // ecx
  unsigned int v10; // esi
  int v11; // edx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  char v18; // al
  int v19; // ecx
  _DWORD *result; // eax
  unsigned int v21[4]; // [esp+0h] [ebp-18h] BYREF
  int v22; // [esp+10h] [ebp-8h]
  int v23; // [esp+14h] [ebp-4h]

  v6 = a2;
  v7 = *a2;
  v8 = *a2 == 97;
  v22 = 0;
  v23 = 0;
  if ( v8 )
  {
    v9 = 265;
LABEL_7:
    v10 = dword_FB861C | 2;
    goto LABEL_8;
  }
  if ( v7 != 114 )
  {
    if ( v7 != 119 )
      return 0;
    v9 = 769;
    goto LABEL_7;
  }
  v9 = 0;
  v10 = dword_FB861C | 1;
LABEL_8:
  v11 = 1;
  while ( 1 )
  {
    v18 = *++v6;
    if ( !*v6 || !v11 )
      break;
    if ( v18 > 84 )
    {
      v15 = v18 - 98;
      if ( v15 )
      {
        v16 = v15 - 1;
        if ( v16 )
        {
          v17 = v16 - 11;
          if ( v17 )
          {
            if ( v17 != 6 || (v9 & 0xC000) != 0 )
LABEL_35:
              v11 = 0;
            else
              v9 |= 0x4000u;
          }
          else
          {
            if ( v22 )
              goto LABEL_35;
            v22 = 1;
            v10 &= ~0x4000u;
          }
        }
        else
        {
          if ( v22 )
            goto LABEL_35;
          v22 = 1;
          v10 |= 0x4000u;
        }
      }
      else
      {
        if ( (v9 & 0xC000) != 0 )
          goto LABEL_35;
        v9 |= 0x8000u;
      }
    }
    else if ( v18 == 84 )
    {
      if ( (v9 & 0x1000) != 0 )
        goto LABEL_35;
      v9 |= 0x1000u;
    }
    else
    {
      v12 = v18 - 43;
      if ( v12 )
      {
        v13 = v12 - 25;
        if ( v13 )
        {
          v14 = v13 - 14;
          if ( v14 )
          {
            if ( v14 != 1 || v23 )
              goto LABEL_35;
            v23 = 1;
            v9 |= 0x20u;
          }
          else
          {
            if ( v23 )
              goto LABEL_35;
            v23 = 1;
            v9 |= 0x10u;
          }
        }
        else
        {
          if ( (v9 & 0x40) != 0 )
            goto LABEL_35;
          v9 |= 0x40u;
        }
      }
      else
      {
        if ( (v9 & 2) != 0 )
          goto LABEL_35;
        v9 = v9 & 0xFFFFFFFC | 2;
        v10 = v10 & 0xFFFFFF7C | 0x80;
      }
    }
  }
  v21[0] = v9;
  v4 = __readeflags();
  v5 = dword_16C6E08 ^ dword_16EC8E8;
  __writeeflags(v4);
  v19 = _sopen(FileName, _InterlockedExchange((volatile __int32 *)v21, v5), ShareFlag);
  if ( v19 < 0 )
    return 0;
  result = a4;
  ++dword_FB8350;
  a4[3] = v10;
  a4[1] = 0;
  *a4 = 0;
  a4[2] = 0;
  a4[7] = 0;
  a4[4] = v19;
  return result;
}
