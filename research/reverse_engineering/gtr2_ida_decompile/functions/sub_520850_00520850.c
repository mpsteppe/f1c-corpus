char __thiscall sub_520850(void *this, int *a2)
{
  int v2; // edx
  unsigned __int8 v3; // al
  unsigned __int8 v5; // [esp+19h] [ebp-101h] BYREF
  _BYTE v6[253]; // [esp+1Ah] [ebp-100h] BYREF
  __int16 v7; // [esp+117h] [ebp-3h]
  char v8; // [esp+119h] [ebp-1h]

  (*(void (__thiscall **)(int *, void *, int))(*a2 + 28))(a2, this, 4);
  v2 = *a2;
  v5 = 0;
  (*(void (__thiscall **)(int *, unsigned __int8 *, int))(v2 + 28))(a2, &v5, 1);
  memset(v6, 0, sizeof(v6));
  v7 = 0;
  v8 = 0;
  v3 = v5;
  if ( v5 )
  {
    (*(void (__thiscall **)(int *, _BYTE *, _DWORD))(*a2 + 28))(a2, v6, v5);
    v3 = v5;
  }
  v6[v3] = 0;
  sub_615860(v6);
  return 1;
}
