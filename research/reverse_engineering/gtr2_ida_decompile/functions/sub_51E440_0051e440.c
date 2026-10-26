float *__thiscall sub_51E440(_DWORD *this, int a2)
{
  _DWORD *v2; // eax
  int v3; // ebx
  int v4; // edx
  unsigned __int16 *v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  float *v9; // eax
  float *v10; // ecx
  float *v11; // edx
  int v12; // eax
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  float *v16; // eax
  float *v17; // ecx
  float *v18; // edx
  int v19; // eax
  int v20; // ebx
  int v21; // eax
  int v22; // eax
  float *result; // eax
  float *v24; // ecx
  float *v25; // edx
  int v26; // [esp+10h] [ebp-8h]
  int v27; // [esp+14h] [ebp-4h]

  v2 = (_DWORD *)this[7];
  v3 = v2[26];
  v4 = (*v2 & 8) != 0 ? 0x8000 : 4096;
  v26 = v4;
  v27 = v3;
  if ( a2 >= *(_DWORD *)(v3 + 368) )
    v5 = 0;
  else
    v5 = (unsigned __int16 *)(*(_DWORD *)(v3 + 372) + 36 * a2);
  v6 = *((_DWORD *)v5 + 2);
  v7 = *v5;
  if ( (*(_BYTE *)v6 & 8) != 0 )
    v8 = 88 * v7;
  else
    v8 = v7 << 6;
  v9 = (float *)(*(_DWORD *)(v6 + 32) + v8);
  if ( v4 == 4096 )
  {
    v10 = v9 + 14;
    v11 = v9 + 15;
  }
  else
  {
    v10 = v9 + 20;
    v11 = v9 + 21;
  }
  *v10 = *v9 * 0.1;
  *v11 = v9[2] * 0.1;
  if ( a2 >= *(_DWORD *)(v3 + 368) )
    v12 = 0;
  else
    v12 = *(_DWORD *)(v3 + 372) + 36 * a2;
  v13 = *(_DWORD *)(v12 + 8);
  v14 = *(unsigned __int16 *)(v12 + 2);
  if ( (*(_BYTE *)v13 & 8) != 0 )
    v15 = 88 * v14;
  else
    v15 = v14 << 6;
  v16 = (float *)(*(_DWORD *)(v13 + 32) + v15);
  if ( v26 == 4096 )
  {
    v17 = v16 + 14;
    v18 = v16 + 15;
  }
  else
  {
    v17 = v16 + 20;
    v18 = v16 + 21;
  }
  *v17 = *v16 * 0.1;
  *v18 = v16[2] * 0.1;
  if ( a2 >= *(_DWORD *)(v27 + 368) )
    v19 = 0;
  else
    v19 = *(_DWORD *)(v27 + 372) + 36 * a2;
  v20 = *(_DWORD *)(v19 + 8);
  v21 = *(unsigned __int16 *)(v19 + 4);
  if ( (*(_BYTE *)v20 & 8) != 0 )
    v22 = 88 * v21;
  else
    v22 = v21 << 6;
  result = (float *)(*(_DWORD *)(v20 + 32) + v22);
  if ( v26 == 4096 )
  {
    v24 = result + 14;
    v25 = result + 15;
  }
  else
  {
    v24 = result + 20;
    v25 = result + 21;
  }
  *v24 = *result * 0.1;
  *v25 = result[2] * 0.1;
  return result;
}
