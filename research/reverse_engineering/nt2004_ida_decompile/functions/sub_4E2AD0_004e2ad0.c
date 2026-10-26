int __stdcall sub_4E2AD0(const char *ArgList)
{
  int v1; // eax
  char v2; // cl
  const char *v3; // eax
  signed int v4; // edi
  char *v5; // eax
  int v6; // ebp
  int v7; // ebx
  char *v8; // esi
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // edi
  int v13; // ebp
  int v14; // ebx
  char *v15; // esi
  int v16; // eax
  char *v17; // eax
  signed int v18; // ebx
  _DWORD *v19; // edi
  int v20; // eax
  int v21; // esi
  BOOL v23; // [esp-8h] [ebp-128h]
  int v24[4]; // [esp+10h] [ebp-110h] BYREF
  char Destination[256]; // [esp+20h] [ebp-100h] BYREF

  if ( (int)NumOfElements > 0 )
  {
    sub_504470(v24);
    if ( sub_42DBA0() )
    {
      v3 = dword_7665D8;
      if ( !dword_7665D8 )
        v3 = &byte_629120;
      strncpy(Destination, v3, 0xFFu);
      Destination[255] = 0;
    }
    else
    {
      v1 = 0;
      do
      {
        v2 = *(&byte_629120 + v1);
        Destination[v1++] = v2;
      }
      while ( v2 );
    }
    v4 = 1;
    if ( *(_DWORD *)dword_7689CC == 1 )
    {
      if ( dword_7685AC )
      {
        NumOfElements = 1;
        sub_42DC40();
LABEL_32:
        sub_4E2420(v24);
        goto LABEL_33;
      }
    }
    else
    {
      if ( *(_DWORD *)dword_7689CC == 2 )
      {
        if ( dword_7685F4 == 44 )
        {
          v5 = dword_76662C;
          if ( !dword_76662C )
            v5 = &byte_629120;
          v6 = sub_4E3130(v5);
          v7 = 1;
          if ( (int)NumOfElements > 1 )
          {
            v8 = (char *)&unk_632240;
            do
            {
              if ( v4 == v6 )
                ++v7;
              sub_51BC20(1, 0);
              v9 = sub_4E33C0(v7);
              sub_4EEAE0(v9);
              sub_4EDDB0(v4);
              ++v7;
              ++v4;
              v8 += 25304;
            }
            while ( v4 < (int)NumOfElements );
          }
          goto LABEL_32;
        }
        goto LABEL_25;
      }
      if ( *(_DWORD *)dword_7689CC != 1 || dword_7685AC )
      {
LABEL_25:
        if ( sub_42DBA0() )
          v10 = NumOfElements - 1;
        else
          v10 = NumOfElements;
        if ( sub_4E2570(v24, v10, Destination, ArgList) == v10 )
        {
          v11 = sub_42DBA0();
          v12 = v11;
          v13 = v11 + v10;
          if ( v11 < v11 + v10 )
          {
            v14 = 0;
            v15 = (char *)&unk_62BF68 + 25304 * v11;
            do
            {
              sub_51BC20(1, 0);
              v16 = sub_4E2960(v24, v14);
              sub_4EEAE0(v16);
              sub_4EDDB0(v12++);
              ++v14;
              v15 += 25304;
            }
            while ( v12 < v13 );
          }
        }
        goto LABEL_32;
      }
    }
    NumOfElements = sub_4D1A80(&dword_7D3C50) % 3u + 3;
    sub_42DC40();
    goto LABEL_25;
  }
LABEL_33:
  v17 = dword_7665D8;
  if ( !dword_7665D8 )
    v17 = &byte_629120;
  sub_4E7690(v17);
  sub_4EEAE0(dword_7D6A54);
  sub_4EDDB0(0);
  dword_62C760 = dword_768228;
  v23 = !sub_42DBA0();
  sub_51BC20(v23, 0);
  v18 = 1;
  if ( (int)NumOfElements > 1 )
  {
    v19 = &unk_6384E4;
    do
    {
      if ( *(v19 - 2167) == 1 )
      {
        v20 = 0;
        if ( dword_76824C )
        {
          if ( dword_76824C == 1 )
          {
            v20 = sub_4E31D0(*v19);
          }
          else if ( dword_76824C == 2 )
          {
            v21 = dword_7D6A5C + 1232 * *v19;
            if ( v21 )
              v20 = rand() % *(_DWORD *)(v21 + 1228);
          }
        }
        else
        {
          v20 = 0;
        }
        *(v19 - 5803) = v20;
      }
      ++v18;
      v19 += 6326;
    }
    while ( v18 < (int)NumOfElements );
  }
  return 0;
}
