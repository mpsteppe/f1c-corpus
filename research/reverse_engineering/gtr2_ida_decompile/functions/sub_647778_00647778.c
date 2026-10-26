void __cdecl __noreturn sub_647778(int a1)
{
  int v1; // [esp+0h] [ebp-4h]
  int savedregs; // [esp+4h] [ebp+0h]
  int savedregsa; // [esp+4h] [ebp+0h]

  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)a1 + 8))(a1, v1, savedregs);
  savedregsa = 1;
  sub_6E0030(*(_DWORD *)a1 + 132);
  __debugbreak();
}
