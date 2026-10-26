int __usercall sub_47DA30@<eax>(_DWORD *a1@<ecx>, int a2@<edi>)
{
  int v3; // eax
  int *v4; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  char v9; // cl
  int v10; // eax
  bool v11; // bl
  int v12; // ecx
  int result; // eax
  int v14; // eax
  int v15; // eax
  _DWORD *v16; // ecx
  _DWORD *v17; // ecx
  int v18; // ecx
  int v19; // eax
  int v20; // ebp
  unsigned int v21; // ebx
  int v22; // edi
  int **v23; // [esp-10h] [ebp-398h]
  int v24; // [esp-Ch] [ebp-394h]
  int v25; // [esp-8h] [ebp-390h]
  int v26; // [esp-4h] [ebp-38Ch]
  char *v27; // [esp+0h] [ebp-388h]
  int *v28; // [esp+4h] [ebp-384h]
  float v29; // [esp+8h] [ebp-380h]
  int *v30; // [esp+Ch] [ebp-37Ch] BYREF
  _BYTE *v31; // [esp+10h] [ebp-378h]
  int *v32; // [esp+14h] [ebp-374h]
  int v33; // [esp+18h] [ebp-370h] BYREF
  int *v34; // [esp+1Ch] [ebp-36Ch] BYREF
  int v35; // [esp+20h] [ebp-368h] BYREF
  __int128 v36; // [esp+24h] [ebp-364h] BYREF
  int v37[16]; // [esp+34h] [ebp-354h] BYREF
  char v38; // [esp+74h] [ebp-314h]
  int v39; // [esp+368h] [ebp-20h]
  int *v40; // [esp+374h] [ebp-14h]
  char v41; // [esp+380h] [ebp-8h] BYREF

  v3 = a1[28332];
  if ( v3 == 2 || v3 == 1 )
  {
    if ( byte_B73510 )
    {
      sub_48A7C0(a1 + 28326);
      v4 = (int *)a1[28327];
      v5 = *v4;
      DWORD2(v36) = *v4;
      if ( (int *)DWORD2(v36) != v4 )
      {
        while ( 1 )
        {
          v6 = 132 * *(unsigned __int8 *)(v5 + 16);
          v7 = a1[v6 + 557];
          v8 = (int)&a1[v6 + 557];
          if ( v7 != 3 )
            break;
          a2 = *(_DWORD *)(v5 + 12);
          if ( dword_923E84[5654 * sub_479D00(a1, a2)] != -1 )
          {
            v33 = a2;
LABEL_11:
            sub_48B4C0(&dword_B6D67C);
          }
LABEL_12:
          sub_476240((int *)&v36 + 1);
          v5 = DWORD1(v36);
          if ( DWORD1(v36) == a1[28327] )
            goto LABEL_13;
        }
        v9 = *(_BYTE *)(v8 + 524);
        if ( (v9 & 2) == 0 || (v9 & 4) != 0 )
          goto LABEL_12;
        v33 = *(_DWORD *)(v5 + 12);
        goto LABEL_11;
      }
    }
  }
LABEL_13:
  v10 = a1[28332];
  v11 = v10 == 2 || v10 == 1;
  v32 = (int *)&v41;
  v12 = a1[28329];
  v31 = (char *)&v36 + 8;
  v30 = v37;
  DWORD2(v36) = 848;
  for ( result = sub_59B4D0(v12); !result; result = sub_59B4D0(v18) )
  {
    a1[533] = 0;
    if ( v11 )
    {
      a2 = (int)v40;
      v34 = v40;
      sub_4796F0(a1 + 28326, (int **)&v36, &v34);
      v14 = a1[28332];
      if ( v14 == 2 || v14 == 1 )
      {
        v15 = 0;
        v16 = a1 + 424;
        while ( a2 != *v16 )
        {
          ++v15;
          ++v16;
          if ( v15 >= 104 )
            goto LABEL_28;
        }
      }
      else
      {
        v15 = 0;
        v17 = a1 + 28222;
        while ( a2 != *v17 )
        {
          ++v15;
          ++v17;
          if ( v15 >= 104 )
          {
LABEL_28:
            v15 = 104;
            break;
          }
        }
      }
      DWORD1(v36) = v15 | DWORD1(v36) & 0xFFFFFF00;
    }
    else if ( BYTE4(v36) < 0x68u )
    {
      v40 = (int *)a1[BYTE4(v36) + 28222];
    }
    v29 = dbl_FB1D18;
    sub_47AB30(a1 + 73173, (int)&v36 + 4, v29);
    sub_47BEE0(
      (int)a1,
      a2,
      (int)a1,
      (const char *)&v36 + 4,
      v30,
      (int)v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37[0],
      v37[1],
      v37[2],
      v37[3],
      v37[4],
      v37[5],
      v37[6],
      v37[7],
      v37[8],
      v37[9],
      v37[10],
      v37[11],
      v37[12],
      v37[13],
      v37[14],
      v37[15],
      v38);
    v28 = &v35;
    v27 = (char *)&v36 + 4;
    v18 = a1[28329];
    v35 = 848;
  }
  if ( v11 )
  {
    v19 = a1[28332];
    if ( (v19 == 2 || v19 == 1) && byte_B73510 )
    {
      sub_51A340(&dword_75B490);
      for ( result = sub_51BFE0(&v34); result; result = sub_51BFE0(&v33) )
        sub_489EC0(&dword_B6D67C, &v34);
    }
    else
    {
      v33 = sub_59B580(*(_DWORD *)(*(_DWORD *)*a1 + 113316));
      v20 = 0;
      v21 = 0;
      if ( a1[28221] )
      {
        v32 = a1 + 28013;
        v31 = a1 + 688;
        do
        {
          if ( (*v31 & 2) != 0 && (*v31 & 4) == 0 )
          {
            v22 = *v32;
            if ( *v32 != v33 )
            {
              sub_51A340(&dword_75B490);
              if ( sub_51BFE0(&v34) )
              {
                do
                {
                  if ( v22 != v39 )
                  {
                    v26 = 1000;
                    v25 = v22;
                    v24 = 1;
                    v23 = &v34;
                    sub_4745E0();
                    ++v20;
                  }
                }
                while ( sub_51BFE0(&v30) );
              }
            }
          }
          ++v21;
          ++v28;
          v27 += 528;
        }
        while ( v21 < a1[28221] );
      }
      result = dword_B73300;
      if ( !dword_B73300 && dword_B73294 > 8 && v20 > 0 )
        return sub_59B4A0(a1[28329], 0, v23, v24, v25, v26);
    }
  }
  return result;
}
