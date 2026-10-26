int __thiscall sub_4F3200(int this, float a2, float *a3, float *a4, float a5, int a6, char a7, int a8, int a9)
{
  int result; // eax
  float *v11; // esi
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17[3]; // [esp+4h] [ebp-34h] BYREF
  int v18; // [esp+1Ch] [ebp-1Ch]
  int v19; // [esp+20h] [ebp-18h]
  int v20; // [esp+24h] [ebp-14h]
  int v21; // [esp+28h] [ebp-10h]
  double v22; // [esp+2Ch] [ebp-Ch]
  int v23; // [esp+34h] [ebp-4h]

  result = *(_DWORD *)(this + 96);
  if ( result > 0 )
  {
    v11 = (float *)sub_4F2AE0((_DWORD *)this);
    v12 = a2 + v11[7];
    v11[2] = a2;
    v11[3] = v12;
    *((_DWORD *)v11 + 24) = a9 & 0xFFFFFF;
    v11[11] = *a3;
    v11[12] = a3[1];
    v11[13] = a3[2];
    v11[14] = *a4;
    v11[15] = a4[1];
    v11[16] = a4[2];
    v13 = flt_7D3C54[(unsigned __int8)dword_7D3C50++] * 64.0;
    *((_DWORD *)v11 + 17) = a8;
    v11[10] = (v13 + 190.0) * a5;
    v23 = a6;
    v17[0] = *a3;
    v14 = a3[1];
    v18 = 0;
    v17[1] = v14;
    v15 = a3[2];
    v19 = 1070596096;
    v17[2] = v15;
    v20 = 0x40000000;
    v21 = 1201543096;
    if ( sub_44E990(dbl_760B48, v17, v11 + 21) )
    {
      v16 = v22;
    }
    else
    {
      v11[21] = 0.0;
      v11[22] = 1.0;
      v11[23] = 0.0;
      v16 = a3[1] - 0.25;
    }
    if ( a7 )
    {
      v11[12] = *(float *)(this + 16) * 0.5 + v16;
      v11[15] = v11[26] * *(float *)(this + 28) * 0.5;
    }
    sub_5B0B40(*(_DWORD *)v11, *((_DWORD *)v11 + 11), *((_DWORD *)v11 + 12), *((_DWORD *)v11 + 13));
    sub_5B0B90(*(_DWORD *)v11, *(_DWORD *)(this + 12), *(_DWORD *)(this + 16), *(_DWORD *)(this + 20));
    return sub_5B0C30(*(_DWORD *)v11, *((_DWORD *)v11 + 24));
  }
  return result;
}
