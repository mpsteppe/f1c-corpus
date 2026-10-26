int __thiscall sub_409510(_DWORD *this, int a2, float *a3, int a4)
{
  int v5; // edx
  float v6; // ebx
  int v7; // ebp
  int v8; // eax
  int result; // eax
  double v10; // st7
  float v11; // [esp+14h] [ebp-58h]
  float v12; // [esp+20h] [ebp-4Ch]
  _BYTE v13[12]; // [esp+28h] [ebp-44h] BYREF
  double v14[6]; // [esp+34h] [ebp-38h] BYREF
  int v15; // [esp+64h] [ebp-8h]

  v14[0] = *a3;
  v5 = this[5];
  v14[1] = a3[1];
  v6 = *a3;
  v14[2] = a3[2];
  v7 = *((_DWORD *)a3 + 2);
  v14[3] = 1000000.0;
  v14[4] = 9.999999933815813e36;
  v15 = v5;
  v8 = sub_45D190(v14);
  this[5] = v8;
  if ( v8 )
  {
    sub_56C0A0(v13);
    result = a2;
    v10 = v14[5] - v12;
    *(float *)a2 = v6;
    v11 = v10;
    *(float *)(a2 + 4) = v11;
    *(_DWORD *)(a2 + 8) = v7;
  }
  else
  {
    result = a2;
    *(float *)a2 = *a3;
    *(float *)(a2 + 4) = a3[1];
    *(float *)(a2 + 8) = a3[2];
  }
  return result;
}
