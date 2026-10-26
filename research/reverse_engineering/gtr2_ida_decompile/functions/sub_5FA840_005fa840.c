int __thiscall sub_5FA840(int this)
{
  int result; // eax
  int v3; // ebx
  bool v4; // zf
  bool v5; // sf
  char **v6; // ebp
  char *v7; // edi

  result = *(_DWORD *)(this + 380);
  v3 = 0;
  if ( result )
    result = (*(int (__stdcall **)(int))(*(_DWORD *)result + 8))(result);
  v4 = *(_DWORD *)(this + 340) == 0;
  v5 = *(int *)(this + 340) < 0;
  *(_BYTE *)(this + 268) = 0;
  *(_BYTE *)(this + 204) = 0;
  *(_DWORD *)(this + 380) = 0;
  *(_DWORD *)(this + 376) = 0;
  if ( !v5 && !v4 )
  {
    v6 = (char **)(this + 344);
    do
    {
      v7 = *v6;
      if ( *v6 )
      {
        sub_5F77C0(*v6);
        j__free(v7);
      }
      result = *(_DWORD *)(this + 340);
      ++v3;
      ++v6;
    }
    while ( v3 < result );
  }
  return result;
}
