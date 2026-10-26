int __thiscall sub_4B6DA0(_DWORD *this)
{
  int result; // eax
  int v3; // ecx
  int v4; // ebp
  int v5; // edi
  int v6; // ebp
  int v7; // edx
  int v8; // ebx
  int v9; // eax
  char *v10; // esi
  int v11; // eax
  int v12; // [esp+14h] [ebp-84h]
  char Buffer[61]; // [esp+18h] [ebp-80h] BYREF
  __int16 v14; // [esp+55h] [ebp-43h]
  char v15; // [esp+57h] [ebp-41h]
  char Destination[61]; // [esp+58h] [ebp-40h] BYREF
  __int16 v17; // [esp+95h] [ebp-3h]
  char v18; // [esp+97h] [ebp-1h]

  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x3Cu);
  v14 = 0;
  v15 = 0;
  sub_506960(0);
  result = sub_5072A0(aCurrentPositio, 0.5, 0, dword_60911C, 2, -1.0, -1.0, 0);
  if ( dword_75CBB4 >= 5 )
  {
    v3 = this[17] - 2;
    if ( dword_768948 )
      v4 = *(_DWORD *)(dword_75AAC4 + 20888);
    else
      v4 = *(_DWORD *)(dword_75AAC4 + 20884);
    v5 = NumOfElements;
    result = v3 / 2;
    v6 = v4 - v3 / 2;
    v7 = 0;
    if ( (int)NumOfElements > v3 )
    {
      result = v3 + v6;
      do
      {
        if ( v6 >= 1 )
        {
          if ( result <= (int)NumOfElements )
            goto LABEL_7;
          --v6;
          --result;
        }
        else
        {
          ++v6;
          ++result;
        }
        ++v7;
      }
      while ( v7 <= 50 );
    }
    else
    {
      v6 = 1;
LABEL_7:
      v8 = 1;
      v12 = v6 + v3;
      if ( v6 <= v6 + v3 )
      {
        while ( 1 )
        {
          if ( v6 > v5 )
            return result;
          if ( dword_768948 )
            break;
          v11 = 0;
          if ( v5 > 0 )
          {
            while ( v6 != *(_DWORD *)(dword_75AAD0[v11] + 20888) )
            {
              if ( ++v11 >= v5 )
                goto LABEL_25;
            }
            v10 = (char *)dword_75AAD0[v11];
            goto LABEL_23;
          }
LABEL_25:
          result = v12;
          if ( ++v6 > v12 )
            return result;
        }
        v9 = sub_4FA870(v6 - 1);
        v5 = NumOfElements;
        v10 = (char *)&unk_62BF68 + 25304 * v9;
LABEL_23:
        if ( v10 )
        {
          sprintf(Buffer, "%2d.", v6);
          sub_5072A0(Buffer, 0.125, v8, -256, 1, -1.0, -1.0, 0);
          Destination[0] = byte_629120;
          memset(&Destination[1], 0, 0x3Cu);
          v17 = 0;
          v18 = 0;
          sub_4EDE00(Destination, 63);
          sprintf(Buffer, "%s %s", Destination, v10 + 24772);
          sub_5072A0(Buffer, 0.125, v8, v10 != (char *)dword_75AAC4 ? -1 : -16711936, 0, -1.0, -1.0, 0);
          v5 = NumOfElements;
          ++v8;
        }
        goto LABEL_25;
      }
    }
  }
  return result;
}
