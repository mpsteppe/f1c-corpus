double __usercall _CIexp@<st0>(double x@<st0>, __int16 a2@<cx>, __int16 a3@<fpstat>)
{
  int v3; // eax
  bool v4; // zf
  char v5; // [esp+0h] [ebp-8h]

  if ( !dword_FBB5E0 )
    goto __CIexp_default;
  v3 = _mm_getcsr() & 0x1F80;
  v4 = v3 == 8064;
  if ( v3 == 8064 )
    v4 = (v5 & 0x7F) == 127;
  if ( v4 )
    _CIexp_pentium4();
  else
__CIexp_default:
    _cintrindisp1((int)&unk_91335A, a2, a3, x);
  return x;
}
