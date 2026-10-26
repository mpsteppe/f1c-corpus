int __userpurge sub_438B80@<eax>(int a1@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>, int a5)
{
  int result; // eax
  int v7; // edx
  int v8; // edi
  int v9; // ebp
  float *v10; // ebx
  int v11; // eax
  float *v12; // eax
  double v13; // st7
  int v14; // eax
  int v15; // edi
  int v16; // ebp
  float *v17; // eax
  double v18; // st7
  double v19; // st6
  int v20; // [esp+1Ch] [ebp-84h]
  int v21; // [esp+20h] [ebp-80h]
  int v22; // [esp+20h] [ebp-80h]
  float v23; // [esp+24h] [ebp-7Ch]
  int v24; // [esp+24h] [ebp-7Ch]
  int v25; // [esp+24h] [ebp-7Ch]
  int v26; // [esp+24h] [ebp-7Ch]
  float v27; // [esp+28h] [ebp-78h]
  int v28; // [esp+28h] [ebp-78h]
  int v29; // [esp+28h] [ebp-78h]
  int v30; // [esp+28h] [ebp-78h]
  int v31; // [esp+2Ch] [ebp-74h] BYREF
  int v32; // [esp+30h] [ebp-70h] BYREF
  int v33; // [esp+34h] [ebp-6Ch]
  float v34; // [esp+38h] [ebp-68h]
  float v35; // [esp+3Ch] [ebp-64h]
  float v36; // [esp+40h] [ebp-60h]
  int v37; // [esp+54h] [ebp-4Ch]
  int v38; // [esp+58h] [ebp-48h]
  int v39; // [esp+5Ch] [ebp-44h]
  int v40; // [esp+60h] [ebp-40h]
  _BYTE v41[4]; // [esp+64h] [ebp-3Ch] BYREF
  _BYTE v42[4]; // [esp+70h] [ebp-30h] BYREF
  float v43; // [esp+74h] [ebp-2Ch] BYREF

  result = *(_DWORD *)(a1 + 12);
  if ( result && *(_DWORD *)(result + 180) )
  {
    v7 = *(_DWORD *)(a1 + 44);
    v37 = *(_DWORD *)(result + 192);
    v8 = sub_46B2B0(result + 180, v7 - 1, a4, a3, a2);
    v9 = sub_46B2B0(*(_DWORD *)(a1 + 12) + 180, *(_DWORD *)(a1 + 44), v33, LODWORD(v34), LODWORD(v35));
    v10 = (float *)sub_46B2B0(*(_DWORD *)(a1 + 12) + 180, *(_DWORD *)(a1 + 44) + 1, v32, v33, LODWORD(v34));
    if ( v8 && v9 )
      v35 = (*(float *)(v9 + 24) - *(float *)(*(_DWORD *)(a1 + 12) + 192))
          / (*(float *)(v9 + 24) - *(float *)(v8 + 24))
          * *(float *)(a1 + 48);
    v11 = *(_DWORD *)(a1 + 28);
    v38 = 0;
    v39 = 0;
    v40 = 0;
    if ( v11 < 0 || *(int *)(a1 + 24) < 0 || v11 >= dword_757C10 || *(_DWORD *)(a1 + 4) == 5 )
    {
      if ( sub_46B2B0(*(_DWORD *)(a1 + 12) + 180, 4, v31, v32, v33)
        && sub_46B2B0(*(_DWORD *)(a1 + 12) + 180, 4, v28, v31, v32) )
      {
        v15 = sub_46B2B0(*(_DWORD *)(a1 + 12) + 180, 4, v24, v29, v31);
        v16 = sub_46B2B0(*(_DWORD *)(a1 + 12) + 180, 4, v21, v25, v30);
        v17 = (float *)sub_46B2B0(*(_DWORD *)(a1 + 12) + 180, 4, v20, v22, v26);
        v18 = -*(float *)(v15 + 8);
        v19 = -*(float *)(v16 + 4);
        v34 = -*v17;
        v35 = v19;
        v36 = v18;
      }
      else
      {
        sub_4035C0();
      }
    }
    else
    {
      sub_5690F0(*(&dword_91E088 + v11) + 2704, v42, v41, v31);
      sub_4035C0();
      if ( v10 )
      {
        v12 = sub_409350(v10, &v43);
        v34 = *v12;
        v35 = v12[1];
        v36 = v12[2];
      }
      sub_46B1F0(&v31, &v32);
      v13 = v23;
      if ( v23 < (double)*(float *)(a1 + 16) )
      {
        v13 = v13 + dbl_FB1D10 * 20.0;
        if ( v13 > *(float *)(a1 + 16) )
          v13 = *(float *)(a1 + 16);
      }
      v14 = *(_DWORD *)(a1 + 12);
      *(float *)(v14 + 56) = v13;
      *(float *)(v14 + 60) = v27;
    }
    return off_16C975C(*(_DWORD *)(a1 + 12), a5);
  }
  return result;
}
