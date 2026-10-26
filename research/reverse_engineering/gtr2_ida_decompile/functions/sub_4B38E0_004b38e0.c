int __thiscall sub_4B38E0(float *this)
{
  int v2; // edi
  _DWORD *v3; // ebx
  int v4; // eax
  _DWORD *v5; // eax
  char *v6; // eax
  int v7; // ebp
  int v8; // eax
  int v9; // eax
  char Buffer[61]; // [esp+14h] [ebp-40h] BYREF
  __int16 v12; // [esp+51h] [ebp-3h]
  char v13; // [esp+53h] [ebp-1h]

  memset(Buffer, 0, sizeof(Buffer));
  v12 = 0;
  v13 = 0;
  v2 = dword_B72BD4;
  v3 = (_DWORD *)(*(int (__thiscall **)(float *))(*(_DWORD *)this + 188))(this);
  v4 = sub_53A250(0);
  this[74] = 103.0;
  if ( v4 )
  {
    v5 = (_DWORD *)sub_616630("Max Vehicles");
    if ( v5 )
    {
      v6 = sub_48D380(v5);
      this[74] = (double)atol(v6) - 1.0;
    }
  }
  v7 = sub_502090(&byte_B6F530);
  if ( v3 )
    sprintf(Buffer, "%d", *v3);
  *((_BYTE *)this + 281) = 0;
  if ( v7 < v2 )
    *((_BYTE *)this + 281) = 1;
  sub_615860(Buffer);
  v8 = dword_B72BB8;
  Value = v2;
  if ( v2 < dword_B72BB8 || (v8 = dword_B72BBC, v2 > dword_B72BBC) )
    Value = v8;
  v9 = dword_B72BDC;
  dword_B72BD4 = v2;
  if ( v2 < dword_B72BDC || (v9 = dword_B72BE0, v2 > dword_B72BE0) )
    dword_B72BD4 = v9;
  return 0;
}
