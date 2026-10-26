HANDLE __thiscall sub_468960(_DWORD *this)
{
  DWORD v2; // eax
  LPVOID **v3; // edi
  LPVOID *v4; // eax
  bool v5; // zf
  _DWORD *i; // eax
  int v7; // eax
  int v8; // eax
  LPVOID *v9; // eax
  LPVOID *v10; // eax
  LPVOID *v11; // esi
  LPVOID *v12; // ebp
  char v13; // al
  DWORD v14; // eax
  const char **v15; // esi
  const char *v16; // edi
  char *v17; // ecx
  HANDLE result; // eax

  if ( dword_7652A0 && ((v2 = WaitForSingleObject(dword_7652A0, dword_7652A4)) == 0 || v2 == 128) )
    v3 = (LPVOID **)&unk_765290;
  else
    v3 = 0;
  v4 = *v3;
  v5 = *v3 == 0;
  v3[2] = *v3;
  if ( !v5 )
  {
    for ( i = *v4; i; i = *v10 )
    {
      v7 = *i - 1;
      if ( v7 )
      {
        v8 = v7 - 1;
        if ( v8 )
        {
          if ( v8 == 1 )
          {
            if ( this[105] )
              sub_46B260(this);
            else
              this[105] = 1;
          }
        }
        else
        {
          sub_46B230(this);
        }
      }
      else
      {
        sub_46B200(this);
      }
      v9 = v3[2];
      if ( !v9 )
        break;
      v10 = (LPVOID *)v9[1];
      v3[2] = v10;
      if ( !v10 )
        break;
    }
  }
  if ( (int)v3[3] > 0 )
    sub_469EB0(1);
  v11 = *v3;
  while ( v11 )
  {
    v12 = v11;
    v13 = *((_BYTE *)v11 + 8);
    v11 = (LPVOID *)v11[1];
    if ( v13 )
      sub_5BE8AE(*v12);
    sub_5BE8AE(v12);
  }
  *v3 = 0;
  v3[1] = 0;
  v3[2] = 0;
  v3[3] = 0;
  if ( dword_7652A0 )
    ReleaseMutex(dword_7652A0);
  if ( hHandle && ((v14 = WaitForSingleObject(hHandle, dword_764EFC)) == 0 || v14 == 128) )
    v15 = (const char **)&unk_764EF0;
  else
    v15 = 0;
  v16 = *v15;
  if ( !*v15 )
    v16 = &byte_629120;
  if ( strlen(v16) )
  {
    v17 = (char *)*v15;
    if ( !*v15 )
      v17 = &byte_629120;
    sub_468300(v17, -1);
    sub_578600(&byte_629120);
  }
  result = hHandle;
  if ( hHandle )
    return (HANDLE)ReleaseMutex(hHandle);
  return result;
}
