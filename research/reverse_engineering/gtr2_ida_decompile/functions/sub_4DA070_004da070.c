int __stdcall sub_4DA070(int a1, int a2)
{
  int v2; // esi
  int v3; // eax
  int v4; // eax
  void *Block; // [esp+14h] [ebp-52Ch]
  int v7[64]; // [esp+18h] [ebp-528h] BYREF
  _BYTE v8[512]; // [esp+118h] [ebp-428h] BYREF
  int v9; // [esp+318h] [ebp-228h]
  char v10; // [esp+31Ch] [ebp-224h]
  int v11; // [esp+324h] [ebp-21Ch]
  int v12; // [esp+328h] [ebp-218h]
  int v13; // [esp+32Ch] [ebp-214h]
  _BYTE v14[516]; // [esp+330h] [ebp-210h] BYREF
  int v15; // [esp+53Ch] [ebp-4h]

  memset(v14, 0, 0x200u);
  memset(v7, 0, sizeof(v7));
  v9 = 0;
  v13 = 0;
  v11 = 0;
  v12 = 0;
  v10 = 1;
  Block = operator new(0x70u);
  v15 = 0;
  if ( Block )
    v2 = sub_4D9F90();
  else
    v2 = 0;
  v15 = -1;
  sub_615860(a2);
  while ( (*(int (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)a1 + 36))(a1, v14, 511) )
  {
    v3 = sub_612EB0(v8);
    if ( v3 )
    {
      if ( v3 == 2 )
        return v2;
    }
    else if ( sub_6131C0("Page", (int)v7) || sub_6131C0("AutoSelectChild", (int)v7) )
    {
      sub_615860(v7);
    }
    else if ( sub_6131C0((char *)off_711740, (int)v7) )
    {
      v4 = sub_4DA070(a1, v7);
      if ( v4 )
      {
        *(_DWORD *)(v4 + 24) = v2;
        sub_5FDFB0(v4, 1);
      }
    }
  }
  return v2;
}
