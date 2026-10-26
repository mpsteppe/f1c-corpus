int __thiscall sub_483AD0(_DWORD *this)
{
  _DWORD *v1; // esi
  _DWORD *v2; // edi
  void *v3; // ebp
  _DWORD *v4; // ebp
  int v5; // eax
  int v6; // ebx
  char *v7; // eax
  char *v8; // eax
  char v9; // cl
  CHAR *v10; // eax
  char *v11; // edx
  CHAR v12; // cl
  int v13; // edx
  unsigned int v14; // ecx
  _DWORD *v15; // eax
  _DWORD *v16; // ecx
  int v17; // eax
  _DWORD *v18; // edx
  int v19; // eax
  int v20; // edx
  int v21; // ebp
  _DWORD *v22; // ebx
  _DWORD *v23; // eax
  _DWORD *v24; // edi
  _DWORD *v25; // ebp
  _DWORD *v26; // eax
  _DWORD *v27; // edx
  _DWORD *j; // eax
  int v30; // [esp-4h] [ebp-440h]
  int i; // [esp+10h] [ebp-42Ch]
  _DWORD *v32; // [esp+10h] [ebp-42Ch]
  char Buffer[29]; // [esp+1Ch] [ebp-420h] BYREF
  __int16 v35; // [esp+39h] [ebp-403h]
  char v36; // [esp+3Bh] [ebp-401h]
  char v37[253]; // [esp+3Ch] [ebp-400h] BYREF
  __int16 v38; // [esp+139h] [ebp-303h]
  char v39; // [esp+13Bh] [ebp-301h]
  _BYTE v40[256]; // [esp+13Ch] [ebp-300h] BYREF
  char Destination[512]; // [esp+23Ch] [ebp-200h] BYREF

  v1 = this;
  sub_4CE6A0(*(int *)dword_7689CC, Destination, 0x1FFu);
  sub_4E8260(Destination);
  v2 = (_DWORD *)v1[217];
  while ( v2 )
  {
    v3 = v2;
    v2 = (_DWORD *)v2[1];
    sub_576570(v3);
    sub_5BE8AE(v3);
  }
  v1[217] = 0;
  v1[218] = 0;
  v1[219] = 0;
  v1[220] = 0;
  for ( i = 0; i < sub_577280(&unk_7D6A34); v1 = this )
  {
    v4 = operator new(0x68u);
    if ( v4 )
    {
      sub_4A5920(v1);
      v4[22] = 0;
      v4[23] = -1;
      v4[24] = 0;
      v4[25] = -1;
      *v4 = &off_5D6F2C;
    }
    else
    {
      v4 = 0;
    }
    v5 = sub_4E8590(i);
    v37[0] = byte_629120;
    v6 = v5;
    memset(&v37[1], 0, 0xFCu);
    v38 = 0;
    v39 = 0;
    if ( sub_49C9C0(v1) )
      v7 = (char *)sub_49C9C0(v1);
    else
      v7 = (char *)sub_4AE330(v1[12]);
    if ( v6 )
    {
      sub_4A59F0(v7, v6 + 246);
      v8 = (char *)(v6 + 246);
      do
      {
        v9 = *v8;
        v40[(_DWORD)v8 - 246 - v6] = *v8;
        ++v8;
      }
      while ( v9 );
      v4[21] = v6;
      if ( sub_579060(v6 + 630, aBusch) )
      {
        sub_578600(aB);
      }
      else if ( sub_579060(v6 + 630, aWinstoncup_0) )
      {
        sub_578600(aA_0);
      }
      else if ( sub_579060(v6 + 630, aLegend) )
      {
        sub_578600(aC_0);
      }
    }
    v4[2] = (*(int (__thiscall **)(_DWORD *))(*v4 + 8))(v4) + 12;
    v10 = (CHAR *)v4[24];
    if ( !v10 )
      v10 = &byte_629120;
    v11 = (char *)(v37 - v10);
    do
    {
      v12 = *v10;
      v10[(_DWORD)v11] = *v10;
      ++v10;
    }
    while ( v12 );
    v13 = atoi((const char *)(v4[21] + 168));
    Buffer[0] = byte_629120;
    memset(&Buffer[1], 0, 0x1Cu);
    v35 = 0;
    v36 = 0;
    sub_405480(Buffer, 0x1Fu, "%03d", v13);
    strcat(v37, Buffer);
    strcat(v37, (const char *)(v6 + 374));
    v14 = strlen((const char *)(v6 + 310)) + 1;
    qmemcpy(&v37[strlen(v37)], (const void *)(v6 + 310), v14);
    sub_578600(v37);
    v15 = operator new(0xCu);
    if ( v15 )
    {
      *v15 = v4;
      v15[1] = 0;
      *((_BYTE *)v15 + 8) = 1;
    }
    else
    {
      v15 = 0;
    }
    if ( this[217] )
    {
      *(_DWORD *)(this[218] + 4) = v15;
    }
    else
    {
      this[217] = v15;
      this[219] = v15;
    }
    ++this[220];
    this[218] = v15;
    ++i;
  }
  if ( (int)v1[220] > 0 )
  {
    v16 = (_DWORD *)v1[217];
    v17 = 0;
    v18 = v16;
    if ( v16 )
    {
      do
      {
        v18 = (_DWORD *)v18[1];
        ++v17;
      }
      while ( v18 );
      if ( v17 >= 2 )
      {
        v19 = v17 / 2 - 1;
        v20 = v1[217];
        if ( v19 > 0 )
        {
          do
          {
            --v19;
            v20 = *(_DWORD *)(v20 + 4);
          }
          while ( v19 );
        }
        v21 = *(_DWORD *)(v20 + 4);
        v30 = v1[217];
        *(_DWORD *)(v20 + 4) = 0;
        v22 = (_DWORD *)sub_492F60(v30);
        v23 = (_DWORD *)sub_492F60(v21);
        v24 = v23;
        if ( v22 )
        {
          if ( v23 )
          {
            if ( sub_4A46C0(*v23) )
            {
              v32 = v22;
              v25 = v22;
              v22 = (_DWORD *)v22[1];
            }
            else
            {
              v32 = v24;
              v25 = v24;
              v24 = (_DWORD *)v24[1];
            }
            if ( v22 )
            {
              while ( v24 )
              {
                if ( sub_4A46C0(*v24) )
                {
                  v26 = v22;
                  v22 = (_DWORD *)v22[1];
                }
                else
                {
                  v26 = v24;
                  v24 = (_DWORD *)v24[1];
                }
                v25[1] = v26;
                v25 = v26;
                if ( !v22 )
                  goto LABEL_47;
              }
              v25[1] = v22;
            }
            else
            {
LABEL_47:
              if ( v24 )
                v25[1] = v24;
              else
                v25[1] = 0;
            }
          }
          else
          {
            v32 = v22;
          }
        }
        else
        {
          v32 = v23;
        }
        v16 = v32;
      }
    }
    v1[217] = v16;
    v27 = v16;
    if ( v16 )
    {
      for ( j = (_DWORD *)v16[1]; j; j = (_DWORD *)j[1] )
        v27 = j;
    }
    v1[218] = v27;
    v1[219] = v16;
  }
  sub_4840E0(v1);
  sub_484090(v1);
  return 0;
}
