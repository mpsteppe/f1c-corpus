char __thiscall sub_4CE0F0(int this, int a2)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // eax
  int v6; // eax
  float v7; // edx
  int v8; // eax
  unsigned __int8 v9; // al
  int v10; // eax
  int v11; // eax
  int v12; // eax
  float v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v20; // [esp-8h] [ebp-10h]
  int v21; // [esp-8h] [ebp-10h]
  int v22; // [esp-8h] [ebp-10h]
  int v23; // [esp-8h] [ebp-10h]
  int v24; // [esp-8h] [ebp-10h]
  int v25; // [esp-8h] [ebp-10h]
  int v26; // [esp-8h] [ebp-10h]

  if ( a2 < 1 || a2 >= 9 )
    return 0;
  v20 = *(_DWORD *)(this + 9720);
  *(_DWORD *)(this + 9708) = a2;
  sub_4CF410(v20);
  v3 = *(_DWORD *)(this + 1944);
  v4 = (_DWORD *)(this + 36 * a2);
  *(_DWORD *)(this + 1932) = v4[483];
  sub_4CF410(v3);
  v21 = *(_DWORD *)(this + 2280);
  *(_DWORD *)(this + 2268) = *(_DWORD *)(this + 4 * (9 * a2 + 567));
  sub_4CF410(v21);
  v5 = *(_DWORD *)(this + 2604);
  *(_DWORD *)(this + 2592) = *(_DWORD *)(this + 4 * (9 * a2 + 648));
  sub_4CF410(v5);
  v22 = *(_DWORD *)(this + 2928);
  *(_DWORD *)(this + 2916) = *(_DWORD *)(this + 4 * (9 * a2 + 729));
  sub_4CF410(v22);
  v6 = *(_DWORD *)(this + 3252);
  *(_DWORD *)(this + 3240) = *(_DWORD *)(this + 4 * (9 * a2 + 810));
  sub_4CF410(v6);
  v7 = *(float *)(this + 3576);
  *(_DWORD *)(this + 3564) = *(_DWORD *)(this + 4 * (9 * a2 + 891));
  sub_466720((float *)(this + 3564), *(float *)(this + 3572), v7);
  v23 = *(_DWORD *)(this + 3900);
  *(_DWORD *)(this + 3888) = *(_DWORD *)(this + 4 * (9 * a2 + 972));
  sub_4CF410(v23);
  v8 = *(_DWORD *)(this + 4224);
  *(_DWORD *)(this + 4212) = *(_DWORD *)(this + 4 * (9 * a2 + 1053));
  sub_4CF410(v8);
  v24 = *(_DWORD *)(this + 4548);
  *(_DWORD *)(this + 4536) = *(_DWORD *)(this + 4 * (9 * a2 + 1134));
  sub_4CF410(v24);
  v9 = *(_BYTE *)(this + 4863);
  *(_BYTE *)(this + 4860) = *(_BYTE *)(this + 24 * a2 + 4860);
  sub_466780((unsigned __int8 *)(this + 4860), *(_BYTE *)(this + 4862), v9);
  v10 = *(_DWORD *)(this + 9816);
  *(_DWORD *)(this + 9804) = v4[2451];
  sub_4CF410(v10);
  v11 = *(_DWORD *)(this + 10140);
  *(_DWORD *)(this + 10128) = v4[2532];
  sub_4CF410(v11);
  v12 = *(_DWORD *)(this + 10464);
  *(_DWORD *)(this + 10452) = v4[2613];
  sub_4CF410(v12);
  v13 = *(float *)(this + 10788);
  *(_DWORD *)(this + 10776) = v4[2694];
  sub_466720((float *)(this + 10776), *(float *)(this + 10784), v13);
  v25 = *(_DWORD *)(this + 11472);
  *(_DWORD *)(this + 11460) = v4[2865];
  sub_4CF410(v25);
  v14 = *(_DWORD *)(this + 11928);
  *(_DWORD *)(this + 11916) = *(_DWORD *)(this + 4 * (9 * a2 + 2979));
  sub_4CF410(v14);
  v26 = *(_DWORD *)(this + 12252);
  *(_DWORD *)(this + 12240) = *(_DWORD *)(this + 4 * (9 * a2 + 3060));
  sub_4CF410(v26);
  v15 = *(_DWORD *)(this + 12576);
  *(_DWORD *)(this + 12564) = *(_DWORD *)(this + 4 * (9 * a2 + 3141));
  sub_4CF410(v15);
  v16 = *(_DWORD *)(this + 11112);
  *(_DWORD *)(this + 11100) = v4[2775];
  sub_4CF410(v16);
  if ( a2 == 1 )
  {
    v18 = *(_DWORD *)(this + 8700);
    *(_DWORD *)(this + 8688) = 1;
    sub_4CF410(v18);
  }
  else if ( a2 == 2 )
  {
    v17 = *(_DWORD *)(this + 8700);
    *(_DWORD *)(this + 8688) = 7;
    sub_4CF410(v17);
  }
  sub_4CE420(-1.0);
  return 1;
}
