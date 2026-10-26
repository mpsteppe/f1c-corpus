int __thiscall sub_5E4E30(int this, float *a2, int *a3)
{
  double v4; // st7
  double v5; // st6
  int v6; // ebx
  unsigned __int64 v7; // rax
  int v8; // ecx
  int v9; // ecx
  float v11; // [esp+Ch] [ebp-1Ch]
  float v12; // [esp+10h] [ebp-18h]
  float v13; // [esp+14h] [ebp-14h]
  float v14; // [esp+18h] [ebp-10h]
  float v15[3]; // [esp+1Ch] [ebp-Ch] BYREF

  v11 = (double)*(int *)(this + 100) * 0.5 / tan(*(float *)(this + 124) * 0.5);
  v13 = (double)*(int *)(this + 104) * 0.5 / tan(*(float *)(this + 128) * 0.5);
  v12 = (float)*(int *)(this + 108);
  v14 = (float)*(int *)(this + 112);
  sub_5D7810(a2, v15, (float *)(this + 348));
  v4 = 1.0 / v15[2];
  v5 = v15[1] * v4;
  v6 = (unsigned __int64)(v15[0] * v4 * v11 + v12);
  *a3 = v6;
  v7 = (unsigned __int64)(v14 - v5 * v13);
  a3[1] = v7;
  if ( v6 <= *(_DWORD *)(this + 120) )
    v6 = *(_DWORD *)(this + 120);
  *a3 = v6;
  v8 = *(_DWORD *)(this + 100) + *(_DWORD *)(this + 120);
  if ( v6 < v8 )
    v8 = v6;
  *a3 = v8;
  if ( (int)v7 <= *(_DWORD *)(this + 116) )
    LODWORD(v7) = *(_DWORD *)(this + 116);
  a3[1] = v7;
  v9 = *(_DWORD *)(this + 116) + *(_DWORD *)(this + 104);
  if ( (int)v7 >= v9 )
    a3[1] = v9;
  else
    a3[1] = v7;
  return v7;
}
