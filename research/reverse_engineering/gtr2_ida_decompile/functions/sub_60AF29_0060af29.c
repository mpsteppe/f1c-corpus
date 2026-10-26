int __userpurge sub_60AF29@<eax>(
        char a1@<zf>,
        char a2@<sf>,
        char a3@<of>,
        int a4@<eax>,
        int *a5@<ecx>,
        int a6,
        int a7,
        int a8)
{
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  int v11; // edx
  _DWORD *v12; // edi
  _DWORD *v13; // eax
  int v14; // ecx
  _DWORD *v15; // eax
  _DWORD *v16; // eax
  _DWORD *v17; // eax
  _DWORD *v18; // eax
  _DWORD *v19; // eax
  _DWORD *v20; // eax
  _DWORD *v21; // eax
  _DWORD *v22; // eax
  _DWORD *v23; // eax
  _DWORD *v24; // eax
  _DWORD *v25; // eax
  _DWORD *v26; // eax
  _DWORD *v27; // eax
  _DWORD *v28; // eax
  _DWORD *v29; // eax
  _DWORD *v30; // eax
  _DWORD *v31; // eax
  int v32; // ebx
  int v33; // ebp
  int v34; // ebp
  char v36; // [esp+0h] [ebp-Ch]

  if ( a2 ^ a3 | a1 )
  {
    if ( !a1 )
    {
      switch ( a4 )
      {
        case 1:
          v9 = operator new(0x24u);
          if ( v9 )
            v10 = sub_60AD20(v9);
          else
            v10 = 0;
          a5[9] = (int)v10;
          v11 = 0;
          v12 = v10;
          v13 = v10 + 7;
          a5[6] |= 1u;
          v14 = 32;
          *v13 = 0;
          goto LABEL_50;
        case 2:
          v15 = operator new(0x24u);
          if ( v15 )
            v16 = sub_60AD20(v15);
          else
            v16 = 0;
          a5[10] = (int)v16;
          v12 = v16;
          v13 = v16 + 7;
          a5[6] |= 2u;
          v14 = 16;
          v11 = 1;
          *v13 = 0;
          goto LABEL_50;
        case 4:
          v17 = operator new(0x24u);
          if ( v17 )
            v18 = sub_60AD20(v17);
          else
            v18 = 0;
          a5[11] = (int)v18;
          v12 = v18;
          v13 = v18 + 7;
          a5[6] |= 4u;
          v14 = 24;
          v11 = 2;
          *v13 = 0;
          goto LABEL_50;
        case 16:
          v19 = operator new(0x24u);
          if ( v19 )
            v20 = sub_60AD20(v19);
          else
            v20 = 0;
          a5[12] = (int)v20;
          v12 = v20;
          v13 = v20 + 7;
          a5[6] |= 0x10u;
          v14 = 32;
          v11 = 3;
          *v13 = 0;
          goto LABEL_50;
        case 32:
          v21 = operator new(0x24u);
          if ( v21 )
            v22 = sub_60AD20(v21);
          else
            v22 = 0;
          a5[13] = (int)v22;
          v14 = 32;
          v12 = v22;
          v13 = v22 + 7;
          a5[6] |= 0x20u;
          v11 = 4;
          *v13 = 0;
          goto LABEL_50;
        default:
          return 0;
      }
    }
    v23 = operator new(0x24u);
    if ( v23 )
    {
      byte_FB2320 = 0;
      dword_FB2748 = 0;
      *v23 = 0;
      v23[1] = 0;
      v23[4] = 0;
      v23[3] = 0;
      v23[2] = 0;
      v23[7] = 0;
      v23[5] = 0;
      v23[6] = 0;
      v23[8] = 0;
    }
    else
    {
      v23 = 0;
    }
    a5[8] = (int)v23;
    v12 = v23;
    v11 = 0;
    v13 = v23 + 7;
    a5[6] = 4096;
    v14 = 64;
    *v13 = 1234;
    goto LABEL_50;
  }
  if ( a4 > 0x8000 )
  {
    if ( a4 != 0x20000 )
      return 0;
    v30 = operator new(0x24u);
    if ( v30 )
      v31 = sub_60AD20(v30);
    else
      v31 = 0;
    a5[8] = (int)v31;
    v12 = v31;
    v11 = 0;
    v13 = v31 + 7;
    a5[6] = 0x20000;
    *v13 = 450;
    goto LABEL_49;
  }
  if ( a4 == 0x8000 )
  {
    v28 = operator new(0x24u);
    if ( v28 )
      v29 = sub_60AD20(v28);
    else
      v29 = 0;
    a5[8] = (int)v29;
    v11 = 0;
    v12 = v29;
    v13 = v29 + 7;
    a5[6] = 0x8000;
    v14 = 88;
    *v13 = 0;
    goto LABEL_50;
  }
  if ( a4 == 0x2000 )
  {
    v26 = operator new(0x24u);
    if ( v26 )
      v27 = sub_60AD20(v26);
    else
      v27 = 0;
    a5[8] = (int)v27;
    v12 = v27;
    v11 = 0;
    v13 = v27 + 7;
    a5[6] = 0x2000;
    *v13 = 324;
LABEL_49:
    v14 = 28;
    goto LABEL_50;
  }
  if ( a4 != 0x4000 )
    return 0;
  v24 = operator new(0x24u);
  if ( v24 )
    v25 = sub_60AD20(v24);
  else
    v25 = 0;
  a5[8] = (int)v25;
  v11 = 0;
  v12 = v25;
  v13 = v25 + 7;
  a5[6] = 0x4000;
  v14 = 32;
  *v13 = 0;
LABEL_50:
  v32 = *a5;
  v12[6] = v11;
  v12[2] = a7;
  v33 = 0;
  *v12 = v32;
  v12[5] = v14;
  if ( (v32 & 0x40) != 0 )
    v33 = 16;
  if ( (v32 & 2) != 0 )
    v33 |= 8u;
  if ( (v32 & 4) != 0 )
    v34 = v33 | 0x200;
  else
    v34 = v33 | 8;
  if ( (*(int (__stdcall **)(int, int, int, _DWORD, _DWORD, _DWORD *, _DWORD))(*(_DWORD *)a6 + 104))(
         a6,
         a7 * v14,
         v34,
         *v13,
         0,
         v12 + 8,
         0) )
  {
    sub_5D8C80((int)v12, (char *)0xFFFFFFFF, "Error creating vertex buffer", v36);
    j__free(v12);
    return -1;
  }
  a5[1] = a7;
  a5[2] = 0;
  return 0;
}
