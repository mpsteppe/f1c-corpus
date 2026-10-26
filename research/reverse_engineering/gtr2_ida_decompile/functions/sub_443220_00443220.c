int __thiscall sub_443220(int this, double *a2, int a3)
{
  int v4; // edi
  int v5; // ecx
  double v6; // st7
  double v7; // st6
  int result; // eax
  double v9[5]; // [esp+10h] [ebp-78h] BYREF
  double v10; // [esp+38h] [ebp-50h]
  double v11; // [esp+40h] [ebp-48h]
  double v12; // [esp+48h] [ebp-40h]
  double v13; // [esp+50h] [ebp-38h]
  double v14; // [esp+58h] [ebp-30h]
  double v15; // [esp+60h] [ebp-28h]
  double v16; // [esp+68h] [ebp-20h]
  double v17; // [esp+70h] [ebp-18h]
  double v18; // [esp+78h] [ebp-10h]
  double v19; // [esp+80h] [ebp-8h]

  v4 = sub_615460(dword_16C9A88);
  sub_61B860(a3);
  v5 = *(_DWORD *)(this + 6312);
  v6 = v11 * *(double *)(this + 6328) + v12 * *(double *)(this + 6336) + v13 * *(double *)(this + 6344);
  v7 = v14 * *(double *)(this + 6328) + v15 * *(double *)(this + 6336) + v16 * *(double *)(this + 6344);
  v10 = v17 * *(double *)(this + 6328) + v18 * *(double *)(this + 6336) + v19 * *(double *)(this + 6344);
  v9[0] = *a2 - v6;
  v9[1] = a2[1] - v7;
  v9[2] = a2[2] - v10;
  result = sub_61E140(v5, v9, a3, 0);
  *(_DWORD *)(this + 200) = 0;
  *(double *)(this + 968) = -1.797693134862316e308;
  *(double *)(this + 1000) = -1.797693134862316e308;
  *(double *)(this + 2248) = -1.797693134862316e308;
  *(double *)(this + 2280) = -1.797693134862316e308;
  *(double *)(this + 3528) = -1.797693134862316e308;
  *(double *)(this + 3560) = -1.797693134862316e308;
  *(double *)(this + 4808) = -1.797693134862316e308;
  *(double *)(this + 4840) = -1.797693134862316e308;
  if ( v4 != 512 )
    return sub_6154A0(v4);
  return result;
}
