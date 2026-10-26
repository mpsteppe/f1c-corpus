int __thiscall sub_649048(int *this, int a2)
{
  int *i; // eax
  int v4; // eax
  int *v5; // ebx
  int v6; // ecx
  int v8; // eax
  int *v9; // esi
  int v10; // ebx
  unsigned int v11; // eax
  int *v12; // esi
  int v13; // edi
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ecx
  char *v17; // eax
  _DWORD v18[31]; // [esp+8h] [ebp-94h] BYREF
  int Buffer; // [esp+84h] [ebp-18h] BYREF
  _DWORD *v20; // [esp+88h] [ebp-14h]
  int *v21; // [esp+8Ch] [ebp-10h]
  DWORD NumberOfBytesWritten; // [esp+90h] [ebp-Ch] BYREF
  int v23; // [esp+94h] [ebp-8h]
  int *v24; // [esp+98h] [ebp-4h]

  v24 = 0;
  v21 = this;
  for ( i = this; i; v24 = (int *)((char *)v24 + 1) )
    i = (int *)i[19];
  v4 = dword_913C58;
  v5 = &dword_913C58;
  if ( dword_913C58 )
  {
    v6 = *this;
    do
    {
      if ( v4 == v6 )
        break;
      v5 += 9;
      v4 = *v5;
    }
    while ( *v5 );
  }
  if ( !*v5 )
    return -2147467259;
  v20 = sub_644568(*this);
  v23 = v20[2] >> 3;
  Buffer = 542327876;
  if ( sub_6462BB(a2, (char *)&Buffer, 4u, &NumberOfBytesWritten) < 0 )
    return -2147467259;
  memset(v18, 0, sizeof(v18));
  v18[2] = this[4];
  v18[3] = this[3];
  v8 = v5[2];
  v18[0] = 124;
  v18[1] = 4103;
  qmemcpy(&v18[18], v5 + 1, 0x20u);
  v18[26] = 4096;
  if ( (v8 & 3) != 0 )
    v18[26] = 4098;
  if ( (v8 & 0x20) != 0 )
    BYTE1(v18[26]) |= 1u;
  v9 = v21;
  v10 = 0;
  if ( v21[19] )
  {
    v18[26] |= 0x400008u;
    v18[1] = 135175;
    v18[6] = v24;
  }
  if ( v21[20] )
  {
    v18[26] |= 8u;
    BYTE1(v18[27]) |= 0xFEu;
  }
  v11 = v21[5];
  if ( v11 > 1 )
  {
    BYTE2(v18[1]) |= 0x80u;
    BYTE2(v18[27]) |= 0x20u;
    v18[5] = v11;
  }
  if ( sub_6462BB(a2, (char *)v18, 0x7Cu, &NumberOfBytesWritten) < 0
    || v20[1] == 1 && sub_6462BB(a2, (char *)v9[2], 0x400u, &NumberOfBytesWritten) < 0 )
  {
    return -2147467259;
  }
  v24 = v9;
  do
  {
    v12 = v24;
    while ( v12 )
    {
      if ( v12[5] )
      {
        while ( 1 )
        {
          v13 = 0;
          if ( v12[4] )
            break;
LABEL_38:
          if ( ++v10 >= (unsigned int)v12[5] )
            goto LABEL_39;
        }
        while ( 2 )
        {
          v14 = *v21;
          if ( *v21 > 877942852 )
          {
            if ( v14 != 894720068 )
            {
              if ( v14 != 1111970375 && v14 != 1195525970 && v14 != 1498831189 )
                goto LABEL_49;
              goto LABEL_50;
            }
LABEL_34:
            v15 = 16 * ((unsigned int)v12[6] >> 2)
                + v12[13] * (v10 + v12[10])
                + v12[12] * ((unsigned int)(v13 + v12[7]) >> 2);
            v16 = 16 * ((unsigned int)(v12[3] + 3) >> 2);
          }
          else
          {
            if ( *v21 == 877942852 )
              goto LABEL_34;
            if ( v14 != 827611204 )
            {
              if ( v14 == 844388420 )
                goto LABEL_34;
              if ( v14 != 844715353 )
              {
                if ( v14 == 861165636 )
                  goto LABEL_34;
LABEL_49:
                v17 = (char *)(v12[1] + v23 * v12[6] + v12[13] * (v10 + v12[10]) + v12[12] * (v13 + v12[7]));
                v16 = v23 * v12[3];
LABEL_36:
                if ( sub_6462BB(a2, v17, v16, &NumberOfBytesWritten) < 0 )
                  return -2147467259;
                if ( ++v13 >= (unsigned int)v12[4] )
                  goto LABEL_38;
                continue;
              }
LABEL_50:
              v17 = (char *)(v12[1] + v23 * v12[6] + v12[13] * (v10 + v12[10]) + v12[12] * (v13 + v12[7]));
              v16 = 4 * ((unsigned int)(v12[3] + 1) >> 1);
              goto LABEL_36;
            }
            v15 = v12[13] * (v10 + v12[10])
                + v12[12] * ((unsigned int)(v13 + v12[7]) >> 2)
                + 8 * ((unsigned int)v12[6] >> 2);
            v16 = 8 * ((unsigned int)(v12[3] + 3) >> 2);
          }
          break;
        }
        v17 = (char *)(v12[1] + v15);
        v13 += 3;
        goto LABEL_36;
      }
LABEL_39:
      v12 = (int *)v12[19];
      v10 = 0;
    }
    v24 = (int *)v24[20];
  }
  while ( v24 );
  return 0;
}
