unsigned int __cdecl _read_lk(int FileHandle, char *lpBuffer, DWORD nNumberOfBytesToRead)
{
  char *v3; // ebx
  char *v4; // edx
  int v5; // esi
  int v6; // eax
  char v7; // cl
  char v8; // al
  int v9; // eax
  DWORD LastError; // eax
  int v12; // eax
  char *v13; // ecx
  char v14; // al
  char v15; // al
  char *v16; // ecx
  bool v17; // cf
  char v18; // al
  char v19; // al
  _BYTE *v20; // esi
  DWORD NumberOfBytesRead; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int v22; // [esp+10h] [ebp-8h]
  char Buffer; // [esp+17h] [ebp-1h] BYREF
  char *nNumberOfBytesToReada; // [esp+28h] [ebp+10h]

  v22 = 0;
  v3 = lpBuffer;
  v4 = lpBuffer;
  if ( nNumberOfBytesToRead )
  {
    v5 = 36 * (FileHandle & 0x1F);
    v6 = v5 + dword_8003E0[FileHandle >> 5];
    v7 = *(_BYTE *)(v6 + 4);
    if ( (v7 & 2) == 0 )
    {
      if ( (v7 & 0x48) != 0 )
      {
        v8 = *(_BYTE *)(v6 + 5);
        if ( v8 != 10 )
        {
          --nNumberOfBytesToRead;
          *lpBuffer = v8;
          v9 = dword_8003E0[FileHandle >> 5];
          v4 = lpBuffer + 1;
          v22 = 1;
          *(_BYTE *)(v9 + v5 + 5) = 10;
        }
      }
      if ( !ReadFile(
              *(HANDLE *)(dword_8003E0[FileHandle >> 5] + 36 * (FileHandle & 0x1F)),
              v4,
              nNumberOfBytesToRead,
              &NumberOfBytesRead,
              0) )
      {
        LastError = GetLastError();
        if ( LastError == 5 )
        {
          *_errno() = 9;
          *__doserrno() = 5;
          return -1;
        }
        if ( LastError != 109 )
        {
          _dosmaperr(LastError);
          return -1;
        }
        return 0;
      }
      v12 = dword_8003E0[FileHandle >> 5];
      v22 += NumberOfBytesRead;
      v13 = (char *)(v12 + v5 + 4);
      v14 = *v13;
      if ( *v13 < 0 )
      {
        if ( NumberOfBytesRead && *lpBuffer == 10 )
          v15 = v14 | 4;
        else
          v15 = v14 & 0xFB;
        *v13 = v15;
        nNumberOfBytesToReada = lpBuffer;
        v16 = &lpBuffer[v22];
        v17 = lpBuffer < &lpBuffer[v22];
        v22 += (unsigned int)lpBuffer;
        if ( v17 )
        {
          do
          {
            v18 = *nNumberOfBytesToReada;
            if ( *nNumberOfBytesToReada == 26 )
            {
              v20 = (_BYTE *)(dword_8003E0[FileHandle >> 5] + v5 + 4);
              if ( (*v20 & 0x40) == 0 )
                *v20 |= 2u;
              return v3 - lpBuffer;
            }
            if ( v18 == 13 )
            {
              if ( nNumberOfBytesToReada >= v16 - 1 )
              {
                ++nNumberOfBytesToReada;
                if ( !ReadFile(
                        *(HANDLE *)(dword_8003E0[FileHandle >> 5] + 36 * (FileHandle & 0x1F)),
                        &Buffer,
                        1u,
                        &NumberOfBytesRead,
                        0)
                  && GetLastError()
                  || !NumberOfBytesRead )
                {
LABEL_35:
                  *v3 = 13;
                  goto LABEL_36;
                }
                if ( (*(_BYTE *)(dword_8003E0[FileHandle >> 5] + v5 + 4) & 0x48) != 0 )
                {
                  v19 = Buffer;
                  if ( Buffer == 10 )
                    goto LABEL_33;
                  *v3++ = 13;
                  *(_BYTE *)(dword_8003E0[FileHandle >> 5] + v5 + 5) = v19;
                }
                else
                {
                  if ( v3 == lpBuffer && Buffer == 10 )
                    goto LABEL_33;
                  _lseek_lk(FileHandle, -1, 1u);
                  if ( Buffer != 10 )
                    goto LABEL_35;
                }
              }
              else
              {
                if ( nNumberOfBytesToReada[1] == 10 )
                {
                  nNumberOfBytesToReada += 2;
LABEL_33:
                  *v3 = 10;
LABEL_36:
                  ++v3;
                  goto LABEL_37;
                }
                *v3++ = 13;
                ++nNumberOfBytesToReada;
              }
            }
            else
            {
              *v3++ = v18;
              ++nNumberOfBytesToReada;
            }
LABEL_37:
            v16 = (char *)v22;
          }
          while ( (unsigned int)nNumberOfBytesToReada < v22 );
        }
        return v3 - lpBuffer;
      }
      return v22;
    }
  }
  return 0;
}
