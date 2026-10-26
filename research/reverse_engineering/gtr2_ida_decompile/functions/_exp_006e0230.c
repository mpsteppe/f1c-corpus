double __cdecl exp(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( !dword_FBB5E0 )
    goto __exp_default;
  v1 = _mm_getcsr() & 0x1F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v4 & 0x7F) == 127;
  if ( !v2 )
__exp_default:
    JUMPOUT(0x6E02A7);
  return start_3(X);
}
