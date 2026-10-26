char __thiscall sub_4612C0(int this)
{
  _DWORD *v1; // ebp
  char result; // al
  char *v3; // ebx
  char *v4; // esi
  int v5; // edi
  const char *v6; // eax
  const char *v7; // eax
  signed int v8; // edi
  bool v9; // cc
  int v10; // edi
  _DWORD *v11; // esi
  int v12; // eax
  char *v13; // ebx
  char *v14; // esi
  int v15; // eax
  const char *v16; // esi
  const char **v17; // eax
  const char *v18; // edi
  int v19; // eax
  const char **v20; // eax
  int v21; // esi
  int v22; // eax
  int v23; // eax
  int v24; // [esp+0h] [ebp-160h]
  char v25; // [esp+8h] [ebp-158h]
  char i; // [esp+18h] [ebp-148h]
  char v27; // [esp+19h] [ebp-147h]
  char v28; // [esp+1Ah] [ebp-146h]
  char v29; // [esp+1Bh] [ebp-145h]
  int ArgList; // [esp+1Ch] [ebp-144h]
  char ArgLista[4]; // [esp+1Ch] [ebp-144h]
  char *v32; // [esp+20h] [ebp-140h]
  const char *v33; // [esp+20h] [ebp-140h]
  char v34[4]; // [esp+24h] [ebp-13Ch]
  char v35[4]; // [esp+24h] [ebp-13Ch]
  size_t v36; // [esp+28h] [ebp-138h]
  char v38[48]; // [esp+30h] [ebp-130h] BYREF
  char Buffer[256]; // [esp+60h] [ebp-100h] BYREF

  v1 = (_DWORD *)this;
  result = *(_BYTE *)(this + 636);
  if ( !result )
  {
    memset(v38, 0, sizeof(v38));
    i = 0;
    v27 = 0;
    v29 = 0;
    v36 = 0;
    *(_DWORD *)v34 = 0;
    if ( *(int *)(this + 6512) > 0 )
    {
      v3 = (char *)(this + 788);
      v32 = (char *)(this + 788);
      do
      {
        if ( (unsigned __int8)sub_462C60(2) && strlen(v3) )
        {
          ArgList = v3[64];
          v4 = (char *)&unk_62BF68 + 25304 * ArgList;
          v5 = *((_DWORD *)v4 + 474);
          v28 = 0;
          v6 = (const char *)sub_4EDED0(v4);
          if ( _strcmpi(v6, v3) || !v5 || *((_DWORD *)v4 + 4146) == -1 )
          {
            sub_4EED10(v3);
            sub_50B240(v3 + 32);
            v7 = (const char *)sub_4EDED0(v4);
            if ( !_strcmpi(v7, v3) || !v5 )
            {
              sub_45D3D0(&v1[14 * ArgList + 7538]);
              sub_52E5C0(&v1[106 * ArgList + 1735]);
              sub_45DDD0(v1 + 6929, ArgList);
              if ( ArgList == sub_463B80(*v1) )
              {
                if ( !*((_DWORD *)v4 + 5223) || *((_DWORD *)v4 + 4146) == -1 )
                  sub_51BC20(0, 0);
                sub_42DC00(ArgList);
              }
              else
              {
                sub_51BC20(2, 0);
              }
              sub_4DEB20(ArgList + 1);
              sub_4DD140(v4 + 20836);
              if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 4592) )
                sub_500FE0((int)&unk_7D7920, aLoadingSlotInd, ArgList);
              ++NumOfElements;
              sub_42DC40();
              sub_4EE0B0(v4, 1);
              sub_4EE160(COERCE_FLOAT(1));
              v24 = *((_DWORD *)v4 + 6312);
              *((_DWORD *)v4 + 6316) = v24;
              sub_4BF8E0(v24, v4);
              if ( *((_DWORD *)v4 + 4146) )
              {
                v28 = 1;
                v27 = 1;
                sub_46D160(*((_DWORD *)v4 + 6312), v3[65]);
              }
              else
              {
                if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 4618) )
                  sub_500FE0((int)&unk_7D7920, aSlotIsTaggedAs, v25);
                v8 = 0;
                for ( i = 1; v8 < (int)NumOfElements; ++v8 )
                  sub_50B4E0(0, 1);
                sub_42DB60(ArgList);
                sub_40C3F0((_DWORD **)&dword_6291CC);
                sub_4B4210(&unk_765E90);
              }
              sub_4365F0((const char **)&dword_75E8F0, *((_DWORD *)v4 + 6312));
              byte_7DA994 = 0;
            }
          }
          if ( strcmp(v4 + 24772, v32 - 32) )
            sub_4EDDD0(v32 - 32);
          if ( v28 )
          {
            if ( sub_41F230(dword_62A170, aHasEnteredTheG, Destination) )
            {
              strncpy(Destination, aHasEnteredTheG, 0x1FFu);
              byte_62A37B = 0;
            }
            sprintf(Buffer, "%s %s", v4 + 24772, Destination);
            sub_45D100(&byte_764D68, (int)Buffer, 3, 16909060, 0);
          }
          v3 = v32;
          v1 = (_DWORD *)this;
          ++v36;
          v38[ArgList] = 1;
        }
        v3 += 116;
        v9 = ++*(_DWORD *)v34 < v1[1628];
        v32 = v3;
      }
      while ( v9 );
    }
    v10 = 0;
    v11 = &unk_632108;
    *(_DWORD *)ArgLista = 0;
    *(_DWORD *)v35 = 0;
    v33 = (const char *)&unk_632108;
    do
    {
      if ( !v38[v10] )
      {
        v12 = *(v11 - 2102);
        v13 = (char *)(v11 - 6248);
        v14 = (char *)(v11 - 55);
        if ( v12 != -1 )
        {
          if ( sub_41F230(dword_62A170, aLeftTheGame, Destination) )
          {
            strncpy(Destination, aLeftTheGame, 0x1FFu);
            byte_62A37B = 0;
          }
          sprintf(Buffer, "%s %s", v14, Destination);
          sub_45D100(&byte_764D68, (int)Buffer, 3, 16909060, 0);
          if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 4700) )
            sub_500FE0((int)&unk_7D7920, aUnloadingSlotI, *((_DWORD *)v14 + 119));
          v15 = v1[1680];
          v29 = 1;
          if ( v15 == 2 || v15 == 1 )
          {
            v16 = &v33[strlen(v33)];
            if ( v16 > v33 )
            {
              while ( *v16 != 92 )
              {
                if ( --v16 <= v33 )
                  goto LABEL_52;
              }
              ++v16;
            }
LABEL_52:
            v17 = (const char **)v1[1681];
            v1[1683] = v17;
            if ( v17 )
            {
              v18 = *v17;
              if ( *v17 )
              {
                while ( _strcmpi(v18, v16) )
                {
                  v19 = v1[1683];
                  if ( v19 )
                    v1[1683] = *(_DWORD *)(v19 + 4);
                  v20 = (const char **)v1[1683];
                  if ( v20 )
                  {
                    v18 = *v20;
                    if ( *v20 )
                      continue;
                  }
                  goto LABEL_75;
                }
                if ( v18 )
                {
                  v21 = v1[1681];
                  v22 = 0;
                  if ( v21 )
                  {
                    while ( *(const char **)v21 != v18 )
                    {
                      v22 = v21;
                      v21 = *(_DWORD *)(v21 + 4);
                      if ( !v21 )
                        goto LABEL_75;
                    }
                    if ( v21 == v1[1683] )
                      v1[1683] = *(_DWORD *)(v21 + 4);
                    if ( v22 )
                      *(_DWORD *)(v22 + 4) = *(_DWORD *)(v21 + 4);
                    else
                      v1[1681] = *(_DWORD *)(v21 + 4);
                    if ( v1[1682] == v21 )
                      v1[1682] = v22;
                    --v1[1684];
                    if ( *(_BYTE *)(v21 + 8) )
                      sub_5BE8AE(*(LPVOID *)v21);
                    sub_5BE8AE((LPVOID)v21);
                  }
                }
              }
            }
          }
LABEL_75:
          sub_4EE280(v13);
          sub_51BC20(-1, 0);
          v10 = *(_DWORD *)v35;
          ++*(_DWORD *)ArgLista;
          if ( *(_DWORD *)(dword_75AAD0[dword_75AAC0] + 25248) == *(_DWORD *)v35 )
          {
            if ( dword_630030[6326 * *(_DWORD *)(dword_75AAD0[dword_75AAC8] + 25248)] == -1 )
            {
              v23 = 0;
              if ( (int)NumOfElements > 0 )
              {
                while ( *(_DWORD *)(dword_75AAD0[v23] + 16584) == -1 )
                {
                  if ( ++v23 >= (int)NumOfElements )
                    goto LABEL_83;
                }
                sub_42DB40(v23);
              }
            }
            else
            {
              sub_42DB60(*(_DWORD *)(dword_75AAD0[dword_75AAC8] + 25248));
            }
          }
LABEL_83:
          if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 4753) )
            sub_500FE0((int)&unk_7D7920, aUnsettingSlotI, v35[0]);
        }
      }
      v11 = v33 + 25304;
      ++v10;
      v9 = (int)(v33 + 25304) < (int)&unk_75A988;
      *(_DWORD *)v35 = v10;
      v33 += 25304;
    }
    while ( v9 );
    if ( *(int *)ArgLista > 0 )
    {
      sub_462430(1);
      NumOfElements -= *(_DWORD *)ArgLista;
      sub_42DC40();
    }
    if ( v1[1680] != 1 )
    {
      if ( i )
        sub_4F0220(0, 1065353216);
      if ( v27 )
        sub_4F0220(1, 1065353216);
      if ( v29 )
        sub_4F0220(2, 1065353216);
    }
    result = v36;
    if ( v36 != NumOfElements )
    {
      NumOfElements = v36;
      return sub_42DC40();
    }
  }
  return result;
}
