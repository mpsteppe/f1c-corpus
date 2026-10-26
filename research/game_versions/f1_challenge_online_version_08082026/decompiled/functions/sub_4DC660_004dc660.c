int __fastcall sub_4DC660(int a1, int a2, int a3, int a4, int a5, _DWORD *a6, int a7, int a8, int a9)
{
  int result; // eax
  int v11; // esi
  float v12; // ecx
  int v13; // edx
  int v14; // eax
  int v15; // ebx
  int v16; // ebp
  float v17; // [esp+8h] [ebp-8h]
  int v18; // [esp+Ch] [ebp-4h]

  result = a9;
  if ( !a9 )
  {
    result = dword_8B8DC8;
    a9 = dword_8B8DC8;
  }
  if ( a1 && a2 )
  {
    result = sub_53D1F0(a1);
    v11 = result;
    if ( result )
    {
      v12 = *(float *)(result + 92);
      v13 = *(_DWORD *)(result + 96);
      v14 = a5;
      v15 = *(_DWORD *)(v11 + 72);
      *(float *)(v11 + 92) = *(float *)&a7 * v12;
      v17 = v12;
      *(float *)(v11 + 96) = *(float *)&a8 * *(float *)(v11 + 96);
      v18 = v13;
      sub_552FC0(v14);
      v16 = sub_587BDC((double)a3 / *(float *)(v11 + 92));
      a3 = v16;
      a4 = sub_587BDC((double)a4 / *(float *)(v11 + 96));
      *(float *)&a8 = 0.0;
      *(float *)&a7 = 0.0;
      sub_5531F0(a2, &a8, &a7, 0);
      sub_4DC340(v16, a4, a8, a7, a6, &a3, &a4);
      sub_553070(a2, a3, a4, a9);
      result = v18;
      *(_DWORD *)(v11 + 72) = v15;
      *(float *)(v11 + 92) = v17;
      *(_DWORD *)(v11 + 96) = v18;
    }
  }
  return result;
}
