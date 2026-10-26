int __thiscall sub_45BD30(void *this, int *a2)
{
  int v3; // ecx
  unsigned int v4; // edx
  int v5; // eax
  int v6; // edx
  int *v7; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ebx
  int v12; // eax
  int v13; // esi
  unsigned __int8 v15; // c0
  unsigned __int8 v16; // c2
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v21; // eax
  int v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // eax
  int v26; // edx
  int v27; // eax
  unsigned __int8 v29; // c0
  unsigned __int8 v30; // c2
  int v31; // eax
  int v32; // eax
  int v33; // edx
  int v34; // eax
  unsigned __int8 v36; // c0
  unsigned __int8 v37; // c2
  int v38; // [esp+8h] [ebp-C8h]
  unsigned __int16 v39; // [esp+10h] [ebp-C0h] BYREF
  unsigned __int8 v40; // [esp+12h] [ebp-BEh]
  int v41; // [esp+14h] [ebp-BCh]
  int v42; // [esp+18h] [ebp-B8h]
  int v43; // [esp+1Ch] [ebp-B4h]
  int v44; // [esp+20h] [ebp-B0h]
  int v45; // [esp+28h] [ebp-A8h]
  int i; // [esp+2Ch] [ebp-A4h]
  int v47; // [esp+30h] [ebp-A0h]
  int v48; // [esp+38h] [ebp-98h]
  double v49; // [esp+3Ch] [ebp-94h]
  double v50; // [esp+44h] [ebp-8Ch] BYREF
  int v51; // [esp+4Ch] [ebp-84h]
  _BYTE v52[12]; // [esp+50h] [ebp-80h]
  int v53; // [esp+5Ch] [ebp-74h]
  int v54; // [esp+60h] [ebp-70h]
  int v55; // [esp+64h] [ebp-6Ch] BYREF

  v3 = *a2;
  HIDWORD(v49) = this;
  sub_458E90(v3, &v50);
  v4 = *(_DWORD *)(*a2 + 8);
  v5 = a2[1];
  *(_DWORD *)v52 = *(_DWORD *)*a2;
  *(_QWORD *)&v52[4] = __PAIR64__(*(_DWORD *)(v5 + 8), v4);
  v6 = *(_DWORD *)(v5 + 16);
  v7 = (int *)a2[2];
  v8 = v7[4];
  v53 = v6;
  v9 = *v7;
  v54 = v8;
  v55 = v9;
  v38 = (int)&v50;
  sub_45BC50();
  v10 = 0;
  v11 = 0;
  v12 = 2 - (_DWORD)&v39;
  v41 = 0;
  for ( i = 2 - (_DWORD)&v39; ; v12 = i )
  {
    *((_BYTE *)&v39 + v11) = 0;
    v13 = v11;
    v42 = (int)&v39 + v11 + v12;
    if ( v11 < v42 )
    {
      while ( 1 )
      {
        v49 = **(float **)(a2[v13 == 3 ? 0 : v13] + v10 + 4);
        if ( !(v15 | v16) )
          break;
        if ( ++v13 >= v42 )
          goto LABEL_8;
      }
      v17 = v41 + 1;
      *((_BYTE *)&v39 + v11) = 1;
      v41 = v17;
    }
LABEL_8:
    v10 += 8;
    ++v11;
    if ( v10 >= 24 )
      break;
  }
  v18 = 1;
  if ( v41 <= 1 )
  {
    if ( !v41 )
    {
      v13 = 0;
      while ( 1 )
      {
        v19 = v13 == 2 ? 0 : v13 + 1;
        if ( !sub_45BCB0((int)&a2[24 * v13 + 4], (int)&v55, *(_DWORD *)(a2[v13] + 8 * v19 + 4)) )
          break;
        if ( ++v13 >= 3 )
          return 4;
      }
      v39 = (unsigned __int16)&nullsub_12;
      v40 = (unsigned __int8)&nullsub_12;
      v11 = 3;
    }
    v21 = 0;
    i = 0;
    do
    {
      if ( !*((_BYTE *)&v39 + v21) )
        goto LABEL_43;
      if ( v21 )
      {
        v22 = v21 - 1;
        if ( v22 )
        {
          if ( v22 == 1 )
          {
            v44 = 3;
            v11 = 2;
            v13 = 0;
            v42 = v18;
          }
        }
        else
        {
          v13 = 2;
          v44 = 2;
          v11 = v18;
          v42 = 0;
        }
      }
      else
      {
        v44 = v18;
        v11 = 0;
        v13 = v18;
        v42 = 2;
      }
      switch ( v44 )
      {
        case 1:
          v43 = 0;
          v47 = v18;
          v45 = 2;
          break;
        case 2:
          v43 = v18;
          v47 = 2;
          v45 = 0;
          break;
        case 3:
          v23 = 2;
          v43 = 2;
          v47 = 0;
          v45 = v18;
          goto LABEL_34;
      }
      v23 = v43;
LABEL_34:
      v24 = a2[v23];
      v50 = *(double *)(v24 + 8 * v23);
      v51 = *(_DWORD *)(v24 + 8 * v47);
      v25 = a2[v45];
      *(_DWORD *)v52 = *(_DWORD *)(v25 + 8 * v23 + 4);
      v26 = *(_DWORD *)(v25 + 8 * v45);
      v27 = *(_DWORD *)(v25 + 8 * v23);
      *(_DWORD *)&v52[4] = v26;
      *(_DWORD *)&v52[8] = v27;
      sub_45BC50();
      *(double *)v52 = **(float **)(a2[v11] + 8 * v13 + 4);
      if ( v29 | v30 )
      {
        switch ( v41 )
        {
          case 1:
            v47 = 0;
            v42 = 1;
            v38 = 2;
            break;
          case 2:
            v47 = 1;
            v42 = 2;
            v38 = 0;
            break;
          case 3:
            v47 = 2;
            v42 = 0;
            v38 = 1;
            break;
        }
        v31 = a2[v42];
        v48 = *(_DWORD *)(v31 + 8 * v47);
        LODWORD(v49) = *(_DWORD *)(v31 + 8 * v47 + 4);
        HIDWORD(v49) = *(_DWORD *)(v31 + 8 * v42);
        v32 = a2[v38];
        LODWORD(v50) = *(_DWORD *)(v32 + 8 * v42);
        v33 = *(_DWORD *)(v32 + 8 * v38);
        v34 = *(_DWORD *)(v32 + 8 * v47 + 4);
        HIDWORD(v50) = v33;
        v51 = v34;
        sub_45BC50();
        v50 = **(float **)(a2[v13] + 8 * (_DWORD)&v55 + 4);
        if ( v36 | v37 )
          return v38;
      }
      v21 = v41;
      v18 = 1;
LABEL_43:
      v41 = ++v21;
    }
    while ( v21 < 3 );
  }
  return 0;
}
