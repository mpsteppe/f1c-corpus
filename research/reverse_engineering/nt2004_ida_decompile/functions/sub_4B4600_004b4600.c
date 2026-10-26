void __stdcall sub_4B4600(int a1, _DWORD *a2, char *a3, float a4, float a5, int a6, int a7)
{
  char *v7; // eax
  int v8; // eax
  const char *v9; // eax
  char *v10; // eax
  char v11; // al
  char *v12; // edi
  CHAR *v13; // eax
  CHAR *v14; // eax
  int v15; // eax
  int v16; // eax
  float v17; // edi
  float v18; // ebp
  int v19; // eax
  int v20; // [esp+8h] [ebp-88h] BYREF
  int v21; // [esp+Ch] [ebp-84h] BYREF
  char Destination[125]; // [esp+10h] [ebp-80h] BYREF
  __int16 v23; // [esp+8Dh] [ebp-3h]
  char v24; // [esp+8Fh] [ebp-1h]

  if ( dword_7DA9B8 && sub_598170(dword_7DA9B8) )
  {
    Destination[0] = byte_629120;
    memset(&Destination[1], 0, 0x7Cu);
    v23 = 0;
    v24 = 0;
    v7 = dword_7665D8;
    v20 = 0;
    v21 = 0;
    if ( !dword_7665D8 )
      v7 = &byte_629120;
    v8 = sub_4E7790(v7);
    if ( v8 )
    {
      v9 = *(const char **)(v8 + 32);
      if ( !v9 )
        v9 = &byte_629120;
      strncpy(Destination, v9, 0x7Fu);
      v24 = 0;
      v10 = &Destination[strlen(Destination)];
      if ( v10 > Destination )
      {
        while ( *v10 != 46 )
        {
          if ( --v10 <= Destination )
            goto LABEL_13;
        }
        *v10 = 0;
      }
LABEL_13:
      v11 = byte_60951C;
      v12 = &Destination[strlen(Destination)];
      *(_DWORD *)v12 = dword_609518;
      v12[4] = v11;
    }
    v13 = *(CHAR **)dword_62A068;
    if ( !*(_DWORD *)dword_62A068 )
      v13 = &byte_629120;
    sub_591F10(v13);
    if ( _strcmpi(Destination, &byte_629120) )
      sub_5924D0(dword_7DA988, (int)&v21, (int)Destination);
    sub_5924D0(dword_7DA988, (int)&v20, off_609054);
    v14 = *(CHAR **)dword_62A068;
    if ( !*(_DWORD *)dword_62A068 )
      v14 = &byte_629120;
    sub_592030(v14);
    if ( v20 )
    {
      if ( a2 )
      {
        v15 = sub_599D20(a3);
        *a2 = v15;
        if ( v15 )
        {
          v16 = *(_DWORD *)(v15 + 16);
          if ( v16 )
          {
            v17 = *(float *)(v16 + 28);
            v18 = *(float *)(v16 + 32);
            sub_4B5EF0(a3);
            sub_4B5F70(0.0, 0, v17, v18, 2);
            v19 = sub_4B5F30(off_609084[0]);
            if ( v19 )
              sub_4B60A0(
                COERCE_FLOAT(SLODWORD(v17) / 2),
                SLODWORD(v18) / 2,
                (__int64)((double)*(int *)(*(_DWORD *)(v19 + 16) + 28) * a4),
                (__int64)((double)*(int *)(*(_DWORD *)(v19 + 16) + 32) * a5),
                COERCE_FLOAT(2));
            *(_DWORD *)(a1 + 20) = a6;
            *(_DWORD *)(a1 + 24) = a7;
          }
        }
      }
    }
    sub_592750(v20);
    if ( v21 )
      sub_592750(v21);
  }
}
