int __thiscall sub_53E150(int this, int a2)
{
  int result; // eax
  float *v4; // eax
  double v5; // st7
  double v6; // rt0
  int v7; // edi
  int v8; // ecx
  float *v9; // eax
  double v10; // st7
  double v11; // st6
  int v12; // eax
  float v13; // ecx
  float v14; // [esp+4h] [ebp-34h]
  float v15; // [esp+4h] [ebp-34h]
  float v16; // [esp+8h] [ebp-30h] BYREF
  float v17; // [esp+Ch] [ebp-2Ch]
  float v18; // [esp+10h] [ebp-28h]
  float v19; // [esp+14h] [ebp-24h] BYREF
  float v20; // [esp+18h] [ebp-20h]
  float v21; // [esp+1Ch] [ebp-1Ch]
  float v22; // [esp+28h] [ebp-10h]
  float v23; // [esp+2Ch] [ebp-Ch]

  result = sub_5BFC80(*(_DWORD *)(this + 24));
  if ( (_BYTE)result )
  {
    v4 = *(float **)(this + 28);
    v5 = v4[17];
    v4 += 17;
    v6 = v4[1];
    v21 = v4[2];
    v16 = -v5;
    v17 = -v6;
    v18 = -v21;
    sub_5C1640(&v16);
    v7 = **(_DWORD **)(this + 32);
    if ( (unsigned __int8)sub_405250() )
    {
      v14 = *(float *)(v7 + 32);
      v8 = *(_DWORD *)(this + 24);
      v16 = v14 * *(float *)(this + 12);
      v17 = v14 * *(float *)(this + 16);
      v18 = v14 * *(float *)(this + 20);
      v9 = (float *)sub_5C1550(v8);
      v10 = v9[29];
      v11 = v9[30];
      v22 = v9[31];
      v15 = 1.0 - v14;
      v23 = v10 * v15;
      v19 = v23 + v16;
      v20 = v11 * v15 + v17;
      v21 = v22 * v15 + v18;
    }
    else
    {
      v12 = sub_5C1550(*(_DWORD *)(this + 24));
      v13 = *(float *)(v12 + 116);
      v12 += 116;
      v19 = v13;
      v20 = *(float *)(v12 + 4);
      v21 = *(float *)(v12 + 8);
    }
    return sub_5C1620(&v19);
  }
  return result;
}
