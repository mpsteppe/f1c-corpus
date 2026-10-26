int __usercall sub_51C5A3@<eax>(int a1@<eax>)
{
  _DWORD *v2; // esi
  int result; // eax
  char *v4; // edx
  int i; // ecx
  int v6; // edi
  int v7; // edi
  int v8; // [esp+Ch] [ebp-8h]
  int v9; // [esp+10h] [ebp-4h]

  v2 = *(_DWORD **)(a1 + 416);
  v2[2] = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 1024);
  v2[3] = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 1024);
  v2[4] = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 1024);
  v2[5] = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 1024);
  result = 0;
  v4 = (char *)&unk_5B6900;
  v8 = -14831872;
  v9 = -11728000;
  for ( i = 2919680; i >= -2831590; i -= 22554 )
  {
    v6 = v9;
    v9 += 91881;
    *(_DWORD *)(result + v2[2]) = v6 >> 16;
    v7 = v8;
    v8 += 116130;
    *(_DWORD *)(result + v2[3]) = v7 >> 16;
    *(_DWORD *)(result + v2[4]) = v4;
    *(_DWORD *)(result + v2[5]) = i;
    v4 -= 46802;
    result += 4;
  }
  return result;
}
