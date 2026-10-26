int __stdcall sub_6D7B30(int *a1, int a2, int a3, int a4)
{
  int v4; // esi
  int v5; // ebx
  int v6; // eax
  int v7; // edx
  int result; // eax
  int v9; // ecx
  unsigned __int8 *v10; // edi
  _BYTE *v11; // esi
  unsigned __int8 *v12; // ecx
  unsigned __int8 *v13; // edx
  unsigned __int8 *v14; // eax
  int v15; // eax
  int v16; // edx
  unsigned __int8 *v17; // ecx
  int v18; // eax
  unsigned __int8 *v19; // edx
  unsigned __int8 *v20; // eax
  unsigned __int8 *v21; // esi
  bool v22; // zf
  bool v23; // cc
  int v24; // [esp+Ch] [ebp-2Ch]
  int v25; // [esp+10h] [ebp-28h]
  int v26; // [esp+18h] [ebp-20h]
  int v27; // [esp+1Ch] [ebp-1Ch]
  unsigned __int8 *v28; // [esp+20h] [ebp-18h]
  int v29; // [esp+20h] [ebp-18h]
  int v30; // [esp+20h] [ebp-18h]
  unsigned __int8 *v31; // [esp+24h] [ebp-14h]
  int v32; // [esp+30h] [ebp-8h]
  int v33; // [esp+34h] [ebp-4h]
  _BYTE *v34; // [esp+34h] [ebp-4h]
  int v35; // [esp+40h] [ebp+8h]
  int v36; // [esp+44h] [ebp+Ch]
  unsigned __int8 *v37; // [esp+44h] [ebp+Ch]
  int v38; // [esp+48h] [ebp+10h]

  v4 = 8 * *(_DWORD *)(a2 + 28);
  v5 = a3 - 4;
  sub_6D75E0(16 * *(_DWORD *)(a2 + 28), a3 - 4, a3 - 4, a1[61] + 2, a1[7]);
  v6 = a1[48];
  v7 = 80 * v6;
  v38 = 16 * v6;
  result = *(_DWORD *)(a2 + 12);
  v35 = 0x4000 - v7;
  v9 = 0;
  v26 = 0;
  v24 = result;
  if ( result > 0 )
  {
    result = v5;
    v25 = v4 - 2;
    v27 = v5;
    do
    {
      v10 = *(unsigned __int8 **)(result + 4);
      v11 = *(_BYTE **)(a4 + 4 * v9);
      v12 = *(unsigned __int8 **)(result + 8);
      v13 = *(unsigned __int8 **)result;
      v14 = *(unsigned __int8 **)(result + 12);
      v36 = *v14;
      v32 = *v12;
      v33 = *v10;
      v28 = v14 + 2;
      v31 = v13 + 2;
      v15 = *v13 + v13[2] + 2 * (v36 + *v13 + v32 + v13[1] + v14[1] + v33 + v12[2] + v10[2]) + v14[2];
      v16 = v33 + v12[1] + v10[1];
      v17 = v12 + 2;
      v18 = v38 * (v36 + v15) + v35 * (v32 + v16) + 0x8000;
      v19 = v28;
      *v11 = BYTE2(v18);
      v20 = v10 + 2;
      v34 = v11 + 1;
      v21 = v31;
      v37 = v28;
      if ( v25 )
      {
        v29 = v25;
        do
        {
          *v34++ = (v38
                  * (v19[2]
                   + v21[2]
                   + *(v21 - 1)
                   + *(v19 - 1)
                   + 2 * (v20[2] + *v21 + v17[2] + *v19 + *(v20 - 1) + *(v17 - 1) + v21[1] + v19[1]))
                  + v35 * (*v20 + *v17 + v20[1] + (unsigned int)v17[1])
                  + 0x8000) >> 16;
          v19 = v37 + 2;
          v20 += 2;
          v17 += 2;
          v21 += 2;
          v22 = v29 == 1;
          v37 += 2;
          --v29;
        }
        while ( !v22 );
      }
      v30 = v19[1];
      *v34 = (v38
            * (v30
             + v21[1]
             + *(v37 - 1)
             + 2 * (v30 + v21[1] + v17[1] + *(v20 - 1) + *(v17 - 1) + v20[1] + *v19 + *v21)
             + *(v21 - 1))
            + v35 * (v17[1] + v20[1] + *v17 + (unsigned int)*v20)
            + 0x8000) >> 16;
      result = v27 + 8;
      v9 = v26 + 1;
      v23 = v26 + 1 < v24;
      v27 += 8;
      ++v26;
    }
    while ( v23 );
  }
  return result;
}
