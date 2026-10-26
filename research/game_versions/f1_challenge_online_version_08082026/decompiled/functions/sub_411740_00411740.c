void __stdcall sub_411740(int a1)
{
  int v1; // esi
  int v2; // [esp+4h] [ebp-10h] BYREF
  int v3; // [esp+8h] [ebp-Ch] BYREF
  int v4; // [esp+Ch] [ebp-8h] BYREF
  int v5; // [esp+10h] [ebp-4h] BYREF

  v1 = dword_8AC4C4;
  if ( dword_8AC4C4 )
  {
    v2 = -1;
    v3 = -1;
    v5 = 0;
    v4 = 0;
    if ( !sub_4117B0(a1, &v2, &v3, &v5, &v4) )
    {
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v1 + 76))(v1, v2);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v1 + 76))(v1, v3);
    }
  }
}
