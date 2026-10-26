void __stdcall sub_49CD80(int a1, _DWORD *a2, int a3, float a4, float a5, int a6, int a7)
{
  char *v7; // eax
  int v8; // eax
  char *v9; // eax
  char *v10; // eax
  char v11; // al
  char *v12; // edi
  char *v13; // eax
  char *v14; // eax
  int v15; // eax
  int v16; // eax
  float v17; // edi
  float v18; // ebp
  int v19; // eax
  int v20; // ebx
  int v21; // eax
  int v22; // [esp-10h] [ebp-A0h]
  int v23; // [esp+8h] [ebp-88h] BYREF
  int v24; // [esp+Ch] [ebp-84h] BYREF
  char v25[125]; // [esp+10h] [ebp-80h] BYREF
  __int16 v26; // [esp+8Dh] [ebp-3h]
  char v27; // [esp+8Fh] [ebp-1h]

  if ( dword_8AFE88 && sub_545F40(dword_8AFE88) )
  {
    v25[0] = byte_5EA438[0];
    memset(&v25[1], 0, 0x7Cu);
    v26 = 0;
    v27 = 0;
    v7 = (char *)dword_7CE64C;
    v23 = 0;
    v24 = 0;
    if ( !dword_7CE64C )
      v7 = byte_5EA438;
    v8 = sub_4C40B0(v7);
    if ( v8 )
    {
      v9 = *(char **)(v8 + 32);
      if ( !v9 )
        v9 = byte_5EA438;
      sub_587DD0(v25, v9, 127);
      v27 = 0;
      v10 = &v25[strlen(v25)];
      if ( v10 > v25 )
      {
        while ( *v10 != 46 )
        {
          if ( --v10 <= v25 )
            goto LABEL_13;
        }
        *v10 = 0;
      }
LABEL_13:
      v11 = byte_5CCEC0;
      v12 = &v25[strlen(v25)];
      *(_DWORD *)v12 = dword_5CCEBC;
      v12[4] = v11;
    }
    v13 = (char *)dword_5EC3D8;
    if ( !dword_5EC3D8 )
      v13 = byte_5EA438;
    sub_53C800(v13);
    if ( sub_588410(v25, byte_5EA438) )
      sub_53CBC0(&v24, v25);
    sub_53CBC0(&v23, off_5CCB54[0]);
    v14 = (char *)dword_5EC3D8;
    if ( !dword_5EC3D8 )
      v14 = byte_5EA438;
    sub_53C900(v14);
    if ( v23 )
    {
      if ( a2 )
      {
        v15 = sub_547920(a3);
        *a2 = v15;
        if ( v15 )
        {
          v16 = *(_DWORD *)(v15 + 84);
          if ( v16 )
          {
            v17 = *(float *)(v16 + 28);
            v18 = *(float *)(v16 + 32);
            sub_49E930(a3);
            sub_49EA10(0.0, 0, v17, v18, 2);
            v19 = sub_49E9A0(off_5CCB84[0]);
            if ( v19 )
            {
              v20 = *(_DWORD *)(v19 + 84);
              v22 = sub_587BDC((double)*(int *)(v20 + 32) * a5);
              v21 = sub_587BDC((double)*(int *)(v20 + 28) * a4);
              sub_49EB40(COERCE_FLOAT(SLODWORD(v17) / 2), SLODWORD(v18) / 2, v21, v22, COERCE_FLOAT(2));
            }
            *(_DWORD *)(a1 + 20) = a6;
            *(_DWORD *)(a1 + 24) = a7;
          }
        }
      }
    }
    sub_53CE40(v23);
    if ( v24 )
      sub_53CE40(v24);
  }
}
