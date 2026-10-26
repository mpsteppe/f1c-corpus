char __thiscall sub_5C3150(_DWORD *this, float *a2, int a3)
{
  int v4; // eax
  int v5; // ebx
  int v7; // edi
  _DWORD *i; // esi
  int v10; // [esp+10h] [ebp-9Ch]
  float v11[16]; // [esp+14h] [ebp-98h] BYREF
  float v12[3]; // [esp+54h] [ebp-58h] BYREF
  float v13[3]; // [esp+60h] [ebp-4Ch] BYREF
  float v14[16]; // [esp+6Ch] [ebp-40h] BYREF

  v4 = this[8];
  v5 = this[4];
  qmemcpy(v14, (const void *)(a3 + 68), sizeof(v14));
  v10 = v4;
  sub_5BE470(v14);
  qmemcpy(v11, v14, sizeof(v11));
  v12[0] = v11[0] * *a2 + v11[4] * a2[1] + v11[8] * a2[2] + v11[12];
  v12[1] = v11[1] * *a2 + v11[5] * a2[1] + v11[9] * a2[2] + v11[13];
  v12[2] = v11[2] * *a2 + v11[6] * a2[1] + v11[10] * a2[2] + v11[14];
  v13[0] = v11[0] * a2[3] + v11[4] * a2[4] + v11[8] * a2[5] + v11[12];
  v13[1] = v11[1] * a2[3] + v11[5] * a2[4] + v11[9] * a2[5] + v11[13];
  v13[2] = v11[6] * a2[4] + v11[10] * a2[5] + v11[2] * a2[3] + v11[14];
  sub_5C2770(v11, v12, v13);
  v7 = 0;
  if ( (int)this[11] <= 0 )
    return 0;
  for ( i = (_DWORD *)(v10 + 4);
        !(unsigned __int8)((int (__thiscall *)(float *, int, int, int, _DWORD, _DWORD, _DWORD))loc_5C2C30)(
                            v11,
                            v5 + 12 * *(i - 1),
                            v5 + 12 * *i,
                            v5 + 12 * i[1],
                            0,
                            0,
                            0);
        i += 3 )
  {
    v7 += 3;
    if ( v7 >= this[11] )
      return 0;
  }
  return 1;
}
