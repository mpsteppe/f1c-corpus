void __thiscall sub_540EB0(_DWORD *this, int a2)
{
  int v3; // eax

  if ( a2 && *(_DWORD *)(a2 + 32) )
  {
    while ( *(int *)(a2 + 20) > 0 )
      ArithmeticComparison_0f90(a2);
    v3 = *(_DWORD *)(a2 + 32);
    *(_DWORD *)(a2 + 20) = 0;
    *this = (*(int (__stdcall **)(int))(*(_DWORD *)v3 + 8))(v3);
    *(_DWORD *)(a2 + 32) = 0;
  }
}

