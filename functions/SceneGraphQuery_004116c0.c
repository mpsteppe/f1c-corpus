int __stdcall sub_4116C0(int a1)
{
  int v1; // esi
  int result; // eax
  int v3; // edi
  int v4; // [esp+8h] [ebp-10h] BYREF
  int v5; // [esp+Ch] [ebp-Ch] BYREF
  int v6; // [esp+10h] [ebp-8h] BYREF
  int v7; // [esp+14h] [ebp-4h] BYREF

  v1 = dword_8AC4C4;
  result = 1;
  if ( dword_8AC4C4 )
  {
    v4 = -1;
    v6 = -1;
    v5 = 0;
    v7 = 0;
    v3 = AudioCommentaryChannelConfiguration(a1, &v4, &v6, &v5, &v7);
    if ( !v3 )
    {
      (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v1 + 72))(v1, v5, v4);
      (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v1 + 72))(v1, v7, v6);
    }
    return v3;
  }
  return result;
}
