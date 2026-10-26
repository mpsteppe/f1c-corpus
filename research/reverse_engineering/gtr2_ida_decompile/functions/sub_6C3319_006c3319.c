int __thiscall sub_6C3319(int this, int a2)
{
  int v2; // edi
  unsigned int v3; // esi
  int result; // eax
  int v5; // eax
  _DWORD *v6; // ecx
  _DWORD *v7; // eax
  bool v8; // zf
  _DWORD *v9; // eax
  char *v10; // ebx
  char *v11; // ecx
  int v12; // edx
  void *v13; // edi
  int v14; // esi
  int v15; // eax
  int *v16; // ecx
  int v17; // edi
  int v18; // ecx
  int v19; // edi
  _DWORD *v20; // edx
  int v21; // eax
  int v22; // ecx
  unsigned int v23; // eax
  _DWORD *v24; // ecx
  bool v25; // cf
  void *v26; // ecx
  int v27; // edi
  int *v28; // [esp-20h] [ebp-140h]
  _BYTE v29[16]; // [esp+Ch] [ebp-114h] BYREF
  char v30; // [esp+1Ch] [ebp-104h] BYREF
  char v31[16]; // [esp+2Ch] [ebp-F4h] BYREF
  _DWORD v32[28]; // [esp+3Ch] [ebp-E4h] BYREF
  _DWORD v33[16]; // [esp+ACh] [ebp-74h] BYREF
  int v34[4]; // [esp+ECh] [ebp-34h] BYREF
  unsigned int v35; // [esp+FCh] [ebp-24h]
  int v36; // [esp+100h] [ebp-20h]
  char *v37; // [esp+104h] [ebp-1Ch]
  int v38; // [esp+108h] [ebp-18h]
  _BYTE *v39; // [esp+10Ch] [ebp-14h]
  unsigned int v40; // [esp+110h] [ebp-10h]
  unsigned int v41; // [esp+114h] [ebp-Ch] BYREF
  unsigned int v42; // [esp+118h] [ebp-8h]
  _DWORD *v43; // [esp+11Ch] [ebp-4h]

  v41 = 0;
  v34[0] = 0;
  v2 = this;
  v3 = **(_DWORD **)(this + 256) & 0xFFFFF;
  v28 = *(int **)(this + 256);
  v36 = this;
  v34[1] = 1;
  v34[2] = 2;
  v34[3] = 3;
  v35 = v3;
  if ( sub_6BB35B((_DWORD *)this, v28, dword_7459B0, (char *)v33, &v41, (int)v29, v34, v3, a2)
    && sub_6BB35B((_DWORD *)v2, *(int **)(v2 + 256), dword_745A10, (char *)v33, &v41, (int)v29, v34, v3, a2) )
  {
    return 1;
  }
  v40 = 0;
  v39 = v29;
  v37 = &v30;
  while ( 1 )
  {
    v42 = 0;
    if ( v3 )
    {
      v38 = (int)(*(_DWORD *)(v2 + 108) << 6) >> 31;
      v43 = v39;
      while ( 1 )
      {
        v5 = *(_DWORD *)(v2 + 20);
        v6 = *(_DWORD **)(v5 + 4 * *v43);
        v7 = *(_DWORD **)(v5 + 4 * v32[v42]);
        if ( v38 )
        {
          if ( (v6[15] ^ v7[15]) != 0x80000 )
            break;
          v8 = v7[14] == *v43;
        }
        else
        {
          if ( v6[1] != v7[1] || v6[2] != v7[2] || v6[3] != v7[3] || v6[4] != v7[4] )
            break;
          v8 = (v6[15] ^ v7[15]) == 0x80000;
        }
        if ( v8 )
        {
          ++v42;
          ++v43;
          if ( v42 < v3 )
            continue;
        }
        break;
      }
    }
    if ( v42 != v3 )
      goto LABEL_37;
    v9 = (_DWORD *)sub_681186(116);
    if ( v9 )
      v10 = (char *)sub_680CEC(v9);
    else
      v10 = 0;
    if ( !v10 )
      return -2147024882;
    v43 = (_DWORD *)sub_6811D1(v10, v3 & 0xFFFFF | 0x70100000, 3 * v3, v3, 0);
    v11 = v10;
    if ( (int)v43 < 0 )
      goto LABEL_42;
    v43 = (_DWORD *)sub_680D22(v10, *(_DWORD *)(v2 + 256));
    if ( (int)v43 < 0 )
    {
      v11 = v10;
LABEL_42:
      sub_66238F(v11, 1);
      return (int)v43;
    }
    qmemcpy(*((void **)v10 + 4), *(const void **)(*(_DWORD *)(v2 + 256) + 16), 4 * v3);
    qmemcpy(*((void **)v10 + 2), v31, 4 * v3);
    qmemcpy((void *)(4 * v3 + *((_DWORD *)v10 + 2)), v37, 4 * v3);
    v12 = 2 * v35;
    v13 = (void *)(8 * v35 + *((_DWORD *)v10 + 2));
    v42 = 0;
    qmemcpy(v13, v32, 4 * v3);
    v14 = v36;
    v15 = *(_DWORD *)(v36 + 20);
    v43 = *(_DWORD **)(v15 + 4 * **((_DWORD **)v10 + 4));
    v16 = (int *)*((_DWORD *)v10 + 2);
    v17 = *v16;
    v18 = v16[v12];
    v19 = *(_DWORD *)(v15 + 4 * v17);
    v20 = v43;
    v21 = *(_DWORD *)(v15 + 4 * v18);
    v22 = v43[1];
    if ( v22 != *(_DWORD *)(v19 + 4) )
      goto LABEL_27;
    if ( v43[3] != *(_DWORD *)(v19 + 12) )
    {
      v20 = v43;
LABEL_27:
      if ( (v22 != *(_DWORD *)(v21 + 4) || v20[3] != *(_DWORD *)(v21 + 12)) && v22 == *(_DWORD *)(v36 + 136) )
        goto LABEL_32;
    }
    if ( (*(_BYTE *)(v36 + 111) & 2) == 0 )
      v42 = 1;
LABEL_32:
    if ( !(*(int (__thiscall **)(int, char *, _DWORD))(*(_DWORD *)v36 + 32))(v36, v10, 0)
      && ((*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v14 + 16) + 4 * v43[1]) + 4) & 0x20) == 0 && !v42
       || (*(_BYTE *)(v14 + 111) & 2) != 0) )
    {
      break;
    }
    sub_66238F(v10, 1);
    v3 = v35;
    v2 = v36;
LABEL_37:
    ++v40;
    v39 += 16;
    v37 -= 16;
    if ( v40 >= 2 )
      return 1;
  }
  if ( !a2 )
  {
    v38 = *(_DWORD *)v33[0];
    *(_DWORD *)v33[0] = 0;
  }
  if ( (*(_BYTE *)(v14 + 111) & 2) != 0
    && (*(_BYTE *)(v19 + 61) & 2) == 0
    && ((*(_DWORD *)v19 & 4) == 0 || (*(_DWORD *)v19 & 0x10) == 0) )
  {
    sub_66238F(v10, 1);
    sub_686816(
      v14,
      *(_DWORD *)(*(_DWORD *)(v14 + 256) + 60),
      (const char *)0x125F,
      "cannot match lerp because lerp factor is not _sat'd");
    *(_DWORD *)v33[0] = v38;
    return 1;
  }
  if ( !a2 )
  {
    v23 = 0;
    if ( v41 )
    {
      do
      {
        v24 = (_DWORD *)v33[v23++];
        v25 = v23 < v41;
        *v24 = 0;
      }
      while ( v25 );
    }
    v26 = *(void **)(*(_DWORD *)(v14 + 24) + 4 * *(_DWORD *)(v14 + 252));
    if ( v26 )
      sub_66238F(v26, 1);
    *(_DWORD *)(*(_DWORD *)(v14 + 24) + 4 * *(_DWORD *)(v14 + 252)) = v10;
    return 0;
  }
  v27 = sub_681430(*(char **)(v14 + 256), v10);
  sub_66238F(v10, 1);
  if ( v27 < 0 )
    return v27;
  result = sub_680D22(*(_DWORD **)(v14 + 256), *(_DWORD *)(v14 + 256));
  if ( result >= 0 )
    return 0;
  return result;
}
