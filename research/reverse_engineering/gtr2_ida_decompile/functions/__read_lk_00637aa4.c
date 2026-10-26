unsigned int __cdecl _read_lk(int FileHandle, char *lpBuffer, DWORD nNumberOfBytesToRead)
{
  char *v3; // ebx
  char *v4; // edx
  int v5; // esi
  int v6; // eax
  char v7; // cl
  int v8; // eax
  DWORD LastError; // eax
  int v11; // ecx
  char *v12; // ecx
  bool v13; // cf
  char v14; // al
  char v15; // al
  DWORD NumberOfBytesRead; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int v17; // [esp+10h] [ebp-8h]
  char Buffer; // [esp+17h] [ebp-1h] BYREF
  char *nNumberOfBytesToReada; // [esp+28h] [ebp+10h]

  v17 = 0;
  v3 = lpBuffer;
  v4 = lpBuffer;
  if ( nNumberOfBytesToRead )
  {
    v5 = 36 * (FileHandle & 0x1F);
    v6 = v5 + dword_FBB4E0[FileHandle >> 5];
    v7 = *(_BYTE *)(v6 + 4);
    if ( (v7 & 2) == 0 )
    {
      if ( (v7 & 0x48) != 0 && *(_BYTE *)(v6 + 5) != 10 )
      {
        --nNumberOfBytesToRead;
        *lpBuffer = *(_BYTE *)(dword_FBB4E0[FileHandle >> 5] + v5 + 5);
        v8 = dword_FBB4E0[FileHandle >> 5];
        v4 = lpBuffer + 1;
        v17 = 1;
        *(_BYTE *)(v8 + v5 + 5) = 10;
      }
      if ( !ReadFile(
              *(HANDLE *)(dword_FBB4E0[FileHandle >> 5] + 36 * (FileHandle & 0x1F)),
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
      v11 = dword_FBB4E0[FileHandle >> 5];
      v17 += NumberOfBytesRead;
      if ( *(char *)(v11 + v5 + 4) < 0 )
      {
        if ( NumberOfBytesRead && *lpBuffer == 10 )
          *(_BYTE *)(v11 + v5 + 4) |= 4u;
        else
          *(_BYTE *)(dword_FBB4E0[FileHandle >> 5] + v5 + 4) &= ~4u;
        v12 = &lpBuffer[v17];
        v13 = lpBuffer < &lpBuffer[v17];
        nNumberOfBytesToReada = lpBuffer;
        v17 += (unsigned int)lpBuffer;
        if ( v13 )
        {
          do
          {
            v14 = *nNumberOfBytesToReada;
            if ( *nNumberOfBytesToReada == 26 )
            {
              if ( (*(_BYTE *)(dword_FBB4E0[FileHandle >> 5] + v5 + 4) & 0x40) == 0 )
                *(_BYTE *)(dword_FBB4E0[FileHandle >> 5] + v5 + 4) |= 2u;
              return v3 - lpBuffer;
            }
            if ( v14 == 13 )
            {
              if ( nNumberOfBytesToReada < v12 - 1 )
              {
                if ( nNumberOfBytesToReada[1] != 10 )
                {
                  ++nNumberOfBytesToReada;
LABEL_35:
                  *v3 = 13;
LABEL_36:
                  ++v3;
                  goto LABEL_37;
                }
                nNumberOfBytesToReada += 2;
                goto LABEL_33;
              }
              ++nNumberOfBytesToReada;
              if ( !ReadFile(
                      *(HANDLE *)(dword_FBB4E0[FileHandle >> 5] + 36 * (FileHandle & 0x1F)),
                      &Buffer,
                      1u,
                      &NumberOfBytesRead,
                      0)
                && GetLastError()
                || !NumberOfBytesRead )
              {
                goto LABEL_35;
              }
              if ( (*(_BYTE *)(dword_FBB4E0[FileHandle >> 5] + v5 + 4) & 0x48) != 0 )
              {
                v15 = Buffer;
                if ( Buffer != 10 )
                {
                  *v3 = 13;
                  *(_BYTE *)(dword_FBB4E0[FileHandle >> 5] + v5 + 5) = v15;
                  goto LABEL_36;
                }
LABEL_33:
                *v3 = 10;
                goto LABEL_36;
              }
              if ( v3 == lpBuffer && Buffer == 10 )
                goto LABEL_33;
              _lseek_lk(FileHandle, -1, 1u);
              if ( Buffer != 10 )
                goto LABEL_35;
            }
            else
            {
              *v3++ = v14;
              ++nNumberOfBytesToReada;
            }
LABEL_37:
            v12 = (char *)v17;
          }
          while ( (unsigned int)nNumberOfBytesToReada < v17 );
        }
        return v3 - lpBuffer;
      }
      return v17;
    }
  }
  return 0;
}
