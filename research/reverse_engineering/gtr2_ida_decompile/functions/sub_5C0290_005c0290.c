void __thiscall sub_5C0290(int this, int a2, int a3)
{
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  float *v8; // edi
  int v9; // ebp
  float v10[3]; // [esp+8h] [ebp-Ch] BYREF

  *(_DWORD *)a2 = 2139095039;
  *(_DWORD *)(a2 + 4) = 2139095039;
  *(_DWORD *)(a2 + 8) = 2139095039;
  *(_DWORD *)(a2 + 12) = -8388609;
  *(_DWORD *)(a2 + 16) = -8388609;
  *(_DWORD *)(a2 + 20) = -8388609;
  v4 = *(_DWORD *)(*(_DWORD *)(this + 296) + 8 * a3 + 4);
  if ( v4 )
  {
    v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 12))(v4);
    if ( v5 )
    {
      v6 = *(_DWORD *)(v5 + 16);
      v7 = *(_DWORD *)(v5 + 40);
      if ( v7 > 0 )
      {
        v8 = (float *)(v6 + 4);
        v9 = v7;
        do
        {
          v10[0] = *(float *)(this + 100) * v8[1]
                 + *(float *)(this + 68) * *(v8 - 1)
                 + *(float *)(this + 84) * *v8
                 + *(float *)(this + 116);
          v10[1] = *(float *)(this + 104) * v8[1]
                 + *(float *)(this + 88) * *v8
                 + *(float *)(this + 72) * *(v8 - 1)
                 + *(float *)(this + 120);
          v10[2] = *(float *)(this + 92) * *v8
                 + *(float *)(this + 76) * *(v8 - 1)
                 + *(float *)(this + 108) * v8[1]
                 + *(float *)(this + 124);
          sub_5BC480((float *)a2, v10);
          v8 += 3;
          --v9;
        }
        while ( v9 );
      }
    }
  }
}
