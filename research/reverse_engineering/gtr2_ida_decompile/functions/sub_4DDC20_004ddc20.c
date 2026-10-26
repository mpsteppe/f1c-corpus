void __stdcall sub_4DDC20(
        float a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14)
{
  int v15; // eax
  int v16; // edx
  int v17; // esi
  int v18; // edi
  float v19; // esi
  float v20; // ebp
  float v21; // [esp+0h] [ebp-4h]
  int v22; // [esp+8h] [ebp+4h]
  float v23; // [esp+8h] [ebp+4h]
  float v24; // [esp+8h] [ebp+4h]
  float v25; // [esp+8h] [ebp+4h]
  int v26; // [esp+14h] [ebp+10h]
  float v27; // [esp+14h] [ebp+10h]
  float v28; // [esp+18h] [ebp+14h]

  if ( a1 != 0.0 && dword_B6E2A4 && dword_B6E2AC )
  {
    v15 = *(_DWORD *)(LODWORD(a1) + 4);
    v16 = a5;
    v17 = a4;
    v22 = a4;
    v26 = a5;
    if ( v15 >= 1024 )
      v15 = 1024;
    v18 = *(_DWORD *)(LODWORD(a1) + 8);
    if ( v18 >= 1024 )
      v18 = 1024;
    if ( v17 >= 0 )
    {
      if ( v17 <= v15 )
        goto LABEL_13;
      v17 = v15;
    }
    else
    {
      v17 = 0;
    }
    v22 = v17;
LABEL_13:
    if ( a5 >= 0 )
    {
      if ( a5 <= v18 )
      {
LABEL_18:
        v21 = ((double)v22 - 0.5) * 0.0009765625;
        v28 = ((double)v26 - 0.5) * 0.0009765625;
        sub_5E7540(a2, a3, dword_B6E2A4, 0, 0, v17, v16, 1, 0, 0);
        v23 = (float)a8;
        v19 = v23;
        v27 = (float)a7;
        sub_5EDF20(dword_B6E2AC, 0, v27, v23, 1.0, 0.0, 0.0, a11);
        v24 = (double)a10 + v23;
        v20 = v24;
        sub_5EDF20(dword_B6E2AC, 1, v27, v24, 1.0, 0.0, v28, a12);
        v25 = (double)a9 + v27;
        sub_5EDF20(dword_B6E2AC, 2, v25, v20, 1.0, v21, v28, a13);
        sub_5EDF20(dword_B6E2AC, 3, v25, v19, 1.0, v21, 0.0, a14);
        sub_5EDDD0(a6, 0);
        return;
      }
      v16 = v18;
    }
    else
    {
      v16 = 0;
    }
    v26 = v16;
    goto LABEL_18;
  }
}
