int __stdcall sub_42BDD0(int a1, char *a2)
{
  int v2; // ebp
  int v3; // eax
  char *v4; // ebx
  int v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // eax
  char v10; // cl
  int v11; // eax
  char v12; // cl
  double v13; // st7
  int v14; // eax
  int v15; // eax
  int v16; // eax
  const char *v17; // esi
  const char *v19; // esi
  float v20; // [esp+1Ch] [ebp+4h]
  int v21; // [esp+1Ch] [ebp+4h]
  float v22; // [esp+20h] [ebp+8h]
  float v23; // [esp+20h] [ebp+8h]

  if ( a1 < 0 || a1 >= dword_5C329C )
    return 0;
  v2 = dword_7C54F0[a1];
  if ( dword_7C56A4 == 7 )
  {
    v4 = a2;
    *a2 = 0;
    v5 = *(_DWORD *)(v2 + 16444);
    if ( v5 > 0 && *(_DWORD *)(v2 + 16484) == 1 )
    {
      if ( *(_DWORD *)(v2 + 16480) == 1 )
      {
        v23 = *(float *)(v2 + 16568);
        v21 = CRTFtol(v23 * 0.00027777778);
        InterruptDispatch(v23);
        v15 = CRTFtol((v23 - (double)v21 * 3600.0) * 0.016666668);
        StringFormatWithBufferOverflowCheck(v4, "%d:%02.2d:%06.3f", v21, v15, v23);
      }
      else
      {
        v6 = 0;
        if ( dword_5C329C > 0 )
        {
          while ( *(_DWORD *)(dword_7C54F0[v6] + 16480) != 1 )
          {
            if ( ++v6 >= dword_5C329C )
              goto LABEL_27;
          }
          v7 = dword_7C54F0[v6];
          if ( v7 )
          {
            v8 = *(_DWORD *)(v7 + 16444) - v5;
            if ( v8 == 1 )
            {
              if ( BinarySearchInStringTable(byte_5EC4C0, (const char *)&off_5C330C, byte_5EC4CC) )
              {
                v9 = 0;
                do
                {
                  v10 = *((_BYTE *)&off_5C330C + v9);
                  byte_5EC4CC[v9++] = v10;
                }
                while ( v10 );
              }
              StringFormatWithBufferOverflowCheck(a2, "+%d %s", 1, byte_5EC4CC);
            }
            else if ( v8 <= 0 )
            {
              v13 = *(float *)(v2 + 16568) - *(float *)(v7 + 16568);
              v22 = v13;
              InterruptDispatch(v13);
              v14 = CRTFtol(v22 * 0.016666668);
              StringFormatWithBufferOverflowCheck(v4, "+%d:%06.3f", v14, v13);
            }
            else
            {
              if ( BinarySearchInStringTable(byte_5EC4C0, aLaps_1, byte_5EC4CC) )
              {
                v11 = 0;
                do
                {
                  v12 = aLaps_1[v11];
                  byte_5EC4CC[v11++] = v12;
                }
                while ( v12 );
              }
              StringFormatWithBufferOverflowCheck(a2, "+%d %s", v8, byte_5EC4CC);
            }
          }
        }
      }
    }
LABEL_27:
    if ( !strlen(v4) )
      StringFormatWithBufferOverflowCheck(v4, "%s", "--:--.---");
  }
  else
  {
    v20 = *(float *)(v2 + 16540);
    if ( v20 < 0.0 )
    {
      v4 = a2;
      StringFormatWithBufferOverflowCheck(a2, "--:--.---");
    }
    else
    {
      InterruptDispatch(v20);
      v3 = CRTFtol(v20 * 0.016666668);
      v4 = a2;
      StringFormatWithBufferOverflowCheck(a2, "%d:%06.3f", v3, v20);
    }
  }
  v16 = *(_DWORD *)(v2 + 16484);
  if ( v16 != 3 && (dword_7C56A4 != 7 || v16 != 2) )
    return 0;
  if ( v16 == 3 )
  {
    v17 = (const char *)off_5C3298;
    if ( BinarySearchInStringTable(byte_5EC4C0, (const char *)off_5C3298, byte_5EC4CC) )
    {
      if ( v17 )
        strcpy(byte_5EC4CC, v17);
      else
        byte_5EC4CC[0] = 0;
    }
    strcpy(v4, byte_5EC4CC);
    return 3;
  }
  else
  {
    v19 = (const char *)FailureCategoryNameLookup(*(_DWORD *)(v2 + 16488));
    if ( BinarySearchInStringTable(byte_5EC4C0, v19, byte_5EC4CC) )
    {
      if ( v19 )
        strcpy(byte_5EC4CC, v19);
      else
        byte_5EC4CC[0] = 0;
    }
    strcpy(v4, byte_5EC4CC);
    return 3;
  }
}

