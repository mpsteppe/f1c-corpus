void __userpurge sub_52D970(_DWORD **a1@<ecx>, float a2@<edi>, float a3, int a4, _DWORD *a5, int a6)
{
  int v7; // ecx
  int v8; // ebx
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // eax
  int v13; // edi
  _DWORD *v14; // eax
  int v15; // ecx
  _DWORD *v16; // edx
  char *v17; // eax
  char v18; // al
  char *v19; // eax
  _DWORD *v20; // eax
  _DWORD *v21; // ecx
  int v22; // eax
  int v23; // eax
  char *v24; // eax
  float v25; // ecx
  int v26; // eax
  int v27; // eax
  _DWORD *v28; // ecx
  int v29; // esi
  float v30; // [esp+0h] [ebp-280h]
  _DWORD *v31; // [esp+4h] [ebp-27Ch]
  char v33[4]; // [esp+20h] [ebp-260h] BYREF
  char Buffer[508]; // [esp+74h] [ebp-20Ch] BYREF
  float v35; // [esp+270h] [ebp-10h]
  float v36; // [esp+278h] [ebp-8h]
  float retaddr; // [esp+280h] [ebp+0h]

  v7 = (int)*a1;
  v8 = 3;
  if ( *(int *)(v7 + 14820) >= 3 )
    return;
  if ( !a5 )
  {
    if ( a1[2] == (_DWORD *)9 )
      a1[2] = (_DWORD *)5;
    a1[70] = (_DWORD *)((char *)a1[70] + 1);
    if ( !dword_FADE9C || dword_FADE9C == 7 )
    {
      if ( a1[2] != (_DWORD *)dword_B64134 )
      {
        a1[2] = (_DWORD *)5;
        sub_427C40(v7, 16, 0);
      }
    }
    else if ( dword_FADE9C >= 1 )
    {
      if ( dword_FADE9C == 1 && (v8 = dword_757C10, v9 = 0, dword_757C10 > 0) )
      {
        while ( 1 )
        {
          v10 = *(&dword_91E088 + v9);
          if ( v10 != v7 && a6 + 1 <= *(_DWORD *)(v10 + 19284) )
            break;
          if ( ++v9 >= dword_757C10 )
            goto LABEL_13;
        }
      }
      else
      {
LABEL_13:
        LOBYTE(v8) = a1[2] == (_DWORD *)10;
        sub_52C760();
        if ( !(_BYTE)v8 )
        {
          v11 = (int)*a1;
          a1[70] = 0;
          if ( !*(_BYTE *)(v11 + 15572) )
            sub_552CA0(v11, LODWORD(a3));
        }
      }
    }
    v12 = (int)a1[3];
    a1[4] = 0;
    if ( v12 >= 332 )
    {
      v13 = 332;
    }
    else
    {
      v13 = v12;
      if ( v12 < 0 )
        goto LABEL_57;
    }
    if ( v13 < (int)a1[51] )
    {
      if ( retaddr <= 0.0 )
      {
LABEL_56:
        *((_BYTE *)a1[54] + v13) = sub_551270(*((_BYTE *)a1 + 4));
        goto LABEL_57;
      }
      *(float *)&a1[53][v13] = retaddr;
      if ( *((float *)a1 + 41) < 0.0 || retaddr < (double)*((float *)a1 + 41) )
      {
        v14 = a1[40];
        v15 = (int)*a1;
        *((float *)a1 + 41) = retaddr;
        v16 = a1[4];
        a1[47] = v14;
        LOBYTE(v8) = sub_5512F0(v16, *(_DWORD *)(v15 + 22468), 0);
        sub_414510();
        if ( *(_DWORD *)dword_B72314 != 7 && !(*a1)[3705] && (_BYTE)v8 == 1 )
        {
          sub_6153C0(*((float *)a1 + 41));
          v17 = sub_41D840(&byte_91CC38, "New Fastest Lap: ");
          sprintf(Buffer, "%s%d:%06.3f", v17, a2, *(float *)v33);
          sub_4730C0((int **)&dword_B6CB98, Buffer, 2, (int)&byte_1020304, 1084227584);
        }
      }
      v18 = *((_BYTE *)a1 + 200);
      *((float *)a1 + 8) = v36;
      if ( !v18 || *((float *)a1 + 49) <= (double)v36 && *((float *)a1 + 49) >= 0.0 )
        goto LABEL_53;
      *((float *)a1 + 49) = v36;
      if ( *(_DWORD *)dword_B72314 != 7 )
        goto LABEL_53;
      LOBYTE(v8) = 0.0 == sub_521060(&dword_BE1228) || sub_521060(&dword_BE1228) > *((float *)a1 + 49);
      if ( sub_52B8B0(dword_BE1210) )
      {
        if ( !(_BYTE)v8 )
          goto LABEL_53;
      }
      else
      {
        if ( 0.0 != sub_521060(&dword_BE122C) && sub_521060(&dword_BE122C) <= *((float *)a1 + 49) )
          goto LABEL_53;
        if ( !(_BYTE)v8 )
          goto LABEL_42;
      }
      sub_6153C0(*((float *)a1 + 49));
      v19 = sub_41D840(&byte_91CC38, "New Fastest Lap: ");
      sprintf(Buffer, "%s%d:%06.3f", v19, *(_DWORD *)v33, a2);
      sub_4730C0((int **)&dword_B6CB98, Buffer, 2, (int)&byte_1020304, 1084227584);
LABEL_42:
      if ( sub_52B8B0(dword_BE1210) )
        sub_5284C0(&dword_BE1228, v8, v13, 0, 0);
      sub_52A3E0();
      sub_5284C0(&dword_BE122C, v8, v13, 1, 0);
      if ( byte_B731F8 )
      {
        if ( !sub_52B8D0(dword_BE1210) )
          goto LABEL_52;
      }
      else if ( 0.0 == sub_521060(&dword_BE1228) || sub_521060(&dword_BE1228) > *((float *)a1 + 49) )
      {
        sub_5284C0(&dword_BE1228, v8, v13, 0, 0);
LABEL_52:
        sub_529C70(dword_BE1210);
      }
LABEL_53:
      if ( *((float *)a1 + 44) <= 0.0 || *((float *)a1 + 44) > (double)*((float *)a1 + 8) )
      {
        v20 = a1[9];
        v21 = a1[10];
        a1[44] = a1[8];
        a1[45] = v20;
        a1[46] = v21;
      }
      goto LABEL_56;
    }
LABEL_57:
    *((_BYTE *)a1 + 200) = *(_DWORD *)(dword_91E084 + 14820) == 0;
    if ( a1[39] )
    {
      v22 = a6 + 1;
      a1[3] = (_DWORD *)(a6 + 1);
      switch ( *(_DWORD *)dword_B640C8 )
      {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
          if ( a1[27] == (_DWORD *)1 )
          {
            if ( (*(_DWORD *)dword_B640C8 == 3 || *(_DWORD *)dword_B640C8 == 4)
              && v22 > dword_FADE18
              && dword_B6FA78
              && (*a1)[3705] <= 1u )
            {
              v24 = sub_41D840(&byte_91CC38, "Laps");
              sprintf(v33, "%d %s", a1[3], v24);
              sub_52C000((int *)a1, v33);
            }
          }
          else
          {
            if ( v22 >= dword_FADE18 || v36 >= (double)flt_FADE20 )
              sub_52D900(a1);
            if ( ((int)a1[3] >= dword_FADE18 - 1 || v36 >= (double)flt_FADE20)
              && (*(_DWORD *)dword_B640C8 == 3 || *(_DWORD *)dword_B640C8 == 4)
              && a1[1] == *(_DWORD **)(*(&dword_91E088 + dword_91E080) + 22468) )
            {
              sub_4EB7C0();
            }
          }
          break;
        case 6:
          if ( dword_B64134 == 8 )
          {
            sub_52D900(a1);
            v31 = *a1;
            *((float *)a1 + 48) = v36 - flt_FADE1C;
            sub_4EC270(v31);
          }
          else if ( v22 >= dword_FADE18 || v36 >= (double)flt_FADE20 && a1[13] == (_DWORD *)1 )
          {
            sub_52D900(a1);
            *((float *)a1 + 48) = v36 - flt_FADE1C;
            sub_430250(&dword_B640C0, 8u);
            sub_4EC270(*a1);
          }
          else
          {
            sub_4EB6E0();
          }
          v8 = 0;
          if ( (int)a1[30] > 0 )
          {
            v13 = (int)(a1 + 31);
            do
            {
              v23 = *(_DWORD *)v13;
              if ( *(_DWORD *)v13 && (v23 != 1 || *((_BYTE *)*a1 + 15572)) )
              {
                *(_DWORD *)v13 = v23 - 1;
              }
              else
              {
                if ( (*a1)[3705] <= 1u )
                  sub_52C000((int *)a1, "Ignored Stop/Go Penalty");
                *(_DWORD *)v13 = 0;
              }
              if ( a1[27] )
                *((float *)a1 + 48) = (double)(*(_DWORD *)(v13 + 4) + 15) + *((float *)a1 + 48);
              ++v8;
              v13 += 8;
            }
            while ( v8 < (int)a1[30] );
          }
          break;
        default:
          break;
      }
      if ( !byte_FADE3C )
        byte_FADE3C = (int)a1[3] >= (dword_FADE18 + 1) >> 1;
    }
    if ( dword_B64134 != 3 )
    {
      v25 = v36;
      a1[39] = (_DWORD *)2;
      *((float *)a1 + 40) = v25;
    }
    if ( *(_DWORD *)dword_B72314 == 7 )
    {
      sub_5284C0(&dword_BE122C, v8, v13, 0, 0);
      sub_52A420();
      sub_524160(dword_BE1210, 0);
      sub_52A3E0();
      v30 = dbl_FB1D18 - v35;
      sub_527C90(dword_BE1210, v30);
    }
    v26 = (int)a1[3];
    if ( v26 > 0 && v26 <= (int)a1[51] )
      *(float *)&a1[52][v26 - 1] = v35;
    if ( *(_DWORD *)dword_B640C8 != 6 && *((_BYTE *)*a1 + 15572) && a1[39] == (_DWORD *)2 )
      a1[39] = (_DWORD *)1;
    return;
  }
  a1[4] = a5;
  if ( a3 > 0.0 )
  {
    if ( *(float *)&a1[(_DWORD)a5 + 41] < 0.0 || a3 < (double)*(float *)&a1[(_DWORD)a5 + 41] )
      *(float *)&a1[(_DWORD)a5 + 41] = a3;
    *(float *)&a1[(_DWORD)a1[4] + 8] = a3;
    sub_5512F0(a1[4], (*a1)[5617], 0);
    sub_414510();
  }
  if ( !a1[39] && a1[4] == (_DWORD *)1 && dword_B64134 != 3 )
    a1[39] = (_DWORD *)1;
  if ( a5 == (_DWORD *)2 )
  {
    v27 = 0;
    if ( (int)a1[30] > 0 )
    {
      v28 = a1 + 31;
      while ( *v28 != 1 )
      {
        ++v27;
        v28 += 2;
        if ( v27 >= (int)a1[30] )
          goto LABEL_125;
      }
      if ( !(*a1)[3705] )
        sub_4EE320(36, 0);
    }
  }
LABEL_125:
  v29 = (int)*a1;
  if ( !*(_DWORD *)(v29 + 14820) )
    sub_500B60((float *)(v29 + 14824));
}
