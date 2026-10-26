int __thiscall sub_5A9AD0(_DWORD *this, int a2, int a3, int a4)
{
  int v4; // ebx
  char *v6; // eax
  _DWORD *v7; // esi
  int *v8; // edi
  int v9; // edx
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // edx
  int v14; // eax
  int v15; // edx
  int v16; // eax
  int v18; // [esp+8h] [ebp-3Ch]
  int v19; // [esp+Ch] [ebp-38h] BYREF
  int v20; // [esp+10h] [ebp-34h]
  int v21; // [esp+14h] [ebp-30h]
  int v22; // [esp+28h] [ebp-1Ch]
  int v23; // [esp+2Ch] [ebp-18h]
  int v24; // [esp+30h] [ebp-14h]
  char *v25; // [esp+50h] [ebp+Ch]

  v4 = a4;
  flt_61BBA4 = (float)-dword_7E8CE8;
  flt_61BBC4 = (float)-dword_7E8CEC;
  v18 = 0;
  v6 = (char *)operator new(32 * a4);
  v25 = v6;
  if ( v4 > 0 )
  {
    v7 = v6 + 8;
    v8 = (int *)(a2 + 8);
    do
    {
      v9 = *(v8 - 1);
      v10 = *v8;
      v19 = *(v8 - 2);
      v22 = v8[1];
      v20 = v9;
      v11 = v8[2];
      v21 = v10;
      v12 = v8[3];
      v23 = v11;
      v24 = v12;
      if ( sub_5A9920((int)&v19) )
      {
        v13 = v19;
        v14 = v20;
        *v7 = v21;
        v7[3] = v24;
        *(v7 - 2) = v13;
        v15 = v22;
        *(v7 - 1) = v14;
        v16 = v23;
        v7[1] = v15;
        v7[2] = v16;
        ++v18;
        v7 += 8;
      }
      v8 += 8;
      --v4;
    }
    while ( v4 );
    v6 = v25;
  }
  if ( (this[14] & 0x40000) != 0 )
    sub_5B47F0(this, v6, a3, v18);
  else
    sub_5A9C30((__int64)*(float *)(a2 + 12), (__int64)*(float *)(a2 + 16), a3, this);
  this[14] &= ~0x400u;
  return sub_5BE8AE();
}
