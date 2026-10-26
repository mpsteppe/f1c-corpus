int __stdcall sub_42DD90(int a1, char *Buffer)
{
  int v2; // ebp
  char *v3; // ebx
  int v4; // edx
  int v5; // eax
  int v6; // eax
  int v7; // esi
  long double v8; // st7
  int v9; // eax
  const char *v10; // esi
  const char *v12; // esi
  int v13; // [esp+1Ch] [ebp+4h]
  float Buffera; // [esp+20h] [ebp+8h]

  if ( a1 < 0 || a1 >= (int)NumOfElements )
    return 0;
  v2 = dword_75AAD0[a1];
  if ( dword_75CBB0 == 7 )
  {
    v3 = Buffer;
    *Buffer = 0;
    v4 = *(_DWORD *)(v2 + 20848);
    if ( v4 > 0 && *(_DWORD *)(v2 + 20892) == 1 )
    {
      if ( *(_DWORD *)(v2 + 20884) == 1 )
      {
        v13 = (__int64)(*(float *)(v2 + 20988) * 0.00027777778);
        sprintf(
          Buffer,
          "%d:%02.2d:%06.3f",
          v13,
          (unsigned int)(__int64)((*(float *)(v2 + 20988) - (double)v13 * 3600.0) * 0.016666668),
          (double)fmod(*(float *)(v2 + 20988), 60.0));
      }
      else
      {
        v5 = 0;
        if ( (int)NumOfElements > 0 )
        {
          while ( *(_DWORD *)(dword_75AAD0[v5] + 20884) != 1 )
          {
            if ( ++v5 >= (int)NumOfElements )
              goto LABEL_25;
          }
          v6 = dword_75AAD0[v5];
          if ( v6 )
          {
            v7 = *(_DWORD *)(v6 + 20848) - v4;
            if ( v7 == 1 )
            {
              if ( sub_41F230(dword_62A170, off_5FD3B4, Destination) )
              {
                strncpy(Destination, off_5FD3B4, 0x1FFu);
                byte_62A37B = 0;
              }
              sprintf(Buffer, "+%d %s", 1, Destination);
            }
            else if ( v7 <= 0 )
            {
              v8 = *(float *)(v2 + 20988) - *(float *)(v6 + 20988);
              Buffera = v8;
              sprintf(v3, "+%d:%06.3f", (unsigned int)(__int64)(Buffera * 0.016666668), (double)fmod(v8, 60.0));
            }
            else
            {
              if ( sub_41F230(dword_62A170, aLaps_1, Destination) )
              {
                strncpy(Destination, aLaps_1, 0x1FFu);
                byte_62A37B = 0;
              }
              sprintf(Buffer, "+%d %s", v7, Destination);
            }
          }
        }
      }
    }
LABEL_25:
    if ( !strlen(v3) )
      sprintf(v3, "%s", "--:--.---");
  }
  else
  {
    v3 = Buffer;
    if ( *(float *)(v2 + 20960) < 0.0 )
      sprintf(Buffer, "--:--.---");
    else
      sprintf(
        Buffer,
        "%d:%06.3f",
        (unsigned int)(__int64)(*(float *)(v2 + 20960) * 0.016666668),
        (double)fmod(*(float *)(v2 + 20960), 60.0));
  }
  v9 = *(_DWORD *)(v2 + 20892);
  if ( v9 != 3 && (dword_75CBB0 != 7 || v9 != 2) )
    return 0;
  if ( v9 == 3 )
  {
    v10 = off_5FD33C;
    if ( sub_41F230(dword_62A170, off_5FD33C, Destination) )
    {
      if ( v10 )
      {
        strncpy(Destination, v10, 0x1FFu);
        byte_62A37B = 0;
      }
      else
      {
        Destination[0] = 0;
      }
    }
    strcpy(v3, Destination);
    return 3;
  }
  else
  {
    v12 = (const char *)sub_4DBF10(*(_DWORD *)(v2 + 20896));
    if ( sub_41F230(dword_62A170, v12, Destination) )
    {
      if ( v12 )
      {
        strncpy(Destination, v12, 0x1FFu);
        byte_62A37B = 0;
      }
      else
      {
        Destination[0] = 0;
      }
    }
    strcpy(v3, Destination);
    return 3;
  }
}
