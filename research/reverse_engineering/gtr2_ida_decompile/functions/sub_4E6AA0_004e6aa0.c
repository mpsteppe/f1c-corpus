int __userpurge sub_4E6AA0@<eax>(int a1@<ecx>, int a2, int *a3, int a4, int a5, char a6, int a7)
{
  int v9; // ebx
  unsigned __int64 v10; // rax
  int v12; // eax
  int v13; // ebx
  void *v14; // esi
  int v15; // esi
  int v16; // esi
  int v17; // edi
  int v19; // [esp+10h] [ebp-3Ch]
  int v20; // [esp+20h] [ebp-2Ch] BYREF
  int v21; // [esp+24h] [ebp-28h] BYREF
  int v22; // [esp+28h] [ebp-24h]
  int v23[8]; // [esp+2Ch] [ebp-20h] BYREF
  int v24; // [esp+54h] [ebp+8h]
  int v25; // [esp+58h] [ebp+Ch]
  int v26; // [esp+58h] [ebp+Ch]
  int v27; // [esp+58h] [ebp+Ch]

  v21 = 0;
  v20 = 0;
  sub_5F0380(a2, &v21, &v20, 0);
  v9 = (unsigned __int64)((double)v21 * *(float *)(a4 + 152));
  v21 = v9;
  v10 = (unsigned __int64)((double)v20 * *(float *)(a4 + 156));
  v20 = v10;
  if ( v9 > 0 && (int)v10 > 0 )
  {
    v25 = *(_DWORD *)(a1 + 8);
    v12 = *a3;
    v13 = v25 - v9 / 2;
    *(float *)v23 = (float)v25;
    v26 = *(_DWORD *)(a1 + 12) - v12;
    *(float *)&v23[1] = (float)(v12 + v20 + 4);
    v23[3] = v23[0];
    v22 = v13;
    *(float *)&v23[4] = (double)v26 * 0.94999999 + (double)(v12 + 4);
    sub_5F5470((int)v23, -2002081110, (void *)1);
    *(float *)v23 = (float)(*(_DWORD *)(a1 + 8) - 1);
    sub_5F5470((int)v23, -2002081110, (void *)1);
    *(float *)v23 = (float)(*(_DWORD *)(a1 + 8) - 2);
    sub_5F5470((int)v23, -2002081110, (void *)1);
    *(float *)v23 = (float)(*(_DWORD *)(a1 + 8) - 3);
    sub_5F5470((int)v23, -2002081110, (void *)1);
    *(float *)v23 = (float)(*(_DWORD *)(a1 + 8) - 4);
    sub_5F5470((int)v23, -2002081110, (void *)1);
    *(float *)v23 = (float)(*(_DWORD *)(a1 + 8) - 5);
    sub_5F5470((int)v23, -1999844148, (void *)1);
    v14 = dword_B6E4C0;
    if ( dword_B6E4C0 )
    {
      sub_567D60(v13 - 4, *a3 - 4, 1, 0);
      ((void (__thiscall *)(void *, int, int))dword_567D40)(v14, v21 + 8, v20 + 8);
      sub_567E70(1728053247);
      sub_568750(v14, 0);
    }
    v15 = (unsigned __int64)(1.0 / *(float *)(a4 + 152) * (double)v22);
    v27 = (unsigned __int64)(1.0 / *(float *)(a4 + 156) * (double)*a3);
    v24 = *(_DWORD *)(a4 + 84);
    ((void (__thiscall *)(int, int))loc_5F0350)(a4, -1);
    sub_5F0DD0(a2, v15, v27, dword_FB2790, 0);
    ((void (__thiscall *)(int, int))loc_5F0350)(a4, v24);
    if ( a6 )
    {
      v16 = dword_B6E4C4;
      if ( dword_B6E4C4 )
      {
        v17 = v20 + 8;
        sub_4E6A40((int)byte_FFFFFF, -1, 0.0);
        sub_567D60(v13 + v21 + 5, *a3 - 4, 1, 0);
        ((void (__thiscall *)(int, int, int, int))dword_567D40)(v16, v17, v17, v19);
        sub_567E70(a7);
        sub_568750(v16, 0);
      }
    }
    LODWORD(v10) = v20 + 8 + *a3;
    *a3 = v10;
  }
  return v10;
}
