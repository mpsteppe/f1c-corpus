int __thiscall sub_5FEEB0(void *this, _DWORD *a2, float a3)
{
  int result; // eax
  float *v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  float v8; // [esp+4h] [ebp-90h]
  float v9; // [esp+8h] [ebp-8Ch]
  float v10; // [esp+Ch] [ebp-88h]
  float v11[3]; // [esp+1Ch] [ebp-78h] BYREF
  _BYTE v12[4]; // [esp+28h] [ebp-6Ch] BYREF
  float v13[26]; // [esp+2Ch] [ebp-68h] BYREF

  result = *((_DWORD *)this + 68);
  if ( result )
  {
    *((_DWORD *)this + 50) = *a2;
    *((_DWORD *)this + 51) = a2[1];
    *((_DWORD *)this + 52) = a2[2];
    sub_5D7750((float *)this + 50);
    sub_46F740();
    sub_5D73C0((int)v12, 1.5707964, 0.0, a3);
    sub_5D77B0((float *)this + 50, (float *)this + 53, v13);
    sub_5D7940((float *)this + 50, (float *)this + 53, v11);
    sub_5D7750(v11);
    sub_5D7940((float *)this + 53, v11, (float *)this + 50);
    sub_5D7750((float *)this + 50);
    v5 = (float *)*((_DWORD *)this + 68);
    v5[87] = v11[0];
    v5[91] = v11[1];
    v5[95] = v11[2];
    v6 = (_DWORD *)*((_DWORD *)this + 68);
    v6[88] = *((_DWORD *)this + 53);
    v6[92] = *((_DWORD *)this + 54);
    v6[96] = *((_DWORD *)this + 55);
    v7 = (_DWORD *)*((_DWORD *)this + 68);
    v7[89] = *((_DWORD *)this + 50);
    v7 += 86;
    v7[7] = *((_DWORD *)this + 51);
    v7[11] = *((_DWORD *)this + 52);
    v10 = *((float *)this + 56) * *((float *)this + 52) - *((float *)this + 49);
    v9 = *((float *)this + 56) * *((float *)this + 51) - *((float *)this + 48);
    v8 = *((float *)this + 56) * *((float *)this + 50) - *((float *)this + 47);
    sub_5E4C80(*((float **)this + 68), v8, v9, v10);
    result = *(_DWORD *)this | 8;
    *(_DWORD *)this = result;
  }
  return result;
}
