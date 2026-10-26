int __thiscall sub_46DDE0(void *this, int *a2)
{
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int *v6; // [esp+14h] [ebp-51Ch]
  int v8; // [esp+1Ch] [ebp-514h] BYREF
  int v9; // [esp+20h] [ebp-510h] BYREF
  int v10; // [esp+24h] [ebp-50Ch] BYREF
  _BYTE v11[512]; // [esp+28h] [ebp-508h] BYREF
  int v12; // [esp+228h] [ebp-308h]
  char v13; // [esp+22Ch] [ebp-304h]
  int v14; // [esp+234h] [ebp-2FCh]
  int v15; // [esp+238h] [ebp-2F8h]
  int v16; // [esp+23Ch] [ebp-2F4h]
  _BYTE v17[512]; // [esp+240h] [ebp-2F0h] BYREF
  _DWORD v18[60]; // [esp+440h] [ebp-F0h] BYREF

  memset(v17, 0, sizeof(v17));
  v2 = *a2;
  v12 = 0;
  v16 = 0;
  v14 = 0;
  v15 = 0;
  v13 = 1;
  v3 = 0;
  if ( !(*(int (__thiscall **)(int *, _BYTE *, int))(v2 + 36))(a2, v17, 512) )
    return 1;
  v6 = v18;
  do
  {
    v4 = sub_612EB0(v11);
    if ( !v4 )
    {
      if ( sub_6134B0("CONTROLPOINT", (int)&v8, (int)&v9, (int)&v10, 0, 0, 0, 0, 0) )
      {
        if ( v3 < 20 )
        {
          *v6 = v8;
          v6[1] = v9;
          ++v3;
          v6[2] = v10;
          v6 += 3;
        }
      }
      continue;
    }
    if ( v4 == 2 || v4 == 4 )
      break;
  }
  while ( (*(int (__thiscall **)(int *, _BYTE *, int))(*a2 + 36))(a2, v17, 512) );
  if ( v3 >= 4 )
    return sub_46DD10((int)this, v18, v3);
  return 1;
}
