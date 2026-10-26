int __thiscall sub_413E00(int this, char a2, char a3, int a4, int a5, int a6)
{
  int result; // eax
  int v8; // edx
  int v9; // eax

  result = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 36))(dword_76BB24);
  if ( (unsigned __int8)result < *(_BYTE *)(this + 2) )
  {
    *(_BYTE *)((unsigned __int8)result + *(_DWORD *)(this + 4)) = a2;
    *(_BYTE *)((unsigned __int8)result + *(_DWORD *)(this + 8)) = a3;
    v8 = *(_DWORD *)(this + 20);
    v9 = *(_DWORD *)(this + 24);
    *(_DWORD *)(this + 12) += a4;
    *(_DWORD *)(this + 20) = a5 + v8;
    result = a6 + v9;
    *(_DWORD *)(this + 24) = result;
  }
  return result;
}
