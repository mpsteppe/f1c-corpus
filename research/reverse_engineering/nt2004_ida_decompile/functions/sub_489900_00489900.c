int __fastcall sub_489900(int a1, int a2)
{
  double v3; // st7

  if ( *(float *)(a1 + 864) >= 0.0 )
  {
    v3 = *(float *)(a1 + 864) - sub_4AE720(*(_DWORD *)(a1 + 48), a2);
    *(float *)(a1 + 864) = v3;
    if ( v3 < 0.0 )
    {
      if ( *(_DWORD *)(a1 + 868) )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)a1 + 188))(a1);
        sub_4ED5B0(&dword_7D6B74);
        dword_600F44 = (*(_DWORD *)(a1 + 868) != 1) + 1;
      }
    }
  }
  return (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 164))(a1);
}
