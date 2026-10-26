int __userpurge sub_5E9E60@<eax>(_DWORD *a1@<ecx>, int a2@<edi>, int i, char a4, int a5)
{
  _DWORD *v5; // ebx
  _DWORD *v7; // eax
  char *v8; // edi
  char *v9; // esi
  int v10; // eax
  int v11; // eax
  int v12; // eax
  _DWORD *v13; // esi
  void *v14; // eax
  unsigned __int64 v15; // rax
  char **v16; // eax
  int v17; // ecx
  unsigned int v19; // [esp-8h] [ebp-80h]
  int v20; // [esp-4h] [ebp-7Ch]
  char *v21; // [esp+Ch] [ebp-6Ch]
  int v22; // [esp+14h] [ebp-64h]
  int v23; // [esp+18h] [ebp-60h] BYREF
  int v24; // [esp+1Ch] [ebp-5Ch] BYREF
  int v25; // [esp+20h] [ebp-58h] BYREF
  char v26[8]; // [esp+24h] [ebp-54h] BYREF
  char v27[64]; // [esp+2Ch] [ebp-4Ch] BYREF
  int v28; // [esp+74h] [ebp-4h]

  v5 = (_DWORD *)i;
  sub_5DEC60(&v23, (_DWORD *)i, 4u);
  v22 = 0;
  if ( v23 > 0 )
  {
    v20 = a2;
    do
    {
      v7 = operator new(0x450u);
      v28 = 0;
      if ( v7 )
      {
        v8 = (char *)sub_5E8AC0(v7);
        v21 = v8;
      }
      else
      {
        v21 = 0;
        v8 = 0;
      }
      v9 = v8 + 4;
      v28 = -1;
      sub_5DEC60(v8 + 4, v5, 0x40u);
      sub_5DEC60(v8, v5, 4u);
      sub_5DEC60(v8 + 88, v5, 0x10u);
      sub_5DEC60(v8 + 72, v5, 0x10u);
      sub_5DEC60(v8 + 104, v5, 0x10u);
      sub_5DEC60(v8 + 120, v5, 0x10u);
      sub_5DEC60(v8 + 236, v5, 4u);
      sub_5DEC60(v8 + 240, v5, 4u);
      sub_5DEC60(&v24, v5, 4u);
      if ( (*v8 & 0x20) == 0 )
        *((_DWORD *)v8 + 21) = 1065353216;
      sub_5DEC60(v8 + 264, v5, 4u);
      sub_5DEC60(v8 + 268, v5, 4u);
      if ( a4 )
        sub_5DEC60(v8 + 272, v5, 4u);
      else
        sub_5DEC60(v8 + 272, v5, 0x40u);
      v10 = 0;
      for ( i = 0; i < 8; ++i )
      {
        sub_5DEC60(&v8[24 * v10 + 336], v5, 0x18u);
        v10 = i + 1;
      }
      sub_5DEC60(v8 + 532, v5, 4u);
      sub_5DEC60(v8 + 536, v5, 4u);
      if ( a4 )
        sub_5DEC60(v8 + 540, v5, 4u);
      else
        sub_5DEC60(v8 + 540, v5, 0x40u);
      v11 = 0;
      for ( i = 0; i < 8; ++i )
      {
        sub_5DEC60(&v8[24 * v11 + 604], v5, 0x18u);
        v11 = i + 1;
      }
      sub_5DEC60(v8 + 800, v5, 4u);
      sub_5DEC60(v8 + 804, v5, 4u);
      if ( a4 )
        sub_5DEC60(v8 + 808, v5, 4u);
      else
        sub_5DEC60(v8 + 808, v5, 0x40u);
      v12 = 0;
      for ( i = 0; i < 8; ++i )
      {
        sub_5DEC60(&v8[24 * v12 + 872], v5, 0x18u);
        v12 = i + 1;
      }
      sub_5DEC60(v8 + 1068, v5, 0x20u);
      if ( a4 )
        sub_5DEC60(&i, v5, 4u);
      *(_DWORD *)v8 |= 2u;
      *((_DWORD *)v8 + 61) = v24;
      sub_5DEC60(&v25, v5, 4u);
      if ( v25 > 0 )
      {
        sub_5E8100(v8, v25);
        v13 = (_DWORD *)*((_DWORD *)v8 + 65);
        i = 0;
        if ( *((int *)v8 + 64) > 0 )
        {
          while ( 1 )
          {
            sub_5DEC60(v13 + 3, v5, 0x40u);
            sub_5DEC60(v13, v5, 4u);
            sub_5DEC60(v13 + 2, v5, 4u);
            sub_5DEC60(v13 + 1, v5, 4u);
            if ( (int)v13[1] > 1 )
              break;
            if ( (*v13 & 0x40000) != 0 )
            {
              sub_5DEC60(v13 + 21, v5, 4u);
              goto LABEL_31;
            }
LABEL_32:
            sub_5DEC60(v13 + 24, v5, 4u);
            sub_5DEC60(v13 + 25, v5, 4u);
            sub_5DEC60(v13 + 26, v5, 4u);
            sub_5DEC60(v13 + 28, v5, 4u);
            sub_5DEC60(v13 + 29, v5, 4u);
            sub_5DEC60(v13 + 30, v5, 4u);
            sub_5DEC60(v13 + 31, v5, 4u);
            sub_5DEC60(v13 + 33, v5, 4u);
            v15 = (unsigned __int64)(*((float *)v13 + 26) * 255.0);
            v13[27] = v15 | (((unsigned int)v15 | (((unsigned int)v15 | ((_DWORD)v15 << 8)) << 8)) << 8);
            sub_5DEC60(v27, v5, 0x40u);
            sub_5E3A50(v13, *v13 & 0xC, v13[2]);
            sub_5E2C50((int)v13);
            if ( (*v13 & 0x100) != 0 )
              *(_DWORD *)v8 |= 0x200u;
            if ( (*v13 & 0x200) != 0 )
              *(_DWORD *)v8 |= 0x4000u;
            v13 += 121;
            if ( ++i >= *((_DWORD *)v8 + 64) )
              goto LABEL_37;
          }
          sub_5DEC60(v13 + 20, v5, 4u);
          v14 = operator new(4 * v13[20]);
          v19 = 4 * v13[20];
          v13[19] = v14;
          sub_5DEC60(v14, v5, v19);
          sub_5DEC60(v13 + 21, v5, 4u);
LABEL_31:
          sub_5DEC60(v13 + 22, v5, 4u);
          *((float *)v13 + 22) = 1.0 / *((float *)v13 + 22);
          goto LABEL_32;
        }
LABEL_37:
        v9 = v8 + 4;
      }
      if ( (*(_DWORD *)v8 & 0x200) != 0 )
      {
        sub_5E8910((int)v8, (int)v26);
        sub_630FE0(v8 + 68);
        strcat(v9, v26);
        v8 = v21;
      }
      if ( sub_5E9070((int)a1, (int)v8, 0, a5) )
      {
        sub_5E9AE0();
        sub_5E8CD0(v8, (__int32)v5, v20);
        j__free(v8);
      }
      else
      {
        v16 = (char **)operator new(0xCu);
        if ( v16 )
        {
          *v16 = v8;
          v16[1] = 0;
          *((_BYTE *)v16 + 8) = 1;
        }
        else
        {
          v16 = 0;
        }
        if ( a1[9] )
        {
          *(_DWORD *)(a1[10] + 4) = v16;
        }
        else
        {
          a1[9] = v16;
          a1[11] = v16;
        }
        v17 = a1[12] + 1;
        a1[10] = v16;
        a1[12] = v17;
        *(_DWORD *)v8 |= 1u;
      }
      ++v22;
    }
    while ( v22 < v23 );
  }
  return 0;
}
