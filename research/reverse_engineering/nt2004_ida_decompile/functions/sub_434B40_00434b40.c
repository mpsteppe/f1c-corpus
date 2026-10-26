char __thiscall sub_434B40(char *this, int a2)
{
  CHAR *v3; // eax
  CHAR *v4; // eax
  const char *v5; // edi
  unsigned int v6; // kr04_4
  int v7; // esi
  _DWORD *v8; // ebp
  _BYTE *v9; // edi
  int *v10; // eax
  int v11; // esi
  _BYTE *v12; // edi
  _DWORD *v13; // edi
  const CHAR *v14; // eax
  bool v15; // zf
  int v16; // eax
  int v17; // ecx
  int i; // edx
  CHAR *v19; // eax
  _DWORD *v21; // eax
  _DWORD *v22; // esi
  int v23; // eax
  _DWORD *v24; // esi
  char v25; // [esp+Fh] [ebp-351h]
  LPCSTR lpFileName[2]; // [esp+10h] [ebp-350h] BYREF
  _DWORD *v27; // [esp+18h] [ebp-348h]
  HANDLE hFindFile; // [esp+1Ch] [ebp-344h]
  _WIN32_FIND_DATAA FindFileData; // [esp+20h] [ebp-340h] BYREF
  _BYTE v30[256]; // [esp+160h] [ebp-200h] BYREF
  _BYTE v31[256]; // [esp+260h] [ebp-100h] BYREF

  v27 = this;
  v25 = 1;
  lpFileName[0] = (LPCSTR)operator new(0x80u);
  *lpFileName[0] = 0;
  lpFileName[1] = (LPCSTR)128;
  if ( a2 )
  {
    sub_578600(a2);
  }
  else
  {
    v3 = *(CHAR **)this;
    if ( !*(_DWORD *)this )
      v3 = &byte_629120;
    sub_578600(v3);
    v4 = (CHAR *)*((_DWORD *)this + 2);
    if ( !v4 )
      v4 = &byte_629120;
    sub_578560(v4);
  }
  v5 = lpFileName[0];
  if ( !lpFileName[0] )
    v5 = &byte_629120;
  v6 = strlen(v5) + 1;
  if ( (int)(v6 - 1) > 0 && sub_410E00((CHAR **)lpFileName)[v6 - 2] != 92 )
    sub_578560(word_5FB9F4);
  sub_578560(asc_5FCA68);
  v7 = *((_DWORD *)this + 8);
  v8 = this + 32;
  while ( v7 )
  {
    v9 = (_BYTE *)v7;
    v7 = *(_DWORD *)(v7 + 4);
    sub_4145A0(v9);
    sub_5BE8AE(v9);
  }
  v10 = v27 + 12;
  *v8 = 0;
  v8[1] = 0;
  v8[2] = 0;
  v8[3] = 0;
  v11 = *v10;
  while ( v11 )
  {
    v12 = (_BYTE *)v11;
    v11 = *(_DWORD *)(v11 + 4);
    sub_4145A0(v12);
    sub_5BE8AE(v12);
  }
  v13 = v27;
  v14 = lpFileName[0];
  v15 = lpFileName[0] == 0;
  v27[12] = 0;
  v13[13] = 0;
  v13[14] = 0;
  v13[15] = 0;
  if ( v15 )
    v14 = &byte_629120;
  hFindFile = FindFirstFileA(v14, &FindFileData);
  if ( hFindFile == (HANDLE)-1 )
  {
    v25 = 0;
  }
  else
  {
    while ( 1 )
    {
      if ( (FindFileData.dwFileAttributes & 0x10) != 0 )
      {
        if ( strcmp(FindFileData.cFileName, word_5FC804) && strcmp(FindFileData.cFileName, asc_5FCA64) )
        {
          sub_57B340(256);
          v21 = operator new(8u);
          v22 = v21;
          if ( v21 )
          {
            *v21 = 0;
            v21[1] = -1;
            sub_578600(v30);
          }
          else
          {
            v22 = 0;
          }
          if ( v22 )
          {
            if ( operator new(0xCu) )
              v23 = sub_4DB610(v22, 1);
            else
              v23 = 0;
            if ( *v8 )
            {
              *(_DWORD *)(v8[1] + 4) = v23;
            }
            else
            {
              *v8 = v23;
              v8[2] = v23;
            }
            v8[1] = v23;
            ++v8[3];
          }
        }
      }
      else
      {
        sub_57B340(256);
        v24 = operator new(8u);
        if ( v24 )
        {
          *v24 = 0;
          v24[1] = -1;
          sub_578600(v31);
        }
        else
        {
          v24 = 0;
        }
        sub_414410(v13 + 12, (int)v24, 1);
      }
      if ( !FindNextFileA(hFindFile, &FindFileData) )
        break;
      v13 = v27;
    }
    FindClose(hFindFile);
    v13 = v27;
  }
  v16 = sub_436F70(*v8);
  v17 = v16;
  *v8 = v16;
  if ( v16 )
  {
    for ( i = *(_DWORD *)(v16 + 4); i; i = *(_DWORD *)(i + 4) )
      v17 = i;
  }
  v8[1] = v17;
  v8[2] = v16;
  sub_436D70(1);
  v19 = (CHAR *)lpFileName[0];
  ++v13[7];
  if ( v19 )
    sub_5BE8AE(v19);
  return v25;
}
