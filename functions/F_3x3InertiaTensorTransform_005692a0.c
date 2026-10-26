int __thiscall sub_5692A0(int this)
{
  double v1; // st7
  double v2; // st6
  double v3; // st5
  int result; // eax
  double v5; // [esp+18h] [ebp-30h]
  double v6; // [esp+20h] [ebp-28h]
  double v7; // [esp+28h] [ebp-20h]
  double v8; // [esp+30h] [ebp-18h]
  double v9; // [esp+38h] [ebp-10h]
  double v10; // [esp+40h] [ebp-8h]

  v1 = *(double *)(this + 28) * *(double *)(this + 212);
  v2 = *(double *)(this + 220) * *(double *)(this + 36);
  v3 = *(double *)(this + 44) * *(double *)(this + 228);
  v5 = *(double *)(this + 52) * *(double *)(this + 212);
  v6 = *(double *)(this + 220) * *(double *)(this + 60);
  v7 = *(double *)(this + 68) * *(double *)(this + 228);
  v8 = *(double *)(this + 76) * *(double *)(this + 212);
  v9 = *(double *)(this + 220) * *(double *)(this + 84);
  v10 = *(double *)(this + 92) * *(double *)(this + 228);
  *(double *)(this + 236) = v3 * *(double *)(this + 44) + v1 * *(double *)(this + 28) + v2 * *(double *)(this + 36);
  *(double *)(this + 244) = v2 * *(double *)(this + 60) + v3 * *(double *)(this + 68) + v1 * *(double *)(this + 52);
  *(double *)(this + 252) = v3 * *(double *)(this + 92) + v1 * *(double *)(this + 76) + v2 * *(double *)(this + 84);
  *(_DWORD *)(this + 260) = *(_DWORD *)(this + 244);
  *(_DWORD *)(this + 264) = *(_DWORD *)(this + 248);
  *(double *)(this + 268) = v6 * *(double *)(this + 60) + v7 * *(double *)(this + 68) + v5 * *(double *)(this + 52);
  *(double *)(this + 276) = v7 * *(double *)(this + 92) + v5 * *(double *)(this + 76) + v6 * *(double *)(this + 84);
  *(_DWORD *)(this + 284) = *(_DWORD *)(this + 252);
  *(_DWORD *)(this + 288) = *(_DWORD *)(this + 256);
  result = *(_DWORD *)(this + 276);
  *(_DWORD *)(this + 292) = result;
  *(_DWORD *)(this + 296) = *(_DWORD *)(this + 280);
  *(double *)(this + 300) = v10 * *(double *)(this + 92) + v8 * *(double *)(this + 76) + v9 * *(double *)(this + 84);
  return result;
}
