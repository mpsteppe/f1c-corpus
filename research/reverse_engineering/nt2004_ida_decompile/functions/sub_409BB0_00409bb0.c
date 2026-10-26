void __thiscall sub_409BB0(void *this, int a2)
{
  signed int v2; // ebx
  int v3; // esi
  float v5; // [esp+8h] [ebp-3Ch]
  float v6; // [esp+Ch] [ebp-38h]
  float v7; // [esp+20h] [ebp-24h]
  float v8; // [esp+24h] [ebp-20h]
  float v9; // [esp+28h] [ebp-1Ch]
  float v10; // [esp+2Ch] [ebp-18h]
  float v11; // [esp+30h] [ebp-14h]
  float v12; // [esp+34h] [ebp-10h]
  float v13; // [esp+38h] [ebp-Ch] BYREF
  float v14; // [esp+3Ch] [ebp-8h]
  float v15; // [esp+40h] [ebp-4h]
  float v16; // [esp+48h] [ebp+4h]

  v2 = NumOfElements;
  v3 = 0;
  if ( (int)NumOfElements > 0 )
  {
    while ( 1 )
    {
      v10 = *(float *)(dword_75AAD0[v3] + 1976);
      v11 = *(float *)(dword_75AAD0[v3] + 1980);
      v12 = *(float *)(dword_75AAD0[v3] + 1984);
      sub_459BC0(&v13, 0);
      v16 = (v12 - v15) * (v12 - v15) + (v11 - v14) * (v11 - v14) + (v10 - v13) * (v10 - v13);
      if ( v16 < 250.0 )
      {
        v8 = *(float *)(dword_75AAD0[v3] + 164);
        v9 = *(float *)(dword_75AAD0[v3] + 168);
        v7 = *(float *)(dword_75AAD0[v3] + 160);
        if ( sqrt(v8 * v8 + v9 * v9 + v7 * v7) > 35.0 )
          break;
      }
      if ( ++v3 >= v2 )
        return;
    }
    v6 = sub_40BEC0(this);
    v5 = 1.0 - v16 * 0.0040000002;
    sub_459B60(v5, v6);
  }
}
