// f1c  0x00540f90  size=39
void __thiscall sub_540F90(int *this, int a2)
{
  int v3; // eax
  int v4; // eax

  if ( a2 )
  {
    v3 = *(_DWORD *)(a2 + 32);
    if ( v3 )
    {
      v4 = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v3 + 48))(*(_DWORD *)(a2 + 32));
      *this = v4;
      if ( !v4 )
        --*(_DWORD *)(a2 + 20);
    }
  }
}
