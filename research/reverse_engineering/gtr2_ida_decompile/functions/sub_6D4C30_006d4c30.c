int __stdcall sub_6D4C30(_DWORD *a1, int a2)
{
  int *v3; // ecx
  int v4; // edx
  int v5; // ecx
  _DWORD *v6; // eax
  _DWORD *v7; // edi
  int v8; // edx
  int v9; // ecx
  int result; // eax
  int v11; // ebx
  int v12; // edx
  _DWORD *v13; // ecx
  int v14; // esi
  int v15; // edx
  int v16; // ecx
  int v17; // edx
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  int v21; // [esp+8h] [ebp-2Ch] BYREF
  int v22; // [esp+Ch] [ebp-28h]
  int v23; // [esp+10h] [ebp-24h]
  int v24; // [esp+14h] [ebp-20h]
  int v25; // [esp+18h] [ebp-1Ch] BYREF
  int v26; // [esp+1Ch] [ebp-18h]
  int v27; // [esp+20h] [ebp-14h]
  int v28; // [esp+24h] [ebp-10h]
  _DWORD *v29; // [esp+28h] [ebp-Ch]
  int *v30; // [esp+2Ch] [ebp-8h]
  _DWORD *v31; // [esp+30h] [ebp-4h]
  _DWORD *v32; // [esp+3Ch] [ebp+8h]

  v3 = (int *)a1[6];
  v4 = *v3;
  v5 = v3[1];
  v6 = (_DWORD *)a1[93];
  v21 = v4;
  v22 = v5;
  v7 = v6 + 3;
  v23 = v6[3];
  v24 = v6[4];
  v25 = v6[5];
  v26 = v6[6];
  v8 = v6[8];
  v27 = v6[7];
  v9 = a1[50];
  v31 = v6;
  v28 = v8;
  v29 = a1;
  if ( v9 && !v6[9] )
  {
    result = sub_6D4B60(&v21, v6[10]);
    if ( !result )
      return result;
    v6 = v31;
  }
  v11 = 0;
  if ( (int)a1[70] <= 0 )
  {
LABEL_9:
    v13 = (_DWORD *)a1[6];
    v14 = a1[50];
    *v13 = v21;
    v13[1] = v22;
    v15 = v24;
    *v7 = v23;
    v16 = v25;
    v7[1] = v15;
    v17 = v26;
    v7[2] = v16;
    v18 = v27;
    v7[3] = v17;
    v19 = v28;
    v7[4] = v18;
    v7[5] = v19;
    if ( v14 )
    {
      if ( !v6[9] )
      {
        v20 = ((unsigned __int8)v6[10] + 1) & 7;
        v6[9] = v14;
        v6[10] = v20;
      }
      --v6[9];
    }
    return 1;
  }
  else
  {
    v32 = a1 + 71;
    while ( 1 )
    {
      v12 = a1[*v32 + 64];
      v30 = &v25 + *v32;
      if ( !sub_6D49D0(
              (int)&v21,
              *(__int16 **)(a2 + 4 * v11),
              *v30,
              v6[*(_DWORD *)(v12 + 20) + 11],
              v6[*(_DWORD *)(v12 + 24) + 15]) )
        return 0;
      *v30 = **(__int16 **)(a2 + 4 * v11++);
      v6 = v31;
      ++v32;
      if ( v11 >= a1[70] )
        goto LABEL_9;
    }
  }
}
