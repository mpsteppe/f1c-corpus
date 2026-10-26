int __thiscall sub_5BC9C0(_DWORD *this, int a2, int a3)
{
  int result; // eax
  int v4; // ebp
  int v5; // esi
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  float *v10; // esi
  int v11; // edi
  _DWORD *v12; // [esp+8h] [ebp-54h]
  int v13; // [esp+Ch] [ebp-50h]
  float v14[3]; // [esp+10h] [ebp-4Ch] BYREF
  float v15[16]; // [esp+1Ch] [ebp-40h] BYREF

  *(_DWORD *)a2 = 2139095039;
  *(_DWORD *)(a2 + 4) = 2139095039;
  *(_DWORD *)(a2 + 8) = 2139095039;
  *(_DWORD *)(a2 + 12) = -8388609;
  *(_DWORD *)(a2 + 16) = -8388609;
  *(_DWORD *)(a2 + 20) = -8388609;
  result = this[111];
  v4 = 0;
  v12 = this;
  v13 = result;
  if ( result > 0 )
  {
    while ( 1 )
    {
      v5 = *(_DWORD *)(this[113] + 4 * v4);
      v6 = *(_DWORD *)(*(_DWORD *)(v5 + 296) + 8 * a3 + 4);
      if ( v6 )
      {
        v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 12))(v6);
        if ( v7 )
        {
          qmemcpy(v15, (const void *)(v5 + 68), sizeof(v15));
          v8 = *(_DWORD *)(v7 + 16);
          v9 = *(_DWORD *)(v7 + 40);
          if ( v9 > 0 )
          {
            v10 = (float *)(v8 + 8);
            v11 = v9;
            do
            {
              v14[0] = v15[8] * *v10 + v15[4] * *(v10 - 1) + v15[0] * *(v10 - 2) + v15[12];
              v14[1] = v15[9] * *v10 + v15[1] * *(v10 - 2) + v15[5] * *(v10 - 1) + v15[13];
              v14[2] = v15[10] * *v10 + v15[2] * *(v10 - 2) + v15[6] * *(v10 - 1) + v15[14];
              sub_5BC480((float *)a2, v14);
              v10 += 3;
              --v11;
            }
            while ( v11 );
          }
        }
      }
      result = v13;
      if ( ++v4 >= v13 )
        break;
      this = v12;
    }
  }
  return result;
}
