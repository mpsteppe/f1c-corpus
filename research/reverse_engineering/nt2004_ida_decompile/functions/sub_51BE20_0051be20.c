_DWORD *__thiscall sub_51BE20(int this, float *a2, _DWORD *a3)
{
  float *v4; // ebx
  _DWORD *v5; // ecx
  double v6; // st7
  double v7; // st6
  double v8; // st7
  double v9; // st6
  double v10; // st5
  float *v11; // ecx
  _DWORD *result; // eax
  double v13; // [esp+Ch] [ebp-30h] BYREF
  double v14; // [esp+14h] [ebp-28h]
  double v15; // [esp+1Ch] [ebp-20h]
  double v16[3]; // [esp+24h] [ebp-18h] BYREF

  v4 = (float *)(this + 17532);
  v5 = (_DWORD *)(this + 17532);
  *v5 = *a3;
  v5[1] = a3[1];
  v5[2] = a3[2];
  sub_579100(v5, this + 17484);
  sub_51BCE0((float *)this, (int)&v13);
  v6 = *(float *)&v14 * *(float *)(this + 17492)
     + *((float *)&v13 + 1) * *(float *)(this + 17488)
     + *(float *)&v13 * *(float *)(this + 17484);
  v7 = *(float *)&v14 * *(float *)(this + 17504)
     + *((float *)&v13 + 1) * *(float *)(this + 17500)
     + *(float *)&v13 * *(float *)(this + 17496);
  *(float *)&v14 = *(float *)&v14 * *(float *)(this + 17516)
                 + *((float *)&v13 + 1) * *(float *)(this + 17512)
                 + *(float *)&v13 * *(float *)(this + 17508);
  *(float *)&v13 = v6 + *(float *)(this + 17520);
  v8 = v7 + *(float *)(this + 17524);
  v9 = *(float *)&v14 + *(float *)(this + 17528);
  *(float *)&v13 = *a2 - *(float *)&v13;
  *((float *)&v13 + 1) = a2[1] - v8;
  v10 = a2[2] - v9;
  *(float *)(this + 17520) = *(float *)&v13 + *(float *)(this + 17520);
  *(float *)(this + 17524) = *((float *)&v13 + 1) + *(float *)(this + 17524);
  *(float *)(this + 17528) = v10 + *(float *)(this + 17528);
  *(_DWORD *)(this + 19000) = 0;
  sub_5157A0(v11);
  result = *(_DWORD **)(this + 16500);
  if ( !result )
  {
    v16[0] = *(float *)(this + 17520);
    v16[1] = *(float *)(this + 17524);
    v16[2] = *(float *)(this + 17528);
    v13 = *v4;
    v14 = *(float *)(this + 17536);
    v15 = *(float *)(this + 17540);
    return sub_4417D0((int)&dbl_75E930, v16, (int)&v13);
  }
  return result;
}
