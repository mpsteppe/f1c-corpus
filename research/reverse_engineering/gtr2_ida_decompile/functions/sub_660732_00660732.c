int __thiscall sub_660732(int this, _DWORD *a2)
{
  int result; // eax
  unsigned int v4; // eax
  int v5; // [esp+4h] [ebp-4h] BYREF

  result = sub_677265(4 * *(_DWORD *)(this + 92), &v5);
  if ( result >= 0 )
  {
    v4 = (*(int (__stdcall **)(int))(*(_DWORD *)v5 + 16))(v5);
    qmemcpy((void *)(*(int (__stdcall **)(int))(*(_DWORD *)v5 + 12))(v5), *(const void **)(this + 88), v4);
    *a2 = v5;
    return 0;
  }
  return result;
}
