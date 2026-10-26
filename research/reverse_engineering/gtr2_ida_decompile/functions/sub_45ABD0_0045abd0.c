int __stdcall sub_45ABD0(int *a1, int a2)
{
  int v2; // edx
  int v3; // eax
  double v4; // st7
  int v5; // edx
  int v6; // ecx
  int v7; // eax
  int v9; // [esp+Ch] [ebp-28h]
  double v10[3]; // [esp+10h] [ebp-24h] BYREF
  int v11; // [esp+28h] [ebp-Ch]
  int v12; // [esp+2Ch] [ebp-8h]
  __int16 v13; // [esp+30h] [ebp-4h]

  v2 = a1[5];
  v3 = *a1;
  v10[0] = *(double *)(a1[1] + 24);
  v10[1] = *(double *)(a1[3] + 24);
  v4 = *(double *)(v2 + 24);
  v5 = a1[2];
  v10[2] = v4;
  v6 = *(_DWORD *)(v3 + 80);
  v7 = *(_DWORD *)(v5 + 80);
  v9 = *(_DWORD *)(a1[4] + 80);
  v11 = v6 + (v7 << 21);
  v13 = *((_WORD *)a1 + 13);
  v12 = (v9 << 10) + (v7 >> 11);
  (*(void (__thiscall **)(int, double *, int))(*(_DWORD *)a2 + 24))(a2, v10, 34);
  return sub_45A530();
}
