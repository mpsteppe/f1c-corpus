int __stdcall sub_41E8F0(char *a1)
{
  int v1; // eax
  char v2; // cl
  int result; // eax
  unsigned int v4; // edx
  char v5; // cl
  char v6; // cl
  char v7; // cl
  char v8; // cl
  char v9; // cl
  char v10; // cl
  char v11; // cl
  _BYTE VersionInformation[156]; // [esp+0h] [ebp-19Ch] BYREF
  char v13[256]; // [esp+9Ch] [ebp-100h] BYREF

  v1 = 0;
  do
  {
    v2 = aUnknown[v1];
    v13[v1++] = v2;
  }
  while ( v2 );
  memset(VersionInformation, 0, sizeof(VersionInformation));
  *(_DWORD *)VersionInformation = 156;
  if ( GetVersionExA((LPOSVERSIONINFOA)VersionInformation)
    || (*(_DWORD *)VersionInformation = 148, (result = GetVersionExA((LPOSVERSIONINFOA)VersionInformation)) != 0) )
  {
    if ( !*(_DWORD *)&VersionInformation[16] )
    {
      result = 0;
      do
      {
        v11 = byte_5FD060[result];
        v13[result++] = v11;
      }
      while ( v11 );
      goto LABEL_34;
    }
    if ( *(_DWORD *)&VersionInformation[16] != 1 )
    {
      result = *(_DWORD *)&VersionInformation[16] - 2;
      if ( *(_DWORD *)&VersionInformation[16] == 2 )
      {
        v4 = *(_DWORD *)&VersionInformation[4];
        if ( *(_DWORD *)&VersionInformation[4] <= 4u )
        {
          result = 0;
          do
          {
            v5 = aWindowsNt[result];
            v13[result++] = v5;
          }
          while ( v5 );
        }
        if ( v4 >= 5 )
        {
          if ( *(_DWORD *)&VersionInformation[8] )
          {
            result = 0;
            do
            {
              v6 = aWindowsXp[result];
              v13[result++] = v6;
            }
            while ( v6 );
          }
          else
          {
            result = 0;
            do
            {
              v7 = aWindows2000[result];
              v13[result++] = v7;
            }
            while ( v7 );
          }
        }
      }
      goto LABEL_34;
    }
    if ( *(_DWORD *)&VersionInformation[4] >= 4u )
    {
      if ( *(_DWORD *)&VersionInformation[8] >= 0x5Au )
      {
        result = 0;
        do
        {
          v8 = byte_5FD08C[result];
          v13[result++] = v8;
        }
        while ( v8 );
LABEL_34:
        if ( a1 )
          strcpy(a1, v13);
        return result;
      }
      if ( *(_DWORD *)&VersionInformation[4] > 4u || *(_DWORD *)&VersionInformation[8] )
      {
        result = 0;
        do
        {
          v10 = byte_5FD074[result];
          v13[result++] = v10;
        }
        while ( v10 );
        goto LABEL_34;
      }
    }
    result = 0;
    do
    {
      v9 = byte_5FD080[result];
      v13[result++] = v9;
    }
    while ( v9 );
    goto LABEL_34;
  }
  return result;
}
