int __thiscall sub_65B5D6(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *v4; // eax
  int v5; // esi
  int *v6; // edi
  int v7; // eax
  int v9; // edx
  bool v10; // zf
  _DWORD *v11; // ebx
  int v12; // esi
  char *v13; // edx
  unsigned int v14; // edi
  char v15; // cl
  _DWORD *v16; // edi
  int v17; // eax
  _DWORD *v18; // edi
  int *v19; // esi
  int v20; // eax
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  int v24; // eax
  int v25; // ebx
  int v26; // eax
  int v27; // esi
  int v28; // eax
  int v29; // eax
  _DWORD *v30; // esi
  int v31; // eax
  int v32; // edi
  char *v33; // edi
  int *v34; // ecx
  int v35; // eax
  char v36; // bl
  _DWORD *v37; // esi
  int v38; // eax
  _DWORD *v39; // ebx
  int v40; // eax
  int v41; // ecx
  int v42; // eax
  int v43; // ebx
  int v44; // eax
  int v45; // [esp-8h] [ebp-8Ch]
  char v46; // [esp+0h] [ebp-84h]
  _BYTE v47[56]; // [esp+Ch] [ebp-78h] BYREF
  _BYTE v48[32]; // [esp+44h] [ebp-40h] BYREF
  int *v49; // [esp+64h] [ebp-20h]
  int v50; // [esp+68h] [ebp-1Ch] BYREF
  int v51; // [esp+6Ch] [ebp-18h]
  int *v52; // [esp+70h] [ebp-14h]
  int v53; // [esp+74h] [ebp-10h]
  int v54; // [esp+78h] [ebp-Ch] BYREF
  int v55; // [esp+7Ch] [ebp-8h]
  _DWORD *v56; // [esp+80h] [ebp-4h]
  int *v57; // [esp+8Ch] [ebp+8h]
  int *v58; // [esp+8Ch] [ebp+8h]
  int v59; // [esp+90h] [ebp+Ch]
  int v60; // [esp+94h] [ebp+10h]
  int v61; // [esp+94h] [ebp+10h]
  char *v62; // [esp+94h] [ebp+10h]

  v50 = 0;
  v54 = 0;
  v4 = this;
  v56 = this;
  if ( !a3 )
  {
    v5 = a4;
    v6 = &v54;
    if ( a4 )
    {
      while ( 1 )
      {
        v7 = sub_65B229(48) ? sub_67EF22(v5 + 16) : 0;
        *v6 = v7;
        if ( !v7 )
          return 0;
        v5 = *(_DWORD *)(v5 + 12);
        v6 = (int *)(v7 + 12);
        if ( !v5 )
        {
          v4 = v56;
          break;
        }
      }
    }
    *v6 = v4[25];
    v4[25] = v54;
    return 1;
  }
  v9 = this[25];
  if ( v9 )
  {
    qmemcpy(this + 158, (const void *)(v9 + 16), 0x20u);
    v10 = this[158] == 1;
    v53 = (int)(this + 158);
    if ( !v10 )
      return 0;
    v51 = (int)(v56 + 160);
    if ( strcmp((const char *)v56 + 640, "(") )
      return 0;
    v11 = v56;
    v56[25] = *(_DWORD *)(v9 + 12);
    *(_DWORD *)(v9 + 12) = 0;
  }
  else
  {
    v12 = this[155];
    v13 = *(char **)v12;
    v14 = *(_DWORD *)(v12 + 4);
    if ( *(_DWORD *)v12 < v14 )
    {
      do
      {
        v15 = *v13;
        if ( *v13 != 32 && (v15 < 9 || v15 > 13) )
          break;
        ++v13;
      }
      while ( (unsigned int)v13 < *(_DWORD *)(v4[155] + 4) );
      if ( (unsigned int)v13 < v14 )
      {
        if ( *v13 != 40 )
          return 0;
        v4 = v56;
      }
    }
    v16 = v4 + 158;
    v45 = v4[166];
    v53 = (int)(v4 + 158);
    if ( (int)sub_65E7A1(v45, v4 + 158) < 0 )
      return 0;
    if ( *v16 != 1 )
      return 0;
    v51 = (int)(v56 + 160);
    if ( strcmp((const char *)v56 + 640, "(") )
      return 0;
    v11 = v56;
  }
  v52 = 0;
  v55 = 1;
  v49 = &v50;
  do
  {
    v17 = v11[25];
    v18 = (_DWORD *)v53;
    if ( v17 )
    {
      qmemcpy((void *)v53, (const void *)(v17 + 16), 0x20u);
      v18 = (_DWORD *)v53;
      v11[25] = *(_DWORD *)(v17 + 12);
      *(_DWORD *)(v17 + 12) = 0;
    }
    else
    {
      if ( (int)sub_65E7A1(v11[166], v53) < 0 )
        return 0;
      v11 = v56;
    }
    if ( *v18 == 13 )
    {
      sub_65DD1F((int)(v11 + 6), a2, 1515, "unexpected end of file in macro expansion", v46);
      return 0;
    }
    v19 = v49;
    if ( !*v49 )
    {
      if ( sub_65B229(20) )
        v20 = sub_67ED1B(0, 0, &off_737A94);
      else
        v20 = 0;
      *v49 = v20;
      if ( !v20 )
        return 0;
      v11 = v56;
      v52 = (int *)(v20 + 8);
    }
    if ( v55 == 1 && *v18 == 1 && (*(_BYTE *)v51 == 44 || *(_BYTE *)v51 == 41) && !*((_BYTE *)v11 + 641) )
    {
      v49 = (int *)(*v19 + 12);
    }
    else
    {
      if ( sub_65B229(48) )
        v21 = sub_67EF22(v18);
      else
        v21 = 0;
      *v52 = v21;
      if ( !v21 )
        return 0;
      v11 = v56;
      v52 = (int *)(v21 + 12);
    }
    if ( *v18 == 1 && !*((_BYTE *)v11 + 641) )
    {
      if ( *(_BYTE *)v51 != 40 )
      {
        if ( *(_BYTE *)v51 == 41 )
          goto LABEL_58;
        if ( *(_BYTE *)v51 != 91 )
        {
          if ( *(_BYTE *)v51 == 93 )
            goto LABEL_58;
          if ( *(_BYTE *)v51 != 123 )
          {
            if ( *(_BYTE *)v51 != 125 )
              continue;
LABEL_58:
            --v55;
            continue;
          }
        }
      }
      ++v55;
    }
  }
  while ( v55 );
  v22 = a3;
  v23 = v50;
  do
  {
    if ( !v23 )
      break;
    if ( !*(_DWORD *)(v23 + 8) )
      break;
    v22 = *(_DWORD *)(v22 + 12);
    v23 = *(_DWORD *)(v23 + 12);
  }
  while ( v22 );
  if ( !v22 && !v23 )
  {
    v57 = &v54;
    v24 = a4;
    v55 = 0;
    v53 = 0;
    v51 = 0;
    v49 = (int *)a4;
    if ( !a4 )
    {
LABEL_118:
      v58 = &v54;
      if ( v54 )
      {
        do
        {
          v41 = *(_DWORD *)(*v58 + 12);
          v59 = *v58;
          if ( v41 )
            v50 = *(_DWORD *)(v41 + 12);
          else
            v50 = 0;
          v42 = v41 != 0 ? v41 + 16 : 0;
          v43 = v50 != 0 ? v50 + 16 : 0;
          if ( v41 && v50 && *(_DWORD *)v42 == 1 && !strcmp((const char *)(v42 + 8), "##") )
          {
            v49 = (int *)(*(_DWORD *)(v50 != 0 ? v50 + 16 + 0x1C : 28) + *(_DWORD *)(v59 + 44));
            v62 = (char *)sub_67EB7E((int)v49, 1u);
            if ( !v62 )
              return 0;
            qmemcpy(v62, *(const void **)(v59 + 40), *(_DWORD *)(v59 + 44));
            qmemcpy(&v62[*(_DWORD *)(v59 + 44)], *(const void **)(v43 + 24), *(_DWORD *)(v43 + 28));
            sub_65D7E5(v47);
            if ( (int)sub_65D800(v62, v49, *(_DWORD *)(v59 + 32), *(_DWORD *)(v59 + 36), v56, v56 + 6) < 0
              || (int)sub_65E7A1(v56[166], v59 + 16) < 0 )
            {
              goto LABEL_133;
            }
            v44 = v50;
            *(_DWORD *)(v59 + 12) = *(_DWORD *)(v50 + 12);
            *(_DWORD *)(v44 + 12) = 0;
            nullsub_9(v47);
          }
          v58 = (int *)(*v58 + 12);
        }
        while ( *v58 );
        v11 = v56;
      }
      *v58 = v11[25];
      v11[25] = v54;
      return 1;
    }
    while ( 2 )
    {
      v25 = v24 + 16;
      v52 = v57;
      if ( !v55 && !v53 )
      {
        if ( *(_DWORD *)v25 == 1 && !strcmp((const char *)(v24 + 24), "#") )
        {
          v51 = v24 + 16;
          v55 = 1;
          goto LABEL_116;
        }
        if ( *(_DWORD *)v25 == 1 && !strcmp((const char *)(v24 + 24), "#@") )
        {
          v51 = v24 + 16;
          v53 = 1;
LABEL_116:
          v49 = (int *)v49[3];
          v24 = (int)v49;
          if ( !v49 )
          {
            v11 = v56;
            goto LABEL_118;
          }
          continue;
        }
      }
      break;
    }
    if ( *(_DWORD *)v25 != 9 )
      goto LABEL_138;
    v26 = a3;
    v60 = v50;
    do
    {
      if ( !strcmp(*(const char **)(v26 + 24), *(const char **)(v25 + 8)) )
        break;
      v26 = *(_DWORD *)(v26 + 12);
      v60 = *(_DWORD *)(v60 + 12);
    }
    while ( v26 );
    if ( v26 )
    {
      v27 = *(_DWORD *)(v60 + 8);
      while ( v27 )
      {
        if ( sub_65B229(48) )
          v28 = sub_67EF22(v27 + 16);
        else
          v28 = 0;
        *v57 = v28;
        if ( !v28 )
          return 0;
        v27 = *(_DWORD *)(v27 + 12);
        v57 = (int *)(v28 + 12);
      }
    }
    else
    {
LABEL_138:
      if ( sub_65B229(48) )
        v29 = sub_67EF22(v25);
      else
        v29 = 0;
      *v57 = v29;
      if ( !v29 )
        return 0;
      v57 = (int *)(v29 + 12);
    }
    if ( v55 || v53 )
    {
      v30 = (_DWORD *)*v52;
      v31 = 0;
      v32 = 1;
      while ( v30 )
      {
        if ( v31 && v31 != v30[10] )
          ++v32;
        v32 += sub_65B242((_BYTE *)v30[10], v30[11], 0);
        v31 = v30[11] + v30[10];
        v30 = (_DWORD *)v30[3];
      }
      v33 = (char *)sub_67EB7E(v32 + 1, 1u);
      if ( !v33 )
        return 0;
      v34 = v52;
      v35 = 0;
      v61 = 1;
      v36 = v55 == 0 ? 39 : 34;
      *v33 = v36;
      v37 = (_DWORD *)*v34;
      if ( *v34 )
      {
        do
        {
          if ( v35 && v35 != v37[10] )
          {
            v38 = v61++;
            v33[v38] = 32;
          }
          v61 += sub_65B242((_BYTE *)v37[10], v37[11], (int)&v33[v61]);
          v35 = v37[10] + v37[11];
          v37 = (_DWORD *)v37[3];
        }
        while ( v37 );
      }
      v33[v61] = v36;
      sub_65D7E5(v47);
      v39 = v56;
      if ( (int)sub_65D800(v33, v61 + 1, *(_DWORD *)(v51 + 16), *(_DWORD *)(v51 + 20), v56, v56 + 6) < 0
        || (int)sub_65E7A1(v39[166], v48) < 0
        || (!sub_65B229(48) ? (v40 = 0) : (v40 = sub_67EF22(v48)), (*v52 = v40) == 0) )
      {
LABEL_133:
        nullsub_9(v47);
        return 0;
      }
      v53 = 0;
      v55 = 0;
      v57 = (int *)(v40 + 12);
      nullsub_9(v47);
    }
    goto LABEL_116;
  }
  sub_65DD1F((int)(v11 + 6), a2, 1516, "not enough actual parameters for macro '%s'", *(_DWORD *)(a2 + 8));
  return 0;
}
