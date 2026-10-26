int __userpurge sub_5D0E20@<eax>(int *a1@<ecx>, int a2@<edi>, int a3@<esi>, float a4)
{
  int v5; // ebx
  int v6; // edi
  int v7; // eax
  int *v8; // ecx
  int v9; // edx
  double v10; // st7
  int v11; // eax
  int v12; // ecx
  int v13; // ecx
  __int16 *v14; // eax
  int v15; // edx
  double v16; // st7
  int v17; // ecx
  int v18; // eax
  int *v19; // eax
  int v20; // ecx
  int v21; // edx
  int v23; // [esp+8h] [ebp-50h]
  float v24; // [esp+10h] [ebp-48h]
  int *v25; // [esp+14h] [ebp-44h]
  int v26; // [esp+18h] [ebp-40h]
  int v27; // [esp+20h] [ebp-38h]
  int v28; // [esp+30h] [ebp-28h] BYREF
  int v29; // [esp+34h] [ebp-24h]
  int v30; // [esp+38h] [ebp-20h]
  int v31; // [esp+3Ch] [ebp-1Ch]
  float v32[6]; // [esp+40h] [ebp-18h] BYREF

  v5 = 0;
  if ( a1[6] > 0 )
  {
    v26 = a2;
    do
    {
      v6 = *(_DWORD *)(a1[8] + 4 * v5);
      v7 = *(_DWORD *)(v6 + 48);
      if ( v7 )
      {
        v8 = *(int **)(v6 + 56);
        v9 = *v8;
        v10 = *(float *)&v8[4 * v7 - 1];
        v11 = v8[1];
        v12 = v8[2];
        v28 = v9;
        v25 = &v28;
        v30 = v12;
        v24 = v10 + a4;
        v29 = v11;
        sub_5CEE00();
        sub_5C62C0((int *)(v6 + 48));
      }
      v13 = *(_DWORD *)(v6 + 16);
      if ( v13 )
      {
        v14 = *(__int16 **)(v6 + 24);
        v27 = *v14;
        v15 = v14[2];
        v16 = *(float *)&v14[6 * v13 - 2];
        v17 = v14[1];
        v18 = v14[3];
        v32[0] = (double)v27 * 0.000030518509;
        v32[1] = (double)v17 * 0.000030518509;
        v32[2] = (double)v15 * 0.000030518509;
        v32[3] = (double)v18 * 0.000030518509;
        *(float *)&v23 = v16 + v32[5];
        sub_5CEDD0((_BYTE *)(v6 + 16), v23, v32);
        sub_5C61E0((int *)(v6 + 16));
      }
      if ( *(_DWORD *)(v6 + 80) )
      {
        v19 = *(int **)(v6 + 88);
        v20 = v19[1];
        v29 = *v19;
        v21 = v19[2];
        v30 = v20;
        v31 = v21;
        sub_5CEE00();
        sub_5C62C0((int *)(v6 + 80));
      }
      ++v5;
    }
    while ( v5 < a3 );
  }
  return (*(int (__thiscall **)(int *, float, int *, int))(*a1 + 20))(a1, COERCE_FLOAT(LODWORD(v24)), v25, v26);
}
