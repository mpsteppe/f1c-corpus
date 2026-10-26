void __userpurge sub_5680F0(
        int a1@<ecx>,
        int a2@<edx>,
        int a3@<ebp>,
        int a4,
        float *a5,
        float a6,
        float a7,
        int a8,
        int a9,
        _DWORD *a10,
        int a11)
{
  _DWORD *v11; // edi
  int v13; // eax
  int v14; // esi
  int v15; // eax
  float v16; // [esp+8h] [ebp-20h]
  float v17; // [esp+Ch] [ebp-1Ch]
  float v18; // [esp+Ch] [ebp-1Ch]
  int v19; // [esp+20h] [ebp-8h]
  int v20; // [esp+24h] [ebp-4h]

  v11 = a10;
  if ( !a10 )
    v11 = dword_FB2790;
  if ( a1 )
  {
    if ( a2 )
    {
      v13 = sub_5F04C0(dword_FB1CE0, a1);
      v14 = v13;
      if ( v13 )
      {
        v20 = *(_DWORD *)(v13 + 156);
        v19 = *(_DWORD *)(v13 + 152);
        v15 = a9;
        v17 = a6;
        *(_DWORD *)(v14 + 152) = a8;
        *(_DWORD *)(v14 + 156) = v15;
        ((void (__thiscall *)(int, _DWORD, int))loc_5F0350)(v14, LODWORD(v17), a3);
        if ( v11 )
          a11 = v11[1];
        else
          a11 = *(_DWORD *)dword_903EB8;
        a7 = (float)a11;
        if ( v11 )
          a9 = v11[2];
        else
          a9 = dword_903EBC;
        a10 = 0;
        a11 = 0;
        sub_5F0380(a2, &a10, &a11, 1);
        v18 = (double)a11 / (double)a9;
        v16 = (double)(int)a10 / a7;
        sub_567AA0(a8, (float *)&a5, a5, a6, v16, v18, &a6);
        sub_5F10F0(a2, *(float *)&a5, a6, (int)v11, 64);
        ((void (__thiscall *)(int))loc_5F0350)(v14);
        *(_DWORD *)(v14 + 152) = v19;
        *(_DWORD *)(v14 + 156) = v20;
      }
    }
  }
}
