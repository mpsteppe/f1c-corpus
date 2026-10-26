int __thiscall sub_5F2BE0(int this)
{
  int result; // eax

  result = *(_DWORD *)(this + 68);
  if ( result )
    result = (*(int (__stdcall **)(int))(*(_DWORD *)result + 8))(result);
  *(_DWORD *)(this + 68) = 0;
  *(_BYTE *)(this + 72) = 0;
  return result;
}
